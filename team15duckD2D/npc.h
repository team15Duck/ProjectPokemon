#pragma once

enum NPC_TYPE
{
	NPC_TYPE_OAK,										  //오박사
	NPC_TYPE_SHOPOWNER,									  //상점주인
	NPC_TYPE_NURSE,										  //간호사
		
	NPC_TYPE_NONE,
	NPC_TYPE_COUNT = NPC_TYPE_NONE
};

enum NPC_ACTIVE
{
	NPC_ACTIVE_OAK_LEFT,									//오박사(왼쪽)
	NPC_ACTIVE_OAK_RIGHT,									//오박사(오른쪽)
	NPC_ACTIVE_OAK_UP,										//오박사(위쪽)
	NPC_ACTIVE_OAK_DOWN,									//오박사(아래쪽)
															
	NPC_ACTIVE_SHOPOWNER_RIGHT,								//상점주인(오른쪽)
	NPC_ACTIVE_SHOPOWNER_DOWN,								//상점주인(아래쪽)
															
	NPC_ACTIVE_NURSE_LEFT,									//간호사(왼쪽)
	NPC_ACTIVE_NURSE_DOWN,									//간호사(아래쪽)
	
	NPC_ACTIVE_NONE,
	NPC_ACTIVE_COUNT = NPC_ACTIVE_NONE
};


class npc
{
private:

	//대사는 우선 벡터로 넣어보자.


	string		_sceneName;						//등장할 씬이름
	string		_npcName;						//npc이름(키값용)
	NPC_TYPE	_npcType;						//npc종류
	NPC_ACTIVE	_npcActive;						//플레이어가 npc에게 말걸었을때 방향



	UINT		_tileX;							//위치
	UINT		_tileY;							//위치



public:
	npc();
	~npc();

	HRESULT init(string sceneName);
	void release();
	void update();
	void render();

	void settingNPC();
};

