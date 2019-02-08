#pragma once
#include "gameNode.h"

enum ITEM_TYPE
{
	//포켓몬은 현재 체력이 30퍼 미만이면 무조건 잡히고
	//그 이상이면 포켓몬볼의 포획률에 따라 잡힌다.
	MONSTER_BALL,			//몬스터볼
	SUPER_BALL,				//슈퍼볼
	HYPER_BALL,				//하이퍼볼
	MASTER_BALL,			//마스터볼
						   
	NORMAL_POTION,			//상처약(20회복)
	SUPER_POTION,			//좋은상처약(60회복)
	HYPER_POTION,			//고급상처약(120회복)
	MAX_POTION,				//풀회복약(전체회복)
	FULL_RESTORE,			//회복약(전체회복+상태이상)

	NORMAL_ETHER,			//PP회복(한기술 10회복)
	MAX_ETHER,				//pp회복(한기술 전체회복)
	NORMAL_ELIXIR,			//pp회복(모든기술 10회복)
	MAX_ELIXIR,				//pp회복(모든기술 전체회복)

	ANTIDOTE,				//해독제
	PARLYZE_HEAL,			//마비해독제
	BURN_HEAL,				//화상치료제
	ICE_HEAL,				//동상치료제
	AWAKENING,				//잠깨는약
	FULL_HEAL,				//전체상태이상				

	
	RARE_CANDY,				//이상한캔디
	BICYCLE,				//자전거
	FISHING_ROD,			//낚시대
	TOWN_MAP,				//타운맵
	TM_CASE					//기술머신케이스


};


class item : public gameNode
{
private:
	
	image*		_img;			//이미지
	RECT		_rc;			//렉트
	string		_itemName;		//아이템이름
	ITEM_TYPE	_itemType;		//종류
	int			_itemValue;		//아이템적용값(회복값, pp회복값, 포획률 등)
	int			_itemNum;		//개수
	int			_frameNum;		//프레임번호


public:
	item();
	~item();

	HRESULT init();
	HRESULT init(int value, ITEM_TYPE type);
	void release();
	void update();
	void render();
	
	void initImg();



	// ========== GET & SET ==========
	string getItemName() { return _itemName; }
	void setItemName(string name) { _itemName = name; }

	ITEM_TYPE getItemType() { return _itemType; }
	void setItemType(ITEM_TYPE type) { _itemType = type; }

	int getItemValue() { return _itemValue; }
	void setItemValue(int value) { _itemValue = value; }

	int getItemNum() { return _itemNum; }
	void setItemNum(int num) { _itemNum = num; }
};

