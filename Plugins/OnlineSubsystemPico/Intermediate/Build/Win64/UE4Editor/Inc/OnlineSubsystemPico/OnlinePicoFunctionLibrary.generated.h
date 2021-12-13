// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FOnlinePicoPayCodeOrderInfo;
struct FOnlinePicoCoinOrderInfo;
#ifdef ONLINESUBSYSTEMPICO_OnlinePicoFunctionLibrary_generated_h
#error "OnlinePicoFunctionLibrary.generated.h already included, missing '#pragma once' in OnlinePicoFunctionLibrary.h"
#endif
#define ONLINESUBSYSTEMPICO_OnlinePicoFunctionLibrary_generated_h

#define PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Public_OnlinePicoFunctionLibrary_h_9_DELEGATE \
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


#define PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Public_OnlinePicoFunctionLibrary_h_14_SPARSE_DATA
#define PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Public_OnlinePicoFunctionLibrary_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execPicoGetDeviceSN); \
	DECLARE_FUNCTION(execPicoEntitlementVerifyCheck); \
	DECLARE_FUNCTION(execPicoEntitlementVerifyAppDelegate); \
	DECLARE_FUNCTION(execPicoBindPaymentExceptionDelegate); \
	DECLARE_FUNCTION(execPicoPaymentQueryOrder); \
	DECLARE_FUNCTION(execPicoPaymentPayWithPayCode); \
	DECLARE_FUNCTION(execPicoPaymentPayWithCoin); \
	DECLARE_FUNCTION(execPicoPaymentGetUserInfo); \
	DECLARE_FUNCTION(execPicoSDKGetUserInfo); \
	DECLARE_FUNCTION(execPicoPaymentLogout); \
	DECLARE_FUNCTION(execPicoLogoutSDK); \
	DECLARE_FUNCTION(execPicoPaymentLogin); \
	DECLARE_FUNCTION(execPicoLoginSDK);


#define PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Public_OnlinePicoFunctionLibrary_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPicoGetDeviceSN); \
	DECLARE_FUNCTION(execPicoEntitlementVerifyCheck); \
	DECLARE_FUNCTION(execPicoEntitlementVerifyAppDelegate); \
	DECLARE_FUNCTION(execPicoBindPaymentExceptionDelegate); \
	DECLARE_FUNCTION(execPicoPaymentQueryOrder); \
	DECLARE_FUNCTION(execPicoPaymentPayWithPayCode); \
	DECLARE_FUNCTION(execPicoPaymentPayWithCoin); \
	DECLARE_FUNCTION(execPicoPaymentGetUserInfo); \
	DECLARE_FUNCTION(execPicoSDKGetUserInfo); \
	DECLARE_FUNCTION(execPicoPaymentLogout); \
	DECLARE_FUNCTION(execPicoLogoutSDK); \
	DECLARE_FUNCTION(execPicoPaymentLogin); \
	DECLARE_FUNCTION(execPicoLoginSDK);


#define PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Public_OnlinePicoFunctionLibrary_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOnlinePicoFunctionLibrary(); \
	friend struct Z_Construct_UClass_UOnlinePicoFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UOnlinePicoFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UOnlinePicoFunctionLibrary)


#define PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Public_OnlinePicoFunctionLibrary_h_14_INCLASS \
private: \
	static void StaticRegisterNativesUOnlinePicoFunctionLibrary(); \
	friend struct Z_Construct_UClass_UOnlinePicoFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UOnlinePicoFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UOnlinePicoFunctionLibrary)


#define PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Public_OnlinePicoFunctionLibrary_h_14_STANDARD_CONSTRUCTORS \
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


#define PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Public_OnlinePicoFunctionLibrary_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOnlinePicoFunctionLibrary(UOnlinePicoFunctionLibrary&&); \
	NO_API UOnlinePicoFunctionLibrary(const UOnlinePicoFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOnlinePicoFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOnlinePicoFunctionLibrary); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UOnlinePicoFunctionLibrary)


#define PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Public_OnlinePicoFunctionLibrary_h_14_PRIVATE_PROPERTY_OFFSET
#define PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Public_OnlinePicoFunctionLibrary_h_11_PROLOG
#define PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Public_OnlinePicoFunctionLibrary_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Public_OnlinePicoFunctionLibrary_h_14_PRIVATE_PROPERTY_OFFSET \
	PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Public_OnlinePicoFunctionLibrary_h_14_SPARSE_DATA \
	PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Public_OnlinePicoFunctionLibrary_h_14_RPC_WRAPPERS \
	PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Public_OnlinePicoFunctionLibrary_h_14_INCLASS \
	PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Public_OnlinePicoFunctionLibrary_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Public_OnlinePicoFunctionLibrary_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Public_OnlinePicoFunctionLibrary_h_14_PRIVATE_PROPERTY_OFFSET \
	PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Public_OnlinePicoFunctionLibrary_h_14_SPARSE_DATA \
	PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Public_OnlinePicoFunctionLibrary_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Public_OnlinePicoFunctionLibrary_h_14_INCLASS_NO_PURE_DECLS \
	PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Public_OnlinePicoFunctionLibrary_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<class UOnlinePicoFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID PicoXR_Unreal_Plugins_OnlineSubsystemPico_Source_Public_OnlinePicoFunctionLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
