#pragma once
#include "gameNode.h"

class hpBar : public gameNode
{
private:
	
	D2D1_RECT_F _hpBar;

	float _x;			//��ǥ
	float _y;			//ũ��
	float _width;		//����ũ��
	float _maxwidht;	//�ִ밡��ũ��
	float _height;		//����ũ��

	string _imgName;
	bool _isbottomuse;
public:
	hpBar();
	~hpBar();

	HRESULT init(string imgname, int framX, int framY, int x, int y, int width, int height, bool isbottomuse);
	void release();
	void update();
	void render();

	void setHPbar(float currentHP, float maxHP);

	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }
};

