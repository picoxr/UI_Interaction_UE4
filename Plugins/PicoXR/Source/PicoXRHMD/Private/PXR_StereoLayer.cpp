// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#include "PXR_StereoLayer.h"

#include "DataDrivenShaderPlatformInfo.h"
#include "PXR_HMDPrivateRHI.h"
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



#ifdef PICO_CUSTOM_ENGINE
void GetTrackingSpaceDeltaPose(const FGameSettings* Setting, const FPXRGameFrame* Frame, FTransform& TrackingSpaceDeltaPose)
{
	TrackingSpaceDeltaPose = Frame->TrackingToWorld * Frame->LastTrackingToWorld.Inverse();
	PXR_LOGV(PxrUnreal, "AppSpaceWarp GetTrackingSpaceDeltaPose TrackingToWorld:%s LastTrackingToWorld.Inverse():%s"
		,PLATFORM_CHAR(*Frame->TrackingToWorld.ToString())
		,PLATFORM_CHAR(*Frame->LastTrackingToWorld.Inverse().ToString()));
	PXR_LOGV(PxrUnreal, "AppSpaceWarp GetTrackingSpaceDeltaPose TrackingSpaceDeltaPose 1:%s"
		,PLATFORM_CHAR(*TrackingSpaceDeltaPose.ToString()));
	FTransform SettingBasePose = FTransform(Setting->BaseOrientation, Setting->BaseOffset);
	PXR_LOGV(PxrUnreal, "AppSpaceWarp GetTrackingSpaceDeltaPose SettingBasePose Orientation:X:%f,Y:%f,Z:%f,W:%f"
		, Setting->BaseOrientation.X
		, Setting->BaseOrientation.Y
		, Setting->BaseOrientation.Z
		, Setting->BaseOrientation.W);
	TrackingSpaceDeltaPose = SettingBasePose.Inverse() * TrackingSpaceDeltaPose * SettingBasePose;
	
	PXR_LOGV(PxrUnreal, "AppSpaceWarp TrackingSpaceDeltaPose 2:%s",PLATFORM_CHAR(*TrackingSpaceDeltaPose.ToString()));
}
#endif

FPxrLayer::FPxrLayer(uint32 ID, uint32 InPxrLayerId, FDelayDeleteLayerManager* InDelayDeletion) :
	ID(ID),
	PxrLayerId(InPxrLayerId),
	DelayDeletion(InDelayDeletion)
{
}

FPxrLayer::~FPxrLayer()
{
	if (IsInGameThread())
	{
		ExecuteOnRenderThread([ID = this->ID, PxrLayerId = this->PxrLayerId, DelayDeletion = this->DelayDeletion]()
		{
			DelayDeletion->AddPxrLayerToDeferredDeletionQueue(ID, PxrLayerId);
		});
	}
	else
	{
		DelayDeletion->AddPxrLayerToDeferredDeletionQueue(ID, PxrLayerId);
	}
}

uint64_t OverlayImages[2] = {};
uint64_t OverlayNativeImages[2][3] = {};

uint32 FPICOXRStereoLayer::PxrLayerIDCounter = 0;

FPICOXRStereoLayer::FPICOXRStereoLayer(FPICOXRHMD* InHMDDevice, uint32 InPXRLayerId, const IStereoLayers::FLayerDesc& InDesc)
	: bSplashLayer(false)
	, bSplashBlackProjectionLayer(false)
	, bMRCLayer(false)
	, bNeedsTexSrgbCreate(false)
#ifdef PICO_CUSTOM_ENGINE
	, bEnableEyeTrackingFoveationRendering(false)
#endif
    , HMDDevice(InHMDDevice)
	, ID(InPXRLayerId)
	, PxrLayerID(0)
    , bTextureNeedUpdate(false)
    , UnderlayMeshComponent(NULL)
    , UnderlayActor(NULL)
    , PxrLayer(nullptr)
	, TrackingMode(PXR_TRACKING_MODE_POSITION_BIT)
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
	, bNeedsTexSrgbCreate(InPXRLayer.bNeedsTexSrgbCreate)
#ifdef PICO_CUSTOM_ENGINE
	, bEnableEyeTrackingFoveationRendering(InPXRLayer.bEnableEyeTrackingFoveationRendering)
#endif
    , HMDDevice(InPXRLayer.HMDDevice)
	, ID(InPXRLayer.ID)
	, PxrLayerID(InPXRLayer.PxrLayerID)
    , LayerDesc(InPXRLayer.LayerDesc)
    , SwapChain(InPXRLayer.SwapChain)
    , LeftSwapChain(InPXRLayer.LeftSwapChain)
    , FoveationSwapChain(InPXRLayer.FoveationSwapChain)
#ifdef PICO_CUSTOM_ENGINE
	, MotionVectorSwapChain(InPXRLayer.MotionVectorSwapChain)
	, MotionVectorDepthSwapChain(InPXRLayer.MotionVectorDepthSwapChain)
#endif
    , bTextureNeedUpdate(InPXRLayer.bTextureNeedUpdate)
    , UnderlayMeshComponent(InPXRLayer.UnderlayMeshComponent)
    , UnderlayActor(InPXRLayer.UnderlayActor)
    , PxrLayer(InPXRLayer.PxrLayer)
	, TrackingMode(InPXRLayer.TrackingMode)
{
	FMemory::Memcpy(&PxrLayerCreateParam, &InPXRLayer.PxrLayerCreateParam, sizeof(PxrLayerCreateParam));
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
	bool bRatioChanged = (LayerDesc.Flags & IStereoLayers::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO) != (InDesc.Flags & IStereoLayers::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO);
	
	if (LayerDesc.Texture != InDesc.Texture || LayerDesc.LeftTexture != InDesc.LeftTexture)
	{
		bTextureNeedUpdate = true;
	}
	LayerDesc = InDesc;

	ManageUnderlayComponent(bRatioChanged);
}

void FPICOXRStereoLayer::ManageUnderlayComponent(bool bRatioChanged)
{
	if (IsLayerSupportDepth())
	{
		if (bRatioChanged)
		{
			DestroyUnderlayMesh();
		}
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
		if (IsValid(UnderlayMeshComponent))
		{
			UnderlayMeshComponent->SetWorldTransform(LayerDesc.Transform);
		}
		else
		{
			PXR_LOGD(PxrUnreal, "UnderlayMeshComponent IsValid False，DestroyUnderlayMesh！！");
			DestroyUnderlayMesh();
		}
	}
	else
	{
		DestroyUnderlayMesh();
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
	if (LayerDesc.HasShape<FQuadLayer>())
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
	else if (LayerDesc.HasShape<FCylinderLayer>())
	{
		float Arc, Radius, Height;
		const FCylinderLayer& CylinderProps = LayerDesc.GetShape<FCylinderLayer>();
		Arc = CylinderProps.OverlayArc;
		Radius = CylinderProps.Radius;
		Height = CylinderProps.Height;
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
	else if (LayerDesc.HasShape<FCubemapLayer>())
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
	else if (LayerDesc.HasShape<FEACLayer>())
	{
		float Scale;
		const FEACLayer& EACProps = LayerDesc.GetShape<FEACLayer>();
		Scale = EACProps.Scale;

		// Implements a cube mesh
		// Cubemap Scale should be changed eventually to incorporate scale
		Vertices.Init(FVector::ZeroVector, 8);
		Vertices[0] = FVector(-1.0, -1.0, -1.0) * Scale;
		Vertices[1] = FVector(-1.0, -1.0, 1.0) * Scale;
		Vertices[2] = FVector(-1.0, 1.0, -1.0) * Scale;
		Vertices[3] = FVector(-1.0, 1.0, 1.0) * Scale;
		Vertices[4] = FVector(1.0, -1.0, -1.0) * Scale;
		Vertices[5] = FVector(1.0, -1.0, 1.0) * Scale;
		Vertices[6] = FVector(1.0, 1.0, -1.0) * Scale;
		Vertices[7] = FVector(1.0, 1.0, 1.0) * Scale;

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
			bool bInvertY = bMRCLayer || LayerDesc.HasShape<FCubemapLayer>() ? true : false;
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
				RenderBridge->TransferImage_RenderThread(RHICmdList, LeftDstTexture, LeftSrcTexture, DstRect, SrcRect, true, bNoAlpha, bMRCLayer, bInvertY);
			}

			bTextureNeedUpdate = false;
		}
		else
		{
			DestroyUnderlayMesh();
		}
	}
}

bool FPICOXRStereoLayer::InitPXRLayer_RenderThread(const FGameSettings* Settings, FPICOXRRenderBridge* CustomPresent, FDelayDeleteLayerManager* DelayDeletion, FRHICommandListImmediate& RHICmdList, const FPICOXRStereoLayer* InLayer)
{
	check(IsInRenderingThread());

	int32 MSAAValue = 1;
	bool bNeedFFRSwapChain = false;
#ifdef PICO_CUSTOM_ENGINE
	bool bNeedMotionVectorSwapChain=false;
#endif
	if (ID == 0)
	{
		static const auto CVarMobileMSAA = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("r.MSAACount"));
		MSAAValue = (CVarMobileMSAA ? CVarMobileMSAA->GetValueOnAnyThread() : 1);

		if (CustomPresent->RHIString == TEXT("Vulkan"))
		{
			bNeedFFRSwapChain = true;
		}
#ifdef PICO_CUSTOM_ENGINE
		if (HMDDevice->IsSupportsSpaceWarp())
		{
			bNeedMotionVectorSwapChain=true;
		}
#endif

	}
	else if(bSplashBlackProjectionLayer)
	{
		uint32 SizeX = 1;
		uint32 SizeY = 1;
		if (LayerDesc.Texture.IsValid())
		{
			FRHITexture2D* Texture2D = LayerDesc.Texture->GetTexture2D();
			if (Texture2D)
			{
				SizeX = Texture2D->GetSizeX();
				SizeY = Texture2D->GetSizeY();
			}
		}
		uint32 Layout = 1;
		if (HMDDevice->IsUsingMobileMultiView() && IsMobilePlatform(Settings->CurrentShaderPlatform))
		{
			Layout = 2;
		}
		PxrLayerCreateParam.layerShape = PXR_LAYER_PROJECTION;
		PxrLayerCreateParam.width = SizeX;
		PxrLayerCreateParam.height = SizeY;
		PxrLayerCreateParam.faceCount = 1;
		PxrLayerCreateParam.mipmapCount = 1;
		PxrLayerCreateParam.sampleCount = 1;
		PxrLayerCreateParam.arraySize = Layout;
		PxrLayerCreateParam.layerLayout = Layout == 2 ? PXR_LAYER_LAYOUT_ARRAY : PXR_LAYER_LAYOUT_DOUBLE_WIDE;
#if PLATFORM_ANDROID
		 if (CustomPresent->RHIString == TEXT("Vulkan"))
		{
			PxrLayerCreateParam.format = IsMobileColorsRGB() ? VK_FORMAT_R8G8B8A8_SRGB : VK_FORMAT_R8G8B8A8_UNORM;
		}
#endif
		PxrLayerCreateParam.layerFlags |= PXR_LAYER_FLAG_STATIC_IMAGE;
	}
	else
	{
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
				PxrLayerCreateParam.mipmapCount = Texture2D->GetNumMips();
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

		if (PxrLayerCreateParam.layerShape == PxrLayerShape::PXR_LAYER_CUBE /* || PxrLayerCreateParam.layerShape == PxrLayerShape::PXR_LAYER_EAC */)
		{
			PxrLayerCreateParam.faceCount = 6;
		}
		else
		{
			PxrLayerCreateParam.faceCount = 1;
		}
		PxrLayerCreateParam.arraySize = 1;

		if (!(LayerDesc.Flags & IStereoLayers::LAYER_FLAG_TEX_CONTINUOUS_UPDATE))
		{
			PxrLayerCreateParam.layerFlags |= PXR_LAYER_FLAG_STATIC_IMAGE;
		}
		else
		{
			PxrLayerCreateParam.layerFlags &= ~PXR_LAYER_FLAG_STATIC_IMAGE;
		}

		PxrLayerCreateParam.layerLayout = LayerDesc.LeftTexture.IsValid() ? PXR_LAYER_LAYOUT_STEREO : PXR_LAYER_LAYOUT_MONO;
#if PLATFORM_ANDROID
		 if (CustomPresent->RHIString == TEXT("Vulkan"))
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
#ifdef PICO_CUSTOM_ENGINE
		MotionVectorSwapChain=InLayer->MotionVectorSwapChain;
		MotionVectorDepthSwapChain=InLayer->MotionVectorDepthSwapChain;
#endif
		bTextureNeedUpdate |= InLayer->bTextureNeedUpdate;
		bNeedsTexSrgbCreate = InLayer->bNeedsTexSrgbCreate;
	}
    else
	{
		TArray<uint64> TextureResources;
		TArray<uint64> LeftTextureResources;
		TArray<uint64> FFRTextureResources;
#ifdef PICO_CUSTOM_ENGINE
		TArray<uint64> MotionVectorTextureResources;
		TArray<uint64> MotionVectorDepthTextureResources;
#endif
		uint32_t FoveationWidth = 0;
		uint32_t FoveationHeight = 0;
		TextureResources.Empty();
		LeftTextureResources.Empty();
		FFRTextureResources.Empty();
		bool bNativeTextureCreated = false;
#ifdef PICO_CUSTOM_ENGINE
		int RenderTextureX = 0;
		int RenderTextureY = 0;
		FPICOXRHMDModule::GetPluginWrapper().GetConfigInt(PXR_RENDER_TEXTURE_WIDTH, &RenderTextureX);
		FPICOXRHMDModule::GetPluginWrapper().GetConfigInt(PXR_RENDER_TEXTURE_HEIGHT, &RenderTextureY);
		const uint32_t MotionVectorWidth = RenderTextureX/4;
		const uint32_t MotionVectorHeight =RenderTextureY/4;
		const uint32_t MotionVectorDepthWidth = MotionVectorWidth;
		const uint32_t MotionVectorDepthHeight = MotionVectorHeight;
		
		PXR_LOGI(PxrUnreal, "MotionVectorWidth =%d", MotionVectorWidth);
		PXR_LOGI(PxrUnreal, "MotionVectorHeight =%d", MotionVectorHeight);
#endif
		ExecuteOnRHIThread([&]()
			{
#if PLATFORM_ANDROID
				PxrLayerCreateParam.layerId = PxrLayerID = PxrLayerIDCounter;
				if (FPICOXRHMDModule::GetPluginWrapper().bIsSessionInitialized && (FPICOXRHMDModule::GetPluginWrapper().CreateLayer(&PxrLayerCreateParam) == 0))
				{
					PxrLayerIDCounter++;
					uint32_t ImageCounts = 0;
					uint64_t LayerImages[2][3] = {};
					uint64_t FoveationImages[3]={};
#ifdef PICO_CUSTOM_ENGINE
					uint64_t MotionVectorImages[3]={};
					uint64_t MotionDepthImages[3]={};
#endif
					FPICOXRHMDModule::GetPluginWrapper().GetLayerImageCount(PxrLayerID, PXR_EYE_RIGHT, &ImageCounts);
					ensure(ImageCounts != 0);
					for (uint32_t i = 0; i < ImageCounts; i++)
					{
						FPICOXRHMDModule::GetPluginWrapper().GetLayerImage(PxrLayerID, PXR_EYE_RIGHT, i, &LayerImages[1][i]);
						PXR_LOGI(PxrUnreal, "Pxr_GetLayerImage Right LayerImages[1][%d]=u_%u", i, (uint32_t)LayerImages[1][i]);
						TextureResources.Add(LayerImages[1][i]);
#ifdef PICO_CUSTOM_ENGINE
						if (bNeedMotionVectorSwapChain)
						{
							FPICOXRHMDModule::GetPluginWrapper().GetLayerImageExt(PxrLayerID,PXR_EYE_RIGHT,i,&MotionVectorImages[i],PXR_LAYER_IMAGE_TYPE_MOTION_VECTOR);
							PXR_LOGI(PxrUnreal, "Pxr_GetLayerImageExt Right MotionVectorImage[%d]=u_%u", i, (uint32_t)MotionVectorImages[i]);

							FPICOXRHMDModule::GetPluginWrapper().GetLayerImageExt(PxrLayerID,PXR_EYE_RIGHT,i,&MotionDepthImages[i],PXR_LAYER_IMAGE_TYPE_DEPTH);
							PXR_LOGI(PxrUnreal, "Pxr_GetLayerImageExt Right MotionDepthImage[%d]=u_%u", i, (uint32_t)MotionDepthImages[i]);

							MotionVectorTextureResources.Add(MotionVectorImages[i]);
							MotionVectorDepthTextureResources.Add(MotionDepthImages[i]);
						}
#endif

						if (bNeedFFRSwapChain)
						{
							if (i == 0) {
								FPICOXRHMDModule::GetPluginWrapper().GetLayerFoveationImage(PxrLayerID, PXR_EYE_RIGHT, &FoveationImages[0], &FoveationWidth, &FoveationHeight);
							} else {
								FPICOXRHMDModule::GetPluginWrapper().GetLayerImageExt(PxrLayerID, PXR_EYE_RIGHT, i, &FoveationImages[i], PXR_LAYER_IMAGE_TYPE_FDM);
							}

							FFRTextureResources.Add(FoveationImages[i]);
						}
					}

					if (PxrLayerCreateParam.layerLayout == PXR_LAYER_LAYOUT_STEREO)
					{
						FPICOXRHMDModule::GetPluginWrapper().GetLayerImageCount(PxrLayerID, PXR_EYE_LEFT, &ImageCounts);
						ensure(ImageCounts != 0);
						for (uint32_t i = 0; i < ImageCounts; i++)
						{
							FPICOXRHMDModule::GetPluginWrapper().GetLayerImage(PxrLayerID, PXR_EYE_LEFT, i, &LayerImages[0][i]);
							PXR_LOGI(PxrUnreal, "Pxr_GetLayerImage Left LayerImages[0][%d]=u_%u", i, (uint32_t)LayerImages[0][i]);
							LeftTextureResources.Add(LayerImages[0][i]);
						}
					}

					bNativeTextureCreated = true;
				}
				else
				{
					PXR_LOGE(PxrUnreal, "Create native texture failed!");
				}
#endif
			});

		if (bNativeTextureCreated)
		{
			PxrLayer = MakeShareable<FPxrLayer>(new FPxrLayer(ID, PxrLayerID, DelayDeletion));

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

			ETextureCreateFlags Flags= TexCreate_None;
			ETextureCreateFlags TargetableTextureFlags= TexCreate_None;
			Flags = TargetableTextureFlags |= TexCreate_RenderTargetable | TexCreate_ShaderResource |TexCreate_ResolveTargetable |(IsMobileColorsRGB() ? TexCreate_SRGB : TexCreate_None);

			SwapChain = CustomPresent->CreateSwapChain_RenderThread(ID,PxrLayerID, ResourceType, TextureResources, PF_R8G8B8A8, PxrLayerCreateParam.width, PxrLayerCreateParam.height, PxrLayerCreateParam.arraySize, PxrLayerCreateParam.mipmapCount, PxrLayerCreateParam.sampleCount, Flags, TargetableTextureFlags, MSAAValue);
			if (PxrLayerCreateParam.layerLayout == PXR_LAYER_LAYOUT_STEREO)
			{
				LeftSwapChain = CustomPresent->CreateSwapChain_RenderThread(ID,PxrLayerID, ResourceType, LeftTextureResources, PF_R8G8B8A8, PxrLayerCreateParam.width, PxrLayerCreateParam.height, PxrLayerCreateParam.arraySize, PxrLayerCreateParam.mipmapCount, PxrLayerCreateParam.sampleCount, Flags, TargetableTextureFlags, MSAAValue);
			}

			if (bNeedFFRSwapChain)
			{

				ETextureCreateFlags	TCF = TexCreate_Foveation;
				FoveationSwapChain = CustomPresent->CreateSwapChain_RenderThread(ID,PxrLayerID, ResourceType, FFRTextureResources, PF_R8G8, FoveationWidth, FoveationHeight, PxrLayerCreateParam.arraySize, 1, 1, Flags, TCF, 1);
			}	
#ifdef PICO_CUSTOM_ENGINE
			if (bNeedMotionVectorSwapChain)
			{
				EPixelFormat MvPixelFormat = PF_FloatRGBA;
				ETextureCreateFlags MVTexCreateFlags = TexCreate_ShaderResource | TexCreate_RenderTargetable;
				MotionVectorSwapChain = CustomPresent->CreateSwapChain_RenderThread(ID, PxrLayerID,ResourceType,MotionVectorTextureResources, MvPixelFormat, MotionVectorWidth, MotionVectorHeight, PxrLayerCreateParam.arraySize, 1, 1, MVTexCreateFlags, MVTexCreateFlags,1);
				if (MotionVectorDepthTextureResources.Num() && MotionVectorDepthTextureResources[0] != (unsigned long long)nullptr)
				{
					ETextureCreateFlags MVDepthTexCreateFlags = TexCreate_ShaderResource | TexCreate_DepthStencilTargetable;
					MotionVectorDepthSwapChain = CustomPresent->CreateSwapChain_RenderThread(ID, PxrLayerID,ResourceType,MotionVectorDepthTextureResources, PF_DepthStencil, MotionVectorDepthWidth, MotionVectorDepthHeight, PxrLayerCreateParam.arraySize, 1, 1, MVDepthTexCreateFlags, MVDepthTexCreateFlags,1);
				}
				else
				{
					MotionVectorDepthSwapChain = NULL;
				}
			}
			else
			{
				MotionVectorSwapChain.Reset();
				MotionVectorDepthSwapChain.Reset();
			}
#endif
			bTextureNeedUpdate = true;
		}
		else
		{
			PXR_LOGE(PxrUnreal, "Create SwapChain failed!");
			return false;
		}
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
		PxrLayerCreateParam.layerType != InLayer->PxrLayerCreateParam.layerType     ||
		bNeedsTexSrgbCreate != InLayer->bNeedsTexSrgbCreate
#ifdef PICO_CUSTOM_ENGINE
		|| bEnableEyeTrackingFoveationRendering != InLayer->bEnableEyeTrackingFoveationRendering
#endif
		)
	{
		return false;
	}

	if (TrackingMode != InLayer->TrackingMode)
	{
		return false;
	}
#endif

	return true;
}

void FPICOXRStereoLayer::ReleaseResources_RHIThread()
{
	CheckInRHIThread();
	PxrLayerID = 0;
	PxrLayer.Reset();
	SwapChain.Reset();
	FoveationSwapChain.Reset();
	LeftSwapChain.Reset();
	bTextureNeedUpdate = false;
}

void FPICOXRStereoLayer::DestroyUnderlayMesh()
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
		FPICOXRHMDModule::GetPluginWrapper().GetLayerNextImageIndex(PxrLayerID, &index);
#endif
		while (index != SwapChain->GetSwapChainIndex_RHIThread())
		{
			SwapChain->IncrementSwapChainIndex_RHIThread();
		}
#ifdef PICO_CUSTOM_ENGINE		
		if (MotionVectorSwapChain.IsValid())
		{
			while (index != MotionVectorSwapChain->GetSwapChainIndex_RHIThread())
			{
				MotionVectorSwapChain->IncrementSwapChainIndex_RHIThread();
			}
		}
		if(MotionVectorDepthSwapChain.IsValid())
		{
			while (index != MotionVectorDepthSwapChain->GetSwapChainIndex_RHIThread())
			{
				MotionVectorDepthSwapChain->IncrementSwapChainIndex_RHIThread();
			}
		}
#endif
		if (LeftSwapChain && LeftSwapChain.IsValid())
		{
			while (index != LeftSwapChain->GetSwapChainIndex_RHIThread())
			{
				LeftSwapChain->IncrementSwapChainIndex_RHIThread();
			}
		}
	}
}

const void FPICOXRStereoLayer::SubmitLayer_RHIThread(const FGameSettings* Settings, const FPXRGameFrame* Frame)
{
	PXR_LOGV(PxrUnreal, "Submit Layer:%u", ID);
	float ColorScale[4] = { Settings->ColorScale.x, Settings->ColorScale.y, Settings->ColorScale.z, Settings->ColorScale.w };
	float ColorOffset[4] = { Settings->ColorOffset.x, Settings->ColorOffset.y, Settings->ColorOffset.z, Settings->ColorOffset.w };
	if (ID == 0)
	{
		PxrLayerProjection2 layerProjection = {};
		layerProjection.header.layerId = PxrLayerID;
		layerProjection.header.layerFlags = 0;
		layerProjection.header.sensorFrameIndex = Frame->ViewNumber;
		layerProjection.header.useLayerBlend=1;
		PxrLayerBlend layerBlend={};
		layerBlend.srcAlpha=PxrBlendFactor::PXR_BLEND_FACTOR_ONE;
		layerBlend.dstAlpha=PxrBlendFactor::PXR_BLEND_FACTOR_ONE;
		layerBlend.srcColor=PxrBlendFactor::PXR_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
		layerBlend.dstColor=PxrBlendFactor::PXR_BLEND_FACTOR_SRC_ALPHA;
		layerProjection.header.layerBlend=layerBlend;
        	
		if (!HMDDevice->bNeedDrawBlackEye)
		{
			FMemory::Memcpy(layerProjection.header.colorScale, ColorScale, sizeof(ColorScale));
			FMemory::Memcpy(layerProjection.header.colorBias, ColorOffset, sizeof(ColorOffset));
		}
#ifdef PICO_CUSTOM_ENGINE
		//PICO AppSpaceWarp
		static const auto CVarPICOEnableSpaceWarpInternal1 = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("r.Mobile.PICO.SpaceWarp.EnableInternal"));
		if (CVarPICOEnableSpaceWarpInternal1->GetValueOnAnyThread())
		{
			FTransform TrackingSpaceDeltaPose;
			GetTrackingSpaceDeltaPose(Settings, Frame, TrackingSpaceDeltaPose);
			FQuat PxrQuat=FPICOXRUtils::ConvertUnrealQuatToXRQuat(TrackingSpaceDeltaPose.GetRotation());
			FVector PxrLocation= FPICOXRUtils::ConvertUnrealVectorToXRVector(TrackingSpaceDeltaPose.GetLocation(),Frame->WorldToMetersScale);
			PxrPosef PxrDeltaPose = {};
			PxrDeltaPose.position.x=PxrLocation.X; 
			PxrDeltaPose.position.y=PxrLocation.Y;
			PxrDeltaPose.position.z=PxrLocation.Z;
			PXR_LOGV(PxrUnreal, "AppSpaceWarp SubmitLayer_RHIThread PxrDeltaPose.position:X:%f,Y:%f,Z:%f", PxrDeltaPose.position.x,PxrDeltaPose.position.y,PxrDeltaPose.position.z);
		
			PxrDeltaPose.orientation.x=PxrQuat.X;
			PxrDeltaPose.orientation.y=PxrQuat.Y;
			PxrDeltaPose.orientation.z=PxrQuat.Z;
			PxrDeltaPose.orientation.w=PxrQuat.W;
			PXR_LOGV(PxrUnreal, "AppSpaceWarp SubmitLayer_RHIThread PxrDeltaPose.orientation:X:%f,Y:%f,Z:%f,W:%f", PxrDeltaPose.orientation.x,PxrDeltaPose.orientation.y,PxrDeltaPose.orientation.z,PxrDeltaPose.orientation.w);

			layerProjection.deltaPose=PxrDeltaPose;
			layerProjection.header.layerFlags = PXR_LAYER_FLAG_USE_FRAME_EXTRAPOLATION;
			layerProjection.minDepth=0.1f;
			layerProjection.maxDepth=1.0f;
			//Todo:Infinity is not supported for now
			layerProjection.nearZ=1000000/Frame->WorldToMetersScale;
			//Todo:GNearClippingPlane No unit conversion, just pass it on？
			layerProjection.farZ=GNearClippingPlane/Frame->WorldToMetersScale;
		}
#endif

		static const auto CVarPICOSuperResolution = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("r.Mobile.PICO.EnableSuperResolution"));
		CVarPICOSuperResolution->GetValueOnAnyThread() == 1 ? layerProjection.header.layerFlags |= PXR_LAYER_FLAG_ENABLE_SUPER_RESOLUTION : layerProjection.header.layerFlags &= ~PXR_LAYER_FLAG_ENABLE_SUPER_RESOLUTION;
		PXR_LOGV(PxrUnreal, "SuperResolution is %d",CVarPICOSuperResolution->GetValueOnAnyThread());

		static const auto CVarPICOSharpening = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("r.Mobile.PICO.SharpeningSetting"));
		const EPICOXRSharpeningType SharpeningType = static_cast<EPICOXRSharpeningType>(CVarPICOSharpening->GetValueOnAnyThread());
		switch (SharpeningType) {
		case EPICOXRSharpeningType::NormalSharpening:
			{
				layerProjection.header.layerFlags |= PXR_LAYER_FLAG_ENABLE_NORMAL_SHARPENING;
				PXR_LOGV(PxrUnreal, "NormalSharpening Layer Flag is enable");
			}
			break;
		case EPICOXRSharpeningType::QualitySharpening:
			{
				layerProjection.header.layerFlags |= PXR_LAYER_FLAG_ENABLE_QUALITY_SHARPENING;
				PXR_LOGV(PxrUnreal, "QualitySharpening Layer Flag is enable");
			}
			break;
		default: ;
		}
		
		static const auto CVarPICOSharpeningEnhance = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("r.Mobile.PICO.SharpeningEnhanceMode"));
		const EPICOXRSharpeningEnhanceModeType EnhanceMode = static_cast<EPICOXRSharpeningEnhanceModeType>(CVarPICOSharpeningEnhance->GetValueOnAnyThread());
		switch (EnhanceMode) {
		case EPICOXRSharpeningEnhanceModeType::FixedFoveated:
			{
				layerProjection.header.layerFlags |= PXR_LAYER_FLAG_ENABLE_FIXED_FOVEATED_SHARPENING;
				PXR_LOGV(PxrUnreal, "FixedFoveatedSharpening Layer Flag is enable");
			}
			break;
		case EPICOXRSharpeningEnhanceModeType::Adaptive:
			{
				layerProjection.header.layerFlags |= PXR_LAYER_FLAG_ENABLE_SELF_ADAPTIVE_SHARPENING;
				PXR_LOGV(PxrUnreal, "AdaptiveSharpening Layer Flag is enable");
			}
			break;
		case EPICOXRSharpeningEnhanceModeType::Both:
			{
				layerProjection.header.layerFlags |= PXR_LAYER_FLAG_ENABLE_FIXED_FOVEATED_SHARPENING;
				layerProjection.header.layerFlags |= PXR_LAYER_FLAG_ENABLE_SELF_ADAPTIVE_SHARPENING;
				PXR_LOGV(PxrUnreal, "FixedFoveatedSharpening and AdaptiveSharpening Layer Flag is enable");
			}
			break;
		default: ;
		}
		FPICOXRHMDModule::GetPluginWrapper().SubmitLayer2((PxrLayerHeader2*)&layerProjection);
		PXR_LOGV(PxrUnreal, "SubmitLayer2 Flag is 0x%08x",layerProjection.header.layerFlags);

	}
	else if (bSplashBlackProjectionLayer)
	{
		PxrLayerProjection layerProjection = {};
		layerProjection.header.layerId = PxrLayerID;
		layerProjection.header.layerFlags = 0;
		layerProjection.header.sensorFrameIndex = Frame->ViewNumber;
		FPICOXRHMDModule::GetPluginWrapper().SubmitLayer((PxrLayerHeader*)&layerProjection);
	}
	else
	{			
		if (!Settings->bApplyColorScaleAndOffsetToAllLayers || bSplashLayer)
		{
			for (int32 i = 0; i < 4; i++)
			{
				ColorScale[i] = 1;
				ColorOffset[i] = 0;
			}
		}

		FTransform BaseTransform = FTransform::Identity;
		uint32 Flags = 0;
		Flags |= bMRCLayer ? (1 << 30) : 0;
		FVector LocationScaleInv(Frame->WorldToMetersScale);
		FVector LocationScale = LocationScaleInv.Reciprocal();
		PxrVector3f Scale = ToPxrVector3f(GetLayerScale() * LocationScale);
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

		FQuat Orientation = BaseTransform.GetRotation().Inverse() * GetLayerOrientation();
		FVector Location = BaseTransform.InverseTransformPosition(GetLayerLocation());
		FPose OutLayerPose = FPose(Orientation, Location);
		if (LayerDesc.PositionType != IStereoLayers::FaceLocked)
		{
			ConvertPose_Private(FPose(Orientation, Location), OutLayerPose, Settings->BaseOrientation.Inverse(), Settings->BaseOrientation.Inverse().RotateVector(-Settings->BaseOffset * LocationScaleInv), 1.0);
		}
		PxrPosef PxrLayerSubmitPose;
		PxrLayerSubmitPose.orientation = ToPxrQuatf(OutLayerPose.Orientation);
		PxrLayerSubmitPose.position = ToPxrVector3f(OutLayerPose.Position * LocationScale);

		int SizeX = PxrLayerCreateParam.width;
		int SizeY = PxrLayerCreateParam.height;
		float AspectRatio = SizeX ? (float)SizeY / (float)SizeX : 3.0f / 4.0f;

		int32 ShapeType = GetShapeType();
		if (ShapeType == (int32)PxrLayerShape::PXR_LAYER_QUAD)
		{
			PxrLayerQuad layerSubmit = {};
			layerSubmit.header.layerId = PxrLayerID;
			layerSubmit.header.compositionDepth = 0;
			layerSubmit.header.sensorFrameIndex = Frame->ViewNumber;
			layerSubmit.header.layerFlags = Flags;

			FMemory::Memcpy(layerSubmit.header.colorScale, ColorScale, sizeof(ColorScale));
			FMemory::Memcpy(layerSubmit.header.colorBias, ColorOffset, sizeof(ColorOffset));

			layerSubmit.pose = PxrLayerSubmitPose;

			float QuadSizeY = (LayerDesc.Flags & IStereoLayers::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO) ? LayerDesc.QuadSize.X * AspectRatio : LayerDesc.QuadSize.Y;
			layerSubmit.size[0] = (float)(LayerDesc.QuadSize.X * Scale.x);
			layerSubmit.size[1] = (float)(QuadSizeY * Scale.y);

			FPICOXRHMDModule::GetPluginWrapper().SubmitLayer((PxrLayerHeader*)&layerSubmit);
		}
		else if (ShapeType == (int32)PxrLayerShape::PXR_LAYER_CYLINDER)
		{
			PxrLayerCylinder layerSubmit = {};
			layerSubmit.header.layerId = PxrLayerID;
			layerSubmit.header.compositionDepth = 0;
			layerSubmit.header.sensorFrameIndex = Frame->ViewNumber;
			layerSubmit.header.layerFlags = Flags;

			FMemory::Memcpy(layerSubmit.header.colorScale, ColorScale, sizeof(ColorScale));
			FMemory::Memcpy(layerSubmit.header.colorBias, ColorOffset, sizeof(ColorOffset));

			layerSubmit.pose = PxrLayerSubmitPose;

			const FCylinderLayer& CylinderProps = LayerDesc.GetShape<FCylinderLayer>();
			float CylinderHeight = (LayerDesc.Flags & IStereoLayers::LAYER_FLAG_QUAD_PRESERVE_TEX_RATIO) ? CylinderProps.OverlayArc * AspectRatio : CylinderProps.Height;
			layerSubmit.centralAngle = CylinderProps.OverlayArc / CylinderProps.Radius;
			layerSubmit.height = CylinderHeight * Scale.x;
			layerSubmit.radius = CylinderProps.Radius * Scale.y;
			FPICOXRHMDModule::GetPluginWrapper().SubmitLayer((PxrLayerHeader*)&layerSubmit);
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

			FMemory::Memcpy(layerSubmit.header.colorScale, ColorScale, sizeof(ColorScale));
			FMemory::Memcpy(layerSubmit.header.colorBias, ColorOffset, sizeof(ColorOffset));

			const FEquirectLayer& EquirectProps = LayerDesc.GetShape<FEquirectLayer>();
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
				layerSubmit.pose[EyeIndex] = PxrLayerSubmitPose;
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
			result = FPICOXRHMDModule::GetPluginWrapper().SubmitLayer2((PxrLayerHeader2*)&layerSubmit);
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

			FMemory::Memcpy(layerSubmit.header.colorScale, ColorScale, sizeof(ColorScale));
			FMemory::Memcpy(layerSubmit.header.colorBias, ColorOffset, sizeof(ColorOffset));

			for (int32 EyeIndex = 0; EyeIndex < 2; EyeIndex++)
			{
				layerSubmit.pose[EyeIndex] = PxrLayerSubmitPose;
			}
			int result;
			result = FPICOXRHMDModule::GetPluginWrapper().SubmitLayer2((PxrLayerHeader2*)&layerSubmit);
			if (result != (int)PxrReturnStatus::PXR_RET_SUCCESS)
			{
				PXR_LOGE(PxrUnreal, "Submit Layer:%d PxrLayerCube2 Failed!:%d", PxrLayerID, result);
			}
		}
		else if (ShapeType == (int32)PxrLayerShape::PXR_LAYER_EAC)
		{
			const FEACLayer& EACProps = LayerDesc.GetShape<FEACLayer>();

			PxrLayerEAC2 layerSubmit = {};
			layerSubmit.header.layerId = PxrLayerID;
			layerSubmit.header.compositionDepth = -1;
			layerSubmit.header.sensorFrameIndex = Frame->ViewNumber;
			layerSubmit.header.layerFlags = Flags;
			layerSubmit.header.layerShape = PxrLayerShape::PXR_LAYER_EAC;
			layerSubmit.header.useImageRect = 1;

			FMemory::Memcpy(layerSubmit.header.colorScale, ColorScale, sizeof(ColorScale));
			FMemory::Memcpy(layerSubmit.header.colorBias, ColorOffset, sizeof(ColorOffset));

			/* Start of Unique Parameters for EAC */
			layerSubmit.modelType = EACProps.GetModelType();
			layerSubmit.overlapFactor = EACProps.OverlapFactor;

			for (int32 EyeIndex = 0; EyeIndex < 2; EyeIndex++)
			{
				layerSubmit.header.imageRect[EyeIndex] = {
					int32(FGenericPlatformMath::RoundToInt(SizeX * EACProps.UVRect[EyeIndex].Min.X)),
					int32(FGenericPlatformMath::RoundToInt(SizeY * EACProps.UVRect[EyeIndex].Min.Y)),
					int32(FGenericPlatformMath::RoundToInt(SizeX * (EACProps.UVRect[EyeIndex].GetSize().X))),
					int32(FGenericPlatformMath::RoundToInt(SizeY * (EACProps.UVRect[EyeIndex].GetSize().Y)))
				};

				layerSubmit.pose[EyeIndex] = PxrLayerSubmitPose;

				FVector Offset = FPICOXRUtils::ConvertUnrealVectorToXRVector(EACProps.Offset[EyeIndex], 1.0);
				FQuat OffsetRot = FPICOXRUtils::ConvertUnrealQuatToXRQuat(EACProps.OffsetRot[EyeIndex]);

				layerSubmit.offset[EyeIndex] = { float(Offset.X), float(Offset.Y), float(Offset.Z) };
				layerSubmit.offsetRot[EyeIndex] = { float(OffsetRot.X), float(OffsetRot.Y), float(OffsetRot.Z), float(OffsetRot.W) };
			}

			/* End of Unique Parameters for EAC */

			int result;
			result = FPICOXRHMDModule::GetPluginWrapper().SubmitLayer2((PxrLayerHeader2*)&layerSubmit);
			if (result != (int)PxrReturnStatus::PXR_RET_SUCCESS)
			{
				PXR_LOGE(PxrUnreal, "Submit Layer:%d PxrLayerEAC Failed!:%d", PxrLayerID, result);
			}
		}
	}
}

int32 FPICOXRStereoLayer::GetShapeType()
{
	int32 ShapeType = 0;
#if PLATFORM_ANDROID
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
	else if (LayerDesc.HasShape<FEACLayer>())
	{
		ShapeType = 6;
	}
#endif
	return ShapeType;
}

void FPICOXRStereoLayer::SetEyeLayerDesc(uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, FString RHIString,bool EnableSubSampled)
{
	PxrLayerCreateParam.layerShape = PXR_LAYER_PROJECTION;
	PxrLayerCreateParam.width = SizeX;
	PxrLayerCreateParam.height = SizeY;
	PxrLayerCreateParam.faceCount = 1;
	PxrLayerCreateParam.mipmapCount = NumMips;
	PxrLayerCreateParam.sampleCount = NumSamples;
	PxrLayerCreateParam.arraySize = ArraySize;
	PxrLayerCreateParam.layerLayout = ArraySize == 2 ? PXR_LAYER_LAYOUT_ARRAY : PXR_LAYER_LAYOUT_DOUBLE_WIDE;
#if PLATFORM_ANDROID
	 if (RHIString == TEXT("Vulkan"))
	{
		PxrLayerCreateParam.format = IsMobileColorsRGB() ? VK_FORMAT_R8G8B8A8_SRGB : VK_FORMAT_R8G8B8A8_UNORM;
	}
	if (EnableSubSampled)
	{
		PxrLayerCreateParam.layerFlags |= PXR_LAYER_FLAG_ENABLE_SUBSAMPLED;
	}
	else
	{
		PxrLayerCreateParam.layerFlags &= ~PXR_LAYER_FLAG_ENABLE_SUBSAMPLED;
	}
#ifdef PICO_CUSTOM_ENGINE
	if (HMDDevice->IsSupportsSpaceWarp())
	{
		PxrLayerCreateParam.layerFlags |= PXR_LAYER_FLAG_ENABLE_FRAME_EXTRAPOLATION ;
	}
#endif
#endif
	
}

const FName FEACLayer::ShapeName = FName("EACLayer");

uint32_t FEACLayer::GetModelType() const
{
	// Determine if EAC is Viewport. This is the case when offset is zero and offsetRot is identity.
	bool bIsViewportEAC = !(Offset[0].IsNearlyZero()
		&& Offset[1].IsNearlyZero()
		&& OffsetRot[0].IsIdentity()
		&& OffsetRot[1].IsIdentity());

	switch (Subtype)
	{
	case ESubtypeEAC::EAC360:
		return bIsViewportEAC ? 1 : 0;
		break;
	case ESubtypeEAC::EAC180:
		return 4;
		break;
	}

	return 0;
}

void UStereoLayerShapeEAC::SetOverlapFactor(float InOverlapFactor)
{
	if (OverlapFactor == InOverlapFactor)
	{
		return;
	}

	OverlapFactor = InOverlapFactor;
	MarkStereoLayerDirty();
}

void UStereoLayerShapeEAC::SetSubtype(ESubtypeEAC InSubtype)
{
	if (Subtype == InSubtype)
	{
		return;
	}

	Subtype = InSubtype;
	MarkStereoLayerDirty();
}

void UStereoLayerShapeEAC::ApplyShape(IStereoLayers::FLayerDesc& LayerDesc)
{
	LayerDesc.SetShape<FEACLayer>(Scale, OverlapFactor, Subtype, LeftUVRect, RightUVRect, Offset, OffsetRot);
}

#if WITH_EDITOR
void UStereoLayerShapeEAC::DrawShapeVisualization(const class FSceneView* View, class FPrimitiveDrawInterface* PDI)
{
}
#endif
