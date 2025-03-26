// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#include "PicoNetDriver.h"
#include "OnlineSubsystemPicoPrivate.h"
#include "OnlineSessionInterfacePico.h"
#include "IPAddressPico.h"
#include "PicoNetConnection.h"
#include "PacketHandlers/StatelessConnectHandlerComponent.h"
#include "Engine/NetworkDelegates.h"


bool UPicoNetDriver::IsAvailable() const
{
    // Net driver won't work if the online subsystem doesn't exist
    IOnlineSubsystem* PicoSubsystem = IOnlineSubsystem::Get(PICO_SUBSYSTEM);
    if (PicoSubsystem)
    {
        return true;
    }
    return false;
}

ISocketSubsystem* UPicoNetDriver::GetSocketSubsystem()
{
    if (bIsPassthrough)
    {
        return UIpNetDriver::GetSocketSubsystem();
    }
    /** Not used */
    return nullptr;
}

bool UPicoNetDriver::InitBase(bool bInitAsClient, FNetworkNotify* InNotify, const FURL& URL, bool bReuseAddressAndPort, FString& Error)
{
    if (bIsPassthrough)
    {
        return UIpNetDriver::InitBase(bInitAsClient, InNotify, URL, bReuseAddressAndPort, Error);
    }

    if (!UNetDriver::InitBase(bInitAsClient, InNotify, URL, bReuseAddressAndPort, Error))
    {
        return false;
    }

    // How often new links time out
    if (InitialConnectTimeout == 0.0)
    {
        UE_LOG(LogNet, Warning, TEXT("InitalConnectTimeout was set to %f"), InitialConnectTimeout);
        InitialConnectTimeout = 120.0;
    }

    // How long has the connection timed out
    if (ConnectionTimeout == 0.0)
    {
        UE_LOG(LogNet, Warning, TEXT("ConnectionTimeout was set to %f"), ConnectionTimeout);
        ConnectionTimeout = 120.0;
    }

    if (KeepAliveTime == 0.0)
    {
        UE_LOG(LogNet, Warning, TEXT("KeepAliveTime was set to %f"), KeepAliveTime);
        KeepAliveTime = 0.2;
    }

    if (SpawnPrioritySeconds == 0.0)
    {
        UE_LOG(LogNet, Warning, TEXT("SpawnPrioritySeconds was set to %f"), SpawnPrioritySeconds);
        SpawnPrioritySeconds = 1.0;
    }

    if (RelevantTimeout == 0.0)
    {
        UE_LOG(LogNet, Warning, TEXT("RelevantTimeout was set to %f"), RelevantTimeout);
        RelevantTimeout = 5.0;
    }

    if (ServerTravelPause == 0.0)
    {
        UE_LOG(LogNet, Warning, TEXT("ServerTravelPause was set to %f"), ServerTravelPause);
        ServerTravelPause = 4.0;
    }
    return true;
}

bool UPicoNetDriver::InitConnect(FNetworkNotify* InNotify, const FURL& ConnectURL, FString& Error)
{
    UE_LOG(LogNet, Verbose, TEXT("Connecting to host: %s"), *ConnectURL.ToString(true));

#if ENGINE_MAJOR_VERSION > 4
    FInternetAddrPico PicoAddr = FInternetAddrPico::FromUrl(ConnectURL);
#elif ENGINE_MINOR_VERSION > 26
    FInternetAddrPico PicoAddr = FInternetAddrPico::FromUrl(ConnectURL);
#elif ENGINE_MINOR_VERSION > 24
    FInternetAddrPico PicoAddr(ConnectURL);
#endif

    if (!PicoAddr.IsValid())
    {
        UE_LOG(LogNet, Verbose, TEXT("Init as IPNetDriver connect"));
        bIsPassthrough = true;
        return UIpNetDriver::InitConnect(InNotify, ConnectURL, Error);
    }

    if (!InitBase(true, InNotify, ConnectURL, false, Error))
    {
        return false;
    }

    // Create an unreal connection to the server
    UPicoNetConnection* Connection = NewObject<UPicoNetConnection>(NetConnectionClass);
    check(Connection);

    // Set it as the server connection before anything else so everything knows this is a client
    ServerConnection = Connection;
    Connection->InitLocalConnection(this, nullptr, ConnectURL, USOCK_Open);
    Connections.Add(PicoAddr.GetStrID(), Connection);

    // Create the control channel so we can send the Hello message
    CreateInitialClientChannels();

    return true;
}

bool UPicoNetDriver::InitListen(FNetworkNotify* InNotify, FURL& LocalURL, bool bReuseAddressAndPort, FString& Error)
{
    if (LocalURL.HasOption(TEXT("bIsLanMatch")))
    {
        UE_LOG(LogNet, Verbose, TEXT("Init as IPNetDriver listen server"));
        bIsPassthrough = true;
        return Super::InitListen(InNotify, LocalURL, bReuseAddressAndPort, Error);
    }

    if (!InitBase(false, InNotify, LocalURL, bReuseAddressAndPort, Error))
    {
        return false;
    }

    InitConnectionlessHandler();

    UE_LOG(LogNet, Verbose, TEXT("Init as a listen server"));

    return true;
}

void UPicoNetDriver::TickDispatch(float DeltaTime)
{
    if (bIsPassthrough)
    {
        UIpNetDriver::TickDispatch(DeltaTime);
        return;
    }

    UNetDriver::TickDispatch(DeltaTime);

    // Process all incoming packets.
    for (;;)
    {
        auto Packet = ppf_Net_ReadPacket();
        if (!Packet)
        {
            break;
        }

        bool bIgnorePacket = false;

        auto SenderID = ppf_Packet_GetSenderID(Packet);
        FString SenderIDStr = UTF8_TO_TCHAR(SenderID);
        auto PacketSize = static_cast<int32>(ppf_Packet_GetSize(Packet));
        auto Data = (uint8*)ppf_Packet_GetBytes(Packet);

        // The server must check the pending client connections first to see if any clients are challenging the server
        // This logic is basically the same as the one in IpNetDriver
        if (IsServer() && PendingClientConnections.Contains(SenderIDStr))
        {
            bool bPassedChallenge = false;
            TSharedPtr<StatelessConnectHandlerComponent> StatelessConnect;

            if (!ConnectionlessHandler.IsValid() || !StatelessConnectComponent.IsValid())
            {
                UE_LOG(LogNet, Log,
                    TEXT("Invalid ConnectionlessHandler (%i) or StatelessConnectComponent (%i); can't accept connections."),
                    (int32)(ConnectionlessHandler.IsValid()), (int32)(StatelessConnectComponent.IsValid()));
                continue;
            }

            UE_LOG(LogNet, Verbose, TEXT("Checking challenge from: %s"), *SenderIDStr);
            TSharedPtr<FInternetAddr> PicoAddr = MakeShareable(new FInternetAddrPico(SenderIDStr));
            StatelessConnect = StatelessConnectComponent.Pin();
            const ProcessedPacket UnProcessedPacket = ConnectionlessHandler->IncomingConnectionless(PicoAddr, Data, PacketSize);
            bool bRestartedHandshake = false;
            bPassedChallenge = !UnProcessedPacket.bError && StatelessConnect->HasPassedChallenge(PicoAddr, bRestartedHandshake);

            if (bPassedChallenge)
            {
                PendingClientConnections.Remove(SenderIDStr);
                PacketSize = FMath::DivideAndRoundUp(UnProcessedPacket.CountBits, 8);
                if (PacketSize > 0)
                {
                    Data = UnProcessedPacket.Data;
                }

                UE_LOG(LogNet, Log, TEXT("Server accepting post-challenge connection from: %s"), *SenderIDStr);

                // Create an unreal connection to the client
                UPicoNetConnection* Connection = NewObject<UPicoNetConnection>(NetConnectionClass);
                check(Connection);

                Connection->InitRemoteConnection(this, nullptr, FURL(), *PicoAddr, USOCK_Open);

                AddClientConnection(Connection);

                Connections.Add(SenderIDStr, Connection);

                // Set the initial packet sequence from the handshake data
                if (StatelessConnect.IsValid())
                {
                    int32 ServerSequence = 0;
                    int32 ClientSequence = 0;

                    StatelessConnect->GetChallengeSequence(ServerSequence, ClientSequence);

                    Connection->InitSequence(ClientSequence, ServerSequence);

                    StatelessConnect->ResetChallengeData();
                }

                if (Connection->Handler.IsValid())
                {
                    Connection->Handler->BeginHandshaking();
                }

                Notify->NotifyAcceptedConnection(Connection);

                // If there is nothing left to process for this packet, then skip it
                if (PacketSize == 0)
                {
                    bIgnorePacket = true;
                }
            }
            else
            {
                UE_LOG(LogNet, Warning, TEXT("Server failed post-challenge connection from: %s"), *SenderIDStr);
                bIgnorePacket = true;
            }
        }

        // Process the packet if we aren't suppose to ignore it
        if (!bIgnorePacket && Connections.Contains(SenderIDStr))
        {
            auto Connection = Connections[SenderIDStr];
#if ENGINE_MAJOR_VERSION > 4
            if (Connection->GetConnectionState() == EConnectionState::USOCK_Open)
#elif ENGINE_MINOR_VERSION > 24
            if (Connection->State == EConnectionState::USOCK_Open)
#endif
            {
                UE_LOG(LogNetTraffic, VeryVerbose, TEXT("Got a raw packet of size %d"), PacketSize);
                Connection->ReceivedRawPacket(Data, PacketSize);
            }
            else
            {
                // This can happen on non-seamless map travels
                UE_LOG(LogNet, Verbose, TEXT("Got a packet but the connection is closed to: %s"), *SenderIDStr);
            }
        }
        else
        {
            UE_LOG(LogNet, Warning, TEXT("There is no connection to: %s"), *SenderIDStr);
        }
        ppf_Packet_Free(Packet);
    }
}

void UPicoNetDriver::LowLevelSend(TSharedPtr<const FInternetAddr> Address, void* Data, int32 CountBits, FOutPacketTraits& Traits)
{
    if (bIsPassthrough)
    {
        return UIpNetDriver::LowLevelSend(Address, Data, CountBits, Traits);
    }

#if ENGINE_MAJOR_VERSION > 4
    FInternetAddrPico PicoAddr = FInternetAddrPico::FromUrl(FURL(nullptr, *Address->ToString(false), ETravelType::TRAVEL_Absolute));
#elif ENGINE_MINOR_VERSION > 26
    FInternetAddrPico PicoAddr = FInternetAddrPico::FromUrl(FURL(nullptr, *Address->ToString(false), ETravelType::TRAVEL_Absolute));
#elif ENGINE_MINOR_VERSION > 24
    FInternetAddrPico PicoAddr(FURL(nullptr, *Address->ToString(false), ETravelType::TRAVEL_Absolute));
#endif

    ppfID PeerID = PicoAddr.GetID();
    FString UserID = PicoAddr.GetStrID();
    if (IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get())
    {
        auto PicoSubsystem = static_cast<FOnlineSubsystemPico*>(Subsystem);
        if (PicoSubsystem && PicoSubsystem->Init() && PicoSubsystem->GetGameSessionInterface())
        {
            auto SessionInterface = PicoSubsystem->GetGameSessionInterface();
            if (!SessionInterface->IsInitSuccess())
            {
                return;
            }
            const uint8* DataToSend = reinterpret_cast<uint8*>(Data);

            if (ConnectionlessHandler.IsValid())
            {
                const ProcessedPacket ProcessedData =
                    ConnectionlessHandler->OutgoingConnectionless(Address, (uint8*)DataToSend, CountBits, Traits);

                if (!ProcessedData.bError)
                {
                    DataToSend = ProcessedData.Data;
                    CountBits = ProcessedData.CountBits;
                }
                else
                {
                    CountBits = 0;
                }
            }
            int32 BytesSent = 0;
            uint32 CountBytes = FMath::DivideAndRoundUp(CountBits, 8);

            if (CountBits > 0)
            {
                ppf_Net_SendPacket(TCHAR_TO_UTF8(*UserID), static_cast<size_t>(CountBytes), DataToSend);
            }
        }
        else
        {
            UE_LOG(LogNet, Warning, TEXT("There is no connection to: %s"), *UserID);
        }
    }
}

bool UPicoNetDriver::AddNewClientConnection(const FString& UserID)
{
    // Ignore the peer if not accepting new connections
    if (Notify->NotifyAcceptingConnection() != EAcceptConnection::Accept)
    {
        UE_LOG(LogNet, Warning, TEXT("Not accepting more new connections"));
        return false;
    }

    UE_LOG(LogNet, Verbose, TEXT("New incoming peer request: %s"), *UserID);

    // todo
    // Add to the list of clients we are expecting a challenge from
    PendingClientConnections.Add(UserID, USOCK_Open);
    // Remove it from existing connections map if it exists.
    Connections.Remove(UserID);

    return true;
}

void UPicoNetDriver::Shutdown()
{
    if (bIsPassthrough)
    {
        UIpNetDriver::Shutdown();
        return;
    }
    UNetDriver::Shutdown();
    UE_LOG(LogNet, Verbose, TEXT("Pico Net Driver shutdown"));
}

bool UPicoNetDriver::IsNetResourceValid()
{
    if (bIsPassthrough)
    {
        return UIpNetDriver::IsNetResourceValid();
    }

    if (!IsAvailable())
    {
        return false;
    }

    // The listen server is always available
    if (IsServer())
    {
        return true;
    }

    // The clients need to wait until the connection is established before sending packets
#if ENGINE_MAJOR_VERSION > 4
    return ServerConnection->GetConnectionState() == EConnectionState::USOCK_Open;
#elif ENGINE_MINOR_VERSION > 24
    return ServerConnection->State == EConnectionState::USOCK_Open;
#endif
}
