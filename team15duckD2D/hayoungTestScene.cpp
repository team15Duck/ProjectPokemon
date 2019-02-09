#include "stdafx.h"
#include "hayoungTestScene.h"


hayoungTestScene::hayoungTestScene()
{
}


hayoungTestScene::~hayoungTestScene()
{
}

HRESULT hayoungTestScene::init()
{
	frameImageinit();

	_cm._bottom = { 0, 490, 960, 640 };

	_cm._menu[0] = { 726, 33, 926, 93 };
	_cm._menu[1] = { 726, 93, 926, 153 };
	_cm._menu[2] = { 726, 153, 926, 213 };
	_cm._menu[3] = { 726, 213, 926, 273 };
	_cm._menu[4] = { 726, 273, 926, 333 };
	_cm._menu[5] = { 726, 333, 926, 393 };
	_cm._menu[6] = { 726, 393, 926, 453 };

 	_cm._cursor[0] = { 702, 43, 726, 83 };
	_cm._cursor[1] = { 702, 103, 726, 143 };
	_cm._cursor[2] = { 702, 163, 726, 203 };
	_cm._cursor[3] = { 702, 223, 726, 263 };
	_cm._cursor[4] = { 702, 283, 726, 323 };
	_cm._cursor[5] = { 702, 343, 726, 383 };
	_cm._cursor[6] = { 702, 403, 726, 443 };


	_rc = { 0 , 480, 960, 640 };
	MENUMANAGER->addFrame("기본메뉴", 670, 1, 9, 15);

	_cm._cstate = POKEMON_BOOK;

	_isCommonMenu = false;
	_isCussorDown = false;
	_isCussorUp = false;
	
	return S_OK;
}

void hayoungTestScene::release()
{
}

void hayoungTestScene::update()
{
	//만약에 엔터키를 누르면 
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		_isCommonMenu = true;
	}
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		_isCommonMenu = false;
	}

	//만약에 메뉴가 켜진상태에서 아래버튼을 누르면

	if (_isCommonMenu)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_isCussorDown = true;
			switch (_cm._cstate)
			{
			case POKEMON_BOOK:
				_cm._cstate = POKEMON;
				break;
			case POKEMON:
				_cm._cstate = BAG;
				break;
			case BAG:
				_cm._cstate = PLAYER;
				break;
			case PLAYER:
				_cm._cstate = SAVE_REPORT;
				break;
			case SAVE_REPORT:
				_cm._cstate = SETTING;
				break;
			case SETTING:
				_cm._cstate = CLOSE;
				break;
			case CLOSE:
				_cm._cstate = POKEMON_BOOK;
				break;
			}

		}
		else if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			_isCussorDown = false;
			switch (_cm._cstate)
			{
				case POKEMON_BOOK:
					_cm._cstate = CLOSE;
					break;
				case POKEMON:
					_cm._cstate = POKEMON_BOOK;
					break;
				case BAG:
					_cm._cstate = POKEMON;
					break;
				case PLAYER:
					_cm._cstate = BAG;
					break;
				case SAVE_REPORT:
					_cm._cstate = PLAYER;
					break;
				case SETTING:
					_cm._cstate = SAVE_REPORT;
					break;
				case CLOSE:
					_cm._cstate = SETTING;
					break;
			}
		}
	}

}

void hayoungTestScene::render()
{

	if (_isCommonMenu)
	{
		IMAGEMANAGER->findImage("테스트")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
		MENUMANAGER->findMenuFrame("기본메뉴")->render("타입1");

		//============================ 체크용 렉트 출력 확인끝나면 삭제할거임 
		//D2DMANAGER->fillRectangle(RGB(255, 0, 255), _cm._menu[0]);
		//D2DMANAGER->fillRectangle(RGB(0, 10, 255), _cm._menu[1]);
		//D2DMANAGER->fillRectangle(RGB(100, 20, 50), _cm._menu[2]);
		//D2DMANAGER->fillRectangle(RGB(12, 30, 25), _cm._menu[3]);
		//D2DMANAGER->fillRectangle(RGB(0, 30, 0), _cm._menu[4]);
		//D2DMANAGER->fillRectangle(RGB(110, 30, 110), _cm._menu[5]);
		//D2DMANAGER->fillRectangle(RGB(255, 255, 255), _cm._menu[6]);
		//
		//D2DMANAGER->fillRectangle(RGB(0, 0, 50), _cm._cursor[0]);
		//D2DMANAGER->fillRectangle(RGB(0, 0, 50), _cm._cursor[1]);
		//D2DMANAGER->fillRectangle(RGB(0, 0, 50), _cm._cursor[2]);
		//D2DMANAGER->fillRectangle(RGB(0, 0, 50), _cm._cursor[3]);
		//D2DMANAGER->fillRectangle(RGB(0, 0, 50), _cm._cursor[4]);
		//D2DMANAGER->fillRectangle(RGB(0, 0, 50), _cm._cursor[5]);
		//D2DMANAGER->fillRectangle(RGB(0, 0, 50), _cm._cursor[6]);

		//===================================================================================
		IMAGEMANAGER->findImage("기본하단")->render(_rc.left + CAMERA->getPosX(), _rc.top + CAMERA->getPosY());

		WCHAR str[1024];
		swprintf_s(str, L"메뉴선택상태: %d" , _cm._cstate);
		D2DMANAGER->drawText(str, 100 + CAMERA->getPosX(), 100 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"도감");
		D2DMANAGER->drawText(str, _cm._menu[0].left + CAMERA->getPosX(), _cm._menu[0].top + 15 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"포켓몬");
		D2DMANAGER->drawText(str, _cm._menu[1].left + CAMERA->getPosX(), _cm._menu[1].top + 15 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"가방");
		D2DMANAGER->drawText(str, _cm._menu[2].left + CAMERA->getPosX(), _cm._menu[2].top + 15 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"닉네임출력");
		D2DMANAGER->drawText(str, _cm._menu[3].left + CAMERA->getPosX(), _cm._menu[3].top + 15 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"리포트");
		D2DMANAGER->drawText(str, _cm._menu[4].left + CAMERA->getPosX(), _cm._menu[4].top + 15 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"설정");
		D2DMANAGER->drawText(str, _cm._menu[5].left + CAMERA->getPosX(), _cm._menu[5].top + 15 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"닫기");
		D2DMANAGER->drawText(str, _cm._menu[6].left + CAMERA->getPosX(), _cm._menu[6].top + 15 + CAMERA->getPosY(), 40);
	
		switch (_cm._cstate)
		{
			case POKEMON_BOOK:
				IMAGEMANAGER->findImage("화살표")->render(_cm._cursor[0].left + CAMERA->getPosX(), _cm._cursor[0].top + CAMERA->getPosY());
				swprintf_s(str, L"도감에 기록된 포켓몬의 상세 정보를 확인합니다. ");
				D2DMANAGER->drawText(str, _cm._bottom.left + 10 + CAMERA->getPosX(), _cm._bottom.top + 15 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
			break;
			case POKEMON:
				IMAGEMANAGER->findImage("화살표")->render(_cm._cursor[1].left + CAMERA->getPosX(), _cm._cursor[1].top + CAMERA->getPosY());
				swprintf_s(str, L"같이 있는 포켓몬의 상태를 확인하고 관리합니다.");
				D2DMANAGER->drawText(str, _cm._bottom.left + 10 + CAMERA->getPosX(), _cm._bottom.top + 15 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
			break;
			case BAG:
				IMAGEMANAGER->findImage("화살표")->render(_cm._cursor[2].left + CAMERA->getPosX(), _cm._cursor[2].top + CAMERA->getPosY());
				swprintf_s(str, L"도구를 확인하고 사용할 수 있습니다.");
				D2DMANAGER->drawText(str, _cm._bottom.left + 10 + CAMERA->getPosX(), _cm._bottom.top + 15 + CAMERA->getPosY(), 40, RGB(255,255,255));
			break;
			case PLAYER:
				IMAGEMANAGER->findImage("화살표")->render(_cm._cursor[3].left + CAMERA->getPosX(), _cm._cursor[3].top + CAMERA->getPosY());
				swprintf_s(str, L"당신의 트레이너 카드를 확인합니다. ");
				D2DMANAGER->drawText(str, _cm._bottom.left + 10 + CAMERA->getPosX(), _cm._bottom.top + 15 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
			break;
			case SAVE_REPORT:
				IMAGEMANAGER->findImage("화살표")->render(_cm._cursor[4].left + CAMERA->getPosX(), _cm._cursor[4].top + CAMERA->getPosY());
				swprintf_s(str, L"지금까지의 모험을 리포트로 기록합니다. ");
				D2DMANAGER->drawText(str, _cm._bottom.left + 10 + CAMERA->getPosX(), _cm._bottom.top + 15 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
			break;
			case SETTING:
				IMAGEMANAGER->findImage("화살표")->render(_cm._cursor[5].left + CAMERA->getPosX(), _cm._cursor[5].top + CAMERA->getPosY());
				swprintf_s(str, L"사운드, 속도등의 설정을 변경합니다. ");
				D2DMANAGER->drawText(str, _cm._bottom.left + 10 + CAMERA->getPosX(), _cm._bottom.top + 15 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
			break;
			case CLOSE:
				IMAGEMANAGER->findImage("화살표")->render(_cm._cursor[6].left + CAMERA->getPosX(), _cm._cursor[6].top + CAMERA->getPosY());
				swprintf_s(str, L"이 메뉴를 닫고 게임을 계속합니다. ");
				D2DMANAGER->drawText(str, _cm._bottom.left + 10 + CAMERA->getPosX(), _cm._bottom.top + 15 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
			break;
		}
	
	}
}

void hayoungTestScene::frameImageinit()
{
	IMAGEMANAGER->addImage("기본하단", L"image/common_bg.png", 960, 160);
	IMAGEMANAGER->addImage("화살표", L"image/pokemonMenu_cursor.png", 24, 40);
	IMAGEMANAGER->addImage("테스트", L"image/test/aaa.png", 960, 640);

}
