#include "stdafx.h"
#include "shop.h"


shop::shop()
{
}


shop::~shop()
{
}

HRESULT shop::init()
{

	MENUMANAGER->addFrame("money_Frame", 5, 5, 10, 5);
	MENUMANAGER->addFrame("shop_Frame", 320, 5, 20, 14);
	MENUMANAGER->addFrame("number_Frame", 480, 260, 15, 6);
	MENUMANAGER->addFrame("choice_Frame", 650, 260, 8, 6);

	_isHaveMoney = true;
	_isBuy = false;
	_isNumber = false;
	_isSure = false; 

	_curItem = 0;
	_curPointY = 50;
	_surePointY = 305;
	_itemNum = 1;

	initItems();


	_exit = false;


	return S_OK;
}

void shop::release()
{
}

void shop::update()
{
	itemInfoSetting();
	if(_isBuy)
		keyControl();

}

void shop::render()
{
	WCHAR str[128];
	if (_isBuy)
	{
		IMAGEMANAGER->findImage("가방메뉴배경")->frameRender(0 + CAMERA->getPosX(), 448 + CAMERA->getPosY(), 0, 448, 960, 192, 0, 0);
		MENUMANAGER->findMenuFrame("money_Frame")->render();
		MENUMANAGER->findMenuFrame("shop_Frame")->render();

		IMAGEMANAGER->findImage("화살표")->render(370 + CAMERA->getPosX(), _curPointY + CAMERA->getPosY());
		D2DMANAGER->drawText(_itemInfo[_curItem].c_str(), 200 + CAMERA->getPosX(), 500 + CAMERA->getPosY(), 35);
		_shopItems[_curItem]->render();


		for (int i = 0; i < _shopItems.size(); i++)
		{
			D2DMANAGER->drawText(_itemName[i].c_str(), 400 + CAMERA->getPosX(), 50 + 40 * i + CAMERA->getPosY(), 35);
			swprintf_s(str, L"%d원", _itemBuyPrice[i]);
			D2DMANAGER->drawText(str, 800 + CAMERA->getPosX(), 50 + 40 * i + CAMERA->getPosY(), 35);
		}

		if (_isNumber)
		{
			MENUMANAGER->findMenuFrame("number_Frame")->render();
			swprintf_s(str, L"x %d", _itemNum);
			D2DMANAGER->drawText(str, 530 + CAMERA->getPosX(), 330 + CAMERA->getPosY(), 45);

			swprintf_s(str, L"%d원", (_itemBuyPrice[_curItem] * _itemNum));
			D2DMANAGER->drawText(str, 750 + CAMERA->getPosX(), 330 + CAMERA->getPosY(), 45);
		}

		if (_isSure)
		{
			MENUMANAGER->findMenuFrame("choice_Frame")->render();
			swprintf_s(str, L"예");
			D2DMANAGER->drawText(str, 730 + CAMERA->getPosX(), 305 + CAMERA->getPosY(), 35);
			swprintf_s(str, L"아니오");
			D2DMANAGER->drawText(str, 730 + CAMERA->getPosX(), 355 + CAMERA->getPosY(), 35);
			IMAGEMANAGER->findImage("화살표")->render(690 + CAMERA->getPosX(), _surePointY + CAMERA->getPosY());
		}


		swprintf_s(str, L"돈");
		D2DMANAGER->drawText(str, 50 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 30);

		swprintf_s(str, L"%d", PLAYERDATA->getPlayer()->getMoney());
		D2DMANAGER->drawText(str, 150 + CAMERA->getPosX(), 100 + CAMERA->getPosY(), 30);

		swprintf_s(str, L"__________원");
		D2DMANAGER->drawText(str, 110 + CAMERA->getPosX(), 100 + CAMERA->getPosY(), 30);

	}
}

void shop::initItems()
{
	_shopItems.push_back(ITEMDATA->settingItemInfo(MONSTER_BALL));
	_shopItems.push_back(ITEMDATA->settingItemInfo(SUPER_BALL));
	_shopItems.push_back(ITEMDATA->settingItemInfo(NORMAL_POTION));
	_shopItems.push_back(ITEMDATA->settingItemInfo(SUPER_POTION));
	_shopItems.push_back(ITEMDATA->settingItemInfo(ANTIDOTE));
	_shopItems.push_back(ITEMDATA->settingItemInfo(PARLYZE_HEAL));
	_shopItems.push_back(ITEMDATA->settingItemInfo(BURN_HEAL));
	_shopItems.push_back(ITEMDATA->settingItemInfo(ICE_HEAL));
	_shopItems.push_back(ITEMDATA->settingItemInfo(AWAKENING));
}

void shop::itemInfoSetting()
{
	for (int i = 0; i < _shopItems.size(); i++)
	{
		_itemInfo[i] = string2wstring(_shopItems[i]->getItemInfo());
		_itemName[i] = string2wstring(_shopItems[i]->getItemName());
		_itemBuyPrice[i] = _shopItems[i]->getBuyPrice();
		_itemSellPrice[i] = _shopItems[i]->getSellPrice();
	}
}

void shop::keyControl()
{
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if (_isBuy && !_isNumber && !_isSure)
		{
			if (_curItem >= _shopItems.size() - 1) return;
			_curItem++;
			_curPointY += 40;
		}
		if (_isBuy && _isNumber && !_isSure)
		{
			if (_itemNum == 1)
			{
				_itemNum = PLAYERDATA->getPlayer()->getMoney() / _itemBuyPrice[_curItem];
				return;
			}
			_itemNum--;
		}
		if (_isBuy && !_isNumber && _isSure)
		{
			if (_surePointY >= 350) return;
			_surePointY += 45;
			if (_choice == CHOICE_SHOP_YES)
				_choice = CHOICE_SHOP_NO;
			else if (_choice == CHOICE_SHOP_NO)
				_choice = CHOICE_SHOP_YES;
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if (_isBuy && !_isNumber && !_isSure)
		{
			if (_curItem == 0) return;
			_curItem--;
			_curPointY -= 40;
		}
		if (_isBuy && _isNumber && !_isSure)
		{
			if (_itemNum >= (PLAYERDATA->getPlayer()->getMoney() / _itemBuyPrice[_curItem]))
			{
				_itemNum = 1;
				return;
			}
			_itemNum++;
		}
		if (_isBuy && !_isNumber && _isSure)
		{
			if (_surePointY <= 305) return;
			_surePointY -= 45;
			if (_choice == CHOICE_SHOP_YES)
				_choice = CHOICE_SHOP_NO;
			else if (_choice == CHOICE_SHOP_NO)
				_choice = CHOICE_SHOP_YES;
		}
	}


	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		if (_isBuy && !_isNumber && !_isSure)
		{
			_isNumber = true;
		}
		else if (_isBuy && _isNumber && !_isSure)
		{
			_isNumber = false;
			_isSure = true;
		}
		else if (_isBuy && !_isNumber && !_isSure)
		{
			_isSure = true;
		}
		else if (_isSure && _choice == CHOICE_SHOP_YES)
		{
			if (PLAYERDATA->getPlayer()->getMoney() <= 0)
			{
				_isHaveMoney = false;
			}
			PLAYERDATA->getPlayer()->setMoney(PLAYERDATA->getPlayer()->getMoney() - (_itemBuyPrice[_curItem] * _itemNum));
			_itemType = _shopItems[_curItem]->getItemType();
			if (PLAYERDATA->getPlayer()->getItem().size())
			{
				player::mapItemIter iter = PLAYERDATA->getPlayer()->getItem().find(_itemType);

				if (iter == PLAYERDATA->getPlayer()->getItem().end())
				{
					PLAYERDATA->getPlayer()->pushItem(_itemType, _itemNum);
				}
				else
				{
					iter->second += _itemNum;
				}
			}
			else
			{
				PLAYERDATA->getPlayer()->pushItem(_itemType, _itemNum);
			}
			
			_isSure = false;
			_itemNum = 1;
		}
		else if (_isSure && _choice == CHOICE_SHOP_NO)
		{
			_isSure = false;
			_itemNum = 1;
		}
		UIMANAGER->uiDataSetting();
	}
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		if (_isBuy && _isNumber && !_isSure)
		{
			_isNumber = false;
			_itemNum = 1;
		}
		else if (_isBuy && !_isNumber && _isSure)
		{
			_isSure = false;
			_itemNum = 1;
		}
		else if (_isBuy && !_isNumber && !_isSure)
		{
			_isBuy = false;
			_itemNum = 1;
			_exit = true;
		}
	}
}
