#include "stdafx.h"
#include "fieldScene.h"


fieldScene::fieldScene()
{
}

fieldScene::~fieldScene()
{
}



HRESULT fieldScene::init()
{
	_fieldMap = new fieldMap;
	_fieldMap->init("data/fieldMapSize.map", "data/fieldMapData.map");

	_player = new player;
	_player->init();
	_fieldMap->setPlayerMemoryAdressLink(_player);
	_player->setMapDataMemoryAdressLink(_fieldMap);

	return S_OK;
}

void fieldScene::release()
{
	_fieldMap->release();
}

void fieldScene::update()
{
	_fieldMap->update();
	_player->update();
	CAMERA->move(_player->getPosX(), _player->getPosY());
}

void fieldScene::render()
{
	_fieldMap->render();
}
