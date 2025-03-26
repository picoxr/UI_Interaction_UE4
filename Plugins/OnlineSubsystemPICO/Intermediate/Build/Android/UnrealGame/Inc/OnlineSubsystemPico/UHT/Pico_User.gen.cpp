// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../OnlineSubsystemPico/Public/Pico_User.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePico_User() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoUserFunction();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoUserFunction_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_EntitlementCheckResult();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_EntitlementCheckResult_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_OrgScopedID();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_OrgScopedID_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_PermissionResult();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_PermissionResult_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_Room_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_User();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_User_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_UserAndRoom();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_UserAndRoom_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_UserAndRoomArray();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_UserAndRoomArray_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_UserArray();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_UserArray_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_UserRelationResult();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_UserRelationResult_NoRegister();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_EUserGender();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_EUserPresenceStatus();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_EUserRelationType();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemPico();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetLoggedInUserFriendsAndRooms_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_UserAndRoomArray* UserAndRoomArray;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_UserAndRoomArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetLoggedInUserFriendsAndRooms_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetLoggedInUserFriendsAndRooms_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetLoggedInUserFriendsAndRooms_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature_Statics::NewProp_UserAndRoomArray = { "UserAndRoomArray", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetLoggedInUserFriendsAndRooms_Parms, UserAndRoomArray), Z_Construct_UClass_UPico_UserAndRoomArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature_Statics::NewProp_UserAndRoomArray,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetLoggedInUserFriendsAndRooms__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetLoggedInUserFriendsAndRooms_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetLoggedInUserFriendsAndRooms_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetLoggedInUserFriendsAndRooms_DelegateWrapper(const FScriptDelegate& GetLoggedInUserFriendsAndRooms, bool bIsError, const FString& ErrorMessage, UPico_UserAndRoomArray* UserAndRoomArray)
{
	struct _Script_OnlineSubsystemPico_eventGetLoggedInUserFriendsAndRooms_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_UserAndRoomArray* UserAndRoomArray;
	};
	_Script_OnlineSubsystemPico_eventGetLoggedInUserFriendsAndRooms_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.UserAndRoomArray=UserAndRoomArray;
	GetLoggedInUserFriendsAndRooms.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetNextUserAndRoomArrayPage_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_UserAndRoomArray* UserAndRoomArray;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_UserAndRoomArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetNextUserAndRoomArrayPage_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetNextUserAndRoomArrayPage_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetNextUserAndRoomArrayPage_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature_Statics::NewProp_UserAndRoomArray = { "UserAndRoomArray", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetNextUserAndRoomArrayPage_Parms, UserAndRoomArray), Z_Construct_UClass_UPico_UserAndRoomArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature_Statics::NewProp_UserAndRoomArray,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_User.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetNextUserAndRoomArrayPage__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetNextUserAndRoomArrayPage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetNextUserAndRoomArrayPage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetNextUserAndRoomArrayPage_DelegateWrapper(const FScriptDelegate& GetNextUserAndRoomArrayPage, bool bIsError, const FString& ErrorMessage, UPico_UserAndRoomArray* UserAndRoomArray)
{
	struct _Script_OnlineSubsystemPico_eventGetNextUserAndRoomArrayPage_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_UserAndRoomArray* UserAndRoomArray;
	};
	_Script_OnlineSubsystemPico_eventGetNextUserAndRoomArrayPage_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.UserAndRoomArray=UserAndRoomArray;
	GetNextUserAndRoomArrayPage.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetLoggedInUserFriends_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_UserArray* UserArray;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_UserArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetLoggedInUserFriends_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetLoggedInUserFriends_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetLoggedInUserFriends_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature_Statics::NewProp_UserArray = { "UserArray", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetLoggedInUserFriends_Parms, UserArray), Z_Construct_UClass_UPico_UserArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature_Statics::NewProp_UserArray,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_User.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetLoggedInUserFriends__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetLoggedInUserFriends_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetLoggedInUserFriends_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetLoggedInUserFriends_DelegateWrapper(const FScriptDelegate& GetLoggedInUserFriends, bool bIsError, const FString& ErrorMessage, UPico_UserArray* UserArray)
{
	struct _Script_OnlineSubsystemPico_eventGetLoggedInUserFriends_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_UserArray* UserArray;
	};
	_Script_OnlineSubsystemPico_eventGetLoggedInUserFriends_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.UserArray=UserArray;
	GetLoggedInUserFriends.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetNextUserPage_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_UserArray* UserArray;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_UserArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetNextUserPage_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetNextUserPage_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetNextUserPage_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature_Statics::NewProp_UserArray = { "UserArray", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetNextUserPage_Parms, UserArray), Z_Construct_UClass_UPico_UserArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature_Statics::NewProp_UserArray,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_User.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetNextUserPage__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetNextUserPage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetNextUserPage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetNextUserPage_DelegateWrapper(const FScriptDelegate& GetNextUserPage, bool bIsError, const FString& ErrorMessage, UPico_UserArray* UserArray)
{
	struct _Script_OnlineSubsystemPico_eventGetNextUserPage_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_UserArray* UserArray;
	};
	_Script_OnlineSubsystemPico_eventGetNextUserPage_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.UserArray=UserArray;
	GetNextUserPage.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetLoginUser_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_User* User;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_User;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetLoginUser_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetLoginUser_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetLoginUser_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature_Statics::NewProp_User = { "User", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetLoginUser_Parms, User), Z_Construct_UClass_UPico_User_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature_Statics::NewProp_User,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_User.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetLoginUser__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetLoginUser_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetLoginUser_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetLoginUser_DelegateWrapper(const FScriptDelegate& GetLoginUser, bool bIsError, const FString& ErrorMessage, UPico_User* User)
{
	struct _Script_OnlineSubsystemPico_eventGetLoginUser_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_User* User;
	};
	_Script_OnlineSubsystemPico_eventGetLoginUser_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.User=User;
	GetLoginUser.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetUserInfo_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_User* User;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_User;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetUserInfo_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetUserInfo_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetUserInfo_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature_Statics::NewProp_User = { "User", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetUserInfo_Parms, User), Z_Construct_UClass_UPico_User_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature_Statics::NewProp_User,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_User.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetUserInfo__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetUserInfo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetUserInfo_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetUserInfo_DelegateWrapper(const FScriptDelegate& GetUserInfo, bool bIsError, const FString& ErrorMessage, UPico_User* User)
{
	struct _Script_OnlineSubsystemPico_eventGetUserInfo_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_User* User;
	};
	_Script_OnlineSubsystemPico_eventGetUserInfo_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.User=User;
	GetUserInfo.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetPermissionResult_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_PermissionResult* PermissionResult;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PermissionResult;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetPermissionResult_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetPermissionResult_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetPermissionResult_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature_Statics::NewProp_PermissionResult = { "PermissionResult", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetPermissionResult_Parms, PermissionResult), Z_Construct_UClass_UPico_PermissionResult_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature_Statics::NewProp_PermissionResult,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_User.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetPermissionResult__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetPermissionResult_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetPermissionResult_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetPermissionResult_DelegateWrapper(const FScriptDelegate& GetPermissionResult, bool bIsError, const FString& ErrorMessage, UPico_PermissionResult* PermissionResult)
{
	struct _Script_OnlineSubsystemPico_eventGetPermissionResult_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_PermissionResult* PermissionResult;
	};
	_Script_OnlineSubsystemPico_eventGetPermissionResult_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.PermissionResult=PermissionResult;
	GetPermissionResult.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetAccessTokenResult_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			FString AccessToken;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AccessToken_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AccessToken;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetAccessTokenResult_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetAccessTokenResult_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetAccessTokenResult_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::NewProp_AccessToken_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::NewProp_AccessToken = { "AccessToken", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetAccessTokenResult_Parms, AccessToken), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::NewProp_AccessToken_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::NewProp_AccessToken_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::NewProp_AccessToken,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_User.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetAccessTokenResult__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetAccessTokenResult_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetAccessTokenResult_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetAccessTokenResult_DelegateWrapper(const FScriptDelegate& GetAccessTokenResult, bool bIsError, const FString& ErrorMessage, const FString& AccessToken)
{
	struct _Script_OnlineSubsystemPico_eventGetAccessTokenResult_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		FString AccessToken;
	};
	_Script_OnlineSubsystemPico_eventGetAccessTokenResult_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.AccessToken=AccessToken;
	GetAccessTokenResult.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventLaunchFriendRequestResult_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			bool bDidCancel;
			bool bDidSendRequest;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static void NewProp_bDidCancel_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDidCancel;
		static void NewProp_bDidSendRequest_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDidSendRequest;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventLaunchFriendRequestResult_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventLaunchFriendRequestResult_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventLaunchFriendRequestResult_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::NewProp_bDidCancel_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventLaunchFriendRequestResult_Parms*)Obj)->bDidCancel = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::NewProp_bDidCancel = { "bDidCancel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventLaunchFriendRequestResult_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::NewProp_bDidCancel_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::NewProp_bDidSendRequest_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventLaunchFriendRequestResult_Parms*)Obj)->bDidSendRequest = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::NewProp_bDidSendRequest = { "bDidSendRequest", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventLaunchFriendRequestResult_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::NewProp_bDidSendRequest_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::NewProp_bDidCancel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::NewProp_bDidSendRequest,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_User.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "LaunchFriendRequestResult__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventLaunchFriendRequestResult_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventLaunchFriendRequestResult_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FLaunchFriendRequestResult_DelegateWrapper(const FScriptDelegate& LaunchFriendRequestResult, bool bIsError, const FString& ErrorMessage, bool bDidCancel, bool bDidSendRequest)
{
	struct _Script_OnlineSubsystemPico_eventLaunchFriendRequestResult_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		bool bDidCancel;
		bool bDidSendRequest;
	};
	_Script_OnlineSubsystemPico_eventLaunchFriendRequestResult_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.bDidCancel=bDidCancel ? true : false;
	Parms.bDidSendRequest=bDidSendRequest ? true : false;
	LaunchFriendRequestResult.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetUserRelationResult_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_UserRelationResult* UserRelationResult;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_UserRelationResult;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetUserRelationResult_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetUserRelationResult_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetUserRelationResult_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature_Statics::NewProp_UserRelationResult = { "UserRelationResult", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetUserRelationResult_Parms, UserRelationResult), Z_Construct_UClass_UPico_UserRelationResult_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature_Statics::NewProp_UserRelationResult,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_User.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetUserRelationResult__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetUserRelationResult_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetUserRelationResult_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetUserRelationResult_DelegateWrapper(const FScriptDelegate& GetUserRelationResult, bool bIsError, const FString& ErrorMessage, UPico_UserRelationResult* UserRelationResult)
{
	struct _Script_OnlineSubsystemPico_eventGetUserRelationResult_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_UserRelationResult* UserRelationResult;
	};
	_Script_OnlineSubsystemPico_eventGetUserRelationResult_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.UserRelationResult=UserRelationResult;
	GetUserRelationResult.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventEntitlementCheckResult_Parms
		{
			bool bIsError;
			int32 ErrorCode;
			FString ErrorMessage;
			UPico_EntitlementCheckResult* EntitlementCheck;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ErrorCode;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_EntitlementCheck;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventEntitlementCheckResult_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventEntitlementCheckResult_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::NewProp_ErrorCode = { "ErrorCode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventEntitlementCheckResult_Parms, ErrorCode), METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventEntitlementCheckResult_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::NewProp_EntitlementCheck = { "EntitlementCheck", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventEntitlementCheckResult_Parms, EntitlementCheck), Z_Construct_UClass_UPico_EntitlementCheckResult_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::NewProp_ErrorCode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::NewProp_EntitlementCheck,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_User.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "EntitlementCheckResult__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventEntitlementCheckResult_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventEntitlementCheckResult_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FEntitlementCheckResult_DelegateWrapper(const FScriptDelegate& EntitlementCheckResult, bool bIsError, int32 ErrorCode, const FString& ErrorMessage, UPico_EntitlementCheckResult* EntitlementCheck)
{
	struct _Script_OnlineSubsystemPico_eventEntitlementCheckResult_Parms
	{
		bool bIsError;
		int32 ErrorCode;
		FString ErrorMessage;
		UPico_EntitlementCheckResult* EntitlementCheck;
	};
	_Script_OnlineSubsystemPico_eventEntitlementCheckResult_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorCode=ErrorCode;
	Parms.ErrorMessage=ErrorMessage;
	Parms.EntitlementCheck=EntitlementCheck;
	EntitlementCheckResult.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetIDToken_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			FString IDToken;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IDToken_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_IDToken;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetIDToken_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetIDToken_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetIDToken_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::NewProp_IDToken_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::NewProp_IDToken = { "IDToken", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetIDToken_Parms, IDToken), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::NewProp_IDToken_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::NewProp_IDToken_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::NewProp_IDToken,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_User.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetIDToken__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetIDToken_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetIDToken_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetIDToken_DelegateWrapper(const FScriptDelegate& GetIDToken, bool bIsError, const FString& ErrorMessage, const FString& IDToken)
{
	struct _Script_OnlineSubsystemPico_eventGetIDToken_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		FString IDToken;
	};
	_Script_OnlineSubsystemPico_eventGetIDToken_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.IDToken=IDToken;
	GetIDToken.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetOrgScopedID_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_OrgScopedID* OrgScopedID;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OrgScopedID;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetOrgScopedID_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetOrgScopedID_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetOrgScopedID_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature_Statics::NewProp_OrgScopedID = { "OrgScopedID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetOrgScopedID_Parms, OrgScopedID), Z_Construct_UClass_UPico_OrgScopedID_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature_Statics::NewProp_OrgScopedID,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_User.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetOrgScopedID__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetOrgScopedID_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetOrgScopedID_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetOrgScopedID_DelegateWrapper(const FScriptDelegate& GetOrgScopedID, bool bIsError, const FString& ErrorMessage, UPico_OrgScopedID* OrgScopedID)
{
	struct _Script_OnlineSubsystemPico_eventGetOrgScopedID_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_OrgScopedID* OrgScopedID;
	};
	_Script_OnlineSubsystemPico_eventGetOrgScopedID_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.OrgScopedID=OrgScopedID;
	GetOrgScopedID.ProcessDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UOnlinePicoUserFunction::execGetOrgScopedID)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_UserId);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_OnGetOrgScopedIDCallback);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoUserFunction::GetOrgScopedID(Z_Param_WorldContextObject,Z_Param_UserId,FGetOrgScopedID(Z_Param_OnGetOrgScopedIDCallback));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoUserFunction::execGetIDToken)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_OnGetIDTokenResultCallback);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoUserFunction::GetIDToken(Z_Param_WorldContextObject,FGetIDToken(Z_Param_OnGetIDTokenResultCallback));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoUserFunction::execEntitlementCheck)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_UBOOL(Z_Param_bKillApp);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_OnEntitlementCheckResultCallback);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoUserFunction::EntitlementCheck(Z_Param_WorldContextObject,Z_Param_bKillApp,FEntitlementCheckResult(Z_Param_OnEntitlementCheckResultCallback));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoUserFunction::execGetRelations)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_TARRAY(FString,Z_Param_UserIDs);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_OnGetUserRelationResultCallback);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoUserFunction::GetRelations(Z_Param_WorldContextObject,Z_Param_UserIDs,FGetUserRelationResult(Z_Param_OnGetUserRelationResultCallback));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoUserFunction::execGetAccessToken)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_OnGetAccessTokenResultCallback);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoUserFunction::GetAccessToken(Z_Param_WorldContextObject,FGetAccessTokenResult(Z_Param_OnGetAccessTokenResultCallback));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoUserFunction::execLaunchFriendRequestFlow)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_UserId);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_OnLaunchFriendRequestResultCallback);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoUserFunction::LaunchFriendRequestFlow(Z_Param_WorldContextObject,Z_Param_UserId,FLaunchFriendRequestResult(Z_Param_OnLaunchFriendRequestResultCallback));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoUserFunction::execRequestUserPermissions)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_TARRAY(FString,Z_Param_Permissions);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_OnGetPermissionResultCallback);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoUserFunction::RequestUserPermissions(Z_Param_WorldContextObject,Z_Param_Permissions,FGetPermissionResult(Z_Param_OnGetPermissionResultCallback));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoUserFunction::execGetAuthorizePermissions)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_OnGetPermissionResultCallback);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoUserFunction::GetAuthorizePermissions(Z_Param_WorldContextObject,FGetPermissionResult(Z_Param_OnGetPermissionResultCallback));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoUserFunction::execGetPicoUserInfo)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_UserId);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetUserInfoDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoUserFunction::GetPicoUserInfo(Z_Param_WorldContextObject,Z_Param_UserId,FGetUserInfo(Z_Param_InGetUserInfoDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoUserFunction::execGetLoginUser)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetLoginUserDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoUserFunction::GetLoginUser(Z_Param_WorldContextObject,FGetLoginUser(Z_Param_InGetLoginUserDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoUserFunction::execPicoGetNextUserPage)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_OBJECT(UPico_UserArray,Z_Param_InUserArray);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetNextUserPageDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoUserFunction::PicoGetNextUserPage(Z_Param_WorldContextObject,Z_Param_InUserArray,FGetNextUserPage(Z_Param_InGetNextUserPageDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoUserFunction::execPicoGetUserFriends)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetLoggedInUserFriendsDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoUserFunction::PicoGetUserFriends(Z_Param_WorldContextObject,FGetLoggedInUserFriends(Z_Param_InGetLoggedInUserFriendsDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoUserFunction::execPicoGetNextUserAndRoomArrayPage)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_OBJECT(UPico_UserAndRoomArray,Z_Param_InUserAndRoomArray);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetNextUserAndRoomArrayPageCallback);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoUserFunction::PicoGetNextUserAndRoomArrayPage(Z_Param_WorldContextObject,Z_Param_InUserAndRoomArray,FGetNextUserAndRoomArrayPage(Z_Param_InGetNextUserAndRoomArrayPageCallback));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoUserFunction::execPicoGetLoggedInUserAndRoom)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetLoggedInuserFriendsAndRoomsCallback);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoUserFunction::PicoGetLoggedInUserAndRoom(Z_Param_WorldContextObject,FGetLoggedInUserFriendsAndRooms(Z_Param_InGetLoggedInuserFriendsAndRoomsCallback));
		P_NATIVE_END;
	}
	void UOnlinePicoUserFunction::StaticRegisterNativesUOnlinePicoUserFunction()
	{
		UClass* Class = UOnlinePicoUserFunction::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "EntitlementCheck", &UOnlinePicoUserFunction::execEntitlementCheck },
			{ "GetAccessToken", &UOnlinePicoUserFunction::execGetAccessToken },
			{ "GetAuthorizePermissions", &UOnlinePicoUserFunction::execGetAuthorizePermissions },
			{ "GetIDToken", &UOnlinePicoUserFunction::execGetIDToken },
			{ "GetLoginUser", &UOnlinePicoUserFunction::execGetLoginUser },
			{ "GetOrgScopedID", &UOnlinePicoUserFunction::execGetOrgScopedID },
			{ "GetPicoUserInfo", &UOnlinePicoUserFunction::execGetPicoUserInfo },
			{ "GetRelations", &UOnlinePicoUserFunction::execGetRelations },
			{ "LaunchFriendRequestFlow", &UOnlinePicoUserFunction::execLaunchFriendRequestFlow },
			{ "PicoGetLoggedInUserAndRoom", &UOnlinePicoUserFunction::execPicoGetLoggedInUserAndRoom },
			{ "PicoGetNextUserAndRoomArrayPage", &UOnlinePicoUserFunction::execPicoGetNextUserAndRoomArrayPage },
			{ "PicoGetNextUserPage", &UOnlinePicoUserFunction::execPicoGetNextUserPage },
			{ "PicoGetUserFriends", &UOnlinePicoUserFunction::execPicoGetUserFriends },
			{ "RequestUserPermissions", &UOnlinePicoUserFunction::execRequestUserPermissions },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics
	{
		struct OnlinePicoUserFunction_eventEntitlementCheck_Parms
		{
			UObject* WorldContextObject;
			bool bKillApp;
			FScriptDelegate OnEntitlementCheckResultCallback;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static void NewProp_bKillApp_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bKillApp;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnEntitlementCheckResultCallback;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventEntitlementCheck_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics::NewProp_bKillApp_SetBit(void* Obj)
	{
		((OnlinePicoUserFunction_eventEntitlementCheck_Parms*)Obj)->bKillApp = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics::NewProp_bKillApp = { "bKillApp", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoUserFunction_eventEntitlementCheck_Parms), &Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics::NewProp_bKillApp_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics::NewProp_OnEntitlementCheckResultCallback = { "OnEntitlementCheckResultCallback", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventEntitlementCheck_Parms, OnEntitlementCheckResultCallback), Z_Construct_UDelegateFunction_OnlineSubsystemPico_EntitlementCheckResult__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1078026669
	void Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoUserFunction_eventEntitlementCheck_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoUserFunction_eventEntitlementCheck_Parms), &Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics::NewProp_bKillApp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics::NewProp_OnEntitlementCheckResultCallback,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets whether the player has entitlement to use the app in the current state.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"bKillApp\">Whether to kill the app in the system when the player does not have the entitlement.\n/// If the value is true, you will not get the callback result because the app is killed.\n/// </param>\n/// <param name=\"OnEntitlementCheckResultCallback\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_EntitlementCheckResult *, EntitlementCheck).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets whether the player has entitlement to use the app in the current state.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"bKillApp\">Whether to kill the app in the system when the player does not have the entitlement.\nIf the value is true, you will not get the callback result because the app is killed.\n</param>\n<param name=\"OnEntitlementCheckResultCallback\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, int, ErrorCode, const FString&, ErrorMessage, UPico_EntitlementCheckResult *, EntitlementCheck).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoUserFunction, nullptr, "EntitlementCheck", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics::OnlinePicoUserFunction_eventEntitlementCheck_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics::OnlinePicoUserFunction_eventEntitlementCheck_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoUserFunction_GetAccessToken_Statics
	{
		struct OnlinePicoUserFunction_eventGetAccessToken_Parms
		{
			UObject* WorldContextObject;
			FScriptDelegate OnGetAccessTokenResultCallback;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnGetAccessTokenResultCallback;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetAccessToken_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventGetAccessToken_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetAccessToken_Statics::NewProp_OnGetAccessTokenResultCallback = { "OnGetAccessTokenResultCallback", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventGetAccessToken_Parms, OnGetAccessTokenResultCallback), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetAccessTokenResult__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1561044683
	void Z_Construct_UFunction_UOnlinePicoUserFunction_GetAccessToken_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoUserFunction_eventGetAccessToken_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetAccessToken_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoUserFunction_eventGetAccessToken_Parms), &Z_Construct_UFunction_UOnlinePicoUserFunction_GetAccessToken_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoUserFunction_GetAccessToken_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetAccessToken_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetAccessToken_Statics::NewProp_OnGetAccessTokenResultCallback,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetAccessToken_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoUserFunction_GetAccessToken_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets current login user's AccessToken.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"OnGetAccessTokenResultCallback\">Will be executed when the request has been completed.  \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, const FString&, AccessToken).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets current login user's AccessToken.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"OnGetAccessTokenResultCallback\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, const FString&, AccessToken).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetAccessToken_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoUserFunction, nullptr, "GetAccessToken", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoUserFunction_GetAccessToken_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_GetAccessToken_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_GetAccessToken_Statics::OnlinePicoUserFunction_eventGetAccessToken_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_GetAccessToken_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoUserFunction_GetAccessToken_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_GetAccessToken_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_GetAccessToken_Statics::OnlinePicoUserFunction_eventGetAccessToken_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoUserFunction_GetAccessToken()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoUserFunction_GetAccessToken_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoUserFunction_GetAuthorizePermissions_Statics
	{
		struct OnlinePicoUserFunction_eventGetAuthorizePermissions_Parms
		{
			UObject* WorldContextObject;
			FScriptDelegate OnGetPermissionResultCallback;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnGetPermissionResultCallback;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetAuthorizePermissions_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventGetAuthorizePermissions_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetAuthorizePermissions_Statics::NewProp_OnGetPermissionResultCallback = { "OnGetPermissionResultCallback", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventGetAuthorizePermissions_Parms, OnGetPermissionResultCallback), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2400860354
	void Z_Construct_UFunction_UOnlinePicoUserFunction_GetAuthorizePermissions_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoUserFunction_eventGetAuthorizePermissions_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetAuthorizePermissions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoUserFunction_eventGetAuthorizePermissions_Parms), &Z_Construct_UFunction_UOnlinePicoUserFunction_GetAuthorizePermissions_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoUserFunction_GetAuthorizePermissions_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetAuthorizePermissions_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetAuthorizePermissions_Statics::NewProp_OnGetPermissionResultCallback,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetAuthorizePermissions_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoUserFunction_GetAuthorizePermissions_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets the authorized permissions.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"OnGetPermissionResultCallback\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_PermissionResult *, PermissionResult).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets the authorized permissions.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"OnGetPermissionResultCallback\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_PermissionResult *, PermissionResult).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetAuthorizePermissions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoUserFunction, nullptr, "GetAuthorizePermissions", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoUserFunction_GetAuthorizePermissions_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_GetAuthorizePermissions_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_GetAuthorizePermissions_Statics::OnlinePicoUserFunction_eventGetAuthorizePermissions_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_GetAuthorizePermissions_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoUserFunction_GetAuthorizePermissions_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_GetAuthorizePermissions_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_GetAuthorizePermissions_Statics::OnlinePicoUserFunction_eventGetAuthorizePermissions_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoUserFunction_GetAuthorizePermissions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoUserFunction_GetAuthorizePermissions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoUserFunction_GetIDToken_Statics
	{
		struct OnlinePicoUserFunction_eventGetIDToken_Parms
		{
			UObject* WorldContextObject;
			FScriptDelegate OnGetIDTokenResultCallback;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnGetIDTokenResultCallback;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetIDToken_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventGetIDToken_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetIDToken_Statics::NewProp_OnGetIDTokenResultCallback = { "OnGetIDTokenResultCallback", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventGetIDToken_Parms, OnGetIDTokenResultCallback), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetIDToken__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3901398114
	void Z_Construct_UFunction_UOnlinePicoUserFunction_GetIDToken_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoUserFunction_eventGetIDToken_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetIDToken_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoUserFunction_eventGetIDToken_Parms), &Z_Construct_UFunction_UOnlinePicoUserFunction_GetIDToken_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoUserFunction_GetIDToken_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetIDToken_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetIDToken_Statics::NewProp_OnGetIDTokenResultCallback,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetIDToken_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoUserFunction_GetIDToken_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Returns an ID token for this user. ID token is used for OIDC login.\n/// Read the doc for more info :\n/// China's issuer url is [https://platform-cn.picovr.com](https://platform-cn.picovr.com)\n/// The global issuer url is [https://platform-us.picovr.com](https://platform-us.picovr.com)\n/// You can use \\ref ApplicationService.GetSystemInfo to determine the region and choose the right OIDC provider.\n/// \n/// @note  User's permission is required if the user uses this app firstly.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"OnGetIDTokenResultCallback\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, const FString&, IDToken).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nReturns an ID token for this user. ID token is used for OIDC login.\nRead the doc for more info :\nChina's issuer url is [https:platform-cn.picovr.com](https:platform-cn.picovr.com)\nThe global issuer url is [https:platform-us.picovr.com](https:platform-us.picovr.com)\nYou can use \\ref ApplicationService.GetSystemInfo to determine the region and choose the right OIDC provider.\n\n@note  User's permission is required if the user uses this app firstly.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"OnGetIDTokenResultCallback\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, const FString&, IDToken).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetIDToken_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoUserFunction, nullptr, "GetIDToken", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoUserFunction_GetIDToken_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_GetIDToken_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_GetIDToken_Statics::OnlinePicoUserFunction_eventGetIDToken_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_GetIDToken_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoUserFunction_GetIDToken_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_GetIDToken_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_GetIDToken_Statics::OnlinePicoUserFunction_eventGetIDToken_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoUserFunction_GetIDToken()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoUserFunction_GetIDToken_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoUserFunction_GetLoginUser_Statics
	{
		struct OnlinePicoUserFunction_eventGetLoginUser_Parms
		{
			UObject* WorldContextObject;
			FScriptDelegate InGetLoginUserDelegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetLoginUserDelegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetLoginUser_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventGetLoginUser_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetLoginUser_Statics::NewProp_InGetLoginUserDelegate = { "InGetLoginUserDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventGetLoginUser_Parms, InGetLoginUserDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoginUser__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1205119130
	void Z_Construct_UFunction_UOnlinePicoUserFunction_GetLoginUser_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoUserFunction_eventGetLoginUser_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetLoginUser_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoUserFunction_eventGetLoginUser_Parms), &Z_Construct_UFunction_UOnlinePicoUserFunction_GetLoginUser_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoUserFunction_GetLoginUser_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetLoginUser_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetLoginUser_Statics::NewProp_InGetLoginUserDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetLoginUser_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoUserFunction_GetLoginUser_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the information about the current logged-in user.</summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"InGetLoginUserDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_User *, User).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the information about the current logged-in user.</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"InGetLoginUserDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_User *, User).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetLoginUser_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoUserFunction, nullptr, "GetLoginUser", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoUserFunction_GetLoginUser_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_GetLoginUser_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_GetLoginUser_Statics::OnlinePicoUserFunction_eventGetLoginUser_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_GetLoginUser_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoUserFunction_GetLoginUser_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_GetLoginUser_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_GetLoginUser_Statics::OnlinePicoUserFunction_eventGetLoginUser_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoUserFunction_GetLoginUser()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoUserFunction_GetLoginUser_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics
	{
		struct OnlinePicoUserFunction_eventGetOrgScopedID_Parms
		{
			UObject* WorldContextObject;
			FString UserId;
			FScriptDelegate OnGetOrgScopedIDCallback;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UserId_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_UserId;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnGetOrgScopedIDCallback;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventGetOrgScopedID_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::NewProp_UserId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::NewProp_UserId = { "UserId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventGetOrgScopedID_Parms, UserId), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::NewProp_UserId_MetaData), Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::NewProp_UserId_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::NewProp_OnGetOrgScopedIDCallback = { "OnGetOrgScopedIDCallback", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventGetOrgScopedID_Parms, OnGetOrgScopedIDCallback), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetOrgScopedID__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2892007879
	void Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoUserFunction_eventGetOrgScopedID_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoUserFunction_eventGetOrgScopedID_Parms), &Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::NewProp_UserId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::NewProp_OnGetOrgScopedIDCallback,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Query specified user's organization ID.\n/// Different user has different organization ID.\n/// The same user in the same organization's apps has the same organization ID.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"UserId\">The ID of the user.It's the open ID in current application.</param>\n/// <param name=\"OnGetOrgScopedIDCallback\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_OrgScopedID *, OrgScopedID).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nQuery specified user's organization ID.\nDifferent user has different organization ID.\nThe same user in the same organization's apps has the same organization ID.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"UserId\">The ID of the user.It's the open ID in current application.</param>\n<param name=\"OnGetOrgScopedIDCallback\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_OrgScopedID *, OrgScopedID).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoUserFunction, nullptr, "GetOrgScopedID", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::OnlinePicoUserFunction_eventGetOrgScopedID_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::OnlinePicoUserFunction_eventGetOrgScopedID_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics
	{
		struct OnlinePicoUserFunction_eventGetPicoUserInfo_Parms
		{
			UObject* WorldContextObject;
			FString UserId;
			FScriptDelegate InGetUserInfoDelegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UserId_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_UserId;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetUserInfoDelegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventGetPicoUserInfo_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::NewProp_UserId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::NewProp_UserId = { "UserId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventGetPicoUserInfo_Parms, UserId), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::NewProp_UserId_MetaData), Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::NewProp_UserId_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::NewProp_InGetUserInfoDelegate = { "InGetUserInfoDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventGetPicoUserInfo_Parms, InGetUserInfoDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserInfo__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 993958190
	void Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoUserFunction_eventGetPicoUserInfo_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoUserFunction_eventGetPicoUserInfo_Parms), &Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::NewProp_UserId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::NewProp_InGetUserInfoDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets user information by user ID.</summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"UserId\">The ID of the user.</param>    \n/// <param name=\"InGetUserInfoDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_User *, User).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets user information by user ID.</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"UserId\">The ID of the user.</param>\n<param name=\"InGetUserInfoDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_User *, User).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoUserFunction, nullptr, "GetPicoUserInfo", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::OnlinePicoUserFunction_eventGetPicoUserInfo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::OnlinePicoUserFunction_eventGetPicoUserInfo_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics
	{
		struct OnlinePicoUserFunction_eventGetRelations_Parms
		{
			UObject* WorldContextObject;
			TArray<FString> UserIDs;
			FScriptDelegate OnGetUserRelationResultCallback;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FStrPropertyParams NewProp_UserIDs_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_UserIDs;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnGetUserRelationResultCallback;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventGetRelations_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics::NewProp_UserIDs_Inner = { "UserIDs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics::NewProp_UserIDs = { "UserIDs", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventGetRelations_Parms, UserIDs), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics::NewProp_OnGetUserRelationResultCallback = { "OnGetUserRelationResultCallback", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventGetRelations_Parms, OnGetUserRelationResultCallback), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetUserRelationResult__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 205525126
	void Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoUserFunction_eventGetRelations_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoUserFunction_eventGetRelations_Parms), &Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics::NewProp_UserIDs_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics::NewProp_UserIDs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics::NewProp_OnGetUserRelationResultCallback,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets the relationship between a specified user and other user(s).\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"UserIDs\">The list of user IDs.\n/// The request queries the current logged-in user's relationship with these users.\n/// A single request can pass no more than 20 user IDs.\n/// </param>\n/// <param name=\"OnGetUserRelationResultCallback\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_UserRelationResult *, UserRelationResult).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets the relationship between a specified user and other user(s).\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"UserIDs\">The list of user IDs.\nThe request queries the current logged-in user's relationship with these users.\nA single request can pass no more than 20 user IDs.\n</param>\n<param name=\"OnGetUserRelationResultCallback\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_UserRelationResult *, UserRelationResult).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoUserFunction, nullptr, "GetRelations", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics::OnlinePicoUserFunction_eventGetRelations_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics::OnlinePicoUserFunction_eventGetRelations_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics
	{
		struct OnlinePicoUserFunction_eventLaunchFriendRequestFlow_Parms
		{
			UObject* WorldContextObject;
			FString UserId;
			FScriptDelegate OnLaunchFriendRequestResultCallback;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UserId_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_UserId;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnLaunchFriendRequestResultCallback;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventLaunchFriendRequestFlow_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::NewProp_UserId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::NewProp_UserId = { "UserId", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventLaunchFriendRequestFlow_Parms, UserId), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::NewProp_UserId_MetaData), Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::NewProp_UserId_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::NewProp_OnLaunchFriendRequestResultCallback = { "OnLaunchFriendRequestResultCallback", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventLaunchFriendRequestFlow_Parms, OnLaunchFriendRequestResultCallback), Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchFriendRequestResult__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2810225296
	void Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoUserFunction_eventLaunchFriendRequestFlow_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoUserFunction_eventLaunchFriendRequestFlow_Parms), &Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::NewProp_UserId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::NewProp_OnLaunchFriendRequestResultCallback,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Launches the flow to apply for friendship with someone.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"UserId\">The ID of the user that the friend request is sent to.</param>\n/// <param name=\"OnLaunchFriendRequestResultCallback\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, bool, bDidCancel, bool, bDidSendRequest).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nLaunches the flow to apply for friendship with someone.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"UserId\">The ID of the user that the friend request is sent to.</param>\n<param name=\"OnLaunchFriendRequestResultCallback\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, bool, bDidCancel, bool, bDidSendRequest).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoUserFunction, nullptr, "LaunchFriendRequestFlow", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::OnlinePicoUserFunction_eventLaunchFriendRequestFlow_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::OnlinePicoUserFunction_eventLaunchFriendRequestFlow_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetLoggedInUserAndRoom_Statics
	{
		struct OnlinePicoUserFunction_eventPicoGetLoggedInUserAndRoom_Parms
		{
			UObject* WorldContextObject;
			FScriptDelegate InGetLoggedInuserFriendsAndRoomsCallback;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetLoggedInuserFriendsAndRoomsCallback;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetLoggedInUserAndRoom_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventPicoGetLoggedInUserAndRoom_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetLoggedInUserAndRoom_Statics::NewProp_InGetLoggedInuserFriendsAndRoomsCallback = { "InGetLoggedInuserFriendsAndRoomsCallback", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventPicoGetLoggedInUserAndRoom_Parms, InGetLoggedInuserFriendsAndRoomsCallback), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriendsAndRooms__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3472674921
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetLoggedInUserAndRoom_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetLoggedInUserAndRoom_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetLoggedInUserAndRoom_Statics::NewProp_InGetLoggedInuserFriendsAndRoomsCallback,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetLoggedInUserAndRoom_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the friends of the logged-in user and the rooms the friends might be in. If a friend is not in any room, the 'room' field will be null.</summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"InGetLoggedInuserFriendsAndRoomsCallback\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_UserAndRoomArray *, UserAndRoomArray).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns> \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the friends of the logged-in user and the rooms the friends might be in. If a friend is not in any room, the 'room' field will be null.</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"InGetLoggedInuserFriendsAndRoomsCallback\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_UserAndRoomArray *, UserAndRoomArray).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetLoggedInUserAndRoom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoUserFunction, nullptr, "PicoGetLoggedInUserAndRoom", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetLoggedInUserAndRoom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetLoggedInUserAndRoom_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetLoggedInUserAndRoom_Statics::OnlinePicoUserFunction_eventPicoGetLoggedInUserAndRoom_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetLoggedInUserAndRoom_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetLoggedInUserAndRoom_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetLoggedInUserAndRoom_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetLoggedInUserAndRoom_Statics::OnlinePicoUserFunction_eventPicoGetLoggedInUserAndRoom_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetLoggedInUserAndRoom()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetLoggedInUserAndRoom_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserAndRoomArrayPage_Statics
	{
		struct OnlinePicoUserFunction_eventPicoGetNextUserAndRoomArrayPage_Parms
		{
			UObject* WorldContextObject;
			UPico_UserAndRoomArray* InUserAndRoomArray;
			FScriptDelegate InGetNextUserAndRoomArrayPageCallback;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InUserAndRoomArray;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetNextUserAndRoomArrayPageCallback;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserAndRoomArrayPage_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventPicoGetNextUserAndRoomArrayPage_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserAndRoomArrayPage_Statics::NewProp_InUserAndRoomArray = { "InUserAndRoomArray", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventPicoGetNextUserAndRoomArrayPage_Parms, InUserAndRoomArray), Z_Construct_UClass_UPico_UserAndRoomArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserAndRoomArrayPage_Statics::NewProp_InGetNextUserAndRoomArrayPageCallback = { "InGetNextUserAndRoomArrayPageCallback", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventPicoGetNextUserAndRoomArrayPage_Parms, InGetNextUserAndRoomArrayPageCallback), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserAndRoomArrayPage__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2463536799
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserAndRoomArrayPage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserAndRoomArrayPage_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserAndRoomArrayPage_Statics::NewProp_InUserAndRoomArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserAndRoomArrayPage_Statics::NewProp_InGetNextUserAndRoomArrayPageCallback,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserAndRoomArrayPage_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the friend list of the current user.</summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"InUserAndRoomArray\">The current object of user and room array.</param>    \n/// <param name=\"InGetNextUserAndRoomArrayPageCallback\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_UserAndRoomArray *, UserAndRoomArray).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the friend list of the current user.</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"InUserAndRoomArray\">The current object of user and room array.</param>\n<param name=\"InGetNextUserAndRoomArrayPageCallback\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_UserAndRoomArray *, UserAndRoomArray).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserAndRoomArrayPage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoUserFunction, nullptr, "PicoGetNextUserAndRoomArrayPage", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserAndRoomArrayPage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserAndRoomArrayPage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserAndRoomArrayPage_Statics::OnlinePicoUserFunction_eventPicoGetNextUserAndRoomArrayPage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserAndRoomArrayPage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserAndRoomArrayPage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserAndRoomArrayPage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserAndRoomArrayPage_Statics::OnlinePicoUserFunction_eventPicoGetNextUserAndRoomArrayPage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserAndRoomArrayPage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserAndRoomArrayPage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserPage_Statics
	{
		struct OnlinePicoUserFunction_eventPicoGetNextUserPage_Parms
		{
			UObject* WorldContextObject;
			UPico_UserArray* InUserArray;
			FScriptDelegate InGetNextUserPageDelegate;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InUserArray;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetNextUserPageDelegate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserPage_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventPicoGetNextUserPage_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserPage_Statics::NewProp_InUserArray = { "InUserArray", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventPicoGetNextUserPage_Parms, InUserArray), Z_Construct_UClass_UPico_UserArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserPage_Statics::NewProp_InGetNextUserPageDelegate = { "InGetNextUserPageDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventPicoGetNextUserPage_Parms, InGetNextUserPageDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextUserPage__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2193561904
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserPage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserPage_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserPage_Statics::NewProp_InUserArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserPage_Statics::NewProp_InGetNextUserPageDelegate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserPage_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the next page of a user list.</summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"InUserArray\">The current object of user array.</param>    \n/// <param name=\"InGetNextUserPageDelegate\">Will be executed when the request has been completed.   \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_UserArray *, UserArray).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the next page of a user list.</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"InUserArray\">The current object of user array.</param>\n<param name=\"InGetNextUserPageDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_UserArray *, UserArray).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserPage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoUserFunction, nullptr, "PicoGetNextUserPage", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserPage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserPage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserPage_Statics::OnlinePicoUserFunction_eventPicoGetNextUserPage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserPage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserPage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserPage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserPage_Statics::OnlinePicoUserFunction_eventPicoGetNextUserPage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserPage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserPage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetUserFriends_Statics
	{
		struct OnlinePicoUserFunction_eventPicoGetUserFriends_Parms
		{
			UObject* WorldContextObject;
			FScriptDelegate InGetLoggedInUserFriendsDelegate;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetLoggedInUserFriendsDelegate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetUserFriends_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventPicoGetUserFriends_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetUserFriends_Statics::NewProp_InGetLoggedInUserFriendsDelegate = { "InGetLoggedInUserFriendsDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventPicoGetUserFriends_Parms, InGetLoggedInUserFriendsDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetLoggedInUserFriends__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1882582199
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetUserFriends_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetUserFriends_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetUserFriends_Statics::NewProp_InGetLoggedInUserFriendsDelegate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetUserFriends_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the friend list of the current user. Friends who don't use this app won't appear in this list.</summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"InGetLoggedInUserFriendsDelegate\">Will be executed when the request has been completed.  \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_UserArray *, UserArray).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the friend list of the current user. Friends who don't use this app won't appear in this list.</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"InGetLoggedInUserFriendsDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_UserArray *, UserArray).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetUserFriends_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoUserFunction, nullptr, "PicoGetUserFriends", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetUserFriends_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetUserFriends_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetUserFriends_Statics::OnlinePicoUserFunction_eventPicoGetUserFriends_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetUserFriends_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetUserFriends_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetUserFriends_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetUserFriends_Statics::OnlinePicoUserFunction_eventPicoGetUserFriends_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetUserFriends()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetUserFriends_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics
	{
		struct OnlinePicoUserFunction_eventRequestUserPermissions_Parms
		{
			UObject* WorldContextObject;
			TArray<FString> Permissions;
			FScriptDelegate OnGetPermissionResultCallback;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Permissions_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Permissions;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnGetPermissionResultCallback;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventRequestUserPermissions_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics::NewProp_Permissions_Inner = { "Permissions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics::NewProp_Permissions = { "Permissions", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventRequestUserPermissions_Parms, Permissions), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics::NewProp_OnGetPermissionResultCallback = { "OnGetPermissionResultCallback", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoUserFunction_eventRequestUserPermissions_Parms, OnGetPermissionResultCallback), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetPermissionResult__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2400860354
	void Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoUserFunction_eventRequestUserPermissions_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoUserFunction_eventRequestUserPermissions_Parms), &Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics::NewProp_Permissions_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics::NewProp_Permissions,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics::NewProp_OnGetPermissionResultCallback,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Requests user permissions. The user will received a pop-up notification window.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"Permissions\">Will be executed when the request has been completed. Delegate will contain the requested object class.\n/// * `user_info`: The permission to get the user's basic information, such as the user's nickname and profile picture.\n/// * `friend_relation`: The permission to get the user's friend list and invitable users.\n/// * `sports_userinfo`: The permission to get the user's information set in the sport center.\n/// * `sports_summarydata`: The permission to get a summary of the user's exercise data.\n/// </param>\n/// <param name=\"OnGetPermissionResultCallback\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_PermissionResult *, PermissionResult).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nRequests user permissions. The user will received a pop-up notification window.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"Permissions\">Will be executed when the request has been completed. Delegate will contain the requested object class.\n* `user_info`: The permission to get the user's basic information, such as the user's nickname and profile picture.\n* `friend_relation`: The permission to get the user's friend list and invitable users.\n* `sports_userinfo`: The permission to get the user's information set in the sport center.\n* `sports_summarydata`: The permission to get a summary of the user's exercise data.\n</param>\n<param name=\"OnGetPermissionResultCallback\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_PermissionResult *, PermissionResult).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoUserFunction, nullptr, "RequestUserPermissions", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics::OnlinePicoUserFunction_eventRequestUserPermissions_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics::OnlinePicoUserFunction_eventRequestUserPermissions_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOnlinePicoUserFunction);
	UClass* Z_Construct_UClass_UOnlinePicoUserFunction_NoRegister()
	{
		return UOnlinePicoUserFunction::StaticClass();
	}
	struct Z_Construct_UClass_UOnlinePicoUserFunction_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOnlinePicoUserFunction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoUserFunction_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UOnlinePicoUserFunction_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOnlinePicoUserFunction_EntitlementCheck, "EntitlementCheck" }, // 2033224961
		{ &Z_Construct_UFunction_UOnlinePicoUserFunction_GetAccessToken, "GetAccessToken" }, // 1605149777
		{ &Z_Construct_UFunction_UOnlinePicoUserFunction_GetAuthorizePermissions, "GetAuthorizePermissions" }, // 3658038853
		{ &Z_Construct_UFunction_UOnlinePicoUserFunction_GetIDToken, "GetIDToken" }, // 1447202274
		{ &Z_Construct_UFunction_UOnlinePicoUserFunction_GetLoginUser, "GetLoginUser" }, // 2179745367
		{ &Z_Construct_UFunction_UOnlinePicoUserFunction_GetOrgScopedID, "GetOrgScopedID" }, // 4229178388
		{ &Z_Construct_UFunction_UOnlinePicoUserFunction_GetPicoUserInfo, "GetPicoUserInfo" }, // 2495169527
		{ &Z_Construct_UFunction_UOnlinePicoUserFunction_GetRelations, "GetRelations" }, // 4206482686
		{ &Z_Construct_UFunction_UOnlinePicoUserFunction_LaunchFriendRequestFlow, "LaunchFriendRequestFlow" }, // 2192526459
		{ &Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetLoggedInUserAndRoom, "PicoGetLoggedInUserAndRoom" }, // 3689137079
		{ &Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserAndRoomArrayPage, "PicoGetNextUserAndRoomArrayPage" }, // 382649294
		{ &Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetNextUserPage, "PicoGetNextUserPage" }, // 121040492
		{ &Z_Construct_UFunction_UOnlinePicoUserFunction_PicoGetUserFriends, "PicoGetUserFriends" }, // 1330570463
		{ &Z_Construct_UFunction_UOnlinePicoUserFunction_RequestUserPermissions, "RequestUserPermissions" }, // 321831717
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoUserFunction_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoUserFunction_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @defgroup BP_User BP_User\n *  This is the BP_User group\n *  @{\n *//// @brief OnlinePicoUser Blueprint Function class.\n" },
#endif
		{ "IncludePath", "Pico_User.h" },
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@defgroup BP_User BP_User\nThis is the BP_User group\n@{\n/// @brief OnlinePicoUser Blueprint Function class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOnlinePicoUserFunction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOnlinePicoUserFunction>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOnlinePicoUserFunction_Statics::ClassParams = {
		&UOnlinePicoUserFunction::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoUserFunction_Statics::Class_MetaDataParams), Z_Construct_UClass_UOnlinePicoUserFunction_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UOnlinePicoUserFunction()
	{
		if (!Z_Registration_Info_UClass_UOnlinePicoUserFunction.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOnlinePicoUserFunction.OuterSingleton, Z_Construct_UClass_UOnlinePicoUserFunction_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOnlinePicoUserFunction.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UOnlinePicoUserFunction>()
	{
		return UOnlinePicoUserFunction::StaticClass();
	}
	UOnlinePicoUserFunction::UOnlinePicoUserFunction(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOnlinePicoUserFunction);
	UOnlinePicoUserFunction::~UOnlinePicoUserFunction() {}
	DEFINE_FUNCTION(UPico_User::execGetPresenceIsJoinable)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetPresenceIsJoinable();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_User::execGetStoreRegion)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetStoreRegion();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_User::execGetPresenceExtra)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetPresenceExtra();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_User::execGetPresenceMatchSessionId)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetPresenceMatchSessionId();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_User::execGetPresenceLobbySessionId)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetPresenceLobbySessionId();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_User::execGetPresenceDestinationApiName)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetPresenceDestinationApiName();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_User::execGetPresenceDeeplinkMessage)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetPresenceDeeplinkMessage();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_User::execGetPresence)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetPresence();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_User::execGetGender)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EUserGender*)Z_Param__Result=P_THIS->GetGender();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_User::execGetUserPresenceStatus)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EUserPresenceStatus*)Z_Param__Result=P_THIS->GetUserPresenceStatus();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_User::execGetPresencePackage)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetPresencePackage();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_User::execGetSmallImageUrl)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetSmallImageUrl();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_User::execGetInviteToken)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetInviteToken();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_User::execGetID)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetID();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_User::execGetImageURL)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetImageURL();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_User::execGetDisplayName)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetDisplayName();
		P_NATIVE_END;
	}
	void UPico_User::StaticRegisterNativesUPico_User()
	{
		UClass* Class = UPico_User::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetDisplayName", &UPico_User::execGetDisplayName },
			{ "GetGender", &UPico_User::execGetGender },
			{ "GetID", &UPico_User::execGetID },
			{ "GetImageURL", &UPico_User::execGetImageURL },
			{ "GetInviteToken", &UPico_User::execGetInviteToken },
			{ "GetPresence", &UPico_User::execGetPresence },
			{ "GetPresenceDeeplinkMessage", &UPico_User::execGetPresenceDeeplinkMessage },
			{ "GetPresenceDestinationApiName", &UPico_User::execGetPresenceDestinationApiName },
			{ "GetPresenceExtra", &UPico_User::execGetPresenceExtra },
			{ "GetPresenceIsJoinable", &UPico_User::execGetPresenceIsJoinable },
			{ "GetPresenceLobbySessionId", &UPico_User::execGetPresenceLobbySessionId },
			{ "GetPresenceMatchSessionId", &UPico_User::execGetPresenceMatchSessionId },
			{ "GetPresencePackage", &UPico_User::execGetPresencePackage },
			{ "GetSmallImageUrl", &UPico_User::execGetSmallImageUrl },
			{ "GetStoreRegion", &UPico_User::execGetStoreRegion },
			{ "GetUserPresenceStatus", &UPico_User::execGetUserPresenceStatus },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_User_GetDisplayName_Statics
	{
		struct Pico_User_eventGetDisplayName_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_User_GetDisplayName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_User_eventGetDisplayName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_User_GetDisplayName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_User_GetDisplayName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_User_GetDisplayName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief User's display name.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief User's display name." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_User_GetDisplayName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_User, nullptr, "GetDisplayName", nullptr, nullptr, Z_Construct_UFunction_UPico_User_GetDisplayName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetDisplayName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_User_GetDisplayName_Statics::Pico_User_eventGetDisplayName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetDisplayName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_User_GetDisplayName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetDisplayName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_User_GetDisplayName_Statics::Pico_User_eventGetDisplayName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_User_GetDisplayName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_User_GetDisplayName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_User_GetGender_Statics
	{
		struct Pico_User_eventGetGender_Parms
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
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPico_User_GetGender_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPico_User_GetGender_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_User_eventGetGender_Parms, ReturnValue), Z_Construct_UEnum_OnlineSubsystemPico_EUserGender, METADATA_PARAMS(0, nullptr) }; // 2253103228
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_User_GetGender_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_User_GetGender_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_User_GetGender_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_User_GetGender_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief User's gender.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief User's gender." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_User_GetGender_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_User, nullptr, "GetGender", nullptr, nullptr, Z_Construct_UFunction_UPico_User_GetGender_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetGender_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_User_GetGender_Statics::Pico_User_eventGetGender_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetGender_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_User_GetGender_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetGender_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_User_GetGender_Statics::Pico_User_eventGetGender_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_User_GetGender()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_User_GetGender_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_User_GetID_Statics
	{
		struct Pico_User_eventGetID_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_User_GetID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_User_eventGetID_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_User_GetID_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_User_GetID_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_User_GetID_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief User's openID. The same user has different openIDs in different apps.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief User's openID. The same user has different openIDs in different apps." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_User_GetID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_User, nullptr, "GetID", nullptr, nullptr, Z_Construct_UFunction_UPico_User_GetID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetID_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_User_GetID_Statics::Pico_User_eventGetID_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_User_GetID_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetID_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_User_GetID_Statics::Pico_User_eventGetID_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_User_GetID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_User_GetID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_User_GetImageURL_Statics
	{
		struct Pico_User_eventGetImageURL_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_User_GetImageURL_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_User_eventGetImageURL_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_User_GetImageURL_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_User_GetImageURL_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_User_GetImageURL_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The URL of user's profile photo. The image size is 300x300.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The URL of user's profile photo. The image size is 300x300." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_User_GetImageURL_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_User, nullptr, "GetImageURL", nullptr, nullptr, Z_Construct_UFunction_UPico_User_GetImageURL_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetImageURL_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_User_GetImageURL_Statics::Pico_User_eventGetImageURL_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetImageURL_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_User_GetImageURL_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetImageURL_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_User_GetImageURL_Statics::Pico_User_eventGetImageURL_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_User_GetImageURL()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_User_GetImageURL_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_User_GetInviteToken_Statics
	{
		struct Pico_User_eventGetInviteToken_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_User_GetInviteToken_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_User_eventGetInviteToken_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_User_GetInviteToken_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_User_GetInviteToken_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_User_GetInviteToken_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The invite token. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The invite token." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_User_GetInviteToken_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_User, nullptr, "GetInviteToken", nullptr, nullptr, Z_Construct_UFunction_UPico_User_GetInviteToken_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetInviteToken_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_User_GetInviteToken_Statics::Pico_User_eventGetInviteToken_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetInviteToken_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_User_GetInviteToken_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetInviteToken_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_User_GetInviteToken_Statics::Pico_User_eventGetInviteToken_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_User_GetInviteToken()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_User_GetInviteToken_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_User_GetPresence_Statics
	{
		struct Pico_User_eventGetPresence_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_User_GetPresence_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_User_eventGetPresence_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_User_GetPresence_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_User_GetPresence_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_User_GetPresence_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief User's presence info which is configured on the PICO Developer Platform.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief User's presence info which is configured on the PICO Developer Platform." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_User_GetPresence_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_User, nullptr, "GetPresence", nullptr, nullptr, Z_Construct_UFunction_UPico_User_GetPresence_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresence_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_User_GetPresence_Statics::Pico_User_eventGetPresence_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresence_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_User_GetPresence_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresence_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_User_GetPresence_Statics::Pico_User_eventGetPresence_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_User_GetPresence()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_User_GetPresence_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_User_GetPresenceDeeplinkMessage_Statics
	{
		struct Pico_User_eventGetPresenceDeeplinkMessage_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_User_GetPresenceDeeplinkMessage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_User_eventGetPresenceDeeplinkMessage_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_User_GetPresenceDeeplinkMessage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_User_GetPresenceDeeplinkMessage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_User_GetPresenceDeeplinkMessage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The deeplink message. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The deeplink message." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_User_GetPresenceDeeplinkMessage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_User, nullptr, "GetPresenceDeeplinkMessage", nullptr, nullptr, Z_Construct_UFunction_UPico_User_GetPresenceDeeplinkMessage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresenceDeeplinkMessage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_User_GetPresenceDeeplinkMessage_Statics::Pico_User_eventGetPresenceDeeplinkMessage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresenceDeeplinkMessage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_User_GetPresenceDeeplinkMessage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresenceDeeplinkMessage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_User_GetPresenceDeeplinkMessage_Statics::Pico_User_eventGetPresenceDeeplinkMessage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_User_GetPresenceDeeplinkMessage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_User_GetPresenceDeeplinkMessage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_User_GetPresenceDestinationApiName_Statics
	{
		struct Pico_User_eventGetPresenceDestinationApiName_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_User_GetPresenceDestinationApiName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_User_eventGetPresenceDestinationApiName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_User_GetPresenceDestinationApiName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_User_GetPresenceDestinationApiName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_User_GetPresenceDestinationApiName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The destination's API name. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The destination's API name." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_User_GetPresenceDestinationApiName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_User, nullptr, "GetPresenceDestinationApiName", nullptr, nullptr, Z_Construct_UFunction_UPico_User_GetPresenceDestinationApiName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresenceDestinationApiName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_User_GetPresenceDestinationApiName_Statics::Pico_User_eventGetPresenceDestinationApiName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresenceDestinationApiName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_User_GetPresenceDestinationApiName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresenceDestinationApiName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_User_GetPresenceDestinationApiName_Statics::Pico_User_eventGetPresenceDestinationApiName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_User_GetPresenceDestinationApiName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_User_GetPresenceDestinationApiName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_User_GetPresenceExtra_Statics
	{
		struct Pico_User_eventGetPresenceExtra_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_User_GetPresenceExtra_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_User_eventGetPresenceExtra_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_User_GetPresenceExtra_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_User_GetPresenceExtra_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_User_GetPresenceExtra_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief User's extra presence data. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief User's extra presence data." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_User_GetPresenceExtra_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_User, nullptr, "GetPresenceExtra", nullptr, nullptr, Z_Construct_UFunction_UPico_User_GetPresenceExtra_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresenceExtra_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_User_GetPresenceExtra_Statics::Pico_User_eventGetPresenceExtra_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresenceExtra_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_User_GetPresenceExtra_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresenceExtra_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_User_GetPresenceExtra_Statics::Pico_User_eventGetPresenceExtra_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_User_GetPresenceExtra()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_User_GetPresenceExtra_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_User_GetPresenceIsJoinable_Statics
	{
		struct Pico_User_eventGetPresenceIsJoinable_Parms
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
	void Z_Construct_UFunction_UPico_User_GetPresenceIsJoinable_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_User_eventGetPresenceIsJoinable_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_User_GetPresenceIsJoinable_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_User_eventGetPresenceIsJoinable_Parms), &Z_Construct_UFunction_UPico_User_GetPresenceIsJoinable_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_User_GetPresenceIsJoinable_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_User_GetPresenceIsJoinable_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_User_GetPresenceIsJoinable_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Whether the user is joinable.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Whether the user is joinable." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_User_GetPresenceIsJoinable_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_User, nullptr, "GetPresenceIsJoinable", nullptr, nullptr, Z_Construct_UFunction_UPico_User_GetPresenceIsJoinable_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresenceIsJoinable_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_User_GetPresenceIsJoinable_Statics::Pico_User_eventGetPresenceIsJoinable_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresenceIsJoinable_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_User_GetPresenceIsJoinable_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresenceIsJoinable_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_User_GetPresenceIsJoinable_Statics::Pico_User_eventGetPresenceIsJoinable_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_User_GetPresenceIsJoinable()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_User_GetPresenceIsJoinable_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_User_GetPresenceLobbySessionId_Statics
	{
		struct Pico_User_eventGetPresenceLobbySessionId_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_User_GetPresenceLobbySessionId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_User_eventGetPresenceLobbySessionId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_User_GetPresenceLobbySessionId_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_User_GetPresenceLobbySessionId_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_User_GetPresenceLobbySessionId_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The lobby session ID which identifies a group or team. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The lobby session ID which identifies a group or team." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_User_GetPresenceLobbySessionId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_User, nullptr, "GetPresenceLobbySessionId", nullptr, nullptr, Z_Construct_UFunction_UPico_User_GetPresenceLobbySessionId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresenceLobbySessionId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_User_GetPresenceLobbySessionId_Statics::Pico_User_eventGetPresenceLobbySessionId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresenceLobbySessionId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_User_GetPresenceLobbySessionId_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresenceLobbySessionId_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_User_GetPresenceLobbySessionId_Statics::Pico_User_eventGetPresenceLobbySessionId_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_User_GetPresenceLobbySessionId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_User_GetPresenceLobbySessionId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_User_GetPresenceMatchSessionId_Statics
	{
		struct Pico_User_eventGetPresenceMatchSessionId_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_User_GetPresenceMatchSessionId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_User_eventGetPresenceMatchSessionId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_User_GetPresenceMatchSessionId_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_User_GetPresenceMatchSessionId_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_User_GetPresenceMatchSessionId_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The match session ID which identifies a competition. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The match session ID which identifies a competition." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_User_GetPresenceMatchSessionId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_User, nullptr, "GetPresenceMatchSessionId", nullptr, nullptr, Z_Construct_UFunction_UPico_User_GetPresenceMatchSessionId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresenceMatchSessionId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_User_GetPresenceMatchSessionId_Statics::Pico_User_eventGetPresenceMatchSessionId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresenceMatchSessionId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_User_GetPresenceMatchSessionId_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresenceMatchSessionId_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_User_GetPresenceMatchSessionId_Statics::Pico_User_eventGetPresenceMatchSessionId_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_User_GetPresenceMatchSessionId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_User_GetPresenceMatchSessionId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_User_GetPresencePackage_Statics
	{
		struct Pico_User_eventGetPresencePackage_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_User_GetPresencePackage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_User_eventGetPresencePackage_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_User_GetPresencePackage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_User_GetPresencePackage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_User_GetPresencePackage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief User's presence package info which is configured on the PICO Developer Platform.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief User's presence package info which is configured on the PICO Developer Platform." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_User_GetPresencePackage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_User, nullptr, "GetPresencePackage", nullptr, nullptr, Z_Construct_UFunction_UPico_User_GetPresencePackage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresencePackage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_User_GetPresencePackage_Statics::Pico_User_eventGetPresencePackage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresencePackage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_User_GetPresencePackage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetPresencePackage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_User_GetPresencePackage_Statics::Pico_User_eventGetPresencePackage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_User_GetPresencePackage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_User_GetPresencePackage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_User_GetSmallImageUrl_Statics
	{
		struct Pico_User_eventGetSmallImageUrl_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_User_GetSmallImageUrl_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_User_eventGetSmallImageUrl_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_User_GetSmallImageUrl_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_User_GetSmallImageUrl_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_User_GetSmallImageUrl_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**  @brief The URL of the user's small profile photo. The image size is 128x128. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The URL of the user's small profile photo. The image size is 128x128." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_User_GetSmallImageUrl_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_User, nullptr, "GetSmallImageUrl", nullptr, nullptr, Z_Construct_UFunction_UPico_User_GetSmallImageUrl_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetSmallImageUrl_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_User_GetSmallImageUrl_Statics::Pico_User_eventGetSmallImageUrl_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetSmallImageUrl_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_User_GetSmallImageUrl_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetSmallImageUrl_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_User_GetSmallImageUrl_Statics::Pico_User_eventGetSmallImageUrl_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_User_GetSmallImageUrl()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_User_GetSmallImageUrl_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_User_GetStoreRegion_Statics
	{
		struct Pico_User_eventGetStoreRegion_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_User_GetStoreRegion_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_User_eventGetStoreRegion_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_User_GetStoreRegion_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_User_GetStoreRegion_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_User_GetStoreRegion_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief User's registration country/region. It is a country/region code. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief User's registration country/region. It is a country/region code." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_User_GetStoreRegion_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_User, nullptr, "GetStoreRegion", nullptr, nullptr, Z_Construct_UFunction_UPico_User_GetStoreRegion_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetStoreRegion_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_User_GetStoreRegion_Statics::Pico_User_eventGetStoreRegion_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetStoreRegion_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_User_GetStoreRegion_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetStoreRegion_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_User_GetStoreRegion_Statics::Pico_User_eventGetStoreRegion_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_User_GetStoreRegion()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_User_GetStoreRegion_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_User_GetUserPresenceStatus_Statics
	{
		struct Pico_User_eventGetUserPresenceStatus_Parms
		{
			EUserPresenceStatus ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPico_User_GetUserPresenceStatus_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPico_User_GetUserPresenceStatus_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_User_eventGetUserPresenceStatus_Parms, ReturnValue), Z_Construct_UEnum_OnlineSubsystemPico_EUserPresenceStatus, METADATA_PARAMS(0, nullptr) }; // 1831987395
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_User_GetUserPresenceStatus_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_User_GetUserPresenceStatus_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_User_GetUserPresenceStatus_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_User_GetUserPresenceStatus_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief User's presence status which indicates whether the user is online.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief User's presence status which indicates whether the user is online." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_User_GetUserPresenceStatus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_User, nullptr, "GetUserPresenceStatus", nullptr, nullptr, Z_Construct_UFunction_UPico_User_GetUserPresenceStatus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetUserPresenceStatus_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_User_GetUserPresenceStatus_Statics::Pico_User_eventGetUserPresenceStatus_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetUserPresenceStatus_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_User_GetUserPresenceStatus_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_User_GetUserPresenceStatus_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_User_GetUserPresenceStatus_Statics::Pico_User_eventGetUserPresenceStatus_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_User_GetUserPresenceStatus()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_User_GetUserPresenceStatus_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_User);
	UClass* Z_Construct_UClass_UPico_User_NoRegister()
	{
		return UPico_User::StaticClass();
	}
	struct Z_Construct_UClass_UPico_User_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_User_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_User_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_User_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_User_GetDisplayName, "GetDisplayName" }, // 149298733
		{ &Z_Construct_UFunction_UPico_User_GetGender, "GetGender" }, // 1238342384
		{ &Z_Construct_UFunction_UPico_User_GetID, "GetID" }, // 3026961215
		{ &Z_Construct_UFunction_UPico_User_GetImageURL, "GetImageURL" }, // 174342186
		{ &Z_Construct_UFunction_UPico_User_GetInviteToken, "GetInviteToken" }, // 1654555938
		{ &Z_Construct_UFunction_UPico_User_GetPresence, "GetPresence" }, // 898012187
		{ &Z_Construct_UFunction_UPico_User_GetPresenceDeeplinkMessage, "GetPresenceDeeplinkMessage" }, // 652985905
		{ &Z_Construct_UFunction_UPico_User_GetPresenceDestinationApiName, "GetPresenceDestinationApiName" }, // 2570597140
		{ &Z_Construct_UFunction_UPico_User_GetPresenceExtra, "GetPresenceExtra" }, // 3746834528
		{ &Z_Construct_UFunction_UPico_User_GetPresenceIsJoinable, "GetPresenceIsJoinable" }, // 3155544018
		{ &Z_Construct_UFunction_UPico_User_GetPresenceLobbySessionId, "GetPresenceLobbySessionId" }, // 3619144501
		{ &Z_Construct_UFunction_UPico_User_GetPresenceMatchSessionId, "GetPresenceMatchSessionId" }, // 821195354
		{ &Z_Construct_UFunction_UPico_User_GetPresencePackage, "GetPresencePackage" }, // 2115036425
		{ &Z_Construct_UFunction_UPico_User_GetSmallImageUrl, "GetSmallImageUrl" }, // 4272296278
		{ &Z_Construct_UFunction_UPico_User_GetStoreRegion, "GetStoreRegion" }, // 3857138820
		{ &Z_Construct_UFunction_UPico_User_GetUserPresenceStatus, "GetUserPresenceStatus" }, // 1690600173
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_User_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_User_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_User class.\n" },
#endif
		{ "IncludePath", "Pico_User.h" },
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_User class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_User_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_User>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_User_Statics::ClassParams = {
		&UPico_User::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_User_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_User_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPico_User()
	{
		if (!Z_Registration_Info_UClass_UPico_User.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_User.OuterSingleton, Z_Construct_UClass_UPico_User_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_User.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_User>()
	{
		return UPico_User::StaticClass();
	}
	UPico_User::UPico_User(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_User);
	UPico_User::~UPico_User() {}
	DEFINE_FUNCTION(UPico_UserArray::execHasNextPage)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->HasNextPage();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_UserArray::execGetSize)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetSize();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_UserArray::execGetNextPageParam)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetNextPageParam();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_UserArray::execGetElement)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPico_User**)Z_Param__Result=P_THIS->GetElement(Z_Param_Index);
		P_NATIVE_END;
	}
	void UPico_UserArray::StaticRegisterNativesUPico_UserArray()
	{
		UClass* Class = UPico_UserArray::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetElement", &UPico_UserArray::execGetElement },
			{ "GetNextPageParam", &UPico_UserArray::execGetNextPageParam },
			{ "GetSize", &UPico_UserArray::execGetSize },
			{ "HasNextPage", &UPico_UserArray::execHasNextPage },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_UserArray_GetElement_Statics
	{
		struct Pico_UserArray_eventGetElement_Parms
		{
			int32 Index;
			UPico_User* ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_UserArray_GetElement_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_UserArray_eventGetElement_Parms, Index), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPico_UserArray_GetElement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_UserArray_eventGetElement_Parms, ReturnValue), Z_Construct_UClass_UPico_User_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_UserArray_GetElement_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_UserArray_GetElement_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_UserArray_GetElement_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_UserArray_GetElement_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get UserArray element form Index.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get UserArray element form Index." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_UserArray_GetElement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_UserArray, nullptr, "GetElement", nullptr, nullptr, Z_Construct_UFunction_UPico_UserArray_GetElement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserArray_GetElement_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_UserArray_GetElement_Statics::Pico_UserArray_eventGetElement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserArray_GetElement_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_UserArray_GetElement_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserArray_GetElement_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_UserArray_GetElement_Statics::Pico_UserArray_eventGetElement_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_UserArray_GetElement()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_UserArray_GetElement_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_UserArray_GetNextPageParam_Statics
	{
		struct Pico_UserArray_eventGetNextPageParam_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_UserArray_GetNextPageParam_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_UserArray_eventGetNextPageParam_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_UserArray_GetNextPageParam_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_UserArray_GetNextPageParam_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_UserArray_GetNextPageParam_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User Array" },
		{ "ModuleRelativePath", "Public/Pico_User.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_UserArray_GetNextPageParam_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_UserArray, nullptr, "GetNextPageParam", nullptr, nullptr, Z_Construct_UFunction_UPico_UserArray_GetNextPageParam_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserArray_GetNextPageParam_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_UserArray_GetNextPageParam_Statics::Pico_UserArray_eventGetNextPageParam_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserArray_GetNextPageParam_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_UserArray_GetNextPageParam_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserArray_GetNextPageParam_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_UserArray_GetNextPageParam_Statics::Pico_UserArray_eventGetNextPageParam_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_UserArray_GetNextPageParam()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_UserArray_GetNextPageParam_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_UserArray_GetSize_Statics
	{
		struct Pico_UserArray_eventGetSize_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_UserArray_GetSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_UserArray_eventGetSize_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_UserArray_GetSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_UserArray_GetSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_UserArray_GetSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get the size of UserArray .*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get the size of UserArray ." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_UserArray_GetSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_UserArray, nullptr, "GetSize", nullptr, nullptr, Z_Construct_UFunction_UPico_UserArray_GetSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserArray_GetSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_UserArray_GetSize_Statics::Pico_UserArray_eventGetSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserArray_GetSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_UserArray_GetSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserArray_GetSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_UserArray_GetSize_Statics::Pico_UserArray_eventGetSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_UserArray_GetSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_UserArray_GetSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_UserArray_HasNextPage_Statics
	{
		struct Pico_UserArray_eventHasNextPage_Parms
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
	void Z_Construct_UFunction_UPico_UserArray_HasNextPage_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_UserArray_eventHasNextPage_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_UserArray_HasNextPage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_UserArray_eventHasNextPage_Parms), &Z_Construct_UFunction_UPico_UserArray_HasNextPage_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_UserArray_HasNextPage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_UserArray_HasNextPage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_UserArray_HasNextPage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get whether the list has the next page.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get whether the list has the next page." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_UserArray_HasNextPage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_UserArray, nullptr, "HasNextPage", nullptr, nullptr, Z_Construct_UFunction_UPico_UserArray_HasNextPage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserArray_HasNextPage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_UserArray_HasNextPage_Statics::Pico_UserArray_eventHasNextPage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserArray_HasNextPage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_UserArray_HasNextPage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserArray_HasNextPage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_UserArray_HasNextPage_Statics::Pico_UserArray_eventHasNextPage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_UserArray_HasNextPage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_UserArray_HasNextPage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_UserArray);
	UClass* Z_Construct_UClass_UPico_UserArray_NoRegister()
	{
		return UPico_UserArray::StaticClass();
	}
	struct Z_Construct_UClass_UPico_UserArray_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_UserArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UserArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_UserArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_UserArray_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserArray_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_UserArray_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_UserArray_GetElement, "GetElement" }, // 946823976
		{ &Z_Construct_UFunction_UPico_UserArray_GetNextPageParam, "GetNextPageParam" }, // 3518859968
		{ &Z_Construct_UFunction_UPico_UserArray_GetSize, "GetSize" }, // 946708894
		{ &Z_Construct_UFunction_UPico_UserArray_HasNextPage, "HasNextPage" }, // 3258994478
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserArray_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_UserArray_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_UserArray class.\n" },
#endif
		{ "IncludePath", "Pico_User.h" },
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_UserArray class." },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPico_UserArray_Statics::NewProp_UserArray_Inner = { "UserArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UPico_User_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_UserArray_Statics::NewProp_UserArray_MetaData[] = {
		{ "ModuleRelativePath", "Public/Pico_User.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPico_UserArray_Statics::NewProp_UserArray = { "UserArray", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPico_UserArray, UserArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserArray_Statics::NewProp_UserArray_MetaData), Z_Construct_UClass_UPico_UserArray_Statics::NewProp_UserArray_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPico_UserArray_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_UserArray_Statics::NewProp_UserArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_UserArray_Statics::NewProp_UserArray,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_UserArray_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_UserArray>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_UserArray_Statics::ClassParams = {
		&UPico_UserArray::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPico_UserArray_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserArray_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserArray_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_UserArray_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserArray_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPico_UserArray()
	{
		if (!Z_Registration_Info_UClass_UPico_UserArray.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_UserArray.OuterSingleton, Z_Construct_UClass_UPico_UserArray_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_UserArray.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_UserArray>()
	{
		return UPico_UserArray::StaticClass();
	}
	UPico_UserArray::UPico_UserArray(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_UserArray);
	UPico_UserArray::~UPico_UserArray() {}
	DEFINE_FUNCTION(UPico_UserAndRoom::execGetUser)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPico_User**)Z_Param__Result=P_THIS->GetUser();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_UserAndRoom::execGetRoom)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPico_Room**)Z_Param__Result=P_THIS->GetRoom();
		P_NATIVE_END;
	}
	void UPico_UserAndRoom::StaticRegisterNativesUPico_UserAndRoom()
	{
		UClass* Class = UPico_UserAndRoom::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetRoom", &UPico_UserAndRoom::execGetRoom },
			{ "GetUser", &UPico_UserAndRoom::execGetUser },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_UserAndRoom_GetRoom_Statics
	{
		struct Pico_UserAndRoom_eventGetRoom_Parms
		{
			UPico_Room* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPico_UserAndRoom_GetRoom_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_UserAndRoom_eventGetRoom_Parms, ReturnValue), Z_Construct_UClass_UPico_Room_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_UserAndRoom_GetRoom_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_UserAndRoom_GetRoom_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_UserAndRoom_GetRoom_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User And Room" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get the Room Object .*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get the Room Object ." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_UserAndRoom_GetRoom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_UserAndRoom, nullptr, "GetRoom", nullptr, nullptr, Z_Construct_UFunction_UPico_UserAndRoom_GetRoom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserAndRoom_GetRoom_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_UserAndRoom_GetRoom_Statics::Pico_UserAndRoom_eventGetRoom_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserAndRoom_GetRoom_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_UserAndRoom_GetRoom_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserAndRoom_GetRoom_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_UserAndRoom_GetRoom_Statics::Pico_UserAndRoom_eventGetRoom_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_UserAndRoom_GetRoom()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_UserAndRoom_GetRoom_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_UserAndRoom_GetUser_Statics
	{
		struct Pico_UserAndRoom_eventGetUser_Parms
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPico_UserAndRoom_GetUser_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_UserAndRoom_eventGetUser_Parms, ReturnValue), Z_Construct_UClass_UPico_User_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_UserAndRoom_GetUser_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_UserAndRoom_GetUser_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_UserAndRoom_GetUser_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User And Room" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get the User Object .*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get the User Object ." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_UserAndRoom_GetUser_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_UserAndRoom, nullptr, "GetUser", nullptr, nullptr, Z_Construct_UFunction_UPico_UserAndRoom_GetUser_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserAndRoom_GetUser_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_UserAndRoom_GetUser_Statics::Pico_UserAndRoom_eventGetUser_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserAndRoom_GetUser_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_UserAndRoom_GetUser_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserAndRoom_GetUser_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_UserAndRoom_GetUser_Statics::Pico_UserAndRoom_eventGetUser_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_UserAndRoom_GetUser()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_UserAndRoom_GetUser_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_UserAndRoom);
	UClass* Z_Construct_UClass_UPico_UserAndRoom_NoRegister()
	{
		return UPico_UserAndRoom::StaticClass();
	}
	struct Z_Construct_UClass_UPico_UserAndRoom_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Room_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Room;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_User_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_User;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_UserAndRoom_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserAndRoom_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_UserAndRoom_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_UserAndRoom_GetRoom, "GetRoom" }, // 1473803168
		{ &Z_Construct_UFunction_UPico_UserAndRoom_GetUser, "GetUser" }, // 1734744351
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserAndRoom_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_UserAndRoom_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_UserAndRoom class.\n" },
#endif
		{ "IncludePath", "Pico_User.h" },
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_UserAndRoom class." },
#endif
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_UserAndRoom_Statics::NewProp_Room_MetaData[] = {
		{ "ModuleRelativePath", "Public/Pico_User.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPico_UserAndRoom_Statics::NewProp_Room = { "Room", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPico_UserAndRoom, Room), Z_Construct_UClass_UPico_Room_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserAndRoom_Statics::NewProp_Room_MetaData), Z_Construct_UClass_UPico_UserAndRoom_Statics::NewProp_Room_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_UserAndRoom_Statics::NewProp_User_MetaData[] = {
		{ "ModuleRelativePath", "Public/Pico_User.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPico_UserAndRoom_Statics::NewProp_User = { "User", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPico_UserAndRoom, User), Z_Construct_UClass_UPico_User_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserAndRoom_Statics::NewProp_User_MetaData), Z_Construct_UClass_UPico_UserAndRoom_Statics::NewProp_User_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPico_UserAndRoom_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_UserAndRoom_Statics::NewProp_Room,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_UserAndRoom_Statics::NewProp_User,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_UserAndRoom_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_UserAndRoom>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_UserAndRoom_Statics::ClassParams = {
		&UPico_UserAndRoom::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPico_UserAndRoom_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserAndRoom_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserAndRoom_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_UserAndRoom_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserAndRoom_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPico_UserAndRoom()
	{
		if (!Z_Registration_Info_UClass_UPico_UserAndRoom.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_UserAndRoom.OuterSingleton, Z_Construct_UClass_UPico_UserAndRoom_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_UserAndRoom.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_UserAndRoom>()
	{
		return UPico_UserAndRoom::StaticClass();
	}
	UPico_UserAndRoom::UPico_UserAndRoom(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_UserAndRoom);
	UPico_UserAndRoom::~UPico_UserAndRoom() {}
	DEFINE_FUNCTION(UPico_UserAndRoomArray::execHasNextPage)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->HasNextPage();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_UserAndRoomArray::execGetSize)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetSize();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_UserAndRoomArray::execGetNextPageParam)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetNextPageParam();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_UserAndRoomArray::execGetElement)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPico_UserAndRoom**)Z_Param__Result=P_THIS->GetElement(Z_Param_Index);
		P_NATIVE_END;
	}
	void UPico_UserAndRoomArray::StaticRegisterNativesUPico_UserAndRoomArray()
	{
		UClass* Class = UPico_UserAndRoomArray::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetElement", &UPico_UserAndRoomArray::execGetElement },
			{ "GetNextPageParam", &UPico_UserAndRoomArray::execGetNextPageParam },
			{ "GetSize", &UPico_UserAndRoomArray::execGetSize },
			{ "HasNextPage", &UPico_UserAndRoomArray::execHasNextPage },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_UserAndRoomArray_GetElement_Statics
	{
		struct Pico_UserAndRoomArray_eventGetElement_Parms
		{
			int32 Index;
			UPico_UserAndRoom* ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_UserAndRoomArray_GetElement_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_UserAndRoomArray_eventGetElement_Parms, Index), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPico_UserAndRoomArray_GetElement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_UserAndRoomArray_eventGetElement_Parms, ReturnValue), Z_Construct_UClass_UPico_UserAndRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_UserAndRoomArray_GetElement_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_UserAndRoomArray_GetElement_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_UserAndRoomArray_GetElement_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_UserAndRoomArray_GetElement_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User And Room Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get UserAndRoomArray element form Index.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get UserAndRoomArray element form Index." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_UserAndRoomArray_GetElement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_UserAndRoomArray, nullptr, "GetElement", nullptr, nullptr, Z_Construct_UFunction_UPico_UserAndRoomArray_GetElement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserAndRoomArray_GetElement_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_UserAndRoomArray_GetElement_Statics::Pico_UserAndRoomArray_eventGetElement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserAndRoomArray_GetElement_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_UserAndRoomArray_GetElement_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserAndRoomArray_GetElement_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_UserAndRoomArray_GetElement_Statics::Pico_UserAndRoomArray_eventGetElement_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_UserAndRoomArray_GetElement()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_UserAndRoomArray_GetElement_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_UserAndRoomArray_GetNextPageParam_Statics
	{
		struct Pico_UserAndRoomArray_eventGetNextPageParam_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_UserAndRoomArray_GetNextPageParam_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_UserAndRoomArray_eventGetNextPageParam_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_UserAndRoomArray_GetNextPageParam_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_UserAndRoomArray_GetNextPageParam_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_UserAndRoomArray_GetNextPageParam_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User And Room Array" },
		{ "ModuleRelativePath", "Public/Pico_User.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_UserAndRoomArray_GetNextPageParam_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_UserAndRoomArray, nullptr, "GetNextPageParam", nullptr, nullptr, Z_Construct_UFunction_UPico_UserAndRoomArray_GetNextPageParam_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserAndRoomArray_GetNextPageParam_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_UserAndRoomArray_GetNextPageParam_Statics::Pico_UserAndRoomArray_eventGetNextPageParam_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserAndRoomArray_GetNextPageParam_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_UserAndRoomArray_GetNextPageParam_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserAndRoomArray_GetNextPageParam_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_UserAndRoomArray_GetNextPageParam_Statics::Pico_UserAndRoomArray_eventGetNextPageParam_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_UserAndRoomArray_GetNextPageParam()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_UserAndRoomArray_GetNextPageParam_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_UserAndRoomArray_GetSize_Statics
	{
		struct Pico_UserAndRoomArray_eventGetSize_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_UserAndRoomArray_GetSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_UserAndRoomArray_eventGetSize_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_UserAndRoomArray_GetSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_UserAndRoomArray_GetSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_UserAndRoomArray_GetSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User And Room Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get the size of UserAndRoomArray .*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get the size of UserAndRoomArray ." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_UserAndRoomArray_GetSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_UserAndRoomArray, nullptr, "GetSize", nullptr, nullptr, Z_Construct_UFunction_UPico_UserAndRoomArray_GetSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserAndRoomArray_GetSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_UserAndRoomArray_GetSize_Statics::Pico_UserAndRoomArray_eventGetSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserAndRoomArray_GetSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_UserAndRoomArray_GetSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserAndRoomArray_GetSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_UserAndRoomArray_GetSize_Statics::Pico_UserAndRoomArray_eventGetSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_UserAndRoomArray_GetSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_UserAndRoomArray_GetSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_UserAndRoomArray_HasNextPage_Statics
	{
		struct Pico_UserAndRoomArray_eventHasNextPage_Parms
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
	void Z_Construct_UFunction_UPico_UserAndRoomArray_HasNextPage_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_UserAndRoomArray_eventHasNextPage_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_UserAndRoomArray_HasNextPage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_UserAndRoomArray_eventHasNextPage_Parms), &Z_Construct_UFunction_UPico_UserAndRoomArray_HasNextPage_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_UserAndRoomArray_HasNextPage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_UserAndRoomArray_HasNextPage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_UserAndRoomArray_HasNextPage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|User And Room Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get whether the list has the next page.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get whether the list has the next page." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_UserAndRoomArray_HasNextPage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_UserAndRoomArray, nullptr, "HasNextPage", nullptr, nullptr, Z_Construct_UFunction_UPico_UserAndRoomArray_HasNextPage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserAndRoomArray_HasNextPage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_UserAndRoomArray_HasNextPage_Statics::Pico_UserAndRoomArray_eventHasNextPage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserAndRoomArray_HasNextPage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_UserAndRoomArray_HasNextPage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserAndRoomArray_HasNextPage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_UserAndRoomArray_HasNextPage_Statics::Pico_UserAndRoomArray_eventHasNextPage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_UserAndRoomArray_HasNextPage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_UserAndRoomArray_HasNextPage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_UserAndRoomArray);
	UClass* Z_Construct_UClass_UPico_UserAndRoomArray_NoRegister()
	{
		return UPico_UserAndRoomArray::StaticClass();
	}
	struct Z_Construct_UClass_UPico_UserAndRoomArray_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_UserAndRoomArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UserAndRoomArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_UserAndRoomArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_UserAndRoomArray_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserAndRoomArray_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_UserAndRoomArray_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_UserAndRoomArray_GetElement, "GetElement" }, // 916810125
		{ &Z_Construct_UFunction_UPico_UserAndRoomArray_GetNextPageParam, "GetNextPageParam" }, // 4110927740
		{ &Z_Construct_UFunction_UPico_UserAndRoomArray_GetSize, "GetSize" }, // 4142588908
		{ &Z_Construct_UFunction_UPico_UserAndRoomArray_HasNextPage, "HasNextPage" }, // 208382759
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserAndRoomArray_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_UserAndRoomArray_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_UserAndRoomArray class.\n" },
#endif
		{ "IncludePath", "Pico_User.h" },
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_UserAndRoomArray class." },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPico_UserAndRoomArray_Statics::NewProp_UserAndRoomArray_Inner = { "UserAndRoomArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UPico_UserAndRoom_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_UserAndRoomArray_Statics::NewProp_UserAndRoomArray_MetaData[] = {
		{ "ModuleRelativePath", "Public/Pico_User.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPico_UserAndRoomArray_Statics::NewProp_UserAndRoomArray = { "UserAndRoomArray", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPico_UserAndRoomArray, UserAndRoomArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserAndRoomArray_Statics::NewProp_UserAndRoomArray_MetaData), Z_Construct_UClass_UPico_UserAndRoomArray_Statics::NewProp_UserAndRoomArray_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPico_UserAndRoomArray_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_UserAndRoomArray_Statics::NewProp_UserAndRoomArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_UserAndRoomArray_Statics::NewProp_UserAndRoomArray,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_UserAndRoomArray_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_UserAndRoomArray>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_UserAndRoomArray_Statics::ClassParams = {
		&UPico_UserAndRoomArray::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPico_UserAndRoomArray_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserAndRoomArray_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserAndRoomArray_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_UserAndRoomArray_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserAndRoomArray_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPico_UserAndRoomArray()
	{
		if (!Z_Registration_Info_UClass_UPico_UserAndRoomArray.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_UserAndRoomArray.OuterSingleton, Z_Construct_UClass_UPico_UserAndRoomArray_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_UserAndRoomArray.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_UserAndRoomArray>()
	{
		return UPico_UserAndRoomArray::StaticClass();
	}
	UPico_UserAndRoomArray::UPico_UserAndRoomArray(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_UserAndRoomArray);
	UPico_UserAndRoomArray::~UPico_UserAndRoomArray() {}
	DEFINE_FUNCTION(UPico_PermissionResult::execGetUserID)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetUserID();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_PermissionResult::execGetAccessToken)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetAccessToken();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_PermissionResult::execGetSize)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetSize();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_PermissionResult::execGetAuthorizedPermission)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetAuthorizedPermission(Z_Param_Index);
		P_NATIVE_END;
	}
	void UPico_PermissionResult::StaticRegisterNativesUPico_PermissionResult()
	{
		UClass* Class = UPico_PermissionResult::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAccessToken", &UPico_PermissionResult::execGetAccessToken },
			{ "GetAuthorizedPermission", &UPico_PermissionResult::execGetAuthorizedPermission },
			{ "GetSize", &UPico_PermissionResult::execGetSize },
			{ "GetUserID", &UPico_PermissionResult::execGetUserID },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_PermissionResult_GetAccessToken_Statics
	{
		struct Pico_PermissionResult_eventGetAccessToken_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_PermissionResult_GetAccessToken_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_PermissionResult_eventGetAccessToken_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_PermissionResult_GetAccessToken_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_PermissionResult_GetAccessToken_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_PermissionResult_GetAccessToken_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|Permission" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The access token. It has a value only after you call \\ref UserService.RequestUserPermissions.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The access token. It has a value only after you call \\ref UserService.RequestUserPermissions." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_PermissionResult_GetAccessToken_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_PermissionResult, nullptr, "GetAccessToken", nullptr, nullptr, Z_Construct_UFunction_UPico_PermissionResult_GetAccessToken_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PermissionResult_GetAccessToken_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_PermissionResult_GetAccessToken_Statics::Pico_PermissionResult_eventGetAccessToken_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PermissionResult_GetAccessToken_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_PermissionResult_GetAccessToken_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PermissionResult_GetAccessToken_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_PermissionResult_GetAccessToken_Statics::Pico_PermissionResult_eventGetAccessToken_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_PermissionResult_GetAccessToken()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_PermissionResult_GetAccessToken_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_PermissionResult_GetAuthorizedPermission_Statics
	{
		struct Pico_PermissionResult_eventGetAuthorizedPermission_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_PermissionResult_GetAuthorizedPermission_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_PermissionResult_eventGetAuthorizedPermission_Parms, Index), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_PermissionResult_GetAuthorizedPermission_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_PermissionResult_eventGetAuthorizedPermission_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_PermissionResult_GetAuthorizedPermission_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_PermissionResult_GetAuthorizedPermission_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_PermissionResult_GetAuthorizedPermission_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_PermissionResult_GetAuthorizedPermission_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|Permission" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get AuthorizedPermissions element form Index.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get AuthorizedPermissions element form Index." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_PermissionResult_GetAuthorizedPermission_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_PermissionResult, nullptr, "GetAuthorizedPermission", nullptr, nullptr, Z_Construct_UFunction_UPico_PermissionResult_GetAuthorizedPermission_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PermissionResult_GetAuthorizedPermission_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_PermissionResult_GetAuthorizedPermission_Statics::Pico_PermissionResult_eventGetAuthorizedPermission_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PermissionResult_GetAuthorizedPermission_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_PermissionResult_GetAuthorizedPermission_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PermissionResult_GetAuthorizedPermission_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_PermissionResult_GetAuthorizedPermission_Statics::Pico_PermissionResult_eventGetAuthorizedPermission_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_PermissionResult_GetAuthorizedPermission()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_PermissionResult_GetAuthorizedPermission_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_PermissionResult_GetSize_Statics
	{
		struct Pico_PermissionResult_eventGetSize_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_PermissionResult_GetSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_PermissionResult_eventGetSize_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_PermissionResult_GetSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_PermissionResult_GetSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_PermissionResult_GetSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|Permission" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get the size of AuthorizedPermissions .*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get the size of AuthorizedPermissions ." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_PermissionResult_GetSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_PermissionResult, nullptr, "GetSize", nullptr, nullptr, Z_Construct_UFunction_UPico_PermissionResult_GetSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PermissionResult_GetSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_PermissionResult_GetSize_Statics::Pico_PermissionResult_eventGetSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PermissionResult_GetSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_PermissionResult_GetSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PermissionResult_GetSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_PermissionResult_GetSize_Statics::Pico_PermissionResult_eventGetSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_PermissionResult_GetSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_PermissionResult_GetSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_PermissionResult_GetUserID_Statics
	{
		struct Pico_PermissionResult_eventGetUserID_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_PermissionResult_GetUserID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_PermissionResult_eventGetUserID_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_PermissionResult_GetUserID_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_PermissionResult_GetUserID_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_PermissionResult_GetUserID_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|Permission" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The current user's ID.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The current user's ID." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_PermissionResult_GetUserID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_PermissionResult, nullptr, "GetUserID", nullptr, nullptr, Z_Construct_UFunction_UPico_PermissionResult_GetUserID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PermissionResult_GetUserID_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_PermissionResult_GetUserID_Statics::Pico_PermissionResult_eventGetUserID_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PermissionResult_GetUserID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_PermissionResult_GetUserID_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PermissionResult_GetUserID_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_PermissionResult_GetUserID_Statics::Pico_PermissionResult_eventGetUserID_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_PermissionResult_GetUserID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_PermissionResult_GetUserID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_PermissionResult);
	UClass* Z_Construct_UClass_UPico_PermissionResult_NoRegister()
	{
		return UPico_PermissionResult::StaticClass();
	}
	struct Z_Construct_UClass_UPico_PermissionResult_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AuthorizedPermissions_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AuthorizedPermissions_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_AuthorizedPermissions;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_PermissionResult_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_PermissionResult_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_PermissionResult_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_PermissionResult_GetAccessToken, "GetAccessToken" }, // 798653007
		{ &Z_Construct_UFunction_UPico_PermissionResult_GetAuthorizedPermission, "GetAuthorizedPermission" }, // 223333904
		{ &Z_Construct_UFunction_UPico_PermissionResult_GetSize, "GetSize" }, // 3125523184
		{ &Z_Construct_UFunction_UPico_PermissionResult_GetUserID, "GetUserID" }, // 2884674298
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_PermissionResult_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_PermissionResult_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_PermissionResult class.\n" },
#endif
		{ "IncludePath", "Pico_User.h" },
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_PermissionResult class." },
#endif
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UPico_PermissionResult_Statics::NewProp_AuthorizedPermissions_Inner = { "AuthorizedPermissions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_PermissionResult_Statics::NewProp_AuthorizedPermissions_MetaData[] = {
		{ "ModuleRelativePath", "Public/Pico_User.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPico_PermissionResult_Statics::NewProp_AuthorizedPermissions = { "AuthorizedPermissions", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPico_PermissionResult, AuthorizedPermissions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_PermissionResult_Statics::NewProp_AuthorizedPermissions_MetaData), Z_Construct_UClass_UPico_PermissionResult_Statics::NewProp_AuthorizedPermissions_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPico_PermissionResult_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_PermissionResult_Statics::NewProp_AuthorizedPermissions_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_PermissionResult_Statics::NewProp_AuthorizedPermissions,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_PermissionResult_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_PermissionResult>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_PermissionResult_Statics::ClassParams = {
		&UPico_PermissionResult::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPico_PermissionResult_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPico_PermissionResult_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_PermissionResult_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_PermissionResult_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_PermissionResult_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPico_PermissionResult()
	{
		if (!Z_Registration_Info_UClass_UPico_PermissionResult.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_PermissionResult.OuterSingleton, Z_Construct_UClass_UPico_PermissionResult_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_PermissionResult.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_PermissionResult>()
	{
		return UPico_PermissionResult::StaticClass();
	}
	UPico_PermissionResult::UPico_PermissionResult(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_PermissionResult);
	UPico_PermissionResult::~UPico_PermissionResult() {}
	DEFINE_FUNCTION(UPico_UserRelationResult::execGetRelationTypeValue)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Key);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EUserRelationType*)Z_Param__Result=P_THIS->GetRelationTypeValue(Z_Param_Key);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_UserRelationResult::execGetRelationMapSize)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetRelationMapSize();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_UserRelationResult::execGetUserID)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetUserID(Z_Param_Index);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_UserRelationResult::execContains)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Key);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->Contains(Z_Param_Key);
		P_NATIVE_END;
	}
	void UPico_UserRelationResult::StaticRegisterNativesUPico_UserRelationResult()
	{
		UClass* Class = UPico_UserRelationResult::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Contains", &UPico_UserRelationResult::execContains },
			{ "GetRelationMapSize", &UPico_UserRelationResult::execGetRelationMapSize },
			{ "GetRelationTypeValue", &UPico_UserRelationResult::execGetRelationTypeValue },
			{ "GetUserID", &UPico_UserRelationResult::execGetUserID },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_UserRelationResult_Contains_Statics
	{
		struct Pico_UserRelationResult_eventContains_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_UserRelationResult_Contains_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_UserRelationResult_eventContains_Parms, Key), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_UserRelationResult_Contains_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_UserRelationResult_eventContains_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_UserRelationResult_Contains_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_UserRelationResult_Contains_Statics::NewProp_Key,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_UserRelationResult_Contains_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_UserRelationResult_Contains_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|UserRelationResult" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief With UserId as the key, find its index in the UserRelationMap data structure.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief With UserId as the key, find its index in the UserRelationMap data structure." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_UserRelationResult_Contains_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_UserRelationResult, nullptr, "Contains", nullptr, nullptr, Z_Construct_UFunction_UPico_UserRelationResult_Contains_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserRelationResult_Contains_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_UserRelationResult_Contains_Statics::Pico_UserRelationResult_eventContains_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserRelationResult_Contains_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_UserRelationResult_Contains_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserRelationResult_Contains_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_UserRelationResult_Contains_Statics::Pico_UserRelationResult_eventContains_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_UserRelationResult_Contains()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_UserRelationResult_Contains_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_UserRelationResult_GetRelationMapSize_Statics
	{
		struct Pico_UserRelationResult_eventGetRelationMapSize_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_UserRelationResult_GetRelationMapSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_UserRelationResult_eventGetRelationMapSize_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_UserRelationResult_GetRelationMapSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_UserRelationResult_GetRelationMapSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_UserRelationResult_GetRelationMapSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|UserRelationResult" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get the size of UserRelationMap .*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get the size of UserRelationMap ." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_UserRelationResult_GetRelationMapSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_UserRelationResult, nullptr, "GetRelationMapSize", nullptr, nullptr, Z_Construct_UFunction_UPico_UserRelationResult_GetRelationMapSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserRelationResult_GetRelationMapSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_UserRelationResult_GetRelationMapSize_Statics::Pico_UserRelationResult_eventGetRelationMapSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserRelationResult_GetRelationMapSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_UserRelationResult_GetRelationMapSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserRelationResult_GetRelationMapSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_UserRelationResult_GetRelationMapSize_Statics::Pico_UserRelationResult_eventGetRelationMapSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_UserRelationResult_GetRelationMapSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_UserRelationResult_GetRelationMapSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_UserRelationResult_GetRelationTypeValue_Statics
	{
		struct Pico_UserRelationResult_eventGetRelationTypeValue_Parms
		{
			FString Key;
			EUserRelationType ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_Key;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_UserRelationResult_GetRelationTypeValue_Statics::NewProp_Key = { "Key", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_UserRelationResult_eventGetRelationTypeValue_Parms, Key), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPico_UserRelationResult_GetRelationTypeValue_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPico_UserRelationResult_GetRelationTypeValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_UserRelationResult_eventGetRelationTypeValue_Parms, ReturnValue), Z_Construct_UEnum_OnlineSubsystemPico_EUserRelationType, METADATA_PARAMS(0, nullptr) }; // 3571987254
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_UserRelationResult_GetRelationTypeValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_UserRelationResult_GetRelationTypeValue_Statics::NewProp_Key,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_UserRelationResult_GetRelationTypeValue_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_UserRelationResult_GetRelationTypeValue_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_UserRelationResult_GetRelationTypeValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|UserRelationResult" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief With UserId as the key, find its value in the UserRelationMap data structure.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief With UserId as the key, find its value in the UserRelationMap data structure." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_UserRelationResult_GetRelationTypeValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_UserRelationResult, nullptr, "GetRelationTypeValue", nullptr, nullptr, Z_Construct_UFunction_UPico_UserRelationResult_GetRelationTypeValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserRelationResult_GetRelationTypeValue_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_UserRelationResult_GetRelationTypeValue_Statics::Pico_UserRelationResult_eventGetRelationTypeValue_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserRelationResult_GetRelationTypeValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_UserRelationResult_GetRelationTypeValue_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserRelationResult_GetRelationTypeValue_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_UserRelationResult_GetRelationTypeValue_Statics::Pico_UserRelationResult_eventGetRelationTypeValue_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_UserRelationResult_GetRelationTypeValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_UserRelationResult_GetRelationTypeValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_UserRelationResult_GetUserID_Statics
	{
		struct Pico_UserRelationResult_eventGetUserID_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_UserRelationResult_GetUserID_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_UserRelationResult_eventGetUserID_Parms, Index), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_UserRelationResult_GetUserID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_UserRelationResult_eventGetUserID_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_UserRelationResult_GetUserID_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_UserRelationResult_GetUserID_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_UserRelationResult_GetUserID_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_UserRelationResult_GetUserID_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|UserRelationResult" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Find the user ID in the corresponding UserIDArray through the index.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Find the user ID in the corresponding UserIDArray through the index." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_UserRelationResult_GetUserID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_UserRelationResult, nullptr, "GetUserID", nullptr, nullptr, Z_Construct_UFunction_UPico_UserRelationResult_GetUserID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserRelationResult_GetUserID_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_UserRelationResult_GetUserID_Statics::Pico_UserRelationResult_eventGetUserID_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserRelationResult_GetUserID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_UserRelationResult_GetUserID_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_UserRelationResult_GetUserID_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_UserRelationResult_GetUserID_Statics::Pico_UserRelationResult_eventGetUserID_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_UserRelationResult_GetUserID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_UserRelationResult_GetUserID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_UserRelationResult);
	UClass* Z_Construct_UClass_UPico_UserRelationResult_NoRegister()
	{
		return UPico_UserRelationResult::StaticClass();
	}
	struct Z_Construct_UClass_UPico_UserRelationResult_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_UserRelationMap_ValueProp_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_UserRelationMap_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_UserRelationMap_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UserRelationMap_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_UserRelationMap;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_UserRelationResult_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserRelationResult_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_UserRelationResult_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_UserRelationResult_Contains, "Contains" }, // 1346184249
		{ &Z_Construct_UFunction_UPico_UserRelationResult_GetRelationMapSize, "GetRelationMapSize" }, // 2498941170
		{ &Z_Construct_UFunction_UPico_UserRelationResult_GetRelationTypeValue, "GetRelationTypeValue" }, // 3272293596
		{ &Z_Construct_UFunction_UPico_UserRelationResult_GetUserID, "GetUserID" }, // 2123948403
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserRelationResult_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_UserRelationResult_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_UserRelationResult class.\n" },
#endif
		{ "IncludePath", "Pico_User.h" },
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_UserRelationResult class." },
#endif
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPico_UserRelationResult_Statics::NewProp_UserRelationMap_ValueProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UPico_UserRelationResult_Statics::NewProp_UserRelationMap_ValueProp = { "UserRelationMap", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UEnum_OnlineSubsystemPico_EUserRelationType, METADATA_PARAMS(0, nullptr) }; // 3571987254
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UPico_UserRelationResult_Statics::NewProp_UserRelationMap_Key_KeyProp = { "UserRelationMap_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_UserRelationResult_Statics::NewProp_UserRelationMap_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//  <UserId, Userrelationtype>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<UserId, Userrelationtype>" },
#endif
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UPico_UserRelationResult_Statics::NewProp_UserRelationMap = { "UserRelationMap", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPico_UserRelationResult, UserRelationMap), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserRelationResult_Statics::NewProp_UserRelationMap_MetaData), Z_Construct_UClass_UPico_UserRelationResult_Statics::NewProp_UserRelationMap_MetaData) }; // 3571987254
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPico_UserRelationResult_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_UserRelationResult_Statics::NewProp_UserRelationMap_ValueProp_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_UserRelationResult_Statics::NewProp_UserRelationMap_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_UserRelationResult_Statics::NewProp_UserRelationMap_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_UserRelationResult_Statics::NewProp_UserRelationMap,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_UserRelationResult_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_UserRelationResult>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_UserRelationResult_Statics::ClassParams = {
		&UPico_UserRelationResult::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPico_UserRelationResult_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserRelationResult_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserRelationResult_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_UserRelationResult_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_UserRelationResult_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPico_UserRelationResult()
	{
		if (!Z_Registration_Info_UClass_UPico_UserRelationResult.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_UserRelationResult.OuterSingleton, Z_Construct_UClass_UPico_UserRelationResult_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_UserRelationResult.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_UserRelationResult>()
	{
		return UPico_UserRelationResult::StaticClass();
	}
	UPico_UserRelationResult::UPico_UserRelationResult(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_UserRelationResult);
	UPico_UserRelationResult::~UPico_UserRelationResult() {}
	DEFINE_FUNCTION(UPico_EntitlementCheckResult::execGetStatusMessage)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetStatusMessage();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_EntitlementCheckResult::execGetStatusCode)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetStatusCode();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_EntitlementCheckResult::execGetHasEntitlement)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetHasEntitlement();
		P_NATIVE_END;
	}
	void UPico_EntitlementCheckResult::StaticRegisterNativesUPico_EntitlementCheckResult()
	{
		UClass* Class = UPico_EntitlementCheckResult::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetHasEntitlement", &UPico_EntitlementCheckResult::execGetHasEntitlement },
			{ "GetStatusCode", &UPico_EntitlementCheckResult::execGetStatusCode },
			{ "GetStatusMessage", &UPico_EntitlementCheckResult::execGetStatusMessage },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_EntitlementCheckResult_GetHasEntitlement_Statics
	{
		struct Pico_EntitlementCheckResult_eventGetHasEntitlement_Parms
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
	void Z_Construct_UFunction_UPico_EntitlementCheckResult_GetHasEntitlement_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_EntitlementCheckResult_eventGetHasEntitlement_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_EntitlementCheckResult_GetHasEntitlement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_EntitlementCheckResult_eventGetHasEntitlement_Parms), &Z_Construct_UFunction_UPico_EntitlementCheckResult_GetHasEntitlement_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_EntitlementCheckResult_GetHasEntitlement_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_EntitlementCheckResult_GetHasEntitlement_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_EntitlementCheckResult_GetHasEntitlement_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|EntitlementCheckResult" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Gets whether the user has the entitlement.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Gets whether the user has the entitlement." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_EntitlementCheckResult_GetHasEntitlement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_EntitlementCheckResult, nullptr, "GetHasEntitlement", nullptr, nullptr, Z_Construct_UFunction_UPico_EntitlementCheckResult_GetHasEntitlement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_EntitlementCheckResult_GetHasEntitlement_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_EntitlementCheckResult_GetHasEntitlement_Statics::Pico_EntitlementCheckResult_eventGetHasEntitlement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_EntitlementCheckResult_GetHasEntitlement_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_EntitlementCheckResult_GetHasEntitlement_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_EntitlementCheckResult_GetHasEntitlement_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_EntitlementCheckResult_GetHasEntitlement_Statics::Pico_EntitlementCheckResult_eventGetHasEntitlement_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_EntitlementCheckResult_GetHasEntitlement()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_EntitlementCheckResult_GetHasEntitlement_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusCode_Statics
	{
		struct Pico_EntitlementCheckResult_eventGetStatusCode_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusCode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_EntitlementCheckResult_eventGetStatusCode_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusCode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusCode_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusCode_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|EntitlementCheckResult" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get the status code of the current result.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get the status code of the current result." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusCode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_EntitlementCheckResult, nullptr, "GetStatusCode", nullptr, nullptr, Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusCode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusCode_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusCode_Statics::Pico_EntitlementCheckResult_eventGetStatusCode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusCode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusCode_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusCode_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusCode_Statics::Pico_EntitlementCheckResult_eventGetStatusCode_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusCode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusCode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusMessage_Statics
	{
		struct Pico_EntitlementCheckResult_eventGetStatusMessage_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusMessage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_EntitlementCheckResult_eventGetStatusMessage_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusMessage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusMessage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusMessage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|EntitlementCheckResult" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get the status message of the current result.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get the status message of the current result." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusMessage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_EntitlementCheckResult, nullptr, "GetStatusMessage", nullptr, nullptr, Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusMessage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusMessage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusMessage_Statics::Pico_EntitlementCheckResult_eventGetStatusMessage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusMessage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusMessage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusMessage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusMessage_Statics::Pico_EntitlementCheckResult_eventGetStatusMessage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusMessage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusMessage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_EntitlementCheckResult);
	UClass* Z_Construct_UClass_UPico_EntitlementCheckResult_NoRegister()
	{
		return UPico_EntitlementCheckResult::StaticClass();
	}
	struct Z_Construct_UClass_UPico_EntitlementCheckResult_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_EntitlementCheckResult_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_EntitlementCheckResult_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_EntitlementCheckResult_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_EntitlementCheckResult_GetHasEntitlement, "GetHasEntitlement" }, // 3681807437
		{ &Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusCode, "GetStatusCode" }, // 2695628443
		{ &Z_Construct_UFunction_UPico_EntitlementCheckResult_GetStatusMessage, "GetStatusMessage" }, // 2678647292
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_EntitlementCheckResult_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_EntitlementCheckResult_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_EntitlementCheckResult class.\n" },
#endif
		{ "IncludePath", "Pico_User.h" },
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_EntitlementCheckResult class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_EntitlementCheckResult_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_EntitlementCheckResult>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_EntitlementCheckResult_Statics::ClassParams = {
		&UPico_EntitlementCheckResult::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_EntitlementCheckResult_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_EntitlementCheckResult_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPico_EntitlementCheckResult()
	{
		if (!Z_Registration_Info_UClass_UPico_EntitlementCheckResult.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_EntitlementCheckResult.OuterSingleton, Z_Construct_UClass_UPico_EntitlementCheckResult_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_EntitlementCheckResult.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_EntitlementCheckResult>()
	{
		return UPico_EntitlementCheckResult::StaticClass();
	}
	UPico_EntitlementCheckResult::UPico_EntitlementCheckResult(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_EntitlementCheckResult);
	UPico_EntitlementCheckResult::~UPico_EntitlementCheckResult() {}
	DEFINE_FUNCTION(UPico_OrgScopedID::execGetID)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetID();
		P_NATIVE_END;
	}
	void UPico_OrgScopedID::StaticRegisterNativesUPico_OrgScopedID()
	{
		UClass* Class = UPico_OrgScopedID::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetID", &UPico_OrgScopedID::execGetID },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_OrgScopedID_GetID_Statics
	{
		struct Pico_OrgScopedID_eventGetID_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_OrgScopedID_GetID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_OrgScopedID_eventGetID_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_OrgScopedID_GetID_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_OrgScopedID_GetID_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_OrgScopedID_GetID_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|User|OrgScopedID" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get the org scoped id of the current result.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get the org scoped id of the current result." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_OrgScopedID_GetID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_OrgScopedID, nullptr, "GetID", nullptr, nullptr, Z_Construct_UFunction_UPico_OrgScopedID_GetID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_OrgScopedID_GetID_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_OrgScopedID_GetID_Statics::Pico_OrgScopedID_eventGetID_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_OrgScopedID_GetID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_OrgScopedID_GetID_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_OrgScopedID_GetID_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_OrgScopedID_GetID_Statics::Pico_OrgScopedID_eventGetID_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_OrgScopedID_GetID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_OrgScopedID_GetID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_OrgScopedID);
	UClass* Z_Construct_UClass_UPico_OrgScopedID_NoRegister()
	{
		return UPico_OrgScopedID::StaticClass();
	}
	struct Z_Construct_UClass_UPico_OrgScopedID_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_OrgScopedID_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_OrgScopedID_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_OrgScopedID_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_OrgScopedID_GetID, "GetID" }, // 2650718025
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_OrgScopedID_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_OrgScopedID_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_OrgScopedID class.\n" },
#endif
		{ "IncludePath", "Pico_User.h" },
		{ "ModuleRelativePath", "Public/Pico_User.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_OrgScopedID class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_OrgScopedID_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_OrgScopedID>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_OrgScopedID_Statics::ClassParams = {
		&UPico_OrgScopedID::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_OrgScopedID_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_OrgScopedID_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPico_OrgScopedID()
	{
		if (!Z_Registration_Info_UClass_UPico_OrgScopedID.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_OrgScopedID.OuterSingleton, Z_Construct_UClass_UPico_OrgScopedID_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_OrgScopedID.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_OrgScopedID>()
	{
		return UPico_OrgScopedID::StaticClass();
	}
	UPico_OrgScopedID::UPico_OrgScopedID(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_OrgScopedID);
	UPico_OrgScopedID::~UPico_OrgScopedID() {}
	struct Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_User_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_User_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOnlinePicoUserFunction, UOnlinePicoUserFunction::StaticClass, TEXT("UOnlinePicoUserFunction"), &Z_Registration_Info_UClass_UOnlinePicoUserFunction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOnlinePicoUserFunction), 2238411291U) },
		{ Z_Construct_UClass_UPico_User, UPico_User::StaticClass, TEXT("UPico_User"), &Z_Registration_Info_UClass_UPico_User, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_User), 3550519040U) },
		{ Z_Construct_UClass_UPico_UserArray, UPico_UserArray::StaticClass, TEXT("UPico_UserArray"), &Z_Registration_Info_UClass_UPico_UserArray, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_UserArray), 3587182404U) },
		{ Z_Construct_UClass_UPico_UserAndRoom, UPico_UserAndRoom::StaticClass, TEXT("UPico_UserAndRoom"), &Z_Registration_Info_UClass_UPico_UserAndRoom, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_UserAndRoom), 3223165165U) },
		{ Z_Construct_UClass_UPico_UserAndRoomArray, UPico_UserAndRoomArray::StaticClass, TEXT("UPico_UserAndRoomArray"), &Z_Registration_Info_UClass_UPico_UserAndRoomArray, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_UserAndRoomArray), 2833854250U) },
		{ Z_Construct_UClass_UPico_PermissionResult, UPico_PermissionResult::StaticClass, TEXT("UPico_PermissionResult"), &Z_Registration_Info_UClass_UPico_PermissionResult, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_PermissionResult), 4222325045U) },
		{ Z_Construct_UClass_UPico_UserRelationResult, UPico_UserRelationResult::StaticClass, TEXT("UPico_UserRelationResult"), &Z_Registration_Info_UClass_UPico_UserRelationResult, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_UserRelationResult), 1499131383U) },
		{ Z_Construct_UClass_UPico_EntitlementCheckResult, UPico_EntitlementCheckResult::StaticClass, TEXT("UPico_EntitlementCheckResult"), &Z_Registration_Info_UClass_UPico_EntitlementCheckResult, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_EntitlementCheckResult), 317021137U) },
		{ Z_Construct_UClass_UPico_OrgScopedID, UPico_OrgScopedID::StaticClass, TEXT("UPico_OrgScopedID"), &Z_Registration_Info_UClass_UPico_OrgScopedID, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_OrgScopedID), 1599959884U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_User_h_2567409189(TEXT("/Script/OnlineSubsystemPico"),
		Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_User_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_User_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
