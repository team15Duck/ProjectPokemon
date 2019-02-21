#include "stdafx.h"
#include "gymScene.h"


gymScene::gymScene()
{
}

gymScene::~gymScene()
{
}



HRESULT gymScene::init()
{
	_gymMap = new gymMap;
	_gymMap->init("data/gymMapSize.map", "data/gymMapData.map");

	_gymMap->setPlayerMemoryAdressLink(PLAYERDATA->getPlayer());
	PLAYERDATA->getPlayer()->setMapDataMemoryAdressLink(_gymMap);
	PLAYERDATA->getPlayer()->setSceneName("gymScene");

	SOUNDMANAGER->addSound("gymBGM", "sound/bgm_14_Pokemon_Gym.mp3", true, true);
	SOUNDMANAGER->play("gymBGM");

	_npc = new npc;
	_npc->init(NPC_TYPE_BOSS);
	_gymMap->pushNpc(_npc);

	UIMANAGER->init();

	return S_OK;
}

void gymScene::release()
{
	_gymMap->release();
}

void gymScene::update()
{
	SCRIPTMANAGER->update();
	if (!SCRIPTMANAGER->isUpdate())return;
	_gymMap->update();
	PLAYERDATA->getPlayer()->update();
	_npc->update();
	CAMERA->move(PLAYERDATA->getPlayer()->getPosX(), PLAYERDATA->getPlayer()->getPosY());
	UIMANAGER->update();
}

void gymScene::render()
{
	_gymMap->render();
	SCRIPTMANAGER->render();
	UIMANAGER->render();
}
