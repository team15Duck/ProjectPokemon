#include "stdafx.h"
#include "gymScene.h"


gymScene::gymScene()
{
}

gymScene::~gymScene()
{
}



HRESULT gymScene::init()
{
	_gymMap = new gymMap;
	_gymMap->init("data/gymMapSize.map", "data/gymMapData.map");

	_player = new player;
	_player->init();
	_gymMap->setPlayerMemoryAdressLink(_player);
	_player->setMapDataMemoryAdressLink(_gymMap);
	return S_OK;
}

void gymScene::release()
{
	_gymMap->release();
}

void gymScene::update()
{
	_gymMap->update();
	_player->update();
	CAMERA->move(_player->getPosX(), _player->getPosY());
}

void gymScene::render()
{
	_gymMap->render();
}
