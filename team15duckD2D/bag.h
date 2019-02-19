#pragma once
#include "baseUI.h"
#include "playerDataBase.h"

enum BAG_STATE
{
	ITEM_LIST,
};
enum ITEM_USE_STATE
{
	ITEM_USE,
	ITEM_PASS,
	ITEM_THROW_AWAY,
	ITEM_STATE_NONE
};
typedef struct tagBagInfo
{
	wstring name;		//������ ��
	wstring amount;		//������ ����
	wstring info;		//������ ����
	int type;

	bool _isDataset;
}BAG;

class bag : public baseUI
{
private:
	
	BAG_STATE _bag_state;
	ITEM_USE_STATE _item_use;
	BAG _bag[39];
	playerDataBase* _playeritem;

	UINT _currentSelectNum;
	
	UINT _currentitemamount;
	UINT _maxitemamount;

	float _selectNumMoveCount;
	float _selectNumMoveDelay;

	bool _isitemUse;			//������ ����Ҳ���?

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

};

