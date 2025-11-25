// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System;
using System.IO;


public class LibBulletML : ModuleRules
{
	public LibBulletML(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		// Type = ModuleType.External;

        // Add any macros that need to be set
        // PublicDefinitions.Add("WITH_MYTHIRDPARTYLIBRARY=1");

        // Add any include paths for the plugin
        PublicIncludePaths.AddRange(
			new string[] {
				Path.Combine(PluginDirectory, "include")
			}
			);
		PublicSystemIncludePaths.AddRange(
			new string[] {
				Path.Combine(PluginDirectory, "include")
			}
			);
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);

		string build_type = "Release";
		if (Target.Configuration == UnrealTargetConfiguration.Debug
				&& Target.bDebugBuildsActuallyUseDebugCRT) {
			build_type = "Debug";
        }

		// Add any import libraries or static libraries
		PublicAdditionalLibraries.Add(
				Path.Combine(PluginDirectory, "bin", build_type, "bulletml.lib")
		);
		PublicAdditionalLibraries.Add(
				Path.Combine(PluginDirectory, "bin", build_type, "bulletml-shared.lib")
		);
		// PublicAdditionalLibraries.Add(
		// 		Path.Combine(PluginDirectory, "bin", build_type, "bulletml-shared.dll")
		// );

		RuntimeDependencies.Add(
				Path.Combine(PluginDirectory, "bin", build_type, "bulletml.lib")
		);
		RuntimeDependencies.Add(
				Path.Combine(PluginDirectory, "bin", build_type, "bulletml-shared.lib")
		);
		// RuntimeDependencies.Add(
		// 		Path.Combine(PluginDirectory, "bin", build_type, "bulletml-shared.dll")
		// );
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Projects",
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
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
