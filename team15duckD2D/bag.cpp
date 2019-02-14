#include "stdafx.h"
#include "bag.h"


bag::bag()
{
}


bag::~bag()
{
}

HRESULT bag::init()
{

	for (int i = 0; i < 39; i++)
	{
		_bag[i].name = L"아이템명 : " + to_wstring(i + 1);
	}

	return S_OK;
}

void bag::release()
{
}

void bag::update()
{
}

void bag::render()
{
	int height = 50;
	for (int i = 0; i < 39; ++i)
	{
		D2DMANAGER->drawText(_bag[i].name.c_str(), 400, height + ( i * 65) , 40);
	}
}

void bag::itemDataSet()
{
	locale("kor");

	for (int i = 0; i < 39; ++i)
	{
		item* iteminfo = ITEMDATA->settingItemInfo((ITEM_TYPE)i);

		if (iteminfo == nullptr) continue;
		_bag[i]._isDataset = true;
		_bag[i].name.clear();

		_bag[i].name = string2wstring(iteminfo->getItemName());

	}

}
