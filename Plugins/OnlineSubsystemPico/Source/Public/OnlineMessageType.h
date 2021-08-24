#pragma once
#include "CoreMinimal.h"
#include "Interfaces/OnlineAchievementsInterface.h"
#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#endif

enum EOnlineMessageType
{
	Message_Unknown = 0 , 
	Message_Achievements_AddCount = 0x03E76231 ,
	Message_Achievements_AddFields = 0x14AA2129 ,
	Message_Achievements_GetAllDefinitions = 0x03D3458D ,
	Message_Achievements_GetAllProgress = 0x4F9FDE1D ,
	Message_Achievements_GetDefinitionsByName = 0x629101BC ,
	Message_Achievements_GetAchievementDefinition = 0x2A7DD363 ,
	Message_Achievements_GetAchievementProgress = 0x2F42E464 ,
	Message_Achievements_GetNextAchievementDefinitionArrayPage = 0x2A7DD255 ,
	Message_Achievements_GetNextAchievementProgressArrayPage = 0x2F42E727 ,
	Message_Achievements_GetProgressByName = 0x152663B1 , 
	Message_Achievements_Unlock = 0x593CCBDD ,
	Message_Achievements_write_achievement_progress = 0x736BBDD ,
	Message_Achievements_verify_access_token = 0x032D103C ,
	Message_Notification_Networking_ConnectionStateChange = 0x5E02D49A 
};

enum class EAchievementType {
	Unknown = 0,
    Simple,
    Bitfield,
    Count
};

struct FOnlineAchievementDescPico : FOnlineAchievementDesc
{
	/** The way this achievement is unlocked */
	EAchievementType Type;

	/** The value that needs to be reached for "Count" Type achievements to unlock */
	uint64 Target;

	/** How many fields needs to be set for "Bitfield" Type achievements to unlock */
	uint32 BitfieldLength;

};


class FOnlineMessageHandle
{	
public:
	EOnlineMessageType MessageType;
	bool bIsError;
	uint64 MessageID;

#if PLATFORM_ANDROID
	jclass JavaMessage = nullptr;
#else
	void* JavaMessage = nullptr;
#endif
	
	FOnlineMessageHandle()
	:MessageType(Message_Unknown)
	,bIsError(true)
	,MessageID(0)
	{
		
	}

	FOnlineMessageHandle(int32 InMessageType,bool InbIsError, uint64 MessageID)
    :MessageType(static_cast<EOnlineMessageType>(InMessageType))
    ,bIsError(InbIsError)
    ,MessageID(MessageID)
	{
		
	}
	
	bool IsError()
	{
		return  bIsError;
	}

	uint64 GetMessageID()
	{
		return MessageID;
	}

	EOnlineMessageType GetMessageType()
	{
		return  MessageType;
	}
};

class FOnlineAchievementUpdateMessage : public FOnlineMessageHandle
{
private:
	bool bJustUnlocked;
	FString Name;
public:
	FOnlineAchievementUpdateMessage()
	:FOnlineMessageHandle(),
	bJustUnlocked(false),
	Name("")
	{
		
	}

	bool GetIsUnlock()
	{
		return bJustUnlocked;
	}

	FString GetAchievementName()
	{
		return  Name;
	}
};

class OnlineAchievementProgressMessage : public FOnlineMessageHandle
{
public:	
	FString Bitfield;
	uint64 Count;
	bool bIsUnlocked;
	FString  Name;
	FString UnlockTime;

	OnlineAchievementProgressMessage()
    :FOnlineMessageHandle(),
    Bitfield(""),
	Count(0),
	bIsUnlocked(false),
    Name(""),
	UnlockTime("")
	{
		
	}

	FString GetBitfield()
	{
		return Bitfield;
	}

	uint64 GetCount()
	{
		return Count;
	}

	bool GetbIsUnlocked()
	{
		return bIsUnlocked;
	}

	FString GetName()
	{
		return Name;
	}

	FString GetUnlockTime()
	{
		return UnlockTime;
	}	
};

class FOnlineAchievementMessage : public FOnlineMessageHandle
{
private :
	EAchievementType Type;
	FString Name;
	int32  BitfieldLength;
	uint64 Target;
public:
	FOnlineAchievementMessage()
    :FOnlineMessageHandle(),
    Type(EAchievementType::Unknown),
    Name(""),
    BitfieldLength(0),
    Target(0)
	{
		
	}

	EAchievementType GetAchievementType()
	{
		return Type;
	}
	FString GetAchievementName()
	{
		return Name;
	}

	int32  GetBitfieldLength()
	{
		return BitfieldLength;
	}
	uint64 GetTarget()
	{
		return Target;
	}
	
};
