#include "stdafx.h"
#include "fieldScene.h"


fieldScene::fieldScene()
{
}

fieldScene::~fieldScene()
{
}



HRESULT fieldScene::init()
{
	_fieldMap = new fieldMap;
	_fieldMap->init("data/fieldMapSize.map", "data/fieldMapData.map");

	_fieldMap->setPlayerMemoryAdressLink(PLAYERDATA->getPlayer());
	PLAYERDATA->getPlayer()->setMapDataMemoryAdressLink(_fieldMap);
	PLAYERDATA->getPlayer()->setSceneName("fieldScene");

	SOUNDMANAGER->addSound("fieldBGM", "sound/bgm_10_Road_to_Viridian_City.mp3", true, true);
	SOUNDMANAGER->play("fieldBGM");

	UIMANAGER->init();
	return S_OK;
}

void fieldScene::release()
{
	_fieldMap->release();
}

void fieldScene::update()
{
	SCRIPTMANAGER->update();
	if (!SCRIPTMANAGER->isUpdate())return;
	_fieldMap->update();
	PLAYERDATA->getPlayer()->update();
	CAMERA->move(PLAYERDATA->getPlayer()->getPosX(), PLAYERDATA->getPlayer()->getPosY());
	UIMANAGER->update();
}

void fieldScene::render()
{
	_fieldMap->render();
	SCRIPTMANAGER->render();
	UIMANAGER->render();
}
