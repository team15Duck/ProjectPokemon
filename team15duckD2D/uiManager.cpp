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
	{
		IllustratedBook* book = new IllustratedBook;
		book->init();
		_uiMap.insert(make_pair(UI_ILLUST, book));
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
