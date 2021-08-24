// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.
#include "PicoSettingsCustomization.h"
#if WITH_EDITOR
#include "Misc/ConfigCacheIni.h"
#include "PropertyHandle.h"
#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "DetailCategoryBuilder.h"
#include "ISettingsModule.h"
#include "Modules/ModuleManager.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Text/STextBlock.h"
#include "Internationalization/Internationalization.h"
#include "Framework/Application/SlateApplication.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Images/SImage.h"

TSharedPtr<SWindow> FPicoSettingsCustomization::MsgWindow = nullptr;
#define LOCTEXT_NAMESPACE "PicoRuntimeSettings"
class UEditorStyleSettings;
class SPicoDeprecationBanner : public SCompoundWidget
{
    SLATE_BEGIN_ARGS(SPicoDeprecationBanner)
    {}
    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs)
    {
        ChildSlot
        [
            SNew(SBorder)
            .BorderBackgroundColor(this, &SPicoDeprecationBanner::GetBorderColor)
            .BorderImage(FEditorStyle::GetBrush("ToolPanel.LightGroupBorder"))
            .Padding(2.0f)
            [
                SNew(SHorizontalBox)
                +SHorizontalBox::Slot()
                .AutoWidth()
                .VAlign(VAlign_Center)
                [
                    SNew(SImage)
                    .Image(FEditorStyle::GetBrush("SettingsEditor.WarningIcon"))
                ]

                + SHorizontalBox::Slot()
                .AutoWidth()
                .Padding(8.0f, 0.0f)
                .VAlign(VAlign_Center)
                [
                    SNew(STextBlock)
                    .Font(FCoreStyle::GetDefaultFontStyle("Bold", 15))
                    .ColorAndOpacity(FLinearColor::White)
                    .HighlightColor(FLinearColor(1.0f, 1.0f, 1.0f))
                    .ShadowColorAndOpacity(FLinearColor::Black)
                    .ShadowOffset(FVector2D::UnitVector)
                    .Text(LOCTEXT("SPicoDeprecationBanner", "Note:The APPID is required to run an Entitlement Check."))
                    
                    .AutoWrapText(true)
                ]

                + SHorizontalBox::Slot()
               .AutoWidth()
               .Padding(0.f, 0.f)
               .VAlign(VAlign_Center)
               .HAlign(HAlign_Left)
               [
                    SNew(STextBlock)
                    .Font(FCoreStyle::GetDefaultFontStyle("Bold", 10))
                    .ColorAndOpacity(FLinearColor::White)
                    .Text(LOCTEXT("Create_FindYourAPPID", " Create / Find your APPID Here:"))
                    .ToolTipText(LOCTEXT("Create_FindYourAPPID", "Create / Find your APP ID"))
               ]
                + SHorizontalBox::Slot()
                .AutoWidth()
                .Padding(0.f, 0.0f)
                .VAlign(VAlign_Center)
                .HAlign(HAlign_Left)
                [
                    SNew(SButton)
                    .ButtonColorAndOpacity(FLinearColor(0,0,0,0))
                    .OnClicked(this,&SPicoDeprecationBanner::ChangePrimitive)
                    [
                        SNew(STextBlock)
                        .Font(FCoreStyle::GetDefaultFontStyle("Regular", 10))
                        .ColorAndOpacity(FLinearColor(0, 0.2f, 1.0f))
                        .Text(LOCTEXT("URL", "https://developer.pico-interactive.com/developer/overview"))
                        .ToolTipText(LOCTEXT("Create_FindYourAPPID", "Create / Find your APP ID"))
                    ]
                ]
                + SHorizontalBox::Slot()
               .AutoWidth()
               .Padding(0.f, 0.f)
               .VAlign(VAlign_Center)
               .HAlign(HAlign_Left)
               [
                    SNew(STextBlock)
                    .Font(FCoreStyle::GetDefaultFontStyle("Bold", 10))
                    .ColorAndOpacity(FLinearColor::White)
                    .Text(LOCTEXT("If", " If you do not need user Entitlement Check, please uncheck it."))
                    .ToolTipText(LOCTEXT("If", "If you do not need user Entitlement Check, please uncheck it."))
               ]
            ]
        ];
    }

    FSlateColor GetBorderColor() const
    {
        return FLinearColor(1, 1, 0);
    }
    FReply ChangePrimitive()
    {
        const FString URL = "https://developer.pico-interactive.com/developer/overview";
        FPlatformProcess::LaunchURL(*URL, nullptr, nullptr);
        return FReply::Handled();
    }
};



FPicoSettingsCustomization::FPicoSettingsCustomization()
    :SavedLayoutBuilder(nullptr),
     bCheckBoxChecked(false),
     bIsIgnoreShowDialog(false)
{
    if (MsgWindow.IsValid())
    {
        MsgWindow->HideWindow();
        MsgWindow = nullptr;
    }
    PicoSettings = GetMutableDefault<UPicoMobileSettings>();
    if (!GConfig->GetBool(TEXT("/Script/PicoMobile.PicoMobileSettings"), TEXT("bIsIgnoreShowDialog"), bIsIgnoreShowDialog, GEditorIni))
    {
        GConfig->SetBool(TEXT("/Script/PicoMobile.PicoMobileSettings"), TEXT("bIsIgnoreShowDialog"), false, GEditorIni);
        bIsIgnoreShowDialog = false;
    }
}


TSharedRef<IDetailCustomization> FPicoSettingsCustomization::MakeInstance()
{
    return MakeShareable(new FPicoSettingsCustomization);
}

void FPicoSettingsCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailLayout)
{  
    SavedLayoutBuilder = &DetailLayout;
    IDetailCategoryBuilder& PicoMobileCategory = DetailLayout.EditCategory(TEXT("PicoMobile"));
    IDetailCategoryBuilder& PlatformeCategory = DetailLayout.EditCategory(TEXT("Platform"));

    TSharedRef<SPicoDeprecationBanner> PlatformSetupMessage = SNew(SPicoDeprecationBanner);
    PlatformeCategory.AddCustomRow(LOCTEXT("Warning", "Warning"), false)
    .WholeRowWidget
    [
        PlatformSetupMessage
    ];
    ShowDialogWidget();
}

void FPicoSettingsCustomization::ShowDialogWidget()
{
    if (bIsIgnoreShowDialog || (PicoSettings->bStartTimeEntitlementCheck && PicoSettings->EntitlementCheckAppID != ""))
    {
        return;
    }
    if (MsgWindow == nullptr)
    {
        MsgWindow = SNew(SWindow)
        .Title(FText::FromString("Tips"))
        .SizingRule(ESizingRule::Autosized)
        .AutoCenter(EAutoCenter::PreferredWorkArea)
        .HasCloseButton(false)
        .SupportsMinimize(false)
        .SupportsMaximize(false);
    }  

	const TSharedPtr<SBorder> Content = SNew(SBorder)
              .BorderImage(FEditorStyle::GetBrush("ToolPanel.GroupBorder"))
              [
				SNew(SVerticalBox)				
                + SVerticalBox::Slot()
                .FillHeight(0.8f)  
                .Padding(FMargin(5,12,5,0))
                .AutoHeight()
                [
					SNew(STextBlock)
                    .Text(FText::FromString(" EntitlementCheck is highly recommended in order to \nprotect the copyright of an app. To enable it upon app \nstart-up, go to \"Editor->Project Settings->PicoMobile\n->platform\" and enter your APPID."))
                    .Font(FEditorStyle::GetFontStyle("StandardDialog.LargeFont"))
                    .AutoWrapText(true)
                ]
                
                +SVerticalBox::Slot()
                .FillHeight(0.1f)
                .Padding(FMargin(5,30,5,0))    
                [
                    SNew(SHorizontalBox)
                    + SHorizontalBox::Slot()
                    .FillWidth(0.5f)
                    .HAlign(HAlign_Right)
                    .VAlign(VAlign_Bottom)
                    .Padding(FMargin(0,0,30.f,0))
                    [
                        SNew( SButton )
                        .Text( FText::FromString("OK"))
                        .OnClicked( this, &FPicoSettingsCustomization::OnOKButtonClick)
                        .ContentPadding(FEditorStyle::GetMargin("StandardDialog.ContentPadding"))
                        .HAlign(HAlign_Center)
                    ]
                    + SHorizontalBox::Slot()
                    .FillWidth(0.5f)
                    .HAlign(HAlign_Left)
                    .VAlign(VAlign_Bottom)
                    .Padding(FMargin(30.f,0,0,0))
                    [
                        SNew( SButton )
                        .Text( FText::FromString("Ignore"))
                        .OnClicked( this, &FPicoSettingsCustomization::OnIgnoreButtonClick)
                        .ContentPadding(FEditorStyle::GetMargin("StandardDialog.ContentPadding"))
                        .HAlign(HAlign_Center)
                    ]
                ]
                
                +SVerticalBox::Slot()
                .FillHeight(0.1f)
                .Padding(FMargin(5,0,5,5.f))
                [
					SNew(SHorizontalBox)
                    + SHorizontalBox::Slot()                 
                    .HAlign(HAlign_Left)
                    .VAlign(VAlign_Bottom)
                    .AutoWidth()
                    .Padding(FMargin(5.f,0,0,0))
                    [
                        SNew(SCheckBox)
                        .OnCheckStateChanged(this,&FPicoSettingsCustomization::OnCheckBoxChange)
               
                    ]
                    + SHorizontalBox::Slot()                      
                    .HAlign(HAlign_Left)
                    .VAlign(VAlign_Bottom)
                    .AutoWidth()
                    .Padding(FMargin(5.f,0,0,0))
                    [
						SNew(STextBlock)
                        .Text(FText::FromString("No longer remind"))
                        .Font(FEditorStyle::GetFontStyle("StandardDialog.LargeFont"))
                    ]
                ]
                
              ];
	
	MsgWindow->SetContent(Content.ToSharedRef());
    const TSharedPtr<SWindow> RootWindow = FGlobalTabmanager::Get()->GetRootWindow();
    if (RootWindow.IsValid())
    {
        FSlateApplication::Get().AddWindowAsNativeChild(MsgWindow.ToSharedRef(), RootWindow.ToSharedRef());
    }
    else
    {
        FSlateApplication::Get().AddWindow(MsgWindow.ToSharedRef());
    }  
}

FReply FPicoSettingsCustomization::OnOKButtonClick()
{
    if (bCheckBoxChecked)
    {
        GConfig->SetBool(TEXT("/Script/PicoMobile.PicoMobileSettings"), TEXT("bIsIgnoreShowDialog"), true, GEditorIni);
        GConfig->Flush(false, GEngineIni);
    }
    FModuleManager::LoadModuleChecked<ISettingsModule>("Settings").ShowViewer("Project", "Plugins", "PicoMobile");
    MsgWindow->HideWindow();
    return  FReply::Handled();
}

FReply FPicoSettingsCustomization::OnIgnoreButtonClick()
{
    if (bCheckBoxChecked)
    {
        GConfig->SetBool(TEXT("/Script/PicoMobile.PicoMobileSettings"), TEXT("bIsIgnoreShowDialog"), true, GEditorIni);
        GConfig->Flush(false, GEngineIni);
    }
    UE_LOG(LogTemp,Warning,TEXT("EntitlementCheck is highly recommended which can protect the copyright of app. You can enable it when App start-up in the Inspector of \"Edit->Plugins->PicoMobile->Platform\" and Enter your APPID. If you want to call the APIs as needed, please refer to the development Document."));
    MsgWindow->HideWindow();
    return  FReply::Handled();  
}

void FPicoSettingsCustomization::OnCheckBoxChange(ECheckBoxState NewCheckedState)
{
    bCheckBoxChecked = NewCheckedState == ECheckBoxState::Checked;
}
#endif




