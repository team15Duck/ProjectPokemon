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

	//함수함수  테스트씬에서 정상작동한애들만 올릴거임~
};

