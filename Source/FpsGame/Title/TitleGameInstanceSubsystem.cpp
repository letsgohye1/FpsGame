// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleGameInstanceSubsystem.h"

void UTitleGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

/*
	
Subsystem은 게임이 시작되면 자동으로 생성됨

→ 이 순간에 하고 싶은 작업을 Initialize에서 실행
예:

저장된 ID/PW 로드

서버 연결

캐싱 데이터 초기화

UI Manager 생성

설정 파일 읽기

DB 불러오기

*/

}

void UTitleGameInstanceSubsystem::Deinitialize()
{
	Super::Deinitialize();

/*
게임이 종료될 때 자동으로 파괴됨

→ 이 순간에 하고 싶은 작업을 Deinitialize에서 실행
예:

플레이어 정보 저장

세션 정리

파일로 기록

캐시 정리

서버 로그아웃
*/
}
