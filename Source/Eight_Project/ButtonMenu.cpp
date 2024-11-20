// Fill out your copyright notice in the Description page of Project Settings.


#include "ButtonMenu.h"

UButtonMenu::UButtonMenu(FText NewText) {
	Text = NewText;
}

UButtonMenu::UButtonMenu() {
	UButtonMenu(FText::FromString("Button"));
}

void UButtonMenu::NativeConstruct() {
	// Super::NativeConstruct();

	TextBlock = CreateWidget<UTextBlock>(GetWorld());
}

// int UButtonMenu::Tick(float DeltaTime) {

//}