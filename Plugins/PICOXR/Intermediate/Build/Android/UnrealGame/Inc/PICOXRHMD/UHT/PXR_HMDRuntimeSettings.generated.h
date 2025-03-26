// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PXR_HMDRuntimeSettings.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PICOXRHMD_PXR_HMDRuntimeSettings_generated_h
#error "PXR_HMDRuntimeSettings.generated.h already included, missing '#pragma once' in PXR_HMDRuntimeSettings.h"
#endif
#define PICOXRHMD_PXR_HMDRuntimeSettings_generated_h

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_76_SPARSE_DATA
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_76_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_76_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_76_RPC_WRAPPERS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_76_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_76_INCLASS \
private: \
	static void StaticRegisterNativesUPICOXRSettings(); \
	friend struct Z_Construct_UClass_UPICOXRSettings_Statics; \
public: \
	DECLARE_CLASS(UPICOXRSettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/PICOXRHMD"), NO_API) \
	DECLARE_SERIALIZER(UPICOXRSettings) \
	static const TCHAR* StaticConfigName() {return TEXT("Engine");} \



#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_76_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPICOXRSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPICOXRSettings) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPICOXRSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPICOXRSettings); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPICOXRSettings(UPICOXRSettings&&); \
	NO_API UPICOXRSettings(const UPICOXRSettings&); \
public: \
	NO_API virtual ~UPICOXRSettings();


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_73_PROLOG
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_76_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_76_SPARSE_DATA \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_76_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_76_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_76_RPC_WRAPPERS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_76_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_76_INCLASS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_76_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PICOXRHMD_API UClass* StaticClass<class UPICOXRSettings>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h


#define FOREACH_ENUM_EFOVEATIONRENDERINGMODE(op) \
	op(EFoveationRenderingMode::FixedFoveationRendering) \
	op(EFoveationRenderingMode::EyeTrackingFoveationRendering) 

enum class EFoveationRenderingMode : uint8;
template<> struct TIsUEnumClass<EFoveationRenderingMode> { enum { Value = true }; };
template<> PICOXRHMD_API UEnum* StaticEnum<EFoveationRenderingMode>();

#define FOREACH_ENUM_EFOVEATIONLEVEL(op) \
	op(EFoveationLevel::None) \
	op(EFoveationLevel::Low) \
	op(EFoveationLevel::Med) \
	op(EFoveationLevel::High) \
	op(EFoveationLevel::TopHigh) 
#define FOREACH_ENUM_EREFRESHRATE(op) \
	op(ERefreshRate::Default) \
	op(ERefreshRate::RefreshRate72) \
	op(ERefreshRate::RefreshRate90) \
	op(ERefreshRate::RefreshRate120) 
#define FOREACH_ENUM_EPICOXRHANDTRACKINGSUPPORT(op) \
	op(EPICOXRHandTrackingSupport::ControllersOnly) \
	op(EPICOXRHandTrackingSupport::ControllersAndHands) \
	op(EPICOXRHandTrackingSupport::HandsOnly) 

enum class EPICOXRHandTrackingSupport : uint8;
template<> struct TIsUEnumClass<EPICOXRHandTrackingSupport> { enum { Value = true }; };
template<> PICOXRHMD_API UEnum* StaticEnum<EPICOXRHandTrackingSupport>();

#define FOREACH_ENUM_EPICOXRSHARPENINGTYPE(op) \
	op(EPICOXRSharpeningType::None) \
	op(EPICOXRSharpeningType::NormalSharpening) \
	op(EPICOXRSharpeningType::QualitySharpening) 

enum class EPICOXRSharpeningType : uint8;
template<> struct TIsUEnumClass<EPICOXRSharpeningType> { enum { Value = true }; };
template<> PICOXRHMD_API UEnum* StaticEnum<EPICOXRSharpeningType>();

#define FOREACH_ENUM_EPICOXRSHARPENINGENHANCEMODETYPE(op) \
	op(EPICOXRSharpeningEnhanceModeType::None) \
	op(EPICOXRSharpeningEnhanceModeType::FixedFoveated) \
	op(EPICOXRSharpeningEnhanceModeType::Adaptive) \
	op(EPICOXRSharpeningEnhanceModeType::Both) 

enum class EPICOXRSharpeningEnhanceModeType : uint8;
template<> struct TIsUEnumClass<EPICOXRSharpeningEnhanceModeType> { enum { Value = true }; };
template<> PICOXRHMD_API UEnum* StaticEnum<EPICOXRSharpeningEnhanceModeType>();

#define FOREACH_ENUM_EPICOSPATIALMESHLOD(op) \
	op(EPICOSpatialMeshLod::Low) \
	op(EPICOSpatialMeshLod::Medium) \
	op(EPICOSpatialMeshLod::High) 

enum class EPICOSpatialMeshLod : uint8;
template<> struct TIsUEnumClass<EPICOSpatialMeshLod> { enum { Value = true }; };
template<> PICOXRHMD_API UEnum* StaticEnum<EPICOSpatialMeshLod>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
