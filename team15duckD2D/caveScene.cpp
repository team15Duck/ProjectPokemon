#include "stdafx.h"
#include "caveScene.h"


caveScene::caveScene()
{
}

caveScene::~caveScene()
{
}



HRESULT caveScene::init()
{
	_caveMap = new caveMap;
	_caveMap->init("data/caveMapSize.map", "data/caveMapData.map");

	_player = new player;
	_player->init();
	_caveMap->setPlayerMemoryAdressLink(_player);
	_player->setMapDataMemoryAdressLink(_caveMap);
	return S_OK;
}

void caveScene::release()
{
	_caveMap->release();
}

void caveScene::update()
{
	_caveMap->update();
	_player->update();
	CAMERA->move(_player->getPosX(), _player->getPosY());
}

void caveScene::render()
{
	_caveMap->render();
}
