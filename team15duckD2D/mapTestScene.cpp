#include "stdafx.h"
#include "mapTestScene.h"


mapTestScene::mapTestScene()
{
}


mapTestScene::~mapTestScene()
{
}

HRESULT mapTestScene::init()
{
	_testMap = new testMap;
	_testMap->init("data/testMapSize.map", "data/testMapData.map");

	_player = new player;
	_player->init();
	_testMap->setPlayerMemoryAdressLink(_player);

	return S_OK;
}

void mapTestScene::release()
{
	_testMap->release();
}

void mapTestScene::update()
{
	_testMap->update();
	_player->update();
	//CAMERA->move(_player-)
}

void mapTestScene::render()
{
	_testMap->render();
	_player->render();
}
