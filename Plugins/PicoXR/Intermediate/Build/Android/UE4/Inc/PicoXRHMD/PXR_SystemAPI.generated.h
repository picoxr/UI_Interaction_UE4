// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FWifiDisplayModel;
enum class EUSBConfigModeEnum : uint8;
enum class ESystemFunctionSwitchEnum : uint8;
enum class ESwitchEnum : uint8;
enum class ESleepDelayTimeEnum : uint8;
enum class EScreenOffDelayTimeEnum : uint8;
enum class EHomeEventEnum : uint8;
enum class EHomeFunctionEnum : uint8;
enum class EPackageControlEnum : uint8;
enum class EDeviceControlEnum : uint8;
enum class ESystemInfoEnum : uint8;
#ifdef PICOXRHMD_PXR_SystemAPI_generated_h
#error "PXR_SystemAPI.generated.h already included, missing '#pragma once' in PXR_SystemAPI.h"
#endif
#define PICOXRHMD_PXR_SystemAPI_generated_h

#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_167_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FAppManagerStruct_Statics; \
	PICOXRHMD_API static class UScriptStruct* StaticStruct();


template<> PICOXRHMD_API UScriptStruct* StaticStruct<struct FAppManagerStruct>();

#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_125_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FWifiDisplayModel_Statics; \
	PICOXRHMD_API static class UScriptStruct* StaticStruct();


template<> PICOXRHMD_API UScriptStruct* StaticStruct<struct FWifiDisplayModel>();

#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_197_DELEGATE \
struct _Script_PicoXRHMD_eventPicoControlSetAutoConnectWIFIWithErrorCodeDelegate_Parms \
{ \
	int32 Result; \
}; \
static inline void FPicoControlSetAutoConnectWIFIWithErrorCodeDelegate_DelegateWrapper(const FScriptDelegate& PicoControlSetAutoConnectWIFIWithErrorCodeDelegate, int32 Result) \
{ \
	_Script_PicoXRHMD_eventPicoControlSetAutoConnectWIFIWithErrorCodeDelegate_Parms Parms; \
	Parms.Result=Result; \
	PicoControlSetAutoConnectWIFIWithErrorCodeDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_196_DELEGATE \
struct _Script_PicoXRHMD_eventPicoImportMapsDelegate_Parms \
{ \
	bool Result; \
}; \
static inline void FPicoImportMapsDelegate_DelegateWrapper(const FScriptDelegate& PicoImportMapsDelegate, bool Result) \
{ \
	_Script_PicoXRHMD_eventPicoImportMapsDelegate_Parms Parms; \
	Parms.Result=Result ? true : false; \
	PicoImportMapsDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_195_DELEGATE \
struct _Script_PicoXRHMD_eventPicoExportMapsDelegate_Parms \
{ \
	bool Result; \
}; \
static inline void FPicoExportMapsDelegate_DelegateWrapper(const FScriptDelegate& PicoExportMapsDelegate, bool Result) \
{ \
	_Script_PicoXRHMD_eventPicoExportMapsDelegate_Parms Parms; \
	Parms.Result=Result ? true : false; \
	PicoExportMapsDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_194_DELEGATE \
struct _Script_PicoXRHMD_eventPicoSwitchLargeSpaceStatusDelegate_Parms \
{ \
	FString Result; \
}; \
static inline void FPicoSwitchLargeSpaceStatusDelegate_DelegateWrapper(const FScriptDelegate& PicoSwitchLargeSpaceStatusDelegate, const FString& Result) \
{ \
	_Script_PicoXRHMD_eventPicoSwitchLargeSpaceStatusDelegate_Parms Parms; \
	Parms.Result=Result; \
	PicoSwitchLargeSpaceStatusDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_193_DELEGATE \
struct _Script_PicoXRHMD_eventPicoEnableLargeSpaceDelegate_Parms \
{ \
	bool Result; \
}; \
static inline void FPicoEnableLargeSpaceDelegate_DelegateWrapper(const FScriptDelegate& PicoEnableLargeSpaceDelegate, bool Result) \
{ \
	_Script_PicoXRHMD_eventPicoEnableLargeSpaceDelegate_Parms Parms; \
	Parms.Result=Result ? true : false; \
	PicoEnableLargeSpaceDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_192_DELEGATE \
struct _Script_PicoXRHMD_eventPicoSetWDModelsDelegate_Parms \
{ \
	TArray<FWifiDisplayModel> Models; \
}; \
static inline void FPicoSetWDModelsDelegate_DelegateWrapper(const FScriptDelegate& PicoSetWDModelsDelegate, TArray<FWifiDisplayModel> const& Models) \
{ \
	_Script_PicoXRHMD_eventPicoSetWDModelsDelegate_Parms Parms; \
	Parms.Models=Models; \
	PicoSetWDModelsDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_191_DELEGATE \
struct _Script_PicoXRHMD_eventPicoSetWDJsonDelegate_Parms \
{ \
	FString Result; \
}; \
static inline void FPicoSetWDJsonDelegate_DelegateWrapper(const FScriptDelegate& PicoSetWDJsonDelegate, const FString& Result) \
{ \
	_Script_PicoXRHMD_eventPicoSetWDJsonDelegate_Parms Parms; \
	Parms.Result=Result; \
	PicoSetWDJsonDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_190_DELEGATE \
struct _Script_PicoXRHMD_eventPicoResetAllKeyToDefaultDelegate_Parms \
{ \
	bool Result; \
}; \
static inline void FPicoResetAllKeyToDefaultDelegate_DelegateWrapper(const FScriptDelegate& PicoResetAllKeyToDefaultDelegate, bool Result) \
{ \
	_Script_PicoXRHMD_eventPicoResetAllKeyToDefaultDelegate_Parms Parms; \
	Parms.Result=Result ? true : false; \
	PicoResetAllKeyToDefaultDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_189_DELEGATE \
struct _Script_PicoXRHMD_eventPicoWriteConfigFileToDataLocalDelegate_Parms \
{ \
	bool Result; \
}; \
static inline void FPicoWriteConfigFileToDataLocalDelegate_DelegateWrapper(const FScriptDelegate& PicoWriteConfigFileToDataLocalDelegate, bool Result) \
{ \
	_Script_PicoXRHMD_eventPicoWriteConfigFileToDataLocalDelegate_Parms Parms; \
	Parms.Result=Result ? true : false; \
	PicoWriteConfigFileToDataLocalDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_188_DELEGATE \
struct _Script_PicoXRHMD_eventPicoSetScreenOffDelayDelegate_Parms \
{ \
	int32 Result; \
}; \
static inline void FPicoSetScreenOffDelayDelegate_DelegateWrapper(const FScriptDelegate& PicoSetScreenOffDelayDelegate, int32 Result) \
{ \
	_Script_PicoXRHMD_eventPicoSetScreenOffDelayDelegate_Parms Parms; \
	Parms.Result=Result; \
	PicoSetScreenOffDelayDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_187_DELEGATE \
struct _Script_PicoXRHMD_eventPicoDisablePowerKeyDelegate_Parms \
{ \
	int32 Result; \
}; \
static inline void FPicoDisablePowerKeyDelegate_DelegateWrapper(const FScriptDelegate& PicoDisablePowerKeyDelegate, int32 Result) \
{ \
	_Script_PicoXRHMD_eventPicoDisablePowerKeyDelegate_Parms Parms; \
	Parms.Result=Result; \
	PicoDisablePowerKeyDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_186_DELEGATE \
struct _Script_PicoXRHMD_eventPicoSetHomeKeyAllDelegate_Parms \
{ \
	bool Result; \
}; \
static inline void FPicoSetHomeKeyAllDelegate_DelegateWrapper(const FScriptDelegate& PicoSetHomeKeyAllDelegate, bool Result) \
{ \
	_Script_PicoXRHMD_eventPicoSetHomeKeyAllDelegate_Parms Parms; \
	Parms.Result=Result ? true : false; \
	PicoSetHomeKeyAllDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_185_DELEGATE \
struct _Script_PicoXRHMD_eventPicoSetHomeKeyDelegate_Parms \
{ \
	bool Result; \
}; \
static inline void FPicoSetHomeKeyDelegate_DelegateWrapper(const FScriptDelegate& PicoSetHomeKeyDelegate, bool Result) \
{ \
	_Script_PicoXRHMD_eventPicoSetHomeKeyDelegate_Parms Parms; \
	Parms.Result=Result ? true : false; \
	PicoSetHomeKeyDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_184_DELEGATE \
struct _Script_PicoXRHMD_eventPicoClearAutoConnectWifiDelegate_Parms \
{ \
	bool Result; \
}; \
static inline void FPicoClearAutoConnectWifiDelegate_DelegateWrapper(const FScriptDelegate& PicoClearAutoConnectWifiDelegate, bool Result) \
{ \
	_Script_PicoXRHMD_eventPicoClearAutoConnectWifiDelegate_Parms Parms; \
	Parms.Result=Result ? true : false; \
	PicoClearAutoConnectWifiDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_183_DELEGATE \
struct _Script_PicoXRHMD_eventPicoSetAutoConnectWifiDelegate_Parms \
{ \
	bool Result; \
}; \
static inline void FPicoSetAutoConnectWifiDelegate_DelegateWrapper(const FScriptDelegate& PicoSetAutoConnectWifiDelegate, bool Result) \
{ \
	_Script_PicoXRHMD_eventPicoSetAutoConnectWifiDelegate_Parms Parms; \
	Parms.Result=Result ? true : false; \
	PicoSetAutoConnectWifiDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_182_DELEGATE \
struct _Script_PicoXRHMD_eventPicoAppManagerDelegate_Parms \
{ \
	int32 Result; \
}; \
static inline void FPicoAppManagerDelegate_DelegateWrapper(const FScriptDelegate& PicoAppManagerDelegate, int32 Result) \
{ \
	_Script_PicoXRHMD_eventPicoAppManagerDelegate_Parms Parms; \
	Parms.Result=Result; \
	PicoAppManagerDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_181_DELEGATE \
struct _Script_PicoXRHMD_eventPicoSetDeviceActionDelegate_Parms \
{ \
	int32 Result; \
}; \
static inline void FPicoSetDeviceActionDelegate_DelegateWrapper(const FScriptDelegate& PicoSetDeviceActionDelegate, int32 Result) \
{ \
	_Script_PicoXRHMD_eventPicoSetDeviceActionDelegate_Parms Parms; \
	Parms.Result=Result; \
	PicoSetDeviceActionDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_202_SPARSE_DATA
#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_202_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execPXR_AppKeepAlive); \
	DECLARE_FUNCTION(execPXR_ControlSetAutoConnectWIFIWithErrorCode); \
	DECLARE_FUNCTION(execPXR_Record); \
	DECLARE_FUNCTION(execPXR_Capture); \
	DECLARE_FUNCTION(execPXR_GetDeviceTemperatures); \
	DECLARE_FUNCTION(execPXR_GetCpuUsages); \
	DECLARE_FUNCTION(execPXR_ImportMaps); \
	DECLARE_FUNCTION(execPXR_ExportMaps); \
	DECLARE_FUNCTION(execPXR_SaveLargeSpaceMaps); \
	DECLARE_FUNCTION(execPXR_GetSwitchLargeSpaceStatus); \
	DECLARE_FUNCTION(execPXR_SwitchLargeSpaceScene); \
	DECLARE_FUNCTION(execPXR_SetWDModels); \
	DECLARE_FUNCTION(execPXR_SetWDJson); \
	DECLARE_FUNCTION(execPXR_GetConnectedWD); \
	DECLARE_FUNCTION(execPXR_UpdateWifiDisplays); \
	DECLARE_FUNCTION(execPXR_RenameWifiDisplay); \
	DECLARE_FUNCTION(execPXR_ForgetWifiDisplay); \
	DECLARE_FUNCTION(execPXR_DisConnectWifiDisplay); \
	DECLARE_FUNCTION(execPXR_ConnectWifiDisplay); \
	DECLARE_FUNCTION(execPXR_StopScan); \
	DECLARE_FUNCTION(execPXR_StartScan); \
	DECLARE_FUNCTION(execPXR_CloseMiracast); \
	DECLARE_FUNCTION(execPXR_IsMiracastOn); \
	DECLARE_FUNCTION(execPXR_OpenMiracast); \
	DECLARE_FUNCTION(execPXR_KillBackgroundAppsWithWhiteList); \
	DECLARE_FUNCTION(execPXR_KillAppsByPidOrPackageName); \
	DECLARE_FUNCTION(execPXR_FreezeScreen); \
	DECLARE_FUNCTION(execPXR_GetDeviceSN); \
	DECLARE_FUNCTION(execPXR_VolumeDown); \
	DECLARE_FUNCTION(execPXR_VolumeUp); \
	DECLARE_FUNCTION(execPXR_SetVolume); \
	DECLARE_FUNCTION(execPXR_GetMaxVolume); \
	DECLARE_FUNCTION(execPXR_GetCurrentVolume); \
	DECLARE_FUNCTION(execPXR_SetBrightness); \
	DECLARE_FUNCTION(execPXR_GetCurrentBrightness); \
	DECLARE_FUNCTION(execPXR_DisableBackKey); \
	DECLARE_FUNCTION(execPXR_EnableBackKey); \
	DECLARE_FUNCTION(execPXR_DisableVolumeKey); \
	DECLARE_FUNCTION(execPXR_EnableVolumeKey); \
	DECLARE_FUNCTION(execPXR_DisableEnterKey); \
	DECLARE_FUNCTION(execPXR_EnableEnterKey); \
	DECLARE_FUNCTION(execPXR_ResetAllKeyToDefault); \
	DECLARE_FUNCTION(execPXR_WriteConfigFileToDataLocal); \
	DECLARE_FUNCTION(execPXR_ReleaseWakeLock); \
	DECLARE_FUNCTION(execPXR_AcquireWakeLock); \
	DECLARE_FUNCTION(execPXR_ScreenOff); \
	DECLARE_FUNCTION(execPXR_ScreenOn); \
	DECLARE_FUNCTION(execPXR_SetUsbConfigurationOption); \
	DECLARE_FUNCTION(execPXR_SwitchSystemFunction); \
	DECLARE_FUNCTION(execPXR_SetScreenOffDelay); \
	DECLARE_FUNCTION(execPXR_SetSleepDelay); \
	DECLARE_FUNCTION(execPXR_DisablePowerKey); \
	DECLARE_FUNCTION(execPXR_SetHomeKeyAll); \
	DECLARE_FUNCTION(execPXR_SetHomeKey); \
	DECLARE_FUNCTION(execPXR_ClearAutoConnectWifi); \
	DECLARE_FUNCTION(execPXR_SetAutoConnectWifi); \
	DECLARE_FUNCTION(execPXR_AppManager); \
	DECLARE_FUNCTION(execPXR_SetDeviceAction); \
	DECLARE_FUNCTION(execPXR_GetDeviceInfo);


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_202_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPXR_AppKeepAlive); \
	DECLARE_FUNCTION(execPXR_ControlSetAutoConnectWIFIWithErrorCode); \
	DECLARE_FUNCTION(execPXR_Record); \
	DECLARE_FUNCTION(execPXR_Capture); \
	DECLARE_FUNCTION(execPXR_GetDeviceTemperatures); \
	DECLARE_FUNCTION(execPXR_GetCpuUsages); \
	DECLARE_FUNCTION(execPXR_ImportMaps); \
	DECLARE_FUNCTION(execPXR_ExportMaps); \
	DECLARE_FUNCTION(execPXR_SaveLargeSpaceMaps); \
	DECLARE_FUNCTION(execPXR_GetSwitchLargeSpaceStatus); \
	DECLARE_FUNCTION(execPXR_SwitchLargeSpaceScene); \
	DECLARE_FUNCTION(execPXR_SetWDModels); \
	DECLARE_FUNCTION(execPXR_SetWDJson); \
	DECLARE_FUNCTION(execPXR_GetConnectedWD); \
	DECLARE_FUNCTION(execPXR_UpdateWifiDisplays); \
	DECLARE_FUNCTION(execPXR_RenameWifiDisplay); \
	DECLARE_FUNCTION(execPXR_ForgetWifiDisplay); \
	DECLARE_FUNCTION(execPXR_DisConnectWifiDisplay); \
	DECLARE_FUNCTION(execPXR_ConnectWifiDisplay); \
	DECLARE_FUNCTION(execPXR_StopScan); \
	DECLARE_FUNCTION(execPXR_StartScan); \
	DECLARE_FUNCTION(execPXR_CloseMiracast); \
	DECLARE_FUNCTION(execPXR_IsMiracastOn); \
	DECLARE_FUNCTION(execPXR_OpenMiracast); \
	DECLARE_FUNCTION(execPXR_KillBackgroundAppsWithWhiteList); \
	DECLARE_FUNCTION(execPXR_KillAppsByPidOrPackageName); \
	DECLARE_FUNCTION(execPXR_FreezeScreen); \
	DECLARE_FUNCTION(execPXR_GetDeviceSN); \
	DECLARE_FUNCTION(execPXR_VolumeDown); \
	DECLARE_FUNCTION(execPXR_VolumeUp); \
	DECLARE_FUNCTION(execPXR_SetVolume); \
	DECLARE_FUNCTION(execPXR_GetMaxVolume); \
	DECLARE_FUNCTION(execPXR_GetCurrentVolume); \
	DECLARE_FUNCTION(execPXR_SetBrightness); \
	DECLARE_FUNCTION(execPXR_GetCurrentBrightness); \
	DECLARE_FUNCTION(execPXR_DisableBackKey); \
	DECLARE_FUNCTION(execPXR_EnableBackKey); \
	DECLARE_FUNCTION(execPXR_DisableVolumeKey); \
	DECLARE_FUNCTION(execPXR_EnableVolumeKey); \
	DECLARE_FUNCTION(execPXR_DisableEnterKey); \
	DECLARE_FUNCTION(execPXR_EnableEnterKey); \
	DECLARE_FUNCTION(execPXR_ResetAllKeyToDefault); \
	DECLARE_FUNCTION(execPXR_WriteConfigFileToDataLocal); \
	DECLARE_FUNCTION(execPXR_ReleaseWakeLock); \
	DECLARE_FUNCTION(execPXR_AcquireWakeLock); \
	DECLARE_FUNCTION(execPXR_ScreenOff); \
	DECLARE_FUNCTION(execPXR_ScreenOn); \
	DECLARE_FUNCTION(execPXR_SetUsbConfigurationOption); \
	DECLARE_FUNCTION(execPXR_SwitchSystemFunction); \
	DECLARE_FUNCTION(execPXR_SetScreenOffDelay); \
	DECLARE_FUNCTION(execPXR_SetSleepDelay); \
	DECLARE_FUNCTION(execPXR_DisablePowerKey); \
	DECLARE_FUNCTION(execPXR_SetHomeKeyAll); \
	DECLARE_FUNCTION(execPXR_SetHomeKey); \
	DECLARE_FUNCTION(execPXR_ClearAutoConnectWifi); \
	DECLARE_FUNCTION(execPXR_SetAutoConnectWifi); \
	DECLARE_FUNCTION(execPXR_AppManager); \
	DECLARE_FUNCTION(execPXR_SetDeviceAction); \
	DECLARE_FUNCTION(execPXR_GetDeviceInfo);


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_202_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPicoXRSystemAPI(); \
	friend struct Z_Construct_UClass_UPicoXRSystemAPI_Statics; \
public: \
	DECLARE_CLASS(UPicoXRSystemAPI, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PicoXRHMD"), NO_API) \
	DECLARE_SERIALIZER(UPicoXRSystemAPI)


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_202_INCLASS \
private: \
	static void StaticRegisterNativesUPicoXRSystemAPI(); \
	friend struct Z_Construct_UClass_UPicoXRSystemAPI_Statics; \
public: \
	DECLARE_CLASS(UPicoXRSystemAPI, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PicoXRHMD"), NO_API) \
	DECLARE_SERIALIZER(UPicoXRSystemAPI)


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_202_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPicoXRSystemAPI(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPicoXRSystemAPI) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPicoXRSystemAPI); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPicoXRSystemAPI); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPicoXRSystemAPI(UPicoXRSystemAPI&&); \
	NO_API UPicoXRSystemAPI(const UPicoXRSystemAPI&); \
public:


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_202_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPicoXRSystemAPI(UPicoXRSystemAPI&&); \
	NO_API UPicoXRSystemAPI(const UPicoXRSystemAPI&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPicoXRSystemAPI); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPicoXRSystemAPI); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPicoXRSystemAPI)


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_202_PRIVATE_PROPERTY_OFFSET
#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_199_PROLOG
#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_202_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_202_PRIVATE_PROPERTY_OFFSET \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_202_SPARSE_DATA \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_202_RPC_WRAPPERS \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_202_INCLASS \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_202_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_202_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_202_PRIVATE_PROPERTY_OFFSET \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_202_SPARSE_DATA \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_202_RPC_WRAPPERS_NO_PURE_DECLS \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_202_INCLASS_NO_PURE_DECLS \
	UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h_202_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PICOXRHMD_API UClass* StaticClass<class UPicoXRSystemAPI>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID UI_Interaction_UE4_main_Plugins_PicoXR_Source_PicoXRHMD_Private_PXR_SystemAPI_h


#define FOREACH_ENUM_EUSBCONFIGMODEENUM(op) \
	op(EUSBConfigModeEnum::MTP) \
	op(EUSBConfigModeEnum::CHARGE) 

enum class EUSBConfigModeEnum : uint8;
template<> PICOXRHMD_API UEnum* StaticEnum<EUSBConfigModeEnum>();

#define FOREACH_ENUM_ESYSTEMFUNCTIONSWITCHENUM(op) \
	op(ESystemFunctionSwitchEnum::SFS_USB) \
	op(ESystemFunctionSwitchEnum::SFS_AUTOSLEEP) \
	op(ESystemFunctionSwitchEnum::SFS_SCREENON_CHARGING) \
	op(ESystemFunctionSwitchEnum::SFS_OTG_CHARGING) \
	op(ESystemFunctionSwitchEnum::SFS_RETURN_MENU_IN_2DMODE) \
	op(ESystemFunctionSwitchEnum::SFS_COMBINATION_KEY) \
	op(ESystemFunctionSwitchEnum::SFS_CALIBRATION_WITH_POWER_ON) \
	op(ESystemFunctionSwitchEnum::SFS_SYSTEM_UPDATE) \
	op(ESystemFunctionSwitchEnum::SFS_CAST_SERVICE) \
	op(ESystemFunctionSwitchEnum::SFS_EYE_PROTECTION) \
	op(ESystemFunctionSwitchEnum::SFS_SECURITY_ZONE_PERMANENTLY) \
	op(ESystemFunctionSwitchEnum::SFS_GLOBAL_CALIBRATION) \
	op(ESystemFunctionSwitchEnum::SFS_Auto_Calibration) \
	op(ESystemFunctionSwitchEnum::SFS_USB_BOOT) \
	op(ESystemFunctionSwitchEnum::SFS_SHORTCUT_SHOW_RECORD_UI) \
	op(ESystemFunctionSwitchEnum::SFS_SHORTCUT_SHOW_FIT_UI) \
	op(ESystemFunctionSwitchEnum::SFS_SHORTCUT_SHOW_CAST_UI) \
	op(ESystemFunctionSwitchEnum::SFS_SHORTCUT_SHOW_CAPTURE_UI) \
	op(ESystemFunctionSwitchEnum::SFS_STOP_MEM_INFO_SERVICE) \
	op(ESystemFunctionSwitchEnum::SFS_USB_FORCE_HOST) 

enum class ESystemFunctionSwitchEnum : uint8;
template<> PICOXRHMD_API UEnum* StaticEnum<ESystemFunctionSwitchEnum>();

#define FOREACH_ENUM_ESLEEPDELAYTIMEENUM(op) \
	op(ESleepDelayTimeEnum::FIFTEEN) \
	op(ESleepDelayTimeEnum::THIRTY) \
	op(ESleepDelayTimeEnum::SIXTY) \
	op(ESleepDelayTimeEnum::THREE_HUNDRED) \
	op(ESleepDelayTimeEnum::SIX_HUNDRED) \
	op(ESleepDelayTimeEnum::ONE_THOUSAND_AND_EIGHT_HUNDRED) \
	op(ESleepDelayTimeEnum::NEVER) 

enum class ESleepDelayTimeEnum : uint8;
template<> PICOXRHMD_API UEnum* StaticEnum<ESleepDelayTimeEnum>();

#define FOREACH_ENUM_ESCREENOFFDELAYTIMEENUM(op) \
	op(EScreenOffDelayTimeEnum::THREE) \
	op(EScreenOffDelayTimeEnum::TEN) \
	op(EScreenOffDelayTimeEnum::THIRTY) \
	op(EScreenOffDelayTimeEnum::SIXTY) \
	op(EScreenOffDelayTimeEnum::THREE_HUNDRED) \
	op(EScreenOffDelayTimeEnum::SIX_HUNDRED) \
	op(EScreenOffDelayTimeEnum::NEVER) 

enum class EScreenOffDelayTimeEnum : uint8;
template<> PICOXRHMD_API UEnum* StaticEnum<EScreenOffDelayTimeEnum>();

#define FOREACH_ENUM_EHOMEFUNCTIONENUM(op) \
	op(EHomeFunctionEnum::VALUE_HOME_GO_TO_SETTING) \
	op(EHomeFunctionEnum::VALUE_HOME_RECENTER) \
	op(EHomeFunctionEnum::VALUE_HOME_DISABLE) \
	op(EHomeFunctionEnum::VALUE_HOME_GO_TO_HOME) 

enum class EHomeFunctionEnum : uint8;
template<> PICOXRHMD_API UEnum* StaticEnum<EHomeFunctionEnum>();

#define FOREACH_ENUM_EHOMEEVENTENUM(op) \
	op(EHomeEventEnum::HOME_SINGLE_CLICK) \
	op(EHomeEventEnum::HOME_DOUBLE_CLICK) 

enum class EHomeEventEnum : uint8;
template<> PICOXRHMD_API UEnum* StaticEnum<EHomeEventEnum>();

#define FOREACH_ENUM_ESWITCHENUM(op) \
	op(ESwitchEnum::S_ON) \
	op(ESwitchEnum::S_OFF) 

enum class ESwitchEnum : uint8;
template<> PICOXRHMD_API UEnum* StaticEnum<ESwitchEnum>();

#define FOREACH_ENUM_EPACKAGECONTROLENUM(op) \
	op(EPackageControlEnum::PACKAGE_SILENCE_INSTALL) \
	op(EPackageControlEnum::PACKAGE_SILENCE_UNINSTALL) 

enum class EPackageControlEnum : uint8;
template<> PICOXRHMD_API UEnum* StaticEnum<EPackageControlEnum>();

#define FOREACH_ENUM_EDEVICECONTROLENUM(op) \
	op(EDeviceControlEnum::DEVICE_CONTROL_REBOOT) \
	op(EDeviceControlEnum::DEVICE_CONTROL_SHUTDOWN) 

enum class EDeviceControlEnum : uint8;
template<> PICOXRHMD_API UEnum* StaticEnum<EDeviceControlEnum>();

#define FOREACH_ENUM_ESYSTEMINFOENUM(op) \
	op(ESystemInfoEnum::ELECTRIC_QUANTITY) \
	op(ESystemInfoEnum::PUI_VERSION) \
	op(ESystemInfoEnum::EQUIPMENT_MODEL) \
	op(ESystemInfoEnum::EQUIPMENT_SN) \
	op(ESystemInfoEnum::CUSTOMER_SN) \
	op(ESystemInfoEnum::INTERNAL_STORAGE_SPACE_OF_THE_DEVICE) \
	op(ESystemInfoEnum::DEVICE_BLUETOOTH_STATUS) \
	op(ESystemInfoEnum::BLUETOOTH_NAME_CONNECTED) \
	op(ESystemInfoEnum::BLUETOOTH_MAC_ADDRESS) \
	op(ESystemInfoEnum::DEVICE_WIFI_STATUS) \
	op(ESystemInfoEnum::WIFI_NAME_CONNECTED) \
	op(ESystemInfoEnum::WLAN_MAC_ADDRESS) \
	op(ESystemInfoEnum::DEVICE_IP) \
	op(ESystemInfoEnum::CHARGING_STATUS) 

enum class ESystemInfoEnum : uint8;
template<> PICOXRHMD_API UEnum* StaticEnum<ESystemInfoEnum>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
