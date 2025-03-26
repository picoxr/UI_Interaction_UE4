#pragma once
#include "PXR_PluginWrapper.h"

class PicoSpatialAudioEventTracker
{
public:
	PicoSpatialAudioEventTracker();

	static void Init();
	static void Shutdown();
	static int LogSdkApi(const char* buf);

#if PASP_PICO_HMD_SUPPORTED_PLATFORMS
private:
	static PICOPluginWrapper PluginWrapper;
#endif
};
