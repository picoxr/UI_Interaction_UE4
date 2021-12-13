// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ONLINESUBSYSTEMPICO_OnlinePicoPaymentManager_generated_h
#error "OnlinePicoPaymentManager.generated.h already included, missing '#pragma once' in OnlinePicoPaymentManager.h"
#endif
#define ONLINESUBSYSTEMPICO_OnlinePicoPaymentManager_generated_h

#define PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Private_OnlinePicoPaymentManager_h_32_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOnlinePicoPayCodeOrderInfo_Statics; \
	ONLINESUBSYSTEMPICO_API static class UScriptStruct* StaticStruct();


template<> ONLINESUBSYSTEMPICO_API UScriptStruct* StaticStruct<struct FOnlinePicoPayCodeOrderInfo>();

#define PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Private_OnlinePicoPaymentManager_h_11_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FOnlinePicoCoinOrderInfo_Statics; \
	ONLINESUBSYSTEMPICO_API static class UScriptStruct* StaticStruct();


template<> ONLINESUBSYSTEMPICO_API UScriptStruct* StaticStruct<struct FOnlinePicoCoinOrderInfo>();

#define PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Private_OnlinePicoPaymentManager_h_54_DELEGATE \
struct _Script_OnlineSubsystemPico_eventOnlinePicoPaymentExceptionDelegate_Parms \
{ \
	FString Exception; \
}; \
static inline void FOnlinePicoPaymentExceptionDelegate_DelegateWrapper(const FScriptDelegate& OnlinePicoPaymentExceptionDelegate, const FString& Exception) \
{ \
	_Script_OnlineSubsystemPico_eventOnlinePicoPaymentExceptionDelegate_Parms Parms; \
	Parms.Exception=Exception; \
	OnlinePicoPaymentExceptionDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Private_OnlinePicoPaymentManager_h_53_DELEGATE \
struct _Script_OnlineSubsystemPico_eventOnlinePicoPaymentQueryOrderDelegate_Parms \
{ \
	FString Code; \
	FString Message; \
}; \
static inline void FOnlinePicoPaymentQueryOrderDelegate_DelegateWrapper(const FScriptDelegate& OnlinePicoPaymentQueryOrderDelegate, const FString& Code, const FString& Message) \
{ \
	_Script_OnlineSubsystemPico_eventOnlinePicoPaymentQueryOrderDelegate_Parms Parms; \
	Parms.Code=Code; \
	Parms.Message=Message; \
	OnlinePicoPaymentQueryOrderDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Private_OnlinePicoPaymentManager_h_52_DELEGATE \
struct _Script_OnlineSubsystemPico_eventOnlinePicoPaymentPayOrderDelegate_Parms \
{ \
	FString Code; \
	FString Message; \
}; \
static inline void FOnlinePicoPaymentPayOrderDelegate_DelegateWrapper(const FScriptDelegate& OnlinePicoPaymentPayOrderDelegate, const FString& Code, const FString& Message) \
{ \
	_Script_OnlineSubsystemPico_eventOnlinePicoPaymentPayOrderDelegate_Parms Parms; \
	Parms.Code=Code; \
	Parms.Message=Message; \
	OnlinePicoPaymentPayOrderDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Private_OnlinePicoPaymentManager_h_51_DELEGATE \
struct _Script_OnlineSubsystemPico_eventOnlinePicoPaymentGetUserInfoDelegate_Parms \
{ \
	FString Info; \
}; \
static inline void FOnlinePicoPaymentGetUserInfoDelegate_DelegateWrapper(const FScriptDelegate& OnlinePicoPaymentGetUserInfoDelegate, const FString& Info) \
{ \
	_Script_OnlineSubsystemPico_eventOnlinePicoPaymentGetUserInfoDelegate_Parms Parms; \
	Parms.Info=Info; \
	OnlinePicoPaymentGetUserInfoDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Private_OnlinePicoPaymentManager_h_50_DELEGATE \
struct _Script_OnlineSubsystemPico_eventOnlinePicoPaymentLogInOrOutDelegate_Parms \
{ \
	bool bIsSucceed; \
	FString Reason; \
}; \
static inline void FOnlinePicoPaymentLogInOrOutDelegate_DelegateWrapper(const FScriptDelegate& OnlinePicoPaymentLogInOrOutDelegate, bool bIsSucceed, const FString& Reason) \
{ \
	_Script_OnlineSubsystemPico_eventOnlinePicoPaymentLogInOrOutDelegate_Parms Parms; \
	Parms.bIsSucceed=bIsSucceed ? true : false; \
	Parms.Reason=Reason; \
	OnlinePicoPaymentLogInOrOutDelegate.ProcessDelegate<UObject>(&Parms); \
}


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Private_OnlinePicoPaymentManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
