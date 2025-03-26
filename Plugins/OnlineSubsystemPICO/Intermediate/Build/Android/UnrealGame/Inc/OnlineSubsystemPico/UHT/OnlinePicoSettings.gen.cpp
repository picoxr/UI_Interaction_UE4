// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../OnlineSubsystemPico/Private/OnlinePicoSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOnlinePicoSettings() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoSettings();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoSettings_NoRegister();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERegionType();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemPico();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ERegionType;
	static UEnum* ERegionType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ERegionType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ERegionType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERegionType, (UObject*)Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERegionType"));
		}
		return Z_Registration_Info_UEnum_ERegionType.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERegionType>()
	{
		return ERegionType_StaticEnum();
	}
	struct Z_Construct_UEnum_OnlineSubsystemPico_ERegionType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_OnlineSubsystemPico_ERegionType_Statics::Enumerators[] = {
		{ "ERegionType::China", (int64)ERegionType::China },
		{ "ERegionType::NonChina", (int64)ERegionType::NonChina },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_OnlineSubsystemPico_ERegionType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "China.Name", "ERegionType::China" },
		{ "ModuleRelativePath", "Private/OnlinePicoSettings.h" },
		{ "NonChina.Name", "ERegionType::NonChina" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_OnlineSubsystemPico_ERegionType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
		nullptr,
		"ERegionType",
		"ERegionType",
		Z_Construct_UEnum_OnlineSubsystemPico_ERegionType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERegionType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_OnlineSubsystemPico_ERegionType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_OnlineSubsystemPico_ERegionType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERegionType()
	{
		if (!Z_Registration_Info_UEnum_ERegionType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ERegionType.InnerSingleton, Z_Construct_UEnum_OnlineSubsystemPico_ERegionType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ERegionType.InnerSingleton;
	}
	DEFINE_FUNCTION(UOnlinePicoSettings::execGetOnlinePicoSettings)
	{
		P_GET_UBOOL_REF(Z_Param_Out_OutbIsEnable);
		P_GET_ENUM_REF(ERegionType,Z_Param_Out_OutRegionType);
		P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_OutAppID);
		P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_OutAccessToken);
		P_GET_UBOOL_REF(Z_Param_Out_OutbEnableHighlight);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoSettings::GetOnlinePicoSettings(Z_Param_Out_OutbIsEnable,(ERegionType&)(Z_Param_Out_OutRegionType),Z_Param_Out_OutAppID,Z_Param_Out_OutAccessToken,Z_Param_Out_OutbEnableHighlight);
		P_NATIVE_END;
	}
	void UOnlinePicoSettings::StaticRegisterNativesUOnlinePicoSettings()
	{
		UClass* Class = UOnlinePicoSettings::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetOnlinePicoSettings", &UOnlinePicoSettings::execGetOnlinePicoSettings },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics
	{
		struct OnlinePicoSettings_eventGetOnlinePicoSettings_Parms
		{
			bool OutbIsEnable;
			ERegionType OutRegionType;
			FString OutAppID;
			FString OutAccessToken;
			bool OutbEnableHighlight;
		};
		static void NewProp_OutbIsEnable_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_OutbIsEnable;
		static const UECodeGen_Private::FBytePropertyParams NewProp_OutRegionType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_OutRegionType;
		static const UECodeGen_Private::FStrPropertyParams NewProp_OutAppID;
		static const UECodeGen_Private::FStrPropertyParams NewProp_OutAccessToken;
		static void NewProp_OutbEnableHighlight_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_OutbEnableHighlight;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::NewProp_OutbIsEnable_SetBit(void* Obj)
	{
		((OnlinePicoSettings_eventGetOnlinePicoSettings_Parms*)Obj)->OutbIsEnable = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::NewProp_OutbIsEnable = { "OutbIsEnable", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoSettings_eventGetOnlinePicoSettings_Parms), &Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::NewProp_OutbIsEnable_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::NewProp_OutRegionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::NewProp_OutRegionType = { "OutRegionType", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoSettings_eventGetOnlinePicoSettings_Parms, OutRegionType), Z_Construct_UEnum_OnlineSubsystemPico_ERegionType, METADATA_PARAMS(0, nullptr) }; // 293092373
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::NewProp_OutAppID = { "OutAppID", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoSettings_eventGetOnlinePicoSettings_Parms, OutAppID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::NewProp_OutAccessToken = { "OutAccessToken", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoSettings_eventGetOnlinePicoSettings_Parms, OutAccessToken), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::NewProp_OutbEnableHighlight_SetBit(void* Obj)
	{
		((OnlinePicoSettings_eventGetOnlinePicoSettings_Parms*)Obj)->OutbEnableHighlight = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::NewProp_OutbEnableHighlight = { "OutbEnableHighlight", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoSettings_eventGetOnlinePicoSettings_Parms), &Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::NewProp_OutbEnableHighlight_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::NewProp_OutbIsEnable,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::NewProp_OutRegionType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::NewProp_OutRegionType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::NewProp_OutAppID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::NewProp_OutAccessToken,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::NewProp_OutbEnableHighlight,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::Function_MetaDataParams[] = {
		{ "Category", "OVRPlatformBP|OnlineSubsystemOculus" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Gets the config file settings in-game.\n" },
#endif
		{ "ModuleRelativePath", "Private/OnlinePicoSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gets the config file settings in-game." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoSettings, nullptr, "GetOnlinePicoSettings", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::OnlinePicoSettings_eventGetOnlinePicoSettings_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::OnlinePicoSettings_eventGetOnlinePicoSettings_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOnlinePicoSettings);
	UClass* Z_Construct_UClass_UOnlinePicoSettings_NoRegister()
	{
		return UOnlinePicoSettings::StaticClass();
	}
	struct Z_Construct_UClass_UOnlinePicoSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsForeign_MetaData[];
#endif
		static void NewProp_bIsForeign_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsForeign;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsGlobal_MetaData[];
#endif
		static void NewProp_bIsGlobal_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsGlobal;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[];
#endif
		static void NewProp_bEnabled_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AppID_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AppID;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableHighlight_MetaData[];
#endif
		static void NewProp_bEnableHighlight_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableHighlight;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AccessToken_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AccessToken;
		static const UECodeGen_Private::FBytePropertyParams NewProp_RegionType_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RegionType_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_RegionType;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOnlinePicoSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UOnlinePicoSettings_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOnlinePicoSettings_GetOnlinePicoSettings, "GetOnlinePicoSettings" }, // 352075889
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoSettings_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "OnlinePicoSettings.h" },
		{ "ModuleRelativePath", "Private/OnlinePicoSettings.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsForeign_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Platform\n" },
#endif
		{ "ModuleRelativePath", "Private/OnlinePicoSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Platform" },
#endif
	};
#endif
	void Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsForeign_SetBit(void* Obj)
	{
		((UOnlinePicoSettings*)Obj)->bIsForeign = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsForeign = { "bIsForeign", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOnlinePicoSettings), &Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsForeign_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsForeign_MetaData), Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsForeign_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsGlobal_MetaData[] = {
		{ "ModuleRelativePath", "Private/OnlinePicoSettings.h" },
	};
#endif
	void Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsGlobal_SetBit(void* Obj)
	{
		((UOnlinePicoSettings*)Obj)->bIsGlobal = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsGlobal = { "bIsGlobal", nullptr, (EPropertyFlags)0x0010000000004000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOnlinePicoSettings), &Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsGlobal_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsGlobal_MetaData), Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsGlobal_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bEnabled_MetaData[] = {
		{ "Category", "Platform" },
		{ "DisplayName", "bEnabled" },
		{ "ModuleRelativePath", "Private/OnlinePicoSettings.h" },
	};
#endif
	void Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bEnabled_SetBit(void* Obj)
	{
		((UOnlinePicoSettings*)Obj)->bEnabled = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOnlinePicoSettings), &Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bEnabled_MetaData), Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bEnabled_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_AppID_MetaData[] = {
		{ "Category", "Platform" },
		{ "DisplayName", "AppID" },
		{ "ModuleRelativePath", "Private/OnlinePicoSettings.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_AppID = { "AppID", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOnlinePicoSettings, AppID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_AppID_MetaData), Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_AppID_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bEnableHighlight_MetaData[] = {
		{ "Category", "Platform" },
		{ "DisplayName", "Highlight" },
		{ "ModuleRelativePath", "Private/OnlinePicoSettings.h" },
	};
#endif
	void Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bEnableHighlight_SetBit(void* Obj)
	{
		((UOnlinePicoSettings*)Obj)->bEnableHighlight = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bEnableHighlight = { "bEnableHighlight", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOnlinePicoSettings), &Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bEnableHighlight_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bEnableHighlight_MetaData), Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bEnableHighlight_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_AccessToken_MetaData[] = {
		{ "Category", "WindowsDebug" },
		{ "DisplayName", "AccessToken" },
		{ "ModuleRelativePath", "Private/OnlinePicoSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the access token from development platform" },
#endif
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_AccessToken = { "AccessToken", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOnlinePicoSettings, AccessToken), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_AccessToken_MetaData), Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_AccessToken_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_RegionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_RegionType_MetaData[] = {
		{ "Category", "WindowsDebug" },
		{ "DisplayName", "Region" },
		{ "ModuleRelativePath", "Private/OnlinePicoSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Only used in windows debug" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_RegionType = { "RegionType", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOnlinePicoSettings, RegionType), Z_Construct_UEnum_OnlineSubsystemPico_ERegionType, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_RegionType_MetaData), Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_RegionType_MetaData) }; // 293092373
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOnlinePicoSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsForeign,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsGlobal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bEnabled,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_AppID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bEnableHighlight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_AccessToken,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_RegionType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_RegionType,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOnlinePicoSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOnlinePicoSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOnlinePicoSettings_Statics::ClassParams = {
		&UOnlinePicoSettings::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UOnlinePicoSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::PropPointers),
		0,
		0x001000A6u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UOnlinePicoSettings_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UOnlinePicoSettings()
	{
		if (!Z_Registration_Info_UClass_UOnlinePicoSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOnlinePicoSettings.OuterSingleton, Z_Construct_UClass_UOnlinePicoSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOnlinePicoSettings.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UOnlinePicoSettings>()
	{
		return UOnlinePicoSettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOnlinePicoSettings);
	UOnlinePicoSettings::~UOnlinePicoSettings() {}
	struct Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_Statics::EnumInfo[] = {
		{ ERegionType_StaticEnum, TEXT("ERegionType"), &Z_Registration_Info_UEnum_ERegionType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 293092373U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOnlinePicoSettings, UOnlinePicoSettings::StaticClass, TEXT("UOnlinePicoSettings"), &Z_Registration_Info_UClass_UOnlinePicoSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOnlinePicoSettings), 3850679380U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_1319078370(TEXT("/Script/OnlineSubsystemPico"),
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Private_OnlinePicoSettings_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
