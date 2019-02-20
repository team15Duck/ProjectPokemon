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

	_isTalk = false;																					//���ߴ�?
	_isVisible = false;

	return S_OK;
}

void storeScene::release()
{
	_storeMap->release();
}

void storeScene::update()
{
	_storeMap->update();
	SCRIPTMANAGER->update();
	if (!SCRIPTMANAGER->isUpdate())return;
	PLAYERDATA->getPlayer()->update();
	_npc->update();
	_isTalk = PLAYERDATA->getPlayer()->getShopOn();
	_npc->setIsTalk(PLAYERDATA->getPlayer()->getShopOn());

	if (_isTalk)
	{
		activeShopOwner();
		_isVisible = true;
	}


	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		_isTalk = false;
		_isVisible = false;
		PLAYERDATA->getPlayer()->setShopOn(_isTalk);
	}

	CAMERA->move(PLAYERDATA->getPlayer()->getPosX(), PLAYERDATA->getPlayer()->getPosY());
}

void storeScene::render()
{
	_storeMap->render();
	if (_isVisible)
		SCRIPTMANAGER->render();

	WCHAR str[128];
	swprintf_s(str, L"����: %d", _shopTalk);
	D2DMANAGER->drawText(str, 13 * 64, 13 * 64, 20, RGB(255, 0, 255));
}

void storeScene::activeShopOwner()
{
	//����â ( 1. �緯�Դ� / 2. �ȷ��Դ� / 3. �ƴմϴ�)
	switch (_shopTalk)
	{
		//1. �緯�Դ�
		case SHOP_TALK_BUY_CHOICE:
		{
			buyItemChoice();
			break;
		}
		case SHOP_TALK_BUY:
		{
			buyItem();
			break;
		}
		case SHOP_TALK_BUY_SURE:
		{
			buyItemSure();
			break;
		}


		//2. �ȷ��Դ�
		case SHOP_TALK_SELL_CHOICE:
		{
			sellItemChoice();
			break;
		}
		case SHOP_TALK_SELL:
		{
			sellItem();
			break;
		}
		case SHOP_TALK_SELL_SURE:
		{
			sellItemSure();
			break;
		}


		//3. �ƴմϴ�
		case SHOP_TALK_NOPE:
		{
			nopeTalk();
			break;
		}

		//4. ������ư
		case SHOP_TALK_CANCEL:
		{
			menuBack();
			break;
		}





		default:
			break;
	}
}

void storeScene::buyItemChoice()
{
	ITEMDATA->init(NORMAL_POTION);
	wstring text = string2wstring(ITEMDATA->getItemName());
	text.append(L"(��)�� \n�� �� �����Ͻðڽ��ϱ�?");
	SCRIPTMANAGER->pushScript(text);

}

void storeScene::buyItem()
{
	ITEMDATA->init(NORMAL_POTION);
	wstring text = string2wstring(ITEMDATA->getItemName());
	text.append(L" ");
	text.append(to_wstring(ITEMDATA->getItemNum() + 3));
	text.append(L"�� �α���. \n");
	text.append(L"��");
	text.append(to_wstring(ITEMDATA->getBuyPrice() * (ITEMDATA->getItemNum() + 2)));
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
	ITEMDATA->init(NORMAL_POTION);
	wstring text = string2wstring(ITEMDATA->getItemName());
	text.append(L"(��)�� \n�� �� �Ľðڽ��ϱ�?");
	SCRIPTMANAGER->pushScript(text);

}

void storeScene::sellItem()
{
	ITEMDATA->init(NORMAL_POTION);
	wstring text = string2wstring(ITEMDATA->getItemName());
	text.append(L" ");
	text.append(to_wstring(3));
	text.append(L"�� �α���. \n");
	text.append(L"��");
	text.append(to_wstring(ITEMDATA->getSellPrice() * 3));
	text.append(L"���ϴ�.");
	SCRIPTMANAGER->pushScript(text);

}

void storeScene::sellItemSure()
{
	ITEMDATA->init(NORMAL_POTION);
	wstring text = string2wstring(ITEMDATA->getItemName());
	text.append(L"(��)�� �޾� \n");
	text.append(to_wstring(ITEMDATA->getSellPrice() * 3));
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
