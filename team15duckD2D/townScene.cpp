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

	SOUNDMANAGER->addSound("townBGM", "sound/bgm_11_City_Theme_Pallet_Town.mp3", true, true);
	SOUNDMANAGER->play("townBGM");

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
