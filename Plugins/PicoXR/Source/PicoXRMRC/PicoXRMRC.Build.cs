
using UnrealBuildTool;
using System.IO;

public class PICOXRMRC : ModuleRules
{
	public PICOXRMRC(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        string PICOXRLibsDirectory = Path.Combine(ModuleDirectory, @"..\..\Libs");
        string PICOXRHeaderDirectory = Path.Combine(PICOXRLibsDirectory, @"Include");
        PICOXRHeaderDirectory = Path.GetFullPath(PICOXRHeaderDirectory);
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
                    "PICOXRHMD",
                    "PICOXRInput"
            });

        PrivateIncludePaths.AddRange(
            new string[] {
					"PICOXRHMD/Private",
                    "PICOXRInput/Private",
                    PICOXRHeaderDirectory
            });
        if (Target.Platform == UnrealTargetPlatform.Android)
        {
            AddEngineThirdPartyPrivateStaticDependencies(Target, "Vulkan");
        }
    }
}

