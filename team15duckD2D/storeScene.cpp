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

	_shop = new shop;
	_shop->init();

	_isTalk = false;																					//말했니?
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

	//테슷흐
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
	//				대화시작
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
	//				카메라
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
	//				상점UI
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
	//		사러왔다/팔러왔다/아닙니다
	//===================================
	if (_isChoice)
	{
		MENUMANAGER->findMenuFrame("choiceFrame_shop")->render();
		swprintf_s(str, L"사러왔다");
		D2DMANAGER->drawText(str, 110 + CAMERA->getPosX(), 55 + CAMERA->getPosY(), 35);
		swprintf_s(str, L"팔러왔다");
		D2DMANAGER->drawText(str, 110 + CAMERA->getPosX(), (55 * 2) + CAMERA->getPosY(), 35);
		swprintf_s(str, L"아닙니다");
		D2DMANAGER->drawText(str, 110 + CAMERA->getPosX(), (55 * 3) + CAMERA->getPosY(), 35);
		IMAGEMANAGER->findImage("화살표")->render(80 + CAMERA->getPosX(), _curPointY + CAMERA->getPosY());
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
			_isBuy = true;									 //산다면
			if (!_shop->getExit())
				_shop->setIsBuy(_isBuy);					 //키동작은 UI에게 넘긴다
			_isChoice = false;								 //예/아니오 창 사라짐

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
			//추가예정
			break;
		}
		case SHOP_TALK_SELL:
		{
			//추가예정
			break;
		}
		case SHOP_TALK_SELL_SURE:
		{
			//추가예정
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
	wstring text = L"어서오세요! \n무엇을 도와 드릴까요?";
	SCRIPTMANAGER->pushScript(text);
}

void storeScene::buyItemChoice()
{
	wstring text = _shop->getItemName();
	text.append(L"(를)을 \n몇 개 구입하시겠습니까?");
	SCRIPTMANAGER->pushScript(text);

}

void storeScene::buyItem()
{
	wstring text = _shop->getItemName();
	text.append(L" ");
	text.append(to_wstring(_shop->getItemNum()));
	text.append(L"개 로군요. \n");
	text.append(L"총");
	text.append(to_wstring(_shop->getItemBuyPrice() * _shop->getItemNum()));
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
	wstring text = _shop->getItemName();
	text.append(L"(를)을 \n몇 개 파시겠습니까?");
	SCRIPTMANAGER->pushScript(text);

}

void storeScene::sellItem()
{
	wstring text = _shop->getItemName();
	text.append(L" ");
	text.append(to_wstring(_shop->getItemNum()));
	text.append(L"개 로군요. \n");
	text.append(L"총");
	text.append(to_wstring(_shop->getItemSellPrice() * _shop->getItemNum()));
	text.append(L"원니다.");
	SCRIPTMANAGER->pushScript(text);

}

void storeScene::sellItemSure()
{
	wstring text = _shop->getItemName();
	text.append(L"(를)을 받아 \n");
	text.append(to_wstring(_shop->getItemSellPrice() * _shop->getItemNum()));
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
