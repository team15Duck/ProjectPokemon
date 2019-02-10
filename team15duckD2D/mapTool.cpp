#include "stdafx.h"
#include "mapTool.h"


mapTool::mapTool()
	: TILEX(0), TILEY(0)
{
	_vvTile.clear();
	_vvRect.clear();
}


mapTool::~mapTool()
{
}

HRESULT mapTool::init()
{
	_sampleImg[0] = IMAGEMANAGER->addFrameImage(TERRAIN_NAME1, L"image/tile/tile_01.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	_sampleImg[1] = IMAGEMANAGER->addFrameImage(TERRAIN_NAME2, L"image/tile/tile_02.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	_sampleImg[2] = IMAGEMANAGER->addFrameImage(TERRAIN_NAME3, L"image/tile/tile_03.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	_sampleImg[3] = IMAGEMANAGER->addFrameImage(TERRAIN_NAME4, L"image/tile/tile_04.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	_sampleImg[4] = IMAGEMANAGER->addFrameImage(TERRAIN_NAME5, L"image/tile/tile_05.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	_sampleImg[5] = IMAGEMANAGER->addFrameImage(TERRAIN_NAME6, L"image/tile/tile_06.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	_sampleImg[6] = IMAGEMANAGER->addFrameImage(TERRAIN_NAME7, L"image/tile/tile_07.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	_sampleImg[7] = IMAGEMANAGER->addFrameImage(TERRAIN_NAME8, L"image/tile/tile_08.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	_sampleImg[8] = IMAGEMANAGER->addFrameImage(TERRAIN_NAME9, L"image/tile/tile_09.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	_sampleImg[9] = IMAGEMANAGER->addFrameImage(TERRAIN_NAME10, L"image/tile/tile_10.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	_curImgNum = 0;
	_sampleImgStr[0] = TERRAIN_NAME1;

	_preButton = { WINSIZEX / 2 + 100, WINSIZEY / 2 + 120, WINSIZEX / 2 + 150, WINSIZEY / 2 + 150 };
	_nextButton = { WINSIZEX / 2 + 250, WINSIZEY / 2 + 120, WINSIZEX / 2 + 300, WINSIZEY / 2 + 150 };

	_sizeUpWidth = { _preButton.left + 100, _preButton.bottom + 50, _preButton.left + 130, _preButton.bottom + 90 };
	_sizeDownWidth = { _preButton.left, _sizeUpWidth.top, _preButton.left + 30, _sizeUpWidth.bottom };
	_sizeUpHeight = { _preButton.left + 40, _preButton.bottom + 10, _preButton.left + 90, _preButton.bottom + 40 };
	_sizeDownHeight = { _preButton.left + 40, _sizeUpWidth.bottom + 10 ,  _preButton.left + 90 , _sizeUpWidth.bottom + 40 };
	setTile();
	MENUMANAGER->addFrame("��Ʋ", WINSIZEX - SAMPLE_TOTAL_SIZE, 0, (WINSIZEX - SAMPLE_TOTAL_SIZE) / TILE_SIZE, WINSIZEY / TILE_SIZE);
	//MENUMANAGER->addFrame("�� Ʋ", WINSIZEX - SAMPLE_TOTAL_SIZE, 1, 9, 15);
	_isTileClick = false;

	CAMERA->init(0, 0, 3000, 3000);
	return S_OK;

}

void mapTool::release()
{
}

void mapTool::update()
{
	turnMap();
	pickSampleMap();
	drawMap();
	//mapSizeUp();

	if (KEYMANAGER->isOnceKeyDown(VK_CONTROL))
	{
		save();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SHIFT))
	{
		load();
	}
}

void mapTool::render()
{
	//�̹��� ����
	IMAGEMANAGER->findImage(_sampleImgStr[_curImgNum])->render(CAMERA->getPosX() + (WINSIZEX - SAMPLE_TOTAL_SIZE), CAMERA->getPosY() + 30);

	//����,���� ��ư ����
	D2DMANAGER->drawRectangle(CAMERA->getPosX() + _preButton.left
							  , CAMERA->getPosY() + _preButton.top
							  , CAMERA->getPosX() + _preButton.right
							  , CAMERA->getPosY() + _preButton.bottom);
	D2DMANAGER->drawRectangle(CAMERA->getPosX() + _nextButton.left
							  , CAMERA->getPosY() + _nextButton.top
							  , CAMERA->getPosX() + _nextButton.right
							  , CAMERA->getPosY() + _nextButton.bottom);

	//�� ������ ��ư ����
	D2DMANAGER->drawRectangle(CAMERA->getPosX() + _sizeUpWidth.left
							  , CAMERA->getPosY() + _sizeUpWidth.top
							  , CAMERA->getPosX() + _sizeUpWidth.right
							  , CAMERA->getPosY() + _sizeUpWidth.bottom);
	D2DMANAGER->drawRectangle(CAMERA->getPosX() + _sizeDownWidth.left
							  , CAMERA->getPosY() + _sizeDownWidth.top
							  , CAMERA->getPosX() + _sizeDownWidth.right
							  , CAMERA->getPosY() + _sizeDownWidth.bottom);
	D2DMANAGER->drawRectangle(CAMERA->getPosX() + _sizeUpHeight.left
							  , CAMERA->getPosY() + _sizeUpHeight.top
							  , CAMERA->getPosX() + _sizeUpHeight.right
							  , CAMERA->getPosY() + _sizeUpHeight.bottom);

	D2DMANAGER->drawRectangle(CAMERA->getPosX() + _sizeDownHeight.left
							  , CAMERA->getPosY() + _sizeDownHeight.top
							  , CAMERA->getPosX() + _sizeDownHeight.right
							  , CAMERA->getPosY() + _sizeDownHeight.bottom);

	//���� ����
	for (int i = 0; i < SAMPLETILE; ++i)
	{
		for (int j = 0; j < SAMPLETILE; ++j)
		{
			D2DMANAGER->drawRectangle(CAMERA->getPosX() + _sampleTile[i][j].sampleRc.left
									  , CAMERA->getPosY() + _sampleTile[i][j].sampleRc.top
									  , CAMERA->getPosX() + _sampleTile[i][j].sampleRc.right
									  , CAMERA->getPosY() + _sampleTile[i][j].sampleRc.bottom);
		}
	}
	
	//�� ����
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			if (_vvRect[i][j].right > CAMERA->getPosX() + CAMERA_SHOW_RANGE)
				continue;
			D2DMANAGER->drawRectangle(_vvRect[i][j].left, _vvRect[i][j].top, _vvRect[i][j].right, _vvRect[i][j].bottom);
			if (_vvTile[i][j]->terrainImageName == TERRAIN_NAME_NONE) continue;
			IMAGEMANAGER->findImage(_vvTile[i][j]->terrainImageName)->frameRender(_vvRect[i][j].left, _vvRect[i][j].top, _vvTile[i][j]->terrainFrameX, _vvTile[i][j]->terrainFrameY);
		}
	}

	if (_isTileClick)
	{
		IMAGEMANAGER->findImage(_sampleImgStr[_curImgNum])->frameRender(_ptMouse.x, _ptMouse.y, _pickSampleTile.curX, _pickSampleTile.curY, 0.5f);
	}

	WCHAR str[128];
	swprintf_s(str, L"TILEX : %d, TILEY : %d", TILEX, TILEY);
	D2DMANAGER->drawText(str, CAMERA->getPosX(), CAMERA->getPosY() + 200);

	//MENUMANAGER->findMenuFrame("�� Ʋ")->render("Ÿ��1");
}

void mapTool::setTile()
{
	//����Ÿ���� ��ġ
	for (int i = 0; i < SAMPLETILE; ++i)
	{
		for (int j = 0; j < SAMPLETILE; ++j)
		{
			_sampleTile[i][j].frameX = 0;
			_sampleTile[i][j].frameY = 0;
			_sampleTile[i][j].sampleRc = { (float)(WINSIZEX - SAMPLE_TOTAL_SIZE) + (j * TILE_SIZE)
										  ,(float)30 + (i*TILE_SIZE)
										  ,(float)(WINSIZEX - SAMPLE_TOTAL_SIZE) + ((j + 1) * TILE_SIZE)
										  ,(float)30 + ((i + 1) * TILE_SIZE) };
		}
	}

	//��
	TILEX = 100;
	TILEY = 100;
	for (int i = 0; i < TILEY; ++i)
	{
		vector<tagTile*> vTile;
		vector<D2D1_RECT_F> vRect;
		for (int j = 0; j < TILEX; ++j)
		{
			tagTile* tempTile = new tagTile;
			D2D1_RECT_F* tempRect = new D2D1_RECT_F;

			tempTile->terrainFrameX = 0;
			tempTile->terrainFrameY = 0;

			tempTile->objectFrameX = 0;
			tempTile->objectFrameY = 0;

			tempTile->attr |= ATTR_NONE;

			tempTile->terrainImageName = TERRAIN_NAME_NONE;
			tempTile->objectImageName = OBJECT_NAME_NONE;

			*tempRect = { (float)j * TILE_SIZE, (float)i * TILE_SIZE, (float)(j + 1) * TILE_SIZE, (float)(i + 1) * TILE_SIZE };

			vTile.push_back(tempTile);
			vRect.push_back(*tempRect);
		}
		_vvTile.push_back(vTile);
		_vvRect.push_back(vRect);
	}
}

void mapTool::turnMap()
{
	const RECT tempPre = { _preButton.left, _preButton.top, _preButton.right, _preButton.bottom };
	POINT tempPTPre = { _ptMouse.x, _ptMouse.y };

	if (PtInRect(&tempPre, tempPTPre))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			--_curImgNum;
			if (_curImgNum < 0)
				_curImgNum = TILE_IMAGE_NUM - 1;
			char str[128];
			if (_curImgNum + 1 == 10)
			{
				sprintf_s(str, "tile_%d", _curImgNum + 1);
				_sampleImgStr[_curImgNum] = str;
				return;
			}
			sprintf_s(str, "tile_0%d", _curImgNum + 1);
			_sampleImgStr[_curImgNum] = str;
		}
	}

	const RECT tempNext = { _nextButton.left, _nextButton.top, _nextButton.right, _nextButton.bottom };
	POINT tempPTNext = { _ptMouse.x, _ptMouse.y };

	if (PtInRect(&tempNext, tempPTNext))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			++_curImgNum;
			if (_curImgNum >= TILE_IMAGE_NUM)
				_curImgNum = 0;
			char str[128];
			if (_curImgNum + 1 == 10)
			{
				sprintf_s(str, "tile_%d", _curImgNum + 1);
				_sampleImgStr[_curImgNum] = str;
				return;
			}
			sprintf_s(str, "tile_0%d", _curImgNum + 1);
			_sampleImgStr[_curImgNum] = str;
		}
	}
}


void mapTool::pickSampleMap()
{
	if (_ptMouse.x < WINSIZEX - SAMPLE_TOTAL_SIZE)
		return;

	int indX = (_ptMouse.x - (WINSIZEX - SAMPLE_TOTAL_SIZE)) / TILE_SIZE;
	int indY = (_ptMouse.y - 30) / TILE_SIZE;

	if (indX >= SAMPLETILE)
		return;
	if (indY >= SAMPLETILE)
		return;

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_isTileClick = true;
		if (_curImgNum == 0 || _curImgNum == 1 || _curImgNum == 2 || _curImgNum == 3)
		{
			if ((indX >= 0 && indX < SAMPLETILE - 1) && (indY == 0 || indY == 3)
				|| (indX >= 0 && indX < SAMPLETILE - 2) && (indY == 1 || indY == 2 || indY == 4 || indY == 5))
			{
				_pickSampleTile.curX = indX;
				_pickSampleTile.curY = indY;
				_pickSampleTile.isObj = false;
			}
			else
				_isTileClick = false;
		}
		//����
		if (_curImgNum == 4)
		{
			if ((indX >= 0 && indX < SAMPLETILE - 1) && (indY == 0 || indY == 1) ||
				(indX >= 0 && indX < SAMPLETILE - 2) && indY == 2 ||
				(indX >= 0 && indX < SAMPLETILE - 3) && indY == 3)
			{
				_pickSampleTile.curX = indX;
				_pickSampleTile.curY = indY;
				_pickSampleTile.isObj = false;
			}
			else
				_isTileClick = false;
		}
		//��
		if (_curImgNum == 5)
		{
			if ((indX >= 0 && indX < SAMPLETILE) && (indY >= 0 && indY <= 4) ||
				(indX >= 0 && indX < SAMPLETILE - 1) && (indY == 5))
			{
				_pickSampleTile.curX = indX;
				_pickSampleTile.curY = indY;
				_pickSampleTile.isObj = false;
			}
			else
				_isTileClick = false;
		}
		//��, ���ڻ�
		if (_curImgNum == 6)
		{
			if ((indX >= 0 && indX < SAMPLETILE - 2) && indY == 0 ||
				(indX >= 0 && indX < SAMPLETILE - 1) && indY == 1)
			{
				_pickSampleTile.curX = indX;
				_pickSampleTile.curY = indY;
				_pickSampleTile.isObj = false;
			}
			else
				_isTileClick = false;
		}
		//���ϸ���
		if (_curImgNum == 7)
		{
			if ((indX >= 0 && indX < SAMPLETILE) && (indY >= 0 && indY < 3) ||
				(indX >= 0 && indX < SAMPLETILE - 2) && (indY >= 3 && indY < SAMPLETILE))
			{
				_pickSampleTile.curX = indX;
				_pickSampleTile.curY = indY;
				_pickSampleTile.isObj = false;
			}
			else
				_isTileClick = false;
		}
		//����
		if (_curImgNum == 8)
		{
			if ((indX >= 0 && indX < 3) && (indY >= 0 && indY < 3) ||
				(indX >= 0 && indX < SAMPLETILE - 2) && (indY >= 3 && indY < SAMPLETILE))
			{
				_pickSampleTile.curX = indX;
				_pickSampleTile.curY = indY;
				_pickSampleTile.isObj = false;
			}
			else
				_isTileClick = false;
		}
		//ü����(��)
		if (_curImgNum == 9)
		{
			if ((indX >= 0 && indX < SAMPLETILE) && (indY >= 0 && indY < SAMPLETILE))
			{
				_pickSampleTile.curX = indX;
				_pickSampleTile.curY = indY;
				_pickSampleTile.isObj = false;
			}
			else
				_isTileClick = false;
		}
	}
}

void mapTool::mapSizeUp()
{
	POINT tempPT = { _ptMouse.x, _ptMouse.y };
	
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && TILEX > 1)
	{
		if (PtInRect(&makeRECT(_sizeDownWidth), tempPT))
		{
			for (int i = 0; i < TILEY; ++i)
			{
				tagTile* target = _vvTile[i].back();
				_vvTile[i].pop_back();

				D2D1_RECT_F targetRc = _vvRect[i].back();
				_vvRect[i].pop_back();
				SAFE_DELETE(target);
				
			}
			TILEX--;
		}

		if (PtInRect(&makeRECT(_sizeUpWidth), tempPT))
		{
			for (int i = 0; i < TILEY; ++i)
			{
				tagTile* tempTile = new tagTile;
				D2D1_RECT_F* tempRect = new D2D1_RECT_F;
				tempTile->terrainFrameX = 0;
				tempTile->terrainFrameY = 0;

				tempTile->objectFrameX = 0;
				tempTile->objectFrameY = 0;

				tempTile->attr |= ATTR_NONE;

				tempTile->terrainImageName = TERRAIN_NAME_NONE;
				tempTile->objectImageName = OBJECT_NAME_NONE;

				*tempRect = { (float)_vvRect[i].back().right
							, (float)_vvRect[i].back().top
							, (float)_vvRect[i].back().right + TILE_SIZE
							, (float)_vvRect[i].back().bottom };
				_vvTile[i].push_back(tempTile);
				_vvRect[i].push_back(*tempRect);
			}
			++TILEX;
		}
	}
	
}

void mapTool::drawMap()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < TILEY; ++i)
		{
			for (int j = 0; j < TILEX; ++j)
			{
				if (PtInRect(&makeRECT(_vvRect[i][j]), makePOINT(_ptMouse)))
				{
					_vvTile[i][j]->terrainImageName = _sampleImgStr[_curImgNum];
					
					_vvTile[i][j]->terrainFrameX = _pickSampleTile.curX;
					_vvTile[i][j]->terrainFrameY = _pickSampleTile.curY;
					_vvTile[i][j]->attr = setAttribute(_vvTile[i][j]->terrainImageName, _vvTile[i][j]->terrainFrameX, _vvTile[i][j]->terrainFrameY);
				}
			}
		}
	}


}

void mapTool::save()
{
	HANDLE file;
	DWORD write;

	char mapSize[128];
	sprintf_s(mapSize, "%d, %d", TILEX, TILEY);
	file = CreateFile("mapSize1.map", GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	

	WriteFile(file, mapSize, strlen(mapSize), &write, NULL);

	CloseHandle(file);

	tagTile* tile = new tagTile[TILEX * TILEY];
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			tile[j + i * TILEX] = *_vvTile[i][j];
		}
	}

	HANDLE file2;
	DWORD write2;
	file2 = CreateFile("mapData.map", GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file2, tile, sizeof(tagTile) * TILEX * TILEY, &write, NULL);

	CloseHandle(file2);

	delete[] tile;
}

void mapTool::load()
{
	_vvTile.clear();

	HANDLE file;
	DWORD read;
	char mapSize[128] = { 0, };

	file = CreateFile("mapSize1.map", GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
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

	file2 = CreateFile("mapData.map", GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

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

DWORD mapTool::setAttribute(string imgName, UINT frameX, UINT frameY)
{
	DWORD result = ATTR_NONE;
	
	if (imgName == TERRAIN_NAME6)
	{

	}
	if (imgName == TERRAIN_NAME7)
	{

	}
	if (imgName == TERRAIN_NAME8)
	{

	}
	if (imgName == TERRAIN_NAME9)
	{

	}
	if (imgName == TERRAIN_NAME10)
	{

	}
	return result;
}
