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

	_isTalk = PLAYERDATA->getPlayer()->getShopOn();					//�÷��̾����� bool���� �޾ƿ´�.
	_npc->setIsTalk(_isTalk);

	if (_isTalk)													//������Ʈ&NPC �۵�
	{
		_obj->update();
		_npc->update();
	}

	if (_isTalk)																			//�÷��̾ ���ɾ���?
	{

		switch (_centerTalk)
		{
			case CENTER_TALK_HELLO:															//��ȣ�� �λ�
			{
				SCRIPTMANAGER->pushScript(L"�ȳ��ϼ���! \n���ϸ� �����Դϴ�!");
				centerHello();
				break;
			}
			case CENTER_TALK_HEAL:															//ġ�Ῡ��(���⼭ ����â)
			{
				SCRIPTMANAGER->pushScript(L"�̰������� ���ϸ��� ü���� ȸ���մϴ�. \n����� ���ϸ��� ���� �Ͻðڽ��ϱ�?");
				centerHeal();
				break;
			}
			case CENTER_TALK_HEALING:														//ġ����(������Ʈ&NPC������ ����)
			{
				_isChoice = false;															//����â���X
				if (_obj->getTime() <= 0)													//������Ʈ���� ������ �ð��� 0���ϸ�
				{
					_npc->setIsBallUp(false);												//����������
					_obj->setIsBallUp(false);												//����������
					SCRIPTMANAGER->pushScript(L"���� ��ٷȽ��ϴ�!");
					SCRIPTMANAGER->pushScript(L"�þƳ��� ���ϸ��� \n��� �ǰ��������ϴ�!");
					_npc->setIsGreeting(true);												//��ȣ�� �λ�
					_centerTalk = CENTER_TALK_NOPE_OR_BYE;
				}
				break;
			}
			case CENTER_TALK_NOPE_OR_BYE:													//ġ�� �ȹްų� �ٹް���
			{
				_isChoice = false;															//��åâ���X
				centerNopeBye();															//�λ罺ũ��Ʈ
				_centerTalk = CENTER_TALK_NONE;												//��ȭ�� ��ġ������
				break;
			}
			case CENTER_TALK_NONE:															//��ȭ�� �����Ѵ�
			{
				PLAYERDATA->getPlayer()->setShopOn(false);
				break;
			}

			default:
				break;
		}

	}
	else if (!_isTalk)												 //�ǹ������� ���۵��Ǳ� ���ؼ� �ʱ�ȭ
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
		swprintf_s(text, L"��");
		D2DMANAGER->drawText(text, 750 + CAMERA->getPosX(), 305 + CAMERA->getPosY(), 35);
		swprintf_s(text, L"�ƴϿ�");
		D2DMANAGER->drawText(text, 750 + CAMERA->getPosX(), 355 + CAMERA->getPosY(), 35);
		IMAGEMANAGER->findImage("ȭ��ǥ")->render(710 + CAMERA->getPosX(), _curPointY + CAMERA->getPosY());

	}
}

void centerScene::centerHello()
{
	_centerTalk = CENTER_TALK_HEAL;
}

void centerScene::centerHeal()
{
	_isChoice = true;
	if (_choice == CHOICE_YES)							//�� �� ���
	{
		_obj->setIsBallUp(true);						//ġ�����غ�Ϸ�
		_npc->setIsBallUp(true);						//ġ�����غ�Ϸ�
		centerHealing();
	}
	else if (_choice == CHOICE_NO)						//�ƴϿ� �� ���
	{
		centerNopeBye();								//������
	}

}

void centerScene::centerHealing()
{
	if (_obj->getIsBallUp())
	{
		wstring text = L"�׷� \n�þƳ��ڽ��ϴ�.";
		SCRIPTMANAGER->pushScript(text);
		_centerTalk = CENTER_TALK_HEALING;
	}
}

void centerScene::centerNopeBye()
{
	{
		_npc->setIsGreeting(false);
		wstring text = L"���� ������ \n �湮�Ͻñ� ��ٸ��ڽ��ϴ�!";
		SCRIPTMANAGER->pushScript(text);
	}
}