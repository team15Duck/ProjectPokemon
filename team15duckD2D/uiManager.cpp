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
	//0. ���� �ʱ�ȭ
	{
		mainUi* main = new mainUi;
		main->init();
		_uiMap.insert(make_pair(UI_MAIN, main));
	}
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
		ui_player* playercard = new ui_player;
		playercard->init();
		_uiMap.insert(make_pair(UI_PLAYER, playercard));
	}
	//5. ����Ʈ �ʱ�ȭ
	{
		report* savereport = new report;
		savereport->init();
		_uiMap.insert(make_pair(UI_REPORT, savereport));
	}
	//6. ���� �ʱ�ȭ
	{
		setting* gamesetting = new setting;
		gamesetting->init();
		_uiMap.insert(make_pair(UI_SETTING, gamesetting));
	}
	
	_currentUI = UI_NONE;

	return S_OK;
}

void uiManager::release()
{
}

void uiManager::update()
{

	if (_currentUI == UI_NONE) return;

	_uiMap[_currentUI]->update();
}

void uiManager::render()
{
	if (_currentUI == UI_NONE) return;
	_uiMap[_currentUI]->render();
}

void uiManager::uiDataSetting()
{
	map<UI_TYPE, baseUI*>::iterator iter = _uiMap.begin();
	map<UI_TYPE, baseUI*>::iterator end = _uiMap.end();

	for (; iter != end; ++iter)
	{
		iter->second->uiInfoSet();
	}
}

