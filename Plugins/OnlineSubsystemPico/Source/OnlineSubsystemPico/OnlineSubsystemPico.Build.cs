// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved. 

using UnrealBuildTool;
using System.IO;
public class OnlineSubsystemPico : ModuleRules
{
    public OnlineSubsystemPico(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivateDefinitions.Add("ONLINESUBSYSTEMPICO_PACKAGE=1");
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        string OnlineSubsystemPublic = Path.GetFullPath(Path.Combine(Target.RelativeEnginePath, "Plugins/Online/OnlineSubsystem/Source/Public/"));
        PublicIncludePaths.Add(Path.Combine(PluginDirectory, "Source/ThirdParty/include"));
        PrivateIncludePaths.Add("OnlineSubsystemPico/Private");
        PrivateIncludePaths.AddRange(
             new string[] {
                OnlineSubsystemPublic
             }
        );
        if (Target.Platform == UnrealTargetPlatform.Android)
        {
            PrivateDependencyModuleNames.AddRange(new string[] { "Launch" });
            PublicAdditionalLibraries.Add(Path.Combine(PluginDirectory, "Source/ThirdParty/lib/arm64-v8a/libpxrplatformloader.so"));
            string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
            AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "OnlineSubsystemPico_APL.xml"));
        }
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            PublicAdditionalLibraries.Add(Path.Combine(PluginDirectory, "Source/ThirdParty/lib/Windows/platformsdk.lib"));
            // Ensure that the DLL is staged along with the executable

            PublicDelayLoadDLLs.Add("platformsdk.dll");
            PublicDelayLoadDLLs.Add("openh264-4.dll");
            PublicDelayLoadDLLs.Add("RTCFFmpeg.dll");
            PublicDelayLoadDLLs.Add("VolcEngineRTC.dll");
            PublicDelayLoadDLLs.Add("pthreadVC2.dll");

            RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/PPFLibrary/Win64/platformsdk.dll");
            RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/PPFLibrary/Win64/openh264-4.dll");
            RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/PPFLibrary/Win64/RTCFFmpeg.dll");
            RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/PPFLibrary/Win64/VolcEngineRTC.dll");
            RuntimeDependencies.Add("$(PluginDir)/Binaries/ThirdParty/PPFLibrary/Win64/pthreadVC2.dll");

            //string DllDirectory = Path.Combine(PluginDirectory, "Source/ThirdParty/lib/Windows/");
            //RuntimeDependencies.Add("$(BinaryOutputDir)/openh264-4.dll", Path.Combine(DllDirectory, "openh264-4.dll"));
            //RuntimeDependencies.Add("$(BinaryOutputDir)/platformsdk.dll", Path.Combine(DllDirectory, "platformsdk.dll"));
            //RuntimeDependencies.Add("$(BinaryOutputDir)/RTCFFmpeg.dll", Path.Combine(DllDirectory, "RTCFFmpeg.dll"));
            //RuntimeDependencies.Add("$(BinaryOutputDir)/VolcEngineRTC.dll", Path.Combine(DllDirectory, "VolcEngineRTC.dll"));
            //RuntimeDependencies.Add("$(BinaryOutputDir)/pthreadVC2.dll", Path.Combine(DllDirectory, "pthreadVC2.dll"));
        }

        PublicIncludePaths.AddRange(
            new string[] {
				// ... add public include paths required here ...
			}
            );


        PublicIncludePathModuleNames.Add("Launch");
        if (Target.Type == TargetRules.TargetType.Editor)
        {
            PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                        "UnrealEd",
                        "Slate",
                        "SlateCore",
                        "EditorStyle",
                        "EditorWidgets",
                        "DesktopWidgets",
                        "PropertyEditor",
                        "SharedSettingsWidgets",
                        "SequencerWidgets"
                }
            );
        }

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "OnlineSubsystemUtils",
                "Projects",
                "NetCore",
                "CoreUObject",
                "Engine",
                "Sockets",
                "OnlineSubsystem",
                "Projects",
                "Json",
                "JsonUtilities",
                "PacketHandler",
                "Voice",
				// ... add other public dependencies that you statically link with here ...
			}
            );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
				// ... add private dependencies that you statically link with here ...	
			}
            );


        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
				// ... add any modules that your module loads dynamically here ...
			}
            );
    }
}
