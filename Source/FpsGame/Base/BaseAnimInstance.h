// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BaseAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class FPSGAME_API UBaseAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public: //매 프레임마다 애니메이션 값을 갱신
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;


public: //ABP 사용 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
	float GroundSpeed = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
	float Direction = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
	uint8 bIsCrouched : 1;

};
