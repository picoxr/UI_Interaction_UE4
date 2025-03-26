// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../OnlineSubsystemPico/Classes/PicoFindSessionsCallbackProxy.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePicoFindSessionsCallbackProxy() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UOnlineBlueprintCallProxyBase();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPicoFindSessionsCallbackProxy();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPicoFindSessionsCallbackProxy_NoRegister();
	ONLINESUBSYSTEMUTILS_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemUtils_BlueprintFindSessionsResultDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemPico();
// End Cross Module References
	DEFINE_FUNCTION(UPicoFindSessionsCallbackProxy::execFindModeratedSessions)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_MaxResults);
		P_GET_PROPERTY(FIntProperty,Z_Param_PageIndex);
		P_GET_PROPERTY(FIntProperty,Z_Param_PageSize);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPicoFindSessionsCallbackProxy**)Z_Param__Result=UPicoFindSessionsCallbackProxy::FindModeratedSessions(Z_Param_MaxResults,Z_Param_PageIndex,Z_Param_PageSize);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPicoFindSessionsCallbackProxy::execFindMatchmakingSessions)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_MaxResults);
		P_GET_PROPERTY(FStrProperty,Z_Param_PicoMatchmakingPool);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPicoFindSessionsCallbackProxy**)Z_Param__Result=UPicoFindSessionsCallbackProxy::FindMatchmakingSessions(Z_Param_MaxResults,Z_Param_PicoMatchmakingPool);
		P_NATIVE_END;
	}
	void UPicoFindSessionsCallbackProxy::StaticRegisterNativesUPicoFindSessionsCallbackProxy()
	{
		UClass* Class = UPicoFindSessionsCallbackProxy::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FindMatchmakingSessions", &UPicoFindSessionsCallbackProxy::execFindMatchmakingSessions },
			{ "FindModeratedSessions", &UPicoFindSessionsCallbackProxy::execFindModeratedSessions },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindMatchmakingSessions_Statics
	{
		struct PicoFindSessionsCallbackProxy_eventFindMatchmakingSessions_Parms
		{
			int32 MaxResults;
			FString PicoMatchmakingPool;
			UPicoFindSessionsCallbackProxy* ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_MaxResults;
		static const UECodeGen_Private::FStrPropertyParams NewProp_PicoMatchmakingPool;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindMatchmakingSessions_Statics::NewProp_MaxResults = { "MaxResults", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PicoFindSessionsCallbackProxy_eventFindMatchmakingSessions_Parms, MaxResults), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindMatchmakingSessions_Statics::NewProp_PicoMatchmakingPool = { "PicoMatchmakingPool", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PicoFindSessionsCallbackProxy_eventFindMatchmakingSessions_Parms, PicoMatchmakingPool), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindMatchmakingSessions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PicoFindSessionsCallbackProxy_eventFindMatchmakingSessions_Parms, ReturnValue), Z_Construct_UClass_UPicoFindSessionsCallbackProxy_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindMatchmakingSessions_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindMatchmakingSessions_Statics::NewProp_MaxResults,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindMatchmakingSessions_Statics::NewProp_PicoMatchmakingPool,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindMatchmakingSessions_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindMatchmakingSessions_Statics::Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Pico|Session" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Searches for matchmaking room sessions with the pico online subsystem\n" },
#endif
		{ "ModuleRelativePath", "Classes/PicoFindSessionsCallbackProxy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Searches for matchmaking room sessions with the pico online subsystem" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindMatchmakingSessions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoFindSessionsCallbackProxy, nullptr, "FindMatchmakingSessions", nullptr, nullptr, Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindMatchmakingSessions_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindMatchmakingSessions_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindMatchmakingSessions_Statics::PicoFindSessionsCallbackProxy_eventFindMatchmakingSessions_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindMatchmakingSessions_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindMatchmakingSessions_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindMatchmakingSessions_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindMatchmakingSessions_Statics::PicoFindSessionsCallbackProxy_eventFindMatchmakingSessions_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindMatchmakingSessions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindMatchmakingSessions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindModeratedSessions_Statics
	{
		struct PicoFindSessionsCallbackProxy_eventFindModeratedSessions_Parms
		{
			int32 MaxResults;
			int32 PageIndex;
			int32 PageSize;
			UPicoFindSessionsCallbackProxy* ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_MaxResults;
		static const UECodeGen_Private::FIntPropertyParams NewProp_PageIndex;
		static const UECodeGen_Private::FIntPropertyParams NewProp_PageSize;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindModeratedSessions_Statics::NewProp_MaxResults = { "MaxResults", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PicoFindSessionsCallbackProxy_eventFindModeratedSessions_Parms, MaxResults), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindModeratedSessions_Statics::NewProp_PageIndex = { "PageIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PicoFindSessionsCallbackProxy_eventFindModeratedSessions_Parms, PageIndex), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindModeratedSessions_Statics::NewProp_PageSize = { "PageSize", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PicoFindSessionsCallbackProxy_eventFindModeratedSessions_Parms, PageSize), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindModeratedSessions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PicoFindSessionsCallbackProxy_eventFindModeratedSessions_Parms, ReturnValue), Z_Construct_UClass_UPicoFindSessionsCallbackProxy_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindModeratedSessions_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindModeratedSessions_Statics::NewProp_MaxResults,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindModeratedSessions_Statics::NewProp_PageIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindModeratedSessions_Statics::NewProp_PageSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindModeratedSessions_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindModeratedSessions_Statics::Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Pico|Session" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Searches for moderated room sessions with the pico online subsystem\n" },
#endif
		{ "ModuleRelativePath", "Classes/PicoFindSessionsCallbackProxy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Searches for moderated room sessions with the pico online subsystem" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindModeratedSessions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoFindSessionsCallbackProxy, nullptr, "FindModeratedSessions", nullptr, nullptr, Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindModeratedSessions_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindModeratedSessions_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindModeratedSessions_Statics::PicoFindSessionsCallbackProxy_eventFindModeratedSessions_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindModeratedSessions_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindModeratedSessions_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindModeratedSessions_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindModeratedSessions_Statics::PicoFindSessionsCallbackProxy_eventFindModeratedSessions_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindModeratedSessions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindModeratedSessions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPicoFindSessionsCallbackProxy);
	UClass* Z_Construct_UClass_UPicoFindSessionsCallbackProxy_NoRegister()
	{
		return UPicoFindSessionsCallbackProxy::StaticClass();
	}
	struct Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnSuccess_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSuccess;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnFailure_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnFailure;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UOnlineBlueprintCallProxyBase,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindMatchmakingSessions, "FindMatchmakingSessions" }, // 1132354786
		{ &Z_Construct_UFunction_UPicoFindSessionsCallbackProxy_FindModeratedSessions, "FindModeratedSessions" }, // 3918546243
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Exposes FindSession of the Platform SDK for blueprint use.\n */" },
#endif
		{ "IncludePath", "PicoFindSessionsCallbackProxy.h" },
		{ "ModuleRelativePath", "Classes/PicoFindSessionsCallbackProxy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Exposes FindSession of the Platform SDK for blueprint use." },
#endif
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::NewProp_OnSuccess_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Called when there is a successful query\n" },
#endif
		{ "ModuleRelativePath", "Classes/PicoFindSessionsCallbackProxy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when there is a successful query" },
#endif
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPicoFindSessionsCallbackProxy, OnSuccess), Z_Construct_UDelegateFunction_OnlineSubsystemUtils_BlueprintFindSessionsResultDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::NewProp_OnSuccess_MetaData), Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::NewProp_OnSuccess_MetaData) }; // 845722378
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::NewProp_OnFailure_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Called when there is an unsuccessful query\n" },
#endif
		{ "ModuleRelativePath", "Classes/PicoFindSessionsCallbackProxy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when there is an unsuccessful query" },
#endif
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::NewProp_OnFailure = { "OnFailure", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPicoFindSessionsCallbackProxy, OnFailure), Z_Construct_UDelegateFunction_OnlineSubsystemUtils_BlueprintFindSessionsResultDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::NewProp_OnFailure_MetaData), Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::NewProp_OnFailure_MetaData) }; // 845722378
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::NewProp_OnSuccess,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::NewProp_OnFailure,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPicoFindSessionsCallbackProxy>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::ClassParams = {
		&UPicoFindSessionsCallbackProxy::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::PropPointers),
		0,
		0x008800A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::Class_MetaDataParams), Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPicoFindSessionsCallbackProxy()
	{
		if (!Z_Registration_Info_UClass_UPicoFindSessionsCallbackProxy.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPicoFindSessionsCallbackProxy.OuterSingleton, Z_Construct_UClass_UPicoFindSessionsCallbackProxy_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPicoFindSessionsCallbackProxy.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPicoFindSessionsCallbackProxy>()
	{
		return UPicoFindSessionsCallbackProxy::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPicoFindSessionsCallbackProxy);
	UPicoFindSessionsCallbackProxy::~UPicoFindSessionsCallbackProxy() {}
	struct Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Classes_PicoFindSessionsCallbackProxy_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Classes_PicoFindSessionsCallbackProxy_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPicoFindSessionsCallbackProxy, UPicoFindSessionsCallbackProxy::StaticClass, TEXT("UPicoFindSessionsCallbackProxy"), &Z_Registration_Info_UClass_UPicoFindSessionsCallbackProxy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPicoFindSessionsCallbackProxy), 3853499789U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Classes_PicoFindSessionsCallbackProxy_h_3839409708(TEXT("/Script/OnlineSubsystemPico"),
		Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Classes_PicoFindSessionsCallbackProxy_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Classes_PicoFindSessionsCallbackProxy_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
