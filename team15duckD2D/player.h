#pragma once
#include <unordered_map>
#include "item.h"
#include "pokemon.h"

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

	typedef unordered_map<string,item*>					mapItemList;
	typedef unordered_map<string,item*>::iterator		mapItemIter;

private:
	string	_name;					//이름
	bool	_isMan;					//남자니?
	float	_playTime;				//플레이타임
	float	_posX;					//좌표
	float	_posY;					//좌표
	UINT	_tileX;					//현재 위치하고 있는 타일 번호
	UINT	_tileY;					//현재 위치하고 있는 타일 번호
	PLAYER_STATE _state;			//스테이트
	mapItemList _mItemList;			//아이템을 담고 있는 셋
	pokemon*	_pokemon[6];		//포켓몬ㅋ
	animation* _playerAni;			//플레이어 애니
public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	//얘는 맵에 끼워넣어서 그려야함
	void render();	

private:
	//내부함수
	void aniSetUp();
	void dataLoad();

	void keyUpdate();
	void stateUpdate();



public:
	//겟셋
	UINT getTileX() { return _tileX; }
	UINT getTileY() { return _tileY; }
	
	string getName() { return _name; }
	bool getIsMan() { return _isMan; }

	mapItemList getItem() { return _mItemList; }
	pokemon** getPokemon() { return _pokemon; }


};

