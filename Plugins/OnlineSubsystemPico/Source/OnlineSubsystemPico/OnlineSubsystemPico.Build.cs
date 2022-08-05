// Copyright 2022 Pico Technology Co., Ltd.All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc.In the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc.All rights reserved.

using UnrealBuildTool;
using System.IO;
public class OnlineSubsystemPico : ModuleRules
{
	public OnlineSubsystemPico(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivateDefinitions.Add("ONLINESUBSYSTEMPICO_PACKAGE=1");
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		string OnlineSubsystemPublic = Path.GetFullPath(Path.Combine(Target.RelativeEnginePath, "Plugins/Online/OnlineSubsystem/Source/Public/"));
		PublicIncludePaths.Add(Path.Combine(PluginDirectory, "Source/OnlineSubsystemPico/include"));
		PrivateIncludePaths.Add("OnlineSubsystemPico/Private");
        PrivateIncludePaths.AddRange(
			 new string[] {
                OnlineSubsystemPublic
			 }
		);
        if (Target.Platform == UnrealTargetPlatform.Android)
        {
            PublicAdditionalLibraries.Add(Path.Combine(PluginDirectory, "Source/OnlineSubsystemPico/lib/armeabi-v7a/libpxrplatformloader.so"));
            PublicAdditionalLibraries.Add(Path.Combine(PluginDirectory, "Source/OnlineSubsystemPico/lib/arm64-v8a/libpxrplatformloader.so"));
			PrivateDependencyModuleNames.AddRange(new string[] { "Launch" });
			string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "OnlineSubsystemPico_APL.xml"));
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
