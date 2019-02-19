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

	_centerMap->setPlayerMemoryAdressLink(PLAYERDATA->getPlayer());
	PLAYERDATA->getPlayer()->setMapDataMemoryAdressLink(_centerMap);
	PLAYERDATA->getPlayer()->setSceneName("centerScene");

	SOUNDMANAGER->addSound("centerBGM", "sound/bgm_13_Pokemon_Center.mp3", true, true);
	SOUNDMANAGER->play("centerBGM");

	_npc = new npc;
	_npc->init(NPC_TYPE_NURSE);
	_centerMap->pushNpc(_npc);

	return S_OK;
}

void centerScene::release()
{
	_centerMap->release();
}

void centerScene::update()
{
	_centerMap->update();
	PLAYERDATA->getPlayer()->update();
	CAMERA->move(PLAYERDATA->getPlayer()->getPosX(), PLAYERDATA->getPlayer()->getPosY());
}

void centerScene::render()
{
	_centerMap->render();
}
