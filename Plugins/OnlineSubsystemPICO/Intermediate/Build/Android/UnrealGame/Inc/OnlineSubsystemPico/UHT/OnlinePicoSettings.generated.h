// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "OnlinePicoSettings.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ERegionType : uint8;
#ifdef ONLINESUBSYSTEMPICO_OnlinePicoSettings_generated_h
#error "OnlinePicoSettings.generated.h already included, missing '#pragma once' in OnlinePicoSettings.h"
#endif
#define ONLINESUBSYSTEMPICO_OnlinePicoSettings_generated_h

#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_18_SPARSE_DATA
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_18_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_18_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetOnlinePicoSettings);


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_18_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_18_INCLASS \
private: \
	static void StaticRegisterNativesUOnlinePicoSettings(); \
	friend struct Z_Construct_UClass_UOnlinePicoSettings_Statics; \
public: \
	DECLARE_CLASS(UOnlinePicoSettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UOnlinePicoSettings) \
	static const TCHAR* StaticConfigName() {return TEXT("Engine");} \



#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOnlinePicoSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOnlinePicoSettings) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOnlinePicoSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOnlinePicoSettings); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOnlinePicoSettings(UOnlinePicoSettings&&); \
	NO_API UOnlinePicoSettings(const UOnlinePicoSettings&); \
public: \
	NO_API virtual ~UOnlinePicoSettings();


#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_15_PROLOG
#define FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_18_SPARSE_DATA \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_18_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_18_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_18_RPC_WRAPPERS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_18_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_18_INCLASS \
	FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<class UOnlinePicoSettings>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h


#define FOREACH_ENUM_EREGIONTYPE(op) \
	op(ERegionType::China) \
	op(ERegionType::NonChina) 

enum class ERegionType : uint8;
template<> struct TIsUEnumClass<ERegionType> { enum { Value = true }; };
template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERegionType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
