#include "stdafx.h"
#include "camera.h"


camera::camera()
{
}


camera::~camera()
{
}

HRESULT camera::init()
{
	_posX = _posY = 0;
	_maxX = 0;
	_maxY = 0;
	return S_OK;
}

HRESULT camera::init(float x, float y, int mX, int mY)
{
	_posX = x;
	_posY = y;
	_maxX = mX;
	_maxY = mY;
	return S_OK;
}

void camera::release()
{
}

void camera::update()
{
	move();
}

void camera::render()
{
}

void camera::move()
{
	
}

//재원이는 여기에 너꺼 무브 작성해서 너꺼에서 업데이트 돌리도록 하여라
void camera::moveMapTool()
{
}
