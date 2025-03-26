#include "PicoSpatialAudioEventTracker.h"

#include "PxrAudioSpatializerCommonUtils.h"

PICOPluginWrapper PicoSpatialAudioEventTracker::PluginWrapper;

void PicoSpatialAudioEventTracker::Init()
{
#if PASP_PICO_HMD_SUPPORTED_PLATFORMS
	PASP_InitializePICOPluginWrapper(&PluginWrapper);
#endif
}

void PicoSpatialAudioEventTracker::Shutdown()
{
#if PASP_PICO_HMD_SUPPORTED_PLATFORMS
	PASP_DestroyPICOPluginWrapper(&PluginWrapper);
#endif
}

int PicoSpatialAudioEventTracker::LogSdkApi(const char* buf)
{
	if (!PluginWrapper.Initialized)
	{
		UE_LOG(LogPicoSpatialAudio, Display, TEXT("LogSdkApi(%s); but PXR PluginWrapper is not initialized."), *FString(buf));
		return 0;
	}
	char temp[200] = {'\0'};
	strcpy(temp, buf);
	const int result = PluginWrapper.LogSdkApi(temp);
	UE_LOG(LogPicoSpatialAudio, Display, TEXT("LogSdkApi(%s); result = %d"), *FString(buf), result);
	return result;
}
