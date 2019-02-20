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
	//이거 나중에 옮기자
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
	// 플레이어가 말걸었을때 보는 방향의 반대로 플레이어를 봐야한다.
	//
	//=================================
	setPlayerState(PLAYERDATA->getPlayer()->getState());

	
	//테슷흐버튼
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
		if (_npcType == NPC_TYPE_OAK)
		{
			//if (_isPrologue)
			//{
			//	{
			//		wstring text = L"안녕! \n포켓몬의 세계에 잘 왔다!";
			//		SCRIPTMANAGER->pushScript(text);
			//	}

			//	{
			//		wstring text = L"나는 포켓몬 박사로 존경받는 오박사란다. \n그리고 이 세계에는 포켓몬이라고 ";
			//		SCRIPTMANAGER->pushScript(text);
			//	}

			//	{
			//		wstring text = L"불리는 생명체가 도처에 살고있다! \n사람들은 이 포켓몬이라는 생명체를";
			//		SCRIPTMANAGER->pushScript(text);
			//	}

			//	{
			//		wstring text = L"에완동물로 기르거나 승부를 하지만... \n나는 포켓몬을 전문적으로 연구하고 있지!";
			//		SCRIPTMANAGER->pushScript(text);
			//	}

			//	{
			//		wstring text = L"자... 그러면 이제 너에 대해 알려다오. \n너는 남자아이인가? 여자아이인가?";
			//		SCRIPTMANAGER->pushScript(text);
			//	}

			//	//성별선택 후

			//	{
			//		wstring text = L"너의 이름은 뭐지?";
			//		SCRIPTMANAGER->pushScript(text);
			//	}

			//	//이름선택 후

			//	{
			//		wstring text = L"음...";
			//		//이름추가
			//		text.append(L"(이름)이구나?");
			//		SCRIPTMANAGER->pushScript(text);
			//	}

			//	{
			//		//이름추가
			//		wstring text = L"(이름)!\n";
			//		text.append(L"준비는 되었는가?");
			//		SCRIPTMANAGER->pushScript(text);
			//	}

			//	{
			//		wstring text = L"드디어 이제부터 \n너의 이야기가 시작되어진다.";
			//		SCRIPTMANAGER->pushScript(text);
			//	}

			//	{
			//		wstring text = L"즐거운 것도 괴로운 것도 \n잔뜩 널 기다리고 있을 것이다!";
			//		SCRIPTMANAGER->pushScript(text);
			//	}
			//	{
			//		wstring text = L"꿈과 모험과! 포켓몬스터의 세계로 \n 렛츠 고!";
			//		SCRIPTMANAGER->pushScript(text);
			//	}
			//	//text.clear();
			//	//text = 

			//}
		}
		else if (_npcType == NPC_TYPE_SHOPOWNER)
		{
			{
				wstring text = L"어서오세요! \n무엇을 도와 드릴까요?";
				SCRIPTMANAGER->pushScript(text);
			}

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
		else if (_npcType == NPC_TYPE_NURSE)
		{
			{
				wstring text = L"안녕하세요! \n포켓몬 센터입니다!";
				SCRIPTMANAGER->pushScript(text);
			}
			{
				wstring text = L"이곳에서는 포켓몬의 체력을 회복합니다. \n당신의 포켓몬을 쉬게 하시겠습니까?";
				SCRIPTMANAGER->pushScript(text);
			}

			//선택창 (1. 예 /2. 아니오)
			//1. 예 선택한 경우
			{
				wstring text = L"그럼 \n맡아놓겠습니다.";
				SCRIPTMANAGER->pushScript(text);
			}

			//회복중
			{
				wstring text = L"오래 기다렸습니다!";
				SCRIPTMANAGER->pushScript(text);
			}
			{
				wstring text = L"맡아놓은 포켓몬은 \n모두 건강해졌습니다!";
				SCRIPTMANAGER->pushScript(text);
			}
			//인사 또는 2. 아니오 선택한 경우
			{
				wstring text = L"다음 번에도 \n 방문하시길 기다리겠습니다!";
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
			if (_isBallUp)
			{
				_npcActive = NPC_ACTIVE_WAY_NURSE_LEFT;
				_isReverse = false;
				_motion = KEYANIMANAGER->findAnimation(_npcName, "nurse_Left");
				_motion->start();
				break;
			}
			else if (!_isBallUp)
			{//간호사는 플레이어 방향에 상관없이 오로지 정면이되 치료하는 와중에는 왼쪽도 본다.
				_npcActive = NPC_ACTIVE_WAY_NURSE_DOWN;
				_isReverse = false;
				_motion = KEYANIMANAGER->findAnimation(_npcName, "nurse_Down");
				_motion->start();
				break;
			}
		}
		case NPC_TYPE_BOSS:
		{
			if (_state == _player->PS_IDLE_DOWN) //"플레이어방향이 아래쪽이니"
			{
				_npcActive = NPC_ACTIVE_WAY_BOSS_UP;
				_isReverse = false;
				_motion = KEYANIMANAGER->findAnimation(_npcName, "boss_Up");
				_motion->start();
			}
			else if (_state == _player->PS_IDLE_UP) //"플레이어방향이 위쪽이니"
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


