#include "stdafx.h"
#include "mapTestScene.h"


mapTestScene::mapTestScene()
{
}


mapTestScene::~mapTestScene()
{
}

HRESULT mapTestScene::init()
{
	_testMap = new testMap;
	_testMap->init("testMapSize.map", "testMapData.map");

	return S_OK;
}

void mapTestScene::release()
{
}

void mapTestScene::update()
{
}

void mapTestScene::render()
{
}
