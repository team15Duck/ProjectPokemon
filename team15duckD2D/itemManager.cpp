#include "stdafx.h"
#include "itemManager.h"
#include "pokemonInfo.h"

itemManager::itemManager()
{
}


itemManager::~itemManager()
{
}

HRESULT itemManager::init()
{
	_vItems.clear();
	// ==============================================================
	// 1. 아이템은 비매품도 있다. 그르면 구입가는 0 / 판매가 설정
	// 2. value에는 속도, 몬스터 잡을 확률 등 필요하다.
	// 3. 아이템 이미지는 어느 UI든 위치가 동일하다. (상점, 가방, 도구시스템)
	// 4. 포켓몬볼은 포획률을 어떻게 할건지 생각해볼것
	// ==============================================================
	IMAGEMANAGER->addFrameImage("items", L"image/items.png", 2600, 100, 26, 1);
	IMAGEMANAGER->addImage("테스트11", L"image/test/ccc.png", 960, 640);

	return S_OK;
}

void itemManager::release()
{
}

void itemManager::update()
{
}

void itemManager::render()
{
	IMAGEMANAGER->render("테스트11", 0 + CAMERA->getPosX(), 0 + +CAMERA->getPosY(), 1.0f);
	_vItems[_choiceItem]->render();
}

