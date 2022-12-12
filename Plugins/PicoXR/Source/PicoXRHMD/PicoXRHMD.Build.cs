//Unreal® Engine, Copyright 1998 – 2022, Epic Games, Inc. All rights reserved.

using UnrealBuildTool;
using System.IO;

public class PICOXRHMD : ModuleRules
{
	public PICOXRHMD(ReadOnlyTargetRules Target) : base(Target)
	{
        System.Console.WriteLine(" Build the PICOXRHMD Plugin");
       
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        string EngineDir = Path.GetFullPath(Target.RelativeEnginePath);
        string RendererPrivatePath = Path.Combine(EngineDir, "Source/Runtime/Renderer/Private");
        string OpenGlDrvPrivatePath = Path.Combine(EngineDir, "Source/Runtime/OpenGLDrv/Private");
        string VulkanRhiPrivatePath = Path.Combine(EngineDir, "Source/Runtime/VulkanRHI/Private");
        string VulkanRhiPrivateAndroidPath = Path.Combine(EngineDir, "Source/Runtime/VulkanRHI/Private/Android");
        string PICOXRLibsDirectory = Path.Combine(ModuleDirectory, "../../Libs");
        string PICOXRHeaderDirectory = Path.Combine(PICOXRLibsDirectory, "Include");
        PICOXRHeaderDirectory = Path.GetFullPath(PICOXRHeaderDirectory);

        PrivateIncludePaths.AddRange(
                new [] {
                   "PICOXRHMD/Private",
                   RendererPrivatePath,
                   OpenGlDrvPrivatePath,
                   VulkanRhiPrivatePath,
                   VulkanRhiPrivateAndroidPath,
                   PICOXRHeaderDirectory,
                   "PICOXRInput/Private"
                });

        PublicIncludePathModuleNames.AddRange(
	        new [] {
		        "Launch",
		        "ProceduralMeshComponent",
	        });		
      
		
		PrivateDependencyModuleNames.AddRange(
			new []
			{
                "Core",
                "CoreUObject",
				"Engine",
                "InputCore",
                "RHI",
                "RenderCore",
                "Renderer",
                "OpenGLDrv",
                "OpenGL",
                "InputDevice",
				"VulkanRHI",
				"ProceduralMeshComponent",
				// ... add private dependencies that you statically link with here ...	
			}
			);
        PublicDependencyModuleNames.AddRange(
	        new []
           {
                "HeadMountedDisplay",
                "EyeTracker"
           });
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
        if (Target.Platform == UnrealTargetPlatform.Android)
        {
	        // Vulkan
            AddEngineThirdPartyPrivateStaticDependencies(Target, "Vulkan");
            PublicAdditionalLibraries.Add(Path.Combine(PICOXRLibsDirectory, "armeabi-v7a", "libpxr_api.so"));
            PublicAdditionalLibraries.Add(Path.Combine(PICOXRLibsDirectory, "arm64-v8a", "libpxr_api.so"));
            string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
            AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "PICOXR_UPL.xml"));
           
        }
    }
}
