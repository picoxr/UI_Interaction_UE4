// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EOnJoinSessionCompleteResultPicoType : uint8;
struct FPicoOnlineSessionSearchResult;
enum class ERtcStreamIndex : uint8;
enum class ERtcMediaDeviceType : uint8;
enum class ERtcMediaDeviceState : uint8;
enum class ERtcMediaDeviceError : uint8;
enum class ERtcAudioPlaybackDevice : uint8;
enum class ERtcMuteState : uint8;
enum class ERtcUserLeaveReasonType : uint8;
enum class ERtcJoinRoomType : uint8;
#ifdef ONLINESUBSYSTEMPICO_OnlineSubsystemPicoManager_generated_h
#error "OnlineSubsystemPicoManager.generated.h already included, missing '#pragma once' in OnlineSubsystemPicoManager.h"
#endif
#define ONLINESUBSYSTEMPICO_OnlineSubsystemPicoManager_generated_h

#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_186_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPicoOnlineSessionSearch_Statics; \
	ONLINESUBSYSTEMPICO_API static class UScriptStruct* StaticStruct();


template<> ONLINESUBSYSTEMPICO_API UScriptStruct* StaticStruct<struct FPicoOnlineSessionSearch>();

#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_175_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPicoOnlineSessionSearchResult_Statics; \
	ONLINESUBSYSTEMPICO_API static class UScriptStruct* StaticStruct();


template<> ONLINESUBSYSTEMPICO_API UScriptStruct* StaticStruct<struct FPicoOnlineSessionSearchResult>();

#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_134_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPicoNamedOnlineSession_Statics; \
	ONLINESUBSYSTEMPICO_API static class UScriptStruct* StaticStruct();


template<> ONLINESUBSYSTEMPICO_API UScriptStruct* StaticStruct<struct FPicoNamedOnlineSession>();

#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_111_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPicoOnlineSession_Statics; \
	ONLINESUBSYSTEMPICO_API static class UScriptStruct* StaticStruct();


template<> ONLINESUBSYSTEMPICO_API UScriptStruct* StaticStruct<struct FPicoOnlineSession>();

#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_75_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPicoOnlineSessionSettings_Statics; \
	ONLINESUBSYSTEMPICO_API static class UScriptStruct* StaticStruct();


template<> ONLINESUBSYSTEMPICO_API UScriptStruct* StaticStruct<struct FPicoOnlineSessionSettings>();

#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_60_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPicoFriend_Statics; \
	ONLINESUBSYSTEMPICO_API static class UScriptStruct* StaticStruct();


template<> ONLINESUBSYSTEMPICO_API UScriptStruct* StaticStruct<struct FPicoFriend>();

#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_272_DELEGATE \
struct _Script_OnlineSubsystemPico_eventOnRoomInviteAcceptedNotifyDelegate_Parms \
{ \
	FString RoomID; \
	bool bWasSuccessful; \
}; \
static inline void FOnRoomInviteAcceptedNotifyDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnRoomInviteAcceptedNotifyDelegate, const FString& RoomID, bool bWasSuccessful) \
{ \
	_Script_OnlineSubsystemPico_eventOnRoomInviteAcceptedNotifyDelegate_Parms Parms; \
	Parms.RoomID=RoomID; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	OnRoomInviteAcceptedNotifyDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_271_DELEGATE \
struct _Script_OnlineSubsystemPico_eventOnRoomUpdateNotifyDelegate_Parms \
{ \
	FString RoomID; \
	bool bWasSuccessful; \
}; \
static inline void FOnRoomUpdateNotifyDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnRoomUpdateNotifyDelegate, const FString& RoomID, bool bWasSuccessful) \
{ \
	_Script_OnlineSubsystemPico_eventOnRoomUpdateNotifyDelegate_Parms Parms; \
	Parms.RoomID=RoomID; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	OnRoomUpdateNotifyDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_270_DELEGATE \
struct _Script_OnlineSubsystemPico_eventOnRoomUpdateMembershipLockStatusNotifyDelegate_Parms \
{ \
	FString RoomID; \
	bool bWasSuccessful; \
}; \
static inline void FOnRoomUpdateMembershipLockStatusNotifyDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnRoomUpdateMembershipLockStatusNotifyDelegate, const FString& RoomID, bool bWasSuccessful) \
{ \
	_Script_OnlineSubsystemPico_eventOnRoomUpdateMembershipLockStatusNotifyDelegate_Parms Parms; \
	Parms.RoomID=RoomID; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	OnRoomUpdateMembershipLockStatusNotifyDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_269_DELEGATE \
struct _Script_OnlineSubsystemPico_eventOnRoomUpdateDataStoreNotifyDelegate_Parms \
{ \
	FString RoomID; \
	bool bWasSuccessful; \
}; \
static inline void FOnRoomUpdateDataStoreNotifyDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnRoomUpdateDataStoreNotifyDelegate, const FString& RoomID, bool bWasSuccessful) \
{ \
	_Script_OnlineSubsystemPico_eventOnRoomUpdateDataStoreNotifyDelegate_Parms Parms; \
	Parms.RoomID=RoomID; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	OnRoomUpdateDataStoreNotifyDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_268_DELEGATE \
struct _Script_OnlineSubsystemPico_eventOnRoomUpdateOwnerNotifyDelegate_Parms \
{ \
	bool bWasSuccessful; \
}; \
static inline void FOnRoomUpdateOwnerNotifyDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnRoomUpdateOwnerNotifyDelegate, bool bWasSuccessful) \
{ \
	_Script_OnlineSubsystemPico_eventOnRoomUpdateOwnerNotifyDelegate_Parms Parms; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	OnRoomUpdateOwnerNotifyDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_267_DELEGATE \
struct _Script_OnlineSubsystemPico_eventOnRoomKickUserNotifyDelegate_Parms \
{ \
	FString RoomID; \
	bool bWasSuccessful; \
}; \
static inline void FOnRoomKickUserNotifyDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnRoomKickUserNotifyDelegate, const FString& RoomID, bool bWasSuccessful) \
{ \
	_Script_OnlineSubsystemPico_eventOnRoomKickUserNotifyDelegate_Parms Parms; \
	Parms.RoomID=RoomID; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	OnRoomKickUserNotifyDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_266_DELEGATE \
struct _Script_OnlineSubsystemPico_eventOnRoomSetDescriptionNotifyDelegate_Parms \
{ \
	FString RoomID; \
	bool bWasSuccessful; \
}; \
static inline void FOnRoomSetDescriptionNotifyDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnRoomSetDescriptionNotifyDelegate, const FString& RoomID, bool bWasSuccessful) \
{ \
	_Script_OnlineSubsystemPico_eventOnRoomSetDescriptionNotifyDelegate_Parms Parms; \
	Parms.RoomID=RoomID; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	OnRoomSetDescriptionNotifyDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_265_DELEGATE \
struct _Script_OnlineSubsystemPico_eventOnRoomJoin2NotifyDelegate_Parms \
{ \
	FString RoomID; \
	bool bWasSuccessful; \
}; \
static inline void FOnRoomJoin2NotifyDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnRoomJoin2NotifyDelegate, const FString& RoomID, bool bWasSuccessful) \
{ \
	_Script_OnlineSubsystemPico_eventOnRoomJoin2NotifyDelegate_Parms Parms; \
	Parms.RoomID=RoomID; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	OnRoomJoin2NotifyDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_264_DELEGATE \
struct _Script_OnlineSubsystemPico_eventOnRoomLeaveNotifyDelegate_Parms \
{ \
	FString RoomID; \
	bool bWasSuccessful; \
}; \
static inline void FOnRoomLeaveNotifyDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnRoomLeaveNotifyDelegate, const FString& RoomID, bool bWasSuccessful) \
{ \
	_Script_OnlineSubsystemPico_eventOnRoomLeaveNotifyDelegate_Parms Parms; \
	Parms.RoomID=RoomID; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	OnRoomLeaveNotifyDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_263_DELEGATE \
struct _Script_OnlineSubsystemPico_eventOnMatchmakingCancel2NotifyDelegate_Parms \
{ \
	bool bWasSuccessful; \
}; \
static inline void FOnMatchmakingCancel2NotifyDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnMatchmakingCancel2NotifyDelegate, bool bWasSuccessful) \
{ \
	_Script_OnlineSubsystemPico_eventOnMatchmakingCancel2NotifyDelegate_Parms Parms; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	OnMatchmakingCancel2NotifyDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_262_DELEGATE \
struct _Script_OnlineSubsystemPico_eventOnGameStateResetNotifyDelegate_Parms \
{ \
	bool bWasSuccessful; \
}; \
static inline void FOnGameStateResetNotifyDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnGameStateResetNotifyDelegate, bool bWasSuccessful) \
{ \
	_Script_OnlineSubsystemPico_eventOnGameStateResetNotifyDelegate_Parms Parms; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	OnGameStateResetNotifyDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_261_DELEGATE \
struct _Script_OnlineSubsystemPico_eventOnGameRequestFailedNotifyDelegate_Parms \
{ \
	int32 Result; \
	bool bWasSuccessful; \
}; \
static inline void FOnGameRequestFailedNotifyDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnGameRequestFailedNotifyDelegate, int32 Result, bool bWasSuccessful) \
{ \
	_Script_OnlineSubsystemPico_eventOnGameRequestFailedNotifyDelegate_Parms Parms; \
	Parms.Result=Result; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	OnGameRequestFailedNotifyDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_260_DELEGATE \
struct _Script_OnlineSubsystemPico_eventOnGameConnectionNotifyDelegate_Parms \
{ \
	int32 Result; \
	bool bWasSuccessful; \
}; \
static inline void FOnGameConnectionNotifyDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnGameConnectionNotifyDelegate, int32 Result, bool bWasSuccessful) \
{ \
	_Script_OnlineSubsystemPico_eventOnGameConnectionNotifyDelegate_Parms Parms; \
	Parms.Result=Result; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	OnGameConnectionNotifyDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_258_DELEGATE \
struct _Script_OnlineSubsystemPico_eventPicoManagerOnJoinSessionCompleteDelegate_Parms \
{ \
	FName SessionName; \
	EOnJoinSessionCompleteResultPicoType Type; \
}; \
static inline void FPicoManagerOnJoinSessionCompleteDelegate_DelegateWrapper(const FScriptDelegate& PicoManagerOnJoinSessionCompleteDelegate, FName SessionName, EOnJoinSessionCompleteResultPicoType Type) \
{ \
	_Script_OnlineSubsystemPico_eventPicoManagerOnJoinSessionCompleteDelegate_Parms Parms; \
	Parms.SessionName=SessionName; \
	Parms.Type=Type; \
	PicoManagerOnJoinSessionCompleteDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_257_DELEGATE \
struct _Script_OnlineSubsystemPico_eventPicoManagerOnSingleSessionResultCompleteDelegate_Parms \
{ \
	int32 LocalUserNum; \
	bool bWasSuccessful; \
	FPicoOnlineSessionSearchResult SearchResult; \
}; \
static inline void FPicoManagerOnSingleSessionResultCompleteDelegate_DelegateWrapper(const FScriptDelegate& PicoManagerOnSingleSessionResultCompleteDelegate, int32 LocalUserNum, bool bWasSuccessful, FPicoOnlineSessionSearchResult const& SearchResult) \
{ \
	_Script_OnlineSubsystemPico_eventPicoManagerOnSingleSessionResultCompleteDelegate_Parms Parms; \
	Parms.LocalUserNum=LocalUserNum; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	Parms.SearchResult=SearchResult; \
	PicoManagerOnSingleSessionResultCompleteDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_256_DELEGATE \
struct _Script_OnlineSubsystemPico_eventPicoManagerOnFindSessionCompleteDelegate_Parms \
{ \
	bool bWasSuccessful; \
}; \
static inline void FPicoManagerOnFindSessionCompleteDelegate_DelegateWrapper(const FScriptDelegate& PicoManagerOnFindSessionCompleteDelegate, bool bWasSuccessful) \
{ \
	_Script_OnlineSubsystemPico_eventPicoManagerOnFindSessionCompleteDelegate_Parms Parms; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	PicoManagerOnFindSessionCompleteDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_253_DELEGATE \
struct _Script_OnlineSubsystemPico_eventPicoManagerOnMatchmakingCompleteDelegate_Parms \
{ \
	FName SessionName; \
	bool bWasSuccessful; \
}; \
static inline void FPicoManagerOnMatchmakingCompleteDelegate_DelegateWrapper(const FScriptDelegate& PicoManagerOnMatchmakingCompleteDelegate, FName SessionName, bool bWasSuccessful) \
{ \
	_Script_OnlineSubsystemPico_eventPicoManagerOnMatchmakingCompleteDelegate_Parms Parms; \
	Parms.SessionName=SessionName; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	PicoManagerOnMatchmakingCompleteDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_252_DELEGATE \
struct _Script_OnlineSubsystemPico_eventPicoManagerOnCancelMatchmakingCompleteDelegate_Parms \
{ \
	FName SessionName; \
	bool bWasSuccessful; \
}; \
static inline void FPicoManagerOnCancelMatchmakingCompleteDelegate_DelegateWrapper(const FScriptDelegate& PicoManagerOnCancelMatchmakingCompleteDelegate, FName SessionName, bool bWasSuccessful) \
{ \
	_Script_OnlineSubsystemPico_eventPicoManagerOnCancelMatchmakingCompleteDelegate_Parms Parms; \
	Parms.SessionName=SessionName; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	PicoManagerOnCancelMatchmakingCompleteDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_251_DELEGATE \
struct _Script_OnlineSubsystemPico_eventPicoManagerOnDestroySessionCompleteDelegate_Parms \
{ \
	FName SessionName; \
	bool bWasSuccessful; \
}; \
static inline void FPicoManagerOnDestroySessionCompleteDelegate_DelegateWrapper(const FScriptDelegate& PicoManagerOnDestroySessionCompleteDelegate, FName SessionName, bool bWasSuccessful) \
{ \
	_Script_OnlineSubsystemPico_eventPicoManagerOnDestroySessionCompleteDelegate_Parms Parms; \
	Parms.SessionName=SessionName; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	PicoManagerOnDestroySessionCompleteDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_250_DELEGATE \
struct _Script_OnlineSubsystemPico_eventPicoManagerOnEndSessionCompleteDelegate_Parms \
{ \
	FName SessionName; \
	bool bWasSuccessful; \
}; \
static inline void FPicoManagerOnEndSessionCompleteDelegate_DelegateWrapper(const FScriptDelegate& PicoManagerOnEndSessionCompleteDelegate, FName SessionName, bool bWasSuccessful) \
{ \
	_Script_OnlineSubsystemPico_eventPicoManagerOnEndSessionCompleteDelegate_Parms Parms; \
	Parms.SessionName=SessionName; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	PicoManagerOnEndSessionCompleteDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_249_DELEGATE \
struct _Script_OnlineSubsystemPico_eventPicoManagerOnUpdateSessionCompleteDelegate_Parms \
{ \
	FName SessionName; \
	bool bWasSuccessful; \
}; \
static inline void FPicoManagerOnUpdateSessionCompleteDelegate_DelegateWrapper(const FScriptDelegate& PicoManagerOnUpdateSessionCompleteDelegate, FName SessionName, bool bWasSuccessful) \
{ \
	_Script_OnlineSubsystemPico_eventPicoManagerOnUpdateSessionCompleteDelegate_Parms Parms; \
	Parms.SessionName=SessionName; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	PicoManagerOnUpdateSessionCompleteDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_248_DELEGATE \
struct _Script_OnlineSubsystemPico_eventPicoManagerOnStartSessionCompleteDelegate_Parms \
{ \
	FName SessionName; \
	bool bWasSuccessful; \
}; \
static inline void FPicoManagerOnStartSessionCompleteDelegate_DelegateWrapper(const FScriptDelegate& PicoManagerOnStartSessionCompleteDelegate, FName SessionName, bool bWasSuccessful) \
{ \
	_Script_OnlineSubsystemPico_eventPicoManagerOnStartSessionCompleteDelegate_Parms Parms; \
	Parms.SessionName=SessionName; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	PicoManagerOnStartSessionCompleteDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_247_DELEGATE \
struct _Script_OnlineSubsystemPico_eventPicoManagerOnCreateSessionCompleteDelegate_Parms \
{ \
	FName SessionName; \
	bool bWasSuccessful; \
}; \
static inline void FPicoManagerOnCreateSessionCompleteDelegate_DelegateWrapper(const FScriptDelegate& PicoManagerOnCreateSessionCompleteDelegate, FName SessionName, bool bWasSuccessful) \
{ \
	_Script_OnlineSubsystemPico_eventPicoManagerOnCreateSessionCompleteDelegate_Parms Parms; \
	Parms.SessionName=SessionName; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	PicoManagerOnCreateSessionCompleteDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_244_DELEGATE \
struct _Script_OnlineSubsystemPico_eventOnlineManagerRtcGetTokenDelegate_Parms \
{ \
	FString Token; \
	bool IsSuccessed; \
	FString ErrorMessage; \
}; \
static inline void FOnlineManagerRtcGetTokenDelegate_DelegateWrapper(const FScriptDelegate& OnlineManagerRtcGetTokenDelegate, const FString& Token, bool IsSuccessed, const FString& ErrorMessage) \
{ \
	_Script_OnlineSubsystemPico_eventOnlineManagerRtcGetTokenDelegate_Parms Parms; \
	Parms.Token=Token; \
	Parms.IsSuccessed=IsSuccessed ? true : false; \
	Parms.ErrorMessage=ErrorMessage; \
	OnlineManagerRtcGetTokenDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_242_DELEGATE \
struct _Script_OnlineSubsystemPico_eventRtcUserStopAudioCaptureDelegate_Parms \
{ \
	FString StringMessage; \
}; \
static inline void FRtcUserStopAudioCaptureDelegate_DelegateWrapper(const FMulticastScriptDelegate& RtcUserStopAudioCaptureDelegate, const FString& StringMessage) \
{ \
	_Script_OnlineSubsystemPico_eventRtcUserStopAudioCaptureDelegate_Parms Parms; \
	Parms.StringMessage=StringMessage; \
	RtcUserStopAudioCaptureDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_241_DELEGATE \
struct _Script_OnlineSubsystemPico_eventRtcUserStartAudioCaptureDelegate_Parms \
{ \
	FString StringMessage; \
}; \
static inline void FRtcUserStartAudioCaptureDelegate_DelegateWrapper(const FMulticastScriptDelegate& RtcUserStartAudioCaptureDelegate, const FString& StringMessage) \
{ \
	_Script_OnlineSubsystemPico_eventRtcUserStartAudioCaptureDelegate_Parms Parms; \
	Parms.StringMessage=StringMessage; \
	RtcUserStartAudioCaptureDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_240_DELEGATE \
struct _Script_OnlineSubsystemPico_eventRtcConnectStateChangedDelegate_Parms \
{ \
	FString StringMessage; \
}; \
static inline void FRtcConnectStateChangedDelegate_DelegateWrapper(const FMulticastScriptDelegate& RtcConnectStateChangedDelegate, const FString& StringMessage) \
{ \
	_Script_OnlineSubsystemPico_eventRtcConnectStateChangedDelegate_Parms Parms; \
	Parms.StringMessage=StringMessage; \
	RtcConnectStateChangedDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_239_DELEGATE \
struct _Script_OnlineSubsystemPico_eventRtcErrorDelegate_Parms \
{ \
	int32 MessageCode; \
}; \
static inline void FRtcErrorDelegate_DelegateWrapper(const FMulticastScriptDelegate& RtcErrorDelegate, int32 MessageCode) \
{ \
	_Script_OnlineSubsystemPico_eventRtcErrorDelegate_Parms Parms; \
	Parms.MessageCode=MessageCode; \
	RtcErrorDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_238_DELEGATE \
struct _Script_OnlineSubsystemPico_eventRtcWarnDelegate_Parms \
{ \
	int32 MessageCode; \
}; \
static inline void FRtcWarnDelegate_DelegateWrapper(const FMulticastScriptDelegate& RtcWarnDelegate, int32 MessageCode) \
{ \
	_Script_OnlineSubsystemPico_eventRtcWarnDelegate_Parms Parms; \
	Parms.MessageCode=MessageCode; \
	RtcWarnDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_236_DELEGATE \
struct _Script_OnlineSubsystemPico_eventRtcRemoteAudioPropertiesReportDelegate_Parms \
{ \
	int32 TotalRemoteVolume; \
	TArray<int32> Volumes; \
	TArray<FString> RoomIds; \
	TArray<FString> UserIds; \
	TArray<ERtcStreamIndex> StreamIndexs; \
}; \
static inline void FRtcRemoteAudioPropertiesReportDelegate_DelegateWrapper(const FMulticastScriptDelegate& RtcRemoteAudioPropertiesReportDelegate, int32 TotalRemoteVolume, TArray<int32> const& Volumes, TArray<FString> const& RoomIds, TArray<FString> const& UserIds, TArray<ERtcStreamIndex> const& StreamIndexs) \
{ \
	_Script_OnlineSubsystemPico_eventRtcRemoteAudioPropertiesReportDelegate_Parms Parms; \
	Parms.TotalRemoteVolume=TotalRemoteVolume; \
	Parms.Volumes=Volumes; \
	Parms.RoomIds=RoomIds; \
	Parms.UserIds=UserIds; \
	Parms.StreamIndexs=StreamIndexs; \
	RtcRemoteAudioPropertiesReportDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_235_DELEGATE \
struct _Script_OnlineSubsystemPico_eventRtcLocalAudioPropertiesReportDelegate_Parms \
{ \
	TArray<ERtcStreamIndex> StreamIndexs; \
	TArray<int32> Volumes; \
}; \
static inline void FRtcLocalAudioPropertiesReportDelegate_DelegateWrapper(const FMulticastScriptDelegate& RtcLocalAudioPropertiesReportDelegate, TArray<ERtcStreamIndex> const& StreamIndexs, TArray<int32> const& Volumes) \
{ \
	_Script_OnlineSubsystemPico_eventRtcLocalAudioPropertiesReportDelegate_Parms Parms; \
	Parms.StreamIndexs=StreamIndexs; \
	Parms.Volumes=Volumes; \
	RtcLocalAudioPropertiesReportDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_234_DELEGATE \
struct _Script_OnlineSubsystemPico_eventRtcMediaDeviceChangeInfoDelegate_Parms \
{ \
	FString DeviceId; \
	ERtcMediaDeviceType MediaDeciveType; \
	ERtcMediaDeviceState MediaDeviceState; \
	ERtcMediaDeviceError MediaDeviceError; \
}; \
static inline void FRtcMediaDeviceChangeInfoDelegate_DelegateWrapper(const FMulticastScriptDelegate& RtcMediaDeviceChangeInfoDelegate, const FString& DeviceId, ERtcMediaDeviceType MediaDeciveType, ERtcMediaDeviceState MediaDeviceState, ERtcMediaDeviceError MediaDeviceError) \
{ \
	_Script_OnlineSubsystemPico_eventRtcMediaDeviceChangeInfoDelegate_Parms Parms; \
	Parms.DeviceId=DeviceId; \
	Parms.MediaDeciveType=MediaDeciveType; \
	Parms.MediaDeviceState=MediaDeviceState; \
	Parms.MediaDeviceError=MediaDeviceError; \
	RtcMediaDeviceChangeInfoDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_233_DELEGATE \
struct _Script_OnlineSubsystemPico_eventRtcAudioChangePlaybackDeviceDelegate_Parms \
{ \
	ERtcAudioPlaybackDevice RtcAudioPlaybackDevice; \
}; \
static inline void FRtcAudioChangePlaybackDeviceDelegate_DelegateWrapper(const FMulticastScriptDelegate& RtcAudioChangePlaybackDeviceDelegate, ERtcAudioPlaybackDevice RtcAudioPlaybackDevice) \
{ \
	_Script_OnlineSubsystemPico_eventRtcAudioChangePlaybackDeviceDelegate_Parms Parms; \
	Parms.RtcAudioPlaybackDevice=RtcAudioPlaybackDevice; \
	RtcAudioChangePlaybackDeviceDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_232_DELEGATE \
struct _Script_OnlineSubsystemPico_eventRtcRoomMuteStateDelegate_Parms \
{ \
	FString UserId; \
	ERtcMuteState RtcMuteState; \
}; \
static inline void FRtcRoomMuteStateDelegate_DelegateWrapper(const FMulticastScriptDelegate& RtcRoomMuteStateDelegate, const FString& UserId, ERtcMuteState RtcMuteState) \
{ \
	_Script_OnlineSubsystemPico_eventRtcRoomMuteStateDelegate_Parms Parms; \
	Parms.UserId=UserId; \
	Parms.RtcMuteState=RtcMuteState; \
	RtcRoomMuteStateDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_231_DELEGATE \
struct _Script_OnlineSubsystemPico_eventRtcRoomErrorDelegate_Parms \
{ \
	int32 Code; \
	FString RoomId; \
}; \
static inline void FRtcRoomErrorDelegate_DelegateWrapper(const FMulticastScriptDelegate& RtcRoomErrorDelegate, int32 Code, const FString& RoomId) \
{ \
	_Script_OnlineSubsystemPico_eventRtcRoomErrorDelegate_Parms Parms; \
	Parms.Code=Code; \
	Parms.RoomId=RoomId; \
	RtcRoomErrorDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_230_DELEGATE \
struct _Script_OnlineSubsystemPico_eventRtcRoomWarnDelegate_Parms \
{ \
	int32 Code; \
	FString RoomId; \
}; \
static inline void FRtcRoomWarnDelegate_DelegateWrapper(const FMulticastScriptDelegate& RtcRoomWarnDelegate, int32 Code, const FString& RoomId) \
{ \
	_Script_OnlineSubsystemPico_eventRtcRoomWarnDelegate_Parms Parms; \
	Parms.Code=Code; \
	Parms.RoomId=RoomId; \
	RtcRoomWarnDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_229_DELEGATE \
struct _Script_OnlineSubsystemPico_eventRtcUserLeaveInfoDelegate_Parms \
{ \
	FString UserId; \
	ERtcUserLeaveReasonType RtcUserLeaveReasonType; \
	FString RoomId; \
}; \
static inline void FRtcUserLeaveInfoDelegate_DelegateWrapper(const FMulticastScriptDelegate& RtcUserLeaveInfoDelegate, const FString& UserId, ERtcUserLeaveReasonType RtcUserLeaveReasonType, const FString& RoomId) \
{ \
	_Script_OnlineSubsystemPico_eventRtcUserLeaveInfoDelegate_Parms Parms; \
	Parms.UserId=UserId; \
	Parms.RtcUserLeaveReasonType=RtcUserLeaveReasonType; \
	Parms.RoomId=RoomId; \
	RtcUserLeaveInfoDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_228_DELEGATE \
struct _Script_OnlineSubsystemPico_eventRtcUserJoinInfoDelegate_Parms \
{ \
	FString UserId; \
	FString UserExtra; \
	int32 Elapsed; \
	FString RoomId; \
}; \
static inline void FRtcUserJoinInfoDelegate_DelegateWrapper(const FMulticastScriptDelegate& RtcUserJoinInfoDelegate, const FString& UserId, const FString& UserExtra, int32 Elapsed, const FString& RoomId) \
{ \
	_Script_OnlineSubsystemPico_eventRtcUserJoinInfoDelegate_Parms Parms; \
	Parms.UserId=UserId; \
	Parms.UserExtra=UserExtra; \
	Parms.Elapsed=Elapsed; \
	Parms.RoomId=RoomId; \
	RtcUserJoinInfoDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_227_DELEGATE \
struct _Script_OnlineSubsystemPico_eventRtcRoomStateDelegate_Parms \
{ \
	int32 TotalDuration; \
	int32 UserCount; \
	FString RoomId; \
}; \
static inline void FRtcRoomStateDelegate_DelegateWrapper(const FMulticastScriptDelegate& RtcRoomStateDelegate, int32 TotalDuration, int32 UserCount, const FString& RoomId) \
{ \
	_Script_OnlineSubsystemPico_eventRtcRoomStateDelegate_Parms Parms; \
	Parms.TotalDuration=TotalDuration; \
	Parms.UserCount=UserCount; \
	Parms.RoomId=RoomId; \
	RtcRoomStateDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_226_DELEGATE \
struct _Script_OnlineSubsystemPico_eventRtcLeaveRoomResultDelegate_Parms \
{ \
	FString RoomId; \
}; \
static inline void FRtcLeaveRoomResultDelegate_DelegateWrapper(const FMulticastScriptDelegate& RtcLeaveRoomResultDelegate, const FString& RoomId) \
{ \
	_Script_OnlineSubsystemPico_eventRtcLeaveRoomResultDelegate_Parms Parms; \
	Parms.RoomId=RoomId; \
	RtcLeaveRoomResultDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_225_DELEGATE \
struct _Script_OnlineSubsystemPico_eventRtcJoinRoomResultDelegate_Parms \
{ \
	FString RoomId; \
	FString UserId; \
	int32 ErrorCode; \
	int32 Elapsed; \
	ERtcJoinRoomType InJoinRoomType; \
}; \
static inline void FRtcJoinRoomResultDelegate_DelegateWrapper(const FMulticastScriptDelegate& RtcJoinRoomResultDelegate, const FString& RoomId, const FString& UserId, int32 ErrorCode, int32 Elapsed, ERtcJoinRoomType InJoinRoomType) \
{ \
	_Script_OnlineSubsystemPico_eventRtcJoinRoomResultDelegate_Parms Parms; \
	Parms.RoomId=RoomId; \
	Parms.UserId=UserId; \
	Parms.ErrorCode=ErrorCode; \
	Parms.Elapsed=Elapsed; \
	Parms.InJoinRoomType=InJoinRoomType; \
	RtcJoinRoomResultDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_222_DELEGATE \
struct _Script_OnlineSubsystemPico_eventOnlineManagerReadFriendListDelegate_Parms \
{ \
	int32 LocalUserNum; \
	bool bWasSuccessful; \
	FString ListName; \
	FString ErrorStr; \
}; \
static inline void FOnlineManagerReadFriendListDelegate_DelegateWrapper(const FScriptDelegate& OnlineManagerReadFriendListDelegate, int32 LocalUserNum, bool bWasSuccessful, const FString& ListName, const FString& ErrorStr) \
{ \
	_Script_OnlineSubsystemPico_eventOnlineManagerReadFriendListDelegate_Parms Parms; \
	Parms.LocalUserNum=LocalUserNum; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	Parms.ListName=ListName; \
	Parms.ErrorStr=ErrorStr; \
	OnlineManagerReadFriendListDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_219_DELEGATE \
struct _Script_OnlineSubsystemPico_eventOnlineManagerLoginCompleteDelegate_Parms \
{ \
	int32 LocalUserNum; \
	FString UserId; \
	bool bIsSuccessed; \
	FString ErrorMessage; \
}; \
static inline void FOnlineManagerLoginCompleteDelegate_DelegateWrapper(const FScriptDelegate& OnlineManagerLoginCompleteDelegate, int32 LocalUserNum, const FString& UserId, bool bIsSuccessed, const FString& ErrorMessage) \
{ \
	_Script_OnlineSubsystemPico_eventOnlineManagerLoginCompleteDelegate_Parms Parms; \
	Parms.LocalUserNum=LocalUserNum; \
	Parms.UserId=UserId; \
	Parms.bIsSuccessed=bIsSuccessed ? true : false; \
	Parms.ErrorMessage=ErrorMessage; \
	OnlineManagerLoginCompleteDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_277_SPARSE_DATA
#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_277_RPC_WRAPPERS
#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_277_RPC_WRAPPERS_NO_PURE_DECLS
#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_277_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOnlineSubsystemPicoManager(); \
	friend struct Z_Construct_UClass_UOnlineSubsystemPicoManager_Statics; \
public: \
	DECLARE_CLASS(UOnlineSubsystemPicoManager, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UOnlineSubsystemPicoManager)


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_277_INCLASS \
private: \
	static void StaticRegisterNativesUOnlineSubsystemPicoManager(); \
	friend struct Z_Construct_UClass_UOnlineSubsystemPicoManager_Statics; \
public: \
	DECLARE_CLASS(UOnlineSubsystemPicoManager, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UOnlineSubsystemPicoManager)


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_277_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOnlineSubsystemPicoManager(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOnlineSubsystemPicoManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOnlineSubsystemPicoManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOnlineSubsystemPicoManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOnlineSubsystemPicoManager(UOnlineSubsystemPicoManager&&); \
	NO_API UOnlineSubsystemPicoManager(const UOnlineSubsystemPicoManager&); \
public:


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_277_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOnlineSubsystemPicoManager(UOnlineSubsystemPicoManager&&); \
	NO_API UOnlineSubsystemPicoManager(const UOnlineSubsystemPicoManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOnlineSubsystemPicoManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOnlineSubsystemPicoManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UOnlineSubsystemPicoManager)


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_277_PRIVATE_PROPERTY_OFFSET
#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_274_PROLOG
#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_277_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_277_PRIVATE_PROPERTY_OFFSET \
	UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_277_SPARSE_DATA \
	UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_277_RPC_WRAPPERS \
	UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_277_INCLASS \
	UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_277_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_277_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_277_PRIVATE_PROPERTY_OFFSET \
	UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_277_SPARSE_DATA \
	UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_277_RPC_WRAPPERS_NO_PURE_DECLS \
	UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_277_INCLASS_NO_PURE_DECLS \
	UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h_277_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<class UOnlineSubsystemPicoManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Private_OnlineSubsystemPicoManager_h


#define FOREACH_ENUM_EONLINESESSIONSTATEPICOTYPE(op) \
	op(EOnlineSessionStatePicoType::NoSession) \
	op(EOnlineSessionStatePicoType::Creating) \
	op(EOnlineSessionStatePicoType::Pending) \
	op(EOnlineSessionStatePicoType::Starting) \
	op(EOnlineSessionStatePicoType::InProgress) \
	op(EOnlineSessionStatePicoType::Ending) \
	op(EOnlineSessionStatePicoType::Ended) \
	op(EOnlineSessionStatePicoType::Destroying) 

enum class EOnlineSessionStatePicoType : uint8;
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<EOnlineSessionStatePicoType>();

#define FOREACH_ENUM_EONJOINSESSIONCOMPLETERESULTPICOTYPE(op) \
	op(EOnJoinSessionCompleteResultPicoType::Success) \
	op(EOnJoinSessionCompleteResultPicoType::SessionIsFull) \
	op(EOnJoinSessionCompleteResultPicoType::SessionDoesNotExist) \
	op(EOnJoinSessionCompleteResultPicoType::CouldNotRetrieveAddress) \
	op(EOnJoinSessionCompleteResultPicoType::AlreadyInSession) \
	op(EOnJoinSessionCompleteResultPicoType::UnknownError) 

enum class EOnJoinSessionCompleteResultPicoType : uint8;
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<EOnJoinSessionCompleteResultPicoType>();

#define FOREACH_ENUM_EONLINEASYNCTASKSTATEPICOTYPE(op) \
	op(EOnlineAsyncTaskStatePicoType::NotStarted) \
	op(EOnlineAsyncTaskStatePicoType::InProgress) \
	op(EOnlineAsyncTaskStatePicoType::Done) \
	op(EOnlineAsyncTaskStatePicoType::Failed) 

enum class EOnlineAsyncTaskStatePicoType : uint8;
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<EOnlineAsyncTaskStatePicoType>();

#define FOREACH_ENUM_EPRESENCESTATUS(op) \
	op(EPresenceStatus::Unknow) \
	op(EPresenceStatus::OnLine) \
	op(EPresenceStatus::OffLine) 

enum class EPresenceStatus : uint8;
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<EPresenceStatus>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
