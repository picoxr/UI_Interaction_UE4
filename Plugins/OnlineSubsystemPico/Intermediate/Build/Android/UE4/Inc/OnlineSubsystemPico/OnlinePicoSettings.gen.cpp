// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OnlineSubsystemPico/Private/OnlinePicoSettings.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOnlinePicoSettings() {}
// Cross Module References
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERegionType();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemPico();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoSettings_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoSettings();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
// End Cross Module References
	static UEnum* ERegionType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERegionType, Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERegionType"));
		}
		return Singleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERegionType>()
	{
		return ERegionType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ERegionType(ERegionType_StaticEnum, TEXT("/Script/OnlineSubsystemPico"), TEXT("ERegionType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_OnlineSubsystemPico_ERegionType_Hash() { return 4042000186U; }
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERegionType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_OnlineSubsystemPico();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ERegionType"), 0, Get_Z_Construct_UEnum_OnlineSubsystemPico_ERegionType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ERegionType::China", (int64)ERegionType::China },
				{ "ERegionType::NonChina", (int64)ERegionType::NonChina },
				{ "ERegionType::Both", (int64)ERegionType::Both },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Both.Name", "ERegionType::Both" },
				{ "China.Name", "ERegionType::China" },
				{ "ModuleRelativePath", "Private/OnlinePicoSettings.h" },
				{ "NonChina.Name", "ERegionType::NonChina" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
				nullptr,
				"ERegionType",
				"ERegionType",
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
	void UOnlinePicoSettings::StaticRegisterNativesUOnlinePicoSettings()
	{
	}
	UClass* Z_Construct_UClass_UOnlinePicoSettings_NoRegister()
	{
		return UOnlinePicoSettings::StaticClass();
	}
	struct Z_Construct_UClass_UOnlinePicoSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsForeign_MetaData[];
#endif
		static void NewProp_bIsForeign_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsForeign;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsGlobal_MetaData[];
#endif
		static void NewProp_bIsGlobal_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsGlobal;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_RegionType_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RegionType_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_RegionType;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AppID_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_AppID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AppKey_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_AppKey;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Scope_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Scope;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bStartTimeEntitlementCheck_MetaData[];
#endif
		static void NewProp_bStartTimeEntitlementCheck_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bStartTimeEntitlementCheck;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EntitlementCheckAppID_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_EntitlementCheckAppID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bEntitlementCheckSimulation_MetaData[];
#endif
		static void NewProp_bEntitlementCheckSimulation_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bEntitlementCheckSimulation;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_DeviceSN_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DeviceSN_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_DeviceSN;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOnlinePicoSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoSettings_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "OnlinePicoSettings.h" },
		{ "ModuleRelativePath", "Private/OnlinePicoSettings.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsForeign_MetaData[] = {
		{ "Comment", "// Platform\n" },
		{ "ModuleRelativePath", "Private/OnlinePicoSettings.h" },
		{ "ToolTip", "Platform" },
	};
#endif
	void Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsForeign_SetBit(void* Obj)
	{
		((UOnlinePicoSettings*)Obj)->bIsForeign = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsForeign = { "bIsForeign", nullptr, (EPropertyFlags)0x0010000000004000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UOnlinePicoSettings), &Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsForeign_SetBit, METADATA_PARAMS(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsForeign_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsForeign_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsGlobal_MetaData[] = {
		{ "ModuleRelativePath", "Private/OnlinePicoSettings.h" },
	};
#endif
	void Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsGlobal_SetBit(void* Obj)
	{
		((UOnlinePicoSettings*)Obj)->bIsGlobal = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsGlobal = { "bIsGlobal", nullptr, (EPropertyFlags)0x0010000000004000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UOnlinePicoSettings), &Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsGlobal_SetBit, METADATA_PARAMS(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsGlobal_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsGlobal_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_RegionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_RegionType_MetaData[] = {
		{ "Category", "Platform" },
		{ "DisplayName", "Region" },
		{ "ModuleRelativePath", "Private/OnlinePicoSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_RegionType = { "RegionType", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOnlinePicoSettings, RegionType), Z_Construct_UEnum_OnlineSubsystemPico_ERegionType, METADATA_PARAMS(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_RegionType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_RegionType_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_AppID_MetaData[] = {
		{ "Category", "Platform" },
		{ "DisplayName", "AppID" },
		{ "ModuleRelativePath", "Private/OnlinePicoSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_AppID = { "AppID", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOnlinePicoSettings, AppID), METADATA_PARAMS(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_AppID_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_AppID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_AppKey_MetaData[] = {
		{ "Category", "Platform" },
		{ "DisplayName", "AppKey" },
		{ "ModuleRelativePath", "Private/OnlinePicoSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_AppKey = { "AppKey", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOnlinePicoSettings, AppKey), METADATA_PARAMS(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_AppKey_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_AppKey_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_Scope_MetaData[] = {
		{ "Category", "Platform" },
		{ "DisplayName", "Scope" },
		{ "ModuleRelativePath", "Private/OnlinePicoSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_Scope = { "Scope", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOnlinePicoSettings, Scope), METADATA_PARAMS(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_Scope_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_Scope_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bStartTimeEntitlementCheck_MetaData[] = {
		{ "Category", "Platform" },
		{ "DisplayName", "User Entitlement Check" },
		{ "ModuleRelativePath", "Private/OnlinePicoSettings.h" },
		{ "ToolTip", "If selected, you will need to enter the APPID that is obtained from Pico Developer Platform after uploading the app for an entitlement check upon the app launch." },
	};
#endif
	void Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bStartTimeEntitlementCheck_SetBit(void* Obj)
	{
		((UOnlinePicoSettings*)Obj)->bStartTimeEntitlementCheck = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bStartTimeEntitlementCheck = { "bStartTimeEntitlementCheck", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UOnlinePicoSettings), &Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bStartTimeEntitlementCheck_SetBit, METADATA_PARAMS(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bStartTimeEntitlementCheck_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bStartTimeEntitlementCheck_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_EntitlementCheckAppID_MetaData[] = {
		{ "Category", "Platform" },
		{ "DisplayName", "EntitlementCheckAppID" },
		{ "EditCondition", "bStartTimeEntitlementCheck" },
		{ "ModuleRelativePath", "Private/OnlinePicoSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_EntitlementCheckAppID = { "EntitlementCheckAppID", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOnlinePicoSettings, EntitlementCheckAppID), METADATA_PARAMS(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_EntitlementCheckAppID_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_EntitlementCheckAppID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bEntitlementCheckSimulation_MetaData[] = {
		{ "Category", "Platform" },
		{ "DisplayName", "Entitlement Check Simulation" },
		{ "ModuleRelativePath", "Private/OnlinePicoSettings.h" },
		{ "ToolTip", "If true, Development devices will simulate Entitlement Check, you should enter a valid device SN codes list. The SN code can be obtain in Settings-General-Device serial number or input 'adb devices ' in cmd" },
	};
#endif
	void Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bEntitlementCheckSimulation_SetBit(void* Obj)
	{
		((UOnlinePicoSettings*)Obj)->bEntitlementCheckSimulation = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bEntitlementCheckSimulation = { "bEntitlementCheckSimulation", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UOnlinePicoSettings), &Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bEntitlementCheckSimulation_SetBit, METADATA_PARAMS(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bEntitlementCheckSimulation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bEntitlementCheckSimulation_MetaData)) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_DeviceSN_Inner = { "DeviceSN", nullptr, (EPropertyFlags)0x0000000000004000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_DeviceSN_MetaData[] = {
		{ "Category", "Platform" },
		{ "DisplayName", "Device SN Code List" },
		{ "EditCondition", "bEntitlementCheckSimulation" },
		{ "ModuleRelativePath", "Private/OnlinePicoSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_DeviceSN = { "DeviceSN", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UOnlinePicoSettings, DeviceSN), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_DeviceSN_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_DeviceSN_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOnlinePicoSettings_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsForeign,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bIsGlobal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_RegionType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_RegionType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_AppID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_AppKey,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_Scope,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bStartTimeEntitlementCheck,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_EntitlementCheckAppID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_bEntitlementCheckSimulation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_DeviceSN_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOnlinePicoSettings_Statics::NewProp_DeviceSN,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOnlinePicoSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOnlinePicoSettings>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UOnlinePicoSettings_Statics::ClassParams = {
		&UOnlinePicoSettings::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UOnlinePicoSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::PropPointers),
		0,
		0x001000A6u,
		METADATA_PARAMS(Z_Construct_UClass_UOnlinePicoSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOnlinePicoSettings()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UOnlinePicoSettings_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UOnlinePicoSettings, 1657519799);
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UOnlinePicoSettings>()
	{
		return UOnlinePicoSettings::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UOnlinePicoSettings(Z_Construct_UClass_UOnlinePicoSettings, &UOnlinePicoSettings::StaticClass, TEXT("/Script/OnlineSubsystemPico"), TEXT("UOnlinePicoSettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOnlinePicoSettings);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
