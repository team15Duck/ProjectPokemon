#pragma once
#include "mapData.h"
#include "item.h"

enum OBJECT_ACTIVE_TYPE
{
	OBJECT_ACTIVE_TYPE_COMPUTER,						 //오브젝트가 컴퓨터일때
	OBJECT_ACTIVE_TYPE_DIALOG,							 //그외 오브젝트
	OBJECT_ACTIVE_TYPE_ITEM,							 //오브젝트가 아이템일때
	OBJECT_ACTIVE_TYPE_CUT,								 //오브젝트가 작은나무일때(풀베기O)
	OBJECT_ACTIVE_TYPE_CENTER,							 //포켓몬 치료할때

	OBJECT_ACTIVE_TYPE_NONE,
	OBJECT_ACTIVE_TYPE_COUNT = OBJECT_ACTIVE_TYPE_NONE
};


class object
{
private:

	string						_sceneName;				//현재씬
	
	//회복용
	UINT						_tileX;					//위치
	UINT						_tileY;					//위치
	UINT						_curPokemon;			//플레이어가 가지고 있는 포켓몬 수
	UINT						_healedPokemon;			//치료받는 포켓몬 수(비교용)
	OBJECT_ACTIVE_TYPE			_activeType;			//오브젝트 어떤타입으로 작동하는지



	bool						_isActive;				//작동했는지?
	bool						_isBallUp;				//볼올리는중인지?
	bool						_isHealing;				//회복중인지?


	animation*					_motion;
	int							_count;					//프레임용
	int							_ballX;					//프레임x
	int							_time;					//이시간동안 회복하는 프레임 돌거다

public:
	object();
	~object();

	HRESULT init();
	void release();
	void update();
	void render();

	
	void centerHealing();

	//테슷흐함수
	void aniSetting();


	//=============겟셋====================

	UINT getTileX() { return _tileX; }
	UINT getTIleY() { return _tileY; }
	void setTileX(UINT tileX) { _tileX = tileX; }
	void setTIleY(UINT tileY) { _tileY = tileY; }

	bool getIsActive() { return _isActive; }
	void setIsActive(bool active) { _isActive = active; }

	bool getIsBallUp() { return _isBallUp; }
	void setIsBallUp(bool ballUp) { _isBallUp = ballUp; }

	void setSceneName(string name) { _sceneName = name; }
};

