#pragma once
#include "gameNode.h"

class endingScene : public gameNode
{
private:
	wstring _endingText = L"�÷��� ���ּż�\n  �����մϴ�.";
	

public:
	endingScene();
	~endingScene();

	HRESULT init();
	void release();
	void update();
	void render();

	
};

