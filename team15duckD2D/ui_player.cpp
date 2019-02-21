#include "stdafx.h"
#include "ui_player.h"


ui_player::ui_player()
{
}


ui_player::~ui_player()
{
}

HRESULT ui_player::init()
{
	_uiplayer.name.clear();
	_uiplayer.money.clear();
	_uiplayer.time.clear();

	return S_OK;
}

void ui_player::release()
{
}

void ui_player::update()
{
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		UIMANAGER->moveBeforeUI();
	}
}

void ui_player::render()
{
	if (PLAYERDATA->getPlayer()->getIsMan())
	{
		IMAGEMANAGER->findImage("트레이너카드")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 1, 0);
	}
	else
	{
		IMAGEMANAGER->findImage("트레이너카드")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 0, 0);
	}

	D2DMANAGER->drawText(_uiplayer.name.c_str(), 50 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 40);
	D2DMANAGER->drawText(_uiplayer.money.c_str(), 100+ CAMERA->getPosX(), 150 + CAMERA->getPosY(), 40);
	D2DMANAGER->drawText(to_wstring((int)PLAYERDATA->getPlayer()->getPlayTime()).c_str(), 530 + CAMERA->getPosX(), 390 + CAMERA->getPosY(), 40);

}

void ui_player::uiDataSetting()
{
	playerDataSet();
}

void ui_player::playerDataSet()
{
	locale("kor");

	_uiplayer.name = string2wstring(PLAYERDATA->getPlayer()->getName());
	_uiplayer.money = to_wstring(PLAYERDATA->getPlayer()->getMoney());
	_uiplayer.time = to_wstring(PLAYERDATA->getPlayer()->getPlayTime());
}
