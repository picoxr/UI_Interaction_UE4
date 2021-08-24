// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PicoBlueprintFunctionLibrary.generated.h"


class UTexture2D;
class UStaticMesh;
class UMaterial;
class UMaterialInstance;
class UMaterialInstanceDynamic;

USTRUCT(BlueprintType, meta = (DisplayName = "PicoCoinOrderInfo"))
struct FPicoCoinOrderInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "PicoPayment")
		FString OrderNumber;

	UPROPERTY(BlueprintReadWrite, Category = "PicoPayment")
		FString OrderTitle;

	UPROPERTY(BlueprintReadWrite, Category = "PicoPayment")
		FString ProductDetail;

	UPROPERTY(BlueprintReadWrite, Category = "PicoPayment")
		FString NotifyUrl;

	UPROPERTY(BlueprintReadWrite, Category = "PicoPayment")
		int32 PicoCoinCount;
};

USTRUCT(BlueprintType, meta = (DisplayName = "PicoCoinOrderInfo"))
struct FPicoPayCodeOrderInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "PicoPayment")
		FString OrderNumber;

	UPROPERTY(BlueprintReadWrite, Category = "PicoPayment")
		FString OrderTitle;

	UPROPERTY(BlueprintReadWrite, Category = "PicoPayment")
		FString ProductDetail;

	UPROPERTY(BlueprintReadWrite, Category = "PicoPayment")
		FString NotifyUrl;

	UPROPERTY(BlueprintReadWrite, Category = "PicoPayment")
		FString PicoPayCode;
};

USTRUCT(BlueprintType, meta = (DisplayName = "PicoControllerButtonTexture"))
struct FPicoControllerButtonTexture
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "ControllerTexture")
		UTexture2D* NormalTexture;

	UPROPERTY(BlueprintReadWrite, Category = "ControllerTexture")
		UTexture2D* TouchPadTexture;

	UPROPERTY(BlueprintReadWrite, Category = "ControllerTexture")
		UTexture2D* RockerTexture;

	UPROPERTY(BlueprintReadWrite, Category = "ControllerTexture")
		UTexture2D* HomeTexture;

	UPROPERTY(BlueprintReadWrite, Category = "ControllerTexture")
		UTexture2D* BackTexture;

	UPROPERTY(BlueprintReadWrite, Category = "ControllerTexture")
		UTexture2D* VolumeUpTexture;

	UPROPERTY(BlueprintReadWrite, Category = "ControllerTexture")
		UTexture2D* VolumeDownTexture;

	UPROPERTY(BlueprintReadWrite, Category = "ControllerTexture")
		UTexture2D* TriggerTexture;

	UPROPERTY(BlueprintReadWrite, Category = "ControllerTexture")
		UTexture2D* ButtonATexture;

	UPROPERTY(BlueprintReadWrite, Category = "ControllerTexture")
		UTexture2D* ButtonBTexture;

	UPROPERTY(BlueprintReadWrite, Category = "ControllerTexture")
		UTexture2D* ButtonXTexture;

	UPROPERTY(BlueprintReadWrite, Category = "ControllerTexture")
		UTexture2D* ButtonYTexture;

	UPROPERTY(BlueprintReadWrite, Category = "ControllerTexture")
		UTexture2D* ControllerGrap;

	UPROPERTY(BlueprintReadWrite, Category = "ControllerTexture")
		UTexture2D* LeftControllerTag;

	UPROPERTY(BlueprintReadWrite, Category = "ControllerTexture")
		UTexture2D* RightControllerTag;

};

USTRUCT(BlueprintType, meta = (DisplayName = "PicoControllerPowerTexture"))
struct FPicoControllerBatteryTexture
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "ControllerTexture")
		UTexture2D* Power0Texture;

	UPROPERTY(BlueprintReadWrite, Category = "ControllerTexture")
		UTexture2D* Power1Texture;

	UPROPERTY(BlueprintReadWrite, Category = "ControllerTexture")
		UTexture2D* Power2Texture;

	UPROPERTY(BlueprintReadWrite, Category = "ControllerTexture")
		UTexture2D* Power3Texture;

	UPROPERTY(BlueprintReadWrite, Category = "ControllerTexture")
		UTexture2D* Power4Texture;

	UPROPERTY(BlueprintReadWrite, Category = "ControllerTexture")
		UTexture2D* Power5Texture;
};

USTRUCT(BlueprintType, meta = (DisplayName = "PicoEyeTrackingData"))
struct FPicoEyeTrackingData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoEyeTrackingData")
		int32  leftEyePoseStatus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoEyeTrackingData")
		int32  rightEyePoseStatus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoEyeTrackingData")
		int32  combinedEyePoseStatus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoEyeTrackingData")
		FVector  leftEyeGazePoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoEyeTrackingData")
		FVector  rightEyeGazePoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoEyeTrackingData")
		FVector  combinedEyeGazePoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoEyeTrackingData")
		FVector  leftEyeGazeVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoEyeTrackingData")
		FVector  rightEyeGazeVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoEyeTrackingData")
		FVector  combinedEyeGazeVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoEyeTrackingData")
		float  leftEyeOpenness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoEyeTrackingData")
		float	rightEyeOpenness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoEyeTrackingData")
		float  leftEyePupilDilation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoEyeTrackingData")
		float   rightEyePupilDilation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoEyeTrackingData")
		FVector   leftEyePositionGuide;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoEyeTrackingData")
		FVector   rightEyePositionGuide;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoEyeTrackingData")
		FVector   foveatedGazeDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoEyeTrackingData")
		int32     foveatedGazeTrackingState;
};

USTRUCT(BlueprintType, meta = (DisplayName = "PicoMeshData"))
struct FPicoMeshData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoMeshData")
	TArray<FVector> Vertices;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoMeshData")
	TArray<int32> Triangles;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoMeshData")
	TArray<FVector> Normals;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoMeshData")
	TArray<FVector2D> UV;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoMeshData")
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PicoMeshData")
	bool Succeed;
};

UENUM(BlueprintType)
enum class FPicoControllerType :uint8
{
	Unknown,
	PicoDisConnectController,
	PicoGoblinController,
	PicoGublin2Controller,
	PicoNeoController,
	PicoNeo2Controller,
};

UENUM(BlueprintType)
enum class PicoFoveationLevel :uint8 
{
	Low = 0,
	Medium = 1,
	High = 2,
	TopHigh=3
};

UENUM(BlueprintType)
enum class EPicoVRHMD_Eye : uint8
{
	LeftEye = 0,
	RightEye,
	AverageEye
};

UENUM(BlueprintType)
enum class EPicoSimulationType : uint8
{
	Null = 0,
	Invalid,
	Valid
};

UENUM(BlueprintType)
enum class EPicoNodeType : uint8
{
	LeftHand = 0,
	RightHand,
	Head
};

UENUM(BlueprintType)
enum class EPicoControllerType :uint8
{
	Goblin = 0,
	Goblin2,
	Neo,
	Neo2,
	Neo3,
	TypeNum
};

UENUM(BlueprintType)
enum class EPicoCamType :uint8
{
	Left = 0,
	Right
};

enum PicoResUtilsType
{
	TYPE_TEXTSIZE = 0,
    TYPE_COLOR = 1,
    TYPE_TEXT = 2,
    TYPE_FONT = 3,
    TYPE_VALUE = 4,
    TYPE_DRAWABLE = 5,
    TYPE_OBJECT = 6,
    TYPR_OBJECTARRAY = 7,
};
// Declare delegate
DECLARE_DYNAMIC_DELEGATE_TwoParams(FPicoLogInOutCallbackDelegate, const bool, isSuccess, const FString&, reason);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoGetUserInfoCallbackDelegate, const FString&, info);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FPicoPayOrderCallbackDelegate, const FString&, code, const FString&, msg);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FPicoQueryOrderCallbackDelegate, const FString&, code, const FString&, msg);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoPaymentExceptionCallbackDelegate, const FString&, exception);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoEntitlementVerifyCallbackDelegate, const int32&, code);
DECLARE_DYNAMIC_DELEGATE_OneParam(FPicoIPDChangedDelegate, float, ipd);

// Blueprint interface
UCLASS()
class PICOMOBILE_API UPicoBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


public:

	static FPicoLogInOutCallbackDelegate PicoLogInOutCallback;
	static FPicoGetUserInfoCallbackDelegate PicoGetUserInfoCallback;
	static FPicoPayOrderCallbackDelegate PicoPayOrderCallback;
	static FPicoQueryOrderCallbackDelegate PicoQueryOrderCallback;
	static FPicoPaymentExceptionCallbackDelegate PicoPaymentExceptionCallback;
	static FPicoEntitlementVerifyCallbackDelegate PicoEntitlementVerifyCallback;
	static FPicoIPDChangedDelegate PicoIPDChangedCallback;
public:
	// Sensor
	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static FQuat PicoGetCurrentOrientation();

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static FVector PicoGetCurrentPosition();

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static void PicoIs6Dof(bool& is6dof);

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static void PicoGetControllerType(int32& ControllerType);


	/**
	* You must check the "Enable PSensor ?" form Project setting befor use this function.
	* 0 - near the sensor, 1 - far the sensor , -1 - You do not check "Enable PSensor".
	*/
	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static void PicoGetPSensorState(int32& SensorState);

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static bool ResetSensor();

	// Render
	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static float PicoGetFov();
	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static float PicoGetVFov();
	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static float PicoGetHFov();
	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static bool PicoSetIPD(float ipd);
	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static bool PicoGetIPD(float& ipd);
	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static bool PicoSetTrackingIPDEnabled(bool enable);
	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static bool PicoGetTrackingIPDEnabled();
	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static bool PicoGetEyeTrackingAutoIPD(float &autoIPD);


	// System
	// Brightness,0~255
	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static int32 PicoGetCurrentBrightness();

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static bool PicoSetBrightness(int32 Brightness);

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static bool PicoGetGpuUtilization(float& GpuUtilization);

	// Volume
	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static int32 PicoGetCurrentVolume();

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static int32 PicoGetMaxVolumeNumber();

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static void PicoSetVolume(int32 Volume);

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static void PicoVolumeUp();

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static void PicoVolumeDown();

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static int32 PicoGetHandness();

	// SN
	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static void PicoGetDeviceSN(FString& SN);

	// Set CPU GPU level
	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static void SetCPUAndGPULevels(int CPULevel, int GPULevel);

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static bool PicoControllerHomekey();
	// Boundary

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static bool PicoGetBoundaryConfigured();

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static bool PicoGetBoundaryEnabled();

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static void PicoSetBoundaryVisible(bool enable);

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static bool PicoBoundaryTestNode(EPicoNodeType node, bool isPlayArea, bool &isTriggering, float &closestDistance, FVector &ppos, FVector &npos);

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static bool PicoBoundaryTestPoint(FVector pos, bool isPlayArea, bool &isTriggering, float &closestDistance, FVector &ppos, FVector &npos);

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static int32 PicoBoundaryGetGeometry(TArray<FVector> &outPointsVec, bool isPlayArea);

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static void PicoGetBoundaryDimensions(FVector &dimensions,bool isPlayArea);

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static bool PicoGetBoundaryVisible();
	
	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static bool PicoGetBoundarySeeThroughData(UTexture2D* &cameraImage,EPicoCamType cameraType);
	
	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static bool PicoSetBoundaryCameraImageSize(FIntPoint imageSize);

	static FIntPoint ImageSize;

	// DeviceModel
	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static void PicoGetDeviceModel(FString& Model);

	/*
	* This interface will be scrapped in the next version!!
	*/
	//UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static EPicoSimulationType PicoIsCurrentDeviceValid();

	/*
	 * This interface will be scrapped in the next version!!
	 */
	//UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static int32 PicoAppEntitlementCheck(FString appID);

	//UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static bool PicoKeyEntitlementCheck(FString publicKey);

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static void PicoEntitlementVerifySetCallbackDelegates(
			FPicoEntitlementVerifyCallbackDelegate OnPicoEntitlementVerifyCallback);

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		static void PicoIPDChangedDelegates(FPicoIPDChangedDelegate OnPicoIPDChanged);

	// Payment
	UFUNCTION(BlueprintCallable, Category = "PicoPayment")
		static void PicoPaymentSetCallbackDelegates(
			FPicoLogInOutCallbackDelegate OnPicoLogInOutCallback,
			FPicoGetUserInfoCallbackDelegate OnPicoGetUserInfoCallback,
			FPicoPayOrderCallbackDelegate OnPicoPayOrderCallback,
			FPicoQueryOrderCallbackDelegate OnPicoQueryOrderCallback,
			FPicoPaymentExceptionCallbackDelegate OnPicoPaymentExceptionCallback
		);

	UFUNCTION(BlueprintCallable, Category = "PicoLoginOrLogout")
		static void PicoLoginSDK();

	UFUNCTION(BlueprintCallable, Category = "PicoPayment")
		static void PicoPaymentLogin();

	UFUNCTION(BlueprintCallable, Category = "PicoLoginOrLogout")
		static void PicoLogoutSDK();

	UFUNCTION(BlueprintCallable, Category = "PicoPayment")
		static void PicoPaymentLogout();

	UFUNCTION(BlueprintCallable, Category = "PicoPayment")
		static void PicoSDKGetUserInfo();

	//return Json
	UFUNCTION(BlueprintCallable, Category = "PicoPayment")
		static void PicoPaymentGetUserInfo();

	UFUNCTION(BlueprintCallable, Category = "PicoPayment")
		static void PicoPaymentPayWithCoin(const FPicoCoinOrderInfo& Order);

	UFUNCTION(BlueprintCallable, Category = "PicoPayment")
		static void PicoPaymentPayWithPayCode(const FPicoPayCodeOrderInfo& Order);

	//return Json
	UFUNCTION(BlueprintCallable, Category = "PicoPayment")
	static void PicoPaymentQueryOrder(const FString& OrderNumber);

	UFUNCTION(BlueprintCallable)
		static void LoadMesh(FString FilePathAndName, TArray<FVector> &Vertices,  TArray<int32> &Triangles, TArray<FVector> &Normals, TArray<FVector2D> &UV, FString &Name,bool &Succeed);

	UFUNCTION(BlueprintCallable)
		static void LoadTexture(FString FilePathAndName, UTexture2D* &Texture ,bool &Succeed);

	static TArray<FColor> uint8ToFColor(const TArray<uint8> origin);

	static UTexture2D* TextureFromImage(const int32 SrcWidth, const int32 SrcHeight, const TArray<FColor> &SrcData, const bool UseAlpha);

	static FString GetRootPath();
	

	 UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		 static bool PicoEnableFoveation(bool enable);

	 UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		 static bool PicoGetFoveationLevel(PicoFoveationLevel& level);

	 UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		 static bool PicoSetFoveationLevel(PicoFoveationLevel level);

	 UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		 static bool PicoSetFoveationParameter(FVector2D foveationGainValue, float foveationAreaValue, float foveationMinimumValue);

	 UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		 static bool PicoGetCurrentDisplayFrequency(float &CurrentDisplayFrequency);

#pragma region Eyetracking
	 // Eye Tracking
	 UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		 static bool PicoGetEyeTrackingGazeRay(FVector& Origin, FVector& Direction);

	 UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		 static void PicoEnableEyeTrackingMarker(bool Enable);

	 UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		 static bool PicoGetEyeTrackingData(FPicoEyeTrackingData &PicoEyeTrackingData);

	 UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		 static bool PicoGetEyeTrackingPos(FVector &EyeTrackingPos);


	 

	 /*UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		 static bool PicoGetEyeDirection(FVector &OutEyeDirection);

	 UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		 static void PicoGetEyeOrientationAndPosition(FVector& OutPosition, FQuat& OutOrientation, FRotator& OutRotation, bool& Success);

	 UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		 static void PicoGetEyeOpenness(EPicoVRHMD_Eye WhichEye, float& Openness, bool& Success);

	 UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		 static void PicoGetPupilDialation(EPicoVRHMD_Eye WhichEye, float& Openness, bool& Success);

	 UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		 static void PicoIsEyetrackingEnabled(bool& IsEnabled);*/


#pragma endregion EyeTracking


#pragma region SplashScreen
	 UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		 static void PicoAddSplashScreen(class UTexture2D* Texture, FVector TranslationInMeters, FRotator Rotation ,FVector2D SizeInMeters = FVector2D(1.0f, 1.0f),bool bAutoShow = false);

	 /**
	  * Removes all the splash screens.
	  */
	 UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		 static void PicoClearSplashScreens();

	 /**
	  * Enables/disables splash screen to be automatically shown when LoadMap is called.
	  *
	  * @param	bAutoShowEnabled	(in)	True, if automatic showing of splash screens is enabled when map is being loaded.
	  */
	 UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		 static void PicoEnableAutoShowSplashScreen(bool bAutoShowEnabled);


	 ///**
	 // * Shows loading splash screen.
	 // */
	 //UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		// static void PicoShowSplashScreen();

	 ///**
	 // * Hides loading splash screen.
	 // *
	 // * @param	bClear	(in) Clear all splash screens after hide.
	 // */
	 //UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		// static void PicoHideSplashScreen();


#pragma  endregion SplashScreen

#pragma region LoadObject
	 UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		 static bool PicoLoadControllerAssets(
			 UObject* WorldContextObject, EPicoControllerType ControllerType,
			 TArray<UStaticMesh*> &ControllerMesh, UStaticMesh* &ControllerRayMesh,
			 FPicoControllerButtonTexture& ButtonTextures, TArray<UTexture2D*> & BatteryTexture,
			 UMaterialInstanceDynamic* &ControllerDynamicMaterial, UMaterialInstanceDynamic* &BatteryDynamicMaterial,
			 TArray<UMaterialInstance*>& RayMaterial, UMaterial* &TouchPointMaterial,UMaterialInstanceDynamic* &OtherDynamicMaterial);

	// UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		 static  bool LoadControllerButtonTextures(EPicoControllerType ControllerType, TArray<FString> Pathes, FPicoControllerButtonTexture& ButtonTextures);
	// UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		 static  bool LoadTextureFromContent(FString TexturePath, UTexture2D*& Texture);
	// UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		 static  bool LoadStaticMeshFromContent(FString Path, UStaticMesh*& StaticMesh);
	// UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		 static  bool LoadMaterialFromContent(FString Path, UMaterial*& Material);

	// UFUNCTION(BlueprintCallable, Category = "PicoMobile")
		 static  bool LoadMaterialInstanceFromContent(FString Path, UMaterialInstance*& Material);

	 






#pragma endregion LoadObject

	UFUNCTION(BlueprintCallable, Category = "PicoMobile")
         static bool PicoLoadControllerResource(TArray<FPicoMeshData> &Meshes, FPicoControllerButtonTexture& ButtonTexture,int32 & ControllerNum);

	static bool LoadControllerMesh(TArray<FString> ControllerPath,TArray<FPicoMeshData>& MeshesDatas);
	static bool LoadControllerTexture(TArray<FString>TexturePaths,FPicoControllerButtonTexture& Texture);

	

	
};