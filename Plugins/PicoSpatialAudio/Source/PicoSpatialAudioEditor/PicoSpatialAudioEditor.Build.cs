namespace UnrealBuildTool.Rules
{
	public class PicoSpatialAudioEditor : ModuleRules
	{
		public PicoSpatialAudioEditor(ReadOnlyTargetRules Target) : base(Target)
		{
			PrivateIncludePaths.AddRange(
				new string[]
				{
					"PicoSpatialAudio/Private",
					"PicoSpatialAudio/include"
				}
			);

			PublicIncludePaths.AddRange(
				new string[]
				{
				}
			);


			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
					"Engine",
					"InputCore",
					"UnrealEd",
					"LevelEditor",
					"EditorStyle",
					"RenderCore",
					"RHI",
					"AudioEditor",
					"AudioMixer",
					"PicoSpatialAudio"
				}
			);

			PrivateIncludePathModuleNames.AddRange(
				new string[]
				{
					"AssetTools",
					"Landscape"
				});

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"Slate",
					"SlateCore",
					"UnrealEd",
					"AudioEditor",
					"LevelEditor",
					"Landscape",
					"Core",
					"CoreUObject",
					"Engine",
					"InputCore",
					"PropertyEditor",
					"Projects",
					"EditorStyle",
					"PicoSpatialAudio",
					"Eigen"
				}
			);
		}
	}
}