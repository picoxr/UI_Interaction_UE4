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
#include "PXR_GameFrame.h"

#if PLATFORM_ANDROID
#include "OpenGLDrvPrivate.h"
#include "OpenGLResources.h"
#include "VulkanRHIPrivate.h"
#include "VulkanResources.h"
#endif

FPxrLayer::FPxrLayer(uint32 InPxrLayerId,FDelayDeleteLayerManager* InDelayDeletion) :
	PxrLayerId(InPxrLayerId),
	DelayDeletion(InDelayDeletion)
{
}

FPxrLayer::~FPxrLayer()
{
	if (IsInGameThread())
	{
		ExecuteOnRenderThread([PxrLayerId = this->PxrLayerId, DelayDeletion = this->DelayDeletion]()
		{
			DelayDeletion->AddPxrLayerToDeferredDeletionQueue(PxrLayerId);
		});
	}
	else
	{
		DelayDeletion->AddPxrLayerToDeferredDeletionQueue(PxrLayerId);
	}
}

uint64_t OverlayImages[2] = {};
uint64_t OverlayNativeImages[2][3] = {};

uint32 FPICOXRStereoLayer::PxrLayerIDCounter = 0;

FPICOXRStereoLayer::FPICOXRStereoLayer(FPICOXRHMD* InHMDDevice, uint32 InPXRLayerId, const IStereoLayers::FLayerDesc& InDesc)
	: bSplashLayer(false)
	, bSplashBlackProjectionLayer(false)
	, bMRCLayer(false)
    , HMDDevice(InHMDDevice)
	, ID(InPXRLayerId)
	, PxrLayerID(0)
    , bTextureNeedUpdate(false)
    , UnderlayMeshComponent(NULL)
    , UnderlayActor(NULL)
    , PxrLayer(nullptr)
{
    PXR_LOGD(PxrUnreal, "FPICOXRStereoLayer with ID=%d", ID);

#if PLATFORM_ANDROID
	FMemory::Memzero(PxrLayerCreateParam);
#endif

    SetPXRLayerDesc(InDesc);
}

FPICOXRStereoLayer::FPICOXRStereoLayer(const FPICOXRStereoLayer& InPXRLayer)
    : bSplashLayer(InPXRLayer.bSplashLayer)
	, bSplashBlackProjectionLayer(InPXRLayer.bSplashBlackProjectionLayer)
    , bMRCLayer(InPXRLayer.bMRCLayer)
    , HMDDevice(InPXRLayer.HMDDevice)
	, ID(InPXRLayer.ID)
	, PxrLayerID(InPXRLayer.PxrLayerID)
    , LayerDesc(InPXRLayer.LayerDesc)
    , SwapChain(InPXRLayer.SwapChain)
    , LeftSwapChain(InPXRLayer.LeftSwapChain)
    , FoveationSwapChain(InPXRLayer.FoveationSwapChain)
    , bTextureNeedUpdate(InPXRLayer.bTextureNeedUpdate)
    , UnderlayMeshComponent(InPXRLayer.UnderlayMeshComponent)
    , UnderlayActor(InPXRLayer.UnderlayActor)
    , PxrLayer(InPXRLayer.PxrLayer)
{
#if PLATFORM_ANDROID
	FMemory::Memcpy(&PxrLayerCreateParam, &InPXRLayer.PxrLayerCreateParam, sizeof(PxrLayerCreateParam));
#endif
}

FPICOXRStereoLayer::~FPICOXRStereoLayer()
{
}

TSharedPtr<FPICOXRStereoLayer, ESPMode::ThreadSafe> FPICOXRStereoLayer::CloneMyself() const
{
	return MakeShareable(new FPICOXRStereoLayer(*this));
}

void FPICOXRStereoLayer::SetPXRLayerDesc(const IStereoLayers::FLayerDesc& InDesc)
{
	if (LayerDesc.Texture != InDesc.Texture || LayerDesc.LeftTexture != InDesc.LeftTexture)
	{
		bTextureNeedUpdate = true;
	}
	LayerDesc = InDesc;

	ManageUnderlayComponent();
}

void FPICOXRStereoLayer::ManageUnderlayComponent()
{
	if (IsLayerSupportDepth())
	{
		const FString UnderlayNameStr = FString::Printf(TEXT("PICOUnderlay_%d"), ID);
		const FName UnderlayComponentName(*UnderlayNameStr);
		if (UnderlayMeshComponent == NULL)
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
			UnderlayMeshComponent = NewObject<UProceduralMeshComponent>(UnderlayActor, UnderlayComponentName);
			UnderlayMeshComponent->RegisterComponent();

			TArray<FVector> VerticePos;
			TArray<int32> TriangleIndics;
			TArray<FVector> Normals;
			TArray<FVector2D> TexUV;
			TArray<FLinearColor> VertexColors;
			TArray<FProcMeshTangent> Tangents;

			CreateUnderlayMesh(VerticePos, TriangleIndics, TexUV);
			UnderlayMeshComponent->CreateMeshSection_LinearColor(0, VerticePos, TriangleIndics, Normals, TexUV, VertexColors, Tangents, false);

			if (HMDDevice && HMDDevice->GetContentResourceFinder())
			{
				UMaterialInstanceDynamic* DynamicMaterialInstance = UMaterialInstanceDynamic::Create(HMDDevice->GetContentResourceFinder()->StereoLayerDepthMat, NULL);
				UnderlayMeshComponent->SetMaterial(0, DynamicMaterialInstance);
			}
		}
		UnderlayMeshComponent->SetWorldTransform(LayerDesc.Transform);
	}
	else
	{
		if (UnderlayActor)
		{
			if (UnderlayMeshComponent)
			{
				UnderlayMeshComponent->DestroyComponent();
				UnderlayMeshComponent = nullptr;
			}
			UnderlayActor->Destroy();
			UnderlayActor = nullptr;
		}
	}
	return;
}

static void AddFaceIndices(const int v0, const int v1, const int v2, const int v3, TArray<int32>& Triangles, bool inverse)
{
	if (inverse)
	{
		Triangles.Add(v0);
		Triangles.Add(v2);
		Triangles.Add(v1);
		Triangles.Add(v0);
		Triangles.Add(v3);
		Triangles.Add(v2);
	}
	else
	{
		Triangles.Add(v0);
		Triangles.Add(v1);
		Triangles.Add(v2);
		Triangles.Add(v0);
		Triangles.Add(v2);
		Triangles.Add(v3);
	}
}

void FPICOXRStereoLayer::CreateUnderlayMesh(TArray<FVector>& Vertices, TArray<int32>& Triangles, TArray<FVector2D>& UV0)
{
#if ENGINE_MINOR_VERSION > 24
	if (LayerDesc.HasShape<FQuadLayer>())
#else
	if (LayerDesc.ShapeType == IStereoLayers::QuadLayer)
#endif
	{
		const float QuadScale = 0.99;

		FIntPoint TexSize = LayerDesc.Texture.IsValid() ? LayerDesc.Texture->GetTexture2D()->GetSizeXY() : LayerDesc.LayerSize;
		float AspectRatio = TexSize.X ? (float)TexSize.Y / (float)TexSize.X : 3.0f / 4.0f;

		float QuadSizeX = LayerDesc.QuadSize.X;
		float QuadSizeY = (LayerDesc.Flags & IStereoLayers::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO) ? LayerDesc.QuadSize.X * AspectRatio : LayerDesc.QuadSize.Y;

		Vertices.Init(FVector::ZeroVector, 4);
		Vertices[0] = FVector(0.0, -QuadSizeX / 2, -QuadSizeY / 2) * QuadScale;
		Vertices[1] = FVector(0.0, QuadSizeX / 2, -QuadSizeY / 2) * QuadScale;
		Vertices[2] = FVector(0.0, QuadSizeX / 2, QuadSizeY / 2) * QuadScale;
		Vertices[3] = FVector(0.0, -QuadSizeX / 2, QuadSizeY / 2) * QuadScale;

		UV0.Init(FVector2D::ZeroVector, 4);
		UV0[0] = FVector2D(1, 0);
		UV0[1] = FVector2D(1, 1);
		UV0[2] = FVector2D(0, 0);
		UV0[3] = FVector2D(0, 1);

		Triangles.Reserve(6);
		AddFaceIndices(0, 1, 2, 3, Triangles, false);
	}
#if ENGINE_MINOR_VERSION > 24
	else if (LayerDesc.HasShape<FCylinderLayer>())
#else
	else if (LayerDesc.ShapeType == IStereoLayers::CylinderLayer)
#endif	
	{
		float Arc, Radius, Height;
#if ENGINE_MAJOR_VERSION >=5 || ENGINE_MINOR_VERSION >= 25
		const FCylinderLayer& CylinderProps = LayerDesc.GetShape<FCylinderLayer>();
		Arc = CylinderProps.OverlayArc;
		Radius = CylinderProps.Radius;
		Height = CylinderProps.Height;
#else
		Arc = LayerDesc.CylinderOverlayArc;
		Radius = LayerDesc.CylinderRadius;
		Height = LayerDesc.CylinderHeight;
#endif
		const float CylinderScale = 0.99;

		FIntPoint TexSize = LayerDesc.Texture.IsValid() ? LayerDesc.Texture->GetTexture2D()->GetSizeXY() : LayerDesc.LayerSize;
		float AspectRatio = TexSize.X ? (float)TexSize.Y / (float)TexSize.X : 3.0f / 4.0f;

		float CylinderHeight = (LayerDesc.Flags & IStereoLayers::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO) ? Arc * AspectRatio : Height;

		const FVector XAxis = FVector(1, 0, 0);
		const FVector YAxis = FVector(0, 1, 0);
		const FVector HalfHeight = FVector(0, 0, CylinderHeight / 2);

		const float ArcAngle = Arc / Radius;
		const int Sides = (int)((ArcAngle * 180) / (PI * 5));
		Vertices.Init(FVector::ZeroVector, 2 * (Sides + 1));
		UV0.Init(FVector2D::ZeroVector, 2 * (Sides + 1));
		Triangles.Init(0, Sides * 6);

		float CurrentAngle = -ArcAngle / 2;
		const float AngleStep = ArcAngle / Sides;


		for (int Side = 0; Side < Sides + 1; Side++)
		{
			FVector MidVertex = Radius * (FMath::Cos(CurrentAngle) * XAxis + FMath::Sin(CurrentAngle) * YAxis);
			Vertices[2 * Side] = (MidVertex - HalfHeight) * CylinderScale;
			Vertices[(2 * Side) + 1] = (MidVertex + HalfHeight) * CylinderScale;

			UV0[2 * Side] = FVector2D(1 - (Side / (float)Sides), 0);
			UV0[(2 * Side) + 1] = FVector2D(1 - (Side / (float)Sides), 1);

			CurrentAngle += AngleStep;

			if (Side < Sides)
			{
				Triangles[6 * Side + 0] = 2 * Side;
				Triangles[6 * Side + 2] = 2 * Side + 1;
				Triangles[6 * Side + 1] = 2 * (Side + 1) + 1;
				Triangles[6 * Side + 3] = 2 * Side;
				Triangles[6 * Side + 5] = 2 * (Side + 1) + 1;
				Triangles[6 * Side + 4] = 2 * (Side + 1);
			}
		}
	}
#if ENGINE_MINOR_VERSION > 24
	else if (LayerDesc.HasShape<FCubemapLayer>())
#else
	else if (LayerDesc.ShapeType == IStereoLayers::CubemapLayer)
#endif	
	{
		const float CubemapScale = 1000;
		Vertices.Init(FVector::ZeroVector, 8);
		Vertices[0] = FVector(-1.0, -1.0, -1.0) * CubemapScale;
		Vertices[1] = FVector(-1.0, -1.0, 1.0) * CubemapScale;
		Vertices[2] = FVector(-1.0, 1.0, -1.0) * CubemapScale;
		Vertices[3] = FVector(-1.0, 1.0, 1.0) * CubemapScale;
		Vertices[4] = FVector(1.0, -1.0, -1.0) * CubemapScale;
		Vertices[5] = FVector(1.0, -1.0, 1.0) * CubemapScale;
		Vertices[6] = FVector(1.0, 1.0, -1.0) * CubemapScale;
		Vertices[7] = FVector(1.0, 1.0, 1.0) * CubemapScale;

		Triangles.Reserve(24);
		AddFaceIndices(0, 1, 3, 2, Triangles, false);
		AddFaceIndices(4, 5, 7, 6, Triangles, true);
		AddFaceIndices(0, 1, 5, 4, Triangles, true);
		AddFaceIndices(2, 3, 7, 6, Triangles, false);
		AddFaceIndices(0, 2, 6, 4, Triangles, false);
		AddFaceIndices(1, 3, 7, 5, Triangles, true);
	}
}

void FPICOXRStereoLayer::PXRLayersCopy_RenderThread(FPICOXRRenderBridge* RenderBridge, FRHICommandListImmediate& RHICmdList)
{
	check(IsInRenderingThread());

	PXR_LOGV(PxrUnreal, "ID=%d, bTextureNeedUpdate=%d, IsVisible:%d, SwapChain.IsValid=%d, LayerDesc.Texture.IsValid=%d", ID, bTextureNeedUpdate, IsVisible(), SwapChain.IsValid(), LayerDesc.Texture.IsValid());

	if (bTextureNeedUpdate && IsVisible())
	{
		// Copy textures
		if (LayerDesc.Texture.IsValid() && SwapChain.IsValid())
		{
			bool bNoAlpha = (LayerDesc.Flags & IStereoLayers::LAYER_FLAG_TEX_NO_ALPHA_CHANNEL) != 0;
#if ENGINE_MAJOR_VERSION >=5 || ENGINE_MINOR_VERSION >=25
			bool bInvertY = bMRCLayer || LayerDesc.HasShape<FCubemapLayer>() ? true : false;
#else
			bool bInvertY = bMRCLayer || LayerDesc.ShapeType == IStereoLayers::CubemapLayer ? true : false;
#endif
			// Mono
			FRHITexture* SrcTexture = LayerDesc.Texture;
			FRHITexture* DstTexture = SwapChain->GetTexture();

			FIntRect DstRect, SrcRect;
#if PLATFORM_ANDROID
			DstRect = SrcRect = FIntRect(LayerDesc.UVRect.Min.X * (float)PxrLayerCreateParam.width, LayerDesc.UVRect.Min.Y * (float)PxrLayerCreateParam.height,
				LayerDesc.UVRect.Max.X * (float)PxrLayerCreateParam.width, LayerDesc.UVRect.Max.Y * (float)PxrLayerCreateParam.height);
#else
			DstRect = SrcRect = FIntRect();
#endif

			RenderBridge->TransferImage_RenderThread(RHICmdList, DstTexture, SrcTexture, DstRect, SrcRect, true, bNoAlpha, bMRCLayer, bInvertY);

			// Stereo
			if (LayerDesc.LeftTexture.IsValid() && LeftSwapChain.IsValid())
			{
				FRHITexture* LeftSrcTexture = LayerDesc.LeftTexture;
				FRHITexture* LeftDstTexture = LeftSwapChain->GetTexture();
				RenderBridge->TransferImage_RenderThread(RHICmdList, LeftDstTexture, LeftSrcTexture, DstRect, SrcRect, true, bNoAlpha, false/*BG*/, bInvertY);
			}

			bTextureNeedUpdate = false;
		}
		else
		{
			if (UnderlayActor)
			{
				if (UnderlayMeshComponent)
				{
					UnderlayMeshComponent->DestroyComponent();
					UnderlayMeshComponent = nullptr;
				}
				UnderlayActor->Destroy();
				UnderlayActor = nullptr;
			}
		}
	}
}

bool FPICOXRStereoLayer::InitPXRLayer_RenderThread(FPICOXRRenderBridge* CustomPresent, FDelayDeleteLayerManager* DelayDeletion, FRHICommandListImmediate& RHICmdList, const FPICOXRStereoLayer* InLayer)
{
	check(IsInRenderingThread());

	int32 MSAAValue = 1;
	bool bNeedFFRSwapChain = false;
	if (ID == 0)
	{
		if (HMDDevice)
		{
			MSAAValue = HMDDevice->GetMSAAValue();
		}

		if (CustomPresent->RHIString == TEXT("Vulkan"))
		{
			bNeedFFRSwapChain = true;
		}
	}
	else if (!bSplashBlackProjectionLayer)
	{
		MSAAValue = 1;
#if PLATFORM_ANDROID
		PxrLayerCreateParam.layerShape = static_cast<PxrLayerShape>(GetShapeType());
		PxrLayerCreateParam.layerType = IsLayerSupportDepth() ? PXR_UNDERLAY : PXR_OVERLAY;

		if (LayerDesc.Texture.IsValid())
		{
			FRHITexture2D* Texture2D = LayerDesc.Texture->GetTexture2D();
			FRHITextureCube* TextureCube = LayerDesc.Texture->GetTextureCube();
			if (Texture2D)
			{
				PxrLayerCreateParam.width = Texture2D->GetSizeX();
				PxrLayerCreateParam.height = Texture2D->GetSizeY();
				PxrLayerCreateParam.sampleCount = Texture2D->GetNumSamples();
#if ENGINE_MINOR_VERSION > 24
				PxrLayerCreateParam.mipmapCount = Texture2D->GetNumMips();
#else
				PxrLayerCreateParam.mipmapCount = 1;
#endif
			}
			else if (TextureCube)
			{
				PxrLayerCreateParam.width = PxrLayerCreateParam.height = TextureCube->GetSize();
				PxrLayerCreateParam.sampleCount = 1;
				PxrLayerCreateParam.mipmapCount = 1;
			}

		}
		else
		{
			PxrLayerCreateParam.width = LayerDesc.QuadSize.X;
			PxrLayerCreateParam.height = LayerDesc.QuadSize.Y;
			PxrLayerCreateParam.sampleCount = 1;
			PxrLayerCreateParam.mipmapCount = 1;
		}

		if (PxrLayerCreateParam.width == 0 || PxrLayerCreateParam.height == 0)
		{
			return false;
		}

		if (PxrLayerCreateParam.layerShape == PxrLayerShape::PXR_LAYER_CUBE)
		{
			PxrLayerCreateParam.faceCount = 6;
		}
		else
		{
			PxrLayerCreateParam.faceCount = 1;
		}
		PxrLayerCreateParam.arraySize = 1;

		//TODO:if bSplashLayer,create swapchain count=1,to avoid flicker between color and black.
		if ((bSplashLayer && CustomPresent->RHIString == TEXT("Vulkan")) || !(LayerDesc.Flags & IStereoLayers::LAYER_FLAG_TEX_CONTINUOUS_UPDATE))
		{
			PxrLayerCreateParam.layerFlags |= PXR_LAYER_FLAG_STATIC_IMAGE;
		}
		else
		{
			PxrLayerCreateParam.layerFlags &= ~PXR_LAYER_FLAG_STATIC_IMAGE;
		}

		PxrLayerCreateParam.layerLayout = LayerDesc.LeftTexture.IsValid() ? PXR_LAYER_LAYOUT_STEREO : PXR_LAYER_LAYOUT_MONO;

		if (CustomPresent->RHIString == TEXT("OpenGL"))
		{
			PxrLayerCreateParam.format = IsMobileColorsRGB() ? GL_SRGB8_ALPHA8 : GL_RGBA8;
		}
		else if (CustomPresent->RHIString == TEXT("Vulkan"))
		{
			PxrLayerCreateParam.format = IsMobileColorsRGB() ? VK_FORMAT_R8G8B8A8_SRGB : VK_FORMAT_R8G8B8A8_UNORM;
		}
#endif
	}

	if (IfCanReuseLayers(InLayer))
	{
		//GameThread = RenderThread
		PxrLayerID = InLayer->PxrLayerID;
		PxrLayer = InLayer->PxrLayer;
		SwapChain = InLayer->SwapChain;
		LeftSwapChain = InLayer->LeftSwapChain;
        FoveationSwapChain =InLayer->FoveationSwapChain;
		bTextureNeedUpdate |= InLayer->bTextureNeedUpdate;
	}
    else
	{
		TArray<uint64> TextureResources;
		TArray<uint64> LeftTextureResources;
		TArray<uint64> FFRTextureResources;
		uint32_t FoveationWidth = 0;
		uint32_t FoveationHeight = 0;
		TextureResources.Empty();
		LeftTextureResources.Empty();
		FFRTextureResources.Empty();
		bool bNativeTextureCreated = false;
#if PLATFORM_ANDROID
		ExecuteOnRHIThread([&]()
			{
				PxrLayerCreateParam.layerId = PxrLayerID = PxrLayerIDCounter;
				if (Pxr_IsInitialized() && (Pxr_CreateLayer(&PxrLayerCreateParam) == 0))
				{
					PxrLayerIDCounter++;
					uint32_t ImageCounts = 0;
					uint64_t LayerImages[2][3] = {};
					Pxr_GetLayerImageCount(PxrLayerID, PXR_EYE_RIGHT, &ImageCounts);
					ensure(ImageCounts != 0);
					for (uint32_t i = 0; i < ImageCounts; i++)
					{
						Pxr_GetLayerImage(PxrLayerID, PXR_EYE_RIGHT, i, &LayerImages[1][i]);
						PXR_LOGI(PxrUnreal, "Pxr_GetLayerImage Right LayerImages[1][%d]=u_%u", i, (uint32_t)LayerImages[1][i]);
						TextureResources.Add(LayerImages[1][i]);
					}

					if (PxrLayerCreateParam.layerLayout == PXR_LAYER_LAYOUT_STEREO)
					{
						Pxr_GetLayerImageCount(PxrLayerID, PXR_EYE_LEFT, &ImageCounts);
						ensure(ImageCounts != 0);
						for (uint32_t i = 0; i < ImageCounts; i++)
						{
							Pxr_GetLayerImage(PxrLayerID, PXR_EYE_LEFT, i, &LayerImages[0][i]);
							PXR_LOGI(PxrUnreal, "Pxr_GetLayerImage Left LayerImages[0][%d]=u_%u", i, (uint32_t)LayerImages[0][i]);
							LeftTextureResources.Add(LayerImages[0][i]);
						}
					}

					if (bNeedFFRSwapChain)
					{
						uint64_t FoveationImage;
						Pxr_GetLayerFoveationImage(PxrLayerID, PXR_EYE_RIGHT, &FoveationImage, &FoveationWidth, &FoveationHeight);
						FFRTextureResources.Add(FoveationImage);
					}

					bNativeTextureCreated = true;
				}
				else
				{
					PXR_LOGE(PxrUnreal, "Create native texture failed!");
				}
			});

		if (bNativeTextureCreated)
		{
			PxrLayer = MakeShareable<FPxrLayer>(new FPxrLayer(PxrLayerID, DelayDeletion));

			ERHIResourceType ResourceType;
			if (PxrLayerCreateParam.layerShape == PxrLayerShape::PXR_LAYER_CUBE)
			{
				ResourceType = RRT_TextureCube;
			}
			else if (PxrLayerCreateParam.arraySize == 2)
			{
				ResourceType = RRT_Texture2DArray;
			}
			else
			{
				ResourceType = RRT_Texture2D;
			}

#if ENGINE_MINOR_VERSION > 25
			ETextureCreateFlags Flags;
			ETextureCreateFlags TargetableTextureFlags;
			Flags = TargetableTextureFlags = ETextureCreateFlags::TexCreate_None;
#else
			uint32 Flags;
			uint32 TargetableTextureFlags;
			Flags = TargetableTextureFlags = 0;
#endif
			Flags = TargetableTextureFlags |= ETextureCreateFlags::TexCreate_RenderTargetable | ETextureCreateFlags::TexCreate_ShaderResource | (IsMobileColorsRGB() ? TexCreate_SRGB : TexCreate_None);

			SwapChain = CustomPresent->CreateSwapChain_RenderThread(PxrLayerID, ResourceType, TextureResources, PF_R8G8B8A8, PxrLayerCreateParam.width, PxrLayerCreateParam.height, PxrLayerCreateParam.arraySize, PxrLayerCreateParam.mipmapCount, PxrLayerCreateParam.sampleCount, Flags, TargetableTextureFlags, MSAAValue);
			if (PxrLayerCreateParam.layerLayout == PXR_LAYER_LAYOUT_STEREO)
			{
				LeftSwapChain = CustomPresent->CreateSwapChain_RenderThread(PxrLayerID, ResourceType, LeftTextureResources, PF_R8G8B8A8, PxrLayerCreateParam.width, PxrLayerCreateParam.height, PxrLayerCreateParam.arraySize, PxrLayerCreateParam.mipmapCount, PxrLayerCreateParam.sampleCount, Flags, TargetableTextureFlags, MSAAValue);
			}

			if (bNeedFFRSwapChain)
			{
#if ENGINE_MINOR_VERSION > 25
				ETextureCreateFlags	TCF = ETextureCreateFlags::TexCreate_Foveation;
#else
				ETextureCreateFlags	TCF = ETextureCreateFlags::TexCreate_None;
#endif
				FoveationSwapChain = CustomPresent->CreateSwapChain_RenderThread(PxrLayerID, ResourceType, FFRTextureResources, PF_R8G8, FoveationWidth, FoveationHeight, PxrLayerCreateParam.arraySize, 1, 1, Flags, TCF, 1);
			}	
			bTextureNeedUpdate = true;
		}
		else
		{
			PXR_LOGE(PxrUnreal, "Create SwapChain failed!");
			return false;
		}
#endif
	}            
	if ((LayerDesc.Flags & IStereoLayers::LAYER_FLAG_TEX_CONTINUOUS_UPDATE) && LayerDesc.Texture.IsValid() && IsVisible())
	{
		bTextureNeedUpdate = true;
	}
    return true;
}

bool FPICOXRStereoLayer::IfCanReuseLayers(const FPICOXRStereoLayer* InLayer) const
{
	if (!InLayer || !InLayer->PxrLayer.IsValid())
	{
		return false;
	}

#if PLATFORM_ANDROID
	if (PxrLayerCreateParam.width != InLayer->PxrLayerCreateParam.width				||
		PxrLayerCreateParam.height != InLayer->PxrLayerCreateParam.height			||
		PxrLayerCreateParam.layerShape != InLayer->PxrLayerCreateParam.layerShape   ||
		PxrLayerCreateParam.layerLayout != InLayer->PxrLayerCreateParam.layerLayout ||
		PxrLayerCreateParam.mipmapCount != InLayer->PxrLayerCreateParam.mipmapCount ||
		PxrLayerCreateParam.sampleCount != InLayer->PxrLayerCreateParam.sampleCount ||
		PxrLayerCreateParam.format != InLayer->PxrLayerCreateParam.format			||
		PxrLayerCreateParam.layerFlags != InLayer->PxrLayerCreateParam.layerFlags   ||
		PxrLayerCreateParam.layerType != InLayer->PxrLayerCreateParam.layerType)
	{
		return false;
	}
#endif

	return true;
}

void FPICOXRStereoLayer::IncrementSwapChainIndex_RHIThread(FPICOXRRenderBridge* RenderBridge)
{
    if ((LayerDesc.Flags & IStereoLayers::LAYER_FLAG_HIDDEN) != 0)
	{
		return;
	}

	if (SwapChain && SwapChain.IsValid())
	{
		int32 index = 0;
#if PLATFORM_ANDROID
		Pxr_GetLayerNextImageIndex(PxrLayerID, &index);
#endif
		while (index != SwapChain->GetSwapChainIndex_RHIThread())
		{
#if ENGINE_MINOR_VERSION > 26
			SwapChain->IncrementSwapChainIndex_RHIThread();
#else
			SwapChain->IncrementSwapChainIndex_RHIThread(0);
#endif
		}

		if (LeftSwapChain && LeftSwapChain.IsValid())
		{
			while (index != LeftSwapChain->GetSwapChainIndex_RHIThread())
			{
#if ENGINE_MINOR_VERSION > 26
				LeftSwapChain->IncrementSwapChainIndex_RHIThread();
#else
				LeftSwapChain->IncrementSwapChainIndex_RHIThread(0);
#endif
			}
		}
	}
}

void FPICOXRStereoLayer::SubmitLayer_RHIThread(FPXRGameFrame* Frame)
{
	PXR_LOGV(PxrUnreal, "Submit Layer:%u", ID);
#if PLATFORM_ANDROID
	if (ID == 0)
	{
		PxrLayerProjection layerProjection = {};
		layerProjection.header.layerId = PxrLayerID;
		layerProjection.header.layerFlags = 0;
		layerProjection.header.sensorFrameIndex = Frame->ViewNumber;
		bool bDrawBlackEye = HMDDevice->bIsSwitchingLevel;
		layerProjection.header.colorScale[0] = bDrawBlackEye ? 0.0f : HMDDevice->GColorScale.R;
		layerProjection.header.colorScale[1] = bDrawBlackEye ? 0.0f : HMDDevice->GColorScale.G;
		layerProjection.header.colorScale[2] = bDrawBlackEye ? 0.0f : HMDDevice->GColorScale.B;
		layerProjection.header.colorScale[3] = bDrawBlackEye ? 0.0f : HMDDevice->GColorScale.A;
		layerProjection.header.colorBias[0] = bDrawBlackEye ? 0.0f : HMDDevice->GColorOffset.R;
		layerProjection.header.colorBias[1] = bDrawBlackEye ? 0.0f : HMDDevice->GColorOffset.G;
		layerProjection.header.colorBias[2] = bDrawBlackEye ? 0.0f : HMDDevice->GColorOffset.B;
		layerProjection.header.colorBias[3] = bDrawBlackEye ? 0.0f : HMDDevice->GColorOffset.A;
		Pxr_SubmitLayer((PxrLayerHeader*)&layerProjection);
	}
	else if (bSplashBlackProjectionLayer)
	{
		PxrLayerProjection layerProjection = {};
		layerProjection.header.layerId = PxrLayerID;
		layerProjection.header.layerFlags = 0;
		layerProjection.header.sensorFrameIndex = Frame->ViewNumber;
		layerProjection.header.colorScale[0] = 0.0f;
		layerProjection.header.colorScale[1] = 0.0f;
		layerProjection.header.colorScale[2] = 0.0f;
		layerProjection.header.colorScale[3] = 0.0f;
		Pxr_SubmitLayer((PxrLayerHeader*)&layerProjection);
	}
	else
	{
		FTransform BaseTransform = FTransform::Identity;
		uint32 Flags = 0;
		Flags |= bMRCLayer ? (1 << 30) : 0;
		switch (LayerDesc.PositionType)
		{
		case IStereoLayers::WorldLocked:
			BaseTransform.SetRotation(Frame->TrackingToWorld.GetRotation());
			BaseTransform.SetLocation(Frame->TrackingToWorld.GetTranslation());
			break;

		case IStereoLayers::TrackerLocked:
			break;

		case IStereoLayers::FaceLocked:
			Flags |= PXR_LAYER_FLAG_HEAD_LOCKED;
			break;
		}

		FVector LayerPosition = GetLayerLocation();
		LayerPosition = BaseTransform.InverseTransformPosition(LayerPosition);
		LayerPosition = FPICOXRUtils::ConvertUnrealVectorToXRVector(LayerPosition, Frame->WorldToMetersScale);

		FQuat LayerOrientation = GetLayerOrientation();
		LayerOrientation = BaseTransform.InverseTransformRotation(LayerOrientation);
		LayerOrientation = FPICOXRUtils::ConvertUnrealQuatToXRQuat(LayerOrientation);

		int SizeX = PxrLayerCreateParam.width;
		int SizeY = PxrLayerCreateParam.height;
		float AspectRatio = SizeX ? (float)SizeY / (float)SizeX : 3.0f / 4.0f;
		FVector Scale = FPICOXRUtils::ConvertUnrealVectorToXRVector(LayerDesc.Transform.GetScale3D(), Frame->WorldToMetersScale);

		bool bAdjustLayersColor = HMDDevice->GbApplyToAllLayers && (!bSplashLayer);

		int32 ShapeType = GetShapeType();
		if (ShapeType == (int32)PxrLayerShape::PXR_LAYER_QUAD)
		{
			PxrLayerQuad layerSubmit = {};
			layerSubmit.header.layerId = PxrLayerID;
			layerSubmit.header.compositionDepth = 0;
			layerSubmit.header.sensorFrameIndex = Frame->ViewNumber;
			layerSubmit.header.layerFlags = Flags;

			layerSubmit.header.colorScale[0] = bAdjustLayersColor ? HMDDevice->GColorScale.R : 1.0f;
			layerSubmit.header.colorScale[1] = bAdjustLayersColor ? HMDDevice->GColorScale.G : 1.0f;
			layerSubmit.header.colorScale[2] = bAdjustLayersColor ? HMDDevice->GColorScale.B : 1.0f;
			layerSubmit.header.colorScale[3] = bAdjustLayersColor ? HMDDevice->GColorScale.A : 1.0f;

			layerSubmit.header.colorBias[0] = bAdjustLayersColor ? HMDDevice->GColorOffset.R : 0.0f;
			layerSubmit.header.colorBias[1] = bAdjustLayersColor ? HMDDevice->GColorOffset.G : 0.0f;
			layerSubmit.header.colorBias[2] = bAdjustLayersColor ? HMDDevice->GColorOffset.B : 0.0f;
			layerSubmit.header.colorBias[3] = bAdjustLayersColor ? HMDDevice->GColorOffset.A : 0.0f;

			layerSubmit.pose.orientation.x = LayerOrientation.X;
			layerSubmit.pose.orientation.y = LayerOrientation.Y;
			layerSubmit.pose.orientation.z = LayerOrientation.Z;
			layerSubmit.pose.orientation.w = LayerOrientation.W;
			layerSubmit.pose.position.x = LayerPosition.X;
			layerSubmit.pose.position.y = LayerPosition.Y;
			layerSubmit.pose.position.z = LayerPosition.Z;

			float QuadSizeY = (LayerDesc.Flags & IStereoLayers::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO) ? LayerDesc.QuadSize.X * AspectRatio : LayerDesc.QuadSize.Y;
			layerSubmit.size[0] = (float)(LayerDesc.QuadSize.X * Scale.X);
			layerSubmit.size[1] = (float)(QuadSizeY * Scale.Y);

			Pxr_SubmitLayer((PxrLayerHeader*)&layerSubmit);
		}
		else if (ShapeType == (int32)PxrLayerShape::PXR_LAYER_CYLINDER)
		{
			PxrLayerCylinder layerSubmit = {};
			layerSubmit.header.layerId = PxrLayerID;
			layerSubmit.header.compositionDepth = 0;
			layerSubmit.header.sensorFrameIndex = Frame->ViewNumber;
			layerSubmit.header.layerFlags = Flags;

			layerSubmit.header.colorScale[0] = bAdjustLayersColor ? HMDDevice->GColorScale.R : 1.0f;
			layerSubmit.header.colorScale[1] = bAdjustLayersColor ? HMDDevice->GColorScale.G : 1.0f;
			layerSubmit.header.colorScale[2] = bAdjustLayersColor ? HMDDevice->GColorScale.B : 1.0f;
			layerSubmit.header.colorScale[3] = bAdjustLayersColor ? HMDDevice->GColorScale.A : 1.0f;

			layerSubmit.header.colorBias[0] = bAdjustLayersColor ? HMDDevice->GColorOffset.R : 0.0f;
			layerSubmit.header.colorBias[1] = bAdjustLayersColor ? HMDDevice->GColorOffset.G : 0.0f;
			layerSubmit.header.colorBias[2] = bAdjustLayersColor ? HMDDevice->GColorOffset.B : 0.0f;
			layerSubmit.header.colorBias[3] = bAdjustLayersColor ? HMDDevice->GColorOffset.A : 0.0f;

			layerSubmit.pose.orientation.x = LayerOrientation.X;
			layerSubmit.pose.orientation.y = LayerOrientation.Y;
			layerSubmit.pose.orientation.z = LayerOrientation.Z;
			layerSubmit.pose.orientation.w = LayerOrientation.W;
			layerSubmit.pose.position.x = LayerPosition.X;
			layerSubmit.pose.position.y = LayerPosition.Y;
			layerSubmit.pose.position.z = LayerPosition.Z;

#if ENGINE_MINOR_VERSION > 24
			const FCylinderLayer& CylinderProps = LayerDesc.GetShape<FCylinderLayer>();
			float CylinderHeight = (LayerDesc.Flags & IStereoLayers::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO) ? CylinderProps.OverlayArc * AspectRatio : CylinderProps.Height;
			layerSubmit.centralAngle = CylinderProps.OverlayArc / CylinderProps.Radius;
			layerSubmit.height = CylinderHeight * Scale.X;
			layerSubmit.radius = CylinderProps.Radius * Scale.X;
#else
			float CylinderHeight = (LayerDesc.Flags & IStereoLayers::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO) ? LayerDesc.CylinderOverlayArc * AspectRatio : LayerDesc.CylinderHeight;
			layerSubmit.centralAngle = LayerDesc.CylinderOverlayArc / LayerDesc.CylinderRadius;
			layerSubmit.height = CylinderHeight * Scale.X;
			layerSubmit.radius = LayerDesc.CylinderRadius * Scale.X;
#endif
			Pxr_SubmitLayer((PxrLayerHeader*)&layerSubmit);
		}
		else if (ShapeType == (int32)PxrLayerShape::PXR_LAYER_EQUIRECT)
		{
			PxrLayerEquirect layerSubmit = {};
			layerSubmit.header.layerId = PxrLayerID;
			layerSubmit.header.compositionDepth = 0;
			layerSubmit.header.sensorFrameIndex = Frame->ViewNumber;
			layerSubmit.header.layerFlags = Flags;
			layerSubmit.header.layerShape = PxrLayerShape::PXR_LAYER_EQUIRECT;
			layerSubmit.header.useImageRect = 1;

			layerSubmit.header.colorScale[0] = bAdjustLayersColor ? HMDDevice->GColorScale.R : 1.0f;
			layerSubmit.header.colorScale[1] = bAdjustLayersColor ? HMDDevice->GColorScale.G : 1.0f;
			layerSubmit.header.colorScale[2] = bAdjustLayersColor ? HMDDevice->GColorScale.B : 1.0f;
			layerSubmit.header.colorScale[3] = bAdjustLayersColor ? HMDDevice->GColorScale.A : 1.0f;

			layerSubmit.header.colorBias[0] = bAdjustLayersColor ? HMDDevice->GColorOffset.R : 0.0f;
			layerSubmit.header.colorBias[1] = bAdjustLayersColor ? HMDDevice->GColorOffset.G : 0.0f;
			layerSubmit.header.colorBias[2] = bAdjustLayersColor ? HMDDevice->GColorOffset.B : 0.0f;
			layerSubmit.header.colorBias[3] = bAdjustLayersColor ? HMDDevice->GColorOffset.A : 0.0f;

#if ENGINE_MAJOR_VERSION >=5 || ENGINE_MINOR_VERSION >=25
			const FEquirectLayer& EquirectProps = LayerDesc.GetShape<FEquirectLayer>();
#else
			const IStereoLayers::FEquirectProps& EquirectProps = LayerDesc.EquirectProps;
#endif
			float ScaleX[2], ScaleY[2], BiasX[2], BiasY[2], imagerectx[2], imagerecty[2], imagerectwidth[2], imagerectheight[2], umax[2], umin[2], vmax[2], vmin[2];
			umax[0] = EquirectProps.LeftUVRect.Max.X;
			umin[0] = EquirectProps.LeftUVRect.Min.X;
			vmax[0] = EquirectProps.LeftUVRect.Max.Y;
			vmin[0] = EquirectProps.LeftUVRect.Min.Y;
			umax[1] = EquirectProps.RightUVRect.Max.X;
			umin[1] = EquirectProps.RightUVRect.Min.X;
			vmax[1] = EquirectProps.RightUVRect.Max.Y;
			vmin[1] = EquirectProps.RightUVRect.Min.Y;
			//Scale is not currently used
			ScaleX[0] = EquirectProps.LeftScale.X;
			ScaleY[0] = EquirectProps.LeftScale.Y;
			ScaleX[1] = EquirectProps.RightScale.X;
			ScaleY[1] = EquirectProps.RightScale.Y;
			//Bias not currently used
			BiasX[0] = EquirectProps.LeftBias.X;
			BiasY[0] = EquirectProps.LeftBias.Y;
			BiasX[1] = EquirectProps.RightBias.X;
			BiasY[1] = EquirectProps.RightBias.Y;

			for (int32 EyeIndex = 0; EyeIndex < 2; EyeIndex++)
			{
				//The UV far point of the engine is in the upper left corner
				float temp = vmin[EyeIndex];
				vmin[EyeIndex] = 1 - vmax[EyeIndex];
				vmax[EyeIndex] = 1 - temp;
				//Sphere radius
				layerSubmit.radius[EyeIndex] = 100.0f;
				//Layer pose
				layerSubmit.pose[EyeIndex].orientation.x = LayerOrientation.X;
				layerSubmit.pose[EyeIndex].orientation.y = LayerOrientation.Y;
				layerSubmit.pose[EyeIndex].orientation.z = LayerOrientation.Z;
				layerSubmit.pose[EyeIndex].orientation.w = LayerOrientation.W;
				layerSubmit.pose[EyeIndex].position.x = LayerPosition.X;
				layerSubmit.pose[EyeIndex].position.y = LayerPosition.Y;
				layerSubmit.pose[EyeIndex].position.z = LayerPosition.Z;
				//SrcRect
				imagerectx[EyeIndex] = (int)(umin[EyeIndex] * PxrLayerCreateParam.width);
				imagerecty[EyeIndex] = (int)(vmin[EyeIndex] * PxrLayerCreateParam.height);
				imagerectwidth[EyeIndex] = PxrLayerCreateParam.width * (umax[EyeIndex] - umin[EyeIndex]);
				imagerectheight[EyeIndex] = PxrLayerCreateParam.height * (vmax[EyeIndex] - vmin[EyeIndex]);
				layerSubmit.header.imageRect[EyeIndex] = { (int)imagerectx[EyeIndex], (int)imagerecty[EyeIndex], (int)imagerectwidth[EyeIndex],(int)imagerectheight[EyeIndex] };
				//DstRect
				BiasX[EyeIndex] = -umin[EyeIndex] / (umax[EyeIndex] - umin[EyeIndex]);
				BiasY[EyeIndex] = (vmax[EyeIndex] - 1) / (vmax[EyeIndex] - vmin[EyeIndex]);
				ScaleX[EyeIndex] = 1 / (umax[EyeIndex] - umin[EyeIndex]);
				ScaleY[EyeIndex] = 1 / (vmax[EyeIndex] - vmin[EyeIndex]);
				layerSubmit.scaleX[EyeIndex] = ScaleX[EyeIndex];
				layerSubmit.scaleY[EyeIndex] = ScaleY[EyeIndex];
				layerSubmit.biasX[EyeIndex] = BiasX[EyeIndex];
				layerSubmit.biasY[EyeIndex] = BiasY[EyeIndex];
				PXR_LOGV(PxrUnreal, "EyeIndex:%d,ScaleX:%f,ScaleY:%f，BiasX:%f，BiasY:%f，imagerectx:%f，imagerecty:%f,imagerectwidth:%f,imagerectheight:%f",
					EyeIndex, ScaleX[EyeIndex], ScaleY[EyeIndex], BiasX[EyeIndex], BiasY[EyeIndex], imagerectx[EyeIndex], imagerecty[EyeIndex], imagerectwidth[EyeIndex], imagerectheight[EyeIndex]);
			}
			int result;
			result = Pxr_SubmitLayer2((PxrLayerHeader2*)&layerSubmit);
			if (result != (int)PxrReturnStatus::PXR_RET_SUCCESS)
			{
				PXR_LOGE(PxrUnreal, "Submit Layer:%d PxrLayerEquirect Failed!:%d", PxrLayerID, result);
			}
		}
		else if (ShapeType == (int32)PxrLayerShape::PXR_LAYER_CUBE)
		{
			PxrLayerCube2 layerSubmit = {};
			layerSubmit.header.layerId = PxrLayerID;
			layerSubmit.header.compositionDepth = 0;
			layerSubmit.header.sensorFrameIndex = Frame->ViewNumber;
			layerSubmit.header.layerFlags = Flags;
			layerSubmit.header.layerShape = PxrLayerShape::PXR_LAYER_CUBE;

			layerSubmit.header.colorScale[0] = bAdjustLayersColor ? HMDDevice->GColorScale.R : 1.0f;
			layerSubmit.header.colorScale[1] = bAdjustLayersColor ? HMDDevice->GColorScale.G : 1.0f;
			layerSubmit.header.colorScale[2] = bAdjustLayersColor ? HMDDevice->GColorScale.B : 1.0f;
			layerSubmit.header.colorScale[3] = bAdjustLayersColor ? HMDDevice->GColorScale.A : 1.0f;

			layerSubmit.header.colorBias[0] = bAdjustLayersColor ? HMDDevice->GColorOffset.R : 0.0f;
			layerSubmit.header.colorBias[1] = bAdjustLayersColor ? HMDDevice->GColorOffset.G : 0.0f;
			layerSubmit.header.colorBias[2] = bAdjustLayersColor ? HMDDevice->GColorOffset.B : 0.0f;
			layerSubmit.header.colorBias[3] = bAdjustLayersColor ? HMDDevice->GColorOffset.A : 0.0f;

			for (int32 EyeIndex = 0; EyeIndex < 2; EyeIndex++)
			{
				layerSubmit.pose[EyeIndex].orientation.x = LayerOrientation.X;
				layerSubmit.pose[EyeIndex].orientation.y = LayerOrientation.Y;
				layerSubmit.pose[EyeIndex].orientation.z = LayerOrientation.Z;
				layerSubmit.pose[EyeIndex].orientation.w = LayerOrientation.W;
				layerSubmit.pose[EyeIndex].position.x = LayerPosition.X;
				layerSubmit.pose[EyeIndex].position.y = LayerPosition.Y;
				layerSubmit.pose[EyeIndex].position.z = LayerPosition.Z;
			}
			int result;
			result = Pxr_SubmitLayer2((PxrLayerHeader2*)&layerSubmit);
			if (result != (int)PxrReturnStatus::PXR_RET_SUCCESS)
			{
				PXR_LOGE(PxrUnreal, "Submit Layer:%d PxrLayerCube2 Failed!:%d", PxrLayerID, result);
			}
		}
	}
#endif
}

int32 FPICOXRStereoLayer::GetShapeType()
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
	else if (LayerDesc.HasShape<FEquirectLayer>())
	{
		ShapeType = 3;
	}
	else if (LayerDesc.HasShape<FCubemapLayer>())
	{
		ShapeType = 5;
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
	case IStereoLayers::EquirectLayer:
		ShapeType = 3;
		break;
	case IStereoLayers::CubemapLayer:
		ShapeType = 5;
		break;
	default:
		ShapeType = 0;
		break;
	}
#endif
#endif
	return ShapeType;
}

void FPICOXRStereoLayer::SetProjectionLayerParams(uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, FString RHIString)
{
#if PLATFORM_ANDROID
	PxrLayerCreateParam.layerShape = PXR_LAYER_PROJECTION;
	PxrLayerCreateParam.width = SizeX;
	PxrLayerCreateParam.height = SizeY;
	PxrLayerCreateParam.faceCount = 1;
	PxrLayerCreateParam.mipmapCount = NumMips;
	PxrLayerCreateParam.sampleCount = NumSamples;
	PxrLayerCreateParam.arraySize = ArraySize;
	PxrLayerCreateParam.layerLayout = (ArraySize == 2 ? PXR_LAYER_LAYOUT_ARRAY : PXR_LAYER_LAYOUT_DOUBLE_WIDE);
	if (RHIString == TEXT("OpenGL"))
	{
		PxrLayerCreateParam.format = IsMobileColorsRGB() ? GL_SRGB8_ALPHA8 : GL_RGBA8;
	}
	else if (RHIString == TEXT("Vulkan"))
	{
		PxrLayerCreateParam.format = IsMobileColorsRGB() ? VK_FORMAT_R8G8B8A8_SRGB : VK_FORMAT_R8G8B8A8_UNORM;
	}
	if (bSplashBlackProjectionLayer)
	{
		PxrLayerCreateParam.layerFlags |= PXR_LAYER_FLAG_STATIC_IMAGE;
	}
#endif
}

