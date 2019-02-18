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
	//_player = new player;
	//_player->init();
	//이거 나중에 옮기자
	IMAGEMANAGER->addFrameImage("oak", L"image/oak.png", 720, 85, 12, 1);
	_npcType = type;
	switch (type)
	{
		case NPC_TYPE_OAK:
		{
			_sceneName = "mapTestScene";
			_npcName = "oak";
			_isTalk = false;
			_isPrologue = true;
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
			_sceneName = "caveScene";
			_npcName = "shopOwner";
			_isTalk = false;
			_isPrologue = false;
			_tileX = 16 * 64;
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
			_sceneName = "mapTestScene";
			_npcName = "nurse";
			_isTalk = false;
			_isPrologue = false;

			KEYANIMANAGER->addAnimationType(_npcName);
			int nurse_Down[] = { 0 };
			KEYANIMANAGER->addArrayFrameAnimation(_npcName, "nurse_Down", "nurse", nurse_Down, 1, 10, true);
			int nurse_Left[] = { 2 };
			KEYANIMANAGER->addArrayFrameAnimation(_npcName, "nurse_Left", "nurse", nurse_Left, 1, 10, true);
			int nurse_Greeting[] = { 3 };
			KEYANIMANAGER->addArrayFrameAnimation(_npcName, "nurse_Greeting", "nurse", nurse_Greeting, 1, 10, false);

			_motion = KEYANIMANAGER->findAnimation(_npcName, "nurse_Right");
			break;
		}
		default:
			break;
	}

	_isReverse = false;
	_test = 0;

	return S_OK;
}

void npc::release()
{
}

void npc::update()
{
	//=================================
	//
	// 플레이어가 말걸었을때 보는 방향의 반대로 플레이어를 봐야한다.
	//
	//=================================
	
	//테슷흐
	if (KEYMANAGER->isOnceKeyDown(VK_F9))
	{
		_isTalk = true;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_F9))
	{
		_isTalk = false;
	}
	if(_isTalk)
		activeWay();

}

void npc::render()
{
	//상점주인용
	if (_isReverse)
		IMAGEMANAGER->findImage(_npcName)->aniRenderReverseX(_tileX, _tileY, _motion);
	else
		IMAGEMANAGER->findImage(_npcName)->aniRender(_tileX, _tileY, _motion);

}

void npc::activeDialog()
{
	if (_isTalk)
	{
		if (_npcName == "oak")
		{
			if (_isPrologue)
			{
				wstring text = L"안녕! \n 포켓몬의 세계에 잘 왔다!";
				SCRIPTMANAGER->pushScript(text);
			}
		}
		else if (_npcName == "shopOwner")
		{

		}
		else if (_npcName == "nurse")
		{


		}
	}

}

void npc::activeWay()
{
	switch (_npcType)
	{
		case NPC_TYPE_OAK:
		{
			if (_state == _player->PS_IDLE_RIGHT) //"플레이어방향이 오른쪽이니"
			{
				_npcActive = NPC_ACTIVE_WAY_OAK_LEFT;
				_isReverse = false;
				_motion = KEYANIMANAGER->findAnimation(_npcName, "oak_Left");
				_motion->start();
			}
			else if (_state == _player->PS_IDLE_LEFT) //"플레이어방향이 왼쪽이니"
			{
				_npcActive = NPC_ACTIVE_WAY_OAK_RIGHT;
				_isReverse = false;
				_motion = KEYANIMANAGER->findAnimation(_npcName, "oak_Right");
				_motion->start();
			}
			else if (_state == _player->PS_IDLE_DOWN) //"플레이어방향이 아래쪽이니"
			{
				_npcActive = NPC_ACTIVE_WAY_OAK_UP;
				_isReverse = false;
				_motion = KEYANIMANAGER->findAnimation(_npcName, "oak_Up");
				_motion->start();
			}
			else if (_state == _player->PS_IDLE_UP) //"플레이어방향이 위쪽이니"
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
			if (_state == _player->PS_IDLE_LEFT) //"플레이어방향이 왼쪽이니"
			{
				_npcActive = NPC_ACTIVE_WAY_SHOPOWNER_RIGHT;
				_isReverse = true;
				_motion = KEYANIMANAGER->findAnimation(_npcName, "shopOwner_Right");
				_motion->start();
			}
			else if (_state == _player->PS_IDLE_UP) //"플레이어방향이 위쪽이니"
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
			//간호사는 플레이어 방향에 상관없이 오로지 정면이되 치료하는 와중에는 왼쪽도 본다.
			_npcActive = NPC_ACTIVE_WAY_NURSE_DOWN;
			_isReverse = true;
			_motion = KEYANIMANAGER->findAnimation(_npcName, "nurse_Down");
			_motion->start();
			break;
		}
		default:
			break;
	}
}
