// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.
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

 	

	/** Whether or not Every Bone's Location should be updated*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HandProperties")
	bool bApplyLocationToBones;

 	/** Bone mapping for custom hand skeletal meshes */
 	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "CustomSkeletalMesh")
 	TMap<EPICOXRHandJoint, FName> BoneNameMappings;

 private:
	/** Whether or not this component has authority within the frame */
	bool bHasAuthority;
	/** Whether or not the hand scale should update based on values from the runtime to match the users hand scale */
	bool bUpdateHandScale;
 	/** Whether or not a custom hand mesh is being used */
 	bool bCustomHandMesh = false;
	
 	void UpdateBonePose();
 	void UpdateHandTransform();
};
