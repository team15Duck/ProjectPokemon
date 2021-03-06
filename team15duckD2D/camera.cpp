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
	
}

void camera::render()
{
}

void camera::move(float x, float y)
{
	_posX = x - 480.0f;
	_posY = y - 320.0f;
}

void camera::mapToolMove()
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && _posX < _maxX)
	{
		_posX += (CAMERA_SPEED);
		if (_posX + WINSIZEX > _maxX)
			_posX = _maxX - WINSIZEX;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && _posX > 0)
	{
		_posX -= CAMERA_SPEED;
		if (_posX < 0)
			_posX = 0;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _posY + WINSIZEY < _maxY )
	{
		_posY += CAMERA_SPEED;
		if (_posY + WINSIZEY > _maxY)
			_posY = _maxY - WINSIZEY;
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP) && _posY > 0)
	{
		_posY -= CAMERA_SPEED;
		if (_posY < 0)
			_posY = 0;
	}

}
