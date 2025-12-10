// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseHUD.h"
#include "Engine/Canvas.h"//Canvas()
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"

void ABaseHUD::DrawHUD()
{
	Super::DrawHUD();

	uint32 Unit = Canvas->SizeX / 100;

	uint32 CenterX = Canvas->SizeX / 2;
	uint32 CenterY = Canvas->SizeY / 2;

	uint32 Gap = Unit * 3;
	float GapRatio = 0.f;

	float CurrentSpeed = 0.f;


	ACharacter* Pawn = Cast<ACharacter>(GetOwningPawn());

	if (Pawn)
	{
		CurrentSpeed = Pawn->GetCharacterMovement()->Velocity.Size2D();
	}

	Gap = float (CurrentSpeed) /50;

	Draw2DLine( //좌측 가로선
		CenterX - Unit - Gap, 
		CenterY, 
		CenterX-Gap,
		CenterY,
		FColor::Red);

	Draw2DLine( //우측 가로선
		CenterX + Gap,
		CenterY,
		CenterX + Unit + Gap,
		CenterY,
		FColor::Red);


	Draw2DLine( //상측 세로선
		CenterX, 
		CenterY - Gap,
		CenterX ,
		CenterY - Unit - Gap,
		FColor::Red);

	Draw2DLine( //하측 세로선
		CenterX,
		CenterY + Unit + Gap,
		CenterX,
		CenterY + Gap,
		FColor::Red);

}