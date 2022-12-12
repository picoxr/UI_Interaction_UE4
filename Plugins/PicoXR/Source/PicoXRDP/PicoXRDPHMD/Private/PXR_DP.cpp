//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.


#include "PXR_DP.h"
#include "D3D11RHIPrivate.h"
#include "PXR_Log.h"

DP::DP()
{
	PXR_LOGD(PxrUnreal,"PXR_DP Construct!");
	PXR_LOGD(PxrUnreal,"PXR_DP ConnectServer!");
	ConnectServer();
	PXR_LOGD(PxrUnreal,"PXR_DP RegisterDemo!");
	RegisterDemo();
	PXR_LOGD(PxrUnreal,"PXR_DP CreateSharedTexture2D!");
	CreateSharedTexture2D();
}

DP::~DP()
{
	PXR_LOGD(PxrUnreal,"PXR_DP Destruct DisConnectServer!");
	DisConnectServer();
}


bool DP::ConnectServer()
{
	FString StreamerDLLDir = FPaths::ProjectPluginsDir() / FString::Printf(TEXT("PICOXR/Libs/Win64/"));
	FPlatformProcess::PushDllDirectory(*StreamerDLLDir);
	FPlatformProcess::GetDllHandle(*(StreamerDLLDir + "pxr_turtledove.dll"));
	FPlatformProcess::PopDllDirectory(*StreamerDLLDir);
	PXR_LOGD(PxrUnreal,"PXR_DP Destruct DisConnectServer!");
	PXR_LOGD(PxrUnreal,"PXR_DP DLL Path:%s", *StreamerDLLDir)

		terminal_ = RegisterAsTerminal();
	bool ConnectToPICORuntimeOk = false;
	while (count < 2)
	{
		count++;
		pxr::IDPInterface::IResult result = terminal_->ConnectToHost("127.0.0.1", "50051");
		if (result != pxr::IDPInterface::IResult::kOK)
		{
			continue;
		}
		else
		{
			PXR_LOGD(PxrUnreal,"PXR_DP Connect to PICO Runtime OK 127.0.0.1:50051");
			ConnectToPICORuntimeOk = true;
			count = 0;
			break;
		}
	}
	return ConnectToPICORuntimeOk;
}

void DP::DisConnectServer()
{
	if (terminal_)
	{
		terminal_->Bye();
		terminal_->DisconnectFromHost();
		UnregisterTerminal(&terminal_);
	}
}

void DP::RegisterDemo()
{
	TerminalInfo  myInfo;
	myInfo.SetTerminalType_(TerminalInfo::Type::kDriver);
	myInfo.SetIp_("127.0.0.1");
	//Todo prevent connect failed, for now just try twice.
	while (count < 2)
	{
		count++;
		auto result = terminal_->Hello(myInfo);
		if (result != pxr::IDPInterface::IResult::kOK)
		{
			continue;
		}
		else
		{
			count = 0;
			PXR_LOGD(PxrUnreal,"PXR_DP Hello OK!");
			break;
		}
	}
}

void DP::GetRemoteID()
{
	if (terminal_)
	{
		terminal_->QueryRemoteTerminalId(TerminalInfo::Type::kRuntime, local_runtime_id_);
		PXR_LOGD(PxrUnreal,"PXR_DP local_runtime_id_:%d", local_runtime_id_);
		terminal_->QueryRemoteTerminalId(TerminalInfo::Type::kHmdWireless, remote_hmd_id_);
		PXR_LOGD(PxrUnreal,"PXR_DP remote_hmd_id_:%d", remote_hmd_id_);
	}
	bQueryIDFinished = true;
}

void DP::SendMessage()
{
	if (!bQueryIDFinished || !bDstTextureOK)
	{
		return;
	}
	uint32 LeftHandle = HandleToULong(LeftDstTextureHandle);
	uint32 RightHandle = HandleToULong(RightDstTextureHandle);
	pxr::p_uint64 left_eye_handle = LeftHandle;
	pxr::p_uint64 right_eye_handle = RightHandle;

	TerminalMessage submit_message;
	submit_message.SetType_(TerminalMessage::Type::kSubmitEyeLayer);
	submit_message.SetDestinationTerminalId(local_runtime_id_);

	std::vector<TerminalMessage::Parameter> parameters;
	TerminalMessage::Parameter parameter;

	FVector position = FVector::ZeroVector;
	FQuat rotation = FQuat::Identity;
	GetPositionAndRotation(position, rotation);

	parameter.describe = "rotation_x";
	parameter.parameter = std::to_string(rotation.X);
	parameter.type = TerminalMessage::Parameter::Type::kFloat;
	parameters.push_back(parameter);

	parameter.describe = "rotation_y";
	parameter.parameter = std::to_string(rotation.Y);
	parameter.type = TerminalMessage::Parameter::Type::kFloat;
	parameters.push_back(parameter);

	parameter.describe = "rotation_z";
	parameter.parameter = std::to_string(rotation.Z);
	parameter.type = TerminalMessage::Parameter::Type::kFloat;
	parameters.push_back(parameter);

	parameter.describe = "rotation_w";
	parameter.parameter = std::to_string(-rotation.W);
	parameter.type = TerminalMessage::Parameter::Type::kFloat;
	parameters.push_back(parameter);

	parameter.describe = "position_x";
	parameter.parameter = std::to_string(position.X);
	parameter.type = TerminalMessage::Parameter::Type::kFloat;
	parameters.push_back(parameter);

	parameter.describe = "position_y";
	parameter.parameter = std::to_string(position.Y);
	parameter.type = TerminalMessage::Parameter::Type::kFloat;
	parameters.push_back(parameter);

	parameter.describe = "position_z";
	parameter.parameter = std::to_string(position.Z);
	parameter.type = TerminalMessage::Parameter::Type::kFloat;
	parameters.push_back(parameter);

	parameter.describe = "left_eye";
	parameter.parameter = std::to_string(left_eye_handle);
	parameter.type = TerminalMessage::Parameter::Type::kUInt64;
	parameters.push_back(parameter);

	parameter.describe = "right_eye";
	parameter.parameter = std::to_string(right_eye_handle);
	parameter.type = TerminalMessage::Parameter::Type::kUInt64;
	parameters.push_back(parameter);

	submit_message.SetParameters(parameters);

	pxr::IDPInterface::IResult res = terminal_->PushMessage(submit_message);
}

uint32 DP::GetHandle(ID3D11Texture2D& D3D11Texture2D)
{

	return uint32();
}

int ColorRGBA(int alpha, int red, int green, int blue)
{
	return (alpha << 24 | red << 16 | green << 8 | blue);
}

void DP::CreateSharedTexture2D()
{
	auto device = static_cast<ID3D11Device*>(GDynamicRHI->RHIGetNativeDevice());
	if (device == nullptr)
	{
		return;
	}
	if (LeftDstTexture && RightDstTexture)
	{
		return;
	}
	D3D11_TEXTURE2D_DESC tdesc;

	tdesc.Width = 1920;
	tdesc.Height = 1920;
	tdesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	tdesc.MipLevels = 1;
	tdesc.ArraySize = 1;
	tdesc.SampleDesc.Count = 1;
	tdesc.SampleDesc.Quality = 0;
	tdesc.CPUAccessFlags = 0;
	tdesc.Usage = D3D11_USAGE_DEFAULT;
	tdesc.BindFlags = D3D11_BIND_RENDER_TARGET;
	tdesc.MiscFlags = D3D11_RESOURCE_MISC_SHARED;

	uint32_t m_color = ColorRGBA(255, 108, 108, 255);

	std::vector<uint32_t> textureMap(1920 * 1920, m_color);
	uint32_t* pData = textureMap.data();

	D3D11_SUBRESOURCE_DATA sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.pSysMem = pData;
	sd.SysMemPitch = 1920 * sizeof(uint32_t);
	sd.SysMemSlicePitch = 1920 * 1920 * sizeof(uint32_t);

	if (device->CreateTexture2D(&tdesc, &sd, LeftDstTexture.GetInitReference()) != S_OK
		|| device->CreateTexture2D(&tdesc, &sd, RightDstTexture.GetInitReference()) != S_OK)
	{
		PXR_LOGD(PxrUnreal,"PXR_DP Shared Texture Created faild!");
		return;
	}
	if (LeftDstTexture&& RightDstTexture)
	{
		PXR_LOGD(PxrUnreal,"PXR_DP Shared Texture Created!");
		TRefCountPtr<IDXGIResource> LeftDXGIResource;
		TRefCountPtr<IDXGIResource> RightDXGIResource;
		LeftDstTexture->QueryInterface(LeftDXGIResource.GetInitReference());
		RightDstTexture->QueryInterface(RightDXGIResource.GetInitReference());

		const HRESULT LeftSharedHandleResult = LeftDXGIResource->GetSharedHandle(&LeftDstTextureHandle);
		const HRESULT RightSharedHandleResult = RightDXGIResource->GetSharedHandle(&RightDstTextureHandle);
		if (FAILED(LeftSharedHandleResult)|| FAILED(RightSharedHandleResult))
		{
			PXR_LOGD(PxrUnreal,"PXR_DP GetSharedHandle faild!");
		}
		else
		{
			PXR_LOGD(PxrUnreal,"PXR_DP Left Shared Handle ID:%lu", HandleToULong(LeftDstTextureHandle));
			PXR_LOGD(PxrUnreal,"PXR_DP Right Shared Handle ID:%lu", HandleToULong(RightDstTextureHandle));
			
			CreateRHITexture(LeftDstTexture, PF_R8G8B8A8, LeftTempTexture);
			CreateRHITexture(RightDstTexture, PF_R8G8B8A8, RightTempTexture);
			if (LeftTempTexture->IsValid()|| RightTempTexture->IsValid())
			{
				PXR_LOGD(PxrUnreal,"PXR_DP TempTexture OK");
			}
			bDstTextureOK = true;
		}
	}
	else
	{
		PXR_LOGD(PxrUnreal,"PXR_DP Shared Texture Created faild!");
	}
}

bool DP::CreateRHITexture(ID3D11Texture2D* OpenedSharedResource, EPixelFormat Format, FTexture2DRHIRef& OutTexture)
{
	FD3D11DynamicRHI* DynamicRHI = static_cast<FD3D11DynamicRHI*>(GDynamicRHI);
	OutTexture = DynamicRHI->RHICreateTexture2DFromResource(
		Format, TexCreate_RenderTargetable | TexCreate_ShaderResource, FClearValueBinding::None, OpenedSharedResource).GetReference();
	return OutTexture.IsValid();
}

void DP::GetPositionAndRotation(FVector& OutPostion, FQuat& OutQuat)
{
	if (terminal_)
	{
		TerminalAccessory ta;
		terminal_->QueryRemoteTerminalAccessory(remote_hmd_id_, ta);
		pxr::p_vector3_f position;
		ta.GetHmdAccessoryPtr()->GetPosition_(position);
		pxr::p_vector4_f rotation;
		ta.GetHmdAccessoryPtr()->GetRotation_(rotation);
		OutPostion.X = position.x;
		OutPostion.Y = position.y;
		OutPostion.Z = position.z;
		OutQuat.X = rotation.x;
		OutQuat.Y = rotation.y;
		OutQuat.Z = rotation.z;
		OutQuat.W = rotation.w;
	}
	else
	{
		OutPostion = FVector::ZeroVector;
		OutQuat = FQuat::Identity;
	}
}

void DP::GetControllerPositionAndRotation(int hand, float WorldScale, FVector& OutPostion, FRotator& OutQuat)
{
	if (terminal_)
	{
		pxr::connector::ControllerAccessory::Type handtype = (hand == 0 ? pxr::connector::ControllerAccessory::Type::kLeft : pxr::connector::ControllerAccessory::Type::kRight);
		TerminalAccessory ta;
		PXR_OUT_VALUE ControllerAccessory out;
		terminal_->QueryRemoteControllerAccessory(remote_hmd_id_, handtype, out);
		
		pxr::p_vector3_f position;
		out.GetPosition_(position);
		pxr::p_vector4_f rotation;
		out.GetRotation_(rotation);
		OutPostion.X = -position.z;
		OutPostion.Y = position.x;
		OutPostion.Z = position.y;
		OutPostion = OutPostion * WorldScale;
		OutQuat = FQuat(rotation.z, rotation.x, rotation.y, rotation.w).Rotator();
	}
	else
	{
		OutPostion = FVector::ZeroVector;
		OutQuat = FRotator::ZeroRotator;
	}
}

bool DP::GetControllerConnectstatus(int hand)
{
	if (terminal_)
	{
		pxr::connector::ControllerAccessory::Type handtype = (hand == 0 ? pxr::connector::ControllerAccessory::Type::kLeft : pxr::connector::ControllerAccessory::Type::kRight);
		ControllerAccessory controller;
		terminal_->QueryRemoteControllerAccessory(remote_hmd_id_, handtype, controller);
		return controller.GetIsActive_();
	}
	return false;
}

uint16 DP::GetControllerButtonStatus(int hand)
{
	if (terminal_)
	{
		pxr::connector::ControllerAccessory::Type handtype = (hand == 0 ? pxr::connector::ControllerAccessory::Type::kLeft : pxr::connector::ControllerAccessory::Type::kRight);
		ControllerAccessory controller;
		terminal_->QueryRemoteControllerAccessory(remote_hmd_id_, handtype, controller);
		return controller.GetButtonStatus_();
	}
	return uint16();
}

void DP::GetControllerAxisValue(int hand, float& JoyStickX, float& JoyStickY, float& TriggerValue, float& GripValue)
{
	if (terminal_)
	{
		pxr::connector::ControllerAccessory::Type handtype = (hand == 0 ? pxr::connector::ControllerAccessory::Type::kLeft : pxr::connector::ControllerAccessory::Type::kRight);
		ControllerAccessory controller;
		terminal_->QueryRemoteControllerAccessory(remote_hmd_id_, handtype, controller);
		if (controller.GetIsActive_())
		{
			//Todo: X Y exchanged!
			JoyStickX = controller.GetJoystickPosition_().y;
			JoyStickY = controller.GetJoystickPosition_().x;
			TriggerValue = controller.GetTriggerValue_();
			GripValue = controller.GetGripValue_();
		}
	}
}


