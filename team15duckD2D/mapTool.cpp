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
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME1, L"image/tile/tile_01.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME2, L"image/tile/tile_02.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME3, L"image/tile/tile_03.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME4, L"image/tile/tile_04.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME5, L"image/tile/tile_05.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME6, L"image/tile/tile_06.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME7, L"image/tile/tile_07.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME8, L"image/tile/tile_08.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME9, L"image/tile/tile_09.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME10, L"image/tile/tile_10.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);

	_preButton = { WINSIZEX / 2 + 100, WINSIZEY/2 + 150, WINSIZEX / 2 + 150,WINSIZEY / 2 + 180  };
	_nextButton = { WINSIZEX / 2 + 250, WINSIZEY/2 + 150, WINSIZEX / 2 + 300,WINSIZEY / 2 + 180  };


	return S_OK;
}

void mapTool::release()
{
}

void mapTool::update()
{
	

}

void mapTool::render()
{
	IMAGEMANAGER->findImage(TERRAIN_NAME1)->render(CAMERA->getPosX() + (WINSIZEX - SAMPLE_TOTAL_SIZE), 30);
	D2DMANAGER->drawRectangle(_preButton);
	D2DMANAGER->drawRectangle(_nextButton);

}
