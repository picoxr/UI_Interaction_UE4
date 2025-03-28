// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PXR_EventManager.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EPICOMRState : uint8;
enum class EPICOVSTDisplayStatus : uint8;
enum class EPxrBodyActionList : uint8;
struct FPXREventDataExtDevBatteryEvent;
struct FPXREventDataExtDevConnectEvent;
struct FPXREventDataMotionTrackerKey;
#ifdef PICOXRHMD_PXR_EventManager_generated_h
#error "PXR_EventManager.generated.h already included, missing '#pragma once' in PXR_EventManager.h"
#endif
#define PICOXRHMD_PXR_EventManager_generated_h

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_13_DELEGATE \
PICOXRHMD_API void FPXRDeviceMainChangedDelegate_DelegateWrapper(const FMulticastScriptDelegate& PXRDeviceMainChangedDelegate, int32 Handness);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_14_DELEGATE \
PICOXRHMD_API void FPXRHandnessChangedDelegate_DelegateWrapper(const FMulticastScriptDelegate& PXRHandnessChangedDelegate, int32 Handness);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_15_DELEGATE \
PICOXRHMD_API void FPXRDeviceConnectChangedDelegate_DelegateWrapper(const FMulticastScriptDelegate& PXRDeviceConnectChangedDelegate, int32 Handness, int32 State);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_16_DELEGATE \
PICOXRHMD_API void FPXRInputDeviceChangedDelegate_DelegateWrapper(const FMulticastScriptDelegate& PXRInputDeviceChangedDelegate, int32 State);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_17_DELEGATE \
PICOXRHMD_API void FPXRBatteryStateChangedDelegate_DelegateWrapper(const FMulticastScriptDelegate& PXRBatteryStateChangedDelegate, int32 State);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_19_DELEGATE \
PICOXRHMD_API void FPXRLongHomeKey_DelegateWrapper(const FMulticastScriptDelegate& PXRLongHomeKey);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_21_DELEGATE \
PICOXRHMD_API void FPXRResume_DelegateWrapper(const FMulticastScriptDelegate& PXRResume);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_23_DELEGATE \
PICOXRHMD_API void FPXRIpdChanged_DelegateWrapper(const FMulticastScriptDelegate& PXRIpdChanged, float NewIpd);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_25_DELEGATE \
PICOXRHMD_API void FPXRRefreshRateChanged_DelegateWrapper(const FMulticastScriptDelegate& PXRRefreshRateChanged, float NewRate);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_27_DELEGATE \
PICOXRHMD_API void FPXRDeviceMotionTrackerBatteryDelegate_DelegateWrapper(const FMulticastScriptDelegate& PXRDeviceMotionTrackerBatteryDelegate, int32 Id, int32 BatteryState);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_28_DELEGATE \
PICOXRHMD_API void FPXRDeviceBodyTrackingStateError_DelegateWrapper(const FMulticastScriptDelegate& PXRDeviceBodyTrackingStateError, int32 Status, int32 ErrorCode);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_29_DELEGATE \
PICOXRHMD_API void FPXRDeviceMotionTrackerConnectionDelegate_DelegateWrapper(const FMulticastScriptDelegate& PXRDeviceMotionTrackerConnectionDelegate, int32 Count, int32 ConnectionState);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_30_DELEGATE \
PICOXRHMD_API void FPXRDeviceMotionTrackerRecalibrationDelegate_DelegateWrapper(const FMulticastScriptDelegate& PXRDeviceMotionTrackerRecalibrationDelegate);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_31_DELEGATE \
PICOXRHMD_API void FPXRDeviceBodyTrackingActionDelegate_DelegateWrapper(const FMulticastScriptDelegate& PXRDeviceBodyTrackingActionDelegate, int32 BoneIndex, EPxrBodyActionList Action);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_32_DELEGATE \
PICOXRHMD_API void FPXREventDataMotionTrackerKeyDelegate_DelegateWrapper(const FMulticastScriptDelegate& PXREventDataMotionTrackerKeyDelegate, FPXREventDataMotionTrackerKey MotionTrackerKey);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_33_DELEGATE \
PICOXRHMD_API void FPXREventDataExtDevConnectEventDelegate_DelegateWrapper(const FMulticastScriptDelegate& PXREventDataExtDevConnectEventDelegate, FPXREventDataExtDevConnectEvent ExtDevConnectEvent);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_34_DELEGATE \
PICOXRHMD_API void FPXREventDataExtDevBatteryEventDelegate_DelegateWrapper(const FMulticastScriptDelegate& PXREventDataExtDevBatteryEventDelegate, FPXREventDataExtDevBatteryEvent ExtDevBatteryEvent);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_35_DELEGATE \
PICOXRHMD_API void FPXREventDataExtDevPassDataEventDelegate_DelegateWrapper(const FMulticastScriptDelegate& PXREventDataExtDevPassDataEventDelegate, int32 status);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_36_DELEGATE \
PICOXRHMD_API void FPXREventDataMotionTrackingModeChangedEventDelegate_DelegateWrapper(const FMulticastScriptDelegate& PXREventDataMotionTrackingModeChangedEventDelegate, int32 mode);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_39_DELEGATE \
PICOXRHMD_API void FPXRAnchorDataUpdatedDelegate_DelegateWrapper(const FMulticastScriptDelegate& PXRAnchorDataUpdatedDelegate);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_40_DELEGATE \
PICOXRHMD_API void FPXRMeshDataUpdatedDelegate_DelegateWrapper(const FMulticastScriptDelegate& PXRMeshDataUpdatedDelegate);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_41_DELEGATE \
PICOXRHMD_API void FPXRSceneCaptureDataUpdatedDelegate_DelegateWrapper(const FMulticastScriptDelegate& PXRSceneCaptureDataUpdatedDelegate);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_43_DELEGATE \
PICOXRHMD_API void FPXRAnchorServiceStateUpdatedDelegate_DelegateWrapper(const FMulticastScriptDelegate& PXRAnchorServiceStateUpdatedDelegate, EPICOMRState State);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_44_DELEGATE \
PICOXRHMD_API void FPXRMeshScanningStateUpdatedDelegate_DelegateWrapper(const FMulticastScriptDelegate& PXRMeshScanningStateUpdatedDelegate, EPICOMRState State);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_45_DELEGATE \
PICOXRHMD_API void FPXRSceneCaptureServiceStateUpdatedDelegate_DelegateWrapper(const FMulticastScriptDelegate& PXRSceneCaptureServiceStateUpdatedDelegate, EPICOMRState State);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_46_DELEGATE \
PICOXRHMD_API void FPXRVSTDisplayChangedDelegate_DelegateWrapper(const FMulticastScriptDelegate& PXRVSTDisplayChangedDelegate, EPICOVSTDisplayStatus Status);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_51_SPARSE_DATA
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_51_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_51_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_51_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_51_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_51_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPICOXREventManager(); \
	friend struct Z_Construct_UClass_UPICOXREventManager_Statics; \
public: \
	DECLARE_CLASS(UPICOXREventManager, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PICOXRHMD"), NO_API) \
	DECLARE_SERIALIZER(UPICOXREventManager)


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_51_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPICOXREventManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPICOXREventManager(UPICOXREventManager&&); \
	NO_API UPICOXREventManager(const UPICOXREventManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPICOXREventManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPICOXREventManager); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPICOXREventManager) \
	NO_API virtual ~UPICOXREventManager();


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_48_PROLOG
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_51_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_51_SPARSE_DATA \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_51_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_51_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_51_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_51_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_51_INCLASS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h_51_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PICOXRHMD_API UClass* StaticClass<class UPICOXREventManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_EventManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
