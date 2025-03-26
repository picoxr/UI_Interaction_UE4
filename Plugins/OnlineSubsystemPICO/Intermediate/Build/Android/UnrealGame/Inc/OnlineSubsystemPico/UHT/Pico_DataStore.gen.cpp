// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../OnlineSubsystemPico/Public/Pico_DataStore.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePico_DataStore() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_DataStore();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_DataStore_NoRegister();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemPico();
// End Cross Module References
	DEFINE_FUNCTION(UPico_DataStore::execGetValue)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Key);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetValue(Z_Param_Key);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_DataStore::execGetNumKeys)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetNumKeys();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_DataStore::execGetKey)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetKey(Z_Param_Index);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_DataStore::execContains)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Key);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->Contains(Z_Param_Key);
		P_NATIVE_END;
	}
	void UPico_DataStore::StaticRegisterNativesUPico_DataStore()
	{
		UClass* Class = UPico_DataStore::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Contains", &UPico_DataStore::execContains },
			{ "GetKey", &UPico_DataStore::execGetKey },
			{ "GetNumKeys", &UPico_DataStore::execGetNumKeys },
			{ "GetValue", &UPico_DataStore::execGetValue },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_DataStore_Contains_Statics
	{
		struct Pico_DataStore_eventContains_Parms
		{
			FString Key;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_Key;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_DataStore_Contains_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_DataStore_eventContains_Parms, Key), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_DataStore_Contains_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_DataStore_eventContains_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_DataStore_Contains_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_DataStore_Contains_Statics::NewProp_Key,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_DataStore_Contains_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_DataStore_Contains_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Misc|Data Store" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief With UserId as the key, find its index in the DataStoreMap data structure.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_DataStore.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief With UserId as the key, find its index in the DataStoreMap data structure." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_DataStore_Contains_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_DataStore, nullptr, "Contains", nullptr, nullptr, Z_Construct_UFunction_UPico_DataStore_Contains_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_DataStore_Contains_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_DataStore_Contains_Statics::Pico_DataStore_eventContains_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_DataStore_Contains_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_DataStore_Contains_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_DataStore_Contains_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_DataStore_Contains_Statics::Pico_DataStore_eventContains_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_DataStore_Contains()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_DataStore_Contains_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_DataStore_GetKey_Statics
	{
		struct Pico_DataStore_eventGetKey_Parms
		{
			int32 Index;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_DataStore_GetKey_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_DataStore_eventGetKey_Parms, Index), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_DataStore_GetKey_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_DataStore_eventGetKey_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_DataStore_GetKey_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_DataStore_GetKey_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_DataStore_GetKey_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_DataStore_GetKey_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Misc|Data Store" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Find the user ID in the corresponding KeyArray through the index.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_DataStore.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Find the user ID in the corresponding KeyArray through the index." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_DataStore_GetKey_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_DataStore, nullptr, "GetKey", nullptr, nullptr, Z_Construct_UFunction_UPico_DataStore_GetKey_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_DataStore_GetKey_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_DataStore_GetKey_Statics::Pico_DataStore_eventGetKey_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_DataStore_GetKey_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_DataStore_GetKey_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_DataStore_GetKey_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_DataStore_GetKey_Statics::Pico_DataStore_eventGetKey_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_DataStore_GetKey()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_DataStore_GetKey_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_DataStore_GetNumKeys_Statics
	{
		struct Pico_DataStore_eventGetNumKeys_Parms
		{
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_DataStore_GetNumKeys_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_DataStore_eventGetNumKeys_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_DataStore_GetNumKeys_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_DataStore_GetNumKeys_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_DataStore_GetNumKeys_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Misc|Data Store" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get the size of DataStoreMap .*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_DataStore.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get the size of DataStoreMap ." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_DataStore_GetNumKeys_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_DataStore, nullptr, "GetNumKeys", nullptr, nullptr, Z_Construct_UFunction_UPico_DataStore_GetNumKeys_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_DataStore_GetNumKeys_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_DataStore_GetNumKeys_Statics::Pico_DataStore_eventGetNumKeys_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_DataStore_GetNumKeys_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_DataStore_GetNumKeys_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_DataStore_GetNumKeys_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_DataStore_GetNumKeys_Statics::Pico_DataStore_eventGetNumKeys_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_DataStore_GetNumKeys()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_DataStore_GetNumKeys_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_DataStore_GetValue_Statics
	{
		struct Pico_DataStore_eventGetValue_Parms
		{
			FString Key;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_Key;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_DataStore_GetValue_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_DataStore_eventGetValue_Parms, Key), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_DataStore_GetValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_DataStore_eventGetValue_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_DataStore_GetValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_DataStore_GetValue_Statics::NewProp_Key,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_DataStore_GetValue_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_DataStore_GetValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Misc|Data Store" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief With UserId as the key, find its value in the DataStoreMap data structure.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_DataStore.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief With UserId as the key, find its value in the DataStoreMap data structure." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_DataStore_GetValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_DataStore, nullptr, "GetValue", nullptr, nullptr, Z_Construct_UFunction_UPico_DataStore_GetValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_DataStore_GetValue_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_DataStore_GetValue_Statics::Pico_DataStore_eventGetValue_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_DataStore_GetValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_DataStore_GetValue_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_DataStore_GetValue_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_DataStore_GetValue_Statics::Pico_DataStore_eventGetValue_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_DataStore_GetValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_DataStore_GetValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_DataStore);
	UClass* Z_Construct_UClass_UPico_DataStore_NoRegister()
	{
		return UPico_DataStore::StaticClass();
	}
	struct Z_Construct_UClass_UPico_DataStore_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_DataStoreMap_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_DataStoreMap_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DataStoreMap_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_DataStoreMap;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_DataStore_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_DataStore_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_DataStore_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_DataStore_Contains, "Contains" }, // 3134654138
		{ &Z_Construct_UFunction_UPico_DataStore_GetKey, "GetKey" }, // 4009994051
		{ &Z_Construct_UFunction_UPico_DataStore_GetNumKeys, "GetNumKeys" }, // 454707851
		{ &Z_Construct_UFunction_UPico_DataStore_GetValue, "GetValue" }, // 1193310204
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_DataStore_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_DataStore_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n *//// @brief UPico_DataStore class.\n" },
#endif
		{ "IncludePath", "Pico_DataStore.h" },
		{ "ModuleRelativePath", "Public/Pico_DataStore.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "/// @brief UPico_DataStore class." },
#endif
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UPico_DataStore_Statics::NewProp_DataStoreMap_ValueProp = { "DataStoreMap", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UPico_DataStore_Statics::NewProp_DataStoreMap_Key_KeyProp = { "DataStoreMap_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_DataStore_Statics::NewProp_DataStoreMap_MetaData[] = {
		{ "ModuleRelativePath", "Public/Pico_DataStore.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UPico_DataStore_Statics::NewProp_DataStoreMap = { "DataStoreMap", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPico_DataStore, DataStoreMap), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_DataStore_Statics::NewProp_DataStoreMap_MetaData), Z_Construct_UClass_UPico_DataStore_Statics::NewProp_DataStoreMap_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPico_DataStore_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_DataStore_Statics::NewProp_DataStoreMap_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_DataStore_Statics::NewProp_DataStoreMap_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_DataStore_Statics::NewProp_DataStoreMap,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_DataStore_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_DataStore>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_DataStore_Statics::ClassParams = {
		&UPico_DataStore::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPico_DataStore_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPico_DataStore_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_DataStore_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_DataStore_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_DataStore_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPico_DataStore()
	{
		if (!Z_Registration_Info_UClass_UPico_DataStore.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_DataStore.OuterSingleton, Z_Construct_UClass_UPico_DataStore_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_DataStore.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_DataStore>()
	{
		return UPico_DataStore::StaticClass();
	}
	UPico_DataStore::UPico_DataStore(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_DataStore);
	UPico_DataStore::~UPico_DataStore() {}
	struct Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_DataStore_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_DataStore_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPico_DataStore, UPico_DataStore::StaticClass, TEXT("UPico_DataStore"), &Z_Registration_Info_UClass_UPico_DataStore, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_DataStore), 3169794114U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_DataStore_h_4070012714(TEXT("/Script/OnlineSubsystemPico"),
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_DataStore_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_DataStore_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
