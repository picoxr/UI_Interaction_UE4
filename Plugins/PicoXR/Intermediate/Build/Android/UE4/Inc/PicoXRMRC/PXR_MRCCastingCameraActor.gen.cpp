// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PicoXRMRC/Private/PXR_MRCCastingCameraActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePXR_MRCCastingCameraActor() {}
// Cross Module References
	PICOXRMRC_API UClass* Z_Construct_UClass_APicoXRMRC_CastingCameraActor_NoRegister();
	PICOXRMRC_API UClass* Z_Construct_UClass_APicoXRMRC_CastingCameraActor();
	ENGINE_API UClass* Z_Construct_UClass_ASceneCapture2D();
	UPackage* Z_Construct_UPackage__Script_PicoXRMRC();
	ENGINE_API UClass* Z_Construct_UClass_ASceneCapture2D_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
	PICOXRMRC_API UClass* Z_Construct_UClass_UPXRInGameThirdCamState_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
// End Cross Module References
	void APicoXRMRC_CastingCameraActor::StaticRegisterNativesAPicoXRMRC_CastingCameraActor()
	{
	}
	UClass* Z_Construct_UClass_APicoXRMRC_CastingCameraActor_NoRegister()
	{
		return APicoXRMRC_CastingCameraActor::StaticClass();
	}
	struct Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ForegroundCaptureActor_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ForegroundCaptureActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BackgroundRenderTarget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BackgroundRenderTarget;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ForegroundRenderTarget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ForegroundRenderTarget;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MRState_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MRState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_M_MRC_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_M_MRC;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MI_Background_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MI_Background;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MI_Foreground_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MI_Foreground;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ASceneCapture2D,
		(UObject* (*)())Z_Construct_UPackage__Script_PicoXRMRC,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Material Attachment Actor Collision Attachment Actor" },
		{ "IncludePath", "PXR_MRCCastingCameraActor.h" },
		{ "IsBlueprintBase", "false" },
		{ "ModuleRelativePath", "Private/PXR_MRCCastingCameraActor.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_ForegroundCaptureActor_MetaData[] = {
		{ "ModuleRelativePath", "Private/PXR_MRCCastingCameraActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_ForegroundCaptureActor = { "ForegroundCaptureActor", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APicoXRMRC_CastingCameraActor, ForegroundCaptureActor), Z_Construct_UClass_ASceneCapture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_ForegroundCaptureActor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_ForegroundCaptureActor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_BackgroundRenderTarget_MetaData[] = {
		{ "ModuleRelativePath", "Private/PXR_MRCCastingCameraActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_BackgroundRenderTarget = { "BackgroundRenderTarget", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APicoXRMRC_CastingCameraActor, BackgroundRenderTarget), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_BackgroundRenderTarget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_BackgroundRenderTarget_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_ForegroundRenderTarget_MetaData[] = {
		{ "ModuleRelativePath", "Private/PXR_MRCCastingCameraActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_ForegroundRenderTarget = { "ForegroundRenderTarget", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APicoXRMRC_CastingCameraActor, ForegroundRenderTarget), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_ForegroundRenderTarget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_ForegroundRenderTarget_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_MRState_MetaData[] = {
		{ "ModuleRelativePath", "Private/PXR_MRCCastingCameraActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_MRState = { "MRState", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APicoXRMRC_CastingCameraActor, MRState), Z_Construct_UClass_UPXRInGameThirdCamState_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_MRState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_MRState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_M_MRC_MetaData[] = {
		{ "ModuleRelativePath", "Private/PXR_MRCCastingCameraActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_M_MRC = { "M_MRC", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APicoXRMRC_CastingCameraActor, M_MRC), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_M_MRC_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_M_MRC_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_MI_Background_MetaData[] = {
		{ "ModuleRelativePath", "Private/PXR_MRCCastingCameraActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_MI_Background = { "MI_Background", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APicoXRMRC_CastingCameraActor, MI_Background), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_MI_Background_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_MI_Background_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_MI_Foreground_MetaData[] = {
		{ "ModuleRelativePath", "Private/PXR_MRCCastingCameraActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_MI_Foreground = { "MI_Foreground", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APicoXRMRC_CastingCameraActor, MI_Foreground), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_MI_Foreground_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_MI_Foreground_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_ForegroundCaptureActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_BackgroundRenderTarget,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_ForegroundRenderTarget,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_MRState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_M_MRC,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_MI_Background,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::NewProp_MI_Foreground,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APicoXRMRC_CastingCameraActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::ClassParams = {
		&APicoXRMRC_CastingCameraActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::PropPointers),
		0,
		0x008002A4u,
		METADATA_PARAMS(Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APicoXRMRC_CastingCameraActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APicoXRMRC_CastingCameraActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APicoXRMRC_CastingCameraActor, 561979447);
	template<> PICOXRMRC_API UClass* StaticClass<APicoXRMRC_CastingCameraActor>()
	{
		return APicoXRMRC_CastingCameraActor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APicoXRMRC_CastingCameraActor(Z_Construct_UClass_APicoXRMRC_CastingCameraActor, &APicoXRMRC_CastingCameraActor::StaticClass, TEXT("/Script/PicoXRMRC"), TEXT("APicoXRMRC_CastingCameraActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APicoXRMRC_CastingCameraActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
