//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.
using UnrealBuildTool;
using System.IO;

namespace UnrealBuildTool.Rules
{
	public class PICOXRDPHMD : ModuleRules
	{
		public PICOXRDPHMD(ReadOnlyTargetRules Target) : base(Target)
		{
			string EnginePath = Path.GetFullPath(Target.RelativeEnginePath);
			PrivateIncludePaths.AddRange(
				new string[] {
					"PICOXRDP/PICOXRDPHMD/Private",
					"PICOXRDP/PICOXRDPHMD/Public",
					"PICOXRHMD/Private",
					EnginePath+"Source/Runtime/Renderer/Private",
					// ... add other private include paths required here ...
				}
				);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
					"Engine",
					"RHI",
					"RenderCore",
					"Renderer",
                    "InputCore",
					"InputDevice",
					"HeadMountedDisplay",
					"PICOXRHMD",
					"Slate",
					"SlateCore",
					"ProceduralMeshComponent",
				}
				);
            
            if (Target.bBuildEditor == true)
            {
                PrivateDependencyModuleNames.Add("UnrealEd");
            }

			if (Target.Platform == UnrealTargetPlatform.Win64 || Target.IsInPlatformGroup(UnrealPlatformGroup.Linux))
			{
				AddEngineThirdPartyPrivateStaticDependencies(Target, "NVAftermath");
			}

			if (Target.Platform == UnrealTargetPlatform.Win32 || Target.Platform == UnrealTargetPlatform.Win64)
            {
				PrivateDependencyModuleNames.AddRange(
					new string[]
					{
							"D3D11RHI",
							"D3D12RHI",
					});

				PrivateIncludePaths.AddRange(
					new string[]
					{
							EnginePath+"Source/Runtime/Windows/D3D11RHI/Private",
							EnginePath+"Source/Runtime/Windows/D3D11RHI/Private/Windows",
							EnginePath+"Source/Runtime/D3D12RHI/Private",
							EnginePath+"Source/Runtime/D3D12RHI/Private/Windows",
					});

				AddEngineThirdPartyPrivateStaticDependencies(Target, "DX11");
				AddEngineThirdPartyPrivateStaticDependencies(Target, "DX12");
				AddEngineThirdPartyPrivateStaticDependencies(Target, "OpenVR");
                AddEngineThirdPartyPrivateStaticDependencies(Target, "NVAftermath");
                AddEngineThirdPartyPrivateStaticDependencies(Target, "IntelMetricsDiscovery");


				BuildVersion Version;
				if (!BuildVersion.TryRead(BuildVersion.GetDefaultFileName(), out Version))
				{
					Version = new BuildVersion();
				}
				if (Version.MinorVersion > 24)
				{
					AddEngineThirdPartyPrivateStaticDependencies(Target, "IntelExtensionsFramework");
				}

                string PICOXRLibsDirectory = Path.Combine(ModuleDirectory, "../../../Libs");

				PublicIncludePaths.Add(Path.Combine(PICOXRLibsDirectory, "Include"));

				PublicAdditionalLibraries.Add(Path.Combine(PICOXRLibsDirectory, "Win64", "pxr_turtledove.lib"));
				PublicDelayLoadDLLs.Add("pxr_turtledove.dll");
				RuntimeDependencies.Add(Path.Combine(PICOXRLibsDirectory, "Win64", "pxr_turtledove.dll"));
			}
		}
	}
}
