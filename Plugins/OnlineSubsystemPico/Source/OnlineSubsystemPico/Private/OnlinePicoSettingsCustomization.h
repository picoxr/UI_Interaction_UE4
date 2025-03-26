// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

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
