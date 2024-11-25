// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Framework/Application/NavigationConfig.h"
#include "GameFramework/PlayerInput.h"
#include "GameFramework/InputSettings.h"

/**
 * 
 */

class EIGHT_PROJECT_API FNavigationConfigKeybind : public FNavigationConfig
{
	// GENERATED_BODY()

public:
	FNavigationConfigKeybind();
	~FNavigationConfigKeybind();

	TMap<FKey, EUINavigationAction> KeyActionRules;

	virtual EUINavigationAction GetNavigationActionFromKey(const FKeyEvent& InKeyEvent) const override;

};
