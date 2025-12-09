// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

//컴포넌트 추가하기
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "Components/CapsuleComponent.h" //GetCapsuleComponent()
#include "Components/SkeletalMeshComponent.h"//GetMesh()

//KismetMathLibrary
#include "Kismet/KismetMathLibrary.h"

// Enhanced Input
#include "InputAction.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"


//#include "GameFramework/Character.h"//GetCharacterMovement
#include "GameFramework/CharacterMovementComponent.h"//GetCharacterMovement




// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//컴포넌트 추가하기
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetCapsuleComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	GetMesh()->SetRelativeLocation(FVector(0, 0, -GetCapsuleComponent()->GetScaledCapsuleHalfHeight()));
	GetMesh()->SetRelativeRotation(FRotator(0,-90.0f,0));

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->MaxWalkSpeed = 300.0f;
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (EIC)
	{
		EIC->BindAction(IA_Sprint, ETriggerEvent::Started, this, &ABaseCharacter::StartSprint);
		EIC->BindAction(IA_Sprint, ETriggerEvent::Completed, this, &ABaseCharacter::StopSprint);

		EIC->BindAction(IA_Crouch, ETriggerEvent::Started, this, &ABaseCharacter::StartCrouch);
		EIC->BindAction(IA_Crouch, ETriggerEvent::Completed, this, &ABaseCharacter::StopCrouch);
	}
}

void ABaseCharacter::Move(float Forward, float Right)
{
	const FRotator YawRot(0, GetController()->GetControlRotation().Yaw, 0);

	AddMovementInput(UKismetMathLibrary::GetForwardVector(YawRot), Forward);
	AddMovementInput(UKismetMathLibrary::GetRightVector(YawRot), Right);
}

void ABaseCharacter::Look(float Pitch, float Yaw)
{
	AddControllerPitchInput(-1*Pitch);
	AddControllerYawInput(Yaw);
}

void ABaseCharacter::StartSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;

}

void ABaseCharacter::StopSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = 300.0f;
}

void ABaseCharacter::StartCrouch()
{
	Crouch();

}

void ABaseCharacter::StopCrouch()
{
	UnCrouch();
}


