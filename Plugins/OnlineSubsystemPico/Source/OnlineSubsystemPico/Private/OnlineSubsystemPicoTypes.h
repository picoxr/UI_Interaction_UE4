// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystemTypes.h"
#include "OnlineSubsystemPicoPackage.h"
#include "PPF_Platform.h"
#include "Runtime/Launch/Resources/Version.h"
#include "OnlineSubsystemPicoNames.h"

#if ENGINE_MAJOR_VERSION > 4
using FUniqueNetIdPicoPtr = TSharedPtr<const class FUniqueNetIdPico>;
using FUniqueNetIdPicoRef = TSharedRef<const class FUniqueNetIdPico>;

#elif ENGINE_MINOR_VERSION > 26
using FUniqueNetIdPicoPtr = TSharedPtr<const class FUniqueNetIdPico, UNIQUENETID_ESPMODE>;
using FUniqueNetIdPicoRef = TSharedRef<const class FUniqueNetIdPico, UNIQUENETID_ESPMODE>;
#elif ENGINE_MINOR_VERSION > 24

#endif


class FUniqueNetIdPico : public FUniqueNetId
{
private:
    // Pass by string
    FString StrID;
    ppfID ID;
    bool bInitWithString;

protected:
    bool Compare(const FUniqueNetId& Other) const override
    {
        if (Other.GetType() != GetType())
        {
            return false;
        }
        return StrID == static_cast<const FUniqueNetIdPico&>(Other).StrID;
    }

public:
#if ENGINE_MAJOR_VERSION > 4
    template<typename... TArgs>
    static FUniqueNetIdPicoRef Create(TArgs&&... Args)
    {
        return MakeShared<FUniqueNetIdPico>(Forward<TArgs>(Args)...);
    }

    static const FUniqueNetIdPico& Cast(const FUniqueNetId& NetId)
    {
        check(NetId.GetType() == PICO_SUBSYSTEM);
        return *static_cast<const FUniqueNetIdPico*>(&NetId);
    }

    FUniqueNetIdPicoRef AsShared() const
    {
        return StaticCastSharedRef<const FUniqueNetIdPico>(FUniqueNetId::AsShared());
    }
#elif ENGINE_MINOR_VERSION > 26
    template<typename... TArgs>
    static FUniqueNetIdPicoRef Create(TArgs&&... Args)
    {
        return MakeShared<FUniqueNetIdPico, UNIQUENETID_ESPMODE>(Forward<TArgs>(Args)...);
    }

    /** Allow MakeShared to see private constructors */
    friend class SharedPointerInternals::TIntrusiveReferenceController<FUniqueNetIdPico>;

    static const FUniqueNetIdPico& Cast(const FUniqueNetId& NetId)
    {
        check(NetId.GetType() == PICO_SUBSYSTEM);
        return *static_cast<const FUniqueNetIdPico*>(&NetId);
    }
    FUniqueNetIdPicoRef AsShared() const
    {
        return StaticCastSharedRef<const FUniqueNetIdPico>(FUniqueNetId::AsShared());
    }
#elif ENGINE_MINOR_VERSION > 24
    static const FUniqueNetIdPico& Cast(const FUniqueNetId& NetId)
    {
        check(NetId.GetType() == PICO_SUBSYSTEM);
        return *static_cast<const FUniqueNetIdPico*>(&NetId);
    }
#endif

    virtual FName GetType() const override
    {
        return PICO_SUBSYSTEM;
    }

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
        return !GetStringID().IsEmpty();
    }

    ppfID GetID() const
    {
        if (bInitWithString)
        {
            // Conversion may failed
            return FCString::Strtoui64(*StrID, NULL, 10);
        }
        else
        {
            return ID;
        }

    }

    FString GetStringID() const
    {
        if (bInitWithString)
        {
            return StrID;
        }
        else
        {
            // Conversion may failed
            return FString::Printf(TEXT("%llu"), ID);
        }

    }

    virtual FString ToString() const override
    {
        return GetStringID();
    }

    virtual FString ToDebugString() const override
    {
        const FString UniqueNetIdStr = FString::Printf(TEXT("%llu"), ID);
        return TEXT("ppfID:") + OSS_UNIQUEID_REDACT(*this, UniqueNetIdStr);
    }

#if ENGINE_MAJOR_VERSION > 4 && ENGINE_MINOR_VERSION > 0
    virtual uint32 GetTypeHash() const override
    {
        return ::GetTypeHash((uint64)ID);
    }
#else
    friend uint32 GetTypeHash(const FUniqueNetIdPico& A)
    {
        return GetTypeHash((uint64)A.ID);
    }
#endif

    /** global static instance of invalid (zero) id */
#if ENGINE_MAJOR_VERSION > 4
    static const FUniqueNetIdPicoRef& EmptyId()
    {
        static const FUniqueNetIdPicoRef EmptyId(Create());
        return EmptyId;
    }
#elif ENGINE_MINOR_VERSION > 26
    static const FUniqueNetIdPicoRef& EmptyId()
    {
        static const FUniqueNetIdPicoRef EmptyId(Create());
        return EmptyId;
    }
#elif ENGINE_MINOR_VERSION > 24

    static const TSharedRef<const FUniqueNetId>& EmptyId()
    {
        static const TSharedRef<const FUniqueNetId> EmptyId(MakeShared<FUniqueNetIdPico>());
        return EmptyId;
    }

#endif

    FUniqueNetIdPico()
    {
        ID = 0;
        StrID = FString();
    }
    FUniqueNetIdPico(const ppfID& id)
    {
        ID = id;
        bInitWithString = false;
        // StrID = FString::Printf(TEXT("%llu"), ID);
    }

    FUniqueNetIdPico(const FString& id)
    {
        StrID = id;
        bInitWithString = true;
        //  ID = FCString::Strtoui64(*StrID, NULL, 10);
    }
    /**
    * Copy Constructor
    *
    * @param Src the id to copy
    */
    explicit FUniqueNetIdPico(const FUniqueNetId& Src)
    {
#if ENGINE_MAJOR_VERSION > 4
        if (Src.GetType() == PICO_SUBSYSTEM)
        {
            ID = FUniqueNetIdPico::Cast(Src).ID;
        }
#elif ENGINE_MINOR_VERSION > 26
        if (Src.GetType() == PICO_SUBSYSTEM)
        {
            ID = FUniqueNetIdPico::Cast(Src).ID;
        }
#elif ENGINE_MINOR_VERSION > 24
        if (Src.GetSize() == sizeof(ppfID))
        {
            ID = static_cast<const FUniqueNetIdPico&>(Src).ID;
        }
#endif
    }
};

/**
* Implementation of session information
*/
class FOnlineSessionInfoPico : public FOnlineSessionInfo
{
protected:

    /** Hidden on purpose */
#if ENGINE_MAJOR_VERSION > 4
    FOnlineSessionInfoPico(const FOnlineSessionInfoPico& Src) = delete;
    FOnlineSessionInfoPico& operator=(const FOnlineSessionInfoPico& Src) = delete;
#elif ENGINE_MINOR_VERSION > 26
    FOnlineSessionInfoPico(const FOnlineSessionInfoPico& Src) = delete;
    FOnlineSessionInfoPico& operator=(const FOnlineSessionInfoPico& Src) = delete;
#elif ENGINE_MINOR_VERSION > 24
    FOnlineSessionInfoPico(const FOnlineSessionInfoPico& Src)
    {
    }

    /** Hidden on purpose */
    FOnlineSessionInfoPico& operator=(const FOnlineSessionInfoPico& Src)
    {
        return *this;
    }
#endif


PACKAGE_SCOPE:

    FOnlineSessionInfoPico(ppfID RoomId);

    /** Unique Id for this session */
#if ENGINE_MAJOR_VERSION > 4
    FUniqueNetIdPicoRef SessionId;
#elif ENGINE_MINOR_VERSION > 26
    FUniqueNetIdPicoRef SessionId;
#elif ENGINE_MINOR_VERSION > 24
    FUniqueNetIdPico SessionId;
#endif


public:

    virtual ~FOnlineSessionInfoPico() {}

    bool operator==(const FOnlineSessionInfoPico& Other) const
    {
#if ENGINE_MAJOR_VERSION > 4
        return *Other.SessionId == *SessionId;
#elif ENGINE_MINOR_VERSION > 26
        return *Other.SessionId == *SessionId;
#elif ENGINE_MINOR_VERSION > 24
        return Other.SessionId == SessionId;
#endif
    }

    virtual const uint8* GetBytes() const override
    {
        return nullptr;
    }

    virtual int32 GetSize() const override
    {
        return 0;
    }

    virtual bool IsValid() const override
    {
        return true;
    }
#if ENGINE_MAJOR_VERSION > 4
    virtual FString ToString() const override
    {
        return SessionId->ToString();
    }

    virtual FString ToDebugString() const override
    {
        return FString::Printf(TEXT("SessionId: %s"), *SessionId->ToDebugString());
    }

    virtual const FUniqueNetId& GetSessionId() const override
    {
        return *SessionId;
    }
#elif ENGINE_MINOR_VERSION > 26
    virtual FString ToString() const override
    {
        return SessionId->ToString();
    }

    virtual FString ToDebugString() const override
    {
        return FString::Printf(TEXT("SessionId: %s"), *SessionId->ToDebugString());
    }

    virtual const FUniqueNetId& GetSessionId() const override
    {
        return *SessionId;
    }
#elif ENGINE_MINOR_VERSION > 24
    virtual FString ToString() const override
    {
        return SessionId.ToString();
    }

    virtual FString ToDebugString() const override
    {
        return FString::Printf(TEXT("SessionId: %s"), *SessionId.ToDebugString());
    }

    virtual const FUniqueNetId& GetSessionId() const override
    {
        return SessionId;
    }
#endif


};


/**
 *	Interface for reading data from a leaderboard service
 */
class FOnlineLeaderboardReadPico : FOnlineLeaderboardRead
{
public:
    int PageSize = 0;
    int PageIndex = 0;
};

#if ENGINE_MINOR_VERSION > 26
typedef TSharedRef<FOnlineLeaderboardReadPico, ESPMode::ThreadSafe> FOnlineLeaderboardReadPicoRef;
typedef TSharedPtr<FOnlineLeaderboardReadPico, ESPMode::ThreadSafe> FOnlineLeaderboardReadPicoPtr;
#elif ENGINE_MINOR_VERSION > 24

#endif