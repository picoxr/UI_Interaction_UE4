//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "ProceduralMeshComponent.h"
#include "IStereoLayers.h"
#include "PXR_HMDRenderBridge.h"
#include "XRSwapChain.h"
#include "GameFramework/PlayerController.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#include "PxrApi.h"
#endif

class FDelayDeleteLayerManager;
class FPXRGameFrame;

class FPxrLayer : public TSharedFromThis<FPxrLayer, ESPMode::ThreadSafe>
{
public:
	FPxrLayer(uint32 InPxrLayerId,FDelayDeleteLayerManager* InDelayDeletion);
	~FPxrLayer();

protected:
	uint32 PxrLayerId;
private:
	FDelayDeleteLayerManager* DelayDeletion;
};

typedef TSharedPtr<FPxrLayer, ESPMode::ThreadSafe> FPxrLayerPtr;

class FPICOXRStereoLayer : public TSharedFromThis<FPICOXRStereoLayer, ESPMode::ThreadSafe>
{
public:
	FPICOXRStereoLayer(FPICOXRHMD* InHMDDevice,uint32 InPXRLayerId, const IStereoLayers::FLayerDesc& InLayerDesc);
	FPICOXRStereoLayer(const FPICOXRStereoLayer& InPXRLayer);
	~FPICOXRStereoLayer();

	TSharedPtr<FPICOXRStereoLayer, ESPMode::ThreadSafe> CloneMyself() const;
	void SetPXRLayerDesc(const IStereoLayers::FLayerDesc& InDesc);
	const IStereoLayers::FLayerDesc& GetPXRLayerDesc() const { return LayerDesc; }
	const uint32& GetID()const{return ID;}

	bool IsLayerSupportDepth() { return (LayerDesc.Flags & IStereoLayers::LAYER_FLAG_SUPPORT_DEPTH) != 0; }
	void ManageUnderlayComponent();
	void CreateUnderlayMesh(TArray<FVector>& VerticePos, TArray<int32>& TriangleIndics, TArray<FVector2D>& TexUV);

	const FXRSwapChainPtr& GetSwapChain() const { return SwapChain; }
	const FXRSwapChainPtr& GetLeftSwapChain() const { return LeftSwapChain; }
	const FXRSwapChainPtr& GetFoveationSwapChain() const { return FoveationSwapChain; }
	void IncrementSwapChainIndex_RHIThread(FPICOXRRenderBridge* RenderBridge);
	void SubmitLayer_RHIThread(FPXRGameFrame* Frame);
	int32 GetShapeType();
	void SetProjectionLayerParams(uint32 SizeX, uint32 SizeY, uint32 ArraySize, uint32 NumMips, uint32 NumSamples, FString RHIString);
    void PXRLayersCopy_RenderThread(FPICOXRRenderBridge* RenderBridge, FRHICommandListImmediate& RHICmdList);
	void MarkTextureForUpdate(bool bUpdate = true) { bTextureNeedUpdate = bUpdate; }
	bool InitPXRLayer_RenderThread(FPICOXRRenderBridge* CustomPresent, FDelayDeleteLayerManager* DelayDeletion, FRHICommandListImmediate& RHICmdList, const FPICOXRStereoLayer* InLayer = nullptr);
	bool IfCanReuseLayers(const FPICOXRStereoLayer* InLayer) const;
	bool IsVisible() { return (LayerDesc.Flags & IStereoLayers::LAYER_FLAG_HIDDEN) == 0; }

	bool bSplashLayer;
	bool bSplashBlackProjectionLayer;
	bool bMRCLayer;

protected:
	FVector GetLayerLocation() const { return LayerDesc.Transform.GetLocation(); };
	FQuat GetLayerOrientation() const { return LayerDesc.Transform.GetRotation(); };
	FVector GetLayerScale() const { return LayerDesc.Transform.GetScale3D(); };
	FPICOXRHMD* HMDDevice;
	uint32 ID;	
	uint32 PxrLayerID;
	static uint32 PxrLayerIDCounter;
	IStereoLayers::FLayerDesc LayerDesc;
	FXRSwapChainPtr SwapChain;
	FXRSwapChainPtr LeftSwapChain;
	FXRSwapChainPtr FoveationSwapChain;
    bool bTextureNeedUpdate;
	UProceduralMeshComponent* UnderlayMeshComponent;
	AActor* UnderlayActor;

	FPxrLayerPtr PxrLayer;
#if PLATFORM_ANDROID
	PxrLayerParam PxrLayerCreateParam;
#endif

};

typedef TSharedPtr<FPICOXRStereoLayer, ESPMode::ThreadSafe> FPICOLayerPtr;

struct FPICOLayerPtr_SortByPriority
{
	FORCEINLINE bool operator()(const FPICOLayerPtr&A,const FPICOLayerPtr&B)const
	{
		int32 nPriorityA = A->GetPXRLayerDesc().Priority;
		int32 nPriorityB = B->GetPXRLayerDesc().Priority;
		if (nPriorityA < nPriorityB)
		{
			return true;
		}
		else if (nPriorityA > nPriorityB)
		{
			return false;
		}
		else
		{
			return A->GetID() < B->GetID();
		}
	}
};

struct FPICOLayerPtr_SortById
{
	FORCEINLINE bool operator()(const FPICOLayerPtr& A, const FPICOLayerPtr& B) const
	{
		return A->GetID() < B->GetID();
	}
};

struct FLayerPtr_CompareByAll
{
	FORCEINLINE bool operator()(const FPICOLayerPtr& A, const FPICOLayerPtr& B) const
	{
		int32 OrderA = (A->GetID() == 0) ? 0 : A->IsLayerSupportDepth() ? -1 : 1;
		int32 OrderB = (B->GetID() == 0) ? 0 : B->IsLayerSupportDepth() ? -1 : 1;

		if (OrderA != OrderB)
		{
			return OrderA < OrderB;
		}

		const IStereoLayers::FLayerDesc& DescA = A->GetPXRLayerDesc();
		const IStereoLayers::FLayerDesc& DescB = B->GetPXRLayerDesc();

		bool bFaceLockedA = (DescA.PositionType == IStereoLayers::ELayerType::FaceLocked);
		bool bFaceLockedB = (DescB.PositionType == IStereoLayers::ELayerType::FaceLocked);

		if (bFaceLockedA != bFaceLockedB)
		{
			return bFaceLockedB;
		}

		if (DescA.Priority != DescB.Priority)
		{
			return DescA.Priority < DescB.Priority;
		}

		return A->GetID() < B->GetID();
	}
};
