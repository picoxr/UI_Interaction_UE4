// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../OnlineSubsystemPico/Public/Pico_AssetFile.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePico_AssetFile() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoAssetFileFunction();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoAssetFileFunction_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AssetDetails();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AssetDetails_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AssetDetailsArray();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AssetDetailsArray_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AssetFileDeleteForSafety();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AssetFileDeleteForSafety_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AssetFileDeleteResult();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AssetFileDeleteResult_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AssetFileDownloadCancelResult();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AssetFileDownloadCancelResult_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AssetFileDownloadResult();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AssetFileDownloadResult_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AssetFileDownloadUpdate();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AssetFileDownloadUpdate_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AssetStatus();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AssetStatus_NoRegister();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_EAssetFileDownloadCompleteStatus();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemPico();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventAssetFileDeleteResult_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_AssetFileDeleteResult* DeleteResult;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DeleteResult;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventAssetFileDeleteResult_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventAssetFileDeleteResult_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventAssetFileDeleteResult_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature_Statics::NewProp_DeleteResult = { "DeleteResult", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventAssetFileDeleteResult_Parms, DeleteResult), Z_Construct_UClass_UPico_AssetFileDeleteResult_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature_Statics::NewProp_DeleteResult,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "AssetFileDeleteResult__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventAssetFileDeleteResult_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventAssetFileDeleteResult_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FAssetFileDeleteResult_DelegateWrapper(const FScriptDelegate& AssetFileDeleteResult, bool bIsError, const FString& ErrorMessage, UPico_AssetFileDeleteResult* DeleteResult)
{
	struct _Script_OnlineSubsystemPico_eventAssetFileDeleteResult_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_AssetFileDeleteResult* DeleteResult;
	};
	_Script_OnlineSubsystemPico_eventAssetFileDeleteResult_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.DeleteResult=DeleteResult;
	AssetFileDeleteResult.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventAssetFileDownloadResult_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_AssetFileDownloadResult* DownloadResult;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DownloadResult;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventAssetFileDownloadResult_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventAssetFileDownloadResult_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventAssetFileDownloadResult_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature_Statics::NewProp_DownloadResult = { "DownloadResult", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventAssetFileDownloadResult_Parms, DownloadResult), Z_Construct_UClass_UPico_AssetFileDownloadResult_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature_Statics::NewProp_DownloadResult,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "AssetFileDownloadResult__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventAssetFileDownloadResult_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventAssetFileDownloadResult_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FAssetFileDownloadResult_DelegateWrapper(const FScriptDelegate& AssetFileDownloadResult, bool bIsError, const FString& ErrorMessage, UPico_AssetFileDownloadResult* DownloadResult)
{
	struct _Script_OnlineSubsystemPico_eventAssetFileDownloadResult_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_AssetFileDownloadResult* DownloadResult;
	};
	_Script_OnlineSubsystemPico_eventAssetFileDownloadResult_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.DownloadResult=DownloadResult;
	AssetFileDownloadResult.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventAssetFileDownloadCancelResult_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_AssetFileDownloadCancelResult* DownloadCancelResult;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DownloadCancelResult;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventAssetFileDownloadCancelResult_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventAssetFileDownloadCancelResult_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventAssetFileDownloadCancelResult_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature_Statics::NewProp_DownloadCancelResult = { "DownloadCancelResult", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventAssetFileDownloadCancelResult_Parms, DownloadCancelResult), Z_Construct_UClass_UPico_AssetFileDownloadCancelResult_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature_Statics::NewProp_DownloadCancelResult,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "AssetFileDownloadCancelResult__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventAssetFileDownloadCancelResult_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventAssetFileDownloadCancelResult_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FAssetFileDownloadCancelResult_DelegateWrapper(const FScriptDelegate& AssetFileDownloadCancelResult, bool bIsError, const FString& ErrorMessage, UPico_AssetFileDownloadCancelResult* DownloadCancelResult)
{
	struct _Script_OnlineSubsystemPico_eventAssetFileDownloadCancelResult_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_AssetFileDownloadCancelResult* DownloadCancelResult;
	};
	_Script_OnlineSubsystemPico_eventAssetFileDownloadCancelResult_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.DownloadCancelResult=DownloadCancelResult;
	AssetFileDownloadCancelResult.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetAssetFileStatus_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_AssetStatus* AssetFileStatus;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AssetFileStatus;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetAssetFileStatus_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetAssetFileStatus_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetAssetFileStatus_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature_Statics::NewProp_AssetFileStatus = { "AssetFileStatus", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetAssetFileStatus_Parms, AssetFileStatus), Z_Construct_UClass_UPico_AssetStatus_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature_Statics::NewProp_AssetFileStatus,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetAssetFileStatus__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetAssetFileStatus_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetAssetFileStatus_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetAssetFileStatus_DelegateWrapper(const FScriptDelegate& GetAssetFileStatus, bool bIsError, const FString& ErrorMessage, UPico_AssetStatus* AssetFileStatus)
{
	struct _Script_OnlineSubsystemPico_eventGetAssetFileStatus_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_AssetStatus* AssetFileStatus;
	};
	_Script_OnlineSubsystemPico_eventGetAssetFileStatus_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.AssetFileStatus=AssetFileStatus;
	GetAssetFileStatus.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetAssetFileList_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_AssetDetailsArray* AssetDetailsArray;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AssetDetailsArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetAssetFileList_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetAssetFileList_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetAssetFileList_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature_Statics::NewProp_AssetDetailsArray = { "AssetDetailsArray", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetAssetFileList_Parms, AssetDetailsArray), Z_Construct_UClass_UPico_AssetDetailsArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature_Statics::NewProp_AssetDetailsArray,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetAssetFileList__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetAssetFileList_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetAssetFileList_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetAssetFileList_DelegateWrapper(const FScriptDelegate& GetAssetFileList, bool bIsError, const FString& ErrorMessage, UPico_AssetDetailsArray* AssetDetailsArray)
{
	struct _Script_OnlineSubsystemPico_eventGetAssetFileList_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_AssetDetailsArray* AssetDetailsArray;
	};
	_Script_OnlineSubsystemPico_eventGetAssetFileList_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.AssetDetailsArray=AssetDetailsArray;
	GetAssetFileList.ProcessDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UOnlinePicoAssetFileFunction::execGetAssetFileStatusByName)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_AssetFileName);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetAssetFileStatusByNameDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoAssetFileFunction::GetAssetFileStatusByName(Z_Param_WorldContextObject,Z_Param_AssetFileName,FGetAssetFileStatus(Z_Param_InGetAssetFileStatusByNameDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoAssetFileFunction::execGetAssetFileStatusById)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_AssetFileID);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetAssetFileStatusByIdDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoAssetFileFunction::GetAssetFileStatusById(Z_Param_WorldContextObject,Z_Param_AssetFileID,FGetAssetFileStatus(Z_Param_InGetAssetFileStatusByIdDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoAssetFileFunction::execGetNextAssetDetailsArrayPage)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_OBJECT(UPico_AssetDetailsArray,Z_Param_InAssetDetailsArray);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetNextAssetDetailsArrayPageDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoAssetFileFunction::GetNextAssetDetailsArrayPage(Z_Param_WorldContextObject,Z_Param_InAssetDetailsArray,FGetAssetFileList(Z_Param_InGetNextAssetDetailsArrayPageDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoAssetFileFunction::execGetAssetFileList)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetAssetFileListDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoAssetFileFunction::GetAssetFileList(Z_Param_WorldContextObject,FGetAssetFileList(Z_Param_InGetAssetFileListDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoAssetFileFunction::execDownloadCancelByName)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_AssetFileName);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InDownloadCancelByNameDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoAssetFileFunction::DownloadCancelByName(Z_Param_WorldContextObject,Z_Param_AssetFileName,FAssetFileDownloadCancelResult(Z_Param_InDownloadCancelByNameDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoAssetFileFunction::execDownloadCancelById)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_AssetFileID);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InDownloadCancelByIDDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoAssetFileFunction::DownloadCancelById(Z_Param_WorldContextObject,Z_Param_AssetFileID,FAssetFileDownloadCancelResult(Z_Param_InDownloadCancelByIDDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoAssetFileFunction::execDownloadByName)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_AssetFileName);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InDownloadByNameDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoAssetFileFunction::DownloadByName(Z_Param_WorldContextObject,Z_Param_AssetFileName,FAssetFileDownloadResult(Z_Param_InDownloadByNameDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoAssetFileFunction::execDownloadById)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_AssetFileID);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InDownloadByIDDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoAssetFileFunction::DownloadById(Z_Param_WorldContextObject,Z_Param_AssetFileID,FAssetFileDownloadResult(Z_Param_InDownloadByIDDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoAssetFileFunction::execDeleteByName)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_AssetFileName);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InDeleteByNameDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoAssetFileFunction::DeleteByName(Z_Param_WorldContextObject,Z_Param_AssetFileName,FAssetFileDeleteResult(Z_Param_InDeleteByNameDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoAssetFileFunction::execDeleteByID)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_AssetFileID);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InDeleteByIDDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoAssetFileFunction::DeleteByID(Z_Param_WorldContextObject,Z_Param_AssetFileID,FAssetFileDeleteResult(Z_Param_InDeleteByIDDelegate));
		P_NATIVE_END;
	}
	void UOnlinePicoAssetFileFunction::StaticRegisterNativesUOnlinePicoAssetFileFunction()
	{
		UClass* Class = UOnlinePicoAssetFileFunction::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DeleteByID", &UOnlinePicoAssetFileFunction::execDeleteByID },
			{ "DeleteByName", &UOnlinePicoAssetFileFunction::execDeleteByName },
			{ "DownloadById", &UOnlinePicoAssetFileFunction::execDownloadById },
			{ "DownloadByName", &UOnlinePicoAssetFileFunction::execDownloadByName },
			{ "DownloadCancelById", &UOnlinePicoAssetFileFunction::execDownloadCancelById },
			{ "DownloadCancelByName", &UOnlinePicoAssetFileFunction::execDownloadCancelByName },
			{ "GetAssetFileList", &UOnlinePicoAssetFileFunction::execGetAssetFileList },
			{ "GetAssetFileStatusById", &UOnlinePicoAssetFileFunction::execGetAssetFileStatusById },
			{ "GetAssetFileStatusByName", &UOnlinePicoAssetFileFunction::execGetAssetFileStatusByName },
			{ "GetNextAssetDetailsArrayPage", &UOnlinePicoAssetFileFunction::execGetNextAssetDetailsArrayPage },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID_Statics
	{
		struct OnlinePicoAssetFileFunction_eventDeleteByID_Parms
		{
			UObject* WorldContextObject;
			FString AssetFileID;
			FScriptDelegate InDeleteByIDDelegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FStrPropertyParams NewProp_AssetFileID;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InDeleteByIDDelegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventDeleteByID_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID_Statics::NewProp_AssetFileID = { "AssetFileID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventDeleteByID_Parms, AssetFileID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID_Statics::NewProp_InDeleteByIDDelegate = { "InDeleteByIDDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventDeleteByID_Parms, InDeleteByIDDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2366496727
	void Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoAssetFileFunction_eventDeleteByID_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoAssetFileFunction_eventDeleteByID_Parms), &Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID_Statics::NewProp_AssetFileID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID_Statics::NewProp_InDeleteByIDDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|AssetFile" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Deletes an installed asset file by asset file ID. The corresponding\n/// asset file will be removed from the device. \n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"AssetFileID\">The ID of the installed asset file to delete.</param>\n/// <param name=\"InDeleteByIDDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AssetFileDeleteResult *, DeleteResult).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nDeletes an installed asset file by asset file ID. The corresponding\nasset file will be removed from the device.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"AssetFileID\">The ID of the installed asset file to delete.</param>\n<param name=\"InDeleteByIDDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AssetFileDeleteResult *, DeleteResult).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoAssetFileFunction, nullptr, "DeleteByID", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID_Statics::OnlinePicoAssetFileFunction_eventDeleteByID_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID_Statics::OnlinePicoAssetFileFunction_eventDeleteByID_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName_Statics
	{
		struct OnlinePicoAssetFileFunction_eventDeleteByName_Parms
		{
			UObject* WorldContextObject;
			FString AssetFileName;
			FScriptDelegate InDeleteByNameDelegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FStrPropertyParams NewProp_AssetFileName;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InDeleteByNameDelegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventDeleteByName_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName_Statics::NewProp_AssetFileName = { "AssetFileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventDeleteByName_Parms, AssetFileName), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName_Statics::NewProp_InDeleteByNameDelegate = { "InDeleteByNameDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventDeleteByName_Parms, InDeleteByNameDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDeleteResult__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2366496727
	void Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoAssetFileFunction_eventDeleteByName_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoAssetFileFunction_eventDeleteByName_Parms), &Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName_Statics::NewProp_AssetFileName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName_Statics::NewProp_InDeleteByNameDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|AssetFile" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Deletes an installed asset file by asset file name. The corresponding\n/// asset file will be removed from the device. \n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"AssetFileName\">The name of the installed asset file to delete.</param>\n/// <param name=\"InDeleteByNameDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AssetFileDeleteResult *, DeleteResult).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nDeletes an installed asset file by asset file name. The corresponding\nasset file will be removed from the device.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"AssetFileName\">The name of the installed asset file to delete.</param>\n<param name=\"InDeleteByNameDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AssetFileDeleteResult *, DeleteResult).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoAssetFileFunction, nullptr, "DeleteByName", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName_Statics::OnlinePicoAssetFileFunction_eventDeleteByName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName_Statics::OnlinePicoAssetFileFunction_eventDeleteByName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById_Statics
	{
		struct OnlinePicoAssetFileFunction_eventDownloadById_Parms
		{
			UObject* WorldContextObject;
			FString AssetFileID;
			FScriptDelegate InDownloadByIDDelegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FStrPropertyParams NewProp_AssetFileID;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InDownloadByIDDelegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventDownloadById_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById_Statics::NewProp_AssetFileID = { "AssetFileID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventDownloadById_Parms, AssetFileID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById_Statics::NewProp_InDownloadByIDDelegate = { "InDownloadByIDDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventDownloadById_Parms, InDownloadByIDDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2414204031
	void Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoAssetFileFunction_eventDownloadById_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoAssetFileFunction_eventDownloadById_Parms), &Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById_Statics::NewProp_AssetFileID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById_Statics::NewProp_InDownloadByIDDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|AssetFile" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Downloads an asset file by asset file ID.\n/// </summary>\n/// <param name =\"WorldContextObject\">The ID of the asset file to download.</param>\n/// <param name=\"AssetFileID\">The asset file ID.</param>\n/// <param name=\"InDownloadByIDDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AssetFileDownloadResult *, DownloadResult).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nDownloads an asset file by asset file ID.\n</summary>\n<param name =\"WorldContextObject\">The ID of the asset file to download.</param>\n<param name=\"AssetFileID\">The asset file ID.</param>\n<param name=\"InDownloadByIDDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AssetFileDownloadResult *, DownloadResult).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoAssetFileFunction, nullptr, "DownloadById", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById_Statics::OnlinePicoAssetFileFunction_eventDownloadById_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById_Statics::OnlinePicoAssetFileFunction_eventDownloadById_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName_Statics
	{
		struct OnlinePicoAssetFileFunction_eventDownloadByName_Parms
		{
			UObject* WorldContextObject;
			FString AssetFileName;
			FScriptDelegate InDownloadByNameDelegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FStrPropertyParams NewProp_AssetFileName;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InDownloadByNameDelegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventDownloadByName_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName_Statics::NewProp_AssetFileName = { "AssetFileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventDownloadByName_Parms, AssetFileName), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName_Statics::NewProp_InDownloadByNameDelegate = { "InDownloadByNameDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventDownloadByName_Parms, InDownloadByNameDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadResult__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2414204031
	void Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoAssetFileFunction_eventDownloadByName_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoAssetFileFunction_eventDownloadByName_Parms), &Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName_Statics::NewProp_AssetFileName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName_Statics::NewProp_InDownloadByNameDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|AssetFile" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Downloads an asset file by asset file name.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"AssetFileName\">The name of the asset file to download.</param>\n/// <param name=\"InDownloadByNameDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AssetFileDownloadResult *, DownloadResult).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nDownloads an asset file by asset file name.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"AssetFileName\">The name of the asset file to download.</param>\n<param name=\"InDownloadByNameDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AssetFileDownloadResult *, DownloadResult).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoAssetFileFunction, nullptr, "DownloadByName", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName_Statics::OnlinePicoAssetFileFunction_eventDownloadByName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName_Statics::OnlinePicoAssetFileFunction_eventDownloadByName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById_Statics
	{
		struct OnlinePicoAssetFileFunction_eventDownloadCancelById_Parms
		{
			UObject* WorldContextObject;
			FString AssetFileID;
			FScriptDelegate InDownloadCancelByIDDelegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FStrPropertyParams NewProp_AssetFileID;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InDownloadCancelByIDDelegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventDownloadCancelById_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById_Statics::NewProp_AssetFileID = { "AssetFileID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventDownloadCancelById_Parms, AssetFileID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById_Statics::NewProp_InDownloadCancelByIDDelegate = { "InDownloadCancelByIDDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventDownloadCancelById_Parms, InDownloadCancelByIDDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2807005880
	void Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoAssetFileFunction_eventDownloadCancelById_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoAssetFileFunction_eventDownloadCancelById_Parms), &Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById_Statics::NewProp_AssetFileID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById_Statics::NewProp_InDownloadCancelByIDDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|AssetFile" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Cancels the download of an asset file by asset file ID.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"AssetFileID\">The ID of the asset file to cancel download for.</param>\n/// <param name=\"InDownloadCancelByIDDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AssetFileDownloadCancelResult *, DownloadCancelResult).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nCancels the download of an asset file by asset file ID.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"AssetFileID\">The ID of the asset file to cancel download for.</param>\n<param name=\"InDownloadCancelByIDDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AssetFileDownloadCancelResult *, DownloadCancelResult).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoAssetFileFunction, nullptr, "DownloadCancelById", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById_Statics::OnlinePicoAssetFileFunction_eventDownloadCancelById_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById_Statics::OnlinePicoAssetFileFunction_eventDownloadCancelById_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName_Statics
	{
		struct OnlinePicoAssetFileFunction_eventDownloadCancelByName_Parms
		{
			UObject* WorldContextObject;
			FString AssetFileName;
			FScriptDelegate InDownloadCancelByNameDelegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FStrPropertyParams NewProp_AssetFileName;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InDownloadCancelByNameDelegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventDownloadCancelByName_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName_Statics::NewProp_AssetFileName = { "AssetFileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventDownloadCancelByName_Parms, AssetFileName), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName_Statics::NewProp_InDownloadCancelByNameDelegate = { "InDownloadCancelByNameDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventDownloadCancelByName_Parms, InDownloadCancelByNameDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_AssetFileDownloadCancelResult__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2807005880
	void Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoAssetFileFunction_eventDownloadCancelByName_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoAssetFileFunction_eventDownloadCancelByName_Parms), &Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName_Statics::NewProp_AssetFileName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName_Statics::NewProp_InDownloadCancelByNameDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|AssetFile" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Cancels the download of an asset file by asset file name.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"AssetFileName\">The name of the asset file to cancel download for.</param>\n/// <param name=\"InDownloadCancelByNameDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AssetFileDownloadCancelResult *, DownloadCancelResult).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nCancels the download of an asset file by asset file name.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"AssetFileName\">The name of the asset file to cancel download for.</param>\n<param name=\"InDownloadCancelByNameDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AssetFileDownloadCancelResult *, DownloadCancelResult).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoAssetFileFunction, nullptr, "DownloadCancelByName", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName_Statics::OnlinePicoAssetFileFunction_eventDownloadCancelByName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName_Statics::OnlinePicoAssetFileFunction_eventDownloadCancelByName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileList_Statics
	{
		struct OnlinePicoAssetFileFunction_eventGetAssetFileList_Parms
		{
			UObject* WorldContextObject;
			FScriptDelegate InGetAssetFileListDelegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetAssetFileListDelegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileList_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventGetAssetFileList_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileList_Statics::NewProp_InGetAssetFileListDelegate = { "InGetAssetFileListDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventGetAssetFileList_Parms, InGetAssetFileListDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1201093621
	void Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileList_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoAssetFileFunction_eventGetAssetFileList_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileList_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoAssetFileFunction_eventGetAssetFileList_Parms), &Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileList_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileList_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileList_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileList_Statics::NewProp_InGetAssetFileListDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileList_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileList_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|AssetFile" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets the asset file list.  \n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"InGetAssetFileListDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AssetDetailsArray *, AssetDetailsArray).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets the asset file list.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"InGetAssetFileListDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AssetDetailsArray *, AssetDetailsArray).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoAssetFileFunction, nullptr, "GetAssetFileList", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileList_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileList_Statics::OnlinePicoAssetFileFunction_eventGetAssetFileList_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileList_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileList_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileList_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileList_Statics::OnlinePicoAssetFileFunction_eventGetAssetFileList_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById_Statics
	{
		struct OnlinePicoAssetFileFunction_eventGetAssetFileStatusById_Parms
		{
			UObject* WorldContextObject;
			FString AssetFileID;
			FScriptDelegate InGetAssetFileStatusByIdDelegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FStrPropertyParams NewProp_AssetFileID;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetAssetFileStatusByIdDelegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventGetAssetFileStatusById_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById_Statics::NewProp_AssetFileID = { "AssetFileID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventGetAssetFileStatusById_Parms, AssetFileID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById_Statics::NewProp_InGetAssetFileStatusByIdDelegate = { "InGetAssetFileStatusByIdDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventGetAssetFileStatusById_Parms, InGetAssetFileStatusByIdDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 4056846303
	void Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoAssetFileFunction_eventGetAssetFileStatusById_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoAssetFileFunction_eventGetAssetFileStatusById_Parms), &Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById_Statics::NewProp_AssetFileID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById_Statics::NewProp_InGetAssetFileStatusByIdDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|AssetFile" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets the download status of an asset file by asset file ID.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"AssetFileID\">The ID of the asset file to get the download status for.</param>\n/// <param name=\"InGetAssetFileStatusByIdDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AssetStatus *, AssetFileStatus).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>     \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets the download status of an asset file by asset file ID.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"AssetFileID\">The ID of the asset file to get the download status for.</param>\n<param name=\"InGetAssetFileStatusByIdDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AssetStatus *, AssetFileStatus).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoAssetFileFunction, nullptr, "GetAssetFileStatusById", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById_Statics::OnlinePicoAssetFileFunction_eventGetAssetFileStatusById_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById_Statics::OnlinePicoAssetFileFunction_eventGetAssetFileStatusById_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName_Statics
	{
		struct OnlinePicoAssetFileFunction_eventGetAssetFileStatusByName_Parms
		{
			UObject* WorldContextObject;
			FString AssetFileName;
			FScriptDelegate InGetAssetFileStatusByNameDelegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FStrPropertyParams NewProp_AssetFileName;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetAssetFileStatusByNameDelegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventGetAssetFileStatusByName_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName_Statics::NewProp_AssetFileName = { "AssetFileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventGetAssetFileStatusByName_Parms, AssetFileName), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName_Statics::NewProp_InGetAssetFileStatusByNameDelegate = { "InGetAssetFileStatusByNameDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventGetAssetFileStatusByName_Parms, InGetAssetFileStatusByNameDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileStatus__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 4056846303
	void Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoAssetFileFunction_eventGetAssetFileStatusByName_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoAssetFileFunction_eventGetAssetFileStatusByName_Parms), &Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName_Statics::NewProp_AssetFileName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName_Statics::NewProp_InGetAssetFileStatusByNameDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|AssetFile" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets the download status of an asset file by asset file name.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"AssetFileName\">The name of the asset file to get the download status for.</param>\n/// <param name=\"InGetAssetFileStatusByNameDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AssetStatus *, AssetFileStatus).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>     \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets the download status of an asset file by asset file name.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"AssetFileName\">The name of the asset file to get the download status for.</param>\n<param name=\"InGetAssetFileStatusByNameDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AssetStatus *, AssetFileStatus).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoAssetFileFunction, nullptr, "GetAssetFileStatusByName", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName_Statics::OnlinePicoAssetFileFunction_eventGetAssetFileStatusByName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName_Statics::OnlinePicoAssetFileFunction_eventGetAssetFileStatusByName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage_Statics
	{
		struct OnlinePicoAssetFileFunction_eventGetNextAssetDetailsArrayPage_Parms
		{
			UObject* WorldContextObject;
			UPico_AssetDetailsArray* InAssetDetailsArray;
			FScriptDelegate InGetNextAssetDetailsArrayPageDelegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InAssetDetailsArray;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetNextAssetDetailsArrayPageDelegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventGetNextAssetDetailsArrayPage_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage_Statics::NewProp_InAssetDetailsArray = { "InAssetDetailsArray", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventGetNextAssetDetailsArrayPage_Parms, InAssetDetailsArray), Z_Construct_UClass_UPico_AssetDetailsArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage_Statics::NewProp_InGetNextAssetDetailsArrayPageDelegate = { "InGetNextAssetDetailsArrayPageDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAssetFileFunction_eventGetNextAssetDetailsArrayPage_Parms, InGetNextAssetDetailsArrayPageDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAssetFileList__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1201093621
	void Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoAssetFileFunction_eventGetNextAssetDetailsArrayPage_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoAssetFileFunction_eventGetNextAssetDetailsArrayPage_Parms), &Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage_Statics::NewProp_InAssetDetailsArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage_Statics::NewProp_InGetNextAssetDetailsArrayPageDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|AssetFile" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets the next page of the asset file list.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"InAssetDetailsArray\">The current asset details array object.</param>\n/// <param name=\"InGetNextAssetDetailsArrayPageDelegate\">Will be executed when the request has been completed.\n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AssetDetailsArray *, AssetDetailsArray).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets the next page of the asset file list.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"InAssetDetailsArray\">The current asset details array object.</param>\n<param name=\"InGetNextAssetDetailsArrayPageDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AssetDetailsArray *, AssetDetailsArray).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoAssetFileFunction, nullptr, "GetNextAssetDetailsArrayPage", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage_Statics::OnlinePicoAssetFileFunction_eventGetNextAssetDetailsArrayPage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage_Statics::OnlinePicoAssetFileFunction_eventGetNextAssetDetailsArrayPage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOnlinePicoAssetFileFunction);
	UClass* Z_Construct_UClass_UOnlinePicoAssetFileFunction_NoRegister()
	{
		return UOnlinePicoAssetFileFunction::StaticClass();
	}
	struct Z_Construct_UClass_UOnlinePicoAssetFileFunction_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOnlinePicoAssetFileFunction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoAssetFileFunction_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UOnlinePicoAssetFileFunction_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByID, "DeleteByID" }, // 2275411864
		{ &Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DeleteByName, "DeleteByName" }, // 3432578713
		{ &Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadById, "DownloadById" }, // 2897068623
		{ &Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadByName, "DownloadByName" }, // 3480943739
		{ &Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelById, "DownloadCancelById" }, // 1327324974
		{ &Z_Construct_UFunction_UOnlinePicoAssetFileFunction_DownloadCancelByName, "DownloadCancelByName" }, // 3788239263
		{ &Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileList, "GetAssetFileList" }, // 3858448932
		{ &Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusById, "GetAssetFileStatusById" }, // 2906181723
		{ &Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetAssetFileStatusByName, "GetAssetFileStatusByName" }, // 2556583778
		{ &Z_Construct_UFunction_UOnlinePicoAssetFileFunction_GetNextAssetDetailsArrayPage, "GetNextAssetDetailsArrayPage" }, // 4244938254
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoAssetFileFunction_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoAssetFileFunction_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @defgroup BP_AssetFile BP_AssetFile\n  *  This is the BP_AssetFile group\n  *  @{\n  *//// @brief OnlinePicoAssetFile Blueprint Function class.\n" },
#endif
		{ "IncludePath", "Pico_AssetFile.h" },
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@defgroup BP_AssetFile BP_AssetFile\nThis is the BP_AssetFile group\n@{\n /// @brief OnlinePicoAssetFile Blueprint Function class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOnlinePicoAssetFileFunction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOnlinePicoAssetFileFunction>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOnlinePicoAssetFileFunction_Statics::ClassParams = {
		&UOnlinePicoAssetFileFunction::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoAssetFileFunction_Statics::Class_MetaDataParams), Z_Construct_UClass_UOnlinePicoAssetFileFunction_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UOnlinePicoAssetFileFunction()
	{
		if (!Z_Registration_Info_UClass_UOnlinePicoAssetFileFunction.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOnlinePicoAssetFileFunction.OuterSingleton, Z_Construct_UClass_UOnlinePicoAssetFileFunction_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOnlinePicoAssetFileFunction.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UOnlinePicoAssetFileFunction>()
	{
		return UOnlinePicoAssetFileFunction::StaticClass();
	}
	UOnlinePicoAssetFileFunction::UOnlinePicoAssetFileFunction(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOnlinePicoAssetFileFunction);
	UOnlinePicoAssetFileFunction::~UOnlinePicoAssetFileFunction() {}
	DEFINE_FUNCTION(UPico_AssetFileDeleteResult::execGetSuccess)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetSuccess();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetFileDeleteResult::execGetFilePath)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetFilePath();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetFileDeleteResult::execGetAssetId)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetAssetId();
		P_NATIVE_END;
	}
	void UPico_AssetFileDeleteResult::StaticRegisterNativesUPico_AssetFileDeleteResult()
	{
		UClass* Class = UPico_AssetFileDeleteResult::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAssetId", &UPico_AssetFileDeleteResult::execGetAssetId },
			{ "GetFilePath", &UPico_AssetFileDeleteResult::execGetFilePath },
			{ "GetSuccess", &UPico_AssetFileDeleteResult::execGetSuccess },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetAssetId_Statics
	{
		struct Pico_AssetFileDeleteResult_eventGetAssetId_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetAssetId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetFileDeleteResult_eventGetAssetId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetAssetId_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetAssetId_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetAssetId_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Delete Result" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The ID of the DLC file. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The ID of the DLC file." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetAssetId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetFileDeleteResult, nullptr, "GetAssetId", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetAssetId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetAssetId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetAssetId_Statics::Pico_AssetFileDeleteResult_eventGetAssetId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetAssetId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetAssetId_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetAssetId_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetAssetId_Statics::Pico_AssetFileDeleteResult_eventGetAssetId_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetAssetId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetAssetId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetFilePath_Statics
	{
		struct Pico_AssetFileDeleteResult_eventGetFilePath_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetFilePath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetFileDeleteResult_eventGetFilePath_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetFilePath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetFilePath_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetFilePath_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Delete Result" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief The path to the DLC file.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The path to the DLC file." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetFilePath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetFileDeleteResult, nullptr, "GetFilePath", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetFilePath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetFilePath_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetFilePath_Statics::Pico_AssetFileDeleteResult_eventGetFilePath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetFilePath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetFilePath_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetFilePath_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetFilePath_Statics::Pico_AssetFileDeleteResult_eventGetFilePath_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetFilePath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetFilePath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetSuccess_Statics
	{
		struct Pico_AssetFileDeleteResult_eventGetSuccess_Parms
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
	void Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetSuccess_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_AssetFileDeleteResult_eventGetSuccess_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetSuccess_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_AssetFileDeleteResult_eventGetSuccess_Parms), &Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetSuccess_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetSuccess_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetSuccess_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetSuccess_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Delete Result" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief Whether the DLC file is deleted successfully.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Whether the DLC file is deleted successfully." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetSuccess_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetFileDeleteResult, nullptr, "GetSuccess", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetSuccess_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetSuccess_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetSuccess_Statics::Pico_AssetFileDeleteResult_eventGetSuccess_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetSuccess_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetSuccess_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetSuccess_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetSuccess_Statics::Pico_AssetFileDeleteResult_eventGetSuccess_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetSuccess()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetSuccess_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_AssetFileDeleteResult);
	UClass* Z_Construct_UClass_UPico_AssetFileDeleteResult_NoRegister()
	{
		return UPico_AssetFileDeleteResult::StaticClass();
	}
	struct Z_Construct_UClass_UPico_AssetFileDeleteResult_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_AssetFileDeleteResult_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetFileDeleteResult_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_AssetFileDeleteResult_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetAssetId, "GetAssetId" }, // 1427777753
		{ &Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetFilePath, "GetFilePath" }, // 211936518
		{ &Z_Construct_UFunction_UPico_AssetFileDeleteResult_GetSuccess, "GetSuccess" }, // 2728534280
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetFileDeleteResult_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_AssetFileDeleteResult_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @} *//// @brief UPico_AssetFileDeleteResult class.\n" },
#endif
		{ "IncludePath", "Pico_AssetFile.h" },
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@} /// @brief UPico_AssetFileDeleteResult class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_AssetFileDeleteResult_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_AssetFileDeleteResult>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_AssetFileDeleteResult_Statics::ClassParams = {
		&UPico_AssetFileDeleteResult::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetFileDeleteResult_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_AssetFileDeleteResult_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPico_AssetFileDeleteResult()
	{
		if (!Z_Registration_Info_UClass_UPico_AssetFileDeleteResult.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_AssetFileDeleteResult.OuterSingleton, Z_Construct_UClass_UPico_AssetFileDeleteResult_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_AssetFileDeleteResult.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_AssetFileDeleteResult>()
	{
		return UPico_AssetFileDeleteResult::StaticClass();
	}
	UPico_AssetFileDeleteResult::UPico_AssetFileDeleteResult(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_AssetFileDeleteResult);
	UPico_AssetFileDeleteResult::~UPico_AssetFileDeleteResult() {}
	DEFINE_FUNCTION(UPico_AssetDetails::execGetIapIconUrl)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetIapIconUrl();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetDetails::execGetIapDescription)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetIapDescription();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetDetails::execGetIapCurrency)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetIapCurrency();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetDetails::execGetIapPrice)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetIapPrice();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetDetails::execGetIapName)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetIapName();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetDetails::execGetIapSku)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetIapSku();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetDetails::execGetVersion)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetVersion();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetDetails::execGetFilename)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetFilename();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetDetails::execGetMetadata)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetMetadata();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetDetails::execGetIapStatus)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetIapStatus();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetDetails::execGetDownloadStatus)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetDownloadStatus();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetDetails::execGetAssetType)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetAssetType();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetDetails::execGetFilePath)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetFilePath();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetDetails::execGetAssetId)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetAssetId();
		P_NATIVE_END;
	}
	void UPico_AssetDetails::StaticRegisterNativesUPico_AssetDetails()
	{
		UClass* Class = UPico_AssetDetails::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAssetId", &UPico_AssetDetails::execGetAssetId },
			{ "GetAssetType", &UPico_AssetDetails::execGetAssetType },
			{ "GetDownloadStatus", &UPico_AssetDetails::execGetDownloadStatus },
			{ "GetFilename", &UPico_AssetDetails::execGetFilename },
			{ "GetFilePath", &UPico_AssetDetails::execGetFilePath },
			{ "GetIapCurrency", &UPico_AssetDetails::execGetIapCurrency },
			{ "GetIapDescription", &UPico_AssetDetails::execGetIapDescription },
			{ "GetIapIconUrl", &UPico_AssetDetails::execGetIapIconUrl },
			{ "GetIapName", &UPico_AssetDetails::execGetIapName },
			{ "GetIapPrice", &UPico_AssetDetails::execGetIapPrice },
			{ "GetIapSku", &UPico_AssetDetails::execGetIapSku },
			{ "GetIapStatus", &UPico_AssetDetails::execGetIapStatus },
			{ "GetMetadata", &UPico_AssetDetails::execGetMetadata },
			{ "GetVersion", &UPico_AssetDetails::execGetVersion },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_AssetDetails_GetAssetId_Statics
	{
		struct Pico_AssetDetails_eventGetAssetId_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetDetails_GetAssetId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetDetails_eventGetAssetId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetDetails_GetAssetId_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetDetails_GetAssetId_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetDetails_GetAssetId_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Asset Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The unique identifier of DLC file.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The unique identifier of DLC file." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetDetails_GetAssetId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetDetails, nullptr, "GetAssetId", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetDetails_GetAssetId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetAssetId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetAssetId_Statics::Pico_AssetDetails_eventGetAssetId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetAssetId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetDetails_GetAssetId_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetAssetId_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetAssetId_Statics::Pico_AssetDetails_eventGetAssetId_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetDetails_GetAssetId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetDetails_GetAssetId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetDetails_GetAssetType_Statics
	{
		struct Pico_AssetDetails_eventGetAssetType_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetDetails_GetAssetType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetDetails_eventGetAssetType_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetDetails_GetAssetType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetDetails_GetAssetType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetDetails_GetAssetType_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Asset Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Some DLC files can be displayed in the PICO Store. Now it has two values: `default` or `store`.\n     * You can refer to \\ref AssetType for details.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Some DLC files can be displayed in the PICO Store. Now it has two values: `default` or `store`.\nYou can refer to \\ref AssetType for details." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetDetails_GetAssetType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetDetails, nullptr, "GetAssetType", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetDetails_GetAssetType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetAssetType_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetAssetType_Statics::Pico_AssetDetails_eventGetAssetType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetAssetType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetDetails_GetAssetType_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetAssetType_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetAssetType_Statics::Pico_AssetDetails_eventGetAssetType_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetDetails_GetAssetType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetDetails_GetAssetType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetDetails_GetDownloadStatus_Statics
	{
		struct Pico_AssetDetails_eventGetDownloadStatus_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetDetails_GetDownloadStatus_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetDetails_eventGetDownloadStatus_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetDetails_GetDownloadStatus_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetDetails_GetDownloadStatus_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetDetails_GetDownloadStatus_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Asset Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief One of `downloaded`, `available`, and `in-progress`. You can refer to \\ref DownloadStatus for details.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief One of `downloaded`, `available`, and `in-progress`. You can refer to \\ref DownloadStatus for details." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetDetails_GetDownloadStatus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetDetails, nullptr, "GetDownloadStatus", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetDetails_GetDownloadStatus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetDownloadStatus_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetDownloadStatus_Statics::Pico_AssetDetails_eventGetDownloadStatus_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetDownloadStatus_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetDetails_GetDownloadStatus_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetDownloadStatus_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetDownloadStatus_Statics::Pico_AssetDetails_eventGetDownloadStatus_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetDetails_GetDownloadStatus()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetDetails_GetDownloadStatus_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetDetails_GetFilename_Statics
	{
		struct Pico_AssetDetails_eventGetFilename_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetDetails_GetFilename_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetDetails_eventGetFilename_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetDetails_GetFilename_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetDetails_GetFilename_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetDetails_GetFilename_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Asset Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The name of the DLC file.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The name of the DLC file." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetDetails_GetFilename_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetDetails, nullptr, "GetFilename", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetDetails_GetFilename_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetFilename_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetFilename_Statics::Pico_AssetDetails_eventGetFilename_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetFilename_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetDetails_GetFilename_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetFilename_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetFilename_Statics::Pico_AssetDetails_eventGetFilename_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetDetails_GetFilename()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetDetails_GetFilename_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetDetails_GetFilePath_Statics
	{
		struct Pico_AssetDetails_eventGetFilePath_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetDetails_GetFilePath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetDetails_eventGetFilePath_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetDetails_GetFilePath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetDetails_GetFilePath_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetDetails_GetFilePath_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Asset Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The path to the downloaded DLC file. For a non-downloaded DLC file, this field will be empty.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The path to the downloaded DLC file. For a non-downloaded DLC file, this field will be empty." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetDetails_GetFilePath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetDetails, nullptr, "GetFilePath", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetDetails_GetFilePath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetFilePath_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetFilePath_Statics::Pico_AssetDetails_eventGetFilePath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetFilePath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetDetails_GetFilePath_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetFilePath_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetFilePath_Statics::Pico_AssetDetails_eventGetFilePath_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetDetails_GetFilePath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetDetails_GetFilePath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetDetails_GetIapCurrency_Statics
	{
		struct Pico_AssetDetails_eventGetIapCurrency_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetDetails_GetIapCurrency_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetDetails_eventGetIapCurrency_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetDetails_GetIapCurrency_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetDetails_GetIapCurrency_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetDetails_GetIapCurrency_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Asset Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The currency required for purchasing the DLC file.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The currency required for purchasing the DLC file." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetDetails_GetIapCurrency_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetDetails, nullptr, "GetIapCurrency", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetDetails_GetIapCurrency_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetIapCurrency_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetIapCurrency_Statics::Pico_AssetDetails_eventGetIapCurrency_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetIapCurrency_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetDetails_GetIapCurrency_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetIapCurrency_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetIapCurrency_Statics::Pico_AssetDetails_eventGetIapCurrency_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetDetails_GetIapCurrency()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetDetails_GetIapCurrency_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetDetails_GetIapDescription_Statics
	{
		struct Pico_AssetDetails_eventGetIapDescription_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetDetails_GetIapDescription_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetDetails_eventGetIapDescription_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetDetails_GetIapDescription_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetDetails_GetIapDescription_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetDetails_GetIapDescription_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Asset Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The description of the in-app product that the DLC file associated with.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The description of the in-app product that the DLC file associated with." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetDetails_GetIapDescription_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetDetails, nullptr, "GetIapDescription", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetDetails_GetIapDescription_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetIapDescription_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetIapDescription_Statics::Pico_AssetDetails_eventGetIapDescription_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetIapDescription_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetDetails_GetIapDescription_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetIapDescription_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetIapDescription_Statics::Pico_AssetDetails_eventGetIapDescription_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetDetails_GetIapDescription()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetDetails_GetIapDescription_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetDetails_GetIapIconUrl_Statics
	{
		struct Pico_AssetDetails_eventGetIapIconUrl_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetDetails_GetIapIconUrl_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetDetails_eventGetIapIconUrl_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetDetails_GetIapIconUrl_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetDetails_GetIapIconUrl_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetDetails_GetIapIconUrl_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Asset Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The icon of the in-app product that the DLC file associated with.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The icon of the in-app product that the DLC file associated with." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetDetails_GetIapIconUrl_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetDetails, nullptr, "GetIapIconUrl", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetDetails_GetIapIconUrl_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetIapIconUrl_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetIapIconUrl_Statics::Pico_AssetDetails_eventGetIapIconUrl_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetIapIconUrl_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetDetails_GetIapIconUrl_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetIapIconUrl_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetIapIconUrl_Statics::Pico_AssetDetails_eventGetIapIconUrl_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetDetails_GetIapIconUrl()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetDetails_GetIapIconUrl_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetDetails_GetIapName_Statics
	{
		struct Pico_AssetDetails_eventGetIapName_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetDetails_GetIapName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetDetails_eventGetIapName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetDetails_GetIapName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetDetails_GetIapName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetDetails_GetIapName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Asset Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The name of the in-app product that the DLC fiel associated with.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The name of the in-app product that the DLC fiel associated with." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetDetails_GetIapName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetDetails, nullptr, "GetIapName", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetDetails_GetIapName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetIapName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetIapName_Statics::Pico_AssetDetails_eventGetIapName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetIapName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetDetails_GetIapName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetIapName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetIapName_Statics::Pico_AssetDetails_eventGetIapName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetDetails_GetIapName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetDetails_GetIapName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetDetails_GetIapPrice_Statics
	{
		struct Pico_AssetDetails_eventGetIapPrice_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetDetails_GetIapPrice_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetDetails_eventGetIapPrice_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetDetails_GetIapPrice_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetDetails_GetIapPrice_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetDetails_GetIapPrice_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Asset Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The price of this DLC file.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The price of this DLC file." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetDetails_GetIapPrice_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetDetails, nullptr, "GetIapPrice", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetDetails_GetIapPrice_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetIapPrice_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetIapPrice_Statics::Pico_AssetDetails_eventGetIapPrice_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetIapPrice_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetDetails_GetIapPrice_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetIapPrice_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetIapPrice_Statics::Pico_AssetDetails_eventGetIapPrice_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetDetails_GetIapPrice()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetDetails_GetIapPrice_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetDetails_GetIapSku_Statics
	{
		struct Pico_AssetDetails_eventGetIapSku_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetDetails_GetIapSku_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetDetails_eventGetIapSku_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetDetails_GetIapSku_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetDetails_GetIapSku_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetDetails_GetIapSku_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Asset Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The SKU of the in-app product that the DLC file associated with.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The SKU of the in-app product that the DLC file associated with." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetDetails_GetIapSku_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetDetails, nullptr, "GetIapSku", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetDetails_GetIapSku_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetIapSku_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetIapSku_Statics::Pico_AssetDetails_eventGetIapSku_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetIapSku_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetDetails_GetIapSku_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetIapSku_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetIapSku_Statics::Pico_AssetDetails_eventGetIapSku_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetDetails_GetIapSku()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetDetails_GetIapSku_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetDetails_GetIapStatus_Statics
	{
		struct Pico_AssetDetails_eventGetIapStatus_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetDetails_GetIapStatus_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetDetails_eventGetIapStatus_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetDetails_GetIapStatus_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetDetails_GetIapStatus_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetDetails_GetIapStatus_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Asset Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief One of `entitled`, `not-entitled`. You can refer to \\ref IapStatus for details.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief One of `entitled`, `not-entitled`. You can refer to \\ref IapStatus for details." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetDetails_GetIapStatus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetDetails, nullptr, "GetIapStatus", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetDetails_GetIapStatus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetIapStatus_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetIapStatus_Statics::Pico_AssetDetails_eventGetIapStatus_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetIapStatus_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetDetails_GetIapStatus_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetIapStatus_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetIapStatus_Statics::Pico_AssetDetails_eventGetIapStatus_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetDetails_GetIapStatus()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetDetails_GetIapStatus_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetDetails_GetMetadata_Statics
	{
		struct Pico_AssetDetails_eventGetMetadata_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetDetails_GetMetadata_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetDetails_eventGetMetadata_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetDetails_GetMetadata_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetDetails_GetMetadata_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetDetails_GetMetadata_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Asset Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The meta info of the DLC file.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The meta info of the DLC file." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetDetails_GetMetadata_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetDetails, nullptr, "GetMetadata", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetDetails_GetMetadata_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetMetadata_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetMetadata_Statics::Pico_AssetDetails_eventGetMetadata_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetMetadata_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetDetails_GetMetadata_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetMetadata_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetMetadata_Statics::Pico_AssetDetails_eventGetMetadata_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetDetails_GetMetadata()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetDetails_GetMetadata_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetDetails_GetVersion_Statics
	{
		struct Pico_AssetDetails_eventGetVersion_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_AssetDetails_GetVersion_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetDetails_eventGetVersion_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetDetails_GetVersion_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetDetails_GetVersion_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetDetails_GetVersion_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Asset Details" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The version of the DLC file.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The version of the DLC file." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetDetails_GetVersion_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetDetails, nullptr, "GetVersion", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetDetails_GetVersion_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetVersion_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetVersion_Statics::Pico_AssetDetails_eventGetVersion_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetVersion_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetDetails_GetVersion_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetails_GetVersion_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetDetails_GetVersion_Statics::Pico_AssetDetails_eventGetVersion_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetDetails_GetVersion()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetDetails_GetVersion_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_AssetDetails);
	UClass* Z_Construct_UClass_UPico_AssetDetails_NoRegister()
	{
		return UPico_AssetDetails::StaticClass();
	}
	struct Z_Construct_UClass_UPico_AssetDetails_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_AssetDetails_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetDetails_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_AssetDetails_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_AssetDetails_GetAssetId, "GetAssetId" }, // 1005943443
		{ &Z_Construct_UFunction_UPico_AssetDetails_GetAssetType, "GetAssetType" }, // 860466474
		{ &Z_Construct_UFunction_UPico_AssetDetails_GetDownloadStatus, "GetDownloadStatus" }, // 2925799535
		{ &Z_Construct_UFunction_UPico_AssetDetails_GetFilename, "GetFilename" }, // 1954353032
		{ &Z_Construct_UFunction_UPico_AssetDetails_GetFilePath, "GetFilePath" }, // 287155530
		{ &Z_Construct_UFunction_UPico_AssetDetails_GetIapCurrency, "GetIapCurrency" }, // 569444880
		{ &Z_Construct_UFunction_UPico_AssetDetails_GetIapDescription, "GetIapDescription" }, // 4027534265
		{ &Z_Construct_UFunction_UPico_AssetDetails_GetIapIconUrl, "GetIapIconUrl" }, // 2955553047
		{ &Z_Construct_UFunction_UPico_AssetDetails_GetIapName, "GetIapName" }, // 2464123673
		{ &Z_Construct_UFunction_UPico_AssetDetails_GetIapPrice, "GetIapPrice" }, // 2070435074
		{ &Z_Construct_UFunction_UPico_AssetDetails_GetIapSku, "GetIapSku" }, // 3612503661
		{ &Z_Construct_UFunction_UPico_AssetDetails_GetIapStatus, "GetIapStatus" }, // 1486826031
		{ &Z_Construct_UFunction_UPico_AssetDetails_GetMetadata, "GetMetadata" }, // 1940144339
		{ &Z_Construct_UFunction_UPico_AssetDetails_GetVersion, "GetVersion" }, // 2347023438
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetDetails_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_AssetDetails_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_AssetDetails class.\n" },
#endif
		{ "IncludePath", "Pico_AssetFile.h" },
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_AssetDetails class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_AssetDetails_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_AssetDetails>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_AssetDetails_Statics::ClassParams = {
		&UPico_AssetDetails::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetDetails_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_AssetDetails_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPico_AssetDetails()
	{
		if (!Z_Registration_Info_UClass_UPico_AssetDetails.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_AssetDetails.OuterSingleton, Z_Construct_UClass_UPico_AssetDetails_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_AssetDetails.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_AssetDetails>()
	{
		return UPico_AssetDetails::StaticClass();
	}
	UPico_AssetDetails::UPico_AssetDetails(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_AssetDetails);
	UPico_AssetDetails::~UPico_AssetDetails() {}
	DEFINE_FUNCTION(UPico_AssetDetailsArray::execGetNextPageParam)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetNextPageParam();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetDetailsArray::execGetHasNextPage)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetHasNextPage();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetDetailsArray::execGetSize)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetSize();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetDetailsArray::execGetElement)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPico_AssetDetails**)Z_Param__Result=P_THIS->GetElement(Z_Param_Index);
		P_NATIVE_END;
	}
	void UPico_AssetDetailsArray::StaticRegisterNativesUPico_AssetDetailsArray()
	{
		UClass* Class = UPico_AssetDetailsArray::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetElement", &UPico_AssetDetailsArray::execGetElement },
			{ "GetHasNextPage", &UPico_AssetDetailsArray::execGetHasNextPage },
			{ "GetNextPageParam", &UPico_AssetDetailsArray::execGetNextPageParam },
			{ "GetSize", &UPico_AssetDetailsArray::execGetSize },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_AssetDetailsArray_GetElement_Statics
	{
		struct Pico_AssetDetailsArray_eventGetElement_Parms
		{
			int32 Index;
			UPico_AssetDetails* ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_AssetDetailsArray_GetElement_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetDetailsArray_eventGetElement_Parms, Index), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPico_AssetDetailsArray_GetElement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetDetailsArray_eventGetElement_Parms, ReturnValue), Z_Construct_UClass_UPico_AssetDetails_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetDetailsArray_GetElement_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetDetailsArray_GetElement_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetDetailsArray_GetElement_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetDetailsArray_GetElement_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Asset Details Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get AssetDetailsArray element form Index.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get AssetDetailsArray element form Index." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetDetailsArray_GetElement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetDetailsArray, nullptr, "GetElement", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetDetailsArray_GetElement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetailsArray_GetElement_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetDetailsArray_GetElement_Statics::Pico_AssetDetailsArray_eventGetElement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetailsArray_GetElement_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetDetailsArray_GetElement_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetailsArray_GetElement_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetDetailsArray_GetElement_Statics::Pico_AssetDetailsArray_eventGetElement_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetDetailsArray_GetElement()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetDetailsArray_GetElement_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetDetailsArray_GetHasNextPage_Statics
	{
		struct Pico_AssetDetailsArray_eventGetHasNextPage_Parms
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
	void Z_Construct_UFunction_UPico_AssetDetailsArray_GetHasNextPage_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_AssetDetailsArray_eventGetHasNextPage_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_AssetDetailsArray_GetHasNextPage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_AssetDetailsArray_eventGetHasNextPage_Parms), &Z_Construct_UFunction_UPico_AssetDetailsArray_GetHasNextPage_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetDetailsArray_GetHasNextPage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetDetailsArray_GetHasNextPage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetDetailsArray_GetHasNextPage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Asset Details Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get whether the list has the next page.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get whether the list has the next page." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetDetailsArray_GetHasNextPage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetDetailsArray, nullptr, "GetHasNextPage", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetDetailsArray_GetHasNextPage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetailsArray_GetHasNextPage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetDetailsArray_GetHasNextPage_Statics::Pico_AssetDetailsArray_eventGetHasNextPage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetailsArray_GetHasNextPage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetDetailsArray_GetHasNextPage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetailsArray_GetHasNextPage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetDetailsArray_GetHasNextPage_Statics::Pico_AssetDetailsArray_eventGetHasNextPage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetDetailsArray_GetHasNextPage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetDetailsArray_GetHasNextPage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetDetailsArray_GetNextPageParam_Statics
	{
		struct Pico_AssetDetailsArray_eventGetNextPageParam_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetDetailsArray_GetNextPageParam_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetDetailsArray_eventGetNextPageParam_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetDetailsArray_GetNextPageParam_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetDetailsArray_GetNextPageParam_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetDetailsArray_GetNextPageParam_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Asset Details Array" },
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetDetailsArray_GetNextPageParam_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetDetailsArray, nullptr, "GetNextPageParam", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetDetailsArray_GetNextPageParam_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetailsArray_GetNextPageParam_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetDetailsArray_GetNextPageParam_Statics::Pico_AssetDetailsArray_eventGetNextPageParam_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetailsArray_GetNextPageParam_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetDetailsArray_GetNextPageParam_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetailsArray_GetNextPageParam_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetDetailsArray_GetNextPageParam_Statics::Pico_AssetDetailsArray_eventGetNextPageParam_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetDetailsArray_GetNextPageParam()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetDetailsArray_GetNextPageParam_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetDetailsArray_GetSize_Statics
	{
		struct Pico_AssetDetailsArray_eventGetSize_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_AssetDetailsArray_GetSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetDetailsArray_eventGetSize_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetDetailsArray_GetSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetDetailsArray_GetSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetDetailsArray_GetSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Asset Details Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get the size of AssetDetailsArray .*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get the size of AssetDetailsArray ." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetDetailsArray_GetSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetDetailsArray, nullptr, "GetSize", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetDetailsArray_GetSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetailsArray_GetSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetDetailsArray_GetSize_Statics::Pico_AssetDetailsArray_eventGetSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetailsArray_GetSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetDetailsArray_GetSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetDetailsArray_GetSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetDetailsArray_GetSize_Statics::Pico_AssetDetailsArray_eventGetSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetDetailsArray_GetSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetDetailsArray_GetSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_AssetDetailsArray);
	UClass* Z_Construct_UClass_UPico_AssetDetailsArray_NoRegister()
	{
		return UPico_AssetDetailsArray::StaticClass();
	}
	struct Z_Construct_UClass_UPico_AssetDetailsArray_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AssetDetailsArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AssetDetailsArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_AssetDetailsArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_AssetDetailsArray_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetDetailsArray_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_AssetDetailsArray_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_AssetDetailsArray_GetElement, "GetElement" }, // 3603307334
		{ &Z_Construct_UFunction_UPico_AssetDetailsArray_GetHasNextPage, "GetHasNextPage" }, // 2791721855
		{ &Z_Construct_UFunction_UPico_AssetDetailsArray_GetNextPageParam, "GetNextPageParam" }, // 2602492450
		{ &Z_Construct_UFunction_UPico_AssetDetailsArray_GetSize, "GetSize" }, // 1494764114
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetDetailsArray_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_AssetDetailsArray_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_AssetDetailsArray class.\n" },
#endif
		{ "IncludePath", "Pico_AssetFile.h" },
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_AssetDetailsArray class." },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPico_AssetDetailsArray_Statics::NewProp_AssetDetailsArray_Inner = { "AssetDetailsArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UPico_AssetDetails_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_AssetDetailsArray_Statics::NewProp_AssetDetailsArray_MetaData[] = {
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPico_AssetDetailsArray_Statics::NewProp_AssetDetailsArray = { "AssetDetailsArray", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPico_AssetDetailsArray, AssetDetailsArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetDetailsArray_Statics::NewProp_AssetDetailsArray_MetaData), Z_Construct_UClass_UPico_AssetDetailsArray_Statics::NewProp_AssetDetailsArray_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPico_AssetDetailsArray_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_AssetDetailsArray_Statics::NewProp_AssetDetailsArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_AssetDetailsArray_Statics::NewProp_AssetDetailsArray,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_AssetDetailsArray_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_AssetDetailsArray>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_AssetDetailsArray_Statics::ClassParams = {
		&UPico_AssetDetailsArray::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPico_AssetDetailsArray_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetDetailsArray_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetDetailsArray_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_AssetDetailsArray_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetDetailsArray_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPico_AssetDetailsArray()
	{
		if (!Z_Registration_Info_UClass_UPico_AssetDetailsArray.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_AssetDetailsArray.OuterSingleton, Z_Construct_UClass_UPico_AssetDetailsArray_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_AssetDetailsArray.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_AssetDetailsArray>()
	{
		return UPico_AssetDetailsArray::StaticClass();
	}
	UPico_AssetDetailsArray::UPico_AssetDetailsArray(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_AssetDetailsArray);
	UPico_AssetDetailsArray::~UPico_AssetDetailsArray() {}
	DEFINE_FUNCTION(UPico_AssetFileDownloadCancelResult::execGetSuccess)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetSuccess();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetFileDownloadCancelResult::execGetFilePath)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetFilePath();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetFileDownloadCancelResult::execGetAssetId)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetAssetId();
		P_NATIVE_END;
	}
	void UPico_AssetFileDownloadCancelResult::StaticRegisterNativesUPico_AssetFileDownloadCancelResult()
	{
		UClass* Class = UPico_AssetFileDownloadCancelResult::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAssetId", &UPico_AssetFileDownloadCancelResult::execGetAssetId },
			{ "GetFilePath", &UPico_AssetFileDownloadCancelResult::execGetFilePath },
			{ "GetSuccess", &UPico_AssetFileDownloadCancelResult::execGetSuccess },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetAssetId_Statics
	{
		struct Pico_AssetFileDownloadCancelResult_eventGetAssetId_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetAssetId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetFileDownloadCancelResult_eventGetAssetId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetAssetId_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetAssetId_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetAssetId_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Download Cancel Result" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The ID of the DLC file. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The ID of the DLC file." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetAssetId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetFileDownloadCancelResult, nullptr, "GetAssetId", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetAssetId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetAssetId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetAssetId_Statics::Pico_AssetFileDownloadCancelResult_eventGetAssetId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetAssetId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetAssetId_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetAssetId_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetAssetId_Statics::Pico_AssetFileDownloadCancelResult_eventGetAssetId_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetAssetId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetAssetId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetFilePath_Statics
	{
		struct Pico_AssetFileDownloadCancelResult_eventGetFilePath_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetFilePath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetFileDownloadCancelResult_eventGetFilePath_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetFilePath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetFilePath_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetFilePath_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Download Cancel Result" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The path to the DLC file. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The path to the DLC file." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetFilePath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetFileDownloadCancelResult, nullptr, "GetFilePath", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetFilePath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetFilePath_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetFilePath_Statics::Pico_AssetFileDownloadCancelResult_eventGetFilePath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetFilePath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetFilePath_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetFilePath_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetFilePath_Statics::Pico_AssetFileDownloadCancelResult_eventGetFilePath_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetFilePath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetFilePath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetSuccess_Statics
	{
		struct Pico_AssetFileDownloadCancelResult_eventGetSuccess_Parms
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
	void Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetSuccess_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_AssetFileDownloadCancelResult_eventGetSuccess_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetSuccess_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_AssetFileDownloadCancelResult_eventGetSuccess_Parms), &Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetSuccess_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetSuccess_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetSuccess_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetSuccess_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Download Cancel Result" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Whether the download is successfully canceled. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Whether the download is successfully canceled." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetSuccess_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetFileDownloadCancelResult, nullptr, "GetSuccess", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetSuccess_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetSuccess_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetSuccess_Statics::Pico_AssetFileDownloadCancelResult_eventGetSuccess_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetSuccess_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetSuccess_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetSuccess_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetSuccess_Statics::Pico_AssetFileDownloadCancelResult_eventGetSuccess_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetSuccess()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetSuccess_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_AssetFileDownloadCancelResult);
	UClass* Z_Construct_UClass_UPico_AssetFileDownloadCancelResult_NoRegister()
	{
		return UPico_AssetFileDownloadCancelResult::StaticClass();
	}
	struct Z_Construct_UClass_UPico_AssetFileDownloadCancelResult_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_AssetFileDownloadCancelResult_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetFileDownloadCancelResult_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_AssetFileDownloadCancelResult_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetAssetId, "GetAssetId" }, // 2924547682
		{ &Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetFilePath, "GetFilePath" }, // 2056052650
		{ &Z_Construct_UFunction_UPico_AssetFileDownloadCancelResult_GetSuccess, "GetSuccess" }, // 2123034205
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetFileDownloadCancelResult_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_AssetFileDownloadCancelResult_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_AssetFileDownloadCancelResult class.\n" },
#endif
		{ "IncludePath", "Pico_AssetFile.h" },
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_AssetFileDownloadCancelResult class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_AssetFileDownloadCancelResult_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_AssetFileDownloadCancelResult>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_AssetFileDownloadCancelResult_Statics::ClassParams = {
		&UPico_AssetFileDownloadCancelResult::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetFileDownloadCancelResult_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_AssetFileDownloadCancelResult_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPico_AssetFileDownloadCancelResult()
	{
		if (!Z_Registration_Info_UClass_UPico_AssetFileDownloadCancelResult.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_AssetFileDownloadCancelResult.OuterSingleton, Z_Construct_UClass_UPico_AssetFileDownloadCancelResult_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_AssetFileDownloadCancelResult.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_AssetFileDownloadCancelResult>()
	{
		return UPico_AssetFileDownloadCancelResult::StaticClass();
	}
	UPico_AssetFileDownloadCancelResult::UPico_AssetFileDownloadCancelResult(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_AssetFileDownloadCancelResult);
	UPico_AssetFileDownloadCancelResult::~UPico_AssetFileDownloadCancelResult() {}
	DEFINE_FUNCTION(UPico_AssetFileDownloadUpdate::execGetCompleteStatus)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EAssetFileDownloadCompleteStatus*)Z_Param__Result=P_THIS->GetCompleteStatus();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetFileDownloadUpdate::execGetBytesTransferred)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int64*)Z_Param__Result=P_THIS->GetBytesTransferred();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetFileDownloadUpdate::execGetBytesTotal)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int64*)Z_Param__Result=P_THIS->GetBytesTotal();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetFileDownloadUpdate::execGetAssetId)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetAssetId();
		P_NATIVE_END;
	}
	void UPico_AssetFileDownloadUpdate::StaticRegisterNativesUPico_AssetFileDownloadUpdate()
	{
		UClass* Class = UPico_AssetFileDownloadUpdate::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAssetId", &UPico_AssetFileDownloadUpdate::execGetAssetId },
			{ "GetBytesTotal", &UPico_AssetFileDownloadUpdate::execGetBytesTotal },
			{ "GetBytesTransferred", &UPico_AssetFileDownloadUpdate::execGetBytesTransferred },
			{ "GetCompleteStatus", &UPico_AssetFileDownloadUpdate::execGetCompleteStatus },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetAssetId_Statics
	{
		struct Pico_AssetFileDownloadUpdate_eventGetAssetId_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetAssetId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetFileDownloadUpdate_eventGetAssetId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetAssetId_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetAssetId_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetAssetId_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Download Update" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The ID of the DLC file. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The ID of the DLC file." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetAssetId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetFileDownloadUpdate, nullptr, "GetAssetId", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetAssetId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetAssetId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetAssetId_Statics::Pico_AssetFileDownloadUpdate_eventGetAssetId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetAssetId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetAssetId_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetAssetId_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetAssetId_Statics::Pico_AssetFileDownloadUpdate_eventGetAssetId_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetAssetId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetAssetId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTotal_Statics
	{
		struct Pico_AssetFileDownloadUpdate_eventGetBytesTotal_Parms
		{
			int64 ReturnValue;
		};
		static const UECodeGen_Private::FInt64PropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTotal_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetFileDownloadUpdate_eventGetBytesTotal_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTotal_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTotal_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTotal_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Download Update" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The total bytes of the DLC file.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The total bytes of the DLC file." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTotal_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetFileDownloadUpdate, nullptr, "GetBytesTotal", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTotal_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTotal_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTotal_Statics::Pico_AssetFileDownloadUpdate_eventGetBytesTotal_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTotal_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTotal_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTotal_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTotal_Statics::Pico_AssetFileDownloadUpdate_eventGetBytesTotal_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTotal()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTotal_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTransferred_Statics
	{
		struct Pico_AssetFileDownloadUpdate_eventGetBytesTransferred_Parms
		{
			int64 ReturnValue;
		};
		static const UECodeGen_Private::FInt64PropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTransferred_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetFileDownloadUpdate_eventGetBytesTransferred_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTransferred_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTransferred_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTransferred_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Download Update" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The transferred bytes of the DLC file. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The transferred bytes of the DLC file." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTransferred_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetFileDownloadUpdate, nullptr, "GetBytesTransferred", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTransferred_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTransferred_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTransferred_Statics::Pico_AssetFileDownloadUpdate_eventGetBytesTransferred_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTransferred_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTransferred_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTransferred_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTransferred_Statics::Pico_AssetFileDownloadUpdate_eventGetBytesTransferred_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTransferred()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTransferred_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetCompleteStatus_Statics
	{
		struct Pico_AssetFileDownloadUpdate_eventGetCompleteStatus_Parms
		{
			EAssetFileDownloadCompleteStatus ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetCompleteStatus_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetCompleteStatus_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetFileDownloadUpdate_eventGetCompleteStatus_Parms, ReturnValue), Z_Construct_UEnum_OnlineSubsystemPico_EAssetFileDownloadCompleteStatus, METADATA_PARAMS(0, nullptr) }; // 420183321
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetCompleteStatus_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetCompleteStatus_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetCompleteStatus_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetCompleteStatus_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Download Update" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The download status of the DLC file.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The download status of the DLC file." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetCompleteStatus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetFileDownloadUpdate, nullptr, "GetCompleteStatus", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetCompleteStatus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetCompleteStatus_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetCompleteStatus_Statics::Pico_AssetFileDownloadUpdate_eventGetCompleteStatus_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetCompleteStatus_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetCompleteStatus_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetCompleteStatus_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetCompleteStatus_Statics::Pico_AssetFileDownloadUpdate_eventGetCompleteStatus_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetCompleteStatus()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetCompleteStatus_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_AssetFileDownloadUpdate);
	UClass* Z_Construct_UClass_UPico_AssetFileDownloadUpdate_NoRegister()
	{
		return UPico_AssetFileDownloadUpdate::StaticClass();
	}
	struct Z_Construct_UClass_UPico_AssetFileDownloadUpdate_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_AssetFileDownloadUpdate_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetFileDownloadUpdate_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_AssetFileDownloadUpdate_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetAssetId, "GetAssetId" }, // 2293892872
		{ &Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTotal, "GetBytesTotal" }, // 3938370467
		{ &Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetBytesTransferred, "GetBytesTransferred" }, // 2676974626
		{ &Z_Construct_UFunction_UPico_AssetFileDownloadUpdate_GetCompleteStatus, "GetCompleteStatus" }, // 859708577
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetFileDownloadUpdate_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_AssetFileDownloadUpdate_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_AssetFileDownloadUpdate class.\n" },
#endif
		{ "IncludePath", "Pico_AssetFile.h" },
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_AssetFileDownloadUpdate class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_AssetFileDownloadUpdate_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_AssetFileDownloadUpdate>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_AssetFileDownloadUpdate_Statics::ClassParams = {
		&UPico_AssetFileDownloadUpdate::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetFileDownloadUpdate_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_AssetFileDownloadUpdate_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPico_AssetFileDownloadUpdate()
	{
		if (!Z_Registration_Info_UClass_UPico_AssetFileDownloadUpdate.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_AssetFileDownloadUpdate.OuterSingleton, Z_Construct_UClass_UPico_AssetFileDownloadUpdate_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_AssetFileDownloadUpdate.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_AssetFileDownloadUpdate>()
	{
		return UPico_AssetFileDownloadUpdate::StaticClass();
	}
	UPico_AssetFileDownloadUpdate::UPico_AssetFileDownloadUpdate(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_AssetFileDownloadUpdate);
	UPico_AssetFileDownloadUpdate::~UPico_AssetFileDownloadUpdate() {}
	DEFINE_FUNCTION(UPico_AssetFileDownloadResult::execGetFilePath)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetFilePath();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetFileDownloadResult::execGetAssetId)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetAssetId();
		P_NATIVE_END;
	}
	void UPico_AssetFileDownloadResult::StaticRegisterNativesUPico_AssetFileDownloadResult()
	{
		UClass* Class = UPico_AssetFileDownloadResult::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAssetId", &UPico_AssetFileDownloadResult::execGetAssetId },
			{ "GetFilePath", &UPico_AssetFileDownloadResult::execGetFilePath },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetAssetId_Statics
	{
		struct Pico_AssetFileDownloadResult_eventGetAssetId_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetAssetId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetFileDownloadResult_eventGetAssetId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetAssetId_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetAssetId_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetAssetId_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Download Result" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The ID of the DLC file. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The ID of the DLC file." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetAssetId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetFileDownloadResult, nullptr, "GetAssetId", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetAssetId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetAssetId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetAssetId_Statics::Pico_AssetFileDownloadResult_eventGetAssetId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetAssetId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetAssetId_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetAssetId_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetAssetId_Statics::Pico_AssetFileDownloadResult_eventGetAssetId_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetAssetId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetAssetId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetFilePath_Statics
	{
		struct Pico_AssetFileDownloadResult_eventGetFilePath_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetFilePath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetFileDownloadResult_eventGetFilePath_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetFilePath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetFilePath_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetFilePath_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Download Result" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The path to the DLC file. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The path to the DLC file." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetFilePath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetFileDownloadResult, nullptr, "GetFilePath", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetFilePath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetFilePath_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetFilePath_Statics::Pico_AssetFileDownloadResult_eventGetFilePath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetFilePath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetFilePath_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetFilePath_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetFilePath_Statics::Pico_AssetFileDownloadResult_eventGetFilePath_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetFilePath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetFilePath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_AssetFileDownloadResult);
	UClass* Z_Construct_UClass_UPico_AssetFileDownloadResult_NoRegister()
	{
		return UPico_AssetFileDownloadResult::StaticClass();
	}
	struct Z_Construct_UClass_UPico_AssetFileDownloadResult_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_AssetFileDownloadResult_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetFileDownloadResult_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_AssetFileDownloadResult_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetAssetId, "GetAssetId" }, // 3181928980
		{ &Z_Construct_UFunction_UPico_AssetFileDownloadResult_GetFilePath, "GetFilePath" }, // 4063654404
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetFileDownloadResult_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_AssetFileDownloadResult_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_AssetFileDownloadResult class.\n" },
#endif
		{ "IncludePath", "Pico_AssetFile.h" },
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_AssetFileDownloadResult class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_AssetFileDownloadResult_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_AssetFileDownloadResult>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_AssetFileDownloadResult_Statics::ClassParams = {
		&UPico_AssetFileDownloadResult::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetFileDownloadResult_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_AssetFileDownloadResult_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPico_AssetFileDownloadResult()
	{
		if (!Z_Registration_Info_UClass_UPico_AssetFileDownloadResult.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_AssetFileDownloadResult.OuterSingleton, Z_Construct_UClass_UPico_AssetFileDownloadResult_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_AssetFileDownloadResult.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_AssetFileDownloadResult>()
	{
		return UPico_AssetFileDownloadResult::StaticClass();
	}
	UPico_AssetFileDownloadResult::UPico_AssetFileDownloadResult(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_AssetFileDownloadResult);
	UPico_AssetFileDownloadResult::~UPico_AssetFileDownloadResult() {}
	DEFINE_FUNCTION(UPico_AssetStatus::execGetDownloadStatus)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetDownloadStatus();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetStatus::execGetFileName)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetFileName();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetStatus::execGetFilePath)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetFilePath();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetStatus::execGetAssetId)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetAssetId();
		P_NATIVE_END;
	}
	void UPico_AssetStatus::StaticRegisterNativesUPico_AssetStatus()
	{
		UClass* Class = UPico_AssetStatus::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAssetId", &UPico_AssetStatus::execGetAssetId },
			{ "GetDownloadStatus", &UPico_AssetStatus::execGetDownloadStatus },
			{ "GetFileName", &UPico_AssetStatus::execGetFileName },
			{ "GetFilePath", &UPico_AssetStatus::execGetFilePath },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_AssetStatus_GetAssetId_Statics
	{
		struct Pico_AssetStatus_eventGetAssetId_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetStatus_GetAssetId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetStatus_eventGetAssetId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetStatus_GetAssetId_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetStatus_GetAssetId_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetStatus_GetAssetId_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Asset Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The ID of the DLC file. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The ID of the DLC file." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetStatus_GetAssetId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetStatus, nullptr, "GetAssetId", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetStatus_GetAssetId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetStatus_GetAssetId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetStatus_GetAssetId_Statics::Pico_AssetStatus_eventGetAssetId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetStatus_GetAssetId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetStatus_GetAssetId_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetStatus_GetAssetId_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetStatus_GetAssetId_Statics::Pico_AssetStatus_eventGetAssetId_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetStatus_GetAssetId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetStatus_GetAssetId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetStatus_GetDownloadStatus_Statics
	{
		struct Pico_AssetStatus_eventGetDownloadStatus_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetStatus_GetDownloadStatus_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetStatus_eventGetDownloadStatus_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetStatus_GetDownloadStatus_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetStatus_GetDownloadStatus_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetStatus_GetDownloadStatus_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Asset Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The download status of the DLC file. You can refer to \\ref DownloadStatus for details. One of 'installed', 'available', or 'in-progress' */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The download status of the DLC file. You can refer to \\ref DownloadStatus for details. One of 'installed', 'available', or 'in-progress'" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetStatus_GetDownloadStatus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetStatus, nullptr, "GetDownloadStatus", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetStatus_GetDownloadStatus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetStatus_GetDownloadStatus_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetStatus_GetDownloadStatus_Statics::Pico_AssetStatus_eventGetDownloadStatus_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetStatus_GetDownloadStatus_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetStatus_GetDownloadStatus_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetStatus_GetDownloadStatus_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetStatus_GetDownloadStatus_Statics::Pico_AssetStatus_eventGetDownloadStatus_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetStatus_GetDownloadStatus()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetStatus_GetDownloadStatus_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetStatus_GetFileName_Statics
	{
		struct Pico_AssetStatus_eventGetFileName_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetStatus_GetFileName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetStatus_eventGetFileName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetStatus_GetFileName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetStatus_GetFileName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetStatus_GetFileName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Asset Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The name of the DLC file. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The name of the DLC file." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetStatus_GetFileName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetStatus, nullptr, "GetFileName", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetStatus_GetFileName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetStatus_GetFileName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetStatus_GetFileName_Statics::Pico_AssetStatus_eventGetFileName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetStatus_GetFileName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetStatus_GetFileName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetStatus_GetFileName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetStatus_GetFileName_Statics::Pico_AssetStatus_eventGetFileName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetStatus_GetFileName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetStatus_GetFileName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetStatus_GetFilePath_Statics
	{
		struct Pico_AssetStatus_eventGetFilePath_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetStatus_GetFilePath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetStatus_eventGetFilePath_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetStatus_GetFilePath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetStatus_GetFilePath_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetStatus_GetFilePath_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Asset Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The path to the DLC file. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The path to the DLC file." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetStatus_GetFilePath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetStatus, nullptr, "GetFilePath", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetStatus_GetFilePath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetStatus_GetFilePath_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetStatus_GetFilePath_Statics::Pico_AssetStatus_eventGetFilePath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetStatus_GetFilePath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetStatus_GetFilePath_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetStatus_GetFilePath_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetStatus_GetFilePath_Statics::Pico_AssetStatus_eventGetFilePath_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetStatus_GetFilePath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetStatus_GetFilePath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_AssetStatus);
	UClass* Z_Construct_UClass_UPico_AssetStatus_NoRegister()
	{
		return UPico_AssetStatus::StaticClass();
	}
	struct Z_Construct_UClass_UPico_AssetStatus_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_AssetStatus_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetStatus_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_AssetStatus_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_AssetStatus_GetAssetId, "GetAssetId" }, // 2824959470
		{ &Z_Construct_UFunction_UPico_AssetStatus_GetDownloadStatus, "GetDownloadStatus" }, // 962674573
		{ &Z_Construct_UFunction_UPico_AssetStatus_GetFileName, "GetFileName" }, // 3780348352
		{ &Z_Construct_UFunction_UPico_AssetStatus_GetFilePath, "GetFilePath" }, // 1629693543
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetStatus_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_AssetStatus_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_AssetStatus class.\n" },
#endif
		{ "IncludePath", "Pico_AssetFile.h" },
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_AssetStatus class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_AssetStatus_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_AssetStatus>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_AssetStatus_Statics::ClassParams = {
		&UPico_AssetStatus::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetStatus_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_AssetStatus_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPico_AssetStatus()
	{
		if (!Z_Registration_Info_UClass_UPico_AssetStatus.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_AssetStatus.OuterSingleton, Z_Construct_UClass_UPico_AssetStatus_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_AssetStatus.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_AssetStatus>()
	{
		return UPico_AssetStatus::StaticClass();
	}
	UPico_AssetStatus::UPico_AssetStatus(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_AssetStatus);
	UPico_AssetStatus::~UPico_AssetStatus() {}
	DEFINE_FUNCTION(UPico_AssetFileDeleteForSafety::execGetReason)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetReason();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AssetFileDeleteForSafety::execGetAssetId)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetAssetId();
		P_NATIVE_END;
	}
	void UPico_AssetFileDeleteForSafety::StaticRegisterNativesUPico_AssetFileDeleteForSafety()
	{
		UClass* Class = UPico_AssetFileDeleteForSafety::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAssetId", &UPico_AssetFileDeleteForSafety::execGetAssetId },
			{ "GetReason", &UPico_AssetFileDeleteForSafety::execGetReason },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetAssetId_Statics
	{
		struct Pico_AssetFileDeleteForSafety_eventGetAssetId_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetAssetId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetFileDeleteForSafety_eventGetAssetId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetAssetId_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetAssetId_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetAssetId_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Delete For Safety" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The ID of the DLC file. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The ID of the DLC file." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetAssetId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetFileDeleteForSafety, nullptr, "GetAssetId", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetAssetId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetAssetId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetAssetId_Statics::Pico_AssetFileDeleteForSafety_eventGetAssetId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetAssetId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetAssetId_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetAssetId_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetAssetId_Statics::Pico_AssetFileDeleteForSafety_eventGetAssetId_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetAssetId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetAssetId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetReason_Statics
	{
		struct Pico_AssetFileDeleteForSafety_eventGetReason_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetReason_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AssetFileDeleteForSafety_eventGetReason_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetReason_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetReason_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetReason_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|AssetFile|Delete For Safety" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The description for why this asset file is deleted. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The description for why this asset file is deleted." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetReason_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AssetFileDeleteForSafety, nullptr, "GetReason", nullptr, nullptr, Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetReason_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetReason_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetReason_Statics::Pico_AssetFileDeleteForSafety_eventGetReason_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetReason_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetReason_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetReason_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetReason_Statics::Pico_AssetFileDeleteForSafety_eventGetReason_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetReason()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetReason_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_AssetFileDeleteForSafety);
	UClass* Z_Construct_UClass_UPico_AssetFileDeleteForSafety_NoRegister()
	{
		return UPico_AssetFileDeleteForSafety::StaticClass();
	}
	struct Z_Construct_UClass_UPico_AssetFileDeleteForSafety_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_AssetFileDeleteForSafety_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetFileDeleteForSafety_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_AssetFileDeleteForSafety_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetAssetId, "GetAssetId" }, // 3589320257
		{ &Z_Construct_UFunction_UPico_AssetFileDeleteForSafety_GetReason, "GetReason" }, // 3169480561
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetFileDeleteForSafety_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_AssetFileDeleteForSafety_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_AssetFileDeleteForSafety class.\n" },
#endif
		{ "IncludePath", "Pico_AssetFile.h" },
		{ "ModuleRelativePath", "Public/Pico_AssetFile.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_AssetFileDeleteForSafety class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_AssetFileDeleteForSafety_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_AssetFileDeleteForSafety>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_AssetFileDeleteForSafety_Statics::ClassParams = {
		&UPico_AssetFileDeleteForSafety::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AssetFileDeleteForSafety_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_AssetFileDeleteForSafety_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPico_AssetFileDeleteForSafety()
	{
		if (!Z_Registration_Info_UClass_UPico_AssetFileDeleteForSafety.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_AssetFileDeleteForSafety.OuterSingleton, Z_Construct_UClass_UPico_AssetFileDeleteForSafety_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_AssetFileDeleteForSafety.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_AssetFileDeleteForSafety>()
	{
		return UPico_AssetFileDeleteForSafety::StaticClass();
	}
	UPico_AssetFileDeleteForSafety::UPico_AssetFileDeleteForSafety(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_AssetFileDeleteForSafety);
	UPico_AssetFileDeleteForSafety::~UPico_AssetFileDeleteForSafety() {}
	struct Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_AssetFile_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_AssetFile_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOnlinePicoAssetFileFunction, UOnlinePicoAssetFileFunction::StaticClass, TEXT("UOnlinePicoAssetFileFunction"), &Z_Registration_Info_UClass_UOnlinePicoAssetFileFunction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOnlinePicoAssetFileFunction), 1706522714U) },
		{ Z_Construct_UClass_UPico_AssetFileDeleteResult, UPico_AssetFileDeleteResult::StaticClass, TEXT("UPico_AssetFileDeleteResult"), &Z_Registration_Info_UClass_UPico_AssetFileDeleteResult, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_AssetFileDeleteResult), 2971455824U) },
		{ Z_Construct_UClass_UPico_AssetDetails, UPico_AssetDetails::StaticClass, TEXT("UPico_AssetDetails"), &Z_Registration_Info_UClass_UPico_AssetDetails, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_AssetDetails), 919750966U) },
		{ Z_Construct_UClass_UPico_AssetDetailsArray, UPico_AssetDetailsArray::StaticClass, TEXT("UPico_AssetDetailsArray"), &Z_Registration_Info_UClass_UPico_AssetDetailsArray, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_AssetDetailsArray), 2719945179U) },
		{ Z_Construct_UClass_UPico_AssetFileDownloadCancelResult, UPico_AssetFileDownloadCancelResult::StaticClass, TEXT("UPico_AssetFileDownloadCancelResult"), &Z_Registration_Info_UClass_UPico_AssetFileDownloadCancelResult, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_AssetFileDownloadCancelResult), 1363614793U) },
		{ Z_Construct_UClass_UPico_AssetFileDownloadUpdate, UPico_AssetFileDownloadUpdate::StaticClass, TEXT("UPico_AssetFileDownloadUpdate"), &Z_Registration_Info_UClass_UPico_AssetFileDownloadUpdate, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_AssetFileDownloadUpdate), 3231011966U) },
		{ Z_Construct_UClass_UPico_AssetFileDownloadResult, UPico_AssetFileDownloadResult::StaticClass, TEXT("UPico_AssetFileDownloadResult"), &Z_Registration_Info_UClass_UPico_AssetFileDownloadResult, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_AssetFileDownloadResult), 1329885163U) },
		{ Z_Construct_UClass_UPico_AssetStatus, UPico_AssetStatus::StaticClass, TEXT("UPico_AssetStatus"), &Z_Registration_Info_UClass_UPico_AssetStatus, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_AssetStatus), 147437198U) },
		{ Z_Construct_UClass_UPico_AssetFileDeleteForSafety, UPico_AssetFileDeleteForSafety::StaticClass, TEXT("UPico_AssetFileDeleteForSafety"), &Z_Registration_Info_UClass_UPico_AssetFileDeleteForSafety, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_AssetFileDeleteForSafety), 1315315733U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_AssetFile_h_2783002695(TEXT("/Script/OnlineSubsystemPico"),
		Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_AssetFile_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_AssetFile_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
