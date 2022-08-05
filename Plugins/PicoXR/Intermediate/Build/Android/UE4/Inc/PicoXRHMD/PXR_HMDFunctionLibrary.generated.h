// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FPxrSensorState;
class UTexture2D;
struct FVector;
struct FRotator;
struct FVector2D;
struct FPicoXREyeTrackingData;
enum class EPicoXRFoveationLevel : uint8;
enum class EPicoXRBoundaryState : uint8;
struct FIntPoint;
enum class EPicoXRCameraType : uint8;
enum class EPicoXRBoundaryType : uint8;
enum class EPicoXRNodeType : uint8;
struct FLinearColor;
class UPicoXREventManager;
struct FQuat;
#ifdef PICOXRHMD_PXR_HMDFunctionLibrary_generated_h
#error "PXR_HMDFunctionLibrary.generated.h already included, missing '#pragma once' in PXR_HMDFunctionLibrary.h"
#endif
#define PICOXRHMD_PXR_HMDFunctionLibrary_generated_h

#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_105_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics; \
	PICOXRHMD_API static class UScriptStruct* StaticStruct();


template<> PICOXRHMD_API UScriptStruct* StaticStruct<struct FPicoXREyeTrackingData>();

#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_78_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPxrSensorState_Statics; \
	PICOXRHMD_API static class UScriptStruct* StaticStruct();


template<> PICOXRHMD_API UScriptStruct* StaticStruct<struct FPxrSensorState>();

#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_159_DELEGATE \
struct _Script_PicoXRHMD_eventPicoXRIPDChangedDelegate_Parms \
{ \
	float Ipd; \
}; \
static inline void FPicoXRIPDChangedDelegate_DelegateWrapper(const FScriptDelegate& PicoXRIPDChangedDelegate, float Ipd) \
{ \
	_Script_PicoXRHMD_eventPicoXRIPDChangedDelegate_Parms Parms; \
	Parms.Ipd=Ipd; \
	PicoXRIPDChangedDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_163_SPARSE_DATA
#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_163_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execPXR_SetLargeSpaceEnable); \
	DECLARE_FUNCTION(execPXR_GetPredictedMainSensorState); \
	DECLARE_FUNCTION(execPXR_SetExtraLatencyMode); \
	DECLARE_FUNCTION(execPXR_GetDisplayFrequenciesAvailable); \
	DECLARE_FUNCTION(execPXR_SetSensorLostCMST); \
	DECLARE_FUNCTION(execPXR_SetSensorLostCustomMode); \
	DECLARE_FUNCTION(execPXR_EnableAutoShowSplashScreen); \
	DECLARE_FUNCTION(execPXR_ClearLoadingSplashScreens); \
	DECLARE_FUNCTION(execPXR_AddSplashScreen); \
	DECLARE_FUNCTION(execPXR_EnableFaceTracking); \
	DECLARE_FUNCTION(execPXR_GetEyeTrackingPos); \
	DECLARE_FUNCTION(execPXR_EnableEyeTrackingMarker); \
	DECLARE_FUNCTION(execPXR_GetEyeTrackingData); \
	DECLARE_FUNCTION(execPXR_GetEyeTrackingGazeRay); \
	DECLARE_FUNCTION(execPXR_SetFoveationParameter); \
	DECLARE_FUNCTION(execPXR_SetFoveationLevel); \
	DECLARE_FUNCTION(execPXR_GetFoveationLevel); \
	DECLARE_FUNCTION(execPXR_EnableFoveation); \
	DECLARE_FUNCTION(execPXR_GetDialogState); \
	DECLARE_FUNCTION(execPXR_SetSeeThroughBackground); \
	DECLARE_FUNCTION(execPXR_SetBoundaryCameraImageSize); \
	DECLARE_FUNCTION(execPXR_GetBoundarySeeThroughData); \
	DECLARE_FUNCTION(execPXR_GetBoundaryDimensions); \
	DECLARE_FUNCTION(execPXR_GetBoundaryGeometry); \
	DECLARE_FUNCTION(execPXR_BoundaryTestPoint); \
	DECLARE_FUNCTION(execPXR_BoundaryTestNode); \
	DECLARE_FUNCTION(execPXR_GetBoundaryVisible); \
	DECLARE_FUNCTION(execPXR_SetBoundaryVisible); \
	DECLARE_FUNCTION(execPXR_GetBoundaryEnabled); \
	DECLARE_FUNCTION(execPXR_GetBoundaryConfigured); \
	DECLARE_FUNCTION(execGetFocusState); \
	DECLARE_FUNCTION(execPXR_SetColorScaleAndOffset); \
	DECLARE_FUNCTION(execPXR_SetSystemDisplayFrequency); \
	DECLARE_FUNCTION(execPXR_GetSystemDisplayFrequency); \
	DECLARE_FUNCTION(execPXR_GetCPUAndGPULevels); \
	DECLARE_FUNCTION(execPXR_SetCPUAndGPULevels); \
	DECLARE_FUNCTION(execPXR_GetCurrentDisplayFrequency); \
	DECLARE_FUNCTION(execPXR_GetDeviceModel); \
	DECLARE_FUNCTION(execPXR_GetEventManager); \
	DECLARE_FUNCTION(execPXR_IPDChangedDelegates); \
	DECLARE_FUNCTION(execPXR_GetIPD); \
	DECLARE_FUNCTION(execPXR_GetHFov); \
	DECLARE_FUNCTION(execPXR_GetVFov); \
	DECLARE_FUNCTION(execPXR_GetFieldOfView); \
	DECLARE_FUNCTION(execPXR_ResetHMDSensor); \
	DECLARE_FUNCTION(execPXR_GetHMDWornState); \
	DECLARE_FUNCTION(execPXR_GetAngularAcceleration); \
	DECLARE_FUNCTION(execPXR_GetVelocity); \
	DECLARE_FUNCTION(execPXR_GetAcceleration); \
	DECLARE_FUNCTION(execPXR_GetAngularVelocity); \
	DECLARE_FUNCTION(execPXR_DoesSupportPositionalTracking); \
	DECLARE_FUNCTION(execPXR_GetCurrentPosition); \
	DECLARE_FUNCTION(execPXR_GetCurrentOrientation);


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_163_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPXR_SetLargeSpaceEnable); \
	DECLARE_FUNCTION(execPXR_GetPredictedMainSensorState); \
	DECLARE_FUNCTION(execPXR_SetExtraLatencyMode); \
	DECLARE_FUNCTION(execPXR_GetDisplayFrequenciesAvailable); \
	DECLARE_FUNCTION(execPXR_SetSensorLostCMST); \
	DECLARE_FUNCTION(execPXR_SetSensorLostCustomMode); \
	DECLARE_FUNCTION(execPXR_EnableAutoShowSplashScreen); \
	DECLARE_FUNCTION(execPXR_ClearLoadingSplashScreens); \
	DECLARE_FUNCTION(execPXR_AddSplashScreen); \
	DECLARE_FUNCTION(execPXR_EnableFaceTracking); \
	DECLARE_FUNCTION(execPXR_GetEyeTrackingPos); \
	DECLARE_FUNCTION(execPXR_EnableEyeTrackingMarker); \
	DECLARE_FUNCTION(execPXR_GetEyeTrackingData); \
	DECLARE_FUNCTION(execPXR_GetEyeTrackingGazeRay); \
	DECLARE_FUNCTION(execPXR_SetFoveationParameter); \
	DECLARE_FUNCTION(execPXR_SetFoveationLevel); \
	DECLARE_FUNCTION(execPXR_GetFoveationLevel); \
	DECLARE_FUNCTION(execPXR_EnableFoveation); \
	DECLARE_FUNCTION(execPXR_GetDialogState); \
	DECLARE_FUNCTION(execPXR_SetSeeThroughBackground); \
	DECLARE_FUNCTION(execPXR_SetBoundaryCameraImageSize); \
	DECLARE_FUNCTION(execPXR_GetBoundarySeeThroughData); \
	DECLARE_FUNCTION(execPXR_GetBoundaryDimensions); \
	DECLARE_FUNCTION(execPXR_GetBoundaryGeometry); \
	DECLARE_FUNCTION(execPXR_BoundaryTestPoint); \
	DECLARE_FUNCTION(execPXR_BoundaryTestNode); \
	DECLARE_FUNCTION(execPXR_GetBoundaryVisible); \
	DECLARE_FUNCTION(execPXR_SetBoundaryVisible); \
	DECLARE_FUNCTION(execPXR_GetBoundaryEnabled); \
	DECLARE_FUNCTION(execPXR_GetBoundaryConfigured); \
	DECLARE_FUNCTION(execGetFocusState); \
	DECLARE_FUNCTION(execPXR_SetColorScaleAndOffset); \
	DECLARE_FUNCTION(execPXR_SetSystemDisplayFrequency); \
	DECLARE_FUNCTION(execPXR_GetSystemDisplayFrequency); \
	DECLARE_FUNCTION(execPXR_GetCPUAndGPULevels); \
	DECLARE_FUNCTION(execPXR_SetCPUAndGPULevels); \
	DECLARE_FUNCTION(execPXR_GetCurrentDisplayFrequency); \
	DECLARE_FUNCTION(execPXR_GetDeviceModel); \
	DECLARE_FUNCTION(execPXR_GetEventManager); \
	DECLARE_FUNCTION(execPXR_IPDChangedDelegates); \
	DECLARE_FUNCTION(execPXR_GetIPD); \
	DECLARE_FUNCTION(execPXR_GetHFov); \
	DECLARE_FUNCTION(execPXR_GetVFov); \
	DECLARE_FUNCTION(execPXR_GetFieldOfView); \
	DECLARE_FUNCTION(execPXR_ResetHMDSensor); \
	DECLARE_FUNCTION(execPXR_GetHMDWornState); \
	DECLARE_FUNCTION(execPXR_GetAngularAcceleration); \
	DECLARE_FUNCTION(execPXR_GetVelocity); \
	DECLARE_FUNCTION(execPXR_GetAcceleration); \
	DECLARE_FUNCTION(execPXR_GetAngularVelocity); \
	DECLARE_FUNCTION(execPXR_DoesSupportPositionalTracking); \
	DECLARE_FUNCTION(execPXR_GetCurrentPosition); \
	DECLARE_FUNCTION(execPXR_GetCurrentOrientation);


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_163_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPicoXRHMDFunctionLibrary(); \
	friend struct Z_Construct_UClass_UPicoXRHMDFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UPicoXRHMDFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PicoXRHMD"), NO_API) \
	DECLARE_SERIALIZER(UPicoXRHMDFunctionLibrary)


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_163_INCLASS \
private: \
	static void StaticRegisterNativesUPicoXRHMDFunctionLibrary(); \
	friend struct Z_Construct_UClass_UPicoXRHMDFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UPicoXRHMDFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PicoXRHMD"), NO_API) \
	DECLARE_SERIALIZER(UPicoXRHMDFunctionLibrary)


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_163_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPicoXRHMDFunctionLibrary(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPicoXRHMDFunctionLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPicoXRHMDFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPicoXRHMDFunctionLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPicoXRHMDFunctionLibrary(UPicoXRHMDFunctionLibrary&&); \
	NO_API UPicoXRHMDFunctionLibrary(const UPicoXRHMDFunctionLibrary&); \
public:


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_163_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPicoXRHMDFunctionLibrary(UPicoXRHMDFunctionLibrary&&); \
	NO_API UPicoXRHMDFunctionLibrary(const UPicoXRHMDFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPicoXRHMDFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPicoXRHMDFunctionLibrary); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPicoXRHMDFunctionLibrary)


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_163_PRIVATE_PROPERTY_OFFSET
#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_160_PROLOG
#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_163_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_163_PRIVATE_PROPERTY_OFFSET \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_163_SPARSE_DATA \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_163_RPC_WRAPPERS \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_163_INCLASS \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_163_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_163_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_163_PRIVATE_PROPERTY_OFFSET \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_163_SPARSE_DATA \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_163_RPC_WRAPPERS_NO_PURE_DECLS \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_163_INCLASS_NO_PURE_DECLS \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h_163_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PICOXRHMD_API UClass* StaticClass<class UPicoXRHMDFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Public_PXR_HMDFunctionLibrary_h


#define FOREACH_ENUM_EPICOXRFOVEATIONLEVEL(op) \
	op(EPicoXRFoveationLevel::Low) \
	op(EPicoXRFoveationLevel::Medium) \
	op(EPicoXRFoveationLevel::High) \
	op(EPicoXRFoveationLevel::TopHigh) 

enum class EPicoXRFoveationLevel : uint8;
template<> PICOXRHMD_API UEnum* StaticEnum<EPicoXRFoveationLevel>();

#define FOREACH_ENUM_EPICOXRCAMERATYPE(op) \
	op(EPicoXRCameraType::Left) \
	op(EPicoXRCameraType::Right) 

enum class EPicoXRCameraType : uint8;
template<> PICOXRHMD_API UEnum* StaticEnum<EPicoXRCameraType>();

#define FOREACH_ENUM_EPICOXRNODETYPE(op) \
	op(EPicoXRNodeType::LeftHand) \
	op(EPicoXRNodeType::RightHand) \
	op(EPicoXRNodeType::Head) 

enum class EPicoXRNodeType : uint8;
template<> PICOXRHMD_API UEnum* StaticEnum<EPicoXRNodeType>();

#define FOREACH_ENUM_EPICOXRTRACKEDDEVICETYPE(op) \
	op(EPicoXRTrackedDeviceType::None) \
	op(EPicoXRTrackedDeviceType::HMD) \
	op(EPicoXRTrackedDeviceType::LTouch) \
	op(EPicoXRTrackedDeviceType::RTouch) \
	op(EPicoXRTrackedDeviceType::Touch) \
	op(EPicoXRTrackedDeviceType::All) 

enum class EPicoXRTrackedDeviceType : uint8;
template<> PICOXRHMD_API UEnum* StaticEnum<EPicoXRTrackedDeviceType>();

#define FOREACH_ENUM_EPICOXRBOUNDARYSTATE(op) \
	op(EPicoXRBoundaryState::GobackDialog) \
	op(EPicoXRBoundaryState::ToofarDialog) \
	op(EPicoXRBoundaryState::LostDialog) \
	op(EPicoXRBoundaryState::LostNoReason) \
	op(EPicoXRBoundaryState::LostCamera) \
	op(EPicoXRBoundaryState::LostHighLight) \
	op(EPicoXRBoundaryState::LostLowLight) \
	op(EPicoXRBoundaryState::LostLowFeatureCount) \
	op(EPicoXRBoundaryState::LostReLocation) \
	op(EPicoXRBoundaryState::LostInitialization) \
	op(EPicoXRBoundaryState::LostNoCamera) \
	op(EPicoXRBoundaryState::LostNoIMU) \
	op(EPicoXRBoundaryState::LostIMUJitter) \
	op(EPicoXRBoundaryState::LostUnknown) \
	op(EPicoXRBoundaryState::NothingDialog) \
	op(EPicoXRBoundaryState::LostNoDialog) 

enum class EPicoXRBoundaryState : uint8;
template<> PICOXRHMD_API UEnum* StaticEnum<EPicoXRBoundaryState>();

#define FOREACH_ENUM_EPICOXRBOUNDARYTYPE(op) \
	op(EPicoXRBoundaryType::Outer) \
	op(EPicoXRBoundaryType::PlayArea) 

enum class EPicoXRBoundaryType : uint8;
template<> PICOXRHMD_API UEnum* StaticEnum<EPicoXRBoundaryType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
