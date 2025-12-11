// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LobbyWidget.generated.h"

/**
 * 
 */
UCLASS()
class FPSGAME_API ULobbyWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override; //BeginPlay같은 함수

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget))
	TObjectPtr<class UButton> StartButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget))
	TObjectPtr<class UEditableTextBox> ChatInput;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget))
	TObjectPtr<class UScrollBox> ChatScrollBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget))
	TObjectPtr<class UTextBlock> LeftTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget", meta = (BindWidget))
	TObjectPtr<class UTextBlock> ConnectionCount;
	
};

/*
Text
LeftTime 남은시간 60초

ConnectionCount 접속자 100명



SizeBox
>border
>>ChatScrollBox

Start

AddMessage

UpdateLeftTime

UpdateConnectionCount

ShowStartButton

*/


/*


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

*/