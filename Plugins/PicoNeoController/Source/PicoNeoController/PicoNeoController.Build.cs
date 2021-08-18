// Copyright © 2015-2020 Pico Technology Co., Ltd. All Rights Reserved.

using System.IO;

namespace UnrealBuildTool.Rules
{
    public class PicoNeoController : ModuleRules
    {
        public PicoNeoController(ReadOnlyTargetRules Target): base(Target)
        {
			PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
			
            string ue4_include_path1 = Path.GetFullPath(Path.Combine(Target.RelativeEnginePath, "Source/Runtime/Core/Private"));
            string ue4_include_path2 = Path.GetFullPath(Path.Combine(Target.RelativeEnginePath, "Source/Runtime/Launch/Private"));
            PrivateIncludePaths.AddRange(
                new string[] {
                    "PicoNeoController/Private",
                    ue4_include_path1,
                    ue4_include_path2,
					// ... add other private include paths required here ...
				}
                );
       
            PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                    "Core",
                    "CoreUObject",
                    "ApplicationCore",
                    "Engine",
                    "InputCore",
                    "InputDevice",
                    "HeadMountedDisplay",
                    "PicoMobile"
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
                AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "PicoNeoController_APL.xml"));
            }
        }
    }
}
