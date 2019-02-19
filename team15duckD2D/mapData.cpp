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


	_count++;
	for (; ii < iiMax; ++ii)
	{
		for (; jj < jjMax; ++jj)
		{
			if ((_vvTile[ii][jj]->attr & ATTR_FLOWER) == ATTR_FLOWER)
			{
				if (_count % 15 == 0)
				{
					_vvTile[ii][jj]->objectFrameX++;
					if (_vvTile[ii][jj]->objectFrameX >= 4)
						_vvTile[ii][jj]->objectFrameX = 0;
					_count = 0;
				}
			}
		}
		jj = CAMERA->getPosX() / TILE_SIZE;
		if (jj < 0) jj = 0;
	}
	ii = CAMERA->getPosY() / TILE_SIZE;
	if (ii < 0) ii = 0;
}


//===================================

void mapData::render()
{
	//맵
	for (; ii < iiMax; ++ii)
	{
		for (; jj < jjMax; ++jj)
		{
			if (TERRAIN_NAME[_vvTile[ii][jj]->terrainImageIndex] == "tile_07")
			{
				if ((_vvTile[ii][jj]->terrainFrameX >= 0 && _vvTile[ii][jj]->terrainFrameX < 3) && _vvTile[ii][jj]->terrainFrameY == 2)
					IMAGEMANAGER->findImage(TERRAIN_NAME[_vvTile[ii][jj]->terrainImageIndex])->frameRender(jj * TILE_SIZE, ii * TILE_SIZE, 0, 0, 64, 36, _vvTile[ii][jj]->terrainFrameX, _vvTile[ii][jj]->terrainFrameY);
			}
			if (TERRAIN_NAME[_vvTile[ii][jj]->terrainImageIndex] != "none")
				IMAGEMANAGER->findImage(TERRAIN_NAME[_vvTile[ii][jj]->terrainImageIndex])->frameRender(jj * TILE_SIZE, ii * TILE_SIZE, _vvTile[ii][jj]->terrainFrameX, _vvTile[ii][jj]->terrainFrameY);

		}
		jj = CAMERA->getPosX() / TILE_SIZE;
		if (jj < 0) jj = 0;
	}
	ii = CAMERA->getPosY() / TILE_SIZE;
	if (ii < 0) ii = 0;

	//오브젝트 + 주인공
	drawObject();
	if(_player->getSceneName() != "caveScene")
		EFFECTMANAGER->render();
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

	potalLoad();

}

void mapData::potalLoad()
{

	
}

void mapData::drawObject()
{
	for (; ii < iiMax; ++ii)
	{
		for (; jj < jjMax; ++jj)
		{

			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] != "none")
			{
				if (_vvTile[ii][jj]->attr & ATTR_APPEAR)
				{
					IMAGEMANAGER->findImage(OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex])->frameRender(jj*TILE_SIZE, ii*TILE_SIZE, 0, 0, 64, 40, _vvTile[ii][jj]->objectFrameX, _vvTile[ii][jj]->objectFrameY, 1);
				}
				else if (_vvTile[ii][jj]->attr & ATTR_FLOWER)
				{
					imgObject();
				}
				else
				{
					imgObject();
				}

			}
			//아래에 그릴거
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_01")
			{
				if ((_vvTile[ii][jj]->objectFrameX == 4 || _vvTile[ii][jj]->objectFrameX == 5) && _vvTile[ii][jj]->objectFrameY == 3)  //동굴계단
				{
					imgObject();
				}
				else if ((_vvTile[ii][jj]->objectFrameX >= 0 && _vvTile[ii][jj]->objectFrameX < 5) && _vvTile[ii][jj]->objectFrameY == 4)
				{
					imgObject();
				}

			}
			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_03")
			{
				if (_vvTile[ii][jj]->objectFrameX == 5 && (_vvTile[ii][jj]->objectFrameY == 4 || _vvTile[ii][jj]->objectFrameY == 5)) //발매트(포탈X)
				{
					imgObject();
				}
			}
			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_04")
			{
				if ((_vvTile[ii][jj]->objectFrameX >= 0 && _vvTile[ii][jj]->objectFrameX < 3) && (_vvTile[ii][jj]->objectFrameY == 3 || _vvTile[ii][jj]->objectFrameY == 4)) //발매트(체육관, 포탈O)
				{
					imgObject();
				}
				else if (_vvTile[ii][jj]->objectFrameX == 4 && _vvTile[ii][jj]->objectFrameY == 4) //내려가는계단(포탈O)
				{
					imgObject();
				}
			}
			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_05")
			{
				if ((_vvTile[ii][jj]->objectFrameX >= 0 && _vvTile[ii][jj]->objectFrameX < 3) && (_vvTile[ii][jj]->objectFrameY == 3 || _vvTile[ii][jj]->objectFrameY == 4)) //움직일 수 있는 다리
				{
					imgObject();
				}
			}
			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_07")
			{
				if ((_vvTile[ii][jj]->objectFrameX == 3 || _vvTile[ii][jj]->objectFrameX == 4) && _vvTile[ii][jj]->objectFrameY == 3) //싱크대밑부분
				{
					imgObject();
				}
				else if ((_vvTile[ii][jj]->objectFrameX >= 1 && _vvTile[ii][jj]->objectFrameX < 6) && _vvTile[ii][jj]->objectFrameY == 5) //상점진열대(정면)밑부분, 식기장밑부분
				{
					imgObject();
				}
			}
			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_08")
			{
				if ((_vvTile[ii][jj]->objectFrameX >= 3 && _vvTile[ii][jj]->objectFrameX < 6) && _vvTile[ii][jj]->objectFrameY == 2) //컴퓨터 & 서랍장 밑부분
				{
					imgObject();
				}
				else if ((_vvTile[ii][jj]->objectFrameX == 0 || _vvTile[ii][jj]->objectFrameX == 1) && (_vvTile[ii][jj]->objectFrameY == 4 || _vvTile[ii][jj]->objectFrameX == 5)) // 초록색 책장 밑부분 & 등받이의자
				{
					imgObject();
				}
			}
			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_09")
			{
				if ((_vvTile[ii][jj]->objectFrameX == 0 || _vvTile[ii][jj]->objectFrameX == 1) && _vvTile[ii][jj]->objectFrameY == 3) //하얀색 책장 밑부분
				{
					imgObject();
				}
				else if (_vvTile[ii][jj]->objectFrameX == 4 && _vvTile[ii][jj]->objectFrameY == 1) //올라가는 계단(포탈O)
				{
					imgObject();
				}
				else if ((_vvTile[ii][jj]->objectFrameX >= 0 || _vvTile[ii][jj]->objectFrameX < 4) && _vvTile[ii][jj]->objectFrameY == 5) //오박사책상
				{
					imgObject();
				}
			}
			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_10")
			{
				if ((_vvTile[ii][jj]->objectFrameX == 3 || _vvTile[ii][jj]->objectFrameX == 4) && _vvTile[ii][jj]->objectFrameY == 3) //의자
				{
					imgObject();
				}
				else if ((_vvTile[ii][jj]->objectFrameX >= 3 && _vvTile[ii][jj]->objectFrameX < 6) && (_vvTile[ii][jj]->objectFrameY == 4 || _vvTile[ii][jj]->objectFrameY == 5)) //빨간색 발매트(포탈O)
				{
					imgObject();
				}

			}
			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_11") //주인공 집
			{
				if (_vvTile[ii][jj]->objectFrameX == 1 && _vvTile[ii][jj]->objectFrameY == 4) //문
				{
					imgObject();
				}
			}
			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_12") //오박사 연구소
			{
				if (_vvTile[ii][jj]->objectFrameX == 3 && _vvTile[ii][jj]->objectFrameY == 4) //문
				{
					imgObject();
				}
			}
			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_13") //포켓몬 센터
			{
				if (_vvTile[ii][jj]->objectFrameX == 2 && _vvTile[ii][jj]->objectFrameY == 4) //문
				{
					imgObject();
				}
			}
			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_14") //포켓몬 상점
			{
				if (_vvTile[ii][jj]->objectFrameX == 2 && _vvTile[ii][jj]->objectFrameY == 3) //문
				{
					imgObject();
				}
			}
			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_15") //체육관
			{
				if ((_vvTile[ii][jj]->objectFrameX == 0 || _vvTile[ii][jj]->objectFrameX == 1 || _vvTile[ii][jj]->objectFrameX == 5) && _vvTile[ii][jj]->objectFrameY == 4) //문이랑 밑부분
				{
					imgObject();
				}
			}

			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_17") //기타
			{
				if (_vvTile[ii][jj]->objectFrameX >= 3 && _vvTile[ii][jj]->objectFrameX < 6) //침대머리부분
				{
					if (_vvTile[ii][jj]->objectFrameY == 1)
						IMAGEMANAGER->findImage(OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex])->frameRender(jj*TILE_SIZE, ii*TILE_SIZE, 0, 0, 64, 28, _vvTile[ii][jj]->objectFrameX, _vvTile[ii][jj]->objectFrameY, 1);
				}
				else if ((_vvTile[ii][jj]->objectFrameX == 1 || _vvTile[ii][jj]->objectFrameX == 2) && _vvTile[ii][jj]->objectFrameY == 4) //체육관 밑부분
				{
					imgObject();
				}
			}

		}
		jj = CAMERA->getPosX() / TILE_SIZE;
		if (jj < 0) jj = 0;

		
		//오브젝트->타일로 변경완료되면 숫자 지워주기
		if (((int)_player->getPosY() + 31) / 64 == ii)
		{
			if (_player->getSceneName() == "caveScene")
				EFFECTMANAGER->render();
			_player->render();
		}

		for (int i = 0; i < _npc.size(); ++i)
		{
			if((_npc[i]->getTileY()) / 64 == ii)
				_npc[i]->render();
		}

		for (; jj < jjMax; ++jj)
		{
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] != "none")
			{
				if (_vvTile[ii][jj]->attr & ATTR_APPEAR)
				{
					IMAGEMANAGER->findImage(OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex])->frameRender(jj*TILE_SIZE, ii*TILE_SIZE + 40, 0, 40, 64, 24, _vvTile[ii][jj]->objectFrameX, _vvTile[ii][jj]->objectFrameY, 1);
				}

			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_01")
			{
				if ((_vvTile[ii][jj]->objectFrameX == 0 && _vvTile[ii][jj]->objectFrameY == 2) || (_vvTile[ii][jj]->objectFrameX == 5 && _vvTile[ii][jj]->objectFrameY == 0)) //작은나무 or 석상 윗부분
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_02")
			{
				if ((_vvTile[ii][jj]->objectFrameX == 1 || _vvTile[ii][jj]->objectFrameX == 2) && _vvTile[ii][jj]->objectFrameY == 3) //나무 윗부분
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_03")
			{

				if ((_vvTile[ii][jj]->objectFrameX >= 0 && _vvTile[ii][jj]->objectFrameX < 6) && _vvTile[ii][jj]->objectFrameY == 0) //큰나무 윗부분
				{
					imgObject();
				}
				else if (_vvTile[ii][jj]->objectFrameX == 4 && (_vvTile[ii][jj]->objectFrameY == 4 || _vvTile[ii][jj]->objectFrameY == 5)) //실내 검은세모(상점, 센터)
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_04")
			{
				if (_vvTile[ii][jj]->objectFrameX == 5 && _vvTile[ii][jj]->objectFrameY == 4) //체육관 간판 윗부분
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_05")
			{
				if (_vvTile[ii][jj]->objectFrameX == 5 && _vvTile[ii][jj]->objectFrameY == 5) //상점진열대 윗부분
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_06")
			{
				if (_vvTile[ii][jj]->objectFrameX == 4 && _vvTile[ii][jj]->objectFrameY == 2)
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_07")
			{
				if ((_vvTile[ii][jj]->objectFrameX == 0 || _vvTile[ii][jj]->objectFrameX == 1) && _vvTile[ii][jj]->objectFrameY == 0) //상점진열대(좌우) 윗부분
				{
					imgObject();
				}
				else if (_vvTile[ii][jj]->objectFrameX == 5 && _vvTile[ii][jj]->objectFrameY == 2) //화분 윗부분
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_08")
			{
				if ((_vvTile[ii][jj]->objectFrameX == 0 || _vvTile[ii][jj]->objectFrameX == 1) && _vvTile[ii][jj]->objectFrameY == 3) //초록색 책장윗부분
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_09")
			{
				if ((_vvTile[ii][jj]->objectFrameX == 0 || _vvTile[ii][jj]->objectFrameX == 1) && _vvTile[ii][jj]->objectFrameY == 1) //하얀색 책장윗부분
				{
					imgObject();
				}
				else if ((_vvTile[ii][jj]->objectFrameX == 2 || _vvTile[ii][jj]->objectFrameX == 3) && _vvTile[ii][jj]->objectFrameY == 1) //오박사기계 윗부분
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_10")
			{
				if ((_vvTile[ii][jj]->objectFrameX >= 0 && _vvTile[ii][jj]->objectFrameX < 3) && _vvTile[ii][jj]->objectFrameY == 4) //체육관 큰돌 윗부분
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_11") //주인공 집
			{
				if ((_vvTile[ii][jj]->objectFrameX >= 0 && _vvTile[ii][jj]->objectFrameX < 5) && _vvTile[ii][jj]->objectFrameY == 0) //지붕윗부분
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_12") //오박사 연구소
			{
				if ((_vvTile[ii][jj]->objectFrameX >= 0 && _vvTile[ii][jj]->objectFrameX < 6) && _vvTile[ii][jj]->objectFrameY == 0) //지붕윗부분
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_13") //포켓몬 센터
			{
				if ((_vvTile[ii][jj]->objectFrameX >= 0 && _vvTile[ii][jj]->objectFrameX < 5) && _vvTile[ii][jj]->objectFrameY == 0) //지붕윗부분
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_14") //포켓몬 상점
			{
				if ((_vvTile[ii][jj]->objectFrameX >= 0 && _vvTile[ii][jj]->objectFrameX < 4) && _vvTile[ii][jj]->objectFrameY == 0) //지붕윗부분
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_15") //체욱관
			{
				if ((_vvTile[ii][jj]->objectFrameX >= 0 && _vvTile[ii][jj]->objectFrameX < 6) && _vvTile[ii][jj]->objectFrameY == 0) //지붕윗부분
				{
					imgObject();
				}
				else if ((_vvTile[ii][jj]->objectFrameX == 2 || _vvTile[ii][jj]->objectFrameX == 4) && _vvTile[ii][jj]->objectFrameY == 4) //문 양옆
				{
					imgObject();
				}
			}
			if (TERRAIN_NAME[_vvTile[ii][jj]->terrainImageIndex] == "tile_07")
			{
				if ((_vvTile[ii][jj]->terrainFrameX >= 0 && _vvTile[ii][jj]->terrainFrameX < 3) && _vvTile[ii][jj]->terrainFrameY == 2)
				{
					IMAGEMANAGER->findImage(TERRAIN_NAME[_vvTile[ii][jj]->terrainImageIndex])->frameRender(jj * TILE_SIZE, ii * TILE_SIZE + 28, 0, 28, 64, 36, _vvTile[ii][jj]->terrainFrameX, _vvTile[ii][jj]->terrainFrameY);
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_17")
			{
				if (_vvTile[ii][jj]->objectFrameX >= 3 && _vvTile[ii][jj]->objectFrameX < 6)
				{
					if (_vvTile[ii][jj]->objectFrameY == 1)
						IMAGEMANAGER->findImage(OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex])->frameRender(jj*TILE_SIZE, ii*TILE_SIZE + 28, 0, 28, 64, 36, _vvTile[ii][jj]->objectFrameX, _vvTile[ii][jj]->objectFrameY, 1);
				}
				else if ((_vvTile[ii][jj]->objectFrameX == 1 || _vvTile[ii][jj]->objectFrameX == 2) && _vvTile[ii][jj]->objectFrameY == 0) //체육관 지붕 윗부분
				{
					imgObject();
				}
				else if (_vvTile[ii][jj]->objectFrameX == 0 && _vvTile[ii][jj]->objectFrameY == 0) //오박사 연구소 지붕 윗부분
				{
					imgObject();
				}
			}


			if ((int)_player->getPosX() / 64 == jj && (int)_player->getPosY() / 64 == ii)
			{
				_player->shadowRender();
			}

			//=====================================속성확인용이에요================================
			if (KEYMANAGER->isToggleKey(VK_CONTROL))
			{
				WCHAR str[128];
				if ((_vvTile[ii][jj]->attr & ATTR_UNMOVE) == ATTR_UNMOVE)
				{
					swprintf_s(str, L"UnMove");
					D2DMANAGER->drawText(str, jj *TILE_SIZE + 5, ii * TILE_SIZE + 5, 20, RGB(255, 0, 255));
				}
				if ((_vvTile[ii][jj]->attr & ATTR_POTAL) == ATTR_POTAL)
				{
					swprintf_s(str, L"POTAL");
					D2DMANAGER->drawText(str, jj *TILE_SIZE + 5, ii * TILE_SIZE + 5, 20, RGB(0, 255, 255));
				}
				if ((_vvTile[ii][jj]->attr & ATTR_APPEAR) == ATTR_APPEAR)
				{
					swprintf_s(str, L"APPEAR");
					D2DMANAGER->drawText(str, jj *TILE_SIZE + 5, ii * TILE_SIZE + 5, 20, RGB(255, 0, 255));
				}
			}
		}
		jj = CAMERA->getPosX() / TILE_SIZE;
		if (jj < 0) jj = 0;
	}
}

void mapData::setPokemon()
{
}
