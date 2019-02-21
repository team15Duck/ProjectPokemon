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

	wstring				_itemInfo[39];			//����������
	wstring				_itemName[39];			//�������̸�
	UINT				_itemBuyPrice[39];		//�����۱��԰���
	UINT				_itemSellPrice[39];		//�������ǸŰ���
	UINT				_itemNum;				//�����۰���
	ITEM_TYPE			_itemType;				//������Ÿ��
	CHOICE_SHOP			_choice;				//��/�ƴϿ� ����

	vector<item*>		_shopItems;				//�Ǹ��� ������

	UINT				_curItem;				//���� ������ ������
	float				_curPointY;				//���� ȭ��ǥ Y��ġ(������)
	float				_surePointY;			//���� ȭ��ǥ Y��ġ(��/�ƴϿ�)

	bool				_isBuy;					//������̴�?
	bool				_isNumber;				//��������̴�?
	bool				_isSure;				//��¥��Ŵ�?
	bool				_isHaveMoney;			//���ִ�?
	bool				_exit;					//����UI����

	bool				_isChoice;				//��Ŵ� �ȰŴ� �ƴϴ�
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

