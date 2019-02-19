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
	//��
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

	//������Ʈ + ���ΰ�
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
			//�Ʒ��� �׸���
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_01")
			{
				if ((_vvTile[ii][jj]->objectFrameX == 4 || _vvTile[ii][jj]->objectFrameX == 5) && _vvTile[ii][jj]->objectFrameY == 3)  //�������
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
				if (_vvTile[ii][jj]->objectFrameX == 5 && (_vvTile[ii][jj]->objectFrameY == 4 || _vvTile[ii][jj]->objectFrameY == 5)) //�߸�Ʈ(��ŻX)
				{
					imgObject();
				}
			}
			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_04")
			{
				if ((_vvTile[ii][jj]->objectFrameX >= 0 && _vvTile[ii][jj]->objectFrameX < 3) && (_vvTile[ii][jj]->objectFrameY == 3 || _vvTile[ii][jj]->objectFrameY == 4)) //�߸�Ʈ(ü����, ��ŻO)
				{
					imgObject();
				}
				else if (_vvTile[ii][jj]->objectFrameX == 4 && _vvTile[ii][jj]->objectFrameY == 4) //�������°��(��ŻO)
				{
					imgObject();
				}
			}
			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_05")
			{
				if ((_vvTile[ii][jj]->objectFrameX >= 0 && _vvTile[ii][jj]->objectFrameX < 3) && (_vvTile[ii][jj]->objectFrameY == 3 || _vvTile[ii][jj]->objectFrameY == 4)) //������ �� �ִ� �ٸ�
				{
					imgObject();
				}
			}
			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_07")
			{
				if ((_vvTile[ii][jj]->objectFrameX == 3 || _vvTile[ii][jj]->objectFrameX == 4) && _vvTile[ii][jj]->objectFrameY == 3) //��ũ��غκ�
				{
					imgObject();
				}
				else if ((_vvTile[ii][jj]->objectFrameX >= 1 && _vvTile[ii][jj]->objectFrameX < 6) && _vvTile[ii][jj]->objectFrameY == 5) //����������(����)�غκ�, �ı���غκ�
				{
					imgObject();
				}
			}
			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_08")
			{
				if ((_vvTile[ii][jj]->objectFrameX >= 3 && _vvTile[ii][jj]->objectFrameX < 6) && _vvTile[ii][jj]->objectFrameY == 2) //��ǻ�� & ������ �غκ�
				{
					imgObject();
				}
				else if ((_vvTile[ii][jj]->objectFrameX == 0 || _vvTile[ii][jj]->objectFrameX == 1) && (_vvTile[ii][jj]->objectFrameY == 4 || _vvTile[ii][jj]->objectFrameX == 5)) // �ʷϻ� å�� �غκ� & ���������
				{
					imgObject();
				}
			}
			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_09")
			{
				if ((_vvTile[ii][jj]->objectFrameX == 0 || _vvTile[ii][jj]->objectFrameX == 1) && _vvTile[ii][jj]->objectFrameY == 3) //�Ͼ�� å�� �غκ�
				{
					imgObject();
				}
				else if (_vvTile[ii][jj]->objectFrameX == 4 && _vvTile[ii][jj]->objectFrameY == 1) //�ö󰡴� ���(��ŻO)
				{
					imgObject();
				}
				else if ((_vvTile[ii][jj]->objectFrameX >= 0 || _vvTile[ii][jj]->objectFrameX < 4) && _vvTile[ii][jj]->objectFrameY == 5) //���ڻ�å��
				{
					imgObject();
				}
			}
			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_10")
			{
				if ((_vvTile[ii][jj]->objectFrameX == 3 || _vvTile[ii][jj]->objectFrameX == 4) && _vvTile[ii][jj]->objectFrameY == 3) //����
				{
					imgObject();
				}
				else if ((_vvTile[ii][jj]->objectFrameX >= 3 && _vvTile[ii][jj]->objectFrameX < 6) && (_vvTile[ii][jj]->objectFrameY == 4 || _vvTile[ii][jj]->objectFrameY == 5)) //������ �߸�Ʈ(��ŻO)
				{
					imgObject();
				}

			}
			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_11") //���ΰ� ��
			{
				if (_vvTile[ii][jj]->objectFrameX == 1 && _vvTile[ii][jj]->objectFrameY == 4) //��
				{
					imgObject();
				}
			}
			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_12") //���ڻ� ������
			{
				if (_vvTile[ii][jj]->objectFrameX == 3 && _vvTile[ii][jj]->objectFrameY == 4) //��
				{
					imgObject();
				}
			}
			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_13") //���ϸ� ����
			{
				if (_vvTile[ii][jj]->objectFrameX == 2 && _vvTile[ii][jj]->objectFrameY == 4) //��
				{
					imgObject();
				}
			}
			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_14") //���ϸ� ����
			{
				if (_vvTile[ii][jj]->objectFrameX == 2 && _vvTile[ii][jj]->objectFrameY == 3) //��
				{
					imgObject();
				}
			}
			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_15") //ü����
			{
				if ((_vvTile[ii][jj]->objectFrameX == 0 || _vvTile[ii][jj]->objectFrameX == 1 || _vvTile[ii][jj]->objectFrameX == 5) && _vvTile[ii][jj]->objectFrameY == 4) //���̶� �غκ�
				{
					imgObject();
				}
			}

			else if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_17") //��Ÿ
			{
				if (_vvTile[ii][jj]->objectFrameX >= 3 && _vvTile[ii][jj]->objectFrameX < 6) //ħ��Ӹ��κ�
				{
					if (_vvTile[ii][jj]->objectFrameY == 1)
						IMAGEMANAGER->findImage(OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex])->frameRender(jj*TILE_SIZE, ii*TILE_SIZE, 0, 0, 64, 28, _vvTile[ii][jj]->objectFrameX, _vvTile[ii][jj]->objectFrameY, 1);
				}
				else if ((_vvTile[ii][jj]->objectFrameX == 1 || _vvTile[ii][jj]->objectFrameX == 2) && _vvTile[ii][jj]->objectFrameY == 4) //ü���� �غκ�
				{
					imgObject();
				}
			}

		}
		jj = CAMERA->getPosX() / TILE_SIZE;
		if (jj < 0) jj = 0;

		
		//������Ʈ->Ÿ�Ϸ� ����Ϸ�Ǹ� ���� �����ֱ�
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
				if ((_vvTile[ii][jj]->objectFrameX == 0 && _vvTile[ii][jj]->objectFrameY == 2) || (_vvTile[ii][jj]->objectFrameX == 5 && _vvTile[ii][jj]->objectFrameY == 0)) //�������� or ���� ���κ�
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_02")
			{
				if ((_vvTile[ii][jj]->objectFrameX == 1 || _vvTile[ii][jj]->objectFrameX == 2) && _vvTile[ii][jj]->objectFrameY == 3) //���� ���κ�
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_03")
			{

				if ((_vvTile[ii][jj]->objectFrameX >= 0 && _vvTile[ii][jj]->objectFrameX < 6) && _vvTile[ii][jj]->objectFrameY == 0) //ū���� ���κ�
				{
					imgObject();
				}
				else if (_vvTile[ii][jj]->objectFrameX == 4 && (_vvTile[ii][jj]->objectFrameY == 4 || _vvTile[ii][jj]->objectFrameY == 5)) //�ǳ� ��������(����, ����)
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_04")
			{
				if (_vvTile[ii][jj]->objectFrameX == 5 && _vvTile[ii][jj]->objectFrameY == 4) //ü���� ���� ���κ�
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_05")
			{
				if (_vvTile[ii][jj]->objectFrameX == 5 && _vvTile[ii][jj]->objectFrameY == 5) //���������� ���κ�
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
				if ((_vvTile[ii][jj]->objectFrameX == 0 || _vvTile[ii][jj]->objectFrameX == 1) && _vvTile[ii][jj]->objectFrameY == 0) //����������(�¿�) ���κ�
				{
					imgObject();
				}
				else if (_vvTile[ii][jj]->objectFrameX == 5 && _vvTile[ii][jj]->objectFrameY == 2) //ȭ�� ���κ�
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_08")
			{
				if ((_vvTile[ii][jj]->objectFrameX == 0 || _vvTile[ii][jj]->objectFrameX == 1) && _vvTile[ii][jj]->objectFrameY == 3) //�ʷϻ� å�����κ�
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_09")
			{
				if ((_vvTile[ii][jj]->objectFrameX == 0 || _vvTile[ii][jj]->objectFrameX == 1) && _vvTile[ii][jj]->objectFrameY == 1) //�Ͼ�� å�����κ�
				{
					imgObject();
				}
				else if ((_vvTile[ii][jj]->objectFrameX == 2 || _vvTile[ii][jj]->objectFrameX == 3) && _vvTile[ii][jj]->objectFrameY == 1) //���ڻ��� ���κ�
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_10")
			{
				if ((_vvTile[ii][jj]->objectFrameX >= 0 && _vvTile[ii][jj]->objectFrameX < 3) && _vvTile[ii][jj]->objectFrameY == 4) //ü���� ū�� ���κ�
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_11") //���ΰ� ��
			{
				if ((_vvTile[ii][jj]->objectFrameX >= 0 && _vvTile[ii][jj]->objectFrameX < 5) && _vvTile[ii][jj]->objectFrameY == 0) //�������κ�
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_12") //���ڻ� ������
			{
				if ((_vvTile[ii][jj]->objectFrameX >= 0 && _vvTile[ii][jj]->objectFrameX < 6) && _vvTile[ii][jj]->objectFrameY == 0) //�������κ�
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_13") //���ϸ� ����
			{
				if ((_vvTile[ii][jj]->objectFrameX >= 0 && _vvTile[ii][jj]->objectFrameX < 5) && _vvTile[ii][jj]->objectFrameY == 0) //�������κ�
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_14") //���ϸ� ����
			{
				if ((_vvTile[ii][jj]->objectFrameX >= 0 && _vvTile[ii][jj]->objectFrameX < 4) && _vvTile[ii][jj]->objectFrameY == 0) //�������κ�
				{
					imgObject();
				}
			}
			if (OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex] == "object_15") //ü���
			{
				if ((_vvTile[ii][jj]->objectFrameX >= 0 && _vvTile[ii][jj]->objectFrameX < 6) && _vvTile[ii][jj]->objectFrameY == 0) //�������κ�
				{
					imgObject();
				}
				else if ((_vvTile[ii][jj]->objectFrameX == 2 || _vvTile[ii][jj]->objectFrameX == 4) && _vvTile[ii][jj]->objectFrameY == 4) //�� �翷
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
				else if ((_vvTile[ii][jj]->objectFrameX == 1 || _vvTile[ii][jj]->objectFrameX == 2) && _vvTile[ii][jj]->objectFrameY == 0) //ü���� ���� ���κ�
				{
					imgObject();
				}
				else if (_vvTile[ii][jj]->objectFrameX == 0 && _vvTile[ii][jj]->objectFrameY == 0) //���ڻ� ������ ���� ���κ�
				{
					imgObject();
				}
			}


			if ((int)_player->getPosX() / 64 == jj && (int)_player->getPosY() / 64 == ii)
			{
				_player->shadowRender();
			}

			//=====================================�Ӽ�Ȯ�ο��̿���================================
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
