//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Materials/Material.h"
#include "ProceduralMeshComponent.h"
#include "PicoSpatializationSourceSettings.h"
#include "PicoSpatializationSourceDirectivityVisualizer.generated.h"

UCLASS()
class PICOSPATIALAUDIO_API APicoSpatializationSourceDirectivityVisualizer : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APicoSpatializationSourceDirectivityVisualizer();

	// Draws given directivity pattern as a 2D mesh based on Settings.
	UFUNCTION(BlueprintCallable, Category = "PicoSpatialAudio|PolarPatternVisualizer")
	void DrawPattern();

	UFUNCTION(BlueprintCallable, Category = "PicoSpatialAudio|PolarPatternVisualizer")
	void SetSettings(UPicoSpatializationSourceSettings* InSettings) { Settings = InSettings; };

	UFUNCTION(BlueprintCallable, Category = "PicoSpatialAudio|PolarPatternVisualizer")
	UPicoSpatializationSourceSettings* GetSettings() const { return Settings; };

	UFUNCTION(BlueprintCallable, Category = "PicoSpatialAudio|PolarPatternVisualizer")
	void SetMaterial(UMaterial* InMaterial) { Material = InMaterial; };

private:
	// Controls the smoothness of mesh visualization.
	const int kCircleSections = 30;

	// Arrays required by Procedural Mesh Component.
	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FColor> VertexColors;

	// Optional arrays.
	TArray<FVector2D> UV0;
	TArray<FProcMeshTangent> Tangents;

	UPROPERTY(Category = APicoSpatializationSourceDirectivityVisualizer, VisibleAnywhere, BlueprintReadOnly, meta = (ExposeFunctionCategories = "Mesh,Rendering,Physics,Components|ProceduralMesh", AllowPrivateAccess = "true"))
	UProceduralMeshComponent* Mesh;
	
	UPROPERTY()
	UMaterial* Material;

	UPROPERTY()
	UPicoSpatializationSourceSettings* Settings;

	bool bMeshCreated = false;
};
