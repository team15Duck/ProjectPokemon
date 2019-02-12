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
	_sampleImg[0] = IMAGEMANAGER->addFrameImage(OBJECT_NAME1, L"image/object/object_1.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	_sampleImg[1] = IMAGEMANAGER->addFrameImage(OBJECT_NAME2, L"image/object/object_2.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	_sampleImg[2] = IMAGEMANAGER->addFrameImage(OBJECT_NAME3, L"image/object/object_3.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	_sampleImg[3] = IMAGEMANAGER->addFrameImage(OBJECT_NAME4, L"image/object/object_4.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	_sampleImg[4] = IMAGEMANAGER->addFrameImage(OBJECT_NAME5, L"image/object/object_5.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	_sampleImg[5] = IMAGEMANAGER->addFrameImage(OBJECT_NAME6, L"image/object/object_6.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	_sampleImg[6] = IMAGEMANAGER->addFrameImage(OBJECT_NAME7, L"image/object/object_7.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	_sampleImg[7] = IMAGEMANAGER->addFrameImage(OBJECT_NAME8, L"image/object/object_8.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	_sampleImg[8] = IMAGEMANAGER->addFrameImage(OBJECT_NAME9, L"image/object/object_9.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	_sampleImg[9] = IMAGEMANAGER->addFrameImage(OBJECT_NAME10, L"image/object/object_10.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	_sampleImg[10] = IMAGEMANAGER->addFrameImage(OBJECT_NAME11, L"image/object/myHouse4x4.png", 320, 320, 5, 5);
	_sampleImg[11] = IMAGEMANAGER->addFrameImage(OBJECT_NAME12, L"image/object/OBakSaJHouse7x5.png", 448, 320, 7, 5);
	_sampleImg[12] = IMAGEMANAGER->addFrameImage(OBJECT_NAME13, L"image/object/pokemonCenter5x5.png", 320, 320, 5, 5);
	_sampleImg[13] = IMAGEMANAGER->addFrameImage(OBJECT_NAME14, L"image/object/pokemonShop4x4.png", 256, 256, 4, 4);
	_sampleImg[14] = IMAGEMANAGER->addFrameImage(OBJECT_NAME15, L"image/object/pokemonGym8x5.png", 512, 320, 8, 5);
	_sampleImg[15] = IMAGEMANAGER->addFrameImage(OBJECT_NAME16, L"image/object/openTheDoor.png", 320, 256, 5, 4);
	_sampleImg[16] = IMAGEMANAGER->addFrameImage(OBJECT_NAME17, L"image/object/healing_Pokemon.png", 120, 24, 5, 1);

	_curImgNum = 0;
	_sampleImgStr[0] = OBJECT_NAME1;
	setTile();

	_preButton = { WINSIZEX / 2 + 100, WINSIZEY / 2 + 120, WINSIZEX / 2 + 150, WINSIZEY / 2 + 150 };
	_nextButton = { WINSIZEX / 2 + 250, WINSIZEY / 2 + 120, WINSIZEX / 2 + 300, WINSIZEY / 2 + 150 };

	_isTileClick = false;
	_isObj = true;
	CAMERA->init(0, 0, 3000, 3000);

	_isShift = false;
	_isCtrl = false;
	_savePointX = 0;
	_savePointY = 0;
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

	//_preButton = { CAMERA->getPosX() + WINSIZEX / 2 + 400, CAMERA->getPosY() + WINSIZEY / 2 + 50, CAMERA->getPosX() + WINSIZEX / 2 + 450, CAMERA->getPosY() + WINSIZEY / 2 + 80 };
	//_nextButton = { CAMERA->getPosX() + WINSIZEX / 2 + 550, CAMERA->getPosY() + WINSIZEY / 2 + 50, CAMERA->getPosX() + WINSIZEX / 2 + 600, CAMERA->getPosY() + WINSIZEY / 2 + 80 };
	
}

void objectTool::render()
{
	if (_isObj)
	{
		IMAGEMANAGER->findImage(_sampleImgStr[_curImgNum])->render(CAMERA->getPosX() + (WINSIZEX - SAMPLE_TOTAL_SIZE), CAMERA->getPosY() + 30);
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

	//이전,다음 버튼 렌더
	D2DMANAGER->drawRectangle(_preButton.left
		, _preButton.top
		, _preButton.right
		, _preButton.bottom);
	D2DMANAGER->drawRectangle(_nextButton.left
		, _nextButton.top
		, _nextButton.right
		, _nextButton.bottom);

	//맵 렌더
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			if (_vvRect[i][j].left - (CAMERA->getPosX() - 50) < 0)
				continue;
			if (_vvRect[i][j].right - CAMERA->getPosX() > CAMERA_SHOW_RANGE)
				continue;
			D2DMANAGER->drawRectangle(_vvRect[i][j].left, _vvRect[i][j].top, _vvRect[i][j].right, _vvRect[i][j].bottom);
			if (_vvTile[i][j]->objectImageName == OBJECT_NAME_NONE) continue;
			if (_vvTile[i][j]->attr == ATTR_APPEAR)
			{
				//IMAGEMANAGER->findImage(_vvTile[i][j]->terrainImageName)->frameRender(_vvRect[i][j].left, _vvRect[i][j].top, _vvTile[i][j]->terrainFrameX, _vvTile[i][j]->terrainFrameY);
				IMAGEMANAGER->findImage(_vvTile[i][j]->objectImageName)->frameRender(_vvRect[i][j].left, _vvRect[i][j].top, _vvTile[i][j]->objectFrameX, _vvTile[i][j]->objectFrameY);
			}
			else
				IMAGEMANAGER->findImage(_vvTile[i][j]->objectImageName)->frameRender(_vvRect[i][j].left, _vvRect[i][j].top, _vvTile[i][j]->objectFrameX, _vvTile[i][j]->objectFrameY);
				//IMAGEMANAGER->findImage(_vvTile[i][j]->terrainImageName)->frameRender(_vvRect[i][j].left, _vvRect[i][j].top, _vvTile[i][j]->terrainFrameX, _vvTile[i][j]->terrainFrameY);
		}
	}

	if (_isTileClick)
	{
		if (!_isObj)
			IMAGEMANAGER->findImage(_sampleImgStr[_curImgNum])->frameRender(_ptMouse.x, _ptMouse.y, _pickSampleTile.curX, _pickSampleTile.curY, 0.5f);
		else
			IMAGEMANAGER->findImage(_sampleImgStr[_curImgNum])->frameRender(_ptMouse.x, _ptMouse.y, _pickSampleTile.curX, _pickSampleTile.curY, 0.5f);

	}

	if (_isShift)
	{
		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
		{
			D2D1_RECT_F dragRc = { _savePointX * TILE_SIZE + 5, _savePointY * TILE_SIZE + 5, _ptMouse.x, _ptMouse.y };

			D2DMANAGER->drawRectangle(RGB(135,12,255),dragRc);
		}
		



	}




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

void objectTool::turnObject()
{
	const RECT tempPre = { _preButton.left, _preButton.top, _preButton.right, _preButton.bottom };
	POINT tempPTPre = { _ptMouse.x, _ptMouse.y };

	if (PtInRect(&tempPre, tempPTPre))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			if (_isObj)
			{
				--_curImgNum;
				if (_curImgNum < 0)
					_curImgNum = OBJECT_IMG_NUM - 1;
				char str[128];
				if (_curImgNum + 1 == 10)
				{
					sprintf_s(str, "object_10", _curImgNum + 1);
					_sampleImgStr[_curImgNum] = str;
					return;

				}
				else if (_curImgNum + 1 == 11)
				{
					sprintf_s(str, "my_House", _curImgNum + 1);
					_sampleImgStr[_curImgNum] = str;
					return;
				}
				else if (_curImgNum + 1 == 12)
				{
					sprintf_s(str, "oak_House", _curImgNum + 1);
					_sampleImgStr[_curImgNum] = str;
					return;
				}
				else if (_curImgNum + 1 == 13)
				{
					sprintf_s(str, "pokemon_Center", _curImgNum + 1);
					_sampleImgStr[_curImgNum] = str;
					return;
				}
				else if (_curImgNum + 1 == 14)
				{
					sprintf_s(str, "pokemon_Shop", _curImgNum + 1);
					_sampleImgStr[_curImgNum] = str;
					return;
				}
				else if (_curImgNum + 1 == 15)
				{
					sprintf_s(str, "pokemon_Gym", _curImgNum + 1);
					_sampleImgStr[_curImgNum] = str;
					return;
				}
				else if (_curImgNum + 1 == 16)
				{
					sprintf_s(str, "openTheDoor", _curImgNum + 1);
					_sampleImgStr[_curImgNum] = str;
					return;
				}
				else if (_curImgNum + 1 == 17)
				{
					sprintf_s(str, "healing_Pokemon", _curImgNum + 1);
					_sampleImgStr[_curImgNum] = str;
					return;
				}
				sprintf_s(str, "object_0%d", _curImgNum + 1);
				_sampleImgStr[_curImgNum] = str;
			}
		}
	}

	const RECT tempNext = { _nextButton.left, _nextButton.top, _nextButton.right, _nextButton.bottom };
	POINT tempPTNext = { _ptMouse.x, _ptMouse.y };

	if (PtInRect(&tempNext, tempPTNext))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			if (_isObj)
			{
				++_curImgNum;
				if (_curImgNum >= OBJECT_IMG_NUM)
					_curImgNum = 0;
				char str[128];
				if (_curImgNum + 1 == 10)
				{
					sprintf_s(str, "object_10", _curImgNum + 1);
					_sampleImgStr[_curImgNum] = str;
					return;

				}
				else if (_curImgNum + 1 == 11)
				{
					sprintf_s(str, "my_House", _curImgNum + 1);
					_sampleImgStr[_curImgNum] = str;
					return;
				}
				else if (_curImgNum + 1 == 12)
				{
					sprintf_s(str, "oak_House", _curImgNum + 1);
					_sampleImgStr[_curImgNum] = str;
					return;
				}
				else if (_curImgNum + 1 == 13)
				{
					sprintf_s(str, "pokemon_Center", _curImgNum + 1);
					_sampleImgStr[_curImgNum] = str;
					return;
				}
				else if (_curImgNum + 1 == 14)
				{
					sprintf_s(str, "pokemon_Shop", _curImgNum + 1);
					_sampleImgStr[_curImgNum] = str;
					return;
				}
				else if (_curImgNum + 1 == 15)
				{
					sprintf_s(str, "pokemon_Gym", _curImgNum + 1);
					_sampleImgStr[_curImgNum] = str;
					return;
				}
				else if (_curImgNum + 1 == 16)
				{
					sprintf_s(str, "openTheDoor", _curImgNum + 1);
					_sampleImgStr[_curImgNum] = str;
					return;
				}
				else if (_curImgNum + 1 == 17)
				{
					sprintf_s(str, "healing_Pokemon", _curImgNum + 1);
					_sampleImgStr[_curImgNum] = str;
					return;
				}
				sprintf_s(str, "object_0%d", _curImgNum + 1);
				_sampleImgStr[_curImgNum] = str;
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown('L'))
	{
		if (!_isObj)
		{
			_curImgNum = 0;
			char str[128];
			sprintf_s(str, "object_0%d", _curImgNum + 1);
			_sampleImgStr[_curImgNum] = str;

			_isObj = true;
			
		}
		else
		{
			_curImgNum = 0;
			char str[128];
			sprintf_s(str, "tile_0%d", _curImgNum + 1);
			_sampleImgStr[_curImgNum] = str;

			_isObj = false;
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

		if (_isObj)
		{
			if (_curImgNum == 0 || _curImgNum == 2 || _curImgNum == 3 || _curImgNum == 4 ||
				_curImgNum == 6 )
			{
				if ((idxX >= 0 && idxX < SAMPLETILE) && (idxY >= 0 && idxY < SAMPLETILE))
				{
					_pickSampleTile.curX = idxX;
					_pickSampleTile.curY = idxY;
					_pickSampleTile.isObj = true;
				}
				else
					_isTileClick = false;
			}
			if (_curImgNum == 1)
			{
				if ((idxX != 4 && idxY != 1) && 
					(idxX >= 0 && idxX < SAMPLETILE) && (idxY >= 0 && idxY < SAMPLETILE))
				{
					_pickSampleTile.curX = idxX;
					_pickSampleTile.curY = idxY;
					_pickSampleTile.isObj = true;
				}
				else
					_isTileClick = false;
			}
			if (_curImgNum == 5)
			{
				if ((idxX != 2 && idxY != 1) &&
					(idxX >= 0 && idxX < SAMPLETILE) && (idxY >= 0 && idxY < SAMPLETILE))
				{
					_pickSampleTile.curX = idxX;
					_pickSampleTile.curY = idxY;
					_pickSampleTile.isObj = true;
				}
				else
					_isTileClick = false;
			}
			if (_curImgNum == 7)
			{
				if ((idxX >= 0 && idxX < SAMPLETILE - 2) && idxY == 0 ||
					(idxX != 2 && idxY != 5) ||
					(idxX >= 0 && idxX < SAMPLETILE) && (idxY >= 1 && idxY < SAMPLETILE))
				{
					_pickSampleTile.curX = idxX;
					_pickSampleTile.curY = idxY;
					_pickSampleTile.isObj = true;
				}
				else
					_isTileClick = false;
			}
			if (_curImgNum == 8)
			{
				if ((idxX >= 0 && idxX < SAMPLETILE) && (idxY == 0 || idxY == 1 || idxY == 2 || idxY == 4 || idxY == 5) ||
					(idxX >= 0 && idxX < SAMPLETILE - 1) && idxY == 3 ||
					(idxX >= 0 && idxX < SAMPLETILE && idxX != 4) && idxY == 1)
				{
					_pickSampleTile.curX = idxX;
					_pickSampleTile.curY = idxY;
					_pickSampleTile.isObj = true;
				}
				else
					_isTileClick = false;
			}
			if (_curImgNum == 9)
			{
				if (idxX == 0 && idxY == 0 ||
					(idxX >= 0 && idxX < 3) && (idxY >= 1 && idxY < SAMPLETILE - 1))
				{
					_pickSampleTile.curX = idxX;
					_pickSampleTile.curY = idxY;
					_pickSampleTile.isObj = true;
				}
				else
					_isTileClick = false;
			}
		}
	}
}

void objectTool::drawObject()
{
	if (KEYMANAGER->isOnceKeyDown(VK_SHIFT))
		_isShift = true;

	if (KEYMANAGER->isOnceKeyUp(VK_SHIFT))
		_isShift = false;



	if (KEYMANAGER->isOnceKeyDown(VK_CONTROL))
	{
		_isCtrl = true;
	}
	

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
					if (_isObj)
					{
						_vvTile[i][j]->objectImageName = _sampleImgStr[_curImgNum];

						_vvTile[i][j]->objectFrameX = _pickSampleTile.curX;
						_vvTile[i][j]->objectFrameY = _pickSampleTile.curY;
						_vvTile[i][j]->attr = setAttribute(_vvTile[i][j]->objectImageName, _vvTile[i][j]->objectFrameX, _vvTile[i][j]->objectFrameY);
					}
					//타일맵에 오브젝트 정보 추가
					else
					{
						_vvTile[i][j]->objectImageName = OBJECT_NAME1;
						_vvTile[i][j]->objectFrameX = _tempObjTile.curX;
						_vvTile[i][j]->objectFrameY = _tempObjTile.curY;
						_vvTile[i][j]->attr = setAttribute(_vvTile[i][j]->objectImageName, _vvTile[i][j]->objectFrameX, _vvTile[i][j]->objectFrameY);
					}
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
						_saveTile.objectImageName = _vvTile[i][j]->objectImageName;
						_saveTile.objectFrameX = _vvTile[i][j]->objectFrameX;
						_saveTile.objectFrameY = _vvTile[i][j]->objectFrameY;
						_saveTile.terrainImageName = _vvTile[i][j]->terrainImageName;
						_saveTile.terrainFrameX = _vvTile[i][j]->terrainFrameX;
						_saveTile.terrainFrameY = _vvTile[i][j]->terrainFrameY;
						if (_isObj)
						{
							_vvTile[i][j]->objectImageName = _sampleImgStr[_curImgNum];

							_vvTile[i][j]->objectFrameX = _pickSampleTile.curX;
							_vvTile[i][j]->objectFrameY = _pickSampleTile.curY;
							_vvTile[i][j]->attr = setAttribute(_vvTile[i][j]->objectImageName, _vvTile[i][j]->objectFrameX, _vvTile[i][j]->objectFrameY);
						}
						//타일맵에 오브젝트 정보 추가
						else
						{
							_vvTile[i][j]->objectImageName = OBJECT_NAME1;
							_vvTile[i][j]->objectFrameX = _tempObjTile.curX;
							_vvTile[i][j]->objectFrameY = _tempObjTile.curY;
							_vvTile[i][j]->attr = setAttribute(_vvTile[i][j]->objectImageName, _vvTile[i][j]->objectFrameX, _vvTile[i][j]->objectFrameY);
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
					if (_saveTile.terrainImageName == _vvTile[i][j]->terrainImageName && _saveTile.objectImageName == _vvTile[i][j]->objectImageName &&
						_saveTile.terrainFrameX == _vvTile[i][j]->terrainFrameX		  && _saveTile.terrainFrameY == _vvTile[i][j]->terrainFrameY &&
						_saveTile.objectFrameX == _vvTile[i][j]->objectFrameX		  && _saveTile.objectFrameY == _vvTile[i][j]->objectFrameY)
					{
						if (_isObj)
						{
							_vvTile[i][j]->objectImageName = _sampleImgStr[_curImgNum];

							_vvTile[i][j]->objectFrameX = _pickSampleTile.curX;
							_vvTile[i][j]->objectFrameY = _pickSampleTile.curY;
							_vvTile[i][j]->attr = setAttribute(_vvTile[i][j]->objectImageName, _vvTile[i][j]->objectFrameX, _vvTile[i][j]->objectFrameY);
						}
						//타일맵에 오브젝트 정보 추가
						else
						{
							_vvTile[i][j]->objectImageName = OBJECT_NAME1;
							_vvTile[i][j]->objectFrameX = _tempObjTile.curX;
							_vvTile[i][j]->objectFrameY = _tempObjTile.curY;
							_vvTile[i][j]->attr = setAttribute(_vvTile[i][j]->objectImageName, _vvTile[i][j]->objectFrameX, _vvTile[i][j]->objectFrameY);
						}
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
						if (_isObj)
						{
							_vvTile[i][j]->objectImageName = _sampleImgStr[_curImgNum];

							_vvTile[i][j]->objectFrameX = _pickSampleTile.curX;
							_vvTile[i][j]->objectFrameY = _pickSampleTile.curY;
							_vvTile[i][j]->attr = setAttribute(_vvTile[i][j]->objectImageName, _vvTile[i][j]->objectFrameX, _vvTile[i][j]->objectFrameY);
						}
						//타일맵에 오브젝트 정보 추가
						else
						{
							_vvTile[i][j]->objectImageName = OBJECT_NAME1;
							_vvTile[i][j]->objectFrameX = _tempObjTile.curX;
							_vvTile[i][j]->objectFrameY = _tempObjTile.curY;
							_vvTile[i][j]->attr = setAttribute(_vvTile[i][j]->objectImageName, _vvTile[i][j]->objectFrameX, _vvTile[i][j]->objectFrameY);
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
	if (imgName == OBJECT_NAME1)
	{
		if (frameX >= 0 && frameY < SAMPLETILE)
		{
			result |= ATTR_NONE;
			result |= ATTR_APPEAR;
		}
	}

	return result;
}
