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
	_npc->init(NPC_TYPE_SHOPOWNER);																		//npc추가(상점주인)
	_storeMap->pushNpc(_npc);																			//맵에 상점주인 추가

	_isTalk = false;																					//말했니?
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
	swprintf_s(str, L"상태: %d", _shopTalk);
	D2DMANAGER->drawText(str, 13 * 64, 13 * 64, 20, RGB(255, 0, 255));
}

void storeScene::activeShopOwner()
{
	//선택창 ( 1. 사러왔다 / 2. 팔러왔다 / 3. 아닙니다)
	switch (_shopTalk)
	{
		//1. 사러왔다
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


		//2. 팔러왔다
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


		//3. 아닙니다
		case SHOP_TALK_NOPE:
		{
			nopeTalk();
			break;
		}

		//4. 이전버튼
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
	text.append(L"(를)을 \n몇 개 구입하시겠습니까?");
	SCRIPTMANAGER->pushScript(text);

}

void storeScene::buyItem()
{
	ITEMDATA->init(NORMAL_POTION);
	wstring text = string2wstring(ITEMDATA->getItemName());
	text.append(L" ");
	text.append(to_wstring(ITEMDATA->getItemNum() + 3));
	text.append(L"개 로군요. \n");
	text.append(L"총");
	text.append(to_wstring(ITEMDATA->getBuyPrice() * (ITEMDATA->getItemNum() + 2)));
	text.append(L"원니다.");
	SCRIPTMANAGER->pushScript(text);

}

void storeScene::buyItemSure()
{
	wstring text = L"네 여기 있습니다. \n대단히 감사합니다.";
	SCRIPTMANAGER->pushScript(text);

}

void storeScene::sellItemChoice()
{
	ITEMDATA->init(NORMAL_POTION);
	wstring text = string2wstring(ITEMDATA->getItemName());
	text.append(L"(를)을 \n몇 개 파시겠습니까?");
	SCRIPTMANAGER->pushScript(text);

}

void storeScene::sellItem()
{
	ITEMDATA->init(NORMAL_POTION);
	wstring text = string2wstring(ITEMDATA->getItemName());
	text.append(L" ");
	text.append(to_wstring(3));
	text.append(L"개 로군요. \n");
	text.append(L"총");
	text.append(to_wstring(ITEMDATA->getSellPrice() * 3));
	text.append(L"원니다.");
	SCRIPTMANAGER->pushScript(text);

}

void storeScene::sellItemSure()
{
	ITEMDATA->init(NORMAL_POTION);
	wstring text = string2wstring(ITEMDATA->getItemName());
	text.append(L"(를)을 받아 \n");
	text.append(to_wstring(ITEMDATA->getSellPrice() * 3));
	text.append(L"원을 드렸습니다.");
	SCRIPTMANAGER->pushScript(text);
}

void storeScene::menuBack()
{
	wstring text = L"그 밖에 저희가 \n뭐 도와드릴 건 없습니까?";
	SCRIPTMANAGER->pushScript(text);
}

void storeScene::nopeTalk()
{
	wstring text = L"또 오세요!";
	SCRIPTMANAGER->pushScript(text);
}
