// Fill out your copyright notice in the Description page of Project Settings.


#include "NavigationConfigKeybind.h"

FNavigationConfigKeybind::FNavigationConfigKeybind() {
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("FNavigationConfigKeybind created!"));

	UInputSettings* InputSettings = UInputSettings::GetInputSettings();

	TArray<FInputActionKeyMapping> ConfirmMappings, CancelMappings;
	InputSettings->GetActionMappingByName(FName("Confirm"), ConfirmMappings);
	// InputSettings->GetActionMappingByName(FName("Cancel"), CancelMappings);

	TArray<FInputAxisKeyMapping> MenuXMappings, MenuYMappings;
	InputSettings->GetAxisMappingByName(FName("MenuX"), MenuXMappings);
	InputSettings->GetAxisMappingByName(FName("MenuY"), MenuYMappings);

	KeyActionRules.Reset();
	KeyEventRules.Reset();

	for (FInputActionKeyMapping mapping : ConfirmMappings) {
		KeyActionRules.Emplace(mapping.Key, EUINavigationAction::Accept);
	}
	for (FInputActionKeyMapping mapping : CancelMappings) {
		KeyActionRules.Emplace(mapping.Key, EUINavigationAction::Back);
	}
	for (FInputAxisKeyMapping mapping : MenuXMappings) {
		KeyEventRules.Emplace(mapping.Key, (mapping.Scale > 0 ? EUINavigation::Right : EUINavigation::Left));
	}
	for (FInputAxisKeyMapping mapping : MenuYMappings) {
		KeyEventRules.Emplace(mapping.Key, (mapping.Scale > 0 ? EUINavigation::Down : EUINavigation::Up));
	}
}

FNavigationConfigKeybind::~FNavigationConfigKeybind() {

}

EUINavigationAction FNavigationConfigKeybind::GetNavigationActionFromKey(const FKeyEvent& InKeyEvent) const {
	const EUINavigationAction* Rule = KeyActionRules.Find(InKeyEvent.GetKey());
	if (Rule) {
		if (bKeyNavigation) {
			return *Rule;
		}
	}

	return EUINavigationAction::Invalid;
}