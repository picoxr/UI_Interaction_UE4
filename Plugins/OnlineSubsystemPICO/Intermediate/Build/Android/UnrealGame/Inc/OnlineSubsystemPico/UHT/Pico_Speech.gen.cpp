// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../OnlineSubsystemPico/Public/Pico_Speech.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePico_Speech() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoSpeechFunction();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UOnlinePicoSpeechFunction_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AsrResult();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_AsrResult_NoRegister();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_SpeechError();
	ONLINESUBSYSTEMPICO_API UClass* Z_Construct_UClass_UPico_SpeechError_NoRegister();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_EAsrEngineInitResult();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemPico();
// End Cross Module References
	DEFINE_FUNCTION(UOnlinePicoSpeechFunction::execStopAsr)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		UOnlinePicoSpeechFunction::StopAsr(Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoSpeechFunction::execStartAsr)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_UBOOL(Z_Param_bAutoStop);
		P_GET_PROPERTY(FIntProperty,Z_Param_VadMaxDurationInSeconds);
		P_GET_UBOOL(Z_Param_bShowPunctual);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UOnlinePicoSpeechFunction::StartAsr(Z_Param_WorldContextObject,Z_Param_bAutoStop,Z_Param_VadMaxDurationInSeconds,Z_Param_bShowPunctual);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UOnlinePicoSpeechFunction::execInitAsrEngine)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EAsrEngineInitResult*)Z_Param__Result=UOnlinePicoSpeechFunction::InitAsrEngine(Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	void UOnlinePicoSpeechFunction::StaticRegisterNativesUOnlinePicoSpeechFunction()
	{
		UClass* Class = UOnlinePicoSpeechFunction::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "InitAsrEngine", &UOnlinePicoSpeechFunction::execInitAsrEngine },
			{ "StartAsr", &UOnlinePicoSpeechFunction::execStartAsr },
			{ "StopAsr", &UOnlinePicoSpeechFunction::execStopAsr },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOnlinePicoSpeechFunction_InitAsrEngine_Statics
	{
		struct OnlinePicoSpeechFunction_eventInitAsrEngine_Parms
		{
			UObject* WorldContextObject;
			EAsrEngineInitResult ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoSpeechFunction_InitAsrEngine_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoSpeechFunction_eventInitAsrEngine_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOnlinePicoSpeechFunction_InitAsrEngine_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOnlinePicoSpeechFunction_InitAsrEngine_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoSpeechFunction_eventInitAsrEngine_Parms, ReturnValue), Z_Construct_UEnum_OnlineSubsystemPico_EAsrEngineInitResult, METADATA_PARAMS(0, nullptr) }; // 156352599
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoSpeechFunction_InitAsrEngine_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSpeechFunction_InitAsrEngine_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSpeechFunction_InitAsrEngine_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSpeechFunction_InitAsrEngine_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoSpeechFunction_InitAsrEngine_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Speech" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @defgroup BP_Speech BP_Speech\n  *  This is the BP_Speech group\n  *  @{\n  *//// <summary>\n/// Initialize the ASR engine.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <returns>The initialization result. </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Speech.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@defgroup BP_Speech BP_Speech\nThis is the BP_Speech group\n@{\n /// <summary>\n/// Initialize the ASR engine.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <returns>The initialization result. </returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoSpeechFunction_InitAsrEngine_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoSpeechFunction, nullptr, "InitAsrEngine", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoSpeechFunction_InitAsrEngine_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSpeechFunction_InitAsrEngine_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoSpeechFunction_InitAsrEngine_Statics::OnlinePicoSpeechFunction_eventInitAsrEngine_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04042401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSpeechFunction_InitAsrEngine_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoSpeechFunction_InitAsrEngine_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSpeechFunction_InitAsrEngine_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoSpeechFunction_InitAsrEngine_Statics::OnlinePicoSpeechFunction_eventInitAsrEngine_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoSpeechFunction_InitAsrEngine()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoSpeechFunction_InitAsrEngine_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics
	{
		struct OnlinePicoSpeechFunction_eventStartAsr_Parms
		{
			UObject* WorldContextObject;
			bool bAutoStop;
			int32 VadMaxDurationInSeconds;
			bool bShowPunctual;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static void NewProp_bAutoStop_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoStop;
		static const UECodeGen_Private::FIntPropertyParams NewProp_VadMaxDurationInSeconds;
		static void NewProp_bShowPunctual_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowPunctual;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoSpeechFunction_eventStartAsr_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::NewProp_bAutoStop_SetBit(void* Obj)
	{
		((OnlinePicoSpeechFunction_eventStartAsr_Parms*)Obj)->bAutoStop = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::NewProp_bAutoStop = { "bAutoStop", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoSpeechFunction_eventStartAsr_Parms), &Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::NewProp_bAutoStop_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::NewProp_VadMaxDurationInSeconds = { "VadMaxDurationInSeconds", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoSpeechFunction_eventStartAsr_Parms, VadMaxDurationInSeconds), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::NewProp_bShowPunctual_SetBit(void* Obj)
	{
		((OnlinePicoSpeechFunction_eventStartAsr_Parms*)Obj)->bShowPunctual = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::NewProp_bShowPunctual = { "bShowPunctual", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OnlinePicoSpeechFunction_eventStartAsr_Parms), &Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::NewProp_bShowPunctual_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoSpeechFunction_eventStartAsr_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::NewProp_bAutoStop,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::NewProp_VadMaxDurationInSeconds,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::NewProp_bShowPunctual,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Speech" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Starts automatic speech recognition.\n/// </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <param name=\"bAutoStop\"> Whether to automatically stop ASR when detects an end-of-speech point to improve the effIciency and accuracy of ASR. </param>\n/// <param name=\"VadMaxDurationInSeconds\"> Sets the maximum duration of Voice Activity Detection (VAD) in seconds before automatically stopping recognition if `bAutoStop` is enabled.\n/// VAD is used to identify speech segments in the audio.\n///  </param>\n/// <param name=\"bShowPunctual\"> Whether to show the punctuation marks during the speech recognition process. </param>\n/// <returns>Int:\n/// <ul>\n/// <li>`0`: success </li>\n/// <li> Other values: failure </li>\n/// </ul>\n/// </returns>\n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Speech.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nStarts automatic speech recognition.\n</summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<param name=\"bAutoStop\"> Whether to automatically stop ASR when detects an end-of-speech point to improve the effIciency and accuracy of ASR. </param>\n<param name=\"VadMaxDurationInSeconds\"> Sets the maximum duration of Voice Activity Detection (VAD) in seconds before automatically stopping recognition if `bAutoStop` is enabled.\nVAD is used to identify speech segments in the audio.\n </param>\n<param name=\"bShowPunctual\"> Whether to show the punctuation marks during the speech recognition process. </param>\n<returns>Int:\n<ul>\n<li>`0`: success </li>\n<li> Other values: failure </li>\n</ul>\n</returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoSpeechFunction, nullptr, "StartAsr", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::OnlinePicoSpeechFunction_eventStartAsr_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04042401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::OnlinePicoSpeechFunction_eventStartAsr_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOnlinePicoSpeechFunction_StopAsr_Statics
	{
		struct OnlinePicoSpeechFunction_eventStopAsr_Parms
		{
			UObject* WorldContextObject;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOnlinePicoSpeechFunction_StopAsr_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OnlinePicoSpeechFunction_eventStopAsr_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOnlinePicoSpeechFunction_StopAsr_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOnlinePicoSpeechFunction_StopAsr_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOnlinePicoSpeechFunction_StopAsr_Statics::Function_MetaDataParams[] = {
		{ "Category", "OnlinePico|Speech" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// <summary>\n/// Stops automatic speech recognition.  </summary>\n/// <param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n/// <returns>None </returns>  \n" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Speech.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "<summary>\nStops automatic speech recognition.  </summary>\n<param name =\"WorldContextObject\">Used to get the information about the current world.</param>\n<returns>None </returns>" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOnlinePicoSpeechFunction_StopAsr_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOnlinePicoSpeechFunction, nullptr, "StopAsr", nullptr, nullptr, Z_Construct_UFunction_UOnlinePicoSpeechFunction_StopAsr_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSpeechFunction_StopAsr_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOnlinePicoSpeechFunction_StopAsr_Statics::OnlinePicoSpeechFunction_eventStopAsr_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04042401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSpeechFunction_StopAsr_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOnlinePicoSpeechFunction_StopAsr_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOnlinePicoSpeechFunction_StopAsr_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UOnlinePicoSpeechFunction_StopAsr_Statics::OnlinePicoSpeechFunction_eventStopAsr_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UOnlinePicoSpeechFunction_StopAsr()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOnlinePicoSpeechFunction_StopAsr_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UOnlinePicoSpeechFunction);
	UClass* Z_Construct_UClass_UOnlinePicoSpeechFunction_NoRegister()
	{
		return UOnlinePicoSpeechFunction::StaticClass();
	}
	struct Z_Construct_UClass_UOnlinePicoSpeechFunction_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOnlinePicoSpeechFunction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSpeechFunction_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UOnlinePicoSpeechFunction_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOnlinePicoSpeechFunction_InitAsrEngine, "InitAsrEngine" }, // 3431337245
		{ &Z_Construct_UFunction_UOnlinePicoSpeechFunction_StartAsr, "StartAsr" }, // 3322792616
		{ &Z_Construct_UFunction_UOnlinePicoSpeechFunction_StopAsr, "StopAsr" }, // 2610129406
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSpeechFunction_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOnlinePicoSpeechFunction_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @} *//// @brief OnlinePicoSpeech Blueprint Function class.\n" },
#endif
		{ "IncludePath", "Pico_Speech.h" },
		{ "ModuleRelativePath", "Public/Pico_Speech.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@} /// @brief OnlinePicoSpeech Blueprint Function class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOnlinePicoSpeechFunction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOnlinePicoSpeechFunction>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UOnlinePicoSpeechFunction_Statics::ClassParams = {
		&UOnlinePicoSpeechFunction::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOnlinePicoSpeechFunction_Statics::Class_MetaDataParams), Z_Construct_UClass_UOnlinePicoSpeechFunction_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UOnlinePicoSpeechFunction()
	{
		if (!Z_Registration_Info_UClass_UOnlinePicoSpeechFunction.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOnlinePicoSpeechFunction.OuterSingleton, Z_Construct_UClass_UOnlinePicoSpeechFunction_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UOnlinePicoSpeechFunction.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UOnlinePicoSpeechFunction>()
	{
		return UOnlinePicoSpeechFunction::StaticClass();
	}
	UOnlinePicoSpeechFunction::UOnlinePicoSpeechFunction(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOnlinePicoSpeechFunction);
	UOnlinePicoSpeechFunction::~UOnlinePicoSpeechFunction() {}
	DEFINE_FUNCTION(UPico_AsrResult::execGetSessionId)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetSessionId();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AsrResult::execGetIsFinalResult)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetIsFinalResult();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_AsrResult::execGetText)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetText();
		P_NATIVE_END;
	}
	void UPico_AsrResult::StaticRegisterNativesUPico_AsrResult()
	{
		UClass* Class = UPico_AsrResult::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetIsFinalResult", &UPico_AsrResult::execGetIsFinalResult },
			{ "GetSessionId", &UPico_AsrResult::execGetSessionId },
			{ "GetText", &UPico_AsrResult::execGetText },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_AsrResult_GetIsFinalResult_Statics
	{
		struct Pico_AsrResult_eventGetIsFinalResult_Parms
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
	void Z_Construct_UFunction_UPico_AsrResult_GetIsFinalResult_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Pico_AsrResult_eventGetIsFinalResult_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UPico_AsrResult_GetIsFinalResult_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Pico_AsrResult_eventGetIsFinalResult_Parms), &Z_Construct_UFunction_UPico_AsrResult_GetIsFinalResult_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AsrResult_GetIsFinalResult_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AsrResult_GetIsFinalResult_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AsrResult_GetIsFinalResult_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Speech|AsrResult" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief Check whether the ASR result is a final result or an interim result. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Speech.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Check whether the ASR result is a final result or an interim result." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AsrResult_GetIsFinalResult_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AsrResult, nullptr, "GetIsFinalResult", nullptr, nullptr, Z_Construct_UFunction_UPico_AsrResult_GetIsFinalResult_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AsrResult_GetIsFinalResult_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AsrResult_GetIsFinalResult_Statics::Pico_AsrResult_eventGetIsFinalResult_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AsrResult_GetIsFinalResult_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AsrResult_GetIsFinalResult_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AsrResult_GetIsFinalResult_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AsrResult_GetIsFinalResult_Statics::Pico_AsrResult_eventGetIsFinalResult_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AsrResult_GetIsFinalResult()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AsrResult_GetIsFinalResult_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AsrResult_GetSessionId_Statics
	{
		struct Pico_AsrResult_eventGetSessionId_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AsrResult_GetSessionId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AsrResult_eventGetSessionId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AsrResult_GetSessionId_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AsrResult_GetSessionId_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AsrResult_GetSessionId_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Speech|AsrResult" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief Retrieves the unique session ID associated with the ASR result. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Speech.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Retrieves the unique session ID associated with the ASR result." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AsrResult_GetSessionId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AsrResult, nullptr, "GetSessionId", nullptr, nullptr, Z_Construct_UFunction_UPico_AsrResult_GetSessionId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AsrResult_GetSessionId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AsrResult_GetSessionId_Statics::Pico_AsrResult_eventGetSessionId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AsrResult_GetSessionId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AsrResult_GetSessionId_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AsrResult_GetSessionId_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AsrResult_GetSessionId_Statics::Pico_AsrResult_eventGetSessionId_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AsrResult_GetSessionId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AsrResult_GetSessionId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_AsrResult_GetText_Statics
	{
		struct Pico_AsrResult_eventGetText_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_AsrResult_GetText_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_AsrResult_eventGetText_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_AsrResult_GetText_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_AsrResult_GetText_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_AsrResult_GetText_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Speech|AsrResult" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief Gets the recognized text from the ASR result. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Speech.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Gets the recognized text from the ASR result." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_AsrResult_GetText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_AsrResult, nullptr, "GetText", nullptr, nullptr, Z_Construct_UFunction_UPico_AsrResult_GetText_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AsrResult_GetText_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_AsrResult_GetText_Statics::Pico_AsrResult_eventGetText_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AsrResult_GetText_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_AsrResult_GetText_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_AsrResult_GetText_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_AsrResult_GetText_Statics::Pico_AsrResult_eventGetText_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_AsrResult_GetText()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_AsrResult_GetText_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_AsrResult);
	UClass* Z_Construct_UClass_UPico_AsrResult_NoRegister()
	{
		return UPico_AsrResult::StaticClass();
	}
	struct Z_Construct_UClass_UPico_AsrResult_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_AsrResult_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AsrResult_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_AsrResult_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_AsrResult_GetIsFinalResult, "GetIsFinalResult" }, // 3733466050
		{ &Z_Construct_UFunction_UPico_AsrResult_GetSessionId, "GetSessionId" }, // 3396576102
		{ &Z_Construct_UFunction_UPico_AsrResult_GetText, "GetText" }, // 3016836712
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AsrResult_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_AsrResult_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_AsrResult class.\n" },
#endif
		{ "IncludePath", "Pico_Speech.h" },
		{ "ModuleRelativePath", "Public/Pico_Speech.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_AsrResult class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_AsrResult_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_AsrResult>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_AsrResult_Statics::ClassParams = {
		&UPico_AsrResult::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_AsrResult_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_AsrResult_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPico_AsrResult()
	{
		if (!Z_Registration_Info_UClass_UPico_AsrResult.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_AsrResult.OuterSingleton, Z_Construct_UClass_UPico_AsrResult_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_AsrResult.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_AsrResult>()
	{
		return UPico_AsrResult::StaticClass();
	}
	UPico_AsrResult::UPico_AsrResult(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_AsrResult);
	UPico_AsrResult::~UPico_AsrResult() {}
	DEFINE_FUNCTION(UPico_SpeechError::execGetCode)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetCode();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SpeechError::execGetSessionId)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetSessionId();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPico_SpeechError::execGetMessage)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetMessage();
		P_NATIVE_END;
	}
	void UPico_SpeechError::StaticRegisterNativesUPico_SpeechError()
	{
		UClass* Class = UPico_SpeechError::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetCode", &UPico_SpeechError::execGetCode },
			{ "GetMessage", &UPico_SpeechError::execGetMessage },
			{ "GetSessionId", &UPico_SpeechError::execGetSessionId },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPico_SpeechError_GetCode_Statics
	{
		struct Pico_SpeechError_eventGetCode_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UPico_SpeechError_GetCode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SpeechError_eventGetCode_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SpeechError_GetCode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SpeechError_GetCode_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SpeechError_GetCode_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Speech|SpeechError" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief Retrieves the error code associated with the speech error. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Speech.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Retrieves the error code associated with the speech error." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SpeechError_GetCode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SpeechError, nullptr, "GetCode", nullptr, nullptr, Z_Construct_UFunction_UPico_SpeechError_GetCode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SpeechError_GetCode_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SpeechError_GetCode_Statics::Pico_SpeechError_eventGetCode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SpeechError_GetCode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SpeechError_GetCode_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SpeechError_GetCode_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SpeechError_GetCode_Statics::Pico_SpeechError_eventGetCode_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SpeechError_GetCode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SpeechError_GetCode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SpeechError_GetMessage_Statics
	{
		struct Pico_SpeechError_eventGetMessage_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_SpeechError_GetMessage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SpeechError_eventGetMessage_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SpeechError_GetMessage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SpeechError_GetMessage_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SpeechError_GetMessage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Speech|SpeechError" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief Retrieves the error message associated with the speech error.*/" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Speech.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Retrieves the error message associated with the speech error." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SpeechError_GetMessage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SpeechError, nullptr, "GetMessage", nullptr, nullptr, Z_Construct_UFunction_UPico_SpeechError_GetMessage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SpeechError_GetMessage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SpeechError_GetMessage_Statics::Pico_SpeechError_eventGetMessage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SpeechError_GetMessage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SpeechError_GetMessage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SpeechError_GetMessage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SpeechError_GetMessage_Statics::Pico_SpeechError_eventGetMessage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SpeechError_GetMessage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SpeechError_GetMessage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPico_SpeechError_GetSessionId_Statics
	{
		struct Pico_SpeechError_eventGetSessionId_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPico_SpeechError_GetSessionId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Pico_SpeechError_eventGetSessionId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPico_SpeechError_GetSessionId_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPico_SpeechError_GetSessionId_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPico_SpeechError_GetSessionId_Statics::Function_MetaDataParams[] = {
		{ "Category", "Pico Platform|Speech|SpeechError" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**@brief Retrieves the unique session ID associated with the speech error. */" },
#endif
		{ "ModuleRelativePath", "Public/Pico_Speech.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Retrieves the unique session ID associated with the speech error." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPico_SpeechError_GetSessionId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPico_SpeechError, nullptr, "GetSessionId", nullptr, nullptr, Z_Construct_UFunction_UPico_SpeechError_GetSessionId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SpeechError_GetSessionId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPico_SpeechError_GetSessionId_Statics::Pico_SpeechError_eventGetSessionId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SpeechError_GetSessionId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPico_SpeechError_GetSessionId_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPico_SpeechError_GetSessionId_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPico_SpeechError_GetSessionId_Statics::Pico_SpeechError_eventGetSessionId_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPico_SpeechError_GetSessionId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPico_SpeechError_GetSessionId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPico_SpeechError);
	UClass* Z_Construct_UClass_UPico_SpeechError_NoRegister()
	{
		return UPico_SpeechError::StaticClass();
	}
	struct Z_Construct_UClass_UPico_SpeechError_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPico_SpeechError_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_SpeechError_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPico_SpeechError_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPico_SpeechError_GetCode, "GetCode" }, // 2378672261
		{ &Z_Construct_UFunction_UPico_SpeechError_GetMessage, "GetMessage" }, // 4164598981
		{ &Z_Construct_UFunction_UPico_SpeechError_GetSessionId, "GetSessionId" }, // 555730454
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_SpeechError_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPico_SpeechError_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief UPico_SpeechError class.\n" },
#endif
		{ "IncludePath", "Pico_Speech.h" },
		{ "ModuleRelativePath", "Public/Pico_Speech.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief UPico_SpeechError class." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPico_SpeechError_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPico_SpeechError>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPico_SpeechError_Statics::ClassParams = {
		&UPico_SpeechError::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPico_SpeechError_Statics::Class_MetaDataParams), Z_Construct_UClass_UPico_SpeechError_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPico_SpeechError()
	{
		if (!Z_Registration_Info_UClass_UPico_SpeechError.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPico_SpeechError.OuterSingleton, Z_Construct_UClass_UPico_SpeechError_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPico_SpeechError.OuterSingleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<UPico_SpeechError>()
	{
		return UPico_SpeechError::StaticClass();
	}
	UPico_SpeechError::UPico_SpeechError(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPico_SpeechError);
	UPico_SpeechError::~UPico_SpeechError() {}
	struct Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UOnlinePicoSpeechFunction, UOnlinePicoSpeechFunction::StaticClass, TEXT("UOnlinePicoSpeechFunction"), &Z_Registration_Info_UClass_UOnlinePicoSpeechFunction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOnlinePicoSpeechFunction), 3692396171U) },
		{ Z_Construct_UClass_UPico_AsrResult, UPico_AsrResult::StaticClass, TEXT("UPico_AsrResult"), &Z_Registration_Info_UClass_UPico_AsrResult, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_AsrResult), 3531576111U) },
		{ Z_Construct_UClass_UPico_SpeechError, UPico_SpeechError::StaticClass, TEXT("UPico_SpeechError"), &Z_Registration_Info_UClass_UPico_SpeechError, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPico_SpeechError), 93186009U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_2629748882(TEXT("/Script/OnlineSubsystemPico"),
		Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UI_Interaction_UE4_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
