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

	_storeMap->setPlayerMemoryAdressLink(PLAYERDATA->getPlayer());
	PLAYERDATA->getPlayer()->setMapDataMemoryAdressLink(_storeMap);
	
	SOUNDMANAGER->addSound("storeBGM", "sound/bgm_13_Pokemon_Center.mp3", true, true);
	SOUNDMANAGER->play("storeBGM");

	_npc = new npc;
	_npc->init(NPC_TYPE_SHOPOWNER);
	_storeMap->pushNpc(_npc);
	
	return S_OK;
}

void storeScene::release()
{
	_storeMap->release();
}

void storeScene::update()
{
	_storeMap->update();
	PLAYERDATA->getPlayer()->update();
	CAMERA->move(PLAYERDATA->getPlayer()->getPosX(), PLAYERDATA->getPlayer()->getPosY());
}

void storeScene::render()
{
	_storeMap->render();
}
