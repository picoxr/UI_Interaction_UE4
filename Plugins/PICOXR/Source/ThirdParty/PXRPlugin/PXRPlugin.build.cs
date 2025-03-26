// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved.

using UnrealBuildTool;
using System.IO;

public class PXRPlugin : ModuleRules
{
	public PXRPlugin(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "PXRPlugin/Include"));

        if (Target.Platform == UnrealTargetPlatform.Android)
        {
            RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "PXRPlugin/Lib/armeabi-v7a/libpxr_api.so"));
			RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "PXRPlugin/Lib/arm64-v8a/libpxr_api.so"));
		}
	}
}
