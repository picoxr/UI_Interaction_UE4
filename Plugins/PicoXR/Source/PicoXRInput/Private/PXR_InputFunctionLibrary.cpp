//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_InputFunctionLibrary.h"
#include "PXR_Input.h"
#include "PXR_Log.h"
#include "UObject/ConstructorHelpers.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#include "PxrApi.h"
#include "PxrInput.h"
#endif

FPICOXRInput* GetPICOXRInput()
{
    TArray<IMotionController*> MotionControllers = IModularFeatures::Get().GetModularFeatureImplementations<IMotionController>(IMotionController::GetModularFeatureName());
    for (auto MotionController : MotionControllers)
    {
        if (MotionController != nullptr && MotionController->GetMotionControllerDeviceTypeName() == FName(TEXT("PICOXRInput")))
        {
            return static_cast<FPICOXRInput*>(MotionController);
        }
    }
    return nullptr;
}

UDataTable* UPICOXRInputFunctionLibrary::PHFDataTable = nullptr;

UPICOXRInputFunctionLibrary::UPICOXRInputFunctionLibrary()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> DT(TEXT("DataTable'/PICOXR/Blueprint/PHFDataTable.PHFDataTable'"));
	PHFDataTable = DT.Object;
#if !PLATFORM_ANDROID
	if (PHFDataTable)
	{
		TArray<FString> PHFFiles;
		FString PHFFilesDir = FPaths::ProjectPluginsDir() / FString::Printf(TEXT("PICOXR/Content/Phf/"));
		IFileManager::Get().FindFiles(PHFFiles, *PHFFilesDir);

		PHFDataTable->EmptyTable();
		FString CSVString = "Name,PHFData\n";
		for (auto item : PHFFiles)
		{
			FString Content;
			FFileHelper::LoadFileToString(Content, *(FPaths::Combine(PHFFilesDir, item)));
			item.RemoveFromEnd(".phf");
			FPHFData Data;
			Data.PHFDataContent.data = Content;
			Data.PHFDataContent.size = Content.Len();
			PHFDataTable->AddRow(*item, Data);
		}
	}
#endif
}

IPXR_HandTracker* GetHandTracker()
{
    TArray<IPXR_HandTracker*> HandTrackers = IModularFeatures::Get().GetModularFeatureImplementations<IPXR_HandTracker>(IPXR_HandTracker::GetModularFeatureName());
    for (auto HandTracker : HandTrackers)
    {
        if (HandTracker != nullptr && HandTracker->GetHandTrackerDeviceTypeName() == FName(TEXT("PICOHandTracking")))
        {
            return HandTracker;
        }
    }
    return nullptr;
}

bool UPICOXRInputFunctionLibrary::PXR_GetControllerPower(EPICOXRControllerType ControllerType, int32& Power)
{
    FPICOXRInput* PICOXRInputInstence = GetPICOXRInput();
    if (PICOXRInputInstence)
    {
        Power = PICOXRInputInstence->UPxr_GetControllerPower((uint8_t)ControllerType);
        return true;
    }
    return false;
}

bool UPICOXRInputFunctionLibrary::PXR_GetControllerConnectionState(EPICOXRControllerType ControllerType, bool& Status)
{
    FPICOXRInput* Input =  GetPICOXRInput();
    if (Input)
    {
        if (ControllerType ==EPICOXRControllerType::LeftHand || ControllerType == EPICOXRControllerType::RightHand)
        {
            Status = Input->UPxr_GetControllerConnectState(static_cast<int32>(ControllerType));
		}
		else if (ControllerType == EPICOXRControllerType::G2Hand)
		{
			Status = Input->UPxr_GetControllerConnectState(0);
		}
		else
		{
			return false;
		}
        return true;
    }  
#if PLATFORM_WINDOWS
	Status = true;
#endif
	return false;
}

bool UPICOXRInputFunctionLibrary::PXR_GetMainControllerHandle( EPICOXRHandedness& Handedness)
{
    bool Ret = false;
    FPICOXRInput* Input =  GetPICOXRInput();
    if (Input)
    {
        int32 MainHandle = 0;
        Ret = Input->UPxr_GetControllerMainInputHandle(MainHandle);
        Handedness = MainHandle == 0? EPICOXRHandedness::LeftHand: EPICOXRHandedness::RightHand;
        return Ret;
    }
    return Ret;
}

bool UPICOXRInputFunctionLibrary::PXR_SetMainControllerHandle(EPICOXRHandedness Handedness)
{
	FPICOXRInput *PxrInput = GetPICOXRInput();
	if (PxrInput)
	{
		PxrInput->UPxr_SetControllerMainInputHandle(int32(Handedness));
		return true;
	}
	return false;
}

bool UPICOXRInputFunctionLibrary::PXR_GetControllerAngularVelocity(EPICOXRControllerType ControllerType,
                                                                          FVector& AngularVelocity)
{
#if PLATFORM_ANDROID
    PxrControllerTracking Tracking;
    uint32_t Hand;

    if (ControllerType == EPICOXRControllerType::LeftHand) 
    {
        Hand = EPICOXRControllerHandness::LeftController;
    } 
    else 
    {
        Hand = EPICOXRControllerHandness::RightController;
    }

    float HeadSensorData[7] = {0};
    Pxr_GetControllerTrackingState(Hand, 0, HeadSensorData, &Tracking);

    float Data[3] = {0.0f};
    Data[0] = Tracking.localControllerPose.angularVelocity.x;
    Data[1] = Tracking.localControllerPose.angularVelocity.y;
    Data[2] = Tracking.localControllerPose.angularVelocity.z;

    PXR_LOGD(PxrUnrealFunctionLibrary,"Pxr_GetControllerAngularVelocityState %f,%f,%f",Data[0],Data[1],Data[2]);
    AngularVelocity = FVector(Data[0],Data[1],Data[2]);
    AngularVelocity = FVector(-AngularVelocity.Z , AngularVelocity.X , AngularVelocity.Y);
    return true;
#endif
    return false;
}

bool UPICOXRInputFunctionLibrary::PXR_GetControllerAcceleration(EPICOXRControllerType ControllerType,FVector& Acceleration)
{
#if PLATFORM_ANDROID
    PxrControllerTracking Tracking;
    uint32_t Hand;

    if (ControllerType == EPICOXRControllerType::LeftHand) {
        Hand = EPICOXRControllerHandness::LeftController;
    } else {
        Hand = EPICOXRControllerHandness::RightController;
    }
	float HeadSensorData[7] = { 0 };
	Pxr_GetControllerTrackingState(Hand, 0, HeadSensorData, &Tracking);

    float Data[3] = {0.0f};
    Data[0] = Tracking.localControllerPose.angularAcceleration.x;
    Data[1] = Tracking.localControllerPose.angularAcceleration.y;
    Data[2] = Tracking.localControllerPose.angularAcceleration.z;

    PXR_LOGD(PxrUnrealFunctionLibrary,"Pxr_GetControllerAccelerationState %f,%f,%f",Data[0],Data[1],Data[2]);
    Acceleration = FVector(Data[0],Data[1],Data[2]);
    Acceleration = FVector(-Acceleration.Z , Acceleration.X , Acceleration.Y);
    return true;
#endif
    return false;
}

bool UPICOXRInputFunctionLibrary::PXR_GetControllerLinearVelocity(EPICOXRControllerType ControllerType,
    FVector& LinearVelocity)
{
#if PLATFORM_ANDROID
    PxrControllerTracking Tracking;
    uint32_t Hand;

    if (ControllerType == EPICOXRControllerType::LeftHand) {
        Hand = EPICOXRControllerHandness::LeftController;
    } else {
        Hand = EPICOXRControllerHandness::RightController;
    }
	float HeadSensorData[7] = { 0 };
	Pxr_GetControllerTrackingState(Hand, 0, HeadSensorData, &Tracking);

    float Data[3] = {0.0f};
    Data[0] = Tracking.localControllerPose.linearVelocity.x;
    Data[1] = Tracking.localControllerPose.linearVelocity.y;
    Data[2] = Tracking.localControllerPose.linearVelocity.z;

    PXR_LOGD(PxrUnrealFunctionLibrary,"Pxr_GetControllerLinearVelocityState %f,%f,%f",Data[0],Data[1],Data[2]);
    LinearVelocity = FVector(Data[0],Data[1],Data[2]);
    LinearVelocity = FVector(-LinearVelocity.Z , LinearVelocity.X , LinearVelocity.Y);
    return true;
#endif
    return false;
}

bool UPICOXRInputFunctionLibrary::PXR_VibrateController(EPICOXRControllerType ControllerType,float Strength, int Time)
{
#if PLATFORM_ANDROID
    if (Pxr_SetControllerVibration((uint32_t)ControllerType, Strength, Time) == 0)
    {
        return true;
    }
#endif
    return false;
}

void UPICOXRInputFunctionLibrary::PXR_GetControllerDeviceType(EPICOXRControllerDeviceType& OutControllerType)
{
	int32 ControllerType = 0;
#if PLATFORM_ANDROID
	PxrControllerCapability Cap;
	Pxr_GetControllerCapabilities(PXR_CONTROLLER_LEFT, &Cap);
	ControllerType = Cap.type;
#endif
#if PLATFORM_WINDOWS
	ControllerType = 6;
#endif
	OutControllerType = static_cast<EPICOXRControllerDeviceType>(ControllerType);
}

void UPICOXRInputFunctionLibrary::PXR_SetControllerArmModelParam(EPICOXRControllerType Controller,
    EPICOXRHandedness Handness, EPICOXRArmModelJoint ArmJoint, EPICOXRGazeBehavior GazeType, float ElbowHeight,
    float ElbowDepth, float PointerTiltAngle)
{
}

void UPICOXRInputFunctionLibrary::PXR_GetControllerArmModelParam(EPICOXRControllerType Controller,
    EPICOXRHandedness& Handness, EPICOXRArmModelJoint& ArmJoint, EPICOXRGazeBehavior& GazeType, float& ElbowHeight,
    float& ElbowDepth, float& PointerTiltAngle)
{
}

bool UPICOXRInputFunctionLibrary::PXR_GetHandedness(EPICOXRHandedness &Handedness)
{
	bool Ret = false;
	FPICOXRInput* PxrInput = GetPICOXRInput();
	if (PxrInput)
	{
		int32 MainHandle = 0;
		Ret = PxrInput->UPxr_GetControllerMainInputHandle(MainHandle);
        Handedness = MainHandle == 0 ? EPICOXRHandedness::LeftHand : EPICOXRHandedness::RightHand;
		return Ret;
	}
	return Ret;
}

bool UPICOXRInputFunctionLibrary::PXR_GetControllerEnableHomekey()
{
    FPICOXRInput* PxrInput = GetPICOXRInput();
    if (PxrInput)
    {
       return PxrInput->UPxr_GetControllerEnableHomeKey();
    }
    return false;
}

void UPICOXRInputFunctionLibrary::PXR_SetControllerOriginOffset(EPICOXRControllerType Controller, FVector Offset)
{
    if (Controller == EPICOXRControllerType::LeftHand)
    {
        FPICOXRInput::OriginOffsetL = Offset;
    }
    else if (Controller == EPICOXRControllerType::RightHand)
    {
        FPICOXRInput::OriginOffsetR = Offset;
    }
}

bool UPICOXRInputFunctionLibrary::PXR_GetControllerPredictedLocationAndRotation(EControllerHand DeviceHand, float PredictedTime, FVector& OutLocation, FRotator& OutRotation)
{
	bool Result = false;
    FVector PredictedLocation; FRotator PredictedRotation;
    PredictedLocation = FVector::ZeroVector;
    PredictedRotation = FRotator::ZeroRotator;
    FPICOXRInput* PxrInput = GetPICOXRInput();
    if (PxrInput)
	{
		Result = PxrInput->GetPredictedLocationAndRotation(DeviceHand, PredictedTime, PredictedRotation, PredictedLocation);
    }
    OutLocation = PredictedLocation;
    OutRotation = PredictedRotation;
    return Result;
}
int UPICOXRInputFunctionLibrary::PXR_StartControllerVCMotor(FString file, EPICOXRVibrateController slot)
{
    //0-Left And Right 1-Left 2-Right 3-Left And Right
    //1-Reversal 0-No Reversal
    int state = 0;
#if PLATFORM_ANDROID
    int SdkVersion = 0;
    Pxr_GetConfigInt(PXR_API_VERSION, &SdkVersion);
    if (SdkVersion >= 0x2000308) {
        state = Pxr_StartControllerVCMotor(TCHAR_TO_UTF8(*file), static_cast<int>(slot));
    }
#endif
    return state;
}

int UPICOXRInputFunctionLibrary::PXR_SetControllerAmp(float mode) {
    int state = 0;
#if PLATFORM_ANDROID
    int SdkVersion = 0;
    Pxr_GetConfigInt(PXR_API_VERSION, &SdkVersion);
    if (SdkVersion >= 0x2000308) {
        state = Pxr_SetControllerAmp(mode);
    }
#endif
    return state;
}

int UPICOXRInputFunctionLibrary::PXR_StopControllerVCMotor(int SourceId) {
    int state = 0;
#if PLATFORM_ANDROID
    int SdkVersion = 0;
    Pxr_GetConfigInt(PXR_API_VERSION, &SdkVersion);
    if (SdkVersion >= 0x2000308) {
        state = Pxr_StopControllerVCMotor(SourceId);
    }
#endif
    return state;
}

int UPICOXRInputFunctionLibrary::PXR_SetControllerVibrationEvent(int deviceID, int frequency, float strength, int time) {
    int state = 0;
#if PLATFORM_ANDROID
    int SdkVersion = 0;
    Pxr_GetConfigInt(PXR_API_VERSION, &SdkVersion);
    if (SdkVersion >= 0x2000305) {
        PXR_LOGD(PxrUnreal, "PXR_SetControllerVibrationEvent :%d", deviceID);
        state = Pxr_SetControllerVibrationEvent((uint32)deviceID, frequency, strength, time);
    }
#endif
    return state;
}


Audio::FSampleBuffer tSampleBuffer;


int UPICOXRInputFunctionLibrary::PXR_StartVibrateBySharem(USoundWave* InSoundWave, EPICOXRVibrateController slot, EPICOXRChannelFlip slotConfig,int& SourceId) {
    int state = 0;
    if (InSoundWave == nullptr) {
        PXR_LOGI(PxrUnreal, "PXR_StartVibrateBySharem : InSoundWave is nullptr");
        return state;
    }
#if PLATFORM_ANDROID
    int SdkVersion = 0;
    Pxr_GetConfigInt(PXR_API_VERSION, &SdkVersion);

    if (SdkVersion >= 0x2000308) {
        int32 delaytag;
        int32 buffersize;
        int32 sampleRate;
        int32 channelMask;
        int32 bitrate = 16;
        float OutSampleDuration;
        uint8* data = nullptr;
        PxrVibrate_config parameter;
        FString TempString;
        int Value = 1024;
        if (GConfig->GetString(FPlatformProperties::GetRuntimeSettingsClassName(), TEXT("AudioCallbackBufferFrameSize"), TempString, GEngineIni))
        {
            Value = FCString::Atoi(*TempString);
            PXR_LOGI(PxrUnreal, "AudioCallbackBufferFrameSize = %d", Value);
        }

        Audio::FSoundWavePCMLoader SoundWaveLoader;
        if (InSoundWave)
        {
            TFunction<void(const USoundWave* SoundWave, const Audio::FSampleBuffer& SampleBuffer)> OnLoaded
                = [](const USoundWave* SoundWave, const Audio::FSampleBuffer& SampleBuffer)
            {
                tSampleBuffer = SampleBuffer;
            };
#if ENGINE_MINOR_VERSION>24
            SoundWaveLoader.LoadSoundWave(InSoundWave, MoveTemp(OnLoaded), true);
#else
            SoundWaveLoader.LoadSoundWave(InSoundWave, MoveTemp(OnLoaded));
#endif
            
        }
        data = InSoundWave->RawPCMData;
        buffersize = tSampleBuffer.GetNumSamples() * tSampleBuffer.GetNumChannels();
        //OutNumFrames = tSampleBuffer.GetNumFrames();
        channelMask = tSampleBuffer.GetNumChannels();
        sampleRate = tSampleBuffer.GetSampleRate();
        OutSampleDuration = tSampleBuffer.GetSampleDuration();
        parameter.slot = static_cast<int>(slot);
        parameter.buffersize = static_cast<uint64>(buffersize);
        parameter.sampleRate = sampleRate;
        parameter.channelCounts = channelMask;
        parameter.bitrate = bitrate;
        parameter.reversal = static_cast<int>(slotConfig);
        parameter.isCache = 0;
        state = Pxr_StartVibrateBySharemU(data, &parameter, &SourceId);
    }
#endif
    return state;
}
int UPICOXRInputFunctionLibrary::PXR_SaveVibrateByCache(USoundWave* InSoundWave, EPICOXRVibrateController slot, EPICOXRChannelFlip slotConfig, EPICOXRCacheConfig enableV, int& SourceId) {
    int state = 0;
    if (InSoundWave == nullptr) {
        PXR_LOGI(PxrUnreal, "PXR_SaveVibrateByCache : InSoundWave is nullptr");
        return state;
    }
#if PLATFORM_ANDROID
    int SdkVersion = 0;
    Pxr_GetConfigInt(PXR_API_VERSION, &SdkVersion);

    if (SdkVersion >= 0x2000308) {
        int32 delaytag;
        int32 buffersize;
        int32 sampleRate;
        int32 channelMask;
        int32 bitrate = 16;
        float OutSampleDuration;
        uint8* data = nullptr;
        PxrVibrate_config parameter;
        FString TempString;
        int Value = 1024;
        if (GConfig->GetString(FPlatformProperties::GetRuntimeSettingsClassName(), TEXT("AudioCallbackBufferFrameSize"), TempString, GEngineIni))
        {
            Value = FCString::Atoi(*TempString);
            PXR_LOGI(PxrUnreal, "AudioCallbackBufferFrameSize = %d", Value);
        }

        Audio::FSoundWavePCMLoader SoundWaveLoader;
        if (InSoundWave)
        {
            TFunction<void(const USoundWave* SoundWave, const Audio::FSampleBuffer& SampleBuffer)> OnLoaded
                = [](const USoundWave* SoundWave, const Audio::FSampleBuffer& SampleBuffer)
            {
                tSampleBuffer = SampleBuffer;
            };
#if ENGINE_MINOR_VERSION>24
            SoundWaveLoader.LoadSoundWave(InSoundWave, MoveTemp(OnLoaded), true);
#else
            SoundWaveLoader.LoadSoundWave(InSoundWave, MoveTemp(OnLoaded));
#endif

        }
        data = InSoundWave->RawPCMData;
        PXR_LOGI(PxrUnreal, "AudioCallbackBufferFrameSize = %d", data[0]);
        buffersize = tSampleBuffer.GetNumSamples() * tSampleBuffer.GetNumChannels();
        //OutNumFrames = tSampleBuffer.GetNumFrames();
        channelMask = tSampleBuffer.GetNumChannels();
        sampleRate = tSampleBuffer.GetSampleRate();
        OutSampleDuration = tSampleBuffer.GetSampleDuration();
        parameter.slot = static_cast<int>(slot);
        parameter.buffersize = static_cast<uint64>(buffersize);
        parameter.sampleRate = sampleRate;
        parameter.channelCounts = channelMask;
        parameter.bitrate = bitrate;
        parameter.reversal = static_cast<int>(slotConfig);
        int isVibrate = 0;
        if (enableV == EPICOXRCacheConfig::CacheAndVibrate)
        {
            isVibrate = 1;
        }
        else if(enableV == EPICOXRCacheConfig::CacheNoVibrate)
        {
            isVibrate = 2;
        }
        parameter.isCache = isVibrate;
        state = Pxr_StartVibrateBySharemU(data, &parameter, &SourceId);
    }
#endif
    return state;
}

int UPICOXRInputFunctionLibrary::PXR_StartVibrateByCache(int SourceId) {
    int state = 0;
#if PLATFORM_ANDROID
    int SdkVersion = 0;
    Pxr_GetConfigInt(PXR_API_VERSION, &SdkVersion);
    if (SdkVersion >= 0x2000308) {
        return Pxr_StartVibrateByCache(SourceId);
    }
#endif
    return 0;
}

int UPICOXRInputFunctionLibrary::PXR_ClearVibrateByCache(int SourceId) {
    int state = 0;
#if PLATFORM_ANDROID
    int SdkVersion = 0;
    Pxr_GetConfigInt(PXR_API_VERSION, &SdkVersion);
    if (SdkVersion >= 0x2000308) {
        return Pxr_ClearVibrateByCache(SourceId);
    }
#endif
    return 0;
}

FQuat UPICOXRInputFunctionLibrary::GetBoneRotation(EPICOXRHandType SkeletonType, EPICOXRHandJoint Key)
{
    IPXR_HandTracker* HandTracker=GetHandTracker();
    if (HandTracker)
    {
        return HandTracker->GetBoneRotation(SkeletonType,Key);
    }
    return FQuat();
}

FVector UPICOXRInputFunctionLibrary::GetBoneLocation(EPICOXRHandType DeviceHand, EPICOXRHandJoint Key)
{
    IPXR_HandTracker* HandTracker=GetHandTracker();
    if (HandTracker)
    {
        return HandTracker->GetBoneLocation(DeviceHand,Key);
    }
    return FVector();
}

float UPICOXRInputFunctionLibrary::GetBoneRadii(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint Key)
{
    IPXR_HandTracker* HandTracker=GetHandTracker();
    if (HandTracker)
    {
        return HandTracker->GetBoneRadii(DeviceHand,Key);
    }
    return 0.f;
}

bool UPICOXRInputFunctionLibrary::IsBoneOrientationValid(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint Key)
{
    IPXR_HandTracker* HandTracker=GetHandTracker();
    if (HandTracker)
    {
        return HandTracker->IsBoneOrientationValid(DeviceHand,Key);
    }
    return false;
}

bool UPICOXRInputFunctionLibrary::IsBonePositionValid(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint Key)
{
    IPXR_HandTracker* HandTracker=GetHandTracker();
    if (HandTracker)
    {
        return HandTracker->IsBonePositionValid(DeviceHand,Key);
    }
    return false;
}

bool UPICOXRInputFunctionLibrary::IsBoneOrientationTracked(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint Key)
{
    IPXR_HandTracker* HandTracker=GetHandTracker();
    if (HandTracker)
    {
        return HandTracker->IsBoneOrientationTracked(DeviceHand,Key);
    }
    return false;
}

bool UPICOXRInputFunctionLibrary::IsBonePositionTracked(const EPICOXRHandType DeviceHand, const EPICOXRHandJoint Key)
{
    IPXR_HandTracker* HandTracker=GetHandTracker();
    if (HandTracker)
    {
        return HandTracker->IsBonePositionTracked(DeviceHand,Key);
    }
    return false;
}

FTransform UPICOXRInputFunctionLibrary::GetHandRootPose(EPICOXRHandType SkeletonType)
{
    IPXR_HandTracker* HandTracker=GetHandTracker();
    if (HandTracker)
    {
        return HandTracker->GetHandRootPose(SkeletonType);
    }
    return FTransform();
}

FTransform UPICOXRInputFunctionLibrary::GetPointerPose(const EPICOXRHandType DeviceHand)
{
    IPXR_HandTracker* HandTracker=GetHandTracker();
    if (HandTracker)
    {
        return HandTracker->GetPointerPose(DeviceHand);
    }
    return FTransform();
}

bool UPICOXRInputFunctionLibrary::IsHandTracked(const EPICOXRHandType DeviceHand)
{
    IPXR_HandTracker* HandTracker=GetHandTracker();
    if (HandTracker)
    {
        return HandTracker->IsHandTracked(DeviceHand);
    }
    return false;
}

bool UPICOXRInputFunctionLibrary::IsAimValid(const EPICOXRHandType DeviceHand)
{
    IPXR_HandTracker* HandTracker=GetHandTracker();
    if (HandTracker)
    {
        return HandTracker->IsAimValid(DeviceHand);
    }
    return false;
}

bool UPICOXRInputFunctionLibrary::IsAimRayTouchedValid(const EPICOXRHandType DeviceHand)
{
    IPXR_HandTracker* HandTracker=GetHandTracker();
    if (HandTracker)
    {
        return HandTracker->IsAimRayTouchedValid(DeviceHand);
    }
    return false;
}

bool UPICOXRInputFunctionLibrary::IsSystemGestureInProgress(const EPICOXRHandType DeviceHand)
{
    IPXR_HandTracker* HandTracker=GetHandTracker();
    if (HandTracker)
    {
        return HandTracker->IsSystemGestureInProgress(DeviceHand);
    }
    return false;
}

bool UPICOXRInputFunctionLibrary::IsDominantHand(const EPICOXRHandType DeviceHand)
{
    IPXR_HandTracker* HandTracker=GetHandTracker();
    if (HandTracker)
    {
        return HandTracker->IsDominantHand(DeviceHand);
    }
    return false;
}

bool UPICOXRInputFunctionLibrary::IsMenuPressed(const EPICOXRHandType DeviceHand)
{
    IPXR_HandTracker* HandTracker=GetHandTracker();
    if (HandTracker)
    {
        return HandTracker->IsMenuPressed(DeviceHand);
    }
    return false;
}

EPICOXRHandTrackingConfidence UPICOXRInputFunctionLibrary::GetTrackingConfidence(const EPICOXRHandType DeviceHand)
{
    IPXR_HandTracker* HandTracker=GetHandTracker();
    if (HandTracker)
    {
        return HandTracker->GetTrackingConfidence(DeviceHand);
    }
    return EPICOXRHandTrackingConfidence::Low;
}

float UPICOXRInputFunctionLibrary::GetHandScale(const EPICOXRHandType DeviceHand)
{
    IPXR_HandTracker* HandTracker=GetHandTracker();
    if (HandTracker)
    {
        return HandTracker->GetHandScale(DeviceHand);
    }
    return 1.f;
}

float UPICOXRInputFunctionLibrary::GetClickStrength(const EPICOXRHandType DeviceHand)
{
    IPXR_HandTracker* HandTracker=GetHandTracker();
    if (HandTracker)
    {
        return HandTracker->GetClickStrength(DeviceHand);
    }
    return 0.f;
}

bool UPICOXRInputFunctionLibrary::IsHandTrackingEnabled()
{
    const UPICOXRSettings* Settings = GetDefault<UPICOXRSettings>();
    IPXR_HandTracker* HandTracker=GetHandTracker();

    if (Settings&&HandTracker&&Settings->HandTrackingSupport != EPICOXRHandTrackingSupport::ControllersOnly)
    {
        return GetHandTracker()->IsHandTrackingStateValid();
    }
    return false;
}

EPICOXRHandType UPICOXRInputFunctionLibrary::GetDominantHand()
{
    EPICOXRHandType DominantHand = EPICOXRHandType::None;
    if (IsDominantHand(EPICOXRHandType::HandLeft))
    {
        DominantHand = EPICOXRHandType::HandLeft;
    }
    else if (IsDominantHand(EPICOXRHandType::HandRight))
    {
        DominantHand = EPICOXRHandType::HandRight;
    }
    return DominantHand;
}

bool UPICOXRInputFunctionLibrary::GetFingerIsPinching(const EPICOXRHandType DeviceHand, EPICOXRHandFinger Finger)
{
    IPXR_HandTracker* HandTracker=GetHandTracker();
    if (HandTracker)
    {
        return HandTracker->GetFingerIsPinching(DeviceHand,Finger);
    }
    return false;
}

float UPICOXRInputFunctionLibrary::GetFingerPinchStrength(const EPICOXRHandType DeviceHand, EPICOXRHandFinger Finger)
{
    IPXR_HandTracker* HandTracker=GetHandTracker();
    if (HandTracker)
    {
        return HandTracker->GetFingerPinchStrength(DeviceHand,Finger);
    }
    return 0.f;
}

EPICOXRActiveInputDevice UPICOXRInputFunctionLibrary::GetActiveInputDevice()
{
    IPXR_HandTracker* HandTracker=GetHandTracker();
    if (HandTracker)
    {
        return HandTracker->GetActiveInputDevice();
    }
    return EPICOXRActiveInputDevice::NoneActive;
}


int UPICOXRInputFunctionLibrary::PXR_StartVibrateByPHF(FName DataName,EPICOXRVibrateController slot, EPICOXRChannelFlip slotConfig,float ampValue ,int& SourceID)
{
	FString ContextString = TEXT("UPICOXRInputFunctionLibrary::PXR_StartVibrateByPHF");
	SourceID = 0;
	UDataTable* Table = PHFDataTable;
	if (Table)
	{
		FPHFData* PHF_ST = Table->FindRow<FPHFData>(DataName, ContextString);
		if (PHF_ST)
		{
#if PLATFORM_ANDROID
			if (PHF_ST->PHFDataContent.size != 0)
			{
				int SdkVersion = 0;
				Pxr_GetConfigInt(PXR_API_VERSION, &SdkVersion);
				if (SdkVersion >= 0x2000308)
				{
					int result = 0;
					PxrVibrate_info vibrateInfo;
					vibrateInfo.slot = (uint32)(static_cast<int>(slot));
					vibrateInfo.reversal = (uint32)(static_cast<int>(slotConfig));
					vibrateInfo.amp = ampValue;
					int ID;
					result = Pxr_StartVibrateByPHF(TCHAR_TO_UTF8(*(PHF_ST->PHFDataContent.data)), PHF_ST->PHFDataContent.size, &ID, &vibrateInfo);
					SourceID = ID;
					return result;
				}
			}
#endif
		}
	}
	return 0;
}

int UPICOXRInputFunctionLibrary::PXR_PauseVibrate(int SourceID)
{
#if PLATFORM_ANDROID
	int SdkVersion = 0;
	Pxr_GetConfigInt(PXR_API_VERSION, &SdkVersion);
	if (SdkVersion >= 0x2000308)
	{
		return Pxr_PauseVibrate(SourceID);
	}
#endif
	return 0;
}

int UPICOXRInputFunctionLibrary::PXR_ResumeVibrate(int SourceID)
{
#if PLATFORM_ANDROID
	int SdkVersion = 0;
	Pxr_GetConfigInt(PXR_API_VERSION, &SdkVersion);
	if (SdkVersion >= 0x2000308)
	{
		return Pxr_ResumeVibrate(SourceID);
	}
#endif
	return 0;
}

void UPICOXRInputFunctionLibrary::PXR_GetVibrateDelayTime(FString &data) {
    int length = 10;
    data = nullptr;
#if PLATFORM_ANDROID
    int SdkVersion = 0;
    Pxr_GetConfigInt(PXR_API_VERSION, &SdkVersion);
    if (SdkVersion >= 0x2000305) {
        data = Pxr_GetVibrateDelayTime(&length);
    }
#endif
}
int UPICOXRInputFunctionLibrary::PXR_SetControllerEnableKey(bool isEnable, EPxrControllerKeyMap Key) {
#if PLATFORM_ANDROID
    PxrControllerKeyMap PxrKey = static_cast<PxrControllerKeyMap>(Key);
    return Pxr_SetControllerEnableKey(isEnable, PxrKey);
#endif
    return 0;
}

int UPICOXRInputFunctionLibrary::PXR_UpdateVibrateParams(int SourceID, EPICOXRVibrateController slot, EPICOXRChannelFlip slotConfig, float AmpValue) {
#if PLATFORM_ANDROID
    int SdkVersion = 0;
    Pxr_GetConfigInt(PXR_API_VERSION, &SdkVersion);
    if (SdkVersion >= 0x2000308)
    {
        PxrVibrate_info vibrateInfo;
        vibrateInfo.slot = (uint32)(static_cast<int>(slot));
        vibrateInfo.reversal = (uint32)(static_cast<int>(slotConfig));
        vibrateInfo.amp = AmpValue;
        return Pxr_UpdateVibrateParams(SourceID, &vibrateInfo);
    }
#endif
    return 0;
}
