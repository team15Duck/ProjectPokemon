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
	_bgmKey.clear();
	_effectKey.clear();

	_bgmKey = "startSceneBgm";
	SOUNDMANAGER->addSound(_bgmKey, _vBgmString[1], true, false);
	SOUNDMANAGER->addSound("startBattleBgm", _vBgmString[2], true, false);
	SOUNDMANAGER->addSound("titleBgm", _vBgmString[3], true, false);

	_soundKeys[0] = "startSceneBgm";
	_soundKeys[1] = "startBattleBgm";
	_soundKeys[2] = "titleBgm";

	_idx = 0;

	SOUNDMANAGER->play(_soundKeys[_idx]);

	_imgKeys[0] = "tempStartScene1";
	_imgKeys[1] = "tempStartScene2";
	_imgKeys[2] = "tempStartScene3";

	IMAGEMANAGER->addFrameImage(_imgKeys[0], L"image/tempStartImg1.png", 960, 640, 1, 1);
	IMAGEMANAGER->addFrameImage(_imgKeys[1], L"image/tempStartImg2.png", 960, 640, 1, 1);
	IMAGEMANAGER->addFrameImage(_imgKeys[2], L"image/tempStartImg3.png", 960, 640, 1, 1);

	//KEYANIMANAGER->start();

	return S_OK;
}

void jaewonTestScene::release()
{
}

void jaewonTestScene::update()
{
	if (3 <= _idx)
		return;
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		SOUNDMANAGER->stop(_soundKeys[_idx]);
	}
	
	if (!SOUNDMANAGER->isPlaySound(_soundKeys[_idx]))
	{
		++_idx;
		if (3 <= _idx)
		{
			SCENEMANAGER->changeScene("mapTestScene");
			return;
		}
	
		SOUNDMANAGER->play(_soundKeys[_idx]);
	}
	IMAGEMANAGER->findImage(_imgKeys[_idx]);
}

void jaewonTestScene::render()
{
	IMAGEMANAGER->render(_imgKeys[_idx]);
	//KEYANIMANAGER->findAnimation(_imgKeys[_idx])
}
