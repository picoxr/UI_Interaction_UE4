// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#pragma once
#include "CoreMinimal.h"
#include "PXR_MRTypes.h"
#include "PXR_AnchorComponent.h"
#include "PXR_MRFunctionLibrary.generated.h"

UCLASS()
class PICOXRMR_API UPICOXRMRFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	/// <summary>
	/// Gets the universally unique identifier (UUID) of an anchor entity.
	/// </summary>
	/// <param name="BoundActor">The bound actor of the anchor entity to get UUID for.</param>
	/// <param name="OutAnchorUUID">Returns the UUID of the anchor entity.</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintPure, Category = "PXR|PXRMR")
	static bool PXR_GetAnchorEntityUuid(AActor* BoundActor, FPICOSpatialUUID& OutAnchorUUID,EPICOResult& OutResult);
	
	/// <summary>
	/// Gets the information about the Bounding Box 2D for a SceneCapture.
	/// Before calling this method, you need to load SceneCaptures and get the SceneInfos first. The result contains the UUIDs of SceneCaptures loaded.
	/// </summary>
	/// <param name="UUID"> Specifies the uuid of the SceneCapture. </param>
	/// <param name="OutBoundingBox2D">
	/// * `Center`: Returns the offset of the boundary's position relative to the world position.
	/// * `Extent`: Returns the width and height of the boundary.
	/// </param>
	/// <returns>Bool:
	/// <ul>
	/// <li> `true` - success</li>
	/// <li> `false` - failure</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRMR")
	static bool PXR_GetSceneBoundingBox2D(const FPICOSpatialUUID& UUID, FPICOBoundingBox2D& OutBoundingBox2D);

	/// <summary>
	/// Gets the information about the polygon (irregular plane) for an anchor entity.
	/// Before calling this method, you need to load SceneCaptures and get the SceneInfos first. The result contains the UUIDs of SceneCaptures loaded.
	/// </summary>
	/// <param name="UUID"> Specifies the uuid of the SceneCapture. </param>
	/// <param name="OutPolygonVertices">
	/// * `Vertices`: The positions of the polygon's vertices on the X, Y, and Z axis.
	/// </param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRMR")
	static bool PXR_GetSceneBoundingPolygon(const FPICOSpatialUUID& UUID, TArray<FVector>& OutPolygonVertices);
	
	/// <summary>
	/// Gets the information about the Bounding Box 3D for an SceneCapture.
	/// Before calling this method, you need to load SceneCaptures and get the SceneInfos first. The result contains the UUIDs of SceneCaptures loaded.
	/// </summary>
	/// <param name="UUID"> Specifies the uuid of the SceneCapture. </param>
	/// <param name="OutBoundingBox3D">
	/// * `Center`: Returns the offset of the boundary's position relative to the world position.
	/// * `Extent`: Returns the width, height and depth of the boundary.
	/// </param>
	/// <returns>Bool:
	/// <ul>
	/// <li> `true` - success</li>
	/// <li> `false` - failure</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRMR")
	static bool PXR_GetSceneBoundingBox3D(const FPICOSpatialUUID& UUID, FPICOBoundingBox3D& OutBoundingBox3D);
	
	/// <summary>
	/// Gets the pose of an actor's anchor entit by Actor.
	/// </summary>
	/// <param name="BoundActor">Specifies the Actor for which you want to get anchor entity pose information.</param>
	/// <param name="OutTransform">
	/// * `Location`: The location of the anchor entity.
	/// * `Rotation`: The rotation of the anchor entity.
	/// * `Scale`: The scale of the anchor entity. `1` by default.
	/// </param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintPure, Category = "PXR|PXRMR")
	static bool PXR_GetAnchorPoseByActor(AActor* BoundActor, FTransform& OutTransform,EPICOResult& OutResult);

	/// <summary>
	/// Gets the pose of an actor's anchor entity by AnchorComponent.
	/// </summary>
	/// <param name="AnchorComponent">Specifies the AnchorComponent for which you want to get anchor entity pose information.</param>
	/// <param name="OutTransform">
	/// * `Location`: The location of the anchor entity.
	/// * `Rotation`: The rotation of the anchor entity.
	/// * `Scale`: The scale of the anchor entity. `1` by default.
	/// </param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintPure, Category = "PXR|PXRMR")
	static bool PXR_GetAnchorPoseByComponent(UPICOAnchorComponent* AnchorComponent, FTransform& OutTransform,EPICOResult& OutResult);

	/// <summary>
	/// Destroy anchor entity by AnchorComponent.
	/// </summary>
	/// <param name="AnchorComponent">Specifies the AnchorComponent for the anchor you want to destroy.</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRMR")
	static bool PXR_DestroyAnchorByComponent(UPICOAnchorComponent* AnchorComponent,EPICOResult& OutResult);

	/// <summary>
	/// Destroy anchor entity by Actor.
	/// </summary>
	/// <param name="BoundActor">Specifies the Actor for the anchor you want to destroy.</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRMR")
	static bool PXR_DestroyAnchorByActor(AActor* BoundActor,EPICOResult& OutResult);

	/// <summary>
	/// Checks if an Actor's anchor is valid.
	/// </summary>
	/// <param name="BoundActor">Specifies the Actor for the anchor you want to check.</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true` - valid</li>
	/// <li>`false` - invalid</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintPure, Category = "PXR|PXRMR")
	static bool PXR_IsAnchorValidForActor(AActor* BoundActor);

	/// <summary>
	/// Checks if an AnchorComponent's anchor is valid.
	/// </summary>
	/// <param name="AnchorComponent">Specifies the AnchorComponent for the anchor you want to check.</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true` - valid</li>
	/// <li>`false` - invalid</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintPure, Category = "PXR|PXRMR")
	static bool PXR_IsAnchorValidForComponent(UPICOAnchorComponent* AnchorComponent);

	/// <summary>
	/// Spawns an actor from the specified anchor load result.
	/// </summary>
	/// <param name="WorldContext">The world context in which the actor will be spawned.</param>
	/// <param name="LoadResult">The anchor load result containing information for spawning, including the anchor's handle, UUID, and location.</param>
	/// <param name="ActorClass"> The class of the actor to be spawned.</param>
	/// <returns>The spawned actor, or nullptr if spawning fails.
	/// </returns>	
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRMR", meta = (WorldContext = "WorldContext", UnsafeDuringActorConstruction = "true"))
	static AActor* PXR_SpawnActorFromLoadResult(UObject* WorldContext, const FAnchorLoadResult& LoadResult, UClass* ActorClass);

	/// <summary>
	/// From AnchorHandle To FString.
	/// </summary>
	/// <param name="AnchorHandle">Specifies the AnchorHandle for which you want to convert.</param>
	/// <returns>FString of AnchorHandle.
	/// </returns>	
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToString (Anchor Handle)", CompactNodeTitle = "->", BlueprintAutocast), Category = "PXR|PXRMR")
	static FString PXR_FromAnchorToString(const FPICOSpatialHandle& AnchorHandle);

	/// <summary>
	/// From UUID To FString.
	/// </summary>
	/// <param name="AnchorUUID">Specifies the AnchorUUID for which you want to convert.</param>
	/// <returns>FString of UUID.
	/// </returns>	
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToString (Anchor UUID)", CompactNodeTitle = "->", BlueprintAutocast), Category = "PXR|PXRMR")
	static FString PXR_FromUUIDToString(const FPICOSpatialUUID& AnchorUUID);

	/// <summary>
	/// From FString To UUID.
	/// </summary>
	/// <param name="AnchorUUIDString">Specifies the AnchorUUIDString for which you want to convert.</param>
	/// <returns>UUID.
	/// </returns>	
	UFUNCTION(BlueprintPure, Category = "PXR|PXRMR")
	static FPICOSpatialUUID PXR_FromStringToUUID(const FString& AnchorUUIDString);

	/// <summary>
	/// Closes Spatial Mesh scanning.
	/// </summary>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRMR")
	static bool PXR_CloseSpatialMeshScanning();

	/// <summary>
	/// Closes Spatial Anchor service.
	/// </summary>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRMR")
	static bool PXR_CloseSpatialAnchorService();

	/// <summary>
	/// Closes Scene Capture service.
	/// </summary>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRMR")
	static bool PXR_CloseSceneCaptureService();

	/// <summary>
	///  Creates Scene Bounding Polygon.
	/// </summary>
	/// <param name="BoundActor">Specifies the actor bound by polygon.</param>
	/// <param name="bNeverCreateCollision">True if never create collision, false otherwise.</param>
	/// <param name="bFlipPolygon"> True if you want to flip polygon, false otherwise. It is recommend to be ture in Floor type, otherwise the orientation is down, which may affect rendering and collision.</param>	
	/// <param name="UseWireframe">True if you want to use Wireframe, false otherwise.</param>
	/// <param name="Transform">The transform of polygon.</param>
	/// <param name="Vertices">The set of vertices.</param>
	/// <param name="DefaultMeshMaterial"> Default mesh material.</param>
	/// <returns>Bool:
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRMR")
	static bool PXR_CreateSceneBoundingPolygon(AActor* BoundActor,bool bNeverCreateCollision,bool bFlipPolygon,bool UseWireframe,const FTransform& Transform,const TArray<FVector>& Vertices,UMaterialInterface* DefaultMeshMaterial);

	/// <summary>
	/// Changes Spatial Mesh's Lod Setting.
	/// </summary>
	/// <param name="SpatialMeshLod">Specifies the Lod for which you want to set.</param>	
	/// <returns>Bool:
	/// <ul>
	/// <li>`true` - success</li>
	/// <li>`false` - failure</li>
	/// </ul>
	/// </returns>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRMR")
	static bool PXR_ChangeSpatialMeshLodSetting(EPICOSpatialMeshLod SpatialMeshLod);

	/// <summary>
	/// Gets Spatial Mesh Lod Setting.
	/// </summary>
	/// <returns>Spatial Mesh Lod.
	/// </returns>	
	UFUNCTION(BlueprintPure, Category = "PXR|PXRMR")
	static EPICOSpatialMeshLod PXR_GetSpatialMeshLodSetting();

	/// <summary>
	/// Gets Spatial Mesh scanning state.
	/// </summary>
	/// <returns>State of Spatial Mesh scanning:
    ///	- Initialized: After checking the Spacial Mesh feature in ProjectSettings, the initialization will be completed during the app startup process.
	///	- Running: This state is set after the Spatial Mesh scanning has been successfully started.
	///	- Stopped: This state is set after the Spatial Mesh scanning has been successfully shut down.
    /// </returns>		
	UFUNCTION(BlueprintPure, Category = "PXR|PXRMR")
	static EPICOMRState PXR_GetSpatialMeshScanningState();

	/// <summary>
	/// Get Spatial Anchor service state.
	/// </summary>
	/// <returns>State of Spatial Anchor service:
    ///	- Initialized: After checking the Spatial Anchor feature in ProjectSettings, the initialization will be completed during the app startup process.
	///	- Running: This state is set after the Spatial Anchor service has been successfully started.
	///	- Stopped: This state is set after the Spatial Anchor service has been successfully shut down.
    /// </returns>	
	UFUNCTION(BlueprintPure, Category = "PXR|PXRMR")
	static EPICOMRState PXR_GetSpatialAnchorServiceState();

	/// <summary>
	/// Get Scene Capture service state.
	/// </summary>
    /// <returns>State of Scene Capture service:
    ///	- Initialized: After checking the Scene Capture feature in ProjectSettings, the initialization will be completed during the app startup process.
	///	- Running: This state is set after the Scene Capture service has been successfully started.
	///	- Stopped: This state is set after the Scene Capture service has been successfully shut down.
    /// </returns>	
	UFUNCTION(BlueprintPure, Category = "PXR|PXRMR")
	static EPICOMRState PXR_GetSceneCaptureServiceState();

	/// <summary>
	/// Reset Spatial Mesh Infos State.
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "PXR|PXRMR")
	static void PXR_ResetSpatialMeshInfosState();
};