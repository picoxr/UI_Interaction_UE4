#pragma once
#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "IAudioExtensionPlugin.h"
#include "PicoSpatializationSourceSettings.h"
#include "pxr_audio_spatializer_types.h"
#include "AudioDevice.h"
#include "PicoAmbisonicsRenderer.h"
#include "PxrAudioSpatializerCommonUtils.h"
#include "Interfaces/IPluginManager.h"

class FPicoSpatializationFactory : public IAudioSpatializationFactory
{
public:
	virtual FString GetDisplayName() override;

	virtual bool SupportsPlatform(const FString& PlatformName) override;

	virtual TAudioSpatializationPtr CreateNewSpatializationPlugin(FAudioDevice* OwningDevice) override;

	virtual UClass* GetCustomSpatializationSettingsClass() const override;;

	virtual bool IsExternalSend() override { return true; }

	virtual int32 GetMaxSupportedChannels() override;
};

class FPicoReverbFactory : public IAudioReverbFactory
{
public:

	virtual FString GetDisplayName() override;

	virtual bool SupportsPlatform(const FString& PlatformName) override;

	virtual TAudioReverbPtr CreateNewReverbPlugin(FAudioDevice* OwningDevice) override;
	virtual bool IsExternalSend() override;
};

class FPicoSpatialAudioModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	// Returns a pointer to a given PluginType or nullptr if PluginType is invalid.
	IAudioPluginFactory* GetPluginFactory(EAudioPlugin PluginType);

	// Registers given audio device with the Pico Spatial Audio module.
	void RegisterAudioDevice(FAudioDevice* AudioDeviceHandle);

	// Unregisters given audio device from the Pico Spatial Audio module.
	void UnregisterAudioDevice(FAudioDevice* AudioDeviceHandle);

	static UPicoSpatializationSourceSettings* GetDefaultSourceSettings();
private:
	static bool bModuleInitialized;
	
	// List of registered audio devices.
	TArray<FAudioDevice*> RegisteredAudioDevices;

	//	Default source settings
	static UPicoSpatializationSourceSettings* DefaultSourceSettings;
	
	// Plugin factories.
	FPicoSpatializationFactory SpatializationPluginFactory;
	FPicoReverbFactory ReverbPluginFactory;
	Pxr_Audio::Spatializer::FAmbisonicsFactory AmbisonicsFactory;

	//	Dll loading tools
	void* DllHandle = nullptr;
	static void* LoadDll();

	static void UnloadDll(void* DllHandle);
};
