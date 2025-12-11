// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TitleGameInstanceSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class FPSGAME_API UTitleGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// 초기화
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	// 정리
	virtual void Deinitialize() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
	FString UserID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
	FString Password;

	
};
