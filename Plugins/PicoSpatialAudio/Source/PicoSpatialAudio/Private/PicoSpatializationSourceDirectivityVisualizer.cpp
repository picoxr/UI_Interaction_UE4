//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#include "PicoSpatializationSourceDirectivityVisualizer.h"

// Sets default values
APicoSpatializationSourceDirectivityVisualizer::APicoSpatializationSourceDirectivityVisualizer()
	: Material(nullptr), Settings(nullptr)
{
	// Make sure visualization is not displayed in the actual game,
	//	except we let polar pattern display in our feature test app
#if defined(PICO_SPATIAL_AUDIO_FEATURE_TEST)
	Super::SetActorHiddenInGame(false);
#else
	Super::SetActorHiddenInGame(true);
#endif

	Mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("VisualizationMesh"));
	Mesh->SetupAttachment(RootComponent);
	// Disable collision data.
	Mesh->ContainsPhysicsTriMeshData(false);
}

void APicoSpatializationSourceDirectivityVisualizer::DrawPattern()
{
	Vertices.Empty();
	Triangles.Empty();
	Normals.Empty();
	VertexColors.Empty();

	// Make the default directivity visualization radius equal 2m
	const float kPolarPatternScale = 200.0f;
	const FVector kNormalVector = FVector(0, 0, 1);

	for (int i = 0; i < kCircleSections; ++i)
	{
		const float Angle1 = static_cast<float>(i * 2) * PI / kCircleSections;
		const float Angle2 = static_cast<float>((i + 1) * 2) * PI / kCircleSections;

		const float Gain1 = kPolarPatternScale * FMath::Pow(
			FMath::Abs((1.0f - Settings->DirectivityAlpha) + Settings->DirectivityAlpha * FMath::Cos(Angle1)),
			Settings->DirectivityOrder);
		const float Gain2 = kPolarPatternScale * FMath::Pow(
			FMath::Abs((1.0f - Settings->DirectivityAlpha) + Settings->DirectivityAlpha * FMath::Cos(Angle2)),
			Settings->DirectivityOrder);

		Vertices.Add(FVector(Gain2 * FMath::Cos(Angle2), Gain2 * FMath::Sin(Angle2), 0.0f));
		Vertices.Add(FVector(Gain1 * FMath::Cos(Angle1), Gain1 * FMath::Sin(Angle1), 0.0f));
		Vertices.Add(FVector(0.0f, 0.0f, 0.0f));

		const static FColor PolarPatternColor(51, 128, 179);
		for (int j = 0; j < 3; ++j)
		{
			Triangles.Add(3 * i + j);
			Normals.Add(kNormalVector);
			VertexColors.Add(PolarPatternColor);
		}
	}

	if (!bMeshCreated)
	{
		Mesh->CreateMeshSection(0, Vertices, Triangles, Normals, UV0, VertexColors, Tangents, false);
		bMeshCreated = true;
	}
	else
		Mesh->UpdateMeshSection(0, Vertices, Normals, UV0, VertexColors, Tangents);
	Mesh->SetMaterial(0, Material);
}
