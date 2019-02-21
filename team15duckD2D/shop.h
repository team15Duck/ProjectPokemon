#pragma once
#include "item.h"
enum CHOICE_SHOP
{
	CHOICE_SHOP_YES,
	CHOICE_SHOP_NO
};

class shop
{
	
private:

	wstring				_itemInfo[39];			//아이템정보
	wstring				_itemName[39];			//아이템이름
	UINT				_itemBuyPrice[39];		//아이템구입가격
	UINT				_itemSellPrice[39];		//아이템판매가격
	UINT				_itemNum;				//아이템개수
	ITEM_TYPE			_itemType;				//아이템타입
	CHOICE_SHOP			_choice;				//예/아니오 선택

	vector<item*>		_shopItems;				//판매할 아이템

	UINT				_curItem;				//현재 선택한 아이템
	float				_curPointY;				//현재 화살표 Y위치(아이템)
	float				_surePointY;			//현재 화살표 Y위치(예/아니오)

	bool				_isBuy;					//사는중이니?
	bool				_isNumber;				//몇개고르는중이니?
	bool				_isSure;				//진짜살거니?
	bool				_isHaveMoney;			//돈있니?
	bool				_exit;					//상점UI나감

	bool				_isChoice;				//살거니 팔거니 아니니
public:
	shop();
	~shop();

	HRESULT init();
	void release();
	void update();
	void render();

	void initItems();
	void itemInfoSetting();
	void keyControl();



	bool getIsBuy() { return _isBuy; }
	void setIsBuy(bool buy) { _isBuy = buy; }

	bool getIsNumber() { return _isNumber; }
	void setIsNumber(bool num) { _isNumber = num; }

	wstring getItemInfo() { return _itemInfo[_curItem]; }
	wstring getItemName() { return _itemName[_curItem]; }
	UINT getItemBuyPrice() { return _itemBuyPrice[_curItem]; }
	UINT getItemSellPrice() { return _itemSellPrice[_curItem]; }
	UINT getItemNum() { return _itemNum; }



	bool getExit() { return _exit; }
	void setExit(bool exit){_exit = exit;}

	bool getChoice() { return _isChoice; }
	void setChoice(bool choice) { _isChoice = choice; }

};

