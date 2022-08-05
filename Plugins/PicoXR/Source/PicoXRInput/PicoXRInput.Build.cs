//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

using UnrealBuildTool;
using System.IO;

public class PicoXRInput : ModuleRules
{
	public PicoXRInput(ReadOnlyTargetRules Target) : base(Target)
	{
        System.Console.WriteLine(" Build the PicoXRInput Plugin");
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        string PicoXRLibsDirectory = Path.Combine(ModuleDirectory, @"..\..\Libs");
        string PicoXRHeaderDirectory = Path.Combine(PicoXRLibsDirectory, @"Include");
        PicoXRHeaderDirectory = Path.GetFullPath(PicoXRHeaderDirectory);

        PrivateIncludePathModuleNames.AddRange(
                new []
                {
                    "InputDevice",			// For IInputDevice.h
					"HeadMountedDisplay",	// For IMotionController.h
					"ImageWrapper",
                });

        PrivateDependencyModuleNames.AddRange(
            new []
            {
                    "Core",
                    "CoreUObject",
                    "ApplicationCore",
                    "Engine",
                    "InputCore",
                    "HeadMountedDisplay",
                    "PicoXRHMD"
            });
        PrivateIncludePaths.AddRange(
                new [] {
					"PicoXRInput/Private",
                    "PicoXRHMD/Private",
                    PicoXRHeaderDirectory,
                });

    }
}
