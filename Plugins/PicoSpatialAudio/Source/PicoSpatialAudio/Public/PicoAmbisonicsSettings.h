//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ISoundfieldFormat.h"
#include "PicoAmbisonicsSettings.generated.h"

namespace Pxr_Audio
{
	namespace Spatializer
	{
		class FAmbisonicsEncodingSettings : public ISoundfieldEncodingSettingsProxy
		{
		public:
			int32 Order;

			virtual uint32 GetUniqueId() const override;
			virtual TUniquePtr<ISoundfieldEncodingSettingsProxy> Duplicate() const override;
		};
	}
}

/**
 * 
 */
UCLASS()
class PICOSPATIALAUDIO_API UPicoAmbisonicsSettings : public USoundfieldEncodingSettingsBase
{
	GENERATED_BODY()
public:
	//Which order of ambisonics to use for this submix.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AmbisonicsSettings,
		meta = (ClampMin = "1", ClampMax = "7", UIMin = "1", UIMax = "7"))
	int32 Order = 1;

	virtual TUniquePtr<ISoundfieldEncodingSettingsProxy> GetProxy() const override;
};
