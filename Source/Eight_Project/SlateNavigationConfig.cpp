// Fill out your copyright notice in the Description page of Project Settings.


#include "SlateNavigationConfig.h"

void USlateNavigationConfig::SetWidgetNavigation(bool enabled) {
	auto& SlateApplication = FSlateApplication::Get();
	auto& NavigationConfig = *SlateApplication.GetNavigationConfig();

	NavigationConfig.bAnalogNavigation = enabled;
	NavigationConfig.bKeyNavigation = enabled;
	NavigationConfig.bTabNavigation = enabled;
}