// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#pragma once

#include "CoreMinimal.h"
#include "Delegates/DelegateCombinations.h"
#include "PXR_PluginWrapper.h"
#include "PXR_Log.h"
#include "PXR_HMDPrivate.h"
#include "PXR_HMDRuntimeSettings.h"
#include "Misc/EnumRange.h"
#include "PXR_MRTypes.generated.h"

DEFINE_LOG_CATEGORY_STATIC(PxrMR, Log, All);

#define PXR_SUCCESS(Result) (uint8(Result) == 0)
#define PXR_FAILURE(Result) (uint8(Result) != 0)

UENUM(BlueprintType)
enum class EPICOResult : uint8
{
	PXR_Success = 0,
	PXR_TimeoutExpired,

	PXR_Spatial_Mesh_Data_No_Update,
	PXR_Scene_Capture_Process_Successful,
	PXR_Error_Spatial_Mesh_Volumes_Update_Failed,
	
	PXR_Error_ValidationFailure,
	PXR_Error_RuntimeFailure,
	PXR_Error_OutOfMemory,
	PXR_Error_APIVersionUnsupported,
	PXR_Error_InitializationFailed,
	PXR_Error_FunctionUnsupported,
	PXR_Error_FeatureUnsupported,
	PXR_Error_LimitReached,
	PXR_Error_SizeInsufficient,
	PXR_Error_HandleInvalid,
	PXR_Error_Pose_Invalid,
	PXR_Error_SpatialLocalizationRunning,
	PXR_Error_SpatialLocalizationNotRunning,
	PXR_Error_SpatialMapCreated,
	PXR_Error_SpatialMapNotCreated,
	PXR_Error_SpatialSensingServiceUnavailable,
	PXR_Error_ComponentNotSupported,
	PXR_Error_ComponentConflict,
	PXR_Error_ComponentNotAdded,
	PXR_Error_ComponentAdded,
	PXR_Error_AnchorEntityNotFound,
	PXR_Error_Tracking_State_Invalid,
	PXR_Error_Space_Locating,
	PXR_Error_Anchor_Sharing_Network_Timeout,
	PXR_Error_Anchor_Sharing_Authentication_Failure,
	PXR_Error_Anchor_Sharing_Network_Failure,
	PXR_Error_Anchor_Sharing_Localization_Fail,
	PXR_Error_Anchor_Sharing_Map_Insufficient,

	PXR_Error_Permission_Insufficient,
	PXR_Error_Unknow
};

UENUM(BlueprintType)
enum class EPICOSpatialTrackingState : uint8
{
	SpatialTrackingState_Invalid	= 0,
	SpatialTrackingState_Valid		= 1,
	SpatialTrackingState_Limited	= 2
};

UENUM(BlueprintType)
enum class EPICOSpatialTrackingStateMessage : uint8
{
	SpatialTrackingStateMessage_Unknown			= 0,
	SpatialTrackingStateMessage_InternalError	= 1,
};

UENUM(BlueprintType)
enum class EPICOAnchorComponentTypeFlag : uint8
{
	ComponentFlag_None = 0,
	ComponentFlag_Pose = 1,
	ComponentFlag_Persistence = 2,
	ComponentFlag_SceneLabel = 3,
	ComponentFlag_Plane = 4,
	ComponentFlag_Volume = 5
};

UENUM(BlueprintType)
enum class EPICOSpatialSceneDataTypeFlags : uint8
{
	SpatialSceneDataTypeFlag_None = 0,
	SpatialSceneDataTypeFlag_Unknown = 1,
	SpatialSceneDataTypeFlag_Floor = 2,
	SpatialSceneDataTypeFlag_Ceiling = 3,
	SpatialSceneDataTypeFlag_Wall = 4,
	SpatialSceneDataTypeFlag_Door = 5,
	SpatialSceneDataTypeFlag_Window = 6,
	SpatialSceneDataTypeFlag_Opening = 7,
	SpatialSceneDataTypeFlag_Object = 8,
};

UENUM(BlueprintType)
enum class EPICOAnchorSceneLabel : uint8
{
	SceneLabel_Unknown		= 0,
	SceneLabel_Floor		= 1,
	SceneLabel_Ceiling		= 2,
	SceneLabel_Wall			= 3,
	SceneLabel_Door			= 4,
	SceneLabel_Window		= 5,
	SceneLabel_Opening		= 6,
	SceneLabel_Table		= 7,
	SceneLabel_Sofa			= 8,
};

UENUM(BlueprintType)
enum class EPICOPersistLocation : uint8
{
	PersistLocation_Local		= 0,
	PersistLocation_Shared		= 1,
	PersistLocation_Max		= 255 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EPICOLoadFilterType : uint8
{
	LoadFilterType_None				= 0 UMETA(Hidden),
	LoadFilterType_UUID				= 1,
	LoadFilterType_SpatialSceneData = 2
};

UENUM(BlueprintType)
enum class EPICOSpatialSceneCaptureStatus : uint8
{
	SpatialSceneCaptureStatus_NotDefined	= 0
};

USTRUCT(BlueprintType)
struct PICOXRMR_API FPICOSpatialHandle
{
	GENERATED_BODY()

	uint64_t Value;

	operator uint64_t() const { return Value; }

	FPICOSpatialHandle() { this->Value = 0; }
	FPICOSpatialHandle(const uint64_t& NewValue) { this->Value = NewValue; }
	FPICOSpatialHandle(const FPICOSpatialHandle& Anchor) { this->Value = Anchor.GetValue(); }

	bool operator==(const FPICOSpatialHandle& Other) const
	{
		return Other.GetValue() == Value;
	}

	bool IsValid() const { return Value > 0; }

	void Reset() { Value = 0; }
	
	uint64_t GetValue() const { return Value; }

	FString ToString() const
	{
		return LexToString((uint64)Value);
	}
};

USTRUCT(BlueprintType)
struct PICOXRMR_API FFutureMessage
{
	GENERATED_BODY()

	FPICOSpatialHandle MessageHandle;
	bool IsFrameBarrier;

	uint64 Uuid;
	
	FFutureMessage()
	{
		Uuid=0;
		MessageHandle=0;
		IsFrameBarrier=false;
	}
};

FORCEINLINE uint32 GetTypeHash(const FPICOSpatialHandle& Anchor)
{
	uint64 Origin = (uint64)Anchor.GetValue();
	uint32 A = Origin & 0xffffffff;
	uint32 B = (Origin >> 32) & 0xffffffff;
	uint32 Hash = HashCombine(A, B);
	return Hash;
}

template<>
struct TStructOpsTypeTraits<FPICOSpatialHandle> : public TStructOpsTypeTraitsBase2<FPICOSpatialHandle>
{
	enum
	{
		WithIdenticalViaEquality = true,
	};
};

USTRUCT(BlueprintType)
struct PICOXRMR_API FPICOSpatialUUID
{
	GENERATED_BODY()

	FPICOSpatialUUID()
	{
		FMemory::Memzero(UUIDArray, PXR_UUID_SIZE);
	}

	FPICOSpatialUUID(const uint64_t(&NewUUIDArray)[PXR_UUID_SIZE])
	{
		FMemory::Memcpy(UUIDArray, NewUUIDArray);
	}

	bool operator==(const FPICOSpatialUUID& UUID) const
	{
		return IsEqual(UUID);
	}

	bool operator!=(const FPICOSpatialUUID& UUID) const
	{
		return !IsEqual(UUID);
	}

	bool IsValid() const
	{
		static uint64_t ZeroUUID[PXR_UUID_SIZE] = { 0 };
		return FMemory::Memcmp(UUIDArray, ZeroUUID, PXR_UUID_SIZE*sizeof(uint64_t))!= 0;
	}

	bool IsEqual(const FPICOSpatialUUID& UUID) const
	{
		bool result =FMemory::Memcmp(&UUIDArray, &UUID.UUIDArray, sizeof(UUIDArray)) == 0;
		return result;
	}

	FString ToString() const
	{
		FString Result = FormatToHexString(UUIDArray[0]);
		for (int32 Index = 1; Index < PXR_UUID_SIZE; ++Index)
		{
			Result += TEXT("-");
			Result += FormatToHexString((uint64)UUIDArray[Index]);
		}
		return Result;
	}

	friend FArchive& operator<<(FArchive& Ar, FPICOSpatialUUID& UUID)
	{
		for (int32 Index = 0; Index < PXR_UUID_SIZE; ++Index)
		{
			Ar.Serialize(&UUID.UUIDArray[Index], sizeof(uint64_t));
		}
		return Ar;
	}

	bool Serialize(FArchive& Ar)
	{
		Ar << *this;
		return true;
	}

	uint64_t UUIDArray[PXR_UUID_SIZE];
};

FORCEINLINE uint32 GetTypeHash(const FPICOSpatialUUID& AnchorUUID)
{
	uint32 Hash = 0;
	for (int32 Index = 0; Index < PXR_UUID_SIZE; ++Index)
	{
		uint64 Origin = (uint64)AnchorUUID.UUIDArray[Index];
		uint32 A = Origin & 0xffffffff;
		uint32 B = (Origin >> 32) & 0xffffffff;
		Hash = HashCombine(Hash, A);
		Hash = HashCombine(Hash, B);
	}
	return Hash;
}

template<>
struct TStructOpsTypeTraits<FPICOSpatialUUID> : public TStructOpsTypeTraitsBase2<FPICOSpatialUUID>
{
	enum
	{
		WithIdenticalViaEquality = true,
		WithSerializer = true,
	};
};

USTRUCT(BlueprintType)
struct PICOXRMR_API FPICOAnchorPlaneBoundaryInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "PXR|MR")
	FVector Center = FVector::ZeroVector;

	UPROPERTY(BlueprintReadWrite, Category = "PXR|MR")
	FVector2D Extent = FVector2D::ZeroVector;
};

USTRUCT(BlueprintType)
struct PICOXRMR_API FPICOAnchorPlanePolygonInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "PXR|MR")
	int32 VerticesNum = 0;

	UPROPERTY(BlueprintReadWrite, Category = "PXR|MR")
	TArray<FVector> Vertices;
};

USTRUCT(BlueprintType)
struct PICOXRMR_API FPICOAnchorVolumeInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "PXR|MR")
	FVector Center = FVector::ZeroVector;

	UPROPERTY(BlueprintReadWrite, Category = "PXR|MR")
	FVector Extent = FVector::ZeroVector;
};

UENUM(BlueprintType)
enum class EPICOSemanticLabel:uint8
{
	Unknown = 0,
	Floor = 1,
	Ceiling = 2,
	Wall = 3,
	Door = 4,
	Window = 5,
	Opening = 6,
	Table = 7,
	Sofa = 8,
	Chair = 9,
	Human = 10,
	Curtain = 13,
	Cabinet = 14,
	Bed =15,
	Screen =17,
	VirtualWall = 18,
	Count UMETA(Hidden)
};
ENUM_RANGE_BY_VALUES(EPICOSemanticLabel, 
	EPICOSemanticLabel::Unknown, 
	EPICOSemanticLabel::Floor,
	EPICOSemanticLabel::Ceiling,
	EPICOSemanticLabel::Wall,
	EPICOSemanticLabel::Door,
	EPICOSemanticLabel::Window,
	EPICOSemanticLabel::Opening,
	EPICOSemanticLabel::Table,
	EPICOSemanticLabel::Sofa,
	EPICOSemanticLabel::Chair,
	EPICOSemanticLabel::Human,
	EPICOSemanticLabel::Curtain,
	EPICOSemanticLabel::Cabinet,
	EPICOSemanticLabel::Bed,
	EPICOSemanticLabel::Screen);


USTRUCT(BlueprintType)
struct PICOXRMR_API FPICOAnchorLoadInfo
{
	GENERATED_BODY()

	FPICOAnchorLoadInfo() :
		PersistLocation(EPICOPersistLocation::PersistLocation_Local)
	{}

	UPROPERTY(BlueprintReadWrite, Category = "PXR|MR")
	EPICOPersistLocation PersistLocation;

	UPROPERTY(BlueprintReadWrite, Category = "PXR|MR")
	TArray<FPICOSpatialUUID> UUIDFilter;


	FString ToString() const
	{
		FString Result = FString::Printf(TEXT("Location[%d], UUIDFilter[%d]"),
			(int32)PersistLocation,
			UUIDFilter.Num());

		return Result;
	}
};


USTRUCT(BlueprintType)
struct PICOXRMR_API FPICOSceneLoadInfo
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, Category = "PXR|MR")
	TArray<EPICOSemanticLabel> SemanticFilter;

	FString ToString() const
	{
		FString Result = FString::Printf(TEXT("SemanticFilter[%d]"),
			SemanticFilter.Num());

		return Result;
	}
};

USTRUCT(BlueprintType)
struct PICOXRMR_API FAnchorLoadResult
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "PXR|MR")
	FPICOSpatialUUID AnchorUUID;

	FPICOSpatialHandle AnchorHandle;

	UPROPERTY(BlueprintReadWrite, Category = "PXR|MR")
	EPICOPersistLocation PersistLocation;
};

UENUM(BlueprintType, meta = (Categories = "PICO|MR"))
enum class EPICOSpatialMeshConfig:uint8
{
	Spatial_Mesh_Config_None = 0x00000000,
	Spatial_Mesh_Config_Semantic = 0x00000001,
	Spatial_Mesh_Config_Semantic_Align_With_Vertex = 0x00000002
};

enum class EPICOProviderType:uint8
{
	Pico_Provider_Unknown=0,
	Pico_Provider_Anchor = 1,
	Pico_Provider_Mesh = 2,
	Pico_Provider_Scene_Capture = 3,
	Pico_Provider_Max
};

struct FPICOQueriedSpatialEntityInfo
{
	FPICOSpatialHandle SpatialEntityHandle;
	uint64 Time; // Spatial entity last update time
	FPICOSpatialUUID UUID;

	FPICOQueriedSpatialEntityInfo(): SpatialEntityHandle(0), Time(0)
	{
	}
};

struct FPICOQueriedSenseData
{
	TArray<PxrQueriedSpatialEntityInfo> QueriedSpatialEntityInfos;
};

struct FPICOSenseDataQueryCompletion
{
	EPICOResult FutureResult;
	FPICOSpatialHandle SnapShotHandle;

	FPICOSenseDataQueryCompletion()
	{
		FutureResult = EPICOResult::PXR_Error_Unknow;
	}
};

struct FPICOSpatialAnchorCreateCompletion
{
	EPICOResult FutureResult;
	FPICOSpatialHandle AnchorHandle;
	FPICOSpatialUUID UUID;

	FPICOSpatialAnchorCreateCompletion()
	{
		FutureResult = EPICOResult::PXR_Error_Unknow;
	}
};

struct FPICOSceneCaptureStartCompletion
{
	EPICOResult FutureResult;

	FPICOSceneCaptureStartCompletion()
	{
		FutureResult = EPICOResult::PXR_Error_Unknow;
	}
};

struct FPICOSpatialAnchorShareCompletion
{
	EPICOResult FutureResult;

	FPICOSpatialAnchorShareCompletion()
	{
		FutureResult = EPICOResult::PXR_Error_Unknow;
	}
};

struct FPICOSpatialAnchorPersistCompletion
{
	EPICOResult FutureResult;
	FPICOSpatialHandle AnchorHandle;
	FPICOSpatialUUID UUID;

	FPICOSpatialAnchorPersistCompletion()
	{
		FutureResult = EPICOResult::PXR_Error_Unknow;
	}
};

struct FPICOSpatialAnchorUnpersistCompletion
{
	EPICOResult FutureResult;
	FPICOSpatialHandle AnchorHandle;
	FPICOSpatialUUID UUID;

	FPICOSpatialAnchorUnpersistCompletion()
	{
		FutureResult = EPICOResult::PXR_Error_Unknow;
	}
};


struct FPICOSenseDataProviderStartCompletion
{
	EPICOResult FutureResult;

	FPICOSenseDataProviderStartCompletion()
	{
		FutureResult = EPICOResult::PXR_Error_Unknow;
	}
};

struct FPICOSharedSpatialAnchorDownloadCompletion
{
	EPICOResult FutureResult;

	FPICOSharedSpatialAnchorDownloadCompletion()
	{
		FutureResult = EPICOResult::PXR_Error_Unknow;
	}
};

struct FPICOSenseDataProviderCreateInfoBase
{
	EPICOProviderType Type;
};

struct FPICOSenseDataProviderCreateInfoAnchor : FPICOSenseDataProviderCreateInfoBase
{
	FPICOSenseDataProviderCreateInfoAnchor()
	{
		Type = EPICOProviderType::Pico_Provider_Anchor;
	}
};

struct FPICOSenseDataProviderCreateInfoMesh : FPICOSenseDataProviderCreateInfoBase
{
	EPICOSpatialMeshLod Lod;
	TArray<EPICOSpatialMeshConfig> ConfigArray;

	FPICOSenseDataProviderCreateInfoMesh(): Lod(EPICOSpatialMeshLod::Low)
	{
		Type = EPICOProviderType::Pico_Provider_Mesh;
	}
};

struct FPICOSenseDataProviderCreateInfoSceneCapture : FPICOSenseDataProviderCreateInfoBase
{
	FPICOSenseDataProviderCreateInfoSceneCapture()
	{
		Type = EPICOProviderType::Pico_Provider_Scene_Capture;
	}
};

UENUM(BlueprintType)
enum class EPICOSpatialEntityComponentType:uint8
{
	Location = 0,
	Semantic = 1,
	Boundary_2D = 2,
	Polygon = 3,
	Boundary_3D = 4,
	Triangle_Mesh = 5,
};

UENUM(BlueprintType)
enum class EPICOSceneType:uint8
{
	BoundingBox2D = 0,
	BoundingPolygon = 1,
	BoundingBox3D = 2,
};

struct FPICOMRMeshInfoBlock
{
	TArray<FPICOSpatialMeshInfo> MeshInfos;
};

UENUM(BlueprintType)
enum class EPICOSpatialMeshState:uint8
{
	Added = 0,
	Stable = 1,
	Updated = 2,
	Removed = 3,
};

USTRUCT(BlueprintType)
struct FPICOExtent3Df
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRMR")
	float Width;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRMR")
	float Height;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRMR")
	float Depth;

	FPICOExtent3Df()
	{
		Width = 0.0f;
		Height = 0.0f;
		Depth = 0.0f;
	}
};

USTRUCT(BlueprintType)
struct FPICOExtent2Df
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRMR")
	float Width;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRMR")
	float Height;

	FPICOExtent2Df()
	{
		Width = 0.0f;
		Height = 0.0f;
	}
};

USTRUCT(BlueprintType)
struct FPICOBoundingBox3D
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRMR")
	FTransform Center;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRMR")
	FPICOExtent3Df Extent;

	FPICOBoundingBox3D()
	{
		Center = FTransform();
		Extent = FPICOExtent3Df();
	}
};

USTRUCT(BlueprintType)
struct FPICOBoundingBox2D
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRMR")
	FVector Center;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRMR")
	FPICOExtent2Df Extent;

	FPICOBoundingBox2D()
	{
		Center = FVector();
		Extent = FPICOExtent2Df();
	}
};

USTRUCT(BlueprintType)
struct FPICOSpatialMeshInfo
{
	GENERATED_BODY()

	/** The UUID of the Mesh */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRMR")
	FPICOSpatialUUID UUID;

	/** The State of the Mesh */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRMR")
	EPICOSpatialMeshState State;

	/** The Transform of the Mesh */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRMR")
	FTransform MeshPose;

	/** The BoundingBox of the Mesh */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRMR")
	FPICOBoundingBox3D BoundingBox;

	/** The Vertices Array of the Mesh */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXRMR")
	TArray<FVector> Vertices;

	/** The Indices Array of the Mesh */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXRMR")
	TArray<int32> Indices;
	
	/** The Semantics Array of the Mesh */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXRMR")
	TArray<EPICOSemanticLabel> Semantics;

	/** The Update Time of the Mesh */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRMR")
	int64 UpdateTime;

	FPICOSpatialMeshInfo()
	{
		State = EPICOSpatialMeshState::Stable;
		UpdateTime = 0;
	}
};


USTRUCT(BlueprintType)
struct FPICOMRSceneInfo
{
	GENERATED_BODY()

	/** The UUID of the Scene */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRMR")
	FPICOSpatialUUID UUID;

	/** The Transform of the Scene */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXR|PXRMR")
	FTransform ScenePose;
	
	/** The Semantics of the Scene */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXRMR")
	EPICOSemanticLabel Semantic;

	/** The SceneType of the Scene */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PXRMR")
	EPICOSceneType SceneType;
	
};