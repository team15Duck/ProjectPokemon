#include "stdafx.h"
#include "timeManager.h"


timeManager::timeManager()
	: _timer(NULL)
{
}


timeManager::~timeManager()
{
}

HRESULT timeManager::init()
{
	_timer = new timer;
	_timer->init();

	return S_OK;
}

void timeManager::release()
{
	if (_timer != NULL) SAFE_DELETE(_timer);
}

void timeManager::update(float lockFPS)
{
	if (_timer != NULL)
	{
		_timer->tick(lockFPS);
	}
}

void timeManager::render()
{
	

	//디버그 상태면
#ifdef _DEBUG
	{
		WCHAR str[128];

		swprintf_s(str, L"framePerSec(FPS) : %d", _timer->getFrameRate(), (float)(MAPSIZEX - WINSIZEX));
		D2DMANAGER->drawText(str, CAMERA->getPosX(), CAMERA->getPosY());
		swprintf_s(str, L"worldTime : %f", _timer->getWorldTime());
		D2DMANAGER->drawText(str, CAMERA->getPosX(), CAMERA->getPosY() + 20);
		swprintf_s(str, L"elapsedTime : %f", _timer->getElapsedTime());
		D2DMANAGER->drawText(str, CAMERA->getPosX(), CAMERA->getPosY() + 40);
	}
#else
	//릴리즈 상태면
	{
		wsprintf(str, "framePerSec(FPS) : %d", _timer->getFrameRate());
		TextOut(hdc, 0, 0, str, strlen(str));
	}
#endif
}
