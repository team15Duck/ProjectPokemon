#include "stdafx.h"
#include "centerScene.h"


centerScene::centerScene()
{
}

centerScene::~centerScene()
{
}



HRESULT centerScene::init()
{
	_centerMap = new centerMap;
	_centerMap->init("data/centerMapSize.map", "data/centerMapData.map");

	_player = new player;
	_player->init();
	_centerMap->setPlayerMemoryAdressLink(_player);
	_player->setMapDataMemoryAdressLink(_centerMap);

	SOUNDMANAGER->addSound("centerBGM", "sound/bgm_13_Pokemon_Center.mp3", true, true);
	SOUNDMANAGER->play("centerBGM");

	return S_OK;
}

void centerScene::release()
{
	_centerMap->render();
}

void centerScene::update()
{
	_centerMap->update();
	_player->update();
	CAMERA->move(_player->getPosX(), _player->getPosY());
}

void centerScene::render()
{
	_centerMap->render();
}
