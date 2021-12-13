// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Source/Public/OnlinePicoFunctionLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOnlinePicoFunctionLibrary() {}
// Cross Module References
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoVerifyAppDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemPico();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoFunctionLibrary_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentExceptionDelegate__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentLogInOrOutDelegate__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentGetUserInfoDelegate__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UScriptStruct* Z_Construct_UScriptStruct_FOnlinePicoCoinOrderInfo();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentPayOrderDelegate__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UScriptStruct* Z_Construct_UScriptStruct_FOnlinePicoPayCodeOrderInfo();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentQueryOrderDelegate__DelegateSignature();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoVerifyAppDelegate__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventOnlinePicoVerifyAppDelegate_Parms
		{
			int32 code;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_code_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_code;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoVerifyAppDelegate__DelegateSignature_Statics::NewProp_code_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoVerifyAppDelegate__DelegateSignature_Statics::NewProp_code = { "code", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventOnlinePicoVerifyAppDelegate_Parms, code), METADATA_PARAMS(Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoVerifyAppDelegate__DelegateSignature_Statics::NewProp_code_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoVerifyAppDelegate__DelegateSignature_Statics::NewProp_code_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoVerifyAppDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoVerifyAppDelegate__DelegateSignature_Statics::NewProp_code,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoVerifyAppDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/OnlinePicoFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoVerifyAppDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "OnlinePicoVerifyAppDelegate__DelegateSignature", nullptr, nullptr, sizeof(_Script_OnlineSubsystemPico_eventOnlinePicoVerifyAppDelegate_Parms), Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoVerifyAppDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoVerifyAppDelegate__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoVerifyAppDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoVerifyAppDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoVerifyAppDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoVerifyAppDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(UOnlinePicoFunctionLibrary::execPicoGetDeviceSN)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UOnlinePicoFunctionLibrary::PicoGetDeviceSN();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoFunctionLibrary::execPicoEntitlementVerifyCheck)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoFunctionLibrary::PicoEntitlementVerifyCheck();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoFunctionLibrary::execPicoEntitlementVerifyAppDelegate)
	{
		P_GET_PROPERTY(FDelegateProperty,Z_Param_OnVerifyAppCallback);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoFunctionLibrary::PicoEntitlementVerifyAppDelegate(FOnlinePicoVerifyAppDelegate(Z_Param_OnVerifyAppCallback));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoFunctionLibrary::execPicoBindPaymentExceptionDelegate)
	{
		P_GET_PROPERTY(FDelegateProperty,Z_Param_ExceptionDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoFunctionLibrary::PicoBindPaymentExceptionDelegate(FOnlinePicoPaymentExceptionDelegate(Z_Param_ExceptionDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoFunctionLibrary::execPicoPaymentQueryOrder)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_OrderNumber);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_QueryOrderDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoFunctionLibrary::PicoPaymentQueryOrder(Z_Param_OrderNumber,FOnlinePicoPaymentQueryOrderDelegate(Z_Param_QueryOrderDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoFunctionLibrary::execPicoPaymentPayWithPayCode)
	{
		P_GET_STRUCT(FOnlinePicoPayCodeOrderInfo,Z_Param_Order);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_PayOrderWithCodeDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoFunctionLibrary::PicoPaymentPayWithPayCode(Z_Param_Order,FOnlinePicoPaymentPayOrderDelegate(Z_Param_PayOrderWithCodeDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoFunctionLibrary::execPicoPaymentPayWithCoin)
	{
		P_GET_STRUCT(FOnlinePicoCoinOrderInfo,Z_Param_Order);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_PayOrderWithCoinDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoFunctionLibrary::PicoPaymentPayWithCoin(Z_Param_Order,FOnlinePicoPaymentPayOrderDelegate(Z_Param_PayOrderWithCoinDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoFunctionLibrary::execPicoPaymentGetUserInfo)
	{
		P_GET_PROPERTY(FDelegateProperty,Z_Param_UserInfoDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoFunctionLibrary::PicoPaymentGetUserInfo(FOnlinePicoPaymentGetUserInfoDelegate(Z_Param_UserInfoDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoFunctionLibrary::execPicoSDKGetUserInfo)
	{
		P_GET_PROPERTY(FDelegateProperty,Z_Param_UserInfoDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoFunctionLibrary::PicoSDKGetUserInfo(FOnlinePicoPaymentGetUserInfoDelegate(Z_Param_UserInfoDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoFunctionLibrary::execPicoPaymentLogout)
	{
		P_GET_PROPERTY(FDelegateProperty,Z_Param_LogOutDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoFunctionLibrary::PicoPaymentLogout(FOnlinePicoPaymentLogInOrOutDelegate(Z_Param_LogOutDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoFunctionLibrary::execPicoLogoutSDK)
	{
		P_GET_PROPERTY(FDelegateProperty,Z_Param_LogOutDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoFunctionLibrary::PicoLogoutSDK(FOnlinePicoPaymentLogInOrOutDelegate(Z_Param_LogOutDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoFunctionLibrary::execPicoPaymentLogin)
	{
		P_GET_PROPERTY(FDelegateProperty,Z_Param_LogInDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoFunctionLibrary::PicoPaymentLogin(FOnlinePicoPaymentLogInOrOutDelegate(Z_Param_LogInDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoFunctionLibrary::execPicoLoginSDK)
	{
		P_GET_PROPERTY(FDelegateProperty,Z_Param_LogInDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoFunctionLibrary::PicoLoginSDK(FOnlinePicoPaymentLogInOrOutDelegate(Z_Param_LogInDelegate));
		P_NATIVE_END;
	}
	void UOnlinePicoFunctionLibrary::StaticRegisterNativesUOnlinePicoFunctionLibrary()
	{
		UClass* Class = UOnlinePicoFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "PicoBindPaymentExceptionDelegate", &UOnlinePicoFunctionLibrary::execPicoBindPaymentExceptionDelegate },
			{ "PicoEntitlementVerifyAppDelegate", &UOnlinePicoFunctionLibrary::execPicoEntitlementVerifyAppDelegate },
			{ "PicoEntitlementVerifyCheck", &UOnlinePicoFunctionLibrary::execPicoEntitlementVerifyCheck },
			{ "PicoGetDeviceSN", &UOnlinePicoFunctionLibrary::execPicoGetDeviceSN },
			{ "PicoLoginSDK", &UOnlinePicoFunctionLibrary::execPicoLoginSDK },
			{ "PicoLogoutSDK", &UOnlinePicoFunctionLibrary::execPicoLogoutSDK },
			{ "PicoPaymentGetUserInfo", &UOnlinePicoFunctionLibrary::execPicoPaymentGetUserInfo },
			{ "PicoPaymentLogin", &UOnlinePicoFunctionLibrary::execPicoPaymentLogin },
			{ "PicoPaymentLogout", &UOnlinePicoFunctionLibrary::execPicoPaymentLogout },
			{ "PicoPaymentPayWithCoin", &UOnlinePicoFunctionLibrary::execPicoPaymentPayWithCoin },
			{ "PicoPaymentPayWithPayCode", &UOnlinePicoFunctionLibrary::execPicoPaymentPayWithPayCode },
			{ "PicoPaymentQueryOrder", &UOnlinePicoFunctionLibrary::execPicoPaymentQueryOrder },
			{ "PicoSDKGetUserInfo", &UOnlinePicoFunctionLibrary::execPicoSDKGetUserInfo },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoBindPaymentExceptionDelegate_Statics
	{
		struct OnlinePicoFunctionLibrary_eventPicoBindPaymentExceptionDelegate_Parms
		{
			FScriptDelegate ExceptionDelegate;
		};
		static const UE4CodeGen_Private::FDelegatePropertyParams NewProp_ExceptionDelegate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoBindPaymentExceptionDelegate_Statics::NewProp_ExceptionDelegate = { "ExceptionDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OnlinePicoFunctionLibrary_eventPicoBindPaymentExceptionDelegate_Parms, ExceptionDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentExceptionDelegate__DelegateSignature, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoBindPaymentExceptionDelegate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoBindPaymentExceptionDelegate_Statics::NewProp_ExceptionDelegate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoBindPaymentExceptionDelegate_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|PicoPayment" },
		{ "ModuleRelativePath", "Public/OnlinePicoFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoBindPaymentExceptionDelegate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoFunctionLibrary, nullptr, "PicoBindPaymentExceptionDelegate", nullptr, nullptr, sizeof(OnlinePicoFunctionLibrary_eventPicoBindPaymentExceptionDelegate_Parms), Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoBindPaymentExceptionDelegate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoBindPaymentExceptionDelegate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoBindPaymentExceptionDelegate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoBindPaymentExceptionDelegate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoBindPaymentExceptionDelegate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoBindPaymentExceptionDelegate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoEntitlementVerifyAppDelegate_Statics
	{
		struct OnlinePicoFunctionLibrary_eventPicoEntitlementVerifyAppDelegate_Parms
		{
			FScriptDelegate OnVerifyAppCallback;
		};
		static const UE4CodeGen_Private::FDelegatePropertyParams NewProp_OnVerifyAppCallback;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoEntitlementVerifyAppDelegate_Statics::NewProp_OnVerifyAppCallback = { "OnVerifyAppCallback", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OnlinePicoFunctionLibrary_eventPicoEntitlementVerifyAppDelegate_Parms, OnVerifyAppCallback), Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoVerifyAppDelegate__DelegateSignature, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoEntitlementVerifyAppDelegate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoEntitlementVerifyAppDelegate_Statics::NewProp_OnVerifyAppCallback,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoEntitlementVerifyAppDelegate_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|PicoEntitlement" },
		{ "ModuleRelativePath", "Public/OnlinePicoFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoEntitlementVerifyAppDelegate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoFunctionLibrary, nullptr, "PicoEntitlementVerifyAppDelegate", nullptr, nullptr, sizeof(OnlinePicoFunctionLibrary_eventPicoEntitlementVerifyAppDelegate_Parms), Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoEntitlementVerifyAppDelegate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoEntitlementVerifyAppDelegate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoEntitlementVerifyAppDelegate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoEntitlementVerifyAppDelegate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoEntitlementVerifyAppDelegate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoEntitlementVerifyAppDelegate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoEntitlementVerifyCheck_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoEntitlementVerifyCheck_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|PicoEntitlement" },
		{ "ModuleRelativePath", "Public/OnlinePicoFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoEntitlementVerifyCheck_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoFunctionLibrary, nullptr, "PicoEntitlementVerifyCheck", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoEntitlementVerifyCheck_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoEntitlementVerifyCheck_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoEntitlementVerifyCheck()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoEntitlementVerifyCheck_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoGetDeviceSN_Statics
	{
		struct OnlinePicoFunctionLibrary_eventPicoGetDeviceSN_Parms
		{
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoGetDeviceSN_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OnlinePicoFunctionLibrary_eventPicoGetDeviceSN_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoGetDeviceSN_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoGetDeviceSN_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoGetDeviceSN_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|PicoEntitlement" },
		{ "ModuleRelativePath", "Public/OnlinePicoFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoGetDeviceSN_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoFunctionLibrary, nullptr, "PicoGetDeviceSN", nullptr, nullptr, sizeof(OnlinePicoFunctionLibrary_eventPicoGetDeviceSN_Parms), Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoGetDeviceSN_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoGetDeviceSN_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoGetDeviceSN_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoGetDeviceSN_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoGetDeviceSN()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoGetDeviceSN_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLoginSDK_Statics
	{
		struct OnlinePicoFunctionLibrary_eventPicoLoginSDK_Parms
		{
			FScriptDelegate LogInDelegate;
		};
		static const UE4CodeGen_Private::FDelegatePropertyParams NewProp_LogInDelegate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLoginSDK_Statics::NewProp_LogInDelegate = { "LogInDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OnlinePicoFunctionLibrary_eventPicoLoginSDK_Parms, LogInDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentLogInOrOutDelegate__DelegateSignature, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLoginSDK_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLoginSDK_Statics::NewProp_LogInDelegate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLoginSDK_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|PicoPayment" },
		{ "ModuleRelativePath", "Public/OnlinePicoFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLoginSDK_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoFunctionLibrary, nullptr, "PicoLoginSDK", nullptr, nullptr, sizeof(OnlinePicoFunctionLibrary_eventPicoLoginSDK_Parms), Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLoginSDK_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLoginSDK_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLoginSDK_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLoginSDK_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLoginSDK()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLoginSDK_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLogoutSDK_Statics
	{
		struct OnlinePicoFunctionLibrary_eventPicoLogoutSDK_Parms
		{
			FScriptDelegate LogOutDelegate;
		};
		static const UE4CodeGen_Private::FDelegatePropertyParams NewProp_LogOutDelegate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLogoutSDK_Statics::NewProp_LogOutDelegate = { "LogOutDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OnlinePicoFunctionLibrary_eventPicoLogoutSDK_Parms, LogOutDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentLogInOrOutDelegate__DelegateSignature, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLogoutSDK_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLogoutSDK_Statics::NewProp_LogOutDelegate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLogoutSDK_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|PicoPayment" },
		{ "ModuleRelativePath", "Public/OnlinePicoFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLogoutSDK_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoFunctionLibrary, nullptr, "PicoLogoutSDK", nullptr, nullptr, sizeof(OnlinePicoFunctionLibrary_eventPicoLogoutSDK_Parms), Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLogoutSDK_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLogoutSDK_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLogoutSDK_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLogoutSDK_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLogoutSDK()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLogoutSDK_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentGetUserInfo_Statics
	{
		struct OnlinePicoFunctionLibrary_eventPicoPaymentGetUserInfo_Parms
		{
			FScriptDelegate UserInfoDelegate;
		};
		static const UE4CodeGen_Private::FDelegatePropertyParams NewProp_UserInfoDelegate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentGetUserInfo_Statics::NewProp_UserInfoDelegate = { "UserInfoDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OnlinePicoFunctionLibrary_eventPicoPaymentGetUserInfo_Parms, UserInfoDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentGetUserInfoDelegate__DelegateSignature, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentGetUserInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentGetUserInfo_Statics::NewProp_UserInfoDelegate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentGetUserInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|PicoPayment" },
		{ "ModuleRelativePath", "Public/OnlinePicoFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentGetUserInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoFunctionLibrary, nullptr, "PicoPaymentGetUserInfo", nullptr, nullptr, sizeof(OnlinePicoFunctionLibrary_eventPicoPaymentGetUserInfo_Parms), Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentGetUserInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentGetUserInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentGetUserInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentGetUserInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentGetUserInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentGetUserInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogin_Statics
	{
		struct OnlinePicoFunctionLibrary_eventPicoPaymentLogin_Parms
		{
			FScriptDelegate LogInDelegate;
		};
		static const UE4CodeGen_Private::FDelegatePropertyParams NewProp_LogInDelegate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogin_Statics::NewProp_LogInDelegate = { "LogInDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OnlinePicoFunctionLibrary_eventPicoPaymentLogin_Parms, LogInDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentLogInOrOutDelegate__DelegateSignature, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogin_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogin_Statics::NewProp_LogInDelegate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogin_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|PicoPayment" },
		{ "ModuleRelativePath", "Public/OnlinePicoFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoFunctionLibrary, nullptr, "PicoPaymentLogin", nullptr, nullptr, sizeof(OnlinePicoFunctionLibrary_eventPicoPaymentLogin_Parms), Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogin_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogin_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogout_Statics
	{
		struct OnlinePicoFunctionLibrary_eventPicoPaymentLogout_Parms
		{
			FScriptDelegate LogOutDelegate;
		};
		static const UE4CodeGen_Private::FDelegatePropertyParams NewProp_LogOutDelegate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogout_Statics::NewProp_LogOutDelegate = { "LogOutDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OnlinePicoFunctionLibrary_eventPicoPaymentLogout_Parms, LogOutDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentLogInOrOutDelegate__DelegateSignature, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogout_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogout_Statics::NewProp_LogOutDelegate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogout_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|PicoPayment" },
		{ "ModuleRelativePath", "Public/OnlinePicoFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogout_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoFunctionLibrary, nullptr, "PicoPaymentLogout", nullptr, nullptr, sizeof(OnlinePicoFunctionLibrary_eventPicoPaymentLogout_Parms), Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogout_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogout_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogout_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogout_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogout()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogout_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithCoin_Statics
	{
		struct OnlinePicoFunctionLibrary_eventPicoPaymentPayWithCoin_Parms
		{
			FOnlinePicoCoinOrderInfo Order;
			FScriptDelegate PayOrderWithCoinDelegate;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Order;
		static const UE4CodeGen_Private::FDelegatePropertyParams NewProp_PayOrderWithCoinDelegate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithCoin_Statics::NewProp_Order = { "Order", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OnlinePicoFunctionLibrary_eventPicoPaymentPayWithCoin_Parms, Order), Z_Construct_UScriptStruct_FOnlinePicoCoinOrderInfo, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithCoin_Statics::NewProp_PayOrderWithCoinDelegate = { "PayOrderWithCoinDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OnlinePicoFunctionLibrary_eventPicoPaymentPayWithCoin_Parms, PayOrderWithCoinDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentPayOrderDelegate__DelegateSignature, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithCoin_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithCoin_Statics::NewProp_Order,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithCoin_Statics::NewProp_PayOrderWithCoinDelegate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithCoin_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|PicoPayment" },
		{ "ModuleRelativePath", "Public/OnlinePicoFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithCoin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoFunctionLibrary, nullptr, "PicoPaymentPayWithCoin", nullptr, nullptr, sizeof(OnlinePicoFunctionLibrary_eventPicoPaymentPayWithCoin_Parms), Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithCoin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithCoin_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithCoin_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithCoin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithCoin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithCoin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithPayCode_Statics
	{
		struct OnlinePicoFunctionLibrary_eventPicoPaymentPayWithPayCode_Parms
		{
			FOnlinePicoPayCodeOrderInfo Order;
			FScriptDelegate PayOrderWithCodeDelegate;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Order;
		static const UE4CodeGen_Private::FDelegatePropertyParams NewProp_PayOrderWithCodeDelegate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithPayCode_Statics::NewProp_Order = { "Order", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OnlinePicoFunctionLibrary_eventPicoPaymentPayWithPayCode_Parms, Order), Z_Construct_UScriptStruct_FOnlinePicoPayCodeOrderInfo, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithPayCode_Statics::NewProp_PayOrderWithCodeDelegate = { "PayOrderWithCodeDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OnlinePicoFunctionLibrary_eventPicoPaymentPayWithPayCode_Parms, PayOrderWithCodeDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentPayOrderDelegate__DelegateSignature, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithPayCode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithPayCode_Statics::NewProp_Order,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithPayCode_Statics::NewProp_PayOrderWithCodeDelegate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithPayCode_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|PicoPayment" },
		{ "ModuleRelativePath", "Public/OnlinePicoFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithPayCode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoFunctionLibrary, nullptr, "PicoPaymentPayWithPayCode", nullptr, nullptr, sizeof(OnlinePicoFunctionLibrary_eventPicoPaymentPayWithPayCode_Parms), Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithPayCode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithPayCode_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithPayCode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithPayCode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithPayCode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithPayCode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentQueryOrder_Statics
	{
		struct OnlinePicoFunctionLibrary_eventPicoPaymentQueryOrder_Parms
		{
			FString OrderNumber;
			FScriptDelegate QueryOrderDelegate;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_OrderNumber;
		static const UE4CodeGen_Private::FDelegatePropertyParams NewProp_QueryOrderDelegate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentQueryOrder_Statics::NewProp_OrderNumber = { "OrderNumber", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OnlinePicoFunctionLibrary_eventPicoPaymentQueryOrder_Parms, OrderNumber), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentQueryOrder_Statics::NewProp_QueryOrderDelegate = { "QueryOrderDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OnlinePicoFunctionLibrary_eventPicoPaymentQueryOrder_Parms, QueryOrderDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentQueryOrderDelegate__DelegateSignature, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentQueryOrder_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentQueryOrder_Statics::NewProp_OrderNumber,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentQueryOrder_Statics::NewProp_QueryOrderDelegate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentQueryOrder_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|PicoPayment" },
		{ "ModuleRelativePath", "Public/OnlinePicoFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentQueryOrder_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoFunctionLibrary, nullptr, "PicoPaymentQueryOrder", nullptr, nullptr, sizeof(OnlinePicoFunctionLibrary_eventPicoPaymentQueryOrder_Parms), Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentQueryOrder_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentQueryOrder_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentQueryOrder_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentQueryOrder_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentQueryOrder()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentQueryOrder_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoSDKGetUserInfo_Statics
	{
		struct OnlinePicoFunctionLibrary_eventPicoSDKGetUserInfo_Parms
		{
			FScriptDelegate UserInfoDelegate;
		};
		static const UE4CodeGen_Private::FDelegatePropertyParams NewProp_UserInfoDelegate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoSDKGetUserInfo_Statics::NewProp_UserInfoDelegate = { "UserInfoDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(OnlinePicoFunctionLibrary_eventPicoSDKGetUserInfo_Parms, UserInfoDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_OnlinePicoPaymentGetUserInfoDelegate__DelegateSignature, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoSDKGetUserInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoSDKGetUserInfo_Statics::NewProp_UserInfoDelegate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoSDKGetUserInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|PicoPayment" },
		{ "ModuleRelativePath", "Public/OnlinePicoFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoSDKGetUserInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoFunctionLibrary, nullptr, "PicoSDKGetUserInfo", nullptr, nullptr, sizeof(OnlinePicoFunctionLibrary_eventPicoSDKGetUserInfo_Parms), Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoSDKGetUserInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoSDKGetUserInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoSDKGetUserInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoSDKGetUserInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoSDKGetUserInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoSDKGetUserInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UOnlinePicoFunctionLibrary_NoRegister()
	{
		return UOnlinePicoFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UOnlinePicoFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOnlinePicoFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UOnlinePicoFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoBindPaymentExceptionDelegate, "PicoBindPaymentExceptionDelegate" }, // 702930485
		{ &Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoEntitlementVerifyAppDelegate, "PicoEntitlementVerifyAppDelegate" }, // 1781189017
		{ &Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoEntitlementVerifyCheck, "PicoEntitlementVerifyCheck" }, // 1979909984
		{ &Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoGetDeviceSN, "PicoGetDeviceSN" }, // 1516979155
		{ &Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLoginSDK, "PicoLoginSDK" }, // 1580700667
		{ &Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoLogoutSDK, "PicoLogoutSDK" }, // 248798933
		{ &Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentGetUserInfo, "PicoPaymentGetUserInfo" }, // 4220742091
		{ &Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogin, "PicoPaymentLogin" }, // 3243328398
		{ &Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentLogout, "PicoPaymentLogout" }, // 2271787014
		{ &Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithCoin, "PicoPaymentPayWithCoin" }, // 1305018114
		{ &Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentPayWithPayCode, "PicoPaymentPayWithPayCode" }, // 4147066167
		{ &Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoPaymentQueryOrder, "PicoPaymentQueryOrder" }, // 2628150471
		{ &Z_Construct_UFunction_UOnlinePicoFunctionLibrary_PicoSDKGetUserInfo, "PicoSDKGetUserInfo" }, // 4195979107
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "OnlinePicoFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/OnlinePicoFunctionLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOnlinePicoFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOnlinePicoFunctionLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UOnlinePicoFunctionLibrary_Statics::ClassParams = {
		&UOnlinePicoFunctionLibrary::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UOnlinePicoFunctionLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoFunctionLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOnlinePicoFunctionLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UOnlinePicoFunctionLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UOnlinePicoFunctionLibrary, 1033631725);
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UOnlinePicoFunctionLibrary>()
	{
		return UOnlinePicoFunctionLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UOnlinePicoFunctionLibrary(Z_Construct_UClass_UOnlinePicoFunctionLibrary, &UOnlinePicoFunctionLibrary::StaticClass, TEXT("/Script/OnlineSubsystemPico"), TEXT("UOnlinePicoFunctionLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOnlinePicoFunctionLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
