#pragma once
#include "gameNode.h"

class endingScene : public gameNode
{
private:
	wstring _endingText = L"플레이 해주셔서\n  감사합니다.";
	

public:
	endingScene();
	~endingScene();

	HRESULT init();
	void release();
	void update();
	void render();

	
};

