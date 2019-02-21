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

	UIMANAGER->uiDataSetting();
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
	SCRIPTMANAGER->update();
	//==================================

	//�׽���
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if (_shopChoice == SHOP_CHOICE_BUY)
			_shopChoice = SHOP_CHOICE_SELL;
		else if (_shopChoice == SHOP_CHOICE_SELL)
			_shopChoice = SHOP_CHOICE_NOPE;
		else if (_shopChoice == SHOP_CHOICE_NOPE)
			_shopChoice = SHOP_CHOICE_BUY;
		_curPointY += 55;
		if (_curPointY >= 166) _curPointY = 55;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if (_shopChoice == SHOP_CHOICE_BUY)
			_shopChoice = SHOP_CHOICE_SELL;
		else if (_shopChoice == SHOP_CHOICE_SELL)
			_shopChoice = SHOP_CHOICE_NOPE;
		else if (_shopChoice == SHOP_CHOICE_NOPE)
			_shopChoice = SHOP_CHOICE_BUY;
		_curPointY -= 55;
		if (_curPointY <= 0) _curPointY = 165;
	}
	if (!SCRIPTMANAGER->isUpdate())return;

	//==================================
	_npc->update();
	if(!_shop->getIsBuy())
		PLAYERDATA->getPlayer()->update();
	_isTalk = PLAYERDATA->getPlayer()->getShopOn();
	_npc->setIsTalk(_isTalk);
	_shop->update();

	//===================================
	//				��ȭ����
	//===================================
	if (_isTalk)
	{
		activeShopOwner();
	}
	else
	{
		_shopChoice = SHOP_CHOICE_BUY;
		_shopTalk = SHOP_TALK_HELLO;
		_curPointY = 55;
	}

	//===================================
	//				ī�޶�
	//===================================
	if (!_shop->getIsBuy())
		CAMERA->move(PLAYERDATA->getPlayer()->getPosX(), PLAYERDATA->getPlayer()->getPosY());
	else if (_shop->getIsBuy())
		CAMERA->move(PLAYERDATA->getPlayer()->getPosX() + 200, PLAYERDATA->getPlayer()->getPosY());

	UIMANAGER->update();
}

void storeScene::render()
{

	WCHAR str[128];
	_storeMap->render();

	//===================================
	//				����UI
	//===================================
	if (_isBuy)
	{
		SCRIPTMANAGER->render();
		_shop->render();
	}
	else if (_isBuy && _shop->getIsNumber())
	{
		_shop->render();
		SCRIPTMANAGER->render();
	}
	else
	{
		SCRIPTMANAGER->render();
		_shop->setExit(false);
	}


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

void storeScene::keyControl()
{
	
}

void storeScene::activeShopOwner()
{
	switch (_shopTalk)
	{
		case SHOP_TALK_HELLO:
		{
			_isChoice = true;
			keyControl();
			buyItemHello();
			_shopTalk = SHOP_TALK_BUY_UI;
			break;
		}
		case SHOP_TALK_BUY_UI:
		{
			_isBuy = true;									 //��ٸ�
			if (!_shop->getExit())
				_shop->setIsBuy(_isBuy);					 //Ű������ UI���� �ѱ��
			_isChoice = false;								 //��/�ƴϿ� â �����

			if (!_shop->getIsBuy())
			{
				_shopTalk = SHOP_TALK_CANCEL;
			}

			break;
		}
		case SHOP_TALK_BUY_CHOICE:
		{
			buyItemChoice();
			_shopTalk = SHOP_TALK_BUY;
			break;
		}
		case SHOP_TALK_BUY:
		{
			_isBuy = true;
			buyItem();
			break;
		}

		case SHOP_TALK_BUY_SURE:
		{
			_isBuy = true;
			buyItemSure();
			_shopTalk = SHOP_TALK_BUY_UI;
			break;
		}
		case SHOP_TALK_SELL_CHOICE:
		{
			//�߰�����
			break;
		}
		case SHOP_TALK_SELL:
		{
			//�߰�����
			break;
		}
		case SHOP_TALK_SELL_SURE:
		{
			//�߰�����
			break;
		}
		case SHOP_TALK_NOPE_OR_BYE:
		{
			nopeTalk();
			_shopTalk = SHOP_TALK_NONE;
			break;
		}
		case SHOP_TALK_CANCEL:
		{
			menuBack();
			_isChoice = true;
			if (_shopChoice == SHOP_CHOICE_BUY)
				_shopTalk = SHOP_TALK_BUY_UI;
			else if (_shopChoice == SHOP_CHOICE_SELL)
				_shopTalk = SHOP_TALK_BUY_UI;
			else if (_shopChoice == SHOP_CHOICE_NOPE)
				_shopTalk = SHOP_TALK_NOPE_OR_BYE;
			break;
		}
		case SHOP_TALK_NONE:
		{
			_isTalk = false;
			PLAYERDATA->getPlayer()->setShopOn(_isTalk);
			_isChoice = false;
			break;
		}

		default:
			break;
	}
	

}

void storeScene::buyItemHello()
{
	wstring text = L"�������! \n������ ���� �帱���?";
	SCRIPTMANAGER->pushScript(text);
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
