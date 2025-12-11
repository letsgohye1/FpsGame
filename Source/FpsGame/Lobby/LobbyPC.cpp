// Fill out your copyright notice in the Description page of Project Settings.


// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPC.h"
#include "LobbyWidget.h"



ALobbyPC::ALobbyPC()
{
}

void ALobbyPC::BeginPlay()
{
    Super::BeginPlay();
}

/*
  UClass* WidetClass = TitleWidgetClass.TryLoadClass<UTitleWidget>();

    //3. CreateWidget: “이 Class를 기반으로 실제 위젯 인스턴스를 만들어줘.”
    if (WidetClass)
    {
        TitleWidgetObject = CreateWidget<UTitleWidget>(this, WidetClass);
        if (TitleWidgetObject)
        {
            TitleWidgetObject->AddToViewport();
        }
    }
*/

void ALobbyPC::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}


bool ALobbyPC::C2S_SendMessage_Validate(const FText& Messaage)
{
	return false;
}

void ALobbyPC::C2S_SendMessage_Implementation(const FText& Messaage)
{
}

void ALobbyPC::S2C_SendMessage_Implementation(const FText& Messaage)
{
}

void ALobbyPC::S2C_ShowLoadingScreen_Implementation()
{
}

