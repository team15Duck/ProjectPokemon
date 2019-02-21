#include "stdafx.h"
#include "townScene.h"


townScene::townScene()
{
}


townScene::~townScene()
{
}

HRESULT townScene::init()
{
	_townMap = new townMap;
	_townMap->init("data/townMapSize.map", "data/townMapData.map");


	_townMap->setPlayerMemoryAdressLink(PLAYERDATA->getPlayer());
	PLAYERDATA->getPlayer()->setMapDataMemoryAdressLink(_townMap);
	PLAYERDATA->getPlayer()->setSceneName("townScene");
	SOUNDMANAGER->addSound("townBGM", "sound/bgm_11_City_Theme_Pallet_Town.mp3", true, true);
	SOUNDMANAGER->play("townBGM");
	UIMANAGER->uiDataSetting();
	return S_OK;
}

void townScene::release()
{
	_townMap->release();
	
}

void townScene::update()
{
	SCRIPTMANAGER->update();
	if (!SCRIPTMANAGER->isUpdate())return;
	_townMap->update();

	PLAYERDATA->getPlayer()->update();
	CAMERA->move(PLAYERDATA->getPlayer()->getPosX(), PLAYERDATA->getPlayer()->getPosY());
	
	UIMANAGER->update();
}

void townScene::render()
{
	_townMap->render();
	SCRIPTMANAGER->render();
	UIMANAGER->render();
	PLAYERDATA->getPlayer()->rectRender();
}
