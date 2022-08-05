// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OnlineSubsystemPico/Public/RTCPicoUserInterface.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTCPicoUserInterface() {}
// Cross Module References
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceError();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemPico();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceState();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceType();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcUserLeaveReasonType();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcJoinRoomType();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcEarMonitorMode();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamIndex();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioScenarioType();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioPlaybackDevice();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcPauseResumeMediaType();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcMuteState();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcRoomProfileType();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcEngineInitResult();
	ONLINESUBSYSTEMPICO_API UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcPrivilege();
// End Cross Module References
	static UEnum* ERtcMediaDeviceError_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceError, Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcMediaDeviceError"));
		}
		return Singleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcMediaDeviceError>()
	{
		return ERtcMediaDeviceError_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ERtcMediaDeviceError(ERtcMediaDeviceError_StaticEnum, TEXT("/Script/OnlineSubsystemPico"), TEXT("ERtcMediaDeviceError"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceError_Hash() { return 825798467U; }
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceError()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_OnlineSubsystemPico();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ERtcMediaDeviceError"), 0, Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceError_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ERtcMediaDeviceError::None", (int64)ERtcMediaDeviceError::None },
				{ "ERtcMediaDeviceError::Ok", (int64)ERtcMediaDeviceError::Ok },
				{ "ERtcMediaDeviceError::NoPermission", (int64)ERtcMediaDeviceError::NoPermission },
				{ "ERtcMediaDeviceError::DeviceBusy", (int64)ERtcMediaDeviceError::DeviceBusy },
				{ "ERtcMediaDeviceError::DeviceFailure", (int64)ERtcMediaDeviceError::DeviceFailure },
				{ "ERtcMediaDeviceError::DeviceNotFound", (int64)ERtcMediaDeviceError::DeviceNotFound },
				{ "ERtcMediaDeviceError::DeviceDisconnected", (int64)ERtcMediaDeviceError::DeviceDisconnected },
				{ "ERtcMediaDeviceError::DeviceNoCallback", (int64)ERtcMediaDeviceError::DeviceNoCallback },
				{ "ERtcMediaDeviceError::UnSupporttedFormat", (int64)ERtcMediaDeviceError::UnSupporttedFormat },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "/// @brief Rtc media device error type.\n" },
				{ "DeviceBusy.Name", "ERtcMediaDeviceError::DeviceBusy" },
				{ "DeviceDisconnected.Name", "ERtcMediaDeviceError::DeviceDisconnected" },
				{ "DeviceFailure.Name", "ERtcMediaDeviceError::DeviceFailure" },
				{ "DeviceNoCallback.Name", "ERtcMediaDeviceError::DeviceNoCallback" },
				{ "DeviceNotFound.Name", "ERtcMediaDeviceError::DeviceNotFound" },
				{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
				{ "None.Name", "ERtcMediaDeviceError::None" },
				{ "NoPermission.Name", "ERtcMediaDeviceError::NoPermission" },
				{ "Ok.Name", "ERtcMediaDeviceError::Ok" },
				{ "ToolTip", "@brief Rtc media device error type." },
				{ "UnSupporttedFormat.Name", "ERtcMediaDeviceError::UnSupporttedFormat" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
				nullptr,
				"ERtcMediaDeviceError",
				"ERtcMediaDeviceError",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* ERtcMediaDeviceState_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceState, Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcMediaDeviceState"));
		}
		return Singleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcMediaDeviceState>()
	{
		return ERtcMediaDeviceState_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ERtcMediaDeviceState(ERtcMediaDeviceState_StaticEnum, TEXT("/Script/OnlineSubsystemPico"), TEXT("ERtcMediaDeviceState"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceState_Hash() { return 1518503382U; }
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceState()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_OnlineSubsystemPico();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ERtcMediaDeviceState"), 0, Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceState_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ERtcMediaDeviceState::None", (int64)ERtcMediaDeviceState::None },
				{ "ERtcMediaDeviceState::Started", (int64)ERtcMediaDeviceState::Started },
				{ "ERtcMediaDeviceState::Stopped", (int64)ERtcMediaDeviceState::Stopped },
				{ "ERtcMediaDeviceState::RuntimeError", (int64)ERtcMediaDeviceState::RuntimeError },
				{ "ERtcMediaDeviceState::Added", (int64)ERtcMediaDeviceState::Added },
				{ "ERtcMediaDeviceState::Removed", (int64)ERtcMediaDeviceState::Removed },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Added.Name", "ERtcMediaDeviceState::Added" },
				{ "BlueprintType", "true" },
				{ "Comment", "/// @brief Rtc media device state.\n" },
				{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
				{ "None.Name", "ERtcMediaDeviceState::None" },
				{ "Removed.Name", "ERtcMediaDeviceState::Removed" },
				{ "RuntimeError.Name", "ERtcMediaDeviceState::RuntimeError" },
				{ "Started.Name", "ERtcMediaDeviceState::Started" },
				{ "Stopped.Name", "ERtcMediaDeviceState::Stopped" },
				{ "ToolTip", "@brief Rtc media device state." },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
				nullptr,
				"ERtcMediaDeviceState",
				"ERtcMediaDeviceState",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* ERtcMediaDeviceType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceType, Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcMediaDeviceType"));
		}
		return Singleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcMediaDeviceType>()
	{
		return ERtcMediaDeviceType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ERtcMediaDeviceType(ERtcMediaDeviceType_StaticEnum, TEXT("/Script/OnlineSubsystemPico"), TEXT("ERtcMediaDeviceType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceType_Hash() { return 3722999313U; }
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_OnlineSubsystemPico();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ERtcMediaDeviceType"), 0, Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcMediaDeviceType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ERtcMediaDeviceType::None", (int64)ERtcMediaDeviceType::None },
				{ "ERtcMediaDeviceType::AudioUnknown", (int64)ERtcMediaDeviceType::AudioUnknown },
				{ "ERtcMediaDeviceType::AudioRenderDevice", (int64)ERtcMediaDeviceType::AudioRenderDevice },
				{ "ERtcMediaDeviceType::AudioCaptureDevice", (int64)ERtcMediaDeviceType::AudioCaptureDevice },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "AudioCaptureDevice.Name", "ERtcMediaDeviceType::AudioCaptureDevice" },
				{ "AudioRenderDevice.Name", "ERtcMediaDeviceType::AudioRenderDevice" },
				{ "AudioUnknown.Name", "ERtcMediaDeviceType::AudioUnknown" },
				{ "BlueprintType", "true" },
				{ "Comment", "/// @brief Rtc media device type.\n" },
				{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
				{ "None.Name", "ERtcMediaDeviceType::None" },
				{ "ToolTip", "@brief Rtc media device type." },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
				nullptr,
				"ERtcMediaDeviceType",
				"ERtcMediaDeviceType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* ERtcUserLeaveReasonType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcUserLeaveReasonType, Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcUserLeaveReasonType"));
		}
		return Singleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcUserLeaveReasonType>()
	{
		return ERtcUserLeaveReasonType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ERtcUserLeaveReasonType(ERtcUserLeaveReasonType_StaticEnum, TEXT("/Script/OnlineSubsystemPico"), TEXT("ERtcUserLeaveReasonType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcUserLeaveReasonType_Hash() { return 3032629734U; }
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcUserLeaveReasonType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_OnlineSubsystemPico();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ERtcUserLeaveReasonType"), 0, Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcUserLeaveReasonType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ERtcUserLeaveReasonType::None", (int64)ERtcUserLeaveReasonType::None },
				{ "ERtcUserLeaveReasonType::Quit", (int64)ERtcUserLeaveReasonType::Quit },
				{ "ERtcUserLeaveReasonType::Dropped", (int64)ERtcUserLeaveReasonType::Dropped },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "/// @brief Rtc user leave reason type.\n" },
				{ "Dropped.Name", "ERtcUserLeaveReasonType::Dropped" },
				{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
				{ "None.Name", "ERtcUserLeaveReasonType::None" },
				{ "Quit.Name", "ERtcUserLeaveReasonType::Quit" },
				{ "ToolTip", "@brief Rtc user leave reason type." },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
				nullptr,
				"ERtcUserLeaveReasonType",
				"ERtcUserLeaveReasonType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* ERtcJoinRoomType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcJoinRoomType, Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcJoinRoomType"));
		}
		return Singleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcJoinRoomType>()
	{
		return ERtcJoinRoomType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ERtcJoinRoomType(ERtcJoinRoomType_StaticEnum, TEXT("/Script/OnlineSubsystemPico"), TEXT("ERtcJoinRoomType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcJoinRoomType_Hash() { return 2927065227U; }
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcJoinRoomType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_OnlineSubsystemPico();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ERtcJoinRoomType"), 0, Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcJoinRoomType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ERtcJoinRoomType::None", (int64)ERtcJoinRoomType::None },
				{ "ERtcJoinRoomType::First", (int64)ERtcJoinRoomType::First },
				{ "ERtcJoinRoomType::Reconnected", (int64)ERtcJoinRoomType::Reconnected },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "/// @brief Rtc join room type enum.\n" },
				{ "First.Name", "ERtcJoinRoomType::First" },
				{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
				{ "None.Name", "ERtcJoinRoomType::None" },
				{ "Reconnected.Name", "ERtcJoinRoomType::Reconnected" },
				{ "ToolTip", "@brief Rtc join room type enum." },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
				nullptr,
				"ERtcJoinRoomType",
				"ERtcJoinRoomType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* ERtcEarMonitorMode_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcEarMonitorMode, Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcEarMonitorMode"));
		}
		return Singleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcEarMonitorMode>()
	{
		return ERtcEarMonitorMode_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ERtcEarMonitorMode(ERtcEarMonitorMode_StaticEnum, TEXT("/Script/OnlineSubsystemPico"), TEXT("ERtcEarMonitorMode"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcEarMonitorMode_Hash() { return 4242333530U; }
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcEarMonitorMode()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_OnlineSubsystemPico();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ERtcEarMonitorMode"), 0, Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcEarMonitorMode_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ERtcEarMonitorMode::None", (int64)ERtcEarMonitorMode::None },
				{ "ERtcEarMonitorMode::Off", (int64)ERtcEarMonitorMode::Off },
				{ "ERtcEarMonitorMode::On", (int64)ERtcEarMonitorMode::On },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "/// @brief Rtc ear monitor mode enum.\n" },
				{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
				{ "None.Name", "ERtcEarMonitorMode::None" },
				{ "Off.Name", "ERtcEarMonitorMode::Off" },
				{ "On.Name", "ERtcEarMonitorMode::On" },
				{ "ToolTip", "@brief Rtc ear monitor mode enum." },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
				nullptr,
				"ERtcEarMonitorMode",
				"ERtcEarMonitorMode",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* ERtcStreamIndex_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamIndex, Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcStreamIndex"));
		}
		return Singleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcStreamIndex>()
	{
		return ERtcStreamIndex_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ERtcStreamIndex(ERtcStreamIndex_StaticEnum, TEXT("/Script/OnlineSubsystemPico"), TEXT("ERtcStreamIndex"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamIndex_Hash() { return 3273820764U; }
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamIndex()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_OnlineSubsystemPico();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ERtcStreamIndex"), 0, Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcStreamIndex_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ERtcStreamIndex::None", (int64)ERtcStreamIndex::None },
				{ "ERtcStreamIndex::Main", (int64)ERtcStreamIndex::Main },
				{ "ERtcStreamIndex::Screen", (int64)ERtcStreamIndex::Screen },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "/// @brief Rtc audio stream index enum.\n" },
				{ "Main.Name", "ERtcStreamIndex::Main" },
				{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
				{ "None.Name", "ERtcStreamIndex::None" },
				{ "Screen.Name", "ERtcStreamIndex::Screen" },
				{ "ToolTip", "@brief Rtc audio stream index enum." },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
				nullptr,
				"ERtcStreamIndex",
				"ERtcStreamIndex",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* ERtcAudioScenarioType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioScenarioType, Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcAudioScenarioType"));
		}
		return Singleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcAudioScenarioType>()
	{
		return ERtcAudioScenarioType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ERtcAudioScenarioType(ERtcAudioScenarioType_StaticEnum, TEXT("/Script/OnlineSubsystemPico"), TEXT("ERtcAudioScenarioType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioScenarioType_Hash() { return 320899389U; }
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioScenarioType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_OnlineSubsystemPico();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ERtcAudioScenarioType"), 0, Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioScenarioType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ERtcAudioScenarioType::None", (int64)ERtcAudioScenarioType::None },
				{ "ERtcAudioScenarioType::Music", (int64)ERtcAudioScenarioType::Music },
				{ "ERtcAudioScenarioType::HighQualityCommunication", (int64)ERtcAudioScenarioType::HighQualityCommunication },
				{ "ERtcAudioScenarioType::Communication", (int64)ERtcAudioScenarioType::Communication },
				{ "ERtcAudioScenarioType::Media", (int64)ERtcAudioScenarioType::Media },
				{ "ERtcAudioScenarioType::GameStreaming", (int64)ERtcAudioScenarioType::GameStreaming },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "/// @brief Rtc audio scenario type enum.\n" },
				{ "Communication.Name", "ERtcAudioScenarioType::Communication" },
				{ "GameStreaming.Name", "ERtcAudioScenarioType::GameStreaming" },
				{ "HighQualityCommunication.Name", "ERtcAudioScenarioType::HighQualityCommunication" },
				{ "Media.Name", "ERtcAudioScenarioType::Media" },
				{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
				{ "Music.Name", "ERtcAudioScenarioType::Music" },
				{ "None.Name", "ERtcAudioScenarioType::None" },
				{ "ToolTip", "@brief Rtc audio scenario type enum." },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
				nullptr,
				"ERtcAudioScenarioType",
				"ERtcAudioScenarioType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* ERtcAudioPlaybackDevice_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioPlaybackDevice, Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcAudioPlaybackDevice"));
		}
		return Singleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcAudioPlaybackDevice>()
	{
		return ERtcAudioPlaybackDevice_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ERtcAudioPlaybackDevice(ERtcAudioPlaybackDevice_StaticEnum, TEXT("/Script/OnlineSubsystemPico"), TEXT("ERtcAudioPlaybackDevice"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioPlaybackDevice_Hash() { return 3351901511U; }
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioPlaybackDevice()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_OnlineSubsystemPico();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ERtcAudioPlaybackDevice"), 0, Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcAudioPlaybackDevice_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ERtcAudioPlaybackDevice::None", (int64)ERtcAudioPlaybackDevice::None },
				{ "ERtcAudioPlaybackDevice::Headset", (int64)ERtcAudioPlaybackDevice::Headset },
				{ "ERtcAudioPlaybackDevice::EarPiece", (int64)ERtcAudioPlaybackDevice::EarPiece },
				{ "ERtcAudioPlaybackDevice::SpeakerPhone", (int64)ERtcAudioPlaybackDevice::SpeakerPhone },
				{ "ERtcAudioPlaybackDevice::HeadsetBlueTooth", (int64)ERtcAudioPlaybackDevice::HeadsetBlueTooth },
				{ "ERtcAudioPlaybackDevice::HeadsetUsb", (int64)ERtcAudioPlaybackDevice::HeadsetUsb },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "/// @brief Rtc audio playback device enum.\n" },
				{ "EarPiece.Name", "ERtcAudioPlaybackDevice::EarPiece" },
				{ "Headset.Name", "ERtcAudioPlaybackDevice::Headset" },
				{ "HeadsetBlueTooth.Name", "ERtcAudioPlaybackDevice::HeadsetBlueTooth" },
				{ "HeadsetUsb.Name", "ERtcAudioPlaybackDevice::HeadsetUsb" },
				{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
				{ "None.Name", "ERtcAudioPlaybackDevice::None" },
				{ "SpeakerPhone.Name", "ERtcAudioPlaybackDevice::SpeakerPhone" },
				{ "ToolTip", "@brief Rtc audio playback device enum." },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
				nullptr,
				"ERtcAudioPlaybackDevice",
				"ERtcAudioPlaybackDevice",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* ERtcPauseResumeMediaType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcPauseResumeMediaType, Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcPauseResumeMediaType"));
		}
		return Singleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcPauseResumeMediaType>()
	{
		return ERtcPauseResumeMediaType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ERtcPauseResumeMediaType(ERtcPauseResumeMediaType_StaticEnum, TEXT("/Script/OnlineSubsystemPico"), TEXT("ERtcPauseResumeMediaType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcPauseResumeMediaType_Hash() { return 1009100221U; }
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcPauseResumeMediaType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_OnlineSubsystemPico();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ERtcPauseResumeMediaType"), 0, Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcPauseResumeMediaType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ERtcPauseResumeMediaType::None", (int64)ERtcPauseResumeMediaType::None },
				{ "ERtcPauseResumeMediaType::Audio", (int64)ERtcPauseResumeMediaType::Audio },
				{ "ERtcPauseResumeMediaType::Video", (int64)ERtcPauseResumeMediaType::Video },
				{ "ERtcPauseResumeMediaType::AudioAndVideo", (int64)ERtcPauseResumeMediaType::AudioAndVideo },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Audio.Name", "ERtcPauseResumeMediaType::Audio" },
				{ "AudioAndVideo.Name", "ERtcPauseResumeMediaType::AudioAndVideo" },
				{ "BlueprintType", "true" },
				{ "Comment", "/// @brief Rtc pause or resume media type enum.\n" },
				{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
				{ "None.Name", "ERtcPauseResumeMediaType::None" },
				{ "ToolTip", "@brief Rtc pause or resume media type enum." },
				{ "Video.Name", "ERtcPauseResumeMediaType::Video" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
				nullptr,
				"ERtcPauseResumeMediaType",
				"ERtcPauseResumeMediaType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* ERtcMuteState_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcMuteState, Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcMuteState"));
		}
		return Singleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcMuteState>()
	{
		return ERtcMuteState_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ERtcMuteState(ERtcMuteState_StaticEnum, TEXT("/Script/OnlineSubsystemPico"), TEXT("ERtcMuteState"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcMuteState_Hash() { return 639118159U; }
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcMuteState()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_OnlineSubsystemPico();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ERtcMuteState"), 0, Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcMuteState_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ERtcMuteState::None", (int64)ERtcMuteState::None },
				{ "ERtcMuteState::Off", (int64)ERtcMuteState::Off },
				{ "ERtcMuteState::On", (int64)ERtcMuteState::On },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "/// @brief Rtc mute state enum.\n" },
				{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
				{ "None.Name", "ERtcMuteState::None" },
				{ "Off.Name", "ERtcMuteState::Off" },
				{ "On.Name", "ERtcMuteState::On" },
				{ "ToolTip", "@brief Rtc mute state enum." },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
				nullptr,
				"ERtcMuteState",
				"ERtcMuteState",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* ERtcRoomProfileType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcRoomProfileType, Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcRoomProfileType"));
		}
		return Singleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcRoomProfileType>()
	{
		return ERtcRoomProfileType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ERtcRoomProfileType(ERtcRoomProfileType_StaticEnum, TEXT("/Script/OnlineSubsystemPico"), TEXT("ERtcRoomProfileType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcRoomProfileType_Hash() { return 1076148944U; }
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcRoomProfileType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_OnlineSubsystemPico();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ERtcRoomProfileType"), 0, Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcRoomProfileType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ERtcRoomProfileType::None", (int64)ERtcRoomProfileType::None },
				{ "ERtcRoomProfileType::Communication", (int64)ERtcRoomProfileType::Communication },
				{ "ERtcRoomProfileType::LiveBroadcasting", (int64)ERtcRoomProfileType::LiveBroadcasting },
				{ "ERtcRoomProfileType::Game", (int64)ERtcRoomProfileType::Game },
				{ "ERtcRoomProfileType::CloundGame", (int64)ERtcRoomProfileType::CloundGame },
				{ "ERtcRoomProfileType::LowLatency", (int64)ERtcRoomProfileType::LowLatency },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "CloundGame.Name", "ERtcRoomProfileType::CloundGame" },
				{ "Comment", "/// @brief Rtc engine room profile type enum.\n" },
				{ "Communication.Name", "ERtcRoomProfileType::Communication" },
				{ "Game.Name", "ERtcRoomProfileType::Game" },
				{ "LiveBroadcasting.Name", "ERtcRoomProfileType::LiveBroadcasting" },
				{ "LowLatency.Name", "ERtcRoomProfileType::LowLatency" },
				{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
				{ "None.Name", "ERtcRoomProfileType::None" },
				{ "ToolTip", "@brief Rtc engine room profile type enum." },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
				nullptr,
				"ERtcRoomProfileType",
				"ERtcRoomProfileType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* ERtcEngineInitResult_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcEngineInitResult, Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcEngineInitResult"));
		}
		return Singleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcEngineInitResult>()
	{
		return ERtcEngineInitResult_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ERtcEngineInitResult(ERtcEngineInitResult_StaticEnum, TEXT("/Script/OnlineSubsystemPico"), TEXT("ERtcEngineInitResult"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcEngineInitResult_Hash() { return 3011258590U; }
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcEngineInitResult()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_OnlineSubsystemPico();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ERtcEngineInitResult"), 0, Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcEngineInitResult_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ERtcEngineInitResult::None", (int64)ERtcEngineInitResult::None },
				{ "ERtcEngineInitResult::Unknow", (int64)ERtcEngineInitResult::Unknow },
				{ "ERtcEngineInitResult::AlreadyInitialized", (int64)ERtcEngineInitResult::AlreadyInitialized },
				{ "ERtcEngineInitResult::InvalidConfig", (int64)ERtcEngineInitResult::InvalidConfig },
				{ "ERtcEngineInitResult::Success", (int64)ERtcEngineInitResult::Success },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "AlreadyInitialized.Name", "ERtcEngineInitResult::AlreadyInitialized" },
				{ "BlueprintType", "true" },
				{ "Comment", "/// @brief Rtc engine init result enum.\n" },
				{ "InvalidConfig.Name", "ERtcEngineInitResult::InvalidConfig" },
				{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
				{ "None.Name", "ERtcEngineInitResult::None" },
				{ "Success.Name", "ERtcEngineInitResult::Success" },
				{ "ToolTip", "@brief Rtc engine init result enum." },
				{ "Unknow.Name", "ERtcEngineInitResult::Unknow" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
				nullptr,
				"ERtcEngineInitResult",
				"ERtcEngineInitResult",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	static UEnum* ERtcPrivilege_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_OnlineSubsystemPico_ERtcPrivilege, Z_Construct_UPackage__Script_OnlineSubsystemPico(), TEXT("ERtcPrivilege"));
		}
		return Singleton;
	}
	template<> ONLINESUBSYSTEMPICO_API UEnum* StaticEnum<ERtcPrivilege>()
	{
		return ERtcPrivilege_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ERtcPrivilege(ERtcPrivilege_StaticEnum, TEXT("/Script/OnlineSubsystemPico"), TEXT("ERtcPrivilege"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcPrivilege_Hash() { return 3672534218U; }
	UEnum* Z_Construct_UEnum_OnlineSubsystemPico_ERtcPrivilege()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_OnlineSubsystemPico();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ERtcPrivilege"), 0, Get_Z_Construct_UEnum_OnlineSubsystemPico_ERtcPrivilege_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ERtcPrivilege::None", (int64)ERtcPrivilege::None },
				{ "ERtcPrivilege::PublishStream", (int64)ERtcPrivilege::PublishStream },
				{ "ERtcPrivilege::PublishAudioStream", (int64)ERtcPrivilege::PublishAudioStream },
				{ "ERtcPrivilege::PublishVideoStream", (int64)ERtcPrivilege::PublishVideoStream },
				{ "ERtcPrivilege::SubscribeStream", (int64)ERtcPrivilege::SubscribeStream },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "/// @brief Rtc engine privilege enum.\n" },
				{ "ModuleRelativePath", "Public/RTCPicoUserInterface.h" },
				{ "None.Name", "ERtcPrivilege::None" },
				{ "PublishAudioStream.Name", "ERtcPrivilege::PublishAudioStream" },
				{ "PublishStream.Name", "ERtcPrivilege::PublishStream" },
				{ "PublishVideoStream.Name", "ERtcPrivilege::PublishVideoStream" },
				{ "SubscribeStream.Name", "ERtcPrivilege::SubscribeStream" },
				{ "ToolTip", "@brief Rtc engine privilege enum." },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_OnlineSubsystemPico,
				nullptr,
				"ERtcPrivilege",
				"ERtcPrivilege",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
