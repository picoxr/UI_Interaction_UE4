// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UOnlineSubsystemPicoManager;
class UObject;
struct FPicoOnlineSessionSettings;
struct FPicoOnlineSession;
struct FPicoNamedOnlineSession;
enum class EOnlineSessionStatePicoType : uint8;
struct FPicoOnlineSessionSearchResult;
struct FPicoOnlineSessionSearch;
enum class ERtcEarMonitorMode : uint8;
enum class ERtcStreamIndex : uint8;
enum class ERtcAudioScenarioType : uint8;
enum class ERtcAudioPlaybackDevice : uint8;
enum class ERtcPauseResumeMediaType : uint8;
enum class ERtcMuteState : uint8;
enum class ERtcRoomProfileType : uint8;
enum class ERtcEngineInitResult : uint8;
struct FPicoFriend;
#ifdef ONLINESUBSYSTEMPICO_OnlinePicoFunctionLibrary_generated_h
#error "OnlinePicoFunctionLibrary.generated.h already included, missing '#pragma once' in OnlinePicoFunctionLibrary.h"
#endif
#define ONLINESUBSYSTEMPICO_OnlinePicoFunctionLibrary_generated_h

#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_OnlinePicoFunctionLibrary_h_16_DELEGATE \
struct _Script_OnlineSubsystemPico_eventOnlinePicoVerifyAppDelegate_Parms \
{ \
	int32 code; \
}; \
static inline void FOnlinePicoVerifyAppDelegate_DelegateWrapper(const FScriptDelegate& OnlinePicoVerifyAppDelegate, int32 const& code) \
{ \
	_Script_OnlineSubsystemPico_eventOnlinePicoVerifyAppDelegate_Parms Parms; \
	Parms.code=code; \
	OnlinePicoVerifyAppDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_OnlinePicoFunctionLibrary_h_24_SPARSE_DATA
#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_OnlinePicoFunctionLibrary_h_24_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetOpenId); \
	DECLARE_FUNCTION(execPicoGetDeviceSN); \
	DECLARE_FUNCTION(execPicoEntitlementVerifyCheck); \
	DECLARE_FUNCTION(execPicoEntitlementVerifyAppDelegate); \
	DECLARE_FUNCTION(execGetOnlineSubsystemPicoManager); \
	DECLARE_FUNCTION(execGetSessionSettings); \
	DECLARE_FUNCTION(execAddNamedSession); \
	DECLARE_FUNCTION(execAddNamedSessionBySettings); \
	DECLARE_FUNCTION(execGetNamedSession); \
	DECLARE_FUNCTION(execGetSessionState); \
	DECLARE_FUNCTION(execDumpSessionState); \
	DECLARE_FUNCTION(execJoinSession); \
	DECLARE_FUNCTION(execFindSessionById); \
	DECLARE_FUNCTION(execFindSessions); \
	DECLARE_FUNCTION(execCancelMatchmaking); \
	DECLARE_FUNCTION(execStartMatchmaking); \
	DECLARE_FUNCTION(execIsPlayerInSession); \
	DECLARE_FUNCTION(execDestroySession); \
	DECLARE_FUNCTION(execEndSession); \
	DECLARE_FUNCTION(execUpdateSession); \
	DECLARE_FUNCTION(execStartSession); \
	DECLARE_FUNCTION(execCreateSession); \
	DECLARE_FUNCTION(execRtcUpdateToken); \
	DECLARE_FUNCTION(execRtcStopAudioCapture); \
	DECLARE_FUNCTION(execRtcStartAudioCapture); \
	DECLARE_FUNCTION(execRtcSetPlaybackVolume); \
	DECLARE_FUNCTION(execRtcSetEarMonitorVolume); \
	DECLARE_FUNCTION(execRtcSetEarMonitorMode); \
	DECLARE_FUNCTION(execRtcSetCaptureVolume); \
	DECLARE_FUNCTION(execRtcSetAudioScenario); \
	DECLARE_FUNCTION(execRtcSetAudioPlaybackDevice); \
	DECLARE_FUNCTION(execRtcRoomResumeAllSubscribedStream); \
	DECLARE_FUNCTION(execRtcRoomPauseAllSubscribedStream); \
	DECLARE_FUNCTION(execRtcUnPublishRoom); \
	DECLARE_FUNCTION(execRtcPublishRoom); \
	DECLARE_FUNCTION(execRtcMuteLocalAudio); \
	DECLARE_FUNCTION(execRtcLeaveRoom); \
	DECLARE_FUNCTION(execRtcEnableAudioPropertiesReport); \
	DECLARE_FUNCTION(execRtcDestroyRoom); \
	DECLARE_FUNCTION(execPicoRtcJoinRoom); \
	DECLARE_FUNCTION(execPicoGetRtcEngineInit); \
	DECLARE_FUNCTION(execPicoRtcGetToken); \
	DECLARE_FUNCTION(execPicoGetFriend); \
	DECLARE_FUNCTION(execPicoGetFriendList); \
	DECLARE_FUNCTION(execPicoReadFriendList); \
	DECLARE_FUNCTION(execPicoGetNickName); \
	DECLARE_FUNCTION(execPicoLogin);


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_OnlinePicoFunctionLibrary_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetOpenId); \
	DECLARE_FUNCTION(execPicoGetDeviceSN); \
	DECLARE_FUNCTION(execPicoEntitlementVerifyCheck); \
	DECLARE_FUNCTION(execPicoEntitlementVerifyAppDelegate); \
	DECLARE_FUNCTION(execGetOnlineSubsystemPicoManager); \
	DECLARE_FUNCTION(execGetSessionSettings); \
	DECLARE_FUNCTION(execAddNamedSession); \
	DECLARE_FUNCTION(execAddNamedSessionBySettings); \
	DECLARE_FUNCTION(execGetNamedSession); \
	DECLARE_FUNCTION(execGetSessionState); \
	DECLARE_FUNCTION(execDumpSessionState); \
	DECLARE_FUNCTION(execJoinSession); \
	DECLARE_FUNCTION(execFindSessionById); \
	DECLARE_FUNCTION(execFindSessions); \
	DECLARE_FUNCTION(execCancelMatchmaking); \
	DECLARE_FUNCTION(execStartMatchmaking); \
	DECLARE_FUNCTION(execIsPlayerInSession); \
	DECLARE_FUNCTION(execDestroySession); \
	DECLARE_FUNCTION(execEndSession); \
	DECLARE_FUNCTION(execUpdateSession); \
	DECLARE_FUNCTION(execStartSession); \
	DECLARE_FUNCTION(execCreateSession); \
	DECLARE_FUNCTION(execRtcUpdateToken); \
	DECLARE_FUNCTION(execRtcStopAudioCapture); \
	DECLARE_FUNCTION(execRtcStartAudioCapture); \
	DECLARE_FUNCTION(execRtcSetPlaybackVolume); \
	DECLARE_FUNCTION(execRtcSetEarMonitorVolume); \
	DECLARE_FUNCTION(execRtcSetEarMonitorMode); \
	DECLARE_FUNCTION(execRtcSetCaptureVolume); \
	DECLARE_FUNCTION(execRtcSetAudioScenario); \
	DECLARE_FUNCTION(execRtcSetAudioPlaybackDevice); \
	DECLARE_FUNCTION(execRtcRoomResumeAllSubscribedStream); \
	DECLARE_FUNCTION(execRtcRoomPauseAllSubscribedStream); \
	DECLARE_FUNCTION(execRtcUnPublishRoom); \
	DECLARE_FUNCTION(execRtcPublishRoom); \
	DECLARE_FUNCTION(execRtcMuteLocalAudio); \
	DECLARE_FUNCTION(execRtcLeaveRoom); \
	DECLARE_FUNCTION(execRtcEnableAudioPropertiesReport); \
	DECLARE_FUNCTION(execRtcDestroyRoom); \
	DECLARE_FUNCTION(execPicoRtcJoinRoom); \
	DECLARE_FUNCTION(execPicoGetRtcEngineInit); \
	DECLARE_FUNCTION(execPicoRtcGetToken); \
	DECLARE_FUNCTION(execPicoGetFriend); \
	DECLARE_FUNCTION(execPicoGetFriendList); \
	DECLARE_FUNCTION(execPicoReadFriendList); \
	DECLARE_FUNCTION(execPicoGetNickName); \
	DECLARE_FUNCTION(execPicoLogin);


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_OnlinePicoFunctionLibrary_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOnlinePicoFunctionLibrary(); \
	friend struct Z_Construct_UClass_UOnlinePicoFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UOnlinePicoFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UOnlinePicoFunctionLibrary)


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_OnlinePicoFunctionLibrary_h_24_INCLASS \
private: \
	static void StaticRegisterNativesUOnlinePicoFunctionLibrary(); \
	friend struct Z_Construct_UClass_UOnlinePicoFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UOnlinePicoFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UOnlinePicoFunctionLibrary)


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_OnlinePicoFunctionLibrary_h_24_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOnlinePicoFunctionLibrary(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOnlinePicoFunctionLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOnlinePicoFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOnlinePicoFunctionLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOnlinePicoFunctionLibrary(UOnlinePicoFunctionLibrary&&); \
	NO_API UOnlinePicoFunctionLibrary(const UOnlinePicoFunctionLibrary&); \
public:


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_OnlinePicoFunctionLibrary_h_24_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOnlinePicoFunctionLibrary(UOnlinePicoFunctionLibrary&&); \
	NO_API UOnlinePicoFunctionLibrary(const UOnlinePicoFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOnlinePicoFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOnlinePicoFunctionLibrary); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UOnlinePicoFunctionLibrary)


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_OnlinePicoFunctionLibrary_h_24_PRIVATE_PROPERTY_OFFSET
#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_OnlinePicoFunctionLibrary_h_21_PROLOG
#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_OnlinePicoFunctionLibrary_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_OnlinePicoFunctionLibrary_h_24_PRIVATE_PROPERTY_OFFSET \
	UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_OnlinePicoFunctionLibrary_h_24_SPARSE_DATA \
	UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_OnlinePicoFunctionLibrary_h_24_RPC_WRAPPERS \
	UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_OnlinePicoFunctionLibrary_h_24_INCLASS \
	UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_OnlinePicoFunctionLibrary_h_24_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_OnlinePicoFunctionLibrary_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_OnlinePicoFunctionLibrary_h_24_PRIVATE_PROPERTY_OFFSET \
	UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_OnlinePicoFunctionLibrary_h_24_SPARSE_DATA \
	UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_OnlinePicoFunctionLibrary_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_OnlinePicoFunctionLibrary_h_24_INCLASS_NO_PURE_DECLS \
	UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_OnlinePicoFunctionLibrary_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<class UOnlinePicoFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UI_Interaction_UE4_main_Plugins_OnlineSubsystemPico_Source_OnlineSubsystemPico_Public_OnlinePicoFunctionLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
