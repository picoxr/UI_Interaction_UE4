// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOnlineSubsystemPico_init() {}
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentLogInOrOutDelegate__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentGetUserInfoDelegate__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentPayOrderDelegate__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentQueryOrderDelegate__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentExceptionDelegate__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoVerifyAppDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemPico()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentLogInOrOutDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentGetUserInfoDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentPayOrderDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentQueryOrderDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentExceptionDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoVerifyAppDelegate__DelegateSignature,
			};
			static const UE4CodeGen_Private::FPackageParams PackageParams = {
				"/Script/OnlineSubsystemPico",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x02AD2524,
				0x63998E7F,
				METADATA_PARAMS(nullptr, 0)
			};
			UE4CodeGen_Private::ConstructUPackage(ReturnPackage, PackageParams);
		}
		return ReturnPackage;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
