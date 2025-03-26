// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PXR_HMDTypes.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PICOXRHMD_PXR_HMDTypes_generated_h
#error "PXR_HMDTypes.generated.h already included, missing '#pragma once' in PXR_HMDTypes.h"
#endif
#define PICOXRHMD_PXR_HMDTypes_generated_h

#define FID_New_0311_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDTypes_h_16_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPXRSplashDesc_Statics; \
	PICOXRHMD_API static class UScriptStruct* StaticStruct();


template<> PICOXRHMD_API UScriptStruct* StaticStruct<struct FPXRSplashDesc>();

#define FID_New_0311_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDTypes_h_93_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPXREventDataMotionTrackerKey_Statics; \
	PICOXRHMD_API static class UScriptStruct* StaticStruct();


template<> PICOXRHMD_API UScriptStruct* StaticStruct<struct FPXREventDataMotionTrackerKey>();

#define FID_New_0311_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDTypes_h_119_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPXREventDataExtDevConnectEvent_Statics; \
	PICOXRHMD_API static class UScriptStruct* StaticStruct();


template<> PICOXRHMD_API UScriptStruct* StaticStruct<struct FPXREventDataExtDevConnectEvent>();

#define FID_New_0311_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDTypes_h_136_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPXREventDataExtDevBatteryEvent_Statics; \
	PICOXRHMD_API static class UScriptStruct* StaticStruct();


template<> PICOXRHMD_API UScriptStruct* StaticStruct<struct FPXREventDataExtDevBatteryEvent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_New_0311_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDTypes_h


#define FOREACH_ENUM_EPICOXRCOORDINATETYPE(op) \
	op(EPICOXRCoordinateType::Local) \
	op(EPICOXRCoordinateType::Global_BoundarySystem) 

enum class EPICOXRCoordinateType : uint8;
template<> struct TIsUEnumClass<EPICOXRCoordinateType> { enum { Value = true }; };
template<> PICOXRHMD_API UEnum* StaticEnum<EPICOXRCoordinateType>();

#define FOREACH_ENUM_EPXRBODYACTIONLIST(op) \
	op(EPxrBodyActionList::NoneAction) \
	op(EPxrBodyActionList::TouchGround) \
	op(EPxrBodyActionList::KeepStatic) \
	op(EPxrBodyActionList::TouchGroundAndKeepStatic) \
	op(EPxrBodyActionList::TouchGroundToe) \
	op(EPxrBodyActionList::FootDownAction) 

enum class EPxrBodyActionList : uint8;
template<> struct TIsUEnumClass<EPxrBodyActionList> { enum { Value = true }; };
template<> PICOXRHMD_API UEnum* StaticEnum<EPxrBodyActionList>();

#define FOREACH_ENUM_EPICOMRSTATE(op) \
	op(EPICOMRState::Initialized) \
	op(EPICOMRState::Running) \
	op(EPICOMRState::Stopped) 

enum class EPICOMRState : uint8;
template<> struct TIsUEnumClass<EPICOMRState> { enum { Value = true }; };
template<> PICOXRHMD_API UEnum* StaticEnum<EPICOMRState>();

#define FOREACH_ENUM_EPICOVSTDISPLAYSTATUS(op) \
	op(EPICOVSTDisplayStatus::Display_Disabled) \
	op(EPICOVSTDisplayStatus::Display_Enabling) \
	op(EPICOVSTDisplayStatus::Display_Enabled) \
	op(EPICOVSTDisplayStatus::Display_Disabling) 

enum class EPICOVSTDisplayStatus : uint8;
template<> struct TIsUEnumClass<EPICOVSTDisplayStatus> { enum { Value = true }; };
template<> PICOXRHMD_API UEnum* StaticEnum<EPICOVSTDisplayStatus>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
