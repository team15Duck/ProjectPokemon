#pragma once
#include "gameNode.h"

class field1Scnee : public gameNode
{
private:

public:
	field1Scnee();
	~field1Scnee();

	HRESULT init();
	void release();
	void update();
	void render();
};