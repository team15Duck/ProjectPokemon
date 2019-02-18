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
	_testMap->init("data/townMapSize.map", "data/townMapData.map");

	_player = new player;
	_player->init();
	_testMap->setPlayerMemoryAdressLink(_player);
	_player->setMapDataMemoryAdressLink(_testMap);

	_npc = new npc;
	_npc->init(NPC_TYPE_OAK);
	_testMap->pushNpc(_npc);

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
	_npc->update();
	_npc->setPlayerState(_player->getState());
	CAMERA->move(_player->getPosX(), _player->getPosY());
}

void mapTestScene::render()
{
	_testMap->render();
}
