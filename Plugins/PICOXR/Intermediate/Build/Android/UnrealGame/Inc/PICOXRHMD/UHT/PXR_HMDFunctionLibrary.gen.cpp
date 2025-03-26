// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PICOXRHMD/Public/PXR_HMDFunctionLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePXR_HMDFunctionLibrary() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuat();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	HEADMOUNTEDDISPLAY_API UEnum* Z_Construct_UEnum_HeadMountedDisplay_EHMDWornState();
	HEADMOUNTEDDISPLAY_API UEnum* Z_Construct_UEnum_HeadMountedDisplay_EOrientPositionSelector();
	PICOXRHMD_API UClass* Z_Construct_UClass_UPICOXREventManager_NoRegister();
	PICOXRHMD_API UClass* Z_Construct_UClass_UPICOXRHMDFunctionLibrary();
	PICOXRHMD_API UClass* Z_Construct_UClass_UPICOXRHMDFunctionLibrary_NoRegister();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EFoveationRenderingMode();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EFtLipsyncCtlVal();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EPerformanceSettingTypes();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EPerfSettingsLevel();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryState();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryType();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRCameraType();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRCoordinateType();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRDeviceAbilities();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXREyeType();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRFoveationLevel();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRNodeType();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRTrackedDeviceType();
	PICOXRHMD_API UFunction* Z_Construct_UDelegateFunction_PICOXRHMD_PICOXRIPDChangedDelegate__DelegateSignature();
	PICOXRHMD_API UScriptStruct* Z_Construct_UScriptStruct_FPICOXREyeTrackingData();
	PICOXRHMD_API UScriptStruct* Z_Construct_UScriptStruct_FPxrSensorState();
	UPackage* Z_Construct_UPackage__Script_PICOXRHMD();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRBoundaryType;
	static UEnum* EPICOXRBoundaryType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRBoundaryType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRBoundaryType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryType, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("EPICOXRBoundaryType"));
		}
		return Z_Registration_Info_UEnum_EPICOXRBoundaryType.OuterSingleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPICOXRBoundaryType>()
	{
		return EPICOXRBoundaryType_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryType_Statics::Enumerators[] = {
		{ "EPICOXRBoundaryType::Outer", (int64)EPICOXRBoundaryType::Outer },
		{ "EPICOXRBoundaryType::PlayArea", (int64)EPICOXRBoundaryType::PlayArea },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Boundary boundary types*/" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "Outer.DisplayName", "The Outer Boundary" },
		{ "Outer.Name", "EPICOXRBoundaryType::Outer" },
		{ "PlayArea.DisplayName", "The Play Area Boundary" },
		{ "PlayArea.Name", "EPICOXRBoundaryType::PlayArea" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Boundary boundary types" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		"EPICOXRBoundaryType",
		"EPICOXRBoundaryType",
		Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryType()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRBoundaryType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRBoundaryType.InnerSingleton, Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRBoundaryType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRBoundaryState;
	static UEnum* EPICOXRBoundaryState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRBoundaryState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRBoundaryState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryState, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("EPICOXRBoundaryState"));
		}
		return Z_Registration_Info_UEnum_EPICOXRBoundaryState.OuterSingleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPICOXRBoundaryState>()
	{
		return EPICOXRBoundaryState_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryState_Statics::Enumerators[] = {
		{ "EPICOXRBoundaryState::GobackDialog", (int64)EPICOXRBoundaryState::GobackDialog },
		{ "EPICOXRBoundaryState::ToofarDialog", (int64)EPICOXRBoundaryState::ToofarDialog },
		{ "EPICOXRBoundaryState::LostDialog", (int64)EPICOXRBoundaryState::LostDialog },
		{ "EPICOXRBoundaryState::LostNoReason", (int64)EPICOXRBoundaryState::LostNoReason },
		{ "EPICOXRBoundaryState::LostCamera", (int64)EPICOXRBoundaryState::LostCamera },
		{ "EPICOXRBoundaryState::LostHighLight", (int64)EPICOXRBoundaryState::LostHighLight },
		{ "EPICOXRBoundaryState::LostLowLight", (int64)EPICOXRBoundaryState::LostLowLight },
		{ "EPICOXRBoundaryState::LostLowFeatureCount", (int64)EPICOXRBoundaryState::LostLowFeatureCount },
		{ "EPICOXRBoundaryState::LostReLocation", (int64)EPICOXRBoundaryState::LostReLocation },
		{ "EPICOXRBoundaryState::LostInitialization", (int64)EPICOXRBoundaryState::LostInitialization },
		{ "EPICOXRBoundaryState::LostNoCamera", (int64)EPICOXRBoundaryState::LostNoCamera },
		{ "EPICOXRBoundaryState::LostNoIMU", (int64)EPICOXRBoundaryState::LostNoIMU },
		{ "EPICOXRBoundaryState::LostIMUJitter", (int64)EPICOXRBoundaryState::LostIMUJitter },
		{ "EPICOXRBoundaryState::LostUnknown", (int64)EPICOXRBoundaryState::LostUnknown },
		{ "EPICOXRBoundaryState::NothingDialog", (int64)EPICOXRBoundaryState::NothingDialog },
		{ "EPICOXRBoundaryState::LostNoDialog", (int64)EPICOXRBoundaryState::LostNoDialog },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryState_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "GobackDialog.Name", "EPICOXRBoundaryState::GobackDialog" },
		{ "LostCamera.Name", "EPICOXRBoundaryState::LostCamera" },
		{ "LostDialog.Name", "EPICOXRBoundaryState::LostDialog" },
		{ "LostHighLight.Name", "EPICOXRBoundaryState::LostHighLight" },
		{ "LostIMUJitter.Name", "EPICOXRBoundaryState::LostIMUJitter" },
		{ "LostInitialization.Name", "EPICOXRBoundaryState::LostInitialization" },
		{ "LostLowFeatureCount.Name", "EPICOXRBoundaryState::LostLowFeatureCount" },
		{ "LostLowLight.Name", "EPICOXRBoundaryState::LostLowLight" },
		{ "LostNoCamera.Name", "EPICOXRBoundaryState::LostNoCamera" },
		{ "LostNoDialog.Name", "EPICOXRBoundaryState::LostNoDialog" },
		{ "LostNoIMU.Name", "EPICOXRBoundaryState::LostNoIMU" },
		{ "LostNoReason.Name", "EPICOXRBoundaryState::LostNoReason" },
		{ "LostReLocation.Name", "EPICOXRBoundaryState::LostReLocation" },
		{ "LostUnknown.Name", "EPICOXRBoundaryState::LostUnknown" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "NothingDialog.Name", "EPICOXRBoundaryState::NothingDialog" },
		{ "ToofarDialog.Name", "EPICOXRBoundaryState::ToofarDialog" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		"EPICOXRBoundaryState",
		"EPICOXRBoundaryState",
		Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryState_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryState_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryState_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryState()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRBoundaryState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRBoundaryState.InnerSingleton, Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRBoundaryState.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRTrackedDeviceType;
	static UEnum* EPICOXRTrackedDeviceType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRTrackedDeviceType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRTrackedDeviceType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRHMD_EPICOXRTrackedDeviceType, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("EPICOXRTrackedDeviceType"));
		}
		return Z_Registration_Info_UEnum_EPICOXRTrackedDeviceType.OuterSingleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPICOXRTrackedDeviceType>()
	{
		return EPICOXRTrackedDeviceType_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRHMD_EPICOXRTrackedDeviceType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRHMD_EPICOXRTrackedDeviceType_Statics::Enumerators[] = {
		{ "EPICOXRTrackedDeviceType::None", (int64)EPICOXRTrackedDeviceType::None },
		{ "EPICOXRTrackedDeviceType::HMD", (int64)EPICOXRTrackedDeviceType::HMD },
		{ "EPICOXRTrackedDeviceType::LTouch", (int64)EPICOXRTrackedDeviceType::LTouch },
		{ "EPICOXRTrackedDeviceType::RTouch", (int64)EPICOXRTrackedDeviceType::RTouch },
		{ "EPICOXRTrackedDeviceType::Touch", (int64)EPICOXRTrackedDeviceType::Touch },
		{ "EPICOXRTrackedDeviceType::All", (int64)EPICOXRTrackedDeviceType::All },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRHMD_EPICOXRTrackedDeviceType_Statics::Enum_MetaDataParams[] = {
		{ "All.DisplayName", "All Devices" },
		{ "All.Name", "EPICOXRTrackedDeviceType::All" },
		{ "BlueprintType", "true" },
		{ "HMD.DisplayName", "HMD" },
		{ "HMD.Name", "EPICOXRTrackedDeviceType::HMD" },
		{ "LTouch.DisplayName", "Left Hand" },
		{ "LTouch.Name", "EPICOXRTrackedDeviceType::LTouch" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "None.DisplayName", "No Devices" },
		{ "None.Name", "EPICOXRTrackedDeviceType::None" },
		{ "RTouch.DisplayName", "Right Hand" },
		{ "RTouch.Name", "EPICOXRTrackedDeviceType::RTouch" },
		{ "Touch.DisplayName", "All Hands" },
		{ "Touch.Name", "EPICOXRTrackedDeviceType::Touch" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRHMD_EPICOXRTrackedDeviceType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		"EPICOXRTrackedDeviceType",
		"EPICOXRTrackedDeviceType",
		Z_Construct_UEnum_PICOXRHMD_EPICOXRTrackedDeviceType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXRTrackedDeviceType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXRTrackedDeviceType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRHMD_EPICOXRTrackedDeviceType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRTrackedDeviceType()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRTrackedDeviceType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRTrackedDeviceType.InnerSingleton, Z_Construct_UEnum_PICOXRHMD_EPICOXRTrackedDeviceType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRTrackedDeviceType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRNodeType;
	static UEnum* EPICOXRNodeType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRNodeType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRNodeType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRHMD_EPICOXRNodeType, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("EPICOXRNodeType"));
		}
		return Z_Registration_Info_UEnum_EPICOXRNodeType.OuterSingleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPICOXRNodeType>()
	{
		return EPICOXRNodeType_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRHMD_EPICOXRNodeType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRHMD_EPICOXRNodeType_Statics::Enumerators[] = {
		{ "EPICOXRNodeType::LeftHand", (int64)EPICOXRNodeType::LeftHand },
		{ "EPICOXRNodeType::RightHand", (int64)EPICOXRNodeType::RightHand },
		{ "EPICOXRNodeType::Head", (int64)EPICOXRNodeType::Head },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRHMD_EPICOXRNodeType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Head.Name", "EPICOXRNodeType::Head" },
		{ "LeftHand.Name", "EPICOXRNodeType::LeftHand" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "RightHand.Name", "EPICOXRNodeType::RightHand" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRHMD_EPICOXRNodeType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		"EPICOXRNodeType",
		"EPICOXRNodeType",
		Z_Construct_UEnum_PICOXRHMD_EPICOXRNodeType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXRNodeType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXRNodeType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRHMD_EPICOXRNodeType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRNodeType()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRNodeType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRNodeType.InnerSingleton, Z_Construct_UEnum_PICOXRHMD_EPICOXRNodeType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRNodeType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRCameraType;
	static UEnum* EPICOXRCameraType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRCameraType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRCameraType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRHMD_EPICOXRCameraType, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("EPICOXRCameraType"));
		}
		return Z_Registration_Info_UEnum_EPICOXRCameraType.OuterSingleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPICOXRCameraType>()
	{
		return EPICOXRCameraType_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRHMD_EPICOXRCameraType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRHMD_EPICOXRCameraType_Statics::Enumerators[] = {
		{ "EPICOXRCameraType::Left", (int64)EPICOXRCameraType::Left },
		{ "EPICOXRCameraType::Right", (int64)EPICOXRCameraType::Right },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRHMD_EPICOXRCameraType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Left.DisplayName", "Left Camera" },
		{ "Left.Name", "EPICOXRCameraType::Left" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "Right.DisplayName", "Right Camera" },
		{ "Right.Name", "EPICOXRCameraType::Right" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRHMD_EPICOXRCameraType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		"EPICOXRCameraType",
		"EPICOXRCameraType",
		Z_Construct_UEnum_PICOXRHMD_EPICOXRCameraType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXRCameraType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXRCameraType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRHMD_EPICOXRCameraType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRCameraType()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRCameraType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRCameraType.InnerSingleton, Z_Construct_UEnum_PICOXRHMD_EPICOXRCameraType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRCameraType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRFoveationLevel;
	static UEnum* EPICOXRFoveationLevel_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRFoveationLevel.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRFoveationLevel.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRHMD_EPICOXRFoveationLevel, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("EPICOXRFoveationLevel"));
		}
		return Z_Registration_Info_UEnum_EPICOXRFoveationLevel.OuterSingleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPICOXRFoveationLevel>()
	{
		return EPICOXRFoveationLevel_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRHMD_EPICOXRFoveationLevel_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRHMD_EPICOXRFoveationLevel_Statics::Enumerators[] = {
		{ "EPICOXRFoveationLevel::None", (int64)EPICOXRFoveationLevel::None },
		{ "EPICOXRFoveationLevel::Low", (int64)EPICOXRFoveationLevel::Low },
		{ "EPICOXRFoveationLevel::Medium", (int64)EPICOXRFoveationLevel::Medium },
		{ "EPICOXRFoveationLevel::High", (int64)EPICOXRFoveationLevel::High },
		{ "EPICOXRFoveationLevel::TopHigh", (int64)EPICOXRFoveationLevel::TopHigh },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRHMD_EPICOXRFoveationLevel_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DisplayName", "PICOXR Foveated Rendering Level" },
		{ "High.Name", "EPICOXRFoveationLevel::High" },
		{ "Low.Name", "EPICOXRFoveationLevel::Low" },
		{ "Medium.Name", "EPICOXRFoveationLevel::Medium" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "None.Name", "EPICOXRFoveationLevel::None" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "PICOXR Foveated Rendering Level" },
#endif
		{ "TopHigh.Name", "EPICOXRFoveationLevel::TopHigh" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRHMD_EPICOXRFoveationLevel_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		"EPICOXRFoveationLevel",
		"EPICOXRFoveationLevel",
		Z_Construct_UEnum_PICOXRHMD_EPICOXRFoveationLevel_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXRFoveationLevel_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXRFoveationLevel_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRHMD_EPICOXRFoveationLevel_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRFoveationLevel()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRFoveationLevel.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRFoveationLevel.InnerSingleton, Z_Construct_UEnum_PICOXRHMD_EPICOXRFoveationLevel_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRFoveationLevel.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXREyeType;
	static UEnum* EPICOXREyeType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXREyeType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXREyeType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRHMD_EPICOXREyeType, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("EPICOXREyeType"));
		}
		return Z_Registration_Info_UEnum_EPICOXREyeType.OuterSingleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPICOXREyeType>()
	{
		return EPICOXREyeType_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRHMD_EPICOXREyeType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRHMD_EPICOXREyeType_Statics::Enumerators[] = {
		{ "EPICOXREyeType::LeftEye", (int64)EPICOXREyeType::LeftEye },
		{ "EPICOXREyeType::RightEye", (int64)EPICOXREyeType::RightEye },
		{ "EPICOXREyeType::BothEye", (int64)EPICOXREyeType::BothEye },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRHMD_EPICOXREyeType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "BothEye.DisplayName", "BothEye" },
		{ "BothEye.Name", "EPICOXREyeType::BothEye" },
		{ "LeftEye.DisplayName", "LeftEye" },
		{ "LeftEye.Name", "EPICOXREyeType::LeftEye" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "RightEye.DisplayName", "RightEye" },
		{ "RightEye.Name", "EPICOXREyeType::RightEye" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRHMD_EPICOXREyeType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		"EPICOXREyeType",
		"EPICOXREyeType",
		Z_Construct_UEnum_PICOXRHMD_EPICOXREyeType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXREyeType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXREyeType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRHMD_EPICOXREyeType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXREyeType()
	{
		if (!Z_Registration_Info_UEnum_EPICOXREyeType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXREyeType.InnerSingleton, Z_Construct_UEnum_PICOXRHMD_EPICOXREyeType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXREyeType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRDeviceAbilities;
	static UEnum* EPICOXRDeviceAbilities_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRDeviceAbilities.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRDeviceAbilities.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRHMD_EPICOXRDeviceAbilities, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("EPICOXRDeviceAbilities"));
		}
		return Z_Registration_Info_UEnum_EPICOXRDeviceAbilities.OuterSingleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPICOXRDeviceAbilities>()
	{
		return EPICOXRDeviceAbilities_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRHMD_EPICOXRDeviceAbilities_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRHMD_EPICOXRDeviceAbilities_Statics::Enumerators[] = {
		{ "EPICOXRDeviceAbilities::TRACKING_MODE_ROTATION_BIT", (int64)EPICOXRDeviceAbilities::TRACKING_MODE_ROTATION_BIT },
		{ "EPICOXRDeviceAbilities::TRACKING_MODE_POSITION_BIT", (int64)EPICOXRDeviceAbilities::TRACKING_MODE_POSITION_BIT },
		{ "EPICOXRDeviceAbilities::TRACKING_MODE_EYE_BIT", (int64)EPICOXRDeviceAbilities::TRACKING_MODE_EYE_BIT },
		{ "EPICOXRDeviceAbilities::TRACKING_MODE_FACE_BIT", (int64)EPICOXRDeviceAbilities::TRACKING_MODE_FACE_BIT },
		{ "EPICOXRDeviceAbilities::TRACKING_MODE_VCMOTOR_BIT", (int64)EPICOXRDeviceAbilities::TRACKING_MODE_VCMOTOR_BIT },
		{ "EPICOXRDeviceAbilities::TRACKING_MODE_HAND_BIT", (int64)EPICOXRDeviceAbilities::TRACKING_MODE_HAND_BIT },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRHMD_EPICOXRDeviceAbilities_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "TRACKING_MODE_EYE_BIT.DisplayName", "SupportEyeTracking" },
		{ "TRACKING_MODE_EYE_BIT.Name", "EPICOXRDeviceAbilities::TRACKING_MODE_EYE_BIT" },
		{ "TRACKING_MODE_FACE_BIT.DisplayName", "SupportFaceTracking" },
		{ "TRACKING_MODE_FACE_BIT.Name", "EPICOXRDeviceAbilities::TRACKING_MODE_FACE_BIT" },
		{ "TRACKING_MODE_HAND_BIT.DisplayName", "SupportHandTracking" },
		{ "TRACKING_MODE_HAND_BIT.Name", "EPICOXRDeviceAbilities::TRACKING_MODE_HAND_BIT" },
		{ "TRACKING_MODE_POSITION_BIT.DisplayName", "SupportPositionTracking" },
		{ "TRACKING_MODE_POSITION_BIT.Name", "EPICOXRDeviceAbilities::TRACKING_MODE_POSITION_BIT" },
		{ "TRACKING_MODE_ROTATION_BIT.DisplayName", "SupportRotationTracking" },
		{ "TRACKING_MODE_ROTATION_BIT.Name", "EPICOXRDeviceAbilities::TRACKING_MODE_ROTATION_BIT" },
		{ "TRACKING_MODE_VCMOTOR_BIT.DisplayName", "SupportBroadBandMotor" },
		{ "TRACKING_MODE_VCMOTOR_BIT.Name", "EPICOXRDeviceAbilities::TRACKING_MODE_VCMOTOR_BIT" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRHMD_EPICOXRDeviceAbilities_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		"EPICOXRDeviceAbilities",
		"EPICOXRDeviceAbilities",
		Z_Construct_UEnum_PICOXRHMD_EPICOXRDeviceAbilities_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXRDeviceAbilities_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXRDeviceAbilities_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRHMD_EPICOXRDeviceAbilities_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRDeviceAbilities()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRDeviceAbilities.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRDeviceAbilities.InnerSingleton, Z_Construct_UEnum_PICOXRHMD_EPICOXRDeviceAbilities_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRDeviceAbilities.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPerfSettingsLevel;
	static UEnum* EPerfSettingsLevel_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPerfSettingsLevel.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPerfSettingsLevel.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRHMD_EPerfSettingsLevel, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("EPerfSettingsLevel"));
		}
		return Z_Registration_Info_UEnum_EPerfSettingsLevel.OuterSingleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPerfSettingsLevel>()
	{
		return EPerfSettingsLevel_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRHMD_EPerfSettingsLevel_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRHMD_EPerfSettingsLevel_Statics::Enumerators[] = {
		{ "EPerfSettingsLevel::XR_PERF_SETTINGS_LEVEL_POWER_SAVINGS_EXT", (int64)EPerfSettingsLevel::XR_PERF_SETTINGS_LEVEL_POWER_SAVINGS_EXT },
		{ "EPerfSettingsLevel::XR_PERF_SETTINGS_LEVEL_SUSTAINED_LOW_EXT", (int64)EPerfSettingsLevel::XR_PERF_SETTINGS_LEVEL_SUSTAINED_LOW_EXT },
		{ "EPerfSettingsLevel::XR_PERF_SETTINGS_LEVEL_SUSTAINED_HIGH_EXT", (int64)EPerfSettingsLevel::XR_PERF_SETTINGS_LEVEL_SUSTAINED_HIGH_EXT },
		{ "EPerfSettingsLevel::XR_PERF_SETTINGS_LEVEL_BOOST_EXT", (int64)EPerfSettingsLevel::XR_PERF_SETTINGS_LEVEL_BOOST_EXT },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRHMD_EPerfSettingsLevel_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "XR_PERF_SETTINGS_LEVEL_BOOST_EXT.DisplayName", "Boost(*)" },
		{ "XR_PERF_SETTINGS_LEVEL_BOOST_EXT.Name", "EPerfSettingsLevel::XR_PERF_SETTINGS_LEVEL_BOOST_EXT" },
		{ "XR_PERF_SETTINGS_LEVEL_POWER_SAVINGS_EXT.DisplayName", "PowerSavings" },
		{ "XR_PERF_SETTINGS_LEVEL_POWER_SAVINGS_EXT.Name", "EPerfSettingsLevel::XR_PERF_SETTINGS_LEVEL_POWER_SAVINGS_EXT" },
		{ "XR_PERF_SETTINGS_LEVEL_SUSTAINED_HIGH_EXT.DisplayName", "SustainedHigh" },
		{ "XR_PERF_SETTINGS_LEVEL_SUSTAINED_HIGH_EXT.Name", "EPerfSettingsLevel::XR_PERF_SETTINGS_LEVEL_SUSTAINED_HIGH_EXT" },
		{ "XR_PERF_SETTINGS_LEVEL_SUSTAINED_LOW_EXT.DisplayName", "SustainedLow" },
		{ "XR_PERF_SETTINGS_LEVEL_SUSTAINED_LOW_EXT.Name", "EPerfSettingsLevel::XR_PERF_SETTINGS_LEVEL_SUSTAINED_LOW_EXT" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRHMD_EPerfSettingsLevel_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		"EPerfSettingsLevel",
		"EPerfSettingsLevel",
		Z_Construct_UEnum_PICOXRHMD_EPerfSettingsLevel_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPerfSettingsLevel_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPerfSettingsLevel_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRHMD_EPerfSettingsLevel_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRHMD_EPerfSettingsLevel()
	{
		if (!Z_Registration_Info_UEnum_EPerfSettingsLevel.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPerfSettingsLevel.InnerSingleton, Z_Construct_UEnum_PICOXRHMD_EPerfSettingsLevel_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPerfSettingsLevel.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPerformanceSettingTypes;
	static UEnum* EPerformanceSettingTypes_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPerformanceSettingTypes.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPerformanceSettingTypes.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRHMD_EPerformanceSettingTypes, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("EPerformanceSettingTypes"));
		}
		return Z_Registration_Info_UEnum_EPerformanceSettingTypes.OuterSingleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPerformanceSettingTypes>()
	{
		return EPerformanceSettingTypes_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRHMD_EPerformanceSettingTypes_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRHMD_EPerformanceSettingTypes_Statics::Enumerators[] = {
		{ "EPerformanceSettingTypes::CPULevel", (int64)EPerformanceSettingTypes::CPULevel },
		{ "EPerformanceSettingTypes::GPULevel", (int64)EPerformanceSettingTypes::GPULevel },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRHMD_EPerformanceSettingTypes_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CPULevel.DisplayName", "CPU Level" },
		{ "CPULevel.Name", "EPerformanceSettingTypes::CPULevel" },
		{ "GPULevel.DisplayName", "GPU Level" },
		{ "GPULevel.Name", "EPerformanceSettingTypes::GPULevel" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRHMD_EPerformanceSettingTypes_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		"EPerformanceSettingTypes",
		"EPerformanceSettingTypes",
		Z_Construct_UEnum_PICOXRHMD_EPerformanceSettingTypes_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPerformanceSettingTypes_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPerformanceSettingTypes_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRHMD_EPerformanceSettingTypes_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRHMD_EPerformanceSettingTypes()
	{
		if (!Z_Registration_Info_UEnum_EPerformanceSettingTypes.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPerformanceSettingTypes.InnerSingleton, Z_Construct_UEnum_PICOXRHMD_EPerformanceSettingTypes_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPerformanceSettingTypes.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EFtLipsyncCtlVal;
	static UEnum* EFtLipsyncCtlVal_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EFtLipsyncCtlVal.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EFtLipsyncCtlVal.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRHMD_EFtLipsyncCtlVal, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("EFtLipsyncCtlVal"));
		}
		return Z_Registration_Info_UEnum_EFtLipsyncCtlVal.OuterSingleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EFtLipsyncCtlVal>()
	{
		return EFtLipsyncCtlVal_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRHMD_EFtLipsyncCtlVal_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRHMD_EFtLipsyncCtlVal_Statics::Enumerators[] = {
		{ "EFtLipsyncCtlVal::STOP_FT", (int64)EFtLipsyncCtlVal::STOP_FT },
		{ "EFtLipsyncCtlVal::STOP_LIPSYNC", (int64)EFtLipsyncCtlVal::STOP_LIPSYNC },
		{ "EFtLipsyncCtlVal::START_FT", (int64)EFtLipsyncCtlVal::START_FT },
		{ "EFtLipsyncCtlVal::START_LIPSYNC", (int64)EFtLipsyncCtlVal::START_LIPSYNC },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRHMD_EFtLipsyncCtlVal_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "START_FT.Name", "EFtLipsyncCtlVal::START_FT" },
		{ "START_LIPSYNC.Name", "EFtLipsyncCtlVal::START_LIPSYNC" },
		{ "STOP_FT.Name", "EFtLipsyncCtlVal::STOP_FT" },
		{ "STOP_LIPSYNC.Name", "EFtLipsyncCtlVal::STOP_LIPSYNC" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRHMD_EFtLipsyncCtlVal_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		"EFtLipsyncCtlVal",
		"EFtLipsyncCtlVal",
		Z_Construct_UEnum_PICOXRHMD_EFtLipsyncCtlVal_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EFtLipsyncCtlVal_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EFtLipsyncCtlVal_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRHMD_EFtLipsyncCtlVal_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRHMD_EFtLipsyncCtlVal()
	{
		if (!Z_Registration_Info_UEnum_EFtLipsyncCtlVal.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EFtLipsyncCtlVal.InnerSingleton, Z_Construct_UEnum_PICOXRHMD_EFtLipsyncCtlVal_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EFtLipsyncCtlVal.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PxrSensorState;
class UScriptStruct* FPxrSensorState::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PxrSensorState.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PxrSensorState.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPxrSensorState, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("PxrSensorState"));
	}
	return Z_Registration_Info_UScriptStruct_PxrSensorState.OuterSingleton;
}
template<> PICOXRHMD_API UScriptStruct* StaticStruct<FPxrSensorState>()
{
	return FPxrSensorState::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPxrSensorState_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_status_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_status;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_poseQuat_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_poseQuat;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_poseVector_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_poseVector;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_globalPoseQuat_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_globalPoseQuat;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_globalPoseVector_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_globalPoseVector;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_angularVelocity_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_angularVelocity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_linearVelocity_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_linearVelocity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_angularAcceleration_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_angularAcceleration;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_linearAcceleration_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_linearAcceleration;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_poseTimeStampNs_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_poseTimeStampNs;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrSensorState_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPxrSensorState>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_status_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_status = { "status", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrSensorState, status), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_status_MetaData), Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_status_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseQuat_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseQuat = { "poseQuat", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrSensorState, poseQuat), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseQuat_MetaData), Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseQuat_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseVector_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseVector = { "poseVector", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrSensorState, poseVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseVector_MetaData), Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseVector_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_globalPoseQuat_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_globalPoseQuat = { "globalPoseQuat", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrSensorState, globalPoseQuat), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_globalPoseQuat_MetaData), Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_globalPoseQuat_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_globalPoseVector_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_globalPoseVector = { "globalPoseVector", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrSensorState, globalPoseVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_globalPoseVector_MetaData), Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_globalPoseVector_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_angularVelocity_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_angularVelocity = { "angularVelocity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrSensorState, angularVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_angularVelocity_MetaData), Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_angularVelocity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_linearVelocity_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_linearVelocity = { "linearVelocity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrSensorState, linearVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_linearVelocity_MetaData), Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_linearVelocity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_angularAcceleration_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_angularAcceleration = { "angularAcceleration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrSensorState, angularAcceleration), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_angularAcceleration_MetaData), Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_angularAcceleration_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_linearAcceleration_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_linearAcceleration = { "linearAcceleration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrSensorState, linearAcceleration), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_linearAcceleration_MetaData), Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_linearAcceleration_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseTimeStampNs_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseTimeStampNs = { "poseTimeStampNs", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrSensorState, poseTimeStampNs), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseTimeStampNs_MetaData), Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseTimeStampNs_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPxrSensorState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_status,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseQuat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseVector,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_globalPoseQuat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_globalPoseVector,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_angularVelocity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_linearVelocity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_angularAcceleration,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_linearAcceleration,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseTimeStampNs,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPxrSensorState_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		&NewStructOps,
		"PxrSensorState",
		Z_Construct_UScriptStruct_FPxrSensorState_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::PropPointers),
		sizeof(FPxrSensorState),
		alignof(FPxrSensorState),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPxrSensorState_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPxrSensorState()
	{
		if (!Z_Registration_Info_UScriptStruct_PxrSensorState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PxrSensorState.InnerSingleton, Z_Construct_UScriptStruct_FPxrSensorState_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PxrSensorState.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PICOXREyeTrackingData;
class UScriptStruct* FPICOXREyeTrackingData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PICOXREyeTrackingData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PICOXREyeTrackingData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPICOXREyeTrackingData, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("PICOXREyeTrackingData"));
	}
	return Z_Registration_Info_UScriptStruct_PICOXREyeTrackingData.OuterSingleton;
}
template<> PICOXRHMD_API UScriptStruct* StaticStruct<FPICOXREyeTrackingData>()
{
	return FPICOXREyeTrackingData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LeftEyePoseStatus_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_LeftEyePoseStatus;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RightEyePoseStatus_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_RightEyePoseStatus;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CombinedEyePoseStatus_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_CombinedEyePoseStatus;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CombinedEyeGazePoint_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_CombinedEyeGazePoint;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CombinedEyeGazeVector_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_CombinedEyeGazeVector;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LeftEyeOpenness_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_LeftEyeOpenness;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RightEyeOpenness_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RightEyeOpenness;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LeftEyePositionGuide_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_LeftEyePositionGuide;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RightEyePositionGuide_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RightEyePositionGuide;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FoveatedGazeDirection_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_FoveatedGazeDirection;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FoveatedGazeTrackingState_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_FoveatedGazeTrackingState;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DisplayName", "PICOXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPICOXREyeTrackingData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_LeftEyePoseStatus_MetaData[] = {
		{ "Category", "PICOXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_LeftEyePoseStatus = { "LeftEyePoseStatus", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOXREyeTrackingData, LeftEyePoseStatus), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_LeftEyePoseStatus_MetaData), Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_LeftEyePoseStatus_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_RightEyePoseStatus_MetaData[] = {
		{ "Category", "PICOXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_RightEyePoseStatus = { "RightEyePoseStatus", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOXREyeTrackingData, RightEyePoseStatus), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_RightEyePoseStatus_MetaData), Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_RightEyePoseStatus_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_CombinedEyePoseStatus_MetaData[] = {
		{ "Category", "PICOXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_CombinedEyePoseStatus = { "CombinedEyePoseStatus", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOXREyeTrackingData, CombinedEyePoseStatus), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_CombinedEyePoseStatus_MetaData), Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_CombinedEyePoseStatus_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_CombinedEyeGazePoint_MetaData[] = {
		{ "Category", "PICOXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_CombinedEyeGazePoint = { "CombinedEyeGazePoint", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOXREyeTrackingData, CombinedEyeGazePoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_CombinedEyeGazePoint_MetaData), Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_CombinedEyeGazePoint_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_CombinedEyeGazeVector_MetaData[] = {
		{ "Category", "PICOXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_CombinedEyeGazeVector = { "CombinedEyeGazeVector", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOXREyeTrackingData, CombinedEyeGazeVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_CombinedEyeGazeVector_MetaData), Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_CombinedEyeGazeVector_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_LeftEyeOpenness_MetaData[] = {
		{ "Category", "PICOXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_LeftEyeOpenness = { "LeftEyeOpenness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOXREyeTrackingData, LeftEyeOpenness), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_LeftEyeOpenness_MetaData), Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_LeftEyeOpenness_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_RightEyeOpenness_MetaData[] = {
		{ "Category", "PICOXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_RightEyeOpenness = { "RightEyeOpenness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOXREyeTrackingData, RightEyeOpenness), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_RightEyeOpenness_MetaData), Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_RightEyeOpenness_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_LeftEyePositionGuide_MetaData[] = {
		{ "Category", "PICOXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_LeftEyePositionGuide = { "LeftEyePositionGuide", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOXREyeTrackingData, LeftEyePositionGuide), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_LeftEyePositionGuide_MetaData), Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_LeftEyePositionGuide_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_RightEyePositionGuide_MetaData[] = {
		{ "Category", "PICOXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_RightEyePositionGuide = { "RightEyePositionGuide", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOXREyeTrackingData, RightEyePositionGuide), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_RightEyePositionGuide_MetaData), Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_RightEyePositionGuide_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_FoveatedGazeDirection_MetaData[] = {
		{ "Category", "PICOXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_FoveatedGazeDirection = { "FoveatedGazeDirection", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOXREyeTrackingData, FoveatedGazeDirection), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_FoveatedGazeDirection_MetaData), Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_FoveatedGazeDirection_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_FoveatedGazeTrackingState_MetaData[] = {
		{ "Category", "PICOXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_FoveatedGazeTrackingState = { "FoveatedGazeTrackingState", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPICOXREyeTrackingData, FoveatedGazeTrackingState), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_FoveatedGazeTrackingState_MetaData), Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_FoveatedGazeTrackingState_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_LeftEyePoseStatus,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_RightEyePoseStatus,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_CombinedEyePoseStatus,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_CombinedEyeGazePoint,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_CombinedEyeGazeVector,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_LeftEyeOpenness,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_RightEyeOpenness,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_LeftEyePositionGuide,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_RightEyePositionGuide,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_FoveatedGazeDirection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewProp_FoveatedGazeTrackingState,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		&NewStructOps,
		"PICOXREyeTrackingData",
		Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::PropPointers),
		sizeof(FPICOXREyeTrackingData),
		alignof(FPICOXREyeTrackingData),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPICOXREyeTrackingData()
	{
		if (!Z_Registration_Info_UScriptStruct_PICOXREyeTrackingData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PICOXREyeTrackingData.InnerSingleton, Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PICOXREyeTrackingData.InnerSingleton;
	}
	struct Z_Construct_UDelegateFunction_PICOXRHMD_PICOXRIPDChangedDelegate__DelegateSignature_Statics
	{
		struct _Script_PICOXRHMD_eventPICOXRIPDChangedDelegate_Parms
		{
			float Ipd;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Ipd;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_PICOXRHMD_PICOXRIPDChangedDelegate__DelegateSignature_Statics::NewProp_Ipd = { "Ipd", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_PICOXRHMD_eventPICOXRIPDChangedDelegate_Parms, Ipd), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_PICOXRHMD_PICOXRIPDChangedDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_PICOXRHMD_PICOXRIPDChangedDelegate__DelegateSignature_Statics::NewProp_Ipd,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_PICOXRHMD_PICOXRIPDChangedDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_PICOXRHMD_PICOXRIPDChangedDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_PICOXRHMD, nullptr, "PICOXRIPDChangedDelegate__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_PICOXRHMD_PICOXRIPDChangedDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PICOXRHMD_PICOXRIPDChangedDelegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_PICOXRHMD_PICOXRIPDChangedDelegate__DelegateSignature_Statics::_Script_PICOXRHMD_eventPICOXRIPDChangedDelegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PICOXRHMD_PICOXRIPDChangedDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_PICOXRHMD_PICOXRIPDChangedDelegate__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PICOXRHMD_PICOXRIPDChangedDelegate__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_PICOXRHMD_PICOXRIPDChangedDelegate__DelegateSignature_Statics::_Script_PICOXRHMD_eventPICOXRIPDChangedDelegate_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_PICOXRHMD_PICOXRIPDChangedDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_PICOXRHMD_PICOXRIPDChangedDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FPICOXRIPDChangedDelegate_DelegateWrapper(const FScriptDelegate& PICOXRIPDChangedDelegate, float Ipd)
{
	struct _Script_PICOXRHMD_eventPICOXRIPDChangedDelegate_Parms
	{
		float Ipd;
	};
	_Script_PICOXRHMD_eventPICOXRIPDChangedDelegate_Parms Parms;
	Parms.Ipd=Ipd;
	PICOXRIPDChangedDelegate.ProcessDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetDeviceName)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetDeviceName();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetPredictedDisplayTime)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetPredictedDisplayTime();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetToDeltaSensorY)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetToDeltaSensorY();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_SetFoveatedRenderingMode)
	{
		P_GET_ENUM(EFoveationRenderingMode,Z_Param_Mode);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_SetFoveatedRenderingMode(EFoveationRenderingMode(Z_Param_Mode));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_SelectCoordinateSpace)
	{
		P_GET_ENUM(EPICOXRCoordinateType,Z_Param_CoordinateType);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_SelectCoordinateSpace(EPICOXRCoordinateType(Z_Param_CoordinateType));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetHmdBatteryLevel)
	{
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_Battery);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetHmdBatteryLevel(Z_Param_Out_Battery);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetBaseRotationAndBaseOffsetInMeters)
	{
		P_GET_STRUCT_REF(FRotator,Z_Param_Out_OutRotation);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_OutBaseOffsetInMeters);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPICOXRHMDFunctionLibrary::PXR_GetBaseRotationAndBaseOffsetInMeters(Z_Param_Out_OutRotation,Z_Param_Out_OutBaseOffsetInMeters);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_SetBaseRotationAndBaseOffsetInMeters)
	{
		P_GET_STRUCT(FRotator,Z_Param_Rotation);
		P_GET_STRUCT(FVector,Z_Param_BaseOffsetInMeters);
		P_GET_PROPERTY(FByteProperty,Z_Param_Options);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPICOXRHMDFunctionLibrary::PXR_SetBaseRotationAndBaseOffsetInMeters(Z_Param_Rotation,Z_Param_BaseOffsetInMeters,EOrientPositionSelector::Type(Z_Param_Options));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_SetLateLatchingEnable)
	{
		P_GET_UBOOL(Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPICOXRHMDFunctionLibrary::PXR_SetLateLatchingEnable(Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_QueryDeviceAbilities)
	{
		P_GET_ENUM(EPICOXRDeviceAbilities,Z_Param_DeviceAbility);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_QueryDeviceAbilities(EPICOXRDeviceAbilities(Z_Param_DeviceAbility));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetPredictedMainSensorState)
	{
		P_GET_STRUCT_REF(FPxrSensorState,Z_Param_Out_sensorState);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_sensorFrameIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPICOXRHMDFunctionLibrary::PXR_GetPredictedMainSensorState(Z_Param_Out_sensorState,Z_Param_Out_sensorFrameIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_SetExtraLatencyMode)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Mode);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_SetExtraLatencyMode(Z_Param_Mode);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetDisplayFrequenciesAvailable)
	{
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_Count);
		P_GET_TARRAY_REF(float,Z_Param_Out_AvailableRates);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetDisplayFrequenciesAvailable(Z_Param_Out_Count,Z_Param_Out_AvailableRates);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_SetSensorLostCMST)
	{
		P_GET_UBOOL(Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_SetSensorLostCMST(Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_SetSensorLostCustomMode)
	{
		P_GET_UBOOL(Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_SetSensorLostCustomMode(Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_SetFoveationParameter)
	{
		P_GET_STRUCT(FVector2D,Z_Param_FoveationGainValue);
		P_GET_PROPERTY(FFloatProperty,Z_Param_FoveationAreaValue);
		P_GET_PROPERTY(FFloatProperty,Z_Param_FoveationMinimumValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_SetFoveationParameter(Z_Param_FoveationGainValue,Z_Param_FoveationAreaValue,Z_Param_FoveationMinimumValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_SetFoveationLevel)
	{
		P_GET_ENUM(EPICOXRFoveationLevel,Z_Param_Level);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_SetFoveationLevel(EPICOXRFoveationLevel(Z_Param_Level));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetFoveationLevel)
	{
		P_GET_ENUM_REF(EPICOXRFoveationLevel,Z_Param_Out_Level);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetFoveationLevel((EPICOXRFoveationLevel&)(Z_Param_Out_Level));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_SetSeeThroughBackground)
	{
		P_GET_UBOOL(Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_SetSeeThroughBackground(Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetBoundaryDimensions)
	{
		P_GET_ENUM(EPICOXRBoundaryType,Z_Param_BoundaryType);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetBoundaryDimensions(EPICOXRBoundaryType(Z_Param_BoundaryType));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetBoundaryGeometry)
	{
		P_GET_ENUM(EPICOXRBoundaryType,Z_Param_BoundaryType);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FVector>*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetBoundaryGeometry(EPICOXRBoundaryType(Z_Param_BoundaryType));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_BoundaryTestPoint)
	{
		P_GET_STRUCT(FVector,Z_Param_Point);
		P_GET_ENUM(EPICOXRBoundaryType,Z_Param_BoundaryType);
		P_GET_UBOOL_REF(Z_Param_Out_IsTriggering);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_ClosestDistance);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_ClosestPoint);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_ClosestPointNormal);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_BoundaryTestPoint(Z_Param_Point,EPICOXRBoundaryType(Z_Param_BoundaryType),Z_Param_Out_IsTriggering,Z_Param_Out_ClosestDistance,Z_Param_Out_ClosestPoint,Z_Param_Out_ClosestPointNormal);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_BoundaryTestNode)
	{
		P_GET_ENUM(EPICOXRNodeType,Z_Param_DeviceType);
		P_GET_ENUM(EPICOXRBoundaryType,Z_Param_BoundaryType);
		P_GET_UBOOL_REF(Z_Param_Out_IsTriggering);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_ClosestDistance);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_ClosestPoint);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_ClosestPointNormal);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_BoundaryTestNode(EPICOXRNodeType(Z_Param_DeviceType),EPICOXRBoundaryType(Z_Param_BoundaryType),Z_Param_Out_IsTriggering,Z_Param_Out_ClosestDistance,Z_Param_Out_ClosestPoint,Z_Param_Out_ClosestPointNormal);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetBoundaryVisible)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetBoundaryVisible();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_SetBoundaryVisible)
	{
		P_GET_UBOOL(Z_Param_NewVisible);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPICOXRHMDFunctionLibrary::PXR_SetBoundaryVisible(Z_Param_NewVisible);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetBoundaryEnabled)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetBoundaryEnabled();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetBoundaryConfigured)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetBoundaryConfigured();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execGetFocusState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRHMDFunctionLibrary::GetFocusState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_SetColorScaleAndOffset)
	{
		P_GET_STRUCT(FLinearColor,Z_Param_ColorScale);
		P_GET_STRUCT(FLinearColor,Z_Param_ColorOffset);
		P_GET_UBOOL(Z_Param_bApplyToAllLayers);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPICOXRHMDFunctionLibrary::PXR_SetColorScaleAndOffset(Z_Param_ColorScale,Z_Param_ColorOffset,Z_Param_bApplyToAllLayers);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_SetSystemDisplayFrequency)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Rate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPICOXRHMDFunctionLibrary::PXR_SetSystemDisplayFrequency(Z_Param_Rate);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetSystemDisplayFrequency)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetSystemDisplayFrequency();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetPerformanceLevel)
	{
		P_GET_ENUM(EPerformanceSettingTypes,Z_Param_SettingType);
		P_GET_ENUM_REF(EPerfSettingsLevel,Z_Param_Out_Level);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetPerformanceLevel(EPerformanceSettingTypes(Z_Param_SettingType),(EPerfSettingsLevel&)(Z_Param_Out_Level));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_SetPerformanceLevel)
	{
		P_GET_ENUM(EPerformanceSettingTypes,Z_Param_SettingType);
		P_GET_ENUM(EPerfSettingsLevel,Z_Param_Level);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_SetPerformanceLevel(EPerformanceSettingTypes(Z_Param_SettingType),EPerfSettingsLevel(Z_Param_Level));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetCPUAndGPULevels)
	{
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_CPULevel);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_GPULevel);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPICOXRHMDFunctionLibrary::PXR_GetCPUAndGPULevels(Z_Param_Out_CPULevel,Z_Param_Out_GPULevel);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_SetCPUAndGPULevels)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_CPULevel);
		P_GET_PROPERTY(FIntProperty,Z_Param_GPULevel);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPICOXRHMDFunctionLibrary::PXR_SetCPUAndGPULevels(Z_Param_CPULevel,Z_Param_GPULevel);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetCurrentDisplayFrequency)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetCurrentDisplayFrequency();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetDeviceModel)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetDeviceModel();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetEventManager)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPICOXREventManager**)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetEventManager();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_IPDChangedDelegates)
	{
		P_GET_PROPERTY(FDelegateProperty,Z_Param_OnPICOXRIPDChanged);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPICOXRHMDFunctionLibrary::PXR_IPDChangedDelegates(FPICOXRIPDChangedDelegate(Z_Param_OnPICOXRIPDChanged));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetIPD)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetIPD();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetHFov)
	{
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_HFOVInDegrees);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPICOXRHMDFunctionLibrary::PXR_GetHFov(Z_Param_Out_HFOVInDegrees);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetVFov)
	{
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_VFOVInDegrees);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPICOXRHMDFunctionLibrary::PXR_GetVFov(Z_Param_Out_VFOVInDegrees);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_SetFieldOfView)
	{
		P_GET_ENUM(EPICOXREyeType,Z_Param_Eye);
		P_GET_PROPERTY(FFloatProperty,Z_Param_FovLeftInDegrees);
		P_GET_PROPERTY(FFloatProperty,Z_Param_FovRightInDegrees);
		P_GET_PROPERTY(FFloatProperty,Z_Param_FovUpInDegrees);
		P_GET_PROPERTY(FFloatProperty,Z_Param_FovDownInDegrees);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_SetFieldOfView(EPICOXREyeType(Z_Param_Eye),Z_Param_FovLeftInDegrees,Z_Param_FovRightInDegrees,Z_Param_FovUpInDegrees,Z_Param_FovDownInDegrees);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetFieldOfView)
	{
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_HFOVInDegrees);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_VFOVInDegrees);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetFieldOfView(Z_Param_Out_HFOVInDegrees,Z_Param_Out_VFOVInDegrees);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_ResetHMDSensor)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_ResetHMDSensor();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetHMDWornState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TEnumAsByte<EHMDWornState::Type>*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetHMDWornState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetAngularAcceleration)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetAngularAcceleration();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetVelocity)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetVelocity();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetAcceleration)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetAcceleration();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetAngularVelocity)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetAngularVelocity();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_DoesSupportPositionalTracking)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_DoesSupportPositionalTracking();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetCurrentPosition)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetCurrentPosition();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRHMDFunctionLibrary::execPXR_GetCurrentOrientation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FQuat*)Z_Param__Result=UPICOXRHMDFunctionLibrary::PXR_GetCurrentOrientation();
		P_NATIVE_END;
	}
	void UPICOXRHMDFunctionLibrary::StaticRegisterNativesUPICOXRHMDFunctionLibrary()
	{
		UClass* Class = UPICOXRHMDFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetFocusState", &UPICOXRHMDFunctionLibrary::execGetFocusState },
			{ "PXR_BoundaryTestNode", &UPICOXRHMDFunctionLibrary::execPXR_BoundaryTestNode },
			{ "PXR_BoundaryTestPoint", &UPICOXRHMDFunctionLibrary::execPXR_BoundaryTestPoint },
			{ "PXR_DoesSupportPositionalTracking", &UPICOXRHMDFunctionLibrary::execPXR_DoesSupportPositionalTracking },
			{ "PXR_GetAcceleration", &UPICOXRHMDFunctionLibrary::execPXR_GetAcceleration },
			{ "PXR_GetAngularAcceleration", &UPICOXRHMDFunctionLibrary::execPXR_GetAngularAcceleration },
			{ "PXR_GetAngularVelocity", &UPICOXRHMDFunctionLibrary::execPXR_GetAngularVelocity },
			{ "PXR_GetBaseRotationAndBaseOffsetInMeters", &UPICOXRHMDFunctionLibrary::execPXR_GetBaseRotationAndBaseOffsetInMeters },
			{ "PXR_GetBoundaryConfigured", &UPICOXRHMDFunctionLibrary::execPXR_GetBoundaryConfigured },
			{ "PXR_GetBoundaryDimensions", &UPICOXRHMDFunctionLibrary::execPXR_GetBoundaryDimensions },
			{ "PXR_GetBoundaryEnabled", &UPICOXRHMDFunctionLibrary::execPXR_GetBoundaryEnabled },
			{ "PXR_GetBoundaryGeometry", &UPICOXRHMDFunctionLibrary::execPXR_GetBoundaryGeometry },
			{ "PXR_GetBoundaryVisible", &UPICOXRHMDFunctionLibrary::execPXR_GetBoundaryVisible },
			{ "PXR_GetCPUAndGPULevels", &UPICOXRHMDFunctionLibrary::execPXR_GetCPUAndGPULevels },
			{ "PXR_GetCurrentDisplayFrequency", &UPICOXRHMDFunctionLibrary::execPXR_GetCurrentDisplayFrequency },
			{ "PXR_GetCurrentOrientation", &UPICOXRHMDFunctionLibrary::execPXR_GetCurrentOrientation },
			{ "PXR_GetCurrentPosition", &UPICOXRHMDFunctionLibrary::execPXR_GetCurrentPosition },
			{ "PXR_GetDeviceModel", &UPICOXRHMDFunctionLibrary::execPXR_GetDeviceModel },
			{ "PXR_GetDeviceName", &UPICOXRHMDFunctionLibrary::execPXR_GetDeviceName },
			{ "PXR_GetDisplayFrequenciesAvailable", &UPICOXRHMDFunctionLibrary::execPXR_GetDisplayFrequenciesAvailable },
			{ "PXR_GetEventManager", &UPICOXRHMDFunctionLibrary::execPXR_GetEventManager },
			{ "PXR_GetFieldOfView", &UPICOXRHMDFunctionLibrary::execPXR_GetFieldOfView },
			{ "PXR_GetFoveationLevel", &UPICOXRHMDFunctionLibrary::execPXR_GetFoveationLevel },
			{ "PXR_GetHFov", &UPICOXRHMDFunctionLibrary::execPXR_GetHFov },
			{ "PXR_GetHmdBatteryLevel", &UPICOXRHMDFunctionLibrary::execPXR_GetHmdBatteryLevel },
			{ "PXR_GetHMDWornState", &UPICOXRHMDFunctionLibrary::execPXR_GetHMDWornState },
			{ "PXR_GetIPD", &UPICOXRHMDFunctionLibrary::execPXR_GetIPD },
			{ "PXR_GetPerformanceLevel", &UPICOXRHMDFunctionLibrary::execPXR_GetPerformanceLevel },
			{ "PXR_GetPredictedDisplayTime", &UPICOXRHMDFunctionLibrary::execPXR_GetPredictedDisplayTime },
			{ "PXR_GetPredictedMainSensorState", &UPICOXRHMDFunctionLibrary::execPXR_GetPredictedMainSensorState },
			{ "PXR_GetSystemDisplayFrequency", &UPICOXRHMDFunctionLibrary::execPXR_GetSystemDisplayFrequency },
			{ "PXR_GetToDeltaSensorY", &UPICOXRHMDFunctionLibrary::execPXR_GetToDeltaSensorY },
			{ "PXR_GetVelocity", &UPICOXRHMDFunctionLibrary::execPXR_GetVelocity },
			{ "PXR_GetVFov", &UPICOXRHMDFunctionLibrary::execPXR_GetVFov },
			{ "PXR_IPDChangedDelegates", &UPICOXRHMDFunctionLibrary::execPXR_IPDChangedDelegates },
			{ "PXR_QueryDeviceAbilities", &UPICOXRHMDFunctionLibrary::execPXR_QueryDeviceAbilities },
			{ "PXR_ResetHMDSensor", &UPICOXRHMDFunctionLibrary::execPXR_ResetHMDSensor },
			{ "PXR_SelectCoordinateSpace", &UPICOXRHMDFunctionLibrary::execPXR_SelectCoordinateSpace },
			{ "PXR_SetBaseRotationAndBaseOffsetInMeters", &UPICOXRHMDFunctionLibrary::execPXR_SetBaseRotationAndBaseOffsetInMeters },
			{ "PXR_SetBoundaryVisible", &UPICOXRHMDFunctionLibrary::execPXR_SetBoundaryVisible },
			{ "PXR_SetColorScaleAndOffset", &UPICOXRHMDFunctionLibrary::execPXR_SetColorScaleAndOffset },
			{ "PXR_SetCPUAndGPULevels", &UPICOXRHMDFunctionLibrary::execPXR_SetCPUAndGPULevels },
			{ "PXR_SetExtraLatencyMode", &UPICOXRHMDFunctionLibrary::execPXR_SetExtraLatencyMode },
			{ "PXR_SetFieldOfView", &UPICOXRHMDFunctionLibrary::execPXR_SetFieldOfView },
			{ "PXR_SetFoveatedRenderingMode", &UPICOXRHMDFunctionLibrary::execPXR_SetFoveatedRenderingMode },
			{ "PXR_SetFoveationLevel", &UPICOXRHMDFunctionLibrary::execPXR_SetFoveationLevel },
			{ "PXR_SetFoveationParameter", &UPICOXRHMDFunctionLibrary::execPXR_SetFoveationParameter },
			{ "PXR_SetLateLatchingEnable", &UPICOXRHMDFunctionLibrary::execPXR_SetLateLatchingEnable },
			{ "PXR_SetPerformanceLevel", &UPICOXRHMDFunctionLibrary::execPXR_SetPerformanceLevel },
			{ "PXR_SetSeeThroughBackground", &UPICOXRHMDFunctionLibrary::execPXR_SetSeeThroughBackground },
			{ "PXR_SetSensorLostCMST", &UPICOXRHMDFunctionLibrary::execPXR_SetSensorLostCMST },
			{ "PXR_SetSensorLostCustomMode", &UPICOXRHMDFunctionLibrary::execPXR_SetSensorLostCustomMode },
			{ "PXR_SetSystemDisplayFrequency", &UPICOXRHMDFunctionLibrary::execPXR_SetSystemDisplayFrequency },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_GetFocusState_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventGetFocusState_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_GetFocusState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventGetFocusState_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_GetFocusState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventGetFocusState_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_GetFocusState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_GetFocusState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_GetFocusState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_GetFocusState_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the current focus state of the HMD.</summary>\n/// <returns>Bool: \n/// <ul>\n/// <li>`true`: the HMD has focus</li>\n/// <li>`false`: the HMD has lost focus</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the current focus state of the HMD.</summary>\n<returns>Bool:\n<ul>\n<li>`true`: the HMD has focus</li>\n<li>`false`: the HMD has lost focus</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_GetFocusState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "GetFocusState", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_GetFocusState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_GetFocusState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_GetFocusState_Statics::PICOXRHMDFunctionLibrary_eventGetFocusState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_GetFocusState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_GetFocusState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_GetFocusState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_GetFocusState_Statics::PICOXRHMDFunctionLibrary_eventGetFocusState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_GetFocusState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_GetFocusState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestNode_Parms
		{
			EPICOXRNodeType DeviceType;
			EPICOXRBoundaryType BoundaryType;
			bool IsTriggering;
			float ClosestDistance;
			FVector ClosestPoint;
			FVector ClosestPointNormal;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceType;
		static const UECodeGen_Private::FBytePropertyParams NewProp_BoundaryType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_BoundaryType;
		static void NewProp_IsTriggering_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsTriggering;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ClosestDistance;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ClosestPoint;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ClosestPointNormal;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_DeviceType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_DeviceType = { "DeviceType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestNode_Parms, DeviceType), Z_Construct_UEnum_PICOXRHMD_EPICOXRNodeType, METADATA_PARAMS(0, nullptr) }; // 1745141064
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_BoundaryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_BoundaryType = { "BoundaryType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestNode_Parms, BoundaryType), Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryType, METADATA_PARAMS(0, nullptr) }; // 1887518426
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_IsTriggering_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestNode_Parms*)Obj)->IsTriggering = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_IsTriggering = { "IsTriggering", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestNode_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_IsTriggering_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_ClosestDistance = { "ClosestDistance", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestNode_Parms, ClosestDistance), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_ClosestPoint = { "ClosestPoint", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestNode_Parms, ClosestPoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_ClosestPointNormal = { "ClosestPointNormal", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestNode_Parms, ClosestPointNormal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestNode_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestNode_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_DeviceType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_DeviceType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_BoundaryType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_BoundaryType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_IsTriggering,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_ClosestDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_ClosestPoint,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_ClosestPointNormal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Checks whether a tracked device (Left hand, Right hand, Head) will trigger the boundary.</summary>\n/// <param name =\"DeviceType\">(In) Enum, the type of the tracked device:\n/// <ul>\n/// <li>`LeftHand`: Left hand</li>\n/// <li>`RightHand`: Right hand</li>\n/// <li>`Head`: Headset</li>\n/// </ul>\n/// </param>\n/// <param name =\"BoundaryType\">(In) Enum, boundary type:\n/// <ul>\n/// <li>`Outer`: boundary (i.e., the on-site quick setting boundary or the customized boundary)</li>\n/// <li>`PlayArea`: the biggest internal rectangle of the customized boundary\xef\xbc\x88no such a bounary for on-site quick setting boundary\xef\xbc\x89</li>\n/// </ul>\n/// </param>\n/// <param name =\"IsTriggering\">(Out) bool, whether the boundary is triggered </param>\n/// <param name =\"ClosestDistance\">(Out) float, the minimum distance between the tracked node and the boundary </param>\n/// <param name =\"ClosestPoint\">(Out) FVector, the coordinate of the closest point between the tracked device and the specified boundary </param>\n/// <param name =\"ClosestPointNormal\">(Out) FVector, the normal line of the closest point of tracked device to the specified boundary </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: result got</li>\n/// <li>`false`: failed to get the result</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Checks whether a tracked device (Left hand, Right hand, Head) will trigger the boundary.</summary>\n<param name =\"DeviceType\">(In) Enum, the type of the tracked device:\n<ul>\n<li>`LeftHand`: Left hand</li>\n<li>`RightHand`: Right hand</li>\n<li>`Head`: Headset</li>\n</ul>\n</param>\n<param name =\"BoundaryType\">(In) Enum, boundary type:\n<ul>\n<li>`Outer`: boundary (i.e., the on-site quick setting boundary or the customized boundary)</li>\n<li>`PlayArea`: the biggest internal rectangle of the customized boundary\xef\xbc\x88no such a bounary for on-site quick setting boundary\xef\xbc\x89</li>\n</ul>\n</param>\n<param name =\"IsTriggering\">(Out) bool, whether the boundary is triggered </param>\n<param name =\"ClosestDistance\">(Out) float, the minimum distance between the tracked node and the boundary </param>\n<param name =\"ClosestPoint\">(Out) FVector, the coordinate of the closest point between the tracked device and the specified boundary </param>\n<param name =\"ClosestPointNormal\">(Out) FVector, the normal line of the closest point of tracked device to the specified boundary </param>\n<returns>Bool:\n<ul>\n<li>`true`: result got</li>\n<li>`false`: failed to get the result</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_BoundaryTestNode", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestNode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestNode_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestPoint_Parms
		{
			FVector Point;
			EPICOXRBoundaryType BoundaryType;
			bool IsTriggering;
			float ClosestDistance;
			FVector ClosestPoint;
			FVector ClosestPointNormal;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Point;
		static const UECodeGen_Private::FBytePropertyParams NewProp_BoundaryType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_BoundaryType;
		static void NewProp_IsTriggering_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsTriggering;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ClosestDistance;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ClosestPoint;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ClosestPointNormal;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_Point = { "Point", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestPoint_Parms, Point), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_BoundaryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_BoundaryType = { "BoundaryType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestPoint_Parms, BoundaryType), Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryType, METADATA_PARAMS(0, nullptr) }; // 1887518426
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_IsTriggering_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestPoint_Parms*)Obj)->IsTriggering = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_IsTriggering = { "IsTriggering", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestPoint_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_IsTriggering_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_ClosestDistance = { "ClosestDistance", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestPoint_Parms, ClosestDistance), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_ClosestPoint = { "ClosestPoint", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestPoint_Parms, ClosestPoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_ClosestPointNormal = { "ClosestPointNormal", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestPoint_Parms, ClosestPointNormal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestPoint_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestPoint_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_Point,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_BoundaryType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_BoundaryType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_IsTriggering,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_ClosestDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_ClosestPoint,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_ClosestPointNormal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Checks whether a tracked point in the Unreal coordinate system will trigger the boundary.</summary>\n/// <param name =\"Point\">(In) FVector, the tracked point, (x,y,z) </param>\n/// <param name =\"BoundaryType\">(In) Enum, boundary type:\n/// <ul>\n/// <li>`Outer`: boundary (i.e., the on-site quick setting boundary or the customized boundary)</li>\n/// <li>`PlayArea`: the biggest internal rectangle of the customized boundary\xef\xbc\x88no such a bounary for on-site quick setting boundary\xef\xbc\x89</li>\n/// </ul>\n/// </param>\n/// <param name =\"IsTriggering\">(Out) bool, whether the boundary is triggered </param>\n/// <param name =\"ClosestDistance\">(Out) float, the minimum distance between the tracked node and the boundary </param>\n/// <param name =\"ClosestPoint\">(Out) FVector, the coordinate of the closest point between the tracked device and the specified boundary </param>\n/// <param name =\"ClosestPointNormal\">(Out) FVector, the normal line of the closest point of tracked device to the specified boundary </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: result got</li>\n/// <li>`false`: failed to get the result</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Checks whether a tracked point in the Unreal coordinate system will trigger the boundary.</summary>\n<param name =\"Point\">(In) FVector, the tracked point, (x,y,z) </param>\n<param name =\"BoundaryType\">(In) Enum, boundary type:\n<ul>\n<li>`Outer`: boundary (i.e., the on-site quick setting boundary or the customized boundary)</li>\n<li>`PlayArea`: the biggest internal rectangle of the customized boundary\xef\xbc\x88no such a bounary for on-site quick setting boundary\xef\xbc\x89</li>\n</ul>\n</param>\n<param name =\"IsTriggering\">(Out) bool, whether the boundary is triggered </param>\n<param name =\"ClosestDistance\">(Out) float, the minimum distance between the tracked node and the boundary </param>\n<param name =\"ClosestPoint\">(Out) FVector, the coordinate of the closest point between the tracked device and the specified boundary </param>\n<param name =\"ClosestPointNormal\">(Out) FVector, the normal line of the closest point of tracked device to the specified boundary </param>\n<returns>Bool:\n<ul>\n<li>`true`: result got</li>\n<li>`false`: failed to get the result</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_BoundaryTestPoint", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestPoint_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::PICOXRHMDFunctionLibrary_eventPXR_BoundaryTestPoint_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_DoesSupportPositionalTracking_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_DoesSupportPositionalTracking_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_DoesSupportPositionalTracking_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Checks if the HMD supports positional tracking.</summary>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: support positional tracking (6DOF mode enabled)</li>\n/// <li>`false`: not support positional tracking (3DOF mode enabled)</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Checks if the HMD supports positional tracking.</summary>\n<returns>Bool:\n<ul>\n<li>`true`: support positional tracking (6DOF mode enabled)</li>\n<li>`false`: not support positional tracking (3DOF mode enabled)</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_DoesSupportPositionalTracking", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::PICOXRHMDFunctionLibrary_eventPXR_DoesSupportPositionalTracking_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::PICOXRHMDFunctionLibrary_eventPXR_DoesSupportPositionalTracking_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAcceleration_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetAcceleration_Parms
		{
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAcceleration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetAcceleration_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAcceleration_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAcceleration_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAcceleration_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief Gets the acceleration data of the headset.\n/// @return A FVector representing the acceleration of the headset.\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Gets the acceleration data of the headset.\n@return A FVector representing the acceleration of the headset." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAcceleration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetAcceleration", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAcceleration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAcceleration_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAcceleration_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetAcceleration_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAcceleration_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAcceleration_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAcceleration_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAcceleration_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetAcceleration_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAcceleration()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAcceleration_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetAngularAcceleration_Parms
		{
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetAngularAcceleration_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief Gets the angular acceleration data of the headset.\n/// @return A FVector representing the angular acceleration of the headset.\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Gets the angular acceleration data of the headset.\n@return A FVector representing the angular acceleration of the headset." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetAngularAcceleration", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetAngularAcceleration_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetAngularAcceleration_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularAcceleration()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetAngularVelocity_Parms
		{
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetAngularVelocity_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief Gets the angular velocity of the headset.\n/// @return A FVector representing the angular velocity of the headset.\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Gets the angular velocity of the headset.\n@return A FVector representing the angular velocity of the headset." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetAngularVelocity", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetAngularVelocity_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetAngularVelocity_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularVelocity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBaseRotationAndBaseOffsetInMeters_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetBaseRotationAndBaseOffsetInMeters_Parms
		{
			FRotator OutRotation;
			FVector OutBaseOffsetInMeters;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutRotation;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutBaseOffsetInMeters;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBaseRotationAndBaseOffsetInMeters_Statics::NewProp_OutRotation = { "OutRotation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetBaseRotationAndBaseOffsetInMeters_Parms, OutRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBaseRotationAndBaseOffsetInMeters_Statics::NewProp_OutBaseOffsetInMeters = { "OutBaseOffsetInMeters", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetBaseRotationAndBaseOffsetInMeters_Parms, OutBaseOffsetInMeters), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBaseRotationAndBaseOffsetInMeters_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBaseRotationAndBaseOffsetInMeters_Statics::NewProp_OutRotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBaseRotationAndBaseOffsetInMeters_Statics::NewProp_OutBaseOffsetInMeters,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBaseRotationAndBaseOffsetInMeters_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBaseRotationAndBaseOffsetInMeters_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetBaseRotationAndBaseOffsetInMeters", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBaseRotationAndBaseOffsetInMeters_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBaseRotationAndBaseOffsetInMeters_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBaseRotationAndBaseOffsetInMeters_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetBaseRotationAndBaseOffsetInMeters_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBaseRotationAndBaseOffsetInMeters_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBaseRotationAndBaseOffsetInMeters_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBaseRotationAndBaseOffsetInMeters_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBaseRotationAndBaseOffsetInMeters_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetBaseRotationAndBaseOffsetInMeters_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBaseRotationAndBaseOffsetInMeters()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBaseRotationAndBaseOffsetInMeters_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryConfigured_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryConfigured_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryConfigured_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary> Gets whether there is a valid boundary configured in the system. </summary>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true` - yes</li>\n/// <li>`false` - no</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary> Gets whether there is a valid boundary configured in the system. </summary>\n<returns>Bool:\n<ul>\n<li>`true` - yes</li>\n<li>`false` - no</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetBoundaryConfigured", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryConfigured_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryConfigured_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryConfigured()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryDimensions_Parms
		{
			EPICOXRBoundaryType BoundaryType;
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_BoundaryType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_BoundaryType;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::NewProp_BoundaryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::NewProp_BoundaryType = { "BoundaryType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryDimensions_Parms, BoundaryType), Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryType, METADATA_PARAMS(0, nullptr) }; // 1887518426
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryDimensions_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::NewProp_BoundaryType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::NewProp_BoundaryType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Returns the dimensions in UE world space of the requested Boundary Type.\n\x09* @param BoundaryType\x09\x09\x09(in) An enum representing the boundary type requested, either Outer Boundary (exact Boundary bounds) or PlayArea (rectangle inside the Outer Boundary)\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the dimensions in UE world space of the requested Boundary Type.\n@param BoundaryType                   (in) An enum representing the boundary type requested, either Outer Boundary (exact Boundary bounds) or PlayArea (rectangle inside the Outer Boundary)" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetBoundaryDimensions", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryDimensions_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryDimensions_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryDimensions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryEnabled_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryEnabled_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryEnabled_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets whether the boundary is enabled.</summary>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true` - enabled</li>\n/// <li>`false` - disabled</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets whether the boundary is enabled.</summary>\n<returns>Bool:\n<ul>\n<li>`true` - enabled</li>\n<li>`false` - disabled</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetBoundaryEnabled", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryEnabled_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryEnabled_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryEnabled()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryGeometry_Parms
		{
			EPICOXRBoundaryType BoundaryType;
			TArray<FVector> ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_BoundaryType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_BoundaryType;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::NewProp_BoundaryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::NewProp_BoundaryType = { "BoundaryType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryGeometry_Parms, BoundaryType), Z_Construct_UEnum_PICOXRHMD_EPICOXRBoundaryType, METADATA_PARAMS(0, nullptr) }; // 1887518426
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryGeometry_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::NewProp_BoundaryType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::NewProp_BoundaryType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets an array of boundary coordinates.</summary>\n/// <param name =\"BoundaryType\">(In) Enum, boundary type:\n/// <ul>\n/// <li>`Outer`: boundary (i.e., the on-site quick setting boundary or the customized boundary)</li>\n/// <li>`PlayArea`: the biggest internal rectangle of the customized boundary\xef\xbc\x88no such a bounary for on-site quick setting boundary\xef\xbc\x89</li>\n/// </ul>\n/// </param>\n/// <returns>TArray, an array of boundary coordinates. </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets an array of boundary coordinates.</summary>\n<param name =\"BoundaryType\">(In) Enum, boundary type:\n<ul>\n<li>`Outer`: boundary (i.e., the on-site quick setting boundary or the customized boundary)</li>\n<li>`PlayArea`: the biggest internal rectangle of the customized boundary\xef\xbc\x88no such a bounary for on-site quick setting boundary\xef\xbc\x89</li>\n</ul>\n</param>\n<returns>TArray, an array of boundary coordinates. </returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetBoundaryGeometry", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryGeometry_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryGeometry_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryGeometry()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryVisible_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryVisible_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryVisible_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets whether the boundary is set as visible or invisible.</summary>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: visible</li>\n/// <li>`false`: invisible</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets whether the boundary is set as visible or invisible.</summary>\n<returns>Bool:\n<ul>\n<li>`true`: visible</li>\n<li>`false`: invisible</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetBoundaryVisible", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryVisible_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetBoundaryVisible_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryVisible()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetCPUAndGPULevels_Parms
		{
			int32 CPULevel;
			int32 GPULevel;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_CPULevel;
		static const UECodeGen_Private::FIntPropertyParams NewProp_GPULevel;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::NewProp_CPULevel = { "CPULevel", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetCPUAndGPULevels_Parms, CPULevel), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::NewProp_GPULevel = { "GPULevel", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetCPUAndGPULevels_Parms, GPULevel), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::NewProp_CPULevel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::NewProp_GPULevel,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the clock frequency level for CPU and GPU.\n/// @note When the level is set to `1`: the CPU or GPU runs at the slowest clock frequency (most battery-saving).\n/// </summary>\n/// <param name =\"CPULevel\">(Out) Int, CPU clock frequency level, value range: [1, 5]. </param>\n/// <param name =\"GPULevel\">(Out) Int, CPU clock frequency level, value range: [1, 5]. </param>\n/// <returns>None </returns>\n" },
#endif
		{ "DeprecatedFunction", "" },
		{ "DeprecatedMessage", "Deprecated. Please use Get/PXR_GetPerformanceLevel instead" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the clock frequency level for CPU and GPU.\n@note When the level is set to `1`: the CPU or GPU runs at the slowest clock frequency (most battery-saving).\n</summary>\n<param name =\"CPULevel\">(Out) Int, CPU clock frequency level, value range: [1, 5]. </param>\n<param name =\"GPULevel\">(Out) Int, CPU clock frequency level, value range: [1, 5]. </param>\n<returns>None </returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetCPUAndGPULevels", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetCPUAndGPULevels_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetCPUAndGPULevels_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetCurrentDisplayFrequency_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetCurrentDisplayFrequency_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the current display refresh rate.</summary>\n/// <returns>Float\n/// <ul>\n/// <li>`0`: failed to get display refresh rate </li>\n/// <li>`72`: 72Hz</li>\n/// <li>`90`: 90Hz</li>\n/// <li>`120`: 120Hz</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the current display refresh rate.</summary>\n<returns>Float\n<ul>\n<li>`0`: failed to get display refresh rate </li>\n<li>`72`: 72Hz</li>\n<li>`90`: 90Hz</li>\n<li>`120`: 120Hz</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetCurrentDisplayFrequency", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetCurrentDisplayFrequency_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetCurrentDisplayFrequency_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetCurrentOrientation_Parms
		{
			FQuat ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetCurrentOrientation_Parms, ReturnValue), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the current orientation of the HMD.</summary>\n/// <returns> Quat, the current orientation of the HMD. </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the current orientation of the HMD.</summary>\n<returns> Quat, the current orientation of the HMD. </returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetCurrentOrientation", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetCurrentOrientation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetCurrentOrientation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentOrientation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetCurrentPosition_Parms
		{
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetCurrentPosition_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the current position of the HMD.</summary>\n/// <returns> Quat, the current position of the HMD. </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the current position of the HMD.</summary>\n<returns> Quat, the current position of the HMD. </returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetCurrentPosition", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetCurrentPosition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetCurrentPosition_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetDeviceModel_Parms
		{
			FString ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetDeviceModel_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the device model's series number.</summary>\n/// <returns> FString, the current device model's series number. </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the device model's series number.</summary>\n<returns> FString, the current device model's series number. </returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetDeviceModel", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetDeviceModel_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetDeviceModel_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceModel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceName_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetDeviceName_Parms
		{
			FString ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetDeviceName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceName_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets the Device Name.\n/// </summary>\n/// <returns> FString. The device name,such as PICO 4. </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets the Device Name.\n</summary>\n<returns> FString. The device name,such as PICO 4. </returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetDeviceName", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceName_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetDeviceName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceName_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetDeviceName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetDisplayFrequenciesAvailable_Parms
		{
			int32 Count;
			TArray<float> AvailableRates;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Count;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AvailableRates_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_AvailableRates;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::NewProp_Count = { "Count", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetDisplayFrequenciesAvailable_Parms, Count), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::NewProp_AvailableRates_Inner = { "AvailableRates", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::NewProp_AvailableRates = { "AvailableRates", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetDisplayFrequenciesAvailable_Parms, AvailableRates), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_GetDisplayFrequenciesAvailable_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_GetDisplayFrequenciesAvailable_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::NewProp_Count,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::NewProp_AvailableRates_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::NewProp_AvailableRates,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Get display frequencies available.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get display frequencies available." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetDisplayFrequenciesAvailable", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetDisplayFrequenciesAvailable_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetDisplayFrequenciesAvailable_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetEventManager_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetEventManager_Parms
		{
			UPICOXREventManager* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetEventManager_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetEventManager_Parms, ReturnValue), Z_Construct_UClass_UPICOXREventManager_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetEventManager_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetEventManager_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetEventManager_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the current callback event manager, which can be used to bind callback events for delegates.\n/// @note Currently available callback events for binding:\n/// </summary>\n/// <ul>\n/// <li>Device Connect Changed Delegate </li>\n/// <li>Ipd Changed Delegate </li>\n/// <li>Long Home Pressed Delegate</li>\n/// <li>Refresh Rate Changed Delegate</li>\n/// <li>Resume Delegate</li>\n/// </ul>\n/// <returns>UPICOXREventManager class reference. </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the current callback event manager, which can be used to bind callback events for delegates.\n@note Currently available callback events for binding:\n</summary>\n<ul>\n<li>Device Connect Changed Delegate </li>\n<li>Ipd Changed Delegate </li>\n<li>Long Home Pressed Delegate</li>\n<li>Refresh Rate Changed Delegate</li>\n<li>Resume Delegate</li>\n</ul>\n<returns>UPICOXREventManager class reference. </returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetEventManager_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetEventManager", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetEventManager_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetEventManager_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetEventManager_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetEventManager_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetEventManager_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetEventManager_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetEventManager_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetEventManager_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetEventManager_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetEventManager()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetEventManager_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetFieldOfView_Parms
		{
			float HFOVInDegrees;
			float VFOVInDegrees;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_HFOVInDegrees;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_VFOVInDegrees;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::NewProp_HFOVInDegrees = { "HFOVInDegrees", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetFieldOfView_Parms, HFOVInDegrees), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::NewProp_VFOVInDegrees = { "VFOVInDegrees", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetFieldOfView_Parms, VFOVInDegrees), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_GetFieldOfView_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_GetFieldOfView_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::NewProp_HFOVInDegrees,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::NewProp_VFOVInDegrees,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the horizontal and vertical FOV of the HMD.</summary>\n/// <param name =\"HFOVInDegrees\">(Out) Float, the horizontal FOV (in degrees). </param>\n/// <param name =\"VFOVInDegrees\">(Out) Float, the vertical FOV (in degrees). </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the horizontal and vertical FOV of the HMD.</summary>\n<param name =\"HFOVInDegrees\">(Out) Float, the horizontal FOV (in degrees). </param>\n<param name =\"VFOVInDegrees\">(Out) Float, the vertical FOV (in degrees). </param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetFieldOfView", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetFieldOfView_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetFieldOfView_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFieldOfView()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetFoveationLevel_Parms
		{
			EPICOXRFoveationLevel Level;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_Level_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Level;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::NewProp_Level_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetFoveationLevel_Parms, Level), Z_Construct_UEnum_PICOXRHMD_EPICOXRFoveationLevel, METADATA_PARAMS(0, nullptr) }; // 2259085603
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_GetFoveationLevel_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_GetFoveationLevel_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::NewProp_Level_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::NewProp_Level,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the current foveated rendering level.</summary>\n/// <param name=\"Level\">(Out) Enum, the current foveated rendering level:\n/// <ul>\n/// <li>`None`</li>\n/// <li>`Low`</li>\n/// <li>`Medium`</li>\n/// <li>`High`</li>\n/// <li>`TopHigh`</li>\n/// </ul>\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true` - success</li>\n/// <li>`false` - failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "DisplayName", "PXR Get Foveated Rendering Level" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the current foveated rendering level.</summary>\n<param name=\"Level\">(Out) Enum, the current foveated rendering level:\n<ul>\n<li>`None`</li>\n<li>`Low`</li>\n<li>`Medium`</li>\n<li>`High`</li>\n<li>`TopHigh`</li>\n</ul>\n</param>\n<returns>Bool:\n<ul>\n<li>`true` - success</li>\n<li>`false` - failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetFoveationLevel", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetFoveationLevel_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetFoveationLevel_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFoveationLevel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHFov_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetHFov_Parms
		{
			float HFOVInDegrees;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_HFOVInDegrees;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHFov_Statics::NewProp_HFOVInDegrees = { "HFOVInDegrees", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetHFov_Parms, HFOVInDegrees), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHFov_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHFov_Statics::NewProp_HFOVInDegrees,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHFov_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Get device horizontal Fov.\n\x09* @param HFOVInDegrees    (out) Horizontal FOV.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get device horizontal Fov.\n@param HFOVInDegrees    (out) Horizontal FOV." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHFov_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetHFov", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHFov_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHFov_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHFov_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetHFov_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHFov_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHFov_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHFov_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHFov_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetHFov_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHFov()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHFov_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHmdBatteryLevel_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetHmdBatteryLevel_Parms
		{
			int32 Battery;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Battery;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHmdBatteryLevel_Statics::NewProp_Battery = { "Battery", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetHmdBatteryLevel_Parms, Battery), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHmdBatteryLevel_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_GetHmdBatteryLevel_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHmdBatteryLevel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_GetHmdBatteryLevel_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHmdBatteryLevel_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHmdBatteryLevel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHmdBatteryLevel_Statics::NewProp_Battery,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHmdBatteryLevel_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHmdBatteryLevel_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the percentage of power remaining in the HMD.</summary>\n/// <param name=\"Battery\">(Out) Int, the percentage of power, value range: [0, 100]</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true` - success</li>\n/// <li>`false` - failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the percentage of power remaining in the HMD.</summary>\n<param name=\"Battery\">(Out) Int, the percentage of power, value range: [0, 100]</param>\n<returns>Bool:\n<ul>\n<li>`true` - success</li>\n<li>`false` - failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHmdBatteryLevel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetHmdBatteryLevel", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHmdBatteryLevel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHmdBatteryLevel_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHmdBatteryLevel_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetHmdBatteryLevel_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHmdBatteryLevel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHmdBatteryLevel_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHmdBatteryLevel_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHmdBatteryLevel_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetHmdBatteryLevel_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHmdBatteryLevel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHmdBatteryLevel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetHMDWornState_Parms
		{
			TEnumAsByte<EHMDWornState::Type> ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetHMDWornState_Parms, ReturnValue), Z_Construct_UEnum_HeadMountedDisplay_EHMDWornState, METADATA_PARAMS(0, nullptr) }; // 3118659323
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Detect whether the user is wearing the HMD.</summary>\n/// <returns>\n/// <ul>\n/// <li>EHMDWornState::Worn if we detect that the user is wearing the HMD</li>\n/// <li>EHMDWornState::NotWorn if we detect the user is not wearing the HMD</li>\n/// <li>EEHMDWornState::Unknown if we cannot detect the state.</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Detect whether the user is wearing the HMD.</summary>\n<returns>\n<ul>\n<li>EHMDWornState::Worn if we detect that the user is wearing the HMD</li>\n<li>EHMDWornState::NotWorn if we detect the user is not wearing the HMD</li>\n<li>EEHMDWornState::Unknown if we cannot detect the state.</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetHMDWornState", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetHMDWornState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetHMDWornState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHMDWornState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetIPD_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetIPD_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetIPD_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetIPD_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetIPD_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetIPD_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetIPD_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the interpupillary distance (IPD) of the current device.</summary>\n/// <returns>Float, the IPD of the current device. </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the interpupillary distance (IPD) of the current device.</summary>\n<returns>Float, the IPD of the current device. </returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetIPD_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetIPD", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetIPD_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetIPD_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetIPD_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetIPD_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetIPD_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetIPD_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetIPD_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetIPD_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetIPD_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetIPD()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetIPD_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetPerformanceLevel_Parms
		{
			EPerformanceSettingTypes SettingType;
			EPerfSettingsLevel Level;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_SettingType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_SettingType;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Level_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Level;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics::NewProp_SettingType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics::NewProp_SettingType = { "SettingType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetPerformanceLevel_Parms, SettingType), Z_Construct_UEnum_PICOXRHMD_EPerformanceSettingTypes, METADATA_PARAMS(0, nullptr) }; // 2697330501
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics::NewProp_Level_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetPerformanceLevel_Parms, Level), Z_Construct_UEnum_PICOXRHMD_EPerfSettingsLevel, METADATA_PARAMS(0, nullptr) }; // 3917667178
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_GetPerformanceLevel_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_GetPerformanceLevel_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics::NewProp_SettingType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics::NewProp_SettingType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics::NewProp_Level_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics::NewProp_Level,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the device's GPU or CPU level.</summary>\n/// <param name =\"SettingType\">(In) Enum, choose to set a GPU or CPU level:\n/// <ul>\n/// <li>`CPULevel`</li>\n/// <li>`GPULevel`</li>\n/// </ul>\n/// </param>\n/// <param name =\"Level\">(Out) Enum, select a level from the following:\n/// <ul>\n/// <li>`PowerSaving`: power-saving level</li>\n/// <li>`SustainedLow`: low level</li>\n/// <li>`SustainedHigh`: high level</li>\n/// <li>`Boost(*)`: top-high level, be careful to use this level</li>\n/// </ul>\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the device's GPU or CPU level.</summary>\n<param name =\"SettingType\">(In) Enum, choose to set a GPU or CPU level:\n<ul>\n<li>`CPULevel`</li>\n<li>`GPULevel`</li>\n</ul>\n</param>\n<param name =\"Level\">(Out) Enum, select a level from the following:\n<ul>\n<li>`PowerSaving`: power-saving level</li>\n<li>`SustainedLow`: low level</li>\n<li>`SustainedHigh`: high level</li>\n<li>`Boost(*)`: top-high level, be careful to use this level</li>\n</ul>\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetPerformanceLevel", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetPerformanceLevel_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetPerformanceLevel_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedDisplayTime_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetPredictedDisplayTime_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedDisplayTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetPredictedDisplayTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedDisplayTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedDisplayTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedDisplayTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets the predicted display time of a frame, including the see-through camera image.\n/// </summary>\n/// <returns> Float. The predicted time (in miliseconds). </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets the predicted display time of a frame, including the see-through camera image.\n</summary>\n<returns> Float. The predicted time (in miliseconds). </returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedDisplayTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetPredictedDisplayTime", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedDisplayTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedDisplayTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedDisplayTime_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetPredictedDisplayTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedDisplayTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedDisplayTime_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedDisplayTime_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedDisplayTime_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetPredictedDisplayTime_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedDisplayTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedDisplayTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetPredictedMainSensorState_Parms
		{
			FPxrSensorState sensorState;
			int32 sensorFrameIndex;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_sensorState;
		static const UECodeGen_Private::FIntPropertyParams NewProp_sensorFrameIndex;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::NewProp_sensorState = { "sensorState", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetPredictedMainSensorState_Parms, sensorState), Z_Construct_UScriptStruct_FPxrSensorState, METADATA_PARAMS(0, nullptr) }; // 2579487364
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::NewProp_sensorFrameIndex = { "sensorFrameIndex", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetPredictedMainSensorState_Parms, sensorFrameIndex), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::NewProp_sensorState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::NewProp_sensorFrameIndex,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets the predicted state of the main sensor of the HMD.\n/// </summary>\n/// <param name=\"sensorState\">(Out) The predicted sensor state as an FPxrSensorState structure.</param>\n/// <param name=\"sensorFrameIndex\">(Out) The frame index associated with the sensor state.</param>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets the predicted state of the main sensor of the HMD.\n</summary>\n<param name=\"sensorState\">(Out) The predicted sensor state as an FPxrSensorState structure.</param>\n<param name=\"sensorFrameIndex\">(Out) The frame index associated with the sensor state.</param>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetPredictedMainSensorState", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetPredictedMainSensorState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetPredictedMainSensorState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetSystemDisplayFrequency_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetSystemDisplayFrequency_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Gets the system display frequency rate.\n\x09* @return The system display frequency rate.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gets the system display frequency rate.\n@return The system display frequency rate." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetSystemDisplayFrequency", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetSystemDisplayFrequency_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetSystemDisplayFrequency_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetToDeltaSensorY_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetToDeltaSensorY_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetToDeltaSensorY_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetToDeltaSensorY_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetToDeltaSensorY_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetToDeltaSensorY_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetToDeltaSensorY_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetToDeltaSensorY_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetToDeltaSensorY", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetToDeltaSensorY_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetToDeltaSensorY_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetToDeltaSensorY_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetToDeltaSensorY_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetToDeltaSensorY_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetToDeltaSensorY_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetToDeltaSensorY_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetToDeltaSensorY_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetToDeltaSensorY_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetToDeltaSensorY()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetToDeltaSensorY_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVelocity_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetVelocity_Parms
		{
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVelocity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetVelocity_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVelocity_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVelocity_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVelocity_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief Gets the velocity data of the headset.\n/// @return A FVector representing the velocity of the headset.\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Gets the velocity data of the headset.\n@return A FVector representing the velocity of the headset." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVelocity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetVelocity", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVelocity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVelocity_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVelocity_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetVelocity_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVelocity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVelocity_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVelocity_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVelocity_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetVelocity_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVelocity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVelocity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVFov_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_GetVFov_Parms
		{
			float VFOVInDegrees;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_VFOVInDegrees;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVFov_Statics::NewProp_VFOVInDegrees = { "VFOVInDegrees", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_GetVFov_Parms, VFOVInDegrees), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVFov_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVFov_Statics::NewProp_VFOVInDegrees,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVFov_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Get device vertical Fov.\n\x09* @param VFOVInDegrees    (out) Vertical FOV.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get device vertical Fov.\n@param VFOVInDegrees    (out) Vertical FOV." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVFov_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_GetVFov", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVFov_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVFov_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVFov_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetVFov_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVFov_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVFov_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVFov_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVFov_Statics::PICOXRHMDFunctionLibrary_eventPXR_GetVFov_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVFov()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVFov_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_IPDChangedDelegates_Parms
		{
			FScriptDelegate OnPICOXRIPDChanged;
		};
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnPICOXRIPDChanged;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics::NewProp_OnPICOXRIPDChanged = { "OnPICOXRIPDChanged", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_IPDChangedDelegates_Parms, OnPICOXRIPDChanged), Z_Construct_UDelegateFunction_PICOXRHMD_PICOXRIPDChangedDelegate__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1290877852
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics::NewProp_OnPICOXRIPDChanged,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the new interpupillary distance (IPD) through binding the callback event.</summary>\n/// <param name =\"OnPICOXRIPDChanged\">(In) Delegate, bind the callback event to get the new IPD. The callback parameter is a float-type value Ipd that indicates the current IPD. </param>\n/// <returns>None </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the new interpupillary distance (IPD) through binding the callback event.</summary>\n<param name =\"OnPICOXRIPDChanged\">(In) Delegate, bind the callback event to get the new IPD. The callback parameter is a float-type value Ipd that indicates the current IPD. </param>\n<returns>None </returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_IPDChangedDelegates", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics::PICOXRHMDFunctionLibrary_eventPXR_IPDChangedDelegates_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics::PICOXRHMDFunctionLibrary_eventPXR_IPDChangedDelegates_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_IPDChangedDelegates()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_QueryDeviceAbilities_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_QueryDeviceAbilities_Parms
		{
			EPICOXRDeviceAbilities DeviceAbility;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceAbility_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceAbility;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_QueryDeviceAbilities_Statics::NewProp_DeviceAbility_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_QueryDeviceAbilities_Statics::NewProp_DeviceAbility = { "DeviceAbility", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_QueryDeviceAbilities_Parms, DeviceAbility), Z_Construct_UEnum_PICOXRHMD_EPICOXRDeviceAbilities, METADATA_PARAMS(0, nullptr) }; // 3507183998
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_QueryDeviceAbilities_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_QueryDeviceAbilities_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_QueryDeviceAbilities_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_QueryDeviceAbilities_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_QueryDeviceAbilities_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_QueryDeviceAbilities_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_QueryDeviceAbilities_Statics::NewProp_DeviceAbility_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_QueryDeviceAbilities_Statics::NewProp_DeviceAbility,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_QueryDeviceAbilities_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_QueryDeviceAbilities_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Query Abilities of Device.\n\x09* @param DeviceAbility     (int) Device Ability Type\n\x09* @return bool  The execution result.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Query Abilities of Device.\n@param DeviceAbility     (int) Device Ability Type\n@return bool  The execution result." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_QueryDeviceAbilities_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_QueryDeviceAbilities", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_QueryDeviceAbilities_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_QueryDeviceAbilities_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_QueryDeviceAbilities_Statics::PICOXRHMDFunctionLibrary_eventPXR_QueryDeviceAbilities_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_QueryDeviceAbilities_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_QueryDeviceAbilities_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_QueryDeviceAbilities_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_QueryDeviceAbilities_Statics::PICOXRHMDFunctionLibrary_eventPXR_QueryDeviceAbilities_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_QueryDeviceAbilities()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_QueryDeviceAbilities_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_ResetHMDSensor_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_ResetHMDSensor_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_ResetHMDSensor_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Reset HMD Position and Orientation.\n\x09* @return true: reset HMD sensor Succeed, false :reset HMD sensor Failed.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reset HMD Position and Orientation.\n@return true: reset HMD sensor Succeed, false :reset HMD sensor Failed." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_ResetHMDSensor", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::PICOXRHMDFunctionLibrary_eventPXR_ResetHMDSensor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::PICOXRHMDFunctionLibrary_eventPXR_ResetHMDSensor_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_ResetHMDSensor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_SelectCoordinateSpace_Parms
		{
			EPICOXRCoordinateType CoordinateType;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_CoordinateType_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CoordinateType_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_CoordinateType;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace_Statics::NewProp_CoordinateType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace_Statics::NewProp_CoordinateType_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace_Statics::NewProp_CoordinateType = { "CoordinateType", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SelectCoordinateSpace_Parms, CoordinateType), Z_Construct_UEnum_PICOXRHMD_EPICOXRCoordinateType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace_Statics::NewProp_CoordinateType_MetaData), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace_Statics::NewProp_CoordinateType_MetaData) }; // 2250041083
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_SelectCoordinateSpace_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_SelectCoordinateSpace_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace_Statics::NewProp_CoordinateType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace_Statics::NewProp_CoordinateType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Select Coordinate.\n\x09* @param CoordinateType Coordinate Space  \n\x09* @return bool  The execution result.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Select Coordinate.\n@param CoordinateType Coordinate Space\n@return bool  The execution result." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_SelectCoordinateSpace", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace_Statics::PICOXRHMDFunctionLibrary_eventPXR_SelectCoordinateSpace_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace_Statics::PICOXRHMDFunctionLibrary_eventPXR_SelectCoordinateSpace_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBaseRotationAndBaseOffsetInMeters_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_SetBaseRotationAndBaseOffsetInMeters_Parms
		{
			FRotator Rotation;
			FVector BaseOffsetInMeters;
			TEnumAsByte<EOrientPositionSelector::Type> Options;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
		static const UECodeGen_Private::FStructPropertyParams NewProp_BaseOffsetInMeters;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Options;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBaseRotationAndBaseOffsetInMeters_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetBaseRotationAndBaseOffsetInMeters_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBaseRotationAndBaseOffsetInMeters_Statics::NewProp_BaseOffsetInMeters = { "BaseOffsetInMeters", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetBaseRotationAndBaseOffsetInMeters_Parms, BaseOffsetInMeters), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBaseRotationAndBaseOffsetInMeters_Statics::NewProp_Options = { "Options", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetBaseRotationAndBaseOffsetInMeters_Parms, Options), Z_Construct_UEnum_HeadMountedDisplay_EOrientPositionSelector, METADATA_PARAMS(0, nullptr) }; // 176701829
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBaseRotationAndBaseOffsetInMeters_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBaseRotationAndBaseOffsetInMeters_Statics::NewProp_Rotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBaseRotationAndBaseOffsetInMeters_Statics::NewProp_BaseOffsetInMeters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBaseRotationAndBaseOffsetInMeters_Statics::NewProp_Options,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBaseRotationAndBaseOffsetInMeters_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBaseRotationAndBaseOffsetInMeters_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_SetBaseRotationAndBaseOffsetInMeters", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBaseRotationAndBaseOffsetInMeters_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBaseRotationAndBaseOffsetInMeters_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBaseRotationAndBaseOffsetInMeters_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetBaseRotationAndBaseOffsetInMeters_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBaseRotationAndBaseOffsetInMeters_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBaseRotationAndBaseOffsetInMeters_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBaseRotationAndBaseOffsetInMeters_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBaseRotationAndBaseOffsetInMeters_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetBaseRotationAndBaseOffsetInMeters_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBaseRotationAndBaseOffsetInMeters()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBaseRotationAndBaseOffsetInMeters_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_SetBoundaryVisible_Parms
		{
			bool NewVisible;
		};
		static void NewProp_NewVisible_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_NewVisible;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::NewProp_NewVisible_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_SetBoundaryVisible_Parms*)Obj)->NewVisible = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::NewProp_NewVisible = { "NewVisible", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_SetBoundaryVisible_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::NewProp_NewVisible_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::NewProp_NewVisible,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Sets the boundary as visible or invisible.\n/// @note If the application is paused, this function will cease. Therefore, you need to call this function again after the application has been resumed.\n/// </summary>\n/// <param name =\"NewVisible\">Bool, the visibility of the the boundary.\n/// <ul>\n/// <li>`true`: visible</li>\n/// <li>`false`: invisible</li>\n/// </ul>\n/// </param>\n/// <returns>None</returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Sets the boundary as visible or invisible.\n@note If the application is paused, this function will cease. Therefore, you need to call this function again after the application has been resumed.\n</summary>\n<param name =\"NewVisible\">Bool, the visibility of the the boundary.\n<ul>\n<li>`true`: visible</li>\n<li>`false`: invisible</li>\n</ul>\n</param>\n<returns>None</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_SetBoundaryVisible", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetBoundaryVisible_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetBoundaryVisible_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBoundaryVisible()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_SetColorScaleAndOffset_Parms
		{
			FLinearColor ColorScale;
			FLinearColor ColorOffset;
			bool bApplyToAllLayers;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ColorScale;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ColorOffset;
		static void NewProp_bApplyToAllLayers_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bApplyToAllLayers;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::NewProp_ColorScale = { "ColorScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetColorScaleAndOffset_Parms, ColorScale), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::NewProp_ColorOffset = { "ColorOffset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetColorScaleAndOffset_Parms, ColorOffset), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::NewProp_bApplyToAllLayers_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_SetColorScaleAndOffset_Parms*)Obj)->bApplyToAllLayers = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::NewProp_bApplyToAllLayers = { "bApplyToAllLayers", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_SetColorScaleAndOffset_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::NewProp_bApplyToAllLayers_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::NewProp_ColorScale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::NewProp_ColorOffset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::NewProp_bApplyToAllLayers,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Set eye buffer and overlay color space.\n\x09* @param ColorScale         (In) Color scale.\n\x09* @param ColorOffset        (In) Color offset.\n\x09* @param bApplyToAllLayers  (In) If apply to all Layers,default false.\n\x09*/" },
#endif
		{ "CPP_Default_bApplyToAllLayers", "false" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set eye buffer and overlay color space.\n@param ColorScale         (In) Color scale.\n@param ColorOffset        (In) Color offset.\n@param bApplyToAllLayers  (In) If apply to all Layers,default false." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_SetColorScaleAndOffset", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetColorScaleAndOffset_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetColorScaleAndOffset_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_SetCPUAndGPULevels_Parms
		{
			int32 CPULevel;
			int32 GPULevel;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_CPULevel;
		static const UECodeGen_Private::FIntPropertyParams NewProp_GPULevel;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::NewProp_CPULevel = { "CPULevel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetCPUAndGPULevels_Parms, CPULevel), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::NewProp_GPULevel = { "GPULevel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetCPUAndGPULevels_Parms, GPULevel), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::NewProp_CPULevel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::NewProp_GPULevel,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Sets the clock frequency level for CPU and GPU.\n/// @note When the level is set to `1`: the CPU or GPU runs at the slowest clock frequency (most battery-saving).\n/// </summary>\n/// <param name =\"CPULevel\">(In) Int, CPU clock frequency level, value range: [1, 5]. </param>\n/// <param name =\"GPULevel\">(In) Int, CPU clock frequency level, value range: [1, 5]. </param>\n/// <returns>None </returns>\n" },
#endif
		{ "DeprecatedFunction", "" },
		{ "DeprecatedMessage", "Deprecated. Please use Get/PXR_SetPerformanceLevel instead" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Sets the clock frequency level for CPU and GPU.\n@note When the level is set to `1`: the CPU or GPU runs at the slowest clock frequency (most battery-saving).\n</summary>\n<param name =\"CPULevel\">(In) Int, CPU clock frequency level, value range: [1, 5]. </param>\n<param name =\"GPULevel\">(In) Int, CPU clock frequency level, value range: [1, 5]. </param>\n<returns>None </returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_SetCPUAndGPULevels", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetCPUAndGPULevels_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetCPUAndGPULevels_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_SetExtraLatencyMode_Parms
		{
			int32 Mode;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Mode;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::NewProp_Mode = { "Mode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetExtraLatencyMode_Parms, Mode), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_SetExtraLatencyMode_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_SetExtraLatencyMode_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::NewProp_Mode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief Sets the extra latency mode. Note: Call this function once only.\n/// @param Mode The latency mode:\n/// - 0: ExtraLatencyModeOff (Disable ExtraLatencyMode mode. This option will display the latest rendered frame for display)\n/// - 1: ExtraLatencyModeOn (Enable ExtraLatencyMode mode. This option will display one frame prior to the latest rendered frame)\n/// - 2: ExtraLatencyModeDynamic (Use the system default setup)\n/// @return Whether the extra latency mode has been set:\n/// - true: success\n/// - false: failure\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Sets the extra latency mode. Note: Call this function once only.\n@param Mode The latency mode:\n- 0: ExtraLatencyModeOff (Disable ExtraLatencyMode mode. This option will display the latest rendered frame for display)\n- 1: ExtraLatencyModeOn (Enable ExtraLatencyMode mode. This option will display one frame prior to the latest rendered frame)\n- 2: ExtraLatencyModeDynamic (Use the system default setup)\n@return Whether the extra latency mode has been set:\n- true: success\n- false: failure" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_SetExtraLatencyMode", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetExtraLatencyMode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetExtraLatencyMode_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetExtraLatencyMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_SetFieldOfView_Parms
		{
			EPICOXREyeType Eye;
			float FovLeftInDegrees;
			float FovRightInDegrees;
			float FovUpInDegrees;
			float FovDownInDegrees;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_Eye_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Eye;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FovLeftInDegrees;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FovRightInDegrees;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FovUpInDegrees;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FovDownInDegrees;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::NewProp_Eye_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::NewProp_Eye = { "Eye", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetFieldOfView_Parms, Eye), Z_Construct_UEnum_PICOXRHMD_EPICOXREyeType, METADATA_PARAMS(0, nullptr) }; // 138979643
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::NewProp_FovLeftInDegrees = { "FovLeftInDegrees", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetFieldOfView_Parms, FovLeftInDegrees), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::NewProp_FovRightInDegrees = { "FovRightInDegrees", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetFieldOfView_Parms, FovRightInDegrees), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::NewProp_FovUpInDegrees = { "FovUpInDegrees", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetFieldOfView_Parms, FovUpInDegrees), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::NewProp_FovDownInDegrees = { "FovDownInDegrees", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetFieldOfView_Parms, FovDownInDegrees), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_SetFieldOfView_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_SetFieldOfView_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::NewProp_Eye_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::NewProp_Eye,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::NewProp_FovLeftInDegrees,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::NewProp_FovRightInDegrees,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::NewProp_FovUpInDegrees,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::NewProp_FovDownInDegrees,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Sets FOV in the four directions: left, right, up, and down for specified eye(s).</summary>\n/// <param name =\"Eye\">(In) Enum, the eye to set FOV for:\n/// <ul>\n/// <li>`LeftEye`\n/// <li>`RightEye`\n/// </ul>\n/// </param>\n/// <param name =\"FovLeftInDegrees\">(In) Float, the horizontal FOV (in degrees) for the left part of the eye, for example, `47.5` </param>\n/// <param name =\"FovRightInDegrees\">(In) Float, the horizontal FOV (in degrees) for the right part of the eye </param>\n/// <param name =\"FovUpInDegrees\">(In) Float, the vertical FOV (in degrees) for the upper part of the eye </param>\n/// <param name =\"FovDownInDegrees\">(In) Float, the vertical FOV (in degrees) for the lower part of the eye </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Sets FOV in the four directions: left, right, up, and down for specified eye(s).</summary>\n<param name =\"Eye\">(In) Enum, the eye to set FOV for:\n<ul>\n<li>`LeftEye`\n<li>`RightEye`\n</ul>\n</param>\n<param name =\"FovLeftInDegrees\">(In) Float, the horizontal FOV (in degrees) for the left part of the eye, for example, `47.5` </param>\n<param name =\"FovRightInDegrees\">(In) Float, the horizontal FOV (in degrees) for the right part of the eye </param>\n<param name =\"FovUpInDegrees\">(In) Float, the vertical FOV (in degrees) for the upper part of the eye </param>\n<param name =\"FovDownInDegrees\">(In) Float, the vertical FOV (in degrees) for the lower part of the eye </param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_SetFieldOfView", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetFieldOfView_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetFieldOfView_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveatedRenderingMode_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_SetFoveatedRenderingMode_Parms
		{
			EFoveationRenderingMode Mode;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_Mode_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Mode;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveatedRenderingMode_Statics::NewProp_Mode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveatedRenderingMode_Statics::NewProp_Mode = { "Mode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetFoveatedRenderingMode_Parms, Mode), Z_Construct_UEnum_PICOXRHMD_EFoveationRenderingMode, METADATA_PARAMS(0, nullptr) }; // 4128707893
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveatedRenderingMode_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_SetFoveatedRenderingMode_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveatedRenderingMode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_SetFoveatedRenderingMode_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveatedRenderingMode_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveatedRenderingMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveatedRenderingMode_Statics::NewProp_Mode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveatedRenderingMode_Statics::NewProp_Mode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveatedRenderingMode_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveatedRenderingMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Sets foveated rendering mode. </summary>\n/// <param name=\"Mode\">Foveated rendering mode:\n/// <ul>\n/// <li> `FixedFoveationRendering`: Fixed foveated rendering (FFR)\n/// <li> `EyeTrackingFoveationRendering`: Eye tracked foveated rendering (ETFR)\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true` - success</li>\n/// <li>`false` - failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Sets foveated rendering mode. </summary>\n<param name=\"Mode\">Foveated rendering mode:\n<ul>\n<li> `FixedFoveationRendering`: Fixed foveated rendering (FFR)\n<li> `EyeTrackingFoveationRendering`: Eye tracked foveated rendering (ETFR)\n</param>\n<returns>Bool:\n<ul>\n<li>`true` - success</li>\n<li>`false` - failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveatedRenderingMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_SetFoveatedRenderingMode", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveatedRenderingMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveatedRenderingMode_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveatedRenderingMode_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetFoveatedRenderingMode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveatedRenderingMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveatedRenderingMode_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveatedRenderingMode_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveatedRenderingMode_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetFoveatedRenderingMode_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveatedRenderingMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveatedRenderingMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_SetFoveationLevel_Parms
		{
			EPICOXRFoveationLevel Level;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_Level_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Level;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::NewProp_Level_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetFoveationLevel_Parms, Level), Z_Construct_UEnum_PICOXRHMD_EPICOXRFoveationLevel, METADATA_PARAMS(0, nullptr) }; // 2259085603
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_SetFoveationLevel_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_SetFoveationLevel_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::NewProp_Level_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::NewProp_Level,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Sets a foveated rendering level. </summary>\n/// <param name=\"Level\">(In) Enum, the target foveated rendering level:\n/// <ul>\n/// <li>`None`</li>\n/// <li>`Low`</li>\n/// <li>`Medium`</li>\n/// <li>`High`</li>\n/// <li>`TopHigh`</li>\n/// </ul>\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true` - success</li>\n/// <li>`false` - failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "DisplayName", "PXR Set Foveated Rendering Level" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Sets a foveated rendering level. </summary>\n<param name=\"Level\">(In) Enum, the target foveated rendering level:\n<ul>\n<li>`None`</li>\n<li>`Low`</li>\n<li>`Medium`</li>\n<li>`High`</li>\n<li>`TopHigh`</li>\n</ul>\n</param>\n<returns>Bool:\n<ul>\n<li>`true` - success</li>\n<li>`false` - failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_SetFoveationLevel", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetFoveationLevel_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetFoveationLevel_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationLevel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_SetFoveationParameter_Parms
		{
			FVector2D FoveationGainValue;
			float FoveationAreaValue;
			float FoveationMinimumValue;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_FoveationGainValue;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FoveationAreaValue;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FoveationMinimumValue;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::NewProp_FoveationGainValue = { "FoveationGainValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetFoveationParameter_Parms, FoveationGainValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::NewProp_FoveationAreaValue = { "FoveationAreaValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetFoveationParameter_Parms, FoveationAreaValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::NewProp_FoveationMinimumValue = { "FoveationMinimumValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetFoveationParameter_Parms, FoveationMinimumValue), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_SetFoveationParameter_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_SetFoveationParameter_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::NewProp_FoveationGainValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::NewProp_FoveationAreaValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::NewProp_FoveationMinimumValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Sets foveated rendering parameters.\n/// @note If you are not familiar with foveated rendering, it is recommended to use the predefined Level.\n/// </summary>\n/// <param name=\"FoveationGainValue\">(In) Vector2, it controls the rate of falloff in X and Y direction. The higher the value, the more the reduction. Value range: [1.0, 10.0].</param>\n/// <param name=\"FoveationAreaValue\">(In) Float, it defines the size of the foveated region in which the resolution does not change and this moves with user's gaze point. The value of this parameter is the radius of the region. The higher the value, the larger region. Value range: [0.0, 4.0].</param>\n/// <param name=\"FoveationMinimumValue\">(In) Float, the minimum pixel density. The actual pixel density is greater than or equal to the minimum pixel density. Recommend values: `1/32`, `1/16`, `1/8`, `1/4`, or `1/2`.</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true` - success</li>\n/// <li>`false` - failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "DisplayName", "PXR Set Foveated Rendering Parameter" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Sets foveated rendering parameters.\n@note If you are not familiar with foveated rendering, it is recommended to use the predefined Level.\n</summary>\n<param name=\"FoveationGainValue\">(In) Vector2, it controls the rate of falloff in X and Y direction. The higher the value, the more the reduction. Value range: [1.0, 10.0].</param>\n<param name=\"FoveationAreaValue\">(In) Float, it defines the size of the foveated region in which the resolution does not change and this moves with user's gaze point. The value of this parameter is the radius of the region. The higher the value, the larger region. Value range: [0.0, 4.0].</param>\n<param name=\"FoveationMinimumValue\">(In) Float, the minimum pixel density. The actual pixel density is greater than or equal to the minimum pixel density. Recommend values: `1/32`, `1/16`, `1/8`, `1/4`, or `1/2`.</param>\n<returns>Bool:\n<ul>\n<li>`true` - success</li>\n<li>`false` - failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_SetFoveationParameter", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetFoveationParameter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetFoveationParameter_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetLateLatchingEnable_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_SetLateLatchingEnable_Parms
		{
			bool Value;
		};
		static void NewProp_Value_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetLateLatchingEnable_Statics::NewProp_Value_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_SetLateLatchingEnable_Parms*)Obj)->Value = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetLateLatchingEnable_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_SetLateLatchingEnable_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetLateLatchingEnable_Statics::NewProp_Value_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetLateLatchingEnable_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetLateLatchingEnable_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetLateLatchingEnable_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetLateLatchingEnable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_SetLateLatchingEnable", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetLateLatchingEnable_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetLateLatchingEnable_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetLateLatchingEnable_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetLateLatchingEnable_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetLateLatchingEnable_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetLateLatchingEnable_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetLateLatchingEnable_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetLateLatchingEnable_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetLateLatchingEnable_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetLateLatchingEnable()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetLateLatchingEnable_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_SetPerformanceLevel_Parms
		{
			EPerformanceSettingTypes SettingType;
			EPerfSettingsLevel Level;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_SettingType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_SettingType;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Level_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Level;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics::NewProp_SettingType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics::NewProp_SettingType = { "SettingType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetPerformanceLevel_Parms, SettingType), Z_Construct_UEnum_PICOXRHMD_EPerformanceSettingTypes, METADATA_PARAMS(0, nullptr) }; // 2697330501
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics::NewProp_Level_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetPerformanceLevel_Parms, Level), Z_Construct_UEnum_PICOXRHMD_EPerfSettingsLevel, METADATA_PARAMS(0, nullptr) }; // 3917667178
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_SetPerformanceLevel_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_SetPerformanceLevel_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics::NewProp_SettingType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics::NewProp_SettingType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics::NewProp_Level_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics::NewProp_Level,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Sets a GPU or CPU level for the device.</summary>\n/// <param name =\"SettingType\">(In) Enum, choose to set a GPU or CPU level:\n/// <ul>\n/// <li>`CPULevel`</li>\n/// <li>`GPULevel`</li>\n/// </ul>\n/// </param>\n/// <param name =\"Level\">(In) Enum, select a level from the following:\n/// <ul>\n/// <li>`PowerSaving`: power-saving level</li>\n/// <li>`SustainedLow`: low level</li>\n/// <li>`SustainedHigh`: high level</li>\n/// <li>`Boost(*)`: top-high level, be careful to use this level</li>\n/// </ul>\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Sets a GPU or CPU level for the device.</summary>\n<param name =\"SettingType\">(In) Enum, choose to set a GPU or CPU level:\n<ul>\n<li>`CPULevel`</li>\n<li>`GPULevel`</li>\n</ul>\n</param>\n<param name =\"Level\">(In) Enum, select a level from the following:\n<ul>\n<li>`PowerSaving`: power-saving level</li>\n<li>`SustainedLow`: low level</li>\n<li>`SustainedHigh`: high level</li>\n<li>`Boost(*)`: top-high level, be careful to use this level</li>\n</ul>\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_SetPerformanceLevel", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetPerformanceLevel_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetPerformanceLevel_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_SetSeeThroughBackground_Parms
		{
			bool Value;
			int32 ReturnValue;
		};
		static void NewProp_Value_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Value;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::NewProp_Value_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_SetSeeThroughBackground_Parms*)Obj)->Value = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_SetSeeThroughBackground_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::NewProp_Value_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetSeeThroughBackground_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::NewProp_Value,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Sets the camera image as the background. </summary>\n/// <param name=\"Value\">(In) Bool:\n/// <ul>\n/// <li>`true` - set camera image as background</li>\n/// <li>`false` - stop using camera image as background</li>\n/// </ul>\n/// </param>\n/// <returns>Int:\n/// <ul>\n/// <li>`0` - success</li>\n/// <li>`-1` - failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Sets the camera image as the background. </summary>\n<param name=\"Value\">(In) Bool:\n<ul>\n<li>`true` - set camera image as background</li>\n<li>`false` - stop using camera image as background</li>\n</ul>\n</param>\n<returns>Int:\n<ul>\n<li>`0` - success</li>\n<li>`-1` - failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_SetSeeThroughBackground", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetSeeThroughBackground_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetSeeThroughBackground_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSeeThroughBackground()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_SetSensorLostCMST_Parms
		{
			bool Value;
			int32 ReturnValue;
		};
		static void NewProp_Value_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Value;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::NewProp_Value_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_SetSensorLostCMST_Parms*)Obj)->Value = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_SetSensorLostCMST_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::NewProp_Value_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetSensorLostCMST_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::NewProp_Value,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Set sensor lost CMST.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set sensor lost CMST." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_SetSensorLostCMST", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetSensorLostCMST_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetSensorLostCMST_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCMST()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_SetSensorLostCustomMode_Parms
		{
			bool Value;
			int32 ReturnValue;
		};
		static void NewProp_Value_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Value;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::NewProp_Value_SetBit(void* Obj)
	{
		((PICOXRHMDFunctionLibrary_eventPXR_SetSensorLostCustomMode_Parms*)Obj)->Value = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRHMDFunctionLibrary_eventPXR_SetSensorLostCustomMode_Parms), &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::NewProp_Value_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetSensorLostCustomMode_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::NewProp_Value,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Set sensor lost custom mode.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set sensor lost custom mode." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_SetSensorLostCustomMode", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetSensorLostCustomMode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetSensorLostCustomMode_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics
	{
		struct PICOXRHMDFunctionLibrary_eventPXR_SetSystemDisplayFrequency_Parms
		{
			float Rate;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Rate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics::NewProp_Rate = { "Rate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRHMDFunctionLibrary_eventPXR_SetSystemDisplayFrequency_Parms, Rate), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics::NewProp_Rate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Sets the system display frequency rate.\n\x09* @param Rate    (In) The frequency rate: 72; 90; 120. Other values are invalid.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the system display frequency rate.\n@param Rate    (In) The frequency rate: 72; 90; 120. Other values are invalid." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRHMDFunctionLibrary, nullptr, "PXR_SetSystemDisplayFrequency", nullptr, nullptr, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetSystemDisplayFrequency_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics::PICOXRHMDFunctionLibrary_eventPXR_SetSystemDisplayFrequency_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPICOXRHMDFunctionLibrary);
	UClass* Z_Construct_UClass_UPICOXRHMDFunctionLibrary_NoRegister()
	{
		return UPICOXRHMDFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UPICOXRHMDFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPICOXRHMDFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRHMD,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRHMDFunctionLibrary_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPICOXRHMDFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_GetFocusState, "GetFocusState" }, // 105768185
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestNode, "PXR_BoundaryTestNode" }, // 3977586571
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_BoundaryTestPoint, "PXR_BoundaryTestPoint" }, // 899907892
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking, "PXR_DoesSupportPositionalTracking" }, // 4204834925
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAcceleration, "PXR_GetAcceleration" }, // 3243910169
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularAcceleration, "PXR_GetAngularAcceleration" }, // 4000280357
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetAngularVelocity, "PXR_GetAngularVelocity" }, // 1547562243
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBaseRotationAndBaseOffsetInMeters, "PXR_GetBaseRotationAndBaseOffsetInMeters" }, // 4069405132
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryConfigured, "PXR_GetBoundaryConfigured" }, // 1226051688
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryDimensions, "PXR_GetBoundaryDimensions" }, // 746009896
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryEnabled, "PXR_GetBoundaryEnabled" }, // 2380424861
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryGeometry, "PXR_GetBoundaryGeometry" }, // 1089407077
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetBoundaryVisible, "PXR_GetBoundaryVisible" }, // 1311231701
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels, "PXR_GetCPUAndGPULevels" }, // 1137958180
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency, "PXR_GetCurrentDisplayFrequency" }, // 3640770537
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentOrientation, "PXR_GetCurrentOrientation" }, // 771078098
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetCurrentPosition, "PXR_GetCurrentPosition" }, // 3950114854
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceModel, "PXR_GetDeviceModel" }, // 3781160219
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDeviceName, "PXR_GetDeviceName" }, // 380600491
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable, "PXR_GetDisplayFrequenciesAvailable" }, // 2447122449
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetEventManager, "PXR_GetEventManager" }, // 2490669470
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFieldOfView, "PXR_GetFieldOfView" }, // 3074128924
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetFoveationLevel, "PXR_GetFoveationLevel" }, // 1867498891
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHFov, "PXR_GetHFov" }, // 1881547613
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHmdBatteryLevel, "PXR_GetHmdBatteryLevel" }, // 2804055028
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetHMDWornState, "PXR_GetHMDWornState" }, // 3140104655
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetIPD, "PXR_GetIPD" }, // 2572765252
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPerformanceLevel, "PXR_GetPerformanceLevel" }, // 2883411345
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedDisplayTime, "PXR_GetPredictedDisplayTime" }, // 3014291298
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState, "PXR_GetPredictedMainSensorState" }, // 1793938595
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency, "PXR_GetSystemDisplayFrequency" }, // 67812072
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetToDeltaSensorY, "PXR_GetToDeltaSensorY" }, // 1430018727
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVelocity, "PXR_GetVelocity" }, // 1242787925
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_GetVFov, "PXR_GetVFov" }, // 118455583
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_IPDChangedDelegates, "PXR_IPDChangedDelegates" }, // 884639210
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_QueryDeviceAbilities, "PXR_QueryDeviceAbilities" }, // 1486886722
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_ResetHMDSensor, "PXR_ResetHMDSensor" }, // 165636811
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SelectCoordinateSpace, "PXR_SelectCoordinateSpace" }, // 2203851796
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBaseRotationAndBaseOffsetInMeters, "PXR_SetBaseRotationAndBaseOffsetInMeters" }, // 3477316639
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetBoundaryVisible, "PXR_SetBoundaryVisible" }, // 1731010726
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset, "PXR_SetColorScaleAndOffset" }, // 1874768794
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels, "PXR_SetCPUAndGPULevels" }, // 45434133
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetExtraLatencyMode, "PXR_SetExtraLatencyMode" }, // 1762739417
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFieldOfView, "PXR_SetFieldOfView" }, // 924770761
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveatedRenderingMode, "PXR_SetFoveatedRenderingMode" }, // 877320464
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationLevel, "PXR_SetFoveationLevel" }, // 2169385403
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetFoveationParameter, "PXR_SetFoveationParameter" }, // 3929640450
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetLateLatchingEnable, "PXR_SetLateLatchingEnable" }, // 443256006
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetPerformanceLevel, "PXR_SetPerformanceLevel" }, // 722358402
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSeeThroughBackground, "PXR_SetSeeThroughBackground" }, // 2224902330
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCMST, "PXR_SetSensorLostCMST" }, // 298230515
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode, "PXR_SetSensorLostCustomMode" }, // 313683496
		{ &Z_Construct_UFunction_UPICOXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency, "PXR_SetSystemDisplayFrequency" }, // 1523542647
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRHMDFunctionLibrary_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRHMDFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PXR_HMDFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPICOXRHMDFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPICOXRHMDFunctionLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPICOXRHMDFunctionLibrary_Statics::ClassParams = {
		&UPICOXRHMDFunctionLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRHMDFunctionLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UPICOXRHMDFunctionLibrary_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPICOXRHMDFunctionLibrary()
	{
		if (!Z_Registration_Info_UClass_UPICOXRHMDFunctionLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPICOXRHMDFunctionLibrary.OuterSingleton, Z_Construct_UClass_UPICOXRHMDFunctionLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPICOXRHMDFunctionLibrary.OuterSingleton;
	}
	template<> PICOXRHMD_API UClass* StaticClass<UPICOXRHMDFunctionLibrary>()
	{
		return UPICOXRHMDFunctionLibrary::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPICOXRHMDFunctionLibrary);
	UPICOXRHMDFunctionLibrary::~UPICOXRHMDFunctionLibrary() {}
	struct Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDFunctionLibrary_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDFunctionLibrary_h_Statics::EnumInfo[] = {
		{ EPICOXRBoundaryType_StaticEnum, TEXT("EPICOXRBoundaryType"), &Z_Registration_Info_UEnum_EPICOXRBoundaryType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1887518426U) },
		{ EPICOXRBoundaryState_StaticEnum, TEXT("EPICOXRBoundaryState"), &Z_Registration_Info_UEnum_EPICOXRBoundaryState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3566351035U) },
		{ EPICOXRTrackedDeviceType_StaticEnum, TEXT("EPICOXRTrackedDeviceType"), &Z_Registration_Info_UEnum_EPICOXRTrackedDeviceType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 347928108U) },
		{ EPICOXRNodeType_StaticEnum, TEXT("EPICOXRNodeType"), &Z_Registration_Info_UEnum_EPICOXRNodeType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1745141064U) },
		{ EPICOXRCameraType_StaticEnum, TEXT("EPICOXRCameraType"), &Z_Registration_Info_UEnum_EPICOXRCameraType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2654748210U) },
		{ EPICOXRFoveationLevel_StaticEnum, TEXT("EPICOXRFoveationLevel"), &Z_Registration_Info_UEnum_EPICOXRFoveationLevel, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2259085603U) },
		{ EPICOXREyeType_StaticEnum, TEXT("EPICOXREyeType"), &Z_Registration_Info_UEnum_EPICOXREyeType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 138979643U) },
		{ EPICOXRDeviceAbilities_StaticEnum, TEXT("EPICOXRDeviceAbilities"), &Z_Registration_Info_UEnum_EPICOXRDeviceAbilities, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3507183998U) },
		{ EPerfSettingsLevel_StaticEnum, TEXT("EPerfSettingsLevel"), &Z_Registration_Info_UEnum_EPerfSettingsLevel, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3917667178U) },
		{ EPerformanceSettingTypes_StaticEnum, TEXT("EPerformanceSettingTypes"), &Z_Registration_Info_UEnum_EPerformanceSettingTypes, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2697330501U) },
		{ EFtLipsyncCtlVal_StaticEnum, TEXT("EFtLipsyncCtlVal"), &Z_Registration_Info_UEnum_EFtLipsyncCtlVal, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3952649531U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDFunctionLibrary_h_Statics::ScriptStructInfo[] = {
		{ FPxrSensorState::StaticStruct, Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewStructOps, TEXT("PxrSensorState"), &Z_Registration_Info_UScriptStruct_PxrSensorState, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPxrSensorState), 2579487364U) },
		{ FPICOXREyeTrackingData::StaticStruct, Z_Construct_UScriptStruct_FPICOXREyeTrackingData_Statics::NewStructOps, TEXT("PICOXREyeTrackingData"), &Z_Registration_Info_UScriptStruct_PICOXREyeTrackingData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPICOXREyeTrackingData), 2814306751U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDFunctionLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPICOXRHMDFunctionLibrary, UPICOXRHMDFunctionLibrary::StaticClass, TEXT("UPICOXRHMDFunctionLibrary"), &Z_Registration_Info_UClass_UPICOXRHMDFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPICOXRHMDFunctionLibrary), 2988749266U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDFunctionLibrary_h_3508945520(TEXT("/Script/PICOXRHMD"),
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDFunctionLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDFunctionLibrary_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDFunctionLibrary_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDFunctionLibrary_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDFunctionLibrary_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDFunctionLibrary_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
