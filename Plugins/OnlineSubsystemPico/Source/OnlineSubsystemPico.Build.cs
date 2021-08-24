// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class OnlineSubsystemPico : ModuleRules
{
	public OnlineSubsystemPico(ReadOnlyTargetRules Target) : base(Target)
    {		
		PublicDefinitions.Add("ONLINESUBSYSTEMPICO_PACKAGE=1");
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		string OnlineSubsystemPublic = Path.GetFullPath(Path.Combine(Target.RelativeEnginePath, "Plugins/Online/OnlineSubsystem/Source/Public/"));

		PrivateIncludePaths.Add("Private");
		PrivateIncludePaths.AddRange(
			new string[] {
				OnlineSubsystemPublic
			}
		);

		PublicDependencyModuleNames.AddRange(
			new string[] {
				"OnlineSubsystemUtils"
			}
			);
		PrivateDependencyModuleNames.AddRange(
			new string[] {
				"Core",
				"CoreUObject",
				"Engine",
				"Sockets",
				"OnlineSubsystem",
				"Projects",
				"PacketHandler",
				"Voice",
			}
			);

			PublicIncludePathModuleNames.Add("Launch");
		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			PrivateDependencyModuleNames.AddRange(new string[] {"Launch"});
			string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "OnlineSubsystemPico_APL.xml"));
		}
    }
}
