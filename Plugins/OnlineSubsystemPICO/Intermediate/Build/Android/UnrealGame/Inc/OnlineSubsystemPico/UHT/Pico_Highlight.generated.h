// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Pico_Highlight.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class UPico_CaptureInfo;
class UPico_RecordInfo;
class UPico_SessionMedia;
#ifdef ONLINESUBSYSTEMPICO_Pico_Highlight_generated_h
#error "Pico_Highlight.generated.h already included, missing '#pragma once' in Pico_Highlight.h"
#endif
#define ONLINESUBSYSTEMPICO_Pico_Highlight_generated_h

#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_18_DELEGATE \
ONLINESUBSYSTEMPICO_API void FCaptureScreenResult_DelegateWrapper(const FScriptDelegate& CaptureScreenResult, bool bIsError, int32 ErrorCode, const FString& ErrorMessage, UPico_CaptureInfo* CaptureInfo);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_19_DELEGATE \
ONLINESUBSYSTEMPICO_API void FListMediaResult_DelegateWrapper(const FScriptDelegate& ListMediaResult, bool bIsError, int32 ErrorCode, const FString& ErrorMessage, UPico_SessionMedia* SessionMedia);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_20_DELEGATE \
ONLINESUBSYSTEMPICO_API void FSaveMediaResult_DelegateWrapper(const FScriptDelegate& SaveMediaResult, bool bIsError, int32 ErrorCode, const FString& ErrorMessage);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_21_DELEGATE \
ONLINESUBSYSTEMPICO_API void FShareMediaResult_DelegateWrapper(const FScriptDelegate& ShareMediaResult, bool bIsError, int32 ErrorCode, const FString& ErrorMessage);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_22_DELEGATE \
ONLINESUBSYSTEMPICO_API void FStartRecordResult_DelegateWrapper(const FScriptDelegate& StartRecordResult, bool bIsError, int32 ErrorCode, const FString& ErrorMessage);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_23_DELEGATE \
ONLINESUBSYSTEMPICO_API void FStartSessionResult_DelegateWrapper(const FScriptDelegate& StartSessionResult, bool bIsError, int32 ErrorCode, const FString& ErrorMessage, const FString& SessionId);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_24_DELEGATE \
ONLINESUBSYSTEMPICO_API void FStopRecordResult_DelegateWrapper(const FScriptDelegate& StopRecordResult, bool bIsError, int32 ErrorCode, const FString& ErrorMessage, UPico_RecordInfo* RecordInfo);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_156_SPARSE_DATA
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_156_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_156_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_156_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execStartSession); \
	DECLARE_FUNCTION(execStopRecord); \
	DECLARE_FUNCTION(execStartRecord); \
	DECLARE_FUNCTION(execShareMedia); \
	DECLARE_FUNCTION(execSaveMedia); \
	DECLARE_FUNCTION(execListMedia); \
	DECLARE_FUNCTION(execCaptureScreen);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_156_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_156_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOnlinePicoHighlightFunction(); \
	friend struct Z_Construct_UClass_UOnlinePicoHighlightFunction_Statics; \
public: \
	DECLARE_CLASS(UOnlinePicoHighlightFunction, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UOnlinePicoHighlightFunction)


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_156_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOnlinePicoHighlightFunction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOnlinePicoHighlightFunction(UOnlinePicoHighlightFunction&&); \
	NO_API UOnlinePicoHighlightFunction(const UOnlinePicoHighlightFunction&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOnlinePicoHighlightFunction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOnlinePicoHighlightFunction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOnlinePicoHighlightFunction) \
	NO_API virtual ~UOnlinePicoHighlightFunction();


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_153_PROLOG
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_156_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_156_SPARSE_DATA \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_156_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_156_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_156_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_156_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_156_INCLASS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_156_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<class UOnlinePicoHighlightFunction>();

#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_276_SPARSE_DATA
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_276_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_276_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_276_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetJobId); \
	DECLARE_FUNCTION(execGetImagePath);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_276_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_276_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPico_CaptureInfo(); \
	friend struct Z_Construct_UClass_UPico_CaptureInfo_Statics; \
public: \
	DECLARE_CLASS(UPico_CaptureInfo, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UPico_CaptureInfo)


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_276_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPico_CaptureInfo(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPico_CaptureInfo(UPico_CaptureInfo&&); \
	NO_API UPico_CaptureInfo(const UPico_CaptureInfo&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPico_CaptureInfo); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPico_CaptureInfo); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPico_CaptureInfo) \
	NO_API virtual ~UPico_CaptureInfo();


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_272_PROLOG
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_276_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_276_SPARSE_DATA \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_276_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_276_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_276_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_276_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_276_INCLASS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_276_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<class UPico_CaptureInfo>();

#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_297_SPARSE_DATA
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_297_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_297_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_297_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetHeight); \
	DECLARE_FUNCTION(execGetWidth); \
	DECLARE_FUNCTION(execGetDurationInMilliSeconds); \
	DECLARE_FUNCTION(execGetJobId); \
	DECLARE_FUNCTION(execGetVideoPath);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_297_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_297_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPico_RecordInfo(); \
	friend struct Z_Construct_UClass_UPico_RecordInfo_Statics; \
public: \
	DECLARE_CLASS(UPico_RecordInfo, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UPico_RecordInfo)


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_297_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPico_RecordInfo(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPico_RecordInfo(UPico_RecordInfo&&); \
	NO_API UPico_RecordInfo(const UPico_RecordInfo&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPico_RecordInfo); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPico_RecordInfo); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPico_RecordInfo) \
	NO_API virtual ~UPico_RecordInfo();


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_293_PROLOG
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_297_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_297_SPARSE_DATA \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_297_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_297_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_297_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_297_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_297_INCLASS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_297_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<class UPico_RecordInfo>();

#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_333_SPARSE_DATA
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_333_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_333_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_333_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetVideosElement); \
	DECLARE_FUNCTION(execGetVideosSize); \
	DECLARE_FUNCTION(execGetImagesElement); \
	DECLARE_FUNCTION(execGetImagesSize);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_333_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_333_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPico_SessionMedia(); \
	friend struct Z_Construct_UClass_UPico_SessionMedia_Statics; \
public: \
	DECLARE_CLASS(UPico_SessionMedia, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UPico_SessionMedia)


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_333_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPico_SessionMedia(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPico_SessionMedia(UPico_SessionMedia&&); \
	NO_API UPico_SessionMedia(const UPico_SessionMedia&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPico_SessionMedia); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPico_SessionMedia); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPico_SessionMedia) \
	NO_API virtual ~UPico_SessionMedia();


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_329_PROLOG
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_333_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_333_SPARSE_DATA \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_333_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_333_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_333_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_333_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_333_INCLASS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h_333_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<class UPico_SessionMedia>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Highlight_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
