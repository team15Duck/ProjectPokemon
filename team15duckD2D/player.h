#pragma once
class player
{
private:
	string _name;
	int _playTime;

	


public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	void render();
};

