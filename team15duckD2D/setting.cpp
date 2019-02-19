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
	_sbgMusic = BG_SOUND_5;
	_seffSound = E_SOUND_5;
	_currentSelectNum = 0;

	_sframeType = SETTING_FRAME_TYPE1;

	MENUMANAGER->addFrame("설정프레임1", 80, 64, 25, 4);
	MENUMANAGER->addFrame("설정프레임2", 0, 192, 30, 14);

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
				_smenu = BACKGROUND_MUSIC;
			break;
		}
	
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		switch (_smenu)
		{
		case BACKGROUND_MUSIC:
			_smenu = FRAMETYPE;
		break;
		case EFFECT_SOUND:
			_smenu = BACKGROUND_MUSIC;
		break;
		case FRAMETYPE:
			_smenu = EFFECT_SOUND;
		break;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		switch (_smenu)
		{
		case BACKGROUND_MUSIC:
			switch (_sbgMusic)
			{
				case BG_SOUND_0:
					_sbgMusic = BG_SOUND_1;
				break;
				case BG_SOUND_1:
					_sbgMusic = BG_SOUND_2;
				break;
				case BG_SOUND_2:
					_sbgMusic = BG_SOUND_3;
				break;
				case BG_SOUND_3:
					_sbgMusic = BG_SOUND_4;
				break;
				case BG_SOUND_4:
					_sbgMusic = BG_SOUND_5;
				break;
				case BG_SOUND_5:
					_sbgMusic = BG_SOUND_6;
				break;
				case BG_SOUND_6:
					_sbgMusic = BG_SOUND_7;
				break;
				case BG_SOUND_7:
					_sbgMusic = BG_SOUND_8;
				break;
				case BG_SOUND_8:
					_sbgMusic = BG_SOUND_9;
				break;
				case BG_SOUND_9:
					_sbgMusic = BG_SOUND_10;
				break;
				case BG_SOUND_10:
					_sbgMusic = BG_SOUND_0;
				break;
			}
			break;
		case EFFECT_SOUND:
			switch (_seffSound)
			{
				case E_SOUND_0:
					_seffSound = E_SOUND_1;
				break;
				case E_SOUND_1:
					_seffSound = E_SOUND_2;
				break;
				case E_SOUND_2:
					_seffSound = E_SOUND_3;
				break;
				case E_SOUND_3:
					_seffSound = E_SOUND_4;
				break;
				case E_SOUND_4:
					_seffSound = E_SOUND_5;
				break;
				case E_SOUND_5:
					_seffSound = E_SOUND_6;
				break;
				case E_SOUND_6:
					_seffSound = E_SOUND_7;
				break;
				case E_SOUND_7:
					_seffSound = E_SOUND_8;
				break;
				case E_SOUND_8:
					_seffSound = E_SOUND_9;
				break;
				case E_SOUND_9:
					_seffSound = E_SOUND_10;
				break;
				case E_SOUND_10:
					_seffSound = E_SOUND_0;
				break;
			}
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
		}

		
	}

	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		UIMANAGER->moveBeforeUI();
	}

	//배경음악 소리설정
	switch (_sbgMusic)
	{
	case BG_SOUND_0:
		SOUNDMANAGER->setBgmVolume(0.0f);
		break;
	case BG_SOUND_1:
		SOUNDMANAGER->setBgmVolume(0.1f);
		break;
	case BG_SOUND_2:
		SOUNDMANAGER->setBgmVolume(0.2f);
		break;
	case BG_SOUND_3:
		SOUNDMANAGER->setBgmVolume(0.3f);
		break;
	case BG_SOUND_4:
		SOUNDMANAGER->setBgmVolume(0.4f);
		break;
	case BG_SOUND_5:
		SOUNDMANAGER->setBgmVolume(0.5f);
		break;
	case BG_SOUND_6:
		SOUNDMANAGER->setBgmVolume(0.6f);
		break;
	case BG_SOUND_7:
		SOUNDMANAGER->setBgmVolume(0.7f);
		break;
	case BG_SOUND_8:
		SOUNDMANAGER->setBgmVolume(0.8f);
		break;
	case BG_SOUND_9:
		SOUNDMANAGER->setBgmVolume(0.9f);
		break;
	case BG_SOUND_10:
		SOUNDMANAGER->setBgmVolume(1.0f);
		break;
	}
	//효과음 소리설정
	switch (_seffSound)
	{
	case E_SOUND_0:
		SOUNDMANAGER->setEffectVolume(0.0f);
		break;
	case E_SOUND_1:
		SOUNDMANAGER->setEffectVolume(0.1f);
		break;
	case E_SOUND_2:
		SOUNDMANAGER->setEffectVolume(0.2f);
		break;
	case E_SOUND_3:
		SOUNDMANAGER->setEffectVolume(0.3f);
		break;
	case E_SOUND_4:
		SOUNDMANAGER->setEffectVolume(0.4f);
		break;
	case E_SOUND_5:
		SOUNDMANAGER->setEffectVolume(0.5f);
		break;
	case E_SOUND_6:
		SOUNDMANAGER->setEffectVolume(0.6f);
		break;
	case E_SOUND_7:
		SOUNDMANAGER->setEffectVolume(0.7f);
		break;
	case E_SOUND_8:
		SOUNDMANAGER->setEffectVolume(0.8f);
		break;
	case E_SOUND_9:
		SOUNDMANAGER->setEffectVolume(0.9f);
		break;
	case E_SOUND_10:
		SOUNDMANAGER->setEffectVolume(1.0f);
		break;
	}

	setframeType(_sframeType);
}

void setting::render()
{
	//IMAGEMANAGER->findImage("테스트2")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
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

	switch (_sbgMusic)
	{
	case BG_SOUND_0:
		swprintf_s(settingtext, L"볼륨크기 0");
		D2DMANAGER->drawText(settingtext, 680 + CAMERA->getPosX(), 250 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case BG_SOUND_1:
		swprintf_s(settingtext, L"볼륨크기 1");
		D2DMANAGER->drawText(settingtext, 680 + CAMERA->getPosX(), 250 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case BG_SOUND_2:
		swprintf_s(settingtext, L"볼륨크기 2");
		D2DMANAGER->drawText(settingtext, 680 + CAMERA->getPosX(), 250 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case BG_SOUND_3:
		swprintf_s(settingtext, L"볼륨크기 3");
		D2DMANAGER->drawText(settingtext, 680 + CAMERA->getPosX(), 250 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case BG_SOUND_4:
		swprintf_s(settingtext, L"볼륨크기 4");
		D2DMANAGER->drawText(settingtext, 680 + CAMERA->getPosX(), 250 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case BG_SOUND_5:
		swprintf_s(settingtext, L"볼륨크기 5");
		D2DMANAGER->drawText(settingtext, 680 + CAMERA->getPosX(), 250 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case BG_SOUND_6:
		swprintf_s(settingtext, L"볼륨크기 6");
		D2DMANAGER->drawText(settingtext, 680 + CAMERA->getPosX(), 250 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case BG_SOUND_7:
		swprintf_s(settingtext, L"볼륨크기 7");
		D2DMANAGER->drawText(settingtext, 680 + CAMERA->getPosX(), 250 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case BG_SOUND_8:
		swprintf_s(settingtext, L"볼륨크기 8");
		D2DMANAGER->drawText(settingtext, 680 + CAMERA->getPosX(), 250 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case BG_SOUND_9:
		swprintf_s(settingtext, L"볼륨크기 9");
		D2DMANAGER->drawText(settingtext, 680 + CAMERA->getPosX(), 250 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case BG_SOUND_10:
		swprintf_s(settingtext, L"볼륨크기 10");
		D2DMANAGER->drawText(settingtext, 680 + CAMERA->getPosX(), 250 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	}

	//효과음 소리설정
	switch (_seffSound)
	{
	case E_SOUND_0:
		swprintf_s(settingtext, L"볼륨크기 0");
		D2DMANAGER->drawText(settingtext, 680 + CAMERA->getPosX(), 350 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case E_SOUND_1:
		swprintf_s(settingtext, L"볼륨크기 1");
		D2DMANAGER->drawText(settingtext, 680 + CAMERA->getPosX(), 350 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case E_SOUND_2:
		swprintf_s(settingtext, L"볼륨크기 2");
		D2DMANAGER->drawText(settingtext, 680 + CAMERA->getPosX(), 350 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case E_SOUND_3:
		swprintf_s(settingtext, L"볼륨크기 3");
		D2DMANAGER->drawText(settingtext, 680 + CAMERA->getPosX(), 350 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case E_SOUND_4:
		swprintf_s(settingtext, L"볼륨크기 4");
		D2DMANAGER->drawText(settingtext, 680 + CAMERA->getPosX(), 350 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case E_SOUND_5:
		swprintf_s(settingtext, L"볼륨크기 5");
		D2DMANAGER->drawText(settingtext, 680 + CAMERA->getPosX(), 350 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case E_SOUND_6:
		swprintf_s(settingtext, L"볼륨크기 6");
		D2DMANAGER->drawText(settingtext, 680 + CAMERA->getPosX(), 350 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case E_SOUND_7:
		swprintf_s(settingtext, L"볼륨크기 7");
		D2DMANAGER->drawText(settingtext, 680 + CAMERA->getPosX(), 350 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case E_SOUND_8:
		swprintf_s(settingtext, L"볼륨크기 8");
		D2DMANAGER->drawText(settingtext, 680 + CAMERA->getPosX(), 350 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case E_SOUND_9:
		swprintf_s(settingtext, L"볼륨크기 9");
		D2DMANAGER->drawText(settingtext, 680 + CAMERA->getPosX(), 350 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	case E_SOUND_10:
		swprintf_s(settingtext, L"볼륨크기 10");
		D2DMANAGER->drawText(settingtext, 680 + CAMERA->getPosX(), 350 + CAMERA->getPosY(), 40, RGB(255, 0, 0));
		break;
	}

}

void setting::setframeType(SETTING_FRAME_TYPE sframeType)
{
	_sframeType = sframeType;
	MENUMANAGER->setFrameType(sframeType);

}
