#pragma once
#include "storeMap.h"
#include "gameNode.h"
#include "npc.h"

enum SHOP_TALK
{
	//1. 사러왔다
	SHOP_TALK_BUY_CHOICE,						//아이템을 선택했을때
	SHOP_TALK_BUY,								//개수까지 정했을때
	SHOP_TALK_BUY_SURE,							//구입함
	
	//2. 팔러왔다
	SHOP_TALK_SELL_CHOICE,						//아이템을 선택했을때
	SHOP_TALK_SELL,								//개수까지 정했을때
	SHOP_TALK_SELL_SURE,						//판매함
	
	//3. 아닙니다
	SHOP_TALK_NOPE,								//나갈때

	//4. 이전버튼
	SHOP_TALK_CANCEL,							//1. 사러왔다 / 2. 팔러왔다에서
												//이전버튼 눌렀을때
	SHOP_TALK_NONE,
	SHOP_TALK_COUNT = SHOP_TALK_NONE
};


class storeScene : public gameNode
{
private:
	mapData*	_storeMap;						//스토어맵
	npc*		_npc;							//NPC
												
	bool		_isTalk;						//NPC랑 얘기하니
	bool		_isVisible;						//대사 가리기용
	SHOP_TALK	_shopTalk;						//상태

public:
	storeScene();
	~storeScene();

	HRESULT init();
	void release();
	void update();
	void render();

	//상점주인 대화 정리용
	void activeShopOwner();


	//1. 사러왔다
	void buyItemChoice();						//구입할 아이템을 선택하고 개수 물어볼때
	void buyItem();								//사는 아이템, 몇 개 살 것이며 총 얼마이다.
	void buyItemSure();							//구입이 확정되었을때


	//2. 팔러왔다.
	void sellItemChoice();						//판매할 아이템을 선택하고 개수 물어볼때
	void sellItem();							//파는 아이템, 몇 개 살 것이며 총 얼마이다.
	void sellItemSure();						//판매가 확정되었을때

	
	//3. 이전버튼 (X버튼 눌렀을때)
	void menuBack();
	
	//4. 아닙니다
	void nopeTalk();

};

