// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../OnlineSubsystemPico/Public/Pico_Compliance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePico_Compliance() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoComplianceFunction();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoComplianceFunction_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_DetectSensitiveResult();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_DetectSensitiveResult_NoRegister();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_EDetectSensitiveScene();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ESensitiveProposal();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemPico();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventDetectSensitive_Parms
		{
			bool bIsError;
			int32 ErrorCode;
			FString ErrorMessage;
			UPico_DetectSensitiveResult* DetectSensitiveResult;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ErrorCode;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DetectSensitiveResult;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventDetectSensitive_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventDetectSensitive_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::NewProp_ErrorCode = { "ErrorCode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventDetectSensitive_Parms, ErrorCode), METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventDetectSensitive_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::NewProp_DetectSensitiveResult = { "DetectSensitiveResult", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventDetectSensitive_Parms, DetectSensitiveResult), Z_Construct_UClass_UPico_DetectSensitiveResult_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::NewProp_ErrorCode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::NewProp_DetectSensitiveResult,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_Compliance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "DetectSensitive__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventDetectSensitive_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventDetectSensitive_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FDetectSensitive_DelegateWrapper(const FScriptDelegate& DetectSensitive, bool bIsError, int32 ErrorCode, const FString& ErrorMessage, UPico_DetectSensitiveResult* DetectSensitiveResult)
{
	struct _Script_OnlineSubsystemPico_eventDetectSensitive_Parms
	{
		bool bIsError;
		int32 ErrorCode;
		FString ErrorMessage;
		UPico_DetectSensitiveResult* DetectSensitiveResult;
	};
	_Script_OnlineSubsystemPico_eventDetectSensitive_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorCode=ErrorCode;
	Parms.ErrorMessage=ErrorMessage;
	Parms.DetectSensitiveResult=DetectSensitiveResult;
	DetectSensitive.ProcessDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UOnlinePicoComplianceFunction::execDetectSensitive)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_ENUM(EDetectSensitiveScene,Z_Param_DetectSensitiveScene);
		P_GET_PROPERTY(FStrProperty,Z_Param_InDetectContent);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoComplianceFunction::DetectSensitive(Z_Param_WorldContextObject,EDetectSensitiveScene(Z_Param_DetectSensitiveScene),Z_Param_InDetectContent,FDetectSensitive(Z_Param_InDelegate));
		P_NATIVE_END;
	}
	void UOnlinePicoComplianceFunction::StaticRegisterNativesUOnlinePicoComplianceFunction()
	{
		UClass* Class = UOnlinePicoComplianceFunction::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DetectSensitive", &UOnlinePicoComplianceFunction::execDetectSensitive },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics
	{
		struct OnlinePicoComplianceFunction_eventDetectSensitive_Parms
		{
			UObject* WorldContextObject;
			EDetectSensitiveScene DetectSensitiveScene;
			FString InDetectContent;
			FScriptDelegate InDelegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FBytePropertyParams NewProp_DetectSensitiveScene_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DetectSensitiveScene;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InDetectContent_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_InDetectContent;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InDelegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoComplianceFunction_eventDetectSensitive_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::NewProp_DetectSensitiveScene_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::NewProp_DetectSensitiveScene = { "DetectSensitiveScene", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoComplianceFunction_eventDetectSensitive_Parms, DetectSensitiveScene), Z_Construct_UEnum_OnlineSubsystemPico_EDetectSensitiveScene, METADATA_PARAMS(0, nullptr) }; // 2507255313
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::NewProp_InDetectContent_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::NewProp_InDetectContent = { "InDetectContent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoComplianceFunction_eventDetectSensitive_Parms, InDetectContent), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::NewProp_InDetectContent_MetaData), Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::NewProp_InDetectContent_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::NewProp_InDelegate = { "InDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoComplianceFunction_eventDetectSensitive_Parms, InDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_DetectSensitive__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1594923615
	void Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoComplianceFunction_eventDetectSensitive_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoComplianceFunction_eventDetectSensitive_Parms), &Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::NewProp_DetectSensitiveScene_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::NewProp_DetectSensitiveScene,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::NewProp_InDetectContent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::NewProp_InDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Complianc" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Detects if a user name, room name, or the in-room chat content contains sensitive words.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"DetectSensitiveScene\">The type of content to verify. It can be a username, a room name, or in-room chat.</param>\n/// <param name=\"InDetectContent\">The content to verify.</param>\n/// <param name=\"InDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_DetectSensitiveResult *, DetectSensitiveResult).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Compliance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nDetects if a user name, room name, or the in-room chat content contains sensitive words.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"DetectSensitiveScene\">The type of content to verify. It can be a username, a room name, or in-room chat.</param>\n<param name=\"InDetectContent\">The content to verify.</param>\n<param name=\"InDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_DetectSensitiveResult *, DetectSensitiveResult).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoComplianceFunction, nullptr, "DetectSensitive", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::OnlinePicoComplianceFunction_eventDetectSensitive_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::OnlinePicoComplianceFunction_eventDetectSensitive_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOnlinePicoComplianceFunction);
	UClass* Z_Construct_UClass_UOnlinePicoComplianceFunction_NoRegister()
	{
		return UOnlinePicoComplianceFunction::StaticClass();
	}
	struct Z_Construct_UClass_UOnlinePicoComplianceFunction_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOnlinePicoComplianceFunction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoComplianceFunction_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UOnlinePicoComplianceFunction_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOnlinePicoComplianceFunction_DetectSensitive, "DetectSensitive" }, // 2530355546
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoComplianceFunction_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoComplianceFunction_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @defgroup BP_Compliance BP_Compliance\n  *  This is the BP_Compliance group\n  *  @{\n  *//// @brief OnlinePicoCompliance Blueprint Function class.\n" },
#endif
		{ "IncludePath", "Pico_Compliance.h" },
		{ "ModuleRelativePath", "Public/Pico_Compliance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@defgroup BP_Compliance BP_Compliance\nThis is the BP_Compliance group\n@{\n /// @brief OnlinePicoCompliance Blueprint Function class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOnlinePicoComplianceFunction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOnlinePicoComplianceFunction>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOnlinePicoComplianceFunction_Statics::ClassParams = {
		&UOnlinePicoComplianceFunction::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoComplianceFunction_Statics::Class_MetaDataParams), Z_Construct_UClass_UOnlinePicoComplianceFunction_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UOnlinePicoComplianceFunction()
	{
		if (!Z_Registration_Info_UClass_UOnlinePicoComplianceFunction.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOnlinePicoComplianceFunction.OuterSingleton, Z_Construct_UClass_UOnlinePicoComplianceFunction_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOnlinePicoComplianceFunction.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UOnlinePicoComplianceFunction>()
	{
		return UOnlinePicoComplianceFunction::StaticClass();
	}
	UOnlinePicoComplianceFunction::UOnlinePicoComplianceFunction(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOnlinePicoComplianceFunction);
	UOnlinePicoComplianceFunction::~UOnlinePicoComplianceFunction() {}
	DEFINE_FUNCTION(UPico_DetectSensitiveResult::execGetFilteredText)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetFilteredText();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_DetectSensitiveResult::execGetSensitiveProposal)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ESensitiveProposal*)Z_Param__Result=P_THIS->GetSensitiveProposal();
		P_NATIVE_END;
	}
	void UPico_DetectSensitiveResult::StaticRegisterNativesUPico_DetectSensitiveResult()
	{
		UClass* Class = UPico_DetectSensitiveResult::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetFilteredText", &UPico_DetectSensitiveResult::execGetFilteredText },
			{ "GetSensitiveProposal", &UPico_DetectSensitiveResult::execGetSensitiveProposal },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_DetectSensitiveResult_GetFilteredText_Statics
	{
		struct Pico_DetectSensitiveResult_eventGetFilteredText_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_DetectSensitiveResult_GetFilteredText_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_DetectSensitiveResult_eventGetFilteredText_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_DetectSensitiveResult_GetFilteredText_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_DetectSensitiveResult_GetFilteredText_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_DetectSensitiveResult_GetFilteredText_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Compliance|DetectSensitiveResult" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The filtered text is a string which replace sensitive words with `*`. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Compliance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The filtered text is a string which replace sensitive words with `*`." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_DetectSensitiveResult_GetFilteredText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_DetectSensitiveResult, nullptr, "GetFilteredText", nullptr, nullptr, Z_Construct_UFunction_UPico_DetectSensitiveResult_GetFilteredText_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_DetectSensitiveResult_GetFilteredText_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_DetectSensitiveResult_GetFilteredText_Statics::Pico_DetectSensitiveResult_eventGetFilteredText_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_DetectSensitiveResult_GetFilteredText_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_DetectSensitiveResult_GetFilteredText_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_DetectSensitiveResult_GetFilteredText_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_DetectSensitiveResult_GetFilteredText_Statics::Pico_DetectSensitiveResult_eventGetFilteredText_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_DetectSensitiveResult_GetFilteredText()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_DetectSensitiveResult_GetFilteredText_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_DetectSensitiveResult_GetSensitiveProposal_Statics
	{
		struct Pico_DetectSensitiveResult_eventGetSensitiveProposal_Parms
		{
			ESensitiveProposal ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPico_DetectSensitiveResult_GetSensitiveProposal_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPico_DetectSensitiveResult_GetSensitiveProposal_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_DetectSensitiveResult_eventGetSensitiveProposal_Parms, ReturnValue), Z_Construct_UEnum_OnlineSubsystemPico_ESensitiveProposal, METADATA_PARAMS(0, nullptr) }; // 3691664560
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_DetectSensitiveResult_GetSensitiveProposal_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_DetectSensitiveResult_GetSensitiveProposal_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_DetectSensitiveResult_GetSensitiveProposal_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_DetectSensitiveResult_GetSensitiveProposal_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Compliance|DetectSensitiveResult" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The text-handling proposal. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Compliance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The text-handling proposal." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_DetectSensitiveResult_GetSensitiveProposal_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_DetectSensitiveResult, nullptr, "GetSensitiveProposal", nullptr, nullptr, Z_Construct_UFunction_UPico_DetectSensitiveResult_GetSensitiveProposal_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_DetectSensitiveResult_GetSensitiveProposal_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_DetectSensitiveResult_GetSensitiveProposal_Statics::Pico_DetectSensitiveResult_eventGetSensitiveProposal_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_DetectSensitiveResult_GetSensitiveProposal_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_DetectSensitiveResult_GetSensitiveProposal_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_DetectSensitiveResult_GetSensitiveProposal_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_DetectSensitiveResult_GetSensitiveProposal_Statics::Pico_DetectSensitiveResult_eventGetSensitiveProposal_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_DetectSensitiveResult_GetSensitiveProposal()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_DetectSensitiveResult_GetSensitiveProposal_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_DetectSensitiveResult);
	UClass* Z_Construct_UClass_UPico_DetectSensitiveResult_NoRegister()
	{
		return UPico_DetectSensitiveResult::StaticClass();
	}
	struct Z_Construct_UClass_UPico_DetectSensitiveResult_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_DetectSensitiveResult_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_DetectSensitiveResult_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_DetectSensitiveResult_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_DetectSensitiveResult_GetFilteredText, "GetFilteredText" }, // 2353331454
		{ &Z_Construct_UFunction_UPico_DetectSensitiveResult_GetSensitiveProposal, "GetSensitiveProposal" }, // 308454496
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_DetectSensitiveResult_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_DetectSensitiveResult_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @} *//// @brief UPico_DetectSensitiveResult class.\n" },
#endif
		{ "IncludePath", "Pico_Compliance.h" },
		{ "ModuleRelativePath", "Public/Pico_Compliance.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@} /// @brief UPico_DetectSensitiveResult class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_DetectSensitiveResult_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_DetectSensitiveResult>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_DetectSensitiveResult_Statics::ClassParams = {
		&UPico_DetectSensitiveResult::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_DetectSensitiveResult_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_DetectSensitiveResult_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPico_DetectSensitiveResult()
	{
		if (!Z_Registration_Info_UClass_UPico_DetectSensitiveResult.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_DetectSensitiveResult.OuterSingleton, Z_Construct_UClass_UPico_DetectSensitiveResult_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_DetectSensitiveResult.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_DetectSensitiveResult>()
	{
		return UPico_DetectSensitiveResult::StaticClass();
	}
	UPico_DetectSensitiveResult::UPico_DetectSensitiveResult(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_DetectSensitiveResult);
	UPico_DetectSensitiveResult::~UPico_DetectSensitiveResult() {}
	struct Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOnlinePicoComplianceFunction, UOnlinePicoComplianceFunction::StaticClass, TEXT("UOnlinePicoComplianceFunction"), &Z_Registration_Info_UClass_UOnlinePicoComplianceFunction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOnlinePicoComplianceFunction), 1010628052U) },
		{ Z_Construct_UClass_UPico_DetectSensitiveResult, UPico_DetectSensitiveResult::StaticClass, TEXT("UPico_DetectSensitiveResult"), &Z_Registration_Info_UClass_UPico_DetectSensitiveResult, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_DetectSensitiveResult), 3189388751U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_2421549336(TEXT("/Script/OnlineSubsystemPico"),
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
