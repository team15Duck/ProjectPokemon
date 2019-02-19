#include "stdafx.h"
#include "hpBar.h"


hpBar::hpBar()
{
}


hpBar::~hpBar()
{
}


HRESULT hpBar::init(string imgname, int framX, int framY, int x, int y, int width, int height, bool isbottomuse)
{
	_x = x;
	_y = y;

	_hpBar = { _x, _y, width, height };

	_maxwidht = width;
	_height = height;

	_isbottomuse = isbottomuse;
	return S_OK;
}

void hpBar::release()
{
}

void hpBar::update()
{
}

void hpBar::render()
{
}


void hpBar::setHPbar(float currentHP, float maxHP)
{
	_width = (currentHP / maxHP) * _maxwidht;
}
