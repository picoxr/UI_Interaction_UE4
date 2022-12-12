#include "PicoSpatialAudioEditorModule.h"

#define LOCTEXT_NAMESPACE "FPicoSpatialAudioEditorModule"

DEFINE_LOG_CATEGORY(LogPicoSpatialAudioEditor);

void FPicoSpatialAudioEditorModule::StartupModule()
{
	//	Register global settings in Project Settings menu
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "Pico Spatial Audio",
		                                 LOCTEXT("RuntimeSettingsName", "Pico Spatial Audio"),
		                                 LOCTEXT("RuntimeSettingsDescription",
		                                         "Global settings for Pico Spatial Audio plugin, which applys to the entire game"),
		                                 GetMutableDefault<UPicoSpatialAudioSettings>());

		// Register the audio editor asset type actions.
		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

		AssetTools.RegisterAssetTypeActions(MakeShared<FAssetTypeActions_PicoSpatializationSourceSettings>());
		AssetTools.RegisterAssetTypeActions(MakeShared<FAssetTypeActions_PicoSpatialAudioSceneMaterialSettings>());

		//	Register build utilities for acoustic meshes
		BuildAllNecessaryAcousticMeshesDelegate.BindStatic(&BuildAllNecessaryAcousticMeshes);
		FEditorBuildUtils::RegisterCustomBuildType(FName(TEXT("PicoSpatialAudioMeshBaking")),
		                                           BuildAllNecessaryAcousticMeshesDelegate,
		                                           FBuildOptions::BuildGeometry);

		//	Register build category and button for acoustic mesh baking
		// FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
		
	}
}

void FPicoSpatialAudioEditorModule::ShutdownModule()
{
	//	Unregister global settings in Project Settings menu
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "Pico Spatial Audio");
	}

	//	Unregister build utilities for acoustic meshes
	FEditorBuildUtils::UnregisterCustomBuildType(FName(TEXT("PicoSpatialAudioMeshBaking")));
}

EEditorBuildResult FPicoSpatialAudioEditorModule::BuildAllNecessaryAcousticMeshes(UWorld* World, FName BuildId)
{
	UE_LOG(LogPicoSpatialAudioEditor, Display,
	       TEXT("Baking all necessary acoustic meshes (World: %s) (Build ID: %s)"), *World->GetName(),
	       *BuildId.ToString());
	for (TActorIterator<AActor> Actor(World); Actor; ++Actor)
	{
		TArray<UActorComponent*> Components;
		Actor->GetComponents(
			UPicoSpatialAudioSceneGeometryComponent::StaticClass(), Components);
		for (auto* Component : Components)
		{
			auto* Geometry = static_cast<UPicoSpatialAudioSceneGeometryComponent*>(Component);
			if (Geometry != nullptr)
			{
				Geometry->BakeMesh();
			}
		}
	}

	return EEditorBuildResult::Success;
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPicoSpatialAudioEditorModule, PicoSpatialAudioEditor)
