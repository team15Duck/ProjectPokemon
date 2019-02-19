#include "stdafx.h"
#include "oLabScene.h"


oLabScene::oLabScene()
{
}

oLabScene::~oLabScene()
{
}



HRESULT oLabScene::init()
{
	_oLabMap = new oLabMap;
	_oLabMap->init("data/oLabMapSize.map", "data/oLabMapData.map");

	_oLabMap->setPlayerMemoryAdressLink(PLAYERDATA->getPlayer());
	PLAYERDATA->getPlayer()->setMapDataMemoryAdressLink(_oLabMap);

	SOUNDMANAGER->addSound("oLabBGM", "sound/bgm_07_Professor_Oaks_Laboratory.mp3", true, true);
	SOUNDMANAGER->play("oLabBGM");

	return S_OK;
}

void oLabScene::release()
{
	_oLabMap->release();
}

void oLabScene::update()
{
	_oLabMap->update();
	PLAYERDATA->getPlayer()->update();
	CAMERA->move(PLAYERDATA->getPlayer()->getPosX(), PLAYERDATA->getPlayer()->getPosY());
}

void oLabScene::render()
{
	_oLabMap->render();
}
