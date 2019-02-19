#include "stdafx.h"
#include "storeMap.h"


storeMap::storeMap()
{
}


storeMap::~storeMap()
{
}

void storeMap::setPokemon()
{
	_pokemon.push_back(PM_CHARIZARD);
	_pokemon.push_back(PM_IVYSAUR);





}

void storeMap::potalLoad()
{
	{
		potalInfo info;
		//상점의 포탈 좌표
		info.x = 14;					// 마을로 이동할 포탈 좌표
		info.y = 14;					// 마을로 이동할 포탈 좌표
		info.nextX = 38;				// 마을로 씬이 전환되면 플레이어가 위치할 좌표
		info.nextY = 27;				// 마을로 씬이 전환되면 플레이어가 위치할 좌표
		info.nextScene = "townScene";	// 마을 씬으로 전환
		info.nextDirection = 3;			// 마을로 나가면 플레이어가 바라보고 있는 방향
		_potal.push_back(info);
	}
}
