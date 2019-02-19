#include "stdafx.h"
#include "caveMap.h"


caveMap::caveMap()
{
}


caveMap::~caveMap()
{
}

void caveMap::setPokemon()
{
	_minLevel = 7;
	_maxLevel = 10;

	_pokemon.push_back(PM_CHARIZARD);
	_pokemon.push_back(PM_IVYSAUR);
}

void caveMap::potalLoad()
{
	{
		potalInfo info;
		//동굴 포탈
		info.x = 31;
		info.y = 40;
		info.nextScene = "fieldScene";		//포탈을 타면 필드의 동굴 입구로 연결됨.
		info.nextX = 52;					//필드의 동굴 입구 좌표 X
		info.nextY = 15;					//필드의 동굴 입구 좌표 Y
		info.nextDirection = 3;				//나왔을때 아래방향을 향함
		_potal.push_back(info);
	}


}
