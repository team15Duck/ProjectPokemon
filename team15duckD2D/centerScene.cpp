#include "stdafx.h"
#include "centerScene.h"


centerScene::centerScene()
{
}

centerScene::~centerScene()
{
}



HRESULT centerScene::init()
{
	_centerMap = new centerMap;
	_centerMap->init("data/centerMapSize.map", "data/centerMapData.map");

	_centerMap->setPlayerMemoryAdressLink(PLAYERDATA->getPlayer());
	PLAYERDATA->getPlayer()->setMapDataMemoryAdressLink(_centerMap);
	PLAYERDATA->getPlayer()->setSceneName("centerScene");

	SOUNDMANAGER->addSound("centerBGM", "sound/bgm_13_Pokemon_Center.mp3", true, true);
	SOUNDMANAGER->play("centerBGM");

	_npc = new npc;
	_npc->init(NPC_TYPE_NURSE);
	_centerMap->pushNpc(_npc);

	_obj = new object;
	_obj->init();
	_obj->setSceneName("centerScene");

	return S_OK;
}

void centerScene::release()
{
	_centerMap->release();
}

void centerScene::update()
{
	_centerMap->update();
	SCRIPTMANAGER->update();
	if (!SCRIPTMANAGER->isUpdate())return;

	PLAYERDATA->getPlayer()->update();
	_npc->update();
	_isTalk = PLAYERDATA->getPlayer()->getShopOn();
	if (_isTalk)
		_obj->update();

	if (_isTalk)
	{
		switch (_centerTalk)
		{
			case CENTER_TALK_HEAL:
			{
				_obj->setIsBallUp(true);
				_centerTalk = CENTER_TALK_HEALING;
				centerHeal();
				break;
			}
			case CENTER_TALK_HEALING:
			{
				_npc->setIsBallUp(_obj->getIsBallUp());
				this->centerHealing();
				_obj->centerHealing();
				break;
			}
			case CENTER_TALK_NOPE_OR_BYE:
			{
				centerNopeBye();
				break;
			}

			default:
				break;
		}
	}
	CAMERA->move(PLAYERDATA->getPlayer()->getPosX(), PLAYERDATA->getPlayer()->getPosY());
}

void centerScene::render()
{
	
	_centerMap->render();
	_obj->render();
	SCRIPTMANAGER->render();
}

void centerScene::centerHeal()
{
	wstring text = L"이곳에서는 포켓몬의 체력을 회복합니다. \n당신의 포켓몬을 쉬게 하시겠습니까?";
	SCRIPTMANAGER->pushScript(text);

}

void centerScene::centerHealing()
{
	if (_obj->getIsBallUp())
	{
		wstring text = L"그럼 \n맡아놓겠습니다.";
		SCRIPTMANAGER->pushScript(text);
	}

	if (_obj->getTime() <= 0)
	{
		{
			wstring text = L"오래 기다렸습니다!";
			SCRIPTMANAGER->pushScript(text);
		}
		{
			wstring text = L"맡아놓은 포켓몬은 \n모두 건강해졌습니다!";
			SCRIPTMANAGER->pushScript(text);
		}
	}
	_centerTalk = CENTER_TALK_NOPE_OR_BYE;
}

void centerScene::centerNopeBye()
{
	{
		wstring text = L"다음 번에도 \n 방문하시길 기다리겠습니다!";
		SCRIPTMANAGER->pushScript(text);
	}
}