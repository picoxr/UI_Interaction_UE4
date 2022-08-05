//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_StereoLayer.h"
#include "HardwareInfo.h"
#include "IXRTrackingSystem.h"
#include "PXR_HMD.h"
#include "PXR_Utils.h"
#include "GameFramework/PlayerController.h"
#include "PXR_Log.h"
#include "Materials/Material.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "XRThreadUtils.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#include "PxrApi.h"
#include "OpenGLDrvPrivate.h"
#include "OpenGLResources.h"
#include "VulkanRHIPrivate.h"
#include "VulkanResources.h"
#endif

FPxrLayer::FPxrLayer(uint32 InPxrLayerId) :
	PxrLayerId(InPxrLayerId)
{
}

FPxrLayer::~FPxrLayer()
{
	if (IsInGameThread())
	{
		ExecuteOnRenderThread([this]()
			{
				ExecuteOnRHIThread_DoNotWait([this]()
					{
#if PLATFORM_ANDROID
                        PXR_LOGD(PxrUnreal, "~FPxrLayer()a DestroyLayer %d", PxrLayerId);
						Pxr_DestroyLayer(PxrLayerId);
#endif
					});
			});
	}
	else
	{
		ExecuteOnRHIThread_DoNotWait([this]()
			{
#if PLATFORM_ANDROID
                PXR_LOGD(PxrUnreal, "~FPxrLayer()b DestroyLayer %d", PxrLayerId);
				Pxr_DestroyLayer(PxrLayerId);
#endif
			});
	}
}

uint64_t OverlayImages[2] = {};
uint64_t OverlayNativeImages[2][3] = {};

FPicoXRStereoLayer::FPicoXRStereoLayer(FPicoXRHMD* InHMDDevice, uint32 InId, const IStereoLayers::FLayerDesc& InDesc)
    : bMRCLayer(false)
    , HMDDevice(InHMDDevice)
    , LayerId(InId)
    , bTextureNeedUpdate(false)
    , LayerState(EPicoXRLayerState::Unknown)
    , NeedDestoryRuntimeLayer(true)
    , UnderlayComponent(NULL)
    , UnderlayActor(NULL)
    , PxrLayer(nullptr)
{
    PXR_LOGD(PxrUnreal, "FPicoXRStereoLayer with LayerId=%d", LayerId);
    const FString HardwareDetails = FHardwareInfo::GetHardwareDetailsString();
    const FString RHILookup = NAME_RHI.ToString() + TEXT("=");
    FParse::Value(*HardwareDetails, *RHILookup, RHIString);
    SetLayerDesc(InDesc);
}

FPicoXRStereoLayer::FPicoXRStereoLayer(const FPicoXRStereoLayer& InLayer)
    : bMRCLayer(InLayer.bMRCLayer)
    , HMDDevice(InLayer.HMDDevice)
    , LayerId(InLayer.LayerId)
    , LayerDesc(InLayer.LayerDesc)
    , SwapChain(InLayer.SwapChain)
    , LeftSwapChain(InLayer.LeftSwapChain)
    , OverlaySwapChain(InLayer.OverlaySwapChain)
    , LeftOverlaySwapChain(InLayer.LeftOverlaySwapChain)
    , bTextureNeedUpdate(InLayer.bTextureNeedUpdate)
    , RHIString(InLayer.RHIString)
    , LayerState(InLayer.LayerState)
    , EyeLayerParam(InLayer.EyeLayerParam)
	, NeedDestoryRuntimeLayer(false)
    , UnderlayComponent(InLayer.UnderlayComponent)
    , UnderlayActor(InLayer.UnderlayActor)
    , PxrLayer(InLayer.PxrLayer)
{
}

FPicoXRStereoLayer::~FPicoXRStereoLayer()
{
}

TSharedPtr<FPicoXRStereoLayer, ESPMode::ThreadSafe> FPicoXRStereoLayer::Clone() const
{
	return MakeShareable(new FPicoXRStereoLayer(*this));
}

void FPicoXRStereoLayer::SetLayerDesc(const IStereoLayers::FLayerDesc& InDesc)
{
	if (LayerDesc.Texture != InDesc.Texture || LayerDesc.LeftTexture != InDesc.LeftTexture)
	{
		if (LayerId != 0)
		{
			LayerState = EPicoXRLayerState::NeedToReCreate;
		}
	}
	LayerDesc = InDesc;

	ManageUnderlayComponent();
}

void FPicoXRStereoLayer::ManageUnderlayComponent()
{
	if (IsSupportLayerDepth())
	{
		const FString UnderlayNameStr = FString::Printf(TEXT("PicoUnderlay_%d"), LayerId);
		const FName UnderlayComponentName(*UnderlayNameStr);
		if (UnderlayComponent == NULL)
		{
			UWorld* World = NULL;
			for (const FWorldContext& Context : GEngine->GetWorldContexts())
			{
				if (Context.WorldType == EWorldType::Game || Context.WorldType == EWorldType::PIE)
				{
					World = Context.World();
				}
			}
			if (World == NULL)
			{
				return;
			}
			UnderlayActor = World->SpawnActor<AActor>();
			UnderlayComponent = NewObject<UProceduralMeshComponent>(UnderlayActor, UnderlayComponentName);
			UnderlayComponent->RegisterComponent();

			TArray<FVector> VerticePos;
			TArray<int32> TriangleIndics;
			TArray<FVector> Normals;
			TArray<FVector2D> TexUV;
			TArray<FLinearColor> VertexColors;
			TArray<FProcMeshTangent> Tangents;

			CreateQuadUnderlayMesh(VerticePos, TriangleIndics, TexUV);
			UnderlayComponent->CreateMeshSection_LinearColor(0, VerticePos, TriangleIndics, Normals, TexUV, VertexColors, Tangents, false);

			UMaterial* UnderlayMaterial = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), NULL, TEXT("Material'/PicoXR/Materials/UnderlayMaterial.UnderlayMaterial'")));
			UMaterialInstanceDynamic* DynamicMaterialInstance = UMaterialInstanceDynamic::Create(UnderlayMaterial, NULL);
			UnderlayComponent->SetMaterial(0, DynamicMaterialInstance);
		}
		UnderlayComponent->SetWorldTransform(LayerDesc.Transform);
	}
	return;
}

void FPicoXRStereoLayer::CreateQuadUnderlayMesh(TArray<FVector>& VerticePos, TArray<int32>& TriangleIndics, TArray<FVector2D>& TexUV)
{
#if ENGINE_MINOR_VERSION > 24
	if (LayerDesc.HasShape<FQuadLayer>())
#else
	if (LayerDesc.ShapeType==IStereoLayers::QuadLayer)
#endif
	{
		FIntPoint TextureSize = LayerDesc.Texture.IsValid() ? LayerDesc.Texture->GetTexture2D()->GetSizeXY() : LayerDesc.LayerSize;
		float Aspect = 1.0f;
		if (TextureSize.X > 0)
			Aspect = (float)TextureSize.Y / (float)TextureSize.X;

		float QuadSizeX = LayerDesc.QuadSize.X;
		float QuadSizeY = LayerDesc.QuadSize.Y;
		if (LayerDesc.Flags & IStereoLayers::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO)
		{
			QuadSizeY = QuadSizeX * Aspect;
		}

		VerticePos.Init(FVector::ZeroVector, 4);
		VerticePos[0] = FVector(0.0, -QuadSizeX / 2, -QuadSizeY / 2);
		VerticePos[1] = FVector(0.0, QuadSizeX / 2, -QuadSizeY / 2);
		VerticePos[2] = FVector(0.0, QuadSizeX / 2, QuadSizeY / 2);
		VerticePos[3] = FVector(0.0, -QuadSizeX / 2, QuadSizeY / 2);

		TexUV.Init(FVector2D::ZeroVector, 4);
		TexUV[0] = FVector2D(1, 0);
		TexUV[1] = FVector2D(1, 1);
		TexUV[2] = FVector2D(0, 0);
		TexUV[3] = FVector2D(0, 1);

		TriangleIndics.Reserve(6);
		TriangleIndics.Add(0);
		TriangleIndics.Add(1);
		TriangleIndics.Add(2);
		TriangleIndics.Add(0);
		TriangleIndics.Add(2);
		TriangleIndics.Add(3);
	}
}

#if ENGINE_MINOR_VERSION > 25
void FPicoXRStereoLayer::InitializeLayer_RenderThread(FPicoXRRenderBridge* RenderBridge,uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, ETextureCreateFlags Flags, ETextureCreateFlags TargetableTextureFlags,uint32 MSAAValue)
#else
void FPicoXRStereoLayer::InitializeLayer_RenderThread(FPicoXRRenderBridge* RenderBridge,uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, uint32 Flags, uint32 TargetableTextureFlags,uint32 MSAAValue)
#endif
{
    if (!PxrLayer)
	{
		PxrLayer = MakeShareable<FPxrLayer>(new FPxrLayer(LayerId));
    }
#if PLATFORM_ANDROID
    if (LayerId == 0) { // EyeBuffer
        SwapChain = RenderBridge->CreateSwapChain(Format, SizeX, SizeY, ArraySize, NumMips, NumSamples, Flags, TargetableTextureFlags, MSAAValue);
        if (RHIString == TEXT("Vulkan"))
        {
            uint64_t FoveationImage;
            uint32_t FoveationWidth;
            uint32_t FoveationHeight;
            Pxr_GetLayerFoveationImage(0, PXR_EYE_LEFT, &FoveationImage, &FoveationWidth, &FoveationHeight);

            TArray<FTextureRHIRef> TextureChain;
            FVulkanDynamicRHI* DynamicRHI = static_cast<FVulkanDynamicRHI*>(GDynamicRHI);
            if (ArraySize == 2)
            {
                TextureChain.Add(static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DArrayFromResource(PF_R8G8, FoveationWidth, FoveationHeight, 2, NumMips, 1, (VkImage)FoveationImage, (ETextureCreateFlags)0)));
            }
            else
            {
                TextureChain.Add(static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DFromResource(PF_R8G8, FoveationWidth, FoveationHeight, NumMips, 1, (VkImage)FoveationImage, (ETextureCreateFlags)0)));
            }
            FTextureRHIRef ChainTarget;
            ChainTarget = static_cast<FTextureRHIRef>(GDynamicRHI->RHICreateAliasedTexture((FTextureRHIRef&)TextureChain[0]));
            FoveationSwapChain = CreateXRSwapChain(MoveTemp(TextureChain), ChainTarget);
			if (FoveationSwapChain)
			{
				HMDDevice->bNeedReAllocateFoveationTexture_RenderThread = true;
			}
        }
    } else { // Overlay Underlay
        bool bTextureState = LayerDesc.Texture.IsValid();
        bool bLeftTextureState = LayerDesc.LeftTexture.IsValid();
        if (!bTextureState)
            return;
        PxrLayerParam layerParam = {};
        layerParam.layerId = LayerId;
        layerParam.layerShape = static_cast<PxrLayerShape>(GetShapeType());
        if(IsSupportLayerDepth()) {
            layerParam.layerType = PXR_UNDERLAY;
        } else {
            layerParam.layerType = PXR_OVERLAY;
        }

        if (RHIString == TEXT("OpenGL")) {
            layerParam.format = GL_RGBA8;
        } else if (RHIString == TEXT("Vulkan")) {
            layerParam.format = IsMobileColorsRGB() ? VK_FORMAT_R8G8B8A8_SRGB : VK_FORMAT_R8G8B8A8_UNORM;
        }

        layerParam.width = LayerDesc.Texture->GetSizeXYZ().X;
        layerParam.height = LayerDesc.Texture->GetSizeXYZ().Y;
        layerParam.sampleCount = LayerDesc.Texture->GetNumSamples();
        layerParam.faceCount = 1;
        layerParam.arraySize = 1;
        layerParam.mipmapCount = LayerDesc.Texture->GetNumMips();
		if (!(LayerDesc.Flags & IStereoLayers::LAYER_FLAG_TEX_CONTINUOUS_UPDATE))
		{
            layerParam.layerFlags |= PXR_LAYER_FLAG_STATIC_IMAGE;
		}
        //layerParam.layerFlags = PXR_LAYER_FLAG_USE_EXTERNAL_IMAGES;
        //layerParam.externalImageCount = 1;

        if (bTextureState) {
            if (bLeftTextureState) {
                layerParam.layerLayout = PXR_LAYER_LAYOUT_STEREO;
            } else {
                layerParam.layerLayout = PXR_LAYER_LAYOUT_MONO;
            }
        }
        Pxr_CreateLayer(&layerParam);

		uint32_t leftImageCounts = 0;
        uint32_t rightImageCounts = 0;
        if (bTextureState)
        {
            Pxr_GetLayerImageCount(LayerId, PXR_EYE_RIGHT, &rightImageCounts);
            PXR_LOGI(PxrUnreal, "Pxr_GetLayerImageCount right:%d", rightImageCounts);
            for (int j = 0; j < rightImageCounts; j++)
            {
                Pxr_GetLayerImage(LayerId, PXR_EYE_RIGHT, j, &OverlayNativeImages[0][j]);
                PXR_LOGI(PxrUnreal, "Pxr_GetLayerImage OverlayNativeImages[0][%d]=u_%u", j, (uint32_t)OverlayNativeImages[0][j]);
            }
        }
        if (bLeftTextureState)
        {
            Pxr_GetLayerImageCount(LayerId, PXR_EYE_LEFT, &leftImageCounts);
            PXR_LOGI(PxrUnreal, "Pxr_GetLayerImageCount left:%d", leftImageCounts);
            for (int j = 0; j < leftImageCounts; j++)
            {
                Pxr_GetLayerImage(LayerId, PXR_EYE_LEFT, j, &OverlayNativeImages[1][j]);
                PXR_LOGI(PxrUnreal, "Pxr_GetLayerImage OverlayNativeImages[1][%d]=u_%u", j, (uint32_t)OverlayNativeImages[1][j]);
            }
        }

        if (RHIString == TEXT("OpenGL")) {
            if (bTextureState) {
                if (bLeftTextureState) {  //PXR_LAYER_LAYOUT_STEREO
                    TArray<FTextureRHIRef> TextureChain;
                    FOpenGLDynamicRHI* DynamicRHI = static_cast<FOpenGLDynamicRHI*>(GDynamicRHI);
					for (int j = 0; j < leftImageCounts; j++)
					{
						TextureChain.Add(static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DFromResource(PF_R8G8B8A8, layerParam.width, layerParam.height, layerParam.mipmapCount, layerParam.sampleCount, MSAAValue, FClearValueBinding::Black, (uint32)OverlayNativeImages[1][j], TargetableTextureFlags)));
                    }
                    FTextureRHIRef ChainTarget = nullptr;
                    ChainTarget = static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DFromResource(PF_R8G8B8A8, layerParam.width, layerParam.height, layerParam.mipmapCount, layerParam.sampleCount, MSAAValue, FClearValueBinding::Black, (uint32)OverlayNativeImages[1][0], TargetableTextureFlags));
                    LeftOverlaySwapChain = CreateXRSwapChain(MoveTemp(TextureChain), ChainTarget);
                } 
                //PXR_LAYER_LAYOUT_MONO
                    TArray<FTextureRHIRef> TextureChain;
                    FOpenGLDynamicRHI* DynamicRHI = static_cast<FOpenGLDynamicRHI*>(GDynamicRHI);
					for (int j = 0; j < rightImageCounts; j++)
					{
                        TextureChain.Add(static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DFromResource(PF_R8G8B8A8, layerParam.width, layerParam.height, layerParam.mipmapCount, layerParam.sampleCount, MSAAValue, FClearValueBinding::Black, (uint32)OverlayNativeImages[0][j], TargetableTextureFlags)));
                    }
                    FTextureRHIRef ChainTarget = nullptr;
                    ChainTarget = static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DFromResource(PF_R8G8B8A8, layerParam.width, layerParam.height, layerParam.mipmapCount, layerParam.sampleCount, MSAAValue, FClearValueBinding::Black, (uint32)OverlayNativeImages[0][0], TargetableTextureFlags));
                    OverlaySwapChain = CreateXRSwapChain(MoveTemp(TextureChain), ChainTarget);
                }
           
        } else if (RHIString == TEXT("Vulkan")) {
            if (bTextureState) {
                if (bLeftTextureState) {  //PXR_LAYER_LAYOUT_STEREO
                    TArray<FTextureRHIRef> TextureChain;
                    FVulkanDynamicRHI* DynamicRHI = static_cast<FVulkanDynamicRHI*>(GDynamicRHI);

                    TargetableTextureFlags |= TexCreate_ShaderResource | TexCreate_RenderTargetable;
                    if (IsMobileColorsRGB()) {
                        TargetableTextureFlags |= TexCreate_SRGB;
                    }
                    for (int j = 0; j < leftImageCounts; j++)
                    {
                        TextureChain.Add(static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DFromResource(PF_R8G8B8A8, layerParam.width, layerParam.height, layerParam.mipmapCount, layerParam.sampleCount, (VkImage)OverlayNativeImages[1][j], TargetableTextureFlags)));
                    }
                    FTextureRHIRef ChainTarget = nullptr;
                    if (ENGINE_MINOR_VERSION < 25) {
                        ChainTarget = static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DFromResource(PF_R8G8B8A8, layerParam.width, layerParam.height, layerParam.mipmapCount, layerParam.sampleCount, (VkImage)OverlayNativeImages[1][0], TargetableTextureFlags));
                    } else {
                        ChainTarget = static_cast<FTextureRHIRef>(GDynamicRHI->RHICreateAliasedTexture((FTextureRHIRef&)TextureChain[0]));
                    }
                    LeftOverlaySwapChain = CreateXRSwapChain(MoveTemp(TextureChain), ChainTarget);
                } 
                    //PXR_LAYER_LAYOUT_MONO
                    TArray<FTextureRHIRef> TextureChain;
                    FVulkanDynamicRHI* DynamicRHI = static_cast<FVulkanDynamicRHI*>(GDynamicRHI);

                    TargetableTextureFlags |= TexCreate_ShaderResource | TexCreate_RenderTargetable;
                    if (IsMobileColorsRGB()) {
                        TargetableTextureFlags |= TexCreate_SRGB;
                    }
                    for (int j = 0; j < rightImageCounts; j++)
                    {
                        TextureChain.Add(static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DFromResource(PF_R8G8B8A8, layerParam.width, layerParam.height, layerParam.mipmapCount, layerParam.sampleCount, (VkImage)OverlayNativeImages[0][j], TargetableTextureFlags)));
                    }
                    FTextureRHIRef ChainTarget = nullptr;
                    if (ENGINE_MINOR_VERSION < 25) {
                        ChainTarget = static_cast<FTextureRHIRef>(DynamicRHI->RHICreateTexture2DFromResource(PF_R8G8B8A8, layerParam.width, layerParam.height, layerParam.mipmapCount, layerParam.sampleCount, (VkImage)OverlayNativeImages[0][0], TargetableTextureFlags));
                    } else {
                        ChainTarget = static_cast<FTextureRHIRef>(GDynamicRHI->RHICreateAliasedTexture((FTextureRHIRef&)TextureChain[0]));
                    }
                    OverlaySwapChain = CreateXRSwapChain(MoveTemp(TextureChain), ChainTarget);
            }
        }

        bTextureNeedUpdate = true;
    }
    LayerState = EPicoXRLayerState::Ready;
#endif
}

void FPicoXRStereoLayer::RefreshLayers_RenderThread(FPicoXRRenderBridge* RenderBridge, FRHICommandListImmediate& RHICmdList)
{
    check(IsInRenderingThread());
    if ((LayerDesc.Flags & IStereoLayers::LAYER_FLAG_HIDDEN)!=0 || LayerState!=EPicoXRLayerState::Ready)
    {
        return;
    }
    PXR_LOGD(PxrUnreal, "LayerId=%d, bUpdateTexture=%d, OverlaySwapChain_Valid=%d, LayerDesc.Texture.IsValid()=%d, LayerState=%d", LayerId, bTextureNeedUpdate, OverlaySwapChain.IsValid(), LayerDesc.Texture.IsValid(), LayerState);

    if (bTextureNeedUpdate && LayerState == EPicoXRLayerState::Ready)
    {
        // Copy textures
        if (LayerDesc.Texture.IsValid() && OverlaySwapChain.IsValid())
        {
            bool bNoAlpha = (LayerDesc.Flags & IStereoLayers::LAYER_FLAG_TEX_NO_ALPHA_CHANNEL) != 0;

            // Mono
            FRHITexture* SrcTexture = LayerDesc.Texture;
            FRHITexture* DstTexture = OverlaySwapChain->GetTexture();
            RenderBridge->TransferImage_RenderThread(RHICmdList, DstTexture, SrcTexture, FIntRect(), FIntRect(), false, bNoAlpha, bMRCLayer);

            // Stereo
            if (LayerDesc.LeftTexture.IsValid() && LeftOverlaySwapChain.IsValid())
            {
                FRHITexture* LeftSrcTexture = LayerDesc.LeftTexture;
                FRHITexture* LeftDstTexture = LeftOverlaySwapChain->GetTexture();
                RenderBridge->TransferImage_RenderThread(RHICmdList, LeftDstTexture, LeftSrcTexture, FIntRect(), FIntRect(), false, bNoAlpha, bMRCLayer);
            }

            if (!(LayerDesc.Flags & IStereoLayers::LAYER_FLAG_TEX_CONTINUOUS_UPDATE))
            {
                bTextureNeedUpdate = false;
            }
        }
    }
}

void FPicoXRStereoLayer::SetLayerState(EPicoXRLayerState NewState)
{
	LayerState = NewState;
}

void FPicoXRStereoLayer::MarkCreateLayer()
{
	PXR_LOGD(PxrUnreal,"Layer MarkCreateLayer %d",LayerId);
	LayerState = EPicoXRLayerState::NeedToCreate;
}

void FPicoXRStereoLayer::MarkReCreateLayer()
{
	PXR_LOGD(PxrUnreal, "Layer MarkReCreateLayer %d", LayerId);
	LayerState = EPicoXRLayerState::NeedToReCreate;
}

void FPicoXRStereoLayer::CreateLayer(FPicoXRRenderBridge* RenderBridge)
{
    PXR_LOGD(PxrUnreal, "Layer Create RenderBridge LayerId=%d", LayerId);
    if (LayerId == 0) {
        InitializeLayer_RenderThread(RenderBridge,EyeLayerParam.Format,EyeLayerParam.SizeX, EyeLayerParam.SizeY, EyeLayerParam.ArraySize, EyeLayerParam.NumMips, EyeLayerParam.NumSamples, EyeLayerParam.Flags, EyeLayerParam.TargetableTextureFlags,EyeLayerParam.MSAAValue);
    } else {
#if ENGINE_MINOR_VERSION > 25
        InitializeLayer_RenderThread(RenderBridge, 0, 0, 0, 1, 0, 0, ETextureCreateFlags::TexCreate_None, ETextureCreateFlags::TexCreate_None, 0);
#else
        InitializeLayer_RenderThread(RenderBridge, 0, 0, 0, 1, 0, 0, 0, 0, 0);
#endif
    }
}

void FPicoXRStereoLayer::DestroyLayer()
{
    PXR_LOGD(PxrUnreal, "Layer DestroyLayer %d", LayerId);
}

void FPicoXRStereoLayer::ReCreateLayer(FPicoXRRenderBridge* RenderBridge)
{
	PXR_LOGD(PxrUnreal, "Layer ReCreateLayer=%d", LayerId);
#if PLATFORM_ANDROID
	Pxr_DestroyLayer(LayerId);
#endif
	CreateLayer(RenderBridge);
}

void FPicoXRStereoLayer::IncrementSwapChainIndex_RHIThread(FPicoXRRenderBridge* RenderBridge)
{
	if ((static_cast<int32>(LayerState) < 2)||((LayerDesc.Flags & IStereoLayers::LAYER_FLAG_HIDDEN) != 0))
	{
		return;
	}
    if (LayerId == 0)
	{
		if (SwapChain && SwapChain.IsValid())
		{
			int32 index = 0;
#if PLATFORM_ANDROID
			Pxr_GetLayerNextImageIndex(0, &index);
#endif
			while (index != SwapChain->GetSwapChainIndex_RHIThread())
			{
#if ENGINE_MINOR_VERSION > 26
				SwapChain->IncrementSwapChainIndex_RHIThread();
#else
				SwapChain->IncrementSwapChainIndex_RHIThread(0);
#endif
			}
		}
    }
    else
	{
		int32 index = 0;
#if PLATFORM_ANDROID
		Pxr_GetLayerNextImageIndex(LayerId, &index);
#endif
		if (OverlaySwapChain && OverlaySwapChain.IsValid())
		{
			while (index != OverlaySwapChain->GetSwapChainIndex_RHIThread())
			{
#if ENGINE_MINOR_VERSION > 26
				OverlaySwapChain->IncrementSwapChainIndex_RHIThread();
#else
				OverlaySwapChain->IncrementSwapChainIndex_RHIThread(0);
#endif
			}
		}
		if (LeftOverlaySwapChain && LeftOverlaySwapChain.IsValid())
		{
			while (index != LeftOverlaySwapChain->GetSwapChainIndex_RHIThread())
			{
#if ENGINE_MINOR_VERSION > 26
				LeftOverlaySwapChain->IncrementSwapChainIndex_RHIThread();
#else
				LeftOverlaySwapChain->IncrementSwapChainIndex_RHIThread(0);
#endif
			}
		}
    }
}

void FPicoXRStereoLayer::SubmitCompositionLayerRenderMatrix_RHIThread(APlayerController* PlayerController, FQuat& CurrentOrientation, FVector& CurrentPosition, FTransform& CurrentTrackingToWorld)
{
#if PLATFORM_ANDROID
    if (LayerId == 0 || LayerState!=EPicoXRLayerState::Ready || ((LayerDesc.Flags & IStereoLayers::LAYER_FLAG_HIDDEN) != 0))
    {
        return;
    }
	PXR_LOGD(PxrUnreal, "Layer Submit=%d", LayerId);
	int32 ShapeType = GetShapeType();
	FQuat CameraRotation = FQuat::Identity;
	FVector CameraLocation = FVector::ZeroVector;
	FTransform TrackingToWorld =  FTransform::Identity;

	if (LayerDesc.PositionType != IStereoLayers::ELayerType::FaceLocked)
	{
		CameraLocation = CurrentPosition;
		CameraRotation = CurrentOrientation;
		TrackingToWorld = CurrentTrackingToWorld;
		if (PlayerController)
		{
			if (PlayerController->PlayerCameraManager)
			{
				CameraLocation += HMDDevice->InitCamPos;
			}
		}
	}

	FVector LayerPosition = GetLayerLocation();
	LayerPosition = TrackingToWorld.InverseTransformPosition(LayerPosition);
	LayerPosition = FPicoXRUtils::ConvertUnrealVectorToXRVector(LayerPosition,GEngine->XRSystem->GetWorldToMetersScale());
	float ModuleTranslation[3] = { LayerPosition.X,LayerPosition.Y,LayerPosition.Z };
	FQuat LayerOrientation = GetLayerOrientation();
	FRotator LayerRotation = TrackingToWorld.InverseTransformRotation(LayerOrientation).Rotator();

	LayerOrientation = LayerRotation.Quaternion();
	LayerOrientation = FPicoXRUtils::ConvertUnrealQuatToXRQuat(LayerOrientation);
	float ModuleOrientation[4] = { LayerOrientation.X,LayerOrientation.Y,LayerOrientation.Z,LayerOrientation.W };
	FIntPoint TextureSize = LayerDesc.Texture.IsValid() ? LayerDesc.Texture->GetTexture2D()->GetSizeXY() : LayerDesc.LayerSize;
	float Aspect = 1.0f;
	if (TextureSize.X > 0)
		Aspect = (float)TextureSize.Y / (float)TextureSize.X;

	CameraRotation = FPicoXRUtils::ConvertUnrealQuatToXRQuat(CameraRotation);
	float CameraOrientation[4] = { CameraRotation.X,CameraRotation.Y,CameraRotation.Z,CameraRotation.W };
	CameraLocation = FPicoXRUtils::ConvertUnrealVectorToXRVector(CameraLocation,GEngine->XRSystem->GetWorldToMetersScale());
	float CameraTranslation[3] = { CameraLocation.X,CameraLocation.Y,CameraLocation.Z };

    if (ShapeType == (int32)PxrLayerShape::PXR_LAYER_QUAD) {
        PxrLayerQuad layerSubmit = {};
        layerSubmit.header.layerId = LayerId;
        if (LayerDesc.PositionType != IStereoLayers::ELayerType::FaceLocked)
            layerSubmit.header.layerFlags = PXR_LAYER_FLAG_LAYER_POSE_NOT_IN_TRACKING_SPACE | PXR_LAYER_FLAG_USE_EXTERNAL_HEAD_POSE;
        else
            layerSubmit.header.layerFlags = PXR_LAYER_FLAG_LAYER_POSE_NOT_IN_TRACKING_SPACE | PXR_LAYER_FLAG_HEAD_LOCKED;
		
        if (bMRCLayer)
        {
            layerSubmit.header.layerFlags |= 1 << 30;
        }

    	if (HMDDevice->GbApplyToAllLayers && !bSplashLayer)
    	{
    		layerSubmit.header.colorScale[0] = HMDDevice->GColorScale.R;
    		layerSubmit.header.colorScale[1] = HMDDevice->GColorScale.G;
    		layerSubmit.header.colorScale[2] = HMDDevice->GColorScale.B;
    		layerSubmit.header.colorScale[3] = HMDDevice->GColorScale.A;

    		layerSubmit.header.colorBias[0] = HMDDevice->GColorOffset.R;
    		layerSubmit.header.colorBias[1] = HMDDevice->GColorOffset.G;
    		layerSubmit.header.colorBias[2] = HMDDevice->GColorOffset.B;
    		layerSubmit.header.colorBias[3] = HMDDevice->GColorOffset.A;
    	}
    	else
    	{
    		layerSubmit.header.colorScale[0] = 1.0f;
    		layerSubmit.header.colorScale[1] = 1.0f;
    		layerSubmit.header.colorScale[2] = 1.0f;
    		layerSubmit.header.colorScale[3] = 1.0f;
    		layerSubmit.header.colorBias[0] = 0.0f;
    		layerSubmit.header.colorBias[1]  = 0.0f;
    		layerSubmit.header.colorBias[2] = 0.0f;
    		layerSubmit.header.colorBias[3]  = 0.0f;
    	}


        layerSubmit.header.compositionDepth = 0;
        layerSubmit.header.headPose.orientation.x = CameraRotation.X;
        layerSubmit.header.headPose.orientation.y = CameraRotation.Y;
        layerSubmit.header.headPose.orientation.z = CameraRotation.Z;
        layerSubmit.header.headPose.orientation.w = CameraRotation.W;
        layerSubmit.header.headPose.position.x = CameraLocation.X;
        layerSubmit.header.headPose.position.y = CameraLocation.Y;
        layerSubmit.header.headPose.position.z = CameraLocation.Z;

        layerSubmit.pose.orientation.x = LayerOrientation.X;
        layerSubmit.pose.orientation.y = LayerOrientation.Y;
        layerSubmit.pose.orientation.z = LayerOrientation.Z;
        layerSubmit.pose.orientation.w = LayerOrientation.W;
        layerSubmit.pose.position.x = LayerPosition.X;
        layerSubmit.pose.position.y = LayerPosition.Y;
        layerSubmit.pose.position.z = LayerPosition.Z;

        float QuadSizeX = LayerDesc.QuadSize.X;
        float QuadSizeY = LayerDesc.QuadSize.Y;
        if (LayerDesc.Flags & IStereoLayers::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO)
        {
            QuadSizeY = QuadSizeX * Aspect;
        }
        FVector QuadScale = GetLayerScale();
        FVector QuadSize = FVector(-GEngine->XRSystem->GetWorldToMetersScale(), QuadSizeX, QuadSizeY);
        FVector Scale = QuadScale * QuadSize;
        Scale = FPicoXRUtils::ConvertUnrealVectorToXRVector(Scale, GEngine->XRSystem->GetWorldToMetersScale());
        layerSubmit.size[0] = (float)Scale.X;
        layerSubmit.size[1] = (float)Scale.Y;

        Pxr_SubmitLayer((PxrLayerHeader*)&layerSubmit);
    }
    else if (ShapeType == (int32)PxrLayerShape::PXR_LAYER_CYLINDER) {
        PxrLayerCylinder layerSubmit = {};
        layerSubmit.header.layerId = LayerId;
        if (LayerDesc.PositionType != IStereoLayers::ELayerType::FaceLocked)
            layerSubmit.header.layerFlags = PXR_LAYER_FLAG_LAYER_POSE_NOT_IN_TRACKING_SPACE | PXR_LAYER_FLAG_USE_EXTERNAL_HEAD_POSE;
        else
            layerSubmit.header.layerFlags = PXR_LAYER_FLAG_LAYER_POSE_NOT_IN_TRACKING_SPACE | PXR_LAYER_FLAG_HEAD_LOCKED;

        if (HMDDevice->GbApplyToAllLayers && !bSplashLayer)
        {
            layerSubmit.header.colorScale[0] = HMDDevice->GColorScale.R;
            layerSubmit.header.colorScale[1] = HMDDevice->GColorScale.G;
            layerSubmit.header.colorScale[2] = HMDDevice->GColorScale.B;
            layerSubmit.header.colorScale[3] = HMDDevice->GColorScale.A;

            layerSubmit.header.colorBias[0] = HMDDevice->GColorOffset.R;
            layerSubmit.header.colorBias[1] = HMDDevice->GColorOffset.G;
            layerSubmit.header.colorBias[2] = HMDDevice->GColorOffset.B;
            layerSubmit.header.colorBias[3] = HMDDevice->GColorOffset.A;
        }
        else
        {
            layerSubmit.header.colorScale[0] = 1.0f;
            layerSubmit.header.colorScale[1] = 1.0f;
            layerSubmit.header.colorScale[2] = 1.0f;
            layerSubmit.header.colorScale[3] = 1.0f;
            layerSubmit.header.colorBias[0] = 0.0f;
            layerSubmit.header.colorBias[1] = 0.0f;
            layerSubmit.header.colorBias[2] = 0.0f;
            layerSubmit.header.colorBias[3] = 0.0f;
        }

        layerSubmit.header.compositionDepth = 0;
        layerSubmit.header.headPose.orientation.x = CameraRotation.X;
        layerSubmit.header.headPose.orientation.y = CameraRotation.Y;
        layerSubmit.header.headPose.orientation.z = CameraRotation.Z;
        layerSubmit.header.headPose.orientation.w = CameraRotation.W;
        layerSubmit.header.headPose.position.x = CameraLocation.X;
        layerSubmit.header.headPose.position.y = CameraLocation.Y;
        layerSubmit.header.headPose.position.z = CameraLocation.Z;

        layerSubmit.pose.orientation.x = LayerOrientation.X;
        layerSubmit.pose.orientation.y = LayerOrientation.Y;
        layerSubmit.pose.orientation.z = LayerOrientation.Z;
        layerSubmit.pose.orientation.w = LayerOrientation.W;
        layerSubmit.pose.position.x = LayerPosition.X;
        layerSubmit.pose.position.y = LayerPosition.Y;
        layerSubmit.pose.position.z = LayerPosition.Z;

        FVector Scale;
#if ENGINE_MINOR_VERSION > 24
        const FCylinderLayer& CylinderProps = LayerDesc.GetShape<FCylinderLayer>();
        Scale.X = CylinderProps.OverlayArc;
        Scale.Y = (LayerDesc.Flags & IStereoLayers::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO) ? CylinderProps.OverlayArc * Aspect : CylinderProps.Height;
        Scale.Z = CylinderProps.Radius;
#else
        Scale.X = LayerDesc.CylinderOverlayArc;
        Scale.Y = (LayerDesc.Flags & IStereoLayers::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO) ? LayerDesc.CylinderOverlayArc * Aspect : LayerDesc.CylinderHeight;
        Scale.Z = LayerDesc.CylinderRadius;
#endif
        Scale = Scale / GEngine->XRSystem->GetWorldToMetersScale();
        layerSubmit.centralAngle = Scale.X / Scale.Z;
        layerSubmit.height = Scale.Y;
        layerSubmit.radius = Scale.Z;

        Pxr_SubmitLayer((PxrLayerHeader*)&layerSubmit);
    }
#endif
}

int32 FPicoXRStereoLayer::GetShapeType()
{
	int32 ShapeType = 0;
#if PLATFORM_ANDROID
#if ENGINE_MINOR_VERSION>24
	if (LayerDesc.HasShape<FQuadLayer>())
	{
		ShapeType = 1;
	}
	else if (LayerDesc.HasShape<FCylinderLayer>())
	{
		ShapeType = 2;
	}
	else if (LayerDesc.HasShape<FCubemapLayer>())
	{
		ShapeType = 4;
	}
	else if (LayerDesc.HasShape<FEquirectLayer>())
	{
		ShapeType = 3;
	}

#else
	switch (LayerDesc.ShapeType)
	{
	case IStereoLayers::QuadLayer:
		ShapeType = 1;
		break;
	case IStereoLayers::CylinderLayer:
		ShapeType = 2;
		break;
	case IStereoLayers::CubemapLayer:
		ShapeType = 4;
		break;
	default:
		ShapeType = 0;
		break;
	}
#endif
#endif
	return ShapeType;
}

#if ENGINE_MINOR_VERSION > 25
void FPicoXRStereoLayer::SetEyeLayerParam(FPicoXRRenderBridge* RenderBridge,uint8 Format, uint32 SizeX, uint32 SizeY,
	uint32 ArraySize,uint32 NumMips,uint32 NumSamples,  ETextureCreateFlags Flags, ETextureCreateFlags TargetableTextureFlags, uint32 MSAAValue)
#else
void FPicoXRStereoLayer::SetEyeLayerParam(FPicoXRRenderBridge* RenderBridge, uint8 Format, uint32 SizeX, uint32 SizeY,
	uint32 ArraySize, uint32 NumMips, uint32 NumSamples, uint32 Flags, uint32 TargetableTextureFlags, uint32 MSAAValue)
#endif
{
	check(LayerId == 0);
	EyeLayerParam.RenderBridge = RenderBridge;
	EyeLayerParam.Format = Format;
	EyeLayerParam.SizeX = SizeX;
	EyeLayerParam.SizeY = SizeY;
	EyeLayerParam.ArraySize = ArraySize;
	EyeLayerParam.NumMips = NumMips;
	EyeLayerParam.NumSamples = NumSamples;
	EyeLayerParam.Flags = Flags;
	EyeLayerParam.TargetableTextureFlags = TargetableTextureFlags;
	EyeLayerParam.MSAAValue = MSAAValue;
}

