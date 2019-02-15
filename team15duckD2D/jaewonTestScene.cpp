#include "stdafx.h"
#include "jaewonTestScene.h"


jaewonTestScene::jaewonTestScene()
{
}


jaewonTestScene::~jaewonTestScene()
{
}

HRESULT jaewonTestScene::init()
{
	_bgmKey = nullptr;
	_effectKey = nullptr;


	return S_OK;
}

void jaewonTestScene::release()
{
}

void jaewonTestScene::update()
{
	_bgmKey = "startSceneBgm";
	SOUNDMANAGER->addSound(_bgmKey, _vBgmString[0], true, false);
	SOUNDMANAGER->addSound("startBattleBgm", _vBgmString[1], true, false);
	SOUNDMANAGER->addSound("titleBgm", _vBgmString[2], true, false);

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		SOUNDMANAGER->play(_bgmKey);
	}
	//»Ï·Î·Õ ³¡³µÀ¸¸é ¹è
	if (!SOUNDMANAGER->isPlaySound(_bgmKey))
	{
		SOUNDMANAGER->play("startBattleBgm");
		if (!SOUNDMANAGER->isPlaySound("startBattleBgm"))
		{
			SOUNDMANAGER->play("titleBgm");
		}
	}


}

void jaewonTestScene::render()
{
}
