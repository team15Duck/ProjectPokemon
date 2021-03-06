#include "stdafx.h"
#include "mapTool.h"
//#include "objectTool.h"


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
	//이미지 설정은 플레이그라운드에 있어영
	_sampleImg[0] = IMAGEMANAGER->findImage	(TERRAIN_NAME[TERRAIN_NAME1 ]);
	_sampleImg[1] = IMAGEMANAGER->findImage	(TERRAIN_NAME[TERRAIN_NAME2 ]);
	_sampleImg[2] = IMAGEMANAGER->findImage	(TERRAIN_NAME[TERRAIN_NAME3 ]);
	_sampleImg[3] = IMAGEMANAGER->findImage	(TERRAIN_NAME[TERRAIN_NAME4 ]);
	_sampleImg[4] = IMAGEMANAGER->findImage	(TERRAIN_NAME[TERRAIN_NAME5 ]);
	_sampleImg[5] = IMAGEMANAGER->findImage	(TERRAIN_NAME[TERRAIN_NAME6 ]);
	_sampleImg[6] = IMAGEMANAGER->findImage	(TERRAIN_NAME[TERRAIN_NAME7 ]);
	_sampleImg[7] = IMAGEMANAGER->findImage	(TERRAIN_NAME[TERRAIN_NAME8 ]);
	_sampleImg[8] = IMAGEMANAGER->findImage	(TERRAIN_NAME[TERRAIN_NAME9 ]);
	_sampleImg[9] = IMAGEMANAGER->findImage	(TERRAIN_NAME[TERRAIN_NAME10]);
	_sampleImg[10] = IMAGEMANAGER->findImage(TERRAIN_NAME[TERRAIN_NAME11]);

	for (int i = 1; i < OBJ_IMG_NUM; ++i)
	{
		_tempImg[i] = nullptr;
	}
	_curImgNum = TERRAIN_NAME1;

	setSampleTile();
	
	_preButton = { WINSIZEX / 2 + 400, WINSIZEY / 2 + 50, WINSIZEX / 2 + 450, WINSIZEY / 2 + 80 };
	_nextButton = { WINSIZEX / 2 + 550, WINSIZEY / 2 + 50, WINSIZEX / 2 + 600, WINSIZEY / 2 + 80 };

	_sizeUpWidth = { _preButton.left + 135, _preButton.bottom + 50, _preButton.left + 165, _preButton.bottom + 90 };
	_sizeDownWidth = { _preButton.left + 35, _sizeUpWidth.top, _preButton.left + 65, _sizeUpWidth.bottom };
	_sizeUpHeight = { _preButton.left + 75, _preButton.bottom + 10, _preButton.left + 125, _preButton.bottom + 40 };
	_sizeDownHeight = { _preButton.left + 75, _sizeUpWidth.bottom + 10 ,  _preButton.left + 125 , _sizeUpWidth.bottom + 40 };

	_isTileClick = false;
	
	_isObj = false;
	_isRND = false;
	_turnObjCount = 0;

	_isShift = false;
	_savePointX = 0;
	_savePointY = 0;

	_isShowAttr = false;
	_showCount = 0;

	CAMERA->init(0, 0, 10000, 10000);
	
	_mapCase = MAP_TOWN;

	_isPotal = false;
	for (int i = 0; i < MAX_POTAL_NUM; ++i)
	{
		_potalPosX[i] = 0;
		_potalPosY[i] = 0;
	}
	_potalNum = 0;

	setTile();
	nameInit();

	return S_OK;
}

void mapTool::release()
{

}

void mapTool::update()
{
	CAMERA->mapToolMove();
	
	turnMap();
	pickSampleMap();
	drawMap();
	mapSizeChange();
	if (KEYMANAGER->isOnceKeyDown(VK_F8))
	{
		nextSaveName();
		setTile();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		save(_mapCase);
	}
	
	if (KEYMANAGER->isOnceKeyDown(VK_F3))
	{
		load();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_CONTROL))
	{
		_showCount++;
		if (_showCount % 2 == 1)
		{
			_isShowAttr = true;
		}
		else if (_showCount % 2 == 0)
		{
			_isShowAttr = false;
		}

	}


	_preButton = { CAMERA->getPosX() + WINSIZEX / 2 + 400, CAMERA->getPosY() + WINSIZEY / 2 + 50, CAMERA->getPosX() + WINSIZEX / 2 + 450, CAMERA->getPosY() + WINSIZEY / 2 + 80 };
	_nextButton = { CAMERA->getPosX() + WINSIZEX / 2 + 550, CAMERA->getPosY() + WINSIZEY / 2 + 50, CAMERA->getPosX() + WINSIZEX / 2 + 600, CAMERA->getPosY() + WINSIZEY / 2 + 80 };

	_sizeUpWidth = { _preButton.left + 135, _preButton.bottom + 50,  _preButton.left + 165, _preButton.bottom + 90 };
	_sizeDownWidth = { _preButton.left + 35, _sizeUpWidth.top,_preButton.left + 65, _sizeUpWidth.bottom };
	_sizeUpHeight = { _preButton.left + 75, _preButton.bottom + 10, _preButton.left + 125, _preButton.bottom + 40 };
	_sizeDownHeight = { _preButton.left + 75, _sizeUpWidth.bottom + 10 , _preButton.left + 125, _sizeUpWidth.bottom + 40 };

}

void mapTool::render()
{
	//이전,다음 버튼 렌더
	D2DMANAGER->drawRectangle(_preButton.left
							  , _preButton.top
							  , _preButton.right
							  , _preButton.bottom);
	D2DMANAGER->drawRectangle(_nextButton.left
							  , _nextButton.top
							  , _nextButton.right
							  , _nextButton.bottom);

	//맵 사이즈 버튼 렌더
	D2DMANAGER->drawRectangle(_sizeUpWidth.left
							  , _sizeUpWidth.top
							  , _sizeUpWidth.right
							  , _sizeUpWidth.bottom);
	D2DMANAGER->drawRectangle(_sizeDownWidth.left
							  , _sizeDownWidth.top
							  , _sizeDownWidth.right
							  , _sizeDownWidth.bottom);
	D2DMANAGER->drawRectangle(_sizeUpHeight.left
							  , _sizeUpHeight.top
							  , _sizeUpHeight.right
							  , _sizeUpHeight.bottom);

	D2DMANAGER->drawRectangle(_sizeDownHeight.left
							  , _sizeDownHeight.top
							  , _sizeDownHeight.right
							  , _sizeDownHeight.bottom);

	//샘플 RECT 렌더
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
	//맵 렌더는 항상 먼저 출력이 되어야합니다.
	
	
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			if (_vvRect[i][j].left - (CAMERA->getPosX() - 50) < 0)
				continue;
			if (_vvRect[i][j].right - CAMERA->getPosX() > CAMERA_SHOW_RANGE)
				continue;
			
			D2DMANAGER->drawRectangle(_vvRect[i][j].left, _vvRect[i][j].top, _vvRect[i][j].right, _vvRect[i][j].bottom);
			
			if (_vvTile[i][j]->terrainImageIndex == TERRAIN_NAME_NONE) 
				continue;
			IMAGEMANAGER->findImage(TERRAIN_NAME[_vvTile[i][j]->terrainImageIndex])->frameRender(_vvRect[i][j].left, _vvRect[i][j].top, _vvTile[i][j]->terrainFrameX, _vvTile[i][j]->terrainFrameY);
			
		
		}
	}
	
	IMAGEMANAGER->findImage(TERRAIN_NAME[_curImgNum])->render(CAMERA->getPosX() + (WINSIZEX - SAMPLE_TOTAL_SIZE), CAMERA->getPosY() + 30);
	
	if (_isTileClick)
	{
		IMAGEMANAGER->findImage(TERRAIN_NAME[_curImgNum])->frameRender(_ptMouse.x, _ptMouse.y, _pickSampleTile.curX, _pickSampleTile.curY, 0.5f);
	}

	if (_isShift)
	{
		if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
		{
			D2D1_RECT_F dragRc = { _savePointX * TILE_SIZE + 5, _savePointY * TILE_SIZE + 5, _ptMouse.x, _ptMouse.y };
			D2DMANAGER->drawRectangle(RGB(135, 12, 255), dragRc);
		}
	}
	
	
	//===================================확인용 텍스트========================================
	WCHAR str[128];
	swprintf_s(str, L"TILEX : %d, TILEY : %d", TILEX, TILEY);
	D2DMANAGER->drawText(str, CAMERA->getPosX(), CAMERA->getPosY() + 200);

	swprintf_s(str, L"mapcase : %d", _mapCase);
	D2DMANAGER->drawText(str, CAMERA->getPosX(), CAMERA->getPosY() + 250);
	swprintf_s(str, L"_curImgNum : %d", _curImgNum);
	D2DMANAGER->drawText(str, CAMERA->getPosX(), CAMERA->getPosY() + 280);
	
	swprintf_s(str, L"_potalPosX : %d\n _potalPosY : %d", _potalPosX[_potalNum], _potalPosY[_potalNum]);
	D2DMANAGER->drawText(str, CAMERA->getPosX(), CAMERA->getPosY() + 310);
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			if (KEYMANAGER->isToggleKey(VK_CONTROL))
			{
				WCHAR str[128];
				if ((_vvTile[i][j]->attr & ATTR_UNMOVE) == ATTR_UNMOVE)
				{
					swprintf_s(str, L"UnMove");
					D2DMANAGER->drawText(str, j *TILE_SIZE + 5, i * TILE_SIZE + 5, 20, RGB(255, 0, 255));
				}
				if ((_vvTile[i][j]->attr & ATTR_POTAL) == ATTR_POTAL)
				{
					swprintf_s(str, L"POTAL");
					D2DMANAGER->drawText(str, j *TILE_SIZE + 5, i * TILE_SIZE + 5, 20, RGB(0, 0, 255));
				}
				if ((_vvTile[i][j]->attr & ATTR_APPEAR) == ATTR_APPEAR)
				{
					swprintf_s(str, L"APPEAR");
					D2DMANAGER->drawText(str, j *TILE_SIZE + 5, i * TILE_SIZE + 5, 20, RGB(0, 255, 255));
				}
				if ((_vvTile[i][j]->attr & ATTR_FOOT_PRINT) == ATTR_FOOT_PRINT)
				{
					swprintf_s(str, L"FOOT_PRINT");
					D2DMANAGER->drawText(str, j *TILE_SIZE + 5, i * TILE_SIZE + 5, 20, RGB(0, 0, 255));
				}
			}
		}
	}
}

void mapTool::setSampleTile()
{
	//샘플타일의 배치
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
}

void mapTool::setTile()
{
	//맵
	TILEX = 80;
	TILEY = 50;
	for (int i = 0; i < TILEY; ++i)
	{
		vector<tagTile*> vTile;
		vector<D2D1_RECT_F> vRect;
		for (int j = 0; j < TILEX; ++j)
		{
			tagTile* tempTile = new tagTile;
			D2D1_RECT_F tempRect = { (float)j * TILE_SIZE, (float)i * TILE_SIZE, (float)(j + 1) * TILE_SIZE, (float)(i + 1) * TILE_SIZE };

			tempTile->terrainFrameX = 0;
			tempTile->terrainFrameY = 0;

			tempTile->objectFrameX = 0;
			tempTile->objectFrameY = 0;

			tempTile->attr |= ATTR_NONE;

			tempTile->terrainImageIndex = TERRAIN_NAME_NONE;
			tempTile->objectImageIndex = OBJECT_NAME_NONE;

			vTile.push_back(tempTile);
			vRect.push_back(tempRect);
		}
		_vvTile.push_back(vTile);
		_vvRect.push_back(vRect);
	}
}

void mapTool::turnMap()
{
	POINT tempPTPre = { _ptMouse.x, _ptMouse.y };

	if (PtInRect(&makeRECT(_preButton), tempPTPre))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			if (!_isObj)
			{
				--_curImgNum;
				if (_curImgNum < TERRAIN_NAME1)
					_curImgNum = TERRAIN_NAME11;
			}
			else
			{
				--_curImgNum;
				if (_curImgNum < OBJECT_NAME1)
				{
					_curImgNum = OBJECT_NAME17;
				}

			}
		}
	}

	POINT tempPTNext = { _ptMouse.x, _ptMouse.y };

	if (PtInRect(&makeRECT(_nextButton), tempPTNext))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			if (!_isObj)
			{
				++_curImgNum;
				if (_curImgNum > TERRAIN_NAME11)
					_curImgNum = TERRAIN_NAME1;
			}
		}
	}

}

void mapTool::pickSampleMap()
{
	if (_ptMouse.x - CAMERA->getPosX() < SAMPLETILE_STARTX)
		return;

	int indX = (_ptMouse.x -CAMERA->getPosX() - SAMPLETILE_STARTX) / TILE_SIZE;
	int indY = (_ptMouse.y -CAMERA->getPosY() - 30) / TILE_SIZE;

	if (indX >= SAMPLETILE || indX < 0)
		return;
	if (indY >= SAMPLETILE || indY < 0)
		return;


	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_isTileClick = true;
		if (_curImgNum == TERRAIN_NAME1 || _curImgNum == TERRAIN_NAME2 || _curImgNum == TERRAIN_NAME3 || _curImgNum == TERRAIN_NAME4)
		{
			if (_curImgNum == TERRAIN_NAME2)
			{
				_isRND = false;
				if (((indX >= 0 && indX < SAMPLETILE - 1) && (indY == 0 || indY == 3))
					|| ((indX >= 0 && indX < SAMPLETILE - 2) && (indY == 1 || indY == 2 || indY == 4 || indY == 5)))
				{
					if ((indX >= 0 && indX < 4) && indY == 5)
						_isRND = true;
					else
						_isRND = false;
					_pickSampleTile.curX = indX;
					_pickSampleTile.curY = indY;
					_pickSampleTile.isObj = false;
				}
				else
					_isTileClick = false;
			}
			if (_curImgNum == TERRAIN_NAME3)
			{
				_isRND = false;
				if (((indX >= 0 && indX < SAMPLETILE) && (indY == 0 || indY == 1)) ||
					((indX >= 0 && indX < SAMPLETILE - 2) && (indY == 2 || indY == 4 || indY == 5)) ||
					(indX >= 0 && indY == 3))
				{
					_pickSampleTile.curX = indX;
					_pickSampleTile.curY = indY;
					_pickSampleTile.isObj = false;
				}
				else _isTileClick = false;
			}
			else
			{
				_isRND = false;
				if (((indX >= 0 && indX < SAMPLETILE - 1) && (indY == 0 || indY == 3))
				|| ((indX >= 0 && indX < SAMPLETILE - 2) && (indY == 1 || indY == 2 || indY == 4 || indY == 5)))
				{
					_pickSampleTile.curX = indX;
					_pickSampleTile.curY = indY;
					_pickSampleTile.isObj = false;
				}
				else
					_isTileClick = false;
			}
			
		}
		//동굴
		if (_curImgNum == TERRAIN_NAME5)
		{
			if (((indX >= 0 && indX < SAMPLETILE - 1) && (indY == 0 || indY == 1 ||indY == 3 || indY == 4)) ||
				((indX >= 0 && indX < SAMPLETILE - 2) && indY == 2) ||
				((indX >= 0 && indX < SAMPLETILE )&& indY == 5))
			{
				_pickSampleTile.curX = indX;
				_pickSampleTile.curY = indY;
				_pickSampleTile.isObj = false;
			}
			else
				_isTileClick = false;
		}
		//물
		if (_curImgNum == TERRAIN_NAME6)
		{
			if (((indX >= 0 && indX < SAMPLETILE) && (indY >= 0 && indY <= 2)) ||
				((indX >= 0 && indX < 3) && (indY > 2 && indY < SAMPLETILE)))
			{
				_pickSampleTile.curX = indX;
				_pickSampleTile.curY = indY;
				_pickSampleTile.isObj = false;
			}
			else
				_isTileClick = false;
		}
		//집, 오박사
		if (_curImgNum == TERRAIN_NAME7)
		{
			if (((indX >= 0 && indX < SAMPLETILE - 1) && indY == 0) ||
				((indX >= 0 && indX < SAMPLETILE) && indY == 1) ||
				((indX >= 0  && indX <SAMPLETILE) && (indY == 2 ||indY == 3)) ||
				((indX >= 3 && indX <SAMPLETILE) && indY == 4))
			{
				_pickSampleTile.curX = indX;
				_pickSampleTile.curY = indY;
				_pickSampleTile.isObj = false;
			}
			else
				_isTileClick = false;
		}
		//포켓몬센터
		if (_curImgNum == TERRAIN_NAME8)
		{
			if (((indX >= 0 && indX < SAMPLETILE) && (indY >= 0 && indY < 3)) ||
				((indX >= 0 && indX < SAMPLETILE - 1) && indY == 3) ||
				((indX >= 0 && indX < SAMPLETILE - 1) && indY == 4) ||
				((indX >= 0 && indX <SAMPLETILE -2 ) && indY == 5))
			{
				_pickSampleTile.curX = indX;
				_pickSampleTile.curY = indY;
				_pickSampleTile.isObj = false;
			}
			else
				_isTileClick = false;
		}
		//상점
		if (_curImgNum == TERRAIN_NAME9)
		{
			if (((indX >= 0 && indX < 3) && (indY == 0 || indY == 1)) ||
				((indX >= 0 && indX < SAMPLETILE - 2) && (indY >= 2 && indY < SAMPLETILE)))
			{
				_pickSampleTile.curX = indX;
				_pickSampleTile.curY = indY;
				_pickSampleTile.isObj = false;
			}
			else
				_isTileClick = false;
		}
		//체육관(웅)
		if (_curImgNum == TERRAIN_NAME10)
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
		//체육관(웅) 2번째 이미지
		if (_curImgNum == TERRAIN_NAME11)
		{
			if ((indX >= 0 && indX < 4) && (indY == 0 || indY == 1))
			{
				_pickSampleTile.curX = indX;
				_pickSampleTile.curY = indY;
				_pickSampleTile.isObj = false;
			}
			else
				_isTileClick = false;
		}
	}

	
	if (_isRND)
	{
		_pickSampleTile.curX = RND->getInt(4);
	}
}

void mapTool::mapSizeChange()
{
	POINT tempPT = { _ptMouse.x, _ptMouse.y };
	
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && TILEX > 1)
	{
		//가로 사이즈 줄이는 버튼 눌렀을때
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
		//가로 사이즈 늘리는 버튼 눌렀을 때
		if (PtInRect(&makeRECT(_sizeUpWidth), tempPT))
		{
			for (int i = 0; i < TILEY; ++i)
			{
				tagTile* tempTile = new tagTile;
				D2D1_RECT_F tempRect = { (float)_vvRect[i].back().right
									  , (float)_vvRect[i].back().top
									  , (float)_vvRect[i].back().right + TILE_SIZE
									  , (float)_vvRect[i].back().bottom };

				tempTile->terrainFrameX = 0;
				tempTile->terrainFrameY = 0;

				tempTile->objectFrameX = 0;
				tempTile->objectFrameY = 0;

				tempTile->attr |= ATTR_NONE;

				tempTile->terrainImageIndex = TERRAIN_NAME_NONE;
				tempTile->objectImageIndex = OBJECT_NAME_NONE;
							
				_vvTile[i].push_back(tempTile);
				_vvRect[i].push_back(tempRect);
			}
			++TILEX;
		}

		//todo
		//세로 사이즈 줄이는 버튼 눌렀을 때
		if (PtInRect(&makeRECT(_sizeDownHeight), tempPT))
		{
			for (int i = 0; i < TILEX; ++i)
			{
				delete _vvTile.back()[i];		//데이터를 메모리에서 삭제함
				_vvTile.back()[i] = nullptr;	//포인터의 주소를 없앰
			}
			_vvTile.pop_back();
			TILEY--;
		}
		//세로 사이즈 늘리는 버튼 눌렀을 때
		if (PtInRect(&makeRECT(_sizeUpHeight), tempPT))
		{
			vector<tagTile*> vTile;
			vector<D2D1_RECT_F> vRect;
			for (int i = 0; i < TILEX; ++i)
			{
				tagTile* tempTile = new tagTile;
				D2D1_RECT_F tempRect = { (float)_vvRect.back()[i].right
									   , (float)_vvRect.back()[i].top
									   , (float)_vvRect.back()[i].right + TILE_SIZE
									   , (float)_vvRect.back()[i].bottom };

				tempTile->terrainFrameX = 0;
				tempTile->terrainFrameY = 0;

				tempTile->objectFrameX = 0;
				tempTile->objectFrameY = 0;

				tempTile->attr |= ATTR_NONE;
				tempTile->terrainImageIndex = TERRAIN_NAME_NONE;
				tempTile->objectImageIndex = OBJECT_NAME_NONE;
			
				vTile.push_back(tempTile);
				vRect.push_back(tempRect);
			}
			_vvTile.push_back(vTile);
			_vvRect.push_back(vRect);
			TILEY++;
		}
	}
}

void mapTool::drawMap()
{
	//if (포탈찍는중)
	//{
	//	string scenName = 현재 선택중인 씬네임;
	//
	//	int idxX;
	//	int idxY;
	//
	//	idx = idxX + idxY * TILEX;
	//
	//	_potalMap.insert(make_pair(idx, sceneName));
	//	
	//}
	//
	//if (포탈 지우기 선택중)
	//{
	//	int idxX;
	//	int idxY;
	//
	//	idx = idxX + idxY * TILEX;
	//
	//	_potalMap.erase(idx);
	//}


	if (_potalNum == MAX_POTAL_NUM)
		return;
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		//포탈좌표를 계산해서 저장함.
		_potalPosX[_potalNum] = (_ptMouse.x) / TILE_SIZE;
		_potalPosY[_potalNum] = (_ptMouse.y) / TILE_SIZE;
		for (int i = 0; i < TILEY; ++i)
		{
			for (int j = 0; j < TILEX; ++j)
			{
				if (i == _potalPosY[_potalNum] && j == _potalPosX[_potalNum])
				{
					_vvTile[i][j]->attr |= ATTR_POTAL;
				}
			}
		}
		_potalNum++;
	}

	if (_isRND)
	{
		_pickSampleTile.curX = RND->getInt(4);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SHIFT))
		_isShift = true;

	if (KEYMANAGER->isOnceKeyUp(VK_SHIFT))
		_isShift = false;

	if (_ptMouse.x - CAMERA->getPosX() > SAMPLETILE_STARTX) return;
	if (_ptMouse.x > _vvRect[0][TILEX - 1].right) return;
	if (_ptMouse.x < _vvRect[0][0].left) return;
	if (_ptMouse.y > _vvRect[TILEY - 1][0].bottom) return;
	if (_ptMouse.y < _vvRect[0][0].top) return;

	if (_isShift)
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
					if (!_isObj)
					{
						_vvTile[i][j]->terrainImageIndex = _curImgNum;
						_vvTile[i][j]->terrainFrameX = _pickSampleTile.curX;
						_vvTile[i][j]->terrainFrameY = _pickSampleTile.curY;
						_vvTile[i][j]->attr = setAttribute(TERRAIN_NAME[_vvTile[i][j]->terrainImageIndex], _vvTile[i][j]->terrainFrameX, _vvTile[i][j]->terrainFrameY);
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

						_vvTile[i][j]->terrainImageIndex = _curImgNum;
						_vvTile[i][j]->terrainFrameX = _pickSampleTile.curX;
						_vvTile[i][j]->terrainFrameY = _pickSampleTile.curY;
						_vvTile[i][j]->attr = setAttribute(TERRAIN_NAME[_vvTile[i][j]->terrainImageIndex], _vvTile[i][j]->terrainFrameX, _vvTile[i][j]->terrainFrameY);
					}
				}
			}
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < TILEY; ++i)
		{
			for (int j = 0; j < TILEX; ++j)
			{
				if (PtInRect(&makeRECT(_vvRect[i][j]), makePOINT(_ptMouse)))
				{
					if (!_isObj)
					{
						_vvTile[i][j]->terrainImageIndex = _curImgNum;
						_vvTile[i][j]->terrainFrameX = _pickSampleTile.curX;
						_vvTile[i][j]->terrainFrameY = _pickSampleTile.curY;
						_vvTile[i][j]->attr = setAttribute(TERRAIN_NAME[_vvTile[i][j]->terrainImageIndex], _vvTile[i][j]->terrainFrameX, _vvTile[i][j]->terrainFrameY);
					}
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


}

void mapTool::save(int mapCase)
{
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

				//마을맵의 포탈 정보 입력
				if (mapCase ==  1)		//마을의 포탈
				{
					//필드로 가는 포탈
					_vvTile[8][7]->attr |= ATTR_POTAL;
					_vvTile[9][7]->attr |= ATTR_POTAL;
					_vvTile[10][7]->attr |= ATTR_POTAL;

					//집으로 가는 포탈
					_vvTile[15][23]->attr |= ATTR_POTAL;

					//오박사 실험실 포탈
					_vvTile[16][36]->attr |= ATTR_POTAL;

					//상점으로 이동하는 포탈
					_vvTile[26][38]->attr |= ATTR_POTAL;

					//센터로 이동하는 포탈
					_vvTile[26][33]->attr |= ATTR_POTAL;

					//체육관으로 이동하는 포탈
					_vvTile[26][26]->attr |= ATTR_POTAL;

				}
				//플레이어 집의 포탈 정보 입력
				if (mapCase == 2)
				{
					//마을로 이동하는 포탈
					_vvTile[15][15]->attr |= ATTR_POTAL;
				}
				//오박사 연구소의 포탈정보 입력
				if (mapCase == 3)
				{
					//마을로 이동하는 포탈
					_vvTile[21][16]->attr |= ATTR_POTAL;
				}
				//상점의 포탈정보 입력
				if (mapCase == 4)
				{
					//마을로 이동하는 포탈
					_vvTile[14][14]->attr |= ATTR_POTAL;
				}
				//포켓몬센터의 포탈정보 입력
				if (mapCase == 5)
				{
					//마을로 이동하는 포탈 
					_vvTile[15][17]->attr |= ATTR_POTAL;
				}
				//체육관의 포탈정보 입력
				if (mapCase == 6)
				{
					//마을로 이동하는 포탈
					_vvTile[21][16]->attr |= ATTR_POTAL;
				}
				//필드의 포탈정보 입력
				if (mapCase == 7)
				{
					//마을로 이동하는 포탈
					_vvTile[42][47]->attr |= ATTR_POTAL;
					_vvTile[42][48]->attr |= ATTR_POTAL;
					_vvTile[42][49]->attr |= ATTR_POTAL;
					_vvTile[42][50]->attr |= ATTR_POTAL;
					//동굴로 이동하는 포탈
					_vvTile[15][52]->attr |= ATTR_POTAL;
				}
				//동굴의 포탈정보 입력
				if (mapCase == 8)
				{
					//필드로 가는 포탈
					_vvTile[40][31]->attr |= ATTR_POTAL;
				}
			}
		}

		HANDLE file2;
		DWORD write2;
		file2 = CreateFile(_mDataNames[(MAP_NAME)mapCase].c_str(), GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

		WriteFile(file2, tile, sizeof(tagTile) * TILEX * TILEY, &write, NULL);

		CloseHandle(file2);

		delete[] tile;
	}
}

void mapTool::load()
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
	
	//delete[] tile;
}

void mapTool::nextSaveName()
{
	_mapCase = 1 + _mapCase;
	for (int i = 0; i < TILEY; ++i)
	{
		delete _vvTile.back()[i];

	}
	if (_mapCase == MAP_COUNT)
		_mapCase = 1;
}

void mapTool::nameInit()
{
	//테스트용 맵
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

DWORD mapTool::setAttribute(string imgName, UINT frameX, UINT frameY)
{
	DWORD result = ATTR_NONE;
	//타일
	if (imgName == TERRAIN_NAME[TERRAIN_NAME3])
	{
		if ((frameX == 5 && frameY == 0) ||
			((frameX == 4 || frameX == 5) && frameY == 1))
		{
			result |= ATTR_UNMOVE;
		}
	}
	//동굴은 어딜가든 다 만남
	if (imgName == TERRAIN_NAME[TERRAIN_NAME5])
	{
		if(((frameX >= 0 && frameX < SAMPLETILE - 1) && (frameY == 0 || frameY == 1 || frameY == 3 || frameY == 4)) ||
			((frameX >= 0 && frameX < SAMPLETILE - 2) && frameY == 2) ||
		 ((frameX >= 0 && frameX < SAMPLETILE) && frameY == 5))
		{
			result |= ATTR_APPEAR;		//몬스터 출몰 속성
			if (frameX == 1 && frameY == 5)
			{
				result |= ATTR_FOOT_PRINT;
			}
		}
	}
	//물
	if (imgName == TERRAIN_NAME[TERRAIN_NAME6])
	{
		if (((frameX == 0 || frameX == 1) && (frameY == 3)) || 
			((frameX >= 3 && frameX < SAMPLETILE) && (frameY == 0 || frameY == 1)))
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_WATER;		//프레임을 돌려야 해서 있어야 함
		}
	}
	//집, 오박사
	if (imgName == TERRAIN_NAME[TERRAIN_NAME7])
	{
		if (((frameX == 2 || frameX == 3||frameX == 4) && frameY == 0) ||
			(frameX == 5 && frameY == 1))
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_WALL;		//이건 속성을 빼도 될것 같은 UNMOVE랑 WALL의 차이가 딱히 없어보임
		}
		else if ((frameX >= 0 && frameX < 3) && frameY == 2)
		{
			result |= ATTR_UNMOVE;
		}
	}
	//포켓몬 센터
	if (imgName == TERRAIN_NAME[TERRAIN_NAME8])
	{
		if (((frameX >= 0 && frameX < SAMPLETILE - 2) && (frameY == 0 || frameY == 1)) ||
			(frameX == 4 && frameY == 3))
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_WALL;
		}
	}
	//상점
	if (imgName == TERRAIN_NAME[TERRAIN_NAME9])
	{
		if (((frameX >= 0 && frameX < 3) && (frameY >= 0 && frameY < 2)) ||
			(frameX == 3 && frameY == 2))
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_WALL;
		}
	}
	//체육관
	if (imgName == TERRAIN_NAME[TERRAIN_NAME10])
	{
		if (((frameX >= 0 && frameX < SAMPLETILE) && (frameY == 0 || frameY == 1)) ||
				((frameX == 0 || frameX == 4 || frameX == 5) && (frameY >= 2 && frameY <= 4)) ||
				 (frameX == 5 && frameY == 5))
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_WALL;
		}
	}
	//체육관 두번째 이미지
	if (imgName == TERRAIN_NAME[TERRAIN_NAME11])
	{
		if ((frameX == 0 || frameX == 1) && frameY == 0)
		{
			result |= ATTR_UNMOVE;
			result |= ATTR_WALL;
		}
	}

	return result;
}
