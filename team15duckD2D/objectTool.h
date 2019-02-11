#pragma once
class objectTool
{
public:
	objectTool();
	~objectTool();

	HRESULT init();
	void release();
	void update();
	void render();
};

