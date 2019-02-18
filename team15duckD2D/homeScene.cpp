#include "stdafx.h"
#include "homeScene.h"


homeScene::homeScene()
{
}

homeScene::~homeScene()
{
}



HRESULT homeScene::init()
{
	_homeMap = new homeMap;
	_homeMap->init("data/homeMapSize.map", "data/homeMapData.map");

	_player = new player;
	_player->init();
	_homeMap->setPlayerMemoryAdressLink(_player);
	_player->setMapDataMemoryAdressLink(_homeMap);
	return S_OK;
}

void homeScene::release()
{
	_homeMap->release();
}

void homeScene::update()
{
	_homeMap->update();
	_player->update();
	CAMERA->move(_player->getPosX(), _player->getPosY());
}

void homeScene::render()
{
	_homeMap->render();
}
