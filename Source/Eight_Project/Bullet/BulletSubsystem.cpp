// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletSubsystem.h"
#include <string>

#define LOCTEXT_NAMESPACE "BulletSubsystem"


const FString BulletMLPath = "BulletML";

const TMap<FName, std::string> bulletMLFiles = {
    {FName(TEXT("Test")), "Test.xml"},
};

UBulletSubsystem::UBulletSubsystem() {
    FString contentDir = FPaths::ProjectContentDir();

    for(auto& v : bulletMLFiles) {
        FString path = FPaths::Combine(contentDir, BulletMLPath, FString(v.Value.c_str()));
        BulletMLParserTinyXML* bulletParser = new BulletMLParserTinyXML(TCHAR_TO_UTF8(*path));
        UE_LOG(LogTemp, Warning, TEXT("Building BulletML file: %s"), *path);
        try {
            bulletParser->build();
        } catch(BulletMLError e) {
            FMessageDialog::Open(EAppMsgType::Ok, FText::Format(
                LOCTEXT("BulletMLError", "Failed to build BulletML file: {0}"),
                FText::FromString(path)
            ));
            throw e;
        }
        bulletParsers.Add(v.Key, bulletParser);
    }
}

UBulletSubsystem::~UBulletSubsystem() {
    for(auto& v : bulletParsers) {
        delete v.Value;
        v.Value = nullptr;
    }
}

#undef LOCTEXT_NAMESPACE
