#include "stdafx.h"
#include "townScene.h"


townScene::townScene()
{
}


townScene::~townScene()
{
}

HRESULT townScene::init()
{
	_townMap = new townMap;
	_townMap->init("data/townMapSize.map", "data/townMapData.map");

	_player = new player;
	_player->init();
	_townMap->setPlayerMemoryAdressLink(_player);
	_player->setMapDataMemoryAdressLink(_townMap);
	return S_OK;
}

void townScene::release()
{
	_townMap->release();
}

void townScene::update()
{
	_townMap->update();
	_player->update();
	CAMERA->move(_player->getPosX(), _player->getPosY());
}

void townScene::render()
{
	_townMap->render();
}
