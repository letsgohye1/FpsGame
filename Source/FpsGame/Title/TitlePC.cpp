// Fill out your copyright notice in the Description page of Project Settings.


#include "TitlePC.h"
#include "TitleWidget.h"

void ATitlePC::BeginPlay()
{
	Super::BeginPlay();

    //1. SoftClassPath를 쓰면 하드 종속성이 없어져서 로딩이 안전: 경로 문자열만 들고 있다. 나중에 필요하면 로드
    FSoftClassPath TitleWidgetClass(TEXT("/Game/MyProject/Blueprint/Title/WBP_Title.WBP_Title_C"));

    //2. TryLoadClass: 이제 진짜로 에셋을 메모리에 로드하고 UClass로 변환
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





	//마우스 커서 보이게 설정
	bShowMouseCursor = true;

	//UI입력만 가능하도록 설정
	SetInputMode(FInputModeUIOnly());

}
