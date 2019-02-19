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
	OBJECT_ACTIVE_TYPE			_activeType;			//오브젝트 어떤타입으로 작동하는지

	UINT						_tileX;					//위치
	UINT						_tileY;					//위치

	bool						_isActive;				//작동했는지?


	animation*					_motion;
	bool						_isHealing;
	int							_count;
	int							_ballX;

public:
	object();
	~object();

	HRESULT init();
	void release();
	void update();
	void render();




	//테슷흐함수
	void aniSetting();
	void startAni();


	//=============겟셋====================

	UINT getTileX() { return _tileX; }
	UINT getTIleY() { return _tileY; }
	void setTileX(UINT tileX) { _tileX = tileX; }
	void setTIleY(UINT tileY) { _tileY = tileY; }
};

