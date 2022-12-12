// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/StaticMeshActor.h"
#include "PicoSpatialAudioSceneMaterialSettings.h"
#include "PxrAudioSpatializerListener.h"
#include "PxrAudioSpatializerCommonUtils.h"
#include "PicoSpatialAudioSceneGeometryComponent.generated.h"

UCLASS(ClassGroup=(Audio), HideCategories = (Transform, Activation, Collision, Cooking),
	meta=(BlueprintSpawnableComponent))
class PICOSPATIALAUDIO_API UPicoSpatialAudioSceneGeometryComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPicoSpatialAudioSceneGeometryComponent();

	virtual ~UPicoSpatialAudioSceneGeometryComponent() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	virtual void BeginDestroy() override;

	int32 SubmitToContext();
	int32 SubmitBakedMeshToContext();

	// if IncludeChildrenActor is true, children (attached) meshes will be merged and managed by this component
	UPROPERTY(EditAnywhere, Category = "Settings")
	bool IncludeChildrenActor = false;
	// if IncludeChildrenActor is true, children (attached) meshes will be merged and managed by this component
	UPROPERTY(EditAnywhere, Category = "Settings")
	bool IncludeChildrenComponent = false;
	UPROPERTY(EditAnywhere, Category = "Settings")
	UPicoSpatialAudioSceneMaterialSettings* MaterialSettings;

	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Mesh Baking Utilities")
	void BakeMesh();
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Mesh Baking Utilities")
	void ClearBakedMesh();

private:
	int InternalGeomId;
	int InternalBakedGeomId;
	bool bSubmitted;

	UPROPERTY() //	Add UPROPERTY() to prevent GatheredStaticMeshes being garbage collected at unknown time
	TArray<UStaticMesh*> GatheredStaticMeshes;
	TArray<FTransform> GatheredStaticMeshTransforms;
	TArray<float> BatchedMeshVerticesBuffer;
	TArray<int32> BatchedMeshIndicesBuffer;

	UPROPERTY(VisibleAnywhere, Category = "Mesh Baking Utilities")
	TArray<float> BatchedBakedMeshVerticesBuffer;
	UPROPERTY(VisibleAnywhere, Category = "Mesh Baking Utilities")
	TArray<int32> BatchedBakedMeshIndicesBuffer;

	void GatherStaticMeshes(TArray<UStaticMesh*>& OutGatheredStaticMeshes, TArray<FTransform>& OutGatheredStaticMeshTransforms,
	                        bool InAllowCPUAccess);
	
	static void GatherStaticMeshesInChildrenActors(AActor* Actor,
	                                               TArray<UStaticMesh*>& OutGatheredStaticMeshes,
	                                               TArray<FTransform>& OutGatheredStaticMeshTransforms,
	                                               bool InIncludeChildrenActor,
	                                               bool InIncludeChildrenComponent,
	                                               bool InAllowCPUAccess);
	static void GatherStaticMeshesInComponentHierarchy(USceneComponent* Component,
	                                                   TArray<UStaticMesh*>& OutGatheredStaticMeshes,
	                                                   TArray<FTransform>& OutGatheredStaticMeshTransforms,
	                                                   bool InIncludeChildrenComponent,
	                                                   bool InAllowCPUAccess);
	static void BatchStaticMeshes(const TArray<UStaticMesh*>& InGatheredStaticMeshes,
	                              const TArray<FTransform>& InGatheredStaticMeshTransforms,
	                              TArray<float>& OutBatchedMeshVerticesBuffer,
	                              TArray<int32>& OutBatchedMeshIndicesBuffer);
};
