// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PICOXRInput/Public/PXR_InputFunctionLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePXR_InputFunctionLibrary() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuat();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_USoundWave_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
	INPUTCORE_API UEnum* Z_Construct_UEnum_InputCore_EControllerHand();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EPxrBodyActionList();
	PICOXRINPUT_API UClass* Z_Construct_UClass_UPICOXRInputFunctionLibrary();
	PICOXRINPUT_API UClass* Z_Construct_UClass_UPICOXRInputFunctionLibrary_NoRegister();
	PICOXRINPUT_API UEnum* Z_Construct_UEnum_PICOXRInput_EBodyActionList();
	PICOXRINPUT_API UEnum* Z_Construct_UEnum_PICOXRInput_EBodyTrackingMode();
	PICOXRINPUT_API UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRActiveInputDevice();
	PICOXRINPUT_API UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRArmModelJoint();
	PICOXRINPUT_API UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRCacheConfig();
	PICOXRINPUT_API UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRChannelFlip();
	PICOXRINPUT_API UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRControllerDeviceType();
	PICOXRINPUT_API UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRControllerType();
	PICOXRINPUT_API UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRGazeBehavior();
	PICOXRINPUT_API UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRHandedness();
	PICOXRINPUT_API UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRHandFinger();
	PICOXRINPUT_API UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRHandJoint();
	PICOXRINPUT_API UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRHandTrackingConfidence();
	PICOXRINPUT_API UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRHandType();
	PICOXRINPUT_API UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRVibrateController();
	PICOXRINPUT_API UEnum* Z_Construct_UEnum_PICOXRInput_EPxrBodyTrackerRole();
	PICOXRINPUT_API UEnum* Z_Construct_UEnum_PICOXRInput_EPxrControllerKeyMap();
	PICOXRINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FAudioClipData();
	PICOXRINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FBodyTrackingBoneLength();
	PICOXRINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FMotionTrackerConnectState();
	PICOXRINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FPHFData();
	PICOXRINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FPHFDataContent();
	PICOXRINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FPHFJsonData();
	PICOXRINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FPHFJsonFrameData();
	PICOXRINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FPxrBodyTrackingImu();
	PICOXRINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FPxrBodyTrackingTransform();
	UPackage* Z_Construct_UPackage__Script_PICOXRInput();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRHandTrackingConfidence;
	static UEnum* EPICOXRHandTrackingConfidence_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRHandTrackingConfidence.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRHandTrackingConfidence.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRInput_EPICOXRHandTrackingConfidence, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("EPICOXRHandTrackingConfidence"));
		}
		return Z_Registration_Info_UEnum_EPICOXRHandTrackingConfidence.OuterSingleton;
	}
	template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRHandTrackingConfidence>()
	{
		return EPICOXRHandTrackingConfidence_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRInput_EPICOXRHandTrackingConfidence_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRInput_EPICOXRHandTrackingConfidence_Statics::Enumerators[] = {
		{ "EPICOXRHandTrackingConfidence::Low", (int64)EPICOXRHandTrackingConfidence::Low },
		{ "EPICOXRHandTrackingConfidence::High", (int64)EPICOXRHandTrackingConfidence::High },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRInput_EPICOXRHandTrackingConfidence_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "High.Name", "EPICOXRHandTrackingConfidence::High" },
		{ "Low.Name", "EPICOXRHandTrackingConfidence::Low" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRInput_EPICOXRHandTrackingConfidence_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		"EPICOXRHandTrackingConfidence",
		"EPICOXRHandTrackingConfidence",
		Z_Construct_UEnum_PICOXRInput_EPICOXRHandTrackingConfidence_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRHandTrackingConfidence_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRHandTrackingConfidence_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRInput_EPICOXRHandTrackingConfidence_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRHandTrackingConfidence()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRHandTrackingConfidence.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRHandTrackingConfidence.InnerSingleton, Z_Construct_UEnum_PICOXRInput_EPICOXRHandTrackingConfidence_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRHandTrackingConfidence.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRActiveInputDevice;
	static UEnum* EPICOXRActiveInputDevice_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRActiveInputDevice.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRActiveInputDevice.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRInput_EPICOXRActiveInputDevice, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("EPICOXRActiveInputDevice"));
		}
		return Z_Registration_Info_UEnum_EPICOXRActiveInputDevice.OuterSingleton;
	}
	template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRActiveInputDevice>()
	{
		return EPICOXRActiveInputDevice_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRInput_EPICOXRActiveInputDevice_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRInput_EPICOXRActiveInputDevice_Statics::Enumerators[] = {
		{ "EPICOXRActiveInputDevice::NoneActive", (int64)EPICOXRActiveInputDevice::NoneActive },
		{ "EPICOXRActiveInputDevice::ControllerActive", (int64)EPICOXRActiveInputDevice::ControllerActive },
		{ "EPICOXRActiveInputDevice::HandTrackingActive", (int64)EPICOXRActiveInputDevice::HandTrackingActive },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRInput_EPICOXRActiveInputDevice_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ControllerActive.Name", "EPICOXRActiveInputDevice::ControllerActive" },
		{ "HandTrackingActive.Name", "EPICOXRActiveInputDevice::HandTrackingActive" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "NoneActive.Name", "EPICOXRActiveInputDevice::NoneActive" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRInput_EPICOXRActiveInputDevice_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		"EPICOXRActiveInputDevice",
		"EPICOXRActiveInputDevice",
		Z_Construct_UEnum_PICOXRInput_EPICOXRActiveInputDevice_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRActiveInputDevice_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRActiveInputDevice_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRInput_EPICOXRActiveInputDevice_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRActiveInputDevice()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRActiveInputDevice.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRActiveInputDevice.InnerSingleton, Z_Construct_UEnum_PICOXRInput_EPICOXRActiveInputDevice_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRActiveInputDevice.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRHandFinger;
	static UEnum* EPICOXRHandFinger_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRHandFinger.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRHandFinger.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRInput_EPICOXRHandFinger, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("EPICOXRHandFinger"));
		}
		return Z_Registration_Info_UEnum_EPICOXRHandFinger.OuterSingleton;
	}
	template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRHandFinger>()
	{
		return EPICOXRHandFinger_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRInput_EPICOXRHandFinger_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRInput_EPICOXRHandFinger_Statics::Enumerators[] = {
		{ "EPICOXRHandFinger::None", (int64)EPICOXRHandFinger::None },
		{ "EPICOXRHandFinger::Index", (int64)EPICOXRHandFinger::Index },
		{ "EPICOXRHandFinger::Middle", (int64)EPICOXRHandFinger::Middle },
		{ "EPICOXRHandFinger::Ring", (int64)EPICOXRHandFinger::Ring },
		{ "EPICOXRHandFinger::Pinky", (int64)EPICOXRHandFinger::Pinky },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRInput_EPICOXRHandFinger_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Index.Name", "EPICOXRHandFinger::Index" },
		{ "Middle.Name", "EPICOXRHandFinger::Middle" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "None.Name", "EPICOXRHandFinger::None" },
		{ "Pinky.Name", "EPICOXRHandFinger::Pinky" },
		{ "Ring.Name", "EPICOXRHandFinger::Ring" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRInput_EPICOXRHandFinger_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		"EPICOXRHandFinger",
		"EPICOXRHandFinger",
		Z_Construct_UEnum_PICOXRInput_EPICOXRHandFinger_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRHandFinger_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRHandFinger_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRInput_EPICOXRHandFinger_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRHandFinger()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRHandFinger.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRHandFinger.InnerSingleton, Z_Construct_UEnum_PICOXRInput_EPICOXRHandFinger_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRHandFinger.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRHandJoint;
	static UEnum* EPICOXRHandJoint_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRHandJoint.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRHandJoint.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRInput_EPICOXRHandJoint, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("EPICOXRHandJoint"));
		}
		return Z_Registration_Info_UEnum_EPICOXRHandJoint.OuterSingleton;
	}
	template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRHandJoint>()
	{
		return EPICOXRHandJoint_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRInput_EPICOXRHandJoint_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRInput_EPICOXRHandJoint_Statics::Enumerators[] = {
		{ "EPICOXRHandJoint::Palm", (int64)EPICOXRHandJoint::Palm },
		{ "EPICOXRHandJoint::Wrist", (int64)EPICOXRHandJoint::Wrist },
		{ "EPICOXRHandJoint::ThumbMetacarpal", (int64)EPICOXRHandJoint::ThumbMetacarpal },
		{ "EPICOXRHandJoint::ThumbProximal", (int64)EPICOXRHandJoint::ThumbProximal },
		{ "EPICOXRHandJoint::ThumbDistal", (int64)EPICOXRHandJoint::ThumbDistal },
		{ "EPICOXRHandJoint::ThumbTip", (int64)EPICOXRHandJoint::ThumbTip },
		{ "EPICOXRHandJoint::IndexMetacarpal", (int64)EPICOXRHandJoint::IndexMetacarpal },
		{ "EPICOXRHandJoint::IndexProximal", (int64)EPICOXRHandJoint::IndexProximal },
		{ "EPICOXRHandJoint::IndexIntermediate", (int64)EPICOXRHandJoint::IndexIntermediate },
		{ "EPICOXRHandJoint::IndexDistal", (int64)EPICOXRHandJoint::IndexDistal },
		{ "EPICOXRHandJoint::IndexTip", (int64)EPICOXRHandJoint::IndexTip },
		{ "EPICOXRHandJoint::MiddleMetacarpal", (int64)EPICOXRHandJoint::MiddleMetacarpal },
		{ "EPICOXRHandJoint::MiddleProximal", (int64)EPICOXRHandJoint::MiddleProximal },
		{ "EPICOXRHandJoint::MiddleIntermediate", (int64)EPICOXRHandJoint::MiddleIntermediate },
		{ "EPICOXRHandJoint::MiddleDistal", (int64)EPICOXRHandJoint::MiddleDistal },
		{ "EPICOXRHandJoint::MiddleTip", (int64)EPICOXRHandJoint::MiddleTip },
		{ "EPICOXRHandJoint::RingMetacarpal", (int64)EPICOXRHandJoint::RingMetacarpal },
		{ "EPICOXRHandJoint::RingProximal", (int64)EPICOXRHandJoint::RingProximal },
		{ "EPICOXRHandJoint::RingIntermediate", (int64)EPICOXRHandJoint::RingIntermediate },
		{ "EPICOXRHandJoint::RingDistal", (int64)EPICOXRHandJoint::RingDistal },
		{ "EPICOXRHandJoint::RingTip", (int64)EPICOXRHandJoint::RingTip },
		{ "EPICOXRHandJoint::LittleMetacarpal", (int64)EPICOXRHandJoint::LittleMetacarpal },
		{ "EPICOXRHandJoint::LittleProximal", (int64)EPICOXRHandJoint::LittleProximal },
		{ "EPICOXRHandJoint::LittleIntermediate", (int64)EPICOXRHandJoint::LittleIntermediate },
		{ "EPICOXRHandJoint::LittleDistal", (int64)EPICOXRHandJoint::LittleDistal },
		{ "EPICOXRHandJoint::LittleTip", (int64)EPICOXRHandJoint::LittleTip },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRInput_EPICOXRHandJoint_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IndexDistal.Name", "EPICOXRHandJoint::IndexDistal" },
		{ "IndexIntermediate.Name", "EPICOXRHandJoint::IndexIntermediate" },
		{ "IndexMetacarpal.Name", "EPICOXRHandJoint::IndexMetacarpal" },
		{ "IndexProximal.Name", "EPICOXRHandJoint::IndexProximal" },
		{ "IndexTip.Name", "EPICOXRHandJoint::IndexTip" },
		{ "LittleDistal.Name", "EPICOXRHandJoint::LittleDistal" },
		{ "LittleIntermediate.Name", "EPICOXRHandJoint::LittleIntermediate" },
		{ "LittleMetacarpal.Name", "EPICOXRHandJoint::LittleMetacarpal" },
		{ "LittleProximal.Name", "EPICOXRHandJoint::LittleProximal" },
		{ "LittleTip.Name", "EPICOXRHandJoint::LittleTip" },
		{ "MiddleDistal.Name", "EPICOXRHandJoint::MiddleDistal" },
		{ "MiddleIntermediate.Name", "EPICOXRHandJoint::MiddleIntermediate" },
		{ "MiddleMetacarpal.Name", "EPICOXRHandJoint::MiddleMetacarpal" },
		{ "MiddleProximal.Name", "EPICOXRHandJoint::MiddleProximal" },
		{ "MiddleTip.Name", "EPICOXRHandJoint::MiddleTip" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "Palm.Name", "EPICOXRHandJoint::Palm" },
		{ "RingDistal.Name", "EPICOXRHandJoint::RingDistal" },
		{ "RingIntermediate.Name", "EPICOXRHandJoint::RingIntermediate" },
		{ "RingMetacarpal.Name", "EPICOXRHandJoint::RingMetacarpal" },
		{ "RingProximal.Name", "EPICOXRHandJoint::RingProximal" },
		{ "RingTip.Name", "EPICOXRHandJoint::RingTip" },
		{ "ThumbDistal.Name", "EPICOXRHandJoint::ThumbDistal" },
		{ "ThumbMetacarpal.Name", "EPICOXRHandJoint::ThumbMetacarpal" },
		{ "ThumbProximal.Name", "EPICOXRHandJoint::ThumbProximal" },
		{ "ThumbTip.Name", "EPICOXRHandJoint::ThumbTip" },
		{ "Wrist.Name", "EPICOXRHandJoint::Wrist" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRInput_EPICOXRHandJoint_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		"EPICOXRHandJoint",
		"EPICOXRHandJoint",
		Z_Construct_UEnum_PICOXRInput_EPICOXRHandJoint_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRHandJoint_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRHandJoint_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRInput_EPICOXRHandJoint_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRHandJoint()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRHandJoint.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRHandJoint.InnerSingleton, Z_Construct_UEnum_PICOXRInput_EPICOXRHandJoint_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRHandJoint.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRHandType;
	static UEnum* EPICOXRHandType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRHandType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRHandType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRInput_EPICOXRHandType, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("EPICOXRHandType"));
		}
		return Z_Registration_Info_UEnum_EPICOXRHandType.OuterSingleton;
	}
	template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRHandType>()
	{
		return EPICOXRHandType_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRInput_EPICOXRHandType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRInput_EPICOXRHandType_Statics::Enumerators[] = {
		{ "EPICOXRHandType::None", (int64)EPICOXRHandType::None },
		{ "EPICOXRHandType::HandLeft", (int64)EPICOXRHandType::HandLeft },
		{ "EPICOXRHandType::HandRight", (int64)EPICOXRHandType::HandRight },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRInput_EPICOXRHandType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HandLeft.Name", "EPICOXRHandType::HandLeft" },
		{ "HandRight.Name", "EPICOXRHandType::HandRight" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "None.Name", "EPICOXRHandType::None" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRInput_EPICOXRHandType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		"EPICOXRHandType",
		"EPICOXRHandType",
		Z_Construct_UEnum_PICOXRInput_EPICOXRHandType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRHandType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRHandType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRInput_EPICOXRHandType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRHandType()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRHandType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRHandType.InnerSingleton, Z_Construct_UEnum_PICOXRInput_EPICOXRHandType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRHandType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRHandedness;
	static UEnum* EPICOXRHandedness_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRHandedness.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRHandedness.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRInput_EPICOXRHandedness, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("EPICOXRHandedness"));
		}
		return Z_Registration_Info_UEnum_EPICOXRHandedness.OuterSingleton;
	}
	template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRHandedness>()
	{
		return EPICOXRHandedness_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRInput_EPICOXRHandedness_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRInput_EPICOXRHandedness_Statics::Enumerators[] = {
		{ "EPICOXRHandedness::LeftHand", (int64)EPICOXRHandedness::LeftHand },
		{ "EPICOXRHandedness::RightHand", (int64)EPICOXRHandedness::RightHand },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRInput_EPICOXRHandedness_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "LeftHand.Name", "EPICOXRHandedness::LeftHand" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "RightHand.Name", "EPICOXRHandedness::RightHand" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRInput_EPICOXRHandedness_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		"EPICOXRHandedness",
		"EPICOXRHandedness",
		Z_Construct_UEnum_PICOXRInput_EPICOXRHandedness_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRHandedness_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRHandedness_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRInput_EPICOXRHandedness_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRHandedness()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRHandedness.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRHandedness.InnerSingleton, Z_Construct_UEnum_PICOXRInput_EPICOXRHandedness_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRHandedness.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRControllerType;
	static UEnum* EPICOXRControllerType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRControllerType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRControllerType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRInput_EPICOXRControllerType, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("EPICOXRControllerType"));
		}
		return Z_Registration_Info_UEnum_EPICOXRControllerType.OuterSingleton;
	}
	template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRControllerType>()
	{
		return EPICOXRControllerType_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRInput_EPICOXRControllerType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRInput_EPICOXRControllerType_Statics::Enumerators[] = {
		{ "EPICOXRControllerType::LeftHand", (int64)EPICOXRControllerType::LeftHand },
		{ "EPICOXRControllerType::RightHand", (int64)EPICOXRControllerType::RightHand },
		{ "EPICOXRControllerType::G2Hand", (int64)EPICOXRControllerType::G2Hand },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRInput_EPICOXRControllerType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "G2Hand.DisplayName", "PICO G2 Hand" },
		{ "G2Hand.Name", "EPICOXRControllerType::G2Hand" },
		{ "LeftHand.DisplayName", "PICO LeftHand" },
		{ "LeftHand.Name", "EPICOXRControllerType::LeftHand" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "RightHand.DisplayName", "PICO RightHand" },
		{ "RightHand.Name", "EPICOXRControllerType::RightHand" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRInput_EPICOXRControllerType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		"EPICOXRControllerType",
		"EPICOXRControllerType",
		Z_Construct_UEnum_PICOXRInput_EPICOXRControllerType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRControllerType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRControllerType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRInput_EPICOXRControllerType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRControllerType()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRControllerType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRControllerType.InnerSingleton, Z_Construct_UEnum_PICOXRInput_EPICOXRControllerType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRControllerType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRArmModelJoint;
	static UEnum* EPICOXRArmModelJoint_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRArmModelJoint.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRArmModelJoint.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRInput_EPICOXRArmModelJoint, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("EPICOXRArmModelJoint"));
		}
		return Z_Registration_Info_UEnum_EPICOXRArmModelJoint.OuterSingleton;
	}
	template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRArmModelJoint>()
	{
		return EPICOXRArmModelJoint_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRInput_EPICOXRArmModelJoint_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRInput_EPICOXRArmModelJoint_Statics::Enumerators[] = {
		{ "EPICOXRArmModelJoint::Controller", (int64)EPICOXRArmModelJoint::Controller },
		{ "EPICOXRArmModelJoint::Wrist", (int64)EPICOXRArmModelJoint::Wrist },
		{ "EPICOXRArmModelJoint::Elbow", (int64)EPICOXRArmModelJoint::Elbow },
		{ "EPICOXRArmModelJoint::Shoulder", (int64)EPICOXRArmModelJoint::Shoulder },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRInput_EPICOXRArmModelJoint_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Controller.Name", "EPICOXRArmModelJoint::Controller" },
		{ "Elbow.Name", "EPICOXRArmModelJoint::Elbow" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "Shoulder.Name", "EPICOXRArmModelJoint::Shoulder" },
		{ "Wrist.Name", "EPICOXRArmModelJoint::Wrist" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRInput_EPICOXRArmModelJoint_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		"EPICOXRArmModelJoint",
		"EPICOXRArmModelJoint",
		Z_Construct_UEnum_PICOXRInput_EPICOXRArmModelJoint_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRArmModelJoint_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRArmModelJoint_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRInput_EPICOXRArmModelJoint_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRArmModelJoint()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRArmModelJoint.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRArmModelJoint.InnerSingleton, Z_Construct_UEnum_PICOXRInput_EPICOXRArmModelJoint_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRArmModelJoint.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRGazeBehavior;
	static UEnum* EPICOXRGazeBehavior_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRGazeBehavior.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRGazeBehavior.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRInput_EPICOXRGazeBehavior, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("EPICOXRGazeBehavior"));
		}
		return Z_Registration_Info_UEnum_EPICOXRGazeBehavior.OuterSingleton;
	}
	template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRGazeBehavior>()
	{
		return EPICOXRGazeBehavior_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRInput_EPICOXRGazeBehavior_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRInput_EPICOXRGazeBehavior_Statics::Enumerators[] = {
		{ "EPICOXRGazeBehavior::Never", (int64)EPICOXRGazeBehavior::Never },
		{ "EPICOXRGazeBehavior::DuringMotion", (int64)EPICOXRGazeBehavior::DuringMotion },
		{ "EPICOXRGazeBehavior::Always", (int64)EPICOXRGazeBehavior::Always },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRInput_EPICOXRGazeBehavior_Statics::Enum_MetaDataParams[] = {
		{ "Always.Name", "EPICOXRGazeBehavior::Always" },
		{ "BlueprintType", "true" },
		{ "DuringMotion.Name", "EPICOXRGazeBehavior::DuringMotion" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "Never.Name", "EPICOXRGazeBehavior::Never" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRInput_EPICOXRGazeBehavior_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		"EPICOXRGazeBehavior",
		"EPICOXRGazeBehavior",
		Z_Construct_UEnum_PICOXRInput_EPICOXRGazeBehavior_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRGazeBehavior_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRGazeBehavior_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRInput_EPICOXRGazeBehavior_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRGazeBehavior()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRGazeBehavior.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRGazeBehavior.InnerSingleton, Z_Construct_UEnum_PICOXRInput_EPICOXRGazeBehavior_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRGazeBehavior.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRControllerDeviceType;
	static UEnum* EPICOXRControllerDeviceType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRControllerDeviceType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRControllerDeviceType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRInput_EPICOXRControllerDeviceType, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("EPICOXRControllerDeviceType"));
		}
		return Z_Registration_Info_UEnum_EPICOXRControllerDeviceType.OuterSingleton;
	}
	template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRControllerDeviceType>()
	{
		return EPICOXRControllerDeviceType_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRInput_EPICOXRControllerDeviceType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRInput_EPICOXRControllerDeviceType_Statics::Enumerators[] = {
		{ "EPICOXRControllerDeviceType::UnKnown", (int64)EPICOXRControllerDeviceType::UnKnown },
		{ "EPICOXRControllerDeviceType::G2", (int64)EPICOXRControllerDeviceType::G2 },
		{ "EPICOXRControllerDeviceType::Neo2", (int64)EPICOXRControllerDeviceType::Neo2 },
		{ "EPICOXRControllerDeviceType::Neo3", (int64)EPICOXRControllerDeviceType::Neo3 },
		{ "EPICOXRControllerDeviceType::PICO_4", (int64)EPICOXRControllerDeviceType::PICO_4 },
		{ "EPICOXRControllerDeviceType::G3", (int64)EPICOXRControllerDeviceType::G3 },
		{ "EPICOXRControllerDeviceType::PICO_4_U", (int64)EPICOXRControllerDeviceType::PICO_4_U },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRInput_EPICOXRControllerDeviceType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "G2.DisplayName", "PICO G2" },
		{ "G2.Name", "EPICOXRControllerDeviceType::G2" },
		{ "G3.DisplayName", "PICO G3" },
		{ "G3.Name", "EPICOXRControllerDeviceType::G3" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "Neo2.DisplayName", "PICO Neo2" },
		{ "Neo2.Name", "EPICOXRControllerDeviceType::Neo2" },
		{ "Neo3.DisplayName", "PICO Neo3" },
		{ "Neo3.Name", "EPICOXRControllerDeviceType::Neo3" },
		{ "PICO_4.DisplayName", "PICO 4" },
		{ "PICO_4.Name", "EPICOXRControllerDeviceType::PICO_4" },
		{ "PICO_4_U.DisplayName", "PICO 4 U" },
		{ "PICO_4_U.Name", "EPICOXRControllerDeviceType::PICO_4_U" },
		{ "UnKnown.DisplayName", "Unknown Controller" },
		{ "UnKnown.Name", "EPICOXRControllerDeviceType::UnKnown" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRInput_EPICOXRControllerDeviceType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		"EPICOXRControllerDeviceType",
		"EPICOXRControllerDeviceType",
		Z_Construct_UEnum_PICOXRInput_EPICOXRControllerDeviceType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRControllerDeviceType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRControllerDeviceType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRInput_EPICOXRControllerDeviceType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRControllerDeviceType()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRControllerDeviceType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRControllerDeviceType.InnerSingleton, Z_Construct_UEnum_PICOXRInput_EPICOXRControllerDeviceType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRControllerDeviceType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRVibrateController;
	static UEnum* EPICOXRVibrateController_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRVibrateController.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRVibrateController.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRInput_EPICOXRVibrateController, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("EPICOXRVibrateController"));
		}
		return Z_Registration_Info_UEnum_EPICOXRVibrateController.OuterSingleton;
	}
	template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRVibrateController>()
	{
		return EPICOXRVibrateController_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRInput_EPICOXRVibrateController_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRInput_EPICOXRVibrateController_Statics::Enumerators[] = {
		{ "EPICOXRVibrateController::No", (int64)EPICOXRVibrateController::No },
		{ "EPICOXRVibrateController::Left", (int64)EPICOXRVibrateController::Left },
		{ "EPICOXRVibrateController::Right", (int64)EPICOXRVibrateController::Right },
		{ "EPICOXRVibrateController::LeftAndRight", (int64)EPICOXRVibrateController::LeftAndRight },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRInput_EPICOXRVibrateController_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Left.Name", "EPICOXRVibrateController::Left" },
		{ "LeftAndRight.Name", "EPICOXRVibrateController::LeftAndRight" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "No.Name", "EPICOXRVibrateController::No" },
		{ "Right.Name", "EPICOXRVibrateController::Right" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRInput_EPICOXRVibrateController_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		"EPICOXRVibrateController",
		"EPICOXRVibrateController",
		Z_Construct_UEnum_PICOXRInput_EPICOXRVibrateController_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRVibrateController_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRVibrateController_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRInput_EPICOXRVibrateController_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRVibrateController()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRVibrateController.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRVibrateController.InnerSingleton, Z_Construct_UEnum_PICOXRInput_EPICOXRVibrateController_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRVibrateController.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRChannelFlip;
	static UEnum* EPICOXRChannelFlip_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRChannelFlip.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRChannelFlip.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRInput_EPICOXRChannelFlip, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("EPICOXRChannelFlip"));
		}
		return Z_Registration_Info_UEnum_EPICOXRChannelFlip.OuterSingleton;
	}
	template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRChannelFlip>()
	{
		return EPICOXRChannelFlip_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRInput_EPICOXRChannelFlip_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRInput_EPICOXRChannelFlip_Statics::Enumerators[] = {
		{ "EPICOXRChannelFlip::No", (int64)EPICOXRChannelFlip::No },
		{ "EPICOXRChannelFlip::Yes", (int64)EPICOXRChannelFlip::Yes },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRInput_EPICOXRChannelFlip_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "No.Name", "EPICOXRChannelFlip::No" },
		{ "Yes.Name", "EPICOXRChannelFlip::Yes" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRInput_EPICOXRChannelFlip_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		"EPICOXRChannelFlip",
		"EPICOXRChannelFlip",
		Z_Construct_UEnum_PICOXRInput_EPICOXRChannelFlip_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRChannelFlip_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRChannelFlip_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRInput_EPICOXRChannelFlip_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRChannelFlip()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRChannelFlip.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRChannelFlip.InnerSingleton, Z_Construct_UEnum_PICOXRInput_EPICOXRChannelFlip_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRChannelFlip.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRCacheConfig;
	static UEnum* EPICOXRCacheConfig_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRCacheConfig.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRCacheConfig.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRInput_EPICOXRCacheConfig, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("EPICOXRCacheConfig"));
		}
		return Z_Registration_Info_UEnum_EPICOXRCacheConfig.OuterSingleton;
	}
	template<> PICOXRINPUT_API UEnum* StaticEnum<EPICOXRCacheConfig>()
	{
		return EPICOXRCacheConfig_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRInput_EPICOXRCacheConfig_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRInput_EPICOXRCacheConfig_Statics::Enumerators[] = {
		{ "EPICOXRCacheConfig::CacheAndVibrate", (int64)EPICOXRCacheConfig::CacheAndVibrate },
		{ "EPICOXRCacheConfig::CacheNoVibrate", (int64)EPICOXRCacheConfig::CacheNoVibrate },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRInput_EPICOXRCacheConfig_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CacheAndVibrate.Name", "EPICOXRCacheConfig::CacheAndVibrate" },
		{ "CacheNoVibrate.Name", "EPICOXRCacheConfig::CacheNoVibrate" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRInput_EPICOXRCacheConfig_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		"EPICOXRCacheConfig",
		"EPICOXRCacheConfig",
		Z_Construct_UEnum_PICOXRInput_EPICOXRCacheConfig_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRCacheConfig_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPICOXRCacheConfig_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRInput_EPICOXRCacheConfig_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRInput_EPICOXRCacheConfig()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRCacheConfig.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRCacheConfig.InnerSingleton, Z_Construct_UEnum_PICOXRInput_EPICOXRCacheConfig_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRCacheConfig.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EBodyActionList;
	static UEnum* EBodyActionList_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EBodyActionList.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EBodyActionList.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRInput_EBodyActionList, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("EBodyActionList"));
		}
		return Z_Registration_Info_UEnum_EBodyActionList.OuterSingleton;
	}
	template<> PICOXRINPUT_API UEnum* StaticEnum<EBodyActionList>()
	{
		return EBodyActionList_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRInput_EBodyActionList_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRInput_EBodyActionList_Statics::Enumerators[] = {
		{ "EBodyActionList::PxrNoneAction", (int64)EBodyActionList::PxrNoneAction },
		{ "EBodyActionList::PxrTouchGround", (int64)EBodyActionList::PxrTouchGround },
		{ "EBodyActionList::PxrKeepStatic", (int64)EBodyActionList::PxrKeepStatic },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRInput_EBodyActionList_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "PxrKeepStatic.Name", "EBodyActionList::PxrKeepStatic" },
		{ "PxrNoneAction.Name", "EBodyActionList::PxrNoneAction" },
		{ "PxrTouchGround.Name", "EBodyActionList::PxrTouchGround" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRInput_EBodyActionList_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		"EBodyActionList",
		"EBodyActionList",
		Z_Construct_UEnum_PICOXRInput_EBodyActionList_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EBodyActionList_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EBodyActionList_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRInput_EBodyActionList_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRInput_EBodyActionList()
	{
		if (!Z_Registration_Info_UEnum_EBodyActionList.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EBodyActionList.InnerSingleton, Z_Construct_UEnum_PICOXRInput_EBodyActionList_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EBodyActionList.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPxrControllerKeyMap;
	static UEnum* EPxrControllerKeyMap_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPxrControllerKeyMap.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPxrControllerKeyMap.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRInput_EPxrControllerKeyMap, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("EPxrControllerKeyMap"));
		}
		return Z_Registration_Info_UEnum_EPxrControllerKeyMap.OuterSingleton;
	}
	template<> PICOXRINPUT_API UEnum* StaticEnum<EPxrControllerKeyMap>()
	{
		return EPxrControllerKeyMap_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRInput_EPxrControllerKeyMap_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRInput_EPxrControllerKeyMap_Statics::Enumerators[] = {
		{ "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_HOME", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_KEY_HOME },
		{ "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_AX", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_KEY_AX },
		{ "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_BY", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_KEY_BY },
		{ "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_BACK", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_KEY_BACK },
		{ "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_TRIGGER", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_KEY_TRIGGER },
		{ "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_VOL_UP", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_KEY_VOL_UP },
		{ "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_VOL_DOWN", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_KEY_VOL_DOWN },
		{ "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_ROCKER", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_KEY_ROCKER },
		{ "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_GRIP", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_KEY_GRIP },
		{ "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_TOUCHPAD", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_KEY_TOUCHPAD },
		{ "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_LASTONE", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_KEY_LASTONE },
		{ "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_AX", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_AX },
		{ "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_BY", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_BY },
		{ "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_ROCKER", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_ROCKER },
		{ "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_TRIGGER", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_TRIGGER },
		{ "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_THUMB", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_THUMB },
		{ "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_LASTONE", (int64)EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_LASTONE },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRInput_EPxrControllerKeyMap_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "PXR_CONTROLLER_KEY_AX.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_AX" },
		{ "PXR_CONTROLLER_KEY_BACK.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_BACK" },
		{ "PXR_CONTROLLER_KEY_BY.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_BY" },
		{ "PXR_CONTROLLER_KEY_GRIP.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_GRIP" },
		{ "PXR_CONTROLLER_KEY_HOME.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_HOME" },
		{ "PXR_CONTROLLER_KEY_LASTONE.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_LASTONE" },
		{ "PXR_CONTROLLER_KEY_ROCKER.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_ROCKER" },
		{ "PXR_CONTROLLER_KEY_TOUCHPAD.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_TOUCHPAD" },
		{ "PXR_CONTROLLER_KEY_TRIGGER.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_TRIGGER" },
		{ "PXR_CONTROLLER_KEY_VOL_DOWN.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_VOL_DOWN" },
		{ "PXR_CONTROLLER_KEY_VOL_UP.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_KEY_VOL_UP" },
		{ "PXR_CONTROLLER_TOUCH_AX.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_AX" },
		{ "PXR_CONTROLLER_TOUCH_BY.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_BY" },
		{ "PXR_CONTROLLER_TOUCH_LASTONE.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_LASTONE" },
		{ "PXR_CONTROLLER_TOUCH_ROCKER.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_ROCKER" },
		{ "PXR_CONTROLLER_TOUCH_THUMB.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_THUMB" },
		{ "PXR_CONTROLLER_TOUCH_TRIGGER.Name", "EPxrControllerKeyMap::PXR_CONTROLLER_TOUCH_TRIGGER" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRInput_EPxrControllerKeyMap_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		"EPxrControllerKeyMap",
		"EPxrControllerKeyMap",
		Z_Construct_UEnum_PICOXRInput_EPxrControllerKeyMap_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPxrControllerKeyMap_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPxrControllerKeyMap_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRInput_EPxrControllerKeyMap_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRInput_EPxrControllerKeyMap()
	{
		if (!Z_Registration_Info_UEnum_EPxrControllerKeyMap.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPxrControllerKeyMap.InnerSingleton, Z_Construct_UEnum_PICOXRInput_EPxrControllerKeyMap_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPxrControllerKeyMap.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPxrBodyTrackerRole;
	static UEnum* EPxrBodyTrackerRole_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPxrBodyTrackerRole.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPxrBodyTrackerRole.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRInput_EPxrBodyTrackerRole, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("EPxrBodyTrackerRole"));
		}
		return Z_Registration_Info_UEnum_EPxrBodyTrackerRole.OuterSingleton;
	}
	template<> PICOXRINPUT_API UEnum* StaticEnum<EPxrBodyTrackerRole>()
	{
		return EPxrBodyTrackerRole_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRInput_EPxrBodyTrackerRole_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRInput_EPxrBodyTrackerRole_Statics::Enumerators[] = {
		{ "EPxrBodyTrackerRole::PxrPelvis", (int64)EPxrBodyTrackerRole::PxrPelvis },
		{ "EPxrBodyTrackerRole::Pxr_LEFT_HIP", (int64)EPxrBodyTrackerRole::Pxr_LEFT_HIP },
		{ "EPxrBodyTrackerRole::Pxr_RIGHT_HIP", (int64)EPxrBodyTrackerRole::Pxr_RIGHT_HIP },
		{ "EPxrBodyTrackerRole::Pxr_SPINE1", (int64)EPxrBodyTrackerRole::Pxr_SPINE1 },
		{ "EPxrBodyTrackerRole::Pxr_LEFT_KNEE", (int64)EPxrBodyTrackerRole::Pxr_LEFT_KNEE },
		{ "EPxrBodyTrackerRole::Pxr_RIGHT_KNEE", (int64)EPxrBodyTrackerRole::Pxr_RIGHT_KNEE },
		{ "EPxrBodyTrackerRole::Pxr_SPINE2", (int64)EPxrBodyTrackerRole::Pxr_SPINE2 },
		{ "EPxrBodyTrackerRole::Pxr_LEFT_ANKLE", (int64)EPxrBodyTrackerRole::Pxr_LEFT_ANKLE },
		{ "EPxrBodyTrackerRole::Pxr_RIGHT_ANKLE", (int64)EPxrBodyTrackerRole::Pxr_RIGHT_ANKLE },
		{ "EPxrBodyTrackerRole::Pxr_SPINE3", (int64)EPxrBodyTrackerRole::Pxr_SPINE3 },
		{ "EPxrBodyTrackerRole::Pxr_LEFT_FOOT", (int64)EPxrBodyTrackerRole::Pxr_LEFT_FOOT },
		{ "EPxrBodyTrackerRole::Pxr_RIGHT_FOOT", (int64)EPxrBodyTrackerRole::Pxr_RIGHT_FOOT },
		{ "EPxrBodyTrackerRole::Pxr_NECK", (int64)EPxrBodyTrackerRole::Pxr_NECK },
		{ "EPxrBodyTrackerRole::Pxr_LEFT_COLLAR", (int64)EPxrBodyTrackerRole::Pxr_LEFT_COLLAR },
		{ "EPxrBodyTrackerRole::Pxr_RIGHT_COLLAR", (int64)EPxrBodyTrackerRole::Pxr_RIGHT_COLLAR },
		{ "EPxrBodyTrackerRole::Pxr_HEAD", (int64)EPxrBodyTrackerRole::Pxr_HEAD },
		{ "EPxrBodyTrackerRole::Pxr_LEFT_SHOULDER", (int64)EPxrBodyTrackerRole::Pxr_LEFT_SHOULDER },
		{ "EPxrBodyTrackerRole::Pxr_RIGHT_SHOULDER", (int64)EPxrBodyTrackerRole::Pxr_RIGHT_SHOULDER },
		{ "EPxrBodyTrackerRole::Pxr_LEFT_ELBOW", (int64)EPxrBodyTrackerRole::Pxr_LEFT_ELBOW },
		{ "EPxrBodyTrackerRole::Pxr_RIGHT_ELBOW", (int64)EPxrBodyTrackerRole::Pxr_RIGHT_ELBOW },
		{ "EPxrBodyTrackerRole::Pxr_LEFT_WRIST", (int64)EPxrBodyTrackerRole::Pxr_LEFT_WRIST },
		{ "EPxrBodyTrackerRole::Pxr_RIGHT_WRIST", (int64)EPxrBodyTrackerRole::Pxr_RIGHT_WRIST },
		{ "EPxrBodyTrackerRole::Pxr_LEFT_HAND", (int64)EPxrBodyTrackerRole::Pxr_LEFT_HAND },
		{ "EPxrBodyTrackerRole::Pxr_RIGHT_HAND", (int64)EPxrBodyTrackerRole::Pxr_RIGHT_HAND },
		{ "EPxrBodyTrackerRole::Pxr_ROLE_COUNT", (int64)EPxrBodyTrackerRole::Pxr_ROLE_COUNT },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRInput_EPxrBodyTrackerRole_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "Pxr_HEAD.DisplayName", "HEAD" },
		{ "Pxr_HEAD.Name", "EPxrBodyTrackerRole::Pxr_HEAD" },
		{ "Pxr_LEFT_ANKLE.DisplayName", "LEFT_ANKLE" },
		{ "Pxr_LEFT_ANKLE.Name", "EPxrBodyTrackerRole::Pxr_LEFT_ANKLE" },
		{ "Pxr_LEFT_COLLAR.DisplayName", "LEFT_COLLAR" },
		{ "Pxr_LEFT_COLLAR.Name", "EPxrBodyTrackerRole::Pxr_LEFT_COLLAR" },
		{ "Pxr_LEFT_ELBOW.DisplayName", "LEFT_ELBOW" },
		{ "Pxr_LEFT_ELBOW.Name", "EPxrBodyTrackerRole::Pxr_LEFT_ELBOW" },
		{ "Pxr_LEFT_FOOT.DisplayName", "LEFT_FOOT" },
		{ "Pxr_LEFT_FOOT.Name", "EPxrBodyTrackerRole::Pxr_LEFT_FOOT" },
		{ "Pxr_LEFT_HAND.DisplayName", "LEFT_HAND" },
		{ "Pxr_LEFT_HAND.Name", "EPxrBodyTrackerRole::Pxr_LEFT_HAND" },
		{ "Pxr_LEFT_HIP.DisplayName", "LEFT_HIP" },
		{ "Pxr_LEFT_HIP.Name", "EPxrBodyTrackerRole::Pxr_LEFT_HIP" },
		{ "Pxr_LEFT_KNEE.DisplayName", "LEFT_KNEE" },
		{ "Pxr_LEFT_KNEE.Name", "EPxrBodyTrackerRole::Pxr_LEFT_KNEE" },
		{ "Pxr_LEFT_SHOULDER.DisplayName", "LEFT_SHOULDER" },
		{ "Pxr_LEFT_SHOULDER.Name", "EPxrBodyTrackerRole::Pxr_LEFT_SHOULDER" },
		{ "Pxr_LEFT_WRIST.DisplayName", "LEFT_WRIST" },
		{ "Pxr_LEFT_WRIST.Name", "EPxrBodyTrackerRole::Pxr_LEFT_WRIST" },
		{ "Pxr_NECK.DisplayName", "NECK" },
		{ "Pxr_NECK.Name", "EPxrBodyTrackerRole::Pxr_NECK" },
		{ "Pxr_RIGHT_ANKLE.DisplayName", "RIGHT_ANKLE" },
		{ "Pxr_RIGHT_ANKLE.Name", "EPxrBodyTrackerRole::Pxr_RIGHT_ANKLE" },
		{ "Pxr_RIGHT_COLLAR.DisplayName", "RIGHT_COLLAR" },
		{ "Pxr_RIGHT_COLLAR.Name", "EPxrBodyTrackerRole::Pxr_RIGHT_COLLAR" },
		{ "Pxr_RIGHT_ELBOW.DisplayName", "RIGHT_ELBOW" },
		{ "Pxr_RIGHT_ELBOW.Name", "EPxrBodyTrackerRole::Pxr_RIGHT_ELBOW" },
		{ "Pxr_RIGHT_FOOT.DisplayName", "RIGHT_FOOT" },
		{ "Pxr_RIGHT_FOOT.Name", "EPxrBodyTrackerRole::Pxr_RIGHT_FOOT" },
		{ "Pxr_RIGHT_HAND.DisplayName", "RIGHT_HAND" },
		{ "Pxr_RIGHT_HAND.Name", "EPxrBodyTrackerRole::Pxr_RIGHT_HAND" },
		{ "Pxr_RIGHT_HIP.DisplayName", "RIGHT_HIP" },
		{ "Pxr_RIGHT_HIP.Name", "EPxrBodyTrackerRole::Pxr_RIGHT_HIP" },
		{ "Pxr_RIGHT_KNEE.DisplayName", "RIGHT_KNEE" },
		{ "Pxr_RIGHT_KNEE.Name", "EPxrBodyTrackerRole::Pxr_RIGHT_KNEE" },
		{ "Pxr_RIGHT_SHOULDER.DisplayName", "RIGHT_SHOULDER" },
		{ "Pxr_RIGHT_SHOULDER.Name", "EPxrBodyTrackerRole::Pxr_RIGHT_SHOULDER" },
		{ "Pxr_RIGHT_WRIST.DisplayName", "RIGHT_WRIST" },
		{ "Pxr_RIGHT_WRIST.Name", "EPxrBodyTrackerRole::Pxr_RIGHT_WRIST" },
		{ "Pxr_ROLE_COUNT.DisplayName", "Pxr_ROLE_COUNT" },
		{ "Pxr_ROLE_COUNT.Name", "EPxrBodyTrackerRole::Pxr_ROLE_COUNT" },
		{ "Pxr_SPINE1.DisplayName", "SPINE1" },
		{ "Pxr_SPINE1.Name", "EPxrBodyTrackerRole::Pxr_SPINE1" },
		{ "Pxr_SPINE2.DisplayName", "SPINE2" },
		{ "Pxr_SPINE2.Name", "EPxrBodyTrackerRole::Pxr_SPINE2" },
		{ "Pxr_SPINE3.DisplayName", "SPINE3" },
		{ "Pxr_SPINE3.Name", "EPxrBodyTrackerRole::Pxr_SPINE3" },
		{ "PxrPelvis.DisplayName", "Pelvis" },
		{ "PxrPelvis.Name", "EPxrBodyTrackerRole::PxrPelvis" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRInput_EPxrBodyTrackerRole_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		"EPxrBodyTrackerRole",
		"EPxrBodyTrackerRole",
		Z_Construct_UEnum_PICOXRInput_EPxrBodyTrackerRole_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPxrBodyTrackerRole_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EPxrBodyTrackerRole_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRInput_EPxrBodyTrackerRole_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRInput_EPxrBodyTrackerRole()
	{
		if (!Z_Registration_Info_UEnum_EPxrBodyTrackerRole.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPxrBodyTrackerRole.InnerSingleton, Z_Construct_UEnum_PICOXRInput_EPxrBodyTrackerRole_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPxrBodyTrackerRole.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PxrBodyTrackingImu;
class UScriptStruct* FPxrBodyTrackingImu::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PxrBodyTrackingImu.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PxrBodyTrackingImu.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPxrBodyTrackingImu, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("PxrBodyTrackingImu"));
	}
	return Z_Registration_Info_UScriptStruct_PxrBodyTrackingImu.OuterSingleton;
}
template<> PICOXRINPUT_API UScriptStruct* StaticStruct<FPxrBodyTrackingImu>()
{
	return FPxrBodyTrackingImu::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TimeStamp_MetaData[];
#endif
		static const UECodeGen_Private::FInt64PropertyParams NewProp_TimeStamp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_temperature_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_temperature;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GyroData_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GyroData;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AccData_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AccData;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MagData_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_MagData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// imu data\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "imu data" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPxrBodyTrackingImu>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_TimeStamp_MetaData[] = {
		{ "Category", "PXR|FBodyTrackingImuData" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_TimeStamp = { "TimeStamp", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrBodyTrackingImu, TimeStamp), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_TimeStamp_MetaData), Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_TimeStamp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_temperature_MetaData[] = {
		{ "Category", "PXR|FBodyTrackingImuData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// time stamp of imu\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "time stamp of imu" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_temperature = { "temperature", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrBodyTrackingImu, temperature), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_temperature_MetaData), Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_temperature_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_GyroData_MetaData[] = {
		{ "Category", "PXR|FBodyTrackingImuData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// temperature of imu\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "temperature of imu" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_GyroData = { "GyroData", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrBodyTrackingImu, GyroData), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_GyroData_MetaData), Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_GyroData_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_AccData_MetaData[] = {
		{ "Category", "PXR|FBodyTrackingImuData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// gyroscope data, x,y,z\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "gyroscope data, x,y,z" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_AccData = { "AccData", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrBodyTrackingImu, AccData), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_AccData_MetaData), Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_AccData_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_MagData_MetaData[] = {
		{ "Category", "PXR|FBodyTrackingImuData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Accelerometer data, x,y,z\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Accelerometer data, x,y,z" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_MagData = { "MagData", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrBodyTrackingImu, MagData), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_MagData_MetaData), Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_MagData_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_TimeStamp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_temperature,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_GyroData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_AccData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewProp_MagData,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		&NewStructOps,
		"PxrBodyTrackingImu",
		Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::PropPointers),
		sizeof(FPxrBodyTrackingImu),
		alignof(FPxrBodyTrackingImu),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPxrBodyTrackingImu()
	{
		if (!Z_Registration_Info_UScriptStruct_PxrBodyTrackingImu.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PxrBodyTrackingImu.InnerSingleton, Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PxrBodyTrackingImu.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MotionTrackerConnectState;
class UScriptStruct* FMotionTrackerConnectState::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MotionTrackerConnectState.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MotionTrackerConnectState.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMotionTrackerConnectState, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("MotionTrackerConnectState"));
	}
	return Z_Registration_Info_UScriptStruct_MotionTrackerConnectState.OuterSingleton;
}
template<> PICOXRINPUT_API UScriptStruct* StaticStruct<FMotionTrackerConnectState>()
{
	return FMotionTrackerConnectState::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Num_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_Num;
		static const UECodeGen_Private::FBytePropertyParams NewProp_TrackerIDArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TrackerIDArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_TrackerIDArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMotionTrackerConnectState>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics::NewProp_Num_MetaData[] = {
		{ "Category", "PXR|FFitnessBandConnectState" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The number of trackers currently connected  */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The number of trackers currently connected" },
#endif
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics::NewProp_Num = { "Num", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMotionTrackerConnectState, Num), nullptr, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics::NewProp_Num_MetaData), Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics::NewProp_Num_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics::NewProp_TrackerIDArray_Inner = { "TrackerIDArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics::NewProp_TrackerIDArray_MetaData[] = {
		{ "Category", "PXR|FFitnessBandConnectState" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The Array of trackers ID currently connected */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Array of trackers ID currently connected" },
#endif
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics::NewProp_TrackerIDArray = { "TrackerIDArray", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMotionTrackerConnectState, TrackerIDArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics::NewProp_TrackerIDArray_MetaData), Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics::NewProp_TrackerIDArray_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics::NewProp_Num,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics::NewProp_TrackerIDArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics::NewProp_TrackerIDArray,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		&NewStructOps,
		"MotionTrackerConnectState",
		Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics::PropPointers),
		sizeof(FMotionTrackerConnectState),
		alignof(FMotionTrackerConnectState),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FMotionTrackerConnectState()
	{
		if (!Z_Registration_Info_UScriptStruct_MotionTrackerConnectState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MotionTrackerConnectState.InnerSingleton, Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_MotionTrackerConnectState.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PxrBodyTrackingTransform;
class UScriptStruct* FPxrBodyTrackingTransform::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PxrBodyTrackingTransform.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PxrBodyTrackingTransform.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPxrBodyTrackingTransform, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("PxrBodyTrackingTransform"));
	}
	return Z_Registration_Info_UScriptStruct_PxrBodyTrackingTransform.OuterSingleton;
}
template<> PICOXRINPUT_API UScriptStruct* StaticStruct<FPxrBodyTrackingTransform>()
{
	return FPxrBodyTrackingTransform::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TimeStamp_MetaData[];
#endif
		static const UECodeGen_Private::FInt64PropertyParams NewProp_TimeStamp;
		static const UECodeGen_Private::FBytePropertyParams NewProp_bone_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bone_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_bone;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LocalPose_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_LocalPose;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GlobalPose_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GlobalPose;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_velo_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_velo;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_acce_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_acce;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_wvelo_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_wvelo;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_wacce_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_wacce;
		static const UECodeGen_Private::FBytePropertyParams NewProp_bodyAction_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bodyAction_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_bodyAction;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPxrBodyTrackingTransform>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_TimeStamp_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_TimeStamp = { "TimeStamp", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrBodyTrackingTransform, TimeStamp), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_TimeStamp_MetaData), Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_TimeStamp_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_bone_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_bone_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** bone name. if bone == NONE_ROLE, this bone is not calculated */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "bone name. if bone == NONE_ROLE, this bone is not calculated" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_bone = { "bone", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrBodyTrackingTransform, bone), Z_Construct_UEnum_PICOXRInput_EPxrBodyTrackerRole, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_bone_MetaData), Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_bone_MetaData) }; // 1636942506
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_LocalPose_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** bone local transform */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "bone local transform" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_LocalPose = { "LocalPose", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrBodyTrackingTransform, LocalPose), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_LocalPose_MetaData), Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_LocalPose_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_GlobalPose_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** bone Global transform */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "bone Global transform" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_GlobalPose = { "GlobalPose", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrBodyTrackingTransform, GlobalPose), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_GlobalPose_MetaData), Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_GlobalPose_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_velo_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** velocity of x,y,z */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "velocity of x,y,z" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_velo = { "velo", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrBodyTrackingTransform, velo), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_velo_MetaData), Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_velo_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_acce_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** acceleration of x,y,z */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "acceleration of x,y,z" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_acce = { "acce", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrBodyTrackingTransform, acce), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_acce_MetaData), Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_acce_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_wvelo_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** angular velocity of x,y,z */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "angular velocity of x,y,z" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_wvelo = { "wvelo", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrBodyTrackingTransform, wvelo), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_wvelo_MetaData), Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_wvelo_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_wacce_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** angular acceleration of x,y,z */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "angular acceleration of x,y,z" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_wacce = { "wacce", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrBodyTrackingTransform, wacce), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_wacce_MetaData), Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_wacce_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_bodyAction_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_bodyAction_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** multiple actions can be supported at the same time by means of OR BodyActionList */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "multiple actions can be supported at the same time by means of OR BodyActionList" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_bodyAction = { "bodyAction", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPxrBodyTrackingTransform, bodyAction), Z_Construct_UEnum_PICOXRHMD_EPxrBodyActionList, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_bodyAction_MetaData), Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_bodyAction_MetaData) }; // 2274122140
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_TimeStamp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_bone_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_bone,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_LocalPose,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_GlobalPose,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_velo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_acce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_wvelo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_wacce,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_bodyAction_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewProp_bodyAction,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		&NewStructOps,
		"PxrBodyTrackingTransform",
		Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::PropPointers),
		sizeof(FPxrBodyTrackingTransform),
		alignof(FPxrBodyTrackingTransform),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPxrBodyTrackingTransform()
	{
		if (!Z_Registration_Info_UScriptStruct_PxrBodyTrackingTransform.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PxrBodyTrackingTransform.InnerSingleton, Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PxrBodyTrackingTransform.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EBodyTrackingMode;
	static UEnum* EBodyTrackingMode_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EBodyTrackingMode.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EBodyTrackingMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRInput_EBodyTrackingMode, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("EBodyTrackingMode"));
		}
		return Z_Registration_Info_UEnum_EBodyTrackingMode.OuterSingleton;
	}
	template<> PICOXRINPUT_API UEnum* StaticEnum<EBodyTrackingMode>()
	{
		return EBodyTrackingMode_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRInput_EBodyTrackingMode_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRInput_EBodyTrackingMode_Statics::Enumerators[] = {
		{ "EBodyTrackingMode::BODY_TRACKING_MODE_1", (int64)EBodyTrackingMode::BODY_TRACKING_MODE_1 },
		{ "EBodyTrackingMode::BODY_TRACKING_MODE_2", (int64)EBodyTrackingMode::BODY_TRACKING_MODE_2 },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRInput_EBodyTrackingMode_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "BODY_TRACKING_MODE_1.DisplayName", "Body Tracking Mode 1" },
		{ "BODY_TRACKING_MODE_1.Name", "EBodyTrackingMode::BODY_TRACKING_MODE_1" },
		{ "BODY_TRACKING_MODE_1.ToolTip", "Leg Tracking (Tracker1.0)/Low latency Full-body (Tracker2.0)" },
		{ "BODY_TRACKING_MODE_2.DisplayName", "Body Tracking Mode 2" },
		{ "BODY_TRACKING_MODE_2.Name", "EBodyTrackingMode::BODY_TRACKING_MODE_2" },
		{ "BODY_TRACKING_MODE_2.ToolTip", "Full-body (Tracker1.0)/High Accuracy Full-body (Tracker2.0)" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRInput_EBodyTrackingMode_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		"EBodyTrackingMode",
		"EBodyTrackingMode",
		Z_Construct_UEnum_PICOXRInput_EBodyTrackingMode_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EBodyTrackingMode_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRInput_EBodyTrackingMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRInput_EBodyTrackingMode_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRInput_EBodyTrackingMode()
	{
		if (!Z_Registration_Info_UEnum_EBodyTrackingMode.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EBodyTrackingMode.InnerSingleton, Z_Construct_UEnum_PICOXRInput_EBodyTrackingMode_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EBodyTrackingMode.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_BodyTrackingBoneLength;
class UScriptStruct* FBodyTrackingBoneLength::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_BodyTrackingBoneLength.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_BodyTrackingBoneLength.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FBodyTrackingBoneLength, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("BodyTrackingBoneLength"));
	}
	return Z_Registration_Info_UScriptStruct_BodyTrackingBoneLength.OuterSingleton;
}
template<> PICOXRINPUT_API UScriptStruct* StaticStruct<FBodyTrackingBoneLength>()
{
	return FBodyTrackingBoneLength::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_headLen_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_headLen;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_neckLen_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_neckLen;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_torsoLen_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_torsoLen;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_hipLen_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_hipLen;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_upperLegLen_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_upperLegLen;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_lowerLegLen_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_lowerLegLen;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_footLen_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_footLen;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_shoulderLen_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_shoulderLen;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_upperArmLen_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_upperArmLen;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_lowerArmLen_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_lowerArmLen;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_handLen_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_handLen;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FBodyTrackingBoneLength>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_headLen_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_headLen = { "headLen", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBodyTrackingBoneLength, headLen), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_headLen_MetaData), Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_headLen_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_neckLen_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_neckLen = { "neckLen", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBodyTrackingBoneLength, neckLen), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_neckLen_MetaData), Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_neckLen_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_torsoLen_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_torsoLen = { "torsoLen", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBodyTrackingBoneLength, torsoLen), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_torsoLen_MetaData), Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_torsoLen_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_hipLen_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_hipLen = { "hipLen", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBodyTrackingBoneLength, hipLen), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_hipLen_MetaData), Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_hipLen_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_upperLegLen_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_upperLegLen = { "upperLegLen", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBodyTrackingBoneLength, upperLegLen), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_upperLegLen_MetaData), Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_upperLegLen_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_lowerLegLen_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_lowerLegLen = { "lowerLegLen", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBodyTrackingBoneLength, lowerLegLen), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_lowerLegLen_MetaData), Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_lowerLegLen_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_footLen_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_footLen = { "footLen", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBodyTrackingBoneLength, footLen), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_footLen_MetaData), Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_footLen_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_shoulderLen_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_shoulderLen = { "shoulderLen", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBodyTrackingBoneLength, shoulderLen), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_shoulderLen_MetaData), Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_shoulderLen_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_upperArmLen_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_upperArmLen = { "upperArmLen", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBodyTrackingBoneLength, upperArmLen), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_upperArmLen_MetaData), Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_upperArmLen_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_lowerArmLen_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_lowerArmLen = { "lowerArmLen", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBodyTrackingBoneLength, lowerArmLen), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_lowerArmLen_MetaData), Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_lowerArmLen_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_handLen_MetaData[] = {
		{ "Category", "PXR|BodyTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_handLen = { "handLen", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBodyTrackingBoneLength, handLen), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_handLen_MetaData), Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_handLen_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_headLen,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_neckLen,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_torsoLen,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_hipLen,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_upperLegLen,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_lowerLegLen,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_footLen,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_shoulderLen,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_upperArmLen,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_lowerArmLen,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewProp_handLen,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		&NewStructOps,
		"BodyTrackingBoneLength",
		Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::PropPointers),
		sizeof(FBodyTrackingBoneLength),
		alignof(FBodyTrackingBoneLength),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FBodyTrackingBoneLength()
	{
		if (!Z_Registration_Info_UScriptStruct_BodyTrackingBoneLength.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_BodyTrackingBoneLength.InnerSingleton, Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_BodyTrackingBoneLength.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AudioClipData;
class UScriptStruct* FAudioClipData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AudioClipData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AudioClipData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAudioClipData, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("AudioClipData"));
	}
	return Z_Registration_Info_UScriptStruct_AudioClipData.OuterSingleton;
}
template<> PICOXRINPUT_API UScriptStruct* StaticStruct<FAudioClipData>()
{
	return FAudioClipData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FAudioClipData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_delaytag_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_delaytag;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_slot_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_slot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_buffersize_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_buffersize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_sampleRate_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_sampleRate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_channelMask_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_channelMask;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bitrate_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_bitrate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAudioClipData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAudioClipData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAudioClipData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_delaytag_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_delaytag = { "delaytag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAudioClipData, delaytag), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_delaytag_MetaData), Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_delaytag_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_slot_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_slot = { "slot", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAudioClipData, slot), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_slot_MetaData), Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_slot_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_buffersize_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_buffersize = { "buffersize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAudioClipData, buffersize), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_buffersize_MetaData), Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_buffersize_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_sampleRate_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_sampleRate = { "sampleRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAudioClipData, sampleRate), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_sampleRate_MetaData), Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_sampleRate_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_channelMask_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_channelMask = { "channelMask", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAudioClipData, channelMask), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_channelMask_MetaData), Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_channelMask_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_bitrate_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_bitrate = { "bitrate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAudioClipData, bitrate), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_bitrate_MetaData), Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_bitrate_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAudioClipData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_delaytag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_slot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_buffersize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_sampleRate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_channelMask,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAudioClipData_Statics::NewProp_bitrate,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAudioClipData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		&NewStructOps,
		"AudioClipData",
		Z_Construct_UScriptStruct_FAudioClipData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAudioClipData_Statics::PropPointers),
		sizeof(FAudioClipData),
		alignof(FAudioClipData),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAudioClipData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAudioClipData_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAudioClipData_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FAudioClipData()
	{
		if (!Z_Registration_Info_UScriptStruct_AudioClipData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AudioClipData.InnerSingleton, Z_Construct_UScriptStruct_FAudioClipData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_AudioClipData.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PHFDataContent;
class UScriptStruct* FPHFDataContent::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PHFDataContent.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PHFDataContent.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPHFDataContent, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("PHFDataContent"));
	}
	return Z_Registration_Info_UScriptStruct_PHFDataContent.OuterSingleton;
}
template<> PICOXRINPUT_API UScriptStruct* StaticStruct<FPHFDataContent>()
{
	return FPHFDataContent::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPHFDataContent_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_data_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_data;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_size_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_size;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPHFDataContent_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPHFDataContent_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPHFDataContent>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPHFDataContent_Statics::NewProp_data_MetaData[] = {
		{ "Category", "PXR|FPHFDataContent" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPHFDataContent_Statics::NewProp_data = { "data", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPHFDataContent, data), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFDataContent_Statics::NewProp_data_MetaData), Z_Construct_UScriptStruct_FPHFDataContent_Statics::NewProp_data_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPHFDataContent_Statics::NewProp_size_MetaData[] = {
		{ "Category", "PXR|FPHFDataContent" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPHFDataContent_Statics::NewProp_size = { "size", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPHFDataContent, size), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFDataContent_Statics::NewProp_size_MetaData), Z_Construct_UScriptStruct_FPHFDataContent_Statics::NewProp_size_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPHFDataContent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPHFDataContent_Statics::NewProp_data,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPHFDataContent_Statics::NewProp_size,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPHFDataContent_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		&NewStructOps,
		"PHFDataContent",
		Z_Construct_UScriptStruct_FPHFDataContent_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFDataContent_Statics::PropPointers),
		sizeof(FPHFDataContent),
		alignof(FPHFDataContent),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFDataContent_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPHFDataContent_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFDataContent_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPHFDataContent()
	{
		if (!Z_Registration_Info_UScriptStruct_PHFDataContent.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PHFDataContent.InnerSingleton, Z_Construct_UScriptStruct_FPHFDataContent_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PHFDataContent.InnerSingleton;
	}

static_assert(std::is_polymorphic<FPHFData>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FPHFData cannot be polymorphic unless super FTableRowBase is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PHFData;
class UScriptStruct* FPHFData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PHFData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PHFData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPHFData, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("PHFData"));
	}
	return Z_Registration_Info_UScriptStruct_PHFData.OuterSingleton;
}
template<> PICOXRINPUT_API UScriptStruct* StaticStruct<FPHFData>()
{
	return FPHFData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPHFData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PHFDataContent_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_PHFDataContent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPHFData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPHFData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPHFData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPHFData_Statics::NewProp_PHFDataContent_MetaData[] = {
		{ "Category", "PXR|FPHFData" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPHFData_Statics::NewProp_PHFDataContent = { "PHFDataContent", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPHFData, PHFDataContent), Z_Construct_UScriptStruct_FPHFDataContent, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFData_Statics::NewProp_PHFDataContent_MetaData), Z_Construct_UScriptStruct_FPHFData_Statics::NewProp_PHFDataContent_MetaData) }; // 2671331017
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPHFData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPHFData_Statics::NewProp_PHFDataContent,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPHFData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRInput,
		Z_Construct_UScriptStruct_FTableRowBase,
		&NewStructOps,
		"PHFData",
		Z_Construct_UScriptStruct_FPHFData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFData_Statics::PropPointers),
		sizeof(FPHFData),
		alignof(FPHFData),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPHFData_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFData_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPHFData()
	{
		if (!Z_Registration_Info_UScriptStruct_PHFData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PHFData.InnerSingleton, Z_Construct_UScriptStruct_FPHFData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PHFData.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PHFJsonFrameData;
class UScriptStruct* FPHFJsonFrameData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PHFJsonFrameData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PHFJsonFrameData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPHFJsonFrameData, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("PHFJsonFrameData"));
	}
	return Z_Registration_Info_UScriptStruct_PHFJsonFrameData.OuterSingleton;
}
template<> PICOXRINPUT_API UScriptStruct* StaticStruct<FPHFJsonFrameData>()
{
	return FPHFJsonFrameData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_frameseq_MetaData[];
#endif
		static const UECodeGen_Private::FInt64PropertyParams NewProp_frameseq;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_play_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_play;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_frequency_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_frequency;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_loop_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_loop;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_gain_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_gain;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPHFJsonFrameData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_frameseq_MetaData[] = {
		{ "Category", "PXR|FPHFDataContent" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_frameseq = { "frameseq", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPHFJsonFrameData, frameseq), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_frameseq_MetaData), Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_frameseq_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_play_MetaData[] = {
		{ "Category", "PXR|FPHFDataContent" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_play = { "play", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPHFJsonFrameData, play), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_play_MetaData), Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_play_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_frequency_MetaData[] = {
		{ "Category", "PXR|FPHFDataContent" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_frequency = { "frequency", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPHFJsonFrameData, frequency), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_frequency_MetaData), Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_frequency_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_loop_MetaData[] = {
		{ "Category", "PXR|FPHFDataContent" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_loop = { "loop", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPHFJsonFrameData, loop), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_loop_MetaData), Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_loop_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_gain_MetaData[] = {
		{ "Category", "PXR|FPHFDataContent" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_gain = { "gain", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPHFJsonFrameData, gain), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_gain_MetaData), Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_gain_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_frameseq,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_play,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_frequency,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_loop,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewProp_gain,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRInput,
		nullptr,
		&NewStructOps,
		"PHFJsonFrameData",
		Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::PropPointers),
		sizeof(FPHFJsonFrameData),
		alignof(FPHFJsonFrameData),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPHFJsonFrameData()
	{
		if (!Z_Registration_Info_UScriptStruct_PHFJsonFrameData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PHFJsonFrameData.InnerSingleton, Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PHFJsonFrameData.InnerSingleton;
	}

static_assert(std::is_polymorphic<FPHFJsonData>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FPHFJsonData cannot be polymorphic unless super FTableRowBase is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PHFJsonData;
class UScriptStruct* FPHFJsonData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PHFJsonData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PHFJsonData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPHFJsonData, (UObject*)Z_Construct_UPackage__Script_PICOXRInput(), TEXT("PHFJsonData"));
	}
	return Z_Registration_Info_UScriptStruct_PHFJsonData.OuterSingleton;
}
template<> PICOXRINPUT_API UScriptStruct* StaticStruct<FPHFJsonData>()
{
	return FPHFJsonData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPHFJsonData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_phfVersion_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_phfVersion;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_frameDuration_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_frameDuration;
		static const UECodeGen_Private::FStructPropertyParams NewProp_patternData_L_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_patternData_L_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_patternData_L;
		static const UECodeGen_Private::FStructPropertyParams NewProp_patternData_R_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_patternData_R_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_patternData_R;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPHFJsonData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPHFJsonData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_Name_MetaData[] = {
		{ "Category", "PXR|FPHFData" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPHFJsonData, Name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_Name_MetaData), Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_Name_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_phfVersion_MetaData[] = {
		{ "Category", "PXR|FPHFData" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_phfVersion = { "phfVersion", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPHFJsonData, phfVersion), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_phfVersion_MetaData), Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_phfVersion_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_frameDuration_MetaData[] = {
		{ "Category", "PXR|FPHFData" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_frameDuration = { "frameDuration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPHFJsonData, frameDuration), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_frameDuration_MetaData), Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_frameDuration_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_patternData_L_Inner = { "patternData_L", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPHFJsonFrameData, METADATA_PARAMS(0, nullptr) }; // 4027228723
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_patternData_L_MetaData[] = {
		{ "Category", "PXR|FPHFData" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_patternData_L = { "patternData_L", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPHFJsonData, patternData_L), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_patternData_L_MetaData), Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_patternData_L_MetaData) }; // 4027228723
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_patternData_R_Inner = { "patternData_R", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPHFJsonFrameData, METADATA_PARAMS(0, nullptr) }; // 4027228723
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_patternData_R_MetaData[] = {
		{ "Category", "PXR|FPHFData" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_patternData_R = { "patternData_R", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPHFJsonData, patternData_R), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_patternData_R_MetaData), Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_patternData_R_MetaData) }; // 4027228723
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPHFJsonData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_phfVersion,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_frameDuration,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_patternData_L_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_patternData_L,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_patternData_R_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewProp_patternData_R,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPHFJsonData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRInput,
		Z_Construct_UScriptStruct_FTableRowBase,
		&NewStructOps,
		"PHFJsonData",
		Z_Construct_UScriptStruct_FPHFJsonData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFJsonData_Statics::PropPointers),
		sizeof(FPHFJsonData),
		alignof(FPHFJsonData),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFJsonData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPHFJsonData_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPHFJsonData_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPHFJsonData()
	{
		if (!Z_Registration_Info_UScriptStruct_PHFJsonData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PHFJsonData.InnerSingleton, Z_Construct_UScriptStruct_FPHFJsonData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PHFJsonData.InnerSingleton;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_SetBodyTrackingBoneLength)
	{
		P_GET_STRUCT_REF(FBodyTrackingBoneLength,Z_Param_Out_BoneLength);
		P_GET_PROPERTY(FIntProperty,Z_Param_OtherMode);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_SetBodyTrackingBoneLength(Z_Param_Out_BoneLength,Z_Param_OtherMode);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_SetBodyTrackingMode)
	{
		P_GET_ENUM(EBodyTrackingMode,Z_Param_Mode);
		P_GET_PROPERTY(FIntProperty,Z_Param_OtherMode);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_SetBodyTrackingMode(EBodyTrackingMode(Z_Param_Mode),Z_Param_OtherMode);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_GetMotionTrackerCalibState)
	{
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_CalibrateState);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_GetMotionTrackerCalibState(Z_Param_Out_CalibrateState);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_GetMotionTrackerBattery)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_TrackerId);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_Battery);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_GetMotionTrackerBattery(Z_Param_TrackerId,Z_Param_Out_Battery);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_GetMotionTrackerConnectStateWithId)
	{
		P_GET_STRUCT_REF(FMotionTrackerConnectState,Z_Param_Out_State);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_GetMotionTrackerConnectStateWithId(Z_Param_Out_State);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_GetBodyTrackingPoseByRole)
	{
		P_GET_ENUM(EPxrBodyTrackerRole,Z_Param_RoleType);
		P_GET_STRUCT_REF(FPxrBodyTrackingTransform,Z_Param_Out_RoleBodyTrackingData);
		P_GET_PROPERTY(FFloatProperty,Z_Param_WorldToMetersScale);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_GetBodyTrackingPoseByRole(EPxrBodyTrackerRole(Z_Param_RoleType),Z_Param_Out_RoleBodyTrackingData,Z_Param_WorldToMetersScale);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_GetBodyTrackingPose)
	{
		P_GET_TARRAY_REF(FPxrBodyTrackingTransform,Z_Param_Out_BodyTrackingData);
		P_GET_PROPERTY(FFloatProperty,Z_Param_WorldToMetersScale);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_GetBodyTrackingPose(Z_Param_Out_BodyTrackingData,Z_Param_WorldToMetersScale);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_SetBodyTrackingStaticCalibState)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_calibstate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_SetBodyTrackingStaticCalibState(Z_Param_calibstate);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_GetPHFHapticSpeed)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_SourceID);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Speed);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_GetPHFHapticSpeed(Z_Param_SourceID,Z_Param_Out_Speed);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_SetPHFHapticSpeed)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_SourceID);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Speed);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_SetPHFHapticSpeed(Z_Param_SourceID,Z_Param_Speed);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_GetCurrentFrameSequence)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_SourceID);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_FrameSequence);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_GetCurrentFrameSequence(Z_Param_SourceID,Z_Param_Out_FrameSequence);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_WriteHapticStream)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_SourceID);
		P_GET_STRUCT_REF(FPHFJsonData,Z_Param_Out_frames);
		P_GET_PROPERTY(FIntProperty,Z_Param_From);
		P_GET_PROPERTY(FIntProperty,Z_Param_NumFrames);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_WriteHapticStream(Z_Param_SourceID,Z_Param_Out_frames,Z_Param_From,Z_Param_NumFrames);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_StopPHFHaptic)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_SourceID);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_StopPHFHaptic(Z_Param_SourceID);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_StartPHFHaptic)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_SourceID);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_StartPHFHaptic(Z_Param_SourceID);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_RemovePHFHaptic)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_SourceID);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_RemovePHFHaptic(Z_Param_SourceID);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_CreateHapticStream)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_PHFVersion);
		P_GET_PROPERTY(FIntProperty,Z_Param_FrameDurationMs);
		P_GET_PROPERTY(FIntProperty,Z_Param_Slot);
		P_GET_PROPERTY(FIntProperty,Z_Param_Reversal);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Amp);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Speed);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_SourceID);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_CreateHapticStream(Z_Param_PHFVersion,Z_Param_FrameDurationMs,Z_Param_Slot,Z_Param_Reversal,Z_Param_Amp,Z_Param_Speed,Z_Param_Out_SourceID);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_UpdateVibrateParams)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_SourceID);
		P_GET_ENUM(EPICOXRVibrateController,Z_Param_slot);
		P_GET_ENUM(EPICOXRChannelFlip,Z_Param_slotConfig);
		P_GET_PROPERTY(FFloatProperty,Z_Param_AmpValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_UpdateVibrateParams(Z_Param_SourceID,EPICOXRVibrateController(Z_Param_slot),EPICOXRChannelFlip(Z_Param_slotConfig),Z_Param_AmpValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_ResumeVibrate)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_SourceID);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_ResumeVibrate(Z_Param_SourceID);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_PauseVibrate)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_SourceID);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_PauseVibrate(Z_Param_SourceID);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_StartVibrateByPHF)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_DataName);
		P_GET_ENUM(EPICOXRVibrateController,Z_Param_slot);
		P_GET_ENUM(EPICOXRChannelFlip,Z_Param_slotConfig);
		P_GET_PROPERTY(FFloatProperty,Z_Param_ampValue);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_SourceID);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_StartVibrateByPHF(Z_Param_DataName,EPICOXRVibrateController(Z_Param_slot),EPICOXRChannelFlip(Z_Param_slotConfig),Z_Param_ampValue,Z_Param_Out_SourceID);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execGetActiveInputDevice)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EPICOXRActiveInputDevice*)Z_Param__Result=UPICOXRInputFunctionLibrary::GetActiveInputDevice();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execIsHandTrackingEnabled)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::IsHandTrackingEnabled();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execGetPinchStrength)
	{
		P_GET_ENUM(EPICOXRHandType,Z_Param_DeviceHand);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=UPICOXRInputFunctionLibrary::GetPinchStrength(EPICOXRHandType(Z_Param_DeviceHand));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execGetHandScale)
	{
		P_GET_ENUM(EPICOXRHandType,Z_Param_DeviceHand);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=UPICOXRInputFunctionLibrary::GetHandScale(EPICOXRHandType(Z_Param_DeviceHand));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execGetTrackingConfidence)
	{
		P_GET_ENUM(EPICOXRHandType,Z_Param_DeviceHand);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EPICOXRHandTrackingConfidence*)Z_Param__Result=UPICOXRInputFunctionLibrary::GetTrackingConfidence(EPICOXRHandType(Z_Param_DeviceHand));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execIsPinchValid)
	{
		P_GET_ENUM(EPICOXRHandType,Z_Param_DeviceHand);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::IsPinchValid(EPICOXRHandType(Z_Param_DeviceHand));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execIsRayValid)
	{
		P_GET_ENUM(EPICOXRHandType,Z_Param_DeviceHand);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::IsRayValid(EPICOXRHandType(Z_Param_DeviceHand));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execIsComputed)
	{
		P_GET_ENUM(EPICOXRHandType,Z_Param_DeviceHand);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::IsComputed(EPICOXRHandType(Z_Param_DeviceHand));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execGetRayPose)
	{
		P_GET_ENUM(EPICOXRHandType,Z_Param_DeviceHand);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FTransform*)Z_Param__Result=UPICOXRInputFunctionLibrary::GetRayPose(EPICOXRHandType(Z_Param_DeviceHand));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execGetHandRootPose)
	{
		P_GET_ENUM(EPICOXRHandType,Z_Param_DeviceHand);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FTransform*)Z_Param__Result=UPICOXRInputFunctionLibrary::GetHandRootPose(EPICOXRHandType(Z_Param_DeviceHand));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execIsBonePositionTracked)
	{
		P_GET_ENUM(EPICOXRHandType,Z_Param_DeviceHand);
		P_GET_ENUM(EPICOXRHandJoint,Z_Param_Key);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::IsBonePositionTracked(EPICOXRHandType(Z_Param_DeviceHand),EPICOXRHandJoint(Z_Param_Key));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execIsBoneOrientationTracked)
	{
		P_GET_ENUM(EPICOXRHandType,Z_Param_DeviceHand);
		P_GET_ENUM(EPICOXRHandJoint,Z_Param_Key);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::IsBoneOrientationTracked(EPICOXRHandType(Z_Param_DeviceHand),EPICOXRHandJoint(Z_Param_Key));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execIsBonePositionValid)
	{
		P_GET_ENUM(EPICOXRHandType,Z_Param_DeviceHand);
		P_GET_ENUM(EPICOXRHandJoint,Z_Param_Key);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::IsBonePositionValid(EPICOXRHandType(Z_Param_DeviceHand),EPICOXRHandJoint(Z_Param_Key));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execIsBoneOrientationValid)
	{
		P_GET_ENUM(EPICOXRHandType,Z_Param_DeviceHand);
		P_GET_ENUM(EPICOXRHandJoint,Z_Param_Key);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::IsBoneOrientationValid(EPICOXRHandType(Z_Param_DeviceHand),EPICOXRHandJoint(Z_Param_Key));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execGetBoneRadii)
	{
		P_GET_ENUM(EPICOXRHandType,Z_Param_DeviceHand);
		P_GET_ENUM(EPICOXRHandJoint,Z_Param_Key);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=UPICOXRInputFunctionLibrary::GetBoneRadii(EPICOXRHandType(Z_Param_DeviceHand),EPICOXRHandJoint(Z_Param_Key));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execGetBoneLocation)
	{
		P_GET_ENUM(EPICOXRHandType,Z_Param_DeviceHand);
		P_GET_ENUM(EPICOXRHandJoint,Z_Param_Key);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=UPICOXRInputFunctionLibrary::GetBoneLocation(EPICOXRHandType(Z_Param_DeviceHand),EPICOXRHandJoint(Z_Param_Key));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execGetBoneRotation)
	{
		P_GET_ENUM(EPICOXRHandType,Z_Param_DeviceHand);
		P_GET_ENUM(EPICOXRHandJoint,Z_Param_Key);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FQuat*)Z_Param__Result=UPICOXRInputFunctionLibrary::GetBoneRotation(EPICOXRHandType(Z_Param_DeviceHand),EPICOXRHandJoint(Z_Param_Key));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_ClearVibrateByCache)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_SourceId);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_ClearVibrateByCache(Z_Param_SourceId);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_StartVibrateByCache)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_SourceId);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_StartVibrateByCache(Z_Param_SourceId);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_SaveVibrateByCache)
	{
		P_GET_OBJECT(USoundWave,Z_Param_InSoundWave);
		P_GET_ENUM(EPICOXRVibrateController,Z_Param_slot);
		P_GET_ENUM(EPICOXRChannelFlip,Z_Param_slotConfig);
		P_GET_ENUM(EPICOXRCacheConfig,Z_Param_enableV);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_SourceId);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_SaveVibrateByCache(Z_Param_InSoundWave,EPICOXRVibrateController(Z_Param_slot),EPICOXRChannelFlip(Z_Param_slotConfig),EPICOXRCacheConfig(Z_Param_enableV),Z_Param_Out_SourceId);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_SetControllerEnableKey)
	{
		P_GET_UBOOL(Z_Param_isEnable);
		P_GET_ENUM(EPxrControllerKeyMap,Z_Param_Key);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_SetControllerEnableKey(Z_Param_isEnable,EPxrControllerKeyMap(Z_Param_Key));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_StartVibrateBySharem)
	{
		P_GET_OBJECT(USoundWave,Z_Param_InSoundWave);
		P_GET_ENUM(EPICOXRVibrateController,Z_Param_slot);
		P_GET_ENUM(EPICOXRChannelFlip,Z_Param_slotConfig);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_SourceId);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_StartVibrateBySharem(Z_Param_InSoundWave,EPICOXRVibrateController(Z_Param_slot),EPICOXRChannelFlip(Z_Param_slotConfig),Z_Param_Out_SourceId);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_SetControllerVibrationEvent)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_deviceID);
		P_GET_PROPERTY(FIntProperty,Z_Param_frequency);
		P_GET_PROPERTY(FFloatProperty,Z_Param_strength);
		P_GET_PROPERTY(FIntProperty,Z_Param_time);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_SetControllerVibrationEvent(Z_Param_deviceID,Z_Param_frequency,Z_Param_strength,Z_Param_time);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_StopControllerVCMotor)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_clientId);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_StopControllerVCMotor(Z_Param_clientId);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_SetControllerAmp)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_mode);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_SetControllerAmp(Z_Param_mode);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_StartControllerVCMotor)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_file);
		P_GET_ENUM(EPICOXRVibrateController,Z_Param_slot);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_StartControllerVCMotor(Z_Param_file,EPICOXRVibrateController(Z_Param_slot));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_GetControllerPredictedLocationAndRotation)
	{
		P_GET_ENUM(EControllerHand,Z_Param_DeviceHand);
		P_GET_PROPERTY(FFloatProperty,Z_Param_PredictedTime);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_OutLocation);
		P_GET_STRUCT_REF(FRotator,Z_Param_Out_OutRotation);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_GetControllerPredictedLocationAndRotation(EControllerHand(Z_Param_DeviceHand),Z_Param_PredictedTime,Z_Param_Out_OutLocation,Z_Param_Out_OutRotation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_SetControllerOriginOffset)
	{
		P_GET_ENUM(EPICOXRControllerType,Z_Param_Controller);
		P_GET_STRUCT(FVector,Z_Param_Offset);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPICOXRInputFunctionLibrary::PXR_SetControllerOriginOffset(EPICOXRControllerType(Z_Param_Controller),Z_Param_Offset);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_GetControllerEnableHomekey)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_GetControllerEnableHomekey();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_GetHandedness)
	{
		P_GET_ENUM_REF(EPICOXRHandedness,Z_Param_Out_Handedness);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_GetHandedness((EPICOXRHandedness&)(Z_Param_Out_Handedness));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_SetArmModelParameters)
	{
		P_GET_ENUM(EPICOXRGazeBehavior,Z_Param_GazeType);
		P_GET_ENUM(EPICOXRArmModelJoint,Z_Param_ArmJoint);
		P_GET_PROPERTY(FFloatProperty,Z_Param_ElbowHeight);
		P_GET_PROPERTY(FFloatProperty,Z_Param_ElbowDepth);
		P_GET_PROPERTY(FFloatProperty,Z_Param_PointerTiltAngle);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_SetArmModelParameters(EPICOXRGazeBehavior(Z_Param_GazeType),EPICOXRArmModelJoint(Z_Param_ArmJoint),Z_Param_ElbowHeight,Z_Param_ElbowDepth,Z_Param_PointerTiltAngle);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_ResetController)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Device);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_ResetController(Z_Param_Device);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_GetControllerDeviceType)
	{
		P_GET_ENUM_REF(EPICOXRControllerDeviceType,Z_Param_Out_ControllerType);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPICOXRInputFunctionLibrary::PXR_GetControllerDeviceType((EPICOXRControllerDeviceType&)(Z_Param_Out_ControllerType));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_VibrateController)
	{
		P_GET_ENUM(EPICOXRControllerType,Z_Param_ControllerType);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Strength);
		P_GET_PROPERTY(FIntProperty,Z_Param_Time);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_VibrateController(EPICOXRControllerType(Z_Param_ControllerType),Z_Param_Strength,Z_Param_Time);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_GetControllerLinearVelocity)
	{
		P_GET_ENUM(EPICOXRControllerType,Z_Param_ControllerType);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_LinearVelocity);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_GetControllerLinearVelocity(EPICOXRControllerType(Z_Param_ControllerType),Z_Param_Out_LinearVelocity);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_GetControllerAcceleration)
	{
		P_GET_ENUM(EPICOXRControllerType,Z_Param_ControllerType);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Acceleration);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_GetControllerAcceleration(EPICOXRControllerType(Z_Param_ControllerType),Z_Param_Out_Acceleration);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_GetControllerAngularVelocity)
	{
		P_GET_ENUM(EPICOXRControllerType,Z_Param_ControllerType);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_AngularVelocity);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_GetControllerAngularVelocity(EPICOXRControllerType(Z_Param_ControllerType),Z_Param_Out_AngularVelocity);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_SetMainControllerHandle)
	{
		P_GET_ENUM(EPICOXRHandedness,Z_Param_Handedness);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_SetMainControllerHandle(EPICOXRHandedness(Z_Param_Handedness));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_GetMainControllerHandle)
	{
		P_GET_ENUM_REF(EPICOXRHandedness,Z_Param_Out_Handedness);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_GetMainControllerHandle((EPICOXRHandedness&)(Z_Param_Out_Handedness));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_GetControllerConnectionState)
	{
		P_GET_ENUM(EPICOXRControllerType,Z_Param_ControllerType);
		P_GET_UBOOL_REF(Z_Param_Out_Status);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_GetControllerConnectionState(EPICOXRControllerType(Z_Param_ControllerType),Z_Param_Out_Status);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOXRInputFunctionLibrary::execPXR_GetControllerPower)
	{
		P_GET_ENUM(EPICOXRControllerType,Z_Param_ControllerType);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_Power);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPICOXRInputFunctionLibrary::PXR_GetControllerPower(EPICOXRControllerType(Z_Param_ControllerType),Z_Param_Out_Power);
		P_NATIVE_END;
	}
	void UPICOXRInputFunctionLibrary::StaticRegisterNativesUPICOXRInputFunctionLibrary()
	{
		UClass* Class = UPICOXRInputFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetActiveInputDevice", &UPICOXRInputFunctionLibrary::execGetActiveInputDevice },
			{ "GetBoneLocation", &UPICOXRInputFunctionLibrary::execGetBoneLocation },
			{ "GetBoneRadii", &UPICOXRInputFunctionLibrary::execGetBoneRadii },
			{ "GetBoneRotation", &UPICOXRInputFunctionLibrary::execGetBoneRotation },
			{ "GetHandRootPose", &UPICOXRInputFunctionLibrary::execGetHandRootPose },
			{ "GetHandScale", &UPICOXRInputFunctionLibrary::execGetHandScale },
			{ "GetPinchStrength", &UPICOXRInputFunctionLibrary::execGetPinchStrength },
			{ "GetRayPose", &UPICOXRInputFunctionLibrary::execGetRayPose },
			{ "GetTrackingConfidence", &UPICOXRInputFunctionLibrary::execGetTrackingConfidence },
			{ "IsBoneOrientationTracked", &UPICOXRInputFunctionLibrary::execIsBoneOrientationTracked },
			{ "IsBoneOrientationValid", &UPICOXRInputFunctionLibrary::execIsBoneOrientationValid },
			{ "IsBonePositionTracked", &UPICOXRInputFunctionLibrary::execIsBonePositionTracked },
			{ "IsBonePositionValid", &UPICOXRInputFunctionLibrary::execIsBonePositionValid },
			{ "IsComputed", &UPICOXRInputFunctionLibrary::execIsComputed },
			{ "IsHandTrackingEnabled", &UPICOXRInputFunctionLibrary::execIsHandTrackingEnabled },
			{ "IsPinchValid", &UPICOXRInputFunctionLibrary::execIsPinchValid },
			{ "IsRayValid", &UPICOXRInputFunctionLibrary::execIsRayValid },
			{ "PXR_ClearVibrateByCache", &UPICOXRInputFunctionLibrary::execPXR_ClearVibrateByCache },
			{ "PXR_CreateHapticStream", &UPICOXRInputFunctionLibrary::execPXR_CreateHapticStream },
			{ "PXR_GetBodyTrackingPose", &UPICOXRInputFunctionLibrary::execPXR_GetBodyTrackingPose },
			{ "PXR_GetBodyTrackingPoseByRole", &UPICOXRInputFunctionLibrary::execPXR_GetBodyTrackingPoseByRole },
			{ "PXR_GetControllerAcceleration", &UPICOXRInputFunctionLibrary::execPXR_GetControllerAcceleration },
			{ "PXR_GetControllerAngularVelocity", &UPICOXRInputFunctionLibrary::execPXR_GetControllerAngularVelocity },
			{ "PXR_GetControllerConnectionState", &UPICOXRInputFunctionLibrary::execPXR_GetControllerConnectionState },
			{ "PXR_GetControllerDeviceType", &UPICOXRInputFunctionLibrary::execPXR_GetControllerDeviceType },
			{ "PXR_GetControllerEnableHomekey", &UPICOXRInputFunctionLibrary::execPXR_GetControllerEnableHomekey },
			{ "PXR_GetControllerLinearVelocity", &UPICOXRInputFunctionLibrary::execPXR_GetControllerLinearVelocity },
			{ "PXR_GetControllerPower", &UPICOXRInputFunctionLibrary::execPXR_GetControllerPower },
			{ "PXR_GetControllerPredictedLocationAndRotation", &UPICOXRInputFunctionLibrary::execPXR_GetControllerPredictedLocationAndRotation },
			{ "PXR_GetCurrentFrameSequence", &UPICOXRInputFunctionLibrary::execPXR_GetCurrentFrameSequence },
			{ "PXR_GetHandedness", &UPICOXRInputFunctionLibrary::execPXR_GetHandedness },
			{ "PXR_GetMainControllerHandle", &UPICOXRInputFunctionLibrary::execPXR_GetMainControllerHandle },
			{ "PXR_GetMotionTrackerBattery", &UPICOXRInputFunctionLibrary::execPXR_GetMotionTrackerBattery },
			{ "PXR_GetMotionTrackerCalibState", &UPICOXRInputFunctionLibrary::execPXR_GetMotionTrackerCalibState },
			{ "PXR_GetMotionTrackerConnectStateWithId", &UPICOXRInputFunctionLibrary::execPXR_GetMotionTrackerConnectStateWithId },
			{ "PXR_GetPHFHapticSpeed", &UPICOXRInputFunctionLibrary::execPXR_GetPHFHapticSpeed },
			{ "PXR_PauseVibrate", &UPICOXRInputFunctionLibrary::execPXR_PauseVibrate },
			{ "PXR_RemovePHFHaptic", &UPICOXRInputFunctionLibrary::execPXR_RemovePHFHaptic },
			{ "PXR_ResetController", &UPICOXRInputFunctionLibrary::execPXR_ResetController },
			{ "PXR_ResumeVibrate", &UPICOXRInputFunctionLibrary::execPXR_ResumeVibrate },
			{ "PXR_SaveVibrateByCache", &UPICOXRInputFunctionLibrary::execPXR_SaveVibrateByCache },
			{ "PXR_SetArmModelParameters", &UPICOXRInputFunctionLibrary::execPXR_SetArmModelParameters },
			{ "PXR_SetBodyTrackingBoneLength", &UPICOXRInputFunctionLibrary::execPXR_SetBodyTrackingBoneLength },
			{ "PXR_SetBodyTrackingMode", &UPICOXRInputFunctionLibrary::execPXR_SetBodyTrackingMode },
			{ "PXR_SetBodyTrackingStaticCalibState", &UPICOXRInputFunctionLibrary::execPXR_SetBodyTrackingStaticCalibState },
			{ "PXR_SetControllerAmp", &UPICOXRInputFunctionLibrary::execPXR_SetControllerAmp },
			{ "PXR_SetControllerEnableKey", &UPICOXRInputFunctionLibrary::execPXR_SetControllerEnableKey },
			{ "PXR_SetControllerOriginOffset", &UPICOXRInputFunctionLibrary::execPXR_SetControllerOriginOffset },
			{ "PXR_SetControllerVibrationEvent", &UPICOXRInputFunctionLibrary::execPXR_SetControllerVibrationEvent },
			{ "PXR_SetMainControllerHandle", &UPICOXRInputFunctionLibrary::execPXR_SetMainControllerHandle },
			{ "PXR_SetPHFHapticSpeed", &UPICOXRInputFunctionLibrary::execPXR_SetPHFHapticSpeed },
			{ "PXR_StartControllerVCMotor", &UPICOXRInputFunctionLibrary::execPXR_StartControllerVCMotor },
			{ "PXR_StartPHFHaptic", &UPICOXRInputFunctionLibrary::execPXR_StartPHFHaptic },
			{ "PXR_StartVibrateByCache", &UPICOXRInputFunctionLibrary::execPXR_StartVibrateByCache },
			{ "PXR_StartVibrateByPHF", &UPICOXRInputFunctionLibrary::execPXR_StartVibrateByPHF },
			{ "PXR_StartVibrateBySharem", &UPICOXRInputFunctionLibrary::execPXR_StartVibrateBySharem },
			{ "PXR_StopControllerVCMotor", &UPICOXRInputFunctionLibrary::execPXR_StopControllerVCMotor },
			{ "PXR_StopPHFHaptic", &UPICOXRInputFunctionLibrary::execPXR_StopPHFHaptic },
			{ "PXR_UpdateVibrateParams", &UPICOXRInputFunctionLibrary::execPXR_UpdateVibrateParams },
			{ "PXR_VibrateController", &UPICOXRInputFunctionLibrary::execPXR_VibrateController },
			{ "PXR_WriteHapticStream", &UPICOXRInputFunctionLibrary::execPXR_WriteHapticStream },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetActiveInputDevice_Statics
	{
		struct PICOXRInputFunctionLibrary_eventGetActiveInputDevice_Parms
		{
			EPICOXRActiveInputDevice ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetActiveInputDevice_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetActiveInputDevice_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventGetActiveInputDevice_Parms, ReturnValue), Z_Construct_UEnum_PICOXRInput_EPICOXRActiveInputDevice, METADATA_PARAMS(0, nullptr) }; // 1632396129
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetActiveInputDevice_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetActiveInputDevice_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetActiveInputDevice_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetActiveInputDevice_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Get the active input device\n     */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the active input device" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetActiveInputDevice_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "GetActiveInputDevice", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetActiveInputDevice_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetActiveInputDevice_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetActiveInputDevice_Statics::PICOXRInputFunctionLibrary_eventGetActiveInputDevice_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetActiveInputDevice_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetActiveInputDevice_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetActiveInputDevice_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetActiveInputDevice_Statics::PICOXRInputFunctionLibrary_eventGetActiveInputDevice_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetActiveInputDevice()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetActiveInputDevice_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics
	{
		struct PICOXRInputFunctionLibrary_eventGetBoneLocation_Parms
		{
			EPICOXRHandType DeviceHand;
			EPICOXRHandJoint Key;
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeviceHand_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Key_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Key_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Key;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::NewProp_DeviceHand_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventGetBoneLocation_Parms, DeviceHand), Z_Construct_UEnum_PICOXRInput_EPICOXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::NewProp_DeviceHand_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::NewProp_DeviceHand_MetaData) }; // 2963561890
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::NewProp_Key_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::NewProp_Key_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventGetBoneLocation_Parms, Key), Z_Construct_UEnum_PICOXRInput_EPICOXRHandJoint, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::NewProp_Key_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::NewProp_Key_MetaData) }; // 2824206454
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventGetBoneLocation_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::NewProp_DeviceHand_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::NewProp_DeviceHand,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::NewProp_Key_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::NewProp_Key,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Returns the position of the skeletal node for the specified hand component.</summary>\n/// <param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n/// <ul>\n/// <li>`None`: No identification is performed, and the return value is always `false`</li>\n/// <li>`Left`: Left hand</li>\n/// <li>`Right`: Right hand</li>\n/// </ul>\n/// </param>\n/// <param name =\"Key\">(In) EPicoXRHandJoint, specifies which skeletal nodes to identify.\n/// <ul>\n/// <li>`Palm`</li>\n/// <li>`Wrist`</li>\n/// <li>`ThumbMetacarpal`</li>\n/// <li>`ThumbProximal`</li>\n/// <li>`ThumbDistal`</li>\n/// <li>`ThumbTip`</li>\n/// <li>`IndexMetacarpal`</li>\n/// <li>`IndexProximal`</li>\n/// <li>`IndexIntermediate`</li>\n/// <li>`IndexDistal`</li>\n/// <li>`IndexTip`</li>\n/// <li>`MiddleMetacarpal`</li>\n/// <li>`MiddleProximal`</li>\n/// <li>`MiddleIntermediate`</li>\n/// <li>`MiddleDistal`</li>\n/// <li>`MiddleTip`</li>\n/// <li>`RingMetacarpal`</li>\n/// <li>`RingProximal`</li>\n/// <li>`RingIntermediate`</li>\n/// <li>`RingDistal`</li>\n/// <li>`RingTip`</li>\n/// <li>`LittleMetacarpal`</li>\n/// <li>`LittleProximal`</li>\n/// <li>`LittleIntermediate`</li>\n/// <li>`LittleDistal`</li>\n/// <li>`LittleTip`</li>\n/// </ul>\n/// </param>\n/// <returns> FVector, the coordinates of the skeletal node. </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Returns the position of the skeletal node for the specified hand component.</summary>\n<param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n<ul>\n<li>`None`: No identification is performed, and the return value is always `false`</li>\n<li>`Left`: Left hand</li>\n<li>`Right`: Right hand</li>\n</ul>\n</param>\n<param name =\"Key\">(In) EPicoXRHandJoint, specifies which skeletal nodes to identify.\n<ul>\n<li>`Palm`</li>\n<li>`Wrist`</li>\n<li>`ThumbMetacarpal`</li>\n<li>`ThumbProximal`</li>\n<li>`ThumbDistal`</li>\n<li>`ThumbTip`</li>\n<li>`IndexMetacarpal`</li>\n<li>`IndexProximal`</li>\n<li>`IndexIntermediate`</li>\n<li>`IndexDistal`</li>\n<li>`IndexTip`</li>\n<li>`MiddleMetacarpal`</li>\n<li>`MiddleProximal`</li>\n<li>`MiddleIntermediate`</li>\n<li>`MiddleDistal`</li>\n<li>`MiddleTip`</li>\n<li>`RingMetacarpal`</li>\n<li>`RingProximal`</li>\n<li>`RingIntermediate`</li>\n<li>`RingDistal`</li>\n<li>`RingTip`</li>\n<li>`LittleMetacarpal`</li>\n<li>`LittleProximal`</li>\n<li>`LittleIntermediate`</li>\n<li>`LittleDistal`</li>\n<li>`LittleTip`</li>\n</ul>\n</param>\n<returns> FVector, the coordinates of the skeletal node. </returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "GetBoneLocation", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::PICOXRInputFunctionLibrary_eventGetBoneLocation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::PICOXRInputFunctionLibrary_eventGetBoneLocation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics
	{
		struct PICOXRInputFunctionLibrary_eventGetBoneRadii_Parms
		{
			EPICOXRHandType DeviceHand;
			EPICOXRHandJoint Key;
			float ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeviceHand_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Key_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Key_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Key;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::NewProp_DeviceHand_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventGetBoneRadii_Parms, DeviceHand), Z_Construct_UEnum_PICOXRInput_EPICOXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::NewProp_DeviceHand_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::NewProp_DeviceHand_MetaData) }; // 2963561890
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::NewProp_Key_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::NewProp_Key_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventGetBoneRadii_Parms, Key), Z_Construct_UEnum_PICOXRInput_EPICOXRHandJoint, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::NewProp_Key_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::NewProp_Key_MetaData) }; // 2824206454
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventGetBoneRadii_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::NewProp_DeviceHand_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::NewProp_DeviceHand,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::NewProp_Key_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::NewProp_Key,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Returns the radius of the skeletal node for the specified hand component.</summary>\n/// <param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n/// <ul>\n/// <li>`None`: No identification is performed, and the return value is always `false`</li>\n/// <li>`Left`: Left hand</li>\n/// <li>`Right`: Right hand</li>\n/// </ul>\n/// </param>\n/// <param name =\"Key\">(In) EPicoXRHandJoint, specifies which skeletal nodes to identify.\n/// <ul>\n/// <li>`Palm`</li>\n/// <li>`Wrist`</li>\n/// <li>`ThumbMetacarpal`</li>\n/// <li>`ThumbProximal`</li>\n/// <li>`ThumbDistal`</li>\n/// <li>`ThumbTip`</li>\n/// <li>`IndexMetacarpal`</li>\n/// <li>`IndexProximal`</li>\n/// <li>`IndexIntermediate`</li>\n/// <li>`IndexDistal`</li>\n/// <li>`IndexTip`</li>\n/// <li>`MiddleMetacarpal`</li>\n/// <li>`MiddleProximal`</li>\n/// <li>`MiddleIntermediate`</li>\n/// <li>`MiddleDistal`</li>\n/// <li>`MiddleTip`</li>\n/// <li>`RingMetacarpal`</li>\n/// <li>`RingProximal`</li>\n/// <li>`RingIntermediate`</li>\n/// <li>`RingDistal`</li>\n/// <li>`RingTip`</li>\n/// <li>`LittleMetacarpal`</li>\n/// <li>`LittleProximal`</li>\n/// <li>`LittleIntermediate`</li>\n/// <li>`LittleDistal`</li>\n/// <li>`LittleTip`</li>\n/// </ul>\n/// </param>\n/// <returns> FVector, the coordinates of the skeletal node. </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Returns the radius of the skeletal node for the specified hand component.</summary>\n<param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n<ul>\n<li>`None`: No identification is performed, and the return value is always `false`</li>\n<li>`Left`: Left hand</li>\n<li>`Right`: Right hand</li>\n</ul>\n</param>\n<param name =\"Key\">(In) EPicoXRHandJoint, specifies which skeletal nodes to identify.\n<ul>\n<li>`Palm`</li>\n<li>`Wrist`</li>\n<li>`ThumbMetacarpal`</li>\n<li>`ThumbProximal`</li>\n<li>`ThumbDistal`</li>\n<li>`ThumbTip`</li>\n<li>`IndexMetacarpal`</li>\n<li>`IndexProximal`</li>\n<li>`IndexIntermediate`</li>\n<li>`IndexDistal`</li>\n<li>`IndexTip`</li>\n<li>`MiddleMetacarpal`</li>\n<li>`MiddleProximal`</li>\n<li>`MiddleIntermediate`</li>\n<li>`MiddleDistal`</li>\n<li>`MiddleTip`</li>\n<li>`RingMetacarpal`</li>\n<li>`RingProximal`</li>\n<li>`RingIntermediate`</li>\n<li>`RingDistal`</li>\n<li>`RingTip`</li>\n<li>`LittleMetacarpal`</li>\n<li>`LittleProximal`</li>\n<li>`LittleIntermediate`</li>\n<li>`LittleDistal`</li>\n<li>`LittleTip`</li>\n</ul>\n</param>\n<returns> FVector, the coordinates of the skeletal node. </returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "GetBoneRadii", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::PICOXRInputFunctionLibrary_eventGetBoneRadii_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::PICOXRInputFunctionLibrary_eventGetBoneRadii_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics
	{
		struct PICOXRInputFunctionLibrary_eventGetBoneRotation_Parms
		{
			EPICOXRHandType DeviceHand;
			EPICOXRHandJoint Key;
			FQuat ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeviceHand_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Key_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Key_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Key;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_DeviceHand_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventGetBoneRotation_Parms, DeviceHand), Z_Construct_UEnum_PICOXRInput_EPICOXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_DeviceHand_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_DeviceHand_MetaData) }; // 2963561890
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_Key_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_Key_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventGetBoneRotation_Parms, Key), Z_Construct_UEnum_PICOXRInput_EPICOXRHandJoint, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_Key_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_Key_MetaData) }; // 2824206454
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventGetBoneRotation_Parms, ReturnValue), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_DeviceHand_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_DeviceHand,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_Key_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_Key,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Returns the rotational pose of the skeletal node for the specified hand component.</summary>\n/// <param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n/// <ul>\n/// <li>`None`: No identification is performed, and the return value is always `false`</li>\n/// <li>`Left`: Left hand</li>\n/// <li>`Right`: Right hand</li>\n/// </ul>\n/// </param>\n/// <param name =\"Key\">(In) EPicoXRHandJoint, specifies which skeletal nodes to identify.\n/// <ul>\n/// <li>`Palm`</li>\n/// <li>`Wrist`</li>\n/// <li>`ThumbMetacarpal`</li>\n/// <li>`ThumbProximal`</li>\n/// <li>`ThumbDistal`</li>\n/// <li>`ThumbTip`</li>\n/// <li>`IndexMetacarpal`</li>\n/// <li>`IndexProximal`</li>\n/// <li>`IndexIntermediate`</li>\n/// <li>`IndexDistal`</li>\n/// <li>`IndexTip`</li>\n/// <li>`MiddleMetacarpal`</li>\n/// <li>`MiddleProximal`</li>\n/// <li>`MiddleIntermediate`</li>\n/// <li>`MiddleDistal`</li>\n/// <li>`MiddleTip`</li>\n/// <li>`RingMetacarpal`</li>\n/// <li>`RingProximal`</li>\n/// <li>`RingIntermediate`</li>\n/// <li>`RingDistal`</li>\n/// <li>`RingTip`</li>\n/// <li>`LittleMetacarpal`</li>\n/// <li>`LittleProximal`</li>\n/// <li>`LittleIntermediate`</li>\n/// <li>`LittleDistal`</li>\n/// <li>`LittleTip`</li>\n/// </ul>\n/// </param>\n/// <returns> FRotator, rotational pose of the skeletal node. </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Returns the rotational pose of the skeletal node for the specified hand component.</summary>\n<param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n<ul>\n<li>`None`: No identification is performed, and the return value is always `false`</li>\n<li>`Left`: Left hand</li>\n<li>`Right`: Right hand</li>\n</ul>\n</param>\n<param name =\"Key\">(In) EPicoXRHandJoint, specifies which skeletal nodes to identify.\n<ul>\n<li>`Palm`</li>\n<li>`Wrist`</li>\n<li>`ThumbMetacarpal`</li>\n<li>`ThumbProximal`</li>\n<li>`ThumbDistal`</li>\n<li>`ThumbTip`</li>\n<li>`IndexMetacarpal`</li>\n<li>`IndexProximal`</li>\n<li>`IndexIntermediate`</li>\n<li>`IndexDistal`</li>\n<li>`IndexTip`</li>\n<li>`MiddleMetacarpal`</li>\n<li>`MiddleProximal`</li>\n<li>`MiddleIntermediate`</li>\n<li>`MiddleDistal`</li>\n<li>`MiddleTip`</li>\n<li>`RingMetacarpal`</li>\n<li>`RingProximal`</li>\n<li>`RingIntermediate`</li>\n<li>`RingDistal`</li>\n<li>`RingTip`</li>\n<li>`LittleMetacarpal`</li>\n<li>`LittleProximal`</li>\n<li>`LittleIntermediate`</li>\n<li>`LittleDistal`</li>\n<li>`LittleTip`</li>\n</ul>\n</param>\n<returns> FRotator, rotational pose of the skeletal node. </returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "GetBoneRotation", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::PICOXRInputFunctionLibrary_eventGetBoneRotation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::PICOXRInputFunctionLibrary_eventGetBoneRotation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandRootPose_Statics
	{
		struct PICOXRInputFunctionLibrary_eventGetHandRootPose_Parms
		{
			EPICOXRHandType DeviceHand;
			FTransform ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeviceHand_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandRootPose_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandRootPose_Statics::NewProp_DeviceHand_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandRootPose_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventGetHandRootPose_Parms, DeviceHand), Z_Construct_UEnum_PICOXRInput_EPICOXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandRootPose_Statics::NewProp_DeviceHand_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandRootPose_Statics::NewProp_DeviceHand_MetaData) }; // 2963561890
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandRootPose_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventGetHandRootPose_Parms, ReturnValue), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandRootPose_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandRootPose_Statics::NewProp_DeviceHand_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandRootPose_Statics::NewProp_DeviceHand,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandRootPose_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandRootPose_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Returns the root node's pose transformation for the specific hand component.</summary>\n/// <param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n/// <ul>\n/// <li>`None`: No identification is performed, and the return value is always `false`</li>\n/// <li>`Left`: Left hand</li>\n/// <li>`Right`: Right hand</li>\n/// </ul>\n/// </param>\n/// <returns>FTranform, transformation value. </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Returns the root node's pose transformation for the specific hand component.</summary>\n<param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n<ul>\n<li>`None`: No identification is performed, and the return value is always `false`</li>\n<li>`Left`: Left hand</li>\n<li>`Right`: Right hand</li>\n</ul>\n</param>\n<returns>FTranform, transformation value. </returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandRootPose_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "GetHandRootPose", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandRootPose_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandRootPose_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandRootPose_Statics::PICOXRInputFunctionLibrary_eventGetHandRootPose_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandRootPose_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandRootPose_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandRootPose_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandRootPose_Statics::PICOXRInputFunctionLibrary_eventGetHandRootPose_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandRootPose()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandRootPose_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandScale_Statics
	{
		struct PICOXRInputFunctionLibrary_eventGetHandScale_Parms
		{
			EPICOXRHandType DeviceHand;
			float ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeviceHand_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandScale_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandScale_Statics::NewProp_DeviceHand_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandScale_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventGetHandScale_Parms, DeviceHand), Z_Construct_UEnum_PICOXRInput_EPICOXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandScale_Statics::NewProp_DeviceHand_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandScale_Statics::NewProp_DeviceHand_MetaData) }; // 2963561890
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandScale_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventGetHandScale_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandScale_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandScale_Statics::NewProp_DeviceHand_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandScale_Statics::NewProp_DeviceHand,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandScale_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandScale_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Returns the scaling factor of the specified hand component.</summary>\n/// <param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n/// <ul>\n/// <li>`None`: No identification is performed, and the return value is always `false`</li>\n/// <li>`Left`: Left hand</li>\n/// <li>`Right`: Right hand</li>\n/// </ul>\n/// </param>\n/// <returns>Float, the scaling factor. </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Returns the scaling factor of the specified hand component.</summary>\n<param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n<ul>\n<li>`None`: No identification is performed, and the return value is always `false`</li>\n<li>`Left`: Left hand</li>\n<li>`Right`: Right hand</li>\n</ul>\n</param>\n<returns>Float, the scaling factor. </returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandScale_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "GetHandScale", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandScale_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandScale_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandScale_Statics::PICOXRInputFunctionLibrary_eventGetHandScale_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandScale_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandScale_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandScale_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandScale_Statics::PICOXRInputFunctionLibrary_eventGetHandScale_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandScale()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandScale_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetPinchStrength_Statics
	{
		struct PICOXRInputFunctionLibrary_eventGetPinchStrength_Parms
		{
			EPICOXRHandType DeviceHand;
			float ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeviceHand_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetPinchStrength_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetPinchStrength_Statics::NewProp_DeviceHand_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetPinchStrength_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventGetPinchStrength_Parms, DeviceHand), Z_Construct_UEnum_PICOXRInput_EPICOXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetPinchStrength_Statics::NewProp_DeviceHand_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetPinchStrength_Statics::NewProp_DeviceHand_MetaData) }; // 2963561890
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetPinchStrength_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventGetPinchStrength_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetPinchStrength_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetPinchStrength_Statics::NewProp_DeviceHand_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetPinchStrength_Statics::NewProp_DeviceHand,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetPinchStrength_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetPinchStrength_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Returns the click strength for the specified hand component.</summary>\n/// <param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n/// <ul>\n/// <li>`None`: No identification is performed, and the return value is always `false`</li>\n/// <li>`Left`: Left hand</li>\n/// <li>`Right`: Right hand</li>\n/// </ul>\n/// </param>\n/// <returns>Float, click strength. </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Returns the click strength for the specified hand component.</summary>\n<param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n<ul>\n<li>`None`: No identification is performed, and the return value is always `false`</li>\n<li>`Left`: Left hand</li>\n<li>`Right`: Right hand</li>\n</ul>\n</param>\n<returns>Float, click strength. </returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetPinchStrength_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "GetPinchStrength", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetPinchStrength_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetPinchStrength_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetPinchStrength_Statics::PICOXRInputFunctionLibrary_eventGetPinchStrength_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetPinchStrength_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetPinchStrength_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetPinchStrength_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetPinchStrength_Statics::PICOXRInputFunctionLibrary_eventGetPinchStrength_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetPinchStrength()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetPinchStrength_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetRayPose_Statics
	{
		struct PICOXRInputFunctionLibrary_eventGetRayPose_Parms
		{
			EPICOXRHandType DeviceHand;
			FTransform ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeviceHand_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetRayPose_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetRayPose_Statics::NewProp_DeviceHand_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetRayPose_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventGetRayPose_Parms, DeviceHand), Z_Construct_UEnum_PICOXRInput_EPICOXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetRayPose_Statics::NewProp_DeviceHand_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetRayPose_Statics::NewProp_DeviceHand_MetaData) }; // 2963561890
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetRayPose_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventGetRayPose_Parms, ReturnValue), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetRayPose_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetRayPose_Statics::NewProp_DeviceHand_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetRayPose_Statics::NewProp_DeviceHand,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetRayPose_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetRayPose_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Returns the laser pointer pose for the specified hand component.</summary>\n/// <param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n/// <ul>\n/// <li>`None`: No identification is performed, and the return value is always `false`</li>\n/// <li>`Left`: Left hand</li>\n/// <li>`Right`: Right hand</li>\n/// </ul>\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: The position data of the current skeletal node is valid.</li>\n/// <li>`false`: The position data of the current skeletal node is invalid.</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Returns the laser pointer pose for the specified hand component.</summary>\n<param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n<ul>\n<li>`None`: No identification is performed, and the return value is always `false`</li>\n<li>`Left`: Left hand</li>\n<li>`Right`: Right hand</li>\n</ul>\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: The position data of the current skeletal node is valid.</li>\n<li>`false`: The position data of the current skeletal node is invalid.</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetRayPose_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "GetRayPose", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetRayPose_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetRayPose_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetRayPose_Statics::PICOXRInputFunctionLibrary_eventGetRayPose_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetRayPose_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetRayPose_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetRayPose_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetRayPose_Statics::PICOXRInputFunctionLibrary_eventGetRayPose_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetRayPose()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetRayPose_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence_Statics
	{
		struct PICOXRInputFunctionLibrary_eventGetTrackingConfidence_Parms
		{
			EPICOXRHandType DeviceHand;
			EPICOXRHandTrackingConfidence ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeviceHand_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence_Statics::NewProp_DeviceHand_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventGetTrackingConfidence_Parms, DeviceHand), Z_Construct_UEnum_PICOXRInput_EPICOXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence_Statics::NewProp_DeviceHand_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence_Statics::NewProp_DeviceHand_MetaData) }; // 2963561890
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventGetTrackingConfidence_Parms, ReturnValue), Z_Construct_UEnum_PICOXRInput_EPICOXRHandTrackingConfidence, METADATA_PARAMS(0, nullptr) }; // 2631199562
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence_Statics::NewProp_DeviceHand_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence_Statics::NewProp_DeviceHand,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Returns the tracking confidence for the specified hand component.</summary>\n/// <param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n/// <ul>\n/// <li>`None`: No identification is performed, and the return value is always `false`</li>\n/// <li>`Left`: Left hand</li>\n/// <li>`Right`: Right hand</li>\n/// </ul>\n/// </param>\n/// <returns>EPicoXRHandTrackingConfidence\n/// <ul>\n/// <li>`High`: High confidence level </li>\n/// <li>`Low`: Low confidence level </li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Returns the tracking confidence for the specified hand component.</summary>\n<param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n<ul>\n<li>`None`: No identification is performed, and the return value is always `false`</li>\n<li>`Left`: Left hand</li>\n<li>`Right`: Right hand</li>\n</ul>\n</param>\n<returns>EPicoXRHandTrackingConfidence\n<ul>\n<li>`High`: High confidence level </li>\n<li>`Low`: Low confidence level </li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "GetTrackingConfidence", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence_Statics::PICOXRInputFunctionLibrary_eventGetTrackingConfidence_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence_Statics::PICOXRInputFunctionLibrary_eventGetTrackingConfidence_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics
	{
		struct PICOXRInputFunctionLibrary_eventIsBoneOrientationTracked_Parms
		{
			EPICOXRHandType DeviceHand;
			EPICOXRHandJoint Key;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeviceHand_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Key_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Key_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Key;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::NewProp_DeviceHand_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventIsBoneOrientationTracked_Parms, DeviceHand), Z_Construct_UEnum_PICOXRInput_EPICOXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::NewProp_DeviceHand_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::NewProp_DeviceHand_MetaData) }; // 2963561890
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::NewProp_Key_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::NewProp_Key_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventIsBoneOrientationTracked_Parms, Key), Z_Construct_UEnum_PICOXRInput_EPICOXRHandJoint, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::NewProp_Key_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::NewProp_Key_MetaData) }; // 2824206454
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventIsBoneOrientationTracked_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventIsBoneOrientationTracked_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::NewProp_DeviceHand_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::NewProp_DeviceHand,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::NewProp_Key_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::NewProp_Key,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if the specific HandJoint is Bone Orientation Tracked\n\x09 *\n\x09 * @param DeviceHand          (in) The hand to get the Orientation Tracked status from\n\x09 * @param Key              (in) The HandJoint to get the Orientation Tracked status from\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if the specific HandJoint is Bone Orientation Tracked\n\n@param DeviceHand          (in) The hand to get the Orientation Tracked status from\n@param Key              (in) The HandJoint to get the Orientation Tracked status from" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "IsBoneOrientationTracked", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::PICOXRInputFunctionLibrary_eventIsBoneOrientationTracked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::PICOXRInputFunctionLibrary_eventIsBoneOrientationTracked_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics
	{
		struct PICOXRInputFunctionLibrary_eventIsBoneOrientationValid_Parms
		{
			EPICOXRHandType DeviceHand;
			EPICOXRHandJoint Key;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeviceHand_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Key_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Key_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Key;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::NewProp_DeviceHand_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventIsBoneOrientationValid_Parms, DeviceHand), Z_Construct_UEnum_PICOXRInput_EPICOXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::NewProp_DeviceHand_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::NewProp_DeviceHand_MetaData) }; // 2963561890
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::NewProp_Key_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::NewProp_Key_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventIsBoneOrientationValid_Parms, Key), Z_Construct_UEnum_PICOXRInput_EPICOXRHandJoint, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::NewProp_Key_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::NewProp_Key_MetaData) }; // 2824206454
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventIsBoneOrientationValid_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventIsBoneOrientationValid_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::NewProp_DeviceHand_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::NewProp_DeviceHand,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::NewProp_Key_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::NewProp_Key,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Determine the validity of the rotation data for hand joints.</summary>\n/// <param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n/// <ul>\n/// <li>`None`: No identification is performed, and the return value is always `false`</li>\n/// <li>`Left`: Left hand</li>\n/// <li>`Right`: Right hand</li>\n/// </ul>\n/// </param>\n/// <param name =\"Key\">(In) EPicoXRHandJoint, specifies which skeletal nodes to identify.\n/// <ul>\n/// <li>`Palm`</li>\n/// <li>`Wrist`</li>\n/// <li>`ThumbMetacarpal`</li>\n/// <li>`ThumbProximal`</li>\n/// <li>`ThumbDistal`</li>\n/// <li>`ThumbTip`</li>\n/// <li>`IndexMetacarpal`</li>\n/// <li>`IndexProximal`</li>\n/// <li>`IndexIntermediate`</li>\n/// <li>`IndexDistal`</li>\n/// <li>`IndexTip`</li>\n/// <li>`MiddleMetacarpal`</li>\n/// <li>`MiddleProximal`</li>\n/// <li>`MiddleIntermediate`</li>\n/// <li>`MiddleDistal`</li>\n/// <li>`MiddleTip`</li>\n/// <li>`RingMetacarpal`</li>\n/// <li>`RingProximal`</li>\n/// <li>`RingIntermediate`</li>\n/// <li>`RingDistal`</li>\n/// <li>`RingTip`</li>\n/// <li>`LittleMetacarpal`</li>\n/// <li>`LittleProximal`</li>\n/// <li>`LittleIntermediate`</li>\n/// <li>`LittleDistal`</li>\n/// <li>`LittleTip`</li>\n/// </ul>\n/// </param>\n/// <returns>Bool: \n/// <ul>\n/// <li>`true`: The rotation data of the current skeletal node is valid.</li>\n/// <li>`false`: The rotation data of the current skeletal node is invalid.</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Determine the validity of the rotation data for hand joints.</summary>\n<param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n<ul>\n<li>`None`: No identification is performed, and the return value is always `false`</li>\n<li>`Left`: Left hand</li>\n<li>`Right`: Right hand</li>\n</ul>\n</param>\n<param name =\"Key\">(In) EPicoXRHandJoint, specifies which skeletal nodes to identify.\n<ul>\n<li>`Palm`</li>\n<li>`Wrist`</li>\n<li>`ThumbMetacarpal`</li>\n<li>`ThumbProximal`</li>\n<li>`ThumbDistal`</li>\n<li>`ThumbTip`</li>\n<li>`IndexMetacarpal`</li>\n<li>`IndexProximal`</li>\n<li>`IndexIntermediate`</li>\n<li>`IndexDistal`</li>\n<li>`IndexTip`</li>\n<li>`MiddleMetacarpal`</li>\n<li>`MiddleProximal`</li>\n<li>`MiddleIntermediate`</li>\n<li>`MiddleDistal`</li>\n<li>`MiddleTip`</li>\n<li>`RingMetacarpal`</li>\n<li>`RingProximal`</li>\n<li>`RingIntermediate`</li>\n<li>`RingDistal`</li>\n<li>`RingTip`</li>\n<li>`LittleMetacarpal`</li>\n<li>`LittleProximal`</li>\n<li>`LittleIntermediate`</li>\n<li>`LittleDistal`</li>\n<li>`LittleTip`</li>\n</ul>\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: The rotation data of the current skeletal node is valid.</li>\n<li>`false`: The rotation data of the current skeletal node is invalid.</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "IsBoneOrientationValid", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::PICOXRInputFunctionLibrary_eventIsBoneOrientationValid_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::PICOXRInputFunctionLibrary_eventIsBoneOrientationValid_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics
	{
		struct PICOXRInputFunctionLibrary_eventIsBonePositionTracked_Parms
		{
			EPICOXRHandType DeviceHand;
			EPICOXRHandJoint Key;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeviceHand_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Key_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Key_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Key;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::NewProp_DeviceHand_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventIsBonePositionTracked_Parms, DeviceHand), Z_Construct_UEnum_PICOXRInput_EPICOXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::NewProp_DeviceHand_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::NewProp_DeviceHand_MetaData) }; // 2963561890
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::NewProp_Key_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::NewProp_Key_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventIsBonePositionTracked_Parms, Key), Z_Construct_UEnum_PICOXRInput_EPICOXRHandJoint, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::NewProp_Key_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::NewProp_Key_MetaData) }; // 2824206454
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventIsBonePositionTracked_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventIsBonePositionTracked_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::NewProp_DeviceHand_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::NewProp_DeviceHand,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::NewProp_Key_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::NewProp_Key,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if the specific HandJoint is Bone Position Tracked\n\x09 *\n\x09 * @param DeviceHand          (in) The hand to get the Position Tracked status from\n\x09 * @param Key              (in) The HandJoint to get the Position Tracked status from\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if the specific HandJoint is Bone Position Tracked\n\n@param DeviceHand          (in) The hand to get the Position Tracked status from\n@param Key              (in) The HandJoint to get the Position Tracked status from" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "IsBonePositionTracked", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::PICOXRInputFunctionLibrary_eventIsBonePositionTracked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::PICOXRInputFunctionLibrary_eventIsBonePositionTracked_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics
	{
		struct PICOXRInputFunctionLibrary_eventIsBonePositionValid_Parms
		{
			EPICOXRHandType DeviceHand;
			EPICOXRHandJoint Key;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeviceHand_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Key_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Key_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Key;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::NewProp_DeviceHand_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventIsBonePositionValid_Parms, DeviceHand), Z_Construct_UEnum_PICOXRInput_EPICOXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::NewProp_DeviceHand_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::NewProp_DeviceHand_MetaData) }; // 2963561890
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::NewProp_Key_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::NewProp_Key_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventIsBonePositionValid_Parms, Key), Z_Construct_UEnum_PICOXRInput_EPICOXRHandJoint, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::NewProp_Key_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::NewProp_Key_MetaData) }; // 2824206454
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventIsBonePositionValid_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventIsBonePositionValid_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::NewProp_DeviceHand_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::NewProp_DeviceHand,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::NewProp_Key_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::NewProp_Key,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Determine the validity of the position data for hand joints.</summary>\n/// <param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n/// <ul>\n/// <li>`None`: No identification is performed, and the return value is always `false`</li>\n/// <li>`Left`: Left hand</li>\n/// <li>`Right`: Right hand</li>\n/// </ul>\n/// </param>\n/// <param name =\"Key\">(In) EPicoXRHandJoint, specifies which skeletal nodes to identify.\n/// <ul>\n/// <li>`Palm`</li>\n/// <li>`Wrist`</li>\n/// <li>`ThumbMetacarpal`</li>\n/// <li>`ThumbProximal`</li>\n/// <li>`ThumbDistal`</li>\n/// <li>`ThumbTip`</li>\n/// <li>`IndexMetacarpal`</li>\n/// <li>`IndexProximal`</li>\n/// <li>`IndexIntermediate`</li>\n/// <li>`IndexDistal`</li>\n/// <li>`IndexTip`</li>\n/// <li>`MiddleMetacarpal`</li>\n/// <li>`MiddleProximal`</li>\n/// <li>`MiddleIntermediate`</li>\n/// <li>`MiddleDistal`</li>\n/// <li>`MiddleTip`</li>\n/// <li>`RingMetacarpal`</li>\n/// <li>`RingProximal`</li>\n/// <li>`RingIntermediate`</li>\n/// <li>`RingDistal`</li>\n/// <li>`RingTip`</li>\n/// <li>`LittleMetacarpal`</li>\n/// <li>`LittleProximal`</li>\n/// <li>`LittleIntermediate`</li>\n/// <li>`LittleDistal`</li>\n/// <li>`LittleTip`</li>\n/// </ul>\n/// </param>\n/// <returns>Bool: \n/// <ul>\n/// <li>`true`: The position data of the current skeletal node is valid.</li>\n/// <li>`false`: The position data of the current skeletal node is invalid.</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Determine the validity of the position data for hand joints.</summary>\n<param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n<ul>\n<li>`None`: No identification is performed, and the return value is always `false`</li>\n<li>`Left`: Left hand</li>\n<li>`Right`: Right hand</li>\n</ul>\n</param>\n<param name =\"Key\">(In) EPicoXRHandJoint, specifies which skeletal nodes to identify.\n<ul>\n<li>`Palm`</li>\n<li>`Wrist`</li>\n<li>`ThumbMetacarpal`</li>\n<li>`ThumbProximal`</li>\n<li>`ThumbDistal`</li>\n<li>`ThumbTip`</li>\n<li>`IndexMetacarpal`</li>\n<li>`IndexProximal`</li>\n<li>`IndexIntermediate`</li>\n<li>`IndexDistal`</li>\n<li>`IndexTip`</li>\n<li>`MiddleMetacarpal`</li>\n<li>`MiddleProximal`</li>\n<li>`MiddleIntermediate`</li>\n<li>`MiddleDistal`</li>\n<li>`MiddleTip`</li>\n<li>`RingMetacarpal`</li>\n<li>`RingProximal`</li>\n<li>`RingIntermediate`</li>\n<li>`RingDistal`</li>\n<li>`RingTip`</li>\n<li>`LittleMetacarpal`</li>\n<li>`LittleProximal`</li>\n<li>`LittleIntermediate`</li>\n<li>`LittleDistal`</li>\n<li>`LittleTip`</li>\n</ul>\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: The position data of the current skeletal node is valid.</li>\n<li>`false`: The position data of the current skeletal node is invalid.</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "IsBonePositionValid", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::PICOXRInputFunctionLibrary_eventIsBonePositionValid_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::PICOXRInputFunctionLibrary_eventIsBonePositionValid_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed_Statics
	{
		struct PICOXRInputFunctionLibrary_eventIsComputed_Parms
		{
			EPICOXRHandType DeviceHand;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeviceHand_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed_Statics::NewProp_DeviceHand_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventIsComputed_Parms, DeviceHand), Z_Construct_UEnum_PICOXRInput_EPICOXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed_Statics::NewProp_DeviceHand_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed_Statics::NewProp_DeviceHand_MetaData) }; // 2963561890
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventIsComputed_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventIsComputed_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed_Statics::NewProp_DeviceHand_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed_Statics::NewProp_DeviceHand,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Determines whether the specified hand component has been successfully tracked.</summary>\n/// <param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n/// <ul>\n/// <li>`None`: No identification is performed, and the return value is always `false`</li>\n/// <li>`Left`: Left hand</li>\n/// <li>`Right`: Right hand</li>\n/// </ul>\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Tracked successfully.</li>\n/// <li>`false`: Failed to track.</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Determines whether the specified hand component has been successfully tracked.</summary>\n<param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n<ul>\n<li>`None`: No identification is performed, and the return value is always `false`</li>\n<li>`Left`: Left hand</li>\n<li>`Right`: Right hand</li>\n</ul>\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: Tracked successfully.</li>\n<li>`false`: Failed to track.</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "IsComputed", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed_Statics::PICOXRInputFunctionLibrary_eventIsComputed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed_Statics::PICOXRInputFunctionLibrary_eventIsComputed_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsHandTrackingEnabled_Statics
	{
		struct PICOXRInputFunctionLibrary_eventIsHandTrackingEnabled_Parms
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
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventIsHandTrackingEnabled_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventIsHandTrackingEnabled_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Determines the on/off status of the hand tracking feature.</summary>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Hand tracking is enabled</li>\n/// <li>`false`: Hand tracking is disabled</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Determines the on/off status of the hand tracking feature.</summary>\n<returns>Bool:\n<ul>\n<li>`true`: Hand tracking is enabled</li>\n<li>`false`: Hand tracking is disabled</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "IsHandTrackingEnabled", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::PICOXRInputFunctionLibrary_eventIsHandTrackingEnabled_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::PICOXRInputFunctionLibrary_eventIsHandTrackingEnabled_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsHandTrackingEnabled()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsHandTrackingEnabled_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid_Statics
	{
		struct PICOXRInputFunctionLibrary_eventIsPinchValid_Parms
		{
			EPICOXRHandType DeviceHand;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeviceHand_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid_Statics::NewProp_DeviceHand_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventIsPinchValid_Parms, DeviceHand), Z_Construct_UEnum_PICOXRInput_EPICOXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid_Statics::NewProp_DeviceHand_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid_Statics::NewProp_DeviceHand_MetaData) }; // 2963561890
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventIsPinchValid_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventIsPinchValid_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid_Statics::NewProp_DeviceHand_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid_Statics::NewProp_DeviceHand,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Determines if the laser pointer for the specified hand component is in the \"click\" position.</summary>\n/// <param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n/// <ul>\n/// <li>`None`: No identification is performed, and the return value is always `false`</li>\n/// <li>`Left`: Left hand</li>\n/// <li>`Right`: Right hand</li>\n/// </ul>\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: in the \"click\" position </li>\n/// <li>`false`: not in the \"click\" position </li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Determines if the laser pointer for the specified hand component is in the \"click\" position.</summary>\n<param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n<ul>\n<li>`None`: No identification is performed, and the return value is always `false`</li>\n<li>`Left`: Left hand</li>\n<li>`Right`: Right hand</li>\n</ul>\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: in the \"click\" position </li>\n<li>`false`: not in the \"click\" position </li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "IsPinchValid", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid_Statics::PICOXRInputFunctionLibrary_eventIsPinchValid_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid_Statics::PICOXRInputFunctionLibrary_eventIsPinchValid_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid_Statics
	{
		struct PICOXRInputFunctionLibrary_eventIsRayValid_Parms
		{
			EPICOXRHandType DeviceHand;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DeviceHand_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid_Statics::NewProp_DeviceHand_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventIsRayValid_Parms, DeviceHand), Z_Construct_UEnum_PICOXRInput_EPICOXRHandType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid_Statics::NewProp_DeviceHand_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid_Statics::NewProp_DeviceHand_MetaData) }; // 2963561890
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventIsRayValid_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventIsRayValid_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid_Statics::NewProp_DeviceHand_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid_Statics::NewProp_DeviceHand,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHandTracking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Determines whether the laser pointer for the specified hand component is \"displayed\".</summary>\n/// <param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n/// <ul>\n/// <li>`None`: No identification is performed, and the return value is always `false`</li>\n/// <li>`Left`: Left hand</li>\n/// <li>`Right`: Right hand</li>\n/// </ul>\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: \"displayed\" </li>\n/// <li>`false`: \"not displayed\" </li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Determines whether the laser pointer for the specified hand component is \"displayed\".</summary>\n<param name =\"DeviceHand\">(In) EPICOXRHandType, specifies which hand component to identify.\n<ul>\n<li>`None`: No identification is performed, and the return value is always `false`</li>\n<li>`Left`: Left hand</li>\n<li>`Right`: Right hand</li>\n</ul>\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: \"displayed\" </li>\n<li>`false`: \"not displayed\" </li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "IsRayValid", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid_Statics::PICOXRInputFunctionLibrary_eventIsRayValid_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid_Statics::PICOXRInputFunctionLibrary_eventIsRayValid_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ClearVibrateByCache_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_ClearVibrateByCache_Parms
		{
			int32 SourceId;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_SourceId;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ClearVibrateByCache_Statics::NewProp_SourceId = { "SourceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_ClearVibrateByCache_Parms, SourceId), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ClearVibrateByCache_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_ClearVibrateByCache_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ClearVibrateByCache_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ClearVibrateByCache_Statics::NewProp_SourceId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ClearVibrateByCache_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ClearVibrateByCache_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Clears the cached audio vibration data.</summary>\n/// <param name =\"SourceId\">(In) the ID returned by another vibration control API. </param>\n/// <returns>\n/// <ul>\n/// <li>`0`: success</li>\n/// <li>`-1`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Clears the cached audio vibration data.</summary>\n<param name =\"SourceId\">(In) the ID returned by another vibration control API. </param>\n<returns>\n<ul>\n<li>`0`: success</li>\n<li>`-1`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ClearVibrateByCache_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_ClearVibrateByCache", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ClearVibrateByCache_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ClearVibrateByCache_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ClearVibrateByCache_Statics::PICOXRInputFunctionLibrary_eventPXR_ClearVibrateByCache_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ClearVibrateByCache_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ClearVibrateByCache_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ClearVibrateByCache_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ClearVibrateByCache_Statics::PICOXRInputFunctionLibrary_eventPXR_ClearVibrateByCache_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ClearVibrateByCache()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ClearVibrateByCache_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_CreateHapticStream_Parms
		{
			FString PHFVersion;
			int32 FrameDurationMs;
			int32 Slot;
			int32 Reversal;
			float Amp;
			float Speed;
			int32 SourceID;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_PHFVersion;
		static const UECodeGen_Private::FIntPropertyParams NewProp_FrameDurationMs;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Slot;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Reversal;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Amp;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Speed;
		static const UECodeGen_Private::FIntPropertyParams NewProp_SourceID;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::NewProp_PHFVersion = { "PHFVersion", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_CreateHapticStream_Parms, PHFVersion), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::NewProp_FrameDurationMs = { "FrameDurationMs", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_CreateHapticStream_Parms, FrameDurationMs), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_CreateHapticStream_Parms, Slot), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::NewProp_Reversal = { "Reversal", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_CreateHapticStream_Parms, Reversal), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::NewProp_Amp = { "Amp", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_CreateHapticStream_Parms, Amp), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::NewProp_Speed = { "Speed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_CreateHapticStream_Parms, Speed), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::NewProp_SourceID = { "SourceID", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_CreateHapticStream_Parms, SourceID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_CreateHapticStream_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::NewProp_PHFVersion,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::NewProp_FrameDurationMs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::NewProp_Slot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::NewProp_Reversal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::NewProp_Amp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::NewProp_Speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::NewProp_SourceID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Creates a haptic stream.</summary>\n/// <param name =\"PHFVersion\">(In) Fstring, the version of the PHF ( PICO Haptic File). </param>\n/// <param name =\"FrameDurationMs\">(In) Int, interval of each frame. </param>\n/// <param name =\"Slot\">(In) specifies which controller to vibrate with the audio.\n/// <ul>\n/// <li>`No`: none</li>\n/// <li>`Left`: left controller</li>\n/// <li>`Right`: right controller</li>\n/// <li>`LeftAndRight`: both</li>\n/// </ul>\n/// </param>\n/// <param name =\"Reversal\">(In) Not used currently. Set to 0 by default. </param>\n/// <param name =\"Amp\">(In) Float, vibration gain data. The range is 0.0 to 2.0:\n/// <ul>\n/// <li>`0.0`: for no vibration</li>\n/// <li>`1.0`: for standard amplitude</li>\n/// <li>`2.0`: for double the standard amplitude</li>\n/// </ul>\n/// </param>\n/// <param name =\"Speed\">(In) Speed of the haptic stream. </param>\n/// <param name =\"SourceID\">(Out) Int, returns a unique control ID for the corresponding vibration. </param>\n/// <returns>\n/// <ul>\n/// <li>`0`: success</li>\n/// <li>`-1`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Creates a haptic stream.</summary>\n<param name =\"PHFVersion\">(In) Fstring, the version of the PHF ( PICO Haptic File). </param>\n<param name =\"FrameDurationMs\">(In) Int, interval of each frame. </param>\n<param name =\"Slot\">(In) specifies which controller to vibrate with the audio.\n<ul>\n<li>`No`: none</li>\n<li>`Left`: left controller</li>\n<li>`Right`: right controller</li>\n<li>`LeftAndRight`: both</li>\n</ul>\n</param>\n<param name =\"Reversal\">(In) Not used currently. Set to 0 by default. </param>\n<param name =\"Amp\">(In) Float, vibration gain data. The range is 0.0 to 2.0:\n<ul>\n<li>`0.0`: for no vibration</li>\n<li>`1.0`: for standard amplitude</li>\n<li>`2.0`: for double the standard amplitude</li>\n</ul>\n</param>\n<param name =\"Speed\">(In) Speed of the haptic stream. </param>\n<param name =\"SourceID\">(Out) Int, returns a unique control ID for the corresponding vibration. </param>\n<returns>\n<ul>\n<li>`0`: success</li>\n<li>`-1`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_CreateHapticStream", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::PICOXRInputFunctionLibrary_eventPXR_CreateHapticStream_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::PICOXRInputFunctionLibrary_eventPXR_CreateHapticStream_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_GetBodyTrackingPose_Parms
		{
			TArray<FPxrBodyTrackingTransform> BodyTrackingData;
			float WorldToMetersScale;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_BodyTrackingData_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_BodyTrackingData;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_WorldToMetersScale;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose_Statics::NewProp_BodyTrackingData_Inner = { "BodyTrackingData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPxrBodyTrackingTransform, METADATA_PARAMS(0, nullptr) }; // 2358891503
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose_Statics::NewProp_BodyTrackingData = { "BodyTrackingData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetBodyTrackingPose_Parms, BodyTrackingData), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 2358891503
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose_Statics::NewProp_WorldToMetersScale = { "WorldToMetersScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetBodyTrackingPose_Parms, WorldToMetersScale), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventPXR_GetBodyTrackingPose_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventPXR_GetBodyTrackingPose_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose_Statics::NewProp_BodyTrackingData_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose_Statics::NewProp_BodyTrackingData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose_Statics::NewProp_WorldToMetersScale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Get all the available body tracking data.</summary>\n/// <param name =\"BodyTrackingData\">(Out) An array of body tracking data. The index of an element in the array corresponds to a tracking node. You can see the enumeration of the class `EPxrBodyTrackerRole` for correspondence. </param>\n/// <param name = \"WorldToMetersScale\"> Float. Specifies how many Unreal units correspond to one meter in the real world. 1 by default. </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "CPP_Default_WorldToMetersScale", "100.000000" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Get all the available body tracking data.</summary>\n<param name =\"BodyTrackingData\">(Out) An array of body tracking data. The index of an element in the array corresponds to a tracking node. You can see the enumeration of the class `EPxrBodyTrackerRole` for correspondence. </param>\n<param name = \"WorldToMetersScale\"> Float. Specifies how many Unreal units correspond to one meter in the real world. 1 by default. </param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_GetBodyTrackingPose", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose_Statics::PICOXRInputFunctionLibrary_eventPXR_GetBodyTrackingPose_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose_Statics::PICOXRInputFunctionLibrary_eventPXR_GetBodyTrackingPose_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_GetBodyTrackingPoseByRole_Parms
		{
			EPxrBodyTrackerRole RoleType;
			FPxrBodyTrackingTransform RoleBodyTrackingData;
			float WorldToMetersScale;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_RoleType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_RoleType;
		static const UECodeGen_Private::FStructPropertyParams NewProp_RoleBodyTrackingData;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_WorldToMetersScale;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics::NewProp_RoleType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics::NewProp_RoleType = { "RoleType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetBodyTrackingPoseByRole_Parms, RoleType), Z_Construct_UEnum_PICOXRInput_EPxrBodyTrackerRole, METADATA_PARAMS(0, nullptr) }; // 1636942506
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics::NewProp_RoleBodyTrackingData = { "RoleBodyTrackingData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetBodyTrackingPoseByRole_Parms, RoleBodyTrackingData), Z_Construct_UScriptStruct_FPxrBodyTrackingTransform, METADATA_PARAMS(0, nullptr) }; // 2358891503
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics::NewProp_WorldToMetersScale = { "WorldToMetersScale", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetBodyTrackingPoseByRole_Parms, WorldToMetersScale), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventPXR_GetBodyTrackingPoseByRole_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventPXR_GetBodyTrackingPoseByRole_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics::NewProp_RoleType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics::NewProp_RoleType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics::NewProp_RoleBodyTrackingData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics::NewProp_WorldToMetersScale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Get the specified body tracking data.</summary>\n/// <param name =\"RoleType\">(In) Enum, the role to be tracked. </param>\n/// <param name =\"RoleBodyTrackingData\">(Out) The selected role's body tracking data. </param>\n/// <param name = \"WorldToMetersScale\"> Float. Specifies how many Unreal units correspond to one meter in the real world. 1 by default. </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "CPP_Default_WorldToMetersScale", "100.000000" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Get the specified body tracking data.</summary>\n<param name =\"RoleType\">(In) Enum, the role to be tracked. </param>\n<param name =\"RoleBodyTrackingData\">(Out) The selected role's body tracking data. </param>\n<param name = \"WorldToMetersScale\"> Float. Specifies how many Unreal units correspond to one meter in the real world. 1 by default. </param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_GetBodyTrackingPoseByRole", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics::PICOXRInputFunctionLibrary_eventPXR_GetBodyTrackingPoseByRole_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics::PICOXRInputFunctionLibrary_eventPXR_GetBodyTrackingPoseByRole_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_GetControllerAcceleration_Parms
		{
			EPICOXRControllerType ControllerType;
			FVector Acceleration;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ControllerType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ControllerType;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Acceleration;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::NewProp_ControllerType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::NewProp_ControllerType = { "ControllerType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetControllerAcceleration_Parms, ControllerType), Z_Construct_UEnum_PICOXRInput_EPICOXRControllerType, METADATA_PARAMS(0, nullptr) }; // 3139224973
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::NewProp_Acceleration = { "Acceleration", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetControllerAcceleration_Parms, Acceleration), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventPXR_GetControllerAcceleration_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventPXR_GetControllerAcceleration_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::NewProp_ControllerType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::NewProp_ControllerType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::NewProp_Acceleration,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the acceleration of the specified controller.</summary>\n/// <param name =\"ControllerType\">(In) (EPICOXRControllerType)Enum, the controller to get the acceleration for:\n/// <ul>\n/// <li>`LeftHand`: left controller</li>\n/// <li>`RightHand`: right controller</li>\n/// </ul>\n/// </param>\n/// <param name =\"Acceleration\">(Out) FVector, the acceleration of the specified controller. The units are in cm/s\xc2\xb2. </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Success</li>\n/// <li>`false`: Failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the acceleration of the specified controller.</summary>\n<param name =\"ControllerType\">(In) (EPICOXRControllerType)Enum, the controller to get the acceleration for:\n<ul>\n<li>`LeftHand`: left controller</li>\n<li>`RightHand`: right controller</li>\n</ul>\n</param>\n<param name =\"Acceleration\">(Out) FVector, the acceleration of the specified controller. The units are in cm/s\xc2\xb2. </param>\n<returns>Bool:\n<ul>\n<li>`true`: Success</li>\n<li>`false`: Failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_GetControllerAcceleration", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::PICOXRInputFunctionLibrary_eventPXR_GetControllerAcceleration_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::PICOXRInputFunctionLibrary_eventPXR_GetControllerAcceleration_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_GetControllerAngularVelocity_Parms
		{
			EPICOXRControllerType ControllerType;
			FVector AngularVelocity;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ControllerType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ControllerType;
		static const UECodeGen_Private::FStructPropertyParams NewProp_AngularVelocity;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::NewProp_ControllerType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::NewProp_ControllerType = { "ControllerType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetControllerAngularVelocity_Parms, ControllerType), Z_Construct_UEnum_PICOXRInput_EPICOXRControllerType, METADATA_PARAMS(0, nullptr) }; // 3139224973
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::NewProp_AngularVelocity = { "AngularVelocity", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetControllerAngularVelocity_Parms, AngularVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventPXR_GetControllerAngularVelocity_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventPXR_GetControllerAngularVelocity_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::NewProp_ControllerType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::NewProp_ControllerType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::NewProp_AngularVelocity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the angular velocity of the specified controller.</summary>\n/// <param name =\"ControllerType\">(In) (EPICOXRControllerType)Enum, the controller to get the connection state for:\n/// <ul>\n/// <li>`LeftHand`: left controller</li>\n/// <li>`RightHand`: right controller</li>\n/// </ul>\n/// </param>\n/// <param name =\"AngularVelocity\">(Out) FVector, the angular velocity of the specified controller. The units are in radians per second. </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Success</li>\n/// <li>`false`: Failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the angular velocity of the specified controller.</summary>\n<param name =\"ControllerType\">(In) (EPICOXRControllerType)Enum, the controller to get the connection state for:\n<ul>\n<li>`LeftHand`: left controller</li>\n<li>`RightHand`: right controller</li>\n</ul>\n</param>\n<param name =\"AngularVelocity\">(Out) FVector, the angular velocity of the specified controller. The units are in radians per second. </param>\n<returns>Bool:\n<ul>\n<li>`true`: Success</li>\n<li>`false`: Failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_GetControllerAngularVelocity", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::PICOXRInputFunctionLibrary_eventPXR_GetControllerAngularVelocity_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::PICOXRInputFunctionLibrary_eventPXR_GetControllerAngularVelocity_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_GetControllerConnectionState_Parms
		{
			EPICOXRControllerType ControllerType;
			bool Status;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ControllerType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ControllerType;
		static void NewProp_Status_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Status;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_ControllerType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_ControllerType = { "ControllerType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetControllerConnectionState_Parms, ControllerType), Z_Construct_UEnum_PICOXRInput_EPICOXRControllerType, METADATA_PARAMS(0, nullptr) }; // 3139224973
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_Status_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventPXR_GetControllerConnectionState_Parms*)Obj)->Status = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_Status = { "Status", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventPXR_GetControllerConnectionState_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_Status_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventPXR_GetControllerConnectionState_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventPXR_GetControllerConnectionState_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_ControllerType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_ControllerType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_Status,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the connection state of the specified controller.</summary>\n/// <param name =\"ControllerType\">(In) (EPICOXRControllerType)Enum, the controller to get the connection state for:\n/// <ul>\n/// <li>`LeftHand`: left controller</li>\n/// <li>`RightHand`: right controller</li>\n/// </ul>\n/// </param>\n/// <param name =\"Status\">(Out) Bool, the connection state of the specified controller:\n/// <ul>\n/// <li>`true`: Connected</li>\n/// <li>`false`: Not connected</li>\n/// </ul>\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the connection state of the specified controller.</summary>\n<param name =\"ControllerType\">(In) (EPICOXRControllerType)Enum, the controller to get the connection state for:\n<ul>\n<li>`LeftHand`: left controller</li>\n<li>`RightHand`: right controller</li>\n</ul>\n</param>\n<param name =\"Status\">(Out) Bool, the connection state of the specified controller:\n<ul>\n<li>`true`: Connected</li>\n<li>`false`: Not connected</li>\n</ul>\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_GetControllerConnectionState", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::PICOXRInputFunctionLibrary_eventPXR_GetControllerConnectionState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::PICOXRInputFunctionLibrary_eventPXR_GetControllerConnectionState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_GetControllerDeviceType_Parms
		{
			EPICOXRControllerDeviceType ControllerType;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ControllerType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ControllerType;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::NewProp_ControllerType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::NewProp_ControllerType = { "ControllerType", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetControllerDeviceType_Parms, ControllerType), Z_Construct_UEnum_PICOXRInput_EPICOXRControllerDeviceType, METADATA_PARAMS(0, nullptr) }; // 3886460524
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::NewProp_ControllerType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::NewProp_ControllerType,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the device model that the currently connected controller belongs to.</summary>\n/// <param name =\"ControllerType\">(Out)(EPICOXRControllerDeviceType) Enum, the controller to get the acceleration for:\n/// <ul>\n/// <li>`UnKnown`: UnKnown</li>\n/// <li>`G2`: PICO G2</li>\n/// <li>`Neo2`: PICO Neo 2</li>\n/// <li>`Neo3`: PICO Neo 3</li>\n/// <li>`PICO_4`: PICO 4</li>\n/// </ul>\n/// </param>\n/// <returns>None </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the device model that the currently connected controller belongs to.</summary>\n<param name =\"ControllerType\">(Out)(EPICOXRControllerDeviceType) Enum, the controller to get the acceleration for:\n<ul>\n<li>`UnKnown`: UnKnown</li>\n<li>`G2`: PICO G2</li>\n<li>`Neo2`: PICO Neo 2</li>\n<li>`Neo3`: PICO Neo 3</li>\n<li>`PICO_4`: PICO 4</li>\n</ul>\n</param>\n<returns>None </returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_GetControllerDeviceType", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::PICOXRInputFunctionLibrary_eventPXR_GetControllerDeviceType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::PICOXRInputFunctionLibrary_eventPXR_GetControllerDeviceType_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerDeviceType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerDeviceType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_GetControllerEnableHomekey_Parms
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
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventPXR_GetControllerEnableHomekey_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventPXR_GetControllerEnableHomekey_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Get controllers' enable homeKey.\n\x09* @return True if home key enable.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get controllers' enable homeKey.\n@return True if home key enable." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_GetControllerEnableHomekey", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::PICOXRInputFunctionLibrary_eventPXR_GetControllerEnableHomekey_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::PICOXRInputFunctionLibrary_eventPXR_GetControllerEnableHomekey_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerEnableHomekey()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerEnableHomekey_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_GetControllerLinearVelocity_Parms
		{
			EPICOXRControllerType ControllerType;
			FVector LinearVelocity;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ControllerType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ControllerType;
		static const UECodeGen_Private::FStructPropertyParams NewProp_LinearVelocity;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::NewProp_ControllerType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::NewProp_ControllerType = { "ControllerType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetControllerLinearVelocity_Parms, ControllerType), Z_Construct_UEnum_PICOXRInput_EPICOXRControllerType, METADATA_PARAMS(0, nullptr) }; // 3139224973
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::NewProp_LinearVelocity = { "LinearVelocity", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetControllerLinearVelocity_Parms, LinearVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventPXR_GetControllerLinearVelocity_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventPXR_GetControllerLinearVelocity_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::NewProp_ControllerType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::NewProp_ControllerType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::NewProp_LinearVelocity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the acceleration of the specified controller.</summary>\n/// <param name =\"ControllerType\">(In) (EPICOXRControllerType)Enum, the controller to get the acceleration for:\n/// <ul>\n/// <li>`LeftHand`: left controller</li>\n/// <li>`RightHand`: right controller</li>\n/// </ul>\n/// </param>\n/// <param name =\"LinearVelocity\">(Out) FVector, the linear velocity of the specified controller. The units are in cm/s.</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Success</li>\n/// <li>`false`: Failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the acceleration of the specified controller.</summary>\n<param name =\"ControllerType\">(In) (EPICOXRControllerType)Enum, the controller to get the acceleration for:\n<ul>\n<li>`LeftHand`: left controller</li>\n<li>`RightHand`: right controller</li>\n</ul>\n</param>\n<param name =\"LinearVelocity\">(Out) FVector, the linear velocity of the specified controller. The units are in cm/s.</param>\n<returns>Bool:\n<ul>\n<li>`true`: Success</li>\n<li>`false`: Failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_GetControllerLinearVelocity", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::PICOXRInputFunctionLibrary_eventPXR_GetControllerLinearVelocity_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::PICOXRInputFunctionLibrary_eventPXR_GetControllerLinearVelocity_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_GetControllerPower_Parms
		{
			EPICOXRControllerType ControllerType;
			int32 Power;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ControllerType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ControllerType;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Power;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower_Statics::NewProp_ControllerType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower_Statics::NewProp_ControllerType = { "ControllerType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetControllerPower_Parms, ControllerType), Z_Construct_UEnum_PICOXRInput_EPICOXRControllerType, METADATA_PARAMS(0, nullptr) }; // 3139224973
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower_Statics::NewProp_Power = { "Power", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetControllerPower_Parms, Power), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventPXR_GetControllerPower_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventPXR_GetControllerPower_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower_Statics::NewProp_ControllerType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower_Statics::NewProp_ControllerType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower_Statics::NewProp_Power,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the current battery level of the controller.</summary>\n/// <param name =\"ControllerType\">(In) (EPICOXRControllerType)Enum, the controller to get the battery level for:\n/// <ul>\n/// <li>`LeftHand`: left controller</li>\n/// <li>`RightHand`: right controller</li>\n/// </ul>\n/// </param>\n/// <param name =\"Power\">(Out) Int, the battery level of the specified controller, value range: [1, 5].\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the current battery level of the controller.</summary>\n<param name =\"ControllerType\">(In) (EPICOXRControllerType)Enum, the controller to get the battery level for:\n<ul>\n<li>`LeftHand`: left controller</li>\n<li>`RightHand`: right controller</li>\n</ul>\n</param>\n<param name =\"Power\">(Out) Int, the battery level of the specified controller, value range: [1, 5].\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_GetControllerPower", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower_Statics::PICOXRInputFunctionLibrary_eventPXR_GetControllerPower_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower_Statics::PICOXRInputFunctionLibrary_eventPXR_GetControllerPower_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_GetControllerPredictedLocationAndRotation_Parms
		{
			EControllerHand DeviceHand;
			float PredictedTime;
			FVector OutLocation;
			FRotator OutRotation;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_DeviceHand_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DeviceHand;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PredictedTime;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutLocation;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutRotation;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_DeviceHand_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_DeviceHand = { "DeviceHand", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetControllerPredictedLocationAndRotation_Parms, DeviceHand), Z_Construct_UEnum_InputCore_EControllerHand, METADATA_PARAMS(0, nullptr) }; // 2510333578
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_PredictedTime = { "PredictedTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetControllerPredictedLocationAndRotation_Parms, PredictedTime), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_OutLocation = { "OutLocation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetControllerPredictedLocationAndRotation_Parms, OutLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_OutRotation = { "OutRotation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetControllerPredictedLocationAndRotation_Parms, OutRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventPXR_GetControllerPredictedLocationAndRotation_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventPXR_GetControllerPredictedLocationAndRotation_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_DeviceHand_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_DeviceHand,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_PredictedTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_OutLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_OutRotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the predicted location and rotation of the specified controller after a certain period of time.</summary>\n/// <param name =\"DeviceHand\">(In)(EControllerHand) Enum, the controller to get the predicted location and rotation for:\n/// <ul>\n/// <li>`Left`: left controller</li>\n/// <li>`Right`: right controller</li>\n/// </ul>\n/// </param>\n/// <param name =\"PredictedTime\">(In) Float, the time for prediction (in milliseconds), value range: [0, 100]. </param>\n/// <param name =\"OutLocation\">(Out) FVector, the predicted location of the specified controller after the given time. </param>\n/// <param name =\"OutRotation\">(Out) FRotator, the predicted rotation of the specified controller after the given time. </param>\n/// <returns>None </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the predicted location and rotation of the specified controller after a certain period of time.</summary>\n<param name =\"DeviceHand\">(In)(EControllerHand) Enum, the controller to get the predicted location and rotation for:\n<ul>\n<li>`Left`: left controller</li>\n<li>`Right`: right controller</li>\n</ul>\n</param>\n<param name =\"PredictedTime\">(In) Float, the time for prediction (in milliseconds), value range: [0, 100]. </param>\n<param name =\"OutLocation\">(Out) FVector, the predicted location of the specified controller after the given time. </param>\n<param name =\"OutRotation\">(Out) FRotator, the predicted rotation of the specified controller after the given time. </param>\n<returns>None </returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_GetControllerPredictedLocationAndRotation", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::PICOXRInputFunctionLibrary_eventPXR_GetControllerPredictedLocationAndRotation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::PICOXRInputFunctionLibrary_eventPXR_GetControllerPredictedLocationAndRotation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetCurrentFrameSequence_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_GetCurrentFrameSequence_Parms
		{
			int32 SourceID;
			int32 FrameSequence;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_SourceID;
		static const UECodeGen_Private::FIntPropertyParams NewProp_FrameSequence;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetCurrentFrameSequence_Statics::NewProp_SourceID = { "SourceID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetCurrentFrameSequence_Parms, SourceID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetCurrentFrameSequence_Statics::NewProp_FrameSequence = { "FrameSequence", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetCurrentFrameSequence_Parms, FrameSequence), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetCurrentFrameSequence_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetCurrentFrameSequence_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetCurrentFrameSequence_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetCurrentFrameSequence_Statics::NewProp_SourceID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetCurrentFrameSequence_Statics::NewProp_FrameSequence,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetCurrentFrameSequence_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetCurrentFrameSequence_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the current frame sequence.</summary>\n/// <param name =\"SourceID\">(In) Int, a unique control ID for the corresponding vibration. </param>\n/// <param name =\"FrameSequence\">(Out) Returns the current frame's sequence No.\n/// </param>\n/// <returns>\n/// <ul>\n/// <li>`0`: success</li>\n/// <li>`-1`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the current frame sequence.</summary>\n<param name =\"SourceID\">(In) Int, a unique control ID for the corresponding vibration. </param>\n<param name =\"FrameSequence\">(Out) Returns the current frame's sequence No.\n</param>\n<returns>\n<ul>\n<li>`0`: success</li>\n<li>`-1`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetCurrentFrameSequence_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_GetCurrentFrameSequence", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetCurrentFrameSequence_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetCurrentFrameSequence_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetCurrentFrameSequence_Statics::PICOXRInputFunctionLibrary_eventPXR_GetCurrentFrameSequence_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetCurrentFrameSequence_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetCurrentFrameSequence_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetCurrentFrameSequence_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetCurrentFrameSequence_Statics::PICOXRInputFunctionLibrary_eventPXR_GetCurrentFrameSequence_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetCurrentFrameSequence()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetCurrentFrameSequence_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetHandedness_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_GetHandedness_Parms
		{
			EPICOXRHandedness Handedness;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_Handedness_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Handedness;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetHandedness_Statics::NewProp_Handedness_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetHandedness_Statics::NewProp_Handedness = { "Handedness", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetHandedness_Parms, Handedness), Z_Construct_UEnum_PICOXRInput_EPICOXRHandedness, METADATA_PARAMS(0, nullptr) }; // 1423224410
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetHandedness_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetHandedness_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetHandedness_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetHandedness_Statics::NewProp_Handedness_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetHandedness_Statics::NewProp_Handedness,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetHandedness_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetHandedness_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetHandedness_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_GetHandedness", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetHandedness_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetHandedness_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetHandedness_Statics::PICOXRInputFunctionLibrary_eventPXR_GetHandedness_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetHandedness_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetHandedness_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetHandedness_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetHandedness_Statics::PICOXRInputFunctionLibrary_eventPXR_GetHandedness_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetHandedness()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetHandedness_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_GetMainControllerHandle_Parms
		{
			EPICOXRHandedness Handedness;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_Handedness_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Handedness;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::NewProp_Handedness_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::NewProp_Handedness = { "Handedness", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetMainControllerHandle_Parms, Handedness), Z_Construct_UEnum_PICOXRInput_EPICOXRHandedness, METADATA_PARAMS(0, nullptr) }; // 1423224410
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventPXR_GetMainControllerHandle_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventPXR_GetMainControllerHandle_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::NewProp_Handedness_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::NewProp_Handedness,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Get the main controller's handedness.\n\x09* @param Handedness     (Out) The main controller's handedness. Can be left hand or right hand.\n\x09* @return True if successful in obtaining the main controller's handedness, false otherwise.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the main controller's handedness.\n@param Handedness     (Out) The main controller's handedness. Can be left hand or right hand.\n@return True if successful in obtaining the main controller's handedness, false otherwise." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_GetMainControllerHandle", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::PICOXRInputFunctionLibrary_eventPXR_GetMainControllerHandle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::PICOXRInputFunctionLibrary_eventPXR_GetMainControllerHandle_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMainControllerHandle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMainControllerHandle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerBattery_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_GetMotionTrackerBattery_Parms
		{
			int32 TrackerId;
			int32 Battery;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_TrackerId;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Battery;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerBattery_Statics::NewProp_TrackerId = { "TrackerId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetMotionTrackerBattery_Parms, TrackerId), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerBattery_Statics::NewProp_Battery = { "Battery", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetMotionTrackerBattery_Parms, Battery), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerBattery_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventPXR_GetMotionTrackerBattery_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerBattery_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventPXR_GetMotionTrackerBattery_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerBattery_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerBattery_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerBattery_Statics::NewProp_TrackerId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerBattery_Statics::NewProp_Battery,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerBattery_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerBattery_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the specified tracker's battery power.</summary>\n/// <param name =\"TrackerId\">(In) The ID for the tracker that you are querying. Can be `0` or `1`. </param>\n/// <param name =\"Battery\">(Out) Int, the battery level of the tracker, value range: [1, 5]. </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the specified tracker's battery power.</summary>\n<param name =\"TrackerId\">(In) The ID for the tracker that you are querying. Can be `0` or `1`. </param>\n<param name =\"Battery\">(Out) Int, the battery level of the tracker, value range: [1, 5]. </param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerBattery_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_GetMotionTrackerBattery", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerBattery_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerBattery_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerBattery_Statics::PICOXRInputFunctionLibrary_eventPXR_GetMotionTrackerBattery_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerBattery_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerBattery_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerBattery_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerBattery_Statics::PICOXRInputFunctionLibrary_eventPXR_GetMotionTrackerBattery_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerBattery()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerBattery_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerCalibState_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_GetMotionTrackerCalibState_Parms
		{
			int32 CalibrateState;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_CalibrateState;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerCalibState_Statics::NewProp_CalibrateState = { "CalibrateState", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetMotionTrackerCalibState_Parms, CalibrateState), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerCalibState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventPXR_GetMotionTrackerCalibState_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerCalibState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventPXR_GetMotionTrackerCalibState_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerCalibState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerCalibState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerCalibState_Statics::NewProp_CalibrateState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerCalibState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerCalibState_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the current calibration state of the trackers.</summary>\n/// <param name =\"CalibrateState\">(Out) Int, the current calibration state of the trackers.\n/// <ul>\n/// <li>`0`: Not calibrated</li>\n/// <li>`1`: Calibrated</li>\n/// </ul>\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the current calibration state of the trackers.</summary>\n<param name =\"CalibrateState\">(Out) Int, the current calibration state of the trackers.\n<ul>\n<li>`0`: Not calibrated</li>\n<li>`1`: Calibrated</li>\n</ul>\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerCalibState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_GetMotionTrackerCalibState", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerCalibState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerCalibState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerCalibState_Statics::PICOXRInputFunctionLibrary_eventPXR_GetMotionTrackerCalibState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerCalibState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerCalibState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerCalibState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerCalibState_Statics::PICOXRInputFunctionLibrary_eventPXR_GetMotionTrackerCalibState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerCalibState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerCalibState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerConnectStateWithId_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_GetMotionTrackerConnectStateWithId_Parms
		{
			FMotionTrackerConnectState State;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_State;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerConnectStateWithId_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetMotionTrackerConnectStateWithId_Parms, State), Z_Construct_UScriptStruct_FMotionTrackerConnectState, METADATA_PARAMS(0, nullptr) }; // 2197083264
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerConnectStateWithId_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventPXR_GetMotionTrackerConnectStateWithId_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerConnectStateWithId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventPXR_GetMotionTrackerConnectStateWithId_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerConnectStateWithId_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerConnectStateWithId_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerConnectStateWithId_Statics::NewProp_State,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerConnectStateWithId_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerConnectStateWithId_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the connected states of both Motion Trackers.</summary>\n/// <param name =\"State\">(Out) The current connected state. </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the connected states of both Motion Trackers.</summary>\n<param name =\"State\">(Out) The current connected state. </param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerConnectStateWithId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_GetMotionTrackerConnectStateWithId", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerConnectStateWithId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerConnectStateWithId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerConnectStateWithId_Statics::PICOXRInputFunctionLibrary_eventPXR_GetMotionTrackerConnectStateWithId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerConnectStateWithId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerConnectStateWithId_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerConnectStateWithId_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerConnectStateWithId_Statics::PICOXRInputFunctionLibrary_eventPXR_GetMotionTrackerConnectStateWithId_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerConnectStateWithId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerConnectStateWithId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetPHFHapticSpeed_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_GetPHFHapticSpeed_Parms
		{
			int32 SourceID;
			float Speed;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_SourceID;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Speed;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetPHFHapticSpeed_Statics::NewProp_SourceID = { "SourceID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetPHFHapticSpeed_Parms, SourceID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetPHFHapticSpeed_Statics::NewProp_Speed = { "Speed", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetPHFHapticSpeed_Parms, Speed), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetPHFHapticSpeed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_GetPHFHapticSpeed_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetPHFHapticSpeed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetPHFHapticSpeed_Statics::NewProp_SourceID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetPHFHapticSpeed_Statics::NewProp_Speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetPHFHapticSpeed_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetPHFHapticSpeed_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the PHF haptic speed.</summary>\n/// <param name =\"SourceID\">(In) Int, a unique control ID for the corresponding vibration. </param>\n/// <param name =\"Speed\">(Out) Speed of the haptic stream. </param>\n/// <returns>\n/// <ul>\n/// <li>`0`: success</li>\n/// <li>`-1`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the PHF haptic speed.</summary>\n<param name =\"SourceID\">(In) Int, a unique control ID for the corresponding vibration. </param>\n<param name =\"Speed\">(Out) Speed of the haptic stream. </param>\n<returns>\n<ul>\n<li>`0`: success</li>\n<li>`-1`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetPHFHapticSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_GetPHFHapticSpeed", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetPHFHapticSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetPHFHapticSpeed_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetPHFHapticSpeed_Statics::PICOXRInputFunctionLibrary_eventPXR_GetPHFHapticSpeed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetPHFHapticSpeed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetPHFHapticSpeed_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetPHFHapticSpeed_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetPHFHapticSpeed_Statics::PICOXRInputFunctionLibrary_eventPXR_GetPHFHapticSpeed_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetPHFHapticSpeed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetPHFHapticSpeed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_PauseVibrate_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_PauseVibrate_Parms
		{
			int32 SourceID;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_SourceID;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_PauseVibrate_Statics::NewProp_SourceID = { "SourceID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_PauseVibrate_Parms, SourceID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_PauseVibrate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_PauseVibrate_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_PauseVibrate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_PauseVibrate_Statics::NewProp_SourceID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_PauseVibrate_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_PauseVibrate_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Pauses the PHF vibration data.</summary>\n/// <param name =\"SourceID\">(In) ID returned by another vibration control API. </param>\n/// <returns>\n/// <ul>\n/// <li>`0`: success</li>\n/// <li>`-1`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Pauses the PHF vibration data.</summary>\n<param name =\"SourceID\">(In) ID returned by another vibration control API. </param>\n<returns>\n<ul>\n<li>`0`: success</li>\n<li>`-1`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_PauseVibrate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_PauseVibrate", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_PauseVibrate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_PauseVibrate_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_PauseVibrate_Statics::PICOXRInputFunctionLibrary_eventPXR_PauseVibrate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_PauseVibrate_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_PauseVibrate_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_PauseVibrate_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_PauseVibrate_Statics::PICOXRInputFunctionLibrary_eventPXR_PauseVibrate_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_PauseVibrate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_PauseVibrate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_RemovePHFHaptic_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_RemovePHFHaptic_Parms
		{
			int32 SourceID;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_SourceID;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_RemovePHFHaptic_Statics::NewProp_SourceID = { "SourceID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_RemovePHFHaptic_Parms, SourceID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_RemovePHFHaptic_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_RemovePHFHaptic_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_RemovePHFHaptic_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_RemovePHFHaptic_Statics::NewProp_SourceID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_RemovePHFHaptic_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_RemovePHFHaptic_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Removes PHF haptic.</summary>\n/// <param name =\"SourceID\">(In) Int, a unique control ID for the corresponding vibration. </param>\n/// <returns>\n/// <ul>\n/// <li>`0`: success</li>\n/// <li>`-1`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Removes PHF haptic.</summary>\n<param name =\"SourceID\">(In) Int, a unique control ID for the corresponding vibration. </param>\n<returns>\n<ul>\n<li>`0`: success</li>\n<li>`-1`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_RemovePHFHaptic_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_RemovePHFHaptic", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_RemovePHFHaptic_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_RemovePHFHaptic_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_RemovePHFHaptic_Statics::PICOXRInputFunctionLibrary_eventPXR_RemovePHFHaptic_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_RemovePHFHaptic_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_RemovePHFHaptic_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_RemovePHFHaptic_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_RemovePHFHaptic_Statics::PICOXRInputFunctionLibrary_eventPXR_RemovePHFHaptic_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_RemovePHFHaptic()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_RemovePHFHaptic_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResetController_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_ResetController_Parms
		{
			int32 Device;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Device;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResetController_Statics::NewProp_Device = { "Device", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_ResetController_Parms, Device), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResetController_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_ResetController_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResetController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResetController_Statics::NewProp_Device,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResetController_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResetController_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResetController_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_ResetController", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResetController_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResetController_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResetController_Statics::PICOXRInputFunctionLibrary_eventPXR_ResetController_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResetController_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResetController_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResetController_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResetController_Statics::PICOXRInputFunctionLibrary_eventPXR_ResetController_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResetController()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResetController_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResumeVibrate_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_ResumeVibrate_Parms
		{
			int32 SourceID;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_SourceID;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResumeVibrate_Statics::NewProp_SourceID = { "SourceID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_ResumeVibrate_Parms, SourceID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResumeVibrate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_ResumeVibrate_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResumeVibrate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResumeVibrate_Statics::NewProp_SourceID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResumeVibrate_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResumeVibrate_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Resumes PHF vibration data.</summary>\n/// <param name =\"SourceID\">(In) ID returned by another vibration control API. </param>\n/// <returns>\n/// <ul>\n/// <li>`0`: success</li>\n/// <li>`-1`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Resumes PHF vibration data.</summary>\n<param name =\"SourceID\">(In) ID returned by another vibration control API. </param>\n<returns>\n<ul>\n<li>`0`: success</li>\n<li>`-1`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResumeVibrate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_ResumeVibrate", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResumeVibrate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResumeVibrate_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResumeVibrate_Statics::PICOXRInputFunctionLibrary_eventPXR_ResumeVibrate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResumeVibrate_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResumeVibrate_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResumeVibrate_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResumeVibrate_Statics::PICOXRInputFunctionLibrary_eventPXR_ResumeVibrate_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResumeVibrate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResumeVibrate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_SaveVibrateByCache_Parms
		{
			USoundWave* InSoundWave;
			EPICOXRVibrateController slot;
			EPICOXRChannelFlip slotConfig;
			EPICOXRCacheConfig enableV;
			int32 SourceId;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InSoundWave;
		static const UECodeGen_Private::FBytePropertyParams NewProp_slot_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_slot;
		static const UECodeGen_Private::FBytePropertyParams NewProp_slotConfig_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_slotConfig;
		static const UECodeGen_Private::FBytePropertyParams NewProp_enableV_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_enableV;
		static const UECodeGen_Private::FIntPropertyParams NewProp_SourceId;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::NewProp_InSoundWave = { "InSoundWave", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SaveVibrateByCache_Parms, InSoundWave), Z_Construct_UClass_USoundWave_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::NewProp_slot_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::NewProp_slot = { "slot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SaveVibrateByCache_Parms, slot), Z_Construct_UEnum_PICOXRInput_EPICOXRVibrateController, METADATA_PARAMS(0, nullptr) }; // 1498834001
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::NewProp_slotConfig_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::NewProp_slotConfig = { "slotConfig", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SaveVibrateByCache_Parms, slotConfig), Z_Construct_UEnum_PICOXRInput_EPICOXRChannelFlip, METADATA_PARAMS(0, nullptr) }; // 536287980
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::NewProp_enableV_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::NewProp_enableV = { "enableV", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SaveVibrateByCache_Parms, enableV), Z_Construct_UEnum_PICOXRInput_EPICOXRCacheConfig, METADATA_PARAMS(0, nullptr) }; // 1934369178
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::NewProp_SourceId = { "SourceId", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SaveVibrateByCache_Parms, SourceId), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SaveVibrateByCache_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::NewProp_InSoundWave,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::NewProp_slot_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::NewProp_slot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::NewProp_slotConfig_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::NewProp_slotConfig,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::NewProp_enableV_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::NewProp_enableV,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::NewProp_SourceId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Caches audio-based vibration data. You can set whether to keep the controller vibrating while caching the data. Cached audio data can be extracted from the cache directory and then transmitted, which reduces resource consumption and improves service performance.</summary>\n/// <param name =\"InSoundWave\">(In) audio asset (\"SoundWave\" Asset type) </param>\n/// <param name =\"slot\">(In) specifies which controller to vibrate with the audio.\n/// <ul>\n/// <li>`No`: none</li>\n/// <li>`Left`: left controller</li>\n/// <li>`Right`: right controller</li>\n/// <li>`LeftAndRight`: both</li>\n/// </ul>\n/// </param>\n/// <param name =\"slotConfig\">(In) Specifies whether to enable audio channel inversion.\n/// <ul>\n/// <li>`No`: disable</li>\n/// <li>`Yes`: enable</li>\n/// </ul>\n/// </param>\n/// <summary>\n/// @note When slotConfig = `1`, the left controller vibrates with the audio source from right soundtrack, and vice versa.\n/// </summary>\n/// <param name =\"enableV\">(In) defines whether to keep the controller vibrating while caching audio-based vibration data\n/// <ul>\n/// <li>`CacheAndVibrate`: caches and keeps vibrating</li>\n/// <li>`CacheNoVibrate`: caches and stops vibrating</li>\n/// </ul>\n/// </param>\n/// <param name =\"SourceId\">(Out) returns a unique ID for controlling the corresponding vibration, which can be used for subsequent APIs, such as PXR_SaveVibrateByCache, PXR_ClearVibrateByCache and PXR_StopControllerVCMotor.\n/// </param>\n/// <returns>\n/// <ul>\n/// <li>`0`: success</li>\n/// <li>`-1`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Caches audio-based vibration data. You can set whether to keep the controller vibrating while caching the data. Cached audio data can be extracted from the cache directory and then transmitted, which reduces resource consumption and improves service performance.</summary>\n<param name =\"InSoundWave\">(In) audio asset (\"SoundWave\" Asset type) </param>\n<param name =\"slot\">(In) specifies which controller to vibrate with the audio.\n<ul>\n<li>`No`: none</li>\n<li>`Left`: left controller</li>\n<li>`Right`: right controller</li>\n<li>`LeftAndRight`: both</li>\n</ul>\n</param>\n<param name =\"slotConfig\">(In) Specifies whether to enable audio channel inversion.\n<ul>\n<li>`No`: disable</li>\n<li>`Yes`: enable</li>\n</ul>\n</param>\n<summary>\n@note When slotConfig = `1`, the left controller vibrates with the audio source from right soundtrack, and vice versa.\n</summary>\n<param name =\"enableV\">(In) defines whether to keep the controller vibrating while caching audio-based vibration data\n<ul>\n<li>`CacheAndVibrate`: caches and keeps vibrating</li>\n<li>`CacheNoVibrate`: caches and stops vibrating</li>\n</ul>\n</param>\n<param name =\"SourceId\">(Out) returns a unique ID for controlling the corresponding vibration, which can be used for subsequent APIs, such as PXR_SaveVibrateByCache, PXR_ClearVibrateByCache and PXR_StopControllerVCMotor.\n</param>\n<returns>\n<ul>\n<li>`0`: success</li>\n<li>`-1`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_SaveVibrateByCache", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::PICOXRInputFunctionLibrary_eventPXR_SaveVibrateByCache_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::PICOXRInputFunctionLibrary_eventPXR_SaveVibrateByCache_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_SetArmModelParameters_Parms
		{
			EPICOXRGazeBehavior GazeType;
			EPICOXRArmModelJoint ArmJoint;
			float ElbowHeight;
			float ElbowDepth;
			float PointerTiltAngle;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_GazeType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_GazeType;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ArmJoint_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ArmJoint;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ElbowHeight;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ElbowDepth;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PointerTiltAngle;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::NewProp_GazeType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::NewProp_GazeType = { "GazeType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetArmModelParameters_Parms, GazeType), Z_Construct_UEnum_PICOXRInput_EPICOXRGazeBehavior, METADATA_PARAMS(0, nullptr) }; // 120591347
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::NewProp_ArmJoint_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::NewProp_ArmJoint = { "ArmJoint", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetArmModelParameters_Parms, ArmJoint), Z_Construct_UEnum_PICOXRInput_EPICOXRArmModelJoint, METADATA_PARAMS(0, nullptr) }; // 1116113137
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::NewProp_ElbowHeight = { "ElbowHeight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetArmModelParameters_Parms, ElbowHeight), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::NewProp_ElbowDepth = { "ElbowDepth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetArmModelParameters_Parms, ElbowDepth), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::NewProp_PointerTiltAngle = { "PointerTiltAngle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetArmModelParameters_Parms, PointerTiltAngle), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetArmModelParameters_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::NewProp_GazeType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::NewProp_GazeType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::NewProp_ArmJoint_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::NewProp_ArmJoint,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::NewProp_ElbowHeight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::NewProp_ElbowDepth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::NewProp_PointerTiltAngle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::Function_MetaDataParams[] = {
		{ "ArmJoint", "Controller" },
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Set controller arm model parameter.\n\x09* @param GazeType          (In) The gaze type(Never/DuringMotion/Always).\n\x09* @param ArmJoint          (In) The arm joint(Controller/Wrist/Elbow/Shoulder).\n\x09* @param ElbowHeight       (In) The Height of the elbow(cm).Min=0.0f, Max=20.0f.\n\x09* @param ElbowDepth        (In) The Depth of the elbow(cm).Min=0.0f, Max=20.0f.\n\x09* @param PointerTiltAngle  (In) The Downward tilt or pitch of the laser pointer relative to the controller (degrees).Min=0.0f, Max=30.0f.\n\x09*/" },
#endif
		{ "ElbowDepth", "0.0" },
		{ "ElbowHeight", "0.0" },
		{ "GazeType", "DuringMotion" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
		{ "PointerTiltAngle", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set controller arm model parameter.\n@param GazeType          (In) The gaze type(Never/DuringMotion/Always).\n@param ArmJoint          (In) The arm joint(Controller/Wrist/Elbow/Shoulder).\n@param ElbowHeight       (In) The Height of the elbow(cm).Min=0.0f, Max=20.0f.\n@param ElbowDepth        (In) The Depth of the elbow(cm).Min=0.0f, Max=20.0f.\n@param PointerTiltAngle  (In) The Downward tilt or pitch of the laser pointer relative to the controller (degrees).Min=0.0f, Max=30.0f." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_SetArmModelParameters", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::PICOXRInputFunctionLibrary_eventPXR_SetArmModelParameters_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::PICOXRInputFunctionLibrary_eventPXR_SetArmModelParameters_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_SetBodyTrackingBoneLength_Parms
		{
			FBodyTrackingBoneLength BoneLength;
			int32 OtherMode;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BoneLength_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_BoneLength;
		static const UECodeGen_Private::FIntPropertyParams NewProp_OtherMode;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength_Statics::NewProp_BoneLength_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength_Statics::NewProp_BoneLength = { "BoneLength", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetBodyTrackingBoneLength_Parms, BoneLength), Z_Construct_UScriptStruct_FBodyTrackingBoneLength, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength_Statics::NewProp_BoneLength_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength_Statics::NewProp_BoneLength_MetaData) }; // 399108386
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength_Statics::NewProp_OtherMode = { "OtherMode", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetBodyTrackingBoneLength_Parms, OtherMode), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventPXR_SetBodyTrackingBoneLength_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventPXR_SetBodyTrackingBoneLength_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength_Statics::NewProp_BoneLength,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength_Statics::NewProp_OtherMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "OtherMode" },
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Sets bone lengths for different parts of the avatar. The data will be sent to PICO algorithm to make the avatar's poses more accurate. \n/// </summary>\n/// <param name=\"BoneLength\">Sets the bone lengths for different parts of the avatar. See the `FBodyTrackingBoneLength` for details.</param>\n/// <param name=\"OtherMode\"> (In) An additional Swift Tracking Mode. If this value is not -1, use this parameter instead of default mode. </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "CPP_Default_OtherMode", "-1" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nSets bone lengths for different parts of the avatar. The data will be sent to PICO algorithm to make the avatar's poses more accurate.\n</summary>\n<param name=\"BoneLength\">Sets the bone lengths for different parts of the avatar. See the `FBodyTrackingBoneLength` for details.</param>\n<param name=\"OtherMode\"> (In) An additional Swift Tracking Mode. If this value is not -1, use this parameter instead of default mode. </param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_SetBodyTrackingBoneLength", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength_Statics::PICOXRInputFunctionLibrary_eventPXR_SetBodyTrackingBoneLength_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength_Statics::PICOXRInputFunctionLibrary_eventPXR_SetBodyTrackingBoneLength_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_SetBodyTrackingMode_Parms
		{
			EBodyTrackingMode Mode;
			int32 OtherMode;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_Mode_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Mode;
		static const UECodeGen_Private::FIntPropertyParams NewProp_OtherMode;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode_Statics::NewProp_Mode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode_Statics::NewProp_Mode = { "Mode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetBodyTrackingMode_Parms, Mode), Z_Construct_UEnum_PICOXRInput_EBodyTrackingMode, METADATA_PARAMS(0, nullptr) }; // 2823689648
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode_Statics::NewProp_OtherMode = { "OtherMode", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetBodyTrackingMode_Parms, OtherMode), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventPXR_SetBodyTrackingMode_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventPXR_SetBodyTrackingMode_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode_Statics::NewProp_Mode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode_Statics::NewProp_Mode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode_Statics::NewProp_OtherMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "OtherMode" },
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Sets a body tracking mode for PICO Motion Tracker. If this API is not called, the mode defaults to leg tracking.\n/// @note If you want to set the mode to full-body tracking, you must call this API before calling `PXR_StartMotionTrackerCalibApp`.\n/// </summary>\n/// <param name=\"Mode\">Selects a body tracking mode from the following:\n/// * `0`: The default leg tracking, nodes numbered 0 to 15 in `EPxrBodyTrackerRole` enum will return data.\n/// * `1`: full-body tracking, nodes numbered 0 to 23 in `EPxrBodyTrackerRole` enum will return data.\n/// </param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: success</li>\n/// <li>`false`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "CPP_Default_OtherMode", "-1" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nSets a body tracking mode for PICO Motion Tracker. If this API is not called, the mode defaults to leg tracking.\n@note If you want to set the mode to full-body tracking, you must call this API before calling `PXR_StartMotionTrackerCalibApp`.\n</summary>\n<param name=\"Mode\">Selects a body tracking mode from the following:\n* `0`: The default leg tracking, nodes numbered 0 to 15 in `EPxrBodyTrackerRole` enum will return data.\n* `1`: full-body tracking, nodes numbered 0 to 23 in `EPxrBodyTrackerRole` enum will return data.\n</param>\n<returns>Bool:\n<ul>\n<li>`true`: success</li>\n<li>`false`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_SetBodyTrackingMode", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode_Statics::PICOXRInputFunctionLibrary_eventPXR_SetBodyTrackingMode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode_Statics::PICOXRInputFunctionLibrary_eventPXR_SetBodyTrackingMode_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingStaticCalibState_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_SetBodyTrackingStaticCalibState_Parms
		{
			int32 calibstate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_calibstate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingStaticCalibState_Statics::NewProp_calibstate = { "calibstate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetBodyTrackingStaticCalibState_Parms, calibstate), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingStaticCalibState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventPXR_SetBodyTrackingStaticCalibState_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingStaticCalibState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventPXR_SetBodyTrackingStaticCalibState_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingStaticCalibState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingStaticCalibState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingStaticCalibState_Statics::NewProp_calibstate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingStaticCalibState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingStaticCalibState_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// This interface is unavailable at this time.\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "This interface is unavailable at this time." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingStaticCalibState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_SetBodyTrackingStaticCalibState", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingStaticCalibState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingStaticCalibState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingStaticCalibState_Statics::PICOXRInputFunctionLibrary_eventPXR_SetBodyTrackingStaticCalibState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingStaticCalibState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingStaticCalibState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingStaticCalibState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingStaticCalibState_Statics::PICOXRInputFunctionLibrary_eventPXR_SetBodyTrackingStaticCalibState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingStaticCalibState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingStaticCalibState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerAmp_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_SetControllerAmp_Parms
		{
			float mode;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_mode;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerAmp_Statics::NewProp_mode = { "mode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetControllerAmp_Parms, mode), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerAmp_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetControllerAmp_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerAmp_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerAmp_Statics::NewProp_mode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerAmp_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerAmp_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Sets the amplitude of audio-based vibration. You can change the vibration amplitude during audio playback.</summary>\n/// <param name =\"mode\">(In) Vibration amplitude level. The range is 0.0 to 2.0:\n/// <ul>\n/// <li>`0.0`: for no vibration</li>\n/// <li>`1.0`: for standard amplitude</li>\n/// <li>`2.0`: for double the standard amplitude</li>\n/// </ul>\n/// </param>\n/// <returns>\n/// <ul>\n/// <li>`0`: success</li>\n/// <li>`-1`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Sets the amplitude of audio-based vibration. You can change the vibration amplitude during audio playback.</summary>\n<param name =\"mode\">(In) Vibration amplitude level. The range is 0.0 to 2.0:\n<ul>\n<li>`0.0`: for no vibration</li>\n<li>`1.0`: for standard amplitude</li>\n<li>`2.0`: for double the standard amplitude</li>\n</ul>\n</param>\n<returns>\n<ul>\n<li>`0`: success</li>\n<li>`-1`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerAmp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_SetControllerAmp", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerAmp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerAmp_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerAmp_Statics::PICOXRInputFunctionLibrary_eventPXR_SetControllerAmp_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerAmp_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerAmp_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerAmp_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerAmp_Statics::PICOXRInputFunctionLibrary_eventPXR_SetControllerAmp_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerAmp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerAmp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_SetControllerEnableKey_Parms
		{
			bool isEnable;
			EPxrControllerKeyMap Key;
			int32 ReturnValue;
		};
		static void NewProp_isEnable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isEnable;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Key_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Key;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::NewProp_isEnable_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventPXR_SetControllerEnableKey_Parms*)Obj)->isEnable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::NewProp_isEnable = { "isEnable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventPXR_SetControllerEnableKey_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::NewProp_isEnable_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::NewProp_Key_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetControllerEnableKey_Parms, Key), Z_Construct_UEnum_PICOXRInput_EPxrControllerKeyMap, METADATA_PARAMS(0, nullptr) }; // 3572955341
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetControllerEnableKey_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::NewProp_isEnable,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::NewProp_Key_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::NewProp_Key,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_SetControllerEnableKey", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::PICOXRInputFunctionLibrary_eventPXR_SetControllerEnableKey_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::PICOXRInputFunctionLibrary_eventPXR_SetControllerEnableKey_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_SetControllerOriginOffset_Parms
		{
			EPICOXRControllerType Controller;
			FVector Offset;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_Controller_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Controller;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Offset;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::NewProp_Controller_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::NewProp_Controller = { "Controller", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetControllerOriginOffset_Parms, Controller), Z_Construct_UEnum_PICOXRInput_EPICOXRControllerType, METADATA_PARAMS(0, nullptr) }; // 3139224973
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::NewProp_Offset = { "Offset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetControllerOriginOffset_Parms, Offset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::NewProp_Controller_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::NewProp_Controller,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::NewProp_Offset,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Sets the offset of the controller's display position to its real position.</summary>\n/// <param name =\"Controller\">(In) (EPICOXRControllerType)Enum, the controller to set the origin offset for:\n/// <ul>\n/// <li>`LeftHand`: left controller</li>\n/// <li>`RightHand`: right controller</li>\n/// </ul>\n/// </param>\n/// <param name =\"Offset\">(In) Vector, the origin offset (in meters). </param>\n/// <returns>None </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Sets the offset of the controller's display position to its real position.</summary>\n<param name =\"Controller\">(In) (EPICOXRControllerType)Enum, the controller to set the origin offset for:\n<ul>\n<li>`LeftHand`: left controller</li>\n<li>`RightHand`: right controller</li>\n</ul>\n</param>\n<param name =\"Offset\">(In) Vector, the origin offset (in meters). </param>\n<returns>None </returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_SetControllerOriginOffset", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::PICOXRInputFunctionLibrary_eventPXR_SetControllerOriginOffset_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::PICOXRInputFunctionLibrary_eventPXR_SetControllerOriginOffset_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerOriginOffset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerOriginOffset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_SetControllerVibrationEvent_Parms
		{
			int32 deviceID;
			int32 frequency;
			float strength;
			int32 time;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_deviceID;
		static const UECodeGen_Private::FIntPropertyParams NewProp_frequency;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_strength;
		static const UECodeGen_Private::FIntPropertyParams NewProp_time;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent_Statics::NewProp_deviceID = { "deviceID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetControllerVibrationEvent_Parms, deviceID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent_Statics::NewProp_frequency = { "frequency", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetControllerVibrationEvent_Parms, frequency), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent_Statics::NewProp_strength = { "strength", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetControllerVibrationEvent_Parms, strength), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent_Statics::NewProp_time = { "time", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetControllerVibrationEvent_Parms, time), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetControllerVibrationEvent_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent_Statics::NewProp_deviceID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent_Statics::NewProp_frequency,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent_Statics::NewProp_strength,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent_Statics::NewProp_time,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Enables event-based vibration (with customizable vibration frequency).</summary>\n/// <param name =\"deviceID\">(In) specifies which controller to enable event-based vibration:\n/// <ul>\n/// <li>`0`: left controller</li>\n/// <li>`1`: right controller</li>\n/// </ul>\n/// </param>\n/// <param name =\"frequency\">(In) Vibration frequency. `50` to `500` Hz </param>\n/// <param name =\"strength\">(In)  Vibration amplitude. `0` to `1`. The higher the value, the stronger the vibration amplitude. </param>\n/// <param name =\"time\">(In) Vibration duration, `0` to `65535` ms. </param>\n/// <returns>\n/// <ul>\n/// <li>`0`: success</li>\n/// <li>`-1`: failure</li>\n/// </ul>\n/// </returns>\n/// <summary>\n/// **Notes**\n/// <ul>\n/// <li> To disable event-based vibration, you can call `PXR_SetControllerVibrationEvent`, and set `Strength` and `time` to `0`.</li>\n/// <li>Set the vibration frequency according to the scene. Low frequency for soft object collisions, and high frequency for hard object collisions, refer to the table below.</li>\n/// </ul>\n/// |  Scenes | Recommended frequency |\n/// | --- | --- |\n/// |  Playing drums, playing basketball | Low frequencies, 50~100 Hz |\n/// |  Using pistols, playing ping pong | Medium frequency, approx. 170Hz |\n/// |  Stones collision | High frequency, approx. 300Hz |\n/// <summary>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Enables event-based vibration (with customizable vibration frequency).</summary>\n<param name =\"deviceID\">(In) specifies which controller to enable event-based vibration:\n<ul>\n<li>`0`: left controller</li>\n<li>`1`: right controller</li>\n</ul>\n</param>\n<param name =\"frequency\">(In) Vibration frequency. `50` to `500` Hz </param>\n<param name =\"strength\">(In)  Vibration amplitude. `0` to `1`. The higher the value, the stronger the vibration amplitude. </param>\n<param name =\"time\">(In) Vibration duration, `0` to `65535` ms. </param>\n<returns>\n<ul>\n<li>`0`: success</li>\n<li>`-1`: failure</li>\n</ul>\n</returns>\n<summary>\n**Notes**\n<ul>\n<li> To disable event-based vibration, you can call `PXR_SetControllerVibrationEvent`, and set `Strength` and `time` to `0`.</li>\n<li>Set the vibration frequency according to the scene. Low frequency for soft object collisions, and high frequency for hard object collisions, refer to the table below.</li>\n</ul>\n|  Scenes | Recommended frequency |\n| --- | --- |\n|  Playing drums, playing basketball | Low frequencies, 50~100 Hz |\n|  Using pistols, playing ping pong | Medium frequency, approx. 170Hz |\n|  Stones collision | High frequency, approx. 300Hz |\n<summary>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_SetControllerVibrationEvent", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent_Statics::PICOXRInputFunctionLibrary_eventPXR_SetControllerVibrationEvent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent_Statics::PICOXRInputFunctionLibrary_eventPXR_SetControllerVibrationEvent_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_SetMainControllerHandle_Parms
		{
			EPICOXRHandedness Handedness;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_Handedness_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Handedness;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::NewProp_Handedness_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::NewProp_Handedness = { "Handedness", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetMainControllerHandle_Parms, Handedness), Z_Construct_UEnum_PICOXRInput_EPICOXRHandedness, METADATA_PARAMS(0, nullptr) }; // 1423224410
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventPXR_SetMainControllerHandle_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventPXR_SetMainControllerHandle_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::NewProp_Handedness_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::NewProp_Handedness,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Get the main controller's handedness.\n\x09* @param Handedness     (In) The main controller's handedness. Can be left hand or right hand.\n\x09* @return True if successful in setting the main controller's handedness, false otherwise.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the main controller's handedness.\n@param Handedness     (In) The main controller's handedness. Can be left hand or right hand.\n@return True if successful in setting the main controller's handedness, false otherwise." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_SetMainControllerHandle", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::PICOXRInputFunctionLibrary_eventPXR_SetMainControllerHandle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::PICOXRInputFunctionLibrary_eventPXR_SetMainControllerHandle_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetMainControllerHandle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetMainControllerHandle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetPHFHapticSpeed_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_SetPHFHapticSpeed_Parms
		{
			int32 SourceID;
			float Speed;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_SourceID;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Speed;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetPHFHapticSpeed_Statics::NewProp_SourceID = { "SourceID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetPHFHapticSpeed_Parms, SourceID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetPHFHapticSpeed_Statics::NewProp_Speed = { "Speed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetPHFHapticSpeed_Parms, Speed), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetPHFHapticSpeed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_SetPHFHapticSpeed_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetPHFHapticSpeed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetPHFHapticSpeed_Statics::NewProp_SourceID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetPHFHapticSpeed_Statics::NewProp_Speed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetPHFHapticSpeed_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetPHFHapticSpeed_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Sets the PHF haptic speed.</summary>\n/// <param name =\"SourceID\">(In) Int, a unique control ID for the corresponding vibration. </param>\n/// <param name =\"Speed\">(In) Speed of the haptic stream. </param>\n/// <returns>\n/// <ul>\n/// <li>`0`: success</li>\n/// <li>`-1`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Sets the PHF haptic speed.</summary>\n<param name =\"SourceID\">(In) Int, a unique control ID for the corresponding vibration. </param>\n<param name =\"Speed\">(In) Speed of the haptic stream. </param>\n<returns>\n<ul>\n<li>`0`: success</li>\n<li>`-1`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetPHFHapticSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_SetPHFHapticSpeed", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetPHFHapticSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetPHFHapticSpeed_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetPHFHapticSpeed_Statics::PICOXRInputFunctionLibrary_eventPXR_SetPHFHapticSpeed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetPHFHapticSpeed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetPHFHapticSpeed_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetPHFHapticSpeed_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetPHFHapticSpeed_Statics::PICOXRInputFunctionLibrary_eventPXR_SetPHFHapticSpeed_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetPHFHapticSpeed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetPHFHapticSpeed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartControllerVCMotor_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_StartControllerVCMotor_Parms
		{
			FString file;
			EPICOXRVibrateController slot;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_file;
		static const UECodeGen_Private::FBytePropertyParams NewProp_slot_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_slot;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartControllerVCMotor_Statics::NewProp_file = { "file", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_StartControllerVCMotor_Parms, file), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartControllerVCMotor_Statics::NewProp_slot_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartControllerVCMotor_Statics::NewProp_slot = { "slot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_StartControllerVCMotor_Parms, slot), Z_Construct_UEnum_PICOXRInput_EPICOXRVibrateController, METADATA_PARAMS(0, nullptr) }; // 1498834001
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartControllerVCMotor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_StartControllerVCMotor_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartControllerVCMotor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartControllerVCMotor_Statics::NewProp_file,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartControllerVCMotor_Statics::NewProp_slot_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartControllerVCMotor_Statics::NewProp_slot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartControllerVCMotor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartControllerVCMotor_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Enables audio-based vibration through audio file path.</summary>\n/// <param name =\"file\">(In) audio file path. </param>\n/// <param name =\"slot\">(In) specifies which controller to vibrate with the audio.\n/// <ul>\n/// <li>`No`: none</li>\n/// <li>`Left`: left controller</li>\n/// <li>`Right`: right controller</li>\n/// <li>`LeftAndRight`: both</li>\n/// </ul>\n///  </param>\n/// <returns>\n/// <ul>\n/// <li>`0`: success</li>\n/// <li>`-1`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Enables audio-based vibration through audio file path.</summary>\n<param name =\"file\">(In) audio file path. </param>\n<param name =\"slot\">(In) specifies which controller to vibrate with the audio.\n<ul>\n<li>`No`: none</li>\n<li>`Left`: left controller</li>\n<li>`Right`: right controller</li>\n<li>`LeftAndRight`: both</li>\n</ul>\n </param>\n<returns>\n<ul>\n<li>`0`: success</li>\n<li>`-1`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartControllerVCMotor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_StartControllerVCMotor", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartControllerVCMotor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartControllerVCMotor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartControllerVCMotor_Statics::PICOXRInputFunctionLibrary_eventPXR_StartControllerVCMotor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartControllerVCMotor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartControllerVCMotor_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartControllerVCMotor_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartControllerVCMotor_Statics::PICOXRInputFunctionLibrary_eventPXR_StartControllerVCMotor_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartControllerVCMotor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartControllerVCMotor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartPHFHaptic_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_StartPHFHaptic_Parms
		{
			int32 SourceID;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_SourceID;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartPHFHaptic_Statics::NewProp_SourceID = { "SourceID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_StartPHFHaptic_Parms, SourceID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartPHFHaptic_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_StartPHFHaptic_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartPHFHaptic_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartPHFHaptic_Statics::NewProp_SourceID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartPHFHaptic_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartPHFHaptic_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Starts PHF haptic.</summary>\n/// <param name =\"SourceID\">(In) Int, a unique control ID for the corresponding vibration. </param>\n/// <returns>\n/// <ul>\n/// <li>`0`: success</li>\n/// <li>`-1`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Starts PHF haptic.</summary>\n<param name =\"SourceID\">(In) Int, a unique control ID for the corresponding vibration. </param>\n<returns>\n<ul>\n<li>`0`: success</li>\n<li>`-1`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartPHFHaptic_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_StartPHFHaptic", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartPHFHaptic_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartPHFHaptic_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartPHFHaptic_Statics::PICOXRInputFunctionLibrary_eventPXR_StartPHFHaptic_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartPHFHaptic_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartPHFHaptic_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartPHFHaptic_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartPHFHaptic_Statics::PICOXRInputFunctionLibrary_eventPXR_StartPHFHaptic_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartPHFHaptic()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartPHFHaptic_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByCache_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_StartVibrateByCache_Parms
		{
			int32 SourceId;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_SourceId;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByCache_Statics::NewProp_SourceId = { "SourceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_StartVibrateByCache_Parms, SourceId), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByCache_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_StartVibrateByCache_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByCache_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByCache_Statics::NewProp_SourceId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByCache_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByCache_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Plays the cached audio vibration data.</summary>\n/// <param name =\"SourceId\">(In) the ID returned by another vibration control API. </param>\n/// <returns>\n/// <ul>\n/// <li>`0`: success</li>\n/// <li>`-1`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Plays the cached audio vibration data.</summary>\n<param name =\"SourceId\">(In) the ID returned by another vibration control API. </param>\n<returns>\n<ul>\n<li>`0`: success</li>\n<li>`-1`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByCache_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_StartVibrateByCache", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByCache_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByCache_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByCache_Statics::PICOXRInputFunctionLibrary_eventPXR_StartVibrateByCache_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByCache_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByCache_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByCache_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByCache_Statics::PICOXRInputFunctionLibrary_eventPXR_StartVibrateByCache_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByCache()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByCache_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_StartVibrateByPHF_Parms
		{
			FName DataName;
			EPICOXRVibrateController slot;
			EPICOXRChannelFlip slotConfig;
			float ampValue;
			int32 SourceID;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_DataName;
		static const UECodeGen_Private::FBytePropertyParams NewProp_slot_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_slot;
		static const UECodeGen_Private::FBytePropertyParams NewProp_slotConfig_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_slotConfig;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ampValue;
		static const UECodeGen_Private::FIntPropertyParams NewProp_SourceID;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::NewProp_DataName = { "DataName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_StartVibrateByPHF_Parms, DataName), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::NewProp_slot_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::NewProp_slot = { "slot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_StartVibrateByPHF_Parms, slot), Z_Construct_UEnum_PICOXRInput_EPICOXRVibrateController, METADATA_PARAMS(0, nullptr) }; // 1498834001
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::NewProp_slotConfig_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::NewProp_slotConfig = { "slotConfig", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_StartVibrateByPHF_Parms, slotConfig), Z_Construct_UEnum_PICOXRInput_EPICOXRChannelFlip, METADATA_PARAMS(0, nullptr) }; // 536287980
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::NewProp_ampValue = { "ampValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_StartVibrateByPHF_Parms, ampValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::NewProp_SourceID = { "SourceID", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_StartVibrateByPHF_Parms, SourceID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_StartVibrateByPHF_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::NewProp_DataName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::NewProp_slot_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::NewProp_slot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::NewProp_slotConfig_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::NewProp_slotConfig,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::NewProp_ampValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::NewProp_SourceID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Plays PHF vibration data. You need put your *.phf files in the \"/Plugins/PICOXR/Content/Phf/\" folder.</summary>\n/// <param name =\"DataName\">(In) PHF file resource name. It is in the path \"/Plugins/PICOXR/Content/Blueprint/PHFDataTable.uasset\". </param>\n/// <param name =\"slot\">(In) specifies which controller to vibrate with the audio.\n/// <ul>\n/// <li>`No`: none</li>\n/// <li>`Left`: left controller</li>\n/// <li>`Right`: right controller</li>\n/// <li>`LeftAndRight`: both</li>\n/// </ul>\n/// </param>\n/// <param name =\"slotConfig\">(In) Specifies whether to enable audio channel inversion.\n/// <ul>\n/// <li>`No`: disable</li>\n/// <li>`Yes`: enable</li>\n/// </ul>\n/// </param>\n/// <summary>\n/// @note When slotConfig = `1`, the left controller vibrates with the audio source from right soundtrack, and vice versa.\n/// </summary>\n/// <param name =\"ampValue\">(In) Vibration amplitude level. The range is 0.0 to 2.0:\n/// <ul>\n/// <li>`0.0`: for no vibration</li>\n/// <li>`1.0`: for standard amplitude</li>\n/// <li>`2.0`: for double the standard amplitude</li>\n/// </ul>\n/// </param>\n/// <param name =\"SourceID\">(Out) returns a unique ID for controlling the corresponding vibration, which can be used for subsequent APIs, such as PXR_SaveVibrateByCache, PXR_ClearVibrateByCache and PXR_StopControllerVCMotor.\n/// </param>\n/// <returns>\n/// <ul>\n/// <li>`0`: success</li>\n/// <li>`-1`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Plays PHF vibration data. You need put your *.phf files in the \"/Plugins/PICOXR/Content/Phf/\" folder.</summary>\n<param name =\"DataName\">(In) PHF file resource name. It is in the path \"/Plugins/PICOXR/Content/Blueprint/PHFDataTable.uasset\". </param>\n<param name =\"slot\">(In) specifies which controller to vibrate with the audio.\n<ul>\n<li>`No`: none</li>\n<li>`Left`: left controller</li>\n<li>`Right`: right controller</li>\n<li>`LeftAndRight`: both</li>\n</ul>\n</param>\n<param name =\"slotConfig\">(In) Specifies whether to enable audio channel inversion.\n<ul>\n<li>`No`: disable</li>\n<li>`Yes`: enable</li>\n</ul>\n</param>\n<summary>\n@note When slotConfig = `1`, the left controller vibrates with the audio source from right soundtrack, and vice versa.\n</summary>\n<param name =\"ampValue\">(In) Vibration amplitude level. The range is 0.0 to 2.0:\n<ul>\n<li>`0.0`: for no vibration</li>\n<li>`1.0`: for standard amplitude</li>\n<li>`2.0`: for double the standard amplitude</li>\n</ul>\n</param>\n<param name =\"SourceID\">(Out) returns a unique ID for controlling the corresponding vibration, which can be used for subsequent APIs, such as PXR_SaveVibrateByCache, PXR_ClearVibrateByCache and PXR_StopControllerVCMotor.\n</param>\n<returns>\n<ul>\n<li>`0`: success</li>\n<li>`-1`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_StartVibrateByPHF", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::PICOXRInputFunctionLibrary_eventPXR_StartVibrateByPHF_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::PICOXRInputFunctionLibrary_eventPXR_StartVibrateByPHF_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_StartVibrateBySharem_Parms
		{
			USoundWave* InSoundWave;
			EPICOXRVibrateController slot;
			EPICOXRChannelFlip slotConfig;
			int32 SourceId;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InSoundWave;
		static const UECodeGen_Private::FBytePropertyParams NewProp_slot_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_slot;
		static const UECodeGen_Private::FBytePropertyParams NewProp_slotConfig_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_slotConfig;
		static const UECodeGen_Private::FIntPropertyParams NewProp_SourceId;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::NewProp_InSoundWave = { "InSoundWave", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_StartVibrateBySharem_Parms, InSoundWave), Z_Construct_UClass_USoundWave_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::NewProp_slot_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::NewProp_slot = { "slot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_StartVibrateBySharem_Parms, slot), Z_Construct_UEnum_PICOXRInput_EPICOXRVibrateController, METADATA_PARAMS(0, nullptr) }; // 1498834001
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::NewProp_slotConfig_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::NewProp_slotConfig = { "slotConfig", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_StartVibrateBySharem_Parms, slotConfig), Z_Construct_UEnum_PICOXRInput_EPICOXRChannelFlip, METADATA_PARAMS(0, nullptr) }; // 536287980
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::NewProp_SourceId = { "SourceId", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_StartVibrateBySharem_Parms, SourceId), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_StartVibrateBySharem_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::NewProp_InSoundWave,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::NewProp_slot_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::NewProp_slot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::NewProp_slotConfig_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::NewProp_slotConfig,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::NewProp_SourceId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Enables audio-based vibration through the audio asset passed into the engine.</summary>\n/// <param name =\"InSoundWave\">(In) audio asset (\"SoundWave\" Asset type) </param>\n/// <param name =\"slot\">(In) specifies which controller to vibrate with the audio.\n/// <ul>\n/// <li>`No`: none</li>\n/// <li>`Left`: left controller</li>\n/// <li>`Right`: right controller</li>\n/// <li>`LeftAndRight`: both</li>\n/// </ul>\n/// </param>\n/// <param name =\"slotConfig\">(In) Specifies whether to enable audio channel inversion.\n/// <ul>\n/// <li>`No`: disable</li>\n/// <li>`Yes`: enable</li>\n/// </ul>\n/// </param>\n/// <summary>\n/// @note When slotConfig = `1`, the left controller vibrates with the audio source from right soundtrack, and vice versa.\n/// </summary>\n/// <param name =\"SourceId\">(Out) returns a unique ID for controlling the corresponding vibration, which can be used for subsequent APIs, such as PXR_SaveVibrateByCache, PXR_ClearVibrateByCache and PXR_StopControllerVCMotor. </param>\n/// <returns>\n/// <ul>\n/// <li>`0`: success</li>\n/// <li>`-1`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Enables audio-based vibration through the audio asset passed into the engine.</summary>\n<param name =\"InSoundWave\">(In) audio asset (\"SoundWave\" Asset type) </param>\n<param name =\"slot\">(In) specifies which controller to vibrate with the audio.\n<ul>\n<li>`No`: none</li>\n<li>`Left`: left controller</li>\n<li>`Right`: right controller</li>\n<li>`LeftAndRight`: both</li>\n</ul>\n</param>\n<param name =\"slotConfig\">(In) Specifies whether to enable audio channel inversion.\n<ul>\n<li>`No`: disable</li>\n<li>`Yes`: enable</li>\n</ul>\n</param>\n<summary>\n@note When slotConfig = `1`, the left controller vibrates with the audio source from right soundtrack, and vice versa.\n</summary>\n<param name =\"SourceId\">(Out) returns a unique ID for controlling the corresponding vibration, which can be used for subsequent APIs, such as PXR_SaveVibrateByCache, PXR_ClearVibrateByCache and PXR_StopControllerVCMotor. </param>\n<returns>\n<ul>\n<li>`0`: success</li>\n<li>`-1`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_StartVibrateBySharem", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::PICOXRInputFunctionLibrary_eventPXR_StartVibrateBySharem_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::PICOXRInputFunctionLibrary_eventPXR_StartVibrateBySharem_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopControllerVCMotor_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_StopControllerVCMotor_Parms
		{
			int32 clientId;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_clientId;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopControllerVCMotor_Statics::NewProp_clientId = { "clientId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_StopControllerVCMotor_Parms, clientId), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopControllerVCMotor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_StopControllerVCMotor_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopControllerVCMotor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopControllerVCMotor_Statics::NewProp_clientId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopControllerVCMotor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopControllerVCMotor_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Stops audio-based vibration.</summary>\n/// <param name =\"clientId\">(In) a reserved parameter, set it to the `sourceId` returned by another vibration control API to stop the corresponding vibration, or set it to `0` to stop all vibrations.\n/// </param>\n/// <returns>\n/// <ul>\n/// <li>`0`: success</li>\n/// <li>`-1`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Stops audio-based vibration.</summary>\n<param name =\"clientId\">(In) a reserved parameter, set it to the `sourceId` returned by another vibration control API to stop the corresponding vibration, or set it to `0` to stop all vibrations.\n</param>\n<returns>\n<ul>\n<li>`0`: success</li>\n<li>`-1`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopControllerVCMotor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_StopControllerVCMotor", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopControllerVCMotor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopControllerVCMotor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopControllerVCMotor_Statics::PICOXRInputFunctionLibrary_eventPXR_StopControllerVCMotor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopControllerVCMotor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopControllerVCMotor_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopControllerVCMotor_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopControllerVCMotor_Statics::PICOXRInputFunctionLibrary_eventPXR_StopControllerVCMotor_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopControllerVCMotor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopControllerVCMotor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopPHFHaptic_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_StopPHFHaptic_Parms
		{
			int32 SourceID;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_SourceID;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopPHFHaptic_Statics::NewProp_SourceID = { "SourceID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_StopPHFHaptic_Parms, SourceID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopPHFHaptic_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_StopPHFHaptic_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopPHFHaptic_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopPHFHaptic_Statics::NewProp_SourceID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopPHFHaptic_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopPHFHaptic_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Stops PHF haptic.</summary>\n/// <param name =\"SourceID\">(In) Int, a unique control ID for the corresponding vibration. </param>\n/// <returns>\n/// <ul>\n/// <li>`0`: success</li>\n/// <li>`-1`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Stops PHF haptic.</summary>\n<param name =\"SourceID\">(In) Int, a unique control ID for the corresponding vibration. </param>\n<returns>\n<ul>\n<li>`0`: success</li>\n<li>`-1`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopPHFHaptic_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_StopPHFHaptic", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopPHFHaptic_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopPHFHaptic_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopPHFHaptic_Statics::PICOXRInputFunctionLibrary_eventPXR_StopPHFHaptic_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopPHFHaptic_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopPHFHaptic_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopPHFHaptic_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopPHFHaptic_Statics::PICOXRInputFunctionLibrary_eventPXR_StopPHFHaptic_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopPHFHaptic()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopPHFHaptic_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_UpdateVibrateParams_Parms
		{
			int32 SourceID;
			EPICOXRVibrateController slot;
			EPICOXRChannelFlip slotConfig;
			float AmpValue;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_SourceID;
		static const UECodeGen_Private::FBytePropertyParams NewProp_slot_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_slot;
		static const UECodeGen_Private::FBytePropertyParams NewProp_slotConfig_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_slotConfig;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AmpValue;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::NewProp_SourceID = { "SourceID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_UpdateVibrateParams_Parms, SourceID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::NewProp_slot_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::NewProp_slot = { "slot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_UpdateVibrateParams_Parms, slot), Z_Construct_UEnum_PICOXRInput_EPICOXRVibrateController, METADATA_PARAMS(0, nullptr) }; // 1498834001
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::NewProp_slotConfig_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::NewProp_slotConfig = { "slotConfig", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_UpdateVibrateParams_Parms, slotConfig), Z_Construct_UEnum_PICOXRInput_EPICOXRChannelFlip, METADATA_PARAMS(0, nullptr) }; // 536287980
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::NewProp_AmpValue = { "AmpValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_UpdateVibrateParams_Parms, AmpValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_UpdateVibrateParams_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::NewProp_SourceID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::NewProp_slot_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::NewProp_slot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::NewProp_slotConfig_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::NewProp_slotConfig,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::NewProp_AmpValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Dynamically modifies PHF and AudioClip vibration data.</summary>\n/// <param name =\"SourceID\">(In) ID returned by another vibration control API. </param>\n/// <param name =\"slot\">(In) specifies which controller to vibrate with the audio.\n/// <ul>\n/// <li>`No`: none</li>\n/// <li>`Left`: left controller</li>\n/// <li>`Right`: right controller</li>\n/// <li>`LeftAndRight`: both</li>\n/// </ul>\n/// </param>\n/// <param name =\"slotConfig\">(In) Specifies whether to enable audio channel inversion.\n/// <ul>\n/// <li>`No`: disable</li>\n/// <li>`Yes`: enable</li>\n/// </ul>\n/// </param>\n/// <summary>\n/// @note When slotConfig = `1`, the left controller vibrates with the audio source from right soundtrack, and vice versa.\n/// </summary>\n/// <param name =\"AmpValue\">(In) Vibration amplitude level. The range is 0.0 to 2.0:\n/// <ul>\n/// <li>`0.0`: for no vibration</li>\n/// <li>`1.0`: for standard amplitude</li>\n/// <li>`2.0`: for double the standard amplitude</li>\n/// </ul>\n/// </param>\n/// <returns>\n/// <ul>\n/// <li>`0`: success</li>\n/// <li>`-1`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Dynamically modifies PHF and AudioClip vibration data.</summary>\n<param name =\"SourceID\">(In) ID returned by another vibration control API. </param>\n<param name =\"slot\">(In) specifies which controller to vibrate with the audio.\n<ul>\n<li>`No`: none</li>\n<li>`Left`: left controller</li>\n<li>`Right`: right controller</li>\n<li>`LeftAndRight`: both</li>\n</ul>\n</param>\n<param name =\"slotConfig\">(In) Specifies whether to enable audio channel inversion.\n<ul>\n<li>`No`: disable</li>\n<li>`Yes`: enable</li>\n</ul>\n</param>\n<summary>\n@note When slotConfig = `1`, the left controller vibrates with the audio source from right soundtrack, and vice versa.\n</summary>\n<param name =\"AmpValue\">(In) Vibration amplitude level. The range is 0.0 to 2.0:\n<ul>\n<li>`0.0`: for no vibration</li>\n<li>`1.0`: for standard amplitude</li>\n<li>`2.0`: for double the standard amplitude</li>\n</ul>\n</param>\n<returns>\n<ul>\n<li>`0`: success</li>\n<li>`-1`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_UpdateVibrateParams", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::PICOXRInputFunctionLibrary_eventPXR_UpdateVibrateParams_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::PICOXRInputFunctionLibrary_eventPXR_UpdateVibrateParams_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_VibrateController_Parms
		{
			EPICOXRControllerType ControllerType;
			float Strength;
			int32 Time;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ControllerType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ControllerType;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Strength;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Time;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_ControllerType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_ControllerType = { "ControllerType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_VibrateController_Parms, ControllerType), Z_Construct_UEnum_PICOXRInput_EPICOXRControllerType, METADATA_PARAMS(0, nullptr) }; // 3139224973
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_Strength = { "Strength", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_VibrateController_Parms, Strength), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_Time = { "Time", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_VibrateController_Parms, Time), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOXRInputFunctionLibrary_eventPXR_VibrateController_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOXRInputFunctionLibrary_eventPXR_VibrateController_Parms), &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_ControllerType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_ControllerType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_Strength,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_Time,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Enables event-based vibration (with default vibration frequency). If you are not sensitive to vibration frequency, use this interface. This interface will use recommended frequencies to provide a more suitable frequency vibration.\n\x09* @param ControllerType    (In) Enum, specifies which controller enables event vibration:\n\x09* - PICO LeftHand: Left controller\n    * - PICO RightHand: Right controller\n    * - PICO G2 Hand:  Both the left and right controller\n\x09* @param Strength          (In) Float, vibration amplitude, 0 to 1. The higher the value, the stronger the vibration amplitude.\n\x09* @param Time              (In) Int, vibration duration, from 0 to 65535 ms.\n\x09* @return   Bool:\n\x09* - True: Success\n\x09* - False: Failure\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enables event-based vibration (with default vibration frequency). If you are not sensitive to vibration frequency, use this interface. This interface will use recommended frequencies to provide a more suitable frequency vibration.\n@param ControllerType    (In) Enum, specifies which controller enables event vibration:\n- PICO LeftHand: Left controller\n- PICO RightHand: Right controller\n- PICO G2 Hand:  Both the left and right controller\n@param Strength          (In) Float, vibration amplitude, 0 to 1. The higher the value, the stronger the vibration amplitude.\n@param Time              (In) Int, vibration duration, from 0 to 65535 ms.\n@return   Bool:\n- True: Success\n- False: Failure" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_VibrateController", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics::PICOXRInputFunctionLibrary_eventPXR_VibrateController_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics::PICOXRInputFunctionLibrary_eventPXR_VibrateController_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics
	{
		struct PICOXRInputFunctionLibrary_eventPXR_WriteHapticStream_Parms
		{
			int32 SourceID;
			FPHFJsonData frames;
			int32 From;
			int32 NumFrames;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_SourceID;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_frames_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_frames;
		static const UECodeGen_Private::FIntPropertyParams NewProp_From;
		static const UECodeGen_Private::FIntPropertyParams NewProp_NumFrames;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::NewProp_SourceID = { "SourceID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_WriteHapticStream_Parms, SourceID), METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::NewProp_frames_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::NewProp_frames = { "frames", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_WriteHapticStream_Parms, frames), Z_Construct_UScriptStruct_FPHFJsonData, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::NewProp_frames_MetaData), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::NewProp_frames_MetaData) }; // 1262856970
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::NewProp_From = { "From", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_WriteHapticStream_Parms, From), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::NewProp_NumFrames = { "NumFrames", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_WriteHapticStream_Parms, NumFrames), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOXRInputFunctionLibrary_eventPXR_WriteHapticStream_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::NewProp_SourceID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::NewProp_frames,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::NewProp_From,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::NewProp_NumFrames,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRInput" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Writes vibration data in the corresponding stream.</summary>\n/// <param name =\"SourceID\">(In) Int, ID returned by another vibration control API. </param>\n/// <param name =\"frames\">(In) PHF data. </param>\n/// <param name =\"From\">(In) Int, specifies from which element of the array to start sending from. </param>\n/// <param name =\"NumFrames\">(In) Int, specifies how many elements to send. </param>\n/// <returns>\n/// <ul>\n/// <li>`0`: success</li>\n/// <li>`-1`: failure</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Writes vibration data in the corresponding stream.</summary>\n<param name =\"SourceID\">(In) Int, ID returned by another vibration control API. </param>\n<param name =\"frames\">(In) PHF data. </param>\n<param name =\"From\">(In) Int, specifies from which element of the array to start sending from. </param>\n<param name =\"NumFrames\">(In) Int, specifies how many elements to send. </param>\n<returns>\n<ul>\n<li>`0`: success</li>\n<li>`-1`: failure</li>\n</ul>\n</returns>" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOXRInputFunctionLibrary, nullptr, "PXR_WriteHapticStream", nullptr, nullptr, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::PICOXRInputFunctionLibrary_eventPXR_WriteHapticStream_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::PICOXRInputFunctionLibrary_eventPXR_WriteHapticStream_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPICOXRInputFunctionLibrary);
	UClass* Z_Construct_UClass_UPICOXRInputFunctionLibrary_NoRegister()
	{
		return UPICOXRInputFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UPICOXRInputFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPICOXRInputFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRInput,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRInputFunctionLibrary_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPICOXRInputFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetActiveInputDevice, "GetActiveInputDevice" }, // 4286180480
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneLocation, "GetBoneLocation" }, // 2389173010
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRadii, "GetBoneRadii" }, // 2777751467
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetBoneRotation, "GetBoneRotation" }, // 4067013737
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandRootPose, "GetHandRootPose" }, // 2231880046
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetHandScale, "GetHandScale" }, // 2965298449
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetPinchStrength, "GetPinchStrength" }, // 2823648387
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetRayPose, "GetRayPose" }, // 3241932006
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_GetTrackingConfidence, "GetTrackingConfidence" }, // 2473645486
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationTracked, "IsBoneOrientationTracked" }, // 574899041
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBoneOrientationValid, "IsBoneOrientationValid" }, // 3395220266
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionTracked, "IsBonePositionTracked" }, // 1588099513
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsBonePositionValid, "IsBonePositionValid" }, // 3562578727
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsComputed, "IsComputed" }, // 373053699
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsHandTrackingEnabled, "IsHandTrackingEnabled" }, // 938682664
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsPinchValid, "IsPinchValid" }, // 3124692617
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_IsRayValid, "IsRayValid" }, // 2365719042
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ClearVibrateByCache, "PXR_ClearVibrateByCache" }, // 2587859996
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_CreateHapticStream, "PXR_CreateHapticStream" }, // 813554892
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPose, "PXR_GetBodyTrackingPose" }, // 1968025542
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetBodyTrackingPoseByRole, "PXR_GetBodyTrackingPoseByRole" }, // 702250149
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAcceleration, "PXR_GetControllerAcceleration" }, // 2552694662
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerAngularVelocity, "PXR_GetControllerAngularVelocity" }, // 2643429318
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerConnectionState, "PXR_GetControllerConnectionState" }, // 786773092
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerDeviceType, "PXR_GetControllerDeviceType" }, // 1656571317
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerEnableHomekey, "PXR_GetControllerEnableHomekey" }, // 1854109757
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerLinearVelocity, "PXR_GetControllerLinearVelocity" }, // 2141053232
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPower, "PXR_GetControllerPower" }, // 1553559980
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetControllerPredictedLocationAndRotation, "PXR_GetControllerPredictedLocationAndRotation" }, // 1203828153
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetCurrentFrameSequence, "PXR_GetCurrentFrameSequence" }, // 933996952
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetHandedness, "PXR_GetHandedness" }, // 327387715
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMainControllerHandle, "PXR_GetMainControllerHandle" }, // 1922520545
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerBattery, "PXR_GetMotionTrackerBattery" }, // 217384514
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerCalibState, "PXR_GetMotionTrackerCalibState" }, // 2108409699
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetMotionTrackerConnectStateWithId, "PXR_GetMotionTrackerConnectStateWithId" }, // 3046671754
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_GetPHFHapticSpeed, "PXR_GetPHFHapticSpeed" }, // 2572321424
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_PauseVibrate, "PXR_PauseVibrate" }, // 1120780259
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_RemovePHFHaptic, "PXR_RemovePHFHaptic" }, // 3113009074
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResetController, "PXR_ResetController" }, // 3972472980
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_ResumeVibrate, "PXR_ResumeVibrate" }, // 4250285109
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SaveVibrateByCache, "PXR_SaveVibrateByCache" }, // 912497877
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetArmModelParameters, "PXR_SetArmModelParameters" }, // 2432477989
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingBoneLength, "PXR_SetBodyTrackingBoneLength" }, // 450368911
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingMode, "PXR_SetBodyTrackingMode" }, // 2323768511
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetBodyTrackingStaticCalibState, "PXR_SetBodyTrackingStaticCalibState" }, // 3474138638
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerAmp, "PXR_SetControllerAmp" }, // 524836336
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerEnableKey, "PXR_SetControllerEnableKey" }, // 3224278653
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerOriginOffset, "PXR_SetControllerOriginOffset" }, // 1779186665
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetControllerVibrationEvent, "PXR_SetControllerVibrationEvent" }, // 2188578977
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetMainControllerHandle, "PXR_SetMainControllerHandle" }, // 1990172692
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_SetPHFHapticSpeed, "PXR_SetPHFHapticSpeed" }, // 4094508266
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartControllerVCMotor, "PXR_StartControllerVCMotor" }, // 1785642567
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartPHFHaptic, "PXR_StartPHFHaptic" }, // 2745611207
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByCache, "PXR_StartVibrateByCache" }, // 59584393
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateByPHF, "PXR_StartVibrateByPHF" }, // 865886116
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StartVibrateBySharem, "PXR_StartVibrateBySharem" }, // 4036899045
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopControllerVCMotor, "PXR_StopControllerVCMotor" }, // 3053890323
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_StopPHFHaptic, "PXR_StopPHFHaptic" }, // 3056963418
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_UpdateVibrateParams, "PXR_UpdateVibrateParams" }, // 325799047
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_VibrateController, "PXR_VibrateController" }, // 2029528161
		{ &Z_Construct_UFunction_UPICOXRInputFunctionLibrary_PXR_WriteHapticStream, "PXR_WriteHapticStream" }, // 2070827263
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRInputFunctionLibrary_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRInputFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PXR_InputFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/PXR_InputFunctionLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPICOXRInputFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPICOXRInputFunctionLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPICOXRInputFunctionLibrary_Statics::ClassParams = {
		&UPICOXRInputFunctionLibrary::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRInputFunctionLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UPICOXRInputFunctionLibrary_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPICOXRInputFunctionLibrary()
	{
		if (!Z_Registration_Info_UClass_UPICOXRInputFunctionLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPICOXRInputFunctionLibrary.OuterSingleton, Z_Construct_UClass_UPICOXRInputFunctionLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPICOXRInputFunctionLibrary.OuterSingleton;
	}
	template<> PICOXRINPUT_API UClass* StaticClass<UPICOXRInputFunctionLibrary>()
	{
		return UPICOXRInputFunctionLibrary::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPICOXRInputFunctionLibrary);
	UPICOXRInputFunctionLibrary::~UPICOXRInputFunctionLibrary() {}
	struct Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_Statics::EnumInfo[] = {
		{ EPICOXRHandTrackingConfidence_StaticEnum, TEXT("EPICOXRHandTrackingConfidence"), &Z_Registration_Info_UEnum_EPICOXRHandTrackingConfidence, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2631199562U) },
		{ EPICOXRActiveInputDevice_StaticEnum, TEXT("EPICOXRActiveInputDevice"), &Z_Registration_Info_UEnum_EPICOXRActiveInputDevice, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1632396129U) },
		{ EPICOXRHandFinger_StaticEnum, TEXT("EPICOXRHandFinger"), &Z_Registration_Info_UEnum_EPICOXRHandFinger, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1558947568U) },
		{ EPICOXRHandJoint_StaticEnum, TEXT("EPICOXRHandJoint"), &Z_Registration_Info_UEnum_EPICOXRHandJoint, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2824206454U) },
		{ EPICOXRHandType_StaticEnum, TEXT("EPICOXRHandType"), &Z_Registration_Info_UEnum_EPICOXRHandType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2963561890U) },
		{ EPICOXRHandedness_StaticEnum, TEXT("EPICOXRHandedness"), &Z_Registration_Info_UEnum_EPICOXRHandedness, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1423224410U) },
		{ EPICOXRControllerType_StaticEnum, TEXT("EPICOXRControllerType"), &Z_Registration_Info_UEnum_EPICOXRControllerType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3139224973U) },
		{ EPICOXRArmModelJoint_StaticEnum, TEXT("EPICOXRArmModelJoint"), &Z_Registration_Info_UEnum_EPICOXRArmModelJoint, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1116113137U) },
		{ EPICOXRGazeBehavior_StaticEnum, TEXT("EPICOXRGazeBehavior"), &Z_Registration_Info_UEnum_EPICOXRGazeBehavior, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 120591347U) },
		{ EPICOXRControllerDeviceType_StaticEnum, TEXT("EPICOXRControllerDeviceType"), &Z_Registration_Info_UEnum_EPICOXRControllerDeviceType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3886460524U) },
		{ EPICOXRVibrateController_StaticEnum, TEXT("EPICOXRVibrateController"), &Z_Registration_Info_UEnum_EPICOXRVibrateController, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1498834001U) },
		{ EPICOXRChannelFlip_StaticEnum, TEXT("EPICOXRChannelFlip"), &Z_Registration_Info_UEnum_EPICOXRChannelFlip, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 536287980U) },
		{ EPICOXRCacheConfig_StaticEnum, TEXT("EPICOXRCacheConfig"), &Z_Registration_Info_UEnum_EPICOXRCacheConfig, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1934369178U) },
		{ EBodyActionList_StaticEnum, TEXT("EBodyActionList"), &Z_Registration_Info_UEnum_EBodyActionList, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4198894922U) },
		{ EPxrControllerKeyMap_StaticEnum, TEXT("EPxrControllerKeyMap"), &Z_Registration_Info_UEnum_EPxrControllerKeyMap, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3572955341U) },
		{ EPxrBodyTrackerRole_StaticEnum, TEXT("EPxrBodyTrackerRole"), &Z_Registration_Info_UEnum_EPxrBodyTrackerRole, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1636942506U) },
		{ EBodyTrackingMode_StaticEnum, TEXT("EBodyTrackingMode"), &Z_Registration_Info_UEnum_EBodyTrackingMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2823689648U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_Statics::ScriptStructInfo[] = {
		{ FPxrBodyTrackingImu::StaticStruct, Z_Construct_UScriptStruct_FPxrBodyTrackingImu_Statics::NewStructOps, TEXT("PxrBodyTrackingImu"), &Z_Registration_Info_UScriptStruct_PxrBodyTrackingImu, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPxrBodyTrackingImu), 479660873U) },
		{ FMotionTrackerConnectState::StaticStruct, Z_Construct_UScriptStruct_FMotionTrackerConnectState_Statics::NewStructOps, TEXT("MotionTrackerConnectState"), &Z_Registration_Info_UScriptStruct_MotionTrackerConnectState, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMotionTrackerConnectState), 2197083264U) },
		{ FPxrBodyTrackingTransform::StaticStruct, Z_Construct_UScriptStruct_FPxrBodyTrackingTransform_Statics::NewStructOps, TEXT("PxrBodyTrackingTransform"), &Z_Registration_Info_UScriptStruct_PxrBodyTrackingTransform, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPxrBodyTrackingTransform), 2358891503U) },
		{ FBodyTrackingBoneLength::StaticStruct, Z_Construct_UScriptStruct_FBodyTrackingBoneLength_Statics::NewStructOps, TEXT("BodyTrackingBoneLength"), &Z_Registration_Info_UScriptStruct_BodyTrackingBoneLength, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FBodyTrackingBoneLength), 399108386U) },
		{ FAudioClipData::StaticStruct, Z_Construct_UScriptStruct_FAudioClipData_Statics::NewStructOps, TEXT("AudioClipData"), &Z_Registration_Info_UScriptStruct_AudioClipData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAudioClipData), 2602222149U) },
		{ FPHFDataContent::StaticStruct, Z_Construct_UScriptStruct_FPHFDataContent_Statics::NewStructOps, TEXT("PHFDataContent"), &Z_Registration_Info_UScriptStruct_PHFDataContent, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPHFDataContent), 2671331017U) },
		{ FPHFData::StaticStruct, Z_Construct_UScriptStruct_FPHFData_Statics::NewStructOps, TEXT("PHFData"), &Z_Registration_Info_UScriptStruct_PHFData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPHFData), 2372940741U) },
		{ FPHFJsonFrameData::StaticStruct, Z_Construct_UScriptStruct_FPHFJsonFrameData_Statics::NewStructOps, TEXT("PHFJsonFrameData"), &Z_Registration_Info_UScriptStruct_PHFJsonFrameData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPHFJsonFrameData), 4027228723U) },
		{ FPHFJsonData::StaticStruct, Z_Construct_UScriptStruct_FPHFJsonData_Statics::NewStructOps, TEXT("PHFJsonData"), &Z_Registration_Info_UScriptStruct_PHFJsonData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPHFJsonData), 1262856970U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPICOXRInputFunctionLibrary, UPICOXRInputFunctionLibrary::StaticClass, TEXT("UPICOXRInputFunctionLibrary"), &Z_Registration_Info_UClass_UPICOXRInputFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPICOXRInputFunctionLibrary), 2352744859U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_865098700(TEXT("/Script/PICOXRInput"),
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRInput_Public_PXR_InputFunctionLibrary_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
