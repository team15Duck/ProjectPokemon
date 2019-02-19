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
	

	return S_OK;
}

void homeScene::release()
{
	_homeMap->release();
}

void homeScene::update()
{
	_homeMap->update();
	PLAYERDATA->getPlayer()->update();
	CAMERA->move(PLAYERDATA->getPlayer()->getPosX(), PLAYERDATA->getPlayer()->getPosY());
}

void homeScene::render()
{
	_homeMap->render();
}
