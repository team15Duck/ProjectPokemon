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

	_npc = new npc;
	_npc->init(NPC_TYPE_OAK);
	_oLabMap->pushNpc(_npc);

	UIMANAGER->uiDataSetting();

	return S_OK;
}

void oLabScene::release()
{
	_oLabMap->release();
}

void oLabScene::update()
{
	SCRIPTMANAGER->update();
	if (!SCRIPTMANAGER->isUpdate())return;
	_oLabMap->update();
	PLAYERDATA->getPlayer()->update();
	_npc->update();
	CAMERA->move(PLAYERDATA->getPlayer()->getPosX(), PLAYERDATA->getPlayer()->getPosY());
	UIMANAGER->update();
}

void oLabScene::render()
{
	_oLabMap->render();
	SCRIPTMANAGER->render();
	UIMANAGER->render();
}
