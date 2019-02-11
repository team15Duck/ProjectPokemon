#include "stdafx.h"
#include "mapData.h"


mapData::mapData()
{
}


mapData::~mapData()
{
}

HRESULT mapData::init(const char * mapSizeFileName, const char * mapFileName)
{
	ii = iiMax = jj = jjMax = 0;
	return S_OK;
}

void mapData::release()
{
}

void mapData::update()
{
}

void mapData::render()
{

}

void mapData::load(const char * mapSizeFileName, const char * mapFileName)
{
}
