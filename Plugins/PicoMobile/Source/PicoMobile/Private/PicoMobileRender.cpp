// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#include "PicoMobile.h"
#include "PicoCustomPresent.h"
#include "PicoImport.h"
#include "PicoMobileSettings.h"
#include "PicoJava.h"
#include "PicoEyeTracker.h"
#include "XRThreadUtils.h"

DEFINE_LOG_CATEGORY_STATIC(LogPicoRender, Log, All);

#if PLATFORM_ANDROID
FPicoMobileHMDTextureSet::FPicoMobileHMDTextureSet(
	class FOpenGLDynamicRHI* InGLRHI,
	GLenum InTarget,
	GLenum InAttachment,
	uint32 InSizeX,
	uint32 InSizeY,
	uint32 InSizeZ,
	uint32 InNumMips,
	uint32 InNumSamples,
	uint32 InNumSamplesTileMem,
	uint32 InArraySize,
	EPixelFormat InFormat,
	bool bInCubemap,
	bool bInAllocatedStorage,
#if ENGINE_MINOR_VERSION > 25	
	ETextureCreateFlags InFlags,
#else	
	uint32 InFlags,
#endif
	uint8* InTextureRange,
#if ENGINE_MINOR_VERSION > 25	
	ETextureCreateFlags InTargetableTextureFlags
#else	
	uint32 InTargetableTextureFlags
#endif
) : FOpenGLTexture2D(
	InGLRHI,
	0,
	InTarget,
	InAttachment,
	InSizeX,
	InSizeY,
	InSizeZ,
	InNumMips,
	InNumSamples,
	InNumSamplesTileMem,
	InArraySize,
	InFormat,
	bInCubemap,
	bInAllocatedStorage,
	InFlags,
#if ENGINE_MINOR_VERSION < 26	
	InTextureRange,
#endif
	FClearValueBinding::Black)
{
	FRHIResourceCreateInfo CreateInfo;
	bool bArrayTexture = (InArraySize > 1);
	for (int i = 0; i < mkRenderTargetTextureNum; ++i)
	{
		GLuint TextureID = 0;
		FOpenGL::GenTextures(1, &TextureID);

		const bool bSRGB = (InTargetableTextureFlags & TexCreate_SRGB) != 0;
		const FOpenGLTextureFormat& GLFormat = GOpenGLTextureFormats[InFormat];
		if (GLFormat.InternalFormat[bSRGB] == GL_NONE)
		{
			UE_LOG(LogPicoRender, Fatal, TEXT("Pvr_UE Texture format '%s' not supported (sRGB=%d)."), GPixelFormats[InFormat].Name, bSRGB);
		}

		FOpenGLContextState& ContextState = InGLRHI->GetContextStateForCurrentContext();

		// Make sure PBO is disabled
		InGLRHI->CachedBindPixelUnpackBuffer(ContextState, 0);

		// Use a texture stage that's not likely to be used for draws, to avoid waiting
		InGLRHI->CachedSetupTextureStage(ContextState, FOpenGL::GetMaxCombinedTextureImageUnits() - 1, InTarget, TextureID, 0, 1);

		if (bArrayTexture)
		{
			UE_LOG(LogPicoRender, Log, TEXT("FOpenGL::TexStorage3D"));
			FOpenGL::TexStorage3D(InTarget, 1, GLFormat.InternalFormat[bSRGB], InSizeX, InSizeY, InArraySize, GLFormat.Format, GLFormat.Type);
			mRenderTargetTextureRHIRef[i] = InGLRHI->RHICreateTexture2DArrayFromResource(PF_R8G8B8A8, InSizeX, InSizeY, InArraySize, InNumMips, InNumSamples, InNumSamplesTileMem, FClearValueBinding::Black, TextureID, InTargetableTextureFlags);
		}
		else
		{
#if ENGINE_MINOR_VERSION > 25
			mRenderTargetTextureRHIRef[i] = RHICreateTexture2D(InSizeX, InSizeY, PF_R8G8B8A8, InNumMips, InNumSamples, InFlags, CreateInfo);	
#else	
			mRenderTargetTextureRHIRef[i] = InGLRHI->RHICreateTexture2D(InSizeX, InSizeY, PF_R8G8B8A8, InNumMips, InNumSamples, InTargetableTextureFlags, CreateInfo);    
#endif
		}
	}

	{
		FRHIResourceCreateInfo BlackTextureInfo;
		GLuint TextureID = 0;
		FOpenGL::GenTextures(1, &TextureID);

		const bool bSRGB = (InTargetableTextureFlags & TexCreate_SRGB) != 0;
		const FOpenGLTextureFormat& GLFormat = GOpenGLTextureFormats[InFormat];
		if (GLFormat.InternalFormat[bSRGB] == GL_NONE)
		{
			UE_LOG(LogPicoRender, Fatal, TEXT("Pvr_UE Texture format '%s' not supported (sRGB=%d)."), GPixelFormats[InFormat].Name, bSRGB);
		}

		FOpenGLContextState& ContextState = InGLRHI->GetContextStateForCurrentContext();

		// Make sure PBO is disabled
		InGLRHI->CachedBindPixelUnpackBuffer(ContextState, 0);

		// Use a texture stage that's not likely to be used for draws, to avoid waiting
		InGLRHI->CachedSetupTextureStage(ContextState, FOpenGL::GetMaxCombinedTextureImageUnits() - 1, InTarget, TextureID, 0, 1);

		if (bArrayTexture)
		{
			UE_LOG(LogPicoRender, Log, TEXT("FOpenGL::TexStorage3D"));
			FOpenGL::TexStorage3D(InTarget, 1, GLFormat.InternalFormat[bSRGB], 8, 8, InArraySize, GLFormat.Format, GLFormat.Type);
			BlackTexture = InGLRHI->RHICreateTexture2DArrayFromResource(PF_R8G8B8A8, 8, 8, InArraySize, InNumMips, InNumSamples, InNumSamplesTileMem, FClearValueBinding::Black, TextureID, InTargetableTextureFlags);
		}
		else
		{

#if ENGINE_MINOR_VERSION > 25
			BlackTexture = RHICreateTexture2D(8, 8, PF_R8G8B8A8, InNumMips, InNumSamples, InTargetableTextureFlags, BlackTextureInfo);
#else	
			BlackTexture = InGLRHI->RHICreateTexture2D(8, 8, PF_R8G8B8A8, InNumMips, InNumSamples, InTargetableTextureFlags, BlackTextureInfo);
#endif
		}
	}
	{
#if PLATFORM_ANDROID
		FRHIResourceCreateInfo ReticleTextureInfo;
#if ENGINE_MINOR_VERSION > 25
		ReticleTexture = RHICreateTexture2D(5, 5, PF_B8G8R8A8, 1, 1, TexCreate_ShaderResource, CreateInfo);
#else
		ReticleTexture = InGLRHI->RHICreateTexture2D(5, 5, PF_B8G8R8A8, 1, 1, TexCreate_ShaderResource, CreateInfo);
#endif
		uint32 Stride;
		uint8* ReticleTextureBuffer = (uint8*)OpenGLRHI->RHILockTexture2D(ReticleTexture, 0, RLM_WriteOnly, Stride, false);
		static uint32 ReticleData[] =
		{
			0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff,
			0xffff00ff, 0x00000000, 0x00000000, 0x00000000, 0xffff00ff,
			0xffff00ff, 0x00000000, 0x00000000, 0x00000000, 0xffff00ff,
			0xffff00ff, 0x00000000, 0x00000000, 0x00000000, 0xffff00ff,
			0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff, 0xffff00ff,
		};

		uint32 Index = 0;
		for (int32 y = 0; y < 5; ++y)
		{
			for (int32 x = 0; x < 5; ++x)
			{
				uint32* TexelData = (uint32*)(ReticleTextureBuffer + x * sizeof(uint32) + y * Stride);
				*TexelData = ReticleData[Index++];
			}
		}
		OpenGLRHI->RHIUnlockTexture2D(ReticleTexture, 0, false);
#endif
	}
	
	mRenderTargetTextureRHIRefIndex = 0;
	SetIndexAsCurrentRenderTarget();
}

FPicoMobileHMDTextureSet* FPicoMobileHMDTextureSet::CreateTexture2DSet(
	FOpenGLDynamicRHI* InGLRHI,
	GLenum InTarget,
	uint32 SizeX,
	uint32 SizeY,
	uint32 InNumSamples,
	uint32 InNumSamplesTileMem,
	uint32 InArraySize,
	EPixelFormat InFormat,
#if ENGINE_MINOR_VERSION > 25	
	ETextureCreateFlags InFlags,
	ETextureCreateFlags InTargetableTextureFlags,
#else	
	uint32 InFlags,
	uint32 InTargetableTextureFlags,
#endif
	FTexture2DRHIRef& OutTargetableTexture,
	FTexture2DRHIRef& OutShaderResourceTexture)
{
	FPicoMobileHMDTextureSet* TextureSetProxy = new FPicoMobileHMDTextureSet(InGLRHI, InTarget, GL_NONE, SizeX, SizeY, 0, 1, InNumSamples, InNumSamplesTileMem, InArraySize, InFormat, false, false, InFlags, nullptr, InTargetableTextureFlags);
	OutTargetableTexture = OutShaderResourceTexture = TextureSetProxy->GetTexture2D();
	return TextureSetProxy;
}

FPicoMobileHMDTextureSet::~FPicoMobileHMDTextureSet() 
{
	this->SetMemorySize(0);
}

void FPicoMobileHMDTextureSet::SwitchToNextElement()
{
	mRenderTargetTextureRHIRefIndex = ((mRenderTargetTextureRHIRefIndex + 1) % mkRenderTargetTextureNum);
	SetIndexAsCurrentRenderTarget();
}

void FPicoMobileHMDTextureSet::SetIndexAsCurrentRenderTarget()
{
	Resource = GetRenderTargetResource();
}

GLuint FPicoMobileHMDTextureSet::GetRenderTargetResource()
{
	return *(GLuint*)mRenderTargetTextureRHIRef[mRenderTargetTextureRHIRefIndex]->GetNativeResource();
}

GLuint FPicoMobileHMDTextureSet::GetBlackTextureResource()
{
	return *(GLuint*)BlackTexture->GetNativeResource();
}

GLuint FPicoMobileHMDTextureSet::GetReticleTextureResource()
{
	return *(GLuint*)ReticleTexture->GetNativeResource();
}

#endif

#if ENGINE_MINOR_VERSION > 22
void FPicoMobileHMD::RenderTexture_RenderThread(FRHICommandListImmediate& RHICmdList, FRHITexture2D* BackBuffer, FRHITexture2D* SrcTexture, FVector2D WindowSize) const
#else
void FPicoMobileHMD::RenderTexture_RenderThread(FRHICommandListImmediate& RHICmdList, FTexture2DRHIParamRef BackBuffer, FTexture2DRHIParamRef SrcTexture, FVector2D WindowSize) const
#endif
{
	
	check(IsInRenderingThread()||IsInRHIThread());
	if (IsInitialized())
	{
#if PLATFORM_ANDROID
    	if (PicoSDK::SeeThrough::SeeThroughState == 2)		
        {
    		FRHICommandListImmediate& CommandList = FRHICommandListExecutor::GetImmediateCommandList();   		
#if ENGINE_MINOR_VERSION > 25	
    		CommandList.Transition(FRHITransitionInfo(SrcTexture, ERHIAccess::Unknown, ERHIAccess::RTV));
    		FRHIRenderPassInfo RPInfo(SrcTexture, ERenderTargetActions::Clear_Store);
    		CommandList.BeginRenderPass(RPInfo, TEXT("ClearTexture"));
    		CommandList.EndRenderPass();
    		CommandList.Transition(FRHITransitionInfo(SrcTexture, ERHIAccess::RTV, ERHIAccess::SRVMask));
#else
    		FRHIRenderPassInfo RPInfo(SrcTexture, ERenderTargetActions::Clear_Store);
    		CommandList.BeginRenderPass(RPInfo, TEXT("ClearTexture"));
    		CommandList.EndRenderPass();
    		CommandList.SetViewport(0, 0, 0.0f, SrcTexture->GetSizeX(), SrcTexture->GetSizeY(), 1.0f);
    		CommandList.TransitionResource(EResourceTransitionAccess::EReadable, SrcTexture);
#endif		
       }						
#endif	
		ExecuteOnRHIThread([this]()
		{	
			this->FinishRendering();
		});

	}
	
}

#if ENGINE_MINOR_VERSION > 25	
bool FPicoMobileHMD::AllocateRenderTargetTexture(uint32 Index, uint32 SizeX, uint32 SizeY, uint8 Format, uint32 NumMips, ETextureCreateFlags InFlags, ETextureCreateFlags TargetableTextureFlags, FTexture2DRHIRef& OutTargetableTexture, FTexture2DRHIRef& OutShaderResourceTexture, uint32 NumSamples)
#else
bool FPicoMobileHMD::AllocateRenderTargetTexture(uint32 Index, uint32 SizeX, uint32 SizeY, uint8 Format, uint32 NumMips, uint32 InFlags, uint32 TargetableTextureFlags, FTexture2DRHIRef& OutTargetableTexture, FTexture2DRHIRef& OutShaderResourceTexture, uint32 NumSamples)
#endif
{
#if PLATFORM_ANDROID
	static const int32 MaxMSAALevelSupported = FOpenGL::GetMaxMSAASamplesTileMem();
	static const int32 MSAASettingLevel = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("r.MobileMSAA"))->GetValueOnAnyThread();
	static const int32 MobileMSAAValue = FMath::Min(MSAASettingLevel, MaxMSAALevelSupported);
	UE_LOG(LogPicoRender, Log, TEXT("Pvr_UE DISFT MSAA = %d"), MobileMSAAValue);

	GLenum Target = GL_TEXTURE_2D;
	uint32 Layers = 1;
	if (bUsesArrayTexture)
	{
		Target = GL_TEXTURE_2D_ARRAY;
		Layers = 2;
	}
	auto OpenGLDynamicRHI = static_cast<FOpenGLDynamicRHI*>(GDynamicRHI);
	check(OpenGLDynamicRHI);
	mTextureSet = TRefCountPtr<FPicoMobileHMDTextureSet>(FPicoMobileHMDTextureSet::CreateTexture2DSet(OpenGLDynamicRHI, Target, SizeX, SizeY, NumSamples, MobileMSAAValue, Layers, EPixelFormat(Format), InFlags, TargetableTextureFlags, OutTargetableTexture, OutShaderResourceTexture));
	return true;
#endif 
	return false;
}

void FPicoMobileHMD::FinishRendering()const
{
#if PLATFORM_ANDROID
	if (!PicoSplash->IsShown())
	{
		CustomPresent->ViewNnumber = PicoSDK::Sensor::GViewnumber;
		CustomPresent->CurrentPose = PicoSDK::Sensor::GCurrentPoseRT;
		CustomPresent->RtID = mTextureSet->GetRenderTargetResource();
		CustomPresent->bUsesArrayTexture = bUsesArrayTexture;
		mTextureSet->SwitchToNextElement();
#if UE_BUILD_DEBUG || UE_BUILD_DEVELOPMENT
		// frame rate log
		static int count = 0;
		static double theTime = 0.0f;
		if (count == 0)
		{
			theTime = FPlatformTime::Seconds();
		}
		count++;
		{
			double NewTime = FPlatformTime::Seconds();
			double deltaTime = NewTime - theTime;
			if (deltaTime > 1.0f)
			{
				UE_LOG(LogTemp, Log, TEXT("Pvr_UE DISFT FPS : %d "), (int)(count / deltaTime));
				theTime = NewTime;
				count = 0;
			}
		}
#endif
	}
#endif
}



void FPicoMobileHMD::SplashScreenRendering()
{
#if PLATFORM_ANDROID
	auto RTTextureId = mTextureSet->GetBlackTextureResource();
	if (bUsesArrayTexture)
	{
		PicoSDK::Render::RenderEventWithData(EVENT_BOTHEYE_ENDFRAME, RTTextureId);
	}
	else
	{
		PicoSDK::Render::RenderEventWithData(EVENT_LEFTEYE_ENDFRAME, RTTextureId);
	}
	PicoSDK::Render::RenderEventWithData(EVENT_TIMEWARP, PicoSDK::Sensor::GViewnumber);
#endif
}