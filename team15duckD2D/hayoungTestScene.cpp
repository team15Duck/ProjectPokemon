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
	UIMANAGER->uiDataSetting();
	return S_OK;
}

void hayoungTestScene::release()
{
}

void hayoungTestScene::update()
{
	UIMANAGER->update();
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		UIMANAGER->selectUI(UI_MAIN);
	}

	/*
	//메인메뉴 활성화하기
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		_mmselect = MMS_YES;

	}
	//메인메뉴 이동하기

	if (_mmselect == MMS_YES && _smselect == SMS_NO)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			//=========================== 설정
			//메뉴간의 이동은 메인메뉴에서만 가능하다
			//===============================
			switch (_cselect)
			{
			case POKEMON_BOOK:
				_cselect = POKEMON;
				break;
			case POKEMON:
				_cselect = BAG_ITEM;
				break;
			case BAG_ITEM:
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
			case BAG_ITEM:
				_cselect = POKEMON;
				break;
			case PLAYER:
				_cselect = BAG_ITEM;
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
			//uimanager.selectUI(ui_bag);

			_smselect = SMS_YES;

			if (_ppokemon->getstate() == 1)
			{
				_smselect = SMS_YES;

			}
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

	//======================= 특별케이스
	_book->update();
	_bag->update();

	// 프레임 세팅 
	if (_mmselect == MMS_YES && _smselect == SMS_YES && _cselect == SETTING)
	{
		_setting->update();
	}
	if (_mmselect == MMS_YES && _smselect == SMS_YES && _cselect == POKEMON)
	{
		_ppokemon->update();
	}
	//=================================
	*/
}

void hayoungTestScene::render()
{
	UIMANAGER->render();
}

void hayoungTestScene::frameImageinit()
{

}

void hayoungTestScene::setiteminit()
{
	ITEMDATA->settingItemInfo(MONSTER_BALL);
	ITEMDATA->settingItemInfo(SUPER_BALL);
	ITEMDATA->settingItemInfo(HYPER_BALL);
	ITEMDATA->settingItemInfo(MASTER_BALL);

	ITEMDATA->settingItemInfo(NORMAL_POTION);
	ITEMDATA->settingItemInfo(SUPER_POTION);
	ITEMDATA->settingItemInfo(HYPER_POTION);
	ITEMDATA->settingItemInfo(MAX_POTION);
	ITEMDATA->settingItemInfo(FULL_RESTORE);

	ITEMDATA->settingItemInfo(NORMAL_ETHER);
	ITEMDATA->settingItemInfo(MAX_ETHER);
	ITEMDATA->settingItemInfo(NORMAL_ELIXIR);
	ITEMDATA->settingItemInfo(MAX_ELIXIR);

	ITEMDATA->settingItemInfo(ANTIDOTE);
	ITEMDATA->settingItemInfo(PARLYZE_HEAL);
	ITEMDATA->settingItemInfo(BURN_HEAL);
	ITEMDATA->settingItemInfo(ICE_HEAL);
	ITEMDATA->settingItemInfo(AWAKENING);
	ITEMDATA->settingItemInfo(FULL_HEAL);

	ITEMDATA->settingItemInfo(RARE_CANDY);
	ITEMDATA->settingItemInfo(ESCAPE_ROPE);
	ITEMDATA->settingItemInfo(REVIVE);

	ITEMDATA->settingItemInfo(BICYCLE);
	ITEMDATA->settingItemInfo(FISHING_ROD);
	ITEMDATA->settingItemInfo(TOWN_MAP);

	ITEMDATA->settingItemInfo(HM_CUT);
	ITEMDATA->settingItemInfo(HM_FLASH);

	ITEMDATA->settingItemInfo(HM_FLASH);
	ITEMDATA->settingItemInfo(HM_FLASH);
	ITEMDATA->settingItemInfo(HM_FLASH);

	ITEMDATA->settingItemInfo(CHERI_BERRY);
	ITEMDATA->settingItemInfo(CHESTO_BERRY);
	ITEMDATA->settingItemInfo(PECHA_BERRY);
	ITEMDATA->settingItemInfo(RAWST_BERRY);
	ITEMDATA->settingItemInfo(ASPEAR_BERRY);
	ITEMDATA->settingItemInfo(LEPPA_BERRY);
	ITEMDATA->settingItemInfo(ORAN_BERRY);
	ITEMDATA->settingItemInfo(LUM_BERRY);
	ITEMDATA->settingItemInfo(SITRUS_BERRY);
}

void hayoungTestScene::commonMenurender()
{
	/*
	//만약에 메인메뉴가 선택된 상태라면 그림을 그리세요
	if (_mmselect == MMS_YES)
	{
		//=================================================================나중에 삭제해야할 테스트용 배경
		IMAGEMANAGER->findImage("테스트")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
		//=============================================================================================

		//프레임 깔아주기
		MENUMANAGER->findMenuFrame("메인메뉴")->render();
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
	*/
}
