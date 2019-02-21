#pragma once
#include "baseUI.h"
#include "playerDataBase.h"

enum BAG_STATE
{
	ITEM_LIST,
	ITEM_USE_SELECT,
	ITEM_PASS_SELECT,
};
enum ITEM_USE_STATE
{
	ITEM_USE,
	ITEM_PASS,
	ITEM_THROW_AWAY,
	ITEM_STATE_NONE
};
enum ITEM_USE_POKEMON
{
	USE_MAIN_POKEMON,
	USE_SUB_POKEMON1,
	USE_SUB_POKEMON2,
	USE_SUB_POKEMON3,
	USE_SUB_POKEMON4,
	USE_SUB_POKEMON5,
	USE_CANCEL
};
typedef struct tagBagInfo
{
	wstring name;		//아이템 명
	wstring amount;		//아이템 수량
	wstring info;		//아이템 정보
	int type;

	bool _isDataset;
}BAG;

typedef struct tagItemUsePokemon
{
	wstring iD_number;
	wstring name;
	wstring level;
	wstring type;
	wstring item;

	wstring currentHp;
	wstring maxHp;

	bool isDataSet;
}IUPOKEMON;

class bag : public baseUI
{
private:
	
	BAG_STATE _bag_state;
	ITEM_USE_STATE _item_use;

	ITEM_USE_POKEMON _ie_Pokemon; //누구한테 아이템쓸래?
	
	BAG _bag[39];
	IUPOKEMON _iuPokemon[6];
	playerDataBase* _playeritem;

	UINT _currentSelectNum;
	
	UINT _currentitemamount;
	UINT _maxitemamount;

	float _selectNumMoveCount;
	float _selectNumMoveDelay;

	bool _isitemUse;			//아이템 사용할꺼니?

	//====================아이템 사용용 변수들

	int _pokemonCnt; // 보유하고 있는 포켓몬의 수

	// 애니메이션
	animation* _pkAni[6];

public:
	bag();
	~bag();

	HRESULT init();
	void release();
	void update();
	void render();

	void uiOpen();
	void uiClose();

	void uiInfoSet();
	void itemDataSet();

	void keyAni();
	//=====아이템사용을 위한 화면
	void itemUseScreen();

};

