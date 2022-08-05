// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

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
	FUniqueNetIdPicoRef PicoId;

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

	ppfID GetID() const
	{
		return PicoId->GetID();
	}
	FString GetStrID() const
	{
		return PicoId->GetStringID();
	}

	virtual TArray<uint8> GetRawIp() const override
	{
		TArray<uint8> RawAddressArray;
		const uint8* PicoIdWalk = PicoId->GetBytes();
		while (RawAddressArray.Num() < PicoId->GetSize())
		{
			RawAddressArray.Add(*PicoIdWalk);
			++PicoIdWalk;
		}

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

		PicoId = FUniqueNetIdPico::Create(NewId);
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
		return PicoId->ToString();
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
		return PicoId->IsValid();
	}

	virtual TSharedRef<FInternetAddr> Clone() const override
	{
		TSharedRef<FInternetAddrPico> NewAddress = MakeShareable(new FInternetAddrPico);
		NewAddress->PicoId = PicoId;
		return NewAddress;
	}
};