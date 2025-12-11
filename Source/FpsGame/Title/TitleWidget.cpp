// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleWidget.h"

#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Kismet/GameplayStatics.h" //UGameplayStatics::OpenLevel
#include "TitleGameInstanceSubsystem.h"



void UTitleWidget::NativeConstruct()
{
    ServerIP = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("ServerIP")));

    StartServerButton->OnClicked.AddDynamic(this, &UTitleWidget::StartServer);
    ConnectButton->OnClicked.AddDynamic(this, &UTitleWidget::Connect);

}

//리슨 서버를 열어서 Lobby 맵을 서버로 실행
void UTitleWidget::StartServer()
{
    SaveData();
    UGameplayStatics::OpenLevel(GetWorld(), TEXT("LobbyMap"), true, TEXT("listen"));
}

//“리슨 서버의 IP 주소”를 이용해서 그 서버에 접속
void UTitleWidget::Connect()
{
    SaveData();
    UGameplayStatics::OpenLevel(GetWorld(), FName(ServerIP->GetText().ToString()), true, TEXT("Option"));

}

//위젯의 입력창(UserID, Password)을 읽어서 GameInstanceSubsystem에 저장
void UTitleWidget::SaveData()
{
    UGameInstance* GI = UGameplayStatics::GetGameInstance(GetWorld());

    if (GI)
    {
        UTitleGameInstanceSubsystem* TitleGISubsystem = GI->GetSubsystem<UTitleGameInstanceSubsystem>();
        TitleGISubsystem->UserID = UserID->GetText().ToString();        
        TitleGISubsystem->Password = Password->GetText().ToString();

    }
}
