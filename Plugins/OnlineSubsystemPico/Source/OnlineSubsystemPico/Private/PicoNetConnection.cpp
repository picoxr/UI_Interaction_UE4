// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#include "PicoNetConnection.h"
#include "OnlineSubsystemPicoPrivate.h"
#include "IPAddressPico.h"
#include "Net/DataChannel.h"
#include "PacketHandler.h"

void UPicoNetConnection::InitBase(UNetDriver* InDriver, class FSocket* InSocket, const FURL& InURL, EConnectionState InState, int32 InMaxPacket, int32 InPacketOverhead)
{
    if (bIsPassThrough)
    {
        UIpConnection::InitBase(InDriver, InSocket, InURL, InState, InMaxPacket, InPacketOverhead);
        return;
    }

    DisableAddressResolution();

    // Pass the call up the chain
    UNetConnection::InitBase(InDriver, InSocket, InURL, InState,
        // Use the default packet size/overhead unless overridden by a child class
        InMaxPacket == 0 ? MAX_PACKET_SIZE : InMaxPacket,
        /* PacketOverhead */ 1);

    // We handle our own overhead
    PacketOverhead = 0;

    // Initalize the send buffer
    InitSendBuffer();
}

void UPicoNetConnection::InitLocalConnection(UNetDriver* InDriver, class FSocket* InSocket, const FURL& InURL, EConnectionState InState, int32 InMaxPacket, int32 InPacketOverhead)
{
    if (InDriver->GetSocketSubsystem() != nullptr)
    {
        bIsPassThrough = true;
        UIpConnection::InitLocalConnection(InDriver, InSocket, InURL, InState, InMaxPacket, InPacketOverhead);
        return;
    }

    bIsPassThrough = false;
    InitBase(InDriver, InSocket, InURL, InState,
        // Use the default packet size/overhead unless overridden by a child class
        InMaxPacket == 0 ? MAX_PACKET_SIZE : InMaxPacket,
        0);
#if ENGINE_MAJOR_VERSION > 4
    FInternetAddrPico PicoAddr = FInternetAddrPico::FromUrl(InURL);
#elif ENGINE_MINOR_VERSION > 26
    FInternetAddrPico PicoAddr = FInternetAddrPico::FromUrl(InURL);
#elif ENGINE_MINOR_VERSION > 24
    auto PicoAddr = FInternetAddrPico(InURL);
#endif
    PeerID = PicoAddr.GetID();
    UserID = PicoAddr.GetStrID();
}

void UPicoNetConnection::InitRemoteConnection(UNetDriver* InDriver, class FSocket* InSocket, const FURL& InURL, const class FInternetAddr& InRemoteAddr, EConnectionState InState, int32 InMaxPacket, int32 InPacketOverhead)
{
    if (InDriver->GetSocketSubsystem() != nullptr)
    {
        bIsPassThrough = true;
        UIpConnection::InitRemoteConnection(InDriver, InSocket, InURL, InRemoteAddr, InState, InMaxPacket, InPacketOverhead);
        return;
    }

    bIsPassThrough = false;
    InitBase(InDriver, InSocket, InURL, InState,
        // Use the default packet size/overhead unless overridden by a child class
        InMaxPacket == 0 ? MAX_PACKET_SIZE : InMaxPacket,
        0);

    RemoteAddr = InRemoteAddr.Clone();
    PeerID = StaticCastSharedPtr<FInternetAddrPico>(RemoteAddr)->GetID();
    UserID = StaticCastSharedPtr<FInternetAddrPico>(RemoteAddr)->GetStrID();

    // This is for a client that needs to log in, setup ClientLoginState and ExpectedClientLoginMsgType to reflect that
    SetClientLoginState(EClientLoginState::LoggingIn);
    SetExpectedClientLoginMsgType(NMT_Hello);
}

void UPicoNetConnection::LowLevelSend(void* Data, int32 CountBits, FOutPacketTraits& Traits)
{
    if (bIsPassThrough)
    {
        UIpConnection::LowLevelSend(Data, CountBits, Traits);
        return;
    }

    check(PeerID);

    // Do not send packets over a closed connection
    // This can unintentionally re-open the connection
#if ENGINE_MAJOR_VERSION > 4
    if (GetConnectionState() == EConnectionState::USOCK_Closed)
    {
        return;
    }
#elif ENGINE_MINOR_VERSION > 24
    if (State == EConnectionState::USOCK_Closed)
    {
        return;
    }
#endif


    const uint8* DataToSend = reinterpret_cast<uint8*>(Data);

    // Process any packet modifiers
    if (Handler.IsValid() && !Handler->GetRawSend())
    {
        const ProcessedPacket ProcessedData = Handler->Outgoing(reinterpret_cast<uint8*>(Data), CountBits, Traits);

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

    bool bBlockSend = false;
    uint32 CountBytes = FMath::DivideAndRoundUp(CountBits, 8);

#if !UE_BUILD_SHIPPING
    LowLevelSendDel.ExecuteIfBound((void*)DataToSend, CountBytes, bBlockSend);
#endif

    if (!bBlockSend && CountBytes > 0)
    {
        UE_LOG(LogNetTraffic, VeryVerbose, TEXT("Low level send to: %llu Count: %d, UserID: %s"), PeerID, CountBytes, *UserID);
        ppf_Net_SendPacket(TCHAR_TO_UTF8(*UserID), static_cast<size_t>(CountBytes), DataToSend);
    }
}

FString UPicoNetConnection::LowLevelGetRemoteAddress(bool bAppendPort)
{
    if (bIsPassThrough)
    {
        return UIpConnection::LowLevelGetRemoteAddress(bAppendPort);
    }
    return FString::Printf(TEXT("%llu.pico"), PeerID);
}

FString UPicoNetConnection::LowLevelDescribe()
{
    if (bIsPassThrough)
    {
        return UIpConnection::LowLevelDescribe();
    }
    return FString::Printf(TEXT("PeerId=%llu"), PeerID);
}

void UPicoNetConnection::FinishDestroy()
{
    if (bIsPassThrough)
    {
        UIpConnection::FinishDestroy();
        return;
    }
    // Keep track if it's this call that is closing the connection before cleanup is called

#if ENGINE_MAJOR_VERSION > 4
    const bool bIsClosingOpenConnection = GetConnectionState() != EConnectionState::USOCK_Closed;
#elif ENGINE_MINOR_VERSION > 24
    const bool bIsClosingOpenConnection = State != EConnectionState::USOCK_Closed;
#endif
    UNetConnection::FinishDestroy();

    // If this connection was open, then close it
    if (PeerID != 0 && bIsClosingOpenConnection)
    {
        UE_LOG(LogNet, Verbose, TEXT("Pico Net Connection closed to %llu"), PeerID);
    }
}

FString UPicoNetConnection::RemoteAddressToString()
{
    if (bIsPassThrough)
    {
        return UIpConnection::RemoteAddressToString();
    }
    return LowLevelGetRemoteAddress(/* bAppendPort */ false);
}
