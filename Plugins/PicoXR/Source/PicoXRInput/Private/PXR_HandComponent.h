//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/PoseableMeshComponent.h"
#include "PXR_InputFunctionLibrary.h"
#include "PXR_HandComponent.generated.h"

class APlayerCameraManager;

UCLASS(Blueprintable, ClassGroup = (PICOXRComponent), meta = (BlueprintSpawnableComponent))
class PICOXRINPUT_API UPICOXRHandComponent : public UPoseableMeshComponent
{
	GENERATED_UCLASS_BODY()
public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HandProperties")
 	EPICOXRHandType SkeletonType;
	
 	virtual void BeginPlay() override;

 	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

 	/** Behavior for when hand tracking loses high confidence tracking */
 	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HandProperties")
 	bool bHideByConfidence;

 	/** Whether or not the hand scale should update based on values from the runtime to match the users hand scale */
 	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HandProperties")
 	bool bUpdateHandScale;

 	/** Bone mapping for custom hand skeletal meshes */
 	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "CustomSkeletalMesh")
 	TMap<EPICOXRHandJoint, FName> BoneNameMappings;

 private:
 	/** Whether or not a custom hand mesh is being used */
 	bool bCustomHandMesh = false;
	
 	void UpdateBonePose();
 	void UpdateHandTransform();
};
