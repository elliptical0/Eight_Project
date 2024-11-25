// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/Application/NavigationConfig.h"
#include "NavigationConfigKeybind.h"

#include "SlateNavigationConfig.generated.h"

/**
 * 
 */
UCLASS()
class EIGHT_PROJECT_API USlateNavigationConfig : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Slate")
	static void SetNavigationConfigToNavigationConfigKeybind();

	UFUNCTION(BlueprintCallable, Category = "Slate")
	static void SetWidgetNavigation(bool enabled);
};
