//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.


#include "PicoSpatialAudioSceneMaterialSettingsFactory.h"

FText FAssetTypeActions_PicoSpatialAudioSceneMaterialSettings::GetName() const
{
	return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_PicoSpatialAudioSceneMaterialSettings",
					 "Pico Spatial Audio Scene Material Settings");
}

FColor FAssetTypeActions_PicoSpatialAudioSceneMaterialSettings::GetTypeColor() const
{
	return FColor(6, 128, 0);
}

UClass* FAssetTypeActions_PicoSpatialAudioSceneMaterialSettings::GetSupportedClass() const
{
	return UPicoSpatialAudioSceneMaterialSettings::StaticClass();
}

uint32 FAssetTypeActions_PicoSpatialAudioSceneMaterialSettings::GetCategories()
{
	return EAssetTypeCategories::Sounds;
}

const TArray<FText>& FAssetTypeActions_PicoSpatialAudioSceneMaterialSettings::GetSubMenus() const
{
	static const TArray<FText> SubMenus
	{
		NSLOCTEXT("AssetTypeActions", "AssetTypeActions_AssetSoundPicoSpatialAudioSubMenu", "Pico Spatial Audio")
	};

	return SubMenus;
}

UPicoSpatialAudioSceneMaterialSettingsFactory::UPicoSpatialAudioSceneMaterialSettingsFactory(
	const FObjectInitializer& ObjectInitializer)
{
	SupportedClass = UPicoSpatialAudioSceneMaterialSettings::StaticClass();

	bCreateNew = true;
	bEditorImport = false;
	bEditAfterNew = true;
}

UObject* UPicoSpatialAudioSceneMaterialSettingsFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name,
	EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return Cast<UObject>(NewObject<UPicoSpatialAudioSceneMaterialSettings>(InParent, Name, Flags));
}

uint32 UPicoSpatialAudioSceneMaterialSettingsFactory::GetMenuCategories() const
{
	return EAssetTypeCategories::Sounds;
}
