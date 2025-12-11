// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleWidget.generated.h"

/**
 * 
 */
UCLASS()
class FPSGAME_API UTitleWidget : public UUserWidget
{
	GENERATED_BODY()
	

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (WidgetBind))
	TObjectPtr<class UButton> StartServerButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (WidgetBind))
	TObjectPtr<class UButton> ConnectButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (WidgetBind))
	TObjectPtr<class UEditableTextBox> UserID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (WidgetBind))
	TObjectPtr<class UEditableTextBox> Password;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (WidgetBind))
	TObjectPtr<class UEditableTextBox> ServerIP;


public:
	virtual void NativeConstruct() override; //BeginPlay같은 함수

	UFUNCTION()
	void StartServer();

	UFUNCTION()
	void Connect();

	UFUNCTION()
	void SaveData();


};
