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

//����̴� ���⿡ �ʲ� ���� �ۼ��ؼ� �ʲ����� ������Ʈ �������� �Ͽ���
void camera::moveMapTool()
{
}
