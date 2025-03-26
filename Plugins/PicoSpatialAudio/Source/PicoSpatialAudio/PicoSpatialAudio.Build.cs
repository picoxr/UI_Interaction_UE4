//  Copyright © 2015-2023 Pico Technology Co., Ltd. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class PicoSpatialAudio : ModuleRules
{
	public PicoSpatialAudio(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(
			new string[]
			{
				// ... add public include paths required here ...
			}
		);


		PrivateIncludePaths.AddRange(
			new string[]
			{
				Path.Combine(ModuleDirectory, "include")
			}
		);
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"AudioMixer",
				"SignalProcessing",
				"SoundFieldRendering",
				"ProceduralMeshComponent",
				"AndroidPermission",
				"PASP_PXRPlugin"
			}
		);

		PrivateIncludePathModuleNames.AddRange(
			new string[]
			{
				"TargetPlatform",
				"PASP_PXRPlugin"
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				"Projects",
				"AudioMixer",
				"AudioExtensions",
				"ProceduralMeshComponent",
				"PASP_PXRPlugin"
			}
		);

		if (Target.bBuildEditor == true)
		{
			PrivateDependencyModuleNames.Add("UnrealEd");
		}

		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
		);
		
		PrivateDependencyModuleNames.Add("ProceduralMeshComponent");
		PrivateDependencyModuleNames.Add("PASP_PXRPlugin");

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			// Automatically copy DLL to packaged builds
			var dllPath = Path.Combine(ModuleDirectory, "libs/windows/dll", "PicoSpatializerNative.dll");
			var libPath = Path.Combine(ModuleDirectory, "libs/windows/dll", "PicoSpatializerNative.lib");
			RuntimeDependencies.Add(dllPath);
			
			PublicDelayLoadDLLs.Add("PicoSpatializerNative.dll");
			PublicAdditionalLibraries.Add(libPath);
		}
		else if (Target.Platform == UnrealTargetPlatform.Mac)
		{
			var dllPath = Path.Combine(ModuleDirectory, "libs/mac", "libPicoSpatializerNative.dylib");
			PublicAdditionalLibraries.Add(dllPath);
		}
		else if (Target.Platform == UnrealTargetPlatform.Android)
		{
			string BuildPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(BuildPath, "PicoSpatialAudio_APL.xml"));

			PublicAdditionalLibraries.Add(ModuleDirectory + "/libs/android/armeabi-v7a/libPicoSpatializerNative.so");
			PublicAdditionalLibraries.Add(ModuleDirectory + "/libs/android/arm64-v8a/libPicoSpatializerNative.so");
		}
	}
}