// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Misc/EngineVersionComparison.h"

#if !UE_VERSION_OLDER_THAN(5, 3, 0)
#include "VariableRateShadingImageManager.h"
#include "XRSwapchain.h"

class FPICOXRFoveatedRenderingImageGenerator : public IVariableRateShadingImageGenerator
{
public:
	FPICOXRFoveatedRenderingImageGenerator(const FXRSwapChainPtr& Swapchain);
	virtual ~FPICOXRFoveatedRenderingImageGenerator() override;

	// IVariableRateShadingImageGenerator interface
	virtual FRDGTextureRef GetImage(FRDGBuilder& GraphBuilder, const FViewInfo& ViewInfo, FVariableRateShadingImageManager::EVRSImageType ImageType) override;
	virtual void PrepareImages(FRDGBuilder& GraphBuilder, const FSceneViewFamily& ViewFamily, const FMinimalSceneTextures& SceneTextures) override;
	virtual bool IsEnabledForView(const FSceneView& View) const override;
	virtual FRDGTextureRef GetDebugImage(FRDGBuilder& GraphBuilder, const FViewInfo& ViewInfo, FVariableRateShadingImageManager::EVRSImageType ImageType) override;
	virtual FVariableRateShadingImageManager::EVRSSourceType GetType() const override
	{
		return FVariableRateShadingImageManager::EVRSSourceType::FixedFoveation;
	}

private:
	const FXRSwapChainPtr& FoveationSwapchain;
};
#endif // !UE_VERSION_OLDER_THAN(5, 3, 0)
