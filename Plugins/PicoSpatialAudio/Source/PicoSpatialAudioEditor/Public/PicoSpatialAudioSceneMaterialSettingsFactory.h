//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once

#include "Factories/Factory.h"
#include "AssetTypeActions_Base.h"
#include "PicoSpatialAudioSceneMaterialSettings.h"
#include "PicoSpatialAudioSceneMaterialSettingsFactory.generated.h"

class FAssetTypeActions_PicoSpatialAudioSceneMaterialSettings : public FAssetTypeActions_Base
{
public:
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual uint32 GetCategories() override;
	virtual const TArray<FText>& GetSubMenus() const override;
};

UCLASS()
class PICOSPATIALAUDIOEDITOR_API UPicoSpatialAudioSceneMaterialSettingsFactory : public UFactory
{
	GENERATED_BODY()
	UPicoSpatialAudioSceneMaterialSettingsFactory(const FObjectInitializer& ObjectInitializer);
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
									  UObject* Context, FFeedbackContext* Warn) override;
	virtual uint32 GetMenuCategories() const override;
};
