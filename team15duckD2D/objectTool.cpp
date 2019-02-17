#include "stdafx.h"
#include "objectTool.h"


objectTool::objectTool()
{
}


objectTool::~objectTool()
{
}

HRESULT objectTool::init()
{
	//이미지
	_sampleImg_Obj[1] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME1]);
	_sampleImg_Obj[2] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME2]);
	_sampleImg_Obj[3] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME3]);
	_sampleImg_Obj[4] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME4]);
	_sampleImg_Obj[5] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME5]);
	_sampleImg_Obj[6] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME6]);
	_sampleImg_Obj[7] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME7]);
	_sampleImg_Obj[8] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME8]);
	_sampleImg_Obj[9] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME9]);
	_sampleImg_Obj[10] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME10]);
	_sampleImg_Obj[11] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME11]);
	_sampleImg_Obj[12] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME12]);
	_sampleImg_Obj[13] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME13]);
	_sampleImg_Obj[14] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME14]);
	_sampleImg_Obj[15] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME15]);
	_sampleImg_Obj[16] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME16]);
	_sampleImg_Obj[17] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME17]);

	//현재이미지번호
	_curImgNum = OBJECT_NAME1;

	//샘플타일세팅
	setSampleTile();

	//타일세팅
	setTile();

	nameInit();


	//좌우버튼
	_preButton = { WINSIZEX / 2 + 100, WINSIZEY / 2 + 120, WINSIZEX / 2 + 150, WINSIZEY / 2 + 150 };
	_nextButton = { WINSIZEX / 2 + 250, WINSIZEY / 2 + 120, WINSIZEX / 2 + 300, WINSIZEY / 2 + 150 };

	_isTileClick = false;
	_isShift = false;
	_isCtrl = false;
	_isLoad = false;

	CAMERA->init(0, 0, 10000, 10000);

	_savePointX = 0;
	_savePointY = 0;
	_sampleSaveX = 0;
	_sampleSaveY = 0;
	_sampleDrawX = 1;
	_sampleDrawY = 1;

	_mapCase = MAP_TEST;


	return S_OK;
}

void objectTool::release()
{
}

void objectTool::update()
{
	CAMERA->mapToolMove();
	turnObject();
	pickSampleObject();
	drawObject();

	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		_isSave = true;
		save(_mapCase);
	}
	if (KEYMANAGER->isOnceKeyUp(VK_F1))
		_isSave = false;

	if (KEYMANAGER->isOnceKeyDown(VK_F3))
	{
		load();
		_isLoad = true;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F5))
	{
		nextSaveName();
		setTile();
	}


	//테스트맵용
	//===============================
	ii = CAMERA->getPosY() / TILE_SIZE;
	if (ii < 0) ii = 0;
	iiMax = ((CAMERA->getPosY() + WINSIZEY) / TILE_SIZE) + 1;
	if (iiMax >= TILEY) iiMax = TILEY - 1;
	jj = CAMERA->getPosX() / TILE_SIZE;
	if (jj < 0) jj = 0;
	jjMax = ((CAMERA->getPosX() + WINSIZEX) / TILE_SIZE) + 1;
	if (jjMax >= TILEX) jjMax = TILEX - 1;
	//===============================

	_preButton = { CAMERA->getPosX() + WINSIZEX / 2 + 400, CAMERA->getPosY() + WINSIZEY / 2 + 50, CAMERA->getPosX() + WINSIZEX / 2 + 450, CAMERA->getPosY() + WINSIZEY / 2 + 80 };
	_nextButton = { CAMERA->getPosX() + WINSIZEX / 2 + 550, CAMERA->getPosY() + WINSIZEY / 2 + 50, CAMERA->getPosX() + WINSIZEX / 2 + 600, CAMERA->getPosY() + WINSIZEY / 2 + 80 };

}

void objectTool::render()
{
	WCHAR str[128];
	//=================================================================================================

	for (; ii < iiMax; ++ii)
	{
		for (; jj < jjMax; ++jj)
		{
			if (TERRAIN_NAME[_vvTile[ii][jj]->terrainImageIndex] != "none")
				IMAGEMANAGER->findImage(TERRAIN_NAME[_vvTile[ii][jj]->terrainImageIndex])->frameRender(jj * TILE_SIZE, ii * TILE_SIZE, _vvTile[ii][jj]->terrainFrameX, _vvTile[ii][jj]->terrainFrameY);
		}
		jj = CAMERA->getPosX() / TILE_SIZE;
		if (jj < 0) jj = 0;
	}
	ii = CAMERA->getPosY() / TILE_SIZE;

	//=================================================================================================
	//맵 출력
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			if (_vvRect[i][j].left - (CAMERA->getPosX() - 50) < 0)
				continue;
			if (_vvRect[i][j].right - CAMERA->getPosX() > CAMERA_SHOW_RANGE)
				continue;
			//렉트
			if (!_isLoad)
				D2DMANAGER->drawRectangle(_vvRect[i][j].left, _vvRect[i][j].top, _vvRect[i][j].right, _vvRect[i][j].bottom);
			if (_vvTile[i][j]->objectImageIndex == OBJECT_NAME_NONE) continue;
			IMAGEMANAGER->findImage(OBJECT_NAME[_vvTile[i][j]->objectImageIndex])->frameRender(_vvRect[i][j].left, _vvRect[i][j].top, _vvTile[i][j]->objectFrameX, _vvTile[i][j]->objectFrameY);
		}
	}

	if (_isTileClick)
		IMAGEMANAGER->findImage(OBJECT_NAME[_curImgNum])->frameRender(_ptMouse.x, _ptMouse.y, _pickSampleTile.curX, _pickSampleTile.curY, 0.5f);

	if (_isShift)
	{
		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
		{
			D2D1_RECT_F dragRc = { _savePointX * TILE_SIZE + 5, _savePointY * TILE_SIZE + 5, _ptMouse.x, _ptMouse.y };
			D2DMANAGER->drawRectangle(RGB(135, 12, 255), dragRc);
		}
	}

	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			if (OBJECT_NAME[_vvTile[i][j]->objectImageIndex] != "none")
			{
				if (_vvTile[i][j]->objectImageIndex == OBJECT_NAME17)
				{
					if (_vvTile[i][j]->objectFrameX == 3)
					{
						if (_vvTile[i][j]->objectFrameY == 4)
							IMAGEMANAGER->findImage(OBJECT_NAME[_vvTile[i][j]->objectImageIndex])->frameRender(_vvRect[i][j].left, _vvRect[i][j].top + 44, 0, 44, 64, 20, _vvTile[i][j]->objectFrameX, _vvTile[i][j]->objectFrameY);
						if (_vvTile[i][j]->objectFrameY == 5)
							IMAGEMANAGER->findImage(OBJECT_NAME[_vvTile[i][j]->objectImageIndex])->frameRender(_vvRect[i][j].left, _vvRect[i][j].top, 0, 0, 64, 20, _vvTile[i][j]->objectFrameX, _vvTile[i][j]->objectFrameY);
					}
				}

			}
		}

	}

	for (int i = 0; i < SAMPLETILE; ++i)
	{
		for (int j = 0; j < SAMPLETILE; ++j)
		{
			D2DMANAGER->drawRectangle(CAMERA->getPosX() + _sampleTile_Obj[i][j].sampleRC.left
				, CAMERA->getPosY() + _sampleTile_Obj[i][j].sampleRC.top
				, CAMERA->getPosX() + _sampleTile_Obj[i][j].sampleRC.right
				, CAMERA->getPosY() + _sampleTile_Obj[i][j].sampleRC.bottom);
		}
	}

	//샘플타일 출력
	IMAGEMANAGER->findImage(OBJECT_NAME[_curImgNum])->render(CAMERA->getPosX() + (WINSIZEX - SAMPLE_TOTAL_SIZE), CAMERA->getPosY() + 30);

	//버튼 출력
	D2DMANAGER->drawRectangle(_preButton.left, _preButton.top
		, _preButton.right, _preButton.bottom);
	D2DMANAGER->drawRectangle(_nextButton.left, _nextButton.top
		, _nextButton.right, _nextButton.bottom);

	//테슷흐
	for (; ii < iiMax; ++ii)
	{
		for (; jj < jjMax; ++jj)
		{
			if (KEYMANAGER->isToggleKey(VK_TAB))
			{
				if ((_vvTile[ii][jj]->attr & ATTR_UNMOVE) == ATTR_UNMOVE)
				{
					swprintf_s(str, L"UnMove");
					D2DMANAGER->drawText(str, jj * TILE_SIZE + 5, ii * TILE_SIZE + 5, 20, RGB(255, 0, 255));
				}
				if ((_vvTile[ii][jj]->attr & ATTR_POTAL) == ATTR_POTAL)
				{
					swprintf_s(str, L"POTAL");
					D2DMANAGER->drawText(str, jj * TILE_SIZE + 5, ii * TILE_SIZE + 5);
				}
			}
		}
		jj = CAMERA->getPosX() / TILE_SIZE;
		if (jj < 0) jj = 0;
	}
	ii = CAMERA->getPosY() / TILE_SIZE;

	swprintf_s(str, L"mapcase : %d", _mapCase);
	D2DMANAGER->drawText(str, CAMERA->getPosX(), CAMERA->getPosY() + 250);
	if (_isSave)
	{
		swprintf_s(str, L"세이브되었숩니다~~~~~~~~");
		D2DMANAGER->drawText(str, CAMERA->getPosX() + WINSIZEX / 2, CAMERA->getPosY() + WINSIZEY / 2);
	}
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{

	}
	//swprintf_s(str, L"현재 : %d", _curImgNum);
	//D2DMANAGER->drawText(str, 100, 400);
}

void objectTool::setSampleTile()
{
	for (int i = 0; i < SAMPLETILE; i++)
	{
		for (int j = 0; j < SAMPLETILE; j++)
		{
			_sampleTile_Obj[i][j].frameX = 0;
			_sampleTile_Obj[i][j].frameY = 0;
			_sampleTile_Obj[i][j].sampleRC = { (float)(WINSIZEX - SAMPLE_TOTAL_SIZE) + (j * TILE_SIZE)
										  ,(float)30 + (i * TILE_SIZE)
										  ,(float)(WINSIZEX - SAMPLE_TOTAL_SIZE) + ((j + 1) * TILE_SIZE)
										  ,(float)30 + ((i + 1) * TILE_SIZE) };
		}
	}
}

void objectTool::setTile()
{
	TILEX = 80;
	TILEY = 50;

	for (int i = 0; i < TILEY; i++)
	{
		vector<tagTile*> vTile;
		vector<D2D1_RECT_F> vRect;
		for (int j = 0; j < TILEX; j++)
		{
			tagTile* tempTile = new tagTile;
			D2D1_RECT_F* tempRect = new D2D1_RECT_F;

			tempTile->terrainFrameX = 0;
			tempTile->terrainFrameY = 0;

			tempTile->objectFrameX = 0;
			tempTile->objectFrameY = 0;

			tempTile->attr |= ATTR_NONE;

			tempTile->terrainImageIndex = TERRAIN_NAME_NONE;
			tempTile->objectImageIndex = OBJECT_NAME_NONE;

			*tempRect = { (float)j * TILE_SIZE, (float)i * TILE_SIZE, (float)(j + 1) * TILE_SIZE, (float)(i + 1) * TILE_SIZE };

			vTile.push_back(tempTile);
			vRect.push_back(*tempRect);
		}
		_vvTile.push_back(vTile);
		_vvRect.push_back(vRect);
	}
}

void objectTool::turnObject()
{
	const RECT tempPre = { _preButton.left, _preButton.top, _preButton.right, _preButton.bottom };
	POINT tempPTPre = { _ptMouse.x, _ptMouse.y };

	if (PtInRect(&tempPre, tempPTPre))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			--_curImgNum;
			if (_curImgNum < 1)
				_curImgNum = OBJECT_IMG_NUM - 1;
		}
	}

	const RECT tempNext = { _nextButton.left, _nextButton.top, _nextButton.right, _nextButton.bottom };
	POINT tempPTNext = { _ptMouse.x, _ptMouse.y };

	if (PtInRect(&tempNext, tempPTNext))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			++_curImgNum;
			if (_curImgNum >= OBJECT_IMG_NUM)
				_curImgNum = 1;
		}
	}
}

void objectTool::pickSampleObject()
{
	if (_ptMouse.x - CAMERA->getPosX() < SAMPLETILE_STARTX) return;

	int idxX = (_ptMouse.x - CAMERA->getPosX() - SAMPLETILE_STARTX) / TILE_SIZE;
	int idxY = (_ptMouse.y - CAMERA->getPosY() - 30) / TILE_SIZE;

	if (idxX >= SAMPLETILE || idxX < 0) return;
	if (idxY >= SAMPLETILE || idxY < 0) return;
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_isTileClick = true;

		_sampleSaveX = idxX;
		_sampleSaveY = idxY;

		if ((idxX >= 0 && idxX < SAMPLETILE) && (idxY >= 0 && idxY < SAMPLETILE))
		{
			_pickSampleTile.curX = idxX;
			_pickSampleTile.curY = idxY;
			_pickSampleTile.isObj = true;
		}
		else
			_isTileClick = false;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
	{
		_sampleDrawX = idxX + 1;
		if (_sampleDrawX <= _sampleSaveX) _sampleDrawX + 1;
		_sampleDrawY = idxY + 1;
		if (_sampleDrawY <= _sampleSaveY) _sampleDrawY + 1;
	}
}

void objectTool::drawObject()
{
	if (KEYMANAGER->isOnceKeyDown(VK_SHIFT))
		_isShift = true;

	if (KEYMANAGER->isOnceKeyUp(VK_SHIFT))
		_isShift = false;

	if (KEYMANAGER->isOnceKeyDown(VK_CONTROL))
		_isCtrl = true;

	if (KEYMANAGER->isOnceKeyUp(VK_CONTROL))
		_isCtrl = false;

	if (_ptMouse.x - CAMERA->getPosX() > SAMPLETILE_STARTX) return;
	if (_ptMouse.x > _vvRect[0][TILEX - 1].right) return;
	if (_ptMouse.x < _vvRect[0][0].left) return;
	if (_ptMouse.y > _vvRect[TILEY - 1][0].bottom) return;
	if (_ptMouse.y < _vvRect[0][0].top) return;

	if (_isShift && !_isCtrl)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			for (int i = 0; i < TILEY; ++i)
			{
				for (int j = 0; j < TILEX; ++j)
				{
					if (PtInRect(&makeRECT(_vvRect[i][j]), makePOINT(_ptMouse)))
					{
						_savePointY = i;
						_savePointX = j;
					}
				}
			}
		}
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			int savePX2;
			int savePY2;
			for (int i = 0; i < TILEY; ++i)
			{
				for (int j = 0; j < TILEX; ++j)
				{
					if (PtInRect(&makeRECT(_vvRect[i][j]), makePOINT(_ptMouse)))
					{
						savePY2 = i;
						savePX2 = j;
					}
				}
			}
			savePX2++;
			savePY2++;
			if (savePX2 < _savePointX) return;
			if (savePY2 < _savePointY) return;

			for (int i = _savePointY; i < savePY2; ++i)
			{
				for (int j = _savePointX; j < savePX2; ++j)
				{
					_vvTile[i][j]->objectImageIndex = _curImgNum;

					_vvTile[i][j]->objectFrameX = _pickSampleTile.curX;
					_vvTile[i][j]->objectFrameY = _pickSampleTile.curY;
					_vvTile[i][j]->attr = setAttribute(OBJECT_NAME[_curImgNum], _vvTile[i][j]->objectFrameX, _vvTile[i][j]->objectFrameY);
				}
			}
		}
	}
	else if (_isCtrl)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			for (int i = 0; i < TILEY; ++i)
			{
				for (int j = 0; j < TILEX; ++j)
				{
					if (PtInRect(&makeRECT(_vvRect[i][j]), makePOINT(_ptMouse)))
					{
						_saveTile.objectImageIndex = _vvTile[i][j]->objectImageIndex;
						_saveTile.objectFrameX = _vvTile[i][j]->objectFrameX;
						_saveTile.objectFrameY = _vvTile[i][j]->objectFrameY;
						_saveTile.terrainImageIndex = _vvTile[i][j]->terrainImageIndex;
						_saveTile.terrainFrameX = _vvTile[i][j]->terrainFrameX;
						_saveTile.terrainFrameY = _vvTile[i][j]->terrainFrameY;
						{
							_vvTile[i][j]->objectImageIndex = _curImgNum;

							_vvTile[i][j]->objectFrameX = _pickSampleTile.curX;
							_vvTile[i][j]->objectFrameY = _pickSampleTile.curY;
							_vvTile[i][j]->attr = setAttribute(OBJECT_NAME[_curImgNum], _vvTile[i][j]->objectFrameX, _vvTile[i][j]->objectFrameY);
						}
					}
				}
			}
		}
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			for (int i = 0; i < TILEY; ++i)
			{
				for (int j = 0; j < TILEX; ++j)
				{
					if (_saveTile.terrainImageIndex == _vvTile[i][j]->terrainImageIndex && _saveTile.objectImageIndex == _vvTile[i][j]->objectImageIndex &&
						_saveTile.terrainFrameX == _vvTile[i][j]->terrainFrameX		  && _saveTile.terrainFrameY == _vvTile[i][j]->terrainFrameY &&
						_saveTile.objectFrameX == _vvTile[i][j]->objectFrameX		  && _saveTile.objectFrameY == _vvTile[i][j]->objectFrameY)
					{
						_vvTile[i][j]->objectImageIndex = _curImgNum;

						_vvTile[i][j]->objectFrameX = _pickSampleTile.curX;
						_vvTile[i][j]->objectFrameY = _pickSampleTile.curY;
						_vvTile[i][j]->attr = setAttribute(OBJECT_NAME[_curImgNum], _vvTile[i][j]->objectFrameX, _vvTile[i][j]->objectFrameY);
					}
				}
			}
		}
	}
	else
	{
		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
		{
			for (int i = 0; i < TILEY; ++i)
			{
				for (int j = 0; j < TILEX; ++j)
				{
					if (PtInRect(&makeRECT(_vvRect[i][j]), makePOINT(_ptMouse)))
					{
						int drawAreaX = 0;
						int drawAreaY = 0;
						for (int ii = _sampleSaveY; ii < _sampleDrawY; ii++, drawAreaY++)
						{
							for (int jj = _sampleSaveX; jj < _sampleDrawX; jj++, drawAreaX++)
							{
								_vvTile[i + drawAreaY][j + drawAreaX]->objectImageIndex = _curImgNum;
								_vvTile[i + drawAreaY][j + drawAreaX]->objectFrameX = _pickSampleTile.curX + drawAreaX;
								_vvTile[i + drawAreaY][j + drawAreaX]->objectFrameY = _pickSampleTile.curY + drawAreaY;
								_vvTile[i + drawAreaY][j + drawAreaX]->attr = setAttribute(OBJECT_NAME[_curImgNum],
									_vvTile[i + drawAreaY][j + drawAreaX]->objectFrameX,
									_vvTile[i + drawAreaY][j + drawAreaX]->objectFrameY);
							}
							drawAreaX = 0;
						}
					}
				}
			}
		}
	}
	//지우긔
	if (KEYMANAGER->isStayKeyDown(VK_RBUTTON))
	{
		for (int i = 0; i < TILEY; ++i)
		{
			for (int j = 0; j < TILEX; ++j)
			{
				if (PtInRect(&makeRECT(_vvRect[i][j]), makePOINT(_ptMouse)))
				{
					_vvTile[i][j]->objectImageIndex = OBJECT_NAME_NONE;
					_vvTile[i][j]->objectFrameX = 0;
					_vvTile[i][j]->objectFrameY = 0;
					_vvTile[i][j]->attr = setAttribute(OBJECT_NAME[_vvTile[i][j]->objectImageIndex], _vvTile[i][j]->objectFrameX, _vvTile[i][j]->objectFrameY);
				}
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F7))
	{
		for (int i = 0; i < TILEY; ++i)
		{
			for (int j = 0; j < TILEX; ++j)
			{
				if (PtInRect(&makeRECT(_vvRect[i][j]), makePOINT(_ptMouse)))
				{
					_vvTile[i][j]->attr = ATTR_UNMOVE;
				}
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F8))
	{
		for (int i = 0; i < TILEY; ++i)
		{
			for (int j = 0; j < TILEX; ++j)
			{
				if (PtInRect(&makeRECT(_vvRect[i][j]), makePOINT(_ptMouse)))
				{
					_vvTile[i][j]->attr = ATTR_NONE;
				}
			}
		}
	}
}

void objectTool::save(int mapCase)
{
	HANDLE file;
	DWORD write;

	char mapSize[128];
	sprintf_s(mapSize, "%d, %d", TILEX, TILEY);
	file = CreateFile(_mSizeNames[(MAP_NAME)mapCase].c_str(), GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

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
	file2 = CreateFile(_mDataNames[(MAP_NAME)mapCase].c_str(), GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file2, tile, sizeof(tagTile) * TILEX * TILEY, &write, NULL);

	CloseHandle(file2);

	/*HANDLE file3;
	DWORD write3;
	file3 = CreateFile(_mPotalPos[(MAP_NAME)mapCase].c_str(), GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file2, tile, sizeof(tagTile) * TILEX * TILEY, &write, NULL);*/


	delete[] tile;

}

void objectTool::load()
{
	for (int i = TILEY - 1; i >= 0; i--)
	{
		for (int j = TILEX - 1; j >= 0; j--)
		{
			if (_vvTile[i][j])
			{
				SAFE_DELETE(_vvTile[i][j]);
				_vvTile[i].pop_back();
			}
		}
		_vvTile.pop_back();
	}


	_vvTile.clear();

	HANDLE file;
	DWORD read;
	char mapSize[128] = { 0, };

	file = CreateFile(_mSizeNames[(MAP_NAME)_mapCase].c_str(), GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
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
		if (mapSize[i] == NULL)
			break;
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

	tagTile* tile = (tagTile*)malloc(sizeof(tagTile) * TILEX * TILEY);
	ZeroMemory(tile, sizeof(tagTile) * (TILEX * TILEY));

	HANDLE file2;
	DWORD read2;

	file2 = CreateFile(_mDataNames[(MAP_NAME)_mapCase].c_str(), GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file2, tile, sizeof(tagTile) * TILEX * TILEY, &read2, NULL);

	CloseHandle(file2);

	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			_vvTile[i][j] = new tagTile;
			_vvTile[i][j]->setTile(tile[j + i * TILEX]);
		}
	}
}

void objectTool::nextSaveName()
{
	_mapCase = 1 + _mapCase;
	if (_mapCase == MAP_COUNT)
		_mapCase = 1;

}

void objectTool::nameInit()
{
	_mSizeNames.insert(make_pair(MAP_TEST, "data/testMapSize.map"));
	_mDataNames.insert(make_pair(MAP_TEST, "data/testMapData.map"));

	_mDataNames.insert(make_pair(MAP_TOWN, "data/townMapData.map"));
	_mSizeNames.insert(make_pair(MAP_TOWN, "data/townMapSize.map"));

	_mSizeNames.insert(make_pair(MAP_HOME, "data/homeMapSize.map"));
	_mDataNames.insert(make_pair(MAP_HOME, "data/homeMapData.map"));

	_mSizeNames.insert(make_pair(MAP_O_LAB, "data/oLabMapSize.map"));
	_mDataNames.insert(make_pair(MAP_O_LAB, "data/oLabMapData.map"));

	_mSizeNames.insert(make_pair(MAP_FIELD, "data/fieldMapSize.map"));
	_mDataNames.insert(make_pair(MAP_FIELD, "data/fieldMapData.map"));

	_mSizeNames.insert(make_pair(MAP_CAVE, "data/caveMapSize.map"));
	_mDataNames.insert(make_pair(MAP_CAVE, "data/caveMapData.map"));

	_mSizeNames.insert(make_pair(MAP_STORE, "data/storeMapSize.map"));
	_mDataNames.insert(make_pair(MAP_STORE, "data/storeMapData.map"));

	_mSizeNames.insert(make_pair(MAP_CENTER, "data/centerMapSize.map"));
	_mDataNames.insert(make_pair(MAP_CENTER, "data/centerMapData.map"));

	_mSizeNames.insert(make_pair(MAP_GYM, "data/gymMapSize.map"));
	_mDataNames.insert(make_pair(MAP_GYM, "data/gymMapData.map"));
}

DWORD objectTool::setAttribute(string imgName, UINT frameX, UINT frameY)
{
	DWORD result = ATTR_NONE;
	if (imgName == OBJECT_NAME[OBJECT_NAME1])
	{

		if ((frameX == 0 || frameX == 4) && frameY == 0) //산지형
		{
			result |= ATTR_UNMOVE;
		}
		else if ((frameX >= 0 && frameX < 5) && frameY == 1) //산지형 + 돌
		{
			result |= ATTR_UNMOVE;
		}
		else if ((frameX >= 1 && frameX < 4) && (frameY == 2 || frameY == 3)) //산지형
		{
			result |= ATTR_UNMOVE;
		}

		else if (frameX == 5 && frameY == 1) //석상(아랫부분)
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_STONE_STATUE;
		}
		else if (frameX == 5 && frameY == 2) //돌
		{
			result |= ATTR_UNMOVE;
		}
		else if (frameX == 0 && frameY == 3) //작은나무(풀베기 X)
		{
			result |= ATTR_UNMOVE;
		}
		else if ((frameX >= 0 && frameX < 5) && frameY == 4)
		{
			result |= ATTR_FLOWER;
		}
		else if ((frameX >= 0 && frameX < 5) && frameY == 5) //풀(프레임, 몬스터등장)
		{
			result |= ATTR_NONE;
			result |= ATTR_APPEAR;
		}
		else if (frameX == 5 && frameY == 4) //표지판
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_SIGN;
		}
		else if (frameX == 5 && frameY == 5) //동그란 풀
		{
			result |= ATTR_UNMOVE;
		}
	}
	else if (imgName == OBJECT_NAME[OBJECT_NAME2])
	{
		if (frameX == 0 && (frameY == 0 || frameY == 1)) //울타리
		{
			result |= ATTR_UNMOVE;
		}
		else if ((frameX >= 3 && frameX < 6) && (frameY >= 0 && frameY < 6)) //울타리
		{
			result |= ATTR_UNMOVE;
			if (frameX == 4 && frameY == 1) //표지판
				result |= ATTR_SIGN;
		}
		else if ((frameX == 1 || frameX == 2) && (frameY >= 0 && frameY < 6)) //나무
		{
			if (frameY != 3)
				result |= ATTR_UNMOVE;
		}
		else if (frameX == 0 && (frameY >= 2 && frameY < 6)) //오박사집 기계
		{
			result |= ATTR_NONE;
			result |= ATTR_OAK_MACHINE;
			if (frameY == 3 || frameY == 5)
				result |= ATTR_UNMOVE;
		}
	}
	else if (imgName == OBJECT_NAME[OBJECT_NAME3])
	{
		if ((frameX >= 0 && frameX < 6) && (frameY >= 0 && frameY < 3)) //큰나무
		{
			result |= ATTR_UNMOVE;
		}
		else if ((frameX >= 0 && frameX < 4) && (frameY == 4 || frameY == 5)) //돌
		{
			result |= ATTR_UNMOVE;
		}
	}
	else if (imgName == OBJECT_NAME[OBJECT_NAME4])
	{
		if ((frameX == 1 && frameY == 1) || ((frameX == 0 || frameX == 1) && frameY == 2)) //점프할 수 있는 언덕
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_DOWN_JUMP;
		}
		else if (frameX == 0 && frameY == 0) //왼쪽점프
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_LEFT_JUMP;
		}
		else if (frameX == 2 && frameY == 0) //오른쪽점프
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_RIGHT_JUMP;
		}
		else if ((frameX == 0 || frameY == 2) && frameY == 1) //점프할 수 있는 언덕의 대각선부분
		{
			result |= ATTR_UNMOVE;
		}
		else if ((frameX >= 3 && frameX < 6) && (frameY == 1 || frameY == 0)) //오박사 테이블
		{
			result |= ATTR_UNMOVE;
		}
		else if ((frameX >= 2 && frameX < 6) && frameY == 2) //풀베기(프레임)
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_CUT;
		}
		else if ((frameX >= 0 && frameX < 3) && (frameY == 3 || frameY == 4)) //카페트(포탈X)
		{
			if (frameX == 1 && frameY == 3) //카페트(포탈)
			{
				result |= ATTR_NONE;
				result |= ATTR_POTAL;
			}
		}
		else if ((frameX == 4 || frameX == 5) && frameY == 3) //지도
		{
			result |= ATTR_UNMOVE;
		}
		else if ((frameX >= 0 && frameX < 3) && frameY == 5) //장식용
		{
			result |= ATTR_UNMOVE;
		}
		else if (frameX == 3 && (frameY == 3 || frameY == 4 || frameY == 5)) //계단
		{
			result |= ATTR_UNMOVE;
		}
		else if (frameX == 4 && frameY == 5)
		{
			result |= ATTR_UNMOVE;
		}
		else if (frameX == 4 && frameY == 4) //계단(포탈)
		{
			result |= ATTR_NONE;
			result |= ATTR_POTAL;
		}
		else if (frameX == 5 && frameY == 5)
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_SIGN_GYM;
		}
	}
	else if (imgName == OBJECT_NAME[OBJECT_NAME5])
	{

		if ((frameX >= 0 && frameX < 3) && (frameY >= 0 && frameY < 3)) //물(낚시가능)
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_WATER;
		}
		else if (frameX == 4 && frameY == 2) //동굴입구
		{
			result |= ATTR_NONE;
			result |= ATTR_POTAL;
		}
		else if ((frameX == 3 || frameX == 5) && frameY == 2)
		{
			result |= ATTR_UNMOVE;
		}
		else if ((frameX >= 3 && frameX < 6) && (frameY == 0 || frameY == 1 || frameY == 3)) // 동굴
		{
			result |= ATTR_UNMOVE;
		}
		else if (frameX == 3 && (frameY == 4 || frameY == 5)) //동굴벽
		{
			result |= ATTR_UNMOVE;
		}
		else if ((frameX >= 0 && frameX < 3) && frameY == 5) //다리(못감)
		{
			result |= ATTR_UNMOVE;
		}
		else if ((frameX == 4 && frameY == 4)) //필드아이템
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_ITEM;
		}
		else if (frameX == 5 && frameY == 4) //미니맵아이템
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_ITEM;
		}
		else if (frameX == 4 && frameY == 5) //포스터
		{
			result |= ATTR_UNMOVE;
		}
	}
	else if (imgName == OBJECT_NAME[OBJECT_NAME6])
	{
		if (frameX == 0 && (frameY >= 0 && frameY < 3)) //센터카운터
		{
			result |= ATTR_UNMOVE;
		}
		else if ((frameX >= 0 && frameX < 6) && (frameY >= 3 && frameY < 6)) //센터카운터
		{
			if (frameX == 4 && frameY == 3) //우체통
				result |= ATTR_UNMOVE;
			else if ((frameX >= 0 && frameX < 3) && (frameY == 3 || frameY == 4))
				result |= ATTR_UNMOVE;
			else if (frameY == 5)
				result |= ATTR_UNMOVE;
			else if (frameX == 5)
				result |= ATTR_UNMOVE;
			else if (frameX == 3 && frameY == 5)
				result |= ATTR_CENTER;
		}
		else if ((frameX == 1 || frameX == 2) && (frameY == 0 || frameY == 1)) //컴퓨터 윗부분
		{
			result |= ATTR_UNMOVE;
		}
		else if ((frameX == 1 || frameX == 2) && frameY == 2) //컴퓨터
		{
			result |= ATTR_NONE;
			result |= ATTR_COMPUTER;
		}
		else if ((frameX == 4 || frameX == 5) && (frameY == 0 || frameY == 1)) //테이블
		{
			result |= ATTR_UNMOVE;
		}
		else if (frameX == 3 && (frameY >= 0 && frameY < 4)) //액자나 창문
		{
			result |= ATTR_UNMOVE;
		}
		else if (frameX == 5 && frameY == 2) //포켓몬도감
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_ITEM;
		}
	}
	else if (imgName == OBJECT_NAME[OBJECT_NAME7])
	{

		if ((frameX == 0 || frameX == 1) && (frameY >= 0 && frameY < 4)) //진열대
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_STORE_STAND;
		}
		else if ((frameX >= 1 && frameX < 4) && (frameY == 4 || frameY == 5))
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_STORE_STAND;
		}
		else if (frameX == 2 && (frameY >= 0 && frameY < 4)) //상점주인 있는 곳
		{
			result |= ATTR_UNMOVE;
			if (frameY == 2)
				result |= ATTR_SHOP; //주인과 상호작용
		}
		else if ((frameX >= 3 && frameX < 6) && (frameY == 0 || frameY == 1)) //상점주인 있는 곳
		{
			result |= ATTR_UNMOVE;
			if (frameX == 3 && frameY == 5)
				result |= ATTR_SHOP; //주인과 상호작용
		}
		else if ((frameX >= 3 && frameX < 5) && frameY == 2) //싱크대 위
		{
			result |= ATTR_UNMOVE;
		}
		else if ((frameX >= 3 && frameX < 5) && frameY == 3) //싱크대
		{
			result |= ATTR_SINK;
		}
		else if (frameX == 5 && (frameY == 2 || frameY == 3)) //화분
		{
			if (frameY != 2)
				result |= ATTR_UNMOVE;
		}
		else if (frameX == 0 && (frameY == 4 || frameY == 5)) //상점 냉장고
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_STORE_DISPLAY;
		}
		else if ((frameX == 4 || frameX == 5) && (frameY == 4 || frameY == 5)) //식기장
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_PANTRY;
		}

	}
	else if (imgName == OBJECT_NAME[OBJECT_NAME8])
	{
		if ((frameX >= 3 && frameX < 6) && (frameY == 0 || frameY == 1)) //컴퓨터, 책상, 창문
		{
			result |= ATTR_UNMOVE;
			if (frameX == 3 && frameY == 1)
				result |= ATTR_COMPUTER;
		}
		else if ((frameX == 0 || frameX == 1) && frameY == 3) //책장
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_BOOKCASE;
		}
		else if (frameX == 2 && (frameY == 3 || frameY == 4)) //TV
		{
			result |= ATTR_UNMOVE;
		}
		else if (frameX == 2 && frameY == 5) //게임기
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_GAME;
		}
		else if ((frameX >= 3 && frameX < 6) && (frameX == 4 || frameY == 5)) //침대(헤드X)
		{
			if (frameX == 4 && frameY == 5)
				result |= ATTR_UNMOVE;
		}
	}
	else if (imgName == OBJECT_NAME[OBJECT_NAME9])
	{
		if ((frameX >= 0 && frameX < 6) && frameY == 0)	 //포켓몬센터 모니터
		{
			result |= ATTR_UNMOVE;
		}
		else if ((frameX == 2 || frameX == 3) && (frameY >= 2 && frameY < 4)) //오박사기계
		{
			result |= ATTR_UNMOVE;
		}
		else if ((frameX == 0 || frameX == 1) && (frameY >= 1 || frameY < 3)) //책장
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_BOOKCASE;
		}
		else if ((frameX == 4 || frameX == 5) && (frameY == 3 || frameY == 4)) //테이블
		{
			result |= ATTR_UNMOVE;
		}
		else if ((frameX >= 0 && frameX < 4) && (frameY == 4 || frameY == 5)) //오박사컴퓨터
		{
			result |= ATTR_UNMOVE;
		}
		else if (frameX == 4 && (frameY == 1 || frameY == 2)) //계단
		{
			if (frameY == 1)
			{
				result |= ATTR_NONE;
				result |= ATTR_POTAL;
			}
			else
			{
				result |= ATTR_UNMOVE;
			}
		}
		else if (frameX == 5 && frameY == 2)
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_TIP;
		}
	}
	else if (imgName == OBJECT_NAME[OBJECT_NAME10])
	{
		if (frameX == 0 && (frameY >= 0 && frameY < 4)) //동굴
		{
			result |= ATTR_UNMOVE;
		}
		else if (frameX == 4 && (frameY >= 0 && frameY < 3)) //동굴
		{
			result |= ATTR_UNMOVE;
		}
		else if (frameX == 5 && (frameY >= 0 && frameY < 4)) //동굴
		{
			result |= ATTR_UNMOVE;
		}
		else if (frameX == 2 && (frameY == 1 || frameY == 3)) //동굴
		{
			result |= ATTR_UNMOVE;
		}
		else if (frameX == 1 && frameY == 3) //동굴출구
		{
			result |= ATTR_UNMOVE;
		}
		else if ((frameX >= 0 && frameX < 3) && frameY == 5) //비주기가 여기 서있는다.
		{
			result |= ATTR_UNMOVE;
		}
		else if (frameX == 4 && frameY == 4) //발매트, 실내->실외 포탈
		{
			result |= ATTR_NONE;
			result |= ATTR_POTAL;
		}

	}
	else if (imgName == OBJECT_NAME[OBJECT_NAME11])
	{
		if ((frameX >= 0 && frameX < 5) && (frameY >= 1 && frameY < 5))
		{
			if (frameX == 1 && frameY == 4) //문
			{
				result |= ATTR_NONE;
				result |= ATTR_POTAL;
			}
			else
				result |= ATTR_UNMOVE;
		}
	}
	else if (imgName == OBJECT_NAME[OBJECT_NAME12])
	{
		if ((frameX >= 0 && frameX < 6) && (frameY >= 1 && frameY < 5))
		{
			if (frameX == 3 && frameY == 4) //문
			{
				result |= ATTR_NONE;
				result |= ATTR_POTAL;
			}
			else
				result |= ATTR_UNMOVE;
		}
	}
	else if (imgName == OBJECT_NAME[OBJECT_NAME13])
	{
		if ((frameX >= 0 && frameX < 5) && (frameY >= 1 && frameY < 5))
		{
			if (frameX == 2 && frameY == 4) //문
			{
				result |= ATTR_NONE;
				result |= ATTR_POTAL;
			}
			else
				result |= ATTR_UNMOVE;
		}
	}
	else if (imgName == OBJECT_NAME[OBJECT_NAME14])
	{
		if ((frameX >= 0 && frameX < 4) && (frameY >= 1 && frameY < 4))
		{
			if (frameX == 2 && frameY == 3) //문
			{
				result |= ATTR_NONE;
				result |= ATTR_POTAL;
			}
			else
				result |= ATTR_UNMOVE;
		}
	}
	else if (imgName == OBJECT_NAME[OBJECT_NAME15])
	{
		if ((frameX >= 0 && frameX < 6) && (frameY >= 1 && frameY < 5))
		{
			if (frameX == 3 && frameY == 4) //문
			{
				result |= ATTR_NONE;
				result |= ATTR_POTAL;
			}
			else if (!((frameX >= 0 && frameX < 6) && frameY == 4))
				result |= ATTR_UNMOVE;
		}
	}
	else if (imgName == OBJECT_NAME[OBJECT_NAME16])
	{
		if ((frameX >= 0 && frameX < 5) && (frameY >= 0 && frameY < 4))
		{
			result |= ATTR_NONE;
			result |= ATTR_POTAL;
		}
	}
	else if (imgName == OBJECT_NAME[OBJECT_NAME17])
	{
		if ((frameX >= 0 && frameX < 3) && (frameY >= 1 && frameY < 5))
		{
			result |= ATTR_UNMOVE;
		}
		else if (frameX == 3 && (frameY == 4 || frameY == 5))
		{
			result |= ATTR_ITEM;
			result |= ATTR_UNMOVE;
		}
		else if (frameX == 4 && (frameY == 0 || frameY == 2))
		{
			result |= ATTR_UNMOVE;
		}
	}


	return result;
}
