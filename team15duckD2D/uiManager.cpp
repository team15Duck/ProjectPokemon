#include "stdafx.h"
#include "uiManager.h"


uiManager::uiManager()
{
}


uiManager::~uiManager()
{
}

HRESULT uiManager::init()
{
	//1. 도감 초기화
	{
		IllustratedBook* book = new IllustratedBook;
		book->init();
		_uiMap.insert(make_pair(UI_ILLUST, book));
	}
	//2. 포켓몬 초기화
	{
		possessionPokemon* pokemon = new possessionPokemon;
		pokemon->init();
		_uiMap.insert(make_pair(UI_POKEMON, pokemon));
	}
	//3. 가방 초기화
	{
		bag* itembag = new bag;
		itembag->init();
		_uiMap.insert(make_pair(UI_BAG, itembag));

	}
	//4. 플레이어 초기화
	{

	}
	//5. 리포트 초기화
	{

	}
	//6. 세팅 초기화
	{
		setting* gamesetting = new setting;
		gamesetting->init();
		_uiMap.insert(make_pair(UI_BAG, gamesetting));
	}
	
	_currentUI = UI_NONE;

	return S_OK;
}

void uiManager::release()
{
}

void uiManager::update()
{
	_uiMap[_currentUI]->update();
}

void uiManager::render()
{
	_uiMap[_currentUI]->render();
}
