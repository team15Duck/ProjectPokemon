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
	_smenu = BACKGROUND_MUSIC;
	_currentSelectNum = 0;

	_sframeType = SETTING_FRAME_TYPE1;

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
		switch (_smenu)
		{
			case BACKGROUND_MUSIC:
				_smenu = EFFECT_SOUND;
			break;
			case EFFECT_SOUND:
				_smenu = FRAMETYPE;
			break;
			case FRAMETYPE:
				_smenu = SM_SELECT;
			break;
			case SM_SELECT:
				_smenu = BACKGROUND_MUSIC;
			break;
		}
	
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		switch (_smenu)
		{
		case BACKGROUND_MUSIC:
			_smenu = SM_SELECT;
			break;
		case EFFECT_SOUND:
			_smenu = BACKGROUND_MUSIC;
			break;
		case FRAMETYPE:
			_smenu = EFFECT_SOUND;
			break;
		case SM_SELECT:
			_smenu = FRAMETYPE;
			break;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		switch (_smenu)
		{
		case BACKGROUND_MUSIC:
			
			break;
		case EFFECT_SOUND:
			
			break;
		case FRAMETYPE:
			switch (_sframeType)
			{
				case SETTING_FRAME_TYPE1:
					_sframeType = SETTING_FRAME_TYPE2;
				break;
				case SETTING_FRAME_TYPE2:
					_sframeType = SETTING_FRAME_TYPE3;
				break;
				case SETTING_FRAME_TYPE3:
					_sframeType = SETTING_FRAME_TYPE4;
				break;
				case SETTING_FRAME_TYPE4:
					_sframeType = SETTING_FRAME_TYPE5;
				break;
				case SETTING_FRAME_TYPE5:
					_sframeType = SETTING_FRAME_TYPE6;
				break;
				case SETTING_FRAME_TYPE6:
					_sframeType = SETTING_FRAME_TYPE7;
				break;
				case SETTING_FRAME_TYPE7:
					_sframeType = SETTING_FRAME_TYPE8;
				break;
				case SETTING_FRAME_TYPE8:
					_sframeType = SETTING_FRAME_TYPE9;
				break;
				case SETTING_FRAME_TYPE9:
					_sframeType = SETTING_FRAME_TYPE10;
				break;
				case SETTING_FRAME_TYPE10:
					_sframeType = SETTING_FRAME_TYPE1;
				break;
			}
			break;
		case SM_SELECT:
			
			break;
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		switch (_smenu)
		{
		case BACKGROUND_MUSIC:

			break;
		case EFFECT_SOUND:

			break;
		case FRAMETYPE:
			switch (_sframeType)
			{
				case SETTING_FRAME_TYPE1:
					_sframeType = SETTING_FRAME_TYPE10;
					break;
				case SETTING_FRAME_TYPE2:
					_sframeType = SETTING_FRAME_TYPE1;
					break;
				case SETTING_FRAME_TYPE3:
					_sframeType = SETTING_FRAME_TYPE2;
					break;
				case SETTING_FRAME_TYPE4:
					_sframeType = SETTING_FRAME_TYPE3;
					break;
				case SETTING_FRAME_TYPE5:
					_sframeType = SETTING_FRAME_TYPE4;
					break;
				case SETTING_FRAME_TYPE6:
					_sframeType = SETTING_FRAME_TYPE5;
					break;
				case SETTING_FRAME_TYPE7:
					_sframeType = SETTING_FRAME_TYPE6;
					break;
				case SETTING_FRAME_TYPE8:
					_sframeType = SETTING_FRAME_TYPE7;
					break;
				case SETTING_FRAME_TYPE9:
					_sframeType = SETTING_FRAME_TYPE8;
					break;
				case SETTING_FRAME_TYPE10:
					_sframeType = SETTING_FRAME_TYPE9;
					break;
			}
			break;
		case SM_SELECT:

			break;
		}

		
	}

	setframeType(_sframeType);
}

void setting::render()
{
	IMAGEMANAGER->findImage("테스트2")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
	IMAGEMANAGER->findImage("기본상단")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
	MENUMANAGER->findMenuFrame("설정프레임1")->render();
	MENUMANAGER->findMenuFrame("설정프레임2")->render();

	WCHAR settingtext[1024];
	swprintf_s(settingtext, L"포켓몬스터 파이어레드 환경설정");
	D2DMANAGER->drawText(settingtext, 120 + CAMERA->getPosX(), 100 + CAMERA->getPosY(), 48);

	swprintf_s(settingtext, L"배경음");
	D2DMANAGER->drawText(settingtext, 80 + CAMERA->getPosX(), 250 + CAMERA->getPosY(), 40);
	swprintf_s(settingtext, L"효과음");
	D2DMANAGER->drawText(settingtext, 80 + CAMERA->getPosX(), 350 + CAMERA->getPosY(), 40);
	swprintf_s(settingtext, L"프레임");
	D2DMANAGER->drawText(settingtext, 80 + CAMERA->getPosX(), 450 + CAMERA->getPosY(), 40);

	swprintf_s(settingtext, L"결정");
	D2DMANAGER->drawText(settingtext, 80 + CAMERA->getPosX(), 550 + CAMERA->getPosY(), 40);

	switch (_smenu)
	{
	case BACKGROUND_MUSIC:
		IMAGEMANAGER->findImage("화살표")->render(48 + CAMERA->getPosX(), 250 + CAMERA->getPosY());
		break;
	case EFFECT_SOUND:
		IMAGEMANAGER->findImage("화살표")->render(48 + CAMERA->getPosX(), 350 + CAMERA->getPosY());
		break;
	case FRAMETYPE:
		IMAGEMANAGER->findImage("화살표")->render(48 + CAMERA->getPosX(), 450 + CAMERA->getPosY());
		break;
	case SM_SELECT:
		IMAGEMANAGER->findImage("화살표")->render(48 + CAMERA->getPosX(), 550 + CAMERA->getPosY());
		break;
	}

	switch (_sframeType)
	{
	case SETTING_FRAME_TYPE1:
		swprintf_s(settingtext, L"타입1");
		D2DMANAGER->drawText(settingtext, 750 + CAMERA->getPosX(), 450 + CAMERA->getPosY(), 40, RGB(255,0,0));
		break;
	case SETTING_FRAME_TYPE2:
		swprintf_s(settingtext, L"타입2");
		D2DMANAGER->drawText(settingtext, 750 + CAMERA->getPosX(), 450 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case SETTING_FRAME_TYPE3:
		swprintf_s(settingtext, L"타입3");
		D2DMANAGER->drawText(settingtext, 750 + CAMERA->getPosX(), 450 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case SETTING_FRAME_TYPE4:
		swprintf_s(settingtext, L"타입4");
		D2DMANAGER->drawText(settingtext, 750 + CAMERA->getPosX(), 450 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case SETTING_FRAME_TYPE5:
		swprintf_s(settingtext, L"타입5");
		D2DMANAGER->drawText(settingtext, 750 + CAMERA->getPosX(), 450 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case SETTING_FRAME_TYPE6:
		swprintf_s(settingtext, L"타입6");
		D2DMANAGER->drawText(settingtext, 750 + CAMERA->getPosX(), 450 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case SETTING_FRAME_TYPE7:
		swprintf_s(settingtext, L"타입7");
		D2DMANAGER->drawText(settingtext, 750 + CAMERA->getPosX(), 450 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case SETTING_FRAME_TYPE8:
		swprintf_s(settingtext, L"타입8");
		D2DMANAGER->drawText(settingtext, 750 + CAMERA->getPosX(), 450 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case SETTING_FRAME_TYPE9:
		swprintf_s(settingtext, L"타입9");
		D2DMANAGER->drawText(settingtext, 750 + CAMERA->getPosX(), 450 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case SETTING_FRAME_TYPE10:
		swprintf_s(settingtext, L"타입10");
		D2DMANAGER->drawText(settingtext, 750 + CAMERA->getPosX(), 450 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	}
}

void setting::setframeType(SETTING_FRAME_TYPE sframeType)
{
	_sframeType = sframeType;
	MENUMANAGER->setFrameType(sframeType);

}
