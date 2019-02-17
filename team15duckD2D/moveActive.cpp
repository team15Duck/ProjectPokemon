#include "stdafx.h"
#include "moveActive.h"


moveActive::moveActive()
{
}


moveActive::~moveActive()
{
}

HRESULT moveActive::init(float * x, float * y, float minX, float minY, float maxX, float maxY, float speed)
{
	_x = x;
	_y = y;

	_minX = minX;
	_minY = minY;
	_maxX = maxX;
	_maxY = maxY;
	_speed = speed;

	return S_OK;
}

void moveActive::release()
{
}

void moveActive::update()
{
	if( _isMove )
		move();
}

void moveActive::startMove()
{
	_isMove = true;
}

void moveActive::endMove()
{
	_isMove = false;
}






fallDownMove::fallDownMove()
{
}

fallDownMove::~fallDownMove()
{
}

void fallDownMove::move()
{
	*_y += _speed * TIMEMANAGER->getElapsedTime();

	if ( _minY < *_y )
	{
		_isMove = false;
	}
}