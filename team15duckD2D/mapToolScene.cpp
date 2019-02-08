#include "stdafx.h"
#include "mapToolScene.h"


mapToolScene::mapToolScene()
{
}


mapToolScene::~mapToolScene()
{
}

HRESULT mapToolScene::init()
{
	_maptool = new mapTool;
	_maptool->init();
	return S_OK;
}

void mapToolScene::release()
{
	_maptool->release();
	SAFE_DELETE(_maptool);
}

void mapToolScene::update()
{
	_maptool->update();
}

void mapToolScene::render()
{
	_maptool->render();
}
