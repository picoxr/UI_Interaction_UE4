// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PicoXRHMD/Private/PXR_EventManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePXR_EventManager() {}
// Cross Module References
	PICOXRHMD_API UFunction* Z_Construct_UDelegateFunction_PicoXRHMD_PXRRefreshRateChanged__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_PicoXRHMD();
	PICOXRHMD_API UFunction* Z_Construct_UDelegateFunction_PicoXRHMD_PXRIpdChanged__DelegateSignature();
	PICOXRHMD_API UFunction* Z_Construct_UDelegateFunction_PicoXRHMD_PXRResume__DelegateSignature();
	PICOXRHMD_API UFunction* Z_Construct_UDelegateFunction_PicoXRHMD_PXRLongHomeKey__DelegateSignature();
	PICOXRHMD_API UFunction* Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceConnectChangedDelegage__DelegateSignature();
	PICOXRHMD_API UFunction* Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceMainChangedDelegage__DelegateSignature();
	PICOXRHMD_API UClass* Z_Construct_UClass_UPicoXREventManager_NoRegister();
	PICOXRHMD_API UClass* Z_Construct_UClass_UPicoXREventManager();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_PicoXRHMD_PXRRefreshRateChanged__DelegateSignature_Statics
	{
		struct _Script_PicoXRHMD_eventPXRRefreshRateChanged_Parms
		{
			float NewRate;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewRate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_PicoXRHMD_PXRRefreshRateChanged__DelegateSignature_Statics::NewProp_NewRate = { "NewRate", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_PicoXRHMD_eventPXRRefreshRateChanged_Parms, NewRate), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_PicoXRHMD_PXRRefreshRateChanged__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_PicoXRHMD_PXRRefreshRateChanged__DelegateSignature_Statics::NewProp_NewRate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_PicoXRHMD_PXRRefreshRateChanged__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//SystemDisplayRateDelegate\n" },
		{ "ModuleRelativePath", "Private/PXR_EventManager.h" },
		{ "ToolTip", "SystemDisplayRateDelegate" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_PicoXRHMD_PXRRefreshRateChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_PicoXRHMD, nullptr, "PXRRefreshRateChanged__DelegateSignature", nullptr, nullptr, sizeof(_Script_PicoXRHMD_eventPXRRefreshRateChanged_Parms), Z_Construct_UDelegateFunction_PicoXRHMD_PXRRefreshRateChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PicoXRHMD_PXRRefreshRateChanged__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_PicoXRHMD_PXRRefreshRateChanged__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PicoXRHMD_PXRRefreshRateChanged__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_PicoXRHMD_PXRRefreshRateChanged__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_PicoXRHMD_PXRRefreshRateChanged__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_PicoXRHMD_PXRIpdChanged__DelegateSignature_Statics
	{
		struct _Script_PicoXRHMD_eventPXRIpdChanged_Parms
		{
			float NewIpd;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NewIpd;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_PicoXRHMD_PXRIpdChanged__DelegateSignature_Statics::NewProp_NewIpd = { "NewIpd", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_PicoXRHMD_eventPXRIpdChanged_Parms, NewIpd), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_PicoXRHMD_PXRIpdChanged__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_PicoXRHMD_PXRIpdChanged__DelegateSignature_Statics::NewProp_NewIpd,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_PicoXRHMD_PXRIpdChanged__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//HMDDelegate\n" },
		{ "ModuleRelativePath", "Private/PXR_EventManager.h" },
		{ "ToolTip", "HMDDelegate" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_PicoXRHMD_PXRIpdChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_PicoXRHMD, nullptr, "PXRIpdChanged__DelegateSignature", nullptr, nullptr, sizeof(_Script_PicoXRHMD_eventPXRIpdChanged_Parms), Z_Construct_UDelegateFunction_PicoXRHMD_PXRIpdChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PicoXRHMD_PXRIpdChanged__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_PicoXRHMD_PXRIpdChanged__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PicoXRHMD_PXRIpdChanged__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_PicoXRHMD_PXRIpdChanged__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_PicoXRHMD_PXRIpdChanged__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_PicoXRHMD_PXRResume__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_PicoXRHMD_PXRResume__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/PXR_EventManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_PicoXRHMD_PXRResume__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_PicoXRHMD, nullptr, "PXRResume__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_PicoXRHMD_PXRResume__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PicoXRHMD_PXRResume__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_PicoXRHMD_PXRResume__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_PicoXRHMD_PXRResume__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_PicoXRHMD_PXRLongHomeKey__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_PicoXRHMD_PXRLongHomeKey__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/PXR_EventManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_PicoXRHMD_PXRLongHomeKey__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_PicoXRHMD, nullptr, "PXRLongHomeKey__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_PicoXRHMD_PXRLongHomeKey__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PicoXRHMD_PXRLongHomeKey__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_PicoXRHMD_PXRLongHomeKey__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_PicoXRHMD_PXRLongHomeKey__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceConnectChangedDelegage__DelegateSignature_Statics
	{
		struct _Script_PicoXRHMD_eventPXRDeviceConnectChangedDelegage_Parms
		{
			int32 Handness;
			int32 State;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Handness;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_State;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceConnectChangedDelegage__DelegateSignature_Statics::NewProp_Handness = { "Handness", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_PicoXRHMD_eventPXRDeviceConnectChangedDelegage_Parms, Handness), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceConnectChangedDelegage__DelegateSignature_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_PicoXRHMD_eventPXRDeviceConnectChangedDelegage_Parms, State), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceConnectChangedDelegage__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceConnectChangedDelegage__DelegateSignature_Statics::NewProp_Handness,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceConnectChangedDelegage__DelegateSignature_Statics::NewProp_State,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceConnectChangedDelegage__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/PXR_EventManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceConnectChangedDelegage__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_PicoXRHMD, nullptr, "PXRDeviceConnectChangedDelegage__DelegateSignature", nullptr, nullptr, sizeof(_Script_PicoXRHMD_eventPXRDeviceConnectChangedDelegage_Parms), Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceConnectChangedDelegage__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceConnectChangedDelegage__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceConnectChangedDelegage__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceConnectChangedDelegage__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceConnectChangedDelegage__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceConnectChangedDelegage__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceMainChangedDelegage__DelegateSignature_Statics
	{
		struct _Script_PicoXRHMD_eventPXRDeviceMainChangedDelegage_Parms
		{
			int32 Handness;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Handness;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceMainChangedDelegage__DelegateSignature_Statics::NewProp_Handness = { "Handness", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_PicoXRHMD_eventPXRDeviceMainChangedDelegage_Parms, Handness), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceMainChangedDelegage__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceMainChangedDelegage__DelegateSignature_Statics::NewProp_Handness,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceMainChangedDelegage__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//ControllerDelegate\n" },
		{ "ModuleRelativePath", "Private/PXR_EventManager.h" },
		{ "ToolTip", "ControllerDelegate" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceMainChangedDelegage__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_PicoXRHMD, nullptr, "PXRDeviceMainChangedDelegage__DelegateSignature", nullptr, nullptr, sizeof(_Script_PicoXRHMD_eventPXRDeviceMainChangedDelegage_Parms), Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceMainChangedDelegage__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceMainChangedDelegage__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceMainChangedDelegage__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceMainChangedDelegage__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceMainChangedDelegage__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceMainChangedDelegage__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	void UPicoXREventManager::StaticRegisterNativesUPicoXREventManager()
	{
	}
	UClass* Z_Construct_UClass_UPicoXREventManager_NoRegister()
	{
		return UPicoXREventManager::StaticClass();
	}
	struct Z_Construct_UClass_UPicoXREventManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DeviceMainChangedDelegate_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_DeviceMainChangedDelegate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DeviceConnectChangedDelegate_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_DeviceConnectChangedDelegate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IpdChangedDelegate_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_IpdChangedDelegate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LongHomePressedDelegate_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_LongHomePressedDelegate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ResumeDelegate_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_ResumeDelegate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RefreshRateChangedDelegate_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_RefreshRateChangedDelegate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPicoXREventManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_PicoXRHMD,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoXREventManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PXR_EventManager.h" },
		{ "ModuleRelativePath", "Private/PXR_EventManager.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_DeviceMainChangedDelegate_MetaData[] = {
		{ "ModuleRelativePath", "Private/PXR_EventManager.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_DeviceMainChangedDelegate = { "DeviceMainChangedDelegate", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPicoXREventManager, DeviceMainChangedDelegate), Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceMainChangedDelegage__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_DeviceMainChangedDelegate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_DeviceMainChangedDelegate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_DeviceConnectChangedDelegate_MetaData[] = {
		{ "ModuleRelativePath", "Private/PXR_EventManager.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_DeviceConnectChangedDelegate = { "DeviceConnectChangedDelegate", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPicoXREventManager, DeviceConnectChangedDelegate), Z_Construct_UDelegateFunction_PicoXRHMD_PXRDeviceConnectChangedDelegage__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_DeviceConnectChangedDelegate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_DeviceConnectChangedDelegate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_IpdChangedDelegate_MetaData[] = {
		{ "ModuleRelativePath", "Private/PXR_EventManager.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_IpdChangedDelegate = { "IpdChangedDelegate", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPicoXREventManager, IpdChangedDelegate), Z_Construct_UDelegateFunction_PicoXRHMD_PXRIpdChanged__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_IpdChangedDelegate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_IpdChangedDelegate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_LongHomePressedDelegate_MetaData[] = {
		{ "ModuleRelativePath", "Private/PXR_EventManager.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_LongHomePressedDelegate = { "LongHomePressedDelegate", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPicoXREventManager, LongHomePressedDelegate), Z_Construct_UDelegateFunction_PicoXRHMD_PXRLongHomeKey__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_LongHomePressedDelegate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_LongHomePressedDelegate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_ResumeDelegate_MetaData[] = {
		{ "ModuleRelativePath", "Private/PXR_EventManager.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_ResumeDelegate = { "ResumeDelegate", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPicoXREventManager, ResumeDelegate), Z_Construct_UDelegateFunction_PicoXRHMD_PXRResume__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_ResumeDelegate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_ResumeDelegate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_RefreshRateChangedDelegate_MetaData[] = {
		{ "ModuleRelativePath", "Private/PXR_EventManager.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_RefreshRateChangedDelegate = { "RefreshRateChangedDelegate", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPicoXREventManager, RefreshRateChangedDelegate), Z_Construct_UDelegateFunction_PicoXRHMD_PXRRefreshRateChanged__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_RefreshRateChangedDelegate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_RefreshRateChangedDelegate_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPicoXREventManager_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_DeviceMainChangedDelegate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_DeviceConnectChangedDelegate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_IpdChangedDelegate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_LongHomePressedDelegate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_ResumeDelegate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPicoXREventManager_Statics::NewProp_RefreshRateChangedDelegate,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPicoXREventManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPicoXREventManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPicoXREventManager_Statics::ClassParams = {
		&UPicoXREventManager::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPicoXREventManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPicoXREventManager_Statics::PropPointers),
		0,
		0x008000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UPicoXREventManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPicoXREventManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPicoXREventManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPicoXREventManager_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPicoXREventManager, 1336747649);
	template<> PICOXRHMD_API UClass* StaticClass<UPicoXREventManager>()
	{
		return UPicoXREventManager::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPicoXREventManager(Z_Construct_UClass_UPicoXREventManager, &UPicoXREventManager::StaticClass, TEXT("/Script/PicoXRHMD"), TEXT("UPicoXREventManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPicoXREventManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
