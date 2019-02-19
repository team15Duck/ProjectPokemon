#include "stdafx.h"
#include "object.h"


object::object()
{
}


object::~object()
{
}

HRESULT object::init()
{
	//이거 나중에 옮기라
	IMAGEMANAGER->addFrameImage("healingBall", L"image/object/healing_Pokemon.png", 120, 24, 5, 1);
	_isHealing = false;
	_count = 0;
	_ballX = 0;

	return S_OK;
}

void object::release()
{
}

void object::update()
{
	
	if (KEYMANAGER->isOnceKeyDown(VK_F9))
	{
		_isHealing = true;
		
	}
	
	if (_isHealing)
		aniSetting();
}

void object::render()
{
	//테슷흐
	IMAGEMANAGER->findImage("healingBall")->frameRender(15 * 64 + 38, 8 * 64 + 36, _ballX, 0);
}


void object::aniSetting()
{
	_count++;
	if (_count % 5 == 0)
	{
		_ballX++;
		if (_ballX >= 4) _ballX = 1;
		_count = 0;
	}
}

void object::startAni()
{
}
