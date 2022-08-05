//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#pragma once
#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "PXR_EyeMaskComponent.generated.h"

UCLASS( ClassGroup=(PXRComponent), meta=(BlueprintSpawnableComponent) )
class UPicoXREyeMaskComponent : public UProceduralMeshComponent
{
	GENERATED_BODY()
public:
	// Sets default values for this component's properties
	UPicoXREyeMaskComponent(const FObjectInitializer& ObjectInitializer);
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
		int VertexFloatCount;
		int IndexIntCount;
		float * Vertices;
		int * Indices;
	};

private:
	int VertexCountLeft, TriangleCountLeft; // Left
	float* VertexDataLeft;
	int* IndexDataLeft;

	int VertexCountRight, TriangleCountRight; // Right
	float* VertexDataRight;
	int* IndexDataRight;
	bool GetStencilMeshData();
	void CreateStencilMesh();
	EyeMaskData GetEyeMaskData(int Eye);
};
