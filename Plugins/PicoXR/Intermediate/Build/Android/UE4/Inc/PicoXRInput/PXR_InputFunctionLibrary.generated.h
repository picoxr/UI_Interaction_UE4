// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EPxrControllerKeyMap : uint8;
enum class EControllerHand : uint8;
struct FVector;
struct FRotator;
enum class EPicoXRControllerType : uint8;
enum class EPicoXRHandedness : uint8;
enum class EPicoXRArmModelJoint : uint8;
enum class EPicoXRGazeBehavior : uint8;
enum class EPicoXRControllerDeviceType : uint8;
#ifdef PICOXRINPUT_PXR_InputFunctionLibrary_generated_h
#error "PXR_InputFunctionLibrary.generated.h already included, missing '#pragma once' in PXR_InputFunctionLibrary.h"
#endif
#define PICOXRINPUT_PXR_InputFunctionLibrary_generated_h

#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRInput_Public_PXR_InputFunctionLibrary_h_76_SPARSE_DATA
#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRInput_Public_PXR_InputFunctionLibrary_h_76_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execPXR_SetControllerEnableKey); \
	DECLARE_FUNCTION(execPXR_GetControllerPredictedLocationAndRotation); \
	DECLARE_FUNCTION(execPXR_SetControllerOriginOffset); \
	DECLARE_FUNCTION(execPXR_GetControllerEnableHomekey); \
	DECLARE_FUNCTION(execPXR_GetHandedness); \
	DECLARE_FUNCTION(execPXR_GetControllerArmModelParam); \
	DECLARE_FUNCTION(execPXR_SetControllerArmModelParam); \
	DECLARE_FUNCTION(execPXR_GetControllerDeviceType); \
	DECLARE_FUNCTION(execPXR_VibrateController); \
	DECLARE_FUNCTION(execPXR_GetControllerLinearVelocity); \
	DECLARE_FUNCTION(execPXR_GetControllerAcceleration); \
	DECLARE_FUNCTION(execPXR_GetControllerAngularVelocity); \
	DECLARE_FUNCTION(execPXR_SetMainControllerHandle); \
	DECLARE_FUNCTION(execPXR_GetMainControllerHandle); \
	DECLARE_FUNCTION(execPXR_GetControllerConnectionState); \
	DECLARE_FUNCTION(execPXR_GetControllerPower);


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRInput_Public_PXR_InputFunctionLibrary_h_76_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPXR_SetControllerEnableKey); \
	DECLARE_FUNCTION(execPXR_GetControllerPredictedLocationAndRotation); \
	DECLARE_FUNCTION(execPXR_SetControllerOriginOffset); \
	DECLARE_FUNCTION(execPXR_GetControllerEnableHomekey); \
	DECLARE_FUNCTION(execPXR_GetHandedness); \
	DECLARE_FUNCTION(execPXR_GetControllerArmModelParam); \
	DECLARE_FUNCTION(execPXR_SetControllerArmModelParam); \
	DECLARE_FUNCTION(execPXR_GetControllerDeviceType); \
	DECLARE_FUNCTION(execPXR_VibrateController); \
	DECLARE_FUNCTION(execPXR_GetControllerLinearVelocity); \
	DECLARE_FUNCTION(execPXR_GetControllerAcceleration); \
	DECLARE_FUNCTION(execPXR_GetControllerAngularVelocity); \
	DECLARE_FUNCTION(execPXR_SetMainControllerHandle); \
	DECLARE_FUNCTION(execPXR_GetMainControllerHandle); \
	DECLARE_FUNCTION(execPXR_GetControllerConnectionState); \
	DECLARE_FUNCTION(execPXR_GetControllerPower);


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRInput_Public_PXR_InputFunctionLibrary_h_76_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPicoXRInputFunctionLibrary(); \
	friend struct Z_Construct_UClass_UPicoXRInputFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UPicoXRInputFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PicoXRInput"), NO_API) \
	DECLARE_SERIALIZER(UPicoXRInputFunctionLibrary)


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRInput_Public_PXR_InputFunctionLibrary_h_76_INCLASS \
private: \
	static void StaticRegisterNativesUPicoXRInputFunctionLibrary(); \
	friend struct Z_Construct_UClass_UPicoXRInputFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UPicoXRInputFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PicoXRInput"), NO_API) \
	DECLARE_SERIALIZER(UPicoXRInputFunctionLibrary)


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRInput_Public_PXR_InputFunctionLibrary_h_76_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPicoXRInputFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPicoXRInputFunctionLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPicoXRInputFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPicoXRInputFunctionLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPicoXRInputFunctionLibrary(UPicoXRInputFunctionLibrary&&); \
	NO_API UPicoXRInputFunctionLibrary(const UPicoXRInputFunctionLibrary&); \
public:


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRInput_Public_PXR_InputFunctionLibrary_h_76_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPicoXRInputFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPicoXRInputFunctionLibrary(UPicoXRInputFunctionLibrary&&); \
	NO_API UPicoXRInputFunctionLibrary(const UPicoXRInputFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPicoXRInputFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPicoXRInputFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPicoXRInputFunctionLibrary)


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRInput_Public_PXR_InputFunctionLibrary_h_76_PRIVATE_PROPERTY_OFFSET
#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRInput_Public_PXR_InputFunctionLibrary_h_73_PROLOG
#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRInput_Public_PXR_InputFunctionLibrary_h_76_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRInput_Public_PXR_InputFunctionLibrary_h_76_PRIVATE_PROPERTY_OFFSET \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRInput_Public_PXR_InputFunctionLibrary_h_76_SPARSE_DATA \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRInput_Public_PXR_InputFunctionLibrary_h_76_RPC_WRAPPERS \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRInput_Public_PXR_InputFunctionLibrary_h_76_INCLASS \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRInput_Public_PXR_InputFunctionLibrary_h_76_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRInput_Public_PXR_InputFunctionLibrary_h_76_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRInput_Public_PXR_InputFunctionLibrary_h_76_PRIVATE_PROPERTY_OFFSET \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRInput_Public_PXR_InputFunctionLibrary_h_76_SPARSE_DATA \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRInput_Public_PXR_InputFunctionLibrary_h_76_RPC_WRAPPERS_NO_PURE_DECLS \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRInput_Public_PXR_InputFunctionLibrary_h_76_INCLASS_NO_PURE_DECLS \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRInput_Public_PXR_InputFunctionLibrary_h_76_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PICOXRINPUT_API UClass* StaticClass<class UPicoXRInputFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRInput_Public_PXR_InputFunctionLibrary_h


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
template<> PICOXRINPUT_API UEnum* StaticEnum<EPxrControllerKeyMap>();

#define FOREACH_ENUM_EPICOXRCONTROLLERDEVICETYPE(op) \
	op(EPicoXRControllerDeviceType::UnKnown) \
	op(EPicoXRControllerDeviceType::G2) \
	op(EPicoXRControllerDeviceType::Neo2) \
	op(EPicoXRControllerDeviceType::Neo3) 

enum class EPicoXRControllerDeviceType : uint8;
template<> PICOXRINPUT_API UEnum* StaticEnum<EPicoXRControllerDeviceType>();

#define FOREACH_ENUM_EPICOXRGAZEBEHAVIOR(op) \
	op(EPicoXRGazeBehavior::Never) \
	op(EPicoXRGazeBehavior::DuringMotion) \
	op(EPicoXRGazeBehavior::Always) 

enum class EPicoXRGazeBehavior : uint8;
template<> PICOXRINPUT_API UEnum* StaticEnum<EPicoXRGazeBehavior>();

#define FOREACH_ENUM_EPICOXRARMMODELJOINT(op) \
	op(EPicoXRArmModelJoint::Controller) \
	op(EPicoXRArmModelJoint::Wrist) \
	op(EPicoXRArmModelJoint::Elbow) \
	op(EPicoXRArmModelJoint::Shoulder) 

enum class EPicoXRArmModelJoint : uint8;
template<> PICOXRINPUT_API UEnum* StaticEnum<EPicoXRArmModelJoint>();

#define FOREACH_ENUM_EPICOXRCONTROLLERTYPE(op) \
	op(EPicoXRControllerType::LeftHand) \
	op(EPicoXRControllerType::RightHand) \
	op(EPicoXRControllerType::G2Hand) 

enum class EPicoXRControllerType : uint8;
template<> PICOXRINPUT_API UEnum* StaticEnum<EPicoXRControllerType>();

#define FOREACH_ENUM_EPICOXRHANDEDNESS(op) \
	op(EPicoXRHandedness::LeftHand) \
	op(EPicoXRHandedness::RightHand) 

enum class EPicoXRHandedness : uint8;
template<> PICOXRINPUT_API UEnum* StaticEnum<EPicoXRHandedness>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
