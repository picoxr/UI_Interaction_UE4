// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PXR_InputFunctionLibrary.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USoundWave;
enum class EBodyTrackingMode : uint8;
enum class EControllerHand : uint8;
enum class EPICOXRActiveInputDevice : uint8;
enum class EPICOXRArmModelJoint : uint8;
enum class EPICOXRCacheConfig : uint8;
enum class EPICOXRChannelFlip : uint8;
enum class EPICOXRControllerDeviceType : uint8;
enum class EPICOXRControllerType : uint8;
enum class EPICOXRGazeBehavior : uint8;
enum class EPICOXRHandedness : uint8;
enum class EPICOXRHandJoint : uint8;
enum class EPICOXRHandTrackingConfidence : uint8;
enum class EPICOXRHandType : uint8;
enum class EPICOXRVibrateController : uint8;
enum class EPxrBodyTrackerRole : uint8;
enum class EPxrControllerKeyMap : uint8;
struct FBodyTrackingBoneLength;
struct FMotionTrackerConnectState;
struct FPHFJsonData;
struct FPxrBodyTrackingTransform;
#ifdef PICOXRINPUT_PXR_InputFunctionLibrary_generated_h
#error "PXR_InputFunctionLibrary.generated.h already included, missing '#pragma once' in PXR_InputFunctionLibrary.h"
#endif
#define PICOXRINPUT_PXR_InputFunctionLibrary_generated_h

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_216_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics; \
	PICOXRINPUT_API static class UScriptStruct* StaticStruct();


template<> PICOXRINPUT_API UScriptStruct* StaticStruct<struct FPxrBodyTrackingImu>();

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_243_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics; \
	PICOXRINPUT_API static class UScriptStruct* StaticStruct();


template<> PICOXRINPUT_API UScriptStruct* StaticStruct<struct FMotionTrackerConnectState>();

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_259_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics; \
	PICOXRINPUT_API static class UScriptStruct* StaticStruct();


template<> PICOXRINPUT_API UScriptStruct* StaticStruct<struct FPxrBodyTrackingTransform>();

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_313_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics; \
	PICOXRINPUT_API static class UScriptStruct* StaticStruct();


template<> PICOXRINPUT_API UScriptStruct* StaticStruct<struct FBodyTrackingBoneLength>();

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_357_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FAudioClipData_Statics; \
	PICOXRINPUT_API static class UScriptStruct* StaticStruct();


template<> PICOXRINPUT_API UScriptStruct* StaticStruct<struct FAudioClipData>();

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_386_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPHFDataContent_Statics; \
	PICOXRINPUT_API static class UScriptStruct* StaticStruct();


template<> PICOXRINPUT_API UScriptStruct* StaticStruct<struct FPHFDataContent>();

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_402_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPHFData_Statics; \
	static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> PICOXRINPUT_API UScriptStruct* StaticStruct<struct FPHFData>();

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_415_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics; \
	PICOXRINPUT_API static class UScriptStruct* StaticStruct();


template<> PICOXRINPUT_API UScriptStruct* StaticStruct<struct FPHFJsonFrameData>();

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_441_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPHFJsonData_Statics; \
	static class UScriptStruct* StaticStruct(); \
	typedef FTableRowBase Super;


template<> PICOXRINPUT_API UScriptStruct* StaticStruct<struct FPHFJsonData>();

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_468_SPARSE_DATA
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_468_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_468_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_468_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPXR_SetBodyTrackingBoneLength); \
	DECLARE_FUNCTION(execPXR_SetBodyTrackingMode); \
	DECLARE_FUNCTION(execPXR_GetMotionTrackerCalibState); \
	DECLARE_FUNCTION(execPXR_GetMotionTrackerBattery); \
	DECLARE_FUNCTION(execPXR_GetMotionTrackerConnectStateWithId); \
	DECLARE_FUNCTION(execPXR_GetBodyTrackingPoseByRole); \
	DECLARE_FUNCTION(execPXR_GetBodyTrackingPose); \
	DECLARE_FUNCTION(execPXR_SetBodyTrackingStaticCalibState); \
	DECLARE_FUNCTION(execPXR_GetPHFHapticSpeed); \
	DECLARE_FUNCTION(execPXR_SetPHFHapticSpeed); \
	DECLARE_FUNCTION(execPXR_GetCurrentFrameSequence); \
	DECLARE_FUNCTION(execPXR_WriteHapticStream); \
	DECLARE_FUNCTION(execPXR_StopPHFHaptic); \
	DECLARE_FUNCTION(execPXR_StartPHFHaptic); \
	DECLARE_FUNCTION(execPXR_RemovePHFHaptic); \
	DECLARE_FUNCTION(execPXR_CreateHapticStream); \
	DECLARE_FUNCTION(execPXR_UpdateVibrateParams); \
	DECLARE_FUNCTION(execPXR_ResumeVibrate); \
	DECLARE_FUNCTION(execPXR_PauseVibrate); \
	DECLARE_FUNCTION(execPXR_StartVibrateByPHF); \
	DECLARE_FUNCTION(execGetActiveInputDevice); \
	DECLARE_FUNCTION(execIsHandTrackingEnabled); \
	DECLARE_FUNCTION(execGetPinchStrength); \
	DECLARE_FUNCTION(execGetHandScale); \
	DECLARE_FUNCTION(execGetTrackingConfidence); \
	DECLARE_FUNCTION(execIsPinchValid); \
	DECLARE_FUNCTION(execIsRayValid); \
	DECLARE_FUNCTION(execIsComputed); \
	DECLARE_FUNCTION(execGetRayPose); \
	DECLARE_FUNCTION(execGetHandRootPose); \
	DECLARE_FUNCTION(execIsBonePositionTracked); \
	DECLARE_FUNCTION(execIsBoneOrientationTracked); \
	DECLARE_FUNCTION(execIsBonePositionValid); \
	DECLARE_FUNCTION(execIsBoneOrientationValid); \
	DECLARE_FUNCTION(execGetBoneRadii); \
	DECLARE_FUNCTION(execGetBoneLocation); \
	DECLARE_FUNCTION(execGetBoneRotation); \
	DECLARE_FUNCTION(execPXR_ClearVibrateByCache); \
	DECLARE_FUNCTION(execPXR_StartVibrateByCache); \
	DECLARE_FUNCTION(execPXR_SaveVibrateByCache); \
	DECLARE_FUNCTION(execPXR_SetControllerEnableKey); \
	DECLARE_FUNCTION(execPXR_StartVibrateBySharem); \
	DECLARE_FUNCTION(execPXR_SetControllerVibrationEvent); \
	DECLARE_FUNCTION(execPXR_StopControllerVCMotor); \
	DECLARE_FUNCTION(execPXR_SetControllerAmp); \
	DECLARE_FUNCTION(execPXR_StartControllerVCMotor); \
	DECLARE_FUNCTION(execPXR_GetControllerPredictedLocationAndRotation); \
	DECLARE_FUNCTION(execPXR_SetControllerOriginOffset); \
	DECLARE_FUNCTION(execPXR_GetControllerEnableHomekey); \
	DECLARE_FUNCTION(execPXR_GetHandedness); \
	DECLARE_FUNCTION(execPXR_SetArmModelParameters); \
	DECLARE_FUNCTION(execPXR_ResetController); \
	DECLARE_FUNCTION(execPXR_GetControllerDeviceType); \
	DECLARE_FUNCTION(execPXR_VibrateController); \
	DECLARE_FUNCTION(execPXR_GetControllerLinearVelocity); \
	DECLARE_FUNCTION(execPXR_GetControllerAcceleration); \
	DECLARE_FUNCTION(execPXR_GetControllerAngularVelocity); \
	DECLARE_FUNCTION(execPXR_SetMainControllerHandle); \
	DECLARE_FUNCTION(execPXR_GetMainControllerHandle); \
	DECLARE_FUNCTION(execPXR_GetControllerConnectionState); \
	DECLARE_FUNCTION(execPXR_GetControllerPower);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_468_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_468_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPICOXRInputFunctionLibrary(); \
	friend struct Z_Construct_UClass_UPICOXRInputFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UPICOXRInputFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PICOXRInput"), NO_API) \
	DECLARE_SERIALIZER(UPICOXRInputFunctionLibrary)


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_468_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPICOXRInputFunctionLibrary(UPICOXRInputFunctionLibrary&&); \
	NO_API UPICOXRInputFunctionLibrary(const UPICOXRInputFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPICOXRInputFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPICOXRInputFunctionLibrary); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPICOXRInputFunctionLibrary) \
	NO_API virtual ~UPICOXRInputFunctionLibrary();


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_465_PROLOG
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_468_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_468_SPARSE_DATA \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_468_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_468_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_468_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_468_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_468_INCLASS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_468_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PICOXRINPUT_API UClass* StaticClass<class UPICOXRInputFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h


#define FOREACH_ENUM_EPICOXRHANDTRACKINGCONFIDENCE(op) \
	op(EPICOXRHandTrackingConfidence::Low) \
	op(EPICOXRHandTrackingConfidence::High) 

enum class EPICOXRHandTrackingConfidence : uint8;
template<> struct TIsUEnumClass<EPICOXRHandTrackingConfidence> { enum { Value = true }; };
template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRHandTrackingConfidence>();

#define FOREACH_ENUM_EPICOXRACTIVEINPUTDEVICE(op) \
	op(EPICOXRActiveInputDevice::NoneActive) \
	op(EPICOXRActiveInputDevice::ControllerActive) \
	op(EPICOXRActiveInputDevice::HandTrackingActive) 

enum class EPICOXRActiveInputDevice : uint8;
template<> struct TIsUEnumClass<EPICOXRActiveInputDevice> { enum { Value = true }; };
template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRActiveInputDevice>();

#define FOREACH_ENUM_EPICOXRHANDFINGER(op) \
	op(EPICOXRHandFinger::None) \
	op(EPICOXRHandFinger::Index) \
	op(EPICOXRHandFinger::Middle) \
	op(EPICOXRHandFinger::Ring) \
	op(EPICOXRHandFinger::Pinky) 

enum class EPICOXRHandFinger : uint8;
template<> struct TIsUEnumClass<EPICOXRHandFinger> { enum { Value = true }; };
template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRHandFinger>();

#define FOREACH_ENUM_EPICOXRHANDJOINT(op) \
	op(EPICOXRHandJoint::Palm) \
	op(EPICOXRHandJoint::Wrist) \
	op(EPICOXRHandJoint::ThumbMetacarpal) \
	op(EPICOXRHandJoint::ThumbProximal) \
	op(EPICOXRHandJoint::ThumbDistal) \
	op(EPICOXRHandJoint::ThumbTip) \
	op(EPICOXRHandJoint::IndexMetacarpal) \
	op(EPICOXRHandJoint::IndexProximal) \
	op(EPICOXRHandJoint::IndexIntermediate) \
	op(EPICOXRHandJoint::IndexDistal) \
	op(EPICOXRHandJoint::IndexTip) \
	op(EPICOXRHandJoint::MiddleMetacarpal) \
	op(EPICOXRHandJoint::MiddleProximal) \
	op(EPICOXRHandJoint::MiddleIntermediate) \
	op(EPICOXRHandJoint::MiddleDistal) \
	op(EPICOXRHandJoint::MiddleTip) \
	op(EPICOXRHandJoint::RingMetacarpal) \
	op(EPICOXRHandJoint::RingProximal) \
	op(EPICOXRHandJoint::RingIntermediate) \
	op(EPICOXRHandJoint::RingDistal) \
	op(EPICOXRHandJoint::RingTip) \
	op(EPICOXRHandJoint::LittleMetacarpal) \
	op(EPICOXRHandJoint::LittleProximal) \
	op(EPICOXRHandJoint::LittleIntermediate) \
	op(EPICOXRHandJoint::LittleDistal) \
	op(EPICOXRHandJoint::LittleTip) 

enum class EPICOXRHandJoint : uint8;
template<> struct TIsUEnumClass<EPICOXRHandJoint> { enum { Value = true }; };
template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRHandJoint>();

#define FOREACH_ENUM_EPICOXRHANDTYPE(op) \
	op(EPICOXRHandType::None) \
	op(EPICOXRHandType::HandLeft) \
	op(EPICOXRHandType::HandRight) 

enum class EPICOXRHandType : uint8;
template<> struct TIsUEnumClass<EPICOXRHandType> { enum { Value = true }; };
template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRHandType>();

#define FOREACH_ENUM_EPICOXRHANDEDNESS(op) \
	op(EPICOXRHandedness::LeftHand) \
	op(EPICOXRHandedness::RightHand) 

enum class EPICOXRHandedness : uint8;
template<> struct TIsUEnumClass<EPICOXRHandedness> { enum { Value = true }; };
template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRHandedness>();

#define FOREACH_ENUM_EPICOXRCONTROLLERTYPE(op) \
	op(EPICOXRControllerType::LeftHand) \
	op(EPICOXRControllerType::RightHand) \
	op(EPICOXRControllerType::G2Hand) 

enum class EPICOXRControllerType : uint8;
template<> struct TIsUEnumClass<EPICOXRControllerType> { enum { Value = true }; };
template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRControllerType>();

#define FOREACH_ENUM_EPICOXRARMMODELJOINT(op) \
	op(EPICOXRArmModelJoint::Controller) \
	op(EPICOXRArmModelJoint::Wrist) \
	op(EPICOXRArmModelJoint::Elbow) \
	op(EPICOXRArmModelJoint::Shoulder) 

enum class EPICOXRArmModelJoint : uint8;
template<> struct TIsUEnumClass<EPICOXRArmModelJoint> { enum { Value = true }; };
template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRArmModelJoint>();

#define FOREACH_ENUM_EPICOXRGAZEBEHAVIOR(op) \
	op(EPICOXRGazeBehavior::Never) \
	op(EPICOXRGazeBehavior::DuringMotion) \
	op(EPICOXRGazeBehavior::Always) 

enum class EPICOXRGazeBehavior : uint8;
template<> struct TIsUEnumClass<EPICOXRGazeBehavior> { enum { Value = true }; };
template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRGazeBehavior>();

#define FOREACH_ENUM_EPICOXRCONTROLLERDEVICETYPE(op) \
	op(EPICOXRControllerDeviceType::UnKnown) \
	op(EPICOXRControllerDeviceType::G2) \
	op(EPICOXRControllerDeviceType::Neo2) \
	op(EPICOXRControllerDeviceType::Neo3) \
	op(EPICOXRControllerDeviceType::PICO_4) \
	op(EPICOXRControllerDeviceType::G3) \
	op(EPICOXRControllerDeviceType::PICO_4_U) 

enum class EPICOXRControllerDeviceType : uint8;
template<> struct TIsUEnumClass<EPICOXRControllerDeviceType> { enum { Value = true }; };
template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRControllerDeviceType>();

#define FOREACH_ENUM_EPICOXRVIBRATECONTROLLER(op) \
	op(EPICOXRVibrateController::No) \
	op(EPICOXRVibrateController::Left) \
	op(EPICOXRVibrateController::Right) \
	op(EPICOXRVibrateController::LeftAndRight) 

enum class EPICOXRVibrateController : uint8;
template<> struct TIsUEnumClass<EPICOXRVibrateController> { enum { Value = true }; };
template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRVibrateController>();

#define FOREACH_ENUM_EPICOXRCHANNELFLIP(op) \
	op(EPICOXRChannelFlip::No) \
	op(EPICOXRChannelFlip::Yes) 

enum class EPICOXRChannelFlip : uint8;
template<> struct TIsUEnumClass<EPICOXRChannelFlip> { enum { Value = true }; };
template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRChannelFlip>();

#define FOREACH_ENUM_EPICOXRCACHECONFIG(op) \
	op(EPICOXRCacheConfig::CacheAndVibrate) \
	op(EPICOXRCacheConfig::CacheNoVibrate) 

enum class EPICOXRCacheConfig : uint8;
template<> struct TIsUEnumClass<EPICOXRCacheConfig> { enum { Value = true }; };
template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRCacheConfig>();

#define FOREACH_ENUM_EBODYACTIONLIST(op) \
	op(EBodyActionList::PxrNoneAction) \
	op(EBodyActionList::PxrTouchGround) \
	op(EBodyActionList::PxrKeepStatic) 

enum class EBodyActionList : uint8;
template<> struct TIsUEnumClass<EBodyActionList> { enum { Value = true }; };
template<> PICOXRINPUT_API UEnum* StaticEnum<EBodyActionList>();

#define FOREACH_ENUM_EPXRCONTROLLERKEYMAP(op) \
	op(EPxrControllerKeyMap::PXR_CONTROLLER_KEY_HOME) \
	op(EPxrControllerKeyMap::PXR_CONTROLLER_KEY_AX) \
	op(EPxrControllerKeyMap::PXR_CONTROLLER_KEY_BY) \
	op(EPxrControllerKeyMap::PXR_CONTROLLER_KEY_BACK) \
	op(EPxrControllerKeyMap::PXR_CONTROLLER_KEY_TRIGGER) \
	op(EPxrControllerKeyMap::PXR_CONTROLLER_KEY_VOL_UP) \
	op(EPxrControllerKeyMap::PXR_CONTROLLER_KEY_VOL_DOWN) \
	op(EPxrControllerKeyMap::PXR_CONTROLLER_KEY_ROCKER) \
	op(EPxrControllerKeyMap::PXR_CONTROLLER_KEY_GRIP) \
	op(EPxrControllerKeyMap::PXR_CONTROLLER_KEY_TOUCHPAD) \
	op(EPxrControllerKeyMap::PXR_CONTROLLER_KEY_LASTONE) \
	op(EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_AX) \
	op(EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_BY) \
	op(EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_ROCKER) \
	op(EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_TRIGGER) \
	op(EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_THUMB) \
	op(EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_LASTONE) 

enum class EPxrControllerKeyMap : uint8;
template<> struct TIsUEnumClass<EPxrControllerKeyMap> { enum { Value = true }; };
template<> PICOXRINPUT_API UEnum* StaticEnum<EPxrControllerKeyMap>();

#define FOREACH_ENUM_EPXRBODYTRACKERROLE(op) \
	op(EPxrBodyTrackerRole::PxrPelvis) \
	op(EPxrBodyTrackerRole::Pxr_LEFT_HIP) \
	op(EPxrBodyTrackerRole::Pxr_RIGHT_HIP) \
	op(EPxrBodyTrackerRole::Pxr_SPINE1) \
	op(EPxrBodyTrackerRole::Pxr_LEFT_KNEE) \
	op(EPxrBodyTrackerRole::Pxr_RIGHT_KNEE) \
	op(EPxrBodyTrackerRole::Pxr_SPINE2) \
	op(EPxrBodyTrackerRole::Pxr_LEFT_ANKLE) \
	op(EPxrBodyTrackerRole::Pxr_RIGHT_ANKLE) \
	op(EPxrBodyTrackerRole::Pxr_SPINE3) \
	op(EPxrBodyTrackerRole::Pxr_LEFT_FOOT) \
	op(EPxrBodyTrackerRole::Pxr_RIGHT_FOOT) \
	op(EPxrBodyTrackerRole::Pxr_NECK) \
	op(EPxrBodyTrackerRole::Pxr_LEFT_COLLAR) \
	op(EPxrBodyTrackerRole::Pxr_RIGHT_COLLAR) \
	op(EPxrBodyTrackerRole::Pxr_HEAD) \
	op(EPxrBodyTrackerRole::Pxr_LEFT_SHOULDER) \
	op(EPxrBodyTrackerRole::Pxr_RIGHT_SHOULDER) \
	op(EPxrBodyTrackerRole::Pxr_LEFT_ELBOW) \
	op(EPxrBodyTrackerRole::Pxr_RIGHT_ELBOW) \
	op(EPxrBodyTrackerRole::Pxr_LEFT_WRIST) \
	op(EPxrBodyTrackerRole::Pxr_RIGHT_WRIST) \
	op(EPxrBodyTrackerRole::Pxr_LEFT_HAND) \
	op(EPxrBodyTrackerRole::Pxr_RIGHT_HAND) \
	op(EPxrBodyTrackerRole::Pxr_ROLE_COUNT) 

enum class EPxrBodyTrackerRole : uint8;
template<> struct TIsUEnumClass<EPxrBodyTrackerRole> { enum { Value = true }; };
template<> PICOXRINPUT_API UEnum* StaticEnum<EPxrBodyTrackerRole>();

#define FOREACH_ENUM_EBODYTRACKINGMODE(op) \
	op(EBodyTrackingMode::BODY_TRACKING_MODE_1) \
	op(EBodyTrackingMode::BODY_TRACKING_MODE_2) 

enum class EBodyTrackingMode : uint8;
template<> struct TIsUEnumClass<EBodyTrackingMode> { enum { Value = true }; };
template<> PICOXRINPUT_API UEnum* StaticEnum<EBodyTrackingMode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
