//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.
#pragma once
#include "CoreMinimal.h"
#if PLATFORM_WINDOWS
#include "D3D11RHIPrivate.h"
#include "streamer_api.h"
#include "iinterface.h"
#include "connector/terminal_interface.h"
#endif

using namespace pxr::connector;
using namespace pxr;

class PICOXRDPHMD_API DP :public TSharedFromThis<DP,ESPMode::ThreadSafe>
{
public:
	DP();
	~DP();
	//Connect runtime, 1 time in construction
	bool ConnectServer();
	//Disconnect the runtime, 1 time in the destructor
	void DisConnectServer();
	//Register Demo, 1 time during construction
	void RegisterDemo();
	//Get ID, refresh every time in Beginplay of HMD
	void GetRemoteID();
	void SendMessage();
	uint32 GetHandle(ID3D11Texture2D& D3D11Texture2D);
	void CreateSharedTexture2D();
	bool CreateRHITexture(ID3D11Texture2D* OpenedSharedResource, EPixelFormat Format, FTexture2DRHIRef& OutTexture);
	void GetPositionAndRotation(FVector &OutPostion,FQuat &OutQuat);
	void GetControllerPositionAndRotation(int hand,float WorldScale, FVector& OutPostion, FRotator& OutQuat);
	bool GetControllerConnectstatus(int hand);
	
	uint16 GetControllerButtonStatus(int hand);
	void GetControllerAxisValue(int hand,float &JoyStickX,float& JoyStickY,float &TriggerValue,float &GripValue);
	

	pxr::connector::TerminalInterface* terminal_ = nullptr;
	std::vector<TerminalInfo> infos;
	uint32 local_runtime_id_;
	uint32 remote_hmd_id_;

	TRefCountPtr<ID3D11Texture2D> LeftDstTexture;
	TRefCountPtr<ID3D11Texture2D> RightDstTexture;
	FTexture2DRHIRef LeftTempTexture=NULL;
	FTexture2DRHIRef RightTempTexture = NULL;
	void* LeftDstTextureHandle = nullptr;
	void* RightDstTextureHandle = nullptr;
	bool bQueryIDFinished = false;
	bool bDstTextureOK = false;

private:
	uint32 count = 0;


};
typedef TSharedPtr<DP, ESPMode::ThreadSafe> FDP;
