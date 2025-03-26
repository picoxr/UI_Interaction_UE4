// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../OnlineSubsystemPico/Classes/PicoCreateSessionCallbackProxy.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePicoCreateSessionCallbackProxy() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UOnlineBlueprintCallProxyBase();
	ENGINE_API UFunction* Z_Construct_UDelegateFunction_Engine_EmptyOnlineDelegate__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPicoCreateSessionCallbackProxy();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPicoCreateSessionCallbackProxy_NoRegister();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemPico();
// End Cross Module References
	DEFINE_FUNCTION(UPicoCreateSessionCallbackProxy::execCreateSession)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_PublicConnections);
		P_GET_PROPERTY(FStrProperty,Z_Param_PicoMatchmakingPool);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPicoCreateSessionCallbackProxy**)Z_Param__Result=UPicoCreateSessionCallbackProxy::CreateSession(Z_Param_PublicConnections,Z_Param_PicoMatchmakingPool);
		P_NATIVE_END;
	}
	void UPicoCreateSessionCallbackProxy::StaticRegisterNativesUPicoCreateSessionCallbackProxy()
	{
		UClass* Class = UPicoCreateSessionCallbackProxy::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateSession", &UPicoCreateSessionCallbackProxy::execCreateSession },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPicoCreateSessionCallbackProxy_CreateSession_Statics
	{
		struct PicoCreateSessionCallbackProxy_eventCreateSession_Parms
		{
			int32 PublicConnections;
			FString PicoMatchmakingPool;
			UPicoCreateSessionCallbackProxy* ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_PublicConnections;
		static const UECodeGen_Private::FStrPropertyParams NewProp_PicoMatchmakingPool;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPicoCreateSessionCallbackProxy_CreateSession_Statics::NewProp_PublicConnections = { "PublicConnections", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PicoCreateSessionCallbackProxy_eventCreateSession_Parms, PublicConnections), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPicoCreateSessionCallbackProxy_CreateSession_Statics::NewProp_PicoMatchmakingPool = { "PicoMatchmakingPool", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PicoCreateSessionCallbackProxy_eventCreateSession_Parms, PicoMatchmakingPool), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPicoCreateSessionCallbackProxy_CreateSession_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PicoCreateSessionCallbackProxy_eventCreateSession_Parms, ReturnValue), Z_Construct_UClass_UPicoCreateSessionCallbackProxy_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPicoCreateSessionCallbackProxy_CreateSession_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoCreateSessionCallbackProxy_CreateSession_Statics::NewProp_PublicConnections,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoCreateSessionCallbackProxy_CreateSession_Statics::NewProp_PicoMatchmakingPool,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPicoCreateSessionCallbackProxy_CreateSession_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPicoCreateSessionCallbackProxy_CreateSession_Statics::Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Pico|Session" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Kick off CreateSession check. Asynchronous-- see OnCreateSessionCompleteDelegate for results.\n" },
#endif
		{ "ModuleRelativePath", "Classes/PicoCreateSessionCallbackProxy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Kick off CreateSession check. Asynchronous-- see OnCreateSessionCompleteDelegate for results." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPicoCreateSessionCallbackProxy_CreateSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPicoCreateSessionCallbackProxy, nullptr, "CreateSession", nullptr, nullptr, Z_Construct_UFunction_UPicoCreateSessionCallbackProxy_CreateSession_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoCreateSessionCallbackProxy_CreateSession_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPicoCreateSessionCallbackProxy_CreateSession_Statics::PicoCreateSessionCallbackProxy_eventCreateSession_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoCreateSessionCallbackProxy_CreateSession_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPicoCreateSessionCallbackProxy_CreateSession_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPicoCreateSessionCallbackProxy_CreateSession_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPicoCreateSessionCallbackProxy_CreateSession_Statics::PicoCreateSessionCallbackProxy_eventCreateSession_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPicoCreateSessionCallbackProxy_CreateSession()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPicoCreateSessionCallbackProxy_CreateSession_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPicoCreateSessionCallbackProxy);
	UClass* Z_Construct_UClass_UPicoCreateSessionCallbackProxy_NoRegister()
	{
		return UPicoCreateSessionCallbackProxy::StaticClass();
	}
	struct Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics
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
	UObject* (*const Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UOnlineBlueprintCallProxyBase,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPicoCreateSessionCallbackProxy_CreateSession, "CreateSession" }, // 4223539953
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Exposes CreateSession of the Platform SDK for blueprint use.\n */" },
#endif
		{ "IncludePath", "PicoCreateSessionCallbackProxy.h" },
		{ "ModuleRelativePath", "Classes/PicoCreateSessionCallbackProxy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Exposes CreateSession of the Platform SDK for blueprint use." },
#endif
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::NewProp_OnSuccess_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Called when the session was created successfully\n" },
#endif
		{ "ModuleRelativePath", "Classes/PicoCreateSessionCallbackProxy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when the session was created successfully" },
#endif
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPicoCreateSessionCallbackProxy, OnSuccess), Z_Construct_UDelegateFunction_Engine_EmptyOnlineDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::NewProp_OnSuccess_MetaData), Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::NewProp_OnSuccess_MetaData) }; // 747690002
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::NewProp_OnFailure_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Called when there was an error creating the session\n" },
#endif
		{ "ModuleRelativePath", "Classes/PicoCreateSessionCallbackProxy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when there was an error creating the session" },
#endif
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::NewProp_OnFailure = { "OnFailure", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPicoCreateSessionCallbackProxy, OnFailure), Z_Construct_UDelegateFunction_Engine_EmptyOnlineDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::NewProp_OnFailure_MetaData), Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::NewProp_OnFailure_MetaData) }; // 747690002
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::NewProp_OnSuccess,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::NewProp_OnFailure,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPicoCreateSessionCallbackProxy>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::ClassParams = {
		&UPicoCreateSessionCallbackProxy::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::PropPointers),
		0,
		0x008800A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::Class_MetaDataParams), Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPicoCreateSessionCallbackProxy()
	{
		if (!Z_Registration_Info_UClass_UPicoCreateSessionCallbackProxy.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPicoCreateSessionCallbackProxy.OuterSingleton, Z_Construct_UClass_UPicoCreateSessionCallbackProxy_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPicoCreateSessionCallbackProxy.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPicoCreateSessionCallbackProxy>()
	{
		return UPicoCreateSessionCallbackProxy::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPicoCreateSessionCallbackProxy);
	UPicoCreateSessionCallbackProxy::~UPicoCreateSessionCallbackProxy() {}
	struct Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Classes_PicoCreateSessionCallbackProxy_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Classes_PicoCreateSessionCallbackProxy_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPicoCreateSessionCallbackProxy, UPicoCreateSessionCallbackProxy::StaticClass, TEXT("UPicoCreateSessionCallbackProxy"), &Z_Registration_Info_UClass_UPicoCreateSessionCallbackProxy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPicoCreateSessionCallbackProxy), 4209024311U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Classes_PicoCreateSessionCallbackProxy_h_2372442468(TEXT("/Script/OnlineSubsystemPico"),
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Classes_PicoCreateSessionCallbackProxy_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Classes_PicoCreateSessionCallbackProxy_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
