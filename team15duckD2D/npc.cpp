#include "stdafx.h"
#include "npc.h"


npc::npc()
{
}


npc::~npc()
{
}

HRESULT npc::init(NPC_TYPE type)
{
	//�̰� ���߿� �ű���
	IMAGEMANAGER->addFrameImage("oak", L"image/oak.png", 720, 85, 12, 1);
	IMAGEMANAGER->addFrameImage("boss", L"image/boss.png", 576, 80, 9, 1);
	_npcType = type;
	switch (type)
	{
		case NPC_TYPE_OAK:
		{
			_sceneName = "oLabScene";
			_npcName = "oak";
			_isTalk = false;
			_isPrologue = true;
			_isReverse = false;
			_tileX = 16 * 64;
			_tileY = 10 * 64 - 20;
			KEYANIMANAGER->addAnimationType(_npcName);
			int oak_Down[] = { 0 };
			KEYANIMANAGER->addArrayFrameAnimation(_npcName, "oak_Down", "oak", oak_Down, 1, 10, true);
			int oak_Right[] = { 1 };
			KEYANIMANAGER->addArrayFrameAnimation(_npcName, "oak_Right", "oak", oak_Right, 1, 10, true);
			int oak_Left[] = { 2 };
			KEYANIMANAGER->addArrayFrameAnimation(_npcName, "oak_Left", "oak", oak_Left, 1, 10, true);
			int oak_Up[] = { 3 };
			KEYANIMANAGER->addArrayFrameAnimation(_npcName, "oak_Up", "oak", oak_Up, 1, 10, true);

			_motion = KEYANIMANAGER->findAnimation(_npcName, "oak_Down");

			break;
		}
		case NPC_TYPE_SHOPOWNER:
		{
			_sceneName = "storeScene";
			_npcName = "shopOwner";
			_isTalk = false;
			_isPrologue = false;
			_isReverse = true;
			_tileX = 12 * 64;
			_tileY = 10 * 64 - 20;
			KEYANIMANAGER->addAnimationType(_npcName);
			int shopOwner_Down[] = { 0 };
			KEYANIMANAGER->addArrayFrameAnimation(_npcName, "shopOwner_Down", "shopOwner", shopOwner_Down, 1, 10, true);
			int shopOwner_Right[] = { 2 };
			KEYANIMANAGER->addArrayFrameAnimation(_npcName, "shopOwner_Right", "shopOwner", shopOwner_Right, 1, 10, true);

			_motion = KEYANIMANAGER->findAnimation(_npcName, "shopOwner_Right");
			break;
		}
		case NPC_TYPE_NURSE:
		{
			_sceneName = "centerScene";
			_npcName = "nurse";
			_isTalk = false;
			_isPrologue = false;
			_isReverse = false;
			_tileX = 17 * 64;
			_tileY = 9 * 64 - 20;

			KEYANIMANAGER->addAnimationType(_npcName);
			int nurse_Down[] = { 0 };
			KEYANIMANAGER->addArrayFrameAnimation(_npcName, "nurse_Down", "nurse", nurse_Down, 1, 10, true);
			int nurse_Left[] = { 2 };
			KEYANIMANAGER->addArrayFrameAnimation(_npcName, "nurse_Left", "nurse", nurse_Left, 1, 10, true);
			int nurse_Greeting[] = { 3 };
			KEYANIMANAGER->addArrayFrameAnimation(_npcName, "nurse_Greeting", "nurse", nurse_Greeting, 1, 10, false);

			_motion = KEYANIMANAGER->findAnimation(_npcName, "nurse_Down");
			break;
		}
		case NPC_TYPE_BOSS:
		{
			_sceneName = "gymScene";
			_npcName = "boss";
			_isTalk = false;
			_isPrologue = false;
			_isReverse = false;
			_tileX = 16 * 64;
			_tileY = 13 * 64 - 41;

			KEYANIMANAGER->addAnimationType(_npcName);
			int boss_Down[] = { 0 };
			KEYANIMANAGER->addArrayFrameAnimation(_npcName, "boss_Down", "boss", boss_Down, 1, 10, true);
			int boss_Up[] = { 1 };
			KEYANIMANAGER->addArrayFrameAnimation(_npcName, "boss_Up", "boss", boss_Up, 1, 10, true);
			int boss_Left[] = { 2 };
			KEYANIMANAGER->addArrayFrameAnimation(_npcName, "boss_Left", "nurse", boss_Left, 1, 10, true);
			int boss_Right[] = { 2 };
			KEYANIMANAGER->addArrayFrameAnimation(_npcName, "boss_Right", "nurse", boss_Right, 1, 10, true);

			_motion = KEYANIMANAGER->findAnimation(_npcName, "boss_Down");
			break;
		}
		default:
			break;
	}
	_isBallUp = false;

	return S_OK;
}

void npc::release()
{
}

void npc::update()
{
	//=================================
	//
	// �÷��̾ ���ɾ����� ���� ������ �ݴ�� �÷��̾ �����Ѵ�.
	//
	//=================================
	setPlayerState(PLAYERDATA->getPlayer()->getState());

	
	//�׽����ư
	if (KEYMANAGER->isOnceKeyDown(VK_F8))
	{
		_isTalk = true;
	}
	if (_isTalk)
	{
		if (_npcType == NPC_TYPE_OAK)
		{
			activeWay();
		}
		else if (_npcType == NPC_TYPE_SHOPOWNER)
		{
			activeWay();
		}
		else if(_npcType == NPC_TYPE_NURSE)
		{
			activeWay();
			activeDialog();
		}
		else if (_npcType == NPC_TYPE_BOSS)
		{
			activeWay();
			//activeDialog();
		}
	}
	

	
}

void npc::render()
{
	//�������ο�
	if (_isReverse)
		IMAGEMANAGER->findImage(_npcName)->aniRenderReverseX(_tileX, _tileY, _motion);
	else
		IMAGEMANAGER->findImage(_npcName)->aniRender(_tileX, _tileY, _motion);



}

void npc::activeDialog()
{
	if (_isTalk)
	{
		if (_npcType == NPC_TYPE_OAK)
		{
			//if (_isPrologue)
			//{
			//	{
			//		wstring text = L"�ȳ�! \n���ϸ��� ���迡 �� �Դ�!";
			//		SCRIPTMANAGER->pushScript(text);
			//	}

			//	{
			//		wstring text = L"���� ���ϸ� �ڻ�� ����޴� ���ڻ����. \n�׸��� �� ���迡�� ���ϸ��̶�� ";
			//		SCRIPTMANAGER->pushScript(text);
			//	}

			//	{
			//		wstring text = L"�Ҹ��� ����ü�� ��ó�� ����ִ�! \n������� �� ���ϸ��̶�� ����ü��";
			//		SCRIPTMANAGER->pushScript(text);
			//	}

			//	{
			//		wstring text = L"���ϵ����� �⸣�ų� �ºθ� ������... \n���� ���ϸ��� ���������� �����ϰ� ����!";
			//		SCRIPTMANAGER->pushScript(text);
			//	}

			//	{
			//		wstring text = L"��... �׷��� ���� �ʿ� ���� �˷��ٿ�. \n�ʴ� ���ھ����ΰ�? ���ھ����ΰ�?";
			//		SCRIPTMANAGER->pushScript(text);
			//	}

			//	//�������� ��

			//	{
			//		wstring text = L"���� �̸��� ����?";
			//		SCRIPTMANAGER->pushScript(text);
			//	}

			//	//�̸����� ��

			//	{
			//		wstring text = L"��...";
			//		//�̸��߰�
			//		text.append(L"(�̸�)�̱���?");
			//		SCRIPTMANAGER->pushScript(text);
			//	}

			//	{
			//		//�̸��߰�
			//		wstring text = L"(�̸�)!\n";
			//		text.append(L"�غ�� �Ǿ��°�?");
			//		SCRIPTMANAGER->pushScript(text);
			//	}

			//	{
			//		wstring text = L"���� �������� \n���� �̾߱Ⱑ ���۵Ǿ�����.";
			//		SCRIPTMANAGER->pushScript(text);
			//	}

			//	{
			//		wstring text = L"��ſ� �͵� ���ο� �͵� \n�ܶ� �� ��ٸ��� ���� ���̴�!";
			//		SCRIPTMANAGER->pushScript(text);
			//	}
			//	{
			//		wstring text = L"�ް� �����! ���ϸ����� ����� \n ���� ��!";
			//		SCRIPTMANAGER->pushScript(text);
			//	}
			//	//text.clear();
			//	//text = 

			//}
		}
		else if (_npcType == NPC_TYPE_SHOPOWNER)
		{
			{
				wstring text = L"�������! \n������ ���� �帱���?";
				SCRIPTMANAGER->pushScript(text);
			}

			//����â ( 1. �緯�Դ� / 2. �ȷ��Դ� / 3. �ƴմϴ�)

			//1. �緯�Դ� ����������
			{
				wstring text = L"(������)(��)�� \n�� �� �����Ͻðڽ��ϱ�?";
				SCRIPTMANAGER->pushScript(text);
			}
			//��������
			{
				wstring text = L"(������) (����)�α���. \n�� (�ݾ�)���ϴ�.";
				SCRIPTMANAGER->pushScript(text);
			}
			{
				wstring text = L"�� ���� �ֽ��ϴ�. \n����� �����մϴ�.";
				SCRIPTMANAGER->pushScript(text);
			}

			//2. �ȷ��Դ� ���������� 
			{
				wstring text = L"(������)(��)�� \n �� �� �Ľðڽ��ϱ�?";
				SCRIPTMANAGER->pushScript(text);
			}
			//��������
			{
				wstring text = L"(������) (����)�α���. �� (�ݾ�)���Դϴ�.";
				SCRIPTMANAGER->pushScript(text);
			}
			{
				wstring text = L"(������)(��)�� �޾� (�ݾ�)���� ��Ƚ��ϴ�.";
				SCRIPTMANAGER->pushScript(text);
			}

			//1,2������ ��ҹ�ư ��������
			{
				wstring text = L"�� �ۿ� ���� \n�� ���͵帱 �� �����ϱ�?";
				SCRIPTMANAGER->pushScript(text);
			}

			//3. �ƴմϴ�.
			{
				wstring text = L"�� ������!";
				SCRIPTMANAGER->pushScript(text);
			}
		}
		else if (_npcType == NPC_TYPE_NURSE)
		{
			{
				wstring text = L"�ȳ��ϼ���! \n���ϸ� �����Դϴ�!";
				SCRIPTMANAGER->pushScript(text);
			}
			{
				wstring text = L"�̰������� ���ϸ��� ü���� ȸ���մϴ�. \n����� ���ϸ��� ���� �Ͻðڽ��ϱ�?";
				SCRIPTMANAGER->pushScript(text);
			}

			//����â (1. �� /2. �ƴϿ�)
			//1. �� ������ ���
			{
				wstring text = L"�׷� \n�þƳ��ڽ��ϴ�.";
				SCRIPTMANAGER->pushScript(text);
			}

			//ȸ����
			{
				wstring text = L"���� ��ٷȽ��ϴ�!";
				SCRIPTMANAGER->pushScript(text);
			}
			{
				wstring text = L"�þƳ��� ���ϸ��� \n��� �ǰ��������ϴ�!";
				SCRIPTMANAGER->pushScript(text);
			}
			//�λ� �Ǵ� 2. �ƴϿ� ������ ���
			{
				wstring text = L"���� ������ \n �湮�Ͻñ� ��ٸ��ڽ��ϴ�!";
				SCRIPTMANAGER->pushScript(text);
			}
		}
	}

}

void npc::activeWay()
{
	switch (_npcType)
	{
		case NPC_TYPE_OAK:
		{
			if (_state == _player->PS_IDLE_RIGHT) //"�÷��̾������ �������̴�"
			{
				_npcActive = NPC_ACTIVE_WAY_OAK_LEFT;
				_isReverse = false;
				_motion = KEYANIMANAGER->findAnimation(_npcName, "oak_Left");
				_motion->start();
			}
			else if (_state == _player->PS_IDLE_LEFT) //"�÷��̾������ �����̴�"
			{
				_npcActive = NPC_ACTIVE_WAY_OAK_RIGHT;
				_isReverse = false;
				_motion = KEYANIMANAGER->findAnimation(_npcName, "oak_Right");
				_motion->start();
			}
			else if (_state == _player->PS_IDLE_DOWN) //"�÷��̾������ �Ʒ����̴�"
			{
				_npcActive = NPC_ACTIVE_WAY_OAK_UP;
				_isReverse = false;
				_motion = KEYANIMANAGER->findAnimation(_npcName, "oak_Up");
				_motion->start();
			}
			else if (_state == _player->PS_IDLE_UP) //"�÷��̾������ �����̴�"
			{
				_npcActive = NPC_ACTIVE_WAY_OAK_DOWN;
				_isReverse = false;
				_motion = KEYANIMANAGER->findAnimation(_npcName, "oak_Down");
				_motion->start();
			}
			break;
		}
		case NPC_TYPE_SHOPOWNER:
		{
			if (_state == _player->PS_IDLE_LEFT) //"�÷��̾������ �����̴�"
			{
				_npcActive = NPC_ACTIVE_WAY_SHOPOWNER_RIGHT;
				_isReverse = true;
				_motion = KEYANIMANAGER->findAnimation(_npcName, "shopOwner_Right");
				_motion->start();
			}
			else if (_state == _player->PS_IDLE_UP) //"�÷��̾������ �����̴�"
			{
				_npcActive = NPC_ACTIVE_WAY_SHOPOWNER_DOWN;
				_isReverse = false;
				_motion = KEYANIMANAGER->findAnimation(_npcName, "shopOwner_Down");
				_motion->start();
			}
			break;
		}
		case NPC_TYPE_NURSE:
		{
			if (_isBallUp)
			{
				_npcActive = NPC_ACTIVE_WAY_NURSE_LEFT;
				_isReverse = false;
				_motion = KEYANIMANAGER->findAnimation(_npcName, "nurse_Left");
				_motion->start();
				break;
			}
			else if (!_isBallUp)
			{//��ȣ��� �÷��̾� ���⿡ ������� ������ �����̵� ġ���ϴ� ���߿��� ���ʵ� ����.
				_npcActive = NPC_ACTIVE_WAY_NURSE_DOWN;
				_isReverse = false;
				_motion = KEYANIMANAGER->findAnimation(_npcName, "nurse_Down");
				_motion->start();
				break;
			}
		}
		case NPC_TYPE_BOSS:
		{
			if (_state == _player->PS_IDLE_DOWN) //"�÷��̾������ �Ʒ����̴�"
			{
				_npcActive = NPC_ACTIVE_WAY_BOSS_UP;
				_isReverse = false;
				_motion = KEYANIMANAGER->findAnimation(_npcName, "boss_Up");
				_motion->start();
			}
			else if (_state == _player->PS_IDLE_UP) //"�÷��̾������ �����̴�"
			{
				_npcActive = NPC_ACTIVE_WAY_BOSS_DOWN;
				_isReverse = false;
				_motion = KEYANIMANAGER->findAnimation(_npcName, "boss_Down");
				_motion->start();
			}
			break;
		}
		default:
			break;
	}
}


