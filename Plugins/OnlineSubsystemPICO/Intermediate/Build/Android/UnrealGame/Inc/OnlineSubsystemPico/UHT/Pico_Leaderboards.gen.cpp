// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../OnlineSubsystemPico/Public/Pico_Leaderboards.h"
#include "../../OnlineSubsystemPico/Public/OnlineSubsystemPicoNames.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePico_Leaderboards() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoLeaderboardsFunction();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoLeaderboardsFunction_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_Leaderboard();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_Leaderboard_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_LeaderboardArray();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_LeaderboardArray_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_LeaderboardEntry();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_LeaderboardEntry_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_LeaderboardEntryArray();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_LeaderboardEntryArray_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_User_NoRegister();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ELeaderboardFilterType();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ELeaderboardStartAt();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UScriptStruct* Z_Construct_UScriptStruct_FPicoDestination();
	ONLINESUBSYSTEMPICO_API UScriptStruct* Z_Construct_UScriptStruct_FPicoSupplementaryMetric();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemPico();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGet_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_LeaderboardArray* LeaderboardList;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LeaderboardList;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGet_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGet_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGet_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature_Statics::NewProp_LeaderboardList = { "LeaderboardList", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGet_Parms, LeaderboardList), Z_Construct_UClass_UPico_LeaderboardArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature_Statics::NewProp_LeaderboardList,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "Get__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGet_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGet_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGet_DelegateWrapper(const FScriptDelegate& Get, bool bIsError, const FString& ErrorMessage, UPico_LeaderboardArray* LeaderboardList)
{
	struct _Script_OnlineSubsystemPico_eventGet_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_LeaderboardArray* LeaderboardList;
	};
	_Script_OnlineSubsystemPico_eventGet_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.LeaderboardList=LeaderboardList;
	Get.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetEntries_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_LeaderboardEntryArray* LeaderboardEntryList;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LeaderboardEntryList;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetEntries_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetEntries_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetEntries_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature_Statics::NewProp_LeaderboardEntryList = { "LeaderboardEntryList", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetEntries_Parms, LeaderboardEntryList), Z_Construct_UClass_UPico_LeaderboardEntryArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature_Statics::NewProp_LeaderboardEntryList,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetEntries__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetEntries_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetEntries_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetEntries_DelegateWrapper(const FScriptDelegate& GetEntries, bool bIsError, const FString& ErrorMessage, UPico_LeaderboardEntryArray* LeaderboardEntryList)
{
	struct _Script_OnlineSubsystemPico_eventGetEntries_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_LeaderboardEntryArray* LeaderboardEntryList;
	};
	_Script_OnlineSubsystemPico_eventGetEntries_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.LeaderboardEntryList=LeaderboardEntryList;
	GetEntries.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetEntriesAfterRank_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_LeaderboardEntryArray* LeaderboardEntryList;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LeaderboardEntryList;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetEntriesAfterRank_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetEntriesAfterRank_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetEntriesAfterRank_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature_Statics::NewProp_LeaderboardEntryList = { "LeaderboardEntryList", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetEntriesAfterRank_Parms, LeaderboardEntryList), Z_Construct_UClass_UPico_LeaderboardEntryArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature_Statics::NewProp_LeaderboardEntryList,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetEntriesAfterRank__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetEntriesAfterRank_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetEntriesAfterRank_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetEntriesAfterRank_DelegateWrapper(const FScriptDelegate& GetEntriesAfterRank, bool bIsError, const FString& ErrorMessage, UPico_LeaderboardEntryArray* LeaderboardEntryList)
{
	struct _Script_OnlineSubsystemPico_eventGetEntriesAfterRank_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_LeaderboardEntryArray* LeaderboardEntryList;
	};
	_Script_OnlineSubsystemPico_eventGetEntriesAfterRank_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.LeaderboardEntryList=LeaderboardEntryList;
	GetEntriesAfterRank.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetEntriesByIds_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_LeaderboardEntryArray* LeaderboardEntryList;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LeaderboardEntryList;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetEntriesByIds_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetEntriesByIds_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetEntriesByIds_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature_Statics::NewProp_LeaderboardEntryList = { "LeaderboardEntryList", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetEntriesByIds_Parms, LeaderboardEntryList), Z_Construct_UClass_UPico_LeaderboardEntryArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature_Statics::NewProp_LeaderboardEntryList,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetEntriesByIds__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetEntriesByIds_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetEntriesByIds_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetEntriesByIds_DelegateWrapper(const FScriptDelegate& GetEntriesByIds, bool bIsError, const FString& ErrorMessage, UPico_LeaderboardEntryArray* LeaderboardEntryList)
{
	struct _Script_OnlineSubsystemPico_eventGetEntriesByIds_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_LeaderboardEntryArray* LeaderboardEntryList;
	};
	_Script_OnlineSubsystemPico_eventGetEntriesByIds_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.LeaderboardEntryList=LeaderboardEntryList;
	GetEntriesByIds.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventWriteEntry_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			bool WriteResult;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static void NewProp_WriteResult_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_WriteResult;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventWriteEntry_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventWriteEntry_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventWriteEntry_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::NewProp_WriteResult_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventWriteEntry_Parms*)Obj)->WriteResult = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::NewProp_WriteResult = { "WriteResult", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventWriteEntry_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::NewProp_WriteResult_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::NewProp_WriteResult,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "WriteEntry__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventWriteEntry_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventWriteEntry_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FWriteEntry_DelegateWrapper(const FScriptDelegate& WriteEntry, bool bIsError, const FString& ErrorMessage, bool WriteResult)
{
	struct _Script_OnlineSubsystemPico_eventWriteEntry_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		bool WriteResult;
	};
	_Script_OnlineSubsystemPico_eventWriteEntry_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.WriteResult=WriteResult ? true : false;
	WriteEntry.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventWriteEntryWithSupplementaryMetric_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			bool WriteResult;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static void NewProp_WriteResult_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_WriteResult;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventWriteEntryWithSupplementaryMetric_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventWriteEntryWithSupplementaryMetric_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventWriteEntryWithSupplementaryMetric_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::NewProp_WriteResult_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventWriteEntryWithSupplementaryMetric_Parms*)Obj)->WriteResult = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::NewProp_WriteResult = { "WriteResult", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventWriteEntryWithSupplementaryMetric_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::NewProp_WriteResult_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::NewProp_WriteResult,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "WriteEntryWithSupplementaryMetric__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventWriteEntryWithSupplementaryMetric_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventWriteEntryWithSupplementaryMetric_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FWriteEntryWithSupplementaryMetric_DelegateWrapper(const FScriptDelegate& WriteEntryWithSupplementaryMetric, bool bIsError, const FString& ErrorMessage, bool WriteResult)
{
	struct _Script_OnlineSubsystemPico_eventWriteEntryWithSupplementaryMetric_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		bool WriteResult;
	};
	_Script_OnlineSubsystemPico_eventWriteEntryWithSupplementaryMetric_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.WriteResult=WriteResult ? true : false;
	WriteEntryWithSupplementaryMetric.ProcessDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UOnlinePicoLeaderboardsFunction::execWriteEntryWithSupplementaryMetric)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_LeaderboardName);
		P_GET_PROPERTY(FStrProperty,Z_Param_Score);
		P_GET_PROPERTY(FStrProperty,Z_Param_SupplementaryMetric);
		P_GET_PROPERTY(FStrProperty,Z_Param_ExtraData);
		P_GET_UBOOL(Z_Param_ForceUpdate);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InWriteEntryWithSupplementaryMetricDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoLeaderboardsFunction::WriteEntryWithSupplementaryMetric(Z_Param_WorldContextObject,Z_Param_LeaderboardName,Z_Param_Score,Z_Param_SupplementaryMetric,Z_Param_ExtraData,Z_Param_ForceUpdate,FWriteEntryWithSupplementaryMetric(Z_Param_InWriteEntryWithSupplementaryMetricDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoLeaderboardsFunction::execWriteEntry)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_LeaderboardName);
		P_GET_PROPERTY(FStrProperty,Z_Param_Score);
		P_GET_PROPERTY(FStrProperty,Z_Param_ExtraData);
		P_GET_UBOOL(Z_Param_ForceUpdate);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InWriteEntryDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoLeaderboardsFunction::WriteEntry(Z_Param_WorldContextObject,Z_Param_LeaderboardName,Z_Param_Score,Z_Param_ExtraData,Z_Param_ForceUpdate,FWriteEntry(Z_Param_InWriteEntryDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoLeaderboardsFunction::execGetEntriesByIds)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_LeaderboardName);
		P_GET_PROPERTY(FIntProperty,Z_Param_PageIdx);
		P_GET_PROPERTY(FIntProperty,Z_Param_PageSize);
		P_GET_ENUM(ELeaderboardStartAt,Z_Param_StartAt);
		P_GET_TARRAY_REF(FString,Z_Param_Out_UserIDs);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetEntriesByIdsDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoLeaderboardsFunction::GetEntriesByIds(Z_Param_WorldContextObject,Z_Param_LeaderboardName,Z_Param_PageIdx,Z_Param_PageSize,ELeaderboardStartAt(Z_Param_StartAt),Z_Param_Out_UserIDs,FGetEntriesByIds(Z_Param_InGetEntriesByIdsDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoLeaderboardsFunction::execGetEntriesAfterRank)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_LeaderboardName);
		P_GET_PROPERTY(FIntProperty,Z_Param_PageIdx);
		P_GET_PROPERTY(FIntProperty,Z_Param_PageSize);
		P_GET_PROPERTY(FStrProperty,Z_Param_AfterRank);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetEntriesAfterRankDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoLeaderboardsFunction::GetEntriesAfterRank(Z_Param_WorldContextObject,Z_Param_LeaderboardName,Z_Param_PageIdx,Z_Param_PageSize,Z_Param_AfterRank,FGetEntriesAfterRank(Z_Param_InGetEntriesAfterRankDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoLeaderboardsFunction::execGetEntries)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_LeaderboardName);
		P_GET_PROPERTY(FIntProperty,Z_Param_PageIdx);
		P_GET_PROPERTY(FIntProperty,Z_Param_PageSize);
		P_GET_ENUM(ELeaderboardFilterType,Z_Param_Filter);
		P_GET_ENUM(ELeaderboardStartAt,Z_Param_StartAt);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetEntriesDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoLeaderboardsFunction::GetEntries(Z_Param_WorldContextObject,Z_Param_LeaderboardName,Z_Param_PageIdx,Z_Param_PageSize,ELeaderboardFilterType(Z_Param_Filter),ELeaderboardStartAt(Z_Param_StartAt),FGetEntries(Z_Param_InGetEntriesDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoLeaderboardsFunction::execGet)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_LeaderboardName);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoLeaderboardsFunction::Get(Z_Param_WorldContextObject,Z_Param_LeaderboardName,FGet(Z_Param_InGetDelegate));
		P_NATIVE_END;
	}
	void UOnlinePicoLeaderboardsFunction::StaticRegisterNativesUOnlinePicoLeaderboardsFunction()
	{
		UClass* Class = UOnlinePicoLeaderboardsFunction::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Get", &UOnlinePicoLeaderboardsFunction::execGet },
			{ "GetEntries", &UOnlinePicoLeaderboardsFunction::execGetEntries },
			{ "GetEntriesAfterRank", &UOnlinePicoLeaderboardsFunction::execGetEntriesAfterRank },
			{ "GetEntriesByIds", &UOnlinePicoLeaderboardsFunction::execGetEntriesByIds },
			{ "WriteEntry", &UOnlinePicoLeaderboardsFunction::execWriteEntry },
			{ "WriteEntryWithSupplementaryMetric", &UOnlinePicoLeaderboardsFunction::execWriteEntryWithSupplementaryMetric },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_Get_Statics
	{
		struct OnlinePicoLeaderboardsFunction_eventGet_Parms
		{
			UObject* WorldContextObject;
			FString LeaderboardName;
			FScriptDelegate InGetDelegate;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LeaderboardName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_LeaderboardName;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetDelegate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_Get_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventGet_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_Get_Statics::NewProp_LeaderboardName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_Get_Statics::NewProp_LeaderboardName = { "LeaderboardName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventGet_Parms, LeaderboardName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_Get_Statics::NewProp_LeaderboardName_MetaData), Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_Get_Statics::NewProp_LeaderboardName_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_Get_Statics::NewProp_InGetDelegate = { "InGetDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventGet_Parms, InGetDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_Get__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1699767531
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_Get_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_Get_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_Get_Statics::NewProp_LeaderboardName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_Get_Statics::NewProp_InGetDelegate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_Get_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Leaderboards" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets a specified leaderboard.</summary>\n/// <param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"leaderboardName\">Leaderboard name.</param>\n/// <param name=\"InGetDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_LeaderboardArray *, LeaderboardList).</param>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets a specified leaderboard.</summary>\n<param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"leaderboardName\">Leaderboard name.</param>\n<param name=\"InGetDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_LeaderboardArray *, LeaderboardList).</param>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_Get_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoLeaderboardsFunction, nullptr, "Get", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_Get_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_Get_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_Get_Statics::OnlinePicoLeaderboardsFunction_eventGet_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_Get_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_Get_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_Get_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_Get_Statics::OnlinePicoLeaderboardsFunction_eventGet_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_Get()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_Get_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics
	{
		struct OnlinePicoLeaderboardsFunction_eventGetEntries_Parms
		{
			UObject* WorldContextObject;
			FString LeaderboardName;
			int32 PageIdx;
			int32 PageSize;
			ELeaderboardFilterType Filter;
			ELeaderboardStartAt StartAt;
			FScriptDelegate InGetEntriesDelegate;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LeaderboardName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_LeaderboardName;
		static const UECodeGen_Private::FIntPropertyParams NewProp_PageIdx;
		static const UECodeGen_Private::FIntPropertyParams NewProp_PageSize;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Filter_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Filter;
		static const UECodeGen_Private::FBytePropertyParams NewProp_StartAt_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_StartAt;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetEntriesDelegate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventGetEntries_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::NewProp_LeaderboardName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::NewProp_LeaderboardName = { "LeaderboardName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventGetEntries_Parms, LeaderboardName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::NewProp_LeaderboardName_MetaData), Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::NewProp_LeaderboardName_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::NewProp_PageIdx = { "PageIdx", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventGetEntries_Parms, PageIdx), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::NewProp_PageSize = { "PageSize", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventGetEntries_Parms, PageSize), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::NewProp_Filter_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::NewProp_Filter = { "Filter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventGetEntries_Parms, Filter), Z_Construct_UEnum_OnlineSubsystemPico_ELeaderboardFilterType, METADATA_PARAMS(0, nullptr) }; // 2550994441
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::NewProp_StartAt_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::NewProp_StartAt = { "StartAt", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventGetEntries_Parms, StartAt), Z_Construct_UEnum_OnlineSubsystemPico_ELeaderboardStartAt, METADATA_PARAMS(0, nullptr) }; // 2656628965
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::NewProp_InGetEntriesDelegate = { "InGetEntriesDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventGetEntries_Parms, InGetEntriesDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntries__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2148177513
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::NewProp_LeaderboardName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::NewProp_PageIdx,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::NewProp_PageSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::NewProp_Filter_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::NewProp_Filter,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::NewProp_StartAt_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::NewProp_StartAt,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::NewProp_InGetEntriesDelegate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Leaderboards" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets a list of leaderboard entries.</summary>\n/// <param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"leaderboardName\">Leaderboard name.</param>\n/// <param name=\"pageSize\">The number of entries to return on each page. The value ranges from 1 to 100.</param>\n/// <param name=\"pageIdx\">Defines which page of entries to return. The value = (The target page No.)-1.\n/// For example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>\n/// <param name=\"filter\">Restricts the scope of entries to return:\n/// * `NONE`: returns all entries of the specified leaderboard\n/// * `FRIENDS`: returns the entries of the friends of the current logged-in user\n/// * `USER_IDS`(do not pass this value): returns the entries of specified users\n/// </param>\n/// <param name=\"startAt\">Defines where to start returning challenge entries, the enumerations are:\n/// * `0`: Top (return entries from top 1)\n/// * `1`: CenteredOnViewer (place the current logged-in user's entry in the middle of the list on the first page.\n/// For example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5, the ranks displayed\n/// on the first page will be top 3, 4, 5, 6, and 7. Top 1 and 2 will not be displayed, and top 8, 9, and 10 will be\n/// displayed on the second page)\n/// * `2`: CenteredOnViewerOrTop (place the current logged-in user's entry on the top of the list on the first page.\n/// For example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5,\n/// the ranks displayed on the first page will be top 5, 6, 7, 8, and 9. Top 1, 2, 3, and 4 will not be displayed,\n/// and top 10 will be displayed on the second page)\n/// </param>\n/// <param name=\"InGetEntriesDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_LeaderboardEntryArray *, LeaderboardEntryList).</param>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets a list of leaderboard entries.</summary>\n<param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"leaderboardName\">Leaderboard name.</param>\n<param name=\"pageSize\">The number of entries to return on each page. The value ranges from 1 to 100.</param>\n<param name=\"pageIdx\">Defines which page of entries to return. The value = (The target page No.)-1.\nFor example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>\n<param name=\"filter\">Restricts the scope of entries to return:\n* `NONE`: returns all entries of the specified leaderboard\n* `FRIENDS`: returns the entries of the friends of the current logged-in user\n* `USER_IDS`(do not pass this value): returns the entries of specified users\n</param>\n<param name=\"startAt\">Defines where to start returning challenge entries, the enumerations are:\n* `0`: Top (return entries from top 1)\n* `1`: CenteredOnViewer (place the current logged-in user's entry in the middle of the list on the first page.\nFor example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5, the ranks displayed\non the first page will be top 3, 4, 5, 6, and 7. Top 1 and 2 will not be displayed, and top 8, 9, and 10 will be\ndisplayed on the second page)\n* `2`: CenteredOnViewerOrTop (place the current logged-in user's entry on the top of the list on the first page.\nFor example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5,\nthe ranks displayed on the first page will be top 5, 6, 7, 8, and 9. Top 1, 2, 3, and 4 will not be displayed,\nand top 10 will be displayed on the second page)\n</param>\n<param name=\"InGetEntriesDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_LeaderboardEntryArray *, LeaderboardEntryList).</param>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoLeaderboardsFunction, nullptr, "GetEntries", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::OnlinePicoLeaderboardsFunction_eventGetEntries_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::OnlinePicoLeaderboardsFunction_eventGetEntries_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics
	{
		struct OnlinePicoLeaderboardsFunction_eventGetEntriesAfterRank_Parms
		{
			UObject* WorldContextObject;
			FString LeaderboardName;
			int32 PageIdx;
			int32 PageSize;
			FString AfterRank;
			FScriptDelegate InGetEntriesAfterRankDelegate;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LeaderboardName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_LeaderboardName;
		static const UECodeGen_Private::FIntPropertyParams NewProp_PageIdx;
		static const UECodeGen_Private::FIntPropertyParams NewProp_PageSize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AfterRank_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AfterRank;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetEntriesAfterRankDelegate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventGetEntriesAfterRank_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::NewProp_LeaderboardName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::NewProp_LeaderboardName = { "LeaderboardName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventGetEntriesAfterRank_Parms, LeaderboardName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::NewProp_LeaderboardName_MetaData), Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::NewProp_LeaderboardName_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::NewProp_PageIdx = { "PageIdx", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventGetEntriesAfterRank_Parms, PageIdx), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::NewProp_PageSize = { "PageSize", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventGetEntriesAfterRank_Parms, PageSize), METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::NewProp_AfterRank_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::NewProp_AfterRank = { "AfterRank", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventGetEntriesAfterRank_Parms, AfterRank), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::NewProp_AfterRank_MetaData), Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::NewProp_AfterRank_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::NewProp_InGetEntriesAfterRankDelegate = { "InGetEntriesAfterRankDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventGetEntriesAfterRank_Parms, InGetEntriesAfterRankDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesAfterRank__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1872610045
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::NewProp_LeaderboardName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::NewProp_PageIdx,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::NewProp_PageSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::NewProp_AfterRank,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::NewProp_InGetEntriesAfterRankDelegate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Leaderboards" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the leaderboard entries after a specified ranking.</summary>\n/// <param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"leaderboardName\">Leaderboard name.</param>\n/// <param name=\"pageSize\">The number of entries to return on each page. The value ranges from 1 to 100. </param>\n/// <param name=\"pageIdx\">Defines which page of entries to return. The value = (The target page No.)-1.\n/// For example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>\n/// <param name=\"AfterRank\">Defines after which rank to return entries.</param>\n/// <param name=\"InGetEntriesAfterRankDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_LeaderboardEntryArray *, LeaderboardEntryList).</param>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the leaderboard entries after a specified ranking.</summary>\n<param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"leaderboardName\">Leaderboard name.</param>\n<param name=\"pageSize\">The number of entries to return on each page. The value ranges from 1 to 100. </param>\n<param name=\"pageIdx\">Defines which page of entries to return. The value = (The target page No.)-1.\nFor example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>\n<param name=\"AfterRank\">Defines after which rank to return entries.</param>\n<param name=\"InGetEntriesAfterRankDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_LeaderboardEntryArray *, LeaderboardEntryList).</param>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoLeaderboardsFunction, nullptr, "GetEntriesAfterRank", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::OnlinePicoLeaderboardsFunction_eventGetEntriesAfterRank_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::OnlinePicoLeaderboardsFunction_eventGetEntriesAfterRank_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics
	{
		struct OnlinePicoLeaderboardsFunction_eventGetEntriesByIds_Parms
		{
			UObject* WorldContextObject;
			FString LeaderboardName;
			int32 PageIdx;
			int32 PageSize;
			ELeaderboardStartAt StartAt;
			TArray<FString> UserIDs;
			FScriptDelegate InGetEntriesByIdsDelegate;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LeaderboardName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_LeaderboardName;
		static const UECodeGen_Private::FIntPropertyParams NewProp_PageIdx;
		static const UECodeGen_Private::FIntPropertyParams NewProp_PageSize;
		static const UECodeGen_Private::FBytePropertyParams NewProp_StartAt_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_StartAt;
		static const UECodeGen_Private::FStrPropertyParams NewProp_UserIDs_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UserIDs_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_UserIDs;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetEntriesByIdsDelegate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventGetEntriesByIds_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_LeaderboardName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_LeaderboardName = { "LeaderboardName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventGetEntriesByIds_Parms, LeaderboardName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_LeaderboardName_MetaData), Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_LeaderboardName_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_PageIdx = { "PageIdx", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventGetEntriesByIds_Parms, PageIdx), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_PageSize = { "PageSize", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventGetEntriesByIds_Parms, PageSize), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_StartAt_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_StartAt = { "StartAt", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventGetEntriesByIds_Parms, StartAt), Z_Construct_UEnum_OnlineSubsystemPico_ELeaderboardStartAt, METADATA_PARAMS(0, nullptr) }; // 2656628965
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_UserIDs_Inner = { "UserIDs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_UserIDs_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_UserIDs = { "UserIDs", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventGetEntriesByIds_Parms, UserIDs), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_UserIDs_MetaData), Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_UserIDs_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_InGetEntriesByIdsDelegate = { "InGetEntriesByIdsDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventGetEntriesByIds_Parms, InGetEntriesByIdsDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetEntriesByIds__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3072146398
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_LeaderboardName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_PageIdx,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_PageSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_StartAt_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_StartAt,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_UserIDs_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_UserIDs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::NewProp_InGetEntriesByIdsDelegate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Leaderboards" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the leaderboard entries for specified user(s).</summary>\n/// <param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"leaderboardName\">Leaderboard name.</param>\n/// <param name=\"pageSize\">The number of entries to return on each page. The value ranges from 1 to 100. </param>\n/// <param name=\"pageIdx\">Defines which page of entries to return. The value = (The target page No.)-1.\n/// For example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>\n/// <param name=\"startAt\">Defines where to start returning challenge entries, the enumerations are:\n/// * `0`: Top (return entries from top 1)\n/// * `1`: CenteredOnViewer (place the current logged-in user's entry in the middle of the list on the first page.\n/// For example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5, the ranks displayed\n/// on the first page will be top 3, 4, 5, 6, and 7. Top 1 and 2 will not be displayed, and top 8, 9, and 10 will be\n/// displayed on the second page)\n/// * `2`: CenteredOnViewerOrTop (place the current logged-in user's entry on the top of the list on the first page.\n/// For example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5,\n/// the ranks displayed on the first page will be top 5, 6, 7, 8, and 9. Top 1, 2, 3, and 4 will not be displayed,\n/// and top 10 will be displayed on the second page)\n/// </param>\n/// <param name=\"userIDs\">User ID(s).</param>\n/// <param name=\"InGetEntriesByIdsDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_LeaderboardEntryArray *, LeaderboardEntryList).</param>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the leaderboard entries for specified user(s).</summary>\n<param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"leaderboardName\">Leaderboard name.</param>\n<param name=\"pageSize\">The number of entries to return on each page. The value ranges from 1 to 100. </param>\n<param name=\"pageIdx\">Defines which page of entries to return. The value = (The target page No.)-1.\nFor example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>\n<param name=\"startAt\">Defines where to start returning challenge entries, the enumerations are:\n* `0`: Top (return entries from top 1)\n* `1`: CenteredOnViewer (place the current logged-in user's entry in the middle of the list on the first page.\nFor example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5, the ranks displayed\non the first page will be top 3, 4, 5, 6, and 7. Top 1 and 2 will not be displayed, and top 8, 9, and 10 will be\ndisplayed on the second page)\n* `2`: CenteredOnViewerOrTop (place the current logged-in user's entry on the top of the list on the first page.\nFor example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5,\nthe ranks displayed on the first page will be top 5, 6, 7, 8, and 9. Top 1, 2, 3, and 4 will not be displayed,\nand top 10 will be displayed on the second page)\n</param>\n<param name=\"userIDs\">User ID(s).</param>\n<param name=\"InGetEntriesByIdsDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_LeaderboardEntryArray *, LeaderboardEntryList).</param>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoLeaderboardsFunction, nullptr, "GetEntriesByIds", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::OnlinePicoLeaderboardsFunction_eventGetEntriesByIds_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::OnlinePicoLeaderboardsFunction_eventGetEntriesByIds_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics
	{
		struct OnlinePicoLeaderboardsFunction_eventWriteEntry_Parms
		{
			UObject* WorldContextObject;
			FString LeaderboardName;
			FString Score;
			FString ExtraData;
			bool ForceUpdate;
			FScriptDelegate InWriteEntryDelegate;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LeaderboardName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_LeaderboardName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Score_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Score;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ExtraData_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ExtraData;
		static void NewProp_ForceUpdate_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ForceUpdate;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InWriteEntryDelegate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventWriteEntry_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::NewProp_LeaderboardName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::NewProp_LeaderboardName = { "LeaderboardName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventWriteEntry_Parms, LeaderboardName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::NewProp_LeaderboardName_MetaData), Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::NewProp_LeaderboardName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::NewProp_Score_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::NewProp_Score = { "Score", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventWriteEntry_Parms, Score), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::NewProp_Score_MetaData), Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::NewProp_Score_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::NewProp_ExtraData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::NewProp_ExtraData = { "ExtraData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventWriteEntry_Parms, ExtraData), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::NewProp_ExtraData_MetaData), Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::NewProp_ExtraData_MetaData) };
	void Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::NewProp_ForceUpdate_SetBit(void* Obj)
	{
		((OnlinePicoLeaderboardsFunction_eventWriteEntry_Parms*)Obj)->ForceUpdate = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::NewProp_ForceUpdate = { "ForceUpdate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoLeaderboardsFunction_eventWriteEntry_Parms), &Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::NewProp_ForceUpdate_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::NewProp_InWriteEntryDelegate = { "InWriteEntryDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventWriteEntry_Parms, InWriteEntryDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntry__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2148629211
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::NewProp_LeaderboardName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::NewProp_Score,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::NewProp_ExtraData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::NewProp_ForceUpdate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::NewProp_InWriteEntryDelegate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Leaderboards" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Writes a user's score to the leaderboard.</summary>\n/// <param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"leaderboardName\">Leaderboard name.</param>\n/// <param name=\"score\">The user's score.</param>\n/// <param name=\"extraData\">Custom extension fields that can be used to record key information when writing the user's score.</param>\n/// <param name=\"forceUpdate\">Whether to force a leaderboard update. </param>\n/// <param name=\"InWriteEntryDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, bool, WriteResult).</param>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Writes a user's score to the leaderboard.</summary>\n<param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"leaderboardName\">Leaderboard name.</param>\n<param name=\"score\">The user's score.</param>\n<param name=\"extraData\">Custom extension fields that can be used to record key information when writing the user's score.</param>\n<param name=\"forceUpdate\">Whether to force a leaderboard update. </param>\n<param name=\"InWriteEntryDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, bool, WriteResult).</param>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoLeaderboardsFunction, nullptr, "WriteEntry", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::OnlinePicoLeaderboardsFunction_eventWriteEntry_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::OnlinePicoLeaderboardsFunction_eventWriteEntry_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics
	{
		struct OnlinePicoLeaderboardsFunction_eventWriteEntryWithSupplementaryMetric_Parms
		{
			UObject* WorldContextObject;
			FString LeaderboardName;
			FString Score;
			FString SupplementaryMetric;
			FString ExtraData;
			bool ForceUpdate;
			FScriptDelegate InWriteEntryWithSupplementaryMetricDelegate;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LeaderboardName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_LeaderboardName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Score_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Score;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SupplementaryMetric_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_SupplementaryMetric;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ExtraData_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ExtraData;
		static void NewProp_ForceUpdate_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ForceUpdate;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InWriteEntryWithSupplementaryMetricDelegate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventWriteEntryWithSupplementaryMetric_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_LeaderboardName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_LeaderboardName = { "LeaderboardName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventWriteEntryWithSupplementaryMetric_Parms, LeaderboardName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_LeaderboardName_MetaData), Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_LeaderboardName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_Score_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_Score = { "Score", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventWriteEntryWithSupplementaryMetric_Parms, Score), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_Score_MetaData), Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_Score_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_SupplementaryMetric_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_SupplementaryMetric = { "SupplementaryMetric", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventWriteEntryWithSupplementaryMetric_Parms, SupplementaryMetric), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_SupplementaryMetric_MetaData), Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_SupplementaryMetric_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_ExtraData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_ExtraData = { "ExtraData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventWriteEntryWithSupplementaryMetric_Parms, ExtraData), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_ExtraData_MetaData), Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_ExtraData_MetaData) };
	void Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_ForceUpdate_SetBit(void* Obj)
	{
		((OnlinePicoLeaderboardsFunction_eventWriteEntryWithSupplementaryMetric_Parms*)Obj)->ForceUpdate = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_ForceUpdate = { "ForceUpdate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoLeaderboardsFunction_eventWriteEntryWithSupplementaryMetric_Parms), &Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_ForceUpdate_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_InWriteEntryWithSupplementaryMetricDelegate = { "InWriteEntryWithSupplementaryMetricDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoLeaderboardsFunction_eventWriteEntryWithSupplementaryMetric_Parms, InWriteEntryWithSupplementaryMetricDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_WriteEntryWithSupplementaryMetric__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 934180821
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_LeaderboardName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_Score,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_SupplementaryMetric,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_ExtraData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_ForceUpdate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::NewProp_InWriteEntryWithSupplementaryMetricDelegate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Leaderboards" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Adds custom contents when writing a user's score to a leaderboard.</summary>\n/// <param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"leaderboardName\">Leaderboard name.</param>\n/// <param name=\"score\">The user's score.</param>\n/// <param name=\"supplementaryMetric\">Custom contents, such as a video.</param>\n/// <param name=\"extraData\">Custom extension fields that can be used to record key information when writing the custom contents.</param>\n/// <param name=\"forceUpdate\">Whether to force a leaderboard update. </param>\n/// <param name=\"InWriteEntryWithSupplementaryMetricDelegate\">Will be executed when the request has been completed.\n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, bool, WriteResult).</param>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Adds custom contents when writing a user's score to a leaderboard.</summary>\n<param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"leaderboardName\">Leaderboard name.</param>\n<param name=\"score\">The user's score.</param>\n<param name=\"supplementaryMetric\">Custom contents, such as a video.</param>\n<param name=\"extraData\">Custom extension fields that can be used to record key information when writing the custom contents.</param>\n<param name=\"forceUpdate\">Whether to force a leaderboard update. </param>\n<param name=\"InWriteEntryWithSupplementaryMetricDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, bool, WriteResult).</param>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoLeaderboardsFunction, nullptr, "WriteEntryWithSupplementaryMetric", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::OnlinePicoLeaderboardsFunction_eventWriteEntryWithSupplementaryMetric_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::OnlinePicoLeaderboardsFunction_eventWriteEntryWithSupplementaryMetric_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOnlinePicoLeaderboardsFunction);
	UClass* Z_Construct_UClass_UOnlinePicoLeaderboardsFunction_NoRegister()
	{
		return UOnlinePicoLeaderboardsFunction::StaticClass();
	}
	struct Z_Construct_UClass_UOnlinePicoLeaderboardsFunction_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOnlinePicoLeaderboardsFunction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoLeaderboardsFunction_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UOnlinePicoLeaderboardsFunction_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_Get, "Get" }, // 444121771
		{ &Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntries, "GetEntries" }, // 898569759
		{ &Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesAfterRank, "GetEntriesAfterRank" }, // 2542574654
		{ &Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_GetEntriesByIds, "GetEntriesByIds" }, // 4164740617
		{ &Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntry, "WriteEntry" }, // 1558610231
		{ &Z_Construct_UFunction_UOnlinePicoLeaderboardsFunction_WriteEntryWithSupplementaryMetric, "WriteEntryWithSupplementaryMetric" }, // 2093226549
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoLeaderboardsFunction_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoLeaderboardsFunction_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @defgroup BP_Leaderboards BP_Leaderboards\n *  This is the BP_Leaderboards group\n *  @{\n *//// @brief OnlinePicoLeaderboards Blueprint Function class.\n" },
#endif
		{ "IncludePath", "Pico_Leaderboards.h" },
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@defgroup BP_Leaderboards BP_Leaderboards\nThis is the BP_Leaderboards group\n@{\n/// @brief OnlinePicoLeaderboards Blueprint Function class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOnlinePicoLeaderboardsFunction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOnlinePicoLeaderboardsFunction>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOnlinePicoLeaderboardsFunction_Statics::ClassParams = {
		&UOnlinePicoLeaderboardsFunction::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoLeaderboardsFunction_Statics::Class_MetaDataParams), Z_Construct_UClass_UOnlinePicoLeaderboardsFunction_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UOnlinePicoLeaderboardsFunction()
	{
		if (!Z_Registration_Info_UClass_UOnlinePicoLeaderboardsFunction.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOnlinePicoLeaderboardsFunction.OuterSingleton, Z_Construct_UClass_UOnlinePicoLeaderboardsFunction_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOnlinePicoLeaderboardsFunction.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UOnlinePicoLeaderboardsFunction>()
	{
		return UOnlinePicoLeaderboardsFunction::StaticClass();
	}
	UOnlinePicoLeaderboardsFunction::UOnlinePicoLeaderboardsFunction(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOnlinePicoLeaderboardsFunction);
	UOnlinePicoLeaderboardsFunction::~UOnlinePicoLeaderboardsFunction() {}
	DEFINE_FUNCTION(UPico_LeaderboardEntry::execGetExtraDataString)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetExtraDataString();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_LeaderboardEntry::execGetUser)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPico_User**)Z_Param__Result=P_THIS->GetUser();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_LeaderboardEntry::execGetTimestampDateTime)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FDateTime*)Z_Param__Result=P_THIS->GetTimestampDateTime();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_LeaderboardEntry::execGetTimestamp)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetTimestamp();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_LeaderboardEntry::execGetSupplementaryMetricOptional)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FPicoSupplementaryMetric*)Z_Param__Result=P_THIS->GetSupplementaryMetricOptional();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_LeaderboardEntry::execGetScore)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int64*)Z_Param__Result=P_THIS->GetScore();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_LeaderboardEntry::execGetRank)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetRank();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_LeaderboardEntry::execGetDisplayScore)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetDisplayScore();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_LeaderboardEntry::execGetID)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetID();
		P_NATIVE_END;
	}
	void UPico_LeaderboardEntry::StaticRegisterNativesUPico_LeaderboardEntry()
	{
		UClass* Class = UPico_LeaderboardEntry::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetDisplayScore", &UPico_LeaderboardEntry::execGetDisplayScore },
			{ "GetExtraDataString", &UPico_LeaderboardEntry::execGetExtraDataString },
			{ "GetID", &UPico_LeaderboardEntry::execGetID },
			{ "GetRank", &UPico_LeaderboardEntry::execGetRank },
			{ "GetScore", &UPico_LeaderboardEntry::execGetScore },
			{ "GetSupplementaryMetricOptional", &UPico_LeaderboardEntry::execGetSupplementaryMetricOptional },
			{ "GetTimestamp", &UPico_LeaderboardEntry::execGetTimestamp },
			{ "GetTimestampDateTime", &UPico_LeaderboardEntry::execGetTimestampDateTime },
			{ "GetUser", &UPico_LeaderboardEntry::execGetUser },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_LeaderboardEntry_GetDisplayScore_Statics
	{
		struct Pico_LeaderboardEntry_eventGetDisplayScore_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_LeaderboardEntry_GetDisplayScore_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_LeaderboardEntry_eventGetDisplayScore_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_LeaderboardEntry_GetDisplayScore_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_LeaderboardEntry_GetDisplayScore_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_LeaderboardEntry_GetDisplayScore_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Leaderboards|Leaderboard Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The entry's display score. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The entry's display score." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_LeaderboardEntry_GetDisplayScore_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_LeaderboardEntry, nullptr, "GetDisplayScore", nullptr, nullptr, Z_Construct_UFunction_UPico_LeaderboardEntry_GetDisplayScore_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetDisplayScore_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_LeaderboardEntry_GetDisplayScore_Statics::Pico_LeaderboardEntry_eventGetDisplayScore_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetDisplayScore_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_LeaderboardEntry_GetDisplayScore_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetDisplayScore_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_LeaderboardEntry_GetDisplayScore_Statics::Pico_LeaderboardEntry_eventGetDisplayScore_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_LeaderboardEntry_GetDisplayScore()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_LeaderboardEntry_GetDisplayScore_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_LeaderboardEntry_GetExtraDataString_Statics
	{
		struct Pico_LeaderboardEntry_eventGetExtraDataString_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_LeaderboardEntry_GetExtraDataString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_LeaderboardEntry_eventGetExtraDataString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_LeaderboardEntry_GetExtraDataString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_LeaderboardEntry_GetExtraDataString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_LeaderboardEntry_GetExtraDataString_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Leaderboards|Leaderboard Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Additional info, no more than 2KB. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Additional info, no more than 2KB." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_LeaderboardEntry_GetExtraDataString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_LeaderboardEntry, nullptr, "GetExtraDataString", nullptr, nullptr, Z_Construct_UFunction_UPico_LeaderboardEntry_GetExtraDataString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetExtraDataString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_LeaderboardEntry_GetExtraDataString_Statics::Pico_LeaderboardEntry_eventGetExtraDataString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetExtraDataString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_LeaderboardEntry_GetExtraDataString_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetExtraDataString_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_LeaderboardEntry_GetExtraDataString_Statics::Pico_LeaderboardEntry_eventGetExtraDataString_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_LeaderboardEntry_GetExtraDataString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_LeaderboardEntry_GetExtraDataString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_LeaderboardEntry_GetID_Statics
	{
		struct Pico_LeaderboardEntry_eventGetID_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_LeaderboardEntry_GetID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_LeaderboardEntry_eventGetID_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_LeaderboardEntry_GetID_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_LeaderboardEntry_GetID_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_LeaderboardEntry_GetID_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Leaderboards|Leaderboard Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Entry ID. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Entry ID." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_LeaderboardEntry_GetID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_LeaderboardEntry, nullptr, "GetID", nullptr, nullptr, Z_Construct_UFunction_UPico_LeaderboardEntry_GetID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetID_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_LeaderboardEntry_GetID_Statics::Pico_LeaderboardEntry_eventGetID_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_LeaderboardEntry_GetID_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetID_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_LeaderboardEntry_GetID_Statics::Pico_LeaderboardEntry_eventGetID_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_LeaderboardEntry_GetID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_LeaderboardEntry_GetID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_LeaderboardEntry_GetRank_Statics
	{
		struct Pico_LeaderboardEntry_eventGetRank_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_LeaderboardEntry_GetRank_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_LeaderboardEntry_eventGetRank_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_LeaderboardEntry_GetRank_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_LeaderboardEntry_GetRank_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_LeaderboardEntry_GetRank_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Leaderboards|Leaderboard Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The entry's ranking on the leaderboard. For example, returns `1` for top1.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The entry's ranking on the leaderboard. For example, returns `1` for top1." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_LeaderboardEntry_GetRank_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_LeaderboardEntry, nullptr, "GetRank", nullptr, nullptr, Z_Construct_UFunction_UPico_LeaderboardEntry_GetRank_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetRank_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_LeaderboardEntry_GetRank_Statics::Pico_LeaderboardEntry_eventGetRank_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetRank_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_LeaderboardEntry_GetRank_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetRank_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_LeaderboardEntry_GetRank_Statics::Pico_LeaderboardEntry_eventGetRank_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_LeaderboardEntry_GetRank()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_LeaderboardEntry_GetRank_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_LeaderboardEntry_GetScore_Statics
	{
		struct Pico_LeaderboardEntry_eventGetScore_Parms
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
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UPico_LeaderboardEntry_GetScore_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_LeaderboardEntry_eventGetScore_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_LeaderboardEntry_GetScore_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_LeaderboardEntry_GetScore_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_LeaderboardEntry_GetScore_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Leaderboards|Leaderboard Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The score used to rank the entry. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The score used to rank the entry." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_LeaderboardEntry_GetScore_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_LeaderboardEntry, nullptr, "GetScore", nullptr, nullptr, Z_Construct_UFunction_UPico_LeaderboardEntry_GetScore_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetScore_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_LeaderboardEntry_GetScore_Statics::Pico_LeaderboardEntry_eventGetScore_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetScore_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_LeaderboardEntry_GetScore_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetScore_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_LeaderboardEntry_GetScore_Statics::Pico_LeaderboardEntry_eventGetScore_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_LeaderboardEntry_GetScore()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_LeaderboardEntry_GetScore_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_LeaderboardEntry_GetSupplementaryMetricOptional_Statics
	{
		struct Pico_LeaderboardEntry_eventGetSupplementaryMetricOptional_Parms
		{
			FPicoSupplementaryMetric ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPico_LeaderboardEntry_GetSupplementaryMetricOptional_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_LeaderboardEntry_eventGetSupplementaryMetricOptional_Parms, ReturnValue), Z_Construct_UScriptStruct_FPicoSupplementaryMetric, METADATA_PARAMS(0, nullptr) }; // 967339666
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_LeaderboardEntry_GetSupplementaryMetricOptional_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_LeaderboardEntry_GetSupplementaryMetricOptional_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_LeaderboardEntry_GetSupplementaryMetricOptional_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Leaderboards|Leaderboard Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The supplementary metric used for tiebreakers. This field can be null. Need to check whether it is null before use. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The supplementary metric used for tiebreakers. This field can be null. Need to check whether it is null before use." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_LeaderboardEntry_GetSupplementaryMetricOptional_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_LeaderboardEntry, nullptr, "GetSupplementaryMetricOptional", nullptr, nullptr, Z_Construct_UFunction_UPico_LeaderboardEntry_GetSupplementaryMetricOptional_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetSupplementaryMetricOptional_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_LeaderboardEntry_GetSupplementaryMetricOptional_Statics::Pico_LeaderboardEntry_eventGetSupplementaryMetricOptional_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetSupplementaryMetricOptional_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_LeaderboardEntry_GetSupplementaryMetricOptional_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetSupplementaryMetricOptional_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_LeaderboardEntry_GetSupplementaryMetricOptional_Statics::Pico_LeaderboardEntry_eventGetSupplementaryMetricOptional_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_LeaderboardEntry_GetSupplementaryMetricOptional()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_LeaderboardEntry_GetSupplementaryMetricOptional_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestamp_Statics
	{
		struct Pico_LeaderboardEntry_eventGetTimestamp_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestamp_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_LeaderboardEntry_eventGetTimestamp_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestamp_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestamp_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestamp_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Leaderboards|Leaderboard Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The time (as string) when the entry was written to the leaderboard. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The time (as string) when the entry was written to the leaderboard." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestamp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_LeaderboardEntry, nullptr, "GetTimestamp", nullptr, nullptr, Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestamp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestamp_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestamp_Statics::Pico_LeaderboardEntry_eventGetTimestamp_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestamp_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestamp_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestamp_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestamp_Statics::Pico_LeaderboardEntry_eventGetTimestamp_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestamp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestamp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestampDateTime_Statics
	{
		struct Pico_LeaderboardEntry_eventGetTimestampDateTime_Parms
		{
			FDateTime ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestampDateTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_LeaderboardEntry_eventGetTimestampDateTime_Parms, ReturnValue), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestampDateTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestampDateTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestampDateTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Leaderboards|Leaderboard Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The time when the entry was written to the leaderboard. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The time when the entry was written to the leaderboard." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestampDateTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_LeaderboardEntry, nullptr, "GetTimestampDateTime", nullptr, nullptr, Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestampDateTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestampDateTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestampDateTime_Statics::Pico_LeaderboardEntry_eventGetTimestampDateTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestampDateTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestampDateTime_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestampDateTime_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestampDateTime_Statics::Pico_LeaderboardEntry_eventGetTimestampDateTime_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestampDateTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestampDateTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_LeaderboardEntry_GetUser_Statics
	{
		struct Pico_LeaderboardEntry_eventGetUser_Parms
		{
			UPico_User* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPico_LeaderboardEntry_GetUser_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_LeaderboardEntry_eventGetUser_Parms, ReturnValue), Z_Construct_UClass_UPico_User_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_LeaderboardEntry_GetUser_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_LeaderboardEntry_GetUser_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_LeaderboardEntry_GetUser_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Leaderboards|Leaderboard Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The user the entry belongs to. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The user the entry belongs to." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_LeaderboardEntry_GetUser_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_LeaderboardEntry, nullptr, "GetUser", nullptr, nullptr, Z_Construct_UFunction_UPico_LeaderboardEntry_GetUser_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetUser_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_LeaderboardEntry_GetUser_Statics::Pico_LeaderboardEntry_eventGetUser_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetUser_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_LeaderboardEntry_GetUser_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntry_GetUser_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_LeaderboardEntry_GetUser_Statics::Pico_LeaderboardEntry_eventGetUser_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_LeaderboardEntry_GetUser()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_LeaderboardEntry_GetUser_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_LeaderboardEntry);
	UClass* Z_Construct_UClass_UPico_LeaderboardEntry_NoRegister()
	{
		return UPico_LeaderboardEntry::StaticClass();
	}
	struct Z_Construct_UClass_UPico_LeaderboardEntry_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_User_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_User;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_LeaderboardEntry_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_LeaderboardEntry_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_LeaderboardEntry_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_LeaderboardEntry_GetDisplayScore, "GetDisplayScore" }, // 1138666130
		{ &Z_Construct_UFunction_UPico_LeaderboardEntry_GetExtraDataString, "GetExtraDataString" }, // 2007706647
		{ &Z_Construct_UFunction_UPico_LeaderboardEntry_GetID, "GetID" }, // 3817656574
		{ &Z_Construct_UFunction_UPico_LeaderboardEntry_GetRank, "GetRank" }, // 1698995272
		{ &Z_Construct_UFunction_UPico_LeaderboardEntry_GetScore, "GetScore" }, // 1323862168
		{ &Z_Construct_UFunction_UPico_LeaderboardEntry_GetSupplementaryMetricOptional, "GetSupplementaryMetricOptional" }, // 3973478171
		{ &Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestamp, "GetTimestamp" }, // 3255947243
		{ &Z_Construct_UFunction_UPico_LeaderboardEntry_GetTimestampDateTime, "GetTimestampDateTime" }, // 2293669380
		{ &Z_Construct_UFunction_UPico_LeaderboardEntry_GetUser, "GetUser" }, // 2026164663
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_LeaderboardEntry_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_LeaderboardEntry_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_LeaderboardEntry class.\n" },
#endif
		{ "IncludePath", "Pico_Leaderboards.h" },
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_LeaderboardEntry class." },
#endif
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_LeaderboardEntry_Statics::NewProp_User_MetaData[] = {
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPico_LeaderboardEntry_Statics::NewProp_User = { "User", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPico_LeaderboardEntry, User), Z_Construct_UClass_UPico_User_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_LeaderboardEntry_Statics::NewProp_User_MetaData), Z_Construct_UClass_UPico_LeaderboardEntry_Statics::NewProp_User_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPico_LeaderboardEntry_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_LeaderboardEntry_Statics::NewProp_User,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_LeaderboardEntry_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_LeaderboardEntry>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_LeaderboardEntry_Statics::ClassParams = {
		&UPico_LeaderboardEntry::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPico_LeaderboardEntry_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPico_LeaderboardEntry_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_LeaderboardEntry_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_LeaderboardEntry_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_LeaderboardEntry_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPico_LeaderboardEntry()
	{
		if (!Z_Registration_Info_UClass_UPico_LeaderboardEntry.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_LeaderboardEntry.OuterSingleton, Z_Construct_UClass_UPico_LeaderboardEntry_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_LeaderboardEntry.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_LeaderboardEntry>()
	{
		return UPico_LeaderboardEntry::StaticClass();
	}
	UPico_LeaderboardEntry::UPico_LeaderboardEntry(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_LeaderboardEntry);
	UPico_LeaderboardEntry::~UPico_LeaderboardEntry() {}
	DEFINE_FUNCTION(UPico_Leaderboard::execGetDestinationOptional)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FPicoDestination*)Z_Param__Result=P_THIS->GetDestinationOptional();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Leaderboard::execGetID)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetID();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Leaderboard::execGetApiName)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetApiName();
		P_NATIVE_END;
	}
	void UPico_Leaderboard::StaticRegisterNativesUPico_Leaderboard()
	{
		UClass* Class = UPico_Leaderboard::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetApiName", &UPico_Leaderboard::execGetApiName },
			{ "GetDestinationOptional", &UPico_Leaderboard::execGetDestinationOptional },
			{ "GetID", &UPico_Leaderboard::execGetID },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_Leaderboard_GetApiName_Statics
	{
		struct Pico_Leaderboard_eventGetApiName_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_Leaderboard_GetApiName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Leaderboard_eventGetApiName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Leaderboard_GetApiName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Leaderboard_GetApiName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Leaderboard_GetApiName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Leaderboards|Leaderboard" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The unique identifier of the leaderboard, which is configured on the PICO Developer Platform. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The unique identifier of the leaderboard, which is configured on the PICO Developer Platform." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Leaderboard_GetApiName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Leaderboard, nullptr, "GetApiName", nullptr, nullptr, Z_Construct_UFunction_UPico_Leaderboard_GetApiName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Leaderboard_GetApiName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Leaderboard_GetApiName_Statics::Pico_Leaderboard_eventGetApiName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Leaderboard_GetApiName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Leaderboard_GetApiName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Leaderboard_GetApiName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Leaderboard_GetApiName_Statics::Pico_Leaderboard_eventGetApiName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Leaderboard_GetApiName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Leaderboard_GetApiName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Leaderboard_GetDestinationOptional_Statics
	{
		struct Pico_Leaderboard_eventGetDestinationOptional_Parms
		{
			FPicoDestination ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPico_Leaderboard_GetDestinationOptional_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Leaderboard_eventGetDestinationOptional_Parms, ReturnValue), Z_Construct_UScriptStruct_FPicoDestination, METADATA_PARAMS(0, nullptr) }; // 1078875535
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Leaderboard_GetDestinationOptional_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Leaderboard_GetDestinationOptional_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Leaderboard_GetDestinationOptional_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Leaderboards|Leaderboard" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Associate a destination to the leaderboard so that users can be directed to a specific location in the app.\n     * If the leaderboard for that challenge is associated with a destination, the app will be launched, and the user will be directed to the destination.\n     * If the leaderboard for that challenge is not associated with any destination, the app will be launched, and the user will be directed to the Home page.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Associate a destination to the leaderboard so that users can be directed to a specific location in the app.\nIf the leaderboard for that challenge is associated with a destination, the app will be launched, and the user will be directed to the destination.\nIf the leaderboard for that challenge is not associated with any destination, the app will be launched, and the user will be directed to the Home page." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Leaderboard_GetDestinationOptional_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Leaderboard, nullptr, "GetDestinationOptional", nullptr, nullptr, Z_Construct_UFunction_UPico_Leaderboard_GetDestinationOptional_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Leaderboard_GetDestinationOptional_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Leaderboard_GetDestinationOptional_Statics::Pico_Leaderboard_eventGetDestinationOptional_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Leaderboard_GetDestinationOptional_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Leaderboard_GetDestinationOptional_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Leaderboard_GetDestinationOptional_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Leaderboard_GetDestinationOptional_Statics::Pico_Leaderboard_eventGetDestinationOptional_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Leaderboard_GetDestinationOptional()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Leaderboard_GetDestinationOptional_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Leaderboard_GetID_Statics
	{
		struct Pico_Leaderboard_eventGetID_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_Leaderboard_GetID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Leaderboard_eventGetID_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Leaderboard_GetID_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Leaderboard_GetID_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Leaderboard_GetID_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Leaderboards|Leaderboard" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Leaderboard ID. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Leaderboard ID." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Leaderboard_GetID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Leaderboard, nullptr, "GetID", nullptr, nullptr, Z_Construct_UFunction_UPico_Leaderboard_GetID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Leaderboard_GetID_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Leaderboard_GetID_Statics::Pico_Leaderboard_eventGetID_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Leaderboard_GetID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Leaderboard_GetID_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Leaderboard_GetID_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Leaderboard_GetID_Statics::Pico_Leaderboard_eventGetID_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Leaderboard_GetID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Leaderboard_GetID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_Leaderboard);
	UClass* Z_Construct_UClass_UPico_Leaderboard_NoRegister()
	{
		return UPico_Leaderboard::StaticClass();
	}
	struct Z_Construct_UClass_UPico_Leaderboard_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_Leaderboard_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_Leaderboard_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_Leaderboard_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_Leaderboard_GetApiName, "GetApiName" }, // 3045720737
		{ &Z_Construct_UFunction_UPico_Leaderboard_GetDestinationOptional, "GetDestinationOptional" }, // 4200729677
		{ &Z_Construct_UFunction_UPico_Leaderboard_GetID, "GetID" }, // 583735081
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_Leaderboard_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_Leaderboard_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_Leaderboard class.\n" },
#endif
		{ "IncludePath", "Pico_Leaderboards.h" },
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_Leaderboard class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_Leaderboard_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_Leaderboard>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_Leaderboard_Statics::ClassParams = {
		&UPico_Leaderboard::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_Leaderboard_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_Leaderboard_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPico_Leaderboard()
	{
		if (!Z_Registration_Info_UClass_UPico_Leaderboard.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_Leaderboard.OuterSingleton, Z_Construct_UClass_UPico_Leaderboard_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_Leaderboard.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_Leaderboard>()
	{
		return UPico_Leaderboard::StaticClass();
	}
	UPico_Leaderboard::UPico_Leaderboard(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_Leaderboard);
	UPico_Leaderboard::~UPico_Leaderboard() {}
	DEFINE_FUNCTION(UPico_LeaderboardEntryArray::execGetDebugString)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetDebugString();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_LeaderboardEntryArray::execHasPreviousPage)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->HasPreviousPage();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_LeaderboardEntryArray::execHasNextPage)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->HasNextPage();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_LeaderboardEntryArray::execGetTotalSize)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetTotalSize();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_LeaderboardEntryArray::execGetSize)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetSize();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_LeaderboardEntryArray::execGetElement)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPico_LeaderboardEntry**)Z_Param__Result=P_THIS->GetElement(Z_Param_Index);
		P_NATIVE_END;
	}
	void UPico_LeaderboardEntryArray::StaticRegisterNativesUPico_LeaderboardEntryArray()
	{
		UClass* Class = UPico_LeaderboardEntryArray::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetDebugString", &UPico_LeaderboardEntryArray::execGetDebugString },
			{ "GetElement", &UPico_LeaderboardEntryArray::execGetElement },
			{ "GetSize", &UPico_LeaderboardEntryArray::execGetSize },
			{ "GetTotalSize", &UPico_LeaderboardEntryArray::execGetTotalSize },
			{ "HasNextPage", &UPico_LeaderboardEntryArray::execHasNextPage },
			{ "HasPreviousPage", &UPico_LeaderboardEntryArray::execHasPreviousPage },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetDebugString_Statics
	{
		struct Pico_LeaderboardEntryArray_eventGetDebugString_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetDebugString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_LeaderboardEntryArray_eventGetDebugString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetDebugString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetDebugString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetDebugString_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Leaderboards|Leaderboard Entry Array" },
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetDebugString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_LeaderboardEntryArray, nullptr, "GetDebugString", nullptr, nullptr, Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetDebugString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetDebugString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetDebugString_Statics::Pico_LeaderboardEntryArray_eventGetDebugString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetDebugString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetDebugString_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetDebugString_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetDebugString_Statics::Pico_LeaderboardEntryArray_eventGetDebugString_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetDebugString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetDebugString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetElement_Statics
	{
		struct Pico_LeaderboardEntryArray_eventGetElement_Parms
		{
			int32 Index;
			UPico_LeaderboardEntry* ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetElement_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_LeaderboardEntryArray_eventGetElement_Parms, Index), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetElement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_LeaderboardEntryArray_eventGetElement_Parms, ReturnValue), Z_Construct_UClass_UPico_LeaderboardEntry_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetElement_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetElement_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetElement_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetElement_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Leaderboards|Leaderboard Entry Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get LeaderboardEntryArray element form Index.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get LeaderboardEntryArray element form Index." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetElement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_LeaderboardEntryArray, nullptr, "GetElement", nullptr, nullptr, Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetElement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetElement_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetElement_Statics::Pico_LeaderboardEntryArray_eventGetElement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetElement_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetElement_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetElement_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetElement_Statics::Pico_LeaderboardEntryArray_eventGetElement_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetElement()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetElement_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetSize_Statics
	{
		struct Pico_LeaderboardEntryArray_eventGetSize_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_LeaderboardEntryArray_eventGetSize_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Leaderboards|Leaderboard Entry Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get the size of LeaderboardEntryArray .*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get the size of LeaderboardEntryArray ." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_LeaderboardEntryArray, nullptr, "GetSize", nullptr, nullptr, Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetSize_Statics::Pico_LeaderboardEntryArray_eventGetSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetSize_Statics::Pico_LeaderboardEntryArray_eventGetSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetTotalSize_Statics
	{
		struct Pico_LeaderboardEntryArray_eventGetTotalSize_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetTotalSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_LeaderboardEntryArray_eventGetTotalSize_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetTotalSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetTotalSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetTotalSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Leaderboards|Leaderboard Entry Array" },
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetTotalSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_LeaderboardEntryArray, nullptr, "GetTotalSize", nullptr, nullptr, Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetTotalSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetTotalSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetTotalSize_Statics::Pico_LeaderboardEntryArray_eventGetTotalSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetTotalSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetTotalSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetTotalSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetTotalSize_Statics::Pico_LeaderboardEntryArray_eventGetTotalSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetTotalSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetTotalSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasNextPage_Statics
	{
		struct Pico_LeaderboardEntryArray_eventHasNextPage_Parms
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
	void Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasNextPage_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_LeaderboardEntryArray_eventHasNextPage_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasNextPage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_LeaderboardEntryArray_eventHasNextPage_Parms), &Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasNextPage_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasNextPage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasNextPage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasNextPage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Leaderboards|Leaderboard Entry Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get whether the list has the next page.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get whether the list has the next page." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasNextPage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_LeaderboardEntryArray, nullptr, "HasNextPage", nullptr, nullptr, Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasNextPage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasNextPage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasNextPage_Statics::Pico_LeaderboardEntryArray_eventHasNextPage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasNextPage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasNextPage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasNextPage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasNextPage_Statics::Pico_LeaderboardEntryArray_eventHasNextPage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasNextPage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasNextPage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasPreviousPage_Statics
	{
		struct Pico_LeaderboardEntryArray_eventHasPreviousPage_Parms
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
	void Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasPreviousPage_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_LeaderboardEntryArray_eventHasPreviousPage_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasPreviousPage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_LeaderboardEntryArray_eventHasPreviousPage_Parms), &Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasPreviousPage_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasPreviousPage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasPreviousPage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasPreviousPage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Leaderboards|Leaderboard Entry Array" },
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasPreviousPage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_LeaderboardEntryArray, nullptr, "HasPreviousPage", nullptr, nullptr, Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasPreviousPage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasPreviousPage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasPreviousPage_Statics::Pico_LeaderboardEntryArray_eventHasPreviousPage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasPreviousPage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasPreviousPage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasPreviousPage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasPreviousPage_Statics::Pico_LeaderboardEntryArray_eventHasPreviousPage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasPreviousPage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasPreviousPage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_LeaderboardEntryArray);
	UClass* Z_Construct_UClass_UPico_LeaderboardEntryArray_NoRegister()
	{
		return UPico_LeaderboardEntryArray::StaticClass();
	}
	struct Z_Construct_UClass_UPico_LeaderboardEntryArray_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LeaderboardEntryArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LeaderboardEntryArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_LeaderboardEntryArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_LeaderboardEntryArray_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_LeaderboardEntryArray_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_LeaderboardEntryArray_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetDebugString, "GetDebugString" }, // 1942211500
		{ &Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetElement, "GetElement" }, // 821497843
		{ &Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetSize, "GetSize" }, // 2406413016
		{ &Z_Construct_UFunction_UPico_LeaderboardEntryArray_GetTotalSize, "GetTotalSize" }, // 2583171364
		{ &Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasNextPage, "HasNextPage" }, // 4096953126
		{ &Z_Construct_UFunction_UPico_LeaderboardEntryArray_HasPreviousPage, "HasPreviousPage" }, // 1814185206
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_LeaderboardEntryArray_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_LeaderboardEntryArray_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_LeaderboardEntryArray class.\n" },
#endif
		{ "IncludePath", "Pico_Leaderboards.h" },
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_LeaderboardEntryArray class." },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPico_LeaderboardEntryArray_Statics::NewProp_LeaderboardEntryArray_Inner = { "LeaderboardEntryArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UPico_LeaderboardEntry_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_LeaderboardEntryArray_Statics::NewProp_LeaderboardEntryArray_MetaData[] = {
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPico_LeaderboardEntryArray_Statics::NewProp_LeaderboardEntryArray = { "LeaderboardEntryArray", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPico_LeaderboardEntryArray, LeaderboardEntryArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_LeaderboardEntryArray_Statics::NewProp_LeaderboardEntryArray_MetaData), Z_Construct_UClass_UPico_LeaderboardEntryArray_Statics::NewProp_LeaderboardEntryArray_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPico_LeaderboardEntryArray_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_LeaderboardEntryArray_Statics::NewProp_LeaderboardEntryArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_LeaderboardEntryArray_Statics::NewProp_LeaderboardEntryArray,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_LeaderboardEntryArray_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_LeaderboardEntryArray>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_LeaderboardEntryArray_Statics::ClassParams = {
		&UPico_LeaderboardEntryArray::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPico_LeaderboardEntryArray_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPico_LeaderboardEntryArray_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_LeaderboardEntryArray_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_LeaderboardEntryArray_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_LeaderboardEntryArray_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPico_LeaderboardEntryArray()
	{
		if (!Z_Registration_Info_UClass_UPico_LeaderboardEntryArray.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_LeaderboardEntryArray.OuterSingleton, Z_Construct_UClass_UPico_LeaderboardEntryArray_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_LeaderboardEntryArray.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_LeaderboardEntryArray>()
	{
		return UPico_LeaderboardEntryArray::StaticClass();
	}
	UPico_LeaderboardEntryArray::UPico_LeaderboardEntryArray(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_LeaderboardEntryArray);
	UPico_LeaderboardEntryArray::~UPico_LeaderboardEntryArray() {}
	DEFINE_FUNCTION(UPico_LeaderboardArray::execGetDebugString)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetDebugString();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_LeaderboardArray::execHasNextPage)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->HasNextPage();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_LeaderboardArray::execGetTotalSize)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetTotalSize();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_LeaderboardArray::execGetSize)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetSize();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_LeaderboardArray::execGetElement)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPico_Leaderboard**)Z_Param__Result=P_THIS->GetElement(Z_Param_Index);
		P_NATIVE_END;
	}
	void UPico_LeaderboardArray::StaticRegisterNativesUPico_LeaderboardArray()
	{
		UClass* Class = UPico_LeaderboardArray::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetDebugString", &UPico_LeaderboardArray::execGetDebugString },
			{ "GetElement", &UPico_LeaderboardArray::execGetElement },
			{ "GetSize", &UPico_LeaderboardArray::execGetSize },
			{ "GetTotalSize", &UPico_LeaderboardArray::execGetTotalSize },
			{ "HasNextPage", &UPico_LeaderboardArray::execHasNextPage },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_LeaderboardArray_GetDebugString_Statics
	{
		struct Pico_LeaderboardArray_eventGetDebugString_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_LeaderboardArray_GetDebugString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_LeaderboardArray_eventGetDebugString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_LeaderboardArray_GetDebugString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_LeaderboardArray_GetDebugString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_LeaderboardArray_GetDebugString_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Leaderboards|Leaderboard Definition Array" },
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_LeaderboardArray_GetDebugString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_LeaderboardArray, nullptr, "GetDebugString", nullptr, nullptr, Z_Construct_UFunction_UPico_LeaderboardArray_GetDebugString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardArray_GetDebugString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_LeaderboardArray_GetDebugString_Statics::Pico_LeaderboardArray_eventGetDebugString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardArray_GetDebugString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_LeaderboardArray_GetDebugString_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardArray_GetDebugString_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_LeaderboardArray_GetDebugString_Statics::Pico_LeaderboardArray_eventGetDebugString_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_LeaderboardArray_GetDebugString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_LeaderboardArray_GetDebugString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_LeaderboardArray_GetElement_Statics
	{
		struct Pico_LeaderboardArray_eventGetElement_Parms
		{
			int32 Index;
			UPico_Leaderboard* ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_LeaderboardArray_GetElement_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_LeaderboardArray_eventGetElement_Parms, Index), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPico_LeaderboardArray_GetElement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_LeaderboardArray_eventGetElement_Parms, ReturnValue), Z_Construct_UClass_UPico_Leaderboard_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_LeaderboardArray_GetElement_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_LeaderboardArray_GetElement_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_LeaderboardArray_GetElement_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_LeaderboardArray_GetElement_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Leaderboards|Leaderboard Definition Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get LeaderboardArray element form Index.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get LeaderboardArray element form Index." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_LeaderboardArray_GetElement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_LeaderboardArray, nullptr, "GetElement", nullptr, nullptr, Z_Construct_UFunction_UPico_LeaderboardArray_GetElement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardArray_GetElement_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_LeaderboardArray_GetElement_Statics::Pico_LeaderboardArray_eventGetElement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardArray_GetElement_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_LeaderboardArray_GetElement_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardArray_GetElement_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_LeaderboardArray_GetElement_Statics::Pico_LeaderboardArray_eventGetElement_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_LeaderboardArray_GetElement()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_LeaderboardArray_GetElement_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_LeaderboardArray_GetSize_Statics
	{
		struct Pico_LeaderboardArray_eventGetSize_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_LeaderboardArray_GetSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_LeaderboardArray_eventGetSize_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_LeaderboardArray_GetSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_LeaderboardArray_GetSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_LeaderboardArray_GetSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Leaderboards|Leaderboard Definition Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get the size of LeaderboardArray .*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get the size of LeaderboardArray ." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_LeaderboardArray_GetSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_LeaderboardArray, nullptr, "GetSize", nullptr, nullptr, Z_Construct_UFunction_UPico_LeaderboardArray_GetSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardArray_GetSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_LeaderboardArray_GetSize_Statics::Pico_LeaderboardArray_eventGetSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardArray_GetSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_LeaderboardArray_GetSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardArray_GetSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_LeaderboardArray_GetSize_Statics::Pico_LeaderboardArray_eventGetSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_LeaderboardArray_GetSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_LeaderboardArray_GetSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_LeaderboardArray_GetTotalSize_Statics
	{
		struct Pico_LeaderboardArray_eventGetTotalSize_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_LeaderboardArray_GetTotalSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_LeaderboardArray_eventGetTotalSize_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_LeaderboardArray_GetTotalSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_LeaderboardArray_GetTotalSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_LeaderboardArray_GetTotalSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Leaderboards|Leaderboard Definition Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get the total size of LeaderboardArray .*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get the total size of LeaderboardArray ." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_LeaderboardArray_GetTotalSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_LeaderboardArray, nullptr, "GetTotalSize", nullptr, nullptr, Z_Construct_UFunction_UPico_LeaderboardArray_GetTotalSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardArray_GetTotalSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_LeaderboardArray_GetTotalSize_Statics::Pico_LeaderboardArray_eventGetTotalSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardArray_GetTotalSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_LeaderboardArray_GetTotalSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardArray_GetTotalSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_LeaderboardArray_GetTotalSize_Statics::Pico_LeaderboardArray_eventGetTotalSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_LeaderboardArray_GetTotalSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_LeaderboardArray_GetTotalSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_LeaderboardArray_HasNextPage_Statics
	{
		struct Pico_LeaderboardArray_eventHasNextPage_Parms
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
	void Z_Construct_UFunction_UPico_LeaderboardArray_HasNextPage_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_LeaderboardArray_eventHasNextPage_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_LeaderboardArray_HasNextPage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_LeaderboardArray_eventHasNextPage_Parms), &Z_Construct_UFunction_UPico_LeaderboardArray_HasNextPage_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_LeaderboardArray_HasNextPage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_LeaderboardArray_HasNextPage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_LeaderboardArray_HasNextPage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Leaderboards|Leaderboard Definition Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get whether the list has the next page.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get whether the list has the next page." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_LeaderboardArray_HasNextPage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_LeaderboardArray, nullptr, "HasNextPage", nullptr, nullptr, Z_Construct_UFunction_UPico_LeaderboardArray_HasNextPage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardArray_HasNextPage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_LeaderboardArray_HasNextPage_Statics::Pico_LeaderboardArray_eventHasNextPage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardArray_HasNextPage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_LeaderboardArray_HasNextPage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_LeaderboardArray_HasNextPage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_LeaderboardArray_HasNextPage_Statics::Pico_LeaderboardArray_eventHasNextPage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_LeaderboardArray_HasNextPage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_LeaderboardArray_HasNextPage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_LeaderboardArray);
	UClass* Z_Construct_UClass_UPico_LeaderboardArray_NoRegister()
	{
		return UPico_LeaderboardArray::StaticClass();
	}
	struct Z_Construct_UClass_UPico_LeaderboardArray_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LeaderboardArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LeaderboardArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_LeaderboardArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_LeaderboardArray_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_LeaderboardArray_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_LeaderboardArray_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_LeaderboardArray_GetDebugString, "GetDebugString" }, // 4173520760
		{ &Z_Construct_UFunction_UPico_LeaderboardArray_GetElement, "GetElement" }, // 2942435010
		{ &Z_Construct_UFunction_UPico_LeaderboardArray_GetSize, "GetSize" }, // 1820546420
		{ &Z_Construct_UFunction_UPico_LeaderboardArray_GetTotalSize, "GetTotalSize" }, // 4057900097
		{ &Z_Construct_UFunction_UPico_LeaderboardArray_HasNextPage, "HasNextPage" }, // 1431342658
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_LeaderboardArray_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_LeaderboardArray_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_LeaderboardArray class.\n" },
#endif
		{ "IncludePath", "Pico_Leaderboards.h" },
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_LeaderboardArray class." },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPico_LeaderboardArray_Statics::NewProp_LeaderboardArray_Inner = { "LeaderboardArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UPico_Leaderboard_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_LeaderboardArray_Statics::NewProp_LeaderboardArray_MetaData[] = {
		{ "ModuleRelativePath", "Public/Pico_Leaderboards.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPico_LeaderboardArray_Statics::NewProp_LeaderboardArray = { "LeaderboardArray", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPico_LeaderboardArray, LeaderboardArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_LeaderboardArray_Statics::NewProp_LeaderboardArray_MetaData), Z_Construct_UClass_UPico_LeaderboardArray_Statics::NewProp_LeaderboardArray_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPico_LeaderboardArray_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_LeaderboardArray_Statics::NewProp_LeaderboardArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_LeaderboardArray_Statics::NewProp_LeaderboardArray,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_LeaderboardArray_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_LeaderboardArray>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_LeaderboardArray_Statics::ClassParams = {
		&UPico_LeaderboardArray::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPico_LeaderboardArray_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPico_LeaderboardArray_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_LeaderboardArray_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_LeaderboardArray_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_LeaderboardArray_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPico_LeaderboardArray()
	{
		if (!Z_Registration_Info_UClass_UPico_LeaderboardArray.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_LeaderboardArray.OuterSingleton, Z_Construct_UClass_UPico_LeaderboardArray_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_LeaderboardArray.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_LeaderboardArray>()
	{
		return UPico_LeaderboardArray::StaticClass();
	}
	UPico_LeaderboardArray::UPico_LeaderboardArray(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_LeaderboardArray);
	UPico_LeaderboardArray::~UPico_LeaderboardArray() {}
	struct Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Leaderboards_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Leaderboards_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOnlinePicoLeaderboardsFunction, UOnlinePicoLeaderboardsFunction::StaticClass, TEXT("UOnlinePicoLeaderboardsFunction"), &Z_Registration_Info_UClass_UOnlinePicoLeaderboardsFunction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOnlinePicoLeaderboardsFunction), 2341302318U) },
		{ Z_Construct_UClass_UPico_LeaderboardEntry, UPico_LeaderboardEntry::StaticClass, TEXT("UPico_LeaderboardEntry"), &Z_Registration_Info_UClass_UPico_LeaderboardEntry, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_LeaderboardEntry), 1133923061U) },
		{ Z_Construct_UClass_UPico_Leaderboard, UPico_Leaderboard::StaticClass, TEXT("UPico_Leaderboard"), &Z_Registration_Info_UClass_UPico_Leaderboard, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_Leaderboard), 3806581404U) },
		{ Z_Construct_UClass_UPico_LeaderboardEntryArray, UPico_LeaderboardEntryArray::StaticClass, TEXT("UPico_LeaderboardEntryArray"), &Z_Registration_Info_UClass_UPico_LeaderboardEntryArray, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_LeaderboardEntryArray), 1625048968U) },
		{ Z_Construct_UClass_UPico_LeaderboardArray, UPico_LeaderboardArray::StaticClass, TEXT("UPico_LeaderboardArray"), &Z_Registration_Info_UClass_UPico_LeaderboardArray, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_LeaderboardArray), 3306372476U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Leaderboards_h_2617191547(TEXT("/Script/OnlineSubsystemPico"),
		Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Leaderboards_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Leaderboards_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
