#include "stdafx.h"
#include "mapTool.h"


mapTool::mapTool()
{
}


mapTool::~mapTool()
{
}

HRESULT mapTool::init()
{
	IMAGEMANAGER->addImage(TERRAIN_NAME1, L"image/tile/tile_01.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE);
	IMAGEMANAGER->addImage(TERRAIN_NAME2, L"image/tile/tile_02.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE);
	IMAGEMANAGER->addImage(TERRAIN_NAME3, L"image/tile/tile_03.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE);
	IMAGEMANAGER->addImage(TERRAIN_NAME4, L"image/tile/tile_04.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE);
	IMAGEMANAGER->addImage(TERRAIN_NAME5, L"image/tile/tile_05.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE);
	IMAGEMANAGER->addImage(TERRAIN_NAME6, L"image/tile/tile_06.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE);
	IMAGEMANAGER->addImage(TERRAIN_NAME7, L"image/tile/tile_07.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE);
	IMAGEMANAGER->addImage(TERRAIN_NAME8, L"image/tile/tile_08.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE);
	IMAGEMANAGER->addImage(TERRAIN_NAME9, L"image/tile/tile_09.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE);
	IMAGEMANAGER->addImage(TERRAIN_NAME10, L"image/tile/tile_10.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE);

	_preButton = { WINSIZEX / 2 + 100, WINSIZEY/2 + 150, WINSIZEX / 2 + 150,WINSIZEY / 2 + 180  };
	_nextButton = { WINSIZEX / 2 + 250, WINSIZEY/2 + 150, WINSIZEX / 2 + 300,WINSIZEY / 2 + 180  };
	_currentSampleImgNumber = 0;
	

	_currentSample->clear();
	
	_currentSample[0] = TERRAIN_NAME1;

	return S_OK;
}

void mapTool::release()
{
}

void mapTool::update()
{	
	const RECT tempPre = { _preButton.left, _preButton.top, _preButton.right, _preButton.bottom };
	POINT tempPTPre = { _ptMouse.x, _ptMouse.y };

	if (PtInRect(&tempPre, tempPTPre))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			--_currentSampleImgNumber;
			if (_currentSampleImgNumber < 0) 
				_currentSampleImgNumber = TILE_IMAGE_NUM - 1;
			char str[128];
			if (_currentSampleImgNumber + 1 == 10)
			{
				sprintf_s(str, "tile_%d", _currentSampleImgNumber + 1);
				_currentSample[_currentSampleImgNumber] = str;
				return;
			}
			sprintf_s(str, "tile_0%d", _currentSampleImgNumber + 1);
			_currentSample[_currentSampleImgNumber] = str;
		}
	}

	const RECT tempNext = { _nextButton.left, _nextButton.top, _nextButton.right, _nextButton.bottom };
	POINT tempPTNext = { _ptMouse.x, _ptMouse.y };

	if (PtInRect(&tempNext, tempPTNext))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			++_currentSampleImgNumber;
			if (_currentSampleImgNumber >= TILE_IMAGE_NUM)
				_currentSampleImgNumber = 0;
			char str[128];
			if (_currentSampleImgNumber + 1 == 10)
			{
				sprintf_s(str, "tile_%d", _currentSampleImgNumber + 1);
				_currentSample[_currentSampleImgNumber] = str;
				return;
			}
			sprintf_s(str, "tile_0%d", _currentSampleImgNumber + 1);
			_currentSample[_currentSampleImgNumber] = str;
		}
	}
}

void mapTool::render()
{
	IMAGEMANAGER->findImage(_currentSample[_currentSampleImgNumber])->render(CAMERA->getPosX() + (WINSIZEX - SAMPLE_TOTAL_SIZE), 30);

	D2DMANAGER->drawRectangle(_preButton);
	D2DMANAGER->drawRectangle(_nextButton);

}
