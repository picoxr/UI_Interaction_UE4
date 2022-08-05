//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "CoreMinimal.h"
#include <array>
#include "HeadMountedDisplayTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PXR_HMDFunctionLibrary.generated.h"

class UTexture2D;

/* Boundary boundary types*/
UENUM(BlueprintType)
enum class EPicoXRBoundaryType : uint8
{
	Outer	    UMETA(DisplayName = "The Outer Boundary"),
    PlayArea	UMETA(DisplayName = "The Play Area Boundary"),
};

UENUM(BlueprintType)
enum class EPicoXRBoundaryState :uint8
{
	GobackDialog,
	ToofarDialog,
	LostDialog,
	LostNoReason,
	LostCamera,
	LostHighLight,
	LostLowLight,
	LostLowFeatureCount,
	LostReLocation,
	LostInitialization,
	LostNoCamera,
	LostNoIMU,
	LostIMUJitter,
	LostUnknown,
	NothingDialog = 111,
	LostNoDialog = 112
};

UENUM(BlueprintType)
enum class EPicoXRTrackedDeviceType : uint8
{
	None    UMETA(DisplayName = "No Devices"),
    HMD     UMETA(DisplayName = "HMD"),
    LTouch	UMETA(DisplayName = "Left Hand"),
    RTouch	UMETA(DisplayName = "Right Hand"),
    Touch	UMETA(DisplayName = "All Hands"),
    All	    UMETA(DisplayName = "All Devices")
};

UENUM(BlueprintType)
enum class EPicoXRNodeType : uint8
{
	LeftHand,
    RightHand,
    Head
};

UENUM(BlueprintType)
enum class EPicoXRCameraType :uint8
{
	Left   UMETA(DisplayName = "Left Camera"),
    Right  UMETA(DisplayName = "Right Camera")
};

UENUM(BlueprintType)
enum class EPicoXRFoveationLevel :uint8 
{
	Low,
    Medium,
    High,
	TopHigh
};

USTRUCT(BlueprintType)
struct FPxrSensorState {
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
		int status;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
		FQuat poseQuat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
		FVector poseVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
		FQuat globalPoseQuat;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
		FVector globalPoseVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
		FVector angularVelocity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
		FVector linearVelocity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
		FVector angularAcceleration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
		FVector linearAcceleration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRSystemAPI")
		int poseTimeStampNs;
};

USTRUCT(BlueprintType, meta = (DisplayName = "PicoXREyeTrackingData"))
struct FPicoXREyeTrackingData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoXREyeTrackingData")
		int32  LeftEyePoseStatus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoXREyeTrackingData")
		int32  RightEyePoseStatus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoXREyeTrackingData")
		int32  CombinedEyePoseStatus;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoXREyeTrackingData")
		FVector  LeftEyeGazePoint;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoXREyeTrackingData")
		FVector  RightEyeGazePoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoXREyeTrackingData")
		FVector  CombinedEyeGazePoint;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoXREyeTrackingData")
		FVector  LeftEyeGazeVector;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoXREyeTrackingData")
		FVector  RightEyeGazeVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoXREyeTrackingData")
		FVector  CombinedEyeGazeVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoXREyeTrackingData")
		float  LeftEyeOpenness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoXREyeTrackingData")
		float  RightEyeOpenness;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoXREyeTrackingData")
		float  LeftEyePupilDilation;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoXREyeTrackingData")
		float  RightEyePupilDilation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoXREyeTrackingData")
		FVector   LeftEyePositionGuide;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoXREyeTrackingData")
		FVector   RightEyePositionGuide;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoXREyeTrackingData")
		FVector   FoveatedGazeDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoXREyeTrackingData")
		int32     FoveatedGazeTrackingState;
};

DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoXRIPDChangedDelegate, float, Ipd);
UCLASS()
class PICOXRHMD_API UPicoXRHMDFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	static FPicoXRIPDChangedDelegate PicoXRIPDChangedCallback;

	UPicoXRHMDFunctionLibrary();

	static class FPicoXRHMD* PicoXRHMD;
	static FPicoXRHMD* GetPicoXRHMD();
	/**
	* Get HMD devices current orientation.
	* @return  devices current orientation.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
        static FQuat PXR_GetCurrentOrientation();

	/**
	* Get HMD devices current position.
	* @return  devices current position.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
        static FVector PXR_GetCurrentPosition();

	/**
	* Gets whether the device supports position tracking
	* @return  true: Tracking position(6Dof),false: Can not tracking position(3Dof).
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
        static bool PXR_DoesSupportPositionalTracking();

	/**
	* Get HMD devices angular velocity.
	* @return  devices angular velocity.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static FVector PXR_GetAngularVelocity();

	/**
	* Get HMD devices acceleration.
	* @return  devices acceleration.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static FVector PXR_GetAcceleration();

	/**
	* Get HMD devices velocity.
	* @return  devices velocity.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static FVector PXR_GetVelocity();

	/**
	* Get HMD devices angular acceleration.
	* @return  devices angular acceleration.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static FVector PXR_GetAngularAcceleration();

	/**
	* Detect whether the user is wearing the HMD
	* @return
	* EHMDWornState::Worn if we detect that the user is wearing the HMD,
	* EHMDWornState::NotWorn if we detect the user is not wearing the HMD,
	* EHMDWornState::Unknown if we cannot detect the state.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
        static EHMDWornState::Type PXR_GetHMDWornState();

	/**
	* Reset HMD Position and Orientation.
	* @return true: reset HMD sensor Succeed, false :reset HMD sensor Failed.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
        static bool PXR_ResetHMDSensor();
	
	/**
	* Get device FieldOfView(Fov).
	* @param HFOVInDegrees    (out) Horizontal FOV.
	* @param VFOVInDegrees    (out) Vertical FOV.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
        static bool PXR_GetFieldOfView(float& HFOVInDegrees, float& VFOVInDegrees);

	/**
	* Get device vertical Fov.
	* @param VFOVInDegrees    (out) Vertical FOV.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static void PXR_GetVFov(float &VFOVInDegrees);

	/**
	* Get device horizontal Fov.
	* @param HFOVInDegrees    (out) Horizontal FOV.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static void PXR_GetHFov(float &HFOVInDegrees);
	
	/**
	* Get pupil distance of the current device.
	* @return Current devices IPD.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
        static float PXR_GetIPD();

	/**
	* Set IPD changed delegate.
	* @param OnPicoXRIPDChanged  (In) FPicoXRIPDChangedDelegate.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static void PXR_IPDChangedDelegates(FPicoXRIPDChangedDelegate OnPicoXRIPDChanged);

	/**
	* Get event manager.
	* @return UPicoXREventManager class reference.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
    static class UPicoXREventManager* PXR_GetEventManager();

	/**
    * Get device series number.
    * @return device series number.
    */
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static FString PXR_GetDeviceModel();

	/**
	* Get device display frequency.
	* @return device display frequency.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
    static float PXR_GetCurrentDisplayFrequency();

	/**
	* Set CPU GPU level.
	* @param CPULevel   (in) Target CPU level.
	* @param GPULevel   (in) Target GPU level.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static void PXR_SetCPUAndGPULevels(int32 CPULevel, int32 GPULevel);

	/**
	* Get CPU GPU level.
	* @param CPULevel   (out) Target CPU level.
	* @param GPULevel   (out) Target GPU level.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
        static void PXR_GetCPUAndGPULevels(int32 &CPULevel, int32 &GPULevel);

	/**
	* Get system display frequency.
	* @return system display frequency.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static float PXR_GetSystemDisplayFrequency();

	/**
	* Set system display frequency.
	* @param Rate    (In) Display frequency 72/90/120.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static void PXR_SetSystemDisplayFrequency(float Rate);

	/**
	* Set eye buffer and overlay color space.
	* @param ColorScale         (In) Color scale.
	* @param ColorOffset        (In) Color offset.
	* @param bApplyToAllLayers  (In) If apply to all Layers,default false.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static void PXR_SetColorScaleAndOffset(FLinearColor ColorScale, FLinearColor ColorOffset, bool bApplyToAllLayers = false);

	/**
	* Returns true, if the app has focus.
	*/
	UFUNCTION(BlueprintPure, Category = "PXR|PXRHMD")
		static bool GetFocusState();

#pragma region Boundary
	static class UPicoXRBoundarySystem* GetBoundarySystemInterface();
	/**
	* Whether an effective Boundary exists
	* @return true:Exist,false: No exit.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static bool PXR_GetBoundaryConfigured();

	/**
	* Gets whether Boundary is enabled or not
	* @return true:Boundary is enabled,false: Boundary is not enabled.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static bool PXR_GetBoundaryEnabled();

	/**
	* Gets whether Boundary is resident.
	* @param NewVisible:Target visible state.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static void PXR_SetBoundaryVisible(bool NewVisible);

	/**
	* Gets whether Boundary is resident.
	* @return true:Boundary is resident,false: Boundary is not resident.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static bool PXR_GetBoundaryVisible();

	/**
	* Get the intersection result between a tracked device (HMD or controllers) and a Boundary boundary
	* @param DeviceType             (in) Tracked Device type to test against Boundary 
	* @param BoundaryType			(in) An enum representing the boundary type requested, either Outer Boundary (exact Boundary bounds) or PlayArea (rectangle inside the Outer Boundary)
	* @param IsTriggering           (out) The intersection result between a tracked device (HMD or controllers) and a Boundary 
	* @param ClosestDistance        (out) The closest distance between a tracked device (HMD or controllers) and a Boundary
	* @param ClosestPoint           (out) The closest point on surface corresponding to specified boundary 
	* @param ClosestPointNormal     (out) Normal of closest point
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static bool PXR_BoundaryTestNode(EPicoXRNodeType DeviceType, EPicoXRBoundaryType BoundaryType, bool &IsTriggering, float &ClosestDistance, FVector &ClosestPoint, FVector &ClosestPointNormal);

	/**
	* Get the intersection result between a UE4 coordinate and a Boundary boundary
	* @param Point					(in) Point in UE space to test against Boundary boundaries
	* @param BoundaryType			(in) An enum representing the boundary type requested, either Outer Boundary (exact Boundary bounds) or PlayArea (rectangle inside the Outer Boundary)
	* @param IsTriggering           (out) The intersection result between a tracked device (HMD or controllers) and a Boundary 
	* @param ClosestDistance        (out) The closest distance between a tracked device (HMD or controllers) and a Boundary
	* @param ClosestPoint           (out) The closest point on surface corresponding to specified boundary 
	* @param ClosestPointNormal     (out) Normal of closest point
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static bool PXR_BoundaryTestPoint(FVector Point, EPicoXRBoundaryType BoundaryType, bool &IsTriggering, float &ClosestDistance, FVector &ClosestPoint, FVector &ClosestPointNormal);
	
	/**
	* Returns the list of points in UE world space of the requested Boundary Type 
	* @param BoundaryType			(in) An enum representing the boundary type requested, either Outer Boundary (exact Boundary bounds) or PlayArea (rectangle inside the Outer Boundary)
	* @return The array of points in UE world space of the requested Boundary Type .
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static TArray<FVector> PXR_GetBoundaryGeometry(EPicoXRBoundaryType BoundaryType);

	/**
	* Returns the dimensions in UE world space of the requested Boundary Type
	* @param BoundaryType			(in) An enum representing the boundary type requested, either Outer Boundary (exact Boundary bounds) or PlayArea (rectangle inside the Outer Boundary)
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static FVector PXR_GetBoundaryDimensions(EPicoXRBoundaryType BoundaryType);

	/**
	* Get an image of the device's camera.
	* @param CameraType			(in) Left or right camera.
	* @param CameraImage        (out) The image of the device's camera.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static bool PXR_GetBoundarySeeThroughData(EPicoXRCameraType CameraType,UTexture2D* &CameraImage);

	/**
	* Set the size of the image of the device's camera.
	* @param ImageSize			(in) Target image size.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static bool PXR_SetBoundaryCameraImageSize(FIntPoint ImageSize);

	/**
	* Set see through background.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static int PXR_SetSeeThroughBackground(bool Value);

	/**
	* Get dialog state.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static void PXR_GetDialogState(EPicoXRBoundaryState & State);

#pragma  endregion Boundary

	/**
	* Enable or disable Foveation rendering.
	* @param Enable			(in) Target state.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		 static void PXR_EnableFoveation(bool Enable);

	/**
	* Get current Foveation rendering level.
	* @return  Foveation rendering level.
	*/
	 UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		 static bool PXR_GetFoveationLevel(EPicoXRFoveationLevel &FoveationLevel);

	/**
	* Set  Foveation rendering level.
	* @param Level   rendering level.
	*/
	 UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		 static bool PXR_SetFoveationLevel(EPicoXRFoveationLevel Level);

	/**
	* Set  Foveation rendering parameter.
	* @param FoveationGainValue     The reduction rate of peripheral pixels in the X/Y direction, the higher the value, the more the reduction.
	* @param FoveationAreaValue     Take the fixation point as the center and the value of Foveation Area as the radius to maintain the full resolution.
	* @param FoveationMinimumValue  Minimum pixel density limit.
	*/
	 UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		 static bool PXR_SetFoveationParameter(FVector2D FoveationGainValue, float FoveationAreaValue, float FoveationMinimumValue);

#pragma region Eyetracking
	/**
	* Get EyeTracking gaze ray.
	* @param Origin     The starting point of an eye-tracking ray.
	* @param Direction  A unit vector in the direction of an eye-tracking ray.
	*/
	 UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		 static bool PXR_GetEyeTrackingGazeRay(FVector& Origin, FVector& Direction);

	/**
	* Get EyeTracking data.
	* @return  EyeTracking data.
	*/
	 UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		 static FPicoXREyeTrackingData PXR_GetEyeTrackingData();
	
     UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
         static void PXR_EnableEyeTrackingMarker(bool Enable);

	 UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		 static bool PXR_GetEyeTrackingPos(FVector &EyeTrackingPos);

	 UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		 static bool PXR_EnableFaceTracking(bool enable);
	
#pragma endregion EyeTracking

#pragma region SplashScreen
	/**
	 * Adds loading splash screen with parameters.
	 * @param Texture			  (in) A texture asset to be used for the splash. Gear VR uses it as a path for loading icon; all other params are currently ignored by Gear VR.
	 * @param TranslationInMeters (in) Initial translation of the center of the splash screen (in meters).
	 * @param Rotation			  (in) Initial rotation of the splash screen, with the origin at the center of the splash screen.
	 * @param SizeInMeters		  (in) Size, in meters, of the quad with the splash screen.
	 * @param DeltaRotation		  (in) Incremental rotation, that is added each 2nd frame to the quad transform. The quad is rotated around the center of the quad.
	 * @param bClearBeforeAdd	  (in) If true, clears splashes before adding a new one.
	 */
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static bool PXR_AddSplashScreen(class UTexture2D* Texture, FVector TranslationInMeters, FRotator Rotation, FVector2D SizeInMeters = FVector2D(1.0f, 1.0f), bool bClearBeforeAdd = false);

	/**
	 * Removes all the splash screens.
	 */
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static void PXR_ClearLoadingSplashScreens();

	/**
	 * Enable auto show splash screen.
	 */
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
	static void PXR_EnableAutoShowSplashScreen(bool Enable);

#pragma  endregion SplashScreen
	
	/**
	* Set sensor lost custom mode.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static int PXR_SetSensorLostCustomMode(bool Value);

	/**
	* Set sensor lost CMST.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static int PXR_SetSensorLostCMST(bool Value);
	
	/**
	* Get display frequencies available.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static bool PXR_GetDisplayFrequenciesAvailable(int &Count,TArray<float> &AvailableRates);
	
	/**
	* Set extra latency mode.
	*/
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static bool PXR_SetExtraLatencyMode(int Mode);


	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static void PXR_GetPredictedMainSensorState(FPxrSensorState& sensorState, int& sensorFrameIndex);

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRHMD")
		static void PXR_SetLargeSpaceEnable(bool bEnable,int ext=0);
};
