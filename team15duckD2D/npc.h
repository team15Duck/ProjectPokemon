#pragma once
#include "player.h"

enum NPC_TYPE
{
	NPC_TYPE_OAK,										  //오박사
	NPC_TYPE_SHOPOWNER,									  //상점주인
	NPC_TYPE_NURSE,										  //간호사
	NPC_TYPE_BOSS,										  //비주기
		
	NPC_TYPE_NONE,
	NPC_TYPE_COUNT = NPC_TYPE_NONE
};

enum NPC_ACTIVE_WAY
{
	NPC_ACTIVE_WAY_OAK_DOWN,								//오박사(아래쪽)
	NPC_ACTIVE_WAY_OAK_RIGHT,								//오박사(오른쪽)
	NPC_ACTIVE_WAY_OAK_LEFT,								//오박사(왼쪽)	
	NPC_ACTIVE_WAY_OAK_UP,									//오박사(위쪽)
										
	NPC_ACTIVE_WAY_SHOPOWNER_DOWN,							//상점주인(아래쪽)
	NPC_ACTIVE_WAY_SHOPOWNER_RIGHT,							//상점주인(오른쪽)
										
	NPC_ACTIVE_WAY_NURSE_DOWN,								//간호사(아래쪽)
	NPC_ACTIVE_WAY_NURSE_LEFT,								//간호사(왼쪽)
	NPC_ACTIVE_WAY_NURSE_GREETING,							//간호사(인사)

	NPC_ACTIVE_WAY_BOSS_DOWN,								//보스(아래쪽)
	NPC_ACTIVE_WAY_BOSS_UP,									//보스(위쪽)
	NPC_ACTIVE_WAY_BOSS_LEFT,								//보스(왼쪽)
	NPC_ACTIVE_WAY_BOSS_RIGHT,								//보스(오른쪽)

	NPC_ACTIVE_WAY_NONE,
	NPC_ACTIVE_WAY_COUNT = NPC_ACTIVE_WAY_NONE
};


class npc
{
private:

	//대사는 우선 벡터로 넣어보자.


	string					_sceneName;						//등장할 씬이름
	string					_npcName;						//npc이름(키값용)
	NPC_TYPE				_npcType;						//npc종류
	NPC_ACTIVE_WAY			_npcActive;						//플레이어가 npc에게 말걸었을때 방향

	UINT					_tileX;							//위치
	UINT					_tileY;							//위치

	bool					_isTalk;						//플레이어가 말걸었는지?
	bool					_isPrologue;					//오박사용 첫 시작이니?
	bool					_isReverse;						//상점주인용 좌우반전했니?
	bool					_isGreeting;					//간호사용 인사모션

	animation*				_motion;						//실행중인 애니메이션
	bool					_isBallUp;

	player::PLAYER_STATE	_state;
	player*					_player;


public:
	npc();
	~npc();

	HRESULT init(NPC_TYPE type);
	void release();
	void update();
	void render();

	void activeDialog();							//NPC대사설정
	void activeWay();								//NPC방향설정
	
	void setPlayerState(player::PLAYER_STATE state) { _state = state; }

	




	//NPC위치
	UINT getTileX() { return _tileX; }
	UINT getTileY() { return _tileY; }

	//NPC랑 말했니?
	bool getIsTalk() { return _isTalk; }
	void setIsTalk(bool talk) { _isTalk = talk; }

	bool getIsBallUp() { return _isBallUp; }
	void setIsBallUp(bool ballUp) { _isBallUp = ballUp; }

	bool getIsGreeting() { return _isGreeting; }
	void setIsGreeting(bool greeting) { _isGreeting = greeting; }
};

