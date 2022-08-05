//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

#include "PXR_EyeMaskComponent.h"
#include "IXRTrackingSystem.h"
#include "PXR_Log.h"
#include "Engine/Engine.h"
#include "GameFramework/WorldSettings.h"
#include "Materials/MaterialInstanceDynamic.h"

#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#include "PxrApi.h"
#endif

#define RM_R  1.04f
#define RM_P0 0.52
#define RM_P1 0.90666
#define RM_Z  -1     // near plane value in right hand rule clipping space

UPicoXREyeMaskComponent::UPicoXREyeMaskComponent(const FObjectInitializer& ObjectInitializer):
    Super(ObjectInitializer), 
    Color(), 
    UseDebugMesh(false), 
    UseEyeSpecifiedMesh(false)
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UPicoXREyeMaskComponent::PostLoad()
{
    Super::PostLoad();
    PrimaryComponentTick.bCanEverTick = true;
}

void UPicoXREyeMaskComponent::TickComponent(float DeltaTime, ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    if (GetStencilMeshData())
    {
        CreateStencilMesh();
        // release
        delete[] VertexDataLeft;
        delete[] IndexDataLeft;
        delete[] VertexDataRight;
        delete[] IndexDataRight;

        VertexDataLeft = nullptr;
        IndexDataLeft = nullptr;
        VertexDataRight = nullptr;
        IndexDataRight = nullptr;
    }

    SetComponentTickEnabled(false);
    PrimaryComponentTick.bCanEverTick = false;
}

void UPicoXREyeMaskComponent::BeginPlay()
{
    Super::BeginPlay();
}

// Right hand rule
static FMatrix MakeGLProjection(float Left, float Right, float Top, float Bottom, float ZNear, float ZFar = 1000)
{
    float SumRL = Right + Left;
    float SumTB = Top + Bottom;
    float SubRL = Right - Left;
    float SubTB = Top - Bottom;

    auto Matrix = FMatrix(
        FPlane(2 * ZNear / SubRL, 0.0f, 0.0f, 0.0f),
        FPlane(0.0f, 2 * ZNear / SubTB, 0.0f, 0.0f),
        FPlane(SumRL / SubRL, SumTB / SubTB, -(ZFar + ZNear) / (ZFar - ZNear), -1.0f),
        FPlane(0.0f, 0.0f, -2 * ZFar * ZNear / (ZFar - ZNear), 0.0f));
    return Matrix;
}

static void MakeTriangle(const float * VerticesFloats, const int VerticesFloatCount, const int * IndicesInts, const int IndicesIntCount, int IndexOffset, TArray<FVector> &Vertices, TArray<FVector> &Normals, TArray<int32> &Triangles, TArray<FVector2D> &UVs, TArray<FLinearColor> & Colors, TArray<FProcMeshTangent> Tangents)
{
    auto Tangent = FProcMeshTangent(0, 1, 0);
    const int VerticesCount = VerticesFloatCount / 3;
    for (int i = 0; i < VerticesCount; i++) {
        Vertices.Add(FVector(VerticesFloats[3 * i + 0], VerticesFloats[3 * i + 1], -1.0f));
        Normals.Add(FVector(-1, 0, 0));
        UVs.Add(FVector2D(0, 0));
        Colors.Add(FLinearColor::Black);
        Tangents.Add(Tangent);
    }

    for (int i = 0; i < IndicesIntCount; i++) {
        Triangles.Add(IndicesInts[i] + IndexOffset);
    }

    return;
}

static void MakeTriangle(int Shape, float OffsetY, float OffsetZ, float Size, TArray<FVector> &Vertices, TArray<FVector> &Normals, TArray<int32> &Triangles, int & Index, TArray<FVector2D> &UVs, TArray<FLinearColor> & Colors, FLinearColor Color, TArray<FProcMeshTangent> Tangents)
{
    /**
    *  A B
    *  C D
    *  0-2   2  0   0-2
    *  |o   o|  |o   o|
    *  1   0-1  1-2   1
    */

    FVector A(0, OffsetY - Size, OffsetZ + Size);
    FVector B(0, OffsetY + Size, OffsetZ + Size);
    FVector C(0, OffsetY - Size, OffsetZ - Size);
    FVector D(0, OffsetY + Size, OffsetZ - Size);

    switch (Shape)
	{
    case 0:
        Vertices.Add(A);
        Vertices.Add(C);
        Vertices.Add(B);
        break;
    case 1:
        Vertices.Add(C);
        Vertices.Add(D);
        Vertices.Add(B);
        break;
    case 2:
        Vertices.Add(A);
        Vertices.Add(C);
        Vertices.Add(D);
        break;
    case 3:
        Vertices.Add(A);
        Vertices.Add(D);
        Vertices.Add(B);
        break;
    default:
    		break;
    }
    Normals.Add(FVector(-1, 0, 0));
    Normals.Add(FVector(-1, 0, 0));
    Normals.Add(FVector(-1, 0, 0));

    Triangles.Add(Index);
    Triangles.Add(Index + 1);
    Triangles.Add(Index + 2);
    Index += 3;

    UVs.Add(FVector2D(1, 0));
    UVs.Add(FVector2D(1, 1));
    UVs.Add(FVector2D(0, 0));

    Colors.Add(Color);
    Colors.Add(Color);
    Colors.Add(Color);

    auto Tangent = FProcMeshTangent(0, 1, 0);
    Tangents.Add(Tangent);
    Tangents.Add(Tangent);
    Tangents.Add(Tangent);
}
bool UPicoXREyeMaskComponent::GetStencilMeshData()
{
#if WITH_EDITOR
    if (GIsEditor)
    {
        return true;
    }
		 
#endif

#if PLATFORM_ANDROID
    int i = 0;
    float* VertexDataPointer;
    unsigned int* IndexDataPointer = {};

    // Left
    //Pxr_GetStencilmesh(PXR_EYE_LEFT, &VertexCountLeft, &TriangleCountLeft, &VertexDataPointer, &IndexDataPointer);
    if (VertexCountLeft <= 0 || TriangleCountLeft <= 0)
    {
        return false;
    } 
    VertexDataLeft = new float[VertexCountLeft * 3];
    IndexDataLeft = new int[TriangleCountLeft * 3];
    for (i = 0; i < VertexCountLeft * 3; i++)
    {
        //VertexDataLeft[i] = VertexDataPointer[i];
    }

    for (i = 0; i < TriangleCountLeft * 3; i++)
    {
        IndexDataLeft[i] = IndexDataPointer[i];
    }


    // Right
    //Pxr_GetStencilmesh(PXR_EYE_RIGHT, &VertexCountRight, &TriangleCountRight, &VertexDataPointer, &IndexDataPointer);
    if (VertexCountRight <= 0 || TriangleCountRight <= 0)
    {
        return false;
    }
    VertexDataRight = new float[VertexCountRight * 3];
    IndexDataRight = new int[TriangleCountRight * 3];
    for (i = 0; i < VertexCountRight * 3; i++)
    {
        //VertexDataRight[i] = VertexDataPointer[i];
    }

    for (i = 0; i < TriangleCountRight * 3; i++)
    {
        IndexDataRight[i] = IndexDataPointer[i];
    }

    return true;
#endif
    return false;
}

void UPicoXREyeMaskComponent::CreateStencilMesh()
{
     FMatrix InvProj[2];

	 const float WorldUnitToMeter = GWorld->GetWorldSettings()->WorldToMeters;
	 //const float MeterToWorldUnit = 1 / WorldUnitToMeter;

	 const float ZNear = GNearClippingPlane / WorldUnitToMeter;

	 const float FOV = 90;
	 const float Tangent = ZNear * FMath::Tan(FMath::DegreesToRadians(FOV / 2));

	 float L = -Tangent, R = Tangent, T = Tangent, B = -Tangent;

	 const float ZDistance = ZNear + 0.01f; 

	 SetRelativeLocation(FVector(ZDistance * WorldUnitToMeter, 0, 0));
	 SetRelativeRotation(FRotator::ZeroRotator);
	 SetRelativeScale3D(FVector::OneVector);

	 // Transform from right hand rule to Unreal World
	 FMatrix AxisChangeMatrix = FMatrix::Identity;
	 AxisChangeMatrix.M[0][0] = 0, AxisChangeMatrix.M[0][1] = 1, AxisChangeMatrix.M[0][2] = 0;
	 AxisChangeMatrix.M[1][0] = 0, AxisChangeMatrix.M[1][1] = 0, AxisChangeMatrix.M[1][2] = 1;
	 AxisChangeMatrix.M[2][0] = -1, AxisChangeMatrix.M[2][1] = 0, AxisChangeMatrix.M[2][2] = 0;


	 UMaterialInterface * MaterialMask = static_cast<UMaterialInterface*>(LoadObject<UMaterial>(nullptr, TEXT("Material'/PicoXR/Materials/Mat_EyeMask.EyeMask'"))
	 );
	 if (MaterialMask == nullptr)
	 {
		 PXR_LOGW(PxrUnreal,"UEyeMaskComponent Can't find EyeMask.EyeMask");
		 return;
	 }

	 IXRTrackingSystem* XRSystem = GEngine->XRSystem.Get();
	 for (int E = 0; E < 2; E++)
	 {
		 //GetClippingPlaneBoundary(E, &L, &R, &T, &B);
		 L *= ZNear; R *= ZNear; T *= ZNear; B *= ZNear;

		 InvProj[E] = MakeGLProjection(L, R, T, B, ZNear, 1000).Inverse();

		 // Load EyeMask Mesh from API
		 TArray<FVector> Vertices;
		 TArray<FVector> Normals;
		 TArray<int32> Triangles;
		 TArray<FVector2D> UVs;
		 TArray<FLinearColor> Colors;
		 TArray<FProcMeshTangent> Tangents;

		 // Put array to TArray
		 const EyeMaskData Data = GetEyeMaskData(E);
		 if (Data.VertexFloatCount <= 0 || Data.IndexIntCount < 0)
			 continue;
		 MakeTriangle(Data.Vertices, Data.VertexFloatCount, Data.Indices, Data.IndexIntCount, 0, Vertices, Normals, Triangles, UVs, Colors, Tangents);

		 // Convert from
		 TArray<FVector> NewVertices;
		 int N = Data.VertexFloatCount / 3;
		 for (int i = 0; i < N; i++) {
			 auto V = InvProj[E].TransformFVector4(FVector4(Vertices[i].X, Vertices[i].Y, Vertices[i].Z, 1));
			 V = V / V.W;

			 auto NewVertex = AxisChangeMatrix.TransformVector((FVector(V.X, V.Y, 0) / ZNear * ZDistance) * WorldUnitToMeter * (E == 0 ? 10 : 100));

			 NewVertices.Add(NewVertex);
		 }

		 CreateMeshSection_LinearColor(E, NewVertices, Triangles, Normals, UVs, Colors, Tangents, false);
		 UMaterialInstanceDynamic * Dynamic = UMaterialInstanceDynamic::Create(MaterialMask, this);
		 if (Dynamic == nullptr)
		 {
			 PXR_LOGW(PxrUnreal,"Can't create MaterialInstanceDynamic");
			 return;
		 }

		 FQuat EyeToHeadOrientation;
		 FVector EyeToHeadPosition;
		 if (XRSystem)
		 {
			 XRSystem->GetRelativeEyePose(IXRTrackingSystem::HMDDeviceId, E == 0 ? eSSP_LEFT_EYE : eSSP_RIGHT_EYE, EyeToHeadOrientation, EyeToHeadPosition);
		 }		 
		 Dynamic->SetVectorParameterValue("EyeToHeadOffset", FLinearColor(EyeToHeadPosition.Y, EyeToHeadPosition.Z, EyeToHeadPosition.X, 1));
		 Dynamic->SetScalarParameterValue("EyeSpecify", E == 0 ? -1 : 1);
		 Dynamic->SetVectorParameterValue("Color", Color);
	
		 SetMaterial(E, Dynamic);
	 }
	 ContainsPhysicsTriMeshData(false);
}

UPicoXREyeMaskComponent::EyeMaskData UPicoXREyeMaskComponent::GetEyeMaskData(int Eye)
{
#if WITH_EDITOR
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
	static float VerticesF[]{
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

	static int IndexI[]{
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
		if (Eye == 0) {
			IndexI[36] = 16;
			IndexI[37] = 5;
			IndexI[38] = 4;
		}
		else {
			IndexI[36] = 16;
			IndexI[37] = 8;
			IndexI[38] = 7;
		}
	}

	EyeMaskData Data;
	Data.VertexFloatCount = 16 * 3 + (UseEyeSpecifiedMesh ? 3 : 0);
	Data.IndexIntCount = 12 * 3 + (UseEyeSpecifiedMesh ? 3 : 0);
	Data.Vertices = VerticesF;
	Data.Indices = IndexI;

	return Data;
#else
	EyeMaskData Data;
	if (Eye == 0)
	{
		Data.VertexFloatCount = VertexCountLeft * 3;
		Data.IndexIntCount = TriangleCountLeft * 3;
		Data.Vertices = VertexDataLeft;
		Data.Indices = IndexDataLeft;
	}
	else if (Eye == 1)
	{
		Data.VertexFloatCount = VertexCountRight * 3;
		Data.IndexIntCount = TriangleCountRight * 3;
		Data.Vertices = VertexDataRight;
		Data.Indices = IndexDataRight;
	}
	else
	{
		Data.VertexFloatCount = 0;
		Data.IndexIntCount = 0;
		Data.Vertices = nullptr;
		Data.Indices = nullptr;
	}
	return Data;
	
#endif
}

