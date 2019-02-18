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
	//1. ���� �ʱ�ȭ
	{
		IllustratedBook* book = new IllustratedBook;
		book->init();
		_uiMap.insert(make_pair(UI_ILLUST, book));
	}
	//2. ���ϸ� �ʱ�ȭ
	{
		possessionPokemon* pokemon = new possessionPokemon;
		pokemon->init();
		_uiMap.insert(make_pair(UI_POKEMON, pokemon));
	}
	//3. ���� �ʱ�ȭ
	{
		bag* itembag = new bag;
		itembag->init();
		_uiMap.insert(make_pair(UI_BAG, itembag));

	}
	//4. �÷��̾� �ʱ�ȭ
	{

	}
	//5. ����Ʈ �ʱ�ȭ
	{

	}
	//6. ���� �ʱ�ȭ
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
