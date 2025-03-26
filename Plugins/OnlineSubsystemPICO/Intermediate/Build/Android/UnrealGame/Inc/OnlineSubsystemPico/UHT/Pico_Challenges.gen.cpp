// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../OnlineSubsystemPico/Public/Pico_Challenges.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePico_Challenges() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoChallengesFunction();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoChallengesFunction_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_Challenge();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_Challenge_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_ChallengeArray();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_ChallengeArray_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_ChallengeEntry();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_ChallengeEntry_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_ChallengeEntryArray();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_ChallengeEntryArray_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_Leaderboard_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_User_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_UserArray_NoRegister();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_EChallengeCreationType();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_EChallengeViewerFilter();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_EChallengeVisibility();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ELeaderboardFilterType();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ELeaderboardStartAt();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UScriptStruct* Z_Construct_UScriptStruct_FPico_ChallengeOptions();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemPico();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_Pico_ChallengeOptions;
class UScriptStruct* FPico_ChallengeOptions::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_Pico_ChallengeOptions.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_Pico_ChallengeOptions.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPico_ChallengeOptions, (UObject*)Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("Pico_ChallengeOptions"));
	}
	return Z_Registration_Info_UScriptStruct_Pico_ChallengeOptions.OuterSingleton;
}
template<> ONLINESUBSYSTEMPICO_API UScriptStruct* StaticStruct<FPico_ChallengeOptions>()
{
	return FPico_ChallengeOptions::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Title_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Title;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StartDate_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_StartDate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EndDate_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_EndDate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LeaderboardName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_LeaderboardName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIncludeActiveChallenges_MetaData[];
#endif
		static void NewProp_bIncludeActiveChallenges_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludeActiveChallenges;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIncludeFutureChallenges_MetaData[];
#endif
		static void NewProp_bIncludeFutureChallenges_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludeFutureChallenges;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIncludePastChallenges_MetaData[];
#endif
		static void NewProp_bIncludePastChallenges_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludePastChallenges;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Visibility_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Visibility_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Visibility;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ViewerFilter_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ViewerFilter_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ViewerFilter;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// enum FPico_ChallengeOptions;\n" },
#endif
		{ "DisplayName", "ChallengeOptions" },
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "enum FPico_ChallengeOptions;" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPico_ChallengeOptions>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_Title_MetaData[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Options" },
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_Title = { "Title", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPico_ChallengeOptions, Title), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_Title_MetaData), Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_Title_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_StartDate_MetaData[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Options" },
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_StartDate = { "StartDate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPico_ChallengeOptions, StartDate), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_StartDate_MetaData), Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_StartDate_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_EndDate_MetaData[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Options" },
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_EndDate = { "EndDate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPico_ChallengeOptions, EndDate), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_EndDate_MetaData), Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_EndDate_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_LeaderboardName_MetaData[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Options" },
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_LeaderboardName = { "LeaderboardName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPico_ChallengeOptions, LeaderboardName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_LeaderboardName_MetaData), Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_LeaderboardName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_bIncludeActiveChallenges_MetaData[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Options" },
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_bIncludeActiveChallenges_SetBit(void* Obj)
	{
		((FPico_ChallengeOptions*)Obj)->bIncludeActiveChallenges = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_bIncludeActiveChallenges = { "bIncludeActiveChallenges", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPico_ChallengeOptions), &Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_bIncludeActiveChallenges_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_bIncludeActiveChallenges_MetaData), Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_bIncludeActiveChallenges_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_bIncludeFutureChallenges_MetaData[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Options" },
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_bIncludeFutureChallenges_SetBit(void* Obj)
	{
		((FPico_ChallengeOptions*)Obj)->bIncludeFutureChallenges = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_bIncludeFutureChallenges = { "bIncludeFutureChallenges", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPico_ChallengeOptions), &Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_bIncludeFutureChallenges_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_bIncludeFutureChallenges_MetaData), Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_bIncludeFutureChallenges_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_bIncludePastChallenges_MetaData[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Options" },
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_bIncludePastChallenges_SetBit(void* Obj)
	{
		((FPico_ChallengeOptions*)Obj)->bIncludePastChallenges = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_bIncludePastChallenges = { "bIncludePastChallenges", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FPico_ChallengeOptions), &Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_bIncludePastChallenges_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_bIncludePastChallenges_MetaData), Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_bIncludePastChallenges_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_Visibility_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_Visibility_MetaData[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Options" },
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_Visibility = { "Visibility", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPico_ChallengeOptions, Visibility), Z_Construct_UEnum_OnlineSubsystemPico_EChallengeVisibility, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_Visibility_MetaData), Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_Visibility_MetaData) }; // 732351930
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_ViewerFilter_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_ViewerFilter_MetaData[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Options" },
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_ViewerFilter = { "ViewerFilter", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPico_ChallengeOptions, ViewerFilter), Z_Construct_UEnum_OnlineSubsystemPico_EChallengeViewerFilter, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_ViewerFilter_MetaData), Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_ViewerFilter_MetaData) }; // 1236940061
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_Title,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_StartDate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_EndDate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_LeaderboardName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_bIncludeActiveChallenges,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_bIncludeFutureChallenges,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_bIncludePastChallenges,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_Visibility_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_Visibility,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_ViewerFilter_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewProp_ViewerFilter,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
		nullptr,
		&NewStructOps,
		"Pico_ChallengeOptions",
		Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::PropPointers),
		sizeof(FPico_ChallengeOptions),
		alignof(FPico_ChallengeOptions),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPico_ChallengeOptions()
	{
		if (!Z_Registration_Info_UScriptStruct_Pico_ChallengeOptions.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_Pico_ChallengeOptions.InnerSingleton, Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_Pico_ChallengeOptions.InnerSingleton;
	}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventChallengeGet_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_Challenge* Challenge;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Challenge;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventChallengeGet_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventChallengeGet_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventChallengeGet_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature_Statics::NewProp_Challenge = { "Challenge", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventChallengeGet_Parms, Challenge), Z_Construct_UClass_UPico_Challenge_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature_Statics::NewProp_Challenge,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "ChallengeGet__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventChallengeGet_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventChallengeGet_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FChallengeGet_DelegateWrapper(const FScriptDelegate& ChallengeGet, bool bIsError, const FString& ErrorMessage, UPico_Challenge* Challenge)
{
	struct _Script_OnlineSubsystemPico_eventChallengeGet_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_Challenge* Challenge;
	};
	_Script_OnlineSubsystemPico_eventChallengeGet_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.Challenge=Challenge;
	ChallengeGet.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventChallengeGetEntries_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_ChallengeEntryArray* ChallengeEntryList;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ChallengeEntryList;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventChallengeGetEntries_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventChallengeGetEntries_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventChallengeGetEntries_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature_Statics::NewProp_ChallengeEntryList = { "ChallengeEntryList", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventChallengeGetEntries_Parms, ChallengeEntryList), Z_Construct_UClass_UPico_ChallengeEntryArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature_Statics::NewProp_ChallengeEntryList,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "ChallengeGetEntries__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventChallengeGetEntries_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventChallengeGetEntries_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FChallengeGetEntries_DelegateWrapper(const FScriptDelegate& ChallengeGetEntries, bool bIsError, const FString& ErrorMessage, UPico_ChallengeEntryArray* ChallengeEntryList)
{
	struct _Script_OnlineSubsystemPico_eventChallengeGetEntries_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_ChallengeEntryArray* ChallengeEntryList;
	};
	_Script_OnlineSubsystemPico_eventChallengeGetEntries_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.ChallengeEntryList=ChallengeEntryList;
	ChallengeGetEntries.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventChallengeGetEntriesAfterRank_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_ChallengeEntryArray* ChallengeEntryList;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ChallengeEntryList;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventChallengeGetEntriesAfterRank_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventChallengeGetEntriesAfterRank_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventChallengeGetEntriesAfterRank_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature_Statics::NewProp_ChallengeEntryList = { "ChallengeEntryList", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventChallengeGetEntriesAfterRank_Parms, ChallengeEntryList), Z_Construct_UClass_UPico_ChallengeEntryArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature_Statics::NewProp_ChallengeEntryList,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "ChallengeGetEntriesAfterRank__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventChallengeGetEntriesAfterRank_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventChallengeGetEntriesAfterRank_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FChallengeGetEntriesAfterRank_DelegateWrapper(const FScriptDelegate& ChallengeGetEntriesAfterRank, bool bIsError, const FString& ErrorMessage, UPico_ChallengeEntryArray* ChallengeEntryList)
{
	struct _Script_OnlineSubsystemPico_eventChallengeGetEntriesAfterRank_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_ChallengeEntryArray* ChallengeEntryList;
	};
	_Script_OnlineSubsystemPico_eventChallengeGetEntriesAfterRank_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.ChallengeEntryList=ChallengeEntryList;
	ChallengeGetEntriesAfterRank.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventChallengeGetEntriesByIds_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_ChallengeEntryArray* ChallengeEntryList;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ChallengeEntryList;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventChallengeGetEntriesByIds_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventChallengeGetEntriesByIds_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventChallengeGetEntriesByIds_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature_Statics::NewProp_ChallengeEntryList = { "ChallengeEntryList", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventChallengeGetEntriesByIds_Parms, ChallengeEntryList), Z_Construct_UClass_UPico_ChallengeEntryArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature_Statics::NewProp_ChallengeEntryList,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "ChallengeGetEntriesByIds__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventChallengeGetEntriesByIds_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventChallengeGetEntriesByIds_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FChallengeGetEntriesByIds_DelegateWrapper(const FScriptDelegate& ChallengeGetEntriesByIds, bool bIsError, const FString& ErrorMessage, UPico_ChallengeEntryArray* ChallengeEntryList)
{
	struct _Script_OnlineSubsystemPico_eventChallengeGetEntriesByIds_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_ChallengeEntryArray* ChallengeEntryList;
	};
	_Script_OnlineSubsystemPico_eventChallengeGetEntriesByIds_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.ChallengeEntryList=ChallengeEntryList;
	ChallengeGetEntriesByIds.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventChallengeGetList_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_ChallengeArray* ChallengeList;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ChallengeList;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventChallengeGetList_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventChallengeGetList_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventChallengeGetList_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature_Statics::NewProp_ChallengeList = { "ChallengeList", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventChallengeGetList_Parms, ChallengeList), Z_Construct_UClass_UPico_ChallengeArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature_Statics::NewProp_ChallengeList,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "ChallengeGetList__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventChallengeGetList_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventChallengeGetList_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FChallengeGetList_DelegateWrapper(const FScriptDelegate& ChallengeGetList, bool bIsError, const FString& ErrorMessage, UPico_ChallengeArray* ChallengeList)
{
	struct _Script_OnlineSubsystemPico_eventChallengeGetList_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_ChallengeArray* ChallengeList;
	};
	_Script_OnlineSubsystemPico_eventChallengeGetList_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.ChallengeList=ChallengeList;
	ChallengeGetList.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventChallengeInvite_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_Challenge* Challenge;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Challenge;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventChallengeInvite_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventChallengeInvite_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventChallengeInvite_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature_Statics::NewProp_Challenge = { "Challenge", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventChallengeInvite_Parms, Challenge), Z_Construct_UClass_UPico_Challenge_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature_Statics::NewProp_Challenge,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "ChallengeInvite__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventChallengeInvite_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventChallengeInvite_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FChallengeInvite_DelegateWrapper(const FScriptDelegate& ChallengeInvite, bool bIsError, const FString& ErrorMessage, UPico_Challenge* Challenge)
{
	struct _Script_OnlineSubsystemPico_eventChallengeInvite_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_Challenge* Challenge;
	};
	_Script_OnlineSubsystemPico_eventChallengeInvite_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.Challenge=Challenge;
	ChallengeInvite.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventChallengeLeave_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_Challenge* Challenge;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Challenge;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventChallengeLeave_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventChallengeLeave_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventChallengeLeave_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature_Statics::NewProp_Challenge = { "Challenge", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventChallengeLeave_Parms, Challenge), Z_Construct_UClass_UPico_Challenge_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature_Statics::NewProp_Challenge,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "ChallengeLeave__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventChallengeLeave_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventChallengeLeave_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FChallengeLeave_DelegateWrapper(const FScriptDelegate& ChallengeLeave, bool bIsError, const FString& ErrorMessage, UPico_Challenge* Challenge)
{
	struct _Script_OnlineSubsystemPico_eventChallengeLeave_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_Challenge* Challenge;
	};
	_Script_OnlineSubsystemPico_eventChallengeLeave_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.Challenge=Challenge;
	ChallengeLeave.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventChallengeJoin_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_Challenge* Challenge;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Challenge;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventChallengeJoin_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventChallengeJoin_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventChallengeJoin_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature_Statics::NewProp_Challenge = { "Challenge", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventChallengeJoin_Parms, Challenge), Z_Construct_UClass_UPico_Challenge_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature_Statics::NewProp_Challenge,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "ChallengeJoin__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventChallengeJoin_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventChallengeJoin_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FChallengeJoin_DelegateWrapper(const FScriptDelegate& ChallengeJoin, bool bIsError, const FString& ErrorMessage, UPico_Challenge* Challenge)
{
	struct _Script_OnlineSubsystemPico_eventChallengeJoin_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_Challenge* Challenge;
	};
	_Script_OnlineSubsystemPico_eventChallengeJoin_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.Challenge=Challenge;
	ChallengeJoin.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventChallengeLaunchInvitableUserFlow_Parms
		{
			bool bIsError;
			int32 ErrorCode;
			FString ErrorMessage;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ErrorCode;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventChallengeLaunchInvitableUserFlow_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventChallengeLaunchInvitableUserFlow_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature_Statics::NewProp_ErrorCode = { "ErrorCode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventChallengeLaunchInvitableUserFlow_Parms, ErrorCode), METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventChallengeLaunchInvitableUserFlow_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature_Statics::NewProp_ErrorCode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature_Statics::NewProp_ErrorMessage,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "ChallengeLaunchInvitableUserFlow__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventChallengeLaunchInvitableUserFlow_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventChallengeLaunchInvitableUserFlow_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FChallengeLaunchInvitableUserFlow_DelegateWrapper(const FScriptDelegate& ChallengeLaunchInvitableUserFlow, bool bIsError, int32 ErrorCode, const FString& ErrorMessage)
{
	struct _Script_OnlineSubsystemPico_eventChallengeLaunchInvitableUserFlow_Parms
	{
		bool bIsError;
		int32 ErrorCode;
		FString ErrorMessage;
	};
	_Script_OnlineSubsystemPico_eventChallengeLaunchInvitableUserFlow_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorCode=ErrorCode;
	Parms.ErrorMessage=ErrorMessage;
	ChallengeLaunchInvitableUserFlow.ProcessDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UOnlinePicoChallengesFunction::execLaunchInvitableUserFlow)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_ChallengeID);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_Delegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoChallengesFunction::LaunchInvitableUserFlow(Z_Param_WorldContextObject,Z_Param_ChallengeID,FChallengeLaunchInvitableUserFlow(Z_Param_Delegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoChallengesFunction::execInvite)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_ChallengeID);
		P_GET_TARRAY_REF(FString,Z_Param_Out_UserIDs);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_Delegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoChallengesFunction::Invite(Z_Param_WorldContextObject,Z_Param_ChallengeID,Z_Param_Out_UserIDs,FChallengeInvite(Z_Param_Delegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoChallengesFunction::execLeave)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_ChallengeID);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InLeaveDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoChallengesFunction::Leave(Z_Param_WorldContextObject,Z_Param_ChallengeID,FChallengeLeave(Z_Param_InLeaveDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoChallengesFunction::execJoin)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_ChallengeID);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InJoinDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoChallengesFunction::Join(Z_Param_WorldContextObject,Z_Param_ChallengeID,FChallengeJoin(Z_Param_InJoinDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoChallengesFunction::execGetList)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_STRUCT(FPico_ChallengeOptions,Z_Param_ChallengeOptions);
		P_GET_PROPERTY(FIntProperty,Z_Param_PageIdx);
		P_GET_PROPERTY(FIntProperty,Z_Param_PageSize);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetListDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoChallengesFunction::GetList(Z_Param_WorldContextObject,Z_Param_ChallengeOptions,Z_Param_PageIdx,Z_Param_PageSize,FChallengeGetList(Z_Param_InGetListDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoChallengesFunction::execGetEntriesByIds)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_ChallengeID);
		P_GET_PROPERTY(FIntProperty,Z_Param_PageIdx);
		P_GET_PROPERTY(FIntProperty,Z_Param_PageSize);
		P_GET_ENUM(ELeaderboardStartAt,Z_Param_StartAt);
		P_GET_TARRAY_REF(FString,Z_Param_Out_UserIDs);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetEntriesByIdsDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoChallengesFunction::GetEntriesByIds(Z_Param_WorldContextObject,Z_Param_ChallengeID,Z_Param_PageIdx,Z_Param_PageSize,ELeaderboardStartAt(Z_Param_StartAt),Z_Param_Out_UserIDs,FChallengeGetEntriesByIds(Z_Param_InGetEntriesByIdsDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoChallengesFunction::execGetEntriesAfterRank)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_ChallengeID);
		P_GET_PROPERTY(FIntProperty,Z_Param_PageIdx);
		P_GET_PROPERTY(FIntProperty,Z_Param_PageSize);
		P_GET_PROPERTY(FStrProperty,Z_Param_AfterRank);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetEntriesAfterRankDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoChallengesFunction::GetEntriesAfterRank(Z_Param_WorldContextObject,Z_Param_ChallengeID,Z_Param_PageIdx,Z_Param_PageSize,Z_Param_AfterRank,FChallengeGetEntriesAfterRank(Z_Param_InGetEntriesAfterRankDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoChallengesFunction::execGetEntries)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_ChallengeID);
		P_GET_PROPERTY(FIntProperty,Z_Param_PageIdx);
		P_GET_PROPERTY(FIntProperty,Z_Param_PageSize);
		P_GET_ENUM(ELeaderboardFilterType,Z_Param_Filter);
		P_GET_ENUM(ELeaderboardStartAt,Z_Param_StartAt);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetEntriesDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoChallengesFunction::GetEntries(Z_Param_WorldContextObject,Z_Param_ChallengeID,Z_Param_PageIdx,Z_Param_PageSize,ELeaderboardFilterType(Z_Param_Filter),ELeaderboardStartAt(Z_Param_StartAt),FChallengeGetEntries(Z_Param_InGetEntriesDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoChallengesFunction::execGet)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_ChallengeID);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoChallengesFunction::Get(Z_Param_WorldContextObject,Z_Param_ChallengeID,FChallengeGet(Z_Param_InGetDelegate));
		P_NATIVE_END;
	}
	void UOnlinePicoChallengesFunction::StaticRegisterNativesUOnlinePicoChallengesFunction()
	{
		UClass* Class = UOnlinePicoChallengesFunction::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Get", &UOnlinePicoChallengesFunction::execGet },
			{ "GetEntries", &UOnlinePicoChallengesFunction::execGetEntries },
			{ "GetEntriesAfterRank", &UOnlinePicoChallengesFunction::execGetEntriesAfterRank },
			{ "GetEntriesByIds", &UOnlinePicoChallengesFunction::execGetEntriesByIds },
			{ "GetList", &UOnlinePicoChallengesFunction::execGetList },
			{ "Invite", &UOnlinePicoChallengesFunction::execInvite },
			{ "Join", &UOnlinePicoChallengesFunction::execJoin },
			{ "LaunchInvitableUserFlow", &UOnlinePicoChallengesFunction::execLaunchInvitableUserFlow },
			{ "Leave", &UOnlinePicoChallengesFunction::execLeave },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOnlinePicoChallengesFunction_Get_Statics
	{
		struct OnlinePicoChallengesFunction_eventGet_Parms
		{
			UObject* WorldContextObject;
			FString ChallengeID;
			FScriptDelegate InGetDelegate;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChallengeID_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ChallengeID;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetDelegate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_Get_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGet_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoChallengesFunction_Get_Statics::NewProp_ChallengeID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_Get_Statics::NewProp_ChallengeID = { "ChallengeID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGet_Parms, ChallengeID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Get_Statics::NewProp_ChallengeID_MetaData), Z_Construct_UFunction_UOnlinePicoChallengesFunction_Get_Statics::NewProp_ChallengeID_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_Get_Statics::NewProp_InGetDelegate = { "InGetDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGet_Parms, InGetDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGet__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1659587758
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoChallengesFunction_Get_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_Get_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_Get_Statics::NewProp_ChallengeID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_Get_Statics::NewProp_InGetDelegate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoChallengesFunction_Get_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Challenges" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets a specified challenge by ID.</summary>\n/// <param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"ChallengeID\">Challenge ID.</param>\n/// <param name=\"InGetDelegate\">Will be executed when the request has been completed.  \n/// Delegate will contain the requested object class (FChallengeGet, bool, bIsError, const FString&, ErrorMessage, UPico_Challenge *, Challenge).</param>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets a specified challenge by ID.</summary>\n<param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"ChallengeID\">Challenge ID.</param>\n<param name=\"InGetDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (FChallengeGet, bool, bIsError, const FString&, ErrorMessage, UPico_Challenge *, Challenge).</param>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_Get_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoChallengesFunction, nullptr, "Get", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoChallengesFunction_Get_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Get_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Get_Statics::OnlinePicoChallengesFunction_eventGet_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Get_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoChallengesFunction_Get_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Get_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Get_Statics::OnlinePicoChallengesFunction_eventGet_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoChallengesFunction_Get()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoChallengesFunction_Get_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics
	{
		struct OnlinePicoChallengesFunction_eventGetEntries_Parms
		{
			UObject* WorldContextObject;
			FString ChallengeID;
			int32 PageIdx;
			int32 PageSize;
			ELeaderboardFilterType Filter;
			ELeaderboardStartAt StartAt;
			FScriptDelegate InGetEntriesDelegate;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChallengeID_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ChallengeID;
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetEntries_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::NewProp_ChallengeID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::NewProp_ChallengeID = { "ChallengeID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetEntries_Parms, ChallengeID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::NewProp_ChallengeID_MetaData), Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::NewProp_ChallengeID_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::NewProp_PageIdx = { "PageIdx", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetEntries_Parms, PageIdx), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::NewProp_PageSize = { "PageSize", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetEntries_Parms, PageSize), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::NewProp_Filter_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::NewProp_Filter = { "Filter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetEntries_Parms, Filter), Z_Construct_UEnum_OnlineSubsystemPico_ELeaderboardFilterType, METADATA_PARAMS(0, nullptr) }; // 2550994441
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::NewProp_StartAt_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::NewProp_StartAt = { "StartAt", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetEntries_Parms, StartAt), Z_Construct_UEnum_OnlineSubsystemPico_ELeaderboardStartAt, METADATA_PARAMS(0, nullptr) }; // 2656628965
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::NewProp_InGetEntriesDelegate = { "InGetEntriesDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetEntries_Parms, InGetEntriesDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntries__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2884108196
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::NewProp_ChallengeID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::NewProp_PageIdx,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::NewProp_PageSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::NewProp_Filter_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::NewProp_Filter,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::NewProp_StartAt_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::NewProp_StartAt,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::NewProp_InGetEntriesDelegate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Challenges" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets a list of challenge entries.</summary>\n/// <param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"ChallengeID\">Challenge ID.</param>\n/// <param name=\"PageIdx\">Defines which page of entries to return. The value = (The target page No.)-1.\n/// For example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>\n/// <param name=\"PageSize\">The number of entries to return on each page.</param>\n/// <param name=\"Filter\">Restricts the scope of entries to return:\n/// * `NONE`: returns all entries of the specified leaderboard\n/// * `FRIENDS`: returns the entries of the friends of the current logged-in user\n/// * `USER_IDS`(do not pass this value): returns the entries of specified users\n/// </param>\n/// <param name=\"StartAt\">Defines where to start returning challenge entries, the enumerations are:\n/// * `0`: Top (return entries from top 1)\n/// * `1`: CenteredOnViewer (place the current logged-in user's entry in the middle of the list on the first page.\n/// For example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5, the ranks displayed\n/// on the first page will be top 3, 4, 5, 6, and 7. Top 1 and 2 will not be displayed, and top 8, 9, and 10 will be\n/// displayed on the second page)\n/// * `2`: CenteredOnViewerOrTop (place the current logged-in user's entry on the top of the list on the first page.\n/// For example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5,\n/// the ranks displayed on the first page will be top 5, 6, 7, 8, and 9. Top 1, 2, 3, and 4 will not be displayed,\n/// and top 10 will be displayed on the second page)\n/// </param>\n/// <param name=\"InGetEntriesDelegate\">Will be executed when the request has been completed.  \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_ChallengeEntryArray *, ChallengeEntryList).</param>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets a list of challenge entries.</summary>\n<param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"ChallengeID\">Challenge ID.</param>\n<param name=\"PageIdx\">Defines which page of entries to return. The value = (The target page No.)-1.\nFor example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>\n<param name=\"PageSize\">The number of entries to return on each page.</param>\n<param name=\"Filter\">Restricts the scope of entries to return:\n* `NONE`: returns all entries of the specified leaderboard\n* `FRIENDS`: returns the entries of the friends of the current logged-in user\n* `USER_IDS`(do not pass this value): returns the entries of specified users\n</param>\n<param name=\"StartAt\">Defines where to start returning challenge entries, the enumerations are:\n* `0`: Top (return entries from top 1)\n* `1`: CenteredOnViewer (place the current logged-in user's entry in the middle of the list on the first page.\nFor example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5, the ranks displayed\non the first page will be top 3, 4, 5, 6, and 7. Top 1 and 2 will not be displayed, and top 8, 9, and 10 will be\ndisplayed on the second page)\n* `2`: CenteredOnViewerOrTop (place the current logged-in user's entry on the top of the list on the first page.\nFor example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5,\nthe ranks displayed on the first page will be top 5, 6, 7, 8, and 9. Top 1, 2, 3, and 4 will not be displayed,\nand top 10 will be displayed on the second page)\n</param>\n<param name=\"InGetEntriesDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_ChallengeEntryArray *, ChallengeEntryList).</param>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoChallengesFunction, nullptr, "GetEntries", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::OnlinePicoChallengesFunction_eventGetEntries_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::OnlinePicoChallengesFunction_eventGetEntries_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics
	{
		struct OnlinePicoChallengesFunction_eventGetEntriesAfterRank_Parms
		{
			UObject* WorldContextObject;
			FString ChallengeID;
			int32 PageIdx;
			int32 PageSize;
			FString AfterRank;
			FScriptDelegate InGetEntriesAfterRankDelegate;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChallengeID_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ChallengeID;
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetEntriesAfterRank_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::NewProp_ChallengeID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::NewProp_ChallengeID = { "ChallengeID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetEntriesAfterRank_Parms, ChallengeID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::NewProp_ChallengeID_MetaData), Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::NewProp_ChallengeID_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::NewProp_PageIdx = { "PageIdx", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetEntriesAfterRank_Parms, PageIdx), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::NewProp_PageSize = { "PageSize", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetEntriesAfterRank_Parms, PageSize), METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::NewProp_AfterRank_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::NewProp_AfterRank = { "AfterRank", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetEntriesAfterRank_Parms, AfterRank), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::NewProp_AfterRank_MetaData), Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::NewProp_AfterRank_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::NewProp_InGetEntriesAfterRankDelegate = { "InGetEntriesAfterRankDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetEntriesAfterRank_Parms, InGetEntriesAfterRankDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesAfterRank__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3931916242
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::NewProp_ChallengeID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::NewProp_PageIdx,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::NewProp_PageSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::NewProp_AfterRank,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::NewProp_InGetEntriesAfterRankDelegate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Challenges" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the challenge entries after a specified ranking.</summary>\n/// <param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"ChallengeID\">Challenge ID.</param>\n/// <param name=\"PageIdx\">Defines which page of entries to return. The value = (The target page No.)-1.\n/// For example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>\n/// <param name=\"PageSize\">The number of entries to return on each page.</param>\n/// <param name=\"AfterRank\">Defines after which rank to return entries.</param>\n/// <param name=\"InGetEntriesAfterRankDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_ChallengeEntryArray *, ChallengeEntryList).</param>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the challenge entries after a specified ranking.</summary>\n<param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"ChallengeID\">Challenge ID.</param>\n<param name=\"PageIdx\">Defines which page of entries to return. The value = (The target page No.)-1.\nFor example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>\n<param name=\"PageSize\">The number of entries to return on each page.</param>\n<param name=\"AfterRank\">Defines after which rank to return entries.</param>\n<param name=\"InGetEntriesAfterRankDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_ChallengeEntryArray *, ChallengeEntryList).</param>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoChallengesFunction, nullptr, "GetEntriesAfterRank", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::OnlinePicoChallengesFunction_eventGetEntriesAfterRank_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::OnlinePicoChallengesFunction_eventGetEntriesAfterRank_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics
	{
		struct OnlinePicoChallengesFunction_eventGetEntriesByIds_Parms
		{
			UObject* WorldContextObject;
			FString ChallengeID;
			int32 PageIdx;
			int32 PageSize;
			ELeaderboardStartAt StartAt;
			TArray<FString> UserIDs;
			FScriptDelegate InGetEntriesByIdsDelegate;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChallengeID_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ChallengeID;
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetEntriesByIds_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_ChallengeID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_ChallengeID = { "ChallengeID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetEntriesByIds_Parms, ChallengeID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_ChallengeID_MetaData), Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_ChallengeID_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_PageIdx = { "PageIdx", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetEntriesByIds_Parms, PageIdx), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_PageSize = { "PageSize", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetEntriesByIds_Parms, PageSize), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_StartAt_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_StartAt = { "StartAt", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetEntriesByIds_Parms, StartAt), Z_Construct_UEnum_OnlineSubsystemPico_ELeaderboardStartAt, METADATA_PARAMS(0, nullptr) }; // 2656628965
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_UserIDs_Inner = { "UserIDs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_UserIDs_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_UserIDs = { "UserIDs", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetEntriesByIds_Parms, UserIDs), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_UserIDs_MetaData), Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_UserIDs_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_InGetEntriesByIdsDelegate = { "InGetEntriesByIdsDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetEntriesByIds_Parms, InGetEntriesByIdsDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetEntriesByIds__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 767167260
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_ChallengeID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_PageIdx,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_PageSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_StartAt_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_StartAt,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_UserIDs_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_UserIDs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::NewProp_InGetEntriesByIdsDelegate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Challenges" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the challenge entries for specified user(s).</summary>\n/// <param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"ChallengeID\">Challenge ID.</param>\n/// <param name=\"PageIdx\">Defines which page of entries to return. The value = (The target page No.)-1.\n/// For example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>\n/// <param name=\"PageSize\">The number of entries to return on each page.</param>\n/// <param name=\"StartAt\">Defines where to start returning challenge entries, the enumerations are:\n/// * `0`: Top (return entries from top 1)\n/// * `1`: CenteredOnViewer (place the current logged-in user's entry in the middle of the list on the first page.\n/// For example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5, the ranks displayed\n/// on the first page will be top 3, 4, 5, 6, and 7. Top 1 and 2 will not be displayed, and top 8, 9, and 10 will be\n/// displayed on the second page)\n/// * `2`: CenteredOnViewerOrTop (place the current logged-in user's entry on the top of the list on the first page.\n/// For example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5,\n/// the ranks displayed on the first page will be top 5, 6, 7, 8, and 9. Top 1, 2, 3, and 4 will not be displayed,\n/// and top 10 will be displayed on the second page)\n/// </param>\n/// <param name=\"UserIDs\">User ID(s).</param>\n/// <param name=\"InGetEntriesByIdsDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_ChallengeEntryArray *, ChallengeEntryList).</param>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the challenge entries for specified user(s).</summary>\n<param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"ChallengeID\">Challenge ID.</param>\n<param name=\"PageIdx\">Defines which page of entries to return. The value = (The target page No.)-1.\nFor example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`.</param>\n<param name=\"PageSize\">The number of entries to return on each page.</param>\n<param name=\"StartAt\">Defines where to start returning challenge entries, the enumerations are:\n* `0`: Top (return entries from top 1)\n* `1`: CenteredOnViewer (place the current logged-in user's entry in the middle of the list on the first page.\nFor example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5, the ranks displayed\non the first page will be top 3, 4, 5, 6, and 7. Top 1 and 2 will not be displayed, and top 8, 9, and 10 will be\ndisplayed on the second page)\n* `2`: CenteredOnViewerOrTop (place the current logged-in user's entry on the top of the list on the first page.\nFor example, if the total number of entries is 10, `pageSize` is set to `5`, and the user's rank is top 5,\nthe ranks displayed on the first page will be top 5, 6, 7, 8, and 9. Top 1, 2, 3, and 4 will not be displayed,\nand top 10 will be displayed on the second page)\n</param>\n<param name=\"UserIDs\">User ID(s).</param>\n<param name=\"InGetEntriesByIdsDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_ChallengeEntryArray *, ChallengeEntryList).</param>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoChallengesFunction, nullptr, "GetEntriesByIds", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::OnlinePicoChallengesFunction_eventGetEntriesByIds_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::OnlinePicoChallengesFunction_eventGetEntriesByIds_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList_Statics
	{
		struct OnlinePicoChallengesFunction_eventGetList_Parms
		{
			UObject* WorldContextObject;
			FPico_ChallengeOptions ChallengeOptions;
			int32 PageIdx;
			int32 PageSize;
			FScriptDelegate InGetListDelegate;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ChallengeOptions;
		static const UECodeGen_Private::FIntPropertyParams NewProp_PageIdx;
		static const UECodeGen_Private::FIntPropertyParams NewProp_PageSize;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetListDelegate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetList_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList_Statics::NewProp_ChallengeOptions = { "ChallengeOptions", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetList_Parms, ChallengeOptions), Z_Construct_UScriptStruct_FPico_ChallengeOptions, METADATA_PARAMS(0, nullptr) }; // 531778955
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList_Statics::NewProp_PageIdx = { "PageIdx", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetList_Parms, PageIdx), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList_Statics::NewProp_PageSize = { "PageSize", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetList_Parms, PageSize), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList_Statics::NewProp_InGetListDelegate = { "InGetListDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventGetList_Parms, InGetListDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeGetList__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3080046426
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList_Statics::NewProp_ChallengeOptions,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList_Statics::NewProp_PageIdx,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList_Statics::NewProp_PageSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList_Statics::NewProp_InGetListDelegate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Challenges" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets a list of challenges.</summary>\n/// <param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"ChallengeOptions\">Restricts the scope of challenges to return. You can define the start date and end date of challenges, the leaderboard the challenges belong to, etc. </param>\n/// <param name=\"PageIdx\">Defines which page of challenges to return. The value = (The target page No.)-1. For example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`. </param>\n/// <param name=\"PageSize\">The number of challenges to return on each page.</param>\n/// <param name=\"InGetListDelegate\">Will be executed when the request has been completed. Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_ChallengeArray *, ChallengeList).</param>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets a list of challenges.</summary>\n<param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"ChallengeOptions\">Restricts the scope of challenges to return. You can define the start date and end date of challenges, the leaderboard the challenges belong to, etc. </param>\n<param name=\"PageIdx\">Defines which page of challenges to return. The value = (The target page No.)-1. For example, if you want to get the first page of entries, pass `0`; if you want to get the second page of entries, pass `1`. </param>\n<param name=\"PageSize\">The number of challenges to return on each page.</param>\n<param name=\"InGetListDelegate\">Will be executed when the request has been completed. Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_ChallengeArray *, ChallengeList).</param>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoChallengesFunction, nullptr, "GetList", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList_Statics::OnlinePicoChallengesFunction_eventGetList_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList_Statics::OnlinePicoChallengesFunction_eventGetList_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics
	{
		struct OnlinePicoChallengesFunction_eventInvite_Parms
		{
			UObject* WorldContextObject;
			FString ChallengeID;
			TArray<FString> UserIDs;
			FScriptDelegate Delegate;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChallengeID_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ChallengeID;
		static const UECodeGen_Private::FStrPropertyParams NewProp_UserIDs_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UserIDs_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_UserIDs;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_Delegate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventInvite_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::NewProp_ChallengeID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::NewProp_ChallengeID = { "ChallengeID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventInvite_Parms, ChallengeID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::NewProp_ChallengeID_MetaData), Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::NewProp_ChallengeID_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::NewProp_UserIDs_Inner = { "UserIDs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::NewProp_UserIDs_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::NewProp_UserIDs = { "UserIDs", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventInvite_Parms, UserIDs), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::NewProp_UserIDs_MetaData), Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::NewProp_UserIDs_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::NewProp_Delegate = { "Delegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventInvite_Parms, Delegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeInvite__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2671276020
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::NewProp_ChallengeID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::NewProp_UserIDs_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::NewProp_UserIDs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::NewProp_Delegate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Challenges" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Invites user(s) to join a challenge.</summary>\n/// <param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"ChallengeID\">Challenge ID.</param>\n/// <param name=\"UserIDs\">User ID(s).</param>\n/// <param name=\"Delegate\">Will be executed when the request has been completed.   \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_Challenge *, Challenge).</param>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Invites user(s) to join a challenge.</summary>\n<param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"ChallengeID\">Challenge ID.</param>\n<param name=\"UserIDs\">User ID(s).</param>\n<param name=\"Delegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_Challenge *, Challenge).</param>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoChallengesFunction, nullptr, "Invite", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::OnlinePicoChallengesFunction_eventInvite_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::OnlinePicoChallengesFunction_eventInvite_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoChallengesFunction_Join_Statics
	{
		struct OnlinePicoChallengesFunction_eventJoin_Parms
		{
			UObject* WorldContextObject;
			FString ChallengeID;
			FScriptDelegate InJoinDelegate;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChallengeID_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ChallengeID;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InJoinDelegate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_Join_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventJoin_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoChallengesFunction_Join_Statics::NewProp_ChallengeID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_Join_Statics::NewProp_ChallengeID = { "ChallengeID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventJoin_Parms, ChallengeID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Join_Statics::NewProp_ChallengeID_MetaData), Z_Construct_UFunction_UOnlinePicoChallengesFunction_Join_Statics::NewProp_ChallengeID_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_Join_Statics::NewProp_InJoinDelegate = { "InJoinDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventJoin_Parms, InJoinDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeJoin__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 412847403
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoChallengesFunction_Join_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_Join_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_Join_Statics::NewProp_ChallengeID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_Join_Statics::NewProp_InJoinDelegate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoChallengesFunction_Join_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Challenges" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Lets the current user join a challenge.</summary>\n/// <param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"ChallengeID\">Challenge ID.</param>\n/// <param name=\"InJoinDelegate\">Will be executed when the request has been completed.   \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_Challenge *, Challenge).</param>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Lets the current user join a challenge.</summary>\n<param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"ChallengeID\">Challenge ID.</param>\n<param name=\"InJoinDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_Challenge *, Challenge).</param>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_Join_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoChallengesFunction, nullptr, "Join", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoChallengesFunction_Join_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Join_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Join_Statics::OnlinePicoChallengesFunction_eventJoin_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Join_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoChallengesFunction_Join_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Join_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Join_Statics::OnlinePicoChallengesFunction_eventJoin_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoChallengesFunction_Join()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoChallengesFunction_Join_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoChallengesFunction_LaunchInvitableUserFlow_Statics
	{
		struct OnlinePicoChallengesFunction_eventLaunchInvitableUserFlow_Parms
		{
			UObject* WorldContextObject;
			FString ChallengeID;
			FScriptDelegate Delegate;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChallengeID_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ChallengeID;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_Delegate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_LaunchInvitableUserFlow_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventLaunchInvitableUserFlow_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoChallengesFunction_LaunchInvitableUserFlow_Statics::NewProp_ChallengeID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_LaunchInvitableUserFlow_Statics::NewProp_ChallengeID = { "ChallengeID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventLaunchInvitableUserFlow_Parms, ChallengeID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_LaunchInvitableUserFlow_Statics::NewProp_ChallengeID_MetaData), Z_Construct_UFunction_UOnlinePicoChallengesFunction_LaunchInvitableUserFlow_Statics::NewProp_ChallengeID_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_LaunchInvitableUserFlow_Statics::NewProp_Delegate = { "Delegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventLaunchInvitableUserFlow_Parms, Delegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLaunchInvitableUserFlow__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3656424198
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoChallengesFunction_LaunchInvitableUserFlow_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_LaunchInvitableUserFlow_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_LaunchInvitableUserFlow_Statics::NewProp_ChallengeID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_LaunchInvitableUserFlow_Statics::NewProp_Delegate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoChallengesFunction_LaunchInvitableUserFlow_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Challenges" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Launches the invitation flow to let the current user invite friends to a specified challenge.</summary>\n/// <param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"ChallengeID\">Challenge ID.</param>\n/// <param name=\"Delegate\">Will be executed when the request has been completed.  \n/// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage).</param>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Launches the invitation flow to let the current user invite friends to a specified challenge.</summary>\n<param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"ChallengeID\">Challenge ID.</param>\n<param name=\"Delegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage).</param>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_LaunchInvitableUserFlow_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoChallengesFunction, nullptr, "LaunchInvitableUserFlow", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoChallengesFunction_LaunchInvitableUserFlow_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_LaunchInvitableUserFlow_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoChallengesFunction_LaunchInvitableUserFlow_Statics::OnlinePicoChallengesFunction_eventLaunchInvitableUserFlow_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_LaunchInvitableUserFlow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoChallengesFunction_LaunchInvitableUserFlow_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_LaunchInvitableUserFlow_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoChallengesFunction_LaunchInvitableUserFlow_Statics::OnlinePicoChallengesFunction_eventLaunchInvitableUserFlow_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoChallengesFunction_LaunchInvitableUserFlow()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoChallengesFunction_LaunchInvitableUserFlow_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoChallengesFunction_Leave_Statics
	{
		struct OnlinePicoChallengesFunction_eventLeave_Parms
		{
			UObject* WorldContextObject;
			FString ChallengeID;
			FScriptDelegate InLeaveDelegate;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChallengeID_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ChallengeID;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InLeaveDelegate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_Leave_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventLeave_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoChallengesFunction_Leave_Statics::NewProp_ChallengeID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_Leave_Statics::NewProp_ChallengeID = { "ChallengeID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventLeave_Parms, ChallengeID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Leave_Statics::NewProp_ChallengeID_MetaData), Z_Construct_UFunction_UOnlinePicoChallengesFunction_Leave_Statics::NewProp_ChallengeID_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_Leave_Statics::NewProp_InLeaveDelegate = { "InLeaveDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoChallengesFunction_eventLeave_Parms, InLeaveDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ChallengeLeave__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2761763330
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoChallengesFunction_Leave_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_Leave_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_Leave_Statics::NewProp_ChallengeID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoChallengesFunction_Leave_Statics::NewProp_InLeaveDelegate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoChallengesFunction_Leave_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Challenges" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Lets the current user leave a challenge.</summary>\n/// <param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"ChallengeID\">Challenge ID.</param>\n/// <param name=\"InLeaveDelegate\">Will be executed when the request has been completed.  \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_Challenge *, Challenge).</param>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Lets the current user leave a challenge.</summary>\n<param name=\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"ChallengeID\">Challenge ID.</param>\n<param name=\"InLeaveDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_Challenge *, Challenge).</param>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoChallengesFunction_Leave_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoChallengesFunction, nullptr, "Leave", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoChallengesFunction_Leave_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Leave_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Leave_Statics::OnlinePicoChallengesFunction_eventLeave_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Leave_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoChallengesFunction_Leave_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Leave_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoChallengesFunction_Leave_Statics::OnlinePicoChallengesFunction_eventLeave_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoChallengesFunction_Leave()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoChallengesFunction_Leave_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOnlinePicoChallengesFunction);
	UClass* Z_Construct_UClass_UOnlinePicoChallengesFunction_NoRegister()
	{
		return UOnlinePicoChallengesFunction::StaticClass();
	}
	struct Z_Construct_UClass_UOnlinePicoChallengesFunction_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOnlinePicoChallengesFunction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoChallengesFunction_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UOnlinePicoChallengesFunction_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOnlinePicoChallengesFunction_Get, "Get" }, // 3773575244
		{ &Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntries, "GetEntries" }, // 1950309066
		{ &Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesAfterRank, "GetEntriesAfterRank" }, // 3427478116
		{ &Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetEntriesByIds, "GetEntriesByIds" }, // 2258551775
		{ &Z_Construct_UFunction_UOnlinePicoChallengesFunction_GetList, "GetList" }, // 608632800
		{ &Z_Construct_UFunction_UOnlinePicoChallengesFunction_Invite, "Invite" }, // 47761399
		{ &Z_Construct_UFunction_UOnlinePicoChallengesFunction_Join, "Join" }, // 1426149728
		{ &Z_Construct_UFunction_UOnlinePicoChallengesFunction_LaunchInvitableUserFlow, "LaunchInvitableUserFlow" }, // 2531411251
		{ &Z_Construct_UFunction_UOnlinePicoChallengesFunction_Leave, "Leave" }, // 3440408517
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoChallengesFunction_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoChallengesFunction_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @defgroup BP_Challenges BP_Challenges\n *  This is the BP_Challenges group\n *  @{\n *//// @brief OnlinePicoChallenges Blueprint Function class.\n" },
#endif
		{ "IncludePath", "Pico_Challenges.h" },
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@defgroup BP_Challenges BP_Challenges\nThis is the BP_Challenges group\n@{\n/// @brief OnlinePicoChallenges Blueprint Function class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOnlinePicoChallengesFunction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOnlinePicoChallengesFunction>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOnlinePicoChallengesFunction_Statics::ClassParams = {
		&UOnlinePicoChallengesFunction::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoChallengesFunction_Statics::Class_MetaDataParams), Z_Construct_UClass_UOnlinePicoChallengesFunction_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UOnlinePicoChallengesFunction()
	{
		if (!Z_Registration_Info_UClass_UOnlinePicoChallengesFunction.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOnlinePicoChallengesFunction.OuterSingleton, Z_Construct_UClass_UOnlinePicoChallengesFunction_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOnlinePicoChallengesFunction.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UOnlinePicoChallengesFunction>()
	{
		return UOnlinePicoChallengesFunction::StaticClass();
	}
	UOnlinePicoChallengesFunction::UOnlinePicoChallengesFunction(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOnlinePicoChallengesFunction);
	UOnlinePicoChallengesFunction::~UOnlinePicoChallengesFunction() {}
	DEFINE_FUNCTION(UPico_Challenge::execGetParticipantsOptional)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPico_UserArray**)Z_Param__Result=P_THIS->GetParticipantsOptional();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Challenge::execGetLeaderboard)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPico_Leaderboard**)Z_Param__Result=P_THIS->GetLeaderboard();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Challenge::execGetInvitedUsersOptional)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPico_UserArray**)Z_Param__Result=P_THIS->GetInvitedUsersOptional();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Challenge::execGetVisibility)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EChallengeVisibility*)Z_Param__Result=P_THIS->GetVisibility();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Challenge::execGetTitle)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetTitle();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Challenge::execGetID)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetID();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Challenge::execGetStartDate)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetStartDate();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Challenge::execGetEndDate)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetEndDate();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Challenge::execGetStartDateTime)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FDateTime*)Z_Param__Result=P_THIS->GetStartDateTime();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Challenge::execGetEndDateTime)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FDateTime*)Z_Param__Result=P_THIS->GetEndDateTime();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Challenge::execGetCreationType)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EChallengeCreationType*)Z_Param__Result=P_THIS->GetCreationType();
		P_NATIVE_END;
	}
	void UPico_Challenge::StaticRegisterNativesUPico_Challenge()
	{
		UClass* Class = UPico_Challenge::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetCreationType", &UPico_Challenge::execGetCreationType },
			{ "GetEndDate", &UPico_Challenge::execGetEndDate },
			{ "GetEndDateTime", &UPico_Challenge::execGetEndDateTime },
			{ "GetID", &UPico_Challenge::execGetID },
			{ "GetInvitedUsersOptional", &UPico_Challenge::execGetInvitedUsersOptional },
			{ "GetLeaderboard", &UPico_Challenge::execGetLeaderboard },
			{ "GetParticipantsOptional", &UPico_Challenge::execGetParticipantsOptional },
			{ "GetStartDate", &UPico_Challenge::execGetStartDate },
			{ "GetStartDateTime", &UPico_Challenge::execGetStartDateTime },
			{ "GetTitle", &UPico_Challenge::execGetTitle },
			{ "GetVisibility", &UPico_Challenge::execGetVisibility },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_Challenge_GetCreationType_Statics
	{
		struct Pico_Challenge_eventGetCreationType_Parms
		{
			EChallengeCreationType ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPico_Challenge_GetCreationType_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPico_Challenge_GetCreationType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Challenge_eventGetCreationType_Parms, ReturnValue), Z_Construct_UEnum_OnlineSubsystemPico_EChallengeCreationType, METADATA_PARAMS(0, nullptr) }; // 1576434920
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Challenge_GetCreationType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Challenge_GetCreationType_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Challenge_GetCreationType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Challenge_GetCreationType_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The creator of the challenge. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The creator of the challenge." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Challenge_GetCreationType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Challenge, nullptr, "GetCreationType", nullptr, nullptr, Z_Construct_UFunction_UPico_Challenge_GetCreationType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetCreationType_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Challenge_GetCreationType_Statics::Pico_Challenge_eventGetCreationType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetCreationType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Challenge_GetCreationType_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetCreationType_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Challenge_GetCreationType_Statics::Pico_Challenge_eventGetCreationType_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Challenge_GetCreationType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Challenge_GetCreationType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Challenge_GetEndDate_Statics
	{
		struct Pico_Challenge_eventGetEndDate_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_Challenge_GetEndDate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Challenge_eventGetEndDate_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Challenge_GetEndDate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Challenge_GetEndDate_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Challenge_GetEndDate_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Challenge's end date (as string). */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Challenge's end date (as string)." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Challenge_GetEndDate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Challenge, nullptr, "GetEndDate", nullptr, nullptr, Z_Construct_UFunction_UPico_Challenge_GetEndDate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetEndDate_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Challenge_GetEndDate_Statics::Pico_Challenge_eventGetEndDate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetEndDate_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Challenge_GetEndDate_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetEndDate_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Challenge_GetEndDate_Statics::Pico_Challenge_eventGetEndDate_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Challenge_GetEndDate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Challenge_GetEndDate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Challenge_GetEndDateTime_Statics
	{
		struct Pico_Challenge_eventGetEndDateTime_Parms
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
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPico_Challenge_GetEndDateTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Challenge_eventGetEndDateTime_Parms, ReturnValue), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Challenge_GetEndDateTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Challenge_GetEndDateTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Challenge_GetEndDateTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Challenge's end date. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Challenge's end date." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Challenge_GetEndDateTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Challenge, nullptr, "GetEndDateTime", nullptr, nullptr, Z_Construct_UFunction_UPico_Challenge_GetEndDateTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetEndDateTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Challenge_GetEndDateTime_Statics::Pico_Challenge_eventGetEndDateTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetEndDateTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Challenge_GetEndDateTime_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetEndDateTime_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Challenge_GetEndDateTime_Statics::Pico_Challenge_eventGetEndDateTime_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Challenge_GetEndDateTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Challenge_GetEndDateTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Challenge_GetID_Statics
	{
		struct Pico_Challenge_eventGetID_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_Challenge_GetID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Challenge_eventGetID_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Challenge_GetID_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Challenge_GetID_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Challenge_GetID_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Challenge ID */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Challenge ID" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Challenge_GetID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Challenge, nullptr, "GetID", nullptr, nullptr, Z_Construct_UFunction_UPico_Challenge_GetID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetID_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Challenge_GetID_Statics::Pico_Challenge_eventGetID_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Challenge_GetID_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetID_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Challenge_GetID_Statics::Pico_Challenge_eventGetID_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Challenge_GetID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Challenge_GetID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Challenge_GetInvitedUsersOptional_Statics
	{
		struct Pico_Challenge_eventGetInvitedUsersOptional_Parms
		{
			UPico_UserArray* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPico_Challenge_GetInvitedUsersOptional_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Challenge_eventGetInvitedUsersOptional_Parms, ReturnValue), Z_Construct_UClass_UPico_UserArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Challenge_GetInvitedUsersOptional_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Challenge_GetInvitedUsersOptional_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Challenge_GetInvitedUsersOptional_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Users invited to the challenge, which might be null. Should check if it is null before use. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Users invited to the challenge, which might be null. Should check if it is null before use." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Challenge_GetInvitedUsersOptional_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Challenge, nullptr, "GetInvitedUsersOptional", nullptr, nullptr, Z_Construct_UFunction_UPico_Challenge_GetInvitedUsersOptional_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetInvitedUsersOptional_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Challenge_GetInvitedUsersOptional_Statics::Pico_Challenge_eventGetInvitedUsersOptional_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetInvitedUsersOptional_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Challenge_GetInvitedUsersOptional_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetInvitedUsersOptional_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Challenge_GetInvitedUsersOptional_Statics::Pico_Challenge_eventGetInvitedUsersOptional_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Challenge_GetInvitedUsersOptional()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Challenge_GetInvitedUsersOptional_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Challenge_GetLeaderboard_Statics
	{
		struct Pico_Challenge_eventGetLeaderboard_Parms
		{
			UPico_Leaderboard* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPico_Challenge_GetLeaderboard_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Challenge_eventGetLeaderboard_Parms, ReturnValue), Z_Construct_UClass_UPico_Leaderboard_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Challenge_GetLeaderboard_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Challenge_GetLeaderboard_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Challenge_GetLeaderboard_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The info about the leaderboard that the challenge associated with. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The info about the leaderboard that the challenge associated with." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Challenge_GetLeaderboard_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Challenge, nullptr, "GetLeaderboard", nullptr, nullptr, Z_Construct_UFunction_UPico_Challenge_GetLeaderboard_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetLeaderboard_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Challenge_GetLeaderboard_Statics::Pico_Challenge_eventGetLeaderboard_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetLeaderboard_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Challenge_GetLeaderboard_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetLeaderboard_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Challenge_GetLeaderboard_Statics::Pico_Challenge_eventGetLeaderboard_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Challenge_GetLeaderboard()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Challenge_GetLeaderboard_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Challenge_GetParticipantsOptional_Statics
	{
		struct Pico_Challenge_eventGetParticipantsOptional_Parms
		{
			UPico_UserArray* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPico_Challenge_GetParticipantsOptional_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Challenge_eventGetParticipantsOptional_Parms, ReturnValue), Z_Construct_UClass_UPico_UserArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Challenge_GetParticipantsOptional_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Challenge_GetParticipantsOptional_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Challenge_GetParticipantsOptional_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Participants of the challenge, which might be null. Should check if it is null before use. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Participants of the challenge, which might be null. Should check if it is null before use." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Challenge_GetParticipantsOptional_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Challenge, nullptr, "GetParticipantsOptional", nullptr, nullptr, Z_Construct_UFunction_UPico_Challenge_GetParticipantsOptional_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetParticipantsOptional_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Challenge_GetParticipantsOptional_Statics::Pico_Challenge_eventGetParticipantsOptional_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetParticipantsOptional_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Challenge_GetParticipantsOptional_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetParticipantsOptional_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Challenge_GetParticipantsOptional_Statics::Pico_Challenge_eventGetParticipantsOptional_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Challenge_GetParticipantsOptional()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Challenge_GetParticipantsOptional_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Challenge_GetStartDate_Statics
	{
		struct Pico_Challenge_eventGetStartDate_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_Challenge_GetStartDate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Challenge_eventGetStartDate_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Challenge_GetStartDate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Challenge_GetStartDate_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Challenge_GetStartDate_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Challenge's start date (as string). */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Challenge's start date (as string)." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Challenge_GetStartDate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Challenge, nullptr, "GetStartDate", nullptr, nullptr, Z_Construct_UFunction_UPico_Challenge_GetStartDate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetStartDate_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Challenge_GetStartDate_Statics::Pico_Challenge_eventGetStartDate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetStartDate_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Challenge_GetStartDate_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetStartDate_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Challenge_GetStartDate_Statics::Pico_Challenge_eventGetStartDate_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Challenge_GetStartDate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Challenge_GetStartDate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Challenge_GetStartDateTime_Statics
	{
		struct Pico_Challenge_eventGetStartDateTime_Parms
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
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPico_Challenge_GetStartDateTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Challenge_eventGetStartDateTime_Parms, ReturnValue), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Challenge_GetStartDateTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Challenge_GetStartDateTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Challenge_GetStartDateTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Challenge's start date. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Challenge's start date." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Challenge_GetStartDateTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Challenge, nullptr, "GetStartDateTime", nullptr, nullptr, Z_Construct_UFunction_UPico_Challenge_GetStartDateTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetStartDateTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Challenge_GetStartDateTime_Statics::Pico_Challenge_eventGetStartDateTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetStartDateTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Challenge_GetStartDateTime_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetStartDateTime_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Challenge_GetStartDateTime_Statics::Pico_Challenge_eventGetStartDateTime_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Challenge_GetStartDateTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Challenge_GetStartDateTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Challenge_GetTitle_Statics
	{
		struct Pico_Challenge_eventGetTitle_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_Challenge_GetTitle_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Challenge_eventGetTitle_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Challenge_GetTitle_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Challenge_GetTitle_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Challenge_GetTitle_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Challenge's title. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Challenge's title." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Challenge_GetTitle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Challenge, nullptr, "GetTitle", nullptr, nullptr, Z_Construct_UFunction_UPico_Challenge_GetTitle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetTitle_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Challenge_GetTitle_Statics::Pico_Challenge_eventGetTitle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetTitle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Challenge_GetTitle_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetTitle_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Challenge_GetTitle_Statics::Pico_Challenge_eventGetTitle_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Challenge_GetTitle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Challenge_GetTitle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Challenge_GetVisibility_Statics
	{
		struct Pico_Challenge_eventGetVisibility_Parms
		{
			EChallengeVisibility ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPico_Challenge_GetVisibility_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPico_Challenge_GetVisibility_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Challenge_eventGetVisibility_Parms, ReturnValue), Z_Construct_UEnum_OnlineSubsystemPico_EChallengeVisibility, METADATA_PARAMS(0, nullptr) }; // 732351930
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Challenge_GetVisibility_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Challenge_GetVisibility_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Challenge_GetVisibility_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Challenge_GetVisibility_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Challenge's visibility. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Challenge's visibility." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Challenge_GetVisibility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Challenge, nullptr, "GetVisibility", nullptr, nullptr, Z_Construct_UFunction_UPico_Challenge_GetVisibility_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetVisibility_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Challenge_GetVisibility_Statics::Pico_Challenge_eventGetVisibility_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetVisibility_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Challenge_GetVisibility_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Challenge_GetVisibility_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Challenge_GetVisibility_Statics::Pico_Challenge_eventGetVisibility_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Challenge_GetVisibility()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Challenge_GetVisibility_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_Challenge);
	UClass* Z_Construct_UClass_UPico_Challenge_NoRegister()
	{
		return UPico_Challenge::StaticClass();
	}
	struct Z_Construct_UClass_UPico_Challenge_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InvitedUsersOptional_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InvitedUsersOptional;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ParticipantsOptional_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ParticipantsOptional;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Leaderboard_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Leaderboard;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_Challenge_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_Challenge_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_Challenge_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_Challenge_GetCreationType, "GetCreationType" }, // 1638104442
		{ &Z_Construct_UFunction_UPico_Challenge_GetEndDate, "GetEndDate" }, // 3031769080
		{ &Z_Construct_UFunction_UPico_Challenge_GetEndDateTime, "GetEndDateTime" }, // 1546232286
		{ &Z_Construct_UFunction_UPico_Challenge_GetID, "GetID" }, // 3948328760
		{ &Z_Construct_UFunction_UPico_Challenge_GetInvitedUsersOptional, "GetInvitedUsersOptional" }, // 712472696
		{ &Z_Construct_UFunction_UPico_Challenge_GetLeaderboard, "GetLeaderboard" }, // 143968908
		{ &Z_Construct_UFunction_UPico_Challenge_GetParticipantsOptional, "GetParticipantsOptional" }, // 3844497377
		{ &Z_Construct_UFunction_UPico_Challenge_GetStartDate, "GetStartDate" }, // 2777277391
		{ &Z_Construct_UFunction_UPico_Challenge_GetStartDateTime, "GetStartDateTime" }, // 982521899
		{ &Z_Construct_UFunction_UPico_Challenge_GetTitle, "GetTitle" }, // 1994609056
		{ &Z_Construct_UFunction_UPico_Challenge_GetVisibility, "GetVisibility" }, // 3141742854
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_Challenge_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_Challenge_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_Challenge class.\n" },
#endif
		{ "IncludePath", "Pico_Challenges.h" },
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_Challenge class." },
#endif
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_Challenge_Statics::NewProp_InvitedUsersOptional_MetaData[] = {
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPico_Challenge_Statics::NewProp_InvitedUsersOptional = { "InvitedUsersOptional", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPico_Challenge, InvitedUsersOptional), Z_Construct_UClass_UPico_UserArray_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_Challenge_Statics::NewProp_InvitedUsersOptional_MetaData), Z_Construct_UClass_UPico_Challenge_Statics::NewProp_InvitedUsersOptional_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_Challenge_Statics::NewProp_ParticipantsOptional_MetaData[] = {
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPico_Challenge_Statics::NewProp_ParticipantsOptional = { "ParticipantsOptional", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPico_Challenge, ParticipantsOptional), Z_Construct_UClass_UPico_UserArray_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_Challenge_Statics::NewProp_ParticipantsOptional_MetaData), Z_Construct_UClass_UPico_Challenge_Statics::NewProp_ParticipantsOptional_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_Challenge_Statics::NewProp_Leaderboard_MetaData[] = {
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPico_Challenge_Statics::NewProp_Leaderboard = { "Leaderboard", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPico_Challenge, Leaderboard), Z_Construct_UClass_UPico_Leaderboard_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_Challenge_Statics::NewProp_Leaderboard_MetaData), Z_Construct_UClass_UPico_Challenge_Statics::NewProp_Leaderboard_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPico_Challenge_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_Challenge_Statics::NewProp_InvitedUsersOptional,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_Challenge_Statics::NewProp_ParticipantsOptional,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_Challenge_Statics::NewProp_Leaderboard,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_Challenge_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_Challenge>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_Challenge_Statics::ClassParams = {
		&UPico_Challenge::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPico_Challenge_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPico_Challenge_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_Challenge_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_Challenge_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_Challenge_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPico_Challenge()
	{
		if (!Z_Registration_Info_UClass_UPico_Challenge.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_Challenge.OuterSingleton, Z_Construct_UClass_UPico_Challenge_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_Challenge.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_Challenge>()
	{
		return UPico_Challenge::StaticClass();
	}
	UPico_Challenge::UPico_Challenge(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_Challenge);
	UPico_Challenge::~UPico_Challenge() {}
	DEFINE_FUNCTION(UPico_ChallengeEntry::execGetUser)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPico_User**)Z_Param__Result=P_THIS->GetUser();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_ChallengeEntry::execGetTimestamp)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FDateTime*)Z_Param__Result=P_THIS->GetTimestamp();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_ChallengeEntry::execGetScore)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int64*)Z_Param__Result=P_THIS->GetScore();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_ChallengeEntry::execGetRank)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetRank();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_ChallengeEntry::execGetID)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetID();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_ChallengeEntry::execGetExtraDataString)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetExtraDataString();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_ChallengeEntry::execGetExtraData)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<uint8>*)Z_Param__Result=P_THIS->GetExtraData();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_ChallengeEntry::execGetDisplayScore)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetDisplayScore();
		P_NATIVE_END;
	}
	void UPico_ChallengeEntry::StaticRegisterNativesUPico_ChallengeEntry()
	{
		UClass* Class = UPico_ChallengeEntry::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetDisplayScore", &UPico_ChallengeEntry::execGetDisplayScore },
			{ "GetExtraData", &UPico_ChallengeEntry::execGetExtraData },
			{ "GetExtraDataString", &UPico_ChallengeEntry::execGetExtraDataString },
			{ "GetID", &UPico_ChallengeEntry::execGetID },
			{ "GetRank", &UPico_ChallengeEntry::execGetRank },
			{ "GetScore", &UPico_ChallengeEntry::execGetScore },
			{ "GetTimestamp", &UPico_ChallengeEntry::execGetTimestamp },
			{ "GetUser", &UPico_ChallengeEntry::execGetUser },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_ChallengeEntry_GetDisplayScore_Statics
	{
		struct Pico_ChallengeEntry_eventGetDisplayScore_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_ChallengeEntry_GetDisplayScore_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_ChallengeEntry_eventGetDisplayScore_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_ChallengeEntry_GetDisplayScore_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ChallengeEntry_GetDisplayScore_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_ChallengeEntry_GetDisplayScore_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The entry's display score. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The entry's display score." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_ChallengeEntry_GetDisplayScore_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_ChallengeEntry, nullptr, "GetDisplayScore", nullptr, nullptr, Z_Construct_UFunction_UPico_ChallengeEntry_GetDisplayScore_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetDisplayScore_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_ChallengeEntry_GetDisplayScore_Statics::Pico_ChallengeEntry_eventGetDisplayScore_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetDisplayScore_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_ChallengeEntry_GetDisplayScore_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetDisplayScore_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_ChallengeEntry_GetDisplayScore_Statics::Pico_ChallengeEntry_eventGetDisplayScore_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_ChallengeEntry_GetDisplayScore()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_ChallengeEntry_GetDisplayScore_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraData_Statics
	{
		struct Pico_ChallengeEntry_eventGetExtraData_Parms
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
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraData_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_ChallengeEntry_eventGetExtraData_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraData_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraData_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The entry's additional info, no more than 2KB. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The entry's additional info, no more than 2KB." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_ChallengeEntry, nullptr, "GetExtraData", nullptr, nullptr, Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraData_Statics::Pico_ChallengeEntry_eventGetExtraData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraData_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraData_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraData_Statics::Pico_ChallengeEntry_eventGetExtraData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraDataString_Statics
	{
		struct Pico_ChallengeEntry_eventGetExtraDataString_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraDataString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_ChallengeEntry_eventGetExtraDataString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraDataString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraDataString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraDataString_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The entry's additional info (as string)*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The entry's additional info (as string)" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraDataString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_ChallengeEntry, nullptr, "GetExtraDataString", nullptr, nullptr, Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraDataString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraDataString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraDataString_Statics::Pico_ChallengeEntry_eventGetExtraDataString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraDataString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraDataString_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraDataString_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraDataString_Statics::Pico_ChallengeEntry_eventGetExtraDataString_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraDataString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraDataString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_ChallengeEntry_GetID_Statics
	{
		struct Pico_ChallengeEntry_eventGetID_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_ChallengeEntry_GetID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_ChallengeEntry_eventGetID_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_ChallengeEntry_GetID_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ChallengeEntry_GetID_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_ChallengeEntry_GetID_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The ID of the challenge that the entry belongs to. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The ID of the challenge that the entry belongs to." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_ChallengeEntry_GetID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_ChallengeEntry, nullptr, "GetID", nullptr, nullptr, Z_Construct_UFunction_UPico_ChallengeEntry_GetID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetID_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_ChallengeEntry_GetID_Statics::Pico_ChallengeEntry_eventGetID_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_ChallengeEntry_GetID_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetID_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_ChallengeEntry_GetID_Statics::Pico_ChallengeEntry_eventGetID_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_ChallengeEntry_GetID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_ChallengeEntry_GetID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_ChallengeEntry_GetRank_Statics
	{
		struct Pico_ChallengeEntry_eventGetRank_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_ChallengeEntry_GetRank_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_ChallengeEntry_eventGetRank_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_ChallengeEntry_GetRank_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ChallengeEntry_GetRank_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_ChallengeEntry_GetRank_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The rank of the entry. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The rank of the entry." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_ChallengeEntry_GetRank_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_ChallengeEntry, nullptr, "GetRank", nullptr, nullptr, Z_Construct_UFunction_UPico_ChallengeEntry_GetRank_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetRank_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_ChallengeEntry_GetRank_Statics::Pico_ChallengeEntry_eventGetRank_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetRank_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_ChallengeEntry_GetRank_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetRank_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_ChallengeEntry_GetRank_Statics::Pico_ChallengeEntry_eventGetRank_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_ChallengeEntry_GetRank()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_ChallengeEntry_GetRank_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_ChallengeEntry_GetScore_Statics
	{
		struct Pico_ChallengeEntry_eventGetScore_Parms
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
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UPico_ChallengeEntry_GetScore_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_ChallengeEntry_eventGetScore_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_ChallengeEntry_GetScore_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ChallengeEntry_GetScore_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_ChallengeEntry_GetScore_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The score of the entry. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The score of the entry." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_ChallengeEntry_GetScore_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_ChallengeEntry, nullptr, "GetScore", nullptr, nullptr, Z_Construct_UFunction_UPico_ChallengeEntry_GetScore_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetScore_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_ChallengeEntry_GetScore_Statics::Pico_ChallengeEntry_eventGetScore_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetScore_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_ChallengeEntry_GetScore_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetScore_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_ChallengeEntry_GetScore_Statics::Pico_ChallengeEntry_eventGetScore_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_ChallengeEntry_GetScore()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_ChallengeEntry_GetScore_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_ChallengeEntry_GetTimestamp_Statics
	{
		struct Pico_ChallengeEntry_eventGetTimestamp_Parms
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
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPico_ChallengeEntry_GetTimestamp_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_ChallengeEntry_eventGetTimestamp_Parms, ReturnValue), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_ChallengeEntry_GetTimestamp_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ChallengeEntry_GetTimestamp_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_ChallengeEntry_GetTimestamp_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The time when the entry was written. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The time when the entry was written." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_ChallengeEntry_GetTimestamp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_ChallengeEntry, nullptr, "GetTimestamp", nullptr, nullptr, Z_Construct_UFunction_UPico_ChallengeEntry_GetTimestamp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetTimestamp_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_ChallengeEntry_GetTimestamp_Statics::Pico_ChallengeEntry_eventGetTimestamp_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetTimestamp_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_ChallengeEntry_GetTimestamp_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetTimestamp_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_ChallengeEntry_GetTimestamp_Statics::Pico_ChallengeEntry_eventGetTimestamp_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_ChallengeEntry_GetTimestamp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_ChallengeEntry_GetTimestamp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_ChallengeEntry_GetUser_Statics
	{
		struct Pico_ChallengeEntry_eventGetUser_Parms
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPico_ChallengeEntry_GetUser_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_ChallengeEntry_eventGetUser_Parms, ReturnValue), Z_Construct_UClass_UPico_User_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_ChallengeEntry_GetUser_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ChallengeEntry_GetUser_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_ChallengeEntry_GetUser_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The user the entry belongs to. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The user the entry belongs to." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_ChallengeEntry_GetUser_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_ChallengeEntry, nullptr, "GetUser", nullptr, nullptr, Z_Construct_UFunction_UPico_ChallengeEntry_GetUser_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetUser_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_ChallengeEntry_GetUser_Statics::Pico_ChallengeEntry_eventGetUser_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetUser_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_ChallengeEntry_GetUser_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntry_GetUser_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_ChallengeEntry_GetUser_Statics::Pico_ChallengeEntry_eventGetUser_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_ChallengeEntry_GetUser()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_ChallengeEntry_GetUser_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_ChallengeEntry);
	UClass* Z_Construct_UClass_UPico_ChallengeEntry_NoRegister()
	{
		return UPico_ChallengeEntry::StaticClass();
	}
	struct Z_Construct_UClass_UPico_ChallengeEntry_Statics
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
	UObject* (*const Z_Construct_UClass_UPico_ChallengeEntry_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ChallengeEntry_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_ChallengeEntry_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_ChallengeEntry_GetDisplayScore, "GetDisplayScore" }, // 3509390873
		{ &Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraData, "GetExtraData" }, // 2322448263
		{ &Z_Construct_UFunction_UPico_ChallengeEntry_GetExtraDataString, "GetExtraDataString" }, // 997025346
		{ &Z_Construct_UFunction_UPico_ChallengeEntry_GetID, "GetID" }, // 1105228871
		{ &Z_Construct_UFunction_UPico_ChallengeEntry_GetRank, "GetRank" }, // 1885523885
		{ &Z_Construct_UFunction_UPico_ChallengeEntry_GetScore, "GetScore" }, // 2531457191
		{ &Z_Construct_UFunction_UPico_ChallengeEntry_GetTimestamp, "GetTimestamp" }, // 1594225024
		{ &Z_Construct_UFunction_UPico_ChallengeEntry_GetUser, "GetUser" }, // 2369312500
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ChallengeEntry_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_ChallengeEntry_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_ChallengeEntry class.\n" },
#endif
		{ "IncludePath", "Pico_Challenges.h" },
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_ChallengeEntry class." },
#endif
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_ChallengeEntry_Statics::NewProp_User_MetaData[] = {
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPico_ChallengeEntry_Statics::NewProp_User = { "User", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPico_ChallengeEntry, User), Z_Construct_UClass_UPico_User_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ChallengeEntry_Statics::NewProp_User_MetaData), Z_Construct_UClass_UPico_ChallengeEntry_Statics::NewProp_User_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPico_ChallengeEntry_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_ChallengeEntry_Statics::NewProp_User,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_ChallengeEntry_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_ChallengeEntry>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_ChallengeEntry_Statics::ClassParams = {
		&UPico_ChallengeEntry::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPico_ChallengeEntry_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ChallengeEntry_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ChallengeEntry_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_ChallengeEntry_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ChallengeEntry_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPico_ChallengeEntry()
	{
		if (!Z_Registration_Info_UClass_UPico_ChallengeEntry.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_ChallengeEntry.OuterSingleton, Z_Construct_UClass_UPico_ChallengeEntry_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_ChallengeEntry.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_ChallengeEntry>()
	{
		return UPico_ChallengeEntry::StaticClass();
	}
	UPico_ChallengeEntry::UPico_ChallengeEntry(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_ChallengeEntry);
	UPico_ChallengeEntry::~UPico_ChallengeEntry() {}
	DEFINE_FUNCTION(UPico_ChallengeEntryArray::execGetTotalCount)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetTotalCount();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_ChallengeEntryArray::execHasPreviousPage)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->HasPreviousPage();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_ChallengeEntryArray::execHasNextPage)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->HasNextPage();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_ChallengeEntryArray::execGetSize)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetSize();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_ChallengeEntryArray::execGetElement)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPico_ChallengeEntry**)Z_Param__Result=P_THIS->GetElement(Z_Param_Index);
		P_NATIVE_END;
	}
	void UPico_ChallengeEntryArray::StaticRegisterNativesUPico_ChallengeEntryArray()
	{
		UClass* Class = UPico_ChallengeEntryArray::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetElement", &UPico_ChallengeEntryArray::execGetElement },
			{ "GetSize", &UPico_ChallengeEntryArray::execGetSize },
			{ "GetTotalCount", &UPico_ChallengeEntryArray::execGetTotalCount },
			{ "HasNextPage", &UPico_ChallengeEntryArray::execHasNextPage },
			{ "HasPreviousPage", &UPico_ChallengeEntryArray::execHasPreviousPage },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_ChallengeEntryArray_GetElement_Statics
	{
		struct Pico_ChallengeEntryArray_eventGetElement_Parms
		{
			int32 Index;
			UPico_ChallengeEntry* ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_ChallengeEntryArray_GetElement_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_ChallengeEntryArray_eventGetElement_Parms, Index), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPico_ChallengeEntryArray_GetElement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_ChallengeEntryArray_eventGetElement_Parms, ReturnValue), Z_Construct_UClass_UPico_ChallengeEntry_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_ChallengeEntryArray_GetElement_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ChallengeEntryArray_GetElement_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ChallengeEntryArray_GetElement_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_ChallengeEntryArray_GetElement_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Entry Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get ChallengeEntryArray element form Index.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get ChallengeEntryArray element form Index." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_ChallengeEntryArray_GetElement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_ChallengeEntryArray, nullptr, "GetElement", nullptr, nullptr, Z_Construct_UFunction_UPico_ChallengeEntryArray_GetElement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntryArray_GetElement_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_ChallengeEntryArray_GetElement_Statics::Pico_ChallengeEntryArray_eventGetElement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntryArray_GetElement_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_ChallengeEntryArray_GetElement_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntryArray_GetElement_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_ChallengeEntryArray_GetElement_Statics::Pico_ChallengeEntryArray_eventGetElement_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_ChallengeEntryArray_GetElement()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_ChallengeEntryArray_GetElement_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_ChallengeEntryArray_GetSize_Statics
	{
		struct Pico_ChallengeEntryArray_eventGetSize_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_ChallengeEntryArray_GetSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_ChallengeEntryArray_eventGetSize_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_ChallengeEntryArray_GetSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ChallengeEntryArray_GetSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_ChallengeEntryArray_GetSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Entry Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get the size of ChallengeEntryArray .*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get the size of ChallengeEntryArray ." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_ChallengeEntryArray_GetSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_ChallengeEntryArray, nullptr, "GetSize", nullptr, nullptr, Z_Construct_UFunction_UPico_ChallengeEntryArray_GetSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntryArray_GetSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_ChallengeEntryArray_GetSize_Statics::Pico_ChallengeEntryArray_eventGetSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntryArray_GetSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_ChallengeEntryArray_GetSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntryArray_GetSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_ChallengeEntryArray_GetSize_Statics::Pico_ChallengeEntryArray_eventGetSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_ChallengeEntryArray_GetSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_ChallengeEntryArray_GetSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_ChallengeEntryArray_GetTotalCount_Statics
	{
		struct Pico_ChallengeEntryArray_eventGetTotalCount_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_ChallengeEntryArray_GetTotalCount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_ChallengeEntryArray_eventGetTotalCount_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_ChallengeEntryArray_GetTotalCount_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ChallengeEntryArray_GetTotalCount_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_ChallengeEntryArray_GetTotalCount_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Entry Array" },
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_ChallengeEntryArray_GetTotalCount_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_ChallengeEntryArray, nullptr, "GetTotalCount", nullptr, nullptr, Z_Construct_UFunction_UPico_ChallengeEntryArray_GetTotalCount_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntryArray_GetTotalCount_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_ChallengeEntryArray_GetTotalCount_Statics::Pico_ChallengeEntryArray_eventGetTotalCount_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntryArray_GetTotalCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_ChallengeEntryArray_GetTotalCount_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntryArray_GetTotalCount_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_ChallengeEntryArray_GetTotalCount_Statics::Pico_ChallengeEntryArray_eventGetTotalCount_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_ChallengeEntryArray_GetTotalCount()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_ChallengeEntryArray_GetTotalCount_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_ChallengeEntryArray_HasNextPage_Statics
	{
		struct Pico_ChallengeEntryArray_eventHasNextPage_Parms
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
	void Z_Construct_UFunction_UPico_ChallengeEntryArray_HasNextPage_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_ChallengeEntryArray_eventHasNextPage_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_ChallengeEntryArray_HasNextPage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_ChallengeEntryArray_eventHasNextPage_Parms), &Z_Construct_UFunction_UPico_ChallengeEntryArray_HasNextPage_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_ChallengeEntryArray_HasNextPage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ChallengeEntryArray_HasNextPage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_ChallengeEntryArray_HasNextPage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Entry Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get whether the list has the next page.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get whether the list has the next page." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_ChallengeEntryArray_HasNextPage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_ChallengeEntryArray, nullptr, "HasNextPage", nullptr, nullptr, Z_Construct_UFunction_UPico_ChallengeEntryArray_HasNextPage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntryArray_HasNextPage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_ChallengeEntryArray_HasNextPage_Statics::Pico_ChallengeEntryArray_eventHasNextPage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntryArray_HasNextPage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_ChallengeEntryArray_HasNextPage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntryArray_HasNextPage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_ChallengeEntryArray_HasNextPage_Statics::Pico_ChallengeEntryArray_eventHasNextPage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_ChallengeEntryArray_HasNextPage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_ChallengeEntryArray_HasNextPage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_ChallengeEntryArray_HasPreviousPage_Statics
	{
		struct Pico_ChallengeEntryArray_eventHasPreviousPage_Parms
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
	void Z_Construct_UFunction_UPico_ChallengeEntryArray_HasPreviousPage_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_ChallengeEntryArray_eventHasPreviousPage_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_ChallengeEntryArray_HasPreviousPage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_ChallengeEntryArray_eventHasPreviousPage_Parms), &Z_Construct_UFunction_UPico_ChallengeEntryArray_HasPreviousPage_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_ChallengeEntryArray_HasPreviousPage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ChallengeEntryArray_HasPreviousPage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_ChallengeEntryArray_HasPreviousPage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Entry Array" },
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_ChallengeEntryArray_HasPreviousPage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_ChallengeEntryArray, nullptr, "HasPreviousPage", nullptr, nullptr, Z_Construct_UFunction_UPico_ChallengeEntryArray_HasPreviousPage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntryArray_HasPreviousPage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_ChallengeEntryArray_HasPreviousPage_Statics::Pico_ChallengeEntryArray_eventHasPreviousPage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntryArray_HasPreviousPage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_ChallengeEntryArray_HasPreviousPage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeEntryArray_HasPreviousPage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_ChallengeEntryArray_HasPreviousPage_Statics::Pico_ChallengeEntryArray_eventHasPreviousPage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_ChallengeEntryArray_HasPreviousPage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_ChallengeEntryArray_HasPreviousPage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_ChallengeEntryArray);
	UClass* Z_Construct_UClass_UPico_ChallengeEntryArray_NoRegister()
	{
		return UPico_ChallengeEntryArray::StaticClass();
	}
	struct Z_Construct_UClass_UPico_ChallengeEntryArray_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ChallengeEntryArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChallengeEntryArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ChallengeEntryArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_ChallengeEntryArray_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ChallengeEntryArray_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_ChallengeEntryArray_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_ChallengeEntryArray_GetElement, "GetElement" }, // 4111644338
		{ &Z_Construct_UFunction_UPico_ChallengeEntryArray_GetSize, "GetSize" }, // 3822244205
		{ &Z_Construct_UFunction_UPico_ChallengeEntryArray_GetTotalCount, "GetTotalCount" }, // 1854382435
		{ &Z_Construct_UFunction_UPico_ChallengeEntryArray_HasNextPage, "HasNextPage" }, // 3597111543
		{ &Z_Construct_UFunction_UPico_ChallengeEntryArray_HasPreviousPage, "HasPreviousPage" }, // 3173547861
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ChallengeEntryArray_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_ChallengeEntryArray_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_ChallengeEntryArray class.\n" },
#endif
		{ "IncludePath", "Pico_Challenges.h" },
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_ChallengeEntryArray class." },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPico_ChallengeEntryArray_Statics::NewProp_ChallengeEntryArray_Inner = { "ChallengeEntryArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UPico_ChallengeEntry_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_ChallengeEntryArray_Statics::NewProp_ChallengeEntryArray_MetaData[] = {
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPico_ChallengeEntryArray_Statics::NewProp_ChallengeEntryArray = { "ChallengeEntryArray", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPico_ChallengeEntryArray, ChallengeEntryArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ChallengeEntryArray_Statics::NewProp_ChallengeEntryArray_MetaData), Z_Construct_UClass_UPico_ChallengeEntryArray_Statics::NewProp_ChallengeEntryArray_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPico_ChallengeEntryArray_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_ChallengeEntryArray_Statics::NewProp_ChallengeEntryArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_ChallengeEntryArray_Statics::NewProp_ChallengeEntryArray,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_ChallengeEntryArray_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_ChallengeEntryArray>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_ChallengeEntryArray_Statics::ClassParams = {
		&UPico_ChallengeEntryArray::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPico_ChallengeEntryArray_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ChallengeEntryArray_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ChallengeEntryArray_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_ChallengeEntryArray_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ChallengeEntryArray_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPico_ChallengeEntryArray()
	{
		if (!Z_Registration_Info_UClass_UPico_ChallengeEntryArray.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_ChallengeEntryArray.OuterSingleton, Z_Construct_UClass_UPico_ChallengeEntryArray_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_ChallengeEntryArray.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_ChallengeEntryArray>()
	{
		return UPico_ChallengeEntryArray::StaticClass();
	}
	UPico_ChallengeEntryArray::UPico_ChallengeEntryArray(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_ChallengeEntryArray);
	UPico_ChallengeEntryArray::~UPico_ChallengeEntryArray() {}
	DEFINE_FUNCTION(UPico_ChallengeArray::execGetTotalCount)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetTotalCount();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_ChallengeArray::execHasPreviousPage)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->HasPreviousPage();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_ChallengeArray::execHasNextPage)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->HasNextPage();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_ChallengeArray::execGetSize)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetSize();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_ChallengeArray::execGetElement)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPico_Challenge**)Z_Param__Result=P_THIS->GetElement(Z_Param_Index);
		P_NATIVE_END;
	}
	void UPico_ChallengeArray::StaticRegisterNativesUPico_ChallengeArray()
	{
		UClass* Class = UPico_ChallengeArray::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetElement", &UPico_ChallengeArray::execGetElement },
			{ "GetSize", &UPico_ChallengeArray::execGetSize },
			{ "GetTotalCount", &UPico_ChallengeArray::execGetTotalCount },
			{ "HasNextPage", &UPico_ChallengeArray::execHasNextPage },
			{ "HasPreviousPage", &UPico_ChallengeArray::execHasPreviousPage },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_ChallengeArray_GetElement_Statics
	{
		struct Pico_ChallengeArray_eventGetElement_Parms
		{
			int32 Index;
			UPico_Challenge* ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_ChallengeArray_GetElement_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_ChallengeArray_eventGetElement_Parms, Index), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPico_ChallengeArray_GetElement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_ChallengeArray_eventGetElement_Parms, ReturnValue), Z_Construct_UClass_UPico_Challenge_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_ChallengeArray_GetElement_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ChallengeArray_GetElement_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ChallengeArray_GetElement_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_ChallengeArray_GetElement_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get Challenge Array element form Index.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get Challenge Array element form Index." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_ChallengeArray_GetElement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_ChallengeArray, nullptr, "GetElement", nullptr, nullptr, Z_Construct_UFunction_UPico_ChallengeArray_GetElement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeArray_GetElement_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_ChallengeArray_GetElement_Statics::Pico_ChallengeArray_eventGetElement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeArray_GetElement_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_ChallengeArray_GetElement_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeArray_GetElement_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_ChallengeArray_GetElement_Statics::Pico_ChallengeArray_eventGetElement_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_ChallengeArray_GetElement()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_ChallengeArray_GetElement_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_ChallengeArray_GetSize_Statics
	{
		struct Pico_ChallengeArray_eventGetSize_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_ChallengeArray_GetSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_ChallengeArray_eventGetSize_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_ChallengeArray_GetSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ChallengeArray_GetSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_ChallengeArray_GetSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get the size of Challenge Array .*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get the size of Challenge Array ." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_ChallengeArray_GetSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_ChallengeArray, nullptr, "GetSize", nullptr, nullptr, Z_Construct_UFunction_UPico_ChallengeArray_GetSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeArray_GetSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_ChallengeArray_GetSize_Statics::Pico_ChallengeArray_eventGetSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeArray_GetSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_ChallengeArray_GetSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeArray_GetSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_ChallengeArray_GetSize_Statics::Pico_ChallengeArray_eventGetSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_ChallengeArray_GetSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_ChallengeArray_GetSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_ChallengeArray_GetTotalCount_Statics
	{
		struct Pico_ChallengeArray_eventGetTotalCount_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_ChallengeArray_GetTotalCount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_ChallengeArray_eventGetTotalCount_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_ChallengeArray_GetTotalCount_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ChallengeArray_GetTotalCount_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_ChallengeArray_GetTotalCount_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Array" },
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_ChallengeArray_GetTotalCount_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_ChallengeArray, nullptr, "GetTotalCount", nullptr, nullptr, Z_Construct_UFunction_UPico_ChallengeArray_GetTotalCount_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeArray_GetTotalCount_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_ChallengeArray_GetTotalCount_Statics::Pico_ChallengeArray_eventGetTotalCount_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeArray_GetTotalCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_ChallengeArray_GetTotalCount_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeArray_GetTotalCount_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_ChallengeArray_GetTotalCount_Statics::Pico_ChallengeArray_eventGetTotalCount_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_ChallengeArray_GetTotalCount()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_ChallengeArray_GetTotalCount_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_ChallengeArray_HasNextPage_Statics
	{
		struct Pico_ChallengeArray_eventHasNextPage_Parms
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
	void Z_Construct_UFunction_UPico_ChallengeArray_HasNextPage_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_ChallengeArray_eventHasNextPage_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_ChallengeArray_HasNextPage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_ChallengeArray_eventHasNextPage_Parms), &Z_Construct_UFunction_UPico_ChallengeArray_HasNextPage_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_ChallengeArray_HasNextPage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ChallengeArray_HasNextPage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_ChallengeArray_HasNextPage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get whether the list has the next page.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get whether the list has the next page." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_ChallengeArray_HasNextPage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_ChallengeArray, nullptr, "HasNextPage", nullptr, nullptr, Z_Construct_UFunction_UPico_ChallengeArray_HasNextPage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeArray_HasNextPage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_ChallengeArray_HasNextPage_Statics::Pico_ChallengeArray_eventHasNextPage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeArray_HasNextPage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_ChallengeArray_HasNextPage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeArray_HasNextPage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_ChallengeArray_HasNextPage_Statics::Pico_ChallengeArray_eventHasNextPage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_ChallengeArray_HasNextPage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_ChallengeArray_HasNextPage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_ChallengeArray_HasPreviousPage_Statics
	{
		struct Pico_ChallengeArray_eventHasPreviousPage_Parms
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
	void Z_Construct_UFunction_UPico_ChallengeArray_HasPreviousPage_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_ChallengeArray_eventHasPreviousPage_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_ChallengeArray_HasPreviousPage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_ChallengeArray_eventHasPreviousPage_Parms), &Z_Construct_UFunction_UPico_ChallengeArray_HasPreviousPage_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_ChallengeArray_HasPreviousPage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ChallengeArray_HasPreviousPage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_ChallengeArray_HasPreviousPage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Challenges|Challenge Array" },
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_ChallengeArray_HasPreviousPage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_ChallengeArray, nullptr, "HasPreviousPage", nullptr, nullptr, Z_Construct_UFunction_UPico_ChallengeArray_HasPreviousPage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeArray_HasPreviousPage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_ChallengeArray_HasPreviousPage_Statics::Pico_ChallengeArray_eventHasPreviousPage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeArray_HasPreviousPage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_ChallengeArray_HasPreviousPage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ChallengeArray_HasPreviousPage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_ChallengeArray_HasPreviousPage_Statics::Pico_ChallengeArray_eventHasPreviousPage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_ChallengeArray_HasPreviousPage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_ChallengeArray_HasPreviousPage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_ChallengeArray);
	UClass* Z_Construct_UClass_UPico_ChallengeArray_NoRegister()
	{
		return UPico_ChallengeArray::StaticClass();
	}
	struct Z_Construct_UClass_UPico_ChallengeArray_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ChallengeArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChallengeArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ChallengeArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_ChallengeArray_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ChallengeArray_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_ChallengeArray_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_ChallengeArray_GetElement, "GetElement" }, // 1640717324
		{ &Z_Construct_UFunction_UPico_ChallengeArray_GetSize, "GetSize" }, // 2152697747
		{ &Z_Construct_UFunction_UPico_ChallengeArray_GetTotalCount, "GetTotalCount" }, // 4249997406
		{ &Z_Construct_UFunction_UPico_ChallengeArray_HasNextPage, "HasNextPage" }, // 2434334656
		{ &Z_Construct_UFunction_UPico_ChallengeArray_HasPreviousPage, "HasPreviousPage" }, // 1783893555
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ChallengeArray_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_ChallengeArray_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_ChallengeArray class.\n" },
#endif
		{ "IncludePath", "Pico_Challenges.h" },
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_ChallengeArray class." },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPico_ChallengeArray_Statics::NewProp_ChallengeArray_Inner = { "ChallengeArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UPico_Challenge_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_ChallengeArray_Statics::NewProp_ChallengeArray_MetaData[] = {
		{ "ModuleRelativePath", "Public/Pico_Challenges.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPico_ChallengeArray_Statics::NewProp_ChallengeArray = { "ChallengeArray", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPico_ChallengeArray, ChallengeArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ChallengeArray_Statics::NewProp_ChallengeArray_MetaData), Z_Construct_UClass_UPico_ChallengeArray_Statics::NewProp_ChallengeArray_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPico_ChallengeArray_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_ChallengeArray_Statics::NewProp_ChallengeArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_ChallengeArray_Statics::NewProp_ChallengeArray,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_ChallengeArray_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_ChallengeArray>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_ChallengeArray_Statics::ClassParams = {
		&UPico_ChallengeArray::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPico_ChallengeArray_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ChallengeArray_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ChallengeArray_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_ChallengeArray_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ChallengeArray_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPico_ChallengeArray()
	{
		if (!Z_Registration_Info_UClass_UPico_ChallengeArray.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_ChallengeArray.OuterSingleton, Z_Construct_UClass_UPico_ChallengeArray_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_ChallengeArray.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_ChallengeArray>()
	{
		return UPico_ChallengeArray::StaticClass();
	}
	UPico_ChallengeArray::UPico_ChallengeArray(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_ChallengeArray);
	UPico_ChallengeArray::~UPico_ChallengeArray() {}
	struct Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Challenges_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Challenges_h_Statics::ScriptStructInfo[] = {
		{ FPico_ChallengeOptions::StaticStruct, Z_Construct_UScriptStruct_FPico_ChallengeOptions_Statics::NewStructOps, TEXT("Pico_ChallengeOptions"), &Z_Registration_Info_UScriptStruct_Pico_ChallengeOptions, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPico_ChallengeOptions), 531778955U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Challenges_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOnlinePicoChallengesFunction, UOnlinePicoChallengesFunction::StaticClass, TEXT("UOnlinePicoChallengesFunction"), &Z_Registration_Info_UClass_UOnlinePicoChallengesFunction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOnlinePicoChallengesFunction), 1720637652U) },
		{ Z_Construct_UClass_UPico_Challenge, UPico_Challenge::StaticClass, TEXT("UPico_Challenge"), &Z_Registration_Info_UClass_UPico_Challenge, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_Challenge), 2453600705U) },
		{ Z_Construct_UClass_UPico_ChallengeEntry, UPico_ChallengeEntry::StaticClass, TEXT("UPico_ChallengeEntry"), &Z_Registration_Info_UClass_UPico_ChallengeEntry, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_ChallengeEntry), 3164830201U) },
		{ Z_Construct_UClass_UPico_ChallengeEntryArray, UPico_ChallengeEntryArray::StaticClass, TEXT("UPico_ChallengeEntryArray"), &Z_Registration_Info_UClass_UPico_ChallengeEntryArray, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_ChallengeEntryArray), 260179907U) },
		{ Z_Construct_UClass_UPico_ChallengeArray, UPico_ChallengeArray::StaticClass, TEXT("UPico_ChallengeArray"), &Z_Registration_Info_UClass_UPico_ChallengeArray, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_ChallengeArray), 4207054954U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Challenges_h_3355960782(TEXT("/Script/OnlineSubsystemPico"),
		Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Challenges_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Challenges_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Challenges_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Challenges_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
