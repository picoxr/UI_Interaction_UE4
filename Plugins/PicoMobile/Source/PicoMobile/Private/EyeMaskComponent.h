// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "EyeMaskComponent.generated.h"


UCLASS(meta=(BlueprintSpawnableComponent) )
class UEyeMaskComponent : public UProceduralMeshComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UEyeMaskComponent(const FObjectInitializer& ObjectInitializer);
	virtual void PostLoad() override;
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// This is used for debug.  Setting a color instead of black will help developer to see if it is working.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	FLinearColor Color;

	// This is used for debug.  On Editor or some device didn't have RenderMask, set UseDebugMesh true to show a debug mesh.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	bool UseDebugMesh;

	// This is work if UseDebugMesh is true.  This will indicate the left and right eye's mesh, and make them more obviously.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	bool UseEyeSpecifiedMesh;

public:
	class EyeMaskData
	{
	public:
		int vertexFloatCount;
		int indexIntCount;

		float * vertices;
		int * indices;
	};

private:
	int vertexCountLeft, triangleCountLeft; // Left
	float* vertexDataLeft;
	int* indexDataLeft;

	int vertexCountRight, triangleCountRight; // Right
	float* vertexDataRight;
	int* indexDataRight;
	bool GetStencilMeshData();
	void CreateStencilMesh();
	EyeMaskData GetEyeMaskData(int eye);
};
