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
	_book = new IllustratedBook;
	_book->init();
	_book->pokemonDataSet();

	frameImageinit();
	//commonMenuinit();

	_issubpkm1exist = true;
	_issubpkm2exist = false;
	_issubpkm3exist = false;
	_issubpkm4exist = false;
	_issubpkm5exist = false;

	_isFemale = false;
	_isMale = true;

	//메인메뉴 초기화 

	MENUMANAGER->addFrame("메인메뉴", 670, 1, 9, 15);

	//메인메뉴 선택했나요? 아니요
	_mmselect = MMS_NO;
	//서브메뉴 선택했나요? 아니오
	_smselect = SMS_NO;
	//커서는 처음에는 도감을 가르킵니다
	_cselect = POKEMON_BOOK;

	_cmpm._pcs = MAIN_POKEMON;


	//서브포켓몬 슬롯 
	for (int i = 0; i < 5; ++i)
	{
		float top = 35 + (i * 95);
		float bottom = 115 + (i * 95);

		_cmpm._subPokemon[i] = { 450, top, 950 , bottom };
	}

	MENUMANAGER->addFrame("설정프레임1", 80, 64, 25, 4);
	MENUMANAGER->addFrame("설정프레임2", 0, 192, 30, 14);
	MENUMANAGER->addFrame("포켓몬프레임1", 0, 512, 23, 4);

	// IMAGEMANAGER->addImage("남자가방", L"image/common_menu/bag/bag1.png", 236, 257);
	// IMAGEMANAGER->addImage("여자가방", L"image/common_menu/bag/bag2.png", 236, 244);
	IMAGEMANAGER->addFrameImage("남여가방", L"image/common_menu/bag/item_bag.png", 472, 257, 2, 1);

	return S_OK;
}

void hayoungTestScene::release()
{
}

void hayoungTestScene::update()
{

	//메인메뉴 활성화하기
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		_mmselect = MMS_YES;

	}
	//메인메뉴 이동하기
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		//=========================== 설정
		//메뉴간의 이동은 메인메뉴에서만 가능하다
		//===============================

		if (_mmselect == MMS_YES && _smselect == SMS_NO)
		{
			switch (_cselect)
			{
			case POKEMON_BOOK:
				_cselect = POKEMON;
				break;
			case POKEMON:
				_cselect = BAG;
				break;
			case BAG:
				_cselect = PLAYER;
				break;
			case PLAYER:
				_cselect = SAVE_REPORT;
				break;
			case SAVE_REPORT:
				_cselect = SETTING;
				break;
			case SETTING:
				_cselect = CLOSE;
				break;
			case CLOSE:
				_cselect = POKEMON_BOOK;
				break;
			}
		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		//=========================== 설정
		//메뉴간의 이동은 메인메뉴에서만 가능하다
		//===============================

		if (_mmselect == MMS_YES && _smselect == SMS_NO)
		{
			switch (_cselect)
			{
			case POKEMON_BOOK:
				_cselect = CLOSE;
				break;
			case POKEMON:
				_cselect = POKEMON_BOOK;
				break;
			case BAG:
				_cselect = POKEMON;
				break;
			case PLAYER:
				_cselect = BAG;
				break;
			case SAVE_REPORT:
				_cselect = PLAYER;
				break;
			case SETTING:
				_cselect = SAVE_REPORT;
				break;
			case CLOSE:
				_cselect = SETTING;
				break;
			}
		}
	}
	//하위메뉴 활성화하기
	if (_mmselect == MMS_YES && _smselect != SMS_YES)
	{
		//============================= 조건
		//하위메뉴 활성화 조건
		// ** 메인메뉴가 선택되고 하위메뉴는 선택이 안되어 있을때만 **
		//1. 상위(메인)메뉴가 YES상태여야한다.
		//2. 커서가 가르키는 값을 출력해야한다.
		//=============================

		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			_smselect = SMS_YES;
		}
	}
	//하위메뉴 비활성화 하기
	if (_mmselect == MMS_YES && _smselect == SMS_YES)
	{
		if (_book->getState() == 0)
		{
			if (KEYMANAGER->isOnceKeyDown('X'))
			{
				_smselect = SMS_NO;
			}
		}
	}
	//메인메뉴 비활성화하기
	if (_mmselect == MMS_YES && _smselect == SMS_NO)
	{
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			_mmselect = MMS_NO;
		}
	}

	//=================== 특별케이스 도감
	_book->update();
	//=================================


	/*
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
				_cmpm._pcs = SUB_POKEMON1;
				break;
			case SUB_POKEMON3:
				_cmpm._pcs = SUB_POKEMON2;
				break;
			case SUB_POKEMON4:
				_cmpm._pcs = SUB_POKEMON3;
				break;
			case SUB_POKEMON5:
				_cmpm._pcs = SUB_POKEMON4;
				break;
			case CANCEL:
				if (_issubpkm1exist && !_issubpkm2exist && !_issubpkm3exist && !_issubpkm4exist && !_issubpkm5exist)
				{
					_cmpm._pcs = SUB_POKEMON1;
				}
				else if (_issubpkm1exist && _issubpkm2exist && !_issubpkm3exist && !_issubpkm4exist && !_issubpkm5exist)
				{
					_cmpm._pcs = SUB_POKEMON2;
				}
				else if (_issubpkm1exist && _issubpkm2exist && _issubpkm3exist && !_issubpkm4exist && !_issubpkm5exist)
				{
					_cmpm._pcs = SUB_POKEMON3;
				}
				else if (_issubpkm1exist && _issubpkm2exist && _issubpkm3exist && _issubpkm4exist && !_issubpkm5exist)
				{
					_cmpm._pcs = SUB_POKEMON4;
				}
				else if (_issubpkm1exist && _issubpkm2exist && _issubpkm3exist && _issubpkm4exist && _issubpkm5exist)
				{
					_cmpm._pcs = SUB_POKEMON5;
				}
				break;
			}
		}
		//만약에 포켓몬 메뉴에서 아래키를 누르면
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			switch (_cmpm._pcs)
			{
			case MAIN_POKEMON:
				if (!_issubpkm1exist && !_issubpkm2exist && !_issubpkm3exist && !_issubpkm4exist && !_issubpkm5exist)
				{
					_cmpm._pcs = CANCEL;
				}
				else if (_issubpkm1exist)
				{
					_cmpm._pcs = SUB_POKEMON1;
				}
				break;
			case SUB_POKEMON1:
				if (_issubpkm2exist)
				{
					_cmpm._pcs = SUB_POKEMON2;
				}
				else
				{
					_cmpm._pcs = CANCEL;
				}
				break;
			case SUB_POKEMON2:
				if (_issubpkm3exist)
				{
					_cmpm._pcs = SUB_POKEMON3;
				}
				else
				{
					_cmpm._pcs = CANCEL;
				}
				break;
			case SUB_POKEMON3:
				if (_issubpkm4exist)
				{
					_cmpm._pcs = SUB_POKEMON4;
				}
				else
				{
					_cmpm._pcs = CANCEL;
				}
				break;
			case SUB_POKEMON4:
				if (_issubpkm5exist)
				{
					_cmpm._pcs = SUB_POKEMON5;
				}
				else
				{
					_cmpm._pcs = CANCEL;
				}
				break;
			case SUB_POKEMON5:
				_cmpm._pcs = CANCEL;
				break;
			case CANCEL:
				_cmpm._pcs = MAIN_POKEMON;
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

	_book->update();
	*/
}

void hayoungTestScene::render()
{
	commonMenurender();

	// ============================================================= 테스트 및 체크용 텍스트 출력 추후 삭제
	WCHAR test[1024];
	swprintf_s(test, L"메인메뉴상태: %d", _mmselect);
	D2DMANAGER->drawText(test, 0 + CAMERA->getPosX(), 400 + CAMERA->getPosY(), 40);
	// =================================================================================================

	//1. 포켓몬 도감 렌더
	//하위메뉴인 도감이 열리는 조건은 <메인메뉴가 열려있고, 커서가 포켓몬을 가르키고 , 하위메뉴를 선택> 했을때이다.
	if (_mmselect == MMS_YES && _cselect == POKEMON_BOOK && _smselect == SMS_YES)
	{
		_book->render();
	}
	//2. 보유중인 포켓몬 렌더
	if (_mmselect == MMS_YES && _cselect == POKEMON && _smselect == SMS_YES)
	{
		IMAGEMANAGER->findImage("보유중포켓몬")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
		MENUMANAGER->findMenuFrame("포켓몬프레임1")->render("타입1");
		IMAGEMANAGER->findImage("포켓몬메뉴_취소")->frameRender(735 + CAMERA->getPosX(), 530 + CAMERA->getPosY(), 0, 0);
	}
	//3. 가방 렌더
	if (_mmselect == MMS_YES && _cselect == BAG && _smselect == SMS_YES)
	{
		if (_isMale)
		{
			IMAGEMANAGER->findImage("가방메뉴배경")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 0, 0);
			IMAGEMANAGER->findImage("남여가방")->frameRender(100 + CAMERA->getPosX(), 200 + CAMERA->getPosY(), 0, 0);
		}
		else if (_isFemale)
		{
			IMAGEMANAGER->findImage("가방메뉴배경")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 1, 0);
		}

		WCHAR bag[1024];
		swprintf_s(bag, L"아이템");
		D2DMANAGER->drawText(bag, 110 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 40);
	}
	//4. 플레이어 정보 출력
	if (_mmselect == MMS_YES && _cselect == PLAYER && _smselect == SMS_YES)
	{
		IMAGEMANAGER->findImage("트레이너카드")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 1, 0);
	}
	//5. 리포트 < 세이브 > 출력
	if (_mmselect == MMS_YES && _cselect == SAVE_REPORT && _smselect == SMS_YES)
	{

	}
	//6. 설정 출력
	if (_mmselect == MMS_YES && _cselect == SETTING && _smselect == SMS_YES)
	{

	}
	/*
	if (_cm._cstate == POKEMON_BOOK && _cm._ms == YES)
	{
		_book->render();
	}
	else if (_cm._cstate == POKEMON && _cm._ms == YES)
	{
		IMAGEMANAGER->findImage("보유중포켓몬")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
		MENUMANAGER->findMenuFrame("포켓몬프레임1")->render("타입1");
		IMAGEMANAGER->findImage("포켓몬메뉴_취소")->frameRender(735 + CAMERA->getPosX(), 530 + CAMERA->getPosY(), 0, 0);

		if (_issubpkm1exist)
		{
			IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(_cmpm._subPokemon[0].left + CAMERA->getPosX(), _cmpm._subPokemon[0].top + CAMERA->getPosY(), 0, 0);
		}
		else if (!_issubpkm1exist)
		{
			IMAGEMANAGER->findImage("서브포켓몬1")->render(_cmpm._subPokemon[0].left + CAMERA->getPosX(), _cmpm._subPokemon[0].top + CAMERA->getPosY());
		}
		if (_issubpkm2exist)
		{
			IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(_cmpm._subPokemon[1].left + CAMERA->getPosX(), _cmpm._subPokemon[1].top + CAMERA->getPosY(), 0, 0);
		}
		else if (!_issubpkm2exist)
		{
			IMAGEMANAGER->findImage("서브포켓몬1")->render(_cmpm._subPokemon[1].left + CAMERA->getPosX(), _cmpm._subPokemon[1].top + CAMERA->getPosY());
		}
		if (_issubpkm3exist)
		{
			IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(_cmpm._subPokemon[2].left + CAMERA->getPosX(), _cmpm._subPokemon[2].top + CAMERA->getPosY(), 0, 0);
		}
		else if (!_issubpkm3exist)
		{
			IMAGEMANAGER->findImage("서브포켓몬1")->render(_cmpm._subPokemon[2].left + CAMERA->getPosX(), _cmpm._subPokemon[2].top + CAMERA->getPosY());
		}
		if (_issubpkm4exist)
		{
			IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(_cmpm._subPokemon[3].left + CAMERA->getPosX(), _cmpm._subPokemon[3].top + CAMERA->getPosY(), 0, 0);
		}
		else if (!_issubpkm4exist)
		{
			IMAGEMANAGER->findImage("서브포켓몬1")->render(_cmpm._subPokemon[3].left + CAMERA->getPosX(), _cmpm._subPokemon[3].top + CAMERA->getPosY());
		}
		if (_issubpkm5exist)
		{
			IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(_cmpm._subPokemon[4].left + CAMERA->getPosX(), _cmpm._subPokemon[4].top + CAMERA->getPosY(), 0, 0);
		}
		else if (!_issubpkm5exist)
		{
			IMAGEMANAGER->findImage("서브포켓몬1")->render(_cmpm._subPokemon[4].left + CAMERA->getPosX(), _cmpm._subPokemon[4].top + CAMERA->getPosY());
		}

		IMAGEMANAGER->findImage("메인포켓몬")->frameRender(65 + CAMERA->getPosX(), 65 + CAMERA->getPosY(), 0, 0);

		switch (_cmpm._pcs)
		{
		case MAIN_POKEMON:
				IMAGEMANAGER->findImage("메인포켓몬")->frameRender(65 + CAMERA->getPosX(), 64 + CAMERA->getPosY(), 0, 1);
			break;
			case SUB_POKEMON1:
				IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(_cmpm._subPokemon[0].left + CAMERA->getPosX(), _cmpm._subPokemon[0].top + CAMERA->getPosY(), 1, 0);
			break;
			case SUB_POKEMON2:
				IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(_cmpm._subPokemon[1].left + CAMERA->getPosX(), _cmpm._subPokemon[1].top + CAMERA->getPosY(), 1, 0);
			break;
			case SUB_POKEMON3:
				IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(_cmpm._subPokemon[2].left + CAMERA->getPosX(), _cmpm._subPokemon[2].top + CAMERA->getPosY(), 1, 0);
			break;
			case SUB_POKEMON4:
				IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(_cmpm._subPokemon[3].left + CAMERA->getPosX(), _cmpm._subPokemon[3].top + CAMERA->getPosY(), 1, 0);
			break;
			case SUB_POKEMON5:
				IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(_cmpm._subPokemon[4].left + CAMERA->getPosX(), _cmpm._subPokemon[4].top + CAMERA->getPosY(), 1, 0);
			break;
			case CANCEL:
				IMAGEMANAGER->findImage("포켓몬메뉴_취소")->frameRender(735 + CAMERA->getPosX(), 530 + CAMERA->getPosY(), 0, 1);
			break;
		}

		WCHAR pokemon[1024];
		swprintf_s(pokemon, L"취소");
		D2DMANAGER->drawText(pokemon, 820 + CAMERA->getPosX(), 552 + CAMERA->getPosY(), 48, RGB(255, 255, 255));
		swprintf_s(pokemon, L"포켓몬을 선택해 주십시오.");
		D2DMANAGER->drawText(pokemon, 50 + CAMERA->getPosX(), 550 + CAMERA->getPosY(), 48, RGB(0, 0, 0));
	}
	else if (_cm._cstate == BAG && _cm._ms == YES)
	{
		if (_isMale)
		{
			IMAGEMANAGER->findImage("가방메뉴배경")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 0, 0);
		}
		else if (_isFemale)
		{
			IMAGEMANAGER->findImage("가방메뉴배경")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 1, 0);
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
	*/
}

void hayoungTestScene::frameImageinit()
{
	IMAGEMANAGER->addImage("기본하단", L"image/common_menu/common_menu_bg.png", 960, 160);
	IMAGEMANAGER->addImage("기본상단", L"image/common_menu/common_menu_top.png", 960, 64);
	IMAGEMANAGER->addImage("화살표", L"image/common_menu/pokemonMenu_cursor.png", 24, 40);
	IMAGEMANAGER->addImage("테스트", L"image/test/aaa.png", 960, 640);
	IMAGEMANAGER->addImage("테스트2", L"image/test/bbb.png", 960, 640);
}

void hayoungTestScene::commonMenurender()
{
	//만약에 메인메뉴가 선택된 상태라면 그림을 그리세요
	if (_mmselect == MMS_YES)
	{
		//=================================================================나중에 삭제해야할 테스트용 배경
		IMAGEMANAGER->findImage("테스트")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
		//=============================================================================================

		//프레임 깔아주기
		MENUMANAGER->findMenuFrame("메인메뉴")->render("타입1");
		//하단텍스트 출력용 bg출력 
		IMAGEMANAGER->findImage("기본하단")->render(0 + CAMERA->getPosX(), 480 + CAMERA->getPosY());

		//텍스트 출력-
		WCHAR str[1024];
		swprintf_s(str, L"메뉴선택상태: %d", _cselect);
		D2DMANAGER->drawText(str, 100 + CAMERA->getPosX(), 100 + CAMERA->getPosY(), 40);

		swprintf_s(str, L"도감");
		D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 33 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"포켓몬");
		D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 93 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"가방");
		D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 153 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"닉네임출력");
		D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 213 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"리포트");
		D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 273 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"설정");
		D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 333 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"닫기");
		D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 393 + CAMERA->getPosY(), 40);

		switch (_cselect)
		{
		case POKEMON_BOOK:
			IMAGEMANAGER->findImage("화살표")->render(702 + CAMERA->getPosX(), 33 + CAMERA->getPosY());
			swprintf_s(str, L"도감에 기록된 포켓몬의 상세 정보를 확인합니다. ");
			D2DMANAGER->drawText(str, 10 + CAMERA->getPosX(), 500 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
			break;
		case POKEMON:
			IMAGEMANAGER->findImage("화살표")->render(702 + CAMERA->getPosX(), 93 + CAMERA->getPosY());
			swprintf_s(str, L"같이 있는 포켓몬의 상태를 확인하고 관리합니다.");
			D2DMANAGER->drawText(str, 10 + CAMERA->getPosX(), 500 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
			break;
		case BAG:
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
}
