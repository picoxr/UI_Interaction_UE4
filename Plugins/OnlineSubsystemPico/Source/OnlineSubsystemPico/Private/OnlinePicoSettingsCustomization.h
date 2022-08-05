// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

#pragma once
#if WITH_EDITOR
#include "IDetailCustomization.h"
#include "OnlinePicoSettings.h"
#include "Input/Reply.h"
#include "Widgets/Input/SCheckBox.h"

class SCheckBox;

class FOnlinePicoSettingsCustomization : public IDetailCustomization
{
public:
    static TSharedRef<IDetailCustomization> MakeInstance();
    virtual void CustomizeDetails(IDetailLayoutBuilder& DetailLayout) override;
    FOnlinePicoSettingsCustomization();
    void ShowDialogWidget();
private:
    IDetailLayoutBuilder* SavedLayoutBuilder;
    static TSharedPtr<SWindow> MsgWindow;
    bool bCheckBoxChecked;
    UOnlinePicoSettings* OnlinePicoSettings;
    bool bIsIgnoreShowDialog;
    FReply OnOKButtonClick();
    FReply OnIgnoreButtonClick();
    void OnCheckBoxChange(ECheckBoxState NewCheckedState);
};
#endif
