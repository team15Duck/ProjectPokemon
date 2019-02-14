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
	_sampleImg[1] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME1]);
	_sampleImg[2] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME2]);
	_sampleImg[3] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME3]);
	_sampleImg[4] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME4]);
	_sampleImg[5] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME5]);
	_sampleImg[6] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME6]);
	_sampleImg[7] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME7]);
	_sampleImg[8] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME8]);
	_sampleImg[9] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME9]);
	_sampleImg[10] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME10]);
	_sampleImg[11] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME11]);
	_sampleImg[12] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME12]);
	_sampleImg[13] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME13]);
	_sampleImg[14] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME14]);
	_sampleImg[15] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME15]);
	_sampleImg[16] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME16]);
	_sampleImg[17] = IMAGEMANAGER->findImage(OBJECT_NAME[OBJECT_NAME17]);

	_curImgNum = OBJECT_NAME1;

	setTile();

	_preButton = { WINSIZEX / 2 + 100, WINSIZEY / 2 + 120, WINSIZEX / 2 + 150, WINSIZEY / 2 + 150 };
	_nextButton = { WINSIZEX / 2 + 250, WINSIZEY / 2 + 120, WINSIZEX / 2 + 300, WINSIZEY / 2 + 150 };

	_isTileClick = false;
	_isShift = false;
	_isCtrl = false;

	CAMERA->init(0, 0, 10000, 10000);

	_savePointX = 0;
	_savePointY = 0;


	_sampleSaveX = 0;
	_sampleSaveY = 0;
	_sampleDrawX = 1;
	_sampleDrawY = 1;


	//load("data/testMapSize.map", "data/testMapData.map");

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
	
	_preButton = { CAMERA->getPosX() + WINSIZEX / 2 + 400, CAMERA->getPosY() + WINSIZEY / 2 + 50, CAMERA->getPosX() + WINSIZEX / 2 + 450, CAMERA->getPosY() + WINSIZEY / 2 + 80 };
	_nextButton = { CAMERA->getPosX() + WINSIZEX / 2 + 550, CAMERA->getPosY() + WINSIZEY / 2 + 50, CAMERA->getPosX() + WINSIZEX / 2 + 600, CAMERA->getPosY() + WINSIZEY / 2 + 80 };

}

void objectTool::render()
{
	//맵 출력
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			if (_vvRect[i][j].left - (CAMERA->getPosX() - 50) < 0)
				continue;
			if (_vvRect[i][j].right - CAMERA->getPosX() > CAMERA_SHOW_RANGE)
				continue;
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

	for (int i = 0; i < SAMPLETILE; ++i)
	{
		for (int j = 0; j < SAMPLETILE; ++j)
		{
			D2DMANAGER->drawRectangle(CAMERA->getPosX() + _sampleTile[i][j].sampleRC.left
				, CAMERA->getPosY() + _sampleTile[i][j].sampleRC.top
				, CAMERA->getPosX() + _sampleTile[i][j].sampleRC.right
				, CAMERA->getPosY() + _sampleTile[i][j].sampleRC.bottom);
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
	//WCHAR str[128];
	//swprintf_s(str, L"현재 : %d", _curImgNum);
	//D2DMANAGER->drawText(str, 100, 400);
}

void objectTool::setTile()
{
	for (int i = 0; i < SAMPLETILE; i++)
	{
		for (int j = 0; j < SAMPLETILE; j++)
		{
			_sampleTile[i][j].frameX = 0;
			_sampleTile[i][j].frameY = 0;
			_sampleTile[i][j].sampleRC = { (float)(WINSIZEX - SAMPLE_TOTAL_SIZE) + (j * TILE_SIZE)
										  ,(float)30 + (i * TILE_SIZE)
										  ,(float)(WINSIZEX - SAMPLE_TOTAL_SIZE) + ((j + 1) * TILE_SIZE)
										  ,(float)30 + ((i + 1) * TILE_SIZE) };
		}
	}

	TILEX = 50;
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
}

DWORD objectTool::setAttribute(string imgName, UINT frameX, UINT frameY)
{
	DWORD result = ATTR_NONE;
	if (imgName == OBJECT_NAME[OBJECT_NAME1])
	{
		if ((frameX >= 0 && frameX < 5) && frameY == 0)
		{
			result |= ATTR_UNMOVE;
			//산지
		}
		else if (frameX == 5 && frameY == 0)
		{
			result |= ATTR_NONE;
			result |= ATTR_STONE_STATUE;
		}
		else if (frameX == 5 && frameY == 1)
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_STONE_STATUE;
		}
		else if ((frameX == 0 || frameX == 1 || frameX == 3 || frameX == 4) && frameY == 1)
		{
			result |= ATTR_UNMOVE;
			//산지
		}
		else if ((frameX == 2 && frameY == 1) || (frameX == 5 && frameY == 2))
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_ROCK;
		}
		else if (frameX == 0 && frameY == 2)
		{
			result |= ATTR_NONE;
			result |= ATTR_TREE;
		}
		else if (frameX == 0 && frameY == 3)
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_TREE;
		}
		else if ((frameX >= 1 && frameX < 4) && (frameY == 2 || frameY == 3))
		{
			result |= ATTR_UNMOVE;
			//산지
		}
		else if (frameX == 4 && frameY == 2)
		{
			result |= ATTR_NONE;
			//꽃밭
		}
		else if ((frameX == 4 || frameX == 5) && frameY == 3)
		{
			result |= ATTR_NONE;
			//계단
		}
		else if ((frameX >= 0 && frameX < 5) && frameY == 4)
		{
			result |= ATTR_NONE;
			//꽃
		}
		else if ((frameX >= 0 && frameX < 5) && frameY == 5)
		{
			result |= ATTR_NONE;
			result |= ATTR_APPEAR;
		}
		else if (frameX == 5 && frameY == 4)
		{
			result |= ATTR_UNMOVE;
			//표지판
		}
		else if (frameX == 5 && frameY == 5)
		{
			result |= ATTR_UNMOVE;
			//풀
		}
	}
	else if (imgName == OBJECT_NAME[OBJECT_NAME2])
	{
		if ((frameX == 0 && (frameY == 0 && frameY == 1)) ||
			((frameX >= 3 && frameX < 6) && (frameY == 2 || frameY == 3 || frameY == 6)) ||
			((frameX == 3 || frameX == 6) && (frameY == 1 || frameY == 4)))
		{
			result |= ATTR_UNMOVE;
			//울타리
		}
		else if ((frameX == 1 || frameX == 2) && (frameY >= 0 && frameY < 6))
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_TREE;
		}
		else if (frameX == 0 && (frameY >= 2 && frameY < 6))
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_OAK_MACHINE;
		}
	}
	else if (imgName == OBJECT_NAME[OBJECT_NAME3])
	{
		if ((frameX >= 0 && frameX < 6) && (frameY >= 0 && frameY < 4))
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_TREE;
		}
		else if ((frameX >= 0 && frameX < 6) && (frameY == 5 || frameY == 6))
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_ROCK;
		}
	}
	else if (imgName == OBJECT_NAME[OBJECT_NAME4])
	{
		if (((frameX == 0 || frameX == 2) && frameY == 1) ||
			((frameX >= 0 && frameX < 3) && frameY == 1) ||
			((frameX == 0 || frameX == 1) && frameY == 2))
		{
			result |= ATTR_NONE;
			result |= ATTR_JUMP;
		}
		else if ((frameX >= 3 && frameX < 6) && frameY == 0)
		{
			result |= ATTR_NONE;
			//테이블
		}
		else if ((frameX >= 3 && frameX < 6) && frameY == 1)
		{
			result |= ATTR_UNMOVE;
			//테이블
		}
		else if ((frameX >= 2 && frameX < 6) && frameY == 2)
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_CUT;
		}
		else if ((frameX == 0 || frameX == 1) && frameY == 3)
		{
			result |= ATTR_NONE;
			//포탈
		}
		else if (frameX == 2 && (frameY == 3 || frameY == 4))
		{
			result |= ATTR_NONE;
			//카페트
		}
		else if ((frameX == 4 || frameX == 5) && frameY == 3)
		{
			result |= ATTR_NONE;
		}
	}
	return result;
}
