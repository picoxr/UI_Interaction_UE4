// Copyright © 2015-2021 Pico Technology Co., Ltd. All Rights Reserved.

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
	NeedToDestroy,
	NeedToReCreate,
};
#if ENGINE_MINOR_VERSION==24
class FPxrLayer : public TSharedFromThis<FPxrLayer, ESPMode::ThreadSafe>
{
public:
	FPxrLayer(uint32 InPxrLayerId);
	~FPxrLayer();

protected:
	uint32 PxrLayerId;
};

typedef TSharedPtr<FPxrLayer, ESPMode::ThreadSafe> FPxrLayerPtr;
#endif

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
	void MarkDestroyLayer();
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
    void MarkTextureForUpdate() { bUpdateTexture = true; }

	bool bSplashLayer = false;

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
    bool bUpdateTexture;
	FString RHIString;
	EPicoXRLayerState LayerState;
	FEyeLayerParam EyeLayerParam;
    bool NeedDestoryRuntimeLayer;

	UProceduralMeshComponent* UnderlayComponent;
	AActor* UnderlayActor;

#if ENGINE_MINOR_VERSION==24
	FPxrLayerPtr PxrLayer;
#endif
};

typedef TSharedPtr<FPicoXRStereoLayer, ESPMode::ThreadSafe> FPicoLayerPtr;

//-------------------------------------------------------------------------------------------------
//FPicoXRStereoLayerPtr_CompareId
//-------------------------------------------------------------------------------------------------

struct FPicoXRStereoLayerPtr_CompareId
{
	FORCEINLINE bool operator()(const FPicoLayerPtr&A,const FPicoLayerPtr&B)const
	{
		return A->GetLayerID()<B->GetLayerID();
	}
};

//-------------------------------------------------------------------------------------------------
//FPicoXRStereoLayerPtr_ComparePriority
//-------------------------------------------------------------------------------------------------

struct FPicoXRStereoLayerPtr_ComparePriority
{
	FORCEINLINE bool operator()(const FPicoLayerPtr&A,const FPicoLayerPtr&B)const
	{
		if(A->GetLayerDesc().Priority<B->GetLayerDesc().Priority)
			return true;
		if(A->GetLayerDesc().Priority>B->GetLayerDesc().Priority)
			return false;

		return A->GetLayerID() < B->GetLayerID();
	}
};

//-------------------------------------------------------------------------------------------------
//FPicoXRStereoLayerPtr_CompareTotal
//-------------------------------------------------------------------------------------------------

struct FPicoXRStereoLayerPtr_CompareTotal
{
	FORCEINLINE bool operator()(const FPicoLayerPtr&A,const FPicoLayerPtr&B)const
	{
		int32 PassA;
		int32 PassB;
		if (A->GetLayerID() == 0) {
			PassA = 0;
		}
		else if (A->IsSupportLayerDepth())
		{
			PassA = -1;
		}
		else
		{
			PassA = 1;
		}

		if (B->GetLayerID() == 0) {
			PassB = 0;
		}
		else if (B->IsSupportLayerDepth())
		{
			PassB = -1;
		}
		else
		{
			PassB = 1;
		}

		if(PassA!=PassB)
			return PassA<PassB;

		const IStereoLayers::FLayerDesc&DescA=A->GetLayerDesc();
		const IStereoLayers::FLayerDesc&DescB=B->GetLayerDesc();

		bool bLockedA = (DescA.PositionType == IStereoLayers::ELayerType::FaceLocked);
		bool bLockedB = (DescB.PositionType == IStereoLayers::ELayerType::FaceLocked);

		if (bLockedA != bLockedB)
			return!bLockedA;

		if(DescA.Priority!=DescB.Priority)
			return DescA.Priority<DescB.Priority;

		return A->GetLayerID()<B->GetLayerID();
	}
};
