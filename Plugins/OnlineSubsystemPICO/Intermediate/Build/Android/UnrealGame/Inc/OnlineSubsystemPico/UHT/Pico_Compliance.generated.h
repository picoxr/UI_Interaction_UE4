// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Pico_Compliance.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class UPico_DetectSensitiveResult;
enum class EDetectSensitiveScene : uint8;
enum class ESensitiveProposal : uint8;
#ifdef ONLINESUBSYSTEMPICO_Pico_Compliance_generated_h
#error "Pico_Compliance.generated.h already included, missing '#pragma once' in Pico_Compliance.h"
#endif
#define ONLINESUBSYSTEMPICO_Pico_Compliance_generated_h

#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_16_DELEGATE \
ONLINESUBSYSTEMPICO_API void FDetectSensitive_DelegateWrapper(const FScriptDelegate& DetectSensitive, bool bIsError, int32 ErrorCode, const FString& ErrorMessage, UPico_DetectSensitiveResult* DetectSensitiveResult);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_77_SPARSE_DATA
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_77_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_77_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_77_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execDetectSensitive);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_77_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_77_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOnlinePicoComplianceFunction(); \
	friend struct Z_Construct_UClass_UOnlinePicoComplianceFunction_Statics; \
public: \
	DECLARE_CLASS(UOnlinePicoComplianceFunction, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UOnlinePicoComplianceFunction)


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_77_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOnlinePicoComplianceFunction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOnlinePicoComplianceFunction(UOnlinePicoComplianceFunction&&); \
	NO_API UOnlinePicoComplianceFunction(const UOnlinePicoComplianceFunction&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOnlinePicoComplianceFunction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOnlinePicoComplianceFunction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOnlinePicoComplianceFunction) \
	NO_API virtual ~UOnlinePicoComplianceFunction();


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_74_PROLOG
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_77_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_77_SPARSE_DATA \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_77_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_77_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_77_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_77_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_77_INCLASS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_77_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<class UOnlinePicoComplianceFunction>();

#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_107_SPARSE_DATA
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_107_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_107_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_107_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetFilteredText); \
	DECLARE_FUNCTION(execGetSensitiveProposal);


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_107_ACCESSORS
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_107_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPico_DetectSensitiveResult(); \
	friend struct Z_Construct_UClass_UPico_DetectSensitiveResult_Statics; \
public: \
	DECLARE_CLASS(UPico_DetectSensitiveResult, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/OnlineSubsystemPico"), NO_API) \
	DECLARE_SERIALIZER(UPico_DetectSensitiveResult)


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_107_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPico_DetectSensitiveResult(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPico_DetectSensitiveResult(UPico_DetectSensitiveResult&&); \
	NO_API UPico_DetectSensitiveResult(const UPico_DetectSensitiveResult&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPico_DetectSensitiveResult); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPico_DetectSensitiveResult); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPico_DetectSensitiveResult) \
	NO_API virtual ~UPico_DetectSensitiveResult();


#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_103_PROLOG
#define FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_107_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_107_SPARSE_DATA \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_107_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_107_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_107_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_107_ACCESSORS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_107_INCLASS_NO_PURE_DECLS \
	FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h_107_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINESUBSYSTEMPICO_API UClass* StaticClass<class UPico_DetectSensitiveResult>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_New_0311_Plugins_OnlineSubsystemPICO_Source_OnlineSubsystemPico_Public_Pico_Compliance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
