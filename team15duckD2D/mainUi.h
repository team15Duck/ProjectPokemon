#pragma once
#include "gameNode.h"
#include "item.h"

class mainUi : public gameNode
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

