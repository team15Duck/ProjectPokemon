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

	PLAYERDATA->getPlayer()->setSceneName("caveScene");
	_caveMap->setPlayerMemoryAdressLink(PLAYERDATA->getPlayer());
	PLAYERDATA->getPlayer()->setMapDataMemoryAdressLink(_caveMap);

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
	SCRIPTMANAGER->update();
	if (!SCRIPTMANAGER->isUpdate())return;
	_caveMap->update();
	PLAYERDATA->getPlayer()->update();
	CAMERA->move(PLAYERDATA->getPlayer()->getPosX(), PLAYERDATA->getPlayer()->getPosY());
}

void caveScene::render()
{
	_caveMap->render();
	SCRIPTMANAGER->render();
}
