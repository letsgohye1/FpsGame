// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LobbyPC.generated.h"

/**
 * 
 */
UCLASS()
class FPSGAME_API ALobbyPC : public APlayerController
{
	GENERATED_BODY()

public:
	ALobbyPC();


public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UMG")
	TObjectPtr<class ULobbyWidget> LobbywidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UMG")
	TObjectPtr<class ULobbyWidget> LobbywidgetObject;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UMG")
	TObjectPtr<class ULobbyWidget> LoadingWidgerClass;


public:

	UFUNCTION(Server, Reliable, WithValidation)
	void C2S_SendMessage(const FText& Messaage); //Network 던지는 코드 생성
	bool C2S_SendMessage_Validate(const FText& Messaage); //서버에서 확인하는 코드
	void C2S_SendMessage_Implementation(const FText& Messaage); //실제동작


	UFUNCTION(Client, Reliable)
	void S2C_SendMessage(const FText& Messaage); //Network 정보 던져서 실행, 자동생성
	void S2C_SendMessage_Implementation(const FText& Messaage); //실제동작

	UFUNCTION(Client, Reliable)
	void S2C_ShowLoadingScreen(); 
	void S2C_ShowLoadingScreen_Implementation();
};
