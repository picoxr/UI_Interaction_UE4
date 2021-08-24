// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

using System.IO;

namespace UnrealBuildTool.Rules
{
	public class PicoMobileController : ModuleRules
	{
		public PicoMobileController(ReadOnlyTargetRules Target): base(Target)
		{
            PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

            var EngineDir = Path.GetFullPath(Target.RelativeEnginePath);
            var rendererPrivatePath = Path.Combine(EngineDir, @"Source\Runtime\Renderer\Private");
            var corePrivatePath = Path.Combine(EngineDir, @"Source\Runtime\Core\Private");
            var launchPrivatePath = Path.Combine(EngineDir, @"Source\Runtime\Launch\Private");
            var openGLDrvPrivatePath = Path.Combine(EngineDir, @"Source\Runtime\OpenGLDrv\Private");
            PrivateIncludePaths.AddRange(
                new string[] {
                "PicoMobileController/Private",
                rendererPrivatePath,
                corePrivatePath,
                launchPrivatePath,
                openGLDrvPrivatePath
                    // ... add other private include paths required here ...
                }
                );


            PublicDependencyModuleNames.AddRange(
                new string[]
                {
                "Core",
                    // ... add other public dependencies that you statically link with here ...
                }
                );


            PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                "Core",
                "CoreUObject",
                "Engine",
                "InputCore",
                "InputDevice",
                "HeadMountedDisplay",
                "PicoMobile"
                // ... add private dependencies that you statically link with here ...	
                }
                );


            if (Target.Platform == UnrealTargetPlatform.Android)
            {
                PrivateDependencyModuleNames.Add("Launch");
            }

            if (Target.bBuildEditor == true)
            {
                PrivateDependencyModuleNames.Add("UnrealEd");
            }

            if (Target.Platform == UnrealTargetPlatform.Android)
            {
                string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
                AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "PicoMobileController_APL.xml"));
            }
        }
	}
}
