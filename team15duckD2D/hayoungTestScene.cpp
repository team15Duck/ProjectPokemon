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
	commonMenuinit();

	_isFemale = false;
	_isMale = true;

	_cmpm._pcs = MAIN_POKEMON;

	IMAGEMANAGER->addFrameImage("트레이너카드", L"image/common_menu/player/trainerCard.png", 1920, 640, 2, 1);

	IMAGEMANAGER->addFrameImage("도감", L"image/common_menu/pokemonbook/cm_pokemon_book.png", 1920, 640, 2, 1);

	IMAGEMANAGER->addImage("보유중포켓몬", L"image/common_menu/pokemon/pokemonMenu_background.png", 960, 640);
	IMAGEMANAGER->addFrameImage("메인포켓몬", L"image/common_menu/pokemon/pokemonMenu_slot_first.png", 384, 512, 1, 2);
	IMAGEMANAGER->addFrameImage("포켓몬메뉴_취소", L"image/common_menu/pokemon/pokemonMenu_btn_cancle.png", 216, 192, 1, 2);
	IMAGEMANAGER->addFrameImage("서브포켓몬", L"image/common_menu/pokemon/pokemonMenu_slot.png", 620, 256, 1, 2);
	MENUMANAGER->addFrame("설정프레임1", 80, 64, 25, 4);
	MENUMANAGER->addFrame("설정프레임2", 0, 192, 30, 14);
	MENUMANAGER->addFrame("포켓몬프레임1", 0, 512, 23, 4);
	
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
	//하위메뉴가 열려있는 상태에서
	if (_cm._ms == YES)
	{
		//만약에 x키를 누르면 
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			switch (_cm._cstate)
			{
			case POKEMON_BOOK:
			case POKEMON:
			case BAG:
			case PLAYER:
			case SAVE_REPORT:
			case SETTING:
			case CLOSE:
				_cm._ms = NO;			//선택중이 아니다로 바꿔준다
				break;
			}
		}

		//만약에 포켓몬 메뉴에서 위로키를 누르면
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			switch (_cmpm._pcs)
			{
			case MAIN_POKEMON:
				_cmpm._pcs = CANCEL;
				break;
			case SUB_POKEMON1:
				_cmpm._pcs = MAIN_POKEMON;
				break;
			case SUB_POKEMON2:
				
				break;
			case SUB_POKEMON3:
				
				break;
			case SUB_POKEMON4:
				
				break;
			case SUB_POKEMON5:
				
				break;
			case CANCEL:
			
				break;
			}
		}
	}
	if (_cm._ms == NO && _isCommonMenu)
	{
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			_isCommonMenu = false;
		}
	}
	//만약에 기본메뉴가 켜진상태에서의 키세팅 
	if (_isCommonMenu && _cm._ms != YES)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
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
		//다른화면으로 진입해보자
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			switch (_cm._cstate)
			{
			case POKEMON_BOOK:
			case POKEMON:
			case BAG:
			case PLAYER:
			case SAVE_REPORT:
			case SETTING:
				_cm._ms = YES;
				break;
			}
			if (_cm._cstate == CLOSE)
			{
				_isCommonMenu = false;
			}
		}
	}


}

void hayoungTestScene::render()
{
	commonMenurender();
	if (_cm._cstate == POKEMON_BOOK && _cm._ms == YES)
	{
		IMAGEMANAGER->findImage("도감")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 0, 0);
		WCHAR pokemon_book[1024];
		swprintf_s(pokemon_book, L"포켓몬 도감 목록");
		D2DMANAGER->drawText(pokemon_book, 285 + CAMERA->getPosX(), 10 + CAMERA->getPosY(), 48, RGB(160, 160, 160));
		swprintf_s(pokemon_book, L"포켓몬 도감 목록");
		D2DMANAGER->drawText(pokemon_book, 280 + CAMERA->getPosX(), 10 + CAMERA->getPosY(), 48, RGB(255,255,255));

	}
	else if (_cm._cstate == POKEMON && _cm._ms == YES)
	{
		IMAGEMANAGER->findImage("보유중포켓몬")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
		IMAGEMANAGER->findImage("메인포켓몬")->frameRender(0 + CAMERA->getPosX(), 60 + CAMERA->getPosY(), 0, 0);
		MENUMANAGER->findMenuFrame("포켓몬프레임1")->render("타입1");
		IMAGEMANAGER->findImage("포켓몬메뉴_취소")->frameRender(735 + CAMERA->getPosX(), 530 + CAMERA->getPosY(), 0, 0);
		IMAGEMANAGER->findImage("서브포켓몬")->frameRender(345 + CAMERA->getPosX(), 20 + CAMERA->getPosY(), 0, 0);
		
		switch (_cmpm._pcs)
		{
			case MAIN_POKEMON:
				IMAGEMANAGER->findImage("메인포켓몬")->frameRender(0 + CAMERA->getPosX(), 60 + CAMERA->getPosY(), 0, 1);
			break;
			case SUB_POKEMON1:

			break;
			case SUB_POKEMON2:

			break;
			case SUB_POKEMON3:

			break;
			case SUB_POKEMON4:

			break;
			case SUB_POKEMON5:

			break;
			case CANCEL:
				IMAGEMANAGER->findImage("포켓몬메뉴_취소")->frameRender(735 + CAMERA->getPosX(), 530 + CAMERA->getPosY(), 0, 1);
			break;
		}

		WCHAR pokemon[1024];
		swprintf_s(pokemon, L"취소");
		D2DMANAGER->drawText(pokemon, 820 + CAMERA->getPosX(), 552 + CAMERA->getPosY(), 48, RGB(255, 255, 255));
	}
	else if (_cm._cstate == BAG && _cm._ms == YES)
	{
		//if (_isMale)b
		{

		}
	}
	else if (_cm._cstate == PLAYER && _cm._ms == YES)
	{
		IMAGEMANAGER->findImage("트레이너카드")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 1, 0);
	}
	else if (_cm._cstate == SAVE_REPORT && _cm._ms == YES)
	{

	}
	else if (_cm._cstate == SETTING && _cm._ms == YES)
	{
		IMAGEMANAGER->findImage("테스트2")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
		IMAGEMANAGER->findImage("기본상단")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
		MENUMANAGER->findMenuFrame("설정프레임1")->render("타입1");
		MENUMANAGER->findMenuFrame("설정프레임2")->render("타입1");
		
		WCHAR settingtext[1024];
		swprintf_s(settingtext, L"포켓몬스터 파이어레드 환경설정");
		D2DMANAGER->drawText(settingtext, 120 + CAMERA->getPosX(), 100 + CAMERA->getPosY(), 48);
	}
	

	//WCHAR aa[1024];
	//swprintf_s(aa, L"하위메뉴상태: %d", _cm._ms);
	//D2DMANAGER->drawText(aa, 140 + CAMERA->getPosX(), 150 + CAMERA->getPosY(), 40);
}

void hayoungTestScene::frameImageinit()
{
	IMAGEMANAGER->addImage("기본하단", L"image/common_menu/common_menu_bg.png", 960, 160);
	IMAGEMANAGER->addImage("기본상단", L"image/common_menu/common_menu_top.png", 960, 64);
	IMAGEMANAGER->addImage("화살표", L"image/common_menu/pokemonMenu_cursor.png", 24, 40);
	IMAGEMANAGER->addImage("테스트", L"image/test/aaa.png", 960, 640);
	IMAGEMANAGER->addImage("테스트2", L"image/test/bbb.png", 960, 640);

}

void hayoungTestScene::commonMenuinit()
{
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
	_cm._ms = NO;

	_isCommonMenu = false;
}

void hayoungTestScene::commonMenurender()
{

	if (_isCommonMenu)
	{
		IMAGEMANAGER->findImage("테스트")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
		MENUMANAGER->findMenuFrame("기본메뉴")->render("타입1");

		IMAGEMANAGER->findImage("기본하단")->render(_rc.left + CAMERA->getPosX(), _rc.top + CAMERA->getPosY());

		WCHAR str[1024];
		swprintf_s(str, L"메뉴선택상태: %d", _cm._cstate);
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
			D2DMANAGER->drawText(str, _cm._bottom.left + 10 + CAMERA->getPosX(), _cm._bottom.top + 15 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
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
