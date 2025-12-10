// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePCM.h"
#include "BaseCharacter.h"

ABasePCM::ABasePCM()
{
}

void ABasePCM::UpdateCamera(float DeltaTime)
{
	Super::UpdateCamera(DeltaTime);

	ABaseCharacter* Character = Cast< ABaseCharacter>(GetOwningPlayerController()->GetPawn());

	if (Character)
	{
		float TargetFOV = Character->bIronSight ? IronSightFOV : NormalFOV;
		float CurrentFOV = FMath::FInterpTo(GetFOVAngle(), TargetFOV, DeltaTime, 15.f);
		SetFOV(CurrentFOV);
	}
}
