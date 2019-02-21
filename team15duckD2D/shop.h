#pragma once
#include "item.h"
class shop
{
private:

	wstring			_money;		//�÷��̾
	wstring			_itemInfo[39];  //����������
	wstring			_itemName[39];
	UINT			_itemBuyPrice[39];
	UINT			_itemSellPrice[39];
	UINT			_itemNum;	//�����۰���

	vector<item*>	_shopItems;	//�Ǹ��� ������

	UINT			_curItem;	//���� ������ ������
	float			_curPointY;	//���� ȭ��ǥ Y��ġ(������)
	float			_surePointY;//���� ȭ��ǥ Y��ġ(��/�ƴϿ�)

	bool			_isBuy;		//ī�޶� �̵���
	bool			_isNumber;	//���Ŵ�?
	bool			_isSure;	//��¥��Ŵ�?

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

