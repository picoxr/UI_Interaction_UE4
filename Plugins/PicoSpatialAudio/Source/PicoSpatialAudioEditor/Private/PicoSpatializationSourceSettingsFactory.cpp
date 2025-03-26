//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.


#include "PicoSpatializationSourceSettingsFactory.h"

FText FAssetTypeActions_PicoSpatializationSourceSettings::GetName() const
{
	return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_PicoSpatializationSourceSettings",
	                 "Pico Spatial Audio Spatialization Settings");
}

FColor FAssetTypeActions_PicoSpatializationSourceSettings::GetTypeColor() const
{
	return FColor(64, 64, 64);
}

UClass* FAssetTypeActions_PicoSpatializationSourceSettings::GetSupportedClass() const
{
	return UPicoSpatializationSourceSettings::StaticClass();
}

uint32 FAssetTypeActions_PicoSpatializationSourceSettings::GetCategories()
{
	return EAssetTypeCategories::Sounds;
}

const TArray<FText>& FAssetTypeActions_PicoSpatializationSourceSettings::GetSubMenus() const
{
	static const TArray<FText> SubMenus
	{
		NSLOCTEXT("AssetTypeActions", "AssetTypeActions_AssetSoundPicoSpatialAudioSubMenu", "Pico Spatial Audio")
	};

	return SubMenus;
}

UPicoSpatializationSourceSettingsFactory::UPicoSpatializationSourceSettingsFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UPicoSpatializationSourceSettings::StaticClass();

	bCreateNew = true;
	bEditorImport = false;
	bEditAfterNew = true;
}

UObject* UPicoSpatializationSourceSettingsFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name,
                                                                    EObjectFlags Flags, UObject* Context,
                                                                    FFeedbackContext* Warn)
{
	return Cast<UObject>(NewObject<UPicoSpatializationSourceSettings>(InParent, Name, Flags));
}

uint32 UPicoSpatializationSourceSettingsFactory::GetMenuCategories() const
{
	return EAssetTypeCategories::Sounds;
}
