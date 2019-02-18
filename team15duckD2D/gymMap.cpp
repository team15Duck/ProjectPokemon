#include "stdafx.h"
#include "gymMap.h"


gymMap::gymMap()
{
}


gymMap::~gymMap()
{
}

void gymMap::setPokemon()
{
	_minLevel = 10;
	_maxLevel = 14;

	_pokemon.push_back(PM_CHARIZARD);
	_pokemon.push_back(PM_IVYSAUR);

}

void gymMap::potalLoad()
{
	{
		//체육관의 포탈 좌표
		potalInfo info;
		info.x = 16;					// 체육관에 있는 포탈 좌표
		info.y = 20;					// 체육관에 있는 포탈 좌표
		info.nextX = 26;				// 마을로 씬이 전환되면 플레이어가 위치할 좌표
		info.nextY = 27;				// 마을로 씬이 전환되면 플레이어가 위치할 좌표
		info.nextScene = "townScene";	// 마을씬으로 전환
		info.nextDirection = 3;			// 마을로 나오면 플레이어가 바라보고 있는 방향
		_potal.push_back(info);
	}


}
