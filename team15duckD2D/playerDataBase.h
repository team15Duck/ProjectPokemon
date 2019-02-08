#pragma once
#include "singletonBase.h"

class playerDataBase : public singletonBase<playerDataBase>
{
private:

public:
	playerDataBase();
	~playerDataBase();

	HRESULT init();
	void release();
	void update();
	void render();




};

