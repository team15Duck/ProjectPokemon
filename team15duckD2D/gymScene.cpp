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

	SOUNDMANAGER->addSound("gymBGM", "sound/bgm_14_Pokemon_Gym.mp3", true, true);
	SOUNDMANAGER->play("gymBGM");

	return S_OK;
}

void gymScene::release()
{
	_gymMap->release();
}

void gymScene::update()
{
	_gymMap->update();
	PLAYERDATA->getPlayer()->update();
	CAMERA->move(PLAYERDATA->getPlayer()->getPosX(), PLAYERDATA->getPlayer()->getPosY());
}

void gymScene::render()
{
	_gymMap->render();
}
