#pragma once
class player
{
private:
	string _name;			//이름
	int _playTime;			//플레이타임
	float _posX;			//좌표
	float _posY;			//좌표
	int _tileX;				//현재 위치하고 있는 타일 번호
	int _tileY;				//현재 위치하고 있는 타일 번호



public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	void render();
};

