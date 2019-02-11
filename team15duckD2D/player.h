#pragma once
#include <unordered_set>
#include "item.h"

class player
{
public:
	enum PLAYER_STATE
	{
		PS_IDLE_LEFT,			PS_IDLE_UP,				PS_IDLE_RIGHT,				PS_IDLE_DOWN,			//서있음				
		PS_MOVE_LEFT,			PS_MOVE_UP,				PS_MOVE_RIGHT,				PS_MOVE_DOWN,			//이동
		PS_FASTMOVE_LEFT,		PS_FASTMOVE_UP,			PS_FASTMOVE_RIGHT,			PS_FASTMOVE_DOWN,		//빨리이동
		PS_BICYCLE_IDLE_LEFT,	PS_BICYCLE_IDLE_UP,		PS_BICYCLE_IDLE_RIGHT,		PS_BICYCLE_IDLE_DOWN,	//자전거가만히
		PS_BICYCLE_LEFT,		PS_BICYCLE_UP,			PS_BICYCLE_RIGHT,			PS_BICYCLE_DOWN,		//자전거
	};

	typedef unordered_set<item*>				setItemList;
	typedef unordered_set<item*>::iterator		setItemIter;
private:
	string	_name;					//이름
	bool	_isMan;					//남자니?
	int		_playTime;				//플레이타임
	float	_posX;					//좌표
	float	_posY;					//좌표
	int		_tileX;					//현재 위치하고 있는 타일 번호
	int		_tileY;					//현재 위치하고 있는 타일 번호

	setItemList _sItemList;			//아이템을 담고 있는 셋

	
public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	void render();	

private:
	//내부함수
	void aniSetUp();
	void dataLoad();


public:
	//겟셋
};

