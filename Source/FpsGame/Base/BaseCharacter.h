// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"//UIC
#include "BaseCharacter.generated.h"


UCLASS()
class FPSGAME_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
public: //컴포넌트 추가하기
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	TObjectPtr<class USpringArmComponent> SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	TObjectPtr<class UCameraComponent> Camera;



public: //Action

	//Move
	UFUNCTION(BlueprintCallable)
	void Move(float Forward, float Right);


	//Look
	UFUNCTION(BlueprintCallable)
	void Look(float Pitch, float Yaw);

	//Sprint
	void StartSprint();
	void StopSprint();

	//Crouch
	void StartCrouch();
	void StopCrouch();


public: //IA_Action
	//IA_Sprint
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	TObjectPtr <UInputAction> IA_Sprint;

	//IA_Crouch
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character")
	TObjectPtr <UInputAction> IA_Crouch;
};
