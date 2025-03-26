// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "PXR_HMD.h"
#include "PXR_MRTypes.h"
#include "PXR_SpatialMeshComponent.h"
#include "PXR_SpatialMeshActor.generated.h"

UCLASS(BlueprintType,DisplayName="PICO XR SpatialMesh Actor")
class APXRSpatialMeshActor : public AActor
{
	GENERATED_BODY()

public:
	APXRSpatialMeshActor(const FObjectInitializer& ObjectInitializer);
	
	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type Reason) override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR MR Spatial Mesh",meta=(ExposeOnSpawn = true))
	bool bDrawOnBeginPlay = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR MR Spatial Mesh",meta=(ExposeOnSpawn = true))
	UMaterial* SpatialMeshMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR MR Spatial Mesh",meta=(ExposeOnSpawn = true))
	TEnumAsByte<ECollisionEnabled::Type> CollisionType=ECollisionEnabled::Type::QueryAndPhysics;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR MR Spatial Mesh",meta=(ExposeOnSpawn = true))
	bool bSpatialMeshVisible=true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR MR Spatial Mesh")
	TMap<EPICOSemanticLabel,FColor> SemanticToColors;

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRMR")
	void SetSemanticToColors(const TMap<EPICOSemanticLabel,FLinearColor>& In_SemanticToColors);
	
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRMR")
	bool StartDraw();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRMR")
	bool PauseDraw();

	UFUNCTION(BlueprintCallable, Category = "PXR|PXRMR")
	void SetMeshVisibility(bool visibility);
	
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRMR")
	bool ClearMesh();

private:
	UFUNCTION()
	void HandleRequestSpatialMeshContentsEvent(EPICOResult Result, const TArray<FPICOSpatialMeshInfo>& MeshInfos);
	UFUNCTION()
	void HandleMeshDataUpdatedEvent();
	FColor GetColorBySceneLabel(EPICOSemanticLabel SceneLabel);
	bool UpdateMeshByMeshInfo(UPICOSpatialMeshComponent* SpatialMesh, const FPICOSpatialMeshInfo& MeshInfo);

protected:
	UPROPERTY(Transient)
	TMap<FPICOSpatialUUID, UPICOSpatialMeshComponent*> EntityToMeshMap;
	TQueue<TArray<FPICOSpatialMeshInfo>> MeshInfoQueue;
	int32 NumDrawCalls=0;
	int32 DrawnPrimitives=0;
	UPROPERTY()
	UMaterialInstanceDynamic* SpatialMeshInstance=nullptr;
};