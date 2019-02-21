#include "stdafx.h"
#include "endingScene.h"


endingScene::endingScene()
{
}


endingScene::~endingScene()
{
}

HRESULT endingScene::init()
{
	return S_OK;
}

void endingScene::release()
{
}

void endingScene::update()
{
}

void endingScene::render()
{
	D2DMANAGER->drawText(_endingText.c_str(), CAMERA->getPosX() + 250, CAMERA->getPosY() + 250, 70);
}
