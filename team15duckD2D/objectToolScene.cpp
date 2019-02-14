#include "stdafx.h"
#include "objectToolScene.h"


objectToolScene::objectToolScene()
{
}


objectToolScene::~objectToolScene()
{
}

HRESULT objectToolScene::init()
{
	_objectTool = new objectTool;
	_objectTool->init();

	return S_OK;
}

void objectToolScene::release()
{
	_objectTool->release();
}

void objectToolScene::update()
{
	_objectTool->update();
}

void objectToolScene::render()
{
	_objectTool->render();
}
