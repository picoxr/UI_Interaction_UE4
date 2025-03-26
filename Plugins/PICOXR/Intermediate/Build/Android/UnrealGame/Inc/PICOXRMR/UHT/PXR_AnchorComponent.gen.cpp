// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PICOXRMR/Public/PXR_AnchorComponent.h"
#include "PICOXRMR/Public/PXR_MRTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePXR_AnchorComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	PICOXRMR_API UClass* Z_Construct_UClass_UPICOAnchorComponent();
	PICOXRMR_API UClass* Z_Construct_UClass_UPICOAnchorComponent_NoRegister();
	PICOXRMR_API UScriptStruct* Z_Construct_UScriptStruct_FPICOSpatialHandle();
	UPackage* Z_Construct_UPackage__Script_PICOXRMR();
// End Cross Module References
	DEFINE_FUNCTION(UPICOAnchorComponent::execIsAnchorValid)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsAnchorValid();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOAnchorComponent::execGetAnchorHandleString)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetAnchorHandleString();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOAnchorComponent::execSetAnchorHandle)
	{
		P_GET_STRUCT(FPICOSpatialHandle,Z_Param_NewAnchorHandle);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetAnchorHandle(Z_Param_NewAnchorHandle);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPICOAnchorComponent::execGetAnchorHandle)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FPICOSpatialHandle*)Z_Param__Result=P_THIS->GetAnchorHandle();
		P_NATIVE_END;
	}
	void UPICOAnchorComponent::StaticRegisterNativesUPICOAnchorComponent()
	{
		UClass* Class = UPICOAnchorComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAnchorHandle", &UPICOAnchorComponent::execGetAnchorHandle },
			{ "GetAnchorHandleString", &UPICOAnchorComponent::execGetAnchorHandleString },
			{ "IsAnchorValid", &UPICOAnchorComponent::execIsAnchorValid },
			{ "SetAnchorHandle", &UPICOAnchorComponent::execSetAnchorHandle },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandle_Statics
	{
		struct PICOAnchorComponent_eventGetAnchorHandle_Parms
		{
			FPICOSpatialHandle ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandle_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOAnchorComponent_eventGetAnchorHandle_Parms, ReturnValue), Z_Construct_UScriptStruct_FPICOSpatialHandle, METADATA_PARAMS(0, nullptr) }; // 82442488
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandle_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandle_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandle_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|MR" },
		{ "ModuleRelativePath", "Public/PXR_AnchorComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOAnchorComponent, nullptr, "GetAnchorHandle", nullptr, nullptr, Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandle_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandle_Statics::PICOAnchorComponent_eventGetAnchorHandle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandle_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandle_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandle_Statics::PICOAnchorComponent_eventGetAnchorHandle_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandleString_Statics
	{
		struct PICOAnchorComponent_eventGetAnchorHandleString_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandleString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOAnchorComponent_eventGetAnchorHandleString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandleString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandleString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandleString_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|MR" },
		{ "ModuleRelativePath", "Public/PXR_AnchorComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandleString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOAnchorComponent, nullptr, "GetAnchorHandleString", nullptr, nullptr, Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandleString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandleString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandleString_Statics::PICOAnchorComponent_eventGetAnchorHandleString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandleString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandleString_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandleString_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandleString_Statics::PICOAnchorComponent_eventGetAnchorHandleString_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandleString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandleString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOAnchorComponent_IsAnchorValid_Statics
	{
		struct PICOAnchorComponent_eventIsAnchorValid_Parms
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
	void Z_Construct_UFunction_UPICOAnchorComponent_IsAnchorValid_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PICOAnchorComponent_eventIsAnchorValid_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPICOAnchorComponent_IsAnchorValid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(PICOAnchorComponent_eventIsAnchorValid_Parms), &Z_Construct_UFunction_UPICOAnchorComponent_IsAnchorValid_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOAnchorComponent_IsAnchorValid_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOAnchorComponent_IsAnchorValid_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOAnchorComponent_IsAnchorValid_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|MR" },
		{ "ModuleRelativePath", "Public/PXR_AnchorComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOAnchorComponent_IsAnchorValid_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOAnchorComponent, nullptr, "IsAnchorValid", nullptr, nullptr, Z_Construct_UFunction_UPICOAnchorComponent_IsAnchorValid_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOAnchorComponent_IsAnchorValid_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOAnchorComponent_IsAnchorValid_Statics::PICOAnchorComponent_eventIsAnchorValid_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOAnchorComponent_IsAnchorValid_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOAnchorComponent_IsAnchorValid_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOAnchorComponent_IsAnchorValid_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOAnchorComponent_IsAnchorValid_Statics::PICOAnchorComponent_eventIsAnchorValid_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOAnchorComponent_IsAnchorValid()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOAnchorComponent_IsAnchorValid_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPICOAnchorComponent_SetAnchorHandle_Statics
	{
		struct PICOAnchorComponent_eventSetAnchorHandle_Parms
		{
			FPICOSpatialHandle NewAnchorHandle;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_NewAnchorHandle;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPICOAnchorComponent_SetAnchorHandle_Statics::NewProp_NewAnchorHandle = { "NewAnchorHandle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PICOAnchorComponent_eventSetAnchorHandle_Parms, NewAnchorHandle), Z_Construct_UScriptStruct_FPICOSpatialHandle, METADATA_PARAMS(0, nullptr) }; // 82442488
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPICOAnchorComponent_SetAnchorHandle_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPICOAnchorComponent_SetAnchorHandle_Statics::NewProp_NewAnchorHandle,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPICOAnchorComponent_SetAnchorHandle_Statics::Function_MetaDataParams[] = {
		{ "Category", "PXR|MR" },
		{ "ModuleRelativePath", "Public/PXR_AnchorComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPICOAnchorComponent_SetAnchorHandle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPICOAnchorComponent, nullptr, "SetAnchorHandle", nullptr, nullptr, Z_Construct_UFunction_UPICOAnchorComponent_SetAnchorHandle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOAnchorComponent_SetAnchorHandle_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPICOAnchorComponent_SetAnchorHandle_Statics::PICOAnchorComponent_eventSetAnchorHandle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOAnchorComponent_SetAnchorHandle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPICOAnchorComponent_SetAnchorHandle_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPICOAnchorComponent_SetAnchorHandle_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPICOAnchorComponent_SetAnchorHandle_Statics::PICOAnchorComponent_eventSetAnchorHandle_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPICOAnchorComponent_SetAnchorHandle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPICOAnchorComponent_SetAnchorHandle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPICOAnchorComponent);
	UClass* Z_Construct_UClass_UPICOAnchorComponent_NoRegister()
	{
		return UPICOAnchorComponent::StaticClass();
	}
	struct Z_Construct_UClass_UPICOAnchorComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPICOAnchorComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_PICOXRMR,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOAnchorComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPICOAnchorComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandle, "GetAnchorHandle" }, // 1078884592
		{ &Z_Construct_UFunction_UPICOAnchorComponent_GetAnchorHandleString, "GetAnchorHandleString" }, // 653821802
		{ &Z_Construct_UFunction_UPICOAnchorComponent_IsAnchorValid, "IsAnchorValid" }, // 2537096681
		{ &Z_Construct_UFunction_UPICOAnchorComponent_SetAnchorHandle, "SetAnchorHandle" }, // 638035531
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOAnchorComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPICOAnchorComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "PXR_AnchorComponent.h" },
		{ "ModuleRelativePath", "Public/PXR_AnchorComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPICOAnchorComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPICOAnchorComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPICOAnchorComponent_Statics::ClassParams = {
		&UPICOAnchorComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPICOAnchorComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UPICOAnchorComponent_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPICOAnchorComponent()
	{
		if (!Z_Registration_Info_UClass_UPICOAnchorComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPICOAnchorComponent.OuterSingleton, Z_Construct_UClass_UPICOAnchorComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPICOAnchorComponent.OuterSingleton;
	}
	template<> PICOXRMR_API UClass* StaticClass<UPICOAnchorComponent>()
	{
		return UPICOAnchorComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPICOAnchorComponent);
	UPICOAnchorComponent::~UPICOAnchorComponent() {}
	struct Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_AnchorComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_AnchorComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPICOAnchorComponent, UPICOAnchorComponent::StaticClass, TEXT("UPICOAnchorComponent"), &Z_Registration_Info_UClass_UPICOAnchorComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPICOAnchorComponent), 1723323139U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_AnchorComponent_h_916693191(TEXT("/Script/PICOXRMR"),
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_AnchorComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_AnchorComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
