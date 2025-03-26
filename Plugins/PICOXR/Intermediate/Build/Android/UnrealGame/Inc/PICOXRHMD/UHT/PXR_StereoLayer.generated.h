// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PXR_StereoLayer.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ESubtypeEAC : uint8;
#ifdef PICOXRHMD_PXR_StereoLayer_generated_h
#error "PXR_StereoLayer.generated.h already included, missing '#pragma once' in PXR_StereoLayer.h"
#endif
#define PICOXRHMD_PXR_StereoLayer_generated_h

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_StereoLayer_h_212_SPARSE_DATA
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_StereoLayer_h_212_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_StereoLayer_h_212_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_StereoLayer_h_212_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetSubtype); \
	DECLARE_FUNCTION(execSetOverlapFactor);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_StereoLayer_h_212_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_StereoLayer_h_212_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUStereoLayerShapeEAC(); \
	friend struct Z_Construct_UClass_UStereoLayerShapeEAC_Statics; \
public: \
	DECLARE_CLASS(UStereoLayerShapeEAC, UStereoLayerShape, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PICOXRHMD"), NO_API) \
	DECLARE_SERIALIZER(UStereoLayerShapeEAC)


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_StereoLayer_h_212_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UStereoLayerShapeEAC(UStereoLayerShapeEAC&&); \
	NO_API UStereoLayerShapeEAC(const UStereoLayerShapeEAC&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UStereoLayerShapeEAC); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UStereoLayerShapeEAC); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UStereoLayerShapeEAC) \
	NO_API virtual ~UStereoLayerShapeEAC();


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_StereoLayer_h_209_PROLOG
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_StereoLayer_h_212_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_StereoLayer_h_212_SPARSE_DATA \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_StereoLayer_h_212_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_StereoLayer_h_212_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_StereoLayer_h_212_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_StereoLayer_h_212_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_StereoLayer_h_212_INCLASS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_StereoLayer_h_212_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PICOXRHMD_API UClass* StaticClass<class UStereoLayerShapeEAC>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRHMD_Private_PXR_StereoLayer_h


#define FOREACH_ENUM_ESUBTYPEEAC(op) \
	op(ESubtypeEAC::EAC180) \
	op(ESubtypeEAC::EAC360) 

enum class ESubtypeEAC : uint8;
template<> struct TIsUEnumClass<ESubtypeEAC> { enum { Value = true }; };
template<> PICOXRHMD_API UEnum* StaticEnum<ESubtypeEAC>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
