// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BulletMLEvents.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Bullet.generated.h"

UCLASS()
class EIGHT_PROJECT_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

	// BulletML
	BulletMLParser* bulletMLParser = nullptr;
	BulletMLEvents* bulletMLEvents = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
