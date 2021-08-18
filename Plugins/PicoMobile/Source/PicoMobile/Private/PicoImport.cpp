// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#include "PicoImport.h"
#include "PicoJava.h"
#include "../Launch/Resources/Version.h"
#include "PicoMobileSettings.h"
#include "XRThreadUtils.h"
DEFINE_LOG_CATEGORY_STATIC(LogPicoImport, Log, All);

#if PLATFORM_ANDROID
#include "Android/AndroidWindow.h"

#define DLL_IMPORT(Name, Func) \
	Func = (FDll##Func##Proc)dlsym(PicoImport::GSharedLibraryHandle, #Name); \
	if (Func == nullptr) \
	{ \
		UE_LOG(LogPicoImport, Display, TEXT("GetDllExport  %s Failed! "),#Name);\
		return false; \
	}

#define DLL_DEFINE(Func) \
	FDll##Func##Proc PicoImport::Func = nullptr

void* PicoImport::GSharedLibraryHandle = nullptr;
FString PicoImport::GPluginDir;


DLL_DEFINE(PvrInit);
DLL_DEFINE(PvrStartSensor);
DLL_DEFINE(PvrStopSensor);
DLL_DEFINE(PvrResetSensor);
DLL_DEFINE(PvrOptionalResetSensor);
DLL_DEFINE(PvrGetMainSensorState);
DLL_DEFINE(PvrGetPsensorState);
DLL_DEFINE(PvrGetAcceleration);
DLL_DEFINE(PvrGetAngularVelocity);
DLL_DEFINE(PvrGetIntConfig);
DLL_DEFINE(PvrGetFloatConfig);
DLL_DEFINE(PvrSetInitActivity);
DLL_DEFINE(PvrGetSDKVersion);
DLL_DEFINE(PvrGetGpuUtilization);
DLL_DEFINE(PvrGetSeeThroughState);
DLL_DEFINE(PvrSubmitRenderTargetSize);
DLL_DEFINE(PvrSetTrackingOrigin);
DLL_DEFINE(PvrGetFrameRateLimit);
DLL_DEFINE(PvrUnityRenderEvent);
DLL_DEFINE(PvrSetOverlayModelViewMatrix);
DLL_DEFINE(PvrEnable6DofModule);
DLL_DEFINE(PvrEnableFoveation);
DLL_DEFINE(PvrSetFoveationParameters);
DLL_DEFINE(PvrSetFoveationResource);
DLL_DEFINE(PvrSetFoveationParameters2);
DLL_DEFINE(PvrSetFoveationLevel);
DLL_DEFINE(PvrGetFoveationLevel);
DLL_DEFINE(PvrGetEyeTrackingData);
DLL_DEFINE(PvrGetTrackingMode);
DLL_DEFINE(PvrSetTrackingMode);
DLL_DEFINE(PvrSetUnrealParam);
DLL_DEFINE(PvrSetCPUGPULevels);
DLL_DEFINE(PvrEnableMultiView);
DLL_DEFINE(PvrGetBoundaryConfigured);
DLL_DEFINE(PvrGetBoundaryEnabled);
DLL_DEFINE(PvrSetBoundaryVisible);
DLL_DEFINE(PvrBoundaryTestNode);
DLL_DEFINE(PvrBoundaryTestPoint);
DLL_DEFINE(PvrBoundaryGetGeometry);
DLL_DEFINE(PvrSetReinPosition);
DLL_DEFINE(PvrGetBoundaryDimensions);
DLL_DEFINE(PvrGetBoundaryVisible);
DLL_DEFINE(PvrSetBoundaryCameraImageRect);
DLL_DEFINE(PvrSetIPD);
DLL_DEFINE(PvrGetIPD);
DLL_DEFINE(PvrSetTrackingIPDEnabled);
DLL_DEFINE(PvrGetTrackingIPDEnabled);
DLL_DEFINE(PvrGetEyeTrackingAutoIPD);
DLL_DEFINE(PvrGetStencilMesh);

bool PicoImport::Init()
{
	GSharedLibraryHandle = dlopen("libPvr_UESDK.so", 0);
	if (GSharedLibraryHandle != NULL)
	{
		PvrInit = (FDllPvrInitProc)dlsym(GSharedLibraryHandle, "Pvr_Init");
		if (!PvrInit) UE_LOG(LogPicoImport, Warning, TEXT("Pvr_Init not found!"));

		PvrStartSensor = (FDllPvrStartSensorProc)dlsym(GSharedLibraryHandle, "Pvr_StartSensor");
		if (!PvrStartSensor) UE_LOG(LogPicoImport, Warning, TEXT("PvrStartSensor not found!"));

		PvrStopSensor = (FDllPvrStopSensorProc)dlsym(GSharedLibraryHandle, "Pvr_StopSensor");
		if (!PvrStopSensor) UE_LOG(LogPicoImport, Warning, TEXT("PvrStopSensor not found!"));

		PvrResetSensor = (FDllPvrResetSensorProc)dlsym(GSharedLibraryHandle, "Pvr_ResetSensor");
		if (!PvrResetSensor) UE_LOG(LogPicoImport, Warning, TEXT("PvrResetSensor not found!"));

		PvrOptionalResetSensor = (FDllPvrOptionalResetSensorProc)dlsym(GSharedLibraryHandle, "Pvr_OptionalResetSensor");
		if (!PvrOptionalResetSensor) UE_LOG(LogPicoImport, Warning, TEXT("PvrOptionalResetSensor not found!"));

		PvrGetMainSensorState = (FDllPvrGetMainSensorStateProc)dlsym(GSharedLibraryHandle, "Pvr_GetMainSensorState");
		if (!PvrGetMainSensorState) UE_LOG(LogPicoImport, Warning, TEXT("PvrGetMainSensorState not found!"));

		PvrGetPsensorState = (FDllPvrGetPsensorStateProc)dlsym(GSharedLibraryHandle, "Pvr_GetPsensorState");
		if (!PvrGetPsensorState) UE_LOG(LogPicoImport, Warning, TEXT("PvrGetPsensorState not found!"));

		PvrGetIntConfig = (FDllPvrGetIntConfigProc)dlsym(GSharedLibraryHandle, "Pvr_GetIntConfig");
		if (!PvrGetIntConfig) UE_LOG(LogPicoImport, Warning, TEXT("PvrGetIntConfig not found!"));

		PvrGetFloatConfig = (FDllPvrGetFloatConfigProc)dlsym(GSharedLibraryHandle, "Pvr_GetFloatConfig");
		if (!PvrGetFloatConfig) UE_LOG(LogPicoImport, Warning, TEXT("PvrGetFloatConfig not found!"));

		PvrSetInitActivity = (FDllPvrSetInitActivityProc)dlsym(GSharedLibraryHandle, "Pvr_SetInitActivity");
		if (!PvrSetInitActivity) UE_LOG(LogPicoImport, Warning, TEXT("PvrSetInitActivity not found!"));

		PvrGetSDKVersion = (FDllPvrGetSDKVersionProc)dlsym(GSharedLibraryHandle, "Pvr_GetSDKVersion");
		if (!PvrGetSDKVersion) UE_LOG(LogPicoImport, Warning, TEXT("PvrGetSDKVersion not found!"));

		PvrGetGpuUtilization = (FDllPvrGetGpuUtilizationProc)dlsym(GSharedLibraryHandle, "PVR_GetGpuUtilization");
		if (!PvrGetGpuUtilization) UE_LOG(LogPicoImport, Warning, TEXT(" PVR_GetGpuUtilization not found!"));

		PvrGetSeeThroughState = (FDllPvrGetSeeThroughStateProc)dlsym(GSharedLibraryHandle, "Pvr_GetSeeThroughState");
		if (!PvrGetSeeThroughState) UE_LOG(LogPicoImport, Warning, TEXT(" PvrGetSeeThroughState not found!"));

		PvrSubmitRenderTargetSize = (FDllPvrSubmitRenderTargetSizeProc)dlsym(GSharedLibraryHandle, "Pvr_SetViewportSize");
		if (!PvrSubmitRenderTargetSize) UE_LOG(LogPicoImport, Warning, TEXT(" PvrSubmitRenderTargetSize not found!"));

		PvrSetTrackingOrigin = (FDllPvrSetTrackingOriginProc)dlsym(GSharedLibraryHandle, "Pvr_SetTrackingOrigin");
		if (!PvrSetTrackingOrigin) UE_LOG(LogPicoImport, Warning, TEXT("PvrSetTrackingOrigin not found!"));

		PvrGetFrameRateLimit = (FDllPvrGetFrameRateLimitProc)dlsym(GSharedLibraryHandle, "Pvr_GetFrameRateLimit");
		if (!PvrGetFrameRateLimit) UE_LOG(LogPicoImport, Warning, TEXT("PvrGetFrameRateLimit not found!"));
		
		PvrGetBoundaryConfigured = (FDllPvrGetBoundaryConfiguredProc)dlsym(GSharedLibraryHandle, "Pvr_BoundaryGetConfigured");
		if (!PvrGetBoundaryConfigured) UE_LOG(LogPicoImport, Warning, TEXT("PvrBoundaryGetConfigured not found!"));

		PvrGetBoundaryEnabled = (FDllPvrGetBoundaryEnabledProc)dlsym(GSharedLibraryHandle, "Pvr_BoundaryGetEnabled");
		if (!PvrGetBoundaryEnabled) UE_LOG(LogPicoImport, Warning, TEXT("PvrBoundaryGetEnabled not found!"));

		PvrSetBoundaryVisible = (FDllPvrSetBoundaryVisibleProc)dlsym(GSharedLibraryHandle, "Pvr_BoundarySetVisible");
		if (!PvrSetBoundaryVisible) UE_LOG(LogPicoImport, Warning, TEXT("PvrBoundarySetVisible not found!"));

		PvrBoundaryTestNode = (FDllPvrBoundaryTestNodeProc)dlsym(GSharedLibraryHandle, "Pvr_BoundaryTestNode");
		if (!PvrBoundaryTestNode) UE_LOG(LogPicoImport, Warning, TEXT("PvrBoundaryTestNode not found!"));

		PvrBoundaryTestPoint = (FDllPvrBoundaryTestPointProc)dlsym(GSharedLibraryHandle, "Pvr_BoundaryTestPoint");
		if (!PvrBoundaryTestPoint) UE_LOG(LogPicoImport, Warning, TEXT("PvrBoundaryTestPoint not found!"));

		PvrBoundaryGetGeometry = (FDllPvrBoundaryGetGeometryProc)dlsym(GSharedLibraryHandle, "Pvr_BoundaryGetGeometry");
		if (!PvrBoundaryGetGeometry) UE_LOG(LogPicoImport, Warning, TEXT("PvrBoundaryGetGeometry not found!"));

		PvrSetReinPosition = (FDllPvrSetReinPositionProc)dlsym(GSharedLibraryHandle, "Pvr_SetReinPosition");
		if (!PvrSetReinPosition) UE_LOG(LogPicoImport, Warning, TEXT("PvrSetReinPosition not found!"));

		PvrGetBoundaryDimensions = (FDllPvrGetBoundaryDimensionsProc)dlsym(GSharedLibraryHandle, "Pvr_BoundaryGetDimensions");
		if (!PvrGetBoundaryDimensions) UE_LOG(LogPicoImport, Warning, TEXT("Pvr_BoundaryGetDimensions not found!"));

		PvrGetBoundaryVisible = (FDllPvrGetBoundaryVisibleProc)dlsym(GSharedLibraryHandle, "Pvr_BoundaryGetVisible");
		if (!PvrGetBoundaryVisible) UE_LOG(LogPicoImport, Warning, TEXT("Pvr_BoundaryGetVisible not found!"));

		PvrSetBoundaryCameraImageRect = (FDllPvrSetBoundaryCameraImageRectProc)dlsym(GSharedLibraryHandle, "PVR_SetCameraImageRect");
		if (!PvrSetBoundaryCameraImageRect) UE_LOG(LogPicoImport, Warning, TEXT("PVR_SetCameraImageRect not found!"));
		
		PvrSetIPD = (FDllPvrSetIPDProc)dlsym(GSharedLibraryHandle, "Pvr_SetIPD");
		if (!PvrSetIPD) UE_LOG(LogPicoImport, Warning, TEXT("PvrSetIPD not found!"));

		PvrGetIPD = (FDllPvrGetIPDProc)dlsym(GSharedLibraryHandle, "Pvr_GetIPD");
		if (!PvrGetIPD) UE_LOG(LogPicoImport, Warning, TEXT("PvrGetIPD not found!"));

		PvrSetTrackingIPDEnabled = (FDllPvrSetTrackingIPDEnabledProc)dlsym(GSharedLibraryHandle, "Pvr_SetTrackingIPDEnabled");
		if (!PvrSetTrackingIPDEnabled) UE_LOG(LogPicoImport, Warning, TEXT("PvrSetTrackingIPDEnabled not found!"));

		PvrGetTrackingIPDEnabled = (FDllPvrGetTrackingIPDEnabledProc)dlsym(GSharedLibraryHandle, "Pvr_GetTrackingIPDEnabled");
		if (!PvrGetTrackingIPDEnabled) UE_LOG(LogPicoImport, Warning, TEXT("PvrGetTrackingIPDEnabled not found!"));

		PvrGetEyeTrackingAutoIPD = (FDllPvrGetEyeTrackingAutoIPDProc)dlsym(GSharedLibraryHandle, "Pvr_GetEyeTrackingAutoIPD");
		if (!PvrGetEyeTrackingAutoIPD) UE_LOG(LogPicoImport, Warning, TEXT("PvrGetEyeTrackingAutoIPD not found!"));

		PvrUnityRenderEvent = (FDllPvrUnityRenderEventProc)dlsym(GSharedLibraryHandle, "UnityRenderEvent");
		if (!PvrUnityRenderEvent) UE_LOG(LogPicoImport, Warning, TEXT("PvrUnityRenderEvent not found!"));

		PvrSetOverlayModelViewMatrix = (FDllPvrSetOverlayModelViewMatrixProc)dlsym(GSharedLibraryHandle, "Pvr_SetOverlayModelViewMatrix");
		if (!PvrSetOverlayModelViewMatrix) UE_LOG(LogPicoImport, Warning, TEXT("PvrSetOverlayModelViewMatrix not found!"));

		PvrEnable6DofModule = (FDllPvrEnable6DofModuleProc)dlsym(GSharedLibraryHandle, "Pvr_Enable6DofModule");
		if (!PvrEnable6DofModule) UE_LOG(LogPicoImport, Warning, TEXT("PvrEnable6DofModule not found!"));

		PvrEnableFoveation = (FDllPvrEnableFoveationProc)dlsym(GSharedLibraryHandle, "Pvr_EnableFoveation");
		if (!PvrEnableFoveation) UE_LOG(LogPicoImport, Warning, TEXT("PvrEnableFoveation not found!"));

		PvrSetFoveationParameters = (FDllPvrSetFoveationParametersProc)dlsym(GSharedLibraryHandle, "Pvr_SetFoveationParameters");
		if (!PvrSetFoveationParameters) UE_LOG(LogPicoImport, Warning, TEXT("PvrSetFoveationParameters not found!"));

		PvrSetFoveationResource = (FDllPvrSetFoveationResourceProc)dlsym(GSharedLibraryHandle, "Pvr_SetFoveationResource");
		if (!PvrSetFoveationResource) UE_LOG(LogPicoImport, Warning, TEXT("PvrSetFoveationResource not found!"));

		PvrSetFoveationParameters2 = (FDllPvrSetFoveationParameters2Proc)dlsym(GSharedLibraryHandle, "Pvr_SetFoveationParameters2");
		if (!PvrSetFoveationParameters2) UE_LOG(LogPicoImport, Warning, TEXT("PvrSetFoveationParameters2 not found!"));

		PvrGetFoveationLevel = (FDllPvrGetFoveationLevelProc)dlsym(GSharedLibraryHandle, "Pvr_GetFoveationLevel");
		if (!PvrGetFoveationLevel) UE_LOG(LogPicoImport, Warning, TEXT("PvrGetFoveationLevel not found!"));

		PvrSetFoveationLevel = (FDllPvrSetFoveationLevelProc)dlsym(GSharedLibraryHandle, "Pvr_SetFoveationLevel");
		if (!PvrSetFoveationLevel) UE_LOG(LogPicoImport, Warning, TEXT("PvrSetFoveationLevel not found!"));

		PvrGetEyeTrackingData = (FDllPvrGetEyeTrackingDataProc)dlsym(GSharedLibraryHandle, "Pvr_GetEyeTrackingData");
		if (!PvrGetEyeTrackingData)UE_LOG(LogPicoImport, Warning, TEXT("PvrGetEyeTrackingData not found!"));
		
		PvrGetTrackingMode = (FDllPvrGetTrackingModeProc)dlsym(GSharedLibraryHandle, "Pvr_GetTrackingMode");
		if (!PvrGetTrackingMode)UE_LOG(LogPicoImport, Warning, TEXT("PvrGetTrackingMode not found!"));

		PvrSetTrackingMode = (FDllPvrSetTrackingModeProc)dlsym(GSharedLibraryHandle, "Pvr_SetTrackingMode");
		if (!PvrSetTrackingMode)UE_LOG(LogPicoImport, Warning, TEXT("PvrSetTrackingMode not found!"));

		PvrSetUnrealParam = (FDllPvrSetUnrealParamProc)dlsym(GSharedLibraryHandle, "PVR_SetUnrealParam");
		if (!PvrSetUnrealParam) UE_LOG(LogPicoImport, Warning, TEXT("PVR_SetUnrealParam not found!"));
		
		PvrSetCPUGPULevels = (FDllPvrSetCPUGPULevelsProc)dlsym(GSharedLibraryHandle, "PVR_setPerformanceLevels");
		if (!PvrSetCPUGPULevels) UE_LOG(LogPicoImport, Warning, TEXT("PVR_setPerformanceLevels not found!"));
		
		PvrEnableMultiView = (FDllPvrEnableMultiViewProc)dlsym(GSharedLibraryHandle, "Pvr_EnableSinglePass");
		if (!PvrEnableMultiView) UE_LOG(LogPicoImport, Warning, TEXT("PvrEnableMultiView not found!"));

		PvrGetStencilMesh = (FDllPvrGetStencilMeshProc)dlsym(GSharedLibraryHandle, "Pvr_GetStencilMesh");
		if (!PvrGetStencilMesh) UE_LOG(LogPicoImport, Warning, TEXT("PvrGetStencilMesh not found!"));
		return true;
	}
	return false;
}

void PicoImport::Uninit()
{
	GPluginDir.Empty();
	FreeDependency(GSharedLibraryHandle);
}


void PicoImport::FreeDependency(void*& Handle)
{
	if (Handle != nullptr)
	{
		dlclose(Handle);
		Handle = nullptr;
	}
}

#endif

#if PLATFORM_ANDROID
bool PicoSDK::GIsMapPost = false;
uint32 PicoSDK::GMapInitFrame = 1;
int32 PicoSDK::GVerifyCallbackCode = 1;

int32 PicoSDK::Sensor::GMainSensorIndex = 0;
bool PicoSDK::Sensor::GSensorStart[] = { false, false};
float PicoSDK::Sensor::GFov = 90;
float PicoSDK::Sensor::GVFov = 90;
float PicoSDK::Sensor::GHFov = 90;

int32 PicoSDK::Sensor::GViewnumber = 0;
bool PicoSDK::Sensor::GGameFrameEnded = false;
FPoseData PicoSDK::Sensor::GCurrentPoseGT = FPoseData::Default();
FPoseData PicoSDK::Sensor::GCurrentPoseRT = FPoseData::Default();
FPoseData PicoSDK::Sensor::GoldCurrentPoseGT = FPoseData::Default();
FPoseData PicoSDK::Sensor::GoldCurrentPoseRT = FPoseData::Default();

bool PicoSDK::Sensor::GIs6DofEnabled = false;
bool PicoSDK::Sensor::EnableNeckModel = false;
FVector PicoSDK::Sensor::NeckOffset = FVector::ZeroVector;
int32 PicoSDK::Sensor::TrackingOrigin = 0;
float PicoSDK::Sensor::WToMScale = 100.0f;

//Foveation
GLuint PicoSDK::Render::PreviousId = 0;

bool PicoSDK::Sensor::SensorInit()
{
	bool enable = false;
	if (PicoImport::PvrInit((int32)GMainSensorIndex) == 0)
	{
		enable = true;
		UE_LOG(LogPicoImport, Display, TEXT("Pvr_UE PicoMobile PvrInit Success!"));
	}
	else
		UE_LOG(LogPicoImport, Display, TEXT("Pvr_UE PicoMobile PvrInit Failed!"));
	return enable;
}

bool PicoSDK::Sensor::GetSensorCount(int32& count)
{
	bool retB = false;
	int32 _sensorCount = 0;
	PicoImport::PvrGetIntConfig(PicoSDKConfig::GlobalIntConfigs::SEENSOR_COUNT, _sensorCount);

	if (_sensorCount >= 1)
	{
		UE_LOG(LogPicoImport, Display, TEXT("Pvr_UE PicoMobile GetSensorCount Success!"));
		retB = true;
		count = _sensorCount;
	}
	else
		UE_LOG(LogPicoImport, Display, TEXT("Pvr_UE PicoMobile GetSensorCount Failed!"));

	return retB;

}

bool PicoSDK::Sensor::StartSensor(int32 sensorIndex)
{

	bool ret = false;

	if (GSensorStart[sensorIndex])
	{
		UE_LOG(LogPicoImport, Display, TEXT("Pvr_UE Sensor %d already started!"), sensorIndex);
		return ret;
	}

	if (PicoImport::PvrStartSensor(sensorIndex) == 0)
	{
		UE_LOG(LogPicoImport, Display, TEXT("Pvr_UE PicoMobile StartSensor %d Success!"), sensorIndex);
		ret = true;
		GSensorStart[sensorIndex] = true;
	}
	else
		UE_LOG(LogPicoImport, Display, TEXT("Pvr_UE PicoMobile StartSensor %d Failed!"), sensorIndex);
	return ret;
}

bool PicoSDK::Sensor::StopSensor(int32 sensorIndex)
{
	bool ret = false;
	if (GSensorStart[sensorIndex])
	{
		if (PicoImport::PvrStopSensor(sensorIndex) == 0)
		{
			GSensorStart[sensorIndex] = false;
			ret = true;
		}
	}
	else
	{
		UE_LOG(LogPicoImport, Display, TEXT("Pvr_UE Sensor %d was not started!"), sensorIndex);
	}
	return ret;

}

bool PicoSDK::Sensor::ResetSensor(int32 sensorIndex)
{
	bool ret = false;
	if (GSensorStart[sensorIndex])
	{
		if (PicoImport::PvrResetSensor(sensorIndex) == 0)
			ret = true;
	}
	return ret;
}

bool PicoSDK::Sensor::OptionalResetSensor(int32 sensorIndex, int32 isResetRotation, int32 isResetPosition)
{
	bool ret = false;
	if (GSensorStart[sensorIndex])
	{
		if (PicoImport::PvrOptionalResetSensor(sensorIndex, isResetRotation, isResetPosition))
		{
			ret = true;
		}
	}
	return ret;
}

bool PicoSDK::Sensor::GetMainSensorState()
{
	bool enable = false;
	if (GSensorStart[GMainSensorIndex])
	{
		float w = 0, x = 0, y = 0, z = 0, px = 0, py = 0, pz = 0, vfov = 90, hfov = 90;
		int32  viewnumber = 0;
		int32 ret = PicoImport::PvrGetMainSensorState(x, y, z, w, px, py, pz, hfov,vfov,viewnumber);
		if (ret == 0)
		{
			//UE_LOG(LogPicoImport, Display, TEXT("Pvr_UE headSensor %f, %f, %f, %f, %f, %f, %f,"), x, y, z, w, px, py, pz);
			FPicoJava::SetHeadSensorData(x, y, z, w, px, py, pz);
			GCurrentPoseRT.Orientation = FQuat(-z, x, y, -w);
			if (GetDefault <UPicoMobileSettings>()->bDisableHmd6DofModule)//3Dof
			{
				if (EnableNeckModel)
				{
					GCurrentPoseRT.Position = GCurrentPoseRT.Orientation * NeckOffset - NeckOffset.Z * FVector::UpVector;
					if (TrackingOrigin == 1)
					{	
						GCurrentPoseRT.Position.Z += py * PicoSDK::Sensor::WToMScale;
					}
				}
				else
				{
					GCurrentPoseRT.Position = FVector(0, 0, 0);
				}	
			}
			else
			{
				GCurrentPoseRT.Position = FVector(-pz * PicoSDK::Sensor::WToMScale, px * PicoSDK::Sensor::WToMScale, py * PicoSDK::Sensor::WToMScale);
			}
			GFov = vfov;
			GVFov = vfov;
			GHFov = hfov;
			GViewnumber = viewnumber;
			enable = true;
		}
		else if (ret == -1)
		{
			enable = false;
		}
	}
	return enable;
}

bool PicoSDK::Sensor::GetPSensorState(int32& status)
{
	bool retB = false;

	status = PicoImport::PvrGetPsensorState();

	status >= 0 ? retB = true : retB = false;

	return retB;
}

bool PicoSDK::Sensor::Enable6Dof(bool enable)
{
	int32 _isSupport6Dof = -1;
	PicoImport::PvrGetIntConfig(PicoSDKConfig::GlobalIntConfigs::ABILITY6DOF, _isSupport6Dof);

	if (GIs6DofEnabled != enable&& _isSupport6Dof && !PicoImport::PvrEnable6DofModule(enable))
	{
		GIs6DofEnabled = enable;
		EnableNeckModel = !enable;
	}
	return GIs6DofEnabled;
}

bool PicoSDK::Sensor::GetAcceleration()
{
	bool enable = false;
	return enable;
}

bool PicoSDK::Sensor::GetAngularVelocity()
{
	bool enable = false;
	return enable;
}

//Neck Model
void PicoSDK::Sensor::GetNeckOffset()
{
	EnableNeckModel = GetDefault <UPicoMobileSettings>()->bEnableNeckModel;
	if (!GetDefault <UPicoMobileSettings>()->bUseCustomNeckParameter)
	{
		float neckx = 0.0f;
		float necky = 0.0f;
		float neckz = 0.0f;
		int32 modelx = (int32)PicoSDKConfig::GlobalFloatConfigs::NECK_MODEL_X;
		int32 modely = (int32)PicoSDKConfig::GlobalFloatConfigs::NECK_MODEL_Y;
		int32 modelz = (int32)PicoSDKConfig::GlobalFloatConfigs::NECK_MODEL_Z;
		PicoImport::PvrGetFloatConfig(modelx, neckx);
		PicoImport::PvrGetFloatConfig(modely, necky);
		PicoImport::PvrGetFloatConfig(modelz, neckz);
		if (neckx != 0.0f || necky != 0.0f || neckz != 0.0f)
		{
			NeckOffset = FVector(neckz, neckx, necky);
		}
	}
	else
	{
		NeckOffset = FVector(GetDefault <UPicoMobileSettings>()->neckOffset.Z, GetDefault <UPicoMobileSettings>()->neckOffset.X, GetDefault <UPicoMobileSettings>()->neckOffset.Y);
	}
	UE_LOG(LogTemp, Log, TEXT("Pvr_UE DISFT NeckOffset.X is %f NeckOffset.Y is %f NeckOffset.Z is %f"), NeckOffset.X, NeckOffset.Y, NeckOffset.Z);
}




const uint32 IS_DATA_FLAG = 0x80000000;
const uint32 DATA_POS_MASK = 0x40000000;
const int32 DATA_POS_SHIFT = 30;
const uint32 EVENT_TYPE_MASK = 0x3EFF0000;
const int32 EVENT_TYPE_SHIFT = 17;
const uint32 PAYLOAD_MASK = 0x0000FFFF;
const int32 PAYLOAD_SHIFT = 16;

static int32 EncodeType(int32 eventType)
{
	return (int32)((uint32)eventType & ~IS_DATA_FLAG); // make sure upper bit is not set
}

static int32 EncodeData(int32 eventId, int32 eventData, int32 pos)
{
	uint32 data = 0;
	data |= IS_DATA_FLAG;
	data |= (((uint32)pos << DATA_POS_SHIFT) & DATA_POS_MASK);
	data |= (((uint32)eventId << EVENT_TYPE_SHIFT) & EVENT_TYPE_MASK);
	data |= (((uint32)eventData >> (pos * PAYLOAD_SHIFT)) & PAYLOAD_MASK);

	return (int32)data;
}

FIntPoint PicoSDK::Render::GTextureSize = FIntPoint::ZeroValue;
float PicoSDK::Render::CurrentIPD = 0.063f;
// FFR
bool PicoSDK::Render::FoveationRendering = false;
int32 PicoSDK::Render::SystemFoveationLevel = -1;
float PicoSDK::Render::DisplayRate = 60;

void PicoSDK::Render::GetFOV(float& Fov)
{
	float _fov = 0;
#if PLATFORM_ANDROID
	PicoImport::PvrGetFloatConfig(PicoSDKConfig::GlobalFloatConfigs::VFOV, _fov);
	check(_fov > 0);
#endif
	Fov = _fov;
}
void PicoSDK::Render::GetFOV(float& VFov,float& HFov)
{
	float _vfov = 0,_hfov = 0;
#if PLATFORM_ANDROID
	PicoImport::PvrGetFloatConfig(PicoSDKConfig::GlobalFloatConfigs::VFOV, _vfov);	
	check(_vfov > 0);
	PicoImport::PvrGetFloatConfig(PicoSDKConfig::GlobalFloatConfigs::HFOV, _hfov);
	check(_hfov > 0);
#endif
	VFov = _vfov;
	HFov = _hfov;
}
void PicoSDK::Render::GetDisplayRefreshRate(float& RefreshRate)
{
	float _rate = 60.0f;
#if PLATFORM_ANDROID
	PicoImport::PvrGetFloatConfig(PicoSDKConfig::GlobalFloatConfigs::DISPLAY_REFRESH_RATE, _rate);
	check(_rate > 0);
	
#endif
	RefreshRate = _rate;
}

bool PicoSDK::Render::GetIPD(float& Ipd)
{
	Ipd = CurrentIPD;
	return Ipd > 0;
}

bool PicoSDK::Render::SetIPD(float Ipd)
{
	bool ret = false;
#if PLATFORM_ANDROID
	ret = PicoImport::PvrSetIPD(Ipd);
	if (!ret)
	{
		UE_LOG(LogTemp, Warning, TEXT("Pvr_UE SetIPD failed!(ipd = %f)"), Ipd);
	}else
	{
		CurrentIPD = Ipd;
	}
#endif
	return ret;
}

bool PicoSDK::Render::GetTrackingIPDEnabled()
{
	bool ret = false;
#if PLATFORM_ANDROID
	ret = PicoImport::PvrGetTrackingIPDEnabled();
#endif
	return ret;
}

bool PicoSDK::Render::SetTrackingIPDEnabled(bool enable)
{
	bool ret = false;
#if PLATFORM_ANDROID
	ret = PicoImport::PvrSetTrackingIPDEnabled(enable);
#endif
	return ret;
}

bool PicoSDK::Render::GetEyeTrackingAutoIPD(float &autoIPD)
{
	bool ret = false;
#if PLATFORM_ANDROID
	ret = PicoImport::PvrGetEyeTrackingAutoIPD(autoIPD);
#endif
	return ret;
}

//Foveation
void PicoSDK::Render::EnableFoveation(bool isEnable)
{
	PicoSDK::Render::FoveationRendering = isEnable;
	PicoImport::PvrEnableFoveation(isEnable);
}

void PicoSDK::Render::SetFoveationResource(int textureId, int previousId, FVector EyeDirection)
{
	PicoImport::PvrSetFoveationResource(textureId, previousId, EyeDirection.X, EyeDirection.Y);
}

void PicoSDK::Render::SetFoveationParamters(float foveationGainX, float foveationGainY, float foveationArea, float foveationMinimum)
{
	if (!PicoSDK::Render::FoveationRendering)
	{
		UE_LOG(LogTemp, Warning, TEXT("Pvr_UE Please Check the box 'EnableFoveationRendering' or Call 'EnableFoveation' API to enable FFR capability"));
		return;
	}
	PicoImport::PvrSetFoveationParameters2(foveationGainX, foveationGainY, foveationArea, foveationMinimum);
	UE_LOG(LogTemp, Log, TEXT("Pvr_UE DISFT Foveation Paramters: gainX = %f, gainY = %f , area = %f , minimum = %f"), foveationGainX, foveationGainY, foveationArea, foveationMinimum);
}

void PicoSDK::Render::SetFoveationLevel(int32 level)
{
	if (!PicoSDK::Render::FoveationRendering)
	{
		UE_LOG(LogTemp, Warning, TEXT("Pvr_UE Please Check the box 'EnableFoveationRendering' or Call 'EnableFoveation' API to enable FFR capability"));
		return;
	}
	PicoImport::PvrSetFoveationLevel(level);
	UE_LOG(LogTemp, Log, TEXT("Pvr_UE DISFT Foveation Level = %d"), level);
}

int32 PicoSDK::Render::GetFoveationLevel()
{
	if (!PicoSDK::Render::FoveationRendering)
	{
		UE_LOG(LogTemp, Warning, TEXT("Pvr_UE Please Check the box 'EnableFoveationRendering' or Call 'EnableFoveation' API to enable FFR capability"));
	}
	return PicoImport::PvrGetFoveationLevel();
}

void PicoSDK::Render::SendFoveationEvent()
{
	PicoImport::PvrUnityRenderEvent(EncodeType(EVENT_BEGINEYE));
}

//MultiView
void PicoSDK::Render::EnableMultiView(bool isEnable)
{
	PicoImport::PvrEnableMultiView(isEnable);
	UE_LOG(LogTemp, Log, TEXT("Pvr_UE DISFT Multiview = %d"), (int32)isEnable);
}

void PicoSDK::Render::RenderThreadInit()
{
	PicoImport::PvrUnityRenderEvent(EncodeType(EVENT_INIT_RENDERTHREAD));
}

void PicoSDK::Render::PvrSetUnrealParam(int32 UnrealParamKey, int32 value)
{
	PicoImport::PvrSetUnrealParam(UnrealParamKey, value);
}

void PicoSDK::Render::RenderThreadShutdown()
{
	PicoImport::PvrUnityRenderEvent(EncodeType(EVENT_SHUTDOWN_RENDERTHREAD));
}

void PicoSDK::Render::RenderEventWithData(RenderEventType eventType, int32 eventData)
{
	PicoImport::PvrUnityRenderEvent(EncodeData((int32)eventType, eventData, 0));
	PicoImport::PvrUnityRenderEvent(EncodeData((int32)eventType, eventData, 1));
	PicoImport::PvrUnityRenderEvent(EncodeType((int32)eventType));
}
// Set CPU GPU level
void PicoSDK::Render::SetCPUGPULevels(int32 CPULevel, int32 GPULevel)
{  
#if PLATFORM_ANDROID
	PicoImport::PvrSetCPUGPULevels(CPULevel, GPULevel);
#endif
}

void PicoSDK::Render::GetStencilMesh(int eye, int &vertexCount, int &triangleCount, float **vertexData, unsigned int **indexData)
{
#if PLATFORM_ANDROID
	PicoImport::PvrGetStencilMesh(eye, vertexCount, triangleCount, vertexData, indexData);
#endif
}

void PicoSDK::SendResumeEvent()
{
	PicoImport::PvrUnityRenderEvent(EncodeType(EVENT_RESUME));
}

void PicoSDK::SendPauseEvent()
{
	PicoImport::PvrUnityRenderEvent(EncodeType(EVENT_PAUSE));
}
// SeeThrough boundary

int32 PicoSDK::SeeThrough::SeeThroughState = 0;

UTexture2D* PicoSDK::SeeThrough::camTextureLeft = nullptr;
UTexture2D* PicoSDK::SeeThrough::camTextureRight = nullptr;
uint32 PicoSDK::SeeThrough::LeftTextureID = -1;
uint32 PicoSDK::SeeThrough::RightTextureID = -1;
bool PicoSDK::SeeThrough::bCallGetSeeThroughImage = false;


void PicoSDK::SeeThrough::StartCameraFrame()
{
	if (!PicoSDK::SeeThrough::bCallGetSeeThroughImage)
	{
		PicoSDK::SeeThrough::bCallGetSeeThroughImage = true;
		ExecuteOnRenderThread([]()
        {         
          ExecuteOnRHIThread([]()
          {
          	PicoImport::PvrUnityRenderEvent(EncodeType(EVENT_START_CAMERA_FRAME));
          });
        });
		FPlatformProcess::Sleep(0.1);
	}
}

void PicoSDK::SeeThrough::EndCameraFrame()
{
	if (PicoSDK::SeeThrough::bCallGetSeeThroughImage)
	{
		PicoSDK::SeeThrough::bCallGetSeeThroughImage = false;
		ExecuteOnRenderThread([]()
        {         
          ExecuteOnRHIThread([]()
          {
          	PicoImport::PvrUnityRenderEvent(EncodeType(EVENT_STOP_CAMERA_FRAME));
          });
        });
	}
}

int32 PicoSDK::SeeThrough::GetSeeThroughState()
{
	uint32 data = 0;
#if PLATFORM_ANDROID
	data = PicoImport::PvrGetSeeThroughState();
#endif
	return data;
}
bool PicoSDK::SeeThrough::GetBoundaryConfigured()
{
	bool ret = false;
#if PLATFORM_ANDROID
	ret = PicoImport::PvrGetBoundaryConfigured();
#endif					  	
	return ret;
}


bool PicoSDK::SeeThrough::GetBoundaryEnabled()
{
	bool ret = false;
#if PLATFORM_ANDROID
	ret = PicoImport::PvrGetBoundaryEnabled();
#endif
	return ret;
}

void PicoSDK::SeeThrough::SetBoundaryVisible(bool enable)
{
#if PLATFORM_ANDROID
	PicoImport::PvrSetBoundaryVisible(enable);
#endif
}

bool PicoSDK::SeeThrough::BoundaryTestNode(int node, bool isPlayArea, bool &isTriggering, float &closestDistance, float &px, float &py, float &pz, float &nx, float &ny, float &nz)
{
	bool ret = false;
#if PLATFORM_ANDROID
	float ppx = 0, ppy = 0, ppz = 0, nnx = 0, nny = 0, nnz = 0;
	ret = PicoImport::PvrBoundaryTestNode(node, isPlayArea, isTriggering, closestDistance, ppx, ppy, ppz, nnx, nny, nnz);
	px = -ppz * PicoSDK::Sensor::WToMScale;
	py = ppx * PicoSDK::Sensor::WToMScale;
	pz = ppy * PicoSDK::Sensor::WToMScale;
	nx = -nnz * PicoSDK::Sensor::WToMScale;
	ny = nnx * PicoSDK::Sensor::WToMScale;
	nz = nny * PicoSDK::Sensor::WToMScale;
	//UE_LOG(LogTemp, Log, TEXT("Pvr_UE BoundaryTestNode node %d isPlayArea %d istriggering %d closestDistance %f px %f py %f pz %f nx %f ny %f nz %f"), node, (int32)isPlayArea, (int32)isTriggering, closestDistance, px, py, pz, nx, ny, nz);
#endif
	return ret;
}

bool PicoSDK::SeeThrough::BoundaryTestPoint(float x, float y, float z, bool isPlayArea, bool &isTriggering, float &closestDistance, float &px, float &py, float &pz, float &nx, float &ny, float &nz)
{
	bool ret = false;//-pz * 100, px * 100, py * 100
#if PLATFORM_ANDROID
	float ppx = 0, ppy = 0, ppz = 0, nnx = 0, nny = 0, nnz = 0;
	ret = PicoImport::PvrBoundaryTestPoint(y / 100, z / 100, -x / 100, isPlayArea, isTriggering, closestDistance, ppx, ppy, ppz, nnx, nny, nnz);
	px = -ppz * PicoSDK::Sensor::WToMScale;
	py = ppx * PicoSDK::Sensor::WToMScale;
	pz = ppy * PicoSDK::Sensor::WToMScale;
	nx = -nnz * PicoSDK::Sensor::WToMScale;
	ny = nnx * PicoSDK::Sensor::WToMScale;
	nz = nny * PicoSDK::Sensor::WToMScale;
	//UE_LOG(LogTemp, Log, TEXT("Pvr_UE BoundaryTestNode x %f y %f z %f isPlayArea %d istriggering %d closestDistance %f px %f py %f pz %f nx %f ny %f nz %f"), x, y, z, (int32)isPlayArea, (int32)isTriggering, closestDistance, px, py, pz, nx, ny, nz);
#endif
	return ret;
}

int32 PicoSDK::SeeThrough::BoundaryGetGeometry(TArray<FVector> &outPointsFloat, bool isPlayArea)
{
	int32 ret = 0;
	float * data = nullptr;
	outPointsFloat.Empty();
#if PLATFORM_ANDROID
	ret = PicoImport::PvrBoundaryGetGeometry(data, isPlayArea);
#endif
	//UE_LOG(LogTemp, Log, TEXT("Pvr_UE ret is %d isPlayArea is %d"), ret, (int32)isPlayArea);
	for (int i = 0; i < 3 * ret; i = i + 3)
	{
		outPointsFloat.Add(FVector(-data[i + 2] * PicoSDK::Sensor::WToMScale, data[i] * PicoSDK::Sensor::WToMScale, data[i + 1] * PicoSDK::Sensor::WToMScale));
		//UE_LOG(LogTemp, Log, TEXT("Pvr_UE ret is %d i is %d data is %f outPointsFloat %f "), ret, i, data[i], outPointsFloat[i]);
	}
	return ret;
}
void PicoSDK::SeeThrough::GetBoundaryDimensions(FVector &dimensions, bool isPlayArea)
{
#if PLATFORM_ANDROID
	 PicoImport::PvrGetBoundaryDimensions(dimensions.X, dimensions.Y, dimensions.Z, isPlayArea);
#endif
}
bool PicoSDK::SeeThrough::GetBoundaryVisible()
{
	bool ret = false;
#if PLATFORM_ANDROID
	ret = PicoImport::PvrGetBoundaryVisible();
#endif
	return ret;
}

void PicoSDK::SeeThrough::SetReinPosition()
{
#if PLATFORM_ANDROID
	if (FPicoJava::GetLeftConConnectState())
	{
		FQuat LOri = FQuat::Identity;
		FVector LPos = FVector::ZeroVector;
		FPicoJava::GetLeftControllerSensorData(LOri.X, LOri.Y, LOri.Z, LOri.W, LPos.X, LPos.Y, LPos.Z);
		if ((LOri.X == 0 && LOri.Y == 0 && LOri.Z == 0 && LOri.W == 0)||FPicoJava::GetControllerSensorStatus(0) != 1)
		{
			PicoImport::PvrSetReinPosition(0, 0, 0, 0, 0, 0, 0, 0, false, 0);
		}
		else
		{
			int32 LTri = FPicoJava::GetLeftControllerTriggerToBoundary();
			//UE_LOG(LogTemp,Log,TEXT("110900: PvrSetReinPosition Rotation =(%f,%f,%f,%f) Position = (%f,%f,%f) hand = 0, valid = 1, keyEvent = %d"), LOri.X, LOri.Y, LOri.Z, LOri.W, LPos.X, LPos.Y, LPos.Z, LTri);
			PicoImport::PvrSetReinPosition(LOri.X, LOri.Y, LOri.Z, LOri.W, LPos.X, LPos.Y, LPos.Z, 0, true, LTri);
		}	
	}
	else
	{
		PicoImport::PvrSetReinPosition(0, 0, 0, 0, 0, 0, 0, 0, false, 0);
	}

	if (FPicoJava::GetRightConConnectState())
	{
		FQuat ROri = FQuat::Identity;
		FVector RPos = FVector::ZeroVector;
		FPicoJava::GetRightControllerSensorData(ROri.X, ROri.Y, ROri.Z, ROri.W, RPos.X, RPos.Y, RPos.Z);
		if ((ROri.X == 0 && ROri.Y == 0 && ROri.Z == 0 && ROri.W == 0) || FPicoJava::GetControllerSensorStatus(1) != 1) 
		{
			PicoImport::PvrSetReinPosition(0, 0, 0, 0, 0, 0, 0, 1, false, 0);
		}
		else
		{
			int32 RTri = FPicoJava::GetRightControllerTriggerToBoundary();
			//UE_LOG(LogTemp,Log,TEXT("110900: PvrSetReinPosition Rotation =(%f,%f,%f,%f) Position = (%f,%f,%f) hand = 1, valid = 1, keyEvent = %d"), ROri.X, ROri.Y, ROri.Z, ROri.W, RPos.X, RPos.Y, RPos.Z, RTri);
			PicoImport::PvrSetReinPosition(ROri.X, ROri.Y, ROri.Z, ROri.W, RPos.X, RPos.Y, RPos.Z, 1, true, RTri);
		}
	}
	else
	{
		PicoImport::PvrSetReinPosition(0, 0, 0, 0, 0, 0, 0, 1, false, 0);
	}
#endif
}


void PicoSDK::SeeThrough::SetCameraImageRect(FIntPoint imageRect)
{
#if PLATFORM_ANDROID
	PicoImport::PvrSetBoundaryCameraImageRect(imageRect.X, imageRect.Y);
#endif
}

void PicoSDK::Sensor::GetWorldToMetersScale()
{
	if (IsInGameThread() && GWorld != nullptr)
	{
		PicoSDK::Sensor::WToMScale = GWorld->GetWorldSettings()->WorldToMeters;
	}
	// Default value, assume Unreal units are in centimeters
	PicoSDK::Sensor::WToMScale = 100.0f;
}

int32 PicoSDK::GetLoadControllerState()
{
	int32 NeedLoadController = 0;
	PicoImport::PvrGetIntConfig(PicoSDKConfig::GlobalIntConfigs::iCtrlModelLoadingPri, NeedLoadController);
	return NeedLoadController;		
}

#endif	