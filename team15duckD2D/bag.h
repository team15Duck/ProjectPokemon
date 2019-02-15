#pragma once
#include "playerDataBase.h"

typedef struct tagBagInfo
{
	wstring name;		//아이템 명
	wstring amount;		//아이템 수량
	wstring info;		//아이템 정보

	bool _isDataset;
}BAG;

class bag
{
private:
	BAG _bag[39];
	playerDataBase* _playeritem;

	UINT _currentSelectNum;
	
	UINT _currentitemamount;
	UINT _maxitemamount;

	float _selectNumMoveCount;
	float _selectNumMoveDelay;


public:
	bag();
	~bag();

	HRESULT init();
	void release();
	void update();
	void render();

	void itemDataSet();

};

