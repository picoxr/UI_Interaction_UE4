// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PicoXRHMD/Public/PXR_HMDFunctionLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePXR_HMDFunctionLibrary() {}
// Cross Module References
	PICOXRHMD_API UFunction* Z_Construct_UDelegateFunction_PicoXRHMD_PicoXRIPDChangedDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_PicoXRHMD();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PicoXRHMD_EPicoXRFoveationLevel();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PicoXRHMD_EPicoXRCameraType();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PicoXRHMD_EPicoXRNodeType();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PicoXRHMD_EPicoXRTrackedDeviceType();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PicoXRHMD_EPicoXRBoundaryState();
	PICOXRHMD_API UEnum* Z_Construct_UEnum_PicoXRHMD_EPicoXRBoundaryType();
	PICOXRHMD_API UScriptStruct* Z_Construct_UScriptStruct_FPicoXREyeTrackingData();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	PICOXRHMD_API UScriptStruct* Z_Construct_UScriptStruct_FPxrSensorState();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuat();
	PICOXRHMD_API UClass* Z_Construct_UClass_UPicoXRHMDFunctionLibrary_NoRegister();
	PICOXRHMD_API UClass* Z_Construct_UClass_UPicoXRHMDFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	PICOXRHMD_API UClass* Z_Construct_UClass_UPicoXREventManager_NoRegister();
	HEADMOUNTEDDISPLAY_API UEnum* Z_Construct_UEnum_HeadMountedDisplay_EHMDWornState();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_PicoXRHMD_PicoXRIPDChangedDelegate__DelegateSignature_Statics
	{
		struct _Script_PicoXRHMD_eventPicoXRIPDChangedDelegate_Parms
		{
			float Ipd;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Ipd;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_PicoXRHMD_PicoXRIPDChangedDelegate__DelegateSignature_Statics::NewProp_Ipd = { "Ipd", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_PicoXRHMD_eventPicoXRIPDChangedDelegate_Parms, Ipd), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_PicoXRHMD_PicoXRIPDChangedDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_PicoXRHMD_PicoXRIPDChangedDelegate__DelegateSignature_Statics::NewProp_Ipd,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_PicoXRHMD_PicoXRIPDChangedDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_PicoXRHMD_PicoXRIPDChangedDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_PicoXRHMD, nullptr, "PicoXRIPDChangedDelegate__DelegateSignature", nullptr, nullptr, sizeof(_Script_PicoXRHMD_eventPicoXRIPDChangedDelegate_Parms), Z_Construct_UDelegateFunction_PicoXRHMD_PicoXRIPDChangedDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PicoXRHMD_PicoXRIPDChangedDelegate__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_PicoXRHMD_PicoXRIPDChangedDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PicoXRHMD_PicoXRIPDChangedDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_PicoXRHMD_PicoXRIPDChangedDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_PicoXRHMD_PicoXRIPDChangedDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	static UEnum* EPicoXRFoveationLevel_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_PicoXRHMD_EPicoXRFoveationLevel, Z_Construct_UPackage__Script_PicoXRHMD(), TEXT("EPicoXRFoveationLevel"));
		}
		return Singleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPicoXRFoveationLevel>()
	{
		return EPicoXRFoveationLevel_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EPicoXRFoveationLevel(EPicoXRFoveationLevel_StaticEnum, TEXT("/Script/PicoXRHMD"), TEXT("EPicoXRFoveationLevel"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_PicoXRHMD_EPicoXRFoveationLevel_Hash() { return 3565762051U; }
	UEnum* Z_Construct_UEnum_PicoXRHMD_EPicoXRFoveationLevel()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_PicoXRHMD();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EPicoXRFoveationLevel"), 0, Get_Z_Construct_UEnum_PicoXRHMD_EPicoXRFoveationLevel_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EPicoXRFoveationLevel::Low", (int64)EPicoXRFoveationLevel::Low },
				{ "EPicoXRFoveationLevel::Medium", (int64)EPicoXRFoveationLevel::Medium },
				{ "EPicoXRFoveationLevel::High", (int64)EPicoXRFoveationLevel::High },
				{ "EPicoXRFoveationLevel::TopHigh", (int64)EPicoXRFoveationLevel::TopHigh },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "High.Name", "EPicoXRFoveationLevel::High" },
				{ "Low.Name", "EPicoXRFoveationLevel::Low" },
				{ "Medium.Name", "EPicoXRFoveationLevel::Medium" },
				{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
				{ "TopHigh.Name", "EPicoXRFoveationLevel::TopHigh" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_PicoXRHMD,
				nullptr,
				"EPicoXRFoveationLevel",
				"EPicoXRFoveationLevel",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EPicoXRCameraType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_PicoXRHMD_EPicoXRCameraType, Z_Construct_UPackage__Script_PicoXRHMD(), TEXT("EPicoXRCameraType"));
		}
		return Singleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPicoXRCameraType>()
	{
		return EPicoXRCameraType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EPicoXRCameraType(EPicoXRCameraType_StaticEnum, TEXT("/Script/PicoXRHMD"), TEXT("EPicoXRCameraType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_PicoXRHMD_EPicoXRCameraType_Hash() { return 2790596506U; }
	UEnum* Z_Construct_UEnum_PicoXRHMD_EPicoXRCameraType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_PicoXRHMD();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EPicoXRCameraType"), 0, Get_Z_Construct_UEnum_PicoXRHMD_EPicoXRCameraType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EPicoXRCameraType::Left", (int64)EPicoXRCameraType::Left },
				{ "EPicoXRCameraType::Right", (int64)EPicoXRCameraType::Right },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Left.DisplayName", "Left Camera" },
				{ "Left.Name", "EPicoXRCameraType::Left" },
				{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
				{ "Right.DisplayName", "Right Camera" },
				{ "Right.Name", "EPicoXRCameraType::Right" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_PicoXRHMD,
				nullptr,
				"EPicoXRCameraType",
				"EPicoXRCameraType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EPicoXRNodeType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_PicoXRHMD_EPicoXRNodeType, Z_Construct_UPackage__Script_PicoXRHMD(), TEXT("EPicoXRNodeType"));
		}
		return Singleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPicoXRNodeType>()
	{
		return EPicoXRNodeType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EPicoXRNodeType(EPicoXRNodeType_StaticEnum, TEXT("/Script/PicoXRHMD"), TEXT("EPicoXRNodeType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_PicoXRHMD_EPicoXRNodeType_Hash() { return 3926098978U; }
	UEnum* Z_Construct_UEnum_PicoXRHMD_EPicoXRNodeType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_PicoXRHMD();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EPicoXRNodeType"), 0, Get_Z_Construct_UEnum_PicoXRHMD_EPicoXRNodeType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EPicoXRNodeType::LeftHand", (int64)EPicoXRNodeType::LeftHand },
				{ "EPicoXRNodeType::RightHand", (int64)EPicoXRNodeType::RightHand },
				{ "EPicoXRNodeType::Head", (int64)EPicoXRNodeType::Head },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Head.Name", "EPicoXRNodeType::Head" },
				{ "LeftHand.Name", "EPicoXRNodeType::LeftHand" },
				{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
				{ "RightHand.Name", "EPicoXRNodeType::RightHand" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_PicoXRHMD,
				nullptr,
				"EPicoXRNodeType",
				"EPicoXRNodeType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EPicoXRTrackedDeviceType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_PicoXRHMD_EPicoXRTrackedDeviceType, Z_Construct_UPackage__Script_PicoXRHMD(), TEXT("EPicoXRTrackedDeviceType"));
		}
		return Singleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPicoXRTrackedDeviceType>()
	{
		return EPicoXRTrackedDeviceType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EPicoXRTrackedDeviceType(EPicoXRTrackedDeviceType_StaticEnum, TEXT("/Script/PicoXRHMD"), TEXT("EPicoXRTrackedDeviceType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_PicoXRHMD_EPicoXRTrackedDeviceType_Hash() { return 1277292811U; }
	UEnum* Z_Construct_UEnum_PicoXRHMD_EPicoXRTrackedDeviceType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_PicoXRHMD();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EPicoXRTrackedDeviceType"), 0, Get_Z_Construct_UEnum_PicoXRHMD_EPicoXRTrackedDeviceType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EPicoXRTrackedDeviceType::None", (int64)EPicoXRTrackedDeviceType::None },
				{ "EPicoXRTrackedDeviceType::HMD", (int64)EPicoXRTrackedDeviceType::HMD },
				{ "EPicoXRTrackedDeviceType::LTouch", (int64)EPicoXRTrackedDeviceType::LTouch },
				{ "EPicoXRTrackedDeviceType::RTouch", (int64)EPicoXRTrackedDeviceType::RTouch },
				{ "EPicoXRTrackedDeviceType::Touch", (int64)EPicoXRTrackedDeviceType::Touch },
				{ "EPicoXRTrackedDeviceType::All", (int64)EPicoXRTrackedDeviceType::All },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "All.DisplayName", "All Devices" },
				{ "All.Name", "EPicoXRTrackedDeviceType::All" },
				{ "BlueprintType", "true" },
				{ "HMD.DisplayName", "HMD" },
				{ "HMD.Name", "EPicoXRTrackedDeviceType::HMD" },
				{ "LTouch.DisplayName", "Left Hand" },
				{ "LTouch.Name", "EPicoXRTrackedDeviceType::LTouch" },
				{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
				{ "None.DisplayName", "No Devices" },
				{ "None.Name", "EPicoXRTrackedDeviceType::None" },
				{ "RTouch.DisplayName", "Right Hand" },
				{ "RTouch.Name", "EPicoXRTrackedDeviceType::RTouch" },
				{ "Touch.DisplayName", "All Hands" },
				{ "Touch.Name", "EPicoXRTrackedDeviceType::Touch" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_PicoXRHMD,
				nullptr,
				"EPicoXRTrackedDeviceType",
				"EPicoXRTrackedDeviceType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EPicoXRBoundaryState_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_PicoXRHMD_EPicoXRBoundaryState, Z_Construct_UPackage__Script_PicoXRHMD(), TEXT("EPicoXRBoundaryState"));
		}
		return Singleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPicoXRBoundaryState>()
	{
		return EPicoXRBoundaryState_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EPicoXRBoundaryState(EPicoXRBoundaryState_StaticEnum, TEXT("/Script/PicoXRHMD"), TEXT("EPicoXRBoundaryState"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_PicoXRHMD_EPicoXRBoundaryState_Hash() { return 97026353U; }
	UEnum* Z_Construct_UEnum_PicoXRHMD_EPicoXRBoundaryState()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_PicoXRHMD();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EPicoXRBoundaryState"), 0, Get_Z_Construct_UEnum_PicoXRHMD_EPicoXRBoundaryState_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EPicoXRBoundaryState::GobackDialog", (int64)EPicoXRBoundaryState::GobackDialog },
				{ "EPicoXRBoundaryState::ToofarDialog", (int64)EPicoXRBoundaryState::ToofarDialog },
				{ "EPicoXRBoundaryState::LostDialog", (int64)EPicoXRBoundaryState::LostDialog },
				{ "EPicoXRBoundaryState::LostNoReason", (int64)EPicoXRBoundaryState::LostNoReason },
				{ "EPicoXRBoundaryState::LostCamera", (int64)EPicoXRBoundaryState::LostCamera },
				{ "EPicoXRBoundaryState::LostHighLight", (int64)EPicoXRBoundaryState::LostHighLight },
				{ "EPicoXRBoundaryState::LostLowLight", (int64)EPicoXRBoundaryState::LostLowLight },
				{ "EPicoXRBoundaryState::LostLowFeatureCount", (int64)EPicoXRBoundaryState::LostLowFeatureCount },
				{ "EPicoXRBoundaryState::LostReLocation", (int64)EPicoXRBoundaryState::LostReLocation },
				{ "EPicoXRBoundaryState::LostInitialization", (int64)EPicoXRBoundaryState::LostInitialization },
				{ "EPicoXRBoundaryState::LostNoCamera", (int64)EPicoXRBoundaryState::LostNoCamera },
				{ "EPicoXRBoundaryState::LostNoIMU", (int64)EPicoXRBoundaryState::LostNoIMU },
				{ "EPicoXRBoundaryState::LostIMUJitter", (int64)EPicoXRBoundaryState::LostIMUJitter },
				{ "EPicoXRBoundaryState::LostUnknown", (int64)EPicoXRBoundaryState::LostUnknown },
				{ "EPicoXRBoundaryState::NothingDialog", (int64)EPicoXRBoundaryState::NothingDialog },
				{ "EPicoXRBoundaryState::LostNoDialog", (int64)EPicoXRBoundaryState::LostNoDialog },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "GobackDialog.Name", "EPicoXRBoundaryState::GobackDialog" },
				{ "LostCamera.Name", "EPicoXRBoundaryState::LostCamera" },
				{ "LostDialog.Name", "EPicoXRBoundaryState::LostDialog" },
				{ "LostHighLight.Name", "EPicoXRBoundaryState::LostHighLight" },
				{ "LostIMUJitter.Name", "EPicoXRBoundaryState::LostIMUJitter" },
				{ "LostInitialization.Name", "EPicoXRBoundaryState::LostInitialization" },
				{ "LostLowFeatureCount.Name", "EPicoXRBoundaryState::LostLowFeatureCount" },
				{ "LostLowLight.Name", "EPicoXRBoundaryState::LostLowLight" },
				{ "LostNoCamera.Name", "EPicoXRBoundaryState::LostNoCamera" },
				{ "LostNoDialog.Name", "EPicoXRBoundaryState::LostNoDialog" },
				{ "LostNoIMU.Name", "EPicoXRBoundaryState::LostNoIMU" },
				{ "LostNoReason.Name", "EPicoXRBoundaryState::LostNoReason" },
				{ "LostReLocation.Name", "EPicoXRBoundaryState::LostReLocation" },
				{ "LostUnknown.Name", "EPicoXRBoundaryState::LostUnknown" },
				{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
				{ "NothingDialog.Name", "EPicoXRBoundaryState::NothingDialog" },
				{ "ToofarDialog.Name", "EPicoXRBoundaryState::ToofarDialog" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_PicoXRHMD,
				nullptr,
				"EPicoXRBoundaryState",
				"EPicoXRBoundaryState",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* EPicoXRBoundaryType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_PicoXRHMD_EPicoXRBoundaryType, Z_Construct_UPackage__Script_PicoXRHMD(), TEXT("EPicoXRBoundaryType"));
		}
		return Singleton;
	}
	template<> PICOXRHMD_API UEnum* StaticEnum<EPicoXRBoundaryType>()
	{
		return EPicoXRBoundaryType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EPicoXRBoundaryType(EPicoXRBoundaryType_StaticEnum, TEXT("/Script/PicoXRHMD"), TEXT("EPicoXRBoundaryType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_PicoXRHMD_EPicoXRBoundaryType_Hash() { return 366424360U; }
	UEnum* Z_Construct_UEnum_PicoXRHMD_EPicoXRBoundaryType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_PicoXRHMD();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EPicoXRBoundaryType"), 0, Get_Z_Construct_UEnum_PicoXRHMD_EPicoXRBoundaryType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EPicoXRBoundaryType::Outer", (int64)EPicoXRBoundaryType::Outer },
				{ "EPicoXRBoundaryType::PlayArea", (int64)EPicoXRBoundaryType::PlayArea },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "/* Boundary boundary types*/" },
				{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
				{ "Outer.DisplayName", "The Outer Boundary" },
				{ "Outer.Name", "EPicoXRBoundaryType::Outer" },
				{ "PlayArea.DisplayName", "The Play Area Boundary" },
				{ "PlayArea.Name", "EPicoXRBoundaryType::PlayArea" },
				{ "ToolTip", "Boundary boundary types" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_PicoXRHMD,
				nullptr,
				"EPicoXRBoundaryType",
				"EPicoXRBoundaryType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FPicoXREyeTrackingData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern PICOXRHMD_API uint32 Get_Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FPicoXREyeTrackingData, Z_Construct_UPackage__Script_PicoXRHMD(), TEXT("PicoXREyeTrackingData"), sizeof(FPicoXREyeTrackingData), Get_Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Hash());
	}
	return Singleton;
}
template<> PICOXRHMD_API UScriptStruct* StaticStruct<FPicoXREyeTrackingData>()
{
	return FPicoXREyeTrackingData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FPicoXREyeTrackingData(FPicoXREyeTrackingData::StaticStruct, TEXT("/Script/PicoXRHMD"), TEXT("PicoXREyeTrackingData"), false, nullptr, nullptr);
static struct FScriptStruct_PicoXRHMD_StaticRegisterNativesFPicoXREyeTrackingData
{
	FScriptStruct_PicoXRHMD_StaticRegisterNativesFPicoXREyeTrackingData()
	{
		UScriptStruct::DeferCppStructOps<FPicoXREyeTrackingData>(FName(TEXT("PicoXREyeTrackingData")));
	}
} ScriptStruct_PicoXRHMD_StaticRegisterNativesFPicoXREyeTrackingData;
	struct Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LeftEyePoseStatus_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_LeftEyePoseStatus;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RightEyePoseStatus_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_RightEyePoseStatus;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CombinedEyePoseStatus_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_CombinedEyePoseStatus;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CombinedEyeGazePoint_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_CombinedEyeGazePoint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CombinedEyeGazeVector_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_CombinedEyeGazeVector;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LeftEyeOpenness_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_LeftEyeOpenness;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RightEyeOpenness_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RightEyeOpenness;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LeftEyePositionGuide_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LeftEyePositionGuide;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RightEyePositionGuide_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_RightEyePositionGuide;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FoveatedGazeDirection_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_FoveatedGazeDirection;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FoveatedGazeTrackingState_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_FoveatedGazeTrackingState;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "DisplayName", "PicoXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPicoXREyeTrackingData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_LeftEyePoseStatus_MetaData[] = {
		{ "Category", "PicoXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_LeftEyePoseStatus = { "LeftEyePoseStatus", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPicoXREyeTrackingData, LeftEyePoseStatus), METADATA_PARAMS(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_LeftEyePoseStatus_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_LeftEyePoseStatus_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_RightEyePoseStatus_MetaData[] = {
		{ "Category", "PicoXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_RightEyePoseStatus = { "RightEyePoseStatus", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPicoXREyeTrackingData, RightEyePoseStatus), METADATA_PARAMS(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_RightEyePoseStatus_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_RightEyePoseStatus_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_CombinedEyePoseStatus_MetaData[] = {
		{ "Category", "PicoXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_CombinedEyePoseStatus = { "CombinedEyePoseStatus", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPicoXREyeTrackingData, CombinedEyePoseStatus), METADATA_PARAMS(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_CombinedEyePoseStatus_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_CombinedEyePoseStatus_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_CombinedEyeGazePoint_MetaData[] = {
		{ "Category", "PicoXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_CombinedEyeGazePoint = { "CombinedEyeGazePoint", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPicoXREyeTrackingData, CombinedEyeGazePoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_CombinedEyeGazePoint_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_CombinedEyeGazePoint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_CombinedEyeGazeVector_MetaData[] = {
		{ "Category", "PicoXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_CombinedEyeGazeVector = { "CombinedEyeGazeVector", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPicoXREyeTrackingData, CombinedEyeGazeVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_CombinedEyeGazeVector_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_CombinedEyeGazeVector_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_LeftEyeOpenness_MetaData[] = {
		{ "Category", "PicoXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_LeftEyeOpenness = { "LeftEyeOpenness", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPicoXREyeTrackingData, LeftEyeOpenness), METADATA_PARAMS(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_LeftEyeOpenness_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_LeftEyeOpenness_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_RightEyeOpenness_MetaData[] = {
		{ "Category", "PicoXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_RightEyeOpenness = { "RightEyeOpenness", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPicoXREyeTrackingData, RightEyeOpenness), METADATA_PARAMS(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_RightEyeOpenness_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_RightEyeOpenness_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_LeftEyePositionGuide_MetaData[] = {
		{ "Category", "PicoXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_LeftEyePositionGuide = { "LeftEyePositionGuide", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPicoXREyeTrackingData, LeftEyePositionGuide), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_LeftEyePositionGuide_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_LeftEyePositionGuide_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_RightEyePositionGuide_MetaData[] = {
		{ "Category", "PicoXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_RightEyePositionGuide = { "RightEyePositionGuide", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPicoXREyeTrackingData, RightEyePositionGuide), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_RightEyePositionGuide_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_RightEyePositionGuide_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_FoveatedGazeDirection_MetaData[] = {
		{ "Category", "PicoXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_FoveatedGazeDirection = { "FoveatedGazeDirection", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPicoXREyeTrackingData, FoveatedGazeDirection), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_FoveatedGazeDirection_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_FoveatedGazeDirection_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_FoveatedGazeTrackingState_MetaData[] = {
		{ "Category", "PicoXREyeTrackingData" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_FoveatedGazeTrackingState = { "FoveatedGazeTrackingState", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPicoXREyeTrackingData, FoveatedGazeTrackingState), METADATA_PARAMS(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_FoveatedGazeTrackingState_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_FoveatedGazeTrackingState_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_LeftEyePoseStatus,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_RightEyePoseStatus,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_CombinedEyePoseStatus,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_CombinedEyeGazePoint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_CombinedEyeGazeVector,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_LeftEyeOpenness,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_RightEyeOpenness,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_LeftEyePositionGuide,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_RightEyePositionGuide,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_FoveatedGazeDirection,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::NewProp_FoveatedGazeTrackingState,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PicoXRHMD,
		nullptr,
		&NewStructOps,
		"PicoXREyeTrackingData",
		sizeof(FPicoXREyeTrackingData),
		alignof(FPicoXREyeTrackingData),
		Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPicoXREyeTrackingData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_PicoXRHMD();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("PicoXREyeTrackingData"), sizeof(FPicoXREyeTrackingData), Get_Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FPicoXREyeTrackingData_Hash() { return 3965820371U; }
class UScriptStruct* FPxrSensorState::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern PICOXRHMD_API uint32 Get_Z_Construct_UScriptStruct_FPxrSensorState_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FPxrSensorState, Z_Construct_UPackage__Script_PicoXRHMD(), TEXT("PxrSensorState"), sizeof(FPxrSensorState), Get_Z_Construct_UScriptStruct_FPxrSensorState_Hash());
	}
	return Singleton;
}
template<> PICOXRHMD_API UScriptStruct* StaticStruct<FPxrSensorState>()
{
	return FPxrSensorState::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FPxrSensorState(FPxrSensorState::StaticStruct, TEXT("/Script/PicoXRHMD"), TEXT("PxrSensorState"), false, nullptr, nullptr);
static struct FScriptStruct_PicoXRHMD_StaticRegisterNativesFPxrSensorState
{
	FScriptStruct_PicoXRHMD_StaticRegisterNativesFPxrSensorState()
	{
		UScriptStruct::DeferCppStructOps<FPxrSensorState>(FName(TEXT("PxrSensorState")));
	}
} ScriptStruct_PicoXRHMD_StaticRegisterNativesFPxrSensorState;
	struct Z_Construct_UScriptStruct_FPxrSensorState_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_status_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_status;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_poseQuat_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_poseQuat;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_poseVector_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_poseVector;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_globalPoseQuat_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_globalPoseQuat;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_globalPoseVector_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_globalPoseVector;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_angularVelocity_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_angularVelocity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_linearVelocity_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_linearVelocity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_angularAcceleration_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_angularAcceleration;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_linearAcceleration_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_linearAcceleration;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_poseTimeStampNs_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_poseTimeStampNs;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrSensorState_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPxrSensorState>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_status_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_status = { "status", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPxrSensorState, status), METADATA_PARAMS(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_status_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_status_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseQuat_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseQuat = { "poseQuat", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPxrSensorState, poseQuat), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseQuat_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseQuat_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseVector_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseVector = { "poseVector", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPxrSensorState, poseVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseVector_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseVector_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_globalPoseQuat_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_globalPoseQuat = { "globalPoseQuat", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPxrSensorState, globalPoseQuat), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_globalPoseQuat_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_globalPoseQuat_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_globalPoseVector_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_globalPoseVector = { "globalPoseVector", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPxrSensorState, globalPoseVector), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_globalPoseVector_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_globalPoseVector_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_angularVelocity_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_angularVelocity = { "angularVelocity", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPxrSensorState, angularVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_angularVelocity_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_angularVelocity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_linearVelocity_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_linearVelocity = { "linearVelocity", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPxrSensorState, linearVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_linearVelocity_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_linearVelocity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_angularAcceleration_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_angularAcceleration = { "angularAcceleration", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPxrSensorState, angularAcceleration), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_angularAcceleration_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_angularAcceleration_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_linearAcceleration_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_linearAcceleration = { "linearAcceleration", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPxrSensorState, linearAcceleration), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_linearAcceleration_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_linearAcceleration_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseTimeStampNs_MetaData[] = {
		{ "Category", "PXR|PXRSystemAPI" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseTimeStampNs = { "poseTimeStampNs", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPxrSensorState, poseTimeStampNs), METADATA_PARAMS(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseTimeStampNs_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseTimeStampNs_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPxrSensorState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_status,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseQuat,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseVector,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_globalPoseQuat,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_globalPoseVector,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_angularVelocity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_linearVelocity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_angularAcceleration,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_linearAcceleration,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPxrSensorState_Statics::NewProp_poseTimeStampNs,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPxrSensorState_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PicoXRHMD,
		nullptr,
		&NewStructOps,
		"PxrSensorState",
		sizeof(FPxrSensorState),
		alignof(FPxrSensorState),
		Z_Construct_UScriptStruct_FPxrSensorState_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FPxrSensorState_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPxrSensorState_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPxrSensorState()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FPxrSensorState_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_PicoXRHMD();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("PxrSensorState"), sizeof(FPxrSensorState), Get_Z_Construct_UScriptStruct_FPxrSensorState_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FPxrSensorState_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FPxrSensorState_Hash() { return 3820064039U; }
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_SetLargeSpaceEnable)
	{
		P_GET_UBOOL(Z_Param_bEnable);
		P_GET_PROPERTY(FIntProperty,Z_Param_ext);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPicoXRHMDFunctionLibrary::PXR_SetLargeSpaceEnable(Z_Param_bEnable,Z_Param_ext);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetPredictedMainSensorState)
	{
		P_GET_STRUCT_REF(FPxrSensorState,Z_Param_Out_sensorState);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_sensorFrameIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPicoXRHMDFunctionLibrary::PXR_GetPredictedMainSensorState(Z_Param_Out_sensorState,Z_Param_Out_sensorFrameIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_SetExtraLatencyMode)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Mode);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_SetExtraLatencyMode(Z_Param_Mode);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetDisplayFrequenciesAvailable)
	{
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_Count);
		P_GET_TARRAY_REF(float,Z_Param_Out_AvailableRates);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetDisplayFrequenciesAvailable(Z_Param_Out_Count,Z_Param_Out_AvailableRates);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_SetSensorLostCMST)
	{
		P_GET_UBOOL(Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_SetSensorLostCMST(Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_SetSensorLostCustomMode)
	{
		P_GET_UBOOL(Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_SetSensorLostCustomMode(Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_EnableAutoShowSplashScreen)
	{
		P_GET_UBOOL(Z_Param_Enable);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPicoXRHMDFunctionLibrary::PXR_EnableAutoShowSplashScreen(Z_Param_Enable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_ClearLoadingSplashScreens)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		UPicoXRHMDFunctionLibrary::PXR_ClearLoadingSplashScreens();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_AddSplashScreen)
	{
		P_GET_OBJECT(UTexture2D,Z_Param_Texture);
		P_GET_STRUCT(FVector,Z_Param_TranslationInMeters);
		P_GET_STRUCT(FRotator,Z_Param_Rotation);
		P_GET_STRUCT(FVector2D,Z_Param_SizeInMeters);
		P_GET_UBOOL(Z_Param_bClearBeforeAdd);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_AddSplashScreen(Z_Param_Texture,Z_Param_TranslationInMeters,Z_Param_Rotation,Z_Param_SizeInMeters,Z_Param_bClearBeforeAdd);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_EnableFaceTracking)
	{
		P_GET_UBOOL(Z_Param_enable);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_EnableFaceTracking(Z_Param_enable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetEyeTrackingPos)
	{
		P_GET_STRUCT_REF(FVector,Z_Param_Out_EyeTrackingPos);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetEyeTrackingPos(Z_Param_Out_EyeTrackingPos);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_EnableEyeTrackingMarker)
	{
		P_GET_UBOOL(Z_Param_Enable);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPicoXRHMDFunctionLibrary::PXR_EnableEyeTrackingMarker(Z_Param_Enable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetEyeTrackingData)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FPicoXREyeTrackingData*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetEyeTrackingData();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetEyeTrackingGazeRay)
	{
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Origin);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Direction);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetEyeTrackingGazeRay(Z_Param_Out_Origin,Z_Param_Out_Direction);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_SetFoveationParameter)
	{
		P_GET_STRUCT(FVector2D,Z_Param_FoveationGainValue);
		P_GET_PROPERTY(FFloatProperty,Z_Param_FoveationAreaValue);
		P_GET_PROPERTY(FFloatProperty,Z_Param_FoveationMinimumValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_SetFoveationParameter(Z_Param_FoveationGainValue,Z_Param_FoveationAreaValue,Z_Param_FoveationMinimumValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_SetFoveationLevel)
	{
		P_GET_ENUM(EPicoXRFoveationLevel,Z_Param_Level);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_SetFoveationLevel(EPicoXRFoveationLevel(Z_Param_Level));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetFoveationLevel)
	{
		P_GET_ENUM_REF(EPicoXRFoveationLevel,Z_Param_Out_FoveationLevel);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetFoveationLevel((EPicoXRFoveationLevel&)(Z_Param_Out_FoveationLevel));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_EnableFoveation)
	{
		P_GET_UBOOL(Z_Param_Enable);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPicoXRHMDFunctionLibrary::PXR_EnableFoveation(Z_Param_Enable);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetDialogState)
	{
		P_GET_ENUM_REF(EPicoXRBoundaryState,Z_Param_Out_State);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPicoXRHMDFunctionLibrary::PXR_GetDialogState((EPicoXRBoundaryState&)(Z_Param_Out_State));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_SetSeeThroughBackground)
	{
		P_GET_UBOOL(Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_SetSeeThroughBackground(Z_Param_Value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_SetBoundaryCameraImageSize)
	{
		P_GET_STRUCT(FIntPoint,Z_Param_ImageSize);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_SetBoundaryCameraImageSize(Z_Param_ImageSize);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetBoundarySeeThroughData)
	{
		P_GET_ENUM(EPicoXRCameraType,Z_Param_CameraType);
		P_GET_OBJECT_REF(UTexture2D,Z_Param_Out_CameraImage);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetBoundarySeeThroughData(EPicoXRCameraType(Z_Param_CameraType),Z_Param_Out_CameraImage);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetBoundaryDimensions)
	{
		P_GET_ENUM(EPicoXRBoundaryType,Z_Param_BoundaryType);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetBoundaryDimensions(EPicoXRBoundaryType(Z_Param_BoundaryType));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetBoundaryGeometry)
	{
		P_GET_ENUM(EPicoXRBoundaryType,Z_Param_BoundaryType);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FVector>*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetBoundaryGeometry(EPicoXRBoundaryType(Z_Param_BoundaryType));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_BoundaryTestPoint)
	{
		P_GET_STRUCT(FVector,Z_Param_Point);
		P_GET_ENUM(EPicoXRBoundaryType,Z_Param_BoundaryType);
		P_GET_UBOOL_REF(Z_Param_Out_IsTriggering);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_ClosestDistance);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_ClosestPoint);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_ClosestPointNormal);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_BoundaryTestPoint(Z_Param_Point,EPicoXRBoundaryType(Z_Param_BoundaryType),Z_Param_Out_IsTriggering,Z_Param_Out_ClosestDistance,Z_Param_Out_ClosestPoint,Z_Param_Out_ClosestPointNormal);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_BoundaryTestNode)
	{
		P_GET_ENUM(EPicoXRNodeType,Z_Param_DeviceType);
		P_GET_ENUM(EPicoXRBoundaryType,Z_Param_BoundaryType);
		P_GET_UBOOL_REF(Z_Param_Out_IsTriggering);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_ClosestDistance);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_ClosestPoint);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_ClosestPointNormal);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_BoundaryTestNode(EPicoXRNodeType(Z_Param_DeviceType),EPicoXRBoundaryType(Z_Param_BoundaryType),Z_Param_Out_IsTriggering,Z_Param_Out_ClosestDistance,Z_Param_Out_ClosestPoint,Z_Param_Out_ClosestPointNormal);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetBoundaryVisible)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetBoundaryVisible();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_SetBoundaryVisible)
	{
		P_GET_UBOOL(Z_Param_NewVisible);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPicoXRHMDFunctionLibrary::PXR_SetBoundaryVisible(Z_Param_NewVisible);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetBoundaryEnabled)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetBoundaryEnabled();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetBoundaryConfigured)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetBoundaryConfigured();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execGetFocusState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRHMDFunctionLibrary::GetFocusState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_SetColorScaleAndOffset)
	{
		P_GET_STRUCT(FLinearColor,Z_Param_ColorScale);
		P_GET_STRUCT(FLinearColor,Z_Param_ColorOffset);
		P_GET_UBOOL(Z_Param_bApplyToAllLayers);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPicoXRHMDFunctionLibrary::PXR_SetColorScaleAndOffset(Z_Param_ColorScale,Z_Param_ColorOffset,Z_Param_bApplyToAllLayers);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_SetSystemDisplayFrequency)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Rate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPicoXRHMDFunctionLibrary::PXR_SetSystemDisplayFrequency(Z_Param_Rate);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetSystemDisplayFrequency)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetSystemDisplayFrequency();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetCPUAndGPULevels)
	{
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_CPULevel);
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_GPULevel);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPicoXRHMDFunctionLibrary::PXR_GetCPUAndGPULevels(Z_Param_Out_CPULevel,Z_Param_Out_GPULevel);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_SetCPUAndGPULevels)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_CPULevel);
		P_GET_PROPERTY(FIntProperty,Z_Param_GPULevel);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPicoXRHMDFunctionLibrary::PXR_SetCPUAndGPULevels(Z_Param_CPULevel,Z_Param_GPULevel);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetCurrentDisplayFrequency)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetCurrentDisplayFrequency();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetDeviceModel)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetDeviceModel();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetEventManager)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPicoXREventManager**)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetEventManager();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_IPDChangedDelegates)
	{
		P_GET_PROPERTY(FDelegateProperty,Z_Param_OnPicoXRIPDChanged);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPicoXRHMDFunctionLibrary::PXR_IPDChangedDelegates(FPicoXRIPDChangedDelegate(Z_Param_OnPicoXRIPDChanged));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetIPD)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetIPD();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetHFov)
	{
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_HFOVInDegrees);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPicoXRHMDFunctionLibrary::PXR_GetHFov(Z_Param_Out_HFOVInDegrees);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetVFov)
	{
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_VFOVInDegrees);
		P_FINISH;
		P_NATIVE_BEGIN;
		UPicoXRHMDFunctionLibrary::PXR_GetVFov(Z_Param_Out_VFOVInDegrees);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetFieldOfView)
	{
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_HFOVInDegrees);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_VFOVInDegrees);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetFieldOfView(Z_Param_Out_HFOVInDegrees,Z_Param_Out_VFOVInDegrees);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_ResetHMDSensor)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_ResetHMDSensor();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetHMDWornState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TEnumAsByte<EHMDWornState::Type>*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetHMDWornState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetAngularAcceleration)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetAngularAcceleration();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetVelocity)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetVelocity();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetAcceleration)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetAcceleration();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetAngularVelocity)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetAngularVelocity();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_DoesSupportPositionalTracking)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_DoesSupportPositionalTracking();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetCurrentPosition)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetCurrentPosition();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoXRHMDFunctionLibrary::execPXR_GetCurrentOrientation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FQuat*)Z_Param__Result=UPicoXRHMDFunctionLibrary::PXR_GetCurrentOrientation();
		P_NATIVE_END;
	}
	void UPicoXRHMDFunctionLibrary::StaticRegisterNativesUPicoXRHMDFunctionLibrary()
	{
		UClass* Class = UPicoXRHMDFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetFocusState", &UPicoXRHMDFunctionLibrary::execGetFocusState },
			{ "PXR_AddSplashScreen", &UPicoXRHMDFunctionLibrary::execPXR_AddSplashScreen },
			{ "PXR_BoundaryTestNode", &UPicoXRHMDFunctionLibrary::execPXR_BoundaryTestNode },
			{ "PXR_BoundaryTestPoint", &UPicoXRHMDFunctionLibrary::execPXR_BoundaryTestPoint },
			{ "PXR_ClearLoadingSplashScreens", &UPicoXRHMDFunctionLibrary::execPXR_ClearLoadingSplashScreens },
			{ "PXR_DoesSupportPositionalTracking", &UPicoXRHMDFunctionLibrary::execPXR_DoesSupportPositionalTracking },
			{ "PXR_EnableAutoShowSplashScreen", &UPicoXRHMDFunctionLibrary::execPXR_EnableAutoShowSplashScreen },
			{ "PXR_EnableEyeTrackingMarker", &UPicoXRHMDFunctionLibrary::execPXR_EnableEyeTrackingMarker },
			{ "PXR_EnableFaceTracking", &UPicoXRHMDFunctionLibrary::execPXR_EnableFaceTracking },
			{ "PXR_EnableFoveation", &UPicoXRHMDFunctionLibrary::execPXR_EnableFoveation },
			{ "PXR_GetAcceleration", &UPicoXRHMDFunctionLibrary::execPXR_GetAcceleration },
			{ "PXR_GetAngularAcceleration", &UPicoXRHMDFunctionLibrary::execPXR_GetAngularAcceleration },
			{ "PXR_GetAngularVelocity", &UPicoXRHMDFunctionLibrary::execPXR_GetAngularVelocity },
			{ "PXR_GetBoundaryConfigured", &UPicoXRHMDFunctionLibrary::execPXR_GetBoundaryConfigured },
			{ "PXR_GetBoundaryDimensions", &UPicoXRHMDFunctionLibrary::execPXR_GetBoundaryDimensions },
			{ "PXR_GetBoundaryEnabled", &UPicoXRHMDFunctionLibrary::execPXR_GetBoundaryEnabled },
			{ "PXR_GetBoundaryGeometry", &UPicoXRHMDFunctionLibrary::execPXR_GetBoundaryGeometry },
			{ "PXR_GetBoundarySeeThroughData", &UPicoXRHMDFunctionLibrary::execPXR_GetBoundarySeeThroughData },
			{ "PXR_GetBoundaryVisible", &UPicoXRHMDFunctionLibrary::execPXR_GetBoundaryVisible },
			{ "PXR_GetCPUAndGPULevels", &UPicoXRHMDFunctionLibrary::execPXR_GetCPUAndGPULevels },
			{ "PXR_GetCurrentDisplayFrequency", &UPicoXRHMDFunctionLibrary::execPXR_GetCurrentDisplayFrequency },
			{ "PXR_GetCurrentOrientation", &UPicoXRHMDFunctionLibrary::execPXR_GetCurrentOrientation },
			{ "PXR_GetCurrentPosition", &UPicoXRHMDFunctionLibrary::execPXR_GetCurrentPosition },
			{ "PXR_GetDeviceModel", &UPicoXRHMDFunctionLibrary::execPXR_GetDeviceModel },
			{ "PXR_GetDialogState", &UPicoXRHMDFunctionLibrary::execPXR_GetDialogState },
			{ "PXR_GetDisplayFrequenciesAvailable", &UPicoXRHMDFunctionLibrary::execPXR_GetDisplayFrequenciesAvailable },
			{ "PXR_GetEventManager", &UPicoXRHMDFunctionLibrary::execPXR_GetEventManager },
			{ "PXR_GetEyeTrackingData", &UPicoXRHMDFunctionLibrary::execPXR_GetEyeTrackingData },
			{ "PXR_GetEyeTrackingGazeRay", &UPicoXRHMDFunctionLibrary::execPXR_GetEyeTrackingGazeRay },
			{ "PXR_GetEyeTrackingPos", &UPicoXRHMDFunctionLibrary::execPXR_GetEyeTrackingPos },
			{ "PXR_GetFieldOfView", &UPicoXRHMDFunctionLibrary::execPXR_GetFieldOfView },
			{ "PXR_GetFoveationLevel", &UPicoXRHMDFunctionLibrary::execPXR_GetFoveationLevel },
			{ "PXR_GetHFov", &UPicoXRHMDFunctionLibrary::execPXR_GetHFov },
			{ "PXR_GetHMDWornState", &UPicoXRHMDFunctionLibrary::execPXR_GetHMDWornState },
			{ "PXR_GetIPD", &UPicoXRHMDFunctionLibrary::execPXR_GetIPD },
			{ "PXR_GetPredictedMainSensorState", &UPicoXRHMDFunctionLibrary::execPXR_GetPredictedMainSensorState },
			{ "PXR_GetSystemDisplayFrequency", &UPicoXRHMDFunctionLibrary::execPXR_GetSystemDisplayFrequency },
			{ "PXR_GetVelocity", &UPicoXRHMDFunctionLibrary::execPXR_GetVelocity },
			{ "PXR_GetVFov", &UPicoXRHMDFunctionLibrary::execPXR_GetVFov },
			{ "PXR_IPDChangedDelegates", &UPicoXRHMDFunctionLibrary::execPXR_IPDChangedDelegates },
			{ "PXR_ResetHMDSensor", &UPicoXRHMDFunctionLibrary::execPXR_ResetHMDSensor },
			{ "PXR_SetBoundaryCameraImageSize", &UPicoXRHMDFunctionLibrary::execPXR_SetBoundaryCameraImageSize },
			{ "PXR_SetBoundaryVisible", &UPicoXRHMDFunctionLibrary::execPXR_SetBoundaryVisible },
			{ "PXR_SetColorScaleAndOffset", &UPicoXRHMDFunctionLibrary::execPXR_SetColorScaleAndOffset },
			{ "PXR_SetCPUAndGPULevels", &UPicoXRHMDFunctionLibrary::execPXR_SetCPUAndGPULevels },
			{ "PXR_SetExtraLatencyMode", &UPicoXRHMDFunctionLibrary::execPXR_SetExtraLatencyMode },
			{ "PXR_SetFoveationLevel", &UPicoXRHMDFunctionLibrary::execPXR_SetFoveationLevel },
			{ "PXR_SetFoveationParameter", &UPicoXRHMDFunctionLibrary::execPXR_SetFoveationParameter },
			{ "PXR_SetLargeSpaceEnable", &UPicoXRHMDFunctionLibrary::execPXR_SetLargeSpaceEnable },
			{ "PXR_SetSeeThroughBackground", &UPicoXRHMDFunctionLibrary::execPXR_SetSeeThroughBackground },
			{ "PXR_SetSensorLostCMST", &UPicoXRHMDFunctionLibrary::execPXR_SetSensorLostCMST },
			{ "PXR_SetSensorLostCustomMode", &UPicoXRHMDFunctionLibrary::execPXR_SetSensorLostCustomMode },
			{ "PXR_SetSystemDisplayFrequency", &UPicoXRHMDFunctionLibrary::execPXR_SetSystemDisplayFrequency },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_GetFocusState_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventGetFocusState_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_GetFocusState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventGetFocusState_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_GetFocusState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventGetFocusState_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_GetFocusState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_GetFocusState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_GetFocusState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_GetFocusState_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Returns true, if the app has focus.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Returns true, if the app has focus." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_GetFocusState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "GetFocusState", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventGetFocusState_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_GetFocusState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_GetFocusState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_GetFocusState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_GetFocusState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_GetFocusState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_GetFocusState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_AddSplashScreen_Parms
		{
			UTexture2D* Texture;
			FVector TranslationInMeters;
			FRotator Rotation;
			FVector2D SizeInMeters;
			bool bClearBeforeAdd;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Texture;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TranslationInMeters;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Rotation;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SizeInMeters;
		static void NewProp_bClearBeforeAdd_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bClearBeforeAdd;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_AddSplashScreen_Parms, Texture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::NewProp_TranslationInMeters = { "TranslationInMeters", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_AddSplashScreen_Parms, TranslationInMeters), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_AddSplashScreen_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::NewProp_SizeInMeters = { "SizeInMeters", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_AddSplashScreen_Parms, SizeInMeters), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::NewProp_bClearBeforeAdd_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_AddSplashScreen_Parms*)Obj)->bClearBeforeAdd = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::NewProp_bClearBeforeAdd = { "bClearBeforeAdd", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_AddSplashScreen_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::NewProp_bClearBeforeAdd_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_AddSplashScreen_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_AddSplashScreen_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::NewProp_Texture,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::NewProp_TranslationInMeters,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::NewProp_Rotation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::NewProp_SizeInMeters,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::NewProp_bClearBeforeAdd,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09 * Adds loading splash screen with parameters.\n\x09 * @param Texture\x09\x09\x09  (in) A texture asset to be used for the splash. Gear VR uses it as a path for loading icon; all other params are currently ignored by Gear VR.\n\x09 * @param TranslationInMeters (in) Initial translation of the center of the splash screen (in meters).\n\x09 * @param Rotation\x09\x09\x09  (in) Initial rotation of the splash screen, with the origin at the center of the splash screen.\n\x09 * @param SizeInMeters\x09\x09  (in) Size, in meters, of the quad with the splash screen.\n\x09 * @param DeltaRotation\x09\x09  (in) Incremental rotation, that is added each 2nd frame to the quad transform. The quad is rotated around the center of the quad.\n\x09 * @param bClearBeforeAdd\x09  (in) If true, clears splashes before adding a new one.\n\x09 */" },
		{ "CPP_Default_bClearBeforeAdd", "false" },
		{ "CPP_Default_SizeInMeters", "(X=1.000,Y=1.000)" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Adds loading splash screen with parameters.\n@param Texture                         (in) A texture asset to be used for the splash. Gear VR uses it as a path for loading icon; all other params are currently ignored by Gear VR.\n@param TranslationInMeters (in) Initial translation of the center of the splash screen (in meters).\n@param Rotation                        (in) Initial rotation of the splash screen, with the origin at the center of the splash screen.\n@param SizeInMeters            (in) Size, in meters, of the quad with the splash screen.\n@param DeltaRotation           (in) Incremental rotation, that is added each 2nd frame to the quad transform. The quad is rotated around the center of the quad.\n@param bClearBeforeAdd         (in) If true, clears splashes before adding a new one." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_AddSplashScreen", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_AddSplashScreen_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_BoundaryTestNode_Parms
		{
			EPicoXRNodeType DeviceType;
			EPicoXRBoundaryType BoundaryType;
			bool IsTriggering;
			float ClosestDistance;
			FVector ClosestPoint;
			FVector ClosestPointNormal;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_DeviceType_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_DeviceType;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_BoundaryType_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_BoundaryType;
		static void NewProp_IsTriggering_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsTriggering;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ClosestDistance;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ClosestPoint;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ClosestPointNormal;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_DeviceType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_DeviceType = { "DeviceType", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_BoundaryTestNode_Parms, DeviceType), Z_Construct_UEnum_PicoXRHMD_EPicoXRNodeType, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_BoundaryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_BoundaryType = { "BoundaryType", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_BoundaryTestNode_Parms, BoundaryType), Z_Construct_UEnum_PicoXRHMD_EPicoXRBoundaryType, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_IsTriggering_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_BoundaryTestNode_Parms*)Obj)->IsTriggering = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_IsTriggering = { "IsTriggering", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_BoundaryTestNode_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_IsTriggering_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_ClosestDistance = { "ClosestDistance", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_BoundaryTestNode_Parms, ClosestDistance), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_ClosestPoint = { "ClosestPoint", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_BoundaryTestNode_Parms, ClosestPoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_ClosestPointNormal = { "ClosestPointNormal", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_BoundaryTestNode_Parms, ClosestPointNormal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_BoundaryTestNode_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_BoundaryTestNode_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_DeviceType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_DeviceType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_BoundaryType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_BoundaryType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_IsTriggering,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_ClosestDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_ClosestPoint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_ClosestPointNormal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Get the intersection result between a tracked device (HMD or controllers) and a Boundary boundary\n\x09* @param DeviceType             (in) Tracked Device type to test against Boundary \n\x09* @param BoundaryType\x09\x09\x09(in) An enum representing the boundary type requested, either Outer Boundary (exact Boundary bounds) or PlayArea (rectangle inside the Outer Boundary)\n\x09* @param IsTriggering           (out) The intersection result between a tracked device (HMD or controllers) and a Boundary \n\x09* @param ClosestDistance        (out) The closest distance between a tracked device (HMD or controllers) and a Boundary\n\x09* @param ClosestPoint           (out) The closest point on surface corresponding to specified boundary \n\x09* @param ClosestPointNormal     (out) Normal of closest point\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Get the intersection result between a tracked device (HMD or controllers) and a Boundary boundary\n@param DeviceType             (in) Tracked Device type to test against Boundary\n@param BoundaryType                   (in) An enum representing the boundary type requested, either Outer Boundary (exact Boundary bounds) or PlayArea (rectangle inside the Outer Boundary)\n@param IsTriggering           (out) The intersection result between a tracked device (HMD or controllers) and a Boundary\n@param ClosestDistance        (out) The closest distance between a tracked device (HMD or controllers) and a Boundary\n@param ClosestPoint           (out) The closest point on surface corresponding to specified boundary\n@param ClosestPointNormal     (out) Normal of closest point" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_BoundaryTestNode", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_BoundaryTestNode_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_BoundaryTestPoint_Parms
		{
			FVector Point;
			EPicoXRBoundaryType BoundaryType;
			bool IsTriggering;
			float ClosestDistance;
			FVector ClosestPoint;
			FVector ClosestPointNormal;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Point;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_BoundaryType_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_BoundaryType;
		static void NewProp_IsTriggering_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsTriggering;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ClosestDistance;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ClosestPoint;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ClosestPointNormal;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_Point = { "Point", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_BoundaryTestPoint_Parms, Point), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_BoundaryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_BoundaryType = { "BoundaryType", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_BoundaryTestPoint_Parms, BoundaryType), Z_Construct_UEnum_PicoXRHMD_EPicoXRBoundaryType, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_IsTriggering_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_BoundaryTestPoint_Parms*)Obj)->IsTriggering = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_IsTriggering = { "IsTriggering", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_BoundaryTestPoint_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_IsTriggering_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_ClosestDistance = { "ClosestDistance", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_BoundaryTestPoint_Parms, ClosestDistance), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_ClosestPoint = { "ClosestPoint", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_BoundaryTestPoint_Parms, ClosestPoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_ClosestPointNormal = { "ClosestPointNormal", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_BoundaryTestPoint_Parms, ClosestPointNormal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_BoundaryTestPoint_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_BoundaryTestPoint_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_Point,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_BoundaryType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_BoundaryType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_IsTriggering,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_ClosestDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_ClosestPoint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_ClosestPointNormal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Get the intersection result between a UE4 coordinate and a Boundary boundary\n\x09* @param Point\x09\x09\x09\x09\x09(in) Point in UE space to test against Boundary boundaries\n\x09* @param BoundaryType\x09\x09\x09(in) An enum representing the boundary type requested, either Outer Boundary (exact Boundary bounds) or PlayArea (rectangle inside the Outer Boundary)\n\x09* @param IsTriggering           (out) The intersection result between a tracked device (HMD or controllers) and a Boundary \n\x09* @param ClosestDistance        (out) The closest distance between a tracked device (HMD or controllers) and a Boundary\n\x09* @param ClosestPoint           (out) The closest point on surface corresponding to specified boundary \n\x09* @param ClosestPointNormal     (out) Normal of closest point\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Get the intersection result between a UE4 coordinate and a Boundary boundary\n@param Point                                  (in) Point in UE space to test against Boundary boundaries\n@param BoundaryType                   (in) An enum representing the boundary type requested, either Outer Boundary (exact Boundary bounds) or PlayArea (rectangle inside the Outer Boundary)\n@param IsTriggering           (out) The intersection result between a tracked device (HMD or controllers) and a Boundary\n@param ClosestDistance        (out) The closest distance between a tracked device (HMD or controllers) and a Boundary\n@param ClosestPoint           (out) The closest point on surface corresponding to specified boundary\n@param ClosestPointNormal     (out) Normal of closest point" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_BoundaryTestPoint", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_BoundaryTestPoint_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_ClearLoadingSplashScreens_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_ClearLoadingSplashScreens_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09 * Removes all the splash screens.\n\x09 */" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Removes all the splash screens." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_ClearLoadingSplashScreens_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_ClearLoadingSplashScreens", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_ClearLoadingSplashScreens_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_ClearLoadingSplashScreens_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_ClearLoadingSplashScreens()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_ClearLoadingSplashScreens_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_DoesSupportPositionalTracking_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_DoesSupportPositionalTracking_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_DoesSupportPositionalTracking_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Gets whether the device supports position tracking\n\x09* @return  true: Tracking position(6Dof),false: Can not tracking position(3Dof).\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Gets whether the device supports position tracking\n@return  true: Tracking position(6Dof),false: Can not tracking position(3Dof)." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_DoesSupportPositionalTracking", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_DoesSupportPositionalTracking_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableAutoShowSplashScreen_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_EnableAutoShowSplashScreen_Parms
		{
			bool Enable;
		};
		static void NewProp_Enable_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Enable;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableAutoShowSplashScreen_Statics::NewProp_Enable_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_EnableAutoShowSplashScreen_Parms*)Obj)->Enable = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableAutoShowSplashScreen_Statics::NewProp_Enable = { "Enable", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_EnableAutoShowSplashScreen_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableAutoShowSplashScreen_Statics::NewProp_Enable_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableAutoShowSplashScreen_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableAutoShowSplashScreen_Statics::NewProp_Enable,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableAutoShowSplashScreen_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09 * Enable auto show splash screen.\n\x09 */" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Enable auto show splash screen." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableAutoShowSplashScreen_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_EnableAutoShowSplashScreen", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_EnableAutoShowSplashScreen_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableAutoShowSplashScreen_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableAutoShowSplashScreen_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableAutoShowSplashScreen_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableAutoShowSplashScreen_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableAutoShowSplashScreen()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableAutoShowSplashScreen_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableEyeTrackingMarker_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_EnableEyeTrackingMarker_Parms
		{
			bool Enable;
		};
		static void NewProp_Enable_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Enable;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableEyeTrackingMarker_Statics::NewProp_Enable_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_EnableEyeTrackingMarker_Parms*)Obj)->Enable = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableEyeTrackingMarker_Statics::NewProp_Enable = { "Enable", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_EnableEyeTrackingMarker_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableEyeTrackingMarker_Statics::NewProp_Enable_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableEyeTrackingMarker_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableEyeTrackingMarker_Statics::NewProp_Enable,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableEyeTrackingMarker_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableEyeTrackingMarker_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_EnableEyeTrackingMarker", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_EnableEyeTrackingMarker_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableEyeTrackingMarker_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableEyeTrackingMarker_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableEyeTrackingMarker_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableEyeTrackingMarker_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableEyeTrackingMarker()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableEyeTrackingMarker_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFaceTracking_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_EnableFaceTracking_Parms
		{
			bool enable;
			bool ReturnValue;
		};
		static void NewProp_enable_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_enable;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFaceTracking_Statics::NewProp_enable_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_EnableFaceTracking_Parms*)Obj)->enable = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFaceTracking_Statics::NewProp_enable = { "enable", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_EnableFaceTracking_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFaceTracking_Statics::NewProp_enable_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFaceTracking_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_EnableFaceTracking_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFaceTracking_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_EnableFaceTracking_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFaceTracking_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFaceTracking_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFaceTracking_Statics::NewProp_enable,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFaceTracking_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFaceTracking_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFaceTracking_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_EnableFaceTracking", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_EnableFaceTracking_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFaceTracking_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFaceTracking_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFaceTracking_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFaceTracking_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFaceTracking()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFaceTracking_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFoveation_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_EnableFoveation_Parms
		{
			bool Enable;
		};
		static void NewProp_Enable_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Enable;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFoveation_Statics::NewProp_Enable_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_EnableFoveation_Parms*)Obj)->Enable = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFoveation_Statics::NewProp_Enable = { "Enable", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_EnableFoveation_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFoveation_Statics::NewProp_Enable_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFoveation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFoveation_Statics::NewProp_Enable,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFoveation_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Enable or disable Foveation rendering.\n\x09* @param Enable\x09\x09\x09(in) Target state.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Enable or disable Foveation rendering.\n@param Enable                 (in) Target state." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFoveation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_EnableFoveation", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_EnableFoveation_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFoveation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFoveation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFoveation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFoveation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFoveation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFoveation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAcceleration_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetAcceleration_Parms
		{
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAcceleration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetAcceleration_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAcceleration_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAcceleration_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAcceleration_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Get HMD devices acceleration.\n\x09* @return  devices acceleration.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Get HMD devices acceleration.\n@return  devices acceleration." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAcceleration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetAcceleration", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetAcceleration_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAcceleration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAcceleration_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAcceleration_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAcceleration_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAcceleration()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAcceleration_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetAngularAcceleration_Parms
		{
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetAngularAcceleration_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Get HMD devices angular acceleration.\n\x09* @return  devices angular acceleration.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Get HMD devices angular acceleration.\n@return  devices angular acceleration." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetAngularAcceleration", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetAngularAcceleration_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularAcceleration()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularAcceleration_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetAngularVelocity_Parms
		{
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetAngularVelocity_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Get HMD devices angular velocity.\n\x09* @return  devices angular velocity.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Get HMD devices angular velocity.\n@return  devices angular velocity." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetAngularVelocity", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetAngularVelocity_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularVelocity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularVelocity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetBoundaryConfigured_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_GetBoundaryConfigured_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetBoundaryConfigured_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Whether an effective Boundary exists\n\x09* @return true:Exist,false: No exit.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Whether an effective Boundary exists\n@return true:Exist,false: No exit." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetBoundaryConfigured", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetBoundaryConfigured_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryConfigured()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryConfigured_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetBoundaryDimensions_Parms
		{
			EPicoXRBoundaryType BoundaryType;
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_BoundaryType_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_BoundaryType;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::NewProp_BoundaryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::NewProp_BoundaryType = { "BoundaryType", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetBoundaryDimensions_Parms, BoundaryType), Z_Construct_UEnum_PicoXRHMD_EPicoXRBoundaryType, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetBoundaryDimensions_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::NewProp_BoundaryType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::NewProp_BoundaryType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Returns the dimensions in UE world space of the requested Boundary Type\n\x09* @param BoundaryType\x09\x09\x09(in) An enum representing the boundary type requested, either Outer Boundary (exact Boundary bounds) or PlayArea (rectangle inside the Outer Boundary)\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Returns the dimensions in UE world space of the requested Boundary Type\n@param BoundaryType                   (in) An enum representing the boundary type requested, either Outer Boundary (exact Boundary bounds) or PlayArea (rectangle inside the Outer Boundary)" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetBoundaryDimensions", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetBoundaryDimensions_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryDimensions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryDimensions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetBoundaryEnabled_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_GetBoundaryEnabled_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetBoundaryEnabled_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Gets whether Boundary is enabled or not\n\x09* @return true:Boundary is enabled,false: Boundary is not enabled.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Gets whether Boundary is enabled or not\n@return true:Boundary is enabled,false: Boundary is not enabled." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetBoundaryEnabled", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetBoundaryEnabled_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryEnabled()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryEnabled_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetBoundaryGeometry_Parms
		{
			EPicoXRBoundaryType BoundaryType;
			TArray<FVector> ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_BoundaryType_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_BoundaryType;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::NewProp_BoundaryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::NewProp_BoundaryType = { "BoundaryType", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetBoundaryGeometry_Parms, BoundaryType), Z_Construct_UEnum_PicoXRHMD_EPicoXRBoundaryType, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetBoundaryGeometry_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::NewProp_BoundaryType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::NewProp_BoundaryType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::NewProp_ReturnValue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Returns the list of points in UE world space of the requested Boundary Type \n\x09* @param BoundaryType\x09\x09\x09(in) An enum representing the boundary type requested, either Outer Boundary (exact Boundary bounds) or PlayArea (rectangle inside the Outer Boundary)\n\x09* @return The array of points in UE world space of the requested Boundary Type .\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Returns the list of points in UE world space of the requested Boundary Type\n@param BoundaryType                   (in) An enum representing the boundary type requested, either Outer Boundary (exact Boundary bounds) or PlayArea (rectangle inside the Outer Boundary)\n@return The array of points in UE world space of the requested Boundary Type ." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetBoundaryGeometry", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetBoundaryGeometry_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryGeometry()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryGeometry_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundarySeeThroughData_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetBoundarySeeThroughData_Parms
		{
			EPicoXRCameraType CameraType;
			UTexture2D* CameraImage;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_CameraType_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_CameraType;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraImage;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundarySeeThroughData_Statics::NewProp_CameraType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundarySeeThroughData_Statics::NewProp_CameraType = { "CameraType", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetBoundarySeeThroughData_Parms, CameraType), Z_Construct_UEnum_PicoXRHMD_EPicoXRCameraType, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundarySeeThroughData_Statics::NewProp_CameraImage = { "CameraImage", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetBoundarySeeThroughData_Parms, CameraImage), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundarySeeThroughData_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_GetBoundarySeeThroughData_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundarySeeThroughData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetBoundarySeeThroughData_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundarySeeThroughData_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundarySeeThroughData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundarySeeThroughData_Statics::NewProp_CameraType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundarySeeThroughData_Statics::NewProp_CameraType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundarySeeThroughData_Statics::NewProp_CameraImage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundarySeeThroughData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundarySeeThroughData_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Get an image of the device's camera.\n\x09* @param CameraType\x09\x09\x09(in) Left or right camera.\n\x09* @param CameraImage        (out) The image of the device's camera.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Get an image of the device's camera.\n@param CameraType                     (in) Left or right camera.\n@param CameraImage        (out) The image of the device's camera." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundarySeeThroughData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetBoundarySeeThroughData", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetBoundarySeeThroughData_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundarySeeThroughData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundarySeeThroughData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundarySeeThroughData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundarySeeThroughData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundarySeeThroughData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundarySeeThroughData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetBoundaryVisible_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_GetBoundaryVisible_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetBoundaryVisible_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Gets whether Boundary is resident.\n\x09* @return true:Boundary is resident,false: Boundary is not resident.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Gets whether Boundary is resident.\n@return true:Boundary is resident,false: Boundary is not resident." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetBoundaryVisible", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetBoundaryVisible_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryVisible()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryVisible_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetCPUAndGPULevels_Parms
		{
			int32 CPULevel;
			int32 GPULevel;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_CPULevel;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_GPULevel;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::NewProp_CPULevel = { "CPULevel", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetCPUAndGPULevels_Parms, CPULevel), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::NewProp_GPULevel = { "GPULevel", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetCPUAndGPULevels_Parms, GPULevel), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::NewProp_CPULevel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::NewProp_GPULevel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Get CPU GPU level.\n\x09* @param CPULevel   (out) Target CPU level.\n\x09* @param GPULevel   (out) Target GPU level.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Get CPU GPU level.\n@param CPULevel   (out) Target CPU level.\n@param GPULevel   (out) Target GPU level." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetCPUAndGPULevels", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetCPUAndGPULevels_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetCurrentDisplayFrequency_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetCurrentDisplayFrequency_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Get device display frequency.\n\x09* @return device display frequency.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Get device display frequency.\n@return device display frequency." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetCurrentDisplayFrequency", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetCurrentDisplayFrequency_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetCurrentOrientation_Parms
		{
			FQuat ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetCurrentOrientation_Parms, ReturnValue), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Get HMD devices current orientation.\n\x09* @return  devices current orientation.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Get HMD devices current orientation.\n@return  devices current orientation." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetCurrentOrientation", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetCurrentOrientation_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentOrientation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentOrientation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetCurrentPosition_Parms
		{
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetCurrentPosition_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Get HMD devices current position.\n\x09* @return  devices current position.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Get HMD devices current position.\n@return  devices current position." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetCurrentPosition", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetCurrentPosition_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetDeviceModel_Parms
		{
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetDeviceModel_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n    * Get device series number.\n    * @return device series number.\n    */" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Get device series number.\n@return device series number." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetDeviceModel", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetDeviceModel_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDeviceModel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDeviceModel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDialogState_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetDialogState_Parms
		{
			EPicoXRBoundaryState State;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_State;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDialogState_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDialogState_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetDialogState_Parms, State), Z_Construct_UEnum_PicoXRHMD_EPicoXRBoundaryState, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDialogState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDialogState_Statics::NewProp_State_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDialogState_Statics::NewProp_State,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDialogState_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Get dialog state.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Get dialog state." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDialogState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetDialogState", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetDialogState_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDialogState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDialogState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDialogState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDialogState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDialogState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDialogState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetDisplayFrequenciesAvailable_Parms
		{
			int32 Count;
			TArray<float> AvailableRates;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Count;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AvailableRates_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_AvailableRates;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::NewProp_Count = { "Count", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetDisplayFrequenciesAvailable_Parms, Count), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::NewProp_AvailableRates_Inner = { "AvailableRates", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::NewProp_AvailableRates = { "AvailableRates", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetDisplayFrequenciesAvailable_Parms, AvailableRates), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_GetDisplayFrequenciesAvailable_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetDisplayFrequenciesAvailable_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::NewProp_Count,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::NewProp_AvailableRates_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::NewProp_AvailableRates,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Get display frequencies available.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Get display frequencies available." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetDisplayFrequenciesAvailable", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetDisplayFrequenciesAvailable_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEventManager_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetEventManager_Parms
		{
			UPicoXREventManager* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEventManager_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetEventManager_Parms, ReturnValue), Z_Construct_UClass_UPicoXREventManager_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEventManager_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEventManager_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEventManager_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Get event manager.\n\x09* @return UPicoXREventManager class reference.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Get event manager.\n@return UPicoXREventManager class reference." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEventManager_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetEventManager", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetEventManager_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEventManager_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEventManager_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEventManager_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEventManager_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEventManager()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEventManager_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingData_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetEyeTrackingData_Parms
		{
			FPicoXREyeTrackingData ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetEyeTrackingData_Parms, ReturnValue), Z_Construct_UScriptStruct_FPicoXREyeTrackingData, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingData_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Get EyeTracking data.\n\x09* @return  EyeTracking data.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Get EyeTracking data.\n@return  EyeTracking data." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetEyeTrackingData", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetEyeTrackingData_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingGazeRay_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetEyeTrackingGazeRay_Parms
		{
			FVector Origin;
			FVector Direction;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Origin;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Direction;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingGazeRay_Statics::NewProp_Origin = { "Origin", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetEyeTrackingGazeRay_Parms, Origin), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingGazeRay_Statics::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetEyeTrackingGazeRay_Parms, Direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingGazeRay_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_GetEyeTrackingGazeRay_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingGazeRay_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetEyeTrackingGazeRay_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingGazeRay_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingGazeRay_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingGazeRay_Statics::NewProp_Origin,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingGazeRay_Statics::NewProp_Direction,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingGazeRay_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingGazeRay_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Get EyeTracking gaze ray.\n\x09* @param Origin     The starting point of an eye-tracking ray.\n\x09* @param Direction  A unit vector in the direction of an eye-tracking ray.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Get EyeTracking gaze ray.\n@param Origin     The starting point of an eye-tracking ray.\n@param Direction  A unit vector in the direction of an eye-tracking ray." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingGazeRay_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetEyeTrackingGazeRay", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetEyeTrackingGazeRay_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingGazeRay_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingGazeRay_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingGazeRay_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingGazeRay_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingGazeRay()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingGazeRay_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingPos_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetEyeTrackingPos_Parms
		{
			FVector EyeTrackingPos;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_EyeTrackingPos;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingPos_Statics::NewProp_EyeTrackingPos = { "EyeTrackingPos", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetEyeTrackingPos_Parms, EyeTrackingPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingPos_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_GetEyeTrackingPos_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingPos_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetEyeTrackingPos_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingPos_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingPos_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingPos_Statics::NewProp_EyeTrackingPos,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingPos_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingPos_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingPos_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetEyeTrackingPos", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetEyeTrackingPos_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingPos_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingPos_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingPos_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingPos_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingPos()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingPos_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetFieldOfView_Parms
		{
			float HFOVInDegrees;
			float VFOVInDegrees;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HFOVInDegrees;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VFOVInDegrees;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::NewProp_HFOVInDegrees = { "HFOVInDegrees", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetFieldOfView_Parms, HFOVInDegrees), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::NewProp_VFOVInDegrees = { "VFOVInDegrees", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetFieldOfView_Parms, VFOVInDegrees), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_GetFieldOfView_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetFieldOfView_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::NewProp_HFOVInDegrees,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::NewProp_VFOVInDegrees,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Get device FieldOfView(Fov).\n\x09* @param HFOVInDegrees    (out) Horizontal FOV.\n\x09* @param VFOVInDegrees    (out) Vertical FOV.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Get device FieldOfView(Fov).\n@param HFOVInDegrees    (out) Horizontal FOV.\n@param VFOVInDegrees    (out) Vertical FOV." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetFieldOfView", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetFieldOfView_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFieldOfView()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFieldOfView_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetFoveationLevel_Parms
		{
			EPicoXRFoveationLevel FoveationLevel;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_FoveationLevel_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_FoveationLevel;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::NewProp_FoveationLevel_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::NewProp_FoveationLevel = { "FoveationLevel", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetFoveationLevel_Parms, FoveationLevel), Z_Construct_UEnum_PicoXRHMD_EPicoXRFoveationLevel, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_GetFoveationLevel_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetFoveationLevel_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::NewProp_FoveationLevel_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::NewProp_FoveationLevel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Get current Foveation rendering level.\n\x09* @return  Foveation rendering level.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Get current Foveation rendering level.\n@return  Foveation rendering level." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetFoveationLevel", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetFoveationLevel_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFoveationLevel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFoveationLevel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHFov_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetHFov_Parms
		{
			float HFOVInDegrees;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HFOVInDegrees;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHFov_Statics::NewProp_HFOVInDegrees = { "HFOVInDegrees", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetHFov_Parms, HFOVInDegrees), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHFov_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHFov_Statics::NewProp_HFOVInDegrees,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHFov_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Get device horizontal Fov.\n\x09* @param HFOVInDegrees    (out) Horizontal FOV.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Get device horizontal Fov.\n@param HFOVInDegrees    (out) Horizontal FOV." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHFov_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetHFov", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetHFov_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHFov_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHFov_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHFov_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHFov_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHFov()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHFov_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetHMDWornState_Parms
		{
			TEnumAsByte<EHMDWornState::Type> ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetHMDWornState_Parms, ReturnValue), Z_Construct_UEnum_HeadMountedDisplay_EHMDWornState, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Detect whether the user is wearing the HMD\n\x09* @return\n\x09* EHMDWornState::Worn if we detect that the user is wearing the HMD,\n\x09* EHMDWornState::NotWorn if we detect the user is not wearing the HMD,\n\x09* EHMDWornState::Unknown if we cannot detect the state.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Detect whether the user is wearing the HMD\n@return\nEHMDWornState::Worn if we detect that the user is wearing the HMD,\nEHMDWornState::NotWorn if we detect the user is not wearing the HMD,\nEHMDWornState::Unknown if we cannot detect the state." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetHMDWornState", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetHMDWornState_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHMDWornState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHMDWornState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetIPD_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetIPD_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetIPD_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetIPD_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetIPD_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetIPD_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetIPD_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Get pupil distance of the current device.\n\x09* @return Current devices IPD.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Get pupil distance of the current device.\n@return Current devices IPD." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetIPD_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetIPD", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetIPD_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetIPD_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetIPD_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetIPD_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetIPD_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetIPD()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetIPD_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetPredictedMainSensorState_Parms
		{
			FPxrSensorState sensorState;
			int32 sensorFrameIndex;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_sensorState;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_sensorFrameIndex;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::NewProp_sensorState = { "sensorState", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetPredictedMainSensorState_Parms, sensorState), Z_Construct_UScriptStruct_FPxrSensorState, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::NewProp_sensorFrameIndex = { "sensorFrameIndex", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetPredictedMainSensorState_Parms, sensorFrameIndex), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::NewProp_sensorState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::NewProp_sensorFrameIndex,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetPredictedMainSensorState", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetPredictedMainSensorState_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetSystemDisplayFrequency_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetSystemDisplayFrequency_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Get system display frequency.\n\x09* @return system display frequency.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Get system display frequency.\n@return system display frequency." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetSystemDisplayFrequency", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetSystemDisplayFrequency_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVelocity_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetVelocity_Parms
		{
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVelocity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetVelocity_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVelocity_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVelocity_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVelocity_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Get HMD devices velocity.\n\x09* @return  devices velocity.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Get HMD devices velocity.\n@return  devices velocity." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVelocity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetVelocity", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetVelocity_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVelocity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVelocity_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVelocity_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVelocity_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVelocity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVelocity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVFov_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_GetVFov_Parms
		{
			float VFOVInDegrees;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_VFOVInDegrees;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVFov_Statics::NewProp_VFOVInDegrees = { "VFOVInDegrees", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_GetVFov_Parms, VFOVInDegrees), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVFov_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVFov_Statics::NewProp_VFOVInDegrees,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVFov_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Get device vertical Fov.\n\x09* @param VFOVInDegrees    (out) Vertical FOV.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Get device vertical Fov.\n@param VFOVInDegrees    (out) Vertical FOV." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVFov_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_GetVFov", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_GetVFov_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVFov_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVFov_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVFov_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVFov_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVFov()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVFov_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_IPDChangedDelegates_Parms
		{
			FScriptDelegate OnPicoXRIPDChanged;
		};
		static const UE4CodeGen_Private::FDelegatePropertyParams NewProp_OnPicoXRIPDChanged;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics::NewProp_OnPicoXRIPDChanged = { "OnPicoXRIPDChanged", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_IPDChangedDelegates_Parms, OnPicoXRIPDChanged), Z_Construct_UDelegateFunction_PicoXRHMD_PicoXRIPDChangedDelegate__DelegateSignature, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics::NewProp_OnPicoXRIPDChanged,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Set IPD changed delegate.\n\x09* @param OnPicoXRIPDChanged  (In) FPicoXRIPDChangedDelegate.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Set IPD changed delegate.\n@param OnPicoXRIPDChanged  (In) FPicoXRIPDChangedDelegate." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_IPDChangedDelegates", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_IPDChangedDelegates_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_IPDChangedDelegates()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_IPDChangedDelegates_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_ResetHMDSensor_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_ResetHMDSensor_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_ResetHMDSensor_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Reset HMD Position and Orientation.\n\x09* @return true: reset HMD sensor Succeed, false :reset HMD sensor Failed.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Reset HMD Position and Orientation.\n@return true: reset HMD sensor Succeed, false :reset HMD sensor Failed." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_ResetHMDSensor", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_ResetHMDSensor_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_ResetHMDSensor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_ResetHMDSensor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryCameraImageSize_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_SetBoundaryCameraImageSize_Parms
		{
			FIntPoint ImageSize;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ImageSize;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryCameraImageSize_Statics::NewProp_ImageSize = { "ImageSize", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_SetBoundaryCameraImageSize_Parms, ImageSize), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryCameraImageSize_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_SetBoundaryCameraImageSize_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryCameraImageSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_SetBoundaryCameraImageSize_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryCameraImageSize_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryCameraImageSize_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryCameraImageSize_Statics::NewProp_ImageSize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryCameraImageSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryCameraImageSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Set the size of the image of the device's camera.\n\x09* @param ImageSize\x09\x09\x09(in) Target image size.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Set the size of the image of the device's camera.\n@param ImageSize                      (in) Target image size." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryCameraImageSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_SetBoundaryCameraImageSize", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_SetBoundaryCameraImageSize_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryCameraImageSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryCameraImageSize_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryCameraImageSize_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryCameraImageSize_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryCameraImageSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryCameraImageSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_SetBoundaryVisible_Parms
		{
			bool NewVisible;
		};
		static void NewProp_NewVisible_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_NewVisible;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::NewProp_NewVisible_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_SetBoundaryVisible_Parms*)Obj)->NewVisible = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::NewProp_NewVisible = { "NewVisible", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_SetBoundaryVisible_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::NewProp_NewVisible_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::NewProp_NewVisible,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Gets whether Boundary is resident.\n\x09* @param NewVisible:Target visible state.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Gets whether Boundary is resident.\n@param NewVisible:Target visible state." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_SetBoundaryVisible", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_SetBoundaryVisible_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryVisible()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryVisible_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_SetColorScaleAndOffset_Parms
		{
			FLinearColor ColorScale;
			FLinearColor ColorOffset;
			bool bApplyToAllLayers;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ColorScale;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ColorOffset;
		static void NewProp_bApplyToAllLayers_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bApplyToAllLayers;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::NewProp_ColorScale = { "ColorScale", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_SetColorScaleAndOffset_Parms, ColorScale), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::NewProp_ColorOffset = { "ColorOffset", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_SetColorScaleAndOffset_Parms, ColorOffset), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::NewProp_bApplyToAllLayers_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_SetColorScaleAndOffset_Parms*)Obj)->bApplyToAllLayers = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::NewProp_bApplyToAllLayers = { "bApplyToAllLayers", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_SetColorScaleAndOffset_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::NewProp_bApplyToAllLayers_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::NewProp_ColorScale,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::NewProp_ColorOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::NewProp_bApplyToAllLayers,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Set eye buffer and overlay color space.\n\x09* @param ColorScale         (In) Color scale.\n\x09* @param ColorOffset        (In) Color offset.\n\x09* @param bApplyToAllLayers  (In) If apply to all Layers,default false.\n\x09*/" },
		{ "CPP_Default_bApplyToAllLayers", "false" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Set eye buffer and overlay color space.\n@param ColorScale         (In) Color scale.\n@param ColorOffset        (In) Color offset.\n@param bApplyToAllLayers  (In) If apply to all Layers,default false." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_SetColorScaleAndOffset", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_SetColorScaleAndOffset_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_SetCPUAndGPULevels_Parms
		{
			int32 CPULevel;
			int32 GPULevel;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_CPULevel;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_GPULevel;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::NewProp_CPULevel = { "CPULevel", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_SetCPUAndGPULevels_Parms, CPULevel), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::NewProp_GPULevel = { "GPULevel", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_SetCPUAndGPULevels_Parms, GPULevel), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::NewProp_CPULevel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::NewProp_GPULevel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Set CPU GPU level.\n\x09* @param CPULevel   (in) Target CPU level.\n\x09* @param GPULevel   (in) Target GPU level.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Set CPU GPU level.\n@param CPULevel   (in) Target CPU level.\n@param GPULevel   (in) Target GPU level." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_SetCPUAndGPULevels", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_SetCPUAndGPULevels_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_SetExtraLatencyMode_Parms
		{
			int32 Mode;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Mode;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::NewProp_Mode = { "Mode", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_SetExtraLatencyMode_Parms, Mode), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_SetExtraLatencyMode_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_SetExtraLatencyMode_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::NewProp_Mode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Set extra latency mode.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Set extra latency mode." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_SetExtraLatencyMode", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_SetExtraLatencyMode_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetExtraLatencyMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetExtraLatencyMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_SetFoveationLevel_Parms
		{
			EPicoXRFoveationLevel Level;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Level_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Level;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::NewProp_Level_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_SetFoveationLevel_Parms, Level), Z_Construct_UEnum_PicoXRHMD_EPicoXRFoveationLevel, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_SetFoveationLevel_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_SetFoveationLevel_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::NewProp_Level_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::NewProp_Level,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Set  Foveation rendering level.\n\x09* @param Level   rendering level.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Set  Foveation rendering level.\n@param Level   rendering level." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_SetFoveationLevel", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_SetFoveationLevel_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationLevel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationLevel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_SetFoveationParameter_Parms
		{
			FVector2D FoveationGainValue;
			float FoveationAreaValue;
			float FoveationMinimumValue;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_FoveationGainValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_FoveationAreaValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_FoveationMinimumValue;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::NewProp_FoveationGainValue = { "FoveationGainValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_SetFoveationParameter_Parms, FoveationGainValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::NewProp_FoveationAreaValue = { "FoveationAreaValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_SetFoveationParameter_Parms, FoveationAreaValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::NewProp_FoveationMinimumValue = { "FoveationMinimumValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_SetFoveationParameter_Parms, FoveationMinimumValue), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_SetFoveationParameter_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_SetFoveationParameter_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::NewProp_FoveationGainValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::NewProp_FoveationAreaValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::NewProp_FoveationMinimumValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Set  Foveation rendering parameter.\n\x09* @param FoveationGainValue     The reduction rate of peripheral pixels in the X/Y direction, the higher the value, the more the reduction.\n\x09* @param FoveationAreaValue     Take the fixation point as the center and the value of Foveation Area as the radius to maintain the full resolution.\n\x09* @param FoveationMinimumValue  Minimum pixel density limit.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Set  Foveation rendering parameter.\n@param FoveationGainValue     The reduction rate of peripheral pixels in the X/Y direction, the higher the value, the more the reduction.\n@param FoveationAreaValue     Take the fixation point as the center and the value of Foveation Area as the radius to maintain the full resolution.\n@param FoveationMinimumValue  Minimum pixel density limit." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_SetFoveationParameter", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_SetFoveationParameter_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationParameter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationParameter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetLargeSpaceEnable_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_SetLargeSpaceEnable_Parms
		{
			bool bEnable;
			int32 ext;
		};
		static void NewProp_bEnable_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bEnable;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ext;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetLargeSpaceEnable_Statics::NewProp_bEnable_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_SetLargeSpaceEnable_Parms*)Obj)->bEnable = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetLargeSpaceEnable_Statics::NewProp_bEnable = { "bEnable", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_SetLargeSpaceEnable_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetLargeSpaceEnable_Statics::NewProp_bEnable_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetLargeSpaceEnable_Statics::NewProp_ext = { "ext", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_SetLargeSpaceEnable_Parms, ext), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetLargeSpaceEnable_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetLargeSpaceEnable_Statics::NewProp_bEnable,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetLargeSpaceEnable_Statics::NewProp_ext,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetLargeSpaceEnable_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "CPP_Default_ext", "0" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetLargeSpaceEnable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_SetLargeSpaceEnable", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_SetLargeSpaceEnable_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetLargeSpaceEnable_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetLargeSpaceEnable_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetLargeSpaceEnable_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetLargeSpaceEnable_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetLargeSpaceEnable()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetLargeSpaceEnable_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_SetSeeThroughBackground_Parms
		{
			bool Value;
			int32 ReturnValue;
		};
		static void NewProp_Value_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::NewProp_Value_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_SetSeeThroughBackground_Parms*)Obj)->Value = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_SetSeeThroughBackground_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::NewProp_Value_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_SetSeeThroughBackground_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Set see through background.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Set see through background." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_SetSeeThroughBackground", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_SetSeeThroughBackground_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSeeThroughBackground()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSeeThroughBackground_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_SetSensorLostCMST_Parms
		{
			bool Value;
			int32 ReturnValue;
		};
		static void NewProp_Value_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::NewProp_Value_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_SetSensorLostCMST_Parms*)Obj)->Value = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_SetSensorLostCMST_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::NewProp_Value_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_SetSensorLostCMST_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Set sensor lost CMST.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Set sensor lost CMST." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_SetSensorLostCMST", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_SetSensorLostCMST_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCMST()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCMST_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_SetSensorLostCustomMode_Parms
		{
			bool Value;
			int32 ReturnValue;
		};
		static void NewProp_Value_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Value;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::NewProp_Value_SetBit(void* Obj)
	{
		((PicoXRHMDFunctionLibrary_eventPXR_SetSensorLostCustomMode_Parms*)Obj)->Value = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PicoXRHMDFunctionLibrary_eventPXR_SetSensorLostCustomMode_Parms), &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::NewProp_Value_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_SetSensorLostCustomMode_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::NewProp_Value,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Set sensor lost custom mode.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Set sensor lost custom mode." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_SetSensorLostCustomMode", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_SetSensorLostCustomMode_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics
	{
		struct PicoXRHMDFunctionLibrary_eventPXR_SetSystemDisplayFrequency_Parms
		{
			float Rate;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Rate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics::NewProp_Rate = { "Rate", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PicoXRHMDFunctionLibrary_eventPXR_SetSystemDisplayFrequency_Parms, Rate), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics::NewProp_Rate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|PXRHMD" },
		{ "Comment", "/**\n\x09* Set system display frequency.\n\x09* @param Rate    (In) Display frequency 72/90/120.\n\x09*/" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
		{ "ToolTip", "Set system display frequency.\n@param Rate    (In) Display frequency 72/90/120." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoXRHMDFunctionLibrary, nullptr, "PXR_SetSystemDisplayFrequency", nullptr, nullptr, sizeof(PicoXRHMDFunctionLibrary_eventPXR_SetSystemDisplayFrequency_Parms), Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UPicoXRHMDFunctionLibrary_NoRegister()
	{
		return UPicoXRHMDFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UPicoXRHMDFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPicoXRHMDFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_PicoXRHMD,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UPicoXRHMDFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_GetFocusState, "GetFocusState" }, // 4147652861
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_AddSplashScreen, "PXR_AddSplashScreen" }, // 2535758334
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestNode, "PXR_BoundaryTestNode" }, // 2856635994
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_BoundaryTestPoint, "PXR_BoundaryTestPoint" }, // 1521846737
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_ClearLoadingSplashScreens, "PXR_ClearLoadingSplashScreens" }, // 3136324962
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_DoesSupportPositionalTracking, "PXR_DoesSupportPositionalTracking" }, // 188183713
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableAutoShowSplashScreen, "PXR_EnableAutoShowSplashScreen" }, // 3644014042
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableEyeTrackingMarker, "PXR_EnableEyeTrackingMarker" }, // 2350991480
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFaceTracking, "PXR_EnableFaceTracking" }, // 186005795
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_EnableFoveation, "PXR_EnableFoveation" }, // 3942035343
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAcceleration, "PXR_GetAcceleration" }, // 3605697087
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularAcceleration, "PXR_GetAngularAcceleration" }, // 1656545069
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetAngularVelocity, "PXR_GetAngularVelocity" }, // 1956762649
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryConfigured, "PXR_GetBoundaryConfigured" }, // 1354044383
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryDimensions, "PXR_GetBoundaryDimensions" }, // 929349092
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryEnabled, "PXR_GetBoundaryEnabled" }, // 4097384126
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryGeometry, "PXR_GetBoundaryGeometry" }, // 2002389161
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundarySeeThroughData, "PXR_GetBoundarySeeThroughData" }, // 2270263306
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetBoundaryVisible, "PXR_GetBoundaryVisible" }, // 3983418584
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCPUAndGPULevels, "PXR_GetCPUAndGPULevels" }, // 3725730342
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentDisplayFrequency, "PXR_GetCurrentDisplayFrequency" }, // 831688494
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentOrientation, "PXR_GetCurrentOrientation" }, // 3143687617
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetCurrentPosition, "PXR_GetCurrentPosition" }, // 1891205031
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDeviceModel, "PXR_GetDeviceModel" }, // 2113007741
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDialogState, "PXR_GetDialogState" }, // 3329246155
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetDisplayFrequenciesAvailable, "PXR_GetDisplayFrequenciesAvailable" }, // 1468162066
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEventManager, "PXR_GetEventManager" }, // 3180455584
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingData, "PXR_GetEyeTrackingData" }, // 251080766
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingGazeRay, "PXR_GetEyeTrackingGazeRay" }, // 3327919818
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetEyeTrackingPos, "PXR_GetEyeTrackingPos" }, // 21979201
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFieldOfView, "PXR_GetFieldOfView" }, // 3784661645
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetFoveationLevel, "PXR_GetFoveationLevel" }, // 962815486
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHFov, "PXR_GetHFov" }, // 4051039025
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetHMDWornState, "PXR_GetHMDWornState" }, // 2734474774
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetIPD, "PXR_GetIPD" }, // 1624123843
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetPredictedMainSensorState, "PXR_GetPredictedMainSensorState" }, // 3955489561
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetSystemDisplayFrequency, "PXR_GetSystemDisplayFrequency" }, // 79278148
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVelocity, "PXR_GetVelocity" }, // 3169237596
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_GetVFov, "PXR_GetVFov" }, // 2819502944
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_IPDChangedDelegates, "PXR_IPDChangedDelegates" }, // 55701785
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_ResetHMDSensor, "PXR_ResetHMDSensor" }, // 1514740974
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryCameraImageSize, "PXR_SetBoundaryCameraImageSize" }, // 399675692
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetBoundaryVisible, "PXR_SetBoundaryVisible" }, // 2285635289
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetColorScaleAndOffset, "PXR_SetColorScaleAndOffset" }, // 3819669008
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetCPUAndGPULevels, "PXR_SetCPUAndGPULevels" }, // 1402768509
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetExtraLatencyMode, "PXR_SetExtraLatencyMode" }, // 1867346264
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationLevel, "PXR_SetFoveationLevel" }, // 512066187
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetFoveationParameter, "PXR_SetFoveationParameter" }, // 3146355916
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetLargeSpaceEnable, "PXR_SetLargeSpaceEnable" }, // 3886281583
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSeeThroughBackground, "PXR_SetSeeThroughBackground" }, // 1293325808
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCMST, "PXR_SetSensorLostCMST" }, // 706895432
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSensorLostCustomMode, "PXR_SetSensorLostCustomMode" }, // 756085603
		{ &Z_Construct_UFunction_UPicoXRHMDFunctionLibrary_PXR_SetSystemDisplayFrequency, "PXR_SetSystemDisplayFrequency" }, // 717956988
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoXRHMDFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PXR_HMDFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/PXR_HMDFunctionLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPicoXRHMDFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPicoXRHMDFunctionLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPicoXRHMDFunctionLibrary_Statics::ClassParams = {
		&UPicoXRHMDFunctionLibrary::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UPicoXRHMDFunctionLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPicoXRHMDFunctionLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPicoXRHMDFunctionLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPicoXRHMDFunctionLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPicoXRHMDFunctionLibrary, 2641431710);
	template<> PICOXRHMD_API UClass* StaticClass<UPicoXRHMDFunctionLibrary>()
	{
		return UPicoXRHMDFunctionLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPicoXRHMDFunctionLibrary(Z_Construct_UClass_UPicoXRHMDFunctionLibrary, &UPicoXRHMDFunctionLibrary::StaticClass, TEXT("/Script/PicoXRHMD"), TEXT("UPicoXRHMDFunctionLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPicoXRHMDFunctionLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
