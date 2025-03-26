// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PXR_SpatialMeshActor.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EPICOResult : uint8;
enum class EPICOSemanticLabel : uint8; struct FLinearColor;
struct FPICOSpatialMeshInfo;
#ifdef PICOXRMR_PXR_SpatialMeshActor_generated_h
#error "PXR_SpatialMeshActor.generated.h already included, missing '#pragma once' in PXR_SpatialMeshActor.h"
#endif
#define PICOXRMR_PXR_SpatialMeshActor_generated_h

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshActor_h_16_SPARSE_DATA
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshActor_h_16_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshActor_h_16_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshActor_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execHandleMeshDataUpdatedEvent); \
	DECLARE_FUNCTION(execHandleRequestSpatialMeshContentsEvent); \
	DECLARE_FUNCTION(execClearMesh); \
	DECLARE_FUNCTION(execSetMeshVisibility); \
	DECLARE_FUNCTION(execPauseDraw); \
	DECLARE_FUNCTION(execStartDraw); \
	DECLARE_FUNCTION(execSetSemanticToColors);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshActor_h_16_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshActor_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPXRSpatialMeshActor(); \
	friend struct Z_Construct_UClass_APXRSpatialMeshActor_Statics; \
public: \
	DECLARE_CLASS(APXRSpatialMeshActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PICOXRMR"), NO_API) \
	DECLARE_SERIALIZER(APXRSpatialMeshActor)


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshActor_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APXRSpatialMeshActor(APXRSpatialMeshActor&&); \
	NO_API APXRSpatialMeshActor(const APXRSpatialMeshActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APXRSpatialMeshActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APXRSpatialMeshActor); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APXRSpatialMeshActor) \
	NO_API virtual ~APXRSpatialMeshActor();


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshActor_h_13_PROLOG
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshActor_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshActor_h_16_SPARSE_DATA \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshActor_h_16_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshActor_h_16_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshActor_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshActor_h_16_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshActor_h_16_INCLASS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshActor_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PICOXRMR_API UClass* StaticClass<class APXRSpatialMeshActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_SpatialMeshActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
