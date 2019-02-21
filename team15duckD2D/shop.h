#pragma once
#include "item.h"
class shop
{
private:

	wstring			_money;		//플레이어돈
	wstring			_itemInfo[39];  //아이템정보
	wstring			_itemName[39];
	UINT			_itemBuyPrice[39];
	UINT			_itemSellPrice[39];
	UINT			_itemNum;	//아이템개수

	vector<item*>	_shopItems;	//판매할 아이템

	UINT			_curItem;	//현재 선택한 아이템
	float			_curPointY;	//현재 화살표 Y위치(아이템)
	float			_surePointY;//현재 화살표 Y위치(예/아니오)

	bool			_isBuy;		//카메라 이동용
	bool			_isNumber;	//몇개살거니?
	bool			_isSure;	//진짜살거니?

public:
	shop();
	~shop();

	HRESULT init();
	void release();
	void update();
	void render();

	void initItems();
	void itemInfoSetting();



	bool getIsBuy() { return _isBuy; }
	void setIsBuy(bool buy) { _isBuy = buy; }

	wstring getItemInfo() { return _itemInfo[_curItem]; }
	wstring getItemName() { return _itemName[_curItem]; }
	UINT getItemBuyPrice() { return _itemBuyPrice[_curItem]; }
	UINT getItemSellPrice() { return _itemSellPrice[_curItem]; }
	UINT getItemNum() { return _itemNum; }
};

