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
	wstring text = L"�̰������� ���ϸ��� ü���� ȸ���մϴ�. \n����� ���ϸ��� ���� �Ͻðڽ��ϱ�?";
	SCRIPTMANAGER->pushScript(text);

}

void centerScene::centerHealing()
{
	if (_obj->getIsBallUp())
	{
		wstring text = L"�׷� \n�þƳ��ڽ��ϴ�.";
		SCRIPTMANAGER->pushScript(text);
	}

	if (_obj->getTime() <= 0)
	{
		{
			wstring text = L"���� ��ٷȽ��ϴ�!";
			SCRIPTMANAGER->pushScript(text);
		}
		{
			wstring text = L"�þƳ��� ���ϸ��� \n��� �ǰ��������ϴ�!";
			SCRIPTMANAGER->pushScript(text);
		}
	}
	_centerTalk = CENTER_TALK_NOPE_OR_BYE;
}

void centerScene::centerNopeBye()
{
	{
		wstring text = L"���� ������ \n �湮�Ͻñ� ��ٸ��ڽ��ϴ�!";
		SCRIPTMANAGER->pushScript(text);
	}
}