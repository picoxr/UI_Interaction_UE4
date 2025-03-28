// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PXR_MRAsyncActions.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPICOAnchorComponent;
class UPICOCreateSpatialAnchor_AsyncAction;
class UPICOLaunchSceneCaptureApp_AsyncAction;
class UPICOLaunchSceneCaptureService_AsyncAction;
class UPICOLaunchSpatialAnchorService_AsyncAction;
class UPICOLaunchSpatialMeshScanning_AsyncAction;
class UPICOPersistSpatialAnchor_AsyncAction;
class UPICORequestSceneCaptures_AsyncAction;
class UPICORequestSpatialAnchors_AsyncAction;
class UPICORequestSpatialMesh_AsyncAction;
class UPICOUnpersistSpatialAnchor_AsyncAction;
enum class EPICOPersistLocation : uint8;
enum class EPICOResult : uint8;
enum class EPICOSpatialSceneCaptureStatus : uint8;
struct FAnchorLoadResult;
struct FPICOAnchorLoadInfo;
struct FPICOMRSceneInfo;
struct FPICOSceneLoadInfo;
struct FPICOSpatialMeshInfo;
#ifdef PICOXRMR_PXR_MRAsyncActions_generated_h
#error "PXR_MRAsyncActions.generated.h already included, missing '#pragma once' in PXR_MRAsyncActions.h"
#endif
#define PICOXRMR_PXR_MRAsyncActions_generated_h

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_14_DELEGATE \
PICOXRMR_API void FPICOCreateSpatialAnchorActionSuccess_DelegateWrapper(const FMulticastScriptDelegate& PICOCreateSpatialAnchorActionSuccess, EPICOResult Result, const UPICOAnchorComponent* AnchorComponent);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_15_DELEGATE \
PICOXRMR_API void FPICOCreateSpatialAnchorActionFailure_DelegateWrapper(const FMulticastScriptDelegate& PICOCreateSpatialAnchorActionFailure, EPICOResult Result);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_17_DELEGATE \
PICOXRMR_API void FPICOPersistSpatialAnchorActionSuccess_DelegateWrapper(const FMulticastScriptDelegate& PICOPersistSpatialAnchorActionSuccess, EPICOResult Result, const UPICOAnchorComponent* AnchorComponent);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_18_DELEGATE \
PICOXRMR_API void FPICOPersistSpatialAnchorActionFailure_DelegateWrapper(const FMulticastScriptDelegate& PICOPersistSpatialAnchorActionFailure, EPICOResult Result);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_20_DELEGATE \
PICOXRMR_API void FPICOUnpersistSpatialAnchorActionSuccess_DelegateWrapper(const FMulticastScriptDelegate& PICOUnpersistSpatialAnchorActionSuccess, EPICOResult Result, const UPICOAnchorComponent* AnchorComponent);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_21_DELEGATE \
PICOXRMR_API void FPICOUnpersistSpatialAnchorActionFailure_DelegateWrapper(const FMulticastScriptDelegate& PICOUnpersistSpatialAnchorActionFailure, EPICOResult Result);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_23_DELEGATE \
PICOXRMR_API void FPICOLoadSpatialAnchorActionSuccess_DelegateWrapper(const FMulticastScriptDelegate& PICOLoadSpatialAnchorActionSuccess, EPICOResult Result, TArray<FAnchorLoadResult> const& AnchorLoadResults);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_24_DELEGATE \
PICOXRMR_API void FPICOLoadSpatialAnchorActionFailure_DelegateWrapper(const FMulticastScriptDelegate& PICOLoadSpatialAnchorActionFailure, EPICOResult Result);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_26_DELEGATE \
PICOXRMR_API void FPICOStartSpatialSceneCaptureActionSuccess_DelegateWrapper(const FMulticastScriptDelegate& PICOStartSpatialSceneCaptureActionSuccess, EPICOResult Result, EPICOSpatialSceneCaptureStatus SpatialSceneCaptureStatus);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_27_DELEGATE \
PICOXRMR_API void FPICOStartSpatialSceneCaptureActionFailure_DelegateWrapper(const FMulticastScriptDelegate& PICOStartSpatialSceneCaptureActionFailure, EPICOResult Result);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_29_DELEGATE \
PICOXRMR_API void FPICOStartProviderActionSuccess_DelegateWrapper(const FMulticastScriptDelegate& PICOStartProviderActionSuccess, EPICOResult Result);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_30_DELEGATE \
PICOXRMR_API void FPICOStartProviderActionFailure_DelegateWrapper(const FMulticastScriptDelegate& PICOStartProviderActionFailure, EPICOResult Result);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_32_DELEGATE \
PICOXRMR_API void FPICOLaunchSceneCaptureAppActionSuccess_DelegateWrapper(const FMulticastScriptDelegate& PICOLaunchSceneCaptureAppActionSuccess, EPICOResult Result);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_33_DELEGATE \
PICOXRMR_API void FPICOLaunchSceneCaptureAppActionFailure_DelegateWrapper(const FMulticastScriptDelegate& PICOLaunchSceneCaptureAppActionFailure, EPICOResult Result);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_35_DELEGATE \
PICOXRMR_API void FPICORequestSpatialMeshActionSuccess_DelegateWrapper(const FMulticastScriptDelegate& PICORequestSpatialMeshActionSuccess, EPICOResult Result, TArray<FPICOSpatialMeshInfo> const& MeshInfos);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_36_DELEGATE \
PICOXRMR_API void FPICORequestSpatialMeshActionFailure_DelegateWrapper(const FMulticastScriptDelegate& PICORequestSpatialMeshActionFailure, EPICOResult Result);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_38_DELEGATE \
PICOXRMR_API void FPICORequestSceneCapturesActionSuccess_DelegateWrapper(const FMulticastScriptDelegate& PICORequestSceneCapturesActionSuccess, EPICOResult Result, TArray<FPICOMRSceneInfo> const& SceneInfos);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_39_DELEGATE \
PICOXRMR_API void FPICORequestSceneCapturesActionFailure_DelegateWrapper(const FMulticastScriptDelegate& PICORequestSceneCapturesActionFailure, EPICOResult Result);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_50_SPARSE_DATA
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_50_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_50_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_50_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPXR_LaunchSpatialAnchorService_Async);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_50_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_50_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPICOLaunchSpatialAnchorService_AsyncAction(); \
	friend struct Z_Construct_UClass_UPICOLaunchSpatialAnchorService_AsyncAction_Statics; \
public: \
	DECLARE_CLASS(UPICOLaunchSpatialAnchorService_AsyncAction, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PICOXRMR"), NO_API) \
	DECLARE_SERIALIZER(UPICOLaunchSpatialAnchorService_AsyncAction)


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_50_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPICOLaunchSpatialAnchorService_AsyncAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPICOLaunchSpatialAnchorService_AsyncAction(UPICOLaunchSpatialAnchorService_AsyncAction&&); \
	NO_API UPICOLaunchSpatialAnchorService_AsyncAction(const UPICOLaunchSpatialAnchorService_AsyncAction&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPICOLaunchSpatialAnchorService_AsyncAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPICOLaunchSpatialAnchorService_AsyncAction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPICOLaunchSpatialAnchorService_AsyncAction) \
	NO_API virtual ~UPICOLaunchSpatialAnchorService_AsyncAction();


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_47_PROLOG
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_50_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_50_SPARSE_DATA \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_50_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_50_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_50_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_50_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_50_INCLASS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_50_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PICOXRMR_API UClass* StaticClass<class UPICOLaunchSpatialAnchorService_AsyncAction>();

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_79_SPARSE_DATA
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_79_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_79_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_79_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPXR_CreateSpatialAnchor_Async);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_79_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_79_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPICOCreateSpatialAnchor_AsyncAction(); \
	friend struct Z_Construct_UClass_UPICOCreateSpatialAnchor_AsyncAction_Statics; \
public: \
	DECLARE_CLASS(UPICOCreateSpatialAnchor_AsyncAction, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PICOXRMR"), NO_API) \
	DECLARE_SERIALIZER(UPICOCreateSpatialAnchor_AsyncAction)


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_79_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPICOCreateSpatialAnchor_AsyncAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPICOCreateSpatialAnchor_AsyncAction(UPICOCreateSpatialAnchor_AsyncAction&&); \
	NO_API UPICOCreateSpatialAnchor_AsyncAction(const UPICOCreateSpatialAnchor_AsyncAction&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPICOCreateSpatialAnchor_AsyncAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPICOCreateSpatialAnchor_AsyncAction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPICOCreateSpatialAnchor_AsyncAction) \
	NO_API virtual ~UPICOCreateSpatialAnchor_AsyncAction();


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_76_PROLOG
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_79_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_79_SPARSE_DATA \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_79_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_79_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_79_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_79_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_79_INCLASS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_79_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PICOXRMR_API UClass* StaticClass<class UPICOCreateSpatialAnchor_AsyncAction>();

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_117_SPARSE_DATA
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_117_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_117_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_117_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPXR_PersistSpatialAnchor_Async);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_117_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_117_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPICOPersistSpatialAnchor_AsyncAction(); \
	friend struct Z_Construct_UClass_UPICOPersistSpatialAnchor_AsyncAction_Statics; \
public: \
	DECLARE_CLASS(UPICOPersistSpatialAnchor_AsyncAction, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PICOXRMR"), NO_API) \
	DECLARE_SERIALIZER(UPICOPersistSpatialAnchor_AsyncAction)


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_117_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPICOPersistSpatialAnchor_AsyncAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPICOPersistSpatialAnchor_AsyncAction(UPICOPersistSpatialAnchor_AsyncAction&&); \
	NO_API UPICOPersistSpatialAnchor_AsyncAction(const UPICOPersistSpatialAnchor_AsyncAction&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPICOPersistSpatialAnchor_AsyncAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPICOPersistSpatialAnchor_AsyncAction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPICOPersistSpatialAnchor_AsyncAction) \
	NO_API virtual ~UPICOPersistSpatialAnchor_AsyncAction();


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_114_PROLOG
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_117_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_117_SPARSE_DATA \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_117_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_117_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_117_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_117_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_117_INCLASS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_117_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PICOXRMR_API UClass* StaticClass<class UPICOPersistSpatialAnchor_AsyncAction>();

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_159_SPARSE_DATA
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_159_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_159_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_159_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPXR_UnpersistSpatialAnchor_Async);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_159_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_159_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPICOUnpersistSpatialAnchor_AsyncAction(); \
	friend struct Z_Construct_UClass_UPICOUnpersistSpatialAnchor_AsyncAction_Statics; \
public: \
	DECLARE_CLASS(UPICOUnpersistSpatialAnchor_AsyncAction, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PICOXRMR"), NO_API) \
	DECLARE_SERIALIZER(UPICOUnpersistSpatialAnchor_AsyncAction)


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_159_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPICOUnpersistSpatialAnchor_AsyncAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPICOUnpersistSpatialAnchor_AsyncAction(UPICOUnpersistSpatialAnchor_AsyncAction&&); \
	NO_API UPICOUnpersistSpatialAnchor_AsyncAction(const UPICOUnpersistSpatialAnchor_AsyncAction&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPICOUnpersistSpatialAnchor_AsyncAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPICOUnpersistSpatialAnchor_AsyncAction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPICOUnpersistSpatialAnchor_AsyncAction) \
	NO_API virtual ~UPICOUnpersistSpatialAnchor_AsyncAction();


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_156_PROLOG
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_159_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_159_SPARSE_DATA \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_159_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_159_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_159_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_159_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_159_INCLASS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_159_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PICOXRMR_API UClass* StaticClass<class UPICOUnpersistSpatialAnchor_AsyncAction>();

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_200_SPARSE_DATA
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_200_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_200_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_200_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPXR_LoadSpatialAnchor_Async);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_200_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_200_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPICORequestSpatialAnchors_AsyncAction(); \
	friend struct Z_Construct_UClass_UPICORequestSpatialAnchors_AsyncAction_Statics; \
public: \
	DECLARE_CLASS(UPICORequestSpatialAnchors_AsyncAction, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PICOXRMR"), NO_API) \
	DECLARE_SERIALIZER(UPICORequestSpatialAnchors_AsyncAction)


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_200_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPICORequestSpatialAnchors_AsyncAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPICORequestSpatialAnchors_AsyncAction(UPICORequestSpatialAnchors_AsyncAction&&); \
	NO_API UPICORequestSpatialAnchors_AsyncAction(const UPICORequestSpatialAnchors_AsyncAction&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPICORequestSpatialAnchors_AsyncAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPICORequestSpatialAnchors_AsyncAction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPICORequestSpatialAnchors_AsyncAction) \
	NO_API virtual ~UPICORequestSpatialAnchors_AsyncAction();


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_197_PROLOG
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_200_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_200_SPARSE_DATA \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_200_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_200_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_200_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_200_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_200_INCLASS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_200_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PICOXRMR_API UClass* StaticClass<class UPICORequestSpatialAnchors_AsyncAction>();

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_246_SPARSE_DATA
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_246_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_246_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_246_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPXR_LaunchSpatialMeshScanning_Async);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_246_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_246_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPICOLaunchSpatialMeshScanning_AsyncAction(); \
	friend struct Z_Construct_UClass_UPICOLaunchSpatialMeshScanning_AsyncAction_Statics; \
public: \
	DECLARE_CLASS(UPICOLaunchSpatialMeshScanning_AsyncAction, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PICOXRMR"), NO_API) \
	DECLARE_SERIALIZER(UPICOLaunchSpatialMeshScanning_AsyncAction)


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_246_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPICOLaunchSpatialMeshScanning_AsyncAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPICOLaunchSpatialMeshScanning_AsyncAction(UPICOLaunchSpatialMeshScanning_AsyncAction&&); \
	NO_API UPICOLaunchSpatialMeshScanning_AsyncAction(const UPICOLaunchSpatialMeshScanning_AsyncAction&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPICOLaunchSpatialMeshScanning_AsyncAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPICOLaunchSpatialMeshScanning_AsyncAction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPICOLaunchSpatialMeshScanning_AsyncAction) \
	NO_API virtual ~UPICOLaunchSpatialMeshScanning_AsyncAction();


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_243_PROLOG
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_246_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_246_SPARSE_DATA \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_246_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_246_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_246_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_246_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_246_INCLASS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_246_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PICOXRMR_API UClass* StaticClass<class UPICOLaunchSpatialMeshScanning_AsyncAction>();

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_274_SPARSE_DATA
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_274_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_274_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_274_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPXR_RequestSpatialMeshInfos_Async);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_274_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_274_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPICORequestSpatialMesh_AsyncAction(); \
	friend struct Z_Construct_UClass_UPICORequestSpatialMesh_AsyncAction_Statics; \
public: \
	DECLARE_CLASS(UPICORequestSpatialMesh_AsyncAction, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PICOXRMR"), NO_API) \
	DECLARE_SERIALIZER(UPICORequestSpatialMesh_AsyncAction)


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_274_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPICORequestSpatialMesh_AsyncAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPICORequestSpatialMesh_AsyncAction(UPICORequestSpatialMesh_AsyncAction&&); \
	NO_API UPICORequestSpatialMesh_AsyncAction(const UPICORequestSpatialMesh_AsyncAction&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPICORequestSpatialMesh_AsyncAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPICORequestSpatialMesh_AsyncAction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPICORequestSpatialMesh_AsyncAction) \
	NO_API virtual ~UPICORequestSpatialMesh_AsyncAction();


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_271_PROLOG
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_274_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_274_SPARSE_DATA \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_274_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_274_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_274_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_274_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_274_INCLASS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_274_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PICOXRMR_API UClass* StaticClass<class UPICORequestSpatialMesh_AsyncAction>();

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_305_SPARSE_DATA
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_305_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_305_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_305_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPXR_LaunchSceneCaptureService_Async);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_305_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_305_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPICOLaunchSceneCaptureService_AsyncAction(); \
	friend struct Z_Construct_UClass_UPICOLaunchSceneCaptureService_AsyncAction_Statics; \
public: \
	DECLARE_CLASS(UPICOLaunchSceneCaptureService_AsyncAction, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PICOXRMR"), NO_API) \
	DECLARE_SERIALIZER(UPICOLaunchSceneCaptureService_AsyncAction)


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_305_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPICOLaunchSceneCaptureService_AsyncAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPICOLaunchSceneCaptureService_AsyncAction(UPICOLaunchSceneCaptureService_AsyncAction&&); \
	NO_API UPICOLaunchSceneCaptureService_AsyncAction(const UPICOLaunchSceneCaptureService_AsyncAction&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPICOLaunchSceneCaptureService_AsyncAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPICOLaunchSceneCaptureService_AsyncAction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPICOLaunchSceneCaptureService_AsyncAction) \
	NO_API virtual ~UPICOLaunchSceneCaptureService_AsyncAction();


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_302_PROLOG
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_305_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_305_SPARSE_DATA \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_305_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_305_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_305_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_305_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_305_INCLASS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_305_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PICOXRMR_API UClass* StaticClass<class UPICOLaunchSceneCaptureService_AsyncAction>();

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_333_SPARSE_DATA
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_333_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_333_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_333_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPXR_LaunchSceneCaptureApp_Async);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_333_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_333_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPICOLaunchSceneCaptureApp_AsyncAction(); \
	friend struct Z_Construct_UClass_UPICOLaunchSceneCaptureApp_AsyncAction_Statics; \
public: \
	DECLARE_CLASS(UPICOLaunchSceneCaptureApp_AsyncAction, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PICOXRMR"), NO_API) \
	DECLARE_SERIALIZER(UPICOLaunchSceneCaptureApp_AsyncAction)


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_333_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPICOLaunchSceneCaptureApp_AsyncAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPICOLaunchSceneCaptureApp_AsyncAction(UPICOLaunchSceneCaptureApp_AsyncAction&&); \
	NO_API UPICOLaunchSceneCaptureApp_AsyncAction(const UPICOLaunchSceneCaptureApp_AsyncAction&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPICOLaunchSceneCaptureApp_AsyncAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPICOLaunchSceneCaptureApp_AsyncAction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPICOLaunchSceneCaptureApp_AsyncAction) \
	NO_API virtual ~UPICOLaunchSceneCaptureApp_AsyncAction();


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_330_PROLOG
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_333_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_333_SPARSE_DATA \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_333_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_333_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_333_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_333_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_333_INCLASS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_333_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PICOXRMR_API UClass* StaticClass<class UPICOLaunchSceneCaptureApp_AsyncAction>();

#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_363_SPARSE_DATA
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_363_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_363_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_363_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPXR_RequestSceneCaptures_Async);


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_363_ACCESSORS
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_363_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPICORequestSceneCaptures_AsyncAction(); \
	friend struct Z_Construct_UClass_UPICORequestSceneCaptures_AsyncAction_Statics; \
public: \
	DECLARE_CLASS(UPICORequestSceneCaptures_AsyncAction, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PICOXRMR"), NO_API) \
	DECLARE_SERIALIZER(UPICORequestSceneCaptures_AsyncAction)


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_363_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPICORequestSceneCaptures_AsyncAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPICORequestSceneCaptures_AsyncAction(UPICORequestSceneCaptures_AsyncAction&&); \
	NO_API UPICORequestSceneCaptures_AsyncAction(const UPICORequestSceneCaptures_AsyncAction&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPICORequestSceneCaptures_AsyncAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPICORequestSceneCaptures_AsyncAction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPICORequestSceneCaptures_AsyncAction) \
	NO_API virtual ~UPICORequestSceneCaptures_AsyncAction();


#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_360_PROLOG
#define FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_363_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_363_SPARSE_DATA \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_363_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_363_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_363_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_363_ACCESSORS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_363_INCLASS_NO_PURE_DECLS \
	FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h_363_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PICOXRMR_API UClass* StaticClass<class UPICORequestSceneCaptures_AsyncAction>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UI_Interaction_UE4_Plugins_PICOXR_Source_PICOXRMR_Public_PXR_MRAsyncActions_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
