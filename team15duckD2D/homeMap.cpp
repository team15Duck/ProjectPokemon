#include "stdafx.h"
#include "homeMap.h"


homeMap::homeMap()
{
}


homeMap::~homeMap()
{
}

void homeMap::setPokemon()
{
	_pokemon.push_back(PM_CHARIZARD);
	_pokemon.push_back(PM_IVYSAUR);

}

void homeMap::potalLoad()
{
	{
		//집의 포탈 좌표
		potalInfo info;
		info.x = 15;					// 집에 있는 포탈 좌표
		info.y = 15;					// 집에 있는 포탈 좌표
		info.nextX = 23;				// 마을로 씬이 전환되면 플레이어가 위치할 좌표
		info.nextY = 15;				// 마을로 씬이 전환되면 플레이어가 위치할 좌표
		info.nextScene = "townScene";	// 마을씬으로 전환
		info.nextDirection = 3;			// 마을로 나오면 플레이어가 바라보고 있는 방향
		_potal.push_back(info);


	}

}


