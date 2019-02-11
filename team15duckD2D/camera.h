#pragma once
#include "singletonBase.h"

#define CAMERA_SPEED 10.0f

class camera : public singletonBase<camera>
{
private:
	float _posX;
	float _posY;
	int _maxX;
	int _maxY;
public:
	camera();
	~camera();

	HRESULT init();
	HRESULT init(float x, float y, int mX, int mY);
	void release();
	void update();
	void render();
	void move();
	void mapToolMove();

	float getPosX()			{ return _posX; }
	float getPosY()			{ return _posY; }
	void setPosX(float x)	{ _posX = x; }
	void setPosY(float y)	{ _posX = y; }

	float getMaxX()			{ return _maxX; }
	float getMaxY()			{ return _maxY; }
	void setMaxX(int x)		{ _maxX = x; }
	void setMaxY(int y)		{ _maxY = y; }
};

