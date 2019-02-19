#include "stdafx.h"
#include "caveScene.h"


caveScene::caveScene()
{
}

caveScene::~caveScene()
{
}



HRESULT caveScene::init()
{
	_caveMap = new caveMap;
	_caveMap->init("data/caveMapSize.map", "data/caveMapData.map");

	_caveMap->setPlayerMemoryAdressLink(PLAYERDATA->getPlayer());
	PLAYERDATA->getPlayer()->setMapDataMemoryAdressLink(_caveMap);
	PLAYERDATA->getPlayer()->setSceneName("caveScene");

	SOUNDMANAGER->addSound("caveBGM", "sound/bgm_15_Caves_of_Mt_Moon.mp3", true, true);
	SOUNDMANAGER->play("caveBGM");

	return S_OK;
}

void caveScene::release()
{
	_caveMap->release();
	
}

void caveScene::update()
{
	_caveMap->update();
	PLAYERDATA->getPlayer()->update();
	CAMERA->move(PLAYERDATA->getPlayer()->getPosX(), PLAYERDATA->getPlayer()->getPosY());
}

void caveScene::render()
{
	_caveMap->render();
}
