#pragma once
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "Framework/MultiBox/MultiBoxExtender.h"
#include "AssetToolsModule.h"
#include "ISettingsModule.h"
#include "EditorBuildUtils.h"
#include "EngineUtils.h"
#include "LevelEditor.h"
#include "PicoSpatialAudioSettings.h"
#include "PicoSpatializationSourceSettingsFactory.h"
#include "PicoSpatialAudioSceneMaterialSettingsFactory.h"
#include "PicoSpatialAudioSceneGeometryComponent.h"

DECLARE_LOG_CATEGORY_EXTERN(LogPicoSpatialAudioEditor, Display, All);

class FPicoSpatialAudioEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	FDoEditorBuildDelegate BuildAllNecessaryAcousticMeshesDelegate;
private:
	static EEditorBuildResult BuildAllNecessaryAcousticMeshes(UWorld* World, FName BuildId);
};
