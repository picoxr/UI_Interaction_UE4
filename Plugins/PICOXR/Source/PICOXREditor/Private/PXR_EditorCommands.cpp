// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

#include "PXR_EditorCommands.h"

#define LOCTEXT_NAMESPACE "FPICOXREditorModule"
/* UI_COMMAND takes long for the compile to optimize */

void FPICOXREditorCommands::RegisterCommands()
{
 	UI_COMMAND(PluginAction, "PICOXREditor", "Execute PICOXREditor action", EUserInterfaceActionType::Button, FInputChord());
 	UI_COMMAND(LaunchAPIReferenceURL, "Launch PICOXR API Reference", "Launch PICOXR API Reference", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(LaunchSampleDemoURL, "Launch PICOXR Sample", "Launch Sample", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(LaunchOfficialWebsiteURL, "Download SDK From Official", "Launch Official SDK", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(LaunchMarketplaceURL, "Download SDK From Marketplace", "Launch Marketplace SDK", EUserInterfaceActionType::Button, FInputChord());
 	UI_COMMAND(AddSampleInputs, "Add Sample Inputs", "Add Sample Inputs", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(ClearSampleInputs, "Clear Sample Inputs", "Clear Sample Inputs", EUserInterfaceActionType::Button, FInputChord());

}


#undef LOCTEXT_NAMESPACE
