//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "ProceduralMeshComponent.h"
#include "IStereoLayers.h"
#include "PXR_HMDRenderBridge.h"
#include "XRSwapChain.h"
#include "GameFramework/PlayerController.h"

enum class EPicoXRLayerState : uint8
{
	Unknown,
	NeedToCreate,
    Ready,
	NeedToReCreate,
};

class FPxrLayer : public TSharedFromThis<FPxrLayer, ESPMode::ThreadSafe>
{
public:
	FPxrLayer(uint32 InPxrLayerId);
	~FPxrLayer();

protected:
	uint32 PxrLayerId;
};

typedef TSharedPtr<FPxrLayer, ESPMode::ThreadSafe> FPxrLayerPtr;

struct FEyeLayerParam
{
	FPicoXRRenderBridge* RenderBridge;
	uint8 Format;
	uint32 SizeX;
	uint32 SizeY;
	uint32 ArraySize;
	uint32 NumMips;
	uint32 NumSamples;
#if ENGINE_MINOR_VERSION > 25
	ETextureCreateFlags Flags;
	ETextureCreateFlags TargetableTextureFlags;
#else
	uint32 Flags;
	uint32 TargetableTextureFlags;
#endif
	uint32 MSAAValue;
};

class FPicoXRStereoLayer : public TSharedFromThis<FPicoXRStereoLayer, ESPMode::ThreadSafe>
{
public:
	FPicoXRStereoLayer(FPicoXRHMD* InHMDDevice,uint32 InId, const IStereoLayers::FLayerDesc& InDesc);
	FPicoXRStereoLayer(const FPicoXRStereoLayer& InLayer);
	~FPicoXRStereoLayer();

	TSharedPtr<FPicoXRStereoLayer, ESPMode::ThreadSafe> Clone() const;
	void SetLayerDesc(const IStereoLayers::FLayerDesc& InDesc);
	const IStereoLayers::FLayerDesc& GetLayerDesc() const { return LayerDesc; }
	const uint32& GetLayerID()const{return LayerId;}

	bool IsSupportLayerDepth() { return (LayerDesc.Flags & IStereoLayers::LAYER_FLAG_SUPPORT_DEPTH) != 0; }
	void ManageUnderlayComponent();
	void CreateQuadUnderlayMesh(TArray<FVector>& VerticePos, TArray<int32>& TriangleIndics, TArray<FVector2D>& TexUV);

	const FXRSwapChainPtr& GetSwapChain() const { return SwapChain; }
	const FXRSwapChainPtr& GetOverlaySwapChain() const { return OverlaySwapChain; }
	const FXRSwapChainPtr& GetLeftSwapChain() const { return LeftSwapChain; }
	const FXRSwapChainPtr& GetFoveationSwapChain() const { return FoveationSwapChain; }
	EPicoXRLayerState GetLayerState() const { return  LayerState; };
	void SetLayerState(EPicoXRLayerState NewState);
	void MarkCreateLayer();
	void MarkReCreateLayer();
	void CreateLayer(FPicoXRRenderBridge* RenderBridge);
	void DestroyLayer();
	void ReCreateLayer(FPicoXRRenderBridge* RenderBridge);
	void IncrementSwapChainIndex_RHIThread(FPicoXRRenderBridge* RenderBridge);
	void SubmitCompositionLayerRenderMatrix_RHIThread(APlayerController* PlayerController, FQuat& CurrentOrientation, FVector& CurrentPosition, FTransform& CurrentTrackingToWorld);
	int32 GetShapeType();

#if ENGINE_MINOR_VERSION > 25
	void InitializeLayer_RenderThread(FPicoXRRenderBridge* RenderBridge,uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, ETextureCreateFlags Flags, ETextureCreateFlags TargetableTextureFlags,uint32 MSAAValue);
	void SetEyeLayerParam(FPicoXRRenderBridge* RenderBridge,uint8 Format, uint32 SizeX, uint32 SizeY,
         uint32 ArraySize,uint32 NumMips,uint32 NumSamples,  ETextureCreateFlags Flags, ETextureCreateFlags TargetableTextureFlags, uint32 MSAAValue);
#else
	void InitializeLayer_RenderThread(FPicoXRRenderBridge* RenderBridge,uint8 Format, uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, uint32 Flags, uint32 TargetableTextureFlags,uint32 MSAAValue);
    void SetEyeLayerParam(FPicoXRRenderBridge* RenderBridge, uint8 Format, uint32 SizeX, uint32 SizeY,uint32 ArraySize, uint32 NumMips, uint32 NumSamples, uint32 Flags, uint32 TargetableTextureFlags, uint32 MSAAValue);
#endif
    void RefreshLayers_RenderThread(FPicoXRRenderBridge* RenderBridge, FRHICommandListImmediate& RHICmdList);
    void MarkTextureForUpdate() { bTextureNeedUpdate = true; }

	bool bSplashLayer = false;
	bool bMRCLayer = false;

protected:
	FVector GetLayerLocation() const { return LayerDesc.Transform.GetLocation(); };
	FQuat GetLayerOrientation() const { return LayerDesc.Transform.GetRotation(); };
	FVector GetLayerScale() const { return LayerDesc.Transform.GetScale3D(); };
	FPicoXRHMD* HMDDevice;
	uint32 LayerId;
	IStereoLayers::FLayerDesc LayerDesc;
	FXRSwapChainPtr SwapChain;
	FXRSwapChainPtr LeftSwapChain;
	FXRSwapChainPtr FoveationSwapChain;
    FXRSwapChainPtr OverlaySwapChain;
    FXRSwapChainPtr LeftOverlaySwapChain;
    bool bTextureNeedUpdate;
	FString RHIString;
	EPicoXRLayerState LayerState;
	FEyeLayerParam EyeLayerParam;
    bool NeedDestoryRuntimeLayer;

	UProceduralMeshComponent* UnderlayComponent;
	AActor* UnderlayActor;

	FPxrLayerPtr PxrLayer;
};

typedef TSharedPtr<FPicoXRStereoLayer, ESPMode::ThreadSafe> FPicoLayerPtr;

//-------------------------------------------------------------------------------------------------
//FPicoXRStereoLayerPtr_ComparePriority
//-------------------------------------------------------------------------------------------------

struct CompareLayerPriority_PredicateClass
{
	FORCEINLINE bool operator()(const FPicoLayerPtr&A,const FPicoLayerPtr&B)const
	{
		int32 nPriorityA=A->GetLayerDesc().Priority;
		int32 nPriorityB=B->GetLayerDesc().Priority;
		if(nPriorityA<nPriorityB)
		{
			return true;
		}
		else if(nPriorityA>nPriorityB)
		{
			return false;
		}
		else
		{
			return A->GetLayerID() < B->GetLayerID();
		}	
	}
};
