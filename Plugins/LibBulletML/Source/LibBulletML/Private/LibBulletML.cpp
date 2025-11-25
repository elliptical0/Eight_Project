// Copyright Epic Games, Inc. All Rights Reserved.

#include "LibBulletML.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FLibBulletMLModule"

void FLibBulletMLModule::StartupModule()
{
	// // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// // Get the base directory of this plugin
	// FString BaseDir = IPluginManager::Get().FindPlugin("LibBulletMLPlugin")->GetBaseDir();
	// // Add on the relative location of the third party dll and load it
	// FString LibraryPath;
	// LibraryPath = FPaths::Combine(*BaseDir, TEXT("bin/Release/bulletml-shared.dll"));

	// LibBulletML = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;

	// if (LibBulletML)
	// {
	// 	// BulletMLParser bulletMLParser;
	// }
	// else
	// {
	// 	FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibraryError", "Failed to load LibBulletML"));
	// }
}

void FLibBulletMLModule::ShutdownModule()
{
	// // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// // we call this function before unloading the module.

	// // Free the dll handle
	// FPlatformProcess::FreeDllHandle(LibBulletML);
	// LibBulletML = nullptr;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FLibBulletMLModule, LibBulletML)
