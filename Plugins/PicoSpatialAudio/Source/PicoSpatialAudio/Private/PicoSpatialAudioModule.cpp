//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#include "PicoSpatialAudioModule.h"

#include "CoreMinimal.h"
#include "PxrAudioSpatializerSpatialization.h"
#include "PxrAudioSpatializerReverb.h"
#include "PxrAudioSpatializerListener.h"
#include "PicoSpatialAudioEngine/PicoSpatialAudioEventTracker.h"

/**
 * @brief Implementation of FPicoSpatializationFactory 
 */
FString FPicoSpatializationFactory::GetDisplayName()
{
	static FString DisplayName = FString(TEXT("Pico Spatial Audio"));
	return DisplayName;
}

bool FPicoSpatializationFactory::SupportsPlatform(const FString& PlatformName)
{
	return PlatformName == FString(TEXT("Windows")) || PlatformName == FString(TEXT("Mac")) || PlatformName ==
		FString(TEXT("Android"));
}

TAudioSpatializationPtr FPicoSpatializationFactory::CreateNewSpatializationPlugin(
	FAudioDevice* OwningDevice)
{
	// Register the audio device to the Pico Spatial Audio module.
	FPicoSpatialAudioModule* Module = &FModuleManager::GetModuleChecked<FPicoSpatialAudioModule>("PicoSpatialAudio");
	if (Module != nullptr)
	{
		Module->RegisterAudioDevice(OwningDevice);
	}
	return TAudioSpatializationPtr(new Pxr_Audio::Spatializer::FSpatialization());
}

UClass* FPicoSpatializationFactory::GetCustomSpatializationSettingsClass() const
{
	return UPicoSpatializationSourceSettings::StaticClass();
}

int32 FPicoSpatializationFactory::GetMaxSupportedChannels()
{
	return 2;
}

/**
 * @brief Implementation of FPicoSpatializationReverbFactory 
 */
FString FPicoReverbFactory::GetDisplayName()
{
	static FString DisplayName = FString(TEXT("Pico Spatial Audio"));
	return DisplayName;
}

bool FPicoReverbFactory::SupportsPlatform(const FString& PlatformName)
{
	return true;
}

TAudioReverbPtr FPicoReverbFactory::CreateNewReverbPlugin(FAudioDevice* OwningDevice)
{
	// Register the audio device to the Pico Spatial Audio module.
	FPicoSpatialAudioModule* Module = &FModuleManager::GetModuleChecked<FPicoSpatialAudioModule>("PicoSpatialAudio");
	if (Module != nullptr)
	{
		Module->RegisterAudioDevice(OwningDevice);
	}
	return TAudioReverbPtr(new Pxr_Audio::Spatializer::FReverb());
}

bool FPicoReverbFactory::IsExternalSend()
{
	return true;
}

/**
 * @brief Implementation of FPicoSpatialAudioModule 
 */

bool FPicoSpatialAudioModule::bModuleInitialized = false;
UPicoSpatializationSourceSettings* FPicoSpatialAudioModule::DefaultSourceSettings = nullptr;

void FPicoSpatialAudioModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	check(bModuleInitialized == false);
	bModuleInitialized = true;

	//	load dynamic library of pico spatializer native SDK
	DllHandle = LoadDll();

	if (!DefaultSourceSettings)
	{
		DefaultSourceSettings = NewObject<UPicoSpatializationSourceSettings>(
			UPicoSpatializationSourceSettings::StaticClass(), TEXT("Default Pico Spatial Audio Source Preset"));
	}
	if (DefaultSourceSettings)
	{
		DefaultSourceSettings->AddToRoot();
	}

	// Register the Pico Spatial Audio plugin factories.
	IModularFeatures::Get().RegisterModularFeature(FPicoSpatializationFactory::GetModularFeatureName(),
	                                               &SpatializationPluginFactory);
	IModularFeatures::Get().RegisterModularFeature(FPicoReverbFactory::GetModularFeatureName(), &ReverbPluginFactory);

	UE_LOG(LogPicoSpatialAudio, Display, TEXT("Pico Spatial Audio Module is initialized"));

	//	Start event tracking module
	PicoSpatialAudioEventTracker::Init();
}

void FPicoSpatialAudioModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	check(bModuleInitialized == true);
	bModuleInitialized = false;

	//	Unload dll
	UnloadDll(DllHandle);

	UE_LOG(LogPicoSpatialAudio, Display, TEXT("Pico Spatial Audio Module is shutdown"));
	
	//	Stop event tracking module
	PicoSpatialAudioEventTracker::Shutdown();
}

IAudioPluginFactory* FPicoSpatialAudioModule::GetPluginFactory(EAudioPlugin PluginType)
{
	switch (PluginType)
	{
	case EAudioPlugin::SPATIALIZATION:
		return &SpatializationPluginFactory;
	case EAudioPlugin::REVERB:
		return &ReverbPluginFactory;
	default:
		return nullptr;
	}
}

void FPicoSpatialAudioModule::RegisterAudioDevice(FAudioDevice* AudioDeviceHandle)
{
	if (!RegisteredAudioDevices.Contains(AudioDeviceHandle))
	{
		TAudioPluginListenerPtr NewPicoSpatialAudioPluginListener = TAudioPluginListenerPtr(
			new Pxr_Audio::Spatializer::FListener());
		AudioDeviceHandle->RegisterPluginListener(NewPicoSpatialAudioPluginListener);
		RegisteredAudioDevices.Add(AudioDeviceHandle);
	}
}

void FPicoSpatialAudioModule::UnregisterAudioDevice(FAudioDevice* AudioDeviceHandle)
{
	RegisteredAudioDevices.Remove(AudioDeviceHandle);
	UE_LOG(LogPicoSpatialAudio, Display, TEXT("Audio Device unregistered from Pico Spatial Audio"));
}

UPicoSpatializationSourceSettings* FPicoSpatialAudioModule::GetDefaultSourceSettings()
{
	return DefaultSourceSettings;
}

void* FPicoSpatialAudioModule::LoadDll()
{
	void* DllHandle = nullptr;

	//	Get the dll directory in different platforms
	//	Get the base directory of this plugin
	FString Path;
	FString ModuleDir = IPluginManager::Get().FindPlugin("PicoSpatialAudio")->GetBaseDir();
	//	Get platform-specific dynamic lib directory relative to ModuleDir
#if PLATFORM_WINDOWS
#if PLATFORM_64BITS
		Path = ModuleDir / TEXT("Source/PicoSpatialAudio/libs/windows/dll/PicoSpatializerNative.dll");
#endif	// PLATFORM_64BITS
#elif PLATFORM_MAC
	Path = ModuleDir / TEXT("Source/PicoSpatialAudio/libs/mac/libPicoSpatializerNative.dylib");
#elif PLATFORM_ANDROID
		// Not necessary on this platform.
		return nullptr;
#else
		UE_LOG(LogPicoSpatialAudio, Error, TEXT("Unsupported Platform. Supported platforms are ANDROID, MAC and WINDOWS 64-bits"));
		return nullptr;
#endif  // PLATFORM_WINDOWS

	UE_LOG(LogPicoSpatialAudio, Display, TEXT("Attempt to load dynamic library from %s"), *Path);
	if (FPaths::FileExists(*Path))
	{
		DllHandle = FPlatformProcess::GetDllHandle(*Path);
	}
	else
	{
		UE_LOG(LogPicoSpatialAudio, Error, TEXT("Dynamic library file not exist at %s"), *Path);
	}

	UE_CLOG(DllHandle != nullptr, LogPicoSpatialAudio, Display, TEXT("Loaded dynamic library from %s"), *Path);
	return DllHandle;
}

void FPicoSpatialAudioModule::UnloadDll(void* DllHandle)
{
	if (DllHandle != nullptr)
	{
		FPlatformProcess::FreeDllHandle(DllHandle);
	}
}

IMPLEMENT_MODULE(FPicoSpatialAudioModule, PicoSpatialAudio)
