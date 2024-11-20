// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Internationalization/Text.h"

#include "ButtonMenu.generated.h"

/**
 * 
 */
UCLASS()
class EIGHT_PROJECT_API UButtonMenu : public UButton
{
	GENERATED_BODY()

	UButtonMenu(FText NewText);
	UButtonMenu();

protected:
	virtual void NativeConstruct();
	
public:
	UTextBlock* TextBlock;

	FText Text;
	
	//virtual int Tick(float DeltaTime) override;

};
