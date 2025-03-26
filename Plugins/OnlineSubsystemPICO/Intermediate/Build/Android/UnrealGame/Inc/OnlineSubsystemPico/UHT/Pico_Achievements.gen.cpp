// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../OnlineSubsystemPico/Public/Pico_Achievements.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePico_Achievements() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoAchievementsFunction();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoAchievementsFunction_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AchievementDefinition();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AchievementDefinition_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AchievementDefinitionArray();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AchievementDefinitionArray_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AchievementProgress();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AchievementProgress_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AchievementProgressArray();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AchievementProgressArray_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AchievementUpdate();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AchievementUpdate_NoRegister();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_EAchievementType();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_EAchievementWritePolicy();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemPico();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventAddCount_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_AchievementUpdate* AchievementUpdate;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AchievementUpdate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventAddCount_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventAddCount_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventAddCount_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature_Statics::NewProp_AchievementUpdate = { "AchievementUpdate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventAddCount_Parms, AchievementUpdate), Z_Construct_UClass_UPico_AchievementUpdate_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature_Statics::NewProp_AchievementUpdate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "AddCount__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventAddCount_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventAddCount_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FAddCount_DelegateWrapper(const FScriptDelegate& AddCount, bool bIsError, const FString& ErrorMessage, UPico_AchievementUpdate* AchievementUpdate)
{
	struct _Script_OnlineSubsystemPico_eventAddCount_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_AchievementUpdate* AchievementUpdate;
	};
	_Script_OnlineSubsystemPico_eventAddCount_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.AchievementUpdate=AchievementUpdate;
	AddCount.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventAddFields_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_AchievementUpdate* AchievementUpdate;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AchievementUpdate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventAddFields_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventAddFields_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventAddFields_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature_Statics::NewProp_AchievementUpdate = { "AchievementUpdate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventAddFields_Parms, AchievementUpdate), Z_Construct_UClass_UPico_AchievementUpdate_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature_Statics::NewProp_AchievementUpdate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "AddFields__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventAddFields_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventAddFields_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FAddFields_DelegateWrapper(const FScriptDelegate& AddFields, bool bIsError, const FString& ErrorMessage, UPico_AchievementUpdate* AchievementUpdate)
{
	struct _Script_OnlineSubsystemPico_eventAddFields_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_AchievementUpdate* AchievementUpdate;
	};
	_Script_OnlineSubsystemPico_eventAddFields_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.AchievementUpdate=AchievementUpdate;
	AddFields.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventUnlock_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_AchievementUpdate* AchievementUpdate;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AchievementUpdate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventUnlock_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventUnlock_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventUnlock_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature_Statics::NewProp_AchievementUpdate = { "AchievementUpdate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventUnlock_Parms, AchievementUpdate), Z_Construct_UClass_UPico_AchievementUpdate_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature_Statics::NewProp_AchievementUpdate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "Unlock__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventUnlock_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventUnlock_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FUnlock_DelegateWrapper(const FScriptDelegate& Unlock, bool bIsError, const FString& ErrorMessage, UPico_AchievementUpdate* AchievementUpdate)
{
	struct _Script_OnlineSubsystemPico_eventUnlock_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_AchievementUpdate* AchievementUpdate;
	};
	_Script_OnlineSubsystemPico_eventUnlock_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.AchievementUpdate=AchievementUpdate;
	Unlock.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetAllDefinitions_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_AchievementDefinitionArray* AchievementDefinitionArray;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AchievementDefinitionArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetAllDefinitions_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetAllDefinitions_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetAllDefinitions_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature_Statics::NewProp_AchievementDefinitionArray = { "AchievementDefinitionArray", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetAllDefinitions_Parms, AchievementDefinitionArray), Z_Construct_UClass_UPico_AchievementDefinitionArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature_Statics::NewProp_AchievementDefinitionArray,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetAllDefinitions__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetAllDefinitions_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetAllDefinitions_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetAllDefinitions_DelegateWrapper(const FScriptDelegate& GetAllDefinitions, bool bIsError, const FString& ErrorMessage, UPico_AchievementDefinitionArray* AchievementDefinitionArray)
{
	struct _Script_OnlineSubsystemPico_eventGetAllDefinitions_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_AchievementDefinitionArray* AchievementDefinitionArray;
	};
	_Script_OnlineSubsystemPico_eventGetAllDefinitions_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.AchievementDefinitionArray=AchievementDefinitionArray;
	GetAllDefinitions.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetAllProgress_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_AchievementProgressArray* AchievementProgressArray;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AchievementProgressArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetAllProgress_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetAllProgress_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetAllProgress_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature_Statics::NewProp_AchievementProgressArray = { "AchievementProgressArray", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetAllProgress_Parms, AchievementProgressArray), Z_Construct_UClass_UPico_AchievementProgressArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature_Statics::NewProp_AchievementProgressArray,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetAllProgress__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetAllProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetAllProgress_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetAllProgress_DelegateWrapper(const FScriptDelegate& GetAllProgress, bool bIsError, const FString& ErrorMessage, UPico_AchievementProgressArray* AchievementProgressArray)
{
	struct _Script_OnlineSubsystemPico_eventGetAllProgress_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_AchievementProgressArray* AchievementProgressArray;
	};
	_Script_OnlineSubsystemPico_eventGetAllProgress_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.AchievementProgressArray=AchievementProgressArray;
	GetAllProgress.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetDefinitionsByName_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_AchievementDefinitionArray* AchievementDefinitionArray;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AchievementDefinitionArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetDefinitionsByName_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetDefinitionsByName_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetDefinitionsByName_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature_Statics::NewProp_AchievementDefinitionArray = { "AchievementDefinitionArray", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetDefinitionsByName_Parms, AchievementDefinitionArray), Z_Construct_UClass_UPico_AchievementDefinitionArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature_Statics::NewProp_AchievementDefinitionArray,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetDefinitionsByName__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetDefinitionsByName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetDefinitionsByName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetDefinitionsByName_DelegateWrapper(const FScriptDelegate& GetDefinitionsByName, bool bIsError, const FString& ErrorMessage, UPico_AchievementDefinitionArray* AchievementDefinitionArray)
{
	struct _Script_OnlineSubsystemPico_eventGetDefinitionsByName_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_AchievementDefinitionArray* AchievementDefinitionArray;
	};
	_Script_OnlineSubsystemPico_eventGetDefinitionsByName_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.AchievementDefinitionArray=AchievementDefinitionArray;
	GetDefinitionsByName.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetProgressByName_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_AchievementProgressArray* AchievementProgressArray;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AchievementProgressArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetProgressByName_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetProgressByName_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetProgressByName_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature_Statics::NewProp_AchievementProgressArray = { "AchievementProgressArray", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetProgressByName_Parms, AchievementProgressArray), Z_Construct_UClass_UPico_AchievementProgressArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature_Statics::NewProp_AchievementProgressArray,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetProgressByName__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetProgressByName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetProgressByName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetProgressByName_DelegateWrapper(const FScriptDelegate& GetProgressByName, bool bIsError, const FString& ErrorMessage, UPico_AchievementProgressArray* AchievementProgressArray)
{
	struct _Script_OnlineSubsystemPico_eventGetProgressByName_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_AchievementProgressArray* AchievementProgressArray;
	};
	_Script_OnlineSubsystemPico_eventGetProgressByName_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.AchievementProgressArray=AchievementProgressArray;
	GetProgressByName.ProcessDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UOnlinePicoAchievementsFunction::execPicoGetProgressByName)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_TARRAY_REF(FString,Z_Param_Out_NameArray);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetProgressByNameCallback);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoAchievementsFunction::PicoGetProgressByName(Z_Param_WorldContextObject,Z_Param_Out_NameArray,FGetProgressByName(Z_Param_InGetProgressByNameCallback));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoAchievementsFunction::execPicoGetDefinitionsByName)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_TARRAY_REF(FString,Z_Param_Out_NameArray);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetDefinitionsByNameCallback);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoAchievementsFunction::PicoGetDefinitionsByName(Z_Param_WorldContextObject,Z_Param_Out_NameArray,FGetDefinitionsByName(Z_Param_InGetDefinitionsByNameCallback));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoAchievementsFunction::execPicoGetAllProgress)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FIntProperty,Z_Param_PageIndex);
		P_GET_PROPERTY(FIntProperty,Z_Param_PageSize);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetAllProgressCallback);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoAchievementsFunction::PicoGetAllProgress(Z_Param_WorldContextObject,Z_Param_PageIndex,Z_Param_PageSize,FGetAllProgress(Z_Param_InGetAllProgressCallback));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoAchievementsFunction::execPicoGetAllDefinitions)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FIntProperty,Z_Param_PageIndex);
		P_GET_PROPERTY(FIntProperty,Z_Param_PageSize);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetAllDefinitionsCallback);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoAchievementsFunction::PicoGetAllDefinitions(Z_Param_WorldContextObject,Z_Param_PageIndex,Z_Param_PageSize,FGetAllDefinitions(Z_Param_InGetAllDefinitionsCallback));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoAchievementsFunction::execPicoUnlock)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_Name);
		P_GET_PROPERTY(FStrProperty,Z_Param_ExtraData);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InUnlockCallback);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoAchievementsFunction::PicoUnlock(Z_Param_WorldContextObject,Z_Param_Name,Z_Param_ExtraData,FUnlock(Z_Param_InUnlockCallback));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoAchievementsFunction::execPicoAddFields)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_Name);
		P_GET_PROPERTY(FStrProperty,Z_Param_Fields);
		P_GET_PROPERTY(FStrProperty,Z_Param_ExtraData);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InAddFieldsCallback);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoAchievementsFunction::PicoAddFields(Z_Param_WorldContextObject,Z_Param_Name,Z_Param_Fields,Z_Param_ExtraData,FAddFields(Z_Param_InAddFieldsCallback));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoAchievementsFunction::execPicoAddCount)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_Name);
		P_GET_PROPERTY(FStrProperty,Z_Param_Count);
		P_GET_PROPERTY(FStrProperty,Z_Param_ExtraData);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InAddCountCallback);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoAchievementsFunction::PicoAddCount(Z_Param_WorldContextObject,Z_Param_Name,Z_Param_Count,Z_Param_ExtraData,FAddCount(Z_Param_InAddCountCallback));
		P_NATIVE_END;
	}
	void UOnlinePicoAchievementsFunction::StaticRegisterNativesUOnlinePicoAchievementsFunction()
	{
		UClass* Class = UOnlinePicoAchievementsFunction::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "PicoAddCount", &UOnlinePicoAchievementsFunction::execPicoAddCount },
			{ "PicoAddFields", &UOnlinePicoAchievementsFunction::execPicoAddFields },
			{ "PicoGetAllDefinitions", &UOnlinePicoAchievementsFunction::execPicoGetAllDefinitions },
			{ "PicoGetAllProgress", &UOnlinePicoAchievementsFunction::execPicoGetAllProgress },
			{ "PicoGetDefinitionsByName", &UOnlinePicoAchievementsFunction::execPicoGetDefinitionsByName },
			{ "PicoGetProgressByName", &UOnlinePicoAchievementsFunction::execPicoGetProgressByName },
			{ "PicoUnlock", &UOnlinePicoAchievementsFunction::execPicoUnlock },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics
	{
		struct OnlinePicoAchievementsFunction_eventPicoAddCount_Parms
		{
			UObject* WorldContextObject;
			FString Name;
			FString Count;
			FString ExtraData;
			FScriptDelegate InAddCountCallback;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Count_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Count;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ExtraData_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ExtraData;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InAddCountCallback;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoAddCount_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoAddCount_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::NewProp_Name_MetaData), Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::NewProp_Name_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::NewProp_Count_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::NewProp_Count = { "Count", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoAddCount_Parms, Count), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::NewProp_Count_MetaData), Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::NewProp_Count_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::NewProp_ExtraData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::NewProp_ExtraData = { "ExtraData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoAddCount_Parms, ExtraData), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::NewProp_ExtraData_MetaData), Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::NewProp_ExtraData_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::NewProp_InAddCountCallback = { "InAddCountCallback", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoAddCount_Parms, InAddCountCallback), Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddCount__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2113497202
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::NewProp_Count,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::NewProp_ExtraData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::NewProp_InAddCountCallback,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Achievements" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Adds a count to a specified count achievement. The count will be added to the current count,\n/// for example, if the current count is 1 and the count you would like to add is 7, the final count will be 8 if the request succeeds.\n/// @note Available to count achievements only.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"Name\">The API name of the achievement.</param>\n/// <param name=\"Count\">The count you want to add. The largest count supported by this function is the maximum value of a signed 64-bit integer.\n/// If the count is larger than that, it is clamped to that maximum value before being passed to the servers.\n/// </param>\n/// <param name=\"ExtraData\">Custom extension fields that can be used to record key information when unlocking achievements.</param>\n/// <param name=\"InAddCountCallback\">Will be executed when the request has been completed.\n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementUpdate *, AchievementUpdate).</param>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Adds a count to a specified count achievement. The count will be added to the current count,\nfor example, if the current count is 1 and the count you would like to add is 7, the final count will be 8 if the request succeeds.\n@note Available to count achievements only.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"Name\">The API name of the achievement.</param>\n<param name=\"Count\">The count you want to add. The largest count supported by this function is the maximum value of a signed 64-bit integer.\nIf the count is larger than that, it is clamped to that maximum value before being passed to the servers.\n</param>\n<param name=\"ExtraData\">Custom extension fields that can be used to record key information when unlocking achievements.</param>\n<param name=\"InAddCountCallback\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementUpdate *, AchievementUpdate).</param>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoAchievementsFunction, nullptr, "PicoAddCount", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::OnlinePicoAchievementsFunction_eventPicoAddCount_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::OnlinePicoAchievementsFunction_eventPicoAddCount_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics
	{
		struct OnlinePicoAchievementsFunction_eventPicoAddFields_Parms
		{
			UObject* WorldContextObject;
			FString Name;
			FString Fields;
			FString ExtraData;
			FScriptDelegate InAddFieldsCallback;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Fields_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Fields;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ExtraData_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ExtraData;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InAddFieldsCallback;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoAddFields_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoAddFields_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::NewProp_Name_MetaData), Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::NewProp_Name_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::NewProp_Fields_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::NewProp_Fields = { "Fields", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoAddFields_Parms, Fields), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::NewProp_Fields_MetaData), Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::NewProp_Fields_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::NewProp_ExtraData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::NewProp_ExtraData = { "ExtraData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoAddFields_Parms, ExtraData), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::NewProp_ExtraData_MetaData), Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::NewProp_ExtraData_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::NewProp_InAddFieldsCallback = { "InAddFieldsCallback", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoAddFields_Parms, InAddFieldsCallback), Z_Construct_UDelegateFunction_OnlineSubsystemPico_AddFields__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3190645720
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::NewProp_Fields,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::NewProp_ExtraData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::NewProp_InAddFieldsCallback,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Achievements" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Unlocks the bit(s) of a specified bitfield achievement. The status of the bit(s) is then unchangeable.\n/// @note Available to bitfield achievements only.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"Name\">The API name of the achievement to unlock bit(s) for.</param>\n/// <param name=\"Fields\">A string containing either '0' or '1' characters, for example '100011'.\n/// Every '1' will unlock a bit in the corresponding position of a bitfield.\n/// </param>\n/// <param name=\"ExtraData\">Custom extension fields that can be used to record key information when unlocking achievements.</param>\n/// <param name=\"InAddFieldsCallback\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementUpdate *, AchievementUpdate).</param>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Unlocks the bit(s) of a specified bitfield achievement. The status of the bit(s) is then unchangeable.\n@note Available to bitfield achievements only.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"Name\">The API name of the achievement to unlock bit(s) for.</param>\n<param name=\"Fields\">A string containing either '0' or '1' characters, for example '100011'.\nEvery '1' will unlock a bit in the corresponding position of a bitfield.\n</param>\n<param name=\"ExtraData\">Custom extension fields that can be used to record key information when unlocking achievements.</param>\n<param name=\"InAddFieldsCallback\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementUpdate *, AchievementUpdate).</param>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoAchievementsFunction, nullptr, "PicoAddFields", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::OnlinePicoAchievementsFunction_eventPicoAddFields_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::OnlinePicoAchievementsFunction_eventPicoAddFields_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllDefinitions_Statics
	{
		struct OnlinePicoAchievementsFunction_eventPicoGetAllDefinitions_Parms
		{
			UObject* WorldContextObject;
			int32 PageIndex;
			int32 PageSize;
			FScriptDelegate InGetAllDefinitionsCallback;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FIntPropertyParams NewProp_PageIndex;
		static const UECodeGen_Private::FIntPropertyParams NewProp_PageSize;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetAllDefinitionsCallback;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllDefinitions_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoGetAllDefinitions_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllDefinitions_Statics::NewProp_PageIndex = { "PageIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoGetAllDefinitions_Parms, PageIndex), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllDefinitions_Statics::NewProp_PageSize = { "PageSize", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoGetAllDefinitions_Parms, PageSize), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllDefinitions_Statics::NewProp_InGetAllDefinitionsCallback = { "InGetAllDefinitionsCallback", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoGetAllDefinitions_Parms, InGetAllDefinitionsCallback), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllDefinitions__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 910249100
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllDefinitions_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllDefinitions_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllDefinitions_Statics::NewProp_PageIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllDefinitions_Statics::NewProp_PageSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllDefinitions_Statics::NewProp_InGetAllDefinitionsCallback,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllDefinitions_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Achievements" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the information about all achievements,\n/// including API names, descriptions, types, the targets which must be reached to unlock those achievements, and more.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"PageIndex\">The start index of the pages.</param>\n/// <param name=\"PageSize\">The number of entries to return on each page.</param>\n/// <param name=\"InGetAllDefinitionsCallback\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementDefinitionArray *, AchievementDefinitionArray).</param>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the information about all achievements,\nincluding API names, descriptions, types, the targets which must be reached to unlock those achievements, and more.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"PageIndex\">The start index of the pages.</param>\n<param name=\"PageSize\">The number of entries to return on each page.</param>\n<param name=\"InGetAllDefinitionsCallback\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementDefinitionArray *, AchievementDefinitionArray).</param>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllDefinitions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoAchievementsFunction, nullptr, "PicoGetAllDefinitions", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllDefinitions_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllDefinitions_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllDefinitions_Statics::OnlinePicoAchievementsFunction_eventPicoGetAllDefinitions_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllDefinitions_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllDefinitions_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllDefinitions_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllDefinitions_Statics::OnlinePicoAchievementsFunction_eventPicoGetAllDefinitions_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllDefinitions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllDefinitions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllProgress_Statics
	{
		struct OnlinePicoAchievementsFunction_eventPicoGetAllProgress_Parms
		{
			UObject* WorldContextObject;
			int32 PageIndex;
			int32 PageSize;
			FScriptDelegate InGetAllProgressCallback;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FIntPropertyParams NewProp_PageIndex;
		static const UECodeGen_Private::FIntPropertyParams NewProp_PageSize;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetAllProgressCallback;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllProgress_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoGetAllProgress_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllProgress_Statics::NewProp_PageIndex = { "PageIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoGetAllProgress_Parms, PageIndex), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllProgress_Statics::NewProp_PageSize = { "PageSize", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoGetAllProgress_Parms, PageSize), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllProgress_Statics::NewProp_InGetAllProgressCallback = { "InGetAllProgressCallback", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoGetAllProgress_Parms, InGetAllProgressCallback), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAllProgress__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3575863366
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllProgress_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllProgress_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllProgress_Statics::NewProp_PageIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllProgress_Statics::NewProp_PageSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllProgress_Statics::NewProp_InGetAllProgressCallback,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllProgress_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Achievements" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the user's progress on all achievements,\n/// including API names, whether or not the achievements are unlocked, the time at which they were unlocked, achievement types and,\n/// depending on the type, the progress made towards unlocking them, and more.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"PageIndex\">The start index of the pages.</param>\n/// <param name=\"PageSize\">The number of entries to return on each page.</param>\n/// <param name=\"InGetAllProgressCallback\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementProgressArray *, AchievementProgressArray).</param>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the user's progress on all achievements,\nincluding API names, whether or not the achievements are unlocked, the time at which they were unlocked, achievement types and,\ndepending on the type, the progress made towards unlocking them, and more.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"PageIndex\">The start index of the pages.</param>\n<param name=\"PageSize\">The number of entries to return on each page.</param>\n<param name=\"InGetAllProgressCallback\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementProgressArray *, AchievementProgressArray).</param>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllProgress_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoAchievementsFunction, nullptr, "PicoGetAllProgress", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllProgress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllProgress_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllProgress_Statics::OnlinePicoAchievementsFunction_eventPicoGetAllProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllProgress_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllProgress_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllProgress_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllProgress_Statics::OnlinePicoAchievementsFunction_eventPicoGetAllProgress_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllProgress()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllProgress_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName_Statics
	{
		struct OnlinePicoAchievementsFunction_eventPicoGetDefinitionsByName_Parms
		{
			UObject* WorldContextObject;
			TArray<FString> NameArray;
			FScriptDelegate InGetDefinitionsByNameCallback;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FStrPropertyParams NewProp_NameArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NameArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_NameArray;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetDefinitionsByNameCallback;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoGetDefinitionsByName_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName_Statics::NewProp_NameArray_Inner = { "NameArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName_Statics::NewProp_NameArray_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName_Statics::NewProp_NameArray = { "NameArray", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoGetDefinitionsByName_Parms, NameArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName_Statics::NewProp_NameArray_MetaData), Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName_Statics::NewProp_NameArray_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName_Statics::NewProp_InGetDefinitionsByNameCallback = { "InGetDefinitionsByNameCallback", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoGetDefinitionsByName_Parms, InGetDefinitionsByNameCallback), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetDefinitionsByName__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3954862737
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName_Statics::NewProp_NameArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName_Statics::NewProp_NameArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName_Statics::NewProp_InGetDefinitionsByNameCallback,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Achievements" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the information about specified achievements,\n/// including API names, descriptions, types, the targets which must be reached to unlock those achievements, and more.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"NameArray\">The API names of the achievements.</param>\n/// <param name=\"InGetDefinitionsByNameCallback\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementDefinitionArray *, AchievementDefinitionArray).</param>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the information about specified achievements,\nincluding API names, descriptions, types, the targets which must be reached to unlock those achievements, and more.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"NameArray\">The API names of the achievements.</param>\n<param name=\"InGetDefinitionsByNameCallback\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementDefinitionArray *, AchievementDefinitionArray).</param>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoAchievementsFunction, nullptr, "PicoGetDefinitionsByName", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName_Statics::OnlinePicoAchievementsFunction_eventPicoGetDefinitionsByName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName_Statics::OnlinePicoAchievementsFunction_eventPicoGetDefinitionsByName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName_Statics
	{
		struct OnlinePicoAchievementsFunction_eventPicoGetProgressByName_Parms
		{
			UObject* WorldContextObject;
			TArray<FString> NameArray;
			FScriptDelegate InGetProgressByNameCallback;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FStrPropertyParams NewProp_NameArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NameArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_NameArray;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetProgressByNameCallback;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoGetProgressByName_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName_Statics::NewProp_NameArray_Inner = { "NameArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName_Statics::NewProp_NameArray_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName_Statics::NewProp_NameArray = { "NameArray", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoGetProgressByName_Parms, NameArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName_Statics::NewProp_NameArray_MetaData), Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName_Statics::NewProp_NameArray_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName_Statics::NewProp_InGetProgressByNameCallback = { "InGetProgressByNameCallback", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoGetProgressByName_Parms, InGetProgressByNameCallback), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProgressByName__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2357326393
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName_Statics::NewProp_NameArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName_Statics::NewProp_NameArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName_Statics::NewProp_InGetProgressByNameCallback,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Achievements" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the user's progress on specified achievements,\n/// including API names, whether or not the achievements are unlocked, the time at which they were unlocked, achievement types and,\n/// depending on the type, the progress made towards unlocking them, and more.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"NameArray\">The API names of the achievements.</param>\n/// <param name=\"InGetProgressByNameCallback\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementProgressArray *, AchievementProgressArray).</param>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the user's progress on specified achievements,\nincluding API names, whether or not the achievements are unlocked, the time at which they were unlocked, achievement types and,\ndepending on the type, the progress made towards unlocking them, and more.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"NameArray\">The API names of the achievements.</param>\n<param name=\"InGetProgressByNameCallback\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_AchievementProgressArray *, AchievementProgressArray).</param>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoAchievementsFunction, nullptr, "PicoGetProgressByName", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName_Statics::OnlinePicoAchievementsFunction_eventPicoGetProgressByName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName_Statics::OnlinePicoAchievementsFunction_eventPicoGetProgressByName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics
	{
		struct OnlinePicoAchievementsFunction_eventPicoUnlock_Parms
		{
			UObject* WorldContextObject;
			FString Name;
			FString ExtraData;
			FScriptDelegate InUnlockCallback;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ExtraData_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ExtraData;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InUnlockCallback;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoUnlock_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoUnlock_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::NewProp_Name_MetaData), Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::NewProp_Name_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::NewProp_ExtraData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::NewProp_ExtraData = { "ExtraData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoUnlock_Parms, ExtraData), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::NewProp_ExtraData_MetaData), Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::NewProp_ExtraData_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::NewProp_InUnlockCallback = { "InUnlockCallback", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoAchievementsFunction_eventPicoUnlock_Parms, InUnlockCallback), Z_Construct_UDelegateFunction_OnlineSubsystemPico_Unlock__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 95266557
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::NewProp_ExtraData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::NewProp_InUnlockCallback,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Achievements" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Unlocks a specified achievement of any type even if the target for unlocking this achievement is not reached.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"Name\">The API name of the achievement to unlock.</param>\n/// <param name=\"ExtraData\">Custom extension fields that can be used to record key information when unlocking achievements.</param>\n/// <param name=\"InUnlockCallback\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bIsError, const FString&, ErrorMessage, UPico_AchievementUpdate *, AchievementUpdate).</param>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Unlocks a specified achievement of any type even if the target for unlocking this achievement is not reached.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"Name\">The API name of the achievement to unlock.</param>\n<param name=\"ExtraData\">Custom extension fields that can be used to record key information when unlocking achievements.</param>\n<param name=\"InUnlockCallback\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bIsError, const FString&, ErrorMessage, UPico_AchievementUpdate *, AchievementUpdate).</param>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoAchievementsFunction, nullptr, "PicoUnlock", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::OnlinePicoAchievementsFunction_eventPicoUnlock_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::OnlinePicoAchievementsFunction_eventPicoUnlock_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOnlinePicoAchievementsFunction);
	UClass* Z_Construct_UClass_UOnlinePicoAchievementsFunction_NoRegister()
	{
		return UOnlinePicoAchievementsFunction::StaticClass();
	}
	struct Z_Construct_UClass_UOnlinePicoAchievementsFunction_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOnlinePicoAchievementsFunction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoAchievementsFunction_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UOnlinePicoAchievementsFunction_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddCount, "PicoAddCount" }, // 2986463494
		{ &Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoAddFields, "PicoAddFields" }, // 1343134761
		{ &Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllDefinitions, "PicoGetAllDefinitions" }, // 517978646
		{ &Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetAllProgress, "PicoGetAllProgress" }, // 969646338
		{ &Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetDefinitionsByName, "PicoGetDefinitionsByName" }, // 1031250373
		{ &Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoGetProgressByName, "PicoGetProgressByName" }, // 1267176843
		{ &Z_Construct_UFunction_UOnlinePicoAchievementsFunction_PicoUnlock, "PicoUnlock" }, // 2259416554
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoAchievementsFunction_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoAchievementsFunction_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @defgroup BP_Achievements BP_Achievements\n *  This is the BP_Achievements group\n *  @{\n *//// @brief OnlinePicoAchievements Blueprint Function class.\n" },
#endif
		{ "IncludePath", "Pico_Achievements.h" },
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@defgroup BP_Achievements BP_Achievements\nThis is the BP_Achievements group\n@{\n/// @brief OnlinePicoAchievements Blueprint Function class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOnlinePicoAchievementsFunction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOnlinePicoAchievementsFunction>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOnlinePicoAchievementsFunction_Statics::ClassParams = {
		&UOnlinePicoAchievementsFunction::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoAchievementsFunction_Statics::Class_MetaDataParams), Z_Construct_UClass_UOnlinePicoAchievementsFunction_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UOnlinePicoAchievementsFunction()
	{
		if (!Z_Registration_Info_UClass_UOnlinePicoAchievementsFunction.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOnlinePicoAchievementsFunction.OuterSingleton, Z_Construct_UClass_UOnlinePicoAchievementsFunction_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOnlinePicoAchievementsFunction.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UOnlinePicoAchievementsFunction>()
	{
		return UOnlinePicoAchievementsFunction::StaticClass();
	}
	UOnlinePicoAchievementsFunction::UOnlinePicoAchievementsFunction(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOnlinePicoAchievementsFunction);
	UOnlinePicoAchievementsFunction::~UOnlinePicoAchievementsFunction() {}
	DEFINE_FUNCTION(UPico_AchievementUpdate::execGetJustUnlocked)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetJustUnlocked();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementUpdate::execGetName)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetName();
		P_NATIVE_END;
	}
	void UPico_AchievementUpdate::StaticRegisterNativesUPico_AchievementUpdate()
	{
		UClass* Class = UPico_AchievementUpdate::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetJustUnlocked", &UPico_AchievementUpdate::execGetJustUnlocked },
			{ "GetName", &UPico_AchievementUpdate::execGetName },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_AchievementUpdate_GetJustUnlocked_Statics
	{
		struct Pico_AchievementUpdate_eventGetJustUnlocked_Parms
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
	void Z_Construct_UFunction_UPico_AchievementUpdate_GetJustUnlocked_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_AchievementUpdate_eventGetJustUnlocked_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_AchievementUpdate_GetJustUnlocked_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_AchievementUpdate_eventGetJustUnlocked_Parms), &Z_Construct_UFunction_UPico_AchievementUpdate_GetJustUnlocked_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementUpdate_GetJustUnlocked_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementUpdate_GetJustUnlocked_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementUpdate_GetJustUnlocked_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Update" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Whether the achievement is unlocked in this time. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Whether the achievement is unlocked in this time." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementUpdate_GetJustUnlocked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementUpdate, nullptr, "GetJustUnlocked", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementUpdate_GetJustUnlocked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementUpdate_GetJustUnlocked_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementUpdate_GetJustUnlocked_Statics::Pico_AchievementUpdate_eventGetJustUnlocked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementUpdate_GetJustUnlocked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementUpdate_GetJustUnlocked_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementUpdate_GetJustUnlocked_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementUpdate_GetJustUnlocked_Statics::Pico_AchievementUpdate_eventGetJustUnlocked_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementUpdate_GetJustUnlocked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementUpdate_GetJustUnlocked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementUpdate_GetName_Statics
	{
		struct Pico_AchievementUpdate_eventGetName_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AchievementUpdate_GetName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementUpdate_eventGetName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementUpdate_GetName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementUpdate_GetName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementUpdate_GetName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Update" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Achievement name. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Achievement name." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementUpdate_GetName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementUpdate, nullptr, "GetName", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementUpdate_GetName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementUpdate_GetName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementUpdate_GetName_Statics::Pico_AchievementUpdate_eventGetName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementUpdate_GetName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementUpdate_GetName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementUpdate_GetName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementUpdate_GetName_Statics::Pico_AchievementUpdate_eventGetName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementUpdate_GetName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementUpdate_GetName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_AchievementUpdate);
	UClass* Z_Construct_UClass_UPico_AchievementUpdate_NoRegister()
	{
		return UPico_AchievementUpdate::StaticClass();
	}
	struct Z_Construct_UClass_UPico_AchievementUpdate_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_AchievementUpdate_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AchievementUpdate_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_AchievementUpdate_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_AchievementUpdate_GetJustUnlocked, "GetJustUnlocked" }, // 220973603
		{ &Z_Construct_UFunction_UPico_AchievementUpdate_GetName, "GetName" }, // 1215044447
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AchievementUpdate_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_AchievementUpdate_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_AchievementUpdate class.\n" },
#endif
		{ "IncludePath", "Pico_Achievements.h" },
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_AchievementUpdate class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_AchievementUpdate_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_AchievementUpdate>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_AchievementUpdate_Statics::ClassParams = {
		&UPico_AchievementUpdate::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AchievementUpdate_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_AchievementUpdate_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPico_AchievementUpdate()
	{
		if (!Z_Registration_Info_UClass_UPico_AchievementUpdate.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_AchievementUpdate.OuterSingleton, Z_Construct_UClass_UPico_AchievementUpdate_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_AchievementUpdate.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_AchievementUpdate>()
	{
		return UPico_AchievementUpdate::StaticClass();
	}
	UPico_AchievementUpdate::UPico_AchievementUpdate(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_AchievementUpdate);
	UPico_AchievementUpdate::~UPico_AchievementUpdate() {}
	DEFINE_FUNCTION(UPico_AchievementProgress::execGetExtraDataString)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetExtraDataString();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementProgress::execGetExtraData)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<uint8>*)Z_Param__Result=P_THIS->GetExtraData();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementProgress::execGetID)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetID();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementProgress::execGetUnlockDateTime)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FDateTime*)Z_Param__Result=P_THIS->GetUnlockDateTime();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementProgress::execGetUnlockTime)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetUnlockTime();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementProgress::execGetName)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetName();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementProgress::execGetIsUnlocked)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetIsUnlocked();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementProgress::execGetCount)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int64*)Z_Param__Result=P_THIS->GetCount();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementProgress::execGetBitfield)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetBitfield();
		P_NATIVE_END;
	}
	void UPico_AchievementProgress::StaticRegisterNativesUPico_AchievementProgress()
	{
		UClass* Class = UPico_AchievementProgress::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetBitfield", &UPico_AchievementProgress::execGetBitfield },
			{ "GetCount", &UPico_AchievementProgress::execGetCount },
			{ "GetExtraData", &UPico_AchievementProgress::execGetExtraData },
			{ "GetExtraDataString", &UPico_AchievementProgress::execGetExtraDataString },
			{ "GetID", &UPico_AchievementProgress::execGetID },
			{ "GetIsUnlocked", &UPico_AchievementProgress::execGetIsUnlocked },
			{ "GetName", &UPico_AchievementProgress::execGetName },
			{ "GetUnlockDateTime", &UPico_AchievementProgress::execGetUnlockDateTime },
			{ "GetUnlockTime", &UPico_AchievementProgress::execGetUnlockTime },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_AchievementProgress_GetBitfield_Statics
	{
		struct Pico_AchievementProgress_eventGetBitfield_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AchievementProgress_GetBitfield_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementProgress_eventGetBitfield_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementProgress_GetBitfield_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementProgress_GetBitfield_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementProgress_GetBitfield_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Progress" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The progress of a bitfield achievement. `1` represents a completed bit. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The progress of a bitfield achievement. `1` represents a completed bit." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementProgress_GetBitfield_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementProgress, nullptr, "GetBitfield", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementProgress_GetBitfield_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetBitfield_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementProgress_GetBitfield_Statics::Pico_AchievementProgress_eventGetBitfield_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetBitfield_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementProgress_GetBitfield_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetBitfield_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementProgress_GetBitfield_Statics::Pico_AchievementProgress_eventGetBitfield_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementProgress_GetBitfield()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementProgress_GetBitfield_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementProgress_GetCount_Statics
	{
		struct Pico_AchievementProgress_eventGetCount_Parms
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
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UPico_AchievementProgress_GetCount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementProgress_eventGetCount_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementProgress_GetCount_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementProgress_GetCount_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementProgress_GetCount_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Progress" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The progress of a count achievement. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The progress of a count achievement." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementProgress_GetCount_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementProgress, nullptr, "GetCount", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementProgress_GetCount_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetCount_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementProgress_GetCount_Statics::Pico_AchievementProgress_eventGetCount_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementProgress_GetCount_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetCount_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementProgress_GetCount_Statics::Pico_AchievementProgress_eventGetCount_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementProgress_GetCount()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementProgress_GetCount_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementProgress_GetExtraData_Statics
	{
		struct Pico_AchievementProgress_eventGetExtraData_Parms
		{
			TArray<uint8> ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPico_AchievementProgress_GetExtraData_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPico_AchievementProgress_GetExtraData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementProgress_eventGetExtraData_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementProgress_GetExtraData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementProgress_GetExtraData_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementProgress_GetExtraData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementProgress_GetExtraData_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Progress" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief  Additional info, no more than 2KB.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief  Additional info, no more than 2KB." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementProgress_GetExtraData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementProgress, nullptr, "GetExtraData", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementProgress_GetExtraData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetExtraData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementProgress_GetExtraData_Statics::Pico_AchievementProgress_eventGetExtraData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetExtraData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementProgress_GetExtraData_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetExtraData_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementProgress_GetExtraData_Statics::Pico_AchievementProgress_eventGetExtraData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementProgress_GetExtraData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementProgress_GetExtraData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementProgress_GetExtraDataString_Statics
	{
		struct Pico_AchievementProgress_eventGetExtraDataString_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AchievementProgress_GetExtraDataString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementProgress_eventGetExtraDataString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementProgress_GetExtraDataString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementProgress_GetExtraDataString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementProgress_GetExtraDataString_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Progress" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief  Additional info(as string), no more than 2KB.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief  Additional info(as string), no more than 2KB." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementProgress_GetExtraDataString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementProgress, nullptr, "GetExtraDataString", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementProgress_GetExtraDataString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetExtraDataString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementProgress_GetExtraDataString_Statics::Pico_AchievementProgress_eventGetExtraDataString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetExtraDataString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementProgress_GetExtraDataString_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetExtraDataString_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementProgress_GetExtraDataString_Statics::Pico_AchievementProgress_eventGetExtraDataString_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementProgress_GetExtraDataString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementProgress_GetExtraDataString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementProgress_GetID_Statics
	{
		struct Pico_AchievementProgress_eventGetID_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AchievementProgress_GetID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementProgress_eventGetID_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementProgress_GetID_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementProgress_GetID_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementProgress_GetID_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Progress" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Achievement ID. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Achievement ID." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementProgress_GetID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementProgress, nullptr, "GetID", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementProgress_GetID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetID_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementProgress_GetID_Statics::Pico_AchievementProgress_eventGetID_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementProgress_GetID_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetID_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementProgress_GetID_Statics::Pico_AchievementProgress_eventGetID_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementProgress_GetID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementProgress_GetID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementProgress_GetIsUnlocked_Statics
	{
		struct Pico_AchievementProgress_eventGetIsUnlocked_Parms
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
	void Z_Construct_UFunction_UPico_AchievementProgress_GetIsUnlocked_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_AchievementProgress_eventGetIsUnlocked_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_AchievementProgress_GetIsUnlocked_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_AchievementProgress_eventGetIsUnlocked_Parms), &Z_Construct_UFunction_UPico_AchievementProgress_GetIsUnlocked_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementProgress_GetIsUnlocked_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementProgress_GetIsUnlocked_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementProgress_GetIsUnlocked_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Progress" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Whether the achievement is unlocked */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Whether the achievement is unlocked" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementProgress_GetIsUnlocked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementProgress, nullptr, "GetIsUnlocked", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementProgress_GetIsUnlocked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetIsUnlocked_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementProgress_GetIsUnlocked_Statics::Pico_AchievementProgress_eventGetIsUnlocked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetIsUnlocked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementProgress_GetIsUnlocked_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetIsUnlocked_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementProgress_GetIsUnlocked_Statics::Pico_AchievementProgress_eventGetIsUnlocked_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementProgress_GetIsUnlocked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementProgress_GetIsUnlocked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementProgress_GetName_Statics
	{
		struct Pico_AchievementProgress_eventGetName_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AchievementProgress_GetName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementProgress_eventGetName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementProgress_GetName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementProgress_GetName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementProgress_GetName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Progress" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Achievement name. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Achievement name." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementProgress_GetName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementProgress, nullptr, "GetName", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementProgress_GetName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementProgress_GetName_Statics::Pico_AchievementProgress_eventGetName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementProgress_GetName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementProgress_GetName_Statics::Pico_AchievementProgress_eventGetName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementProgress_GetName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementProgress_GetName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockDateTime_Statics
	{
		struct Pico_AchievementProgress_eventGetUnlockDateTime_Parms
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
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockDateTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementProgress_eventGetUnlockDateTime_Parms, ReturnValue), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockDateTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockDateTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockDateTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Progress" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The time when the achievement is unlocked. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The time when the achievement is unlocked." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockDateTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementProgress, nullptr, "GetUnlockDateTime", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockDateTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockDateTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockDateTime_Statics::Pico_AchievementProgress_eventGetUnlockDateTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockDateTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockDateTime_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockDateTime_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockDateTime_Statics::Pico_AchievementProgress_eventGetUnlockDateTime_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockDateTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockDateTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockTime_Statics
	{
		struct Pico_AchievementProgress_eventGetUnlockTime_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementProgress_eventGetUnlockTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Progress" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The time when the achievement is unlocked (as string). */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The time when the achievement is unlocked (as string)." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementProgress, nullptr, "GetUnlockTime", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockTime_Statics::Pico_AchievementProgress_eventGetUnlockTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockTime_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockTime_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockTime_Statics::Pico_AchievementProgress_eventGetUnlockTime_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_AchievementProgress);
	UClass* Z_Construct_UClass_UPico_AchievementProgress_NoRegister()
	{
		return UPico_AchievementProgress::StaticClass();
	}
	struct Z_Construct_UClass_UPico_AchievementProgress_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_AchievementProgress_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AchievementProgress_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_AchievementProgress_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_AchievementProgress_GetBitfield, "GetBitfield" }, // 4029148284
		{ &Z_Construct_UFunction_UPico_AchievementProgress_GetCount, "GetCount" }, // 1404612532
		{ &Z_Construct_UFunction_UPico_AchievementProgress_GetExtraData, "GetExtraData" }, // 2373605811
		{ &Z_Construct_UFunction_UPico_AchievementProgress_GetExtraDataString, "GetExtraDataString" }, // 2893274171
		{ &Z_Construct_UFunction_UPico_AchievementProgress_GetID, "GetID" }, // 60032590
		{ &Z_Construct_UFunction_UPico_AchievementProgress_GetIsUnlocked, "GetIsUnlocked" }, // 2171169955
		{ &Z_Construct_UFunction_UPico_AchievementProgress_GetName, "GetName" }, // 3643404237
		{ &Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockDateTime, "GetUnlockDateTime" }, // 3002925940
		{ &Z_Construct_UFunction_UPico_AchievementProgress_GetUnlockTime, "GetUnlockTime" }, // 89106949
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AchievementProgress_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_AchievementProgress_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_AchievementProgress class.\n" },
#endif
		{ "IncludePath", "Pico_Achievements.h" },
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_AchievementProgress class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_AchievementProgress_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_AchievementProgress>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_AchievementProgress_Statics::ClassParams = {
		&UPico_AchievementProgress::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AchievementProgress_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_AchievementProgress_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPico_AchievementProgress()
	{
		if (!Z_Registration_Info_UClass_UPico_AchievementProgress.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_AchievementProgress.OuterSingleton, Z_Construct_UClass_UPico_AchievementProgress_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_AchievementProgress.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_AchievementProgress>()
	{
		return UPico_AchievementProgress::StaticClass();
	}
	UPico_AchievementProgress::UPico_AchievementProgress(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_AchievementProgress);
	UPico_AchievementProgress::~UPico_AchievementProgress() {}
	DEFINE_FUNCTION(UPico_AchievementDefinition::execGetUnlockedImageURL)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetUnlockedImageURL();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementDefinition::execGetLockedImageURL)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetLockedImageURL();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementDefinition::execGetWritePolicy)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EAchievementWritePolicy*)Z_Param__Result=P_THIS->GetWritePolicy();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementDefinition::execGetUnlockedDescription)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetUnlockedDescription();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementDefinition::execGetID)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetID();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementDefinition::execGetIsSecret)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetIsSecret();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementDefinition::execGetIsArchived)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetIsArchived();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementDefinition::execGetTitle)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetTitle();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementDefinition::execGetDescription)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetDescription();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementDefinition::execGetType)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EAchievementType*)Z_Param__Result=P_THIS->GetType();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementDefinition::execGetTarget)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int64*)Z_Param__Result=P_THIS->GetTarget();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementDefinition::execGetBitfieldLength)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetBitfieldLength();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementDefinition::execGetName)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetName();
		P_NATIVE_END;
	}
	void UPico_AchievementDefinition::StaticRegisterNativesUPico_AchievementDefinition()
	{
		UClass* Class = UPico_AchievementDefinition::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetBitfieldLength", &UPico_AchievementDefinition::execGetBitfieldLength },
			{ "GetDescription", &UPico_AchievementDefinition::execGetDescription },
			{ "GetID", &UPico_AchievementDefinition::execGetID },
			{ "GetIsArchived", &UPico_AchievementDefinition::execGetIsArchived },
			{ "GetIsSecret", &UPico_AchievementDefinition::execGetIsSecret },
			{ "GetLockedImageURL", &UPico_AchievementDefinition::execGetLockedImageURL },
			{ "GetName", &UPico_AchievementDefinition::execGetName },
			{ "GetTarget", &UPico_AchievementDefinition::execGetTarget },
			{ "GetTitle", &UPico_AchievementDefinition::execGetTitle },
			{ "GetType", &UPico_AchievementDefinition::execGetType },
			{ "GetUnlockedDescription", &UPico_AchievementDefinition::execGetUnlockedDescription },
			{ "GetUnlockedImageURL", &UPico_AchievementDefinition::execGetUnlockedImageURL },
			{ "GetWritePolicy", &UPico_AchievementDefinition::execGetWritePolicy },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_AchievementDefinition_GetBitfieldLength_Statics
	{
		struct Pico_AchievementDefinition_eventGetBitfieldLength_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AchievementDefinition_GetBitfieldLength_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementDefinition_eventGetBitfieldLength_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementDefinition_GetBitfieldLength_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementDefinition_GetBitfieldLength_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementDefinition_GetBitfieldLength_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Definition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The requirement that users should meet for unlocking a bitfield achievement. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The requirement that users should meet for unlocking a bitfield achievement." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementDefinition_GetBitfieldLength_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementDefinition, nullptr, "GetBitfieldLength", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementDefinition_GetBitfieldLength_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetBitfieldLength_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetBitfieldLength_Statics::Pico_AchievementDefinition_eventGetBitfieldLength_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetBitfieldLength_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementDefinition_GetBitfieldLength_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetBitfieldLength_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetBitfieldLength_Statics::Pico_AchievementDefinition_eventGetBitfieldLength_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementDefinition_GetBitfieldLength()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementDefinition_GetBitfieldLength_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementDefinition_GetDescription_Statics
	{
		struct Pico_AchievementDefinition_eventGetDescription_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AchievementDefinition_GetDescription_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementDefinition_eventGetDescription_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementDefinition_GetDescription_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementDefinition_GetDescription_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementDefinition_GetDescription_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Definition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The description of the achievement. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The description of the achievement." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementDefinition_GetDescription_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementDefinition, nullptr, "GetDescription", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementDefinition_GetDescription_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetDescription_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetDescription_Statics::Pico_AchievementDefinition_eventGetDescription_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetDescription_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementDefinition_GetDescription_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetDescription_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetDescription_Statics::Pico_AchievementDefinition_eventGetDescription_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementDefinition_GetDescription()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementDefinition_GetDescription_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementDefinition_GetID_Statics
	{
		struct Pico_AchievementDefinition_eventGetID_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AchievementDefinition_GetID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementDefinition_eventGetID_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementDefinition_GetID_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementDefinition_GetID_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementDefinition_GetID_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Definition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The ID of the achievement. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The ID of the achievement." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementDefinition_GetID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementDefinition, nullptr, "GetID", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementDefinition_GetID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetID_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetID_Statics::Pico_AchievementDefinition_eventGetID_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementDefinition_GetID_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetID_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetID_Statics::Pico_AchievementDefinition_eventGetID_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementDefinition_GetID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementDefinition_GetID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementDefinition_GetIsArchived_Statics
	{
		struct Pico_AchievementDefinition_eventGetIsArchived_Parms
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
	void Z_Construct_UFunction_UPico_AchievementDefinition_GetIsArchived_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_AchievementDefinition_eventGetIsArchived_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_AchievementDefinition_GetIsArchived_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_AchievementDefinition_eventGetIsArchived_Parms), &Z_Construct_UFunction_UPico_AchievementDefinition_GetIsArchived_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementDefinition_GetIsArchived_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementDefinition_GetIsArchived_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementDefinition_GetIsArchived_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Definition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Whether the achievement is archived. Archived achievements are invisible to users. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Whether the achievement is archived. Archived achievements are invisible to users." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementDefinition_GetIsArchived_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementDefinition, nullptr, "GetIsArchived", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementDefinition_GetIsArchived_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetIsArchived_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetIsArchived_Statics::Pico_AchievementDefinition_eventGetIsArchived_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetIsArchived_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementDefinition_GetIsArchived_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetIsArchived_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetIsArchived_Statics::Pico_AchievementDefinition_eventGetIsArchived_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementDefinition_GetIsArchived()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementDefinition_GetIsArchived_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementDefinition_GetIsSecret_Statics
	{
		struct Pico_AchievementDefinition_eventGetIsSecret_Parms
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
	void Z_Construct_UFunction_UPico_AchievementDefinition_GetIsSecret_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_AchievementDefinition_eventGetIsSecret_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_AchievementDefinition_GetIsSecret_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_AchievementDefinition_eventGetIsSecret_Parms), &Z_Construct_UFunction_UPico_AchievementDefinition_GetIsSecret_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementDefinition_GetIsSecret_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementDefinition_GetIsSecret_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementDefinition_GetIsSecret_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Definition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Whether the achievement is a hidden achievement. If so, it can be visible after being unlocked only. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Whether the achievement is a hidden achievement. If so, it can be visible after being unlocked only." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementDefinition_GetIsSecret_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementDefinition, nullptr, "GetIsSecret", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementDefinition_GetIsSecret_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetIsSecret_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetIsSecret_Statics::Pico_AchievementDefinition_eventGetIsSecret_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetIsSecret_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementDefinition_GetIsSecret_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetIsSecret_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetIsSecret_Statics::Pico_AchievementDefinition_eventGetIsSecret_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementDefinition_GetIsSecret()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementDefinition_GetIsSecret_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementDefinition_GetLockedImageURL_Statics
	{
		struct Pico_AchievementDefinition_eventGetLockedImageURL_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AchievementDefinition_GetLockedImageURL_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementDefinition_eventGetLockedImageURL_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementDefinition_GetLockedImageURL_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementDefinition_GetLockedImageURL_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementDefinition_GetLockedImageURL_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Definition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The URL of the image displayed when the achievement is still locked. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The URL of the image displayed when the achievement is still locked." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementDefinition_GetLockedImageURL_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementDefinition, nullptr, "GetLockedImageURL", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementDefinition_GetLockedImageURL_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetLockedImageURL_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetLockedImageURL_Statics::Pico_AchievementDefinition_eventGetLockedImageURL_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetLockedImageURL_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementDefinition_GetLockedImageURL_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetLockedImageURL_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetLockedImageURL_Statics::Pico_AchievementDefinition_eventGetLockedImageURL_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementDefinition_GetLockedImageURL()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementDefinition_GetLockedImageURL_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementDefinition_GetName_Statics
	{
		struct Pico_AchievementDefinition_eventGetName_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AchievementDefinition_GetName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementDefinition_eventGetName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementDefinition_GetName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementDefinition_GetName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementDefinition_GetName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Definition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The API name of the achievement. An API name serves as the unique identifier of an achievement. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The API name of the achievement. An API name serves as the unique identifier of an achievement." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementDefinition_GetName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementDefinition, nullptr, "GetName", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementDefinition_GetName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetName_Statics::Pico_AchievementDefinition_eventGetName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementDefinition_GetName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetName_Statics::Pico_AchievementDefinition_eventGetName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementDefinition_GetName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementDefinition_GetName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementDefinition_GetTarget_Statics
	{
		struct Pico_AchievementDefinition_eventGetTarget_Parms
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
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UPico_AchievementDefinition_GetTarget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementDefinition_eventGetTarget_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementDefinition_GetTarget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementDefinition_GetTarget_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementDefinition_GetTarget_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Definition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The requirement that users should meet for unlocking a count achievement. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The requirement that users should meet for unlocking a count achievement." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementDefinition_GetTarget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementDefinition, nullptr, "GetTarget", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementDefinition_GetTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetTarget_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetTarget_Statics::Pico_AchievementDefinition_eventGetTarget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementDefinition_GetTarget_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetTarget_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetTarget_Statics::Pico_AchievementDefinition_eventGetTarget_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementDefinition_GetTarget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementDefinition_GetTarget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementDefinition_GetTitle_Statics
	{
		struct Pico_AchievementDefinition_eventGetTitle_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AchievementDefinition_GetTitle_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementDefinition_eventGetTitle_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementDefinition_GetTitle_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementDefinition_GetTitle_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementDefinition_GetTitle_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Definition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The display name of the achievement. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The display name of the achievement." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementDefinition_GetTitle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementDefinition, nullptr, "GetTitle", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementDefinition_GetTitle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetTitle_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetTitle_Statics::Pico_AchievementDefinition_eventGetTitle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetTitle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementDefinition_GetTitle_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetTitle_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetTitle_Statics::Pico_AchievementDefinition_eventGetTitle_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementDefinition_GetTitle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementDefinition_GetTitle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementDefinition_GetType_Statics
	{
		struct Pico_AchievementDefinition_eventGetType_Parms
		{
			EAchievementType ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPico_AchievementDefinition_GetType_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPico_AchievementDefinition_GetType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementDefinition_eventGetType_Parms, ReturnValue), Z_Construct_UEnum_OnlineSubsystemPico_EAchievementType, METADATA_PARAMS(0, nullptr) }; // 117870442
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementDefinition_GetType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementDefinition_GetType_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementDefinition_GetType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementDefinition_GetType_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Definition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The type of the achievement. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The type of the achievement." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementDefinition_GetType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementDefinition, nullptr, "GetType", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementDefinition_GetType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetType_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetType_Statics::Pico_AchievementDefinition_eventGetType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementDefinition_GetType_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetType_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetType_Statics::Pico_AchievementDefinition_eventGetType_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementDefinition_GetType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementDefinition_GetType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedDescription_Statics
	{
		struct Pico_AchievementDefinition_eventGetUnlockedDescription_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedDescription_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementDefinition_eventGetUnlockedDescription_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedDescription_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedDescription_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedDescription_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Definition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The description displayed to users after they unlock the achievement. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The description displayed to users after they unlock the achievement." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedDescription_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementDefinition, nullptr, "GetUnlockedDescription", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedDescription_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedDescription_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedDescription_Statics::Pico_AchievementDefinition_eventGetUnlockedDescription_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedDescription_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedDescription_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedDescription_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedDescription_Statics::Pico_AchievementDefinition_eventGetUnlockedDescription_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedDescription()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedDescription_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedImageURL_Statics
	{
		struct Pico_AchievementDefinition_eventGetUnlockedImageURL_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedImageURL_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementDefinition_eventGetUnlockedImageURL_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedImageURL_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedImageURL_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedImageURL_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Definition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The URL of the image displayed when the achievement is unlocked. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The URL of the image displayed when the achievement is unlocked." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedImageURL_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementDefinition, nullptr, "GetUnlockedImageURL", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedImageURL_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedImageURL_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedImageURL_Statics::Pico_AchievementDefinition_eventGetUnlockedImageURL_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedImageURL_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedImageURL_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedImageURL_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedImageURL_Statics::Pico_AchievementDefinition_eventGetUnlockedImageURL_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedImageURL()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedImageURL_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementDefinition_GetWritePolicy_Statics
	{
		struct Pico_AchievementDefinition_eventGetWritePolicy_Parms
		{
			EAchievementWritePolicy ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPico_AchievementDefinition_GetWritePolicy_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPico_AchievementDefinition_GetWritePolicy_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementDefinition_eventGetWritePolicy_Parms, ReturnValue), Z_Construct_UEnum_OnlineSubsystemPico_EAchievementWritePolicy, METADATA_PARAMS(0, nullptr) }; // 4037328139
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementDefinition_GetWritePolicy_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementDefinition_GetWritePolicy_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementDefinition_GetWritePolicy_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementDefinition_GetWritePolicy_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Definition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The data-writing policy of the achievement, which indicates whether the client or server are allowed to update the achievement's progress. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The data-writing policy of the achievement, which indicates whether the client or server are allowed to update the achievement's progress." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementDefinition_GetWritePolicy_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementDefinition, nullptr, "GetWritePolicy", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementDefinition_GetWritePolicy_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetWritePolicy_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetWritePolicy_Statics::Pico_AchievementDefinition_eventGetWritePolicy_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetWritePolicy_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementDefinition_GetWritePolicy_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinition_GetWritePolicy_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementDefinition_GetWritePolicy_Statics::Pico_AchievementDefinition_eventGetWritePolicy_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementDefinition_GetWritePolicy()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementDefinition_GetWritePolicy_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_AchievementDefinition);
	UClass* Z_Construct_UClass_UPico_AchievementDefinition_NoRegister()
	{
		return UPico_AchievementDefinition::StaticClass();
	}
	struct Z_Construct_UClass_UPico_AchievementDefinition_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_AchievementDefinition_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AchievementDefinition_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_AchievementDefinition_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_AchievementDefinition_GetBitfieldLength, "GetBitfieldLength" }, // 1513934017
		{ &Z_Construct_UFunction_UPico_AchievementDefinition_GetDescription, "GetDescription" }, // 1687291945
		{ &Z_Construct_UFunction_UPico_AchievementDefinition_GetID, "GetID" }, // 1672861279
		{ &Z_Construct_UFunction_UPico_AchievementDefinition_GetIsArchived, "GetIsArchived" }, // 2015584389
		{ &Z_Construct_UFunction_UPico_AchievementDefinition_GetIsSecret, "GetIsSecret" }, // 3085169178
		{ &Z_Construct_UFunction_UPico_AchievementDefinition_GetLockedImageURL, "GetLockedImageURL" }, // 1169667215
		{ &Z_Construct_UFunction_UPico_AchievementDefinition_GetName, "GetName" }, // 2948187860
		{ &Z_Construct_UFunction_UPico_AchievementDefinition_GetTarget, "GetTarget" }, // 4034844403
		{ &Z_Construct_UFunction_UPico_AchievementDefinition_GetTitle, "GetTitle" }, // 499364325
		{ &Z_Construct_UFunction_UPico_AchievementDefinition_GetType, "GetType" }, // 791232237
		{ &Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedDescription, "GetUnlockedDescription" }, // 4094177234
		{ &Z_Construct_UFunction_UPico_AchievementDefinition_GetUnlockedImageURL, "GetUnlockedImageURL" }, // 1895844952
		{ &Z_Construct_UFunction_UPico_AchievementDefinition_GetWritePolicy, "GetWritePolicy" }, // 2374481834
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AchievementDefinition_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_AchievementDefinition_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_AchievementDefinition class.\n" },
#endif
		{ "IncludePath", "Pico_Achievements.h" },
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_AchievementDefinition class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_AchievementDefinition_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_AchievementDefinition>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_AchievementDefinition_Statics::ClassParams = {
		&UPico_AchievementDefinition::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AchievementDefinition_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_AchievementDefinition_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPico_AchievementDefinition()
	{
		if (!Z_Registration_Info_UClass_UPico_AchievementDefinition.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_AchievementDefinition.OuterSingleton, Z_Construct_UClass_UPico_AchievementDefinition_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_AchievementDefinition.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_AchievementDefinition>()
	{
		return UPico_AchievementDefinition::StaticClass();
	}
	UPico_AchievementDefinition::UPico_AchievementDefinition(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_AchievementDefinition);
	UPico_AchievementDefinition::~UPico_AchievementDefinition() {}
	DEFINE_FUNCTION(UPico_AchievementProgressArray::execHasNextPage)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->HasNextPage();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementProgressArray::execGetTotalSize)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetTotalSize();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementProgressArray::execGetSize)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetSize();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementProgressArray::execGetElement)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPico_AchievementProgress**)Z_Param__Result=P_THIS->GetElement(Z_Param_Index);
		P_NATIVE_END;
	}
	void UPico_AchievementProgressArray::StaticRegisterNativesUPico_AchievementProgressArray()
	{
		UClass* Class = UPico_AchievementProgressArray::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetElement", &UPico_AchievementProgressArray::execGetElement },
			{ "GetSize", &UPico_AchievementProgressArray::execGetSize },
			{ "GetTotalSize", &UPico_AchievementProgressArray::execGetTotalSize },
			{ "HasNextPage", &UPico_AchievementProgressArray::execHasNextPage },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_AchievementProgressArray_GetElement_Statics
	{
		struct Pico_AchievementProgressArray_eventGetElement_Parms
		{
			int32 Index;
			UPico_AchievementProgress* ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_AchievementProgressArray_GetElement_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementProgressArray_eventGetElement_Parms, Index), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPico_AchievementProgressArray_GetElement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementProgressArray_eventGetElement_Parms, ReturnValue), Z_Construct_UClass_UPico_AchievementProgress_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementProgressArray_GetElement_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementProgressArray_GetElement_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementProgressArray_GetElement_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementProgressArray_GetElement_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Progress Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get AchievementProgressArray element form Index.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get AchievementProgressArray element form Index." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementProgressArray_GetElement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementProgressArray, nullptr, "GetElement", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementProgressArray_GetElement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgressArray_GetElement_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementProgressArray_GetElement_Statics::Pico_AchievementProgressArray_eventGetElement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgressArray_GetElement_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementProgressArray_GetElement_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgressArray_GetElement_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementProgressArray_GetElement_Statics::Pico_AchievementProgressArray_eventGetElement_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementProgressArray_GetElement()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementProgressArray_GetElement_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementProgressArray_GetSize_Statics
	{
		struct Pico_AchievementProgressArray_eventGetSize_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_AchievementProgressArray_GetSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementProgressArray_eventGetSize_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementProgressArray_GetSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementProgressArray_GetSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementProgressArray_GetSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Progress Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get the size of AchievementProgressArray .*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get the size of AchievementProgressArray ." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementProgressArray_GetSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementProgressArray, nullptr, "GetSize", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementProgressArray_GetSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgressArray_GetSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementProgressArray_GetSize_Statics::Pico_AchievementProgressArray_eventGetSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgressArray_GetSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementProgressArray_GetSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgressArray_GetSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementProgressArray_GetSize_Statics::Pico_AchievementProgressArray_eventGetSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementProgressArray_GetSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementProgressArray_GetSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementProgressArray_GetTotalSize_Statics
	{
		struct Pico_AchievementProgressArray_eventGetTotalSize_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_AchievementProgressArray_GetTotalSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementProgressArray_eventGetTotalSize_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementProgressArray_GetTotalSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementProgressArray_GetTotalSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementProgressArray_GetTotalSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Progress Array" },
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementProgressArray_GetTotalSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementProgressArray, nullptr, "GetTotalSize", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementProgressArray_GetTotalSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgressArray_GetTotalSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementProgressArray_GetTotalSize_Statics::Pico_AchievementProgressArray_eventGetTotalSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgressArray_GetTotalSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementProgressArray_GetTotalSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgressArray_GetTotalSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementProgressArray_GetTotalSize_Statics::Pico_AchievementProgressArray_eventGetTotalSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementProgressArray_GetTotalSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementProgressArray_GetTotalSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementProgressArray_HasNextPage_Statics
	{
		struct Pico_AchievementProgressArray_eventHasNextPage_Parms
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
	void Z_Construct_UFunction_UPico_AchievementProgressArray_HasNextPage_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_AchievementProgressArray_eventHasNextPage_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_AchievementProgressArray_HasNextPage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_AchievementProgressArray_eventHasNextPage_Parms), &Z_Construct_UFunction_UPico_AchievementProgressArray_HasNextPage_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementProgressArray_HasNextPage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementProgressArray_HasNextPage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementProgressArray_HasNextPage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Progress Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get whether the list has the next page.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get whether the list has the next page." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementProgressArray_HasNextPage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementProgressArray, nullptr, "HasNextPage", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementProgressArray_HasNextPage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgressArray_HasNextPage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementProgressArray_HasNextPage_Statics::Pico_AchievementProgressArray_eventHasNextPage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgressArray_HasNextPage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementProgressArray_HasNextPage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementProgressArray_HasNextPage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementProgressArray_HasNextPage_Statics::Pico_AchievementProgressArray_eventHasNextPage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementProgressArray_HasNextPage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementProgressArray_HasNextPage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_AchievementProgressArray);
	UClass* Z_Construct_UClass_UPico_AchievementProgressArray_NoRegister()
	{
		return UPico_AchievementProgressArray::StaticClass();
	}
	struct Z_Construct_UClass_UPico_AchievementProgressArray_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AchievementProgressArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AchievementProgressArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_AchievementProgressArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_AchievementProgressArray_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AchievementProgressArray_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_AchievementProgressArray_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_AchievementProgressArray_GetElement, "GetElement" }, // 1172317401
		{ &Z_Construct_UFunction_UPico_AchievementProgressArray_GetSize, "GetSize" }, // 1832867046
		{ &Z_Construct_UFunction_UPico_AchievementProgressArray_GetTotalSize, "GetTotalSize" }, // 3663379007
		{ &Z_Construct_UFunction_UPico_AchievementProgressArray_HasNextPage, "HasNextPage" }, // 2579622957
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AchievementProgressArray_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_AchievementProgressArray_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_AchievementProgressArray class.\n" },
#endif
		{ "IncludePath", "Pico_Achievements.h" },
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_AchievementProgressArray class." },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPico_AchievementProgressArray_Statics::NewProp_AchievementProgressArray_Inner = { "AchievementProgressArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UPico_AchievementProgress_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_AchievementProgressArray_Statics::NewProp_AchievementProgressArray_MetaData[] = {
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPico_AchievementProgressArray_Statics::NewProp_AchievementProgressArray = { "AchievementProgressArray", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPico_AchievementProgressArray, AchievementProgressArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AchievementProgressArray_Statics::NewProp_AchievementProgressArray_MetaData), Z_Construct_UClass_UPico_AchievementProgressArray_Statics::NewProp_AchievementProgressArray_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPico_AchievementProgressArray_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_AchievementProgressArray_Statics::NewProp_AchievementProgressArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_AchievementProgressArray_Statics::NewProp_AchievementProgressArray,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_AchievementProgressArray_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_AchievementProgressArray>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_AchievementProgressArray_Statics::ClassParams = {
		&UPico_AchievementProgressArray::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPico_AchievementProgressArray_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AchievementProgressArray_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AchievementProgressArray_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_AchievementProgressArray_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AchievementProgressArray_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPico_AchievementProgressArray()
	{
		if (!Z_Registration_Info_UClass_UPico_AchievementProgressArray.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_AchievementProgressArray.OuterSingleton, Z_Construct_UClass_UPico_AchievementProgressArray_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_AchievementProgressArray.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_AchievementProgressArray>()
	{
		return UPico_AchievementProgressArray::StaticClass();
	}
	UPico_AchievementProgressArray::UPico_AchievementProgressArray(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_AchievementProgressArray);
	UPico_AchievementProgressArray::~UPico_AchievementProgressArray() {}
	DEFINE_FUNCTION(UPico_AchievementDefinitionArray::execHasNextPage)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->HasNextPage();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementDefinitionArray::execGetTotalSize)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetTotalSize();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementDefinitionArray::execGetSize)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetSize();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AchievementDefinitionArray::execGetElement)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPico_AchievementDefinition**)Z_Param__Result=P_THIS->GetElement(Z_Param_Index);
		P_NATIVE_END;
	}
	void UPico_AchievementDefinitionArray::StaticRegisterNativesUPico_AchievementDefinitionArray()
	{
		UClass* Class = UPico_AchievementDefinitionArray::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetElement", &UPico_AchievementDefinitionArray::execGetElement },
			{ "GetSize", &UPico_AchievementDefinitionArray::execGetSize },
			{ "GetTotalSize", &UPico_AchievementDefinitionArray::execGetTotalSize },
			{ "HasNextPage", &UPico_AchievementDefinitionArray::execHasNextPage },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetElement_Statics
	{
		struct Pico_AchievementDefinitionArray_eventGetElement_Parms
		{
			int32 Index;
			UPico_AchievementDefinition* ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetElement_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementDefinitionArray_eventGetElement_Parms, Index), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetElement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementDefinitionArray_eventGetElement_Parms, ReturnValue), Z_Construct_UClass_UPico_AchievementDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetElement_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetElement_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetElement_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetElement_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Definition Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get AchievementDefinitionArray element form Index.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get AchievementDefinitionArray element form Index." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetElement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementDefinitionArray, nullptr, "GetElement", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetElement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetElement_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetElement_Statics::Pico_AchievementDefinitionArray_eventGetElement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetElement_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetElement_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetElement_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetElement_Statics::Pico_AchievementDefinitionArray_eventGetElement_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetElement()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetElement_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetSize_Statics
	{
		struct Pico_AchievementDefinitionArray_eventGetSize_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementDefinitionArray_eventGetSize_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Definition Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get the size of AchievementDefinitionArray .*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get the size of AchievementDefinitionArray ." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementDefinitionArray, nullptr, "GetSize", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetSize_Statics::Pico_AchievementDefinitionArray_eventGetSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetSize_Statics::Pico_AchievementDefinitionArray_eventGetSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetTotalSize_Statics
	{
		struct Pico_AchievementDefinitionArray_eventGetTotalSize_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetTotalSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AchievementDefinitionArray_eventGetTotalSize_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetTotalSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetTotalSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetTotalSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Definition Array" },
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetTotalSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementDefinitionArray, nullptr, "GetTotalSize", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetTotalSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetTotalSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetTotalSize_Statics::Pico_AchievementDefinitionArray_eventGetTotalSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetTotalSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetTotalSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetTotalSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetTotalSize_Statics::Pico_AchievementDefinitionArray_eventGetTotalSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetTotalSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetTotalSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AchievementDefinitionArray_HasNextPage_Statics
	{
		struct Pico_AchievementDefinitionArray_eventHasNextPage_Parms
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
	void Z_Construct_UFunction_UPico_AchievementDefinitionArray_HasNextPage_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_AchievementDefinitionArray_eventHasNextPage_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_AchievementDefinitionArray_HasNextPage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_AchievementDefinitionArray_eventHasNextPage_Parms), &Z_Construct_UFunction_UPico_AchievementDefinitionArray_HasNextPage_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AchievementDefinitionArray_HasNextPage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AchievementDefinitionArray_HasNextPage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AchievementDefinitionArray_HasNextPage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Achievements|Achievement Definition Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get whether the list has the next page.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get whether the list has the next page." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AchievementDefinitionArray_HasNextPage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AchievementDefinitionArray, nullptr, "HasNextPage", nullptr, nullptr, Z_Construct_UFunction_UPico_AchievementDefinitionArray_HasNextPage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinitionArray_HasNextPage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AchievementDefinitionArray_HasNextPage_Statics::Pico_AchievementDefinitionArray_eventHasNextPage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinitionArray_HasNextPage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AchievementDefinitionArray_HasNextPage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AchievementDefinitionArray_HasNextPage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AchievementDefinitionArray_HasNextPage_Statics::Pico_AchievementDefinitionArray_eventHasNextPage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AchievementDefinitionArray_HasNextPage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AchievementDefinitionArray_HasNextPage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_AchievementDefinitionArray);
	UClass* Z_Construct_UClass_UPico_AchievementDefinitionArray_NoRegister()
	{
		return UPico_AchievementDefinitionArray::StaticClass();
	}
	struct Z_Construct_UClass_UPico_AchievementDefinitionArray_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AchievementDefinitionArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AchievementDefinitionArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_AchievementDefinitionArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_AchievementDefinitionArray_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AchievementDefinitionArray_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_AchievementDefinitionArray_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetElement, "GetElement" }, // 2508177015
		{ &Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetSize, "GetSize" }, // 3451899613
		{ &Z_Construct_UFunction_UPico_AchievementDefinitionArray_GetTotalSize, "GetTotalSize" }, // 3951212205
		{ &Z_Construct_UFunction_UPico_AchievementDefinitionArray_HasNextPage, "HasNextPage" }, // 2303202513
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AchievementDefinitionArray_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_AchievementDefinitionArray_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_AchievementDefinitionArray class.\n" },
#endif
		{ "IncludePath", "Pico_Achievements.h" },
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_AchievementDefinitionArray class." },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPico_AchievementDefinitionArray_Statics::NewProp_AchievementDefinitionArray_Inner = { "AchievementDefinitionArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UPico_AchievementDefinition_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_AchievementDefinitionArray_Statics::NewProp_AchievementDefinitionArray_MetaData[] = {
		{ "ModuleRelativePath", "Public/Pico_Achievements.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPico_AchievementDefinitionArray_Statics::NewProp_AchievementDefinitionArray = { "AchievementDefinitionArray", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPico_AchievementDefinitionArray, AchievementDefinitionArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AchievementDefinitionArray_Statics::NewProp_AchievementDefinitionArray_MetaData), Z_Construct_UClass_UPico_AchievementDefinitionArray_Statics::NewProp_AchievementDefinitionArray_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPico_AchievementDefinitionArray_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_AchievementDefinitionArray_Statics::NewProp_AchievementDefinitionArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_AchievementDefinitionArray_Statics::NewProp_AchievementDefinitionArray,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_AchievementDefinitionArray_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_AchievementDefinitionArray>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_AchievementDefinitionArray_Statics::ClassParams = {
		&UPico_AchievementDefinitionArray::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPico_AchievementDefinitionArray_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AchievementDefinitionArray_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AchievementDefinitionArray_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_AchievementDefinitionArray_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AchievementDefinitionArray_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPico_AchievementDefinitionArray()
	{
		if (!Z_Registration_Info_UClass_UPico_AchievementDefinitionArray.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_AchievementDefinitionArray.OuterSingleton, Z_Construct_UClass_UPico_AchievementDefinitionArray_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_AchievementDefinitionArray.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_AchievementDefinitionArray>()
	{
		return UPico_AchievementDefinitionArray::StaticClass();
	}
	UPico_AchievementDefinitionArray::UPico_AchievementDefinitionArray(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_AchievementDefinitionArray);
	UPico_AchievementDefinitionArray::~UPico_AchievementDefinitionArray() {}
	struct Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Achievements_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Achievements_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOnlinePicoAchievementsFunction, UOnlinePicoAchievementsFunction::StaticClass, TEXT("UOnlinePicoAchievementsFunction"), &Z_Registration_Info_UClass_UOnlinePicoAchievementsFunction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOnlinePicoAchievementsFunction), 546176105U) },
		{ Z_Construct_UClass_UPico_AchievementUpdate, UPico_AchievementUpdate::StaticClass, TEXT("UPico_AchievementUpdate"), &Z_Registration_Info_UClass_UPico_AchievementUpdate, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_AchievementUpdate), 344765478U) },
		{ Z_Construct_UClass_UPico_AchievementProgress, UPico_AchievementProgress::StaticClass, TEXT("UPico_AchievementProgress"), &Z_Registration_Info_UClass_UPico_AchievementProgress, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_AchievementProgress), 124427314U) },
		{ Z_Construct_UClass_UPico_AchievementDefinition, UPico_AchievementDefinition::StaticClass, TEXT("UPico_AchievementDefinition"), &Z_Registration_Info_UClass_UPico_AchievementDefinition, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_AchievementDefinition), 4119168740U) },
		{ Z_Construct_UClass_UPico_AchievementProgressArray, UPico_AchievementProgressArray::StaticClass, TEXT("UPico_AchievementProgressArray"), &Z_Registration_Info_UClass_UPico_AchievementProgressArray, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_AchievementProgressArray), 678906005U) },
		{ Z_Construct_UClass_UPico_AchievementDefinitionArray, UPico_AchievementDefinitionArray::StaticClass, TEXT("UPico_AchievementDefinitionArray"), &Z_Registration_Info_UClass_UPico_AchievementDefinitionArray, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_AchievementDefinitionArray), 2995919518U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Achievements_h_3787266769(TEXT("/Script/OnlineSubsystemPico"),
		Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Achievements_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Achievements_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
