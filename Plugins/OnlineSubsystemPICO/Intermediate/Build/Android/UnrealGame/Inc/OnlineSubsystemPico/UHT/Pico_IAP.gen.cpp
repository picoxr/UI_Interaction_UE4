// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../OnlineSubsystemPico/Public/Pico_IAP.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePico_IAP() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoIAPFunction();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoIAPFunction_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_Product();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_Product_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_ProductArray();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_ProductArray_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_Purchase();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_Purchase_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_PurchaseArray();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_PurchaseArray_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_SubscriptionStatus();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_SubscriptionStatus_NoRegister();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_EAddonsType();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ECancelReason();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_EDiscountType();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_EEntitlementStatus();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_EPeriodType();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature();
	ONLINESUBSYSTEMPICO_API UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemPico();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetProductsBySKUDelegate_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_ProductArray* ProductArray;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ProductArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetProductsBySKUDelegate_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetProductsBySKUDelegate_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetProductsBySKUDelegate_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature_Statics::NewProp_ProductArray = { "ProductArray", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetProductsBySKUDelegate_Parms, ProductArray), Z_Construct_UClass_UPico_ProductArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature_Statics::NewProp_ProductArray,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetProductsBySKUDelegate__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetProductsBySKUDelegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetProductsBySKUDelegate_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetProductsBySKUDelegate_DelegateWrapper(const FScriptDelegate& GetProductsBySKUDelegate, bool bIsError, const FString& ErrorMessage, UPico_ProductArray* ProductArray)
{
	struct _Script_OnlineSubsystemPico_eventGetProductsBySKUDelegate_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_ProductArray* ProductArray;
	};
	_Script_OnlineSubsystemPico_eventGetProductsBySKUDelegate_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.ProductArray=ProductArray;
	GetProductsBySKUDelegate.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetViewerPurchasesDelegate_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_PurchaseArray* PurchaseArray;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PurchaseArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetViewerPurchasesDelegate_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetViewerPurchasesDelegate_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetViewerPurchasesDelegate_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature_Statics::NewProp_PurchaseArray = { "PurchaseArray", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetViewerPurchasesDelegate_Parms, PurchaseArray), Z_Construct_UClass_UPico_PurchaseArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature_Statics::NewProp_PurchaseArray,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetViewerPurchasesDelegate__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetViewerPurchasesDelegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetViewerPurchasesDelegate_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetViewerPurchasesDelegate_DelegateWrapper(const FScriptDelegate& GetViewerPurchasesDelegate, bool bIsError, const FString& ErrorMessage, UPico_PurchaseArray* PurchaseArray)
{
	struct _Script_OnlineSubsystemPico_eventGetViewerPurchasesDelegate_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_PurchaseArray* PurchaseArray;
	};
	_Script_OnlineSubsystemPico_eventGetViewerPurchasesDelegate_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.PurchaseArray=PurchaseArray;
	GetViewerPurchasesDelegate.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetNextProductArrayPageDelegate_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_ProductArray* ProductArray;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ProductArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetNextProductArrayPageDelegate_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetNextProductArrayPageDelegate_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetNextProductArrayPageDelegate_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature_Statics::NewProp_ProductArray = { "ProductArray", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetNextProductArrayPageDelegate_Parms, ProductArray), Z_Construct_UClass_UPico_ProductArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature_Statics::NewProp_ProductArray,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetNextProductArrayPageDelegate__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetNextProductArrayPageDelegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetNextProductArrayPageDelegate_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetNextProductArrayPageDelegate_DelegateWrapper(const FScriptDelegate& GetNextProductArrayPageDelegate, bool bIsError, const FString& ErrorMessage, UPico_ProductArray* ProductArray)
{
	struct _Script_OnlineSubsystemPico_eventGetNextProductArrayPageDelegate_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_ProductArray* ProductArray;
	};
	_Script_OnlineSubsystemPico_eventGetNextProductArrayPageDelegate_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.ProductArray=ProductArray;
	GetNextProductArrayPageDelegate.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventConsumePurchaseDelegate_Parms
		{
			bool bIsError;
			FString ErrorMessage;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
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
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventConsumePurchaseDelegate_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventConsumePurchaseDelegate_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventConsumePurchaseDelegate_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature_Statics::NewProp_ErrorMessage,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "ConsumePurchaseDelegate__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventConsumePurchaseDelegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventConsumePurchaseDelegate_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FConsumePurchaseDelegate_DelegateWrapper(const FScriptDelegate& ConsumePurchaseDelegate, bool bIsError, const FString& ErrorMessage)
{
	struct _Script_OnlineSubsystemPico_eventConsumePurchaseDelegate_Parms
	{
		bool bIsError;
		FString ErrorMessage;
	};
	_Script_OnlineSubsystemPico_eventConsumePurchaseDelegate_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	ConsumePurchaseDelegate.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetNextPurchaseArrayPageDelegate_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_PurchaseArray* PurchaseArray;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PurchaseArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetNextPurchaseArrayPageDelegate_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetNextPurchaseArrayPageDelegate_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetNextPurchaseArrayPageDelegate_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature_Statics::NewProp_PurchaseArray = { "PurchaseArray", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetNextPurchaseArrayPageDelegate_Parms, PurchaseArray), Z_Construct_UClass_UPico_PurchaseArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature_Statics::NewProp_PurchaseArray,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetNextPurchaseArrayPageDelegate__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetNextPurchaseArrayPageDelegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetNextPurchaseArrayPageDelegate_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetNextPurchaseArrayPageDelegate_DelegateWrapper(const FScriptDelegate& GetNextPurchaseArrayPageDelegate, bool bIsError, const FString& ErrorMessage, UPico_PurchaseArray* PurchaseArray)
{
	struct _Script_OnlineSubsystemPico_eventGetNextPurchaseArrayPageDelegate_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_PurchaseArray* PurchaseArray;
	};
	_Script_OnlineSubsystemPico_eventGetNextPurchaseArrayPageDelegate_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.PurchaseArray=PurchaseArray;
	GetNextPurchaseArrayPageDelegate.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventLaunchCheckoutFlowDelegate_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_Purchase* Purchase;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Purchase;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventLaunchCheckoutFlowDelegate_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventLaunchCheckoutFlowDelegate_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventLaunchCheckoutFlowDelegate_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature_Statics::NewProp_Purchase = { "Purchase", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventLaunchCheckoutFlowDelegate_Parms, Purchase), Z_Construct_UClass_UPico_Purchase_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature_Statics::NewProp_Purchase,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "LaunchCheckoutFlowDelegate__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventLaunchCheckoutFlowDelegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventLaunchCheckoutFlowDelegate_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FLaunchCheckoutFlowDelegate_DelegateWrapper(const FScriptDelegate& LaunchCheckoutFlowDelegate, bool bIsError, const FString& ErrorMessage, UPico_Purchase* Purchase)
{
	struct _Script_OnlineSubsystemPico_eventLaunchCheckoutFlowDelegate_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_Purchase* Purchase;
	};
	_Script_OnlineSubsystemPico_eventLaunchCheckoutFlowDelegate_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.Purchase=Purchase;
	LaunchCheckoutFlowDelegate.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventLaunchCheckoutFlow_V2Delegate_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_Purchase* Purchase;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Purchase;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventLaunchCheckoutFlow_V2Delegate_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventLaunchCheckoutFlow_V2Delegate_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventLaunchCheckoutFlow_V2Delegate_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature_Statics::NewProp_Purchase = { "Purchase", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventLaunchCheckoutFlow_V2Delegate_Parms, Purchase), Z_Construct_UClass_UPico_Purchase_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature_Statics::NewProp_Purchase,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "LaunchCheckoutFlow_V2Delegate__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventLaunchCheckoutFlow_V2Delegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventLaunchCheckoutFlow_V2Delegate_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FLaunchCheckoutFlow_V2Delegate_DelegateWrapper(const FScriptDelegate& LaunchCheckoutFlow_V2Delegate, bool bIsError, const FString& ErrorMessage, UPico_Purchase* Purchase)
{
	struct _Script_OnlineSubsystemPico_eventLaunchCheckoutFlow_V2Delegate_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_Purchase* Purchase;
	};
	_Script_OnlineSubsystemPico_eventLaunchCheckoutFlow_V2Delegate_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.Purchase=Purchase;
	LaunchCheckoutFlow_V2Delegate.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventGetSubscriptionStatusDelegate_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_SubscriptionStatus* SubscriptionStatus;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SubscriptionStatus;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventGetSubscriptionStatusDelegate_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventGetSubscriptionStatusDelegate_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetSubscriptionStatusDelegate_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature_Statics::NewProp_SubscriptionStatus = { "SubscriptionStatus", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventGetSubscriptionStatusDelegate_Parms, SubscriptionStatus), Z_Construct_UClass_UPico_SubscriptionStatus_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature_Statics::NewProp_SubscriptionStatus,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "GetSubscriptionStatusDelegate__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetSubscriptionStatusDelegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventGetSubscriptionStatusDelegate_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FGetSubscriptionStatusDelegate_DelegateWrapper(const FScriptDelegate& GetSubscriptionStatusDelegate, bool bIsError, const FString& ErrorMessage, UPico_SubscriptionStatus* SubscriptionStatus)
{
	struct _Script_OnlineSubsystemPico_eventGetSubscriptionStatusDelegate_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_SubscriptionStatus* SubscriptionStatus;
	};
	_Script_OnlineSubsystemPico_eventGetSubscriptionStatusDelegate_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.SubscriptionStatus=SubscriptionStatus;
	GetSubscriptionStatusDelegate.ProcessDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature_Statics
	{
		struct _Script_OnlineSubsystemPico_eventLaunchCheckoutFlow_V3Delegate_Parms
		{
			bool bIsError;
			FString ErrorMessage;
			UPico_Purchase* Purchase;
		};
		static void NewProp_bIsError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Purchase;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature_Statics::NewProp_bIsError_SetBit(void* Obj)
	{
		((_Script_OnlineSubsystemPico_eventLaunchCheckoutFlow_V3Delegate_Parms*)Obj)->bIsError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature_Statics::NewProp_bIsError = { "bIsError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_OnlineSubsystemPico_eventLaunchCheckoutFlow_V3Delegate_Parms), &Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature_Statics::NewProp_bIsError_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventLaunchCheckoutFlow_V3Delegate_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData), Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature_Statics::NewProp_ErrorMessage_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature_Statics::NewProp_Purchase = { "Purchase", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_OnlineSubsystemPico_eventLaunchCheckoutFlow_V3Delegate_Parms, Purchase), Z_Construct_UClass_UPico_Purchase_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature_Statics::NewProp_bIsError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature_Statics::NewProp_ErrorMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature_Statics::NewProp_Purchase,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico, nullptr, "LaunchCheckoutFlow_V3Delegate__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventLaunchCheckoutFlow_V3Delegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature_Statics::_Script_OnlineSubsystemPico_eventLaunchCheckoutFlow_V3Delegate_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FLaunchCheckoutFlow_V3Delegate_DelegateWrapper(const FScriptDelegate& LaunchCheckoutFlow_V3Delegate, bool bIsError, const FString& ErrorMessage, UPico_Purchase* Purchase)
{
	struct _Script_OnlineSubsystemPico_eventLaunchCheckoutFlow_V3Delegate_Parms
	{
		bool bIsError;
		FString ErrorMessage;
		UPico_Purchase* Purchase;
	};
	_Script_OnlineSubsystemPico_eventLaunchCheckoutFlow_V3Delegate_Parms Parms;
	Parms.bIsError=bIsError ? true : false;
	Parms.ErrorMessage=ErrorMessage;
	Parms.Purchase=Purchase;
	LaunchCheckoutFlow_V3Delegate.ProcessDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UOnlinePicoIAPFunction::execLaunchCheckoutFlowV3)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_SKU);
		P_GET_PROPERTY(FStrProperty,Z_Param_Price);
		P_GET_PROPERTY(FStrProperty,Z_Param_Currency);
		P_GET_PROPERTY(FStrProperty,Z_Param_OuterId);
		P_GET_PROPERTY(FStrProperty,Z_Param_OrderComment);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InLaunchCheckoutFlow_V3Delegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoIAPFunction::LaunchCheckoutFlowV3(Z_Param_WorldContextObject,Z_Param_SKU,Z_Param_Price,Z_Param_Currency,Z_Param_OuterId,Z_Param_OrderComment,FLaunchCheckoutFlow_V3Delegate(Z_Param_InLaunchCheckoutFlow_V3Delegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoIAPFunction::execGetSubscriptionStatus)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_SKU);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetSubscriptionStatusDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoIAPFunction::GetSubscriptionStatus(Z_Param_WorldContextObject,Z_Param_SKU,FGetSubscriptionStatusDelegate(Z_Param_InGetSubscriptionStatusDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoIAPFunction::execLaunchCheckoutFlowV2)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_SKU);
		P_GET_PROPERTY(FStrProperty,Z_Param_Price);
		P_GET_PROPERTY(FStrProperty,Z_Param_Currency);
		P_GET_PROPERTY(FStrProperty,Z_Param_OuterId);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InLaunchCheckoutFlow_V2Delegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoIAPFunction::LaunchCheckoutFlowV2(Z_Param_WorldContextObject,Z_Param_SKU,Z_Param_Price,Z_Param_Currency,Z_Param_OuterId,FLaunchCheckoutFlow_V2Delegate(Z_Param_InLaunchCheckoutFlow_V2Delegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoIAPFunction::execLaunchCheckoutFlow)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_SKU);
		P_GET_PROPERTY(FStrProperty,Z_Param_Price);
		P_GET_PROPERTY(FStrProperty,Z_Param_Currency);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InLaunchCheckoutFlowDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoIAPFunction::LaunchCheckoutFlow(Z_Param_WorldContextObject,Z_Param_SKU,Z_Param_Price,Z_Param_Currency,FLaunchCheckoutFlowDelegate(Z_Param_InLaunchCheckoutFlowDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoIAPFunction::execGetNextPurchaseArrayPage)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_OBJECT(UPico_PurchaseArray,Z_Param_InPurchaseArray);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetNextPurchaseArrayPageDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoIAPFunction::GetNextPurchaseArrayPage(Z_Param_WorldContextObject,Z_Param_InPurchaseArray,FGetNextPurchaseArrayPageDelegate(Z_Param_InGetNextPurchaseArrayPageDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoIAPFunction::execGetViewerPurchases)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetViewerPurchasesDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoIAPFunction::GetViewerPurchases(Z_Param_WorldContextObject,FGetViewerPurchasesDelegate(Z_Param_InGetViewerPurchasesDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoIAPFunction::execGetNextProductsArrayPage)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_OBJECT(UPico_ProductArray,Z_Param_InProductArray);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetNextProductArrayPageDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoIAPFunction::GetNextProductsArrayPage(Z_Param_WorldContextObject,Z_Param_InProductArray,FGetNextProductArrayPageDelegate(Z_Param_InGetNextProductArrayPageDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoIAPFunction::execGetProductsBySKU)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_TARRAY(FString,Z_Param_ProductSKUs);
		P_GET_PROPERTY(FIntProperty,Z_Param_Count);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InGetProductsBySKUDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoIAPFunction::GetProductsBySKU(Z_Param_WorldContextObject,Z_Param_ProductSKUs,Z_Param_Count,FGetProductsBySKUDelegate(Z_Param_InGetProductsBySKUDelegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoIAPFunction::execConsumePurchase)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_SKU);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_InConsumePurchaseDelegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UOnlinePicoIAPFunction::ConsumePurchase(Z_Param_WorldContextObject,Z_Param_SKU,FConsumePurchaseDelegate(Z_Param_InConsumePurchaseDelegate));
		P_NATIVE_END;
	}
	void UOnlinePicoIAPFunction::StaticRegisterNativesUOnlinePicoIAPFunction()
	{
		UClass* Class = UOnlinePicoIAPFunction::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ConsumePurchase", &UOnlinePicoIAPFunction::execConsumePurchase },
			{ "GetNextProductsArrayPage", &UOnlinePicoIAPFunction::execGetNextProductsArrayPage },
			{ "GetNextPurchaseArrayPage", &UOnlinePicoIAPFunction::execGetNextPurchaseArrayPage },
			{ "GetProductsBySKU", &UOnlinePicoIAPFunction::execGetProductsBySKU },
			{ "GetSubscriptionStatus", &UOnlinePicoIAPFunction::execGetSubscriptionStatus },
			{ "GetViewerPurchases", &UOnlinePicoIAPFunction::execGetViewerPurchases },
			{ "LaunchCheckoutFlow", &UOnlinePicoIAPFunction::execLaunchCheckoutFlow },
			{ "LaunchCheckoutFlowV2", &UOnlinePicoIAPFunction::execLaunchCheckoutFlowV2 },
			{ "LaunchCheckoutFlowV3", &UOnlinePicoIAPFunction::execLaunchCheckoutFlowV3 },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics
	{
		struct OnlinePicoIAPFunction_eventConsumePurchase_Parms
		{
			UObject* WorldContextObject;
			FString SKU;
			FScriptDelegate InConsumePurchaseDelegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SKU_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_SKU;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InConsumePurchaseDelegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventConsumePurchase_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::NewProp_SKU_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::NewProp_SKU = { "SKU", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventConsumePurchase_Parms, SKU), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::NewProp_SKU_MetaData), Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::NewProp_SKU_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::NewProp_InConsumePurchaseDelegate = { "InConsumePurchaseDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventConsumePurchase_Parms, InConsumePurchaseDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_ConsumePurchaseDelegate__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3369793056
	void Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoIAPFunction_eventConsumePurchase_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoIAPFunction_eventConsumePurchase_Parms), &Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::NewProp_SKU,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::NewProp_InConsumePurchaseDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|IAP" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Records the order fulfillment result for a consumable.\n/// @note Users are unable to repurchase the same consumable until the previous order is fulfilled.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param> \n/// <param name =\"SKU\">The unique identifier of the add-on.</param> \n/// <param name =\"InConsumePurchaseDelegate\">Will be executed when the request has been completed.\n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage).</param>\n/// <returns>Bool: \n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Records the order fulfillment result for a consumable.\n@note Users are unable to repurchase the same consumable until the previous order is fulfilled.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name =\"SKU\">The unique identifier of the add-on.</param>\n<param name =\"InConsumePurchaseDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoIAPFunction, nullptr, "ConsumePurchase", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::OnlinePicoIAPFunction_eventConsumePurchase_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::OnlinePicoIAPFunction_eventConsumePurchase_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage_Statics
	{
		struct OnlinePicoIAPFunction_eventGetNextProductsArrayPage_Parms
		{
			UObject* WorldContextObject;
			UPico_ProductArray* InProductArray;
			FScriptDelegate InGetNextProductArrayPageDelegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InProductArray;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetNextProductArrayPageDelegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventGetNextProductsArrayPage_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage_Statics::NewProp_InProductArray = { "InProductArray", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventGetNextProductsArrayPage_Parms, InProductArray), Z_Construct_UClass_UPico_ProductArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage_Statics::NewProp_InGetNextProductArrayPageDelegate = { "InGetNextProductArrayPageDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventGetNextProductsArrayPage_Parms, InGetNextProductArrayPageDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextProductArrayPageDelegate__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1885130927
	void Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoIAPFunction_eventGetNextProductsArrayPage_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoIAPFunction_eventGetNextProductsArrayPage_Parms), &Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage_Statics::NewProp_InProductArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage_Statics::NewProp_InGetNextProductArrayPageDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|IAP" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the next page of purchasable add-ons.</summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param> \n/// <param name =\"InProductArray\">The current object of product array.</param> \n/// <param name =\"InGetNextProductArrayPageDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_ProductArray *, ProductArray).</param>\n/// <returns>Bool: \n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the next page of purchasable add-ons.</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name =\"InProductArray\">The current object of product array.</param>\n<param name =\"InGetNextProductArrayPageDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_ProductArray *, ProductArray).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoIAPFunction, nullptr, "GetNextProductsArrayPage", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage_Statics::OnlinePicoIAPFunction_eventGetNextProductsArrayPage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage_Statics::OnlinePicoIAPFunction_eventGetNextProductsArrayPage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage_Statics
	{
		struct OnlinePicoIAPFunction_eventGetNextPurchaseArrayPage_Parms
		{
			UObject* WorldContextObject;
			UPico_PurchaseArray* InPurchaseArray;
			FScriptDelegate InGetNextPurchaseArrayPageDelegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InPurchaseArray;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetNextPurchaseArrayPageDelegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventGetNextPurchaseArrayPage_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage_Statics::NewProp_InPurchaseArray = { "InPurchaseArray", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventGetNextPurchaseArrayPage_Parms, InPurchaseArray), Z_Construct_UClass_UPico_PurchaseArray_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage_Statics::NewProp_InGetNextPurchaseArrayPageDelegate = { "InGetNextPurchaseArrayPageDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventGetNextPurchaseArrayPage_Parms, InGetNextPurchaseArrayPageDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetNextPurchaseArrayPageDelegate__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2692400935
	void Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoIAPFunction_eventGetNextPurchaseArrayPage_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoIAPFunction_eventGetNextPurchaseArrayPage_Parms), &Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage_Statics::NewProp_InPurchaseArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage_Statics::NewProp_InGetNextPurchaseArrayPageDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|IAP" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets the next page of purchased add-ons.</summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param> \n/// <param name =\"InPurchaseArray\">The current object of purchase array.</param> \n/// <param name =\"InGetNextPurchaseArrayPageDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_PurchaseArray *, PurchaseArray).</param>\n/// <returns>Bool: \n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets the next page of purchased add-ons.</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name =\"InPurchaseArray\">The current object of purchase array.</param>\n<param name =\"InGetNextPurchaseArrayPageDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_PurchaseArray *, PurchaseArray).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoIAPFunction, nullptr, "GetNextPurchaseArrayPage", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage_Statics::OnlinePicoIAPFunction_eventGetNextPurchaseArrayPage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage_Statics::OnlinePicoIAPFunction_eventGetNextPurchaseArrayPage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics
	{
		struct OnlinePicoIAPFunction_eventGetProductsBySKU_Parms
		{
			UObject* WorldContextObject;
			TArray<FString> ProductSKUs;
			int32 Count;
			FScriptDelegate InGetProductsBySKUDelegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ProductSKUs_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ProductSKUs;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Count;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetProductsBySKUDelegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventGetProductsBySKU_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::NewProp_ProductSKUs_Inner = { "ProductSKUs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::NewProp_ProductSKUs = { "ProductSKUs", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventGetProductsBySKU_Parms, ProductSKUs), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::NewProp_Count = { "Count", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventGetProductsBySKU_Parms, Count), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::NewProp_InGetProductsBySKUDelegate = { "InGetProductsBySKUDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventGetProductsBySKU_Parms, InGetProductsBySKUDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetProductsBySKUDelegate__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1143666912
	void Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoIAPFunction_eventGetProductsBySKU_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoIAPFunction_eventGetProductsBySKU_Parms), &Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::NewProp_ProductSKUs_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::NewProp_ProductSKUs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::NewProp_Count,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::NewProp_InGetProductsBySKUDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|IAP" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets a list of purchasable add-ons in the current app.</summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param> \n/// <param name =\"ProductSKUs\">The unique identifiers of add-ons.</param> \n/// <param name =\"Count\">The number of ProductSKUs arrays to return.</param> \n/// <param name =\"InGetProductsBySKUDelegate\">Will be executed when the request has been completed.\n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_ProductArray *, ProductArray).</param>\n/// <returns>Bool: \n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets a list of purchasable add-ons in the current app.</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name =\"ProductSKUs\">The unique identifiers of add-ons.</param>\n<param name =\"Count\">The number of ProductSKUs arrays to return.</param>\n<param name =\"InGetProductsBySKUDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_ProductArray *, ProductArray).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoIAPFunction, nullptr, "GetProductsBySKU", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::OnlinePicoIAPFunction_eventGetProductsBySKU_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::OnlinePicoIAPFunction_eventGetProductsBySKU_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics
	{
		struct OnlinePicoIAPFunction_eventGetSubscriptionStatus_Parms
		{
			UObject* WorldContextObject;
			FString SKU;
			FScriptDelegate InGetSubscriptionStatusDelegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SKU_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_SKU;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetSubscriptionStatusDelegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventGetSubscriptionStatus_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::NewProp_SKU_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::NewProp_SKU = { "SKU", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventGetSubscriptionStatus_Parms, SKU), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::NewProp_SKU_MetaData), Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::NewProp_SKU_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::NewProp_InGetSubscriptionStatusDelegate = { "InGetSubscriptionStatusDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventGetSubscriptionStatus_Parms, InGetSubscriptionStatusDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetSubscriptionStatusDelegate__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3873855188
	void Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoIAPFunction_eventGetSubscriptionStatus_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoIAPFunction_eventGetSubscriptionStatus_Parms), &Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::NewProp_SKU,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::NewProp_InGetSubscriptionStatusDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|IAP" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Gets the subscription status of an add-on.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param> \n/// <param name=\"SKU\">The SKU of the add-on.</param>\n/// <param name =\"InGetSubscriptionStatusDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_SubscriptionStatus *, Purchase).</param>\n/// <returns>Bool: \n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nGets the subscription status of an add-on.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"SKU\">The SKU of the add-on.</param>\n<param name =\"InGetSubscriptionStatusDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_SubscriptionStatus *, Purchase).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoIAPFunction, nullptr, "GetSubscriptionStatus", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::OnlinePicoIAPFunction_eventGetSubscriptionStatus_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::OnlinePicoIAPFunction_eventGetSubscriptionStatus_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoIAPFunction_GetViewerPurchases_Statics
	{
		struct OnlinePicoIAPFunction_eventGetViewerPurchases_Parms
		{
			UObject* WorldContextObject;
			FScriptDelegate InGetViewerPurchasesDelegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InGetViewerPurchasesDelegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetViewerPurchases_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventGetViewerPurchases_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetViewerPurchases_Statics::NewProp_InGetViewerPurchasesDelegate = { "InGetViewerPurchasesDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventGetViewerPurchases_Parms, InGetViewerPurchasesDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_GetViewerPurchasesDelegate__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1203771689
	void Z_Construct_UFunction_UOnlinePicoIAPFunction_GetViewerPurchases_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoIAPFunction_eventGetViewerPurchases_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetViewerPurchases_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoIAPFunction_eventGetViewerPurchases_Parms), &Z_Construct_UFunction_UOnlinePicoIAPFunction_GetViewerPurchases_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoIAPFunction_GetViewerPurchases_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_GetViewerPurchases_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_GetViewerPurchases_Statics::NewProp_InGetViewerPurchasesDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_GetViewerPurchases_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoIAPFunction_GetViewerPurchases_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|IAP" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>Gets a list of purchased add-ons for a user in the current app, including durables and unfulfilled consumables.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param> \n/// <param name =\"InGetViewerPurchasesDelegate\">Will be executed when the request has been completed.\n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_PurchaseArray *, PurchaseArray).</param>\n/// <returns>Bool:\n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>Gets a list of purchased add-ons for a user in the current app, including durables and unfulfilled consumables.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name =\"InGetViewerPurchasesDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_PurchaseArray *, PurchaseArray).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoIAPFunction_GetViewerPurchases_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoIAPFunction, nullptr, "GetViewerPurchases", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoIAPFunction_GetViewerPurchases_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetViewerPurchases_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetViewerPurchases_Statics::OnlinePicoIAPFunction_eventGetViewerPurchases_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetViewerPurchases_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoIAPFunction_GetViewerPurchases_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetViewerPurchases_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoIAPFunction_GetViewerPurchases_Statics::OnlinePicoIAPFunction_eventGetViewerPurchases_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoIAPFunction_GetViewerPurchases()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoIAPFunction_GetViewerPurchases_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics
	{
		struct OnlinePicoIAPFunction_eventLaunchCheckoutFlow_Parms
		{
			UObject* WorldContextObject;
			FString SKU;
			FString Price;
			FString Currency;
			FScriptDelegate InLaunchCheckoutFlowDelegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SKU_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_SKU;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Price_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Price;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Currency_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Currency;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InLaunchCheckoutFlowDelegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventLaunchCheckoutFlow_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::NewProp_SKU_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::NewProp_SKU = { "SKU", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventLaunchCheckoutFlow_Parms, SKU), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::NewProp_SKU_MetaData), Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::NewProp_SKU_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::NewProp_Price_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::NewProp_Price = { "Price", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventLaunchCheckoutFlow_Parms, Price), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::NewProp_Price_MetaData), Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::NewProp_Price_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::NewProp_Currency_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::NewProp_Currency = { "Currency", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventLaunchCheckoutFlow_Parms, Currency), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::NewProp_Currency_MetaData), Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::NewProp_Currency_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::NewProp_InLaunchCheckoutFlowDelegate = { "InLaunchCheckoutFlowDelegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventLaunchCheckoutFlow_Parms, InLaunchCheckoutFlowDelegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlowDelegate__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 265115831
	void Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoIAPFunction_eventLaunchCheckoutFlow_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoIAPFunction_eventLaunchCheckoutFlow_Parms), &Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::NewProp_SKU,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::NewProp_Price,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::NewProp_Currency,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::NewProp_InLaunchCheckoutFlowDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|IAP" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Launches the checkout flow to purchase a consumable or durable.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param> \n/// <param name =\"SKU\">The unique identifier of the add-on to purchase.</param> \n/// <param name =\"Price\">The price for the add-on.</param> \n/// <param name =\"Currency\">The currency of the payment.</param> \n/// <param name =\"InLaunchCheckoutFlowDelegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_Purchase *, Purchase).</param>\n/// <returns>Bool: \n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nLaunches the checkout flow to purchase a consumable or durable.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name =\"SKU\">The unique identifier of the add-on to purchase.</param>\n<param name =\"Price\">The price for the add-on.</param>\n<param name =\"Currency\">The currency of the payment.</param>\n<param name =\"InLaunchCheckoutFlowDelegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_Purchase *, Purchase).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoIAPFunction, nullptr, "LaunchCheckoutFlow", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::OnlinePicoIAPFunction_eventLaunchCheckoutFlow_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::OnlinePicoIAPFunction_eventLaunchCheckoutFlow_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics
	{
		struct OnlinePicoIAPFunction_eventLaunchCheckoutFlowV2_Parms
		{
			UObject* WorldContextObject;
			FString SKU;
			FString Price;
			FString Currency;
			FString OuterId;
			FScriptDelegate InLaunchCheckoutFlow_V2Delegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SKU_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_SKU;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Price_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Price;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Currency_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Currency;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OuterId_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_OuterId;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InLaunchCheckoutFlow_V2Delegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventLaunchCheckoutFlowV2_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_SKU_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_SKU = { "SKU", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventLaunchCheckoutFlowV2_Parms, SKU), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_SKU_MetaData), Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_SKU_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_Price_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_Price = { "Price", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventLaunchCheckoutFlowV2_Parms, Price), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_Price_MetaData), Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_Price_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_Currency_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_Currency = { "Currency", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventLaunchCheckoutFlowV2_Parms, Currency), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_Currency_MetaData), Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_Currency_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_OuterId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_OuterId = { "OuterId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventLaunchCheckoutFlowV2_Parms, OuterId), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_OuterId_MetaData), Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_OuterId_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_InLaunchCheckoutFlow_V2Delegate = { "InLaunchCheckoutFlow_V2Delegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventLaunchCheckoutFlowV2_Parms, InLaunchCheckoutFlow_V2Delegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V2Delegate__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1960537810
	void Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoIAPFunction_eventLaunchCheckoutFlowV2_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoIAPFunction_eventLaunchCheckoutFlowV2_Parms), &Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_SKU,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_Price,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_Currency,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_OuterId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_InLaunchCheckoutFlow_V2Delegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|IAP" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Launches the checkout flow to purchase a consumable, durable, or a subscription add-on.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param> \n/// <param name =\"SKU\">The unique identifier of the subscription add-on the user wants to purchase.</param> \n/// <param name =\"Price\">The price for the subscription add-on.</param> \n/// <param name =\"Currency\">The currency of the payment.</param> \n/// <param name =\"OuterId\">The unique identifier of the subscription period in the subscription add-on.</param> \n/// <param name =\"InLaunchCheckoutFlow_V2Delegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_Purchase *, Purchase).</param>\n/// <returns>Bool: \n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nLaunches the checkout flow to purchase a consumable, durable, or a subscription add-on.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name =\"SKU\">The unique identifier of the subscription add-on the user wants to purchase.</param>\n<param name =\"Price\">The price for the subscription add-on.</param>\n<param name =\"Currency\">The currency of the payment.</param>\n<param name =\"OuterId\">The unique identifier of the subscription period in the subscription add-on.</param>\n<param name =\"InLaunchCheckoutFlow_V2Delegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_Purchase *, Purchase).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoIAPFunction, nullptr, "LaunchCheckoutFlowV2", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::OnlinePicoIAPFunction_eventLaunchCheckoutFlowV2_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::OnlinePicoIAPFunction_eventLaunchCheckoutFlowV2_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics
	{
		struct OnlinePicoIAPFunction_eventLaunchCheckoutFlowV3_Parms
		{
			UObject* WorldContextObject;
			FString SKU;
			FString Price;
			FString Currency;
			FString OuterId;
			FString OrderComment;
			FScriptDelegate InLaunchCheckoutFlow_V3Delegate;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SKU_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_SKU;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Price_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Price;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Currency_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Currency;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OuterId_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_OuterId;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OrderComment_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_OrderComment;
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_InLaunchCheckoutFlow_V3Delegate;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventLaunchCheckoutFlowV3_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_SKU_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_SKU = { "SKU", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventLaunchCheckoutFlowV3_Parms, SKU), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_SKU_MetaData), Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_SKU_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_Price_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_Price = { "Price", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventLaunchCheckoutFlowV3_Parms, Price), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_Price_MetaData), Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_Price_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_Currency_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_Currency = { "Currency", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventLaunchCheckoutFlowV3_Parms, Currency), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_Currency_MetaData), Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_Currency_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_OuterId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_OuterId = { "OuterId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventLaunchCheckoutFlowV3_Parms, OuterId), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_OuterId_MetaData), Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_OuterId_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_OrderComment_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_OrderComment = { "OrderComment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventLaunchCheckoutFlowV3_Parms, OrderComment), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_OrderComment_MetaData), Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_OrderComment_MetaData) };
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_InLaunchCheckoutFlow_V3Delegate = { "InLaunchCheckoutFlow_V3Delegate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoIAPFunction_eventLaunchCheckoutFlowV3_Parms, InLaunchCheckoutFlow_V3Delegate), Z_Construct_UDelegateFunction_OnlineSubsystemPico_LaunchCheckoutFlow_V3Delegate__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 224729259
	void Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((OnlinePicoIAPFunction_eventLaunchCheckoutFlowV3_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoIAPFunction_eventLaunchCheckoutFlowV3_Parms), &Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_SKU,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_Price,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_Currency,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_OuterId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_OrderComment,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_InLaunchCheckoutFlow_V3Delegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|IAP" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Launches the checkout flow to purchase a subscription add-on.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param> \n/// <param name =\"SKU\">The unique identifier of the subscription add-on the user wants to purchase.</param> \n/// <param name =\"Price\">The price for the subscription add-on.</param> \n/// <param name =\"Currency\">The currency of the payment.</param> \n/// <param name =\"OuterId\">The unique identifier of the subscription period in the subscription add-on.</param> \n/// <param name =\"OrderComment\">Extended comment field for a purchase.</param> \n/// <param name =\"InLaunchCheckoutFlow_V2Delegate\">Will be executed when the request has been completed. \n/// Delegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_Purchase *, Purchase).</param>\n/// <returns>Bool: \n/// <ul>\n/// <li>`true`: Sending request succeeded</li>\n/// <li>`false`: Sending request failed</li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nLaunches the checkout flow to purchase a subscription add-on.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name =\"SKU\">The unique identifier of the subscription add-on the user wants to purchase.</param>\n<param name =\"Price\">The price for the subscription add-on.</param>\n<param name =\"Currency\">The currency of the payment.</param>\n<param name =\"OuterId\">The unique identifier of the subscription period in the subscription add-on.</param>\n<param name =\"OrderComment\">Extended comment field for a purchase.</param>\n<param name =\"InLaunchCheckoutFlow_V2Delegate\">Will be executed when the request has been completed.\nDelegate will contain the requested object class (bool, bIsError, const FString&, ErrorMessage, UPico_Purchase *, Purchase).</param>\n<returns>Bool:\n<ul>\n<li>`true`: Sending request succeeded</li>\n<li>`false`: Sending request failed</li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoIAPFunction, nullptr, "LaunchCheckoutFlowV3", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::OnlinePicoIAPFunction_eventLaunchCheckoutFlowV3_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::OnlinePicoIAPFunction_eventLaunchCheckoutFlowV3_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOnlinePicoIAPFunction);
	UClass* Z_Construct_UClass_UOnlinePicoIAPFunction_NoRegister()
	{
		return UOnlinePicoIAPFunction::StaticClass();
	}
	struct Z_Construct_UClass_UOnlinePicoIAPFunction_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOnlinePicoIAPFunction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoIAPFunction_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UOnlinePicoIAPFunction_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOnlinePicoIAPFunction_ConsumePurchase, "ConsumePurchase" }, // 139760550
		{ &Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextProductsArrayPage, "GetNextProductsArrayPage" }, // 1613809067
		{ &Z_Construct_UFunction_UOnlinePicoIAPFunction_GetNextPurchaseArrayPage, "GetNextPurchaseArrayPage" }, // 2782532632
		{ &Z_Construct_UFunction_UOnlinePicoIAPFunction_GetProductsBySKU, "GetProductsBySKU" }, // 397250994
		{ &Z_Construct_UFunction_UOnlinePicoIAPFunction_GetSubscriptionStatus, "GetSubscriptionStatus" }, // 3520033482
		{ &Z_Construct_UFunction_UOnlinePicoIAPFunction_GetViewerPurchases, "GetViewerPurchases" }, // 2526399058
		{ &Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlow, "LaunchCheckoutFlow" }, // 2085059347
		{ &Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV2, "LaunchCheckoutFlowV2" }, // 1910749153
		{ &Z_Construct_UFunction_UOnlinePicoIAPFunction_LaunchCheckoutFlowV3, "LaunchCheckoutFlowV3" }, // 1847249972
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoIAPFunction_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoIAPFunction_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @defgroup BP_IAP BP_IAP\n *  This is the BP_IAP group\n *  @{\n *//// @brief OnlinePicoIAP Blueprint Function class.\n" },
#endif
		{ "IncludePath", "Pico_IAP.h" },
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@defgroup BP_IAP BP_IAP\nThis is the BP_IAP group\n@{\n/// @brief OnlinePicoIAP Blueprint Function class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOnlinePicoIAPFunction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOnlinePicoIAPFunction>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOnlinePicoIAPFunction_Statics::ClassParams = {
		&UOnlinePicoIAPFunction::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoIAPFunction_Statics::Class_MetaDataParams), Z_Construct_UClass_UOnlinePicoIAPFunction_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UOnlinePicoIAPFunction()
	{
		if (!Z_Registration_Info_UClass_UOnlinePicoIAPFunction.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOnlinePicoIAPFunction.OuterSingleton, Z_Construct_UClass_UOnlinePicoIAPFunction_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOnlinePicoIAPFunction.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UOnlinePicoIAPFunction>()
	{
		return UOnlinePicoIAPFunction::StaticClass();
	}
	UOnlinePicoIAPFunction::UOnlinePicoIAPFunction(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOnlinePicoIAPFunction);
	UOnlinePicoIAPFunction::~UOnlinePicoIAPFunction() {}
	DEFINE_FUNCTION(UPico_Product::execGetIsContinuous)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetIsContinuous();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Product::execGetOriginalPrice)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetOriginalPrice();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Product::execGetOuterId)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetOuterId();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Product::execGetTrialPeriodValue)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetTrialPeriodValue();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Product::execGetTrialPeriodUnit)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EPeriodType*)Z_Param__Result=P_THIS->GetTrialPeriodUnit();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Product::execGetPeriodType)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EPeriodType*)Z_Param__Result=P_THIS->GetPeriodType();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Product::execGetAddonsType)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EAddonsType*)Z_Param__Result=P_THIS->GetAddonsType();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Product::execGetIcon)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetIcon();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Product::execGetSKU)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetSKU();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Product::execGetName)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetName();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Product::execGetCurrency)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetCurrency();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Product::execGetFormattedPrice)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetFormattedPrice();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Product::execGetPrice)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetPrice();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Product::execGetDetailDescription)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetDetailDescription();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Product::execGetDescription)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetDescription();
		P_NATIVE_END;
	}
	void UPico_Product::StaticRegisterNativesUPico_Product()
	{
		UClass* Class = UPico_Product::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAddonsType", &UPico_Product::execGetAddonsType },
			{ "GetCurrency", &UPico_Product::execGetCurrency },
			{ "GetDescription", &UPico_Product::execGetDescription },
			{ "GetDetailDescription", &UPico_Product::execGetDetailDescription },
			{ "GetFormattedPrice", &UPico_Product::execGetFormattedPrice },
			{ "GetIcon", &UPico_Product::execGetIcon },
			{ "GetIsContinuous", &UPico_Product::execGetIsContinuous },
			{ "GetName", &UPico_Product::execGetName },
			{ "GetOriginalPrice", &UPico_Product::execGetOriginalPrice },
			{ "GetOuterId", &UPico_Product::execGetOuterId },
			{ "GetPeriodType", &UPico_Product::execGetPeriodType },
			{ "GetPrice", &UPico_Product::execGetPrice },
			{ "GetSKU", &UPico_Product::execGetSKU },
			{ "GetTrialPeriodUnit", &UPico_Product::execGetTrialPeriodUnit },
			{ "GetTrialPeriodValue", &UPico_Product::execGetTrialPeriodValue },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_Product_GetAddonsType_Statics
	{
		struct Pico_Product_eventGetAddonsType_Parms
		{
			EAddonsType ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPico_Product_GetAddonsType_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPico_Product_GetAddonsType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Product_eventGetAddonsType_Parms, ReturnValue), Z_Construct_UEnum_OnlineSubsystemPico_EAddonsType, METADATA_PARAMS(0, nullptr) }; // 2234045637
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Product_GetAddonsType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Product_GetAddonsType_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Product_GetAddonsType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Product_GetAddonsType_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Product" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief The type of the add-on */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The type of the add-on" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Product_GetAddonsType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Product, nullptr, "GetAddonsType", nullptr, nullptr, Z_Construct_UFunction_UPico_Product_GetAddonsType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetAddonsType_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Product_GetAddonsType_Statics::Pico_Product_eventGetAddonsType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetAddonsType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Product_GetAddonsType_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetAddonsType_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Product_GetAddonsType_Statics::Pico_Product_eventGetAddonsType_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Product_GetAddonsType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Product_GetAddonsType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Product_GetCurrency_Statics
	{
		struct Pico_Product_eventGetCurrency_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_Product_GetCurrency_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Product_eventGetCurrency_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Product_GetCurrency_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Product_GetCurrency_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Product_GetCurrency_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Product" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief The currency required for purchasing the add-on. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The currency required for purchasing the add-on." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Product_GetCurrency_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Product, nullptr, "GetCurrency", nullptr, nullptr, Z_Construct_UFunction_UPico_Product_GetCurrency_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetCurrency_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Product_GetCurrency_Statics::Pico_Product_eventGetCurrency_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetCurrency_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Product_GetCurrency_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetCurrency_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Product_GetCurrency_Statics::Pico_Product_eventGetCurrency_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Product_GetCurrency()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Product_GetCurrency_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Product_GetDescription_Statics
	{
		struct Pico_Product_eventGetDescription_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_Product_GetDescription_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Product_eventGetDescription_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Product_GetDescription_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Product_GetDescription_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Product_GetDescription_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Product" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief The description of the add-on. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The description of the add-on." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Product_GetDescription_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Product, nullptr, "GetDescription", nullptr, nullptr, Z_Construct_UFunction_UPico_Product_GetDescription_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetDescription_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Product_GetDescription_Statics::Pico_Product_eventGetDescription_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetDescription_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Product_GetDescription_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetDescription_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Product_GetDescription_Statics::Pico_Product_eventGetDescription_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Product_GetDescription()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Product_GetDescription_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Product_GetDetailDescription_Statics
	{
		struct Pico_Product_eventGetDetailDescription_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_Product_GetDetailDescription_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Product_eventGetDetailDescription_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Product_GetDetailDescription_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Product_GetDetailDescription_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Product_GetDetailDescription_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Product" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief The detailed description of the add-on. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The detailed description of the add-on." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Product_GetDetailDescription_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Product, nullptr, "GetDetailDescription", nullptr, nullptr, Z_Construct_UFunction_UPico_Product_GetDetailDescription_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetDetailDescription_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Product_GetDetailDescription_Statics::Pico_Product_eventGetDetailDescription_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetDetailDescription_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Product_GetDetailDescription_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetDetailDescription_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Product_GetDetailDescription_Statics::Pico_Product_eventGetDetailDescription_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Product_GetDetailDescription()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Product_GetDetailDescription_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Product_GetFormattedPrice_Statics
	{
		struct Pico_Product_eventGetFormattedPrice_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_Product_GetFormattedPrice_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Product_eventGetFormattedPrice_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Product_GetFormattedPrice_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Product_GetFormattedPrice_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Product_GetFormattedPrice_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Product" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief Not use! */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Not use!" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Product_GetFormattedPrice_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Product, nullptr, "GetFormattedPrice", nullptr, nullptr, Z_Construct_UFunction_UPico_Product_GetFormattedPrice_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetFormattedPrice_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Product_GetFormattedPrice_Statics::Pico_Product_eventGetFormattedPrice_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetFormattedPrice_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Product_GetFormattedPrice_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetFormattedPrice_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Product_GetFormattedPrice_Statics::Pico_Product_eventGetFormattedPrice_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Product_GetFormattedPrice()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Product_GetFormattedPrice_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Product_GetIcon_Statics
	{
		struct Pico_Product_eventGetIcon_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_Product_GetIcon_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Product_eventGetIcon_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Product_GetIcon_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Product_GetIcon_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Product_GetIcon_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Product" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief The icon of the add-on, which is an image URL.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The icon of the add-on, which is an image URL." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Product_GetIcon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Product, nullptr, "GetIcon", nullptr, nullptr, Z_Construct_UFunction_UPico_Product_GetIcon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetIcon_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Product_GetIcon_Statics::Pico_Product_eventGetIcon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetIcon_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Product_GetIcon_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetIcon_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Product_GetIcon_Statics::Pico_Product_eventGetIcon_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Product_GetIcon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Product_GetIcon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Product_GetIsContinuous_Statics
	{
		struct Pico_Product_eventGetIsContinuous_Parms
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
	void Z_Construct_UFunction_UPico_Product_GetIsContinuous_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_Product_eventGetIsContinuous_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_Product_GetIsContinuous_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_Product_eventGetIsContinuous_Parms), &Z_Construct_UFunction_UPico_Product_GetIsContinuous_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Product_GetIsContinuous_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Product_GetIsContinuous_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Product_GetIsContinuous_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Product" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief Whether the subscription is auto renewed.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Whether the subscription is auto renewed." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Product_GetIsContinuous_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Product, nullptr, "GetIsContinuous", nullptr, nullptr, Z_Construct_UFunction_UPico_Product_GetIsContinuous_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetIsContinuous_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Product_GetIsContinuous_Statics::Pico_Product_eventGetIsContinuous_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetIsContinuous_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Product_GetIsContinuous_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetIsContinuous_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Product_GetIsContinuous_Statics::Pico_Product_eventGetIsContinuous_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Product_GetIsContinuous()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Product_GetIsContinuous_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Product_GetName_Statics
	{
		struct Pico_Product_eventGetName_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_Product_GetName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Product_eventGetName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Product_GetName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Product_GetName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Product_GetName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Product" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief The name of the add-on. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The name of the add-on." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Product_GetName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Product, nullptr, "GetName", nullptr, nullptr, Z_Construct_UFunction_UPico_Product_GetName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Product_GetName_Statics::Pico_Product_eventGetName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Product_GetName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Product_GetName_Statics::Pico_Product_eventGetName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Product_GetName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Product_GetName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Product_GetOriginalPrice_Statics
	{
		struct Pico_Product_eventGetOriginalPrice_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_Product_GetOriginalPrice_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Product_eventGetOriginalPrice_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Product_GetOriginalPrice_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Product_GetOriginalPrice_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Product_GetOriginalPrice_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Product" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief The original price of the add-on. This field means the price\n     * without discount.\n     */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The original price of the add-on. This field means the price\nwithout discount." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Product_GetOriginalPrice_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Product, nullptr, "GetOriginalPrice", nullptr, nullptr, Z_Construct_UFunction_UPico_Product_GetOriginalPrice_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetOriginalPrice_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Product_GetOriginalPrice_Statics::Pico_Product_eventGetOriginalPrice_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetOriginalPrice_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Product_GetOriginalPrice_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetOriginalPrice_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Product_GetOriginalPrice_Statics::Pico_Product_eventGetOriginalPrice_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Product_GetOriginalPrice()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Product_GetOriginalPrice_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Product_GetOuterId_Statics
	{
		struct Pico_Product_eventGetOuterId_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_Product_GetOuterId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Product_eventGetOuterId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Product_GetOuterId_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Product_GetOuterId_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Product_GetOuterId_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Product" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief The unique identifier of a subscription period.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The unique identifier of a subscription period." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Product_GetOuterId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Product, nullptr, "GetOuterId", nullptr, nullptr, Z_Construct_UFunction_UPico_Product_GetOuterId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetOuterId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Product_GetOuterId_Statics::Pico_Product_eventGetOuterId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetOuterId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Product_GetOuterId_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetOuterId_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Product_GetOuterId_Statics::Pico_Product_eventGetOuterId_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Product_GetOuterId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Product_GetOuterId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Product_GetPeriodType_Statics
	{
		struct Pico_Product_eventGetPeriodType_Parms
		{
			EPeriodType ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPico_Product_GetPeriodType_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPico_Product_GetPeriodType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Product_eventGetPeriodType_Parms, ReturnValue), Z_Construct_UEnum_OnlineSubsystemPico_EPeriodType, METADATA_PARAMS(0, nullptr) }; // 3471629836
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Product_GetPeriodType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Product_GetPeriodType_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Product_GetPeriodType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Product_GetPeriodType_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Product" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief The period type for the subscription add-on.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The period type for the subscription add-on." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Product_GetPeriodType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Product, nullptr, "GetPeriodType", nullptr, nullptr, Z_Construct_UFunction_UPico_Product_GetPeriodType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetPeriodType_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Product_GetPeriodType_Statics::Pico_Product_eventGetPeriodType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetPeriodType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Product_GetPeriodType_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetPeriodType_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Product_GetPeriodType_Statics::Pico_Product_eventGetPeriodType_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Product_GetPeriodType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Product_GetPeriodType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Product_GetPrice_Statics
	{
		struct Pico_Product_eventGetPrice_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_Product_GetPrice_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Product_eventGetPrice_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Product_GetPrice_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Product_GetPrice_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Product_GetPrice_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Product" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief The price of the add-on, which is a number string. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The price of the add-on, which is a number string." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Product_GetPrice_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Product, nullptr, "GetPrice", nullptr, nullptr, Z_Construct_UFunction_UPico_Product_GetPrice_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetPrice_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Product_GetPrice_Statics::Pico_Product_eventGetPrice_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetPrice_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Product_GetPrice_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetPrice_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Product_GetPrice_Statics::Pico_Product_eventGetPrice_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Product_GetPrice()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Product_GetPrice_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Product_GetSKU_Statics
	{
		struct Pico_Product_eventGetSKU_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_Product_GetSKU_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Product_eventGetSKU_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Product_GetSKU_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Product_GetSKU_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Product_GetSKU_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Product" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief The unique identifier of the add-on. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The unique identifier of the add-on." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Product_GetSKU_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Product, nullptr, "GetSKU", nullptr, nullptr, Z_Construct_UFunction_UPico_Product_GetSKU_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetSKU_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Product_GetSKU_Statics::Pico_Product_eventGetSKU_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetSKU_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Product_GetSKU_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetSKU_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Product_GetSKU_Statics::Pico_Product_eventGetSKU_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Product_GetSKU()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Product_GetSKU_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Product_GetTrialPeriodUnit_Statics
	{
		struct Pico_Product_eventGetTrialPeriodUnit_Parms
		{
			EPeriodType ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPico_Product_GetTrialPeriodUnit_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPico_Product_GetTrialPeriodUnit_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Product_eventGetTrialPeriodUnit_Parms, ReturnValue), Z_Construct_UEnum_OnlineSubsystemPico_EPeriodType, METADATA_PARAMS(0, nullptr) }; // 3471629836
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Product_GetTrialPeriodUnit_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Product_GetTrialPeriodUnit_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Product_GetTrialPeriodUnit_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Product_GetTrialPeriodUnit_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Product" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief The trial period unit for the subscription add-on.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The trial period unit for the subscription add-on." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Product_GetTrialPeriodUnit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Product, nullptr, "GetTrialPeriodUnit", nullptr, nullptr, Z_Construct_UFunction_UPico_Product_GetTrialPeriodUnit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetTrialPeriodUnit_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Product_GetTrialPeriodUnit_Statics::Pico_Product_eventGetTrialPeriodUnit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetTrialPeriodUnit_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Product_GetTrialPeriodUnit_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetTrialPeriodUnit_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Product_GetTrialPeriodUnit_Statics::Pico_Product_eventGetTrialPeriodUnit_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Product_GetTrialPeriodUnit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Product_GetTrialPeriodUnit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Product_GetTrialPeriodValue_Statics
	{
		struct Pico_Product_eventGetTrialPeriodValue_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_Product_GetTrialPeriodValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Product_eventGetTrialPeriodValue_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Product_GetTrialPeriodValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Product_GetTrialPeriodValue_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Product_GetTrialPeriodValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Product" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief The trial period value for the subscription add-on.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The trial period value for the subscription add-on." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Product_GetTrialPeriodValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Product, nullptr, "GetTrialPeriodValue", nullptr, nullptr, Z_Construct_UFunction_UPico_Product_GetTrialPeriodValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetTrialPeriodValue_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Product_GetTrialPeriodValue_Statics::Pico_Product_eventGetTrialPeriodValue_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetTrialPeriodValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Product_GetTrialPeriodValue_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Product_GetTrialPeriodValue_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Product_GetTrialPeriodValue_Statics::Pico_Product_eventGetTrialPeriodValue_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Product_GetTrialPeriodValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Product_GetTrialPeriodValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_Product);
	UClass* Z_Construct_UClass_UPico_Product_NoRegister()
	{
		return UPico_Product::StaticClass();
	}
	struct Z_Construct_UClass_UPico_Product_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_Product_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_Product_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_Product_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_Product_GetAddonsType, "GetAddonsType" }, // 1557477685
		{ &Z_Construct_UFunction_UPico_Product_GetCurrency, "GetCurrency" }, // 207813464
		{ &Z_Construct_UFunction_UPico_Product_GetDescription, "GetDescription" }, // 4174339316
		{ &Z_Construct_UFunction_UPico_Product_GetDetailDescription, "GetDetailDescription" }, // 3188450056
		{ &Z_Construct_UFunction_UPico_Product_GetFormattedPrice, "GetFormattedPrice" }, // 855757121
		{ &Z_Construct_UFunction_UPico_Product_GetIcon, "GetIcon" }, // 3756848813
		{ &Z_Construct_UFunction_UPico_Product_GetIsContinuous, "GetIsContinuous" }, // 809685849
		{ &Z_Construct_UFunction_UPico_Product_GetName, "GetName" }, // 1066497573
		{ &Z_Construct_UFunction_UPico_Product_GetOriginalPrice, "GetOriginalPrice" }, // 4007365013
		{ &Z_Construct_UFunction_UPico_Product_GetOuterId, "GetOuterId" }, // 367597568
		{ &Z_Construct_UFunction_UPico_Product_GetPeriodType, "GetPeriodType" }, // 548577932
		{ &Z_Construct_UFunction_UPico_Product_GetPrice, "GetPrice" }, // 3072381593
		{ &Z_Construct_UFunction_UPico_Product_GetSKU, "GetSKU" }, // 4102003654
		{ &Z_Construct_UFunction_UPico_Product_GetTrialPeriodUnit, "GetTrialPeriodUnit" }, // 1703889814
		{ &Z_Construct_UFunction_UPico_Product_GetTrialPeriodValue, "GetTrialPeriodValue" }, // 2454800724
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_Product_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_Product_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * PPF_Product.h\n *//// @brief UPico_Product class.\n" },
#endif
		{ "IncludePath", "Pico_IAP.h" },
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "PPF_Product.h\n /// @brief UPico_Product class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_Product_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_Product>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_Product_Statics::ClassParams = {
		&UPico_Product::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_Product_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_Product_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPico_Product()
	{
		if (!Z_Registration_Info_UClass_UPico_Product.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_Product.OuterSingleton, Z_Construct_UClass_UPico_Product_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_Product.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_Product>()
	{
		return UPico_Product::StaticClass();
	}
	UPico_Product::UPico_Product(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_Product);
	UPico_Product::~UPico_Product() {}
	DEFINE_FUNCTION(UPico_ProductArray::execHasNextPage)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->HasNextPage();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_ProductArray::execGetSize)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetSize();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_ProductArray::execGetNextPageParam)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetNextPageParam();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_ProductArray::execGetElement)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPico_Product**)Z_Param__Result=P_THIS->GetElement(Z_Param_Index);
		P_NATIVE_END;
	}
	void UPico_ProductArray::StaticRegisterNativesUPico_ProductArray()
	{
		UClass* Class = UPico_ProductArray::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetElement", &UPico_ProductArray::execGetElement },
			{ "GetNextPageParam", &UPico_ProductArray::execGetNextPageParam },
			{ "GetSize", &UPico_ProductArray::execGetSize },
			{ "HasNextPage", &UPico_ProductArray::execHasNextPage },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_ProductArray_GetElement_Statics
	{
		struct Pico_ProductArray_eventGetElement_Parms
		{
			int32 Index;
			UPico_Product* ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_ProductArray_GetElement_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_ProductArray_eventGetElement_Parms, Index), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPico_ProductArray_GetElement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_ProductArray_eventGetElement_Parms, ReturnValue), Z_Construct_UClass_UPico_Product_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_ProductArray_GetElement_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ProductArray_GetElement_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ProductArray_GetElement_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_ProductArray_GetElement_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Product Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get ProductArray element form Index.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get ProductArray element form Index." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_ProductArray_GetElement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_ProductArray, nullptr, "GetElement", nullptr, nullptr, Z_Construct_UFunction_UPico_ProductArray_GetElement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ProductArray_GetElement_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_ProductArray_GetElement_Statics::Pico_ProductArray_eventGetElement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ProductArray_GetElement_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_ProductArray_GetElement_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ProductArray_GetElement_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_ProductArray_GetElement_Statics::Pico_ProductArray_eventGetElement_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_ProductArray_GetElement()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_ProductArray_GetElement_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_ProductArray_GetNextPageParam_Statics
	{
		struct Pico_ProductArray_eventGetNextPageParam_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_ProductArray_GetNextPageParam_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_ProductArray_eventGetNextPageParam_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_ProductArray_GetNextPageParam_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ProductArray_GetNextPageParam_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_ProductArray_GetNextPageParam_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Product Array" },
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_ProductArray_GetNextPageParam_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_ProductArray, nullptr, "GetNextPageParam", nullptr, nullptr, Z_Construct_UFunction_UPico_ProductArray_GetNextPageParam_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ProductArray_GetNextPageParam_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_ProductArray_GetNextPageParam_Statics::Pico_ProductArray_eventGetNextPageParam_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ProductArray_GetNextPageParam_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_ProductArray_GetNextPageParam_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ProductArray_GetNextPageParam_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_ProductArray_GetNextPageParam_Statics::Pico_ProductArray_eventGetNextPageParam_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_ProductArray_GetNextPageParam()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_ProductArray_GetNextPageParam_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_ProductArray_GetSize_Statics
	{
		struct Pico_ProductArray_eventGetSize_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_ProductArray_GetSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_ProductArray_eventGetSize_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_ProductArray_GetSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ProductArray_GetSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_ProductArray_GetSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Product Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get the size of ProductArray .*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get the size of ProductArray ." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_ProductArray_GetSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_ProductArray, nullptr, "GetSize", nullptr, nullptr, Z_Construct_UFunction_UPico_ProductArray_GetSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ProductArray_GetSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_ProductArray_GetSize_Statics::Pico_ProductArray_eventGetSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ProductArray_GetSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_ProductArray_GetSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ProductArray_GetSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_ProductArray_GetSize_Statics::Pico_ProductArray_eventGetSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_ProductArray_GetSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_ProductArray_GetSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_ProductArray_HasNextPage_Statics
	{
		struct Pico_ProductArray_eventHasNextPage_Parms
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
	void Z_Construct_UFunction_UPico_ProductArray_HasNextPage_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_ProductArray_eventHasNextPage_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_ProductArray_HasNextPage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_ProductArray_eventHasNextPage_Parms), &Z_Construct_UFunction_UPico_ProductArray_HasNextPage_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_ProductArray_HasNextPage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_ProductArray_HasNextPage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_ProductArray_HasNextPage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Product Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get whether the list has the next page.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get whether the list has the next page." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_ProductArray_HasNextPage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_ProductArray, nullptr, "HasNextPage", nullptr, nullptr, Z_Construct_UFunction_UPico_ProductArray_HasNextPage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ProductArray_HasNextPage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_ProductArray_HasNextPage_Statics::Pico_ProductArray_eventHasNextPage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ProductArray_HasNextPage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_ProductArray_HasNextPage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_ProductArray_HasNextPage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_ProductArray_HasNextPage_Statics::Pico_ProductArray_eventHasNextPage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_ProductArray_HasNextPage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_ProductArray_HasNextPage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_ProductArray);
	UClass* Z_Construct_UClass_UPico_ProductArray_NoRegister()
	{
		return UPico_ProductArray::StaticClass();
	}
	struct Z_Construct_UClass_UPico_ProductArray_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ProductArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProductArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ProductArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_ProductArray_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ProductArray_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_ProductArray_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_ProductArray_GetElement, "GetElement" }, // 1460633961
		{ &Z_Construct_UFunction_UPico_ProductArray_GetNextPageParam, "GetNextPageParam" }, // 3699147781
		{ &Z_Construct_UFunction_UPico_ProductArray_GetSize, "GetSize" }, // 635421764
		{ &Z_Construct_UFunction_UPico_ProductArray_HasNextPage, "HasNextPage" }, // 1996742129
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ProductArray_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_ProductArray_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * PPF_ProductArray.h\n *//// @brief UPico_ProductArray class.\n" },
#endif
		{ "IncludePath", "Pico_IAP.h" },
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "PPF_ProductArray.h\n /// @brief UPico_ProductArray class." },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPico_ProductArray_Statics::NewProp_ProductArray_Inner = { "ProductArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UPico_Product_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_ProductArray_Statics::NewProp_ProductArray_MetaData[] = {
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPico_ProductArray_Statics::NewProp_ProductArray = { "ProductArray", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPico_ProductArray, ProductArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ProductArray_Statics::NewProp_ProductArray_MetaData), Z_Construct_UClass_UPico_ProductArray_Statics::NewProp_ProductArray_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPico_ProductArray_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_ProductArray_Statics::NewProp_ProductArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_ProductArray_Statics::NewProp_ProductArray,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_ProductArray_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_ProductArray>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_ProductArray_Statics::ClassParams = {
		&UPico_ProductArray::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPico_ProductArray_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ProductArray_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ProductArray_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_ProductArray_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_ProductArray_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPico_ProductArray()
	{
		if (!Z_Registration_Info_UClass_UPico_ProductArray.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_ProductArray.OuterSingleton, Z_Construct_UClass_UPico_ProductArray_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_ProductArray.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_ProductArray>()
	{
		return UPico_ProductArray::StaticClass();
	}
	UPico_ProductArray::UPico_ProductArray(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_ProductArray);
	UPico_ProductArray::~UPico_ProductArray() {}
	DEFINE_FUNCTION(UPico_Purchase::execGetOrderComment)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetOrderComment();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Purchase::execGetDiscountType)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EDiscountType*)Z_Param__Result=P_THIS->GetDiscountType();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Purchase::execGetNextPayTime)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int64*)Z_Param__Result=P_THIS->GetNextPayTime();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Purchase::execGetOuterId)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetOuterId();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Purchase::execGetNextPeriodType)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EPeriodType*)Z_Param__Result=P_THIS->GetNextPeriodType();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Purchase::execGetCurrentPeriodType)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EPeriodType*)Z_Param__Result=P_THIS->GetCurrentPeriodType();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Purchase::execGetAddonsType)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EAddonsType*)Z_Param__Result=P_THIS->GetAddonsType();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Purchase::execGetIcon)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetIcon();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Purchase::execGetSKU)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetSKU();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Purchase::execGetID)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetID();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Purchase::execGetGrantTime)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int64*)Z_Param__Result=P_THIS->GetGrantTime();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_Purchase::execGetExpirationTime)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int64*)Z_Param__Result=P_THIS->GetExpirationTime();
		P_NATIVE_END;
	}
	void UPico_Purchase::StaticRegisterNativesUPico_Purchase()
	{
		UClass* Class = UPico_Purchase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAddonsType", &UPico_Purchase::execGetAddonsType },
			{ "GetCurrentPeriodType", &UPico_Purchase::execGetCurrentPeriodType },
			{ "GetDiscountType", &UPico_Purchase::execGetDiscountType },
			{ "GetExpirationTime", &UPico_Purchase::execGetExpirationTime },
			{ "GetGrantTime", &UPico_Purchase::execGetGrantTime },
			{ "GetIcon", &UPico_Purchase::execGetIcon },
			{ "GetID", &UPico_Purchase::execGetID },
			{ "GetNextPayTime", &UPico_Purchase::execGetNextPayTime },
			{ "GetNextPeriodType", &UPico_Purchase::execGetNextPeriodType },
			{ "GetOrderComment", &UPico_Purchase::execGetOrderComment },
			{ "GetOuterId", &UPico_Purchase::execGetOuterId },
			{ "GetSKU", &UPico_Purchase::execGetSKU },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_Purchase_GetAddonsType_Statics
	{
		struct Pico_Purchase_eventGetAddonsType_Parms
		{
			EAddonsType ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPico_Purchase_GetAddonsType_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPico_Purchase_GetAddonsType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Purchase_eventGetAddonsType_Parms, ReturnValue), Z_Construct_UEnum_OnlineSubsystemPico_EAddonsType, METADATA_PARAMS(0, nullptr) }; // 2234045637
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Purchase_GetAddonsType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Purchase_GetAddonsType_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Purchase_GetAddonsType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Purchase_GetAddonsType_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Purchase" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The type of the purchased add-on.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The type of the purchased add-on." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Purchase_GetAddonsType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Purchase, nullptr, "GetAddonsType", nullptr, nullptr, Z_Construct_UFunction_UPico_Purchase_GetAddonsType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetAddonsType_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Purchase_GetAddonsType_Statics::Pico_Purchase_eventGetAddonsType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetAddonsType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Purchase_GetAddonsType_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetAddonsType_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Purchase_GetAddonsType_Statics::Pico_Purchase_eventGetAddonsType_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Purchase_GetAddonsType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Purchase_GetAddonsType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Purchase_GetCurrentPeriodType_Statics
	{
		struct Pico_Purchase_eventGetCurrentPeriodType_Parms
		{
			EPeriodType ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPico_Purchase_GetCurrentPeriodType_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPico_Purchase_GetCurrentPeriodType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Purchase_eventGetCurrentPeriodType_Parms, ReturnValue), Z_Construct_UEnum_OnlineSubsystemPico_EPeriodType, METADATA_PARAMS(0, nullptr) }; // 3471629836
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Purchase_GetCurrentPeriodType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Purchase_GetCurrentPeriodType_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Purchase_GetCurrentPeriodType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Purchase_GetCurrentPeriodType_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Purchase" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The current period type of subscription. Only valid when it's subscription.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The current period type of subscription. Only valid when it's subscription." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Purchase_GetCurrentPeriodType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Purchase, nullptr, "GetCurrentPeriodType", nullptr, nullptr, Z_Construct_UFunction_UPico_Purchase_GetCurrentPeriodType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetCurrentPeriodType_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Purchase_GetCurrentPeriodType_Statics::Pico_Purchase_eventGetCurrentPeriodType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetCurrentPeriodType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Purchase_GetCurrentPeriodType_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetCurrentPeriodType_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Purchase_GetCurrentPeriodType_Statics::Pico_Purchase_eventGetCurrentPeriodType_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Purchase_GetCurrentPeriodType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Purchase_GetCurrentPeriodType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Purchase_GetDiscountType_Statics
	{
		struct Pico_Purchase_eventGetDiscountType_Parms
		{
			EDiscountType ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPico_Purchase_GetDiscountType_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPico_Purchase_GetDiscountType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Purchase_eventGetDiscountType_Parms, ReturnValue), Z_Construct_UEnum_OnlineSubsystemPico_EDiscountType, METADATA_PARAMS(0, nullptr) }; // 3402916840
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Purchase_GetDiscountType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Purchase_GetDiscountType_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Purchase_GetDiscountType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Purchase_GetDiscountType_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Purchase" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief The discount info of the purchase.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The discount info of the purchase." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Purchase_GetDiscountType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Purchase, nullptr, "GetDiscountType", nullptr, nullptr, Z_Construct_UFunction_UPico_Purchase_GetDiscountType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetDiscountType_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Purchase_GetDiscountType_Statics::Pico_Purchase_eventGetDiscountType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetDiscountType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Purchase_GetDiscountType_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetDiscountType_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Purchase_GetDiscountType_Statics::Pico_Purchase_eventGetDiscountType_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Purchase_GetDiscountType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Purchase_GetDiscountType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Purchase_GetExpirationTime_Statics
	{
		struct Pico_Purchase_eventGetExpirationTime_Parms
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
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UPico_Purchase_GetExpirationTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Purchase_eventGetExpirationTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Purchase_GetExpirationTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Purchase_GetExpirationTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Purchase_GetExpirationTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Purchase" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief The expiration time. Only valid when it's subscription type.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The expiration time. Only valid when it's subscription type." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Purchase_GetExpirationTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Purchase, nullptr, "GetExpirationTime", nullptr, nullptr, Z_Construct_UFunction_UPico_Purchase_GetExpirationTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetExpirationTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Purchase_GetExpirationTime_Statics::Pico_Purchase_eventGetExpirationTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetExpirationTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Purchase_GetExpirationTime_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetExpirationTime_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Purchase_GetExpirationTime_Statics::Pico_Purchase_eventGetExpirationTime_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Purchase_GetExpirationTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Purchase_GetExpirationTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Purchase_GetGrantTime_Statics
	{
		struct Pico_Purchase_eventGetGrantTime_Parms
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
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UPico_Purchase_GetGrantTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Purchase_eventGetGrantTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Purchase_GetGrantTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Purchase_GetGrantTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Purchase_GetGrantTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Purchase" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief The grant time. Only valid when it's subscription type.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The grant time. Only valid when it's subscription type." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Purchase_GetGrantTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Purchase, nullptr, "GetGrantTime", nullptr, nullptr, Z_Construct_UFunction_UPico_Purchase_GetGrantTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetGrantTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Purchase_GetGrantTime_Statics::Pico_Purchase_eventGetGrantTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetGrantTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Purchase_GetGrantTime_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetGrantTime_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Purchase_GetGrantTime_Statics::Pico_Purchase_eventGetGrantTime_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Purchase_GetGrantTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Purchase_GetGrantTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Purchase_GetIcon_Statics
	{
		struct Pico_Purchase_eventGetIcon_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_Purchase_GetIcon_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Purchase_eventGetIcon_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Purchase_GetIcon_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Purchase_GetIcon_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Purchase_GetIcon_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Purchase" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The icon of the add-on.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The icon of the add-on." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Purchase_GetIcon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Purchase, nullptr, "GetIcon", nullptr, nullptr, Z_Construct_UFunction_UPico_Purchase_GetIcon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetIcon_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Purchase_GetIcon_Statics::Pico_Purchase_eventGetIcon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetIcon_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Purchase_GetIcon_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetIcon_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Purchase_GetIcon_Statics::Pico_Purchase_eventGetIcon_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Purchase_GetIcon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Purchase_GetIcon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Purchase_GetID_Statics
	{
		struct Pico_Purchase_eventGetID_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_Purchase_GetID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Purchase_eventGetID_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Purchase_GetID_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Purchase_GetID_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Purchase_GetID_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Purchase" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The ID of the purchase order. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The ID of the purchase order." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Purchase_GetID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Purchase, nullptr, "GetID", nullptr, nullptr, Z_Construct_UFunction_UPico_Purchase_GetID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetID_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Purchase_GetID_Statics::Pico_Purchase_eventGetID_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Purchase_GetID_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetID_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Purchase_GetID_Statics::Pico_Purchase_eventGetID_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Purchase_GetID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Purchase_GetID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Purchase_GetNextPayTime_Statics
	{
		struct Pico_Purchase_eventGetNextPayTime_Parms
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
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UPico_Purchase_GetNextPayTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Purchase_eventGetNextPayTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Purchase_GetNextPayTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Purchase_GetNextPayTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Purchase_GetNextPayTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Purchase" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The next pay time of subscription. Only valid when it's subscription.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The next pay time of subscription. Only valid when it's subscription." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Purchase_GetNextPayTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Purchase, nullptr, "GetNextPayTime", nullptr, nullptr, Z_Construct_UFunction_UPico_Purchase_GetNextPayTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetNextPayTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Purchase_GetNextPayTime_Statics::Pico_Purchase_eventGetNextPayTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetNextPayTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Purchase_GetNextPayTime_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetNextPayTime_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Purchase_GetNextPayTime_Statics::Pico_Purchase_eventGetNextPayTime_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Purchase_GetNextPayTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Purchase_GetNextPayTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Purchase_GetNextPeriodType_Statics
	{
		struct Pico_Purchase_eventGetNextPeriodType_Parms
		{
			EPeriodType ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPico_Purchase_GetNextPeriodType_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPico_Purchase_GetNextPeriodType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Purchase_eventGetNextPeriodType_Parms, ReturnValue), Z_Construct_UEnum_OnlineSubsystemPico_EPeriodType, METADATA_PARAMS(0, nullptr) }; // 3471629836
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Purchase_GetNextPeriodType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Purchase_GetNextPeriodType_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Purchase_GetNextPeriodType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Purchase_GetNextPeriodType_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Purchase" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The next period type of subscription. Only valid when it's subscription.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The next period type of subscription. Only valid when it's subscription." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Purchase_GetNextPeriodType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Purchase, nullptr, "GetNextPeriodType", nullptr, nullptr, Z_Construct_UFunction_UPico_Purchase_GetNextPeriodType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetNextPeriodType_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Purchase_GetNextPeriodType_Statics::Pico_Purchase_eventGetNextPeriodType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetNextPeriodType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Purchase_GetNextPeriodType_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetNextPeriodType_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Purchase_GetNextPeriodType_Statics::Pico_Purchase_eventGetNextPeriodType_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Purchase_GetNextPeriodType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Purchase_GetNextPeriodType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Purchase_GetOrderComment_Statics
	{
		struct Pico_Purchase_eventGetOrderComment_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_Purchase_GetOrderComment_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Purchase_eventGetOrderComment_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Purchase_GetOrderComment_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Purchase_GetOrderComment_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Purchase_GetOrderComment_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Purchase" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Extended comment field for a purchase .*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Extended comment field for a purchase ." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Purchase_GetOrderComment_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Purchase, nullptr, "GetOrderComment", nullptr, nullptr, Z_Construct_UFunction_UPico_Purchase_GetOrderComment_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetOrderComment_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Purchase_GetOrderComment_Statics::Pico_Purchase_eventGetOrderComment_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetOrderComment_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Purchase_GetOrderComment_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetOrderComment_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Purchase_GetOrderComment_Statics::Pico_Purchase_eventGetOrderComment_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Purchase_GetOrderComment()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Purchase_GetOrderComment_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Purchase_GetOuterId_Statics
	{
		struct Pico_Purchase_eventGetOuterId_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_Purchase_GetOuterId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Purchase_eventGetOuterId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Purchase_GetOuterId_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Purchase_GetOuterId_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Purchase_GetOuterId_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Purchase" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The outer id of the purchased add-on.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The outer id of the purchased add-on." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Purchase_GetOuterId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Purchase, nullptr, "GetOuterId", nullptr, nullptr, Z_Construct_UFunction_UPico_Purchase_GetOuterId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetOuterId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Purchase_GetOuterId_Statics::Pico_Purchase_eventGetOuterId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetOuterId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Purchase_GetOuterId_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetOuterId_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Purchase_GetOuterId_Statics::Pico_Purchase_eventGetOuterId_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Purchase_GetOuterId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Purchase_GetOuterId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_Purchase_GetSKU_Statics
	{
		struct Pico_Purchase_eventGetSKU_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_Purchase_GetSKU_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_Purchase_eventGetSKU_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_Purchase_GetSKU_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_Purchase_GetSKU_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_Purchase_GetSKU_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Purchase" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief The unique identifier of the add-on in the purchase order. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief The unique identifier of the add-on in the purchase order." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_Purchase_GetSKU_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_Purchase, nullptr, "GetSKU", nullptr, nullptr, Z_Construct_UFunction_UPico_Purchase_GetSKU_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetSKU_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_Purchase_GetSKU_Statics::Pico_Purchase_eventGetSKU_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetSKU_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_Purchase_GetSKU_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_Purchase_GetSKU_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_Purchase_GetSKU_Statics::Pico_Purchase_eventGetSKU_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_Purchase_GetSKU()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_Purchase_GetSKU_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_Purchase);
	UClass* Z_Construct_UClass_UPico_Purchase_NoRegister()
	{
		return UPico_Purchase::StaticClass();
	}
	struct Z_Construct_UClass_UPico_Purchase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_Purchase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_Purchase_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_Purchase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_Purchase_GetAddonsType, "GetAddonsType" }, // 2939620297
		{ &Z_Construct_UFunction_UPico_Purchase_GetCurrentPeriodType, "GetCurrentPeriodType" }, // 1301507066
		{ &Z_Construct_UFunction_UPico_Purchase_GetDiscountType, "GetDiscountType" }, // 3850429816
		{ &Z_Construct_UFunction_UPico_Purchase_GetExpirationTime, "GetExpirationTime" }, // 3493219844
		{ &Z_Construct_UFunction_UPico_Purchase_GetGrantTime, "GetGrantTime" }, // 401680838
		{ &Z_Construct_UFunction_UPico_Purchase_GetIcon, "GetIcon" }, // 3434638313
		{ &Z_Construct_UFunction_UPico_Purchase_GetID, "GetID" }, // 4042551291
		{ &Z_Construct_UFunction_UPico_Purchase_GetNextPayTime, "GetNextPayTime" }, // 861986570
		{ &Z_Construct_UFunction_UPico_Purchase_GetNextPeriodType, "GetNextPeriodType" }, // 2965227041
		{ &Z_Construct_UFunction_UPico_Purchase_GetOrderComment, "GetOrderComment" }, // 3021782186
		{ &Z_Construct_UFunction_UPico_Purchase_GetOuterId, "GetOuterId" }, // 283827188
		{ &Z_Construct_UFunction_UPico_Purchase_GetSKU, "GetSKU" }, // 1285482756
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_Purchase_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_Purchase_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * PPF_Purchase.h\n *//// @brief UPico_Purchase class.\n" },
#endif
		{ "IncludePath", "Pico_IAP.h" },
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "PPF_Purchase.h\n /// @brief UPico_Purchase class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_Purchase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_Purchase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_Purchase_Statics::ClassParams = {
		&UPico_Purchase::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_Purchase_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_Purchase_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPico_Purchase()
	{
		if (!Z_Registration_Info_UClass_UPico_Purchase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_Purchase.OuterSingleton, Z_Construct_UClass_UPico_Purchase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_Purchase.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_Purchase>()
	{
		return UPico_Purchase::StaticClass();
	}
	UPico_Purchase::UPico_Purchase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_Purchase);
	UPico_Purchase::~UPico_Purchase() {}
	DEFINE_FUNCTION(UPico_PurchaseArray::execHasNextPage)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->HasNextPage();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_PurchaseArray::execGetSize)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetSize();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_PurchaseArray::execGetNextPageParam)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetNextPageParam();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_PurchaseArray::execGetElement)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UPico_Purchase**)Z_Param__Result=P_THIS->GetElement(Z_Param_Index);
		P_NATIVE_END;
	}
	void UPico_PurchaseArray::StaticRegisterNativesUPico_PurchaseArray()
	{
		UClass* Class = UPico_PurchaseArray::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetElement", &UPico_PurchaseArray::execGetElement },
			{ "GetNextPageParam", &UPico_PurchaseArray::execGetNextPageParam },
			{ "GetSize", &UPico_PurchaseArray::execGetSize },
			{ "HasNextPage", &UPico_PurchaseArray::execHasNextPage },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_PurchaseArray_GetElement_Statics
	{
		struct Pico_PurchaseArray_eventGetElement_Parms
		{
			int32 Index;
			UPico_Purchase* ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_PurchaseArray_GetElement_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_PurchaseArray_eventGetElement_Parms, Index), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPico_PurchaseArray_GetElement_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_PurchaseArray_eventGetElement_Parms, ReturnValue), Z_Construct_UClass_UPico_Purchase_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_PurchaseArray_GetElement_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_PurchaseArray_GetElement_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_PurchaseArray_GetElement_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_PurchaseArray_GetElement_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Purchase Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get PurchaseArray element form Index.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get PurchaseArray element form Index." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_PurchaseArray_GetElement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_PurchaseArray, nullptr, "GetElement", nullptr, nullptr, Z_Construct_UFunction_UPico_PurchaseArray_GetElement_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PurchaseArray_GetElement_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_PurchaseArray_GetElement_Statics::Pico_PurchaseArray_eventGetElement_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PurchaseArray_GetElement_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_PurchaseArray_GetElement_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PurchaseArray_GetElement_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_PurchaseArray_GetElement_Statics::Pico_PurchaseArray_eventGetElement_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_PurchaseArray_GetElement()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_PurchaseArray_GetElement_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_PurchaseArray_GetNextPageParam_Statics
	{
		struct Pico_PurchaseArray_eventGetNextPageParam_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_PurchaseArray_GetNextPageParam_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_PurchaseArray_eventGetNextPageParam_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_PurchaseArray_GetNextPageParam_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_PurchaseArray_GetNextPageParam_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_PurchaseArray_GetNextPageParam_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Purchase Array" },
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_PurchaseArray_GetNextPageParam_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_PurchaseArray, nullptr, "GetNextPageParam", nullptr, nullptr, Z_Construct_UFunction_UPico_PurchaseArray_GetNextPageParam_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PurchaseArray_GetNextPageParam_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_PurchaseArray_GetNextPageParam_Statics::Pico_PurchaseArray_eventGetNextPageParam_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PurchaseArray_GetNextPageParam_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_PurchaseArray_GetNextPageParam_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PurchaseArray_GetNextPageParam_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_PurchaseArray_GetNextPageParam_Statics::Pico_PurchaseArray_eventGetNextPageParam_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_PurchaseArray_GetNextPageParam()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_PurchaseArray_GetNextPageParam_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_PurchaseArray_GetSize_Statics
	{
		struct Pico_PurchaseArray_eventGetSize_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_PurchaseArray_GetSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_PurchaseArray_eventGetSize_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_PurchaseArray_GetSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_PurchaseArray_GetSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_PurchaseArray_GetSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Purchase Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get the size of PurchaseArray .*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get the size of PurchaseArray ." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_PurchaseArray_GetSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_PurchaseArray, nullptr, "GetSize", nullptr, nullptr, Z_Construct_UFunction_UPico_PurchaseArray_GetSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PurchaseArray_GetSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_PurchaseArray_GetSize_Statics::Pico_PurchaseArray_eventGetSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PurchaseArray_GetSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_PurchaseArray_GetSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PurchaseArray_GetSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_PurchaseArray_GetSize_Statics::Pico_PurchaseArray_eventGetSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_PurchaseArray_GetSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_PurchaseArray_GetSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_PurchaseArray_HasNextPage_Statics
	{
		struct Pico_PurchaseArray_eventHasNextPage_Parms
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
	void Z_Construct_UFunction_UPico_PurchaseArray_HasNextPage_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_PurchaseArray_eventHasNextPage_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_PurchaseArray_HasNextPage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_PurchaseArray_eventHasNextPage_Parms), &Z_Construct_UFunction_UPico_PurchaseArray_HasNextPage_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_PurchaseArray_HasNextPage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_PurchaseArray_HasNextPage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_PurchaseArray_HasNextPage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|Purchase Array" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Get whether the list has the next page.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Get whether the list has the next page." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_PurchaseArray_HasNextPage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_PurchaseArray, nullptr, "HasNextPage", nullptr, nullptr, Z_Construct_UFunction_UPico_PurchaseArray_HasNextPage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PurchaseArray_HasNextPage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_PurchaseArray_HasNextPage_Statics::Pico_PurchaseArray_eventHasNextPage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PurchaseArray_HasNextPage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_PurchaseArray_HasNextPage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_PurchaseArray_HasNextPage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_PurchaseArray_HasNextPage_Statics::Pico_PurchaseArray_eventHasNextPage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_PurchaseArray_HasNextPage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_PurchaseArray_HasNextPage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_PurchaseArray);
	UClass* Z_Construct_UClass_UPico_PurchaseArray_NoRegister()
	{
		return UPico_PurchaseArray::StaticClass();
	}
	struct Z_Construct_UClass_UPico_PurchaseArray_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PurchaseArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PurchaseArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_PurchaseArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_PurchaseArray_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_PurchaseArray_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_PurchaseArray_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_PurchaseArray_GetElement, "GetElement" }, // 3617205814
		{ &Z_Construct_UFunction_UPico_PurchaseArray_GetNextPageParam, "GetNextPageParam" }, // 1009587894
		{ &Z_Construct_UFunction_UPico_PurchaseArray_GetSize, "GetSize" }, // 3862894244
		{ &Z_Construct_UFunction_UPico_PurchaseArray_HasNextPage, "HasNextPage" }, // 3629186751
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_PurchaseArray_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_PurchaseArray_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * PPF_PurchaseArray.h\n *//// @brief UPico_PurchaseArray class.\n" },
#endif
		{ "IncludePath", "Pico_IAP.h" },
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "PPF_PurchaseArray.h\n /// @brief UPico_PurchaseArray class." },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPico_PurchaseArray_Statics::NewProp_PurchaseArray_Inner = { "PurchaseArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UPico_Purchase_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_PurchaseArray_Statics::NewProp_PurchaseArray_MetaData[] = {
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPico_PurchaseArray_Statics::NewProp_PurchaseArray = { "PurchaseArray", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPico_PurchaseArray, PurchaseArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_PurchaseArray_Statics::NewProp_PurchaseArray_MetaData), Z_Construct_UClass_UPico_PurchaseArray_Statics::NewProp_PurchaseArray_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPico_PurchaseArray_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_PurchaseArray_Statics::NewProp_PurchaseArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPico_PurchaseArray_Statics::NewProp_PurchaseArray,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_PurchaseArray_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_PurchaseArray>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_PurchaseArray_Statics::ClassParams = {
		&UPico_PurchaseArray::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPico_PurchaseArray_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPico_PurchaseArray_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_PurchaseArray_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_PurchaseArray_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_PurchaseArray_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPico_PurchaseArray()
	{
		if (!Z_Registration_Info_UClass_UPico_PurchaseArray.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_PurchaseArray.OuterSingleton, Z_Construct_UClass_UPico_PurchaseArray_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_PurchaseArray.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_PurchaseArray>()
	{
		return UPico_PurchaseArray::StaticClass();
	}
	UPico_PurchaseArray::UPico_PurchaseArray(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_PurchaseArray);
	UPico_PurchaseArray::~UPico_PurchaseArray() {}
	DEFINE_FUNCTION(UPico_SubscriptionStatus::execGetNextPeriod)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetNextPeriod();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SubscriptionStatus::execGetIsFreeTrial)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetIsFreeTrial();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SubscriptionStatus::execGetCancelReason)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ECancelReason*)Z_Param__Result=P_THIS->GetCancelReason();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SubscriptionStatus::execGetEntitlementStatus)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EEntitlementStatus*)Z_Param__Result=P_THIS->GetEntitlementStatus();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SubscriptionStatus::execGetCurrentPeriodType)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EPeriodType*)Z_Param__Result=P_THIS->GetCurrentPeriodType();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SubscriptionStatus::execGetEndTime)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int64*)Z_Param__Result=P_THIS->GetEndTime();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SubscriptionStatus::execGetStartTime)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int64*)Z_Param__Result=P_THIS->GetStartTime();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SubscriptionStatus::execGetOuterId)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetOuterId();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SubscriptionStatus::execGetSKU)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetSKU();
		P_NATIVE_END;
	}
	void UPico_SubscriptionStatus::StaticRegisterNativesUPico_SubscriptionStatus()
	{
		UClass* Class = UPico_SubscriptionStatus::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetCancelReason", &UPico_SubscriptionStatus::execGetCancelReason },
			{ "GetCurrentPeriodType", &UPico_SubscriptionStatus::execGetCurrentPeriodType },
			{ "GetEndTime", &UPico_SubscriptionStatus::execGetEndTime },
			{ "GetEntitlementStatus", &UPico_SubscriptionStatus::execGetEntitlementStatus },
			{ "GetIsFreeTrial", &UPico_SubscriptionStatus::execGetIsFreeTrial },
			{ "GetNextPeriod", &UPico_SubscriptionStatus::execGetNextPeriod },
			{ "GetOuterId", &UPico_SubscriptionStatus::execGetOuterId },
			{ "GetSKU", &UPico_SubscriptionStatus::execGetSKU },
			{ "GetStartTime", &UPico_SubscriptionStatus::execGetStartTime },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_SubscriptionStatus_GetCancelReason_Statics
	{
		struct Pico_SubscriptionStatus_eventGetCancelReason_Parms
		{
			ECancelReason ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPico_SubscriptionStatus_GetCancelReason_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPico_SubscriptionStatus_GetCancelReason_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SubscriptionStatus_eventGetCancelReason_Parms, ReturnValue), Z_Construct_UEnum_OnlineSubsystemPico_ECancelReason, METADATA_PARAMS(0, nullptr) }; // 1500011161
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SubscriptionStatus_GetCancelReason_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SubscriptionStatus_GetCancelReason_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SubscriptionStatus_GetCancelReason_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SubscriptionStatus_GetCancelReason_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|SubscriptionStatus" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Gets the Reason for user unsubscribing.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Gets the Reason for user unsubscribing." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SubscriptionStatus_GetCancelReason_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SubscriptionStatus, nullptr, "GetCancelReason", nullptr, nullptr, Z_Construct_UFunction_UPico_SubscriptionStatus_GetCancelReason_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetCancelReason_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SubscriptionStatus_GetCancelReason_Statics::Pico_SubscriptionStatus_eventGetCancelReason_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetCancelReason_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SubscriptionStatus_GetCancelReason_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetCancelReason_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SubscriptionStatus_GetCancelReason_Statics::Pico_SubscriptionStatus_eventGetCancelReason_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SubscriptionStatus_GetCancelReason()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SubscriptionStatus_GetCancelReason_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SubscriptionStatus_GetCurrentPeriodType_Statics
	{
		struct Pico_SubscriptionStatus_eventGetCurrentPeriodType_Parms
		{
			EPeriodType ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPico_SubscriptionStatus_GetCurrentPeriodType_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPico_SubscriptionStatus_GetCurrentPeriodType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SubscriptionStatus_eventGetCurrentPeriodType_Parms, ReturnValue), Z_Construct_UEnum_OnlineSubsystemPico_EPeriodType, METADATA_PARAMS(0, nullptr) }; // 3471629836
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SubscriptionStatus_GetCurrentPeriodType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SubscriptionStatus_GetCurrentPeriodType_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SubscriptionStatus_GetCurrentPeriodType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SubscriptionStatus_GetCurrentPeriodType_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|SubscriptionStatus" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Gets the unit type of the subscription period.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Gets the unit type of the subscription period." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SubscriptionStatus_GetCurrentPeriodType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SubscriptionStatus, nullptr, "GetCurrentPeriodType", nullptr, nullptr, Z_Construct_UFunction_UPico_SubscriptionStatus_GetCurrentPeriodType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetCurrentPeriodType_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SubscriptionStatus_GetCurrentPeriodType_Statics::Pico_SubscriptionStatus_eventGetCurrentPeriodType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetCurrentPeriodType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SubscriptionStatus_GetCurrentPeriodType_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetCurrentPeriodType_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SubscriptionStatus_GetCurrentPeriodType_Statics::Pico_SubscriptionStatus_eventGetCurrentPeriodType_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SubscriptionStatus_GetCurrentPeriodType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SubscriptionStatus_GetCurrentPeriodType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SubscriptionStatus_GetEndTime_Statics
	{
		struct Pico_SubscriptionStatus_eventGetEndTime_Parms
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
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UPico_SubscriptionStatus_GetEndTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SubscriptionStatus_eventGetEndTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SubscriptionStatus_GetEndTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SubscriptionStatus_GetEndTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SubscriptionStatus_GetEndTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|SubscriptionStatus" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief Gets the end time of the subscription period.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Gets the end time of the subscription period." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SubscriptionStatus_GetEndTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SubscriptionStatus, nullptr, "GetEndTime", nullptr, nullptr, Z_Construct_UFunction_UPico_SubscriptionStatus_GetEndTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetEndTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SubscriptionStatus_GetEndTime_Statics::Pico_SubscriptionStatus_eventGetEndTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetEndTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SubscriptionStatus_GetEndTime_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetEndTime_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SubscriptionStatus_GetEndTime_Statics::Pico_SubscriptionStatus_eventGetEndTime_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SubscriptionStatus_GetEndTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SubscriptionStatus_GetEndTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SubscriptionStatus_GetEntitlementStatus_Statics
	{
		struct Pico_SubscriptionStatus_eventGetEntitlementStatus_Parms
		{
			EEntitlementStatus ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UPico_SubscriptionStatus_GetEntitlementStatus_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UPico_SubscriptionStatus_GetEntitlementStatus_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SubscriptionStatus_eventGetEntitlementStatus_Parms, ReturnValue), Z_Construct_UEnum_OnlineSubsystemPico_EEntitlementStatus, METADATA_PARAMS(0, nullptr) }; // 4008459361
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SubscriptionStatus_GetEntitlementStatus_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SubscriptionStatus_GetEntitlementStatus_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SubscriptionStatus_GetEntitlementStatus_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SubscriptionStatus_GetEntitlementStatus_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|SubscriptionStatus" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Gets the subscription status of the Add-on.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Gets the subscription status of the Add-on." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SubscriptionStatus_GetEntitlementStatus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SubscriptionStatus, nullptr, "GetEntitlementStatus", nullptr, nullptr, Z_Construct_UFunction_UPico_SubscriptionStatus_GetEntitlementStatus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetEntitlementStatus_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SubscriptionStatus_GetEntitlementStatus_Statics::Pico_SubscriptionStatus_eventGetEntitlementStatus_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetEntitlementStatus_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SubscriptionStatus_GetEntitlementStatus_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetEntitlementStatus_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SubscriptionStatus_GetEntitlementStatus_Statics::Pico_SubscriptionStatus_eventGetEntitlementStatus_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SubscriptionStatus_GetEntitlementStatus()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SubscriptionStatus_GetEntitlementStatus_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SubscriptionStatus_GetIsFreeTrial_Statics
	{
		struct Pico_SubscriptionStatus_eventGetIsFreeTrial_Parms
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
	void Z_Construct_UFunction_UPico_SubscriptionStatus_GetIsFreeTrial_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_SubscriptionStatus_eventGetIsFreeTrial_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_SubscriptionStatus_GetIsFreeTrial_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_SubscriptionStatus_eventGetIsFreeTrial_Parms), &Z_Construct_UFunction_UPico_SubscriptionStatus_GetIsFreeTrial_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SubscriptionStatus_GetIsFreeTrial_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SubscriptionStatus_GetIsFreeTrial_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SubscriptionStatus_GetIsFreeTrial_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|SubscriptionStatus" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Whether the user is in the free-trail period.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Whether the user is in the free-trail period." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SubscriptionStatus_GetIsFreeTrial_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SubscriptionStatus, nullptr, "GetIsFreeTrial", nullptr, nullptr, Z_Construct_UFunction_UPico_SubscriptionStatus_GetIsFreeTrial_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetIsFreeTrial_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SubscriptionStatus_GetIsFreeTrial_Statics::Pico_SubscriptionStatus_eventGetIsFreeTrial_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetIsFreeTrial_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SubscriptionStatus_GetIsFreeTrial_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetIsFreeTrial_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SubscriptionStatus_GetIsFreeTrial_Statics::Pico_SubscriptionStatus_eventGetIsFreeTrial_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SubscriptionStatus_GetIsFreeTrial()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SubscriptionStatus_GetIsFreeTrial_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SubscriptionStatus_GetNextPeriod_Statics
	{
		struct Pico_SubscriptionStatus_eventGetNextPeriod_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_SubscriptionStatus_GetNextPeriod_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SubscriptionStatus_eventGetNextPeriod_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SubscriptionStatus_GetNextPeriod_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SubscriptionStatus_GetNextPeriod_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SubscriptionStatus_GetNextPeriod_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|SubscriptionStatus" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Gets the next subscription period number. If the user unsubscribes, the next period number is 0.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Gets the next subscription period number. If the user unsubscribes, the next period number is 0." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SubscriptionStatus_GetNextPeriod_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SubscriptionStatus, nullptr, "GetNextPeriod", nullptr, nullptr, Z_Construct_UFunction_UPico_SubscriptionStatus_GetNextPeriod_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetNextPeriod_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SubscriptionStatus_GetNextPeriod_Statics::Pico_SubscriptionStatus_eventGetNextPeriod_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetNextPeriod_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SubscriptionStatus_GetNextPeriod_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetNextPeriod_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SubscriptionStatus_GetNextPeriod_Statics::Pico_SubscriptionStatus_eventGetNextPeriod_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SubscriptionStatus_GetNextPeriod()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SubscriptionStatus_GetNextPeriod_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SubscriptionStatus_GetOuterId_Statics
	{
		struct Pico_SubscriptionStatus_eventGetOuterId_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_SubscriptionStatus_GetOuterId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SubscriptionStatus_eventGetOuterId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SubscriptionStatus_GetOuterId_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SubscriptionStatus_GetOuterId_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SubscriptionStatus_GetOuterId_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|SubscriptionStatus" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Gets the OuterID for the subscription period. The unique identifier for the subscription period.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Gets the OuterID for the subscription period. The unique identifier for the subscription period." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SubscriptionStatus_GetOuterId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SubscriptionStatus, nullptr, "GetOuterId", nullptr, nullptr, Z_Construct_UFunction_UPico_SubscriptionStatus_GetOuterId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetOuterId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SubscriptionStatus_GetOuterId_Statics::Pico_SubscriptionStatus_eventGetOuterId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetOuterId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SubscriptionStatus_GetOuterId_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetOuterId_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SubscriptionStatus_GetOuterId_Statics::Pico_SubscriptionStatus_eventGetOuterId_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SubscriptionStatus_GetOuterId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SubscriptionStatus_GetOuterId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SubscriptionStatus_GetSKU_Statics
	{
		struct Pico_SubscriptionStatus_eventGetSKU_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_SubscriptionStatus_GetSKU_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SubscriptionStatus_eventGetSKU_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SubscriptionStatus_GetSKU_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SubscriptionStatus_GetSKU_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SubscriptionStatus_GetSKU_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|SubscriptionStatus" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @brief Gets the unique identifier of the Add-on in the purchased order.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Gets the unique identifier of the Add-on in the purchased order." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SubscriptionStatus_GetSKU_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SubscriptionStatus, nullptr, "GetSKU", nullptr, nullptr, Z_Construct_UFunction_UPico_SubscriptionStatus_GetSKU_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetSKU_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SubscriptionStatus_GetSKU_Statics::Pico_SubscriptionStatus_eventGetSKU_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetSKU_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SubscriptionStatus_GetSKU_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetSKU_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SubscriptionStatus_GetSKU_Statics::Pico_SubscriptionStatus_eventGetSKU_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SubscriptionStatus_GetSKU()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SubscriptionStatus_GetSKU_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SubscriptionStatus_GetStartTime_Statics
	{
		struct Pico_SubscriptionStatus_eventGetStartTime_Parms
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
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UPico_SubscriptionStatus_GetStartTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SubscriptionStatus_eventGetStartTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SubscriptionStatus_GetStartTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SubscriptionStatus_GetStartTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SubscriptionStatus_GetStartTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|IAP|SubscriptionStatus" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief Gets the start time of the subscription period.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Gets the start time of the subscription period." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SubscriptionStatus_GetStartTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SubscriptionStatus, nullptr, "GetStartTime", nullptr, nullptr, Z_Construct_UFunction_UPico_SubscriptionStatus_GetStartTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetStartTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SubscriptionStatus_GetStartTime_Statics::Pico_SubscriptionStatus_eventGetStartTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetStartTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SubscriptionStatus_GetStartTime_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SubscriptionStatus_GetStartTime_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SubscriptionStatus_GetStartTime_Statics::Pico_SubscriptionStatus_eventGetStartTime_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SubscriptionStatus_GetStartTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SubscriptionStatus_GetStartTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_SubscriptionStatus);
	UClass* Z_Construct_UClass_UPico_SubscriptionStatus_NoRegister()
	{
		return UPico_SubscriptionStatus::StaticClass();
	}
	struct Z_Construct_UClass_UPico_SubscriptionStatus_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_SubscriptionStatus_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_SubscriptionStatus_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_SubscriptionStatus_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_SubscriptionStatus_GetCancelReason, "GetCancelReason" }, // 1437378564
		{ &Z_Construct_UFunction_UPico_SubscriptionStatus_GetCurrentPeriodType, "GetCurrentPeriodType" }, // 3219049998
		{ &Z_Construct_UFunction_UPico_SubscriptionStatus_GetEndTime, "GetEndTime" }, // 1810299828
		{ &Z_Construct_UFunction_UPico_SubscriptionStatus_GetEntitlementStatus, "GetEntitlementStatus" }, // 3142891978
		{ &Z_Construct_UFunction_UPico_SubscriptionStatus_GetIsFreeTrial, "GetIsFreeTrial" }, // 2385104954
		{ &Z_Construct_UFunction_UPico_SubscriptionStatus_GetNextPeriod, "GetNextPeriod" }, // 2391024340
		{ &Z_Construct_UFunction_UPico_SubscriptionStatus_GetOuterId, "GetOuterId" }, // 118318076
		{ &Z_Construct_UFunction_UPico_SubscriptionStatus_GetSKU, "GetSKU" }, // 3296988223
		{ &Z_Construct_UFunction_UPico_SubscriptionStatus_GetStartTime, "GetStartTime" }, // 1972711241
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_SubscriptionStatus_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_SubscriptionStatus_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * PPF_SubscriptionStatus.h\n *//// @brief UPico_SubscriptionStatus class.\n" },
#endif
		{ "IncludePath", "Pico_IAP.h" },
		{ "ModuleRelativePath", "Public/Pico_IAP.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "PPF_SubscriptionStatus.h\n /// @brief UPico_SubscriptionStatus class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_SubscriptionStatus_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_SubscriptionStatus>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_SubscriptionStatus_Statics::ClassParams = {
		&UPico_SubscriptionStatus::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_SubscriptionStatus_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_SubscriptionStatus_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPico_SubscriptionStatus()
	{
		if (!Z_Registration_Info_UClass_UPico_SubscriptionStatus.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_SubscriptionStatus.OuterSingleton, Z_Construct_UClass_UPico_SubscriptionStatus_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_SubscriptionStatus.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_SubscriptionStatus>()
	{
		return UPico_SubscriptionStatus::StaticClass();
	}
	UPico_SubscriptionStatus::UPico_SubscriptionStatus(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_SubscriptionStatus);
	UPico_SubscriptionStatus::~UPico_SubscriptionStatus() {}
	struct Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOnlinePicoIAPFunction, UOnlinePicoIAPFunction::StaticClass, TEXT("UOnlinePicoIAPFunction"), &Z_Registration_Info_UClass_UOnlinePicoIAPFunction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOnlinePicoIAPFunction), 2063757005U) },
		{ Z_Construct_UClass_UPico_Product, UPico_Product::StaticClass, TEXT("UPico_Product"), &Z_Registration_Info_UClass_UPico_Product, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_Product), 591230580U) },
		{ Z_Construct_UClass_UPico_ProductArray, UPico_ProductArray::StaticClass, TEXT("UPico_ProductArray"), &Z_Registration_Info_UClass_UPico_ProductArray, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_ProductArray), 1334570423U) },
		{ Z_Construct_UClass_UPico_Purchase, UPico_Purchase::StaticClass, TEXT("UPico_Purchase"), &Z_Registration_Info_UClass_UPico_Purchase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_Purchase), 840917888U) },
		{ Z_Construct_UClass_UPico_PurchaseArray, UPico_PurchaseArray::StaticClass, TEXT("UPico_PurchaseArray"), &Z_Registration_Info_UClass_UPico_PurchaseArray, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_PurchaseArray), 2637840171U) },
		{ Z_Construct_UClass_UPico_SubscriptionStatus, UPico_SubscriptionStatus::StaticClass, TEXT("UPico_SubscriptionStatus"), &Z_Registration_Info_UClass_UPico_SubscriptionStatus, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_SubscriptionStatus), 113216042U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_853369189(TEXT("/Script/OnlineSubsystemPico"),
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_IAP_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
