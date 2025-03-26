//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once

#include "Factories/Factory.h"
#include "AssetTypeActions_Base.h"
#include "PicoSpatializationSourceSettings.h"
#include "PicoSpatializationSourceSettingsFactory.generated.h"

class FAssetTypeActions_PicoSpatializationSourceSettings : public FAssetTypeActions_Base
{
public:
	virtual FText GetName() const override;
	virtual FColor GetTypeColor() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual uint32 GetCategories() override;
	virtual const TArray<FText>& GetSubMenus() const override;
};

/**
 * 
 */
UCLASS()
class PICOSPATIALAUDIOEDITOR_API UPicoSpatializationSourceSettingsFactory : public UFactory
{
	GENERATED_BODY()
	UPicoSpatializationSourceSettingsFactory(const FObjectInitializer& ObjectInitializer);
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
	                                  UObject* Context, FFeedbackContext* Warn) override;
	virtual uint32 GetMenuCategories() const override;
};
