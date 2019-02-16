#include "stdafx.h"
#include "loadingScene.h"


loadingScene::loadingScene()
{
}


loadingScene::~loadingScene()
{
}

HRESULT loadingScene::init()
{
	//배경이랑 로딩바 이미지 처리 하면됨 여기서 
	//배경이랑 로딩바 이미지 처리 하면됨 여기서 
	//배경이랑 로딩바 이미지 처리 하면됨 여기서 


	CreateThread
	(
		NULL,			//스레드의 보안속성(자식윈도우가 있을때) 핸들로 자식인지 부모인지 여부파악
		NULL,			//스레드의 스택크기(NULL로 두면 메인쓰레드와 스택크기는 동일)
		ThreadFunction,	//스레드 함수 명
		this,			//스레드의 매개변수 (this로 하면 본 클래스)
		NULL,			//스레드의 특성(NULL로 두면 바로 실행함)
		0				//스레드의 생성 후 스레드의 ID를 넘겨준다 보통은 NULL로 둠.
	);

	return S_OK;
}

void loadingScene::release()
{
}

void loadingScene::update()
{
}

void loadingScene::render()
{
	//백그라운드
	//로딩바
}



DWORD CALLBACK ThreadFunction(LPVOID lpParameter)
{
	loadingScene* loadHelper = (loadingScene*)lpParameter;

	//로딩맥스가 1000이기 때문에 이미지는 임의로 1000개만 돌려봅시다
	while (loadHelper->_currentCount != LOADINGMAX)
	{
		IMAGEMANAGER->addImage("인게임", "캐릭터.bmp", 580, 565, false, RGB(0, 0, 0));
		Sleep(1); //이거 없으면 천장이고 뭐고 후다다닥 해버림

		loadHelper->_currentCount++;
	}

	return 0;
}
