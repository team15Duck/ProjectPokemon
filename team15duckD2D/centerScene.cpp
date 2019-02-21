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

	_curPointY = 305;

	MENUMANAGER->addFrame("choiceFrame", 960 - 290, 640 - 370, 8, 5);

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

	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		switch (_choice)
		{
			case CHOICE_YES:
			{
				_curPointY = 355;
				_choice = CHOICE_NO;
				break;
			}
			case CHOICE_NO:
			{
				_curPointY = 305;
				_choice = CHOICE_YES;
				break;
			}
			default:
				break;
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		switch (_choice)
		{
			case CHOICE_YES:
			{
				_curPointY = 355;
				_choice = CHOICE_NO;
				break;
			}
			case CHOICE_NO:
			{
				_curPointY = 305;
				_choice = CHOICE_YES;
				break;
			}
			default:
				break;
		}
	}
	/*if (_isTalk && _centerTalk == CENTER_TALK_HEAL)
	{
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			if (_choice == CHOICE_YES)
			{
				_centerTalk = CENTER_TALK_HEALING;
				centerHealing();

			}
			else if (_choice == CHOICE_NO)
			{
				_centerTalk = CENTER_TALK_NOPE_OR_BYE;
			}
		}
	}*/

	if (!SCRIPTMANAGER->isUpdate()) return;

	PLAYERDATA->getPlayer()->update();

	_isTalk = PLAYERDATA->getPlayer()->getShopOn();					//플레이어한테 bool값을 받아온다.
	_npc->setIsTalk(_isTalk);

	if (_isTalk)													//오브젝트&NPC 작동
	{
		_obj->update();
		_npc->update();
	}

	if (_isTalk)																			//플레이어가 말걸었어?
	{

		switch (_centerTalk)
		{
			case CENTER_TALK_HELLO:															//간호사 인사
			{
				SCRIPTMANAGER->pushScript(L"안녕하세요! \n포켓몬 센터입니다!");
				centerHello();
				break;
			}
			case CENTER_TALK_HEAL:															//치료여부(여기서 선택창)
			{
				SCRIPTMANAGER->pushScript(L"이곳에서는 포켓몬의 체력을 회복합니다. \n당신의 포켓몬을 쉬게 하시겠습니까?");
				centerHeal();
				break;
			}
			case CENTER_TALK_HEALING:														//치료중(오브젝트&NPC프레임 시작)
			{
				_isChoice = false;															//선택창출력X
				if (_obj->getTime() <= 0)													//오브젝트에서 설정한 시간이 0이하면
				{
					_npc->setIsBallUp(false);												//프레임종료
					_obj->setIsBallUp(false);												//프레임종료
					SCRIPTMANAGER->pushScript(L"오래 기다렸습니다!");
					SCRIPTMANAGER->pushScript(L"맡아놓은 포켓몬은 \n모두 건강해졌습니다!");
					_npc->setIsGreeting(true);												//간호사 인사
					_centerTalk = CENTER_TALK_NOPE_OR_BYE;
				}
				break;
			}
			case CENTER_TALK_NOPE_OR_BYE:													//치료 안받거나 다받고나서
			{
				_isChoice = false;															//선책창출력X
				centerNopeBye();															//인사스크립트
				_centerTalk = CENTER_TALK_NONE;												//대화를 마치기위해
				break;
			}
			case CENTER_TALK_NONE:															//대화를 종료한다
			{
				PLAYERDATA->getPlayer()->setShopOn(false);
				break;
			}

			default:
				break;
		}

	}
	else if (!_isTalk)												 //되물었을때 재작동되기 위해서 초기화
		_centerTalk = CENTER_TALK_HELLO;

	CAMERA->move(PLAYERDATA->getPlayer()->getPosX(), PLAYERDATA->getPlayer()->getPosY());
}

void centerScene::render()
{
	WCHAR text[128];

	_centerMap->render();
	_obj->render();
	SCRIPTMANAGER->render();
	if (_isTalk)
	{
		swprintf_s(text, L"%d", _choice);
		D2DMANAGER->drawText(text, 500 + CAMERA->getPosX(), 360 + CAMERA->getPosY(), 30);
	}
	if (_isChoice)
	{
		MENUMANAGER->findMenuFrame("choiceFrame")->render();
		swprintf_s(text, L"예");
		D2DMANAGER->drawText(text, 750 + CAMERA->getPosX(), 305 + CAMERA->getPosY(), 35);
		swprintf_s(text, L"아니오");
		D2DMANAGER->drawText(text, 750 + CAMERA->getPosX(), 355 + CAMERA->getPosY(), 35);
		IMAGEMANAGER->findImage("화살표")->render(710 + CAMERA->getPosX(), _curPointY + CAMERA->getPosY());

	}
}

void centerScene::centerHello()
{
	_centerTalk = CENTER_TALK_HEAL;
}

void centerScene::centerHeal()
{
	_isChoice = true;
	if (_choice == CHOICE_YES)							//예 할 경우
	{
		_obj->setIsBallUp(true);						//치료모션준비완료
		_npc->setIsBallUp(true);						//치료모션준비완료
		centerHealing();
	}
	else if (_choice == CHOICE_NO)						//아니오 할 경우
	{
		centerNopeBye();								//끝난다
	}

}

void centerScene::centerHealing()
{
	if (_obj->getIsBallUp())
	{
		wstring text = L"그럼 \n맡아놓겠습니다.";
		SCRIPTMANAGER->pushScript(text);
		_centerTalk = CENTER_TALK_HEALING;
	}
}

void centerScene::centerNopeBye()
{
	{
		_npc->setIsGreeting(false);
		wstring text = L"다음 번에도 \n 방문하시길 기다리겠습니다!";
		SCRIPTMANAGER->pushScript(text);
	}
}