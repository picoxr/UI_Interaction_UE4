// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PXR_MotionTrackingFunctionLibrary.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EPXREyeTrackingMode : uint8;
enum class EPXRFaceTrackingMode : uint8;
enum class EPXRMotionTrackerConfidence : uint8;
enum class EPXRMotionTrackerMode : uint8;
enum class EPXRMotionTrackerType : uint8;
struct FPXRBodyTrackingData;
struct FPXRBodyTrackingDataGetInfo;
struct FPXRBodyTrackingStartInfo;
struct FPXRBodyTrackingState;
struct FPXRBodyTrackingStopInfo;
struct FPXRExtDevTrackerConnectState;
struct FPXRExtDevTrackerKeyData;
struct FPXRExtDevTrackerMotorVibrate;
struct FPXRExtDevTrackerPassData;
struct FPXREyePupilInfo;
struct FPXREyeTrackingData;
struct FPXREyeTrackingDataGetInfo;
struct FPXREyeTrackingStartInfo;
struct FPXREyeTrackingState;
struct FPXREyeTrackingStopInfo;
struct FPXRFaceTrackingData;
struct FPXRFaceTrackingDataGetInfo;
struct FPXRFaceTrackingStartInfo;
struct FPXRFaceTrackingState;
struct FPXRFaceTrackingStopInfo;
struct FPXRMotionConnectState;
struct FPXRMotionTrackerLocations;
#ifdef PICOXRMOTIONTRACKING_PXR_MotionTrackingFunctionLibrary_generated_h
#error "PXR_MotionTrackingFunctionLibrary.generated.h already included, missing '#pragma once' in PXR_MotionTrackingFunctionLibrary.h"
#endif
#define PICOXRMOTIONTRACKING_PXR_MotionTrackingFunctionLibrary_generated_h

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_MotionTrackingFunctionLibrary_h_13_SPARSE_DATA
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_MotionTrackingFunctionLibrary_h_13_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_MotionTrackingFunctionLibrary_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_MotionTrackingFunctionLibrary_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPXR_GetExtDevTrackerKeyData); \
	DECLARE_FUNCTION(execPXR_GetExtDevTrackerBattery); \
	DECLARE_FUNCTION(execPXR_GetExtDevTrackerByPassData); \
	DECLARE_FUNCTION(execPXR_SetExtDevTrackerByPassData); \
	DECLARE_FUNCTION(execPXR_SetExtDevTrackerPassDataState); \
	DECLARE_FUNCTION(execPXR_SetExtDevTrackerMotorVibrate); \
	DECLARE_FUNCTION(execPXR_GetExtDevTrackerConnectState); \
	DECLARE_FUNCTION(execPXR_CheckMotionTrackerModeAndNumber); \
	DECLARE_FUNCTION(execPXR_GetMotionTrackerLocations); \
	DECLARE_FUNCTION(execPXR_GetMotionTrackerMode); \
	DECLARE_FUNCTION(execPXR_GetMotionTrackerDeviceType); \
	DECLARE_FUNCTION(execPXR_GetMotionTrackerConnectStateWithSN); \
	DECLARE_FUNCTION(execPXR_StartMotionTrackerCalibApp); \
	DECLARE_FUNCTION(execPXR_GetBodyTrackingData); \
	DECLARE_FUNCTION(execPXR_StopBodyTracking); \
	DECLARE_FUNCTION(execPXR_StartBodyTracking); \
	DECLARE_FUNCTION(execPXR_GetBodyTrackingState); \
	DECLARE_FUNCTION(execPXR_GetBodyTrackingSupported); \
	DECLARE_FUNCTION(execPXR_WantBodyTrackingService); \
	DECLARE_FUNCTION(execGetEyeBlink); \
	DECLARE_FUNCTION(execGetPerEyePose); \
	DECLARE_FUNCTION(execGetEyePupilInfo); \
	DECLARE_FUNCTION(execGetEyeOpenness); \
	DECLARE_FUNCTION(execGetEyeTrackingData); \
	DECLARE_FUNCTION(execStopEyeTracking); \
	DECLARE_FUNCTION(execStartEyeTracking); \
	DECLARE_FUNCTION(execGetEyeTrackingState); \
	DECLARE_FUNCTION(execGetEyeTrackingSupported); \
	DECLARE_FUNCTION(execGetFaceTrackingData); \
	DECLARE_FUNCTION(execStopFaceTracking); \
	DECLARE_FUNCTION(execStartFaceTracking); \
	DECLARE_FUNCTION(execGetFaceTrackingState); \
	DECLARE_FUNCTION(execGetFaceTrackingSupported);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_MotionTrackingFunctionLibrary_h_13_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_MotionTrackingFunctionLibrary_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPICOXRMotionTrackingFunctionLibrary(); \
	friend struct Z_Construct_UClass_UPICOXRMotionTrackingFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UPICOXRMotionTrackingFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PICOXRMotionTracking"), NO_API) \
	DECLARE_SERIALIZER(UPICOXRMotionTrackingFunctionLibrary)


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_MotionTrackingFunctionLibrary_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPICOXRMotionTrackingFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPICOXRMotionTrackingFunctionLibrary(UPICOXRMotionTrackingFunctionLibrary&&); \
	NO_API UPICOXRMotionTrackingFunctionLibrary(const UPICOXRMotionTrackingFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPICOXRMotionTrackingFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPICOXRMotionTrackingFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPICOXRMotionTrackingFunctionLibrary) \
	NO_API virtual ~UPICOXRMotionTrackingFunctionLibrary();


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_MotionTrackingFunctionLibrary_h_10_PROLOG
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_MotionTrackingFunctionLibrary_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_MotionTrackingFunctionLibrary_h_13_SPARSE_DATA \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_MotionTrackingFunctionLibrary_h_13_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_MotionTrackingFunctionLibrary_h_13_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_MotionTrackingFunctionLibrary_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_MotionTrackingFunctionLibrary_h_13_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_MotionTrackingFunctionLibrary_h_13_INCLASS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_MotionTrackingFunctionLibrary_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PICOXRMOTIONTRACKING_API UClass* StaticClass<class UPICOXRMotionTrackingFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMotionTracking_Public_PXR_MotionTrackingFunctionLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
