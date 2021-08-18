// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/CoreOnline.h"
#include "OnlineSubsystemPicoModule.h"

class FUniqueNetIdPico : public FUniqueNetId
{
private:
	uint64 ID;

protected:
	virtual bool Compare(const FUniqueNetId& Other) const override
	{
		if (Other.GetType() != GetType())
		{
			return false;
		}

		if (Other.GetSize() != sizeof(uint64))
		{
			return false;
		}

		return ID == static_cast<const FUniqueNetIdPico&>(Other).ID;
	}

public:
	/** Default constructor */
	FUniqueNetIdPico()
	{
		ID = 0;
	}

	FUniqueNetIdPico(const uint64& id)
	{
		ID = id;
	}

	FUniqueNetIdPico(const FString& id)
	{
		FCString::Strtoui64(*id, NULL, 10);
	}

	/**
	* Copy Constructor
	*
	* @param Src the id to copy
	*/
	explicit FUniqueNetIdPico(const FUniqueNetId& Src)
	{
		if (Src.GetSize() == sizeof(uint64))
		{
			ID = static_cast<const FUniqueNetIdPico&>(Src).ID;
		}
	}

	virtual FName GetType() const override
	{
		return PICO_SUBSYSTEM;
	}

	// IOnlinePlatformData

	virtual const uint8* GetBytes() const override
	{
		return reinterpret_cast<const uint8*>(&ID);
	}

	virtual int32 GetSize() const override
	{
		return sizeof(ID);
	}

	virtual bool IsValid() const override
	{
		// Not completely accurate, but safe to assume numbers below this is invalid
		return ID>0;
	}

	uint64 GetID() const
	{
		return ID;
	}

	virtual FString ToString() const override
	{
		return FString::Printf(TEXT("%llu"), ID);
	}

	virtual FString ToDebugString() const override
	{
		const FString UniqueNetIdStr = FString::Printf(TEXT("%llu"), ID);
		return TEXT("PicoUserID:") + UniqueNetIdStr;
	}

	/** Needed for TMap::GetTypeHash() */
	friend uint32 GetTypeHash(const FUniqueNetIdPico& A)
	{
		return GetTypeHash((uint64)A.ID);
	}

	/** global static instance of invalid (zero) id */
	static const TSharedRef<const FUniqueNetId>& EmptyId()
	{
		static const TSharedRef<const FUniqueNetId> EmptyId(MakeShared<FUniqueNetIdPico>());
		return EmptyId;
	}
};
