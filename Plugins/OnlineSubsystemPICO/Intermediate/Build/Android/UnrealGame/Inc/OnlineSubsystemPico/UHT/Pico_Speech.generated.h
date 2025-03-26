// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Pico_Speech.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
enum class EAsrEngineInitResult : uint8;
#ifdef ONLINESUBSYSTEMPICO_Pico_Speech_generated_h
#error "Pico_Speech.generated.h already included, missing '#pragma once' in Pico_Speech.h"
#endif
#define ONLINESUBSYSTEMPICO_Pico_Speech_generated_h

#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_92_SPARSE_DATA
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_92_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_92_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_92_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execStopAsr); \
	DECLARE_FUNCTION(execStartAsr); \
	DECLARE_FUNCTION(execInitAsrEngine);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_92_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_92_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOnlinePicoSpeechFunction(); \
	friend struct Z_Construct_UClass_UOnlinePicoSpeechFunction_Statics; \
public: \
	DECLARE_CLASS(UOnlinePicoSpeechFunction, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UOnlinePicoSpeechFunction)


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_92_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOnlinePicoSpeechFunction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOnlinePicoSpeechFunction(UOnlinePicoSpeechFunction&&); \
	NO_API UOnlinePicoSpeechFunction(const UOnlinePicoSpeechFunction&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOnlinePicoSpeechFunction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOnlinePicoSpeechFunction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOnlinePicoSpeechFunction) \
	NO_API virtual ~UOnlinePicoSpeechFunction();


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_89_PROLOG
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_92_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_92_SPARSE_DATA \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_92_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_92_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_92_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_92_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_92_INCLASS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_92_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<class UOnlinePicoSpeechFunction>();

#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_147_SPARSE_DATA
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_147_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_147_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_147_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetSessionId); \
	DECLARE_FUNCTION(execGetIsFinalResult); \
	DECLARE_FUNCTION(execGetText);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_147_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_147_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPico_AsrResult(); \
	friend struct Z_Construct_UClass_UPico_AsrResult_Statics; \
public: \
	DECLARE_CLASS(UPico_AsrResult, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UPico_AsrResult)


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_147_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPico_AsrResult(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPico_AsrResult(UPico_AsrResult&&); \
	NO_API UPico_AsrResult(const UPico_AsrResult&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPico_AsrResult); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPico_AsrResult); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPico_AsrResult) \
	NO_API virtual ~UPico_AsrResult();


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_144_PROLOG
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_147_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_147_SPARSE_DATA \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_147_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_147_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_147_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_147_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_147_INCLASS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_147_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<class UPico_AsrResult>();

#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_176_SPARSE_DATA
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_176_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_176_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_176_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetCode); \
	DECLARE_FUNCTION(execGetSessionId); \
	DECLARE_FUNCTION(execGetMessage);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_176_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_176_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPico_SpeechError(); \
	friend struct Z_Construct_UClass_UPico_SpeechError_Statics; \
public: \
	DECLARE_CLASS(UPico_SpeechError, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UPico_SpeechError)


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_176_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPico_SpeechError(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPico_SpeechError(UPico_SpeechError&&); \
	NO_API UPico_SpeechError(const UPico_SpeechError&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPico_SpeechError); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPico_SpeechError); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPico_SpeechError) \
	NO_API virtual ~UPico_SpeechError();


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_173_PROLOG
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_176_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_176_SPARSE_DATA \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_176_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_176_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_176_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_176_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_176_INCLASS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h_176_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<class UPico_SpeechError>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Speech_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
