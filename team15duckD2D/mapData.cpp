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
	load(mapSizeFileName, mapFileName);
	
	return S_OK;
}

void mapData::release()
{
}

void mapData::update()
{
	ii = CAMERA->getPosY() / TILE_SIZE;
	if (ii < 0) ii = 0;
	iiMax = ((CAMERA->getPosY() + WINSIZEY) / TILE_SIZE) + 1;
	if (iiMax >= TILEY) iiMax = TILEY - 1;
	jj = CAMERA->getPosX() / TILE_SIZE;
	if (jj < 0) jj = 0;
	jjMax = ((CAMERA->getPosX() + WINSIZEX) / TILE_SIZE) + 1;
	if (jjMax >= TILEX) jjMax = TILEX - 1;
}

void mapData::render()
{
	for (; ii < iiMax; ++ii)
	{
		for (; jj < jjMax; ++jj)
		{
			if (_vvTile[ii][jj]->terrainImageName.size() > 0)
				IMAGEMANAGER->findImage(_vvTile[ii][jj]->terrainImageName)->frameRender(jj * TILE_SIZE, ii * TILE_SIZE , _vvTile[ii][jj]->terrainFrameX, _vvTile[ii][jj]->terrainFrameY);
			if (_vvTile[ii][jj]->objectImageName.size() > 0)
				IMAGEMANAGER->findImage(_vvTile[ii][jj]->objectImageName)->frameRender(jj*TILE_SIZE, ii*TILE_SIZE, _vvTile[ii][jj]->objectFrameX, _vvTile[ii][jj]->objectFrameY);
		}
		jj = CAMERA->getPosX() / TILE_SIZE;
		if (jj < 0) jj = 0;
	}
}

void mapData::load(const char * mapSizeFileName, const char * mapFileName)
{
	_vvTile.clear();

	HANDLE file;
	DWORD read;
	char mapSize[128] = { 0, };

	file = CreateFile(mapSizeFileName, GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(file, mapSize, 128, &read, NULL);
	CloseHandle(file);

	string mapX, mapY;
	mapX.clear();
	mapY.clear();
	bool x = true;
	for (int i = 0; i < strlen(mapSize); ++i)
	{
		if (mapSize[i] == ',')
		{
			x = false;
			continue;
		}
		if (mapSize[i] == NULL) break;
		if (x)
		{
			mapX += mapSize[i];
		}
		else
		{
			mapY += mapSize[i];
		}
	}

	TILEX = stoi(mapX);
	TILEY = stoi(mapY);
	_vvTile.resize(TILEY);

	for (int i = 0; i < TILEY; ++i)
	{
		_vvTile[i].resize(TILEX);
	}

	tagTile* tile = new tagTile[TILEX * TILEY];
	ZeroMemory(tile, sizeof(tagTile) * (TILEX * TILEY));

	HANDLE file2;
	DWORD read2;

	file2 = CreateFile(mapFileName, GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file2, tile, sizeof(tagTile) * TILEX * TILEY, &read2, NULL);

	CloseHandle(file2);

	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			_vvTile[i][j] = &tile[j + i * TILEX];
		}
	}



}
