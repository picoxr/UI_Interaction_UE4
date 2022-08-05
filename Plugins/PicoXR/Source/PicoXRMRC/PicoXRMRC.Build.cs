
using UnrealBuildTool;
using System.IO;

public class PicoXRMRC : ModuleRules
{
	public PicoXRMRC(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        string PicoXRLibsDirectory = Path.Combine(ModuleDirectory, @"..\..\Libs");
        string PicoXRHeaderDirectory = Path.Combine(PicoXRLibsDirectory, @"Include");
        PicoXRHeaderDirectory = Path.GetFullPath(PicoXRHeaderDirectory);
        PrivateIncludePathModuleNames.AddRange(
                new string[]
                {
                    "InputDevice",			// For IInputDevice.h
					"HeadMountedDisplay",	// For IMotionController.h
					"ImageWrapper",
                    "Engine"
                });

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                    "Core",
                    "CoreUObject",
                    "Engine",
                    "InputCore",
                    "Slate",
                    "SlateCore",
                    "RHI",
                    "VulkanRHI",
                    "RenderCore",
                    "MediaAssets",
                    "HeadMountedDisplay",
                    "PicoXRHMD",
                    "PicoXRInput"
            });

        PrivateIncludePaths.AddRange(
            new string[] {
					"PicoXRHMD/Private",
                    "PicoXRInput/Private",
                    PicoXRHeaderDirectory
            });
        if (Target.Platform == UnrealTargetPlatform.Android)
        {
            AddEngineThirdPartyPrivateStaticDependencies(Target, "Vulkan");
        }
    }
}

