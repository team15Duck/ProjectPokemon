#include "stdafx.h"
#include "moveActive.h"


moveActive::moveActive()
{
}


moveActive::~moveActive()
{
}

HRESULT moveActive::init(float * x, float * y, float minX, float minY, float maxX, float maxY, float speed, bool isLoop)
{
	_x = x;
	_y = y;

	_minX = minX;
	_minY = minY;
	_maxX = maxX;
	_maxY = maxY;
	_speed = speed;
	_isLoop = isLoop;

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



void waveXMove::move()
{

	if ( _isRight )
	{
		*_x += _speed * TIMEMANAGER->getElapsedTime();
		if ( _maxX < *_x )
		{
			if( _isLoop )
				_isRight = false;
			else
				_isMove = false;
		}
	}
	else
	{
		*_x -= _speed * TIMEMANAGER->getElapsedTime();
		if ( *_x  < _minX)
		{
			if( _isLoop )
				_isRight = true;
			else
				_isMove = false;
		}
	}
}



void waveYMove::move()
{
	if ( _isDown )
	{
		*_y += _speed * TIMEMANAGER->getElapsedTime();
		if ( _maxY < *_y )
		{
			if( _isLoop )
				_isDown = false;
			else
				_isMove = false;
		}
	}
	else
	{
		*_y -= _speed * TIMEMANAGER->getElapsedTime();
		if ( *_y  < _minY)
		{
			if( _isLoop)
				_isDown = true;
			else
				_isMove = false;
		}
	}
}
