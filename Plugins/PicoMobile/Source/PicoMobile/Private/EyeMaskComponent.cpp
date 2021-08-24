// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.


#include "EyeMaskComponent.h"
#include "PicoImport.h"
#include "PicoMobile.h"


#if PLATFORM_ANDROID
#define PLATFORM_CHAR(str) TCHAR_TO_UTF8(str)
#else
#define PLATFORM_CHAR(str) str
#endif

// Sets default values for this component's properties
UEyeMaskComponent::UEyeMaskComponent(const FObjectInitializer& ObjectInitializer) : 
	Super(ObjectInitializer), 
	Color(), 
	UseDebugMesh(false), 
	UseEyeSpecifiedMesh(false)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

void UEyeMaskComponent::PostLoad()
{
	Super::PostLoad();
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UEyeMaskComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UEyeMaskComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//UE_LOG(LogTemp, Log, TEXT("UEyeMaskComponent::TickComponent"));

	 if (GetStencilMeshData())
	 {
		 CreateStencilMesh();

		 // release
		 delete[] vertexDataLeft;
		 delete[] indexDataLeft;
		 delete[] vertexDataRight;
		 delete[] indexDataRight;

		 vertexDataLeft = nullptr;
		 indexDataLeft = nullptr;
		 vertexDataRight = nullptr;
		 indexDataRight = nullptr;
	 }

	 SetComponentTickEnabled(false);
	 PrimaryComponentTick.bCanEverTick = false;
}

// Right hand rule
static FMatrix MakeGLProjection(float Left, float Right, float Top, float Bottom, float ZNear, float ZFar = 1000)
{
	//UE_LOG(LogTemp, Log, TEXT("UEyeMaskComponent::MakeGLProjection"));
	float SumRL = Right + Left;
	float SumTB = Top + Bottom;
	float SubRL = Right - Left;
	float SubTB = Top - Bottom;

	auto matrix = FMatrix(
		FPlane(2 * ZNear / SubRL, 0.0f, 0.0f, 0.0f),
		FPlane(0.0f, 2 * ZNear / SubTB, 0.0f, 0.0f),
		FPlane(SumRL / SubRL, SumTB / SubTB, -(ZFar + ZNear) / (ZFar - ZNear), -1.0f),
		FPlane(0.0f, 0.0f, -2 * ZFar * ZNear / (ZFar - ZNear), 0.0f)
	);
	auto tostr = matrix.ToString();
	//UE_LOG(LogTemp, Log, TEXT("UEyeMaskComponent::MakeGLProjection Projection Matrix %s"), PLATFORM_CHAR(*tostr));
	return matrix;
}

static void MakeTriangle(const float * verticesF, const int verticeFloatCount, const int * indicesI, const int indiceIntCount, int indexOffset, TArray<FVector> &vertices, TArray<FVector> &normals, TArray<int32> &triangles, TArray<FVector2D> &uvs, TArray<FLinearColor> & colors, TArray<FProcMeshTangent> tangents)
{
	//UE_LOG(LogTemp, Log, TEXT("UEyeMaskComponent MakeTriangle1"));
	auto tangent = FProcMeshTangent(0, 1, 0);
	const int verticesCount = verticeFloatCount / 3;
	for (int i = 0; i < verticesCount; i++) {
		vertices.Add(FVector(verticesF[3 * i + 0], verticesF[3 * i + 1], -1.0f));
		normals.Add(FVector(-1, 0, 0));
		uvs.Add(FVector2D(0, 0));
		colors.Add(FLinearColor::Black);
		tangents.Add(tangent);
	}

	for (int i = 0; i < indiceIntCount; i++) {
		triangles.Add(indicesI[i] + indexOffset);
	}

	return;
}

static void MakeTriangle(int shape, float offsetY, float offsetZ, float size, TArray<FVector> &vertices, TArray<FVector> &normals, TArray<int32> &triangles, int & index, TArray<FVector2D> &uvs, TArray<FLinearColor> & colors, FLinearColor Color, TArray<FProcMeshTangent> tangents)
{
	//UE_LOG(LogTemp, Log, TEXT("UEyeMaskComponent MakeTriangle2"));
	/**
	 *  A B
	 *  C D
	 *  0-2   2  0   0-2
	 *  |o   o|  |o   o|
	 *  1   0-1  1-2   1
	 */

	FVector A(0, offsetY - size, offsetZ + size);
	FVector B(0, offsetY + size, offsetZ + size);
	FVector C(0, offsetY - size, offsetZ - size);
	FVector D(0, offsetY + size, offsetZ - size);

	switch (shape) {
	case 0:
		vertices.Add(A);
		vertices.Add(C);
		vertices.Add(B);
		break;
	case 1:
		vertices.Add(C);
		vertices.Add(D);
		vertices.Add(B);
		break;
	case 2:
		vertices.Add(A);
		vertices.Add(C);
		vertices.Add(D);
		break;
	case 3:
		vertices.Add(A);
		vertices.Add(D);
		vertices.Add(B);
		break;
	}
	normals.Add(FVector(-1, 0, 0));
	normals.Add(FVector(-1, 0, 0));
	normals.Add(FVector(-1, 0, 0));

	triangles.Add(index);
	triangles.Add(index + 1);
	triangles.Add(index + 2);
	index += 3;

	uvs.Add(FVector2D(1, 0));
	uvs.Add(FVector2D(1, 1));
	uvs.Add(FVector2D(0, 0));

	colors.Add(Color);
	colors.Add(Color);
	colors.Add(Color);

	auto tangent = FProcMeshTangent(0, 1, 0);
	tangents.Add(tangent);
	tangents.Add(tangent);
	tangents.Add(tangent);
}

 bool UEyeMaskComponent::GetStencilMeshData()
 {
#if WITH_EDITOR
	 if (GIsEditor)
	 {
		 //UE_LOG(LogTemp, Log, TEXT("UEyeMaskComponent::GetStencilMeshData In Editor"));
		 return true;
	 }
		 
#endif

#if PLATFORM_ANDROID
	 int i = 0;
	 float* vertexDataPointer;
	 unsigned int* indexDataPointer;

	 // Left
	 PicoSDK::Render::GetStencilMesh(0, vertexCountLeft, triangleCountLeft, &vertexDataPointer, &indexDataPointer);
	 if (vertexCountLeft <= 0 || triangleCountLeft <= 0)
	 {
		 return false;
	 } 
	 //UE_LOG(LogTemp, Log, TEXT("Left vertex count = %d, triangle count = %d"), vertexCountLeft, triangleCountLeft);
	 vertexDataLeft = new float[vertexCountLeft * 3];
	 indexDataLeft = new int[triangleCountLeft * 3];
	 for (i = 0; i < vertexCountLeft * 3; i++)
	 {
		 vertexDataLeft[i] = vertexDataPointer[i];
	 }

	 for (i = 0; i < triangleCountLeft * 3; i++)
	 {
		 indexDataLeft[i] = indexDataPointer[i];
	 }


	 // Right
	 PicoSDK::Render::GetStencilMesh(1, vertexCountRight, triangleCountRight, &vertexDataPointer, &indexDataPointer);
	 if (vertexCountRight <= 0 || triangleCountRight <= 0)
	 {
		 return false;
	 }
	 //UE_LOG(LogTemp, Log, TEXT("Right vertex count = %d, triangle count = %d"), vertexCountRight, triangleCountRight);
	 vertexDataRight = new float[vertexCountRight * 3];
	 indexDataRight = new int[triangleCountRight * 3];
	 for (i = 0; i < vertexCountRight * 3; i++)
	 {
		 vertexDataRight[i] = vertexDataPointer[i];
	 }

	 for (i = 0; i < triangleCountRight * 3; i++)
	 {
		 indexDataRight[i] = indexDataPointer[i];
	 }

	 return true;
#endif

	 return false;
 }

 void UEyeMaskComponent::CreateStencilMesh()
 {
	 FMatrix InvProj[2];

	 const float WorldUnitToMeter = GWorld->GetWorldSettings()->WorldToMeters;
	 const float MeterToWorldUnit = 1 / WorldUnitToMeter;

	 const float ZNear = GNearClippingPlane / WorldUnitToMeter;

	 const float FOV = 90;
	 const float Tangent = ZNear * FMath::Tan(FMath::DegreesToRadians(FOV / 2));

	 float L = -Tangent, R = Tangent, T = Tangent, B = -Tangent;

	 const float ZDistance = ZNear + 0.01f; 

	 SetRelativeLocation(FVector(ZDistance * WorldUnitToMeter, 0, 0));
	 SetRelativeRotation(FRotator::ZeroRotator);
	 SetRelativeScale3D(FVector::OneVector);

	 UE_LOG(LogTemp, Log, TEXT("WorldUnitToMeter %f, ZNear %f, ZDistance %f"), WorldUnitToMeter, ZNear, ZDistance);

	 // Transform from right hand rule to Unreal World
	 FMatrix AxisChangeMatrix = FMatrix::Identity;
	 AxisChangeMatrix.M[0][0] = 0, AxisChangeMatrix.M[0][1] = 1, AxisChangeMatrix.M[0][2] = 0;
	 AxisChangeMatrix.M[1][0] = 0, AxisChangeMatrix.M[1][1] = 0, AxisChangeMatrix.M[1][2] = 1;
	 AxisChangeMatrix.M[2][0] = -1, AxisChangeMatrix.M[2][1] = 0, AxisChangeMatrix.M[2][2] = 0;


	 UMaterialInterface * MaterialMask = (UMaterialInterface*)LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/Materia/EyeMask.EyeMask'"));
	 if (MaterialMask == nullptr)
	 {
		 UE_LOG(LogTemp, Log, TEXT("UEyeMaskComponent Can't find EyeMask.EyeMask"));
		 return;
	 }

	 IXRTrackingSystem* XRSystem = GEngine->XRSystem.Get();
	 EHMDTrackingOrigin::Type dofType = XRSystem->GetTrackingOrigin();


	 for (int e = 0; e < 2; e++)
	 {
		 //GetClippingPlaneBoundary(e, &L, &R, &T, &B);
		 L *= ZNear; R *= ZNear; T *= ZNear; B *= ZNear;

		 InvProj[e] = MakeGLProjection(L, R, T, B, ZNear, 1000).Inverse();

		 // Load EyeMask Mesh from API
		 TArray<FVector> vertices;
		 TArray<FVector> normals;
		 TArray<int32> triangles;
		 TArray<FVector2D> uvs;
		 TArray<FLinearColor> colors;
		 TArray<FProcMeshTangent> tangents;

		 // Put array to TArray
		 const EyeMaskData data = GetEyeMaskData(e);
		 if (data.vertexFloatCount <= 0 || data.indexIntCount < 0)
			 continue;
		 MakeTriangle(data.vertices, data.vertexFloatCount, data.indices, data.indexIntCount, 0, vertices, normals, triangles, uvs, colors, tangents);

		 // Convert from
		 TArray<FVector> newVertices;
		 int N = data.vertexFloatCount / 3;
		 for (int i = 0; i < N; i++) {
			 auto v = InvProj[e].TransformFVector4(FVector4(vertices[i].X, vertices[i].Y, vertices[i].Z, 1));
			 v = v / v.W;

			 auto newVertex = AxisChangeMatrix.TransformVector((FVector(v.X, v.Y, 0) / ZNear * ZDistance) * WorldUnitToMeter);

			 newVertices.Add(newVertex);
		 }

		 CreateMeshSection_LinearColor(e, newVertices, triangles, normals, uvs, colors, tangents, false);
		 UMaterialInstanceDynamic * dynamic = UMaterialInstanceDynamic::Create(MaterialMask, this);
		 if (dynamic == nullptr)
		 {
			 UE_LOG(LogTemp, Log, TEXT("Can't create MaterialInstanceDynamic"));
			 return;
		 }

		 FQuat e2hOrientation;
		 FVector e2hPosition;
		 XRSystem->GetRelativeEyePose(IXRTrackingSystem::HMDDeviceId, e == 0 ? eSSP_LEFT_EYE : eSSP_RIGHT_EYE, e2hOrientation, e2hPosition);
		 dynamic->SetVectorParameterValue("EyeToHeadOffset", FLinearColor(e2hPosition.Y, e2hPosition.Z, e2hPosition.X, 1));
		 dynamic->SetScalarParameterValue("EyeSpecify", e == 0 ? -1 : 1);
		 dynamic->SetVectorParameterValue("Color", Color);
		 UE_LOG(LogTemp, Log, TEXT("UEyeMaskComponent EyeToHeadOffsetPos %d (X,Y,Z)= (%f, %f, %f)"), e, e2hPosition.Y, e2hPosition.Z, e2hPosition.X);

		 SetMaterial(e, dynamic);
	 }
	 ContainsPhysicsTriMeshData(false);
 }


#define RM_R 1.04f
#define RM_P0 0.52
#define RM_P1 0.90666
#define RM_Z -1  // near plane value in right hand rule clipping space

 UEyeMaskComponent::EyeMaskData UEyeMaskComponent::GetEyeMaskData(int eye)
 {
	 bool useDebugMesh = false;
#if WITH_EDITOR
	 useDebugMesh = true;
#endif
	 if (useDebugMesh)
	 {
		 /**
		 *   15    11   0    1     12
		 *   +----------+----------+
		 *   |    _+    |    +_    |
		 *   |  -   -   |   -   -  |
		 * 10| + _   -  |  -   _ + |2
		 *   |-    -  - | -  -     |
		 *  9+----------*----------+3
		 *   |-   _ - - | - - _   -|
		 *  8| +     -  |  -     + |4
		 *   |  -_  -   |   -  _-  |
		 *   |    -+_   |   _+-    |
		 *   +----------+----------+
		 *   14    7    6    5     13
		 *
		**/
		 static float verticesF[]{
			 // XYZ
			 // Circle start from Top
			 0,			RM_R,	RM_Z,  // 0
			 RM_P0,		RM_P1,	RM_Z,  // 1
			 RM_P1,		RM_P0,	RM_Z,  // 2
			 RM_R,		0,		RM_Z,  // 3
			 RM_P1,		-RM_P0,	RM_Z,  // 4
			 RM_P0,		-RM_P1,	RM_Z,  // 5
			 0,			-RM_R,	RM_Z,  // 6
			 -RM_P0,		-RM_P1,	RM_Z,  // 7
			 -RM_P1,		-RM_P0,	RM_Z,  // 8
			 -RM_R,		0,		RM_Z,  // 9
			 -RM_P1,		RM_P0,	RM_Z,  // 10
			 -RM_P0,		RM_P1,	RM_Z,  // 11

			 // Corner
			  RM_R,   RM_R, RM_Z,  // 12
			  RM_R,  -RM_R, RM_Z,  // 13
			 -RM_R,  -RM_R, RM_Z,  // 14
			 -RM_R,   RM_R, RM_Z,  // 15

			 0, 0, RM_Z  // 16 center
		 };

		 static int indexI[]{
			 0, 1, 12,
			 1, 2, 12,
			 2, 3, 12,
			 3, 4, 13,
			 4, 5, 13,
			 5, 6, 13,
			 6, 7, 14,
			 7, 8, 14,
			 8, 9, 14,
			 9, 10, 15,
			 10, 11, 15,
			 11, 0, 15,

			 16, 16, 16
		 };

		 if (UseEyeSpecifiedMesh) {
			 if (eye == 0) {
				 indexI[36] = 16;
				 indexI[37] = 5;
				 indexI[38] = 4;
			 }
			 else {
				 indexI[36] = 16;
				 indexI[37] = 8;
				 indexI[38] = 7;
			 }
		 }

		 EyeMaskData data;
		 data.vertexFloatCount = 16 * 3 + (UseEyeSpecifiedMesh ? 3 : 0);
		 data.indexIntCount = 12 * 3 + (UseEyeSpecifiedMesh ? 3 : 0);
		 data.vertices = verticesF;
		 data.indices = indexI;

		 return data;
	 }
	 else
	 {
		 EyeMaskData data;
		 if (eye == 0)
		 {
			 data.vertexFloatCount = vertexCountLeft * 3;
			 data.indexIntCount = triangleCountLeft * 3;
			 data.vertices = vertexDataLeft;
			 data.indices = indexDataLeft;
		 }
		 else if (eye == 1)
		 {
			 data.vertexFloatCount = vertexCountRight * 3;
			 data.indexIntCount = triangleCountRight * 3;
			 data.vertices = vertexDataRight;
			 data.indices = indexDataRight;
		 }
		 else
		 {
			 data.vertexFloatCount = 0;
			 data.indexIntCount = 0;
			 data.vertices = nullptr;
			 data.indices = nullptr;
		 }
		 return data;
	 }
 }