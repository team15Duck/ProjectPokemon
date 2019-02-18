#include "stdafx.h"
#include "storeScene.h"


storeScene::storeScene()
{
}

storeScene::~storeScene()
{
}



HRESULT storeScene::init()
{
	_storeMap = new storeMap;
	_storeMap->init("data/storeMapSize.map", "data/storeMapData.map");

	_player = new player;
	_player->init();
	_storeMap->setPlayerMemoryAdressLink(_player);
	_player->setMapDataMemoryAdressLink(_storeMap);
	
	SOUNDMANAGER->addSound("storeBGM", "sound/bgm_13_Pokemon_Center.mp3", true, true);
	SOUNDMANAGER->play("storeBGM");
	
	return S_OK;
}

void storeScene::release()
{
	_storeMap->release();
}

void storeScene::update()
{
	_storeMap->update();
	_player->update();
	CAMERA->move(_player->getPosX(), _player->getPosY());
}

void storeScene::render()
{
	_storeMap->render();
}
