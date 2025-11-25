// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BulletMLEvents.h"
#include "bulletmlerror.h"
#include "bulletmlparser-tinyxml.h"
#include "CoreMinimal.h"
#include "Misc/MessageDialog.h"
#include "Misc/Paths.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "BulletSubsystem.generated.h"


// extern const TMap<FName, std::string> bulletMLFiles;

/**
 * 
 */
UCLASS()
class EIGHT_PROJECT_API UBulletSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UBulletSubsystem();
	~UBulletSubsystem();

	TMap<FName, BulletMLParserTinyXML*> bulletParsers;
};
