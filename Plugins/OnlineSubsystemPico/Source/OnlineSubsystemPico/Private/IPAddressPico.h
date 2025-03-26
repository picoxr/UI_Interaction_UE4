// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "IPAddress.h"
#include "Algo/Reverse.h"
#include "Engine/EngineBaseTypes.h"
#include "OnlineSubsystemPico.h"
#include "OnlineSubsystemPicoTypes.h"
#include "OnlineSubsystemPicoPackage.h"

/**
* Fake an internet ip address but in reality using an ppfID
*/

class FInternetAddrPico : public FInternetAddr
{
PACKAGE_SCOPE:

#if ENGINE_MAJOR_VERSION > 4
	FUniqueNetIdPicoRef PicoId;
#elif ENGINE_MINOR_VERSION > 26
	FUniqueNetIdPicoRef PicoId;
#elif ENGINE_MINOR_VERSION > 24
	FUniqueNetIdPico PicoId;
#endif

	/**
	* Copy Constructor
	*/
	FInternetAddrPico(const FInternetAddrPico& Src) :
		PicoId(Src.PicoId)
	{
	}


public:
	/**
	* Constructor. Sets address to default state
	*/


#if ENGINE_MAJOR_VERSION > 4
	FInternetAddrPico() :
		PicoId(FUniqueNetIdPico::EmptyId())
	{
	}

	/**
* Constructor
*/
	explicit FInternetAddrPico(const FUniqueNetIdPico& InPicoId) :
		PicoId(InPicoId.AsShared())
	{
	}

	/**
	* Constructor
	*/
	explicit FInternetAddrPico(ppfID InPicoId) :
		PicoId(FUniqueNetIdPico::Create(InPicoId))
	{
	}
	explicit FInternetAddrPico(const FString& UserId) :
		PicoId(FUniqueNetIdPico::Create(UserId))
	{
	}

	static FInternetAddrPico FromUrl(const FURL& ConnectURL)
	{
		FString Host = ConnectURL.Host;
		// Parse the URL: unreal://<pico_id>.pico or unreal://<pico_id>
		int32 DotIndex;
		FString PicoStringID = (Host.FindChar('.', DotIndex)) ? Host.Left(DotIndex) : Host;
		uint64 PicoUintId = strtoull(TCHAR_TO_ANSI(*PicoStringID), nullptr, 10);
		const FUniqueNetIdPicoRef PicoNetId = FUniqueNetIdPico::Create(PicoUintId);
		return FInternetAddrPico(*PicoNetId);
	}
#elif ENGINE_MINOR_VERSION > 26
	FInternetAddrPico() :
		PicoId(FUniqueNetIdPico::EmptyId())
	{
	}

	/**
* Constructor
*/
	explicit FInternetAddrPico(const FUniqueNetIdPico& InPicoId) :
		PicoId(InPicoId.AsShared())
	{
	}

	/**
	* Constructor
	*/
	explicit FInternetAddrPico(ppfID InPicoId) :
		PicoId(FUniqueNetIdPico::Create(InPicoId))
	{
	}
	explicit FInternetAddrPico(const FString& UserId) :
		PicoId(FUniqueNetIdPico::Create(UserId))
	{
	}

	static FInternetAddrPico FromUrl(const FURL& ConnectURL)
	{
		FString Host = ConnectURL.Host;
		// Parse the URL: unreal://<pico_id>.pico or unreal://<pico_id>
		int32 DotIndex;
		FString PicoStringID = (Host.FindChar('.', DotIndex)) ? Host.Left(DotIndex) : Host;
		uint64 PicoUintId = strtoull(TCHAR_TO_ANSI(*PicoStringID), nullptr, 10);
		const FUniqueNetIdPicoRef PicoNetId = FUniqueNetIdPico::Create(PicoUintId);
		return FInternetAddrPico(*PicoNetId);
	}

#elif ENGINE_MINOR_VERSION > 24
	FInternetAddrPico() :
		PicoId(0ull)
	{
	}

	/**
	* Constructor
	*/
	explicit FInternetAddrPico(const FUniqueNetIdPico& InPicoId) :
		PicoId(InPicoId)
	{
	}

	/**
	* Constructor
	*/
	explicit FInternetAddrPico(ppfID InPicoId) :
		PicoId(FUniqueNetIdPico(InPicoId))
	{
	}
	explicit FInternetAddrPico(const FString& UserId) :
		PicoId(FUniqueNetIdPico(UserId))
	{
	}

	explicit FInternetAddrPico(const FURL& ConnectURL)
	{
		auto Host = ConnectURL.Host;

		// Parse the URL: unreal://<oculus_id>.oculus or unreal://<oculus_id>
		int32 DotIndex;
		auto PicoStringID = (Host.FindChar('.', DotIndex)) ? Host.Left(DotIndex) : Host;
		PicoId = strtoull(TCHAR_TO_ANSI(*PicoStringID), nullptr, 10);
	}
#endif


#if ENGINE_MAJOR_VERSION > 4
	ppfID GetID() const
	{
		return PicoId->GetID();
	}
	FString GetStrID() const
	{
		return PicoId->GetStringID();
	}
#elif ENGINE_MINOR_VERSION > 26
	ppfID GetID() const
	{
		return PicoId->GetID();
	}
	FString GetStrID() const
	{
		return PicoId->GetStringID();
	}
#elif ENGINE_MINOR_VERSION > 24
	ppfID GetID() const
	{
		return PicoId.GetID();
	}
	FString GetStrID() const
	{
		return PicoId.GetStringID();
	}
#endif

	virtual TArray<uint8> GetRawIp() const override
	{
#if ENGINE_MAJOR_VERSION > 4
		TArray<uint8> RawAddressArray;
		const uint8* PicoIdWalk = PicoId->GetBytes();
		while (RawAddressArray.Num() < PicoId->GetSize())
		{
			RawAddressArray.Add(*PicoIdWalk);
			++PicoIdWalk;
		}
#elif ENGINE_MINOR_VERSION > 26
		TArray<uint8> RawAddressArray;
		const uint8* PicoIdWalk = PicoId->GetBytes();
		while (RawAddressArray.Num() < PicoId->GetSize())
		{
			RawAddressArray.Add(*PicoIdWalk);
			++PicoIdWalk;
		}

#elif ENGINE_MINOR_VERSION > 24
		TArray<uint8> RawAddressArray;
		const uint8* PicoIdWalk = PicoId.GetBytes();
		while (RawAddressArray.Num() < PicoId.GetSize())
		{
			RawAddressArray.Add(*PicoIdWalk);
			++PicoIdWalk;
		}
#endif


		// We want to make sure that these arrays are in big endian format.
#if PLATFORM_LITTLE_ENDIAN
		Algo::Reverse(RawAddressArray);
#endif

		return RawAddressArray;
	}

	virtual void SetRawIp(const TArray<uint8>& RawAddr) override
	{
		ppfID NewId = 0;

		// Make a quick copy of the array
		TArray<uint8> WorkingArray = RawAddr;

		// If we're little endian, we need to reverse so that the shifts turn out correct
#if PLATFORM_LITTLE_ENDIAN
		Algo::Reverse(WorkingArray);
#endif

		for (int32 i = 0; i < WorkingArray.Num(); ++i)
		{
			NewId |= (ppfID)WorkingArray[i] << (i * 8);
		}

#if ENGINE_MAJOR_VERSION > 4
		PicoId = FUniqueNetIdPico::Create(NewId);
#elif ENGINE_MINOR_VERSION > 26
		PicoId = FUniqueNetIdPico::Create(NewId);
#elif ENGINE_MINOR_VERSION > 24
		PicoId = FUniqueNetIdPico(NewId);
#endif


	}

	/**
	* Sets the ip address from a host byte order uint32
	*
	* @param InAddr the new address to use (must convert to network byte order)
	*/
	void SetIp(uint32 InAddr) override
	{
		/** Not used */
	}

	/**
	* Sets the ip address from a string ("A.B.C.D")
	*
	* @param InAddr the string containing the new ip address to use
	*/
	void SetIp(const TCHAR* InAddr, bool& bIsValid) override
	{
		/** Not used */
	}

	/**
	* Copies the network byte order ip address to a host byte order dword
	*
	* @param OutAddr the out param receiving the ip address
	*/
	void GetIp(uint32& OutAddr) const override
	{
		/** Not used */
	}

	/**
	* Sets the port number from a host byte order int
	*
	* @param InPort the new port to use (must convert to network byte order)
	*/
	void SetPort(int32 InPort) override
	{
		/** Not used */
	}

	/**
	* Copies the port number from this address and places it into a host byte order int
	*
	* @param OutPort the host byte order int that receives the port
	*/
	void GetPort(int32& OutPort) const override
	{
		/** Not used */
	}

	/**
	* Returns the port number from this address in host byte order
	*/
	int32 GetPort() const override
	{
		/** Not used */
		return 0;
	}

	/** Sets the address to be any address */
	void SetAnyAddress() override
	{
		/** Not used */
	}

	/** Sets the address to broadcast */
	void SetBroadcastAddress() override
	{
		/** Not used */
	}

	/** Sets the address to loopback */
	void SetLoopbackAddress() override
	{
		/** Not used */
	}

	/**
	* Converts this internet ip address to string form
	*
	* @param bAppendPort whether to append the port information or not
	*/
	FString ToString(bool bAppendPort) const override
	{
#if ENGINE_MAJOR_VERSION > 4
		return PicoId->ToString();
#elif ENGINE_MINOR_VERSION > 26
		return PicoId->ToString();
#elif ENGINE_MINOR_VERSION > 24
		return PicoId.ToString();
#endif

	}

	/**
	* Compares two internet ip addresses for equality
	*
	* @param Other the address to compare against
	*/
	virtual bool operator==(const FInternetAddr& Other) const override
	{
		FInternetAddrPico& PicoOther = (FInternetAddrPico&)Other;
		return PicoId == PicoOther.PicoId;
	}

	bool operator!=(const FInternetAddrPico& Other) const
	{
		return !(FInternetAddrPico::operator==(Other));
	}

	virtual uint32 GetTypeHash() const override
	{
		return ::GetTypeHash((uint64)GetID());
	}

	virtual FName GetProtocolType() const override
	{
		return FNetworkProtocolTypes::Pico;
	}

	/**
	* Is this a well formed internet address
	*
	* @return true if a valid Pico id, false otherwise
	*/
	virtual bool IsValid() const override
	{
#if ENGINE_MAJOR_VERSION > 4
		return PicoId->IsValid();
#elif ENGINE_MINOR_VERSION > 26
		return PicoId->IsValid();
#elif ENGINE_MINOR_VERSION > 24
		return PicoId.IsValid();
#endif

	}

	virtual TSharedRef<FInternetAddr> Clone() const override
	{
		TSharedRef<FInternetAddrPico> NewAddress = MakeShareable(new FInternetAddrPico);
		NewAddress->PicoId = PicoId;
		return NewAddress;
	}
};