// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NetCompression.generated.h"

/**
 * 
 */
UCLASS()
class EIGHT_PROJECT_API UNetCompression : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure, Category = "Compression")
	static FVector_NetQuantize NetQuantize(FVector input);

	UFUNCTION(BlueprintPure, Category = "Compression")
	static FVector_NetQuantizeNormal NetQuantizeNormal(FVector input);
};