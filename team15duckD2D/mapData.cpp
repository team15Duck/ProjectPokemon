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
	setPokemon();
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
			if (TERRAIN_NAME[_vvTile[ii][jj]->terrainImageIndex] != "none")
				IMAGEMANAGER->findImage(TERRAIN_NAME[_vvTile[ii][jj]->terrainImageIndex])->frameRender(jj * TILE_SIZE, ii * TILE_SIZE , _vvTile[ii][jj]->terrainFrameX, _vvTile[ii][jj]->terrainFrameY);
		}
		jj = CAMERA->getPosX() / TILE_SIZE;
		if (jj < 0) jj = 0;
	}
	ii = CAMERA->getPosY() / TILE_SIZE;
	if (ii < 0) ii = 0;
	for (; ii < iiMax; ++ii)
	{
		for (; jj < jjMax; ++jj)
		{
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] != "none")
			{
				IMAGEMANAGER->findImage(OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex])->frameRender(jj*TILE_SIZE, ii*TILE_SIZE, 0, 0 , 64, 64, _vvTile[ii][jj]->objectFrameX, _vvTile[ii][jj]->objectFrameY,1);
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] != "none" && _vvTile[ii][jj]->attr & ATTR_APPEAR)
			{
				IMAGEMANAGER->findImage(OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex])->frameRender(jj*TILE_SIZE, ii*TILE_SIZE, 0, 0, 64, 40, _vvTile[ii][jj]->objectFrameX, _vvTile[ii][jj]->objectFrameY, 1);
			}



			if ((int)_player->getPosX() / 64 == jj && (int)_player->getPosY() / 64 == ii)
			{
				_player->render();
			}

			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] != "none")
			{
				if (_vvTile[ii][jj]->attr & ATTR_APPEAR)
				{
					IMAGEMANAGER->findImage(OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex])->frameRender(jj*TILE_SIZE, ii*TILE_SIZE + 40, 0, 40, 64, 24, _vvTile[ii][jj]->objectFrameX, _vvTile[ii][jj]->objectFrameY, 1);
				}
				else
				{

				}
			}

			//=====================================속성확인용이에요================================
			if (KEYMANAGER->isToggleKey(VK_CONTROL))
			{
				WCHAR str[128];
				swprintf_s(str, L"UnMove_ATTR");
				if ((_vvTile[ii][jj]->attr & ATTR_UNMOVE) == ATTR_UNMOVE)
				{
					D2DMANAGER->drawText(str, jj *TILE_SIZE + 5, ii * TILE_SIZE + 5);
				}
			}

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

void mapData::setPokemon()
{
}
