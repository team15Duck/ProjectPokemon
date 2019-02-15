#include "stdafx.h"
#include "setting.h"


setting::setting()
{
}


setting::~setting()
{
}

HRESULT setting::init()
{
	//_smenu = SPEED;
	_currentSelectNum = 0;

	return S_OK;
}

void setting::release()
{
}

void setting::update()
{
	//설정메뉴기본이동
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		/*
		switch (_smenu)
		{
			case SPEED:
				_smenu = ANI;
			break;
			case ANI:
				_smenu = RULE;
			break;
			case RULE:
				_smenu = SOUND;
			break;
			case SOUND:
				_smenu = BUTTON;
			break;
			case BUTTON:
				_smenu = FRAMETYPE;
			break;
			case FRAMETYPE:
				_smenu = SM_SELECT;
			break;
			case SM_SELECT:
				_smenu = SPEED;
			break;
		}
		*/
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		/*
		switch (_smenu)
		{
		case SPEED:
			_smenu = SM_SELECT;
			break;
		case ANI:
			_smenu = SPEED;
			break;
		case RULE:
			_smenu = ANI;
			break;
		case SOUND:
			_smenu = RULE;
			break;
		case BUTTON:
			_smenu = SOUND;
			break;
		case FRAMETYPE:
			_smenu = BUTTON;
			break;
		case SM_SELECT:
			_smenu = FRAMETYPE;
			break;
		}
		*/
	}
}

void setting::render()
{
	IMAGEMANAGER->findImage("테스트2")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
	IMAGEMANAGER->findImage("기본상단")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
	MENUMANAGER->findMenuFrame("설정프레임1")->render("타입1");
	MENUMANAGER->findMenuFrame("설정프레임2")->render("타입1");

	WCHAR settingtext[1024];
	swprintf_s(settingtext, L"포켓몬스터 파이어레드 환경설정");
	D2DMANAGER->drawText(settingtext, 120 + CAMERA->getPosX(), 100 + CAMERA->getPosY(), 48);
	swprintf_s(settingtext, L"배경음");
	D2DMANAGER->drawText(settingtext, 80 + CAMERA->getPosX(), 230 + CAMERA->getPosY(), 40);

	swprintf_s(settingtext, L"효과음");
	D2DMANAGER->drawText(settingtext, 80 + CAMERA->getPosX(), 395 + CAMERA->getPosY(), 40);

	swprintf_s(settingtext, L"프레임");
	D2DMANAGER->drawText(settingtext, 80 + CAMERA->getPosX(), 505 + CAMERA->getPosY(), 40);
	swprintf_s(settingtext, L"결정");
	D2DMANAGER->drawText(settingtext, 80 + CAMERA->getPosX(), 560 + CAMERA->getPosY(), 40);

	/*
	switch (_smenu)
	{
	case SPEED:
		IMAGEMANAGER->findImage("화살표")->render(48 + CAMERA->getPosX(), 230 + CAMERA->getPosY());
		break;
	case ANI:
		IMAGEMANAGER->findImage("화살표")->render(48 + CAMERA->getPosX(), 285 + CAMERA->getPosY());
		break;
	case RULE:
		IMAGEMANAGER->findImage("화살표")->render(48 + CAMERA->getPosX(), 340 + CAMERA->getPosY());
		break;
	case SOUND:
		IMAGEMANAGER->findImage("화살표")->render(48 + CAMERA->getPosX(), 395 + CAMERA->getPosY());
		break;
	case BUTTON:
		IMAGEMANAGER->findImage("화살표")->render(48 + CAMERA->getPosX(), 450 + CAMERA->getPosY());
		break;
	case FRAMETYPE:
		IMAGEMANAGER->findImage("화살표")->render(48 + CAMERA->getPosX(), 505 + CAMERA->getPosY());
		break;
	case SM_SELECT:
		IMAGEMANAGER->findImage("화살표")->render(48 + CAMERA->getPosX(), 560 + CAMERA->getPosY());
		break;
	}
	*/
}
