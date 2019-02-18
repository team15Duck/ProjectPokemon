#pragma once
class object
{
public:
	object();
	~object();

	HRESULT init();
	void release();
	void update();
	void render();
};

