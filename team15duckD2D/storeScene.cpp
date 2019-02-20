#include "stdafx.h"
#include "storeScene.h"


storeScene::storeScene()
{
}

storeScene::~storeScene()
{
}



HRESULT storeScene::init()
{
	_storeMap = new storeMap;
	_storeMap->init("data/storeMapSize.map", "data/storeMapData.map");

	_storeMap->setPlayerMemoryAdressLink(PLAYERDATA->getPlayer());
	PLAYERDATA->getPlayer()->setMapDataMemoryAdressLink(_storeMap);
	
	SOUNDMANAGER->addSound("storeBGM", "sound/bgm_13_Pokemon_Center.mp3", true, true);
	//SOUNDMANAGER->play("storeBGM");

	_npc = new npc;
	_npc->init(NPC_TYPE_SHOPOWNER);
	_storeMap->pushNpc(_npc);

	_test = false;
	
	return S_OK;
}

void storeScene::release()
{
	_storeMap->release();
}

void storeScene::update()
{
	_storeMap->update();
	PLAYERDATA->getPlayer()->update();
	_npc->update();

	_test = _npc->getIsTalk();
	if (_test)
	{
		//activeShopOwner();
	}

	SCRIPTMANAGER->update();
	CAMERA->move(PLAYERDATA->getPlayer()->getPosX(), PLAYERDATA->getPlayer()->getPosY());
}

void storeScene::render()
{
	_storeMap->render();
	SCRIPTMANAGER->render();
}

void storeScene::activeShopOwner()
{
	//선택창 ( 1. 사러왔다 / 2. 팔러왔다 / 3. 아닙니다)

	//1. 사러왔다 선택했을때
	{
		wstring text = L"(아이템)(를)을 \n몇 개 구입하시겠습니까?";
		SCRIPTMANAGER->pushScript(text);
	}
	//개수선택
	{
		wstring text = L"(아이템) (개수)로군요. \n총 (금액)원니다.";
		SCRIPTMANAGER->pushScript(text);
	}
	{
		wstring text = L"네 여기 있습니다. \n대단히 감사합니다.";
		SCRIPTMANAGER->pushScript(text);
	}

	//2. 팔러왔다 선택했을때 
	{
		wstring text = L"(아이템)(를)을 \n 몇 개 파시겠습니까?";
		SCRIPTMANAGER->pushScript(text);
	}
	//개수선택
	{
		wstring text = L"(아이템) (개수)로군요. 총 (금액)원입니다.";
		SCRIPTMANAGER->pushScript(text);
	}
	{
		wstring text = L"(아이템)(를)을 받아 (금액)원을 드렸습니다.";
		SCRIPTMANAGER->pushScript(text);
	}

	//1,2번에서 취소버튼 눌렀을때
	{
		wstring text = L"그 밖에 저희가 \n뭐 도와드릴 건 없습니까?";
		SCRIPTMANAGER->pushScript(text);
	}

	//3. 아닙니다.
	{
		wstring text = L"또 오세요!";
		SCRIPTMANAGER->pushScript(text);
	}
}
