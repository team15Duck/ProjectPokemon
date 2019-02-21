#include "stdafx.h"
#include "homeScene.h"


homeScene::homeScene()
{
}

homeScene::~homeScene()
{
}



HRESULT homeScene::init()
{
	_homeMap = new homeMap;
	_homeMap->init("data/homeMapSize.map", "data/homeMapData.map");

	
	PLAYERDATA->getPlayer()->setMapDataMemoryAdressLink(_homeMap);
	_homeMap->setPlayerMemoryAdressLink(PLAYERDATA->getPlayer());
	PLAYERDATA->getPlayer()->setSceneName("hoemScene");

	SOUNDMANAGER->addSound("homeBGM", "sound/bgm_11_City_Theme_Pallet_Town.mp3", true, true);
	SOUNDMANAGER->play("homeBGM");
	
	UIMANAGER->init();

	return S_OK;
}

void homeScene::release()
{
	_homeMap->release();
}

void homeScene::update()
{
	SCRIPTMANAGER->update();
	if (!SCRIPTMANAGER->isUpdate())return;
	_homeMap->update();
	PLAYERDATA->getPlayer()->update();
	CAMERA->move(PLAYERDATA->getPlayer()->getPosX(), PLAYERDATA->getPlayer()->getPosY());

	UIMANAGER->update();
}

void homeScene::render()
{
	_homeMap->render();
	SCRIPTMANAGER->render();
	UIMANAGER->render();
}
