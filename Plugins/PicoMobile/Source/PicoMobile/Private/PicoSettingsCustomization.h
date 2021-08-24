// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.
#pragma once
#if WITH_EDITOR
#include "IDetailCustomization.h"
#include "PicoMobileSettings.h"
#include "Input/Reply.h"
#include "Widgets/Input/SCheckBox.h"

class SCheckBox;

class FPicoSettingsCustomization : public IDetailCustomization
{
public:
    // Makes a new instance of this detail layout class for a specific detail view requesting it
    static TSharedRef<IDetailCustomization> MakeInstance();

    // IDetailCustomization interface
    virtual void CustomizeDetails(IDetailLayoutBuilder& DetailLayout) override;
    // End of IDetailCustomization interface
    FPicoSettingsCustomization();  
    void ShowDialogWidget();
private:
    
    IDetailLayoutBuilder* SavedLayoutBuilder;
    static TSharedPtr<SWindow> MsgWindow;
    bool bCheckBoxChecked;
    UPicoMobileSettings* PicoSettings;
    bool bIsIgnoreShowDialog;
    FReply OnOKButtonClick();
    FReply OnIgnoreButtonClick();
    void OnCheckBoxChange(ECheckBoxState NewCheckedState);
};
#endif