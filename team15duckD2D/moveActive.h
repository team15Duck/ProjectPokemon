#pragma once
class moveActive
{
protected:
	float* _x;
	float* _y;

	float _minX;
	float _minY;
	
	float _maxX;
	float _maxY;

	float _speed;

	bool _isMove;

public:
	moveActive();
	~moveActive();

	virtual HRESULT init(float* x, float* y, float minX, float minY, float maxX, float maxY, float speed);
	virtual void release();
	virtual void update();

	virtual void move() = 0;

	virtual void startMove();
	virtual void endMove();

	bool isMove() { return _isMove; }
};

class fallDownMove : public moveActive
{
private:

public:
	fallDownMove();
	~fallDownMove();

	void move();
};

