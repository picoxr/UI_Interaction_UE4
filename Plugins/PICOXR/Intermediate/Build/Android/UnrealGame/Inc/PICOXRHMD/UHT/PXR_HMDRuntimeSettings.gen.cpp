// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PICOXRHMD/Public/PXR_HMDRuntimeSettings.h"
#include "PICOXRHMD/Public/PXR_HMDTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePXR_HMDRuntimeSettings() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FFilePath();
	PICOXRHMD_API UClass* Z_Construct_UClass_UPICOXRSettings();
	PICOXRHMD_API UClass* Z_Construct_UClass_UPICOXRSettings_NoRegister();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EFoveationLevel();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EFoveationRenderingMode();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOSpatialMeshLod();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRCoordinateType();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRHandTrackingSupport();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningEnhanceModeType();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningType();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PICOXRHMD_ERefreshRate();
	PICOXRHMD_API UScriptStruct* Z_Construct_UScriptStruct_FPXRSplashDesc();
	UPackage* Z_Construct_UPackage__Script_PICOXRHMD();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EFoveationRenderingMode;
	static UEnum* EFoveationRenderingMode_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EFoveationRenderingMode.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EFoveationRenderingMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRHMD_EFoveationRenderingMode, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("EFoveationRenderingMode"));
		}
		return Z_Registration_Info_UEnum_EFoveationRenderingMode.OuterSingleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EFoveationRenderingMode>()
	{
		return EFoveationRenderingMode_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRHMD_EFoveationRenderingMode_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRHMD_EFoveationRenderingMode_Statics::Enumerators[] = {
		{ "EFoveationRenderingMode::FixedFoveationRendering", (int64)EFoveationRenderingMode::FixedFoveationRendering },
		{ "EFoveationRenderingMode::EyeTrackingFoveationRendering", (int64)EFoveationRenderingMode::EyeTrackingFoveationRendering },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRHMD_EFoveationRenderingMode_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "EyeTrackingFoveationRendering.DisplayName", "Eye Tracked Foveated Rendering" },
		{ "EyeTrackingFoveationRendering.Name", "EFoveationRenderingMode::EyeTrackingFoveationRendering" },
		{ "EyeTrackingFoveationRendering.ToolTip", "Eye Tracked Foveated Rendering" },
		{ "FixedFoveationRendering.DisplayName", "Fixed Foveated Rendering" },
		{ "FixedFoveationRendering.Name", "EFoveationRenderingMode::FixedFoveationRendering" },
		{ "FixedFoveationRendering.ToolTip", "Fixed Foveated Rendering" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRHMD_EFoveationRenderingMode_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		"EFoveationRenderingMode",
		"EFoveationRenderingMode",
		Z_Construct_UEnum_PICOXRHMD_EFoveationRenderingMode_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EFoveationRenderingMode_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EFoveationRenderingMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRHMD_EFoveationRenderingMode_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRHMD_EFoveationRenderingMode()
	{
		if (!Z_Registration_Info_UEnum_EFoveationRenderingMode.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EFoveationRenderingMode.InnerSingleton, Z_Construct_UEnum_PICOXRHMD_EFoveationRenderingMode_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EFoveationRenderingMode.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EFoveationLevel;
	static UEnum* EFoveationLevel_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EFoveationLevel.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EFoveationLevel.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRHMD_EFoveationLevel, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("EFoveationLevel"));
		}
		return Z_Registration_Info_UEnum_EFoveationLevel.OuterSingleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EFoveationLevel::Type>()
	{
		return EFoveationLevel_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRHMD_EFoveationLevel_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRHMD_EFoveationLevel_Statics::Enumerators[] = {
		{ "EFoveationLevel::None", (int64)EFoveationLevel::None },
		{ "EFoveationLevel::Low", (int64)EFoveationLevel::Low },
		{ "EFoveationLevel::Med", (int64)EFoveationLevel::Med },
		{ "EFoveationLevel::High", (int64)EFoveationLevel::High },
		{ "EFoveationLevel::TopHigh", (int64)EFoveationLevel::TopHigh },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRHMD_EFoveationLevel_Statics::Enum_MetaDataParams[] = {
		{ "DisplayName", "EFoveationRenderingLevel" },
		{ "High.Name", "EFoveationLevel::High" },
		{ "Low.Name", "EFoveationLevel::Low" },
		{ "Med.Name", "EFoveationLevel::Med" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
		{ "None.Name", "EFoveationLevel::None" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Foveation Rendering Level" },
#endif
		{ "TopHigh.Name", "EFoveationLevel::TopHigh" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRHMD_EFoveationLevel_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		"EFoveationLevel",
		"EFoveationLevel::Type",
		Z_Construct_UEnum_PICOXRHMD_EFoveationLevel_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EFoveationLevel_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Namespaced,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EFoveationLevel_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRHMD_EFoveationLevel_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRHMD_EFoveationLevel()
	{
		if (!Z_Registration_Info_UEnum_EFoveationLevel.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EFoveationLevel.InnerSingleton, Z_Construct_UEnum_PICOXRHMD_EFoveationLevel_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EFoveationLevel.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERefreshRate;
	static UEnum* ERefreshRate_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ERefreshRate.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ERefreshRate.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRHMD_ERefreshRate, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("ERefreshRate"));
		}
		return Z_Registration_Info_UEnum_ERefreshRate.OuterSingleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<ERefreshRate::Type>()
	{
		return ERefreshRate_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRHMD_ERefreshRate_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRHMD_ERefreshRate_Statics::Enumerators[] = {
		{ "ERefreshRate::Default", (int64)ERefreshRate::Default },
		{ "ERefreshRate::RefreshRate72", (int64)ERefreshRate::RefreshRate72 },
		{ "ERefreshRate::RefreshRate90", (int64)ERefreshRate::RefreshRate90 },
		{ "ERefreshRate::RefreshRate120", (int64)ERefreshRate::RefreshRate120 },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRHMD_ERefreshRate_Statics::Enum_MetaDataParams[] = {
		{ "Default.Name", "ERefreshRate::Default" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
		{ "RefreshRate120.Name", "ERefreshRate::RefreshRate120" },
		{ "RefreshRate72.Name", "ERefreshRate::RefreshRate72" },
		{ "RefreshRate90.Name", "ERefreshRate::RefreshRate90" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRHMD_ERefreshRate_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		"ERefreshRate",
		"ERefreshRate::Type",
		Z_Construct_UEnum_PICOXRHMD_ERefreshRate_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_ERefreshRate_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Namespaced,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_ERefreshRate_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRHMD_ERefreshRate_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRHMD_ERefreshRate()
	{
		if (!Z_Registration_Info_UEnum_ERefreshRate.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERefreshRate.InnerSingleton, Z_Construct_UEnum_PICOXRHMD_ERefreshRate_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ERefreshRate.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRHandTrackingSupport;
	static UEnum* EPICOXRHandTrackingSupport_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRHandTrackingSupport.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRHandTrackingSupport.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRHMD_EPICOXRHandTrackingSupport, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("EPICOXRHandTrackingSupport"));
		}
		return Z_Registration_Info_UEnum_EPICOXRHandTrackingSupport.OuterSingleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPICOXRHandTrackingSupport>()
	{
		return EPICOXRHandTrackingSupport_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRHMD_EPICOXRHandTrackingSupport_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRHMD_EPICOXRHandTrackingSupport_Statics::Enumerators[] = {
		{ "EPICOXRHandTrackingSupport::ControllersOnly", (int64)EPICOXRHandTrackingSupport::ControllersOnly },
		{ "EPICOXRHandTrackingSupport::ControllersAndHands", (int64)EPICOXRHandTrackingSupport::ControllersAndHands },
		{ "EPICOXRHandTrackingSupport::HandsOnly", (int64)EPICOXRHandTrackingSupport::HandsOnly },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRHMD_EPICOXRHandTrackingSupport_Statics::Enum_MetaDataParams[] = {
		{ "ControllersAndHands.Name", "EPICOXRHandTrackingSupport::ControllersAndHands" },
		{ "ControllersOnly.Name", "EPICOXRHandTrackingSupport::ControllersOnly" },
		{ "HandsOnly.Name", "EPICOXRHandTrackingSupport::HandsOnly" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRHMD_EPICOXRHandTrackingSupport_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		"EPICOXRHandTrackingSupport",
		"EPICOXRHandTrackingSupport",
		Z_Construct_UEnum_PICOXRHMD_EPICOXRHandTrackingSupport_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXRHandTrackingSupport_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXRHandTrackingSupport_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRHMD_EPICOXRHandTrackingSupport_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRHandTrackingSupport()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRHandTrackingSupport.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRHandTrackingSupport.InnerSingleton, Z_Construct_UEnum_PICOXRHMD_EPICOXRHandTrackingSupport_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRHandTrackingSupport.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRSharpeningType;
	static UEnum* EPICOXRSharpeningType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRSharpeningType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRSharpeningType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningType, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("EPICOXRSharpeningType"));
		}
		return Z_Registration_Info_UEnum_EPICOXRSharpeningType.OuterSingleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPICOXRSharpeningType>()
	{
		return EPICOXRSharpeningType_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningType_Statics::Enumerators[] = {
		{ "EPICOXRSharpeningType::None", (int64)EPICOXRSharpeningType::None },
		{ "EPICOXRSharpeningType::NormalSharpening", (int64)EPICOXRSharpeningType::NormalSharpening },
		{ "EPICOXRSharpeningType::QualitySharpening", (int64)EPICOXRSharpeningType::QualitySharpening },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningType_Statics::Enum_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
		{ "None.Name", "EPICOXRSharpeningType::None" },
		{ "None.ToolTip", "Turn off Sharpening" },
		{ "NormalSharpening.Name", "EPICOXRSharpeningType::NormalSharpening" },
		{ "NormalSharpening.ToolTip", "Turn on NormalSharpening" },
		{ "QualitySharpening.Name", "EPICOXRSharpeningType::QualitySharpening" },
		{ "QualitySharpening.ToolTip", "Turn on QualitySharpening" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		"EPICOXRSharpeningType",
		"EPICOXRSharpeningType",
		Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningType()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRSharpeningType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRSharpeningType.InnerSingleton, Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRSharpeningType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOXRSharpeningEnhanceModeType;
	static UEnum* EPICOXRSharpeningEnhanceModeType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRSharpeningEnhanceModeType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOXRSharpeningEnhanceModeType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningEnhanceModeType, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("EPICOXRSharpeningEnhanceModeType"));
		}
		return Z_Registration_Info_UEnum_EPICOXRSharpeningEnhanceModeType.OuterSingleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPICOXRSharpeningEnhanceModeType>()
	{
		return EPICOXRSharpeningEnhanceModeType_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningEnhanceModeType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningEnhanceModeType_Statics::Enumerators[] = {
		{ "EPICOXRSharpeningEnhanceModeType::None", (int64)EPICOXRSharpeningEnhanceModeType::None },
		{ "EPICOXRSharpeningEnhanceModeType::FixedFoveated", (int64)EPICOXRSharpeningEnhanceModeType::FixedFoveated },
		{ "EPICOXRSharpeningEnhanceModeType::Adaptive", (int64)EPICOXRSharpeningEnhanceModeType::Adaptive },
		{ "EPICOXRSharpeningEnhanceModeType::Both", (int64)EPICOXRSharpeningEnhanceModeType::Both },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningEnhanceModeType_Statics::Enum_MetaDataParams[] = {
		{ "Adaptive.Name", "EPICOXRSharpeningEnhanceModeType::Adaptive" },
		{ "Adaptive.ToolTip", "Turn on Adaptive" },
		{ "Both.Name", "EPICOXRSharpeningEnhanceModeType::Both" },
		{ "Both.ToolTip", "Turn on Fixed Foveated and Adaptive Mode" },
		{ "FixedFoveated.Name", "EPICOXRSharpeningEnhanceModeType::FixedFoveated" },
		{ "FixedFoveated.ToolTip", "Turn on Fixed Foveated Mode" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
		{ "None.Name", "EPICOXRSharpeningEnhanceModeType::None" },
		{ "None.ToolTip", "Turn off all EnhanceMode" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningEnhanceModeType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		"EPICOXRSharpeningEnhanceModeType",
		"EPICOXRSharpeningEnhanceModeType",
		Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningEnhanceModeType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningEnhanceModeType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningEnhanceModeType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningEnhanceModeType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningEnhanceModeType()
	{
		if (!Z_Registration_Info_UEnum_EPICOXRSharpeningEnhanceModeType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOXRSharpeningEnhanceModeType.InnerSingleton, Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningEnhanceModeType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOXRSharpeningEnhanceModeType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPICOSpatialMeshLod;
	static UEnum* EPICOSpatialMeshLod_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPICOSpatialMeshLod.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPICOSpatialMeshLod.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_PICOXRHMD_EPICOSpatialMeshLod, (UObject*)Z_Construct_UPackage__Script_PICOXRHMD(), TEXT("EPICOSpatialMeshLod"));
		}
		return Z_Registration_Info_UEnum_EPICOSpatialMeshLod.OuterSingleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPICOSpatialMeshLod>()
	{
		return EPICOSpatialMeshLod_StaticEnum();
	}
	struct Z_Construct_UEnum_PICOXRHMD_EPICOSpatialMeshLod_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_PICOXRHMD_EPICOSpatialMeshLod_Statics::Enumerators[] = {
		{ "EPICOSpatialMeshLod::Low", (int64)EPICOSpatialMeshLod::Low },
		{ "EPICOSpatialMeshLod::Medium", (int64)EPICOSpatialMeshLod::Medium },
		{ "EPICOSpatialMeshLod::High", (int64)EPICOSpatialMeshLod::High },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_PICOXRHMD_EPICOSpatialMeshLod_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Categories", "PICO|MR" },
		{ "High.Name", "EPICOSpatialMeshLod::High" },
		{ "Low.Name", "EPICOSpatialMeshLod::Low" },
		{ "Medium.Name", "EPICOSpatialMeshLod::Medium" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_PICOXRHMD_EPICOSpatialMeshLod_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_PICOXRHMD,
		nullptr,
		"EPICOSpatialMeshLod",
		"EPICOSpatialMeshLod",
		Z_Construct_UEnum_PICOXRHMD_EPICOSpatialMeshLod_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOSpatialMeshLod_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_PICOXRHMD_EPICOSpatialMeshLod_Statics::Enum_MetaDataParams), Z_Construct_UEnum_PICOXRHMD_EPICOSpatialMeshLod_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_PICOXRHMD_EPICOSpatialMeshLod()
	{
		if (!Z_Registration_Info_UEnum_EPICOSpatialMeshLod.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPICOSpatialMeshLod.InnerSingleton, Z_Construct_UEnum_PICOXRHMD_EPICOSpatialMeshLod_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPICOSpatialMeshLod.InnerSingleton;
	}
	void UPICOXRSettings::StaticRegisterNativesUPICOXRSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPICOXRSettings);
	UClass* Z_Construct_UClass_UPICOXRSettings_NoRegister()
	{
		return UPICOXRSettings::StaticClass();
	}
	struct Z_Construct_UClass_UPICOXRSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnablePSensor_MetaData[];
#endif
		static void NewProp_bEnablePSensor_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnablePSensor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsHMD3Dof_MetaData[];
#endif
		static void NewProp_bIsHMD3Dof_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsHMD3Dof;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsController3Dof_MetaData[];
#endif
		static void NewProp_bIsController3Dof_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsController3Dof;
		static const UECodeGen_Private::FBytePropertyParams NewProp_HandTrackingSupport_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HandTrackingSupport_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_HandTrackingSupport;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAdaptiveHandModel_MetaData[];
#endif
		static void NewProp_bAdaptiveHandModel_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAdaptiveHandModel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bHighFrequencyTracking_MetaData[];
#endif
		static void NewProp_bHighFrequencyTracking_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bHighFrequencyTracking;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableAutoKeyMapping_MetaData[];
#endif
		static void NewProp_bEnableAutoKeyMapping_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableAutoKeyMapping;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableLateLatching_MetaData[];
#endif
		static void NewProp_bEnableLateLatching_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableLateLatching;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseHWsRGBEncoding_MetaData[];
#endif
		static void NewProp_bUseHWsRGBEncoding_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseHWsRGBEncoding;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseRecommendedMSAA_MetaData[];
#endif
		static void NewProp_bUseRecommendedMSAA_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseRecommendedMSAA;
		static const UECodeGen_Private::FBytePropertyParams NewProp_CoordinateType_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CoordinateType_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_CoordinateType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableEyeTracking_MetaData[];
#endif
		static void NewProp_bEnableEyeTracking_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableEyeTracking;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableEyeTrackingCalibration_MetaData[];
#endif
		static void NewProp_bEnableEyeTrackingCalibration_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableEyeTrackingCalibration;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableFaceTracking_MetaData[];
#endif
		static void NewProp_bEnableFaceTracking_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableFaceTracking;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableBodyTracking_MetaData[];
#endif
		static void NewProp_bEnableBodyTracking_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableBodyTracking;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseAdvanceInterface_MetaData[];
#endif
		static void NewProp_bUseAdvanceInterface_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseAdvanceInterface;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseContentProtect_MetaData[];
#endif
		static void NewProp_bUseContentProtect_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseContentProtect;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bSplashScreenAutoShow_MetaData[];
#endif
		static void NewProp_bSplashScreenAutoShow_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSplashScreenAutoShow;
		static const UECodeGen_Private::FStructPropertyParams NewProp_SplashDescs_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SplashDescs_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_SplashDescs;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_refreshRate_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_refreshRate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableMRSafeguard_MetaData[];
#endif
		static void NewProp_bEnableMRSafeguard_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableMRSafeguard;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableVST_MetaData[];
#endif
		static void NewProp_bEnableVST_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableVST;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableAnchor_MetaData[];
#endif
		static void NewProp_bEnableAnchor_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableAnchor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableCloudAnchor_MetaData[];
#endif
		static void NewProp_bEnableCloudAnchor_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableCloudAnchor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableSceneCapture_MetaData[];
#endif
		static void NewProp_bEnableSceneCapture_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableSceneCapture;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableMesh_MetaData[];
#endif
		static void NewProp_bEnableMesh_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bSemanticsAlignWithTriangle_MetaData[];
#endif
		static void NewProp_bSemanticsAlignWithTriangle_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSemanticsAlignWithTriangle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bSemanticsAlignWithVertex_MetaData[];
#endif
		static void NewProp_bSemanticsAlignWithVertex_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSemanticsAlignWithVertex;
		static const UECodeGen_Private::FBytePropertyParams NewProp_MeshLod_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MeshLod_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_MeshLod;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OSSplashScreen_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_OSSplashScreen;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUsingOSSplash_MetaData[];
#endif
		static void NewProp_bUsingOSSplash_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUsingOSSplash;
		static const UECodeGen_Private::FBytePropertyParams NewProp_FoveationRenderingMode_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FoveationRenderingMode_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_FoveationRenderingMode;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FoveationLevel_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_FoveationLevel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableEyeTrackingFoveationRendering_MetaData[];
#endif
		static void NewProp_bEnableEyeTrackingFoveationRendering_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableEyeTrackingFoveationRendering;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableSuperResolution_MetaData[];
#endif
		static void NewProp_bEnableSuperResolution_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableSuperResolution;
		static const UECodeGen_Private::FBytePropertyParams NewProp_SharpeningSetting_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SharpeningSetting_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_SharpeningSetting;
		static const UECodeGen_Private::FBytePropertyParams NewProp_SharpeningEnhanceMode_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SharpeningEnhanceMode_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_SharpeningEnhanceMode;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPICOXRSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRHMD,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PXR_HMDRuntimeSettings.h" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnablePSensor_MetaData[] = {
		{ "Category", "HMD" },
		{ "DisplayName", "Enable PSensor?" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If you want to get PSensor state,Please enable it!" },
#endif
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnablePSensor_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bEnablePSensor = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnablePSensor = { "bEnablePSensor", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnablePSensor_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnablePSensor_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnablePSensor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bIsHMD3Dof_MetaData[] = {
		{ "Category", "HMD" },
		{ "DisplayName", "HMD Only Tracking Rotation" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bIsHMD3Dof_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bIsHMD3Dof = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bIsHMD3Dof = { "bIsHMD3Dof", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bIsHMD3Dof_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bIsHMD3Dof_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bIsHMD3Dof_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bIsController3Dof_MetaData[] = {
		{ "Category", "Controller" },
		{ "DisplayName", "Controller Only Tracking Rotation" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bIsController3Dof_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bIsController3Dof = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bIsController3Dof = { "bIsController3Dof", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bIsController3Dof_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bIsController3Dof_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bIsController3Dof_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_HandTrackingSupport_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_HandTrackingSupport_MetaData[] = {
		{ "Category", "Controller" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether controllers and/or hands can be used with the app */" },
#endif
		{ "DisplayName", "HandTracking Support" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether controllers and/or hands can be used with the app" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_HandTrackingSupport = { "HandTrackingSupport", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPICOXRSettings, HandTrackingSupport), Z_Construct_UEnum_PICOXRHMD_EPICOXRHandTrackingSupport, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_HandTrackingSupport_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_HandTrackingSupport_MetaData) }; // 3962907966
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bAdaptiveHandModel_MetaData[] = {
		{ "Category", "Controller" },
		{ "DisplayName", "Adaptive Hand Model\xef\xbc\x88PICO\xef\xbc\x89" },
		{ "EditCondition", "HandTrackingSupport!=EPICOXRHandTrackingSupport::ControllersOnly" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If this function is selected, the hand model will change according to the actual size of the user's palm. Note that the hand model only works on PICO." },
#endif
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bAdaptiveHandModel_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bAdaptiveHandModel = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bAdaptiveHandModel = { "bAdaptiveHandModel", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bAdaptiveHandModel_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bAdaptiveHandModel_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bAdaptiveHandModel_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bHighFrequencyTracking_MetaData[] = {
		{ "Category", "Controller" },
		{ "DisplayName", "high frequency tracking(60Hz)" },
		{ "EditCondition", "HandTrackingSupport!=EPICOXRHandTrackingSupport::ControllersOnly" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If turned on, hand tracking will run at a higher tracking frequency, which will improve the smoothness of hand tracking, but the power consumption will increase." },
#endif
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bHighFrequencyTracking_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bHighFrequencyTracking = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bHighFrequencyTracking = { "bHighFrequencyTracking", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bHighFrequencyTracking_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bHighFrequencyTracking_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bHighFrequencyTracking_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableAutoKeyMapping_MetaData[] = {
		{ "Category", "Controller" },
		{ "ConfigRestartRequired", "TRUE" },
		{ "DisplayName", "Enable AutoKeyMapping" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When enabled, A set of key mappings will be generated automatically,and default controller animation will work." },
#endif
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableAutoKeyMapping_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bEnableAutoKeyMapping = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableAutoKeyMapping = { "bEnableAutoKeyMapping", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableAutoKeyMapping_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableAutoKeyMapping_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableAutoKeyMapping_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableLateLatching_MetaData[] = {
		{ "Category", "Feature" },
		{ "DisplayName", "Enable LateLatching" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Only support + Vulkan + Multi-View + Disable Occlusion Culling." },
#endif
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableLateLatching_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bEnableLateLatching = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableLateLatching = { "bEnableLateLatching", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableLateLatching_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableLateLatching_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableLateLatching_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseHWsRGBEncoding_MetaData[] = {
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseHWsRGBEncoding_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bUseHWsRGBEncoding = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseHWsRGBEncoding = { "bUseHWsRGBEncoding", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseHWsRGBEncoding_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseHWsRGBEncoding_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseHWsRGBEncoding_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseRecommendedMSAA_MetaData[] = {
		{ "Category", "Feature" },
		{ "DisplayName", "Use Recommended MSAA Level" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseRecommendedMSAA_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bUseRecommendedMSAA = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseRecommendedMSAA = { "bUseRecommendedMSAA", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseRecommendedMSAA_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseRecommendedMSAA_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseRecommendedMSAA_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_CoordinateType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_CoordinateType_MetaData[] = {
		{ "Category", "Feature" },
		{ "DisplayName", "Coordinate Space" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_CoordinateType = { "CoordinateType", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPICOXRSettings, CoordinateType), Z_Construct_UEnum_PICOXRHMD_EPICOXRCoordinateType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_CoordinateType_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_CoordinateType_MetaData) }; // 2250041083
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableEyeTracking_MetaData[] = {
		{ "Category", "Feature" },
		{ "DisplayName", "Enable Eye Tracking" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enable Eye Tracking" },
#endif
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableEyeTracking_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bEnableEyeTracking = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableEyeTracking = { "bEnableEyeTracking", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableEyeTracking_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableEyeTracking_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableEyeTracking_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableEyeTrackingCalibration_MetaData[] = {
		{ "Category", "Feature" },
		{ "DisplayName", "Enable Eye Tracking Calibration" },
		{ "EditCondition", "bEnableEyeTracking" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enable Eye Tracking Calibration" },
#endif
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableEyeTrackingCalibration_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bEnableEyeTrackingCalibration = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableEyeTrackingCalibration = { "bEnableEyeTrackingCalibration", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableEyeTrackingCalibration_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableEyeTrackingCalibration_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableEyeTrackingCalibration_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableFaceTracking_MetaData[] = {
		{ "Category", "Feature" },
		{ "DisplayName", "Enable Face Tracking" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enable Face Tracking" },
#endif
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableFaceTracking_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bEnableFaceTracking = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableFaceTracking = { "bEnableFaceTracking", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableFaceTracking_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableFaceTracking_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableFaceTracking_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableBodyTracking_MetaData[] = {
		{ "Category", "Feature" },
		{ "DisplayName", "Enable Body Tracking" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enable Tracking Function related to Fitness Band" },
#endif
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableBodyTracking_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bEnableBodyTracking = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableBodyTracking = { "bEnableBodyTracking", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableBodyTracking_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableBodyTracking_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableBodyTracking_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseAdvanceInterface_MetaData[] = {
		{ "Category", "Feature" },
		{ "DisplayName", "Use PICO Advance Interface" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseAdvanceInterface_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bUseAdvanceInterface = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseAdvanceInterface = { "bUseAdvanceInterface", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseAdvanceInterface_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseAdvanceInterface_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseAdvanceInterface_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseContentProtect_MetaData[] = {
		{ "Category", "Feature" },
		{ "DisplayName", "Use Content Protect" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseContentProtect_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bUseContentProtect = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseContentProtect = { "bUseContentProtect", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseContentProtect_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseContentProtect_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseContentProtect_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bSplashScreenAutoShow_MetaData[] = {
		{ "Category", "Feature" },
		{ "DisplayName", "Auto Show Splash Screen" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bSplashScreenAutoShow_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bSplashScreenAutoShow = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bSplashScreenAutoShow = { "bSplashScreenAutoShow", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bSplashScreenAutoShow_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bSplashScreenAutoShow_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bSplashScreenAutoShow_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_SplashDescs_Inner = { "SplashDescs", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FPXRSplashDesc, METADATA_PARAMS(0, nullptr) }; // 1402801677
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_SplashDescs_MetaData[] = {
		{ "Category", "Feature" },
		{ "DisplayName", "SplashDescs" },
		{ "EditCondition", "bSplashScreenAutoShow" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_SplashDescs = { "SplashDescs", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPICOXRSettings, SplashDescs), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_SplashDescs_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_SplashDescs_MetaData) }; // 1402801677
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_refreshRate_MetaData[] = {
		{ "Category", "Feature" },
		{ "DisplayName", "Display Refresh Rates" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_refreshRate = { "refreshRate", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPICOXRSettings, refreshRate), Z_Construct_UEnum_PICOXRHMD_ERefreshRate, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_refreshRate_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_refreshRate_MetaData) }; // 338758220
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableMRSafeguard_MetaData[] = {
		{ "Category", "MixedReality" },
		{ "DisplayName", "Enable MR Safeguard" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "MR safety, if you choose this option, your application will adopt MR safety policies during runtime. If not selected, it will continue to use VR safety policies by default." },
#endif
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableMRSafeguard_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bEnableMRSafeguard = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableMRSafeguard = { "bEnableMRSafeguard", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableMRSafeguard_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableMRSafeguard_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableMRSafeguard_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableVST_MetaData[] = {
		{ "Category", "MixedReality" },
		{ "DisplayName", "Enable Video Seethrough" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableVST_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bEnableVST = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableVST = { "bEnableVST", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableVST_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableVST_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableVST_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableAnchor_MetaData[] = {
		{ "Category", "MixedReality" },
		{ "DisplayName", "Enable Spatial Anchor" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableAnchor_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bEnableAnchor = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableAnchor = { "bEnableAnchor", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableAnchor_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableAnchor_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableAnchor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableCloudAnchor_MetaData[] = {
		{ "Category", "MixedReality" },
		{ "DisplayName", "Enable Spatial Shared Anchor" },
		{ "EditCondition", "bEnableAnchor" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableCloudAnchor_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bEnableCloudAnchor = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableCloudAnchor = { "bEnableCloudAnchor", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableCloudAnchor_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableCloudAnchor_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableCloudAnchor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableSceneCapture_MetaData[] = {
		{ "Category", "MixedReality" },
		{ "DisplayName", "Enable Scene Capture" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableSceneCapture_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bEnableSceneCapture = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableSceneCapture = { "bEnableSceneCapture", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableSceneCapture_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableSceneCapture_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableSceneCapture_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableMesh_MetaData[] = {
		{ "Category", "MixedReality" },
		{ "DisplayName", "Enable Spatial Mesh" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableMesh_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bEnableMesh = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableMesh = { "bEnableMesh", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableMesh_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableMesh_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableMesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bSemanticsAlignWithTriangle_MetaData[] = {
		{ "Category", "MixedReality" },
		{ "DisplayName", "Enable Semantics Align With Triangle" },
		{ "EditCondition", "bEnableMesh" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bSemanticsAlignWithTriangle_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bSemanticsAlignWithTriangle = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bSemanticsAlignWithTriangle = { "bSemanticsAlignWithTriangle", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bSemanticsAlignWithTriangle_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bSemanticsAlignWithTriangle_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bSemanticsAlignWithTriangle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bSemanticsAlignWithVertex_MetaData[] = {
		{ "Category", "MixedReality" },
		{ "DisplayName", "Enable Semantics Align With Vertex" },
		{ "EditCondition", "bEnableMesh" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bSemanticsAlignWithVertex_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bSemanticsAlignWithVertex = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bSemanticsAlignWithVertex = { "bSemanticsAlignWithVertex", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bSemanticsAlignWithVertex_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bSemanticsAlignWithVertex_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bSemanticsAlignWithVertex_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_MeshLod_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_MeshLod_MetaData[] = {
		{ "Category", "MixedReality" },
		{ "DisplayName", "Spatial Mesh Lod" },
		{ "EditCondition", "bEnableMesh" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_MeshLod = { "MeshLod", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPICOXRSettings, MeshLod), Z_Construct_UEnum_PICOXRHMD_EPICOSpatialMeshLod, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_MeshLod_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_MeshLod_MetaData) }; // 1769800351
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_OSSplashScreen_MetaData[] = {
		{ "Category", "Mobile" },
		{ "DisplayName", "OS Splash Screen" },
		{ "FilePathFilter", "png" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_OSSplashScreen = { "OSSplashScreen", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPICOXRSettings, OSSplashScreen), Z_Construct_UScriptStruct_FFilePath, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_OSSplashScreen_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_OSSplashScreen_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUsingOSSplash_MetaData[] = {
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUsingOSSplash_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bUsingOSSplash = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUsingOSSplash = { "bUsingOSSplash", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUsingOSSplash_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUsingOSSplash_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUsingOSSplash_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_FoveationRenderingMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_FoveationRenderingMode_MetaData[] = {
		{ "Category", "FoveatedRendering" },
		{ "DisplayName", "Foveated Rendering Mode" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_FoveationRenderingMode = { "FoveationRenderingMode", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPICOXRSettings, FoveationRenderingMode), Z_Construct_UEnum_PICOXRHMD_EFoveationRenderingMode, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_FoveationRenderingMode_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_FoveationRenderingMode_MetaData) }; // 4128707893
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_FoveationLevel_MetaData[] = {
		{ "Category", "FoveatedRendering" },
		{ "DisplayName", "Foveated Rendering Level" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Foveated Rendering Level" },
#endif
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_FoveationLevel = { "FoveationLevel", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPICOXRSettings, FoveationLevel), Z_Construct_UEnum_PICOXRHMD_EFoveationLevel, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_FoveationLevel_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_FoveationLevel_MetaData) }; // 2608396520
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableEyeTrackingFoveationRendering_MetaData[] = {
		{ "Category", "FoveatedRendering" },
		{ "DisplayName", "Enable Eye Tracked Foveated Rendering" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enable Eye Tracked Foveated Rendering" },
#endif
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableEyeTrackingFoveationRendering_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bEnableEyeTrackingFoveationRendering = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableEyeTrackingFoveationRendering = { "bEnableEyeTrackingFoveationRendering", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableEyeTrackingFoveationRendering_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableEyeTrackingFoveationRendering_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableEyeTrackingFoveationRendering_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableSuperResolution_MetaData[] = {
		{ "Category", "Feature" },
		{ "ConsoleVariable", "r.Mobile.PICO.EnableSuperResolution" },
		{ "DisplayName", "Enable SuperResolution" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The two features, super resolution and sharpening, are mutually exclusive, with super resolution having a higher priority, In addition to this, SuperResolution currently has compatibility issues with adaptive resolutions, and it is not recommended to enable them at the same time, which will be fixed in the next release" },
#endif
	};
#endif
	void Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableSuperResolution_SetBit(void* Obj)
	{
		((UPICOXRSettings*)Obj)->bEnableSuperResolution = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableSuperResolution = { "bEnableSuperResolution", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPICOXRSettings), &Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableSuperResolution_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableSuperResolution_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableSuperResolution_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_SharpeningSetting_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_SharpeningSetting_MetaData[] = {
		{ "Category", "Feature" },
		{ "ConsoleVariable", "r.Mobile.PICO.SharpeningSetting" },
		{ "DisplayName", "Sharpening Setting" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The two features, super resolution and sharpening, are mutually exclusive, with super resolution having a higher priority." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_SharpeningSetting = { "SharpeningSetting", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPICOXRSettings, SharpeningSetting), Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_SharpeningSetting_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_SharpeningSetting_MetaData) }; // 1986572637
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_SharpeningEnhanceMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_SharpeningEnhanceMode_MetaData[] = {
		{ "Category", "Feature" },
		{ "ConsoleVariable", "r.Mobile.PICO.SharpeningEnhanceMode" },
		{ "DisplayName", "EnhanceMode Setting" },
		{ "EditCondition", "SharpeningSetting!=EPICOXRSharpeningType::None" },
		{ "ModuleRelativePath", "Public/PXR_HMDRuntimeSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FixedFoveated and Adaptive modes can be turned on in one or both modes." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_SharpeningEnhanceMode = { "SharpeningEnhanceMode", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPICOXRSettings, SharpeningEnhanceMode), Z_Construct_UEnum_PICOXRHMD_EPICOXRSharpeningEnhanceModeType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_SharpeningEnhanceMode_MetaData), Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_SharpeningEnhanceMode_MetaData) }; // 2890311121
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPICOXRSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnablePSensor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bIsHMD3Dof,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bIsController3Dof,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_HandTrackingSupport_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_HandTrackingSupport,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bAdaptiveHandModel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bHighFrequencyTracking,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableAutoKeyMapping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableLateLatching,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseHWsRGBEncoding,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseRecommendedMSAA,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_CoordinateType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_CoordinateType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableEyeTracking,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableEyeTrackingCalibration,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableFaceTracking,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableBodyTracking,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseAdvanceInterface,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUseContentProtect,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bSplashScreenAutoShow,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_SplashDescs_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_SplashDescs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_refreshRate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableMRSafeguard,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableVST,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableAnchor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableCloudAnchor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableSceneCapture,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bSemanticsAlignWithTriangle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bSemanticsAlignWithVertex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_MeshLod_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_MeshLod,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_OSSplashScreen,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bUsingOSSplash,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_FoveationRenderingMode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_FoveationRenderingMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_FoveationLevel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableEyeTrackingFoveationRendering,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_bEnableSuperResolution,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_SharpeningSetting_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_SharpeningSetting,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_SharpeningEnhanceMode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPICOXRSettings_Statics::NewProp_SharpeningEnhanceMode,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPICOXRSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPICOXRSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPICOXRSettings_Statics::ClassParams = {
		&UPICOXRSettings::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPICOXRSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::PropPointers),
		0,
		0x001000A6u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UPICOXRSettings_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOXRSettings_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPICOXRSettings()
	{
		if (!Z_Registration_Info_UClass_UPICOXRSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPICOXRSettings.OuterSingleton, Z_Construct_UClass_UPICOXRSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPICOXRSettings.OuterSingleton;
	}
	template<> PICOXRHMD_API UClass* StaticClass<UPICOXRSettings>()
	{
		return UPICOXRSettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPICOXRSettings);
	UPICOXRSettings::~UPICOXRSettings() {}
	struct Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_Statics::EnumInfo[] = {
		{ EFoveationRenderingMode_StaticEnum, TEXT("EFoveationRenderingMode"), &Z_Registration_Info_UEnum_EFoveationRenderingMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4128707893U) },
		{ EFoveationLevel_StaticEnum, TEXT("EFoveationLevel"), &Z_Registration_Info_UEnum_EFoveationLevel, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2608396520U) },
		{ ERefreshRate_StaticEnum, TEXT("ERefreshRate"), &Z_Registration_Info_UEnum_ERefreshRate, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 338758220U) },
		{ EPICOXRHandTrackingSupport_StaticEnum, TEXT("EPICOXRHandTrackingSupport"), &Z_Registration_Info_UEnum_EPICOXRHandTrackingSupport, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3962907966U) },
		{ EPICOXRSharpeningType_StaticEnum, TEXT("EPICOXRSharpeningType"), &Z_Registration_Info_UEnum_EPICOXRSharpeningType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1986572637U) },
		{ EPICOXRSharpeningEnhanceModeType_StaticEnum, TEXT("EPICOXRSharpeningEnhanceModeType"), &Z_Registration_Info_UEnum_EPICOXRSharpeningEnhanceModeType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2890311121U) },
		{ EPICOSpatialMeshLod_StaticEnum, TEXT("EPICOSpatialMeshLod"), &Z_Registration_Info_UEnum_EPICOSpatialMeshLod, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1769800351U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPICOXRSettings, UPICOXRSettings::StaticClass, TEXT("UPICOXRSettings"), &Z_Registration_Info_UClass_UPICOXRSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPICOXRSettings), 475345615U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_1726797483(TEXT("/Script/PICOXRHMD"),
		Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_New_0311_Plugins_PICOXR_Source_PICOXRHMD_Public_PXR_HMDRuntimeSettings_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
