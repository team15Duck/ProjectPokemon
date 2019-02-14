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
	// 1. 아이템은 비매품도 있다. 그르면 구입가는 0 / 판매가 설정				 v
	// 2. value에는 속도, 몬스터 잡을 확률 등 필요하다.						 v
	// 3. 아이템 이미지는 어느 UI든 위치가 동일하다. (상점, 가방, 도구시스템)	 v
	// 4. 포켓몬볼은 포획률을 어떻게 할건지 생각해볼것
	// 5. 세이브로드 만들자
	// ==============================================================

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

	_vItems[_choiceItem]->render();
}

