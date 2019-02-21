#include "stdafx.h"
#include "mainUi.h"


mainUi::mainUi()
{
}


mainUi::~mainUi()
{
}

HRESULT mainUi::init()
{
	_uiType = UI_MAIN;
	_menu_Select = POKEMON_BOOK;

	//메인메뉴 초기화 
	MENUMANAGER->addFrame("메인메뉴", 670, 1, 9, 15);

	return S_OK;
}

void mainUi::release()
{
}

void mainUi::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		//=========================== 설정
		//메뉴간의 이동은 메인메뉴에서만 가능하다
		//===============================
		switch (_menu_Select)
		{
		case POKEMON_BOOK:
			_menu_Select = MY_POKEMON;
			break;
		case MY_POKEMON:
			_menu_Select = BAG_ITEM;
			break;
		case BAG_ITEM:
			_menu_Select = PLAYER;
			break;
		case PLAYER:
			_menu_Select = SAVE_REPORT;
			break;
		case SAVE_REPORT:
			_menu_Select = SETTING;
			break;
		case SETTING:
			_menu_Select = CLOSE;
			break;
		case CLOSE:
			_menu_Select = POKEMON_BOOK;
			break;
		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		//=========================== 설정
		//메뉴간의 이동은 메인메뉴에서만 가능하다
		//===============================
		switch (_menu_Select)
		{
			case POKEMON_BOOK:
				_menu_Select = CLOSE;
			break;
			case MY_POKEMON:
				_menu_Select = POKEMON_BOOK;
			break;
			case BAG_ITEM:
				_menu_Select = MY_POKEMON;
			break;
			case PLAYER:
				_menu_Select = BAG_ITEM;
			break;
			case SAVE_REPORT:
				_menu_Select = PLAYER;
			break;
			case SETTING:
				_menu_Select = SAVE_REPORT;
			break;
			case CLOSE:
				_menu_Select = SETTING;
			break;
		}
	}

	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		switch (_menu_Select)
		{
		case POKEMON_BOOK:
			UIMANAGER->selectUI(UI_ILLUST);
			UIMANAGER->selecBeforeUI(UI_MAIN);
			break;
		case MY_POKEMON:
			UIMANAGER->selectUI(UI_POKEMON);
			UIMANAGER->selecBeforeUI(UI_MAIN);
			break;
		case BAG_ITEM:
			UIMANAGER->selectUI(UI_BAG);
			UIMANAGER->selecBeforeUI(UI_MAIN);
			break;
		case PLAYER:
			UIMANAGER->selectUI(UI_PLAYER);
			UIMANAGER->selecBeforeUI(UI_MAIN);
			break;
		case SAVE_REPORT:
			UIMANAGER->selectUI(UI_REPORT);
			UIMANAGER->selecBeforeUI(UI_MAIN);
			break;
		case SETTING:
			UIMANAGER->selectUI(UI_SETTING);
			UIMANAGER->selecBeforeUI(UI_MAIN);
			break;
		case CLOSE:
			UIMANAGER->selectUI(UI_NONE);
			break;
		}
	}
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		UIMANAGER->selectUI(UI_NONE);
	}
}

void mainUi::render()
{
	// 프레임 깔아주기
	MENUMANAGER->findMenuFrame("메인메뉴")->render();
	//하단텍스트 출력용 bg출력 
	IMAGEMANAGER->findImage("기본하단")->render(0 + CAMERA->getPosX(), 480 + CAMERA->getPosY());

	//텍스트 출력-
	WCHAR str[1024];

	swprintf_s(str, L"도감");
	D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 33 + CAMERA->getPosY(), 40);
	swprintf_s(str, L"포켓몬");
	D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 93 + CAMERA->getPosY(), 40);
	swprintf_s(str, L"가방");
	D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 153 + CAMERA->getPosY(), 40);

	swprintf_s(str, L"정보");
	D2DMANAGER->drawText(string2wstring(PLAYERDATA->getPlayer()->getName()).c_str(), 726 + CAMERA->getPosX(), 213 + CAMERA->getPosY(), 40);
	swprintf_s(str, L"리포트");
	D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 273 + CAMERA->getPosY(), 40);
	swprintf_s(str, L"설정");
	D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 333 + CAMERA->getPosY(), 40);
	swprintf_s(str, L"닫기");
	D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 393 + CAMERA->getPosY(), 40);

	switch (_menu_Select)
	{
	case POKEMON_BOOK:
		IMAGEMANAGER->findImage("화살표")->render(702 + CAMERA->getPosX(), 33 + CAMERA->getPosY());
		swprintf_s(str, L"도감에 기록된 포켓몬의 상세 정보를 확인합니다. ");
		D2DMANAGER->drawText(str, 10 + CAMERA->getPosX(), 500 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
		break;
	case MY_POKEMON:
		IMAGEMANAGER->findImage("화살표")->render(702 + CAMERA->getPosX(), 93 + CAMERA->getPosY());
		swprintf_s(str, L"같이 있는 포켓몬의 상태를 확인하고 관리합니다.");
		D2DMANAGER->drawText(str, 10 + CAMERA->getPosX(), 500 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
		break;
	case BAG_ITEM:
		IMAGEMANAGER->findImage("화살표")->render(702 + CAMERA->getPosX(), 153 + CAMERA->getPosY());
		swprintf_s(str, L"도구를 확인하고 사용할 수 있습니다.");
		D2DMANAGER->drawText(str, 10 + CAMERA->getPosX(), 500 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
		break;
	case PLAYER:
		IMAGEMANAGER->findImage("화살표")->render(702 + CAMERA->getPosX(), 213 + CAMERA->getPosY());
		swprintf_s(str, L"당신의 트레이너 카드를 확인합니다. ");
		D2DMANAGER->drawText(str, 10 + CAMERA->getPosX(), 500 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
		break;
	case SAVE_REPORT:
		IMAGEMANAGER->findImage("화살표")->render(702 + CAMERA->getPosX(), 273 + CAMERA->getPosY());
		swprintf_s(str, L"지금까지의 모험을 리포트로 기록합니다. ");
		D2DMANAGER->drawText(str, 10 + CAMERA->getPosX(), 500 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
		break;
	case SETTING:
		IMAGEMANAGER->findImage("화살표")->render(702 + CAMERA->getPosX(), 333 + CAMERA->getPosY());
		swprintf_s(str, L"사운드, 속도등의 설정을 변경합니다. ");
		D2DMANAGER->drawText(str, 10 + CAMERA->getPosX(), 500 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
		break;
	case CLOSE:
		IMAGEMANAGER->findImage("화살표")->render(702 + CAMERA->getPosX(), 393 + CAMERA->getPosY());
		swprintf_s(str, L"이 메뉴를 닫고 게임을 계속합니다. ");
		D2DMANAGER->drawText(str, 10 + CAMERA->getPosX(), 500 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
		break;
	}
}
