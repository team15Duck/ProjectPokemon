#include "stdafx.h"
#include "testMap.h"


testMap::testMap()
{
}


testMap::~testMap()
{
}

HRESULT testMap::init()
{
	_map = new mapData;
	_map->init("testMapSize.map", "testMapData.map");


	return S_OK;
}

void testMap::release()
{

}

void testMap::update()
{

}

void testMap::render()
{

}
