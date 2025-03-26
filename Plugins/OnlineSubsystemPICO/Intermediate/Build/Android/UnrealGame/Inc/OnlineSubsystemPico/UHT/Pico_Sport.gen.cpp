// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../OnlineSubsystemPico/Public/Pico_Sport.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePico_Sport() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoSportFunction();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoSportFunction_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_SportDailySummary();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_SportDailySummary_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_SportDailySummaryArray();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_SportDailySummaryArray_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_SportSummary();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_SportSummary_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_SportUserInfo();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_SportUserInfo_NoRegister();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ESportTarget();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_EUserGender();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemPico();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetDailySummary_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_SportDailySummaryArray* SportDailySummaryArray;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SportDailySummaryArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetDailySummary_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetDailySummary_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetDailySummary_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature_Statics::NewProp_SportDailySummaryArray = { "SportDailySummaryArray", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetDailySummary_Parms, SportDailySummaryArray), Z_Construct_UClass_UPico_SportDailySummaryArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature_Statics::NewProp_SportDailySummaryArray,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetDailySummary__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetDailySummary_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetDailySummary_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetDailySummary_DelegateWrapper(const FScriptDelegate& GetDailySummary, bool bIsError, const FString& ErrorMessage, UPico_SportDailySummaryArray* SportDailySummaryArray)
{
	struct _Script_OnlineSubsystemPico_eventGetDailySummary_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_SportDailySummaryArray* SportDailySummaryArray;
	};
	_Script_OnlineSubsystemPico_eventGetDailySummary_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.SportDailySummaryArray=SportDailySummaryArray;
	GetDailySummary.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetSummary_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_SportSummary* SportSummary;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SportSummary;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetSummary_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetSummary_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetSummary_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature_Statics::NewProp_SportSummary = { "SportSummary", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetSummary_Parms, SportSummary), Z_Construct_UClass_UPico_SportSummary_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature_Statics::NewProp_SportSummary,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetSummary__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetSummary_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetSummary_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetSummary_DelegateWrapper(const FScriptDelegate& GetSummary, bool bIsError, const FString& ErrorMessage, UPico_SportSummary* SportSummary)
{
	struct _Script_OnlineSubsystemPico_eventGetSummary_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_SportSummary* SportSummary;
	};
	_Script_OnlineSubsystemPico_eventGetSummary_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.SportSummary=SportSummary;
	GetSummary.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetSportUserInfo_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_SportUserInfo* SportUserInfo;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SportUserInfo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetSportUserInfo_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetSportUserInfo_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetSportUserInfo_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature_Statics::NewProp_SportUserInfo = { "SportUserInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetSportUserInfo_Parms, SportUserInfo), Z_Construct_UClass_UPico_SportUserInfo_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature_Statics::NewProp_SportUserInfo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetSportUserInfo__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetSportUserInfo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetSportUserInfo_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetSportUserInfo_DelegateWrapper(const FScriptDelegate& GetSportUserInfo, bool bIsError, const FString& ErrorMessage, UPico_SportUserInfo* SportUserInfo)
{
	struct _Script_OnlineSubsystemPico_eventGetSportUserInfo_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_SportUserInfo* SportUserInfo;
	};
	_Script_OnlineSubsystemPico_eventGetSportUserInfo_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.SportUserInfo=SportUserInfo;
	GetSportUserInfo.ProcessDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UOnlinePicoSportFunction::execConvertInt64ToDateTime)
	{
		P_GET_PROPERTY(FInt64Property,Z_Param_InValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FDateTime*)Z_Param__Result=UOnlinePicoSportFunction::ConvertInt64ToDateTime(Z_Param_InValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoSportFunction::execConvertDateTimeToInt64)
	{
		P_GET_STRUCT(FDateTime,Z_Param_InDateTime);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int64*)Z_Param__Result=UOnlinePicoSportFunction::ConvertDateTimeToInt64(Z_Param_InDateTime);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoSportFunction::execGetSportUserInfo)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetSportUserInfoDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoSportFunction::GetSportUserInfo(Z_Param_WorldContextObject,FGetSportUserInfo(Z_Param_InGetSportUserInfoDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoSportFunction::execGetSummary)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FInt64Property,Z_Param_BeginTime);
		P_GET_PROPERTY(FInt64Property,Z_Param_EndTime);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetSummaryDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoSportFunction::GetSummary(Z_Param_WorldContextObject,Z_Param_BeginTime,Z_Param_EndTime,FGetSummary(Z_Param_InGetSummaryDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoSportFunction::execGetDailySummary)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FInt64Property,Z_Param_BeginTime);
		P_GET_PROPERTY(FInt64Property,Z_Param_EndTime);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetDailySummaryDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoSportFunction::GetDailySummary(Z_Param_WorldContextObject,Z_Param_BeginTime,Z_Param_EndTime,FGetDailySummary(Z_Param_InGetDailySummaryDelegate));
		P_NATIVE_END;
	}
	void UOnlinePicoSportFunction::StaticRegisterNativesUOnlinePicoSportFunction()
	{
		UClass* Class = UOnlinePicoSportFunction::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ConvertDateTimeToInt64", &UOnlinePicoSportFunction::execConvertDateTimeToInt64 },
			{ "ConvertInt64ToDateTime", &UOnlinePicoSportFunction::execConvertInt64ToDateTime },
			{ "GetDailySummary", &UOnlinePicoSportFunction::execGetDailySummary },
			{ "GetSportUserInfo", &UOnlinePicoSportFunction::execGetSportUserInfo },
			{ "GetSummary", &UOnlinePicoSportFunction::execGetSummary },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertDateTimeToInt64_Statics
	{
		struct OnlinePicoSportFunction_eventConvertDateTimeToInt64_Parms
		{
			FDateTime InDateTime;
			int64 ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_InDateTime;
		static const UECodeGen_Private::FInt64PropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertDateTimeToInt64_Statics::NewProp_InDateTime = { "InDateTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoSportFunction_eventConvertDateTimeToInt64_Parms, InDateTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertDateTimeToInt64_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoSportFunction_eventConvertDateTimeToInt64_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertDateTimeToInt64_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertDateTimeToInt64_Statics::NewProp_InDateTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertDateTimeToInt64_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertDateTimeToInt64_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Sport" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Convert FDateTime to int64\n/// @note BlueprintPure function.\n/// </summary>\n/// <param name =\"InDateTime\">Input DateTime.</param>\n/// <returns>int64 result\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nConvert FDateTime to int64\n@note BlueprintPure function.\n</summary>\n<param name =\"InDateTime\">Input DateTime.</param>\n<returns>int64 result\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertDateTimeToInt64_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoSportFunction, nullptr, "ConvertDateTimeToInt64", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertDateTimeToInt64_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertDateTimeToInt64_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertDateTimeToInt64_Statics::OnlinePicoSportFunction_eventConvertDateTimeToInt64_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertDateTimeToInt64_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertDateTimeToInt64_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertDateTimeToInt64_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertDateTimeToInt64_Statics::OnlinePicoSportFunction_eventConvertDateTimeToInt64_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertDateTimeToInt64()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertDateTimeToInt64_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertInt64ToDateTime_Statics
	{
		struct OnlinePicoSportFunction_eventConvertInt64ToDateTime_Parms
		{
			int64 InValue;
			FDateTime ReturnValue;
		};
		static const UECodeGen_Private::FInt64PropertyParams NewProp_InValue;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertInt64ToDateTime_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoSportFunction_eventConvertInt64ToDateTime_Parms, InValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertInt64ToDateTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoSportFunction_eventConvertInt64ToDateTime_Parms, ReturnValue), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertInt64ToDateTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertInt64ToDateTime_Statics::NewProp_InValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertInt64ToDateTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertInt64ToDateTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Sport" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Converts int64 to FDateTime.\n/// @note BlueprintPure function.\n/// </summary>\n/// <param name =\"InValue\">The int64 input.</param>\n/// <returns>The FDateTime result of the int64 input.\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nConverts int64 to FDateTime.\n@note BlueprintPure function.\n</summary>\n<param name =\"InValue\">The int64 input.</param>\n<returns>The FDateTime result of the int64 input.\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertInt64ToDateTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoSportFunction, nullptr, "ConvertInt64ToDateTime", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertInt64ToDateTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertInt64ToDateTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertInt64ToDateTime_Statics::OnlinePicoSportFunction_eventConvertInt64ToDateTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertInt64ToDateTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertInt64ToDateTime_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertInt64ToDateTime_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertInt64ToDateTime_Statics::OnlinePicoSportFunction_eventConvertInt64ToDateTime_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertInt64ToDateTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertInt64ToDateTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics
	{
		struct OnlinePicoSportFunction_eventGetDailySummary_Parms
		{
			UObject* WorldContextObject;
			int64 BeginTime;
			int64 EndTime;
			FScriptDelegate InGetDailySummaryDelegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FInt64PropertyParams NewProp_BeginTime;
		static const UECodeGen_Private::FInt64PropertyParams NewProp_EndTime;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetDailySummaryDelegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoSportFunction_eventGetDailySummary_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics::NewProp_BeginTime = { "BeginTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoSportFunction_eventGetDailySummary_Parms, BeginTime), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics::NewProp_EndTime = { "EndTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoSportFunction_eventGetDailySummary_Parms, EndTime), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics::NewProp_InGetDailySummaryDelegate = { "InGetDailySummaryDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoSportFunction_eventGetDailySummary_Parms, InGetDailySummaryDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDailySummary__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2910285154
	void Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoSportFunction_eventGetDailySummary_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoSportFunction_eventGetDailySummary_Parms), &Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics::NewProp_BeginTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics::NewProp_EndTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics::NewProp_InGetDailySummaryDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Sport" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets a summary of the user's daily exercise data for a specified period within the recent 3 months.\n/// For example, if the period you set is between 2022/08/16 and 2022/08/18, the exercise data generated on 08/16, 08/17, and 08/18 will be returned.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"BeginTime\">A DateTime struct(FDateTime(int64 InTicks).GetTicks()) defining the begin time of the period.</param>\n/// <param name=\"EndTime\">A DateTime struct(FDateTime(int64 InTicks).GetTicks()) defining the end time of the period.</param>\n/// <param name=\"InGetDailySummaryDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_SportDailySummaryArray *, SportDailySummaryArray).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets a summary of the user's daily exercise data for a specified period within the recent 3 months.\nFor example, if the period you set is between 2022/08/16 and 2022/08/18, the exercise data generated on 08/16, 08/17, and 08/18 will be returned.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"BeginTime\">A DateTime struct(FDateTime(int64 InTicks).GetTicks()) defining the begin time of the period.</param>\n<param name=\"EndTime\">A DateTime struct(FDateTime(int64 InTicks).GetTicks()) defining the end time of the period.</param>\n<param name=\"InGetDailySummaryDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_SportDailySummaryArray *, SportDailySummaryArray).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoSportFunction, nullptr, "GetDailySummary", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics::OnlinePicoSportFunction_eventGetDailySummary_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics::OnlinePicoSportFunction_eventGetDailySummary_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoSportFunction_GetSportUserInfo_Statics
	{
		struct OnlinePicoSportFunction_eventGetSportUserInfo_Parms
		{
			UObject* WorldContextObject;
			FScriptDelegate InGetSportUserInfoDelegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetSportUserInfoDelegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoSportFunction_GetSportUserInfo_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoSportFunction_eventGetSportUserInfo_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoSportFunction_GetSportUserInfo_Statics::NewProp_InGetSportUserInfoDelegate = { "InGetSportUserInfoDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoSportFunction_eventGetSportUserInfo_Parms, InGetSportUserInfoDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSportUserInfo__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1096634372
	void Z_Construct_UFunction_UOnlinePicoSportFunction_GetSportUserInfo_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoSportFunction_eventGetSportUserInfo_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoSportFunction_GetSportUserInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoSportFunction_eventGetSportUserInfo_Parms), &Z_Construct_UFunction_UOnlinePicoSportFunction_GetSportUserInfo_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoSportFunction_GetSportUserInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSportFunction_GetSportUserInfo_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSportFunction_GetSportUserInfo_Statics::NewProp_InGetSportUserInfoDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSportFunction_GetSportUserInfo_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoSportFunction_GetSportUserInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Sport" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets a user's basic information and exercise plan.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"InGetSportUserInfoDelegate\">Will be executed when the request has been completed.  \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_SportUserInfo *, SportUserInfo).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets a user's basic information and exercise plan.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"InGetSportUserInfoDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_SportUserInfo *, SportUserInfo).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoSportFunction_GetSportUserInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoSportFunction, nullptr, "GetSportUserInfo", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoSportFunction_GetSportUserInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSportFunction_GetSportUserInfo_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoSportFunction_GetSportUserInfo_Statics::OnlinePicoSportFunction_eventGetSportUserInfo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSportFunction_GetSportUserInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoSportFunction_GetSportUserInfo_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSportFunction_GetSportUserInfo_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoSportFunction_GetSportUserInfo_Statics::OnlinePicoSportFunction_eventGetSportUserInfo_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoSportFunction_GetSportUserInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoSportFunction_GetSportUserInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics
	{
		struct OnlinePicoSportFunction_eventGetSummary_Parms
		{
			UObject* WorldContextObject;
			int64 BeginTime;
			int64 EndTime;
			FScriptDelegate InGetSummaryDelegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FInt64PropertyParams NewProp_BeginTime;
		static const UECodeGen_Private::FInt64PropertyParams NewProp_EndTime;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetSummaryDelegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoSportFunction_eventGetSummary_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics::NewProp_BeginTime = { "BeginTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoSportFunction_eventGetSummary_Parms, BeginTime), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics::NewProp_EndTime = { "EndTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoSportFunction_eventGetSummary_Parms, EndTime), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics::NewProp_InGetSummaryDelegate = { "InGetSummaryDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoSportFunction_eventGetSummary_Parms, InGetSummaryDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSummary__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1580543236
	void Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoSportFunction_eventGetSummary_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoSportFunction_eventGetSummary_Parms), &Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics::NewProp_BeginTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics::NewProp_EndTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics::NewProp_InGetSummaryDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Sport" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets a summary of the user's exercise data for a specified duration within today. The duration should not exceed 24 hours.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"BeginTime\">A DateTime struct(FDateTime(int64 InTicks).GetTicks()) defining the begin time of the period.</param>\n/// <param name=\"EndTime\">A DateTime struct(FDateTime(int64 InTicks)GetTicks()) defining the end time of the period.</param>\n/// <param name=\"InGetSummaryDelegate\">Will be executed when the request has been completed.  \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_SportSummary *, SportSummary).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets a summary of the user's exercise data for a specified duration within today. The duration should not exceed 24 hours.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"BeginTime\">A DateTime struct(FDateTime(int64 InTicks).GetTicks()) defining the begin time of the period.</param>\n<param name=\"EndTime\">A DateTime struct(FDateTime(int64 InTicks)GetTicks()) defining the end time of the period.</param>\n<param name=\"InGetSummaryDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_SportSummary *, SportSummary).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoSportFunction, nullptr, "GetSummary", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics::OnlinePicoSportFunction_eventGetSummary_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics::OnlinePicoSportFunction_eventGetSummary_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOnlinePicoSportFunction);
	UClass* Z_Construct_UClass_UOnlinePicoSportFunction_NoRegister()
	{
		return UOnlinePicoSportFunction::StaticClass();
	}
	struct Z_Construct_UClass_UOnlinePicoSportFunction_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOnlinePicoSportFunction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSportFunction_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UOnlinePicoSportFunction_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertDateTimeToInt64, "ConvertDateTimeToInt64" }, // 243396168
		{ &Z_Construct_UFunction_UOnlinePicoSportFunction_ConvertInt64ToDateTime, "ConvertInt64ToDateTime" }, // 1445455566
		{ &Z_Construct_UFunction_UOnlinePicoSportFunction_GetDailySummary, "GetDailySummary" }, // 2799749585
		{ &Z_Construct_UFunction_UOnlinePicoSportFunction_GetSportUserInfo, "GetSportUserInfo" }, // 3966415489
		{ &Z_Construct_UFunction_UOnlinePicoSportFunction_GetSummary, "GetSummary" }, // 7609283
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSportFunction_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoSportFunction_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @defgroup BP_Sport BP_Sport\n  *  This is the BP_Sport group\n  *  @{\n  *//// @brief OnlinePicoSport Blueprint Function class.\n" },
#endif
		{ "IncludePath", "Pico_Sport.h" },
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@defgroup BP_Sport BP_Sport\nThis is the BP_Sport group\n@{\n /// @brief OnlinePicoSport Blueprint Function class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOnlinePicoSportFunction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOnlinePicoSportFunction>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOnlinePicoSportFunction_Statics::ClassParams = {
		&UOnlinePicoSportFunction::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSportFunction_Statics::Class_MetaDataParams), Z_Construct_UClass_UOnlinePicoSportFunction_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UOnlinePicoSportFunction()
	{
		if (!Z_Registration_Info_UClass_UOnlinePicoSportFunction.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOnlinePicoSportFunction.OuterSingleton, Z_Construct_UClass_UOnlinePicoSportFunction_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOnlinePicoSportFunction.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UOnlinePicoSportFunction>()
	{
		return UOnlinePicoSportFunction::StaticClass();
	}
	UOnlinePicoSportFunction::UOnlinePicoSportFunction(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOnlinePicoSportFunction);
	UOnlinePicoSportFunction::~UOnlinePicoSportFunction() {}
	DEFINE_FUNCTION(UPico_SportDailySummary::execGetPlanCalorie)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetPlanCalorie();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SportDailySummary::execGetCalorie)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetCalorie();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SportDailySummary::execGetPlanDurationInMinutes)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetPlanDurationInMinutes();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SportDailySummary::execGetDurationInSeconds)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetDurationInSeconds();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SportDailySummary::execGetDate)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int64*)Z_Param__Result=P_THIS->GetDate();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SportDailySummary::execGetID)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int64*)Z_Param__Result=P_THIS->GetID();
		P_NATIVE_END;
	}
	void UPico_SportDailySummary::StaticRegisterNativesUPico_SportDailySummary()
	{
		UClass* Class = UPico_SportDailySummary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetCalorie", &UPico_SportDailySummary::execGetCalorie },
			{ "GetDate", &UPico_SportDailySummary::execGetDate },
			{ "GetDurationInSeconds", &UPico_SportDailySummary::execGetDurationInSeconds },
			{ "GetID", &UPico_SportDailySummary::execGetID },
			{ "GetPlanCalorie", &UPico_SportDailySummary::execGetPlanCalorie },
			{ "GetPlanDurationInMinutes", &UPico_SportDailySummary::execGetPlanDurationInMinutes },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_SportDailySummary_GetCalorie_Statics
	{
		struct Pico_SportDailySummary_eventGetCalorie_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPico_SportDailySummary_GetCalorie_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SportDailySummary_eventGetCalorie_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SportDailySummary_GetCalorie_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SportDailySummary_GetCalorie_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SportDailySummary_GetCalorie_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Sport|Sport Daily Summary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The actual calorie burnt (in kilo calorie).*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The actual calorie burnt (in kilo calorie)." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SportDailySummary_GetCalorie_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SportDailySummary, nullptr, "GetCalorie", nullptr, nullptr, Z_Construct_UFunction_UPico_SportDailySummary_GetCalorie_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummary_GetCalorie_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SportDailySummary_GetCalorie_Statics::Pico_SportDailySummary_eventGetCalorie_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummary_GetCalorie_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SportDailySummary_GetCalorie_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummary_GetCalorie_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SportDailySummary_GetCalorie_Statics::Pico_SportDailySummary_eventGetCalorie_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SportDailySummary_GetCalorie()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SportDailySummary_GetCalorie_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SportDailySummary_GetDate_Statics
	{
		struct Pico_SportDailySummary_eventGetDate_Parms
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
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UPico_SportDailySummary_GetDate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SportDailySummary_eventGetDate_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SportDailySummary_GetDate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SportDailySummary_GetDate_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SportDailySummary_GetDate_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Sport|Sport Daily Summary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The date when the summary was generated.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The date when the summary was generated." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SportDailySummary_GetDate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SportDailySummary, nullptr, "GetDate", nullptr, nullptr, Z_Construct_UFunction_UPico_SportDailySummary_GetDate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummary_GetDate_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SportDailySummary_GetDate_Statics::Pico_SportDailySummary_eventGetDate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummary_GetDate_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SportDailySummary_GetDate_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummary_GetDate_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SportDailySummary_GetDate_Statics::Pico_SportDailySummary_eventGetDate_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SportDailySummary_GetDate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SportDailySummary_GetDate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SportDailySummary_GetDurationInSeconds_Statics
	{
		struct Pico_SportDailySummary_eventGetDurationInSeconds_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_SportDailySummary_GetDurationInSeconds_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SportDailySummary_eventGetDurationInSeconds_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SportDailySummary_GetDurationInSeconds_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SportDailySummary_GetDurationInSeconds_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SportDailySummary_GetDurationInSeconds_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Sport|Sport Daily Summary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The sport duration (in seconds).*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The sport duration (in seconds)." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SportDailySummary_GetDurationInSeconds_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SportDailySummary, nullptr, "GetDurationInSeconds", nullptr, nullptr, Z_Construct_UFunction_UPico_SportDailySummary_GetDurationInSeconds_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummary_GetDurationInSeconds_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SportDailySummary_GetDurationInSeconds_Statics::Pico_SportDailySummary_eventGetDurationInSeconds_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummary_GetDurationInSeconds_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SportDailySummary_GetDurationInSeconds_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummary_GetDurationInSeconds_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SportDailySummary_GetDurationInSeconds_Statics::Pico_SportDailySummary_eventGetDurationInSeconds_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SportDailySummary_GetDurationInSeconds()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SportDailySummary_GetDurationInSeconds_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SportDailySummary_GetID_Statics
	{
		struct Pico_SportDailySummary_eventGetID_Parms
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
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UPico_SportDailySummary_GetID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SportDailySummary_eventGetID_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SportDailySummary_GetID_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SportDailySummary_GetID_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SportDailySummary_GetID_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Sport|Sport Daily Summary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The ID of the summary.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The ID of the summary." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SportDailySummary_GetID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SportDailySummary, nullptr, "GetID", nullptr, nullptr, Z_Construct_UFunction_UPico_SportDailySummary_GetID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummary_GetID_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SportDailySummary_GetID_Statics::Pico_SportDailySummary_eventGetID_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummary_GetID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SportDailySummary_GetID_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummary_GetID_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SportDailySummary_GetID_Statics::Pico_SportDailySummary_eventGetID_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SportDailySummary_GetID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SportDailySummary_GetID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SportDailySummary_GetPlanCalorie_Statics
	{
		struct Pico_SportDailySummary_eventGetPlanCalorie_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPico_SportDailySummary_GetPlanCalorie_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SportDailySummary_eventGetPlanCalorie_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SportDailySummary_GetPlanCalorie_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SportDailySummary_GetPlanCalorie_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SportDailySummary_GetPlanCalorie_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Sport|Sport Daily Summary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The planned calorie to burn. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The planned calorie to burn." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SportDailySummary_GetPlanCalorie_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SportDailySummary, nullptr, "GetPlanCalorie", nullptr, nullptr, Z_Construct_UFunction_UPico_SportDailySummary_GetPlanCalorie_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummary_GetPlanCalorie_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SportDailySummary_GetPlanCalorie_Statics::Pico_SportDailySummary_eventGetPlanCalorie_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummary_GetPlanCalorie_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SportDailySummary_GetPlanCalorie_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummary_GetPlanCalorie_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SportDailySummary_GetPlanCalorie_Statics::Pico_SportDailySummary_eventGetPlanCalorie_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SportDailySummary_GetPlanCalorie()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SportDailySummary_GetPlanCalorie_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SportDailySummary_GetPlanDurationInMinutes_Statics
	{
		struct Pico_SportDailySummary_eventGetPlanDurationInMinutes_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_SportDailySummary_GetPlanDurationInMinutes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SportDailySummary_eventGetPlanDurationInMinutes_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SportDailySummary_GetPlanDurationInMinutes_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SportDailySummary_GetPlanDurationInMinutes_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SportDailySummary_GetPlanDurationInMinutes_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Sport|Sport Daily Summary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The planned sport duration (in seconds).*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The planned sport duration (in seconds)." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SportDailySummary_GetPlanDurationInMinutes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SportDailySummary, nullptr, "GetPlanDurationInMinutes", nullptr, nullptr, Z_Construct_UFunction_UPico_SportDailySummary_GetPlanDurationInMinutes_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummary_GetPlanDurationInMinutes_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SportDailySummary_GetPlanDurationInMinutes_Statics::Pico_SportDailySummary_eventGetPlanDurationInMinutes_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummary_GetPlanDurationInMinutes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SportDailySummary_GetPlanDurationInMinutes_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummary_GetPlanDurationInMinutes_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SportDailySummary_GetPlanDurationInMinutes_Statics::Pico_SportDailySummary_eventGetPlanDurationInMinutes_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SportDailySummary_GetPlanDurationInMinutes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SportDailySummary_GetPlanDurationInMinutes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_SportDailySummary);
	UClass* Z_Construct_UClass_UPico_SportDailySummary_NoRegister()
	{
		return UPico_SportDailySummary::StaticClass();
	}
	struct Z_Construct_UClass_UPico_SportDailySummary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_SportDailySummary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_SportDailySummary_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_SportDailySummary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_SportDailySummary_GetCalorie, "GetCalorie" }, // 4250835235
		{ &Z_Construct_UFunction_UPico_SportDailySummary_GetDate, "GetDate" }, // 3888378613
		{ &Z_Construct_UFunction_UPico_SportDailySummary_GetDurationInSeconds, "GetDurationInSeconds" }, // 1083755554
		{ &Z_Construct_UFunction_UPico_SportDailySummary_GetID, "GetID" }, // 1919946682
		{ &Z_Construct_UFunction_UPico_SportDailySummary_GetPlanCalorie, "GetPlanCalorie" }, // 2622109732
		{ &Z_Construct_UFunction_UPico_SportDailySummary_GetPlanDurationInMinutes, "GetPlanDurationInMinutes" }, // 1631486968
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_SportDailySummary_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_SportDailySummary_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_SportDailySummary class.\n" },
#endif
		{ "IncludePath", "Pico_Sport.h" },
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_SportDailySummary class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_SportDailySummary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_SportDailySummary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_SportDailySummary_Statics::ClassParams = {
		&UPico_SportDailySummary::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_SportDailySummary_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_SportDailySummary_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPico_SportDailySummary()
	{
		if (!Z_Registration_Info_UClass_UPico_SportDailySummary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_SportDailySummary.OuterSingleton, Z_Construct_UClass_UPico_SportDailySummary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_SportDailySummary.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_SportDailySummary>()
	{
		return UPico_SportDailySummary::StaticClass();
	}
	UPico_SportDailySummary::UPico_SportDailySummary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_SportDailySummary);
	UPico_SportDailySummary::~UPico_SportDailySummary() {}
	DEFINE_FUNCTION(UPico_SportDailySummaryArray::execGetElement)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPico_SportDailySummary**)Z_Param__Result=P_THIS->GetElement(Z_Param_Index);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SportDailySummaryArray::execGetSize)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetSize();
		P_NATIVE_END;
	}
	void UPico_SportDailySummaryArray::StaticRegisterNativesUPico_SportDailySummaryArray()
	{
		UClass* Class = UPico_SportDailySummaryArray::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetElement", &UPico_SportDailySummaryArray::execGetElement },
			{ "GetSize", &UPico_SportDailySummaryArray::execGetSize },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_SportDailySummaryArray_GetElement_Statics
	{
		struct Pico_SportDailySummaryArray_eventGetElement_Parms
		{
			int32 Index;
			UPico_SportDailySummary* ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_SportDailySummaryArray_GetElement_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SportDailySummaryArray_eventGetElement_Parms, Index), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPico_SportDailySummaryArray_GetElement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SportDailySummaryArray_eventGetElement_Parms, ReturnValue), Z_Construct_UClass_UPico_SportDailySummary_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SportDailySummaryArray_GetElement_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SportDailySummaryArray_GetElement_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SportDailySummaryArray_GetElement_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SportDailySummaryArray_GetElement_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Sport|Sport Daily Summary Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get SportDailySummaryArray element form Index.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get SportDailySummaryArray element form Index." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SportDailySummaryArray_GetElement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SportDailySummaryArray, nullptr, "GetElement", nullptr, nullptr, Z_Construct_UFunction_UPico_SportDailySummaryArray_GetElement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummaryArray_GetElement_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SportDailySummaryArray_GetElement_Statics::Pico_SportDailySummaryArray_eventGetElement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummaryArray_GetElement_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SportDailySummaryArray_GetElement_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummaryArray_GetElement_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SportDailySummaryArray_GetElement_Statics::Pico_SportDailySummaryArray_eventGetElement_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SportDailySummaryArray_GetElement()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SportDailySummaryArray_GetElement_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SportDailySummaryArray_GetSize_Statics
	{
		struct Pico_SportDailySummaryArray_eventGetSize_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_SportDailySummaryArray_GetSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SportDailySummaryArray_eventGetSize_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SportDailySummaryArray_GetSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SportDailySummaryArray_GetSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SportDailySummaryArray_GetSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Sport|Sport Daily Summary Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get the size of SportDailySummaryArray .*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get the size of SportDailySummaryArray ." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SportDailySummaryArray_GetSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SportDailySummaryArray, nullptr, "GetSize", nullptr, nullptr, Z_Construct_UFunction_UPico_SportDailySummaryArray_GetSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummaryArray_GetSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SportDailySummaryArray_GetSize_Statics::Pico_SportDailySummaryArray_eventGetSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummaryArray_GetSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SportDailySummaryArray_GetSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportDailySummaryArray_GetSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SportDailySummaryArray_GetSize_Statics::Pico_SportDailySummaryArray_eventGetSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SportDailySummaryArray_GetSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SportDailySummaryArray_GetSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_SportDailySummaryArray);
	UClass* Z_Construct_UClass_UPico_SportDailySummaryArray_NoRegister()
	{
		return UPico_SportDailySummaryArray::StaticClass();
	}
	struct Z_Construct_UClass_UPico_SportDailySummaryArray_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SportDailySummaryArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SportDailySummaryArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_SportDailySummaryArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_SportDailySummaryArray_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_SportDailySummaryArray_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_SportDailySummaryArray_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_SportDailySummaryArray_GetElement, "GetElement" }, // 267016550
		{ &Z_Construct_UFunction_UPico_SportDailySummaryArray_GetSize, "GetSize" }, // 3820177282
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_SportDailySummaryArray_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_SportDailySummaryArray_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_SportDailySummaryArray class.\n" },
#endif
		{ "IncludePath", "Pico_Sport.h" },
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_SportDailySummaryArray class." },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPico_SportDailySummaryArray_Statics::NewProp_SportDailySummaryArray_Inner = { "SportDailySummaryArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UPico_SportDailySummary_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_SportDailySummaryArray_Statics::NewProp_SportDailySummaryArray_MetaData[] = {
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPico_SportDailySummaryArray_Statics::NewProp_SportDailySummaryArray = { "SportDailySummaryArray", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPico_SportDailySummaryArray, SportDailySummaryArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_SportDailySummaryArray_Statics::NewProp_SportDailySummaryArray_MetaData), Z_Construct_UClass_UPico_SportDailySummaryArray_Statics::NewProp_SportDailySummaryArray_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPico_SportDailySummaryArray_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_SportDailySummaryArray_Statics::NewProp_SportDailySummaryArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_SportDailySummaryArray_Statics::NewProp_SportDailySummaryArray,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_SportDailySummaryArray_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_SportDailySummaryArray>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_SportDailySummaryArray_Statics::ClassParams = {
		&UPico_SportDailySummaryArray::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPico_SportDailySummaryArray_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPico_SportDailySummaryArray_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_SportDailySummaryArray_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_SportDailySummaryArray_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_SportDailySummaryArray_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPico_SportDailySummaryArray()
	{
		if (!Z_Registration_Info_UClass_UPico_SportDailySummaryArray.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_SportDailySummaryArray.OuterSingleton, Z_Construct_UClass_UPico_SportDailySummaryArray_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_SportDailySummaryArray.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_SportDailySummaryArray>()
	{
		return UPico_SportDailySummaryArray::StaticClass();
	}
	UPico_SportDailySummaryArray::UPico_SportDailySummaryArray(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_SportDailySummaryArray);
	UPico_SportDailySummaryArray::~UPico_SportDailySummaryArray() {}
	DEFINE_FUNCTION(UPico_SportSummary::execGetEndTime)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int64*)Z_Param__Result=P_THIS->GetEndTime();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SportSummary::execGetStartTime)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int64*)Z_Param__Result=P_THIS->GetStartTime();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SportSummary::execGetCalorie)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetCalorie();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SportSummary::execGetDurationInSeconds)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int64*)Z_Param__Result=P_THIS->GetDurationInSeconds();
		P_NATIVE_END;
	}
	void UPico_SportSummary::StaticRegisterNativesUPico_SportSummary()
	{
		UClass* Class = UPico_SportSummary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetCalorie", &UPico_SportSummary::execGetCalorie },
			{ "GetDurationInSeconds", &UPico_SportSummary::execGetDurationInSeconds },
			{ "GetEndTime", &UPico_SportSummary::execGetEndTime },
			{ "GetStartTime", &UPico_SportSummary::execGetStartTime },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_SportSummary_GetCalorie_Statics
	{
		struct Pico_SportSummary_eventGetCalorie_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPico_SportSummary_GetCalorie_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SportSummary_eventGetCalorie_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SportSummary_GetCalorie_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SportSummary_GetCalorie_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SportSummary_GetCalorie_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Sport|Sport Summary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The calorie burnt (in kilo calorie).*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The calorie burnt (in kilo calorie)." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SportSummary_GetCalorie_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SportSummary, nullptr, "GetCalorie", nullptr, nullptr, Z_Construct_UFunction_UPico_SportSummary_GetCalorie_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportSummary_GetCalorie_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SportSummary_GetCalorie_Statics::Pico_SportSummary_eventGetCalorie_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportSummary_GetCalorie_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SportSummary_GetCalorie_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportSummary_GetCalorie_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SportSummary_GetCalorie_Statics::Pico_SportSummary_eventGetCalorie_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SportSummary_GetCalorie()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SportSummary_GetCalorie_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SportSummary_GetDurationInSeconds_Statics
	{
		struct Pico_SportSummary_eventGetDurationInSeconds_Parms
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
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UPico_SportSummary_GetDurationInSeconds_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SportSummary_eventGetDurationInSeconds_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SportSummary_GetDurationInSeconds_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SportSummary_GetDurationInSeconds_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SportSummary_GetDurationInSeconds_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Sport|Sport Summary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The sport duration (in seconds).*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The sport duration (in seconds)." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SportSummary_GetDurationInSeconds_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SportSummary, nullptr, "GetDurationInSeconds", nullptr, nullptr, Z_Construct_UFunction_UPico_SportSummary_GetDurationInSeconds_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportSummary_GetDurationInSeconds_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SportSummary_GetDurationInSeconds_Statics::Pico_SportSummary_eventGetDurationInSeconds_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportSummary_GetDurationInSeconds_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SportSummary_GetDurationInSeconds_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportSummary_GetDurationInSeconds_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SportSummary_GetDurationInSeconds_Statics::Pico_SportSummary_eventGetDurationInSeconds_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SportSummary_GetDurationInSeconds()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SportSummary_GetDurationInSeconds_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SportSummary_GetEndTime_Statics
	{
		struct Pico_SportSummary_eventGetEndTime_Parms
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
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UPico_SportSummary_GetEndTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SportSummary_eventGetEndTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SportSummary_GetEndTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SportSummary_GetEndTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SportSummary_GetEndTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Sport|Sport Summary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The time when the user stopped playing sport.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The time when the user stopped playing sport." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SportSummary_GetEndTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SportSummary, nullptr, "GetEndTime", nullptr, nullptr, Z_Construct_UFunction_UPico_SportSummary_GetEndTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportSummary_GetEndTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SportSummary_GetEndTime_Statics::Pico_SportSummary_eventGetEndTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportSummary_GetEndTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SportSummary_GetEndTime_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportSummary_GetEndTime_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SportSummary_GetEndTime_Statics::Pico_SportSummary_eventGetEndTime_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SportSummary_GetEndTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SportSummary_GetEndTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SportSummary_GetStartTime_Statics
	{
		struct Pico_SportSummary_eventGetStartTime_Parms
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
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UPico_SportSummary_GetStartTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SportSummary_eventGetStartTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SportSummary_GetStartTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SportSummary_GetStartTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SportSummary_GetStartTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Sport|Sport Summary" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The time when the user started playing sport.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The time when the user started playing sport." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SportSummary_GetStartTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SportSummary, nullptr, "GetStartTime", nullptr, nullptr, Z_Construct_UFunction_UPico_SportSummary_GetStartTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportSummary_GetStartTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SportSummary_GetStartTime_Statics::Pico_SportSummary_eventGetStartTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportSummary_GetStartTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SportSummary_GetStartTime_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportSummary_GetStartTime_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SportSummary_GetStartTime_Statics::Pico_SportSummary_eventGetStartTime_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SportSummary_GetStartTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SportSummary_GetStartTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_SportSummary);
	UClass* Z_Construct_UClass_UPico_SportSummary_NoRegister()
	{
		return UPico_SportSummary::StaticClass();
	}
	struct Z_Construct_UClass_UPico_SportSummary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_SportSummary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_SportSummary_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_SportSummary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_SportSummary_GetCalorie, "GetCalorie" }, // 2241985216
		{ &Z_Construct_UFunction_UPico_SportSummary_GetDurationInSeconds, "GetDurationInSeconds" }, // 1365042875
		{ &Z_Construct_UFunction_UPico_SportSummary_GetEndTime, "GetEndTime" }, // 3349884197
		{ &Z_Construct_UFunction_UPico_SportSummary_GetStartTime, "GetStartTime" }, // 2521695180
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_SportSummary_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_SportSummary_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_SportSummary class.\n" },
#endif
		{ "IncludePath", "Pico_Sport.h" },
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_SportSummary class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_SportSummary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_SportSummary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_SportSummary_Statics::ClassParams = {
		&UPico_SportSummary::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_SportSummary_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_SportSummary_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPico_SportSummary()
	{
		if (!Z_Registration_Info_UClass_UPico_SportSummary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_SportSummary.OuterSingleton, Z_Construct_UClass_UPico_SportSummary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_SportSummary.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_SportSummary>()
	{
		return UPico_SportSummary::StaticClass();
	}
	UPico_SportSummary::UPico_SportSummary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_SportSummary);
	UPico_SportSummary::~UPico_SportSummary() {}
	DEFINE_FUNCTION(UPico_SportUserInfo::execGetSportTarget)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ESportTarget*)Z_Param__Result=P_THIS->GetSportTarget();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SportUserInfo::execGetDaysPerWeek)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetDaysPerWeek();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SportUserInfo::execGetDailyDurationInMinutes)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetDailyDurationInMinutes();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SportUserInfo::execGetSportLevel)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetSportLevel();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SportUserInfo::execGetWeight)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetWeight();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SportUserInfo::execGetStature)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetStature();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SportUserInfo::execGetBirthday)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int64*)Z_Param__Result=P_THIS->GetBirthday();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SportUserInfo::execGetGender)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EUserGender*)Z_Param__Result=P_THIS->GetGender();
		P_NATIVE_END;
	}
	void UPico_SportUserInfo::StaticRegisterNativesUPico_SportUserInfo()
	{
		UClass* Class = UPico_SportUserInfo::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetBirthday", &UPico_SportUserInfo::execGetBirthday },
			{ "GetDailyDurationInMinutes", &UPico_SportUserInfo::execGetDailyDurationInMinutes },
			{ "GetDaysPerWeek", &UPico_SportUserInfo::execGetDaysPerWeek },
			{ "GetGender", &UPico_SportUserInfo::execGetGender },
			{ "GetSportLevel", &UPico_SportUserInfo::execGetSportLevel },
			{ "GetSportTarget", &UPico_SportUserInfo::execGetSportTarget },
			{ "GetStature", &UPico_SportUserInfo::execGetStature },
			{ "GetWeight", &UPico_SportUserInfo::execGetWeight },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_SportUserInfo_GetBirthday_Statics
	{
		struct Pico_SportUserInfo_eventGetBirthday_Parms
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
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UPico_SportUserInfo_GetBirthday_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SportUserInfo_eventGetBirthday_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SportUserInfo_GetBirthday_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SportUserInfo_GetBirthday_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SportUserInfo_GetBirthday_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Sport|User Info" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief The birthday of the user (in cm). */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The birthday of the user (in cm)." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SportUserInfo_GetBirthday_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SportUserInfo, nullptr, "GetBirthday", nullptr, nullptr, Z_Construct_UFunction_UPico_SportUserInfo_GetBirthday_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetBirthday_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SportUserInfo_GetBirthday_Statics::Pico_SportUserInfo_eventGetBirthday_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetBirthday_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SportUserInfo_GetBirthday_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetBirthday_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SportUserInfo_GetBirthday_Statics::Pico_SportUserInfo_eventGetBirthday_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SportUserInfo_GetBirthday()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SportUserInfo_GetBirthday_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SportUserInfo_GetDailyDurationInMinutes_Statics
	{
		struct Pico_SportUserInfo_eventGetDailyDurationInMinutes_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_SportUserInfo_GetDailyDurationInMinutes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SportUserInfo_eventGetDailyDurationInMinutes_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SportUserInfo_GetDailyDurationInMinutes_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SportUserInfo_GetDailyDurationInMinutes_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SportUserInfo_GetDailyDurationInMinutes_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Sport|User Info" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The planned daily sport duration (in minutes).*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The planned daily sport duration (in minutes)." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SportUserInfo_GetDailyDurationInMinutes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SportUserInfo, nullptr, "GetDailyDurationInMinutes", nullptr, nullptr, Z_Construct_UFunction_UPico_SportUserInfo_GetDailyDurationInMinutes_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetDailyDurationInMinutes_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SportUserInfo_GetDailyDurationInMinutes_Statics::Pico_SportUserInfo_eventGetDailyDurationInMinutes_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetDailyDurationInMinutes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SportUserInfo_GetDailyDurationInMinutes_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetDailyDurationInMinutes_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SportUserInfo_GetDailyDurationInMinutes_Statics::Pico_SportUserInfo_eventGetDailyDurationInMinutes_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SportUserInfo_GetDailyDurationInMinutes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SportUserInfo_GetDailyDurationInMinutes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SportUserInfo_GetDaysPerWeek_Statics
	{
		struct Pico_SportUserInfo_eventGetDaysPerWeek_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_SportUserInfo_GetDaysPerWeek_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SportUserInfo_eventGetDaysPerWeek_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SportUserInfo_GetDaysPerWeek_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SportUserInfo_GetDaysPerWeek_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SportUserInfo_GetDaysPerWeek_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Sport|User Info" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The planned weekly sport days.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The planned weekly sport days." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SportUserInfo_GetDaysPerWeek_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SportUserInfo, nullptr, "GetDaysPerWeek", nullptr, nullptr, Z_Construct_UFunction_UPico_SportUserInfo_GetDaysPerWeek_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetDaysPerWeek_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SportUserInfo_GetDaysPerWeek_Statics::Pico_SportUserInfo_eventGetDaysPerWeek_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetDaysPerWeek_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SportUserInfo_GetDaysPerWeek_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetDaysPerWeek_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SportUserInfo_GetDaysPerWeek_Statics::Pico_SportUserInfo_eventGetDaysPerWeek_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SportUserInfo_GetDaysPerWeek()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SportUserInfo_GetDaysPerWeek_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SportUserInfo_GetGender_Statics
	{
		struct Pico_SportUserInfo_eventGetGender_Parms
		{
			EUserGender ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPico_SportUserInfo_GetGender_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPico_SportUserInfo_GetGender_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SportUserInfo_eventGetGender_Parms, ReturnValue), Z_Construct_UEnum_OnlineSubsystemPico_EUserGender, METADATA_PARAMS(0, nullptr) }; // 2253103228
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SportUserInfo_GetGender_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SportUserInfo_GetGender_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SportUserInfo_GetGender_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SportUserInfo_GetGender_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Sport|User Info" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief The gender of the user (in cm). */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The gender of the user (in cm)." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SportUserInfo_GetGender_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SportUserInfo, nullptr, "GetGender", nullptr, nullptr, Z_Construct_UFunction_UPico_SportUserInfo_GetGender_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetGender_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SportUserInfo_GetGender_Statics::Pico_SportUserInfo_eventGetGender_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetGender_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SportUserInfo_GetGender_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetGender_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SportUserInfo_GetGender_Statics::Pico_SportUserInfo_eventGetGender_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SportUserInfo_GetGender()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SportUserInfo_GetGender_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SportUserInfo_GetSportLevel_Statics
	{
		struct Pico_SportUserInfo_eventGetSportLevel_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_SportUserInfo_GetSportLevel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SportUserInfo_eventGetSportLevel_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SportUserInfo_GetSportLevel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SportUserInfo_GetSportLevel_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SportUserInfo_GetSportLevel_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Sport|User Info" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The sport level that indicates the intensity of the sport.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The sport level that indicates the intensity of the sport." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SportUserInfo_GetSportLevel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SportUserInfo, nullptr, "GetSportLevel", nullptr, nullptr, Z_Construct_UFunction_UPico_SportUserInfo_GetSportLevel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetSportLevel_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SportUserInfo_GetSportLevel_Statics::Pico_SportUserInfo_eventGetSportLevel_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetSportLevel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SportUserInfo_GetSportLevel_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetSportLevel_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SportUserInfo_GetSportLevel_Statics::Pico_SportUserInfo_eventGetSportLevel_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SportUserInfo_GetSportLevel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SportUserInfo_GetSportLevel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SportUserInfo_GetSportTarget_Statics
	{
		struct Pico_SportUserInfo_eventGetSportTarget_Parms
		{
			ESportTarget ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPico_SportUserInfo_GetSportTarget_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPico_SportUserInfo_GetSportTarget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SportUserInfo_eventGetSportTarget_Parms, ReturnValue), Z_Construct_UEnum_OnlineSubsystemPico_ESportTarget, METADATA_PARAMS(0, nullptr) }; // 2745771092
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SportUserInfo_GetSportTarget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SportUserInfo_GetSportTarget_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SportUserInfo_GetSportTarget_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SportUserInfo_GetSportTarget_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Sport|User Info" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The sport purpose, such as `keep fit` and `lose weight`. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The sport purpose, such as `keep fit` and `lose weight`." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SportUserInfo_GetSportTarget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SportUserInfo, nullptr, "GetSportTarget", nullptr, nullptr, Z_Construct_UFunction_UPico_SportUserInfo_GetSportTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetSportTarget_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SportUserInfo_GetSportTarget_Statics::Pico_SportUserInfo_eventGetSportTarget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetSportTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SportUserInfo_GetSportTarget_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetSportTarget_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SportUserInfo_GetSportTarget_Statics::Pico_SportUserInfo_eventGetSportTarget_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SportUserInfo_GetSportTarget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SportUserInfo_GetSportTarget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SportUserInfo_GetStature_Statics
	{
		struct Pico_SportUserInfo_eventGetStature_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_SportUserInfo_GetStature_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SportUserInfo_eventGetStature_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SportUserInfo_GetStature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SportUserInfo_GetStature_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SportUserInfo_GetStature_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Sport|User Info" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief The height of the user (in cm). */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The height of the user (in cm)." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SportUserInfo_GetStature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SportUserInfo, nullptr, "GetStature", nullptr, nullptr, Z_Construct_UFunction_UPico_SportUserInfo_GetStature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetStature_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SportUserInfo_GetStature_Statics::Pico_SportUserInfo_eventGetStature_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetStature_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SportUserInfo_GetStature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetStature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SportUserInfo_GetStature_Statics::Pico_SportUserInfo_eventGetStature_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SportUserInfo_GetStature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SportUserInfo_GetStature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SportUserInfo_GetWeight_Statics
	{
		struct Pico_SportUserInfo_eventGetWeight_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_SportUserInfo_GetWeight_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SportUserInfo_eventGetWeight_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SportUserInfo_GetWeight_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SportUserInfo_GetWeight_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SportUserInfo_GetWeight_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Sport|User Info" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief The weight of the user (in kg). */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The weight of the user (in kg)." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SportUserInfo_GetWeight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SportUserInfo, nullptr, "GetWeight", nullptr, nullptr, Z_Construct_UFunction_UPico_SportUserInfo_GetWeight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetWeight_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SportUserInfo_GetWeight_Statics::Pico_SportUserInfo_eventGetWeight_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetWeight_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SportUserInfo_GetWeight_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SportUserInfo_GetWeight_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SportUserInfo_GetWeight_Statics::Pico_SportUserInfo_eventGetWeight_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SportUserInfo_GetWeight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SportUserInfo_GetWeight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_SportUserInfo);
	UClass* Z_Construct_UClass_UPico_SportUserInfo_NoRegister()
	{
		return UPico_SportUserInfo::StaticClass();
	}
	struct Z_Construct_UClass_UPico_SportUserInfo_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_SportUserInfo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_SportUserInfo_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_SportUserInfo_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_SportUserInfo_GetBirthday, "GetBirthday" }, // 3048280683
		{ &Z_Construct_UFunction_UPico_SportUserInfo_GetDailyDurationInMinutes, "GetDailyDurationInMinutes" }, // 398807618
		{ &Z_Construct_UFunction_UPico_SportUserInfo_GetDaysPerWeek, "GetDaysPerWeek" }, // 850202172
		{ &Z_Construct_UFunction_UPico_SportUserInfo_GetGender, "GetGender" }, // 3073528621
		{ &Z_Construct_UFunction_UPico_SportUserInfo_GetSportLevel, "GetSportLevel" }, // 121913961
		{ &Z_Construct_UFunction_UPico_SportUserInfo_GetSportTarget, "GetSportTarget" }, // 2758550245
		{ &Z_Construct_UFunction_UPico_SportUserInfo_GetStature, "GetStature" }, // 3215047138
		{ &Z_Construct_UFunction_UPico_SportUserInfo_GetWeight, "GetWeight" }, // 3166060675
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_SportUserInfo_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_SportUserInfo_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_SportUserInfo class.\n" },
#endif
		{ "IncludePath", "Pico_Sport.h" },
		{ "ModuleRelativePath", "Public/Pico_Sport.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_SportUserInfo class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_SportUserInfo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_SportUserInfo>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_SportUserInfo_Statics::ClassParams = {
		&UPico_SportUserInfo::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_SportUserInfo_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_SportUserInfo_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPico_SportUserInfo()
	{
		if (!Z_Registration_Info_UClass_UPico_SportUserInfo.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_SportUserInfo.OuterSingleton, Z_Construct_UClass_UPico_SportUserInfo_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_SportUserInfo.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_SportUserInfo>()
	{
		return UPico_SportUserInfo::StaticClass();
	}
	UPico_SportUserInfo::UPico_SportUserInfo(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_SportUserInfo);
	UPico_SportUserInfo::~UPico_SportUserInfo() {}
	struct Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Sport_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Sport_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOnlinePicoSportFunction, UOnlinePicoSportFunction::StaticClass, TEXT("UOnlinePicoSportFunction"), &Z_Registration_Info_UClass_UOnlinePicoSportFunction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOnlinePicoSportFunction), 2828558453U) },
		{ Z_Construct_UClass_UPico_SportDailySummary, UPico_SportDailySummary::StaticClass, TEXT("UPico_SportDailySummary"), &Z_Registration_Info_UClass_UPico_SportDailySummary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_SportDailySummary), 2553706980U) },
		{ Z_Construct_UClass_UPico_SportDailySummaryArray, UPico_SportDailySummaryArray::StaticClass, TEXT("UPico_SportDailySummaryArray"), &Z_Registration_Info_UClass_UPico_SportDailySummaryArray, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_SportDailySummaryArray), 152299030U) },
		{ Z_Construct_UClass_UPico_SportSummary, UPico_SportSummary::StaticClass, TEXT("UPico_SportSummary"), &Z_Registration_Info_UClass_UPico_SportSummary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_SportSummary), 4269594011U) },
		{ Z_Construct_UClass_UPico_SportUserInfo, UPico_SportUserInfo::StaticClass, TEXT("UPico_SportUserInfo"), &Z_Registration_Info_UClass_UPico_SportUserInfo, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_SportUserInfo), 2493275059U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Sport_h_3846020263(TEXT("/Script/OnlineSubsystemPico"),
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Sport_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Sport_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
