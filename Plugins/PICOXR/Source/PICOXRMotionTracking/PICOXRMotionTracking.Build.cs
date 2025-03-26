// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

namespace UnrealBuildTool.Rules
{
	public class PICOXRMotionTracking : ModuleRules
	{
		public PICOXRMotionTracking(ReadOnlyTargetRules Target) : base(Target)
		{
			PublicDependencyModuleNames.AddRange(new string[] { "PXRPlugin" });
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
					"ApplicationCore",
					"Engine",
					"InputCore",
					"HeadMountedDisplay",                
					"PXRPlugin",
                    "PICOXRHMD", "PICOXRInput"
                });

			PrivateIncludePaths.AddRange(
				new string[] {
					"PICOXRHMD/Private",
				});
		}
	}
}
