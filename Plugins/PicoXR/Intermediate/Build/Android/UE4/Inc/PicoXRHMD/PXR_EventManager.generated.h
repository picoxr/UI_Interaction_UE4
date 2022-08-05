// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PICOXRHMD_PXR_EventManager_generated_h
#error "PXR_EventManager.generated.h already included, missing '#pragma once' in PXR_EventManager.h"
#endif
#define PICOXRHMD_PXR_EventManager_generated_h

#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_17_DELEGATE \
struct _Script_PicoXRHMD_eventPXRRefreshRateChanged_Parms \
{ \
	float NewRate; \
}; \
static inline void FPXRRefreshRateChanged_DelegateWrapper(const FMulticastScriptDelegate& PXRRefreshRateChanged, float NewRate) \
{ \
	_Script_PicoXRHMD_eventPXRRefreshRateChanged_Parms Parms; \
	Parms.NewRate=NewRate; \
	PXRRefreshRateChanged.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_15_DELEGATE \
struct _Script_PicoXRHMD_eventPXRIpdChanged_Parms \
{ \
	float NewIpd; \
}; \
static inline void FPXRIpdChanged_DelegateWrapper(const FMulticastScriptDelegate& PXRIpdChanged, float NewIpd) \
{ \
	_Script_PicoXRHMD_eventPXRIpdChanged_Parms Parms; \
	Parms.NewIpd=NewIpd; \
	PXRIpdChanged.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_13_DELEGATE \
static inline void FPXRResume_DelegateWrapper(const FMulticastScriptDelegate& PXRResume) \
{ \
	PXRResume.ProcessMulticastDelegate<UObject>(NULL); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_12_DELEGATE \
static inline void FPXRLongHomeKey_DelegateWrapper(const FMulticastScriptDelegate& PXRLongHomeKey) \
{ \
	PXRLongHomeKey.ProcessMulticastDelegate<UObject>(NULL); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_11_DELEGATE \
struct _Script_PicoXRHMD_eventPXRDeviceConnectChangedDelegage_Parms \
{ \
	int32 Handness; \
	int32 State; \
}; \
static inline void FPXRDeviceConnectChangedDelegage_DelegateWrapper(const FMulticastScriptDelegate& PXRDeviceConnectChangedDelegage, int32 Handness, int32 State) \
{ \
	_Script_PicoXRHMD_eventPXRDeviceConnectChangedDelegage_Parms Parms; \
	Parms.Handness=Handness; \
	Parms.State=State; \
	PXRDeviceConnectChangedDelegage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_10_DELEGATE \
struct _Script_PicoXRHMD_eventPXRDeviceMainChangedDelegage_Parms \
{ \
	int32 Handness; \
}; \
static inline void FPXRDeviceMainChangedDelegage_DelegateWrapper(const FMulticastScriptDelegate& PXRDeviceMainChangedDelegage, int32 Handness) \
{ \
	_Script_PicoXRHMD_eventPXRDeviceMainChangedDelegage_Parms Parms; \
	Parms.Handness=Handness; \
	PXRDeviceMainChangedDelegage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_21_SPARSE_DATA
#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_21_RPC_WRAPPERS
#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_21_RPC_WRAPPERS_NO_PURE_DECLS
#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPicoXREventManager(); \
	friend struct Z_Construct_UClass_UPicoXREventManager_Statics; \
public: \
	DECLARE_CLASS(UPicoXREventManager, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PicoXRHMD"), NO_API) \
	DECLARE_SERIALIZER(UPicoXREventManager)


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_21_INCLASS \
private: \
	static void StaticRegisterNativesUPicoXREventManager(); \
	friend struct Z_Construct_UClass_UPicoXREventManager_Statics; \
public: \
	DECLARE_CLASS(UPicoXREventManager, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PicoXRHMD"), NO_API) \
	DECLARE_SERIALIZER(UPicoXREventManager)


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPicoXREventManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPicoXREventManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPicoXREventManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPicoXREventManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPicoXREventManager(UPicoXREventManager&&); \
	NO_API UPicoXREventManager(const UPicoXREventManager&); \
public:


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_21_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPicoXREventManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPicoXREventManager(UPicoXREventManager&&); \
	NO_API UPicoXREventManager(const UPicoXREventManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPicoXREventManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPicoXREventManager); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPicoXREventManager)


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_21_PRIVATE_PROPERTY_OFFSET
#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_18_PROLOG
#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_21_PRIVATE_PROPERTY_OFFSET \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_21_SPARSE_DATA \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_21_RPC_WRAPPERS \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_21_INCLASS \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_21_PRIVATE_PROPERTY_OFFSET \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_21_SPARSE_DATA \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_21_INCLASS_NO_PURE_DECLS \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PICOXRHMD_API UClass* StaticClass<class UPicoXREventManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_EventManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
