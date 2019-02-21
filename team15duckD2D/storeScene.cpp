#include "stdafx.h"
#include "storeScene.h"


storeScene::storeScene()
{
}

storeScene::~storeScene()
{
}



HRESULT storeScene::init()
{
	_storeMap = new storeMap;
	_storeMap->init("data/storeMapSize.map", "data/storeMapData.map");

	_storeMap->setPlayerMemoryAdressLink(PLAYERDATA->getPlayer());
	PLAYERDATA->getPlayer()->setMapDataMemoryAdressLink(_storeMap);
	
	SOUNDMANAGER->addSound("storeBGM", "sound/bgm_13_Pokemon_Center.mp3", true, true);
	//SOUNDMANAGER->play("storeBGM");

	_npc = new npc;																						//NPC
	_npc->init(NPC_TYPE_SHOPOWNER);																		//npc�߰�(��������)
	_storeMap->pushNpc(_npc);																			//�ʿ� �������� �߰�

	_shop = new shop;
	_shop->init();

	_isTalk = false;																					//���ߴ�?
	_isChoice = false;
	_curPointY = 55;

	MENUMANAGER->addFrame("choiceFrame_shop", 35, 5, 10, 8);

	UIMANAGER->init();
	return S_OK;
}

void storeScene::release()
{
	_storeMap->release();
}

void storeScene::update()
{

	//==================================
	_storeMap->update();
	_shop->update();
	SCRIPTMANAGER->update();

	//==================================

	//�׽���
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_curPointY += 55;
		if (_curPointY >= 166) _curPointY = 55;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_curPointY -= 55;
		if (_curPointY <= 0) _curPointY = 165;
	}

	if (!SCRIPTMANAGER->isUpdate())return;

	//==================================
	PLAYERDATA->getPlayer()->update();
	_npc->update();
	_isTalk = PLAYERDATA->getPlayer()->getShopOn();
	_npc->setIsTalk(PLAYERDATA->getPlayer()->getShopOn());

	//===================================
	//				��ȭ����
	//===================================
	if (_isTalk)
	{
		activeShopOwner();
	}

	//===================================
	//				ī�޶�
	//===================================
	if(!_shop->getIsBuy())
		CAMERA->move(PLAYERDATA->getPlayer()->getPosX(), PLAYERDATA->getPlayer()->getPosY());
	else if(_shop->getIsBuy())
		CAMERA->move(PLAYERDATA->getPlayer()->getPosX() + 200, PLAYERDATA->getPlayer()->getPosY());

	UIMANAGER->update();
}

void storeScene::render()
{
	_storeMap->render();

	WCHAR str[128];
	swprintf_s(str, L"����: %d", _shopTalk);
	D2DMANAGER->drawText(str, 13 * 64, 13 * 64, 20, RGB(255, 0, 255));

	//===================================
	//				����UI
	//===================================
	if (_isBuy && !_isSure)
	{
		SCRIPTMANAGER->render();
		_shop->render();
	}
	else if (_isBuy && _isSure)
	{
		_shop->render();
		SCRIPTMANAGER->render();
	}
	else
		SCRIPTMANAGER->render();
		

	//===================================
	//		�緯�Դ�/�ȷ��Դ�/�ƴմϴ�
	//===================================
	if (_isChoice)
	{
		MENUMANAGER->findMenuFrame("choiceFrame_shop")->render();
		swprintf_s(str, L"�緯�Դ�");
		D2DMANAGER->drawText(str, 110 + CAMERA->getPosX(), 55 + CAMERA->getPosY(), 35);
		swprintf_s(str, L"�ȷ��Դ�");
		D2DMANAGER->drawText(str, 110 + CAMERA->getPosX(), (55 * 2) + CAMERA->getPosY(), 35);
		swprintf_s(str, L"�ƴմϴ�");
		D2DMANAGER->drawText(str, 110 + CAMERA->getPosX(), (55 * 3) + CAMERA->getPosY(), 35);
		IMAGEMANAGER->findImage("ȭ��ǥ")->render(80 + CAMERA->getPosX(), _curPointY + CAMERA->getPosY());
	}

	UIMANAGER->render();
}

void storeScene::activeShopOwner()
{
	switch (_shopTalk)
	{
		case SHOP_TALK_HELLO:
		{
			_isChoice = true;
			wstring text = L"�������! \n������ ���� �帱���?";
			SCRIPTMANAGER->pushScript(text);
			_shopTalk = SHOP_TALK_BUY_UI;

			break;
		}
		case SHOP_TALK_BUY_UI:
		{
			_isBuy = true;
			_shop->setIsBuy(_isBuy);
			_isChoice = false;
			SCRIPTMANAGER->pushScript(L"����������");
			_shopTalk = SHOP_TALK_BUY_CHOICE;
			break;
		}
		case SHOP_TALK_BUY_CHOICE:
		{
			_isBuy = true;
			_isSure = true;
			buyItemChoice();
			_shopTalk = SHOP_TALK_BUY;
			break;
		}
		case SHOP_TALK_BUY:
		{
			_isBuy = true;
			_isSure = true;
			buyItem();
			break;
		}
			
		case SHOP_TALK_BUY_SURE:
		{
			_isBuy = true;
			_isSure = true;
			buyItemSure();
			_shopTalk = SHOP_TALK_BUY_UI;
			break;
		}
		case SHOP_TALK_SELL_CHOICE:
		{

			break;
		}
		case SHOP_TALK_SELL:
		{

			break;
		}
		case SHOP_TALK_SELL_SURE:
		{

			break;
		}
		case SHOP_TALK_NOPE_OR_BYE:
		{

			break;
		}
		case SHOP_TALK_CANCEL:
		{

			break;
		}
		case SHOP_TALK_NONE:
		{

			break;
		}

		default:
			break;
	}
	
}

void storeScene::buyItemChoice()
{
	wstring text = _shop->getItemName();
	text.append(L"(��)�� \n�� �� �����Ͻðڽ��ϱ�?");
	SCRIPTMANAGER->pushScript(text);

}

void storeScene::buyItem()
{
	wstring text = _shop->getItemName();
	text.append(L" ");
	text.append(to_wstring(_shop->getItemNum()));
	text.append(L"�� �α���. \n");
	text.append(L"��");
	text.append(to_wstring(_shop->getItemBuyPrice() * _shop->getItemNum()));
	text.append(L"���ϴ�.");
	SCRIPTMANAGER->pushScript(text);

}

void storeScene::buyItemSure()
{
	wstring text = L"�� ���� �ֽ��ϴ�. \n����� �����մϴ�.";
	SCRIPTMANAGER->pushScript(text);

}

void storeScene::sellItemChoice()
{
	wstring text = _shop->getItemName();
	text.append(L"(��)�� \n�� �� �Ľðڽ��ϱ�?");
	SCRIPTMANAGER->pushScript(text);

}

void storeScene::sellItem()
{
	wstring text = _shop->getItemName();
	text.append(L" ");
	text.append(to_wstring(_shop->getItemNum()));
	text.append(L"�� �α���. \n");
	text.append(L"��");
	text.append(to_wstring(_shop->getItemSellPrice() * _shop->getItemNum()));
	text.append(L"���ϴ�.");
	SCRIPTMANAGER->pushScript(text);

}

void storeScene::sellItemSure()
{
	wstring text = _shop->getItemName();
	text.append(L"(��)�� �޾� \n");
	text.append(to_wstring(_shop->getItemSellPrice() * _shop->getItemNum()));
	text.append(L"���� ��Ƚ��ϴ�.");
	SCRIPTMANAGER->pushScript(text);
}

void storeScene::menuBack()
{
	wstring text = L"�� �ۿ� ���� \n�� ���͵帱 �� �����ϱ�?";
	SCRIPTMANAGER->pushScript(text);
}

void storeScene::nopeTalk()
{
	wstring text = L"�� ������!";
	SCRIPTMANAGER->pushScript(text);
}
