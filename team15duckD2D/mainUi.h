#pragma once
#include "gameNode.h"
#include "baseUI.h"
#include "item.h"

class mainUi : public baseUI
{
private:



public:
	mainUi();
	~mainUi();

	HRESULT init();
	void release();
	void update();
	void render();

	//�Լ��Լ�  �׽�Ʈ������ �����۵��Ѿֵ鸸 �ø�����~
};

