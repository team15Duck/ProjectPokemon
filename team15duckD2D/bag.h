#pragma once
#include "baseUI.h"
#include "playerDataBase.h"

enum BAG_STATE
{
	ITEM_UNUSE,
	ITEM_USE  
};
typedef struct tagBagInfo
{
	wstring name;		//아이템 명
	wstring amount;		//아이템 수량
	wstring info;		//아이템 정보
	int type;

	bool _isDataset;
}BAG;

class bag : public baseUI
{
private:
	BAG _bag[39];
	playerDataBase* _playeritem;

	UINT _currentSelectNum;
	
	UINT _currentitemamount;
	UINT _maxitemamount;

	float _selectNumMoveCount;
	float _selectNumMoveDelay;

	bool _isitemUse;			//아이템 사용할꺼니?

public:
	bag();
	~bag();

	HRESULT init();
	void release();
	void update();
	void render();

	void itemDataSet();

};

