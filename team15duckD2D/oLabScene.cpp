#include "stdafx.h"
#include "oLabScene.h"


oLabScene::oLabScene()
{
}

oLabScene::~oLabScene()
{
}



HRESULT oLabScene::init()
{
	_oLabMap = new oLabMap;
	_oLabMap->init("data/oLabMapSize.map", "data/oLabMapData.map");

	_player = new player;
	_player->init();
	_oLabMap->setPlayerMemoryAdressLink(_player);
	_player->setMapDataMemoryAdressLink(_oLabMap);
	return S_OK;
}

void oLabScene::release()
{
	_oLabMap->release();
}

void oLabScene::update()
{
	_oLabMap->update();
	_player->update();
	CAMERA->move(_player->getPosX(), _player->getPosY());
}

void oLabScene::render()
{
	_oLabMap->render();
}
