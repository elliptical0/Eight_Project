// Fill out your copyright notice in the Description page of Project Settings.


#include "SlateNavigationConfig.h"

void USlateNavigationConfig::SetNavigationConfigToNavigationConfigKeybind() {
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Creating FNavigationConfigKeybind!"));
	FSlateApplication& SlateApplication = FSlateApplication::Get();
	TSharedRef<FNavigationConfigKeybind> NewNavigationConfigKeybind(new FNavigationConfigKeybind());
	SlateApplication.SetNavigationConfig(NewNavigationConfigKeybind);
}

void USlateNavigationConfig::SetWidgetNavigation(bool enabled) {
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("SetWidgetNavigation!"));
	FSlateApplication& SlateApplication = FSlateApplication::Get();
	TSharedRef<FNavigationConfig> NavigationConfig = SlateApplication.GetNavigationConfig();

	TSharedPtr<FNavigationConfigKeybind> NavigationConfigKeybind = StaticCastSharedRef<FNavigationConfigKeybind>(NavigationConfig);
	if (!NavigationConfigKeybind.IsValid()) {
		SetNavigationConfigToNavigationConfigKeybind();
	}

	NavigationConfigKeybind->bAnalogNavigation = enabled;
	NavigationConfigKeybind->bKeyNavigation = enabled;
	NavigationConfigKeybind->bTabNavigation = false; // always disabled :>
}
