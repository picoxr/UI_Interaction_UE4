// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

#include "OnlinePicoSettingsCustomization.h"

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

#define LOCTEXT_NAMESPACE "OnlinePicoRuntimeSettings"

TSharedPtr<SWindow> FOnlinePicoSettingsCustomization::MsgWindow = nullptr;
class UEditorStyleSettings;
class SPicoDeprecationBanner : public SCompoundWidget
{
    SLATE_BEGIN_ARGS(SPicoDeprecationBanner)
    {
    }

    SLATE_END_ARGS()

        void Construct(const FArguments& InArgs)
    {
        ChildSlot
            [
                SNew(SBorder)
                .BorderBackgroundColor(this, &SPicoDeprecationBanner::GetBorderColor)
#if ENGINE_MAJOR_VERSION > 4 && ENGINE_MINOR_VERSION > 0
            .BorderImage(FAppStyle::GetBrush("ToolPanel.LightGroupBorder"))
#else
            .BorderImage(FEditorStyle::GetBrush("ToolPanel.LightGroupBorder"))
#endif
            .Padding(2.0f)
            [
                SNew(SHorizontalBox)
                + SHorizontalBox::Slot()
            .AutoWidth()
            .VAlign(VAlign_Center)
            [
                SNew(SImage)
#if ENGINE_MAJOR_VERSION > 4 && ENGINE_MINOR_VERSION > 0
                .Image(FAppStyle::GetBrush("SettingsEditor.WarningIcon"))
#else
                .Image(FEditorStyle::GetBrush("SettingsEditor.WarningIcon"))
#endif
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
                .ButtonColorAndOpacity(FLinearColor(0, 0, 0, 0))
            .OnClicked(this, &SPicoDeprecationBanner::ChangePrimitive)
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

FOnlinePicoSettingsCustomization::FOnlinePicoSettingsCustomization()
    :SavedLayoutBuilder(nullptr),
    bCheckBoxChecked(false),
    bIsIgnoreShowDialog(true)
{
    if (MsgWindow.IsValid())
    {
        MsgWindow->HideWindow();
        MsgWindow = nullptr;
    }
    OnlinePicoSettings = GetMutableDefault<UOnlinePicoSettings>();
    if (!GConfig->GetBool(TEXT("/Script/OnlineSubsystemPico.OnlinePicoSettings"), TEXT("bIsIgnoreShowDialog"), bIsIgnoreShowDialog, GEditorIni))
    {
        GConfig->SetBool(TEXT("/Script/OnlineSubsystemPico.OnlinePicoSettings"), TEXT("bIsIgnoreShowDialog"), false, GEditorIni);
        bIsIgnoreShowDialog = false;
    }
}

TSharedRef<IDetailCustomization> FOnlinePicoSettingsCustomization::MakeInstance()
{
    return MakeShareable(new FOnlinePicoSettingsCustomization);
}

void FOnlinePicoSettingsCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailLayout)
{
    SavedLayoutBuilder = &DetailLayout;
    IDetailCategoryBuilder& HMDCategory = DetailLayout.EditCategory(TEXT("HMD"));
    IDetailCategoryBuilder& ControllerCategory = DetailLayout.EditCategory(TEXT("Controller"));
    IDetailCategoryBuilder& FeatureCategory = DetailLayout.EditCategory(TEXT("Feature"));
    ShowDialogWidget();
}

void FOnlinePicoSettingsCustomization::ShowDialogWidget()
{
    return;
    if (bIsIgnoreShowDialog)
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
#if ENGINE_MAJOR_VERSION > 4 && ENGINE_MINOR_VERSION > 0
        .BorderImage(FAppStyle::GetBrush("ToolPanel.GroupBorder"))
#else
        .BorderImage(FEditorStyle::GetBrush("ToolPanel.GroupBorder"))
#endif
        [
            SNew(SVerticalBox)
            + SVerticalBox::Slot()
        .FillHeight(0.8f)
        .Padding(FMargin(5, 12, 5, 0))
        .AutoHeight()
        [
            SNew(STextBlock)
            .Text(FText::FromString("     EntitlementCheck is highly recommended in order \nto protect the copyright of an app. To enable it upon \napp start-up, go to \"Edit->Project Settings->\nOnlinePico Settings->Platform\" and enter your APPID."))
#if ENGINE_MAJOR_VERSION > 4 && ENGINE_MINOR_VERSION > 0
        .Font(FAppStyle::GetFontStyle("StandardDialog.LargeFont"))
#else
        .Font(FEditorStyle::GetFontStyle("StandardDialog.LargeFont"))
#endif
        .AutoWrapText(true)
        ]

    + SVerticalBox::Slot()
        .FillHeight(0.1f)
        .Padding(FMargin(5, 30, 5, 0))
        [
            SNew(SHorizontalBox)
            + SHorizontalBox::Slot()
        .FillWidth(0.5f)
        .HAlign(HAlign_Right)
        .VAlign(VAlign_Bottom)
        .Padding(FMargin(0, 0, 30.f, 0))
        [
            SNew(SButton)
            .Text(FText::FromString("OK"))
        .OnClicked(this, &FOnlinePicoSettingsCustomization::OnOKButtonClick)
#if ENGINE_MAJOR_VERSION > 4 && ENGINE_MINOR_VERSION > 0
        .ContentPadding(FAppStyle::GetMargin("StandardDialog.ContentPadding"))
#else
        .ContentPadding(FEditorStyle::GetMargin("StandardDialog.ContentPadding"))
#endif
        .HAlign(HAlign_Center)
        ]
    + SHorizontalBox::Slot()
        .FillWidth(0.5f)
        .HAlign(HAlign_Left)
        .VAlign(VAlign_Bottom)
        .Padding(FMargin(30.f, 0, 0, 0))
        [
            SNew(SButton)
            .Text(FText::FromString("Ignore"))
        .OnClicked(this, &FOnlinePicoSettingsCustomization::OnIgnoreButtonClick)
#if ENGINE_MAJOR_VERSION > 4 && ENGINE_MINOR_VERSION > 0
        .ContentPadding(FAppStyle::GetMargin("StandardDialog.ContentPadding"))
#else
        .ContentPadding(FEditorStyle::GetMargin("StandardDialog.ContentPadding"))
#endif
        .HAlign(HAlign_Center)
        ]
        ]

    + SVerticalBox::Slot()
        .FillHeight(0.1f)
        .Padding(FMargin(5, 0, 5, 5.f))
        [
            SNew(SHorizontalBox)
            + SHorizontalBox::Slot()
        .HAlign(HAlign_Left)
        .VAlign(VAlign_Bottom)
        .AutoWidth()
        .Padding(FMargin(5.f, 0, 0, 0))
        [
            SNew(SCheckBox)
            .OnCheckStateChanged(this, &FOnlinePicoSettingsCustomization::OnCheckBoxChange)

        ]
    + SHorizontalBox::Slot()
        .HAlign(HAlign_Left)
        .VAlign(VAlign_Bottom)
        .AutoWidth()
        .Padding(FMargin(5.f, 0, 0, 0))
        [
            SNew(STextBlock)
            .Text(FText::FromString("No longer remind"))
#if ENGINE_MAJOR_VERSION > 4 && ENGINE_MINOR_VERSION > 0
        .Font(FAppStyle::GetFontStyle("StandardDialog.LargeFont"))
#else
        .Font(FEditorStyle::GetFontStyle("StandardDialog.LargeFont"))
#endif
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

FReply FOnlinePicoSettingsCustomization::OnOKButtonClick()
{
    if (bCheckBoxChecked)
    {
        GConfig->SetBool(TEXT("/Script/OnlineSubsystemPico.OnlinePicoSettings"), TEXT("bIsIgnoreShowDialog"), true, GEditorIni);
        GConfig->Flush(false, GEngineIni);
    }
    FModuleManager::LoadModuleChecked<ISettingsModule>("Settings").ShowViewer("Project", "Plugins", "OnlinePicoSetting");
    MsgWindow->HideWindow();
    return  FReply::Handled();
}

FReply FOnlinePicoSettingsCustomization::OnIgnoreButtonClick()
{
    if (bCheckBoxChecked)
    {
        GConfig->SetBool(TEXT("/Script/OnlineSubsystemPico.OnlinePicoSettings"), TEXT("bIsIgnoreShowDialog"), true, GEditorIni);
        GConfig->Flush(false, GEngineIni);
    }
    MsgWindow->HideWindow();
    return  FReply::Handled();
}

void FOnlinePicoSettingsCustomization::OnCheckBoxChange(ECheckBoxState NewCheckedState)
{
    bCheckBoxChecked = NewCheckedState == ECheckBoxState::Checked;
}

#endif
#undef LOCTEXT_NAMESPACE 