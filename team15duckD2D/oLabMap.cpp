#include "stdafx.h"
#include "oLabMap.h"


oLabMap::oLabMap()
{
}


oLabMap::~oLabMap()
{
}

void oLabMap::setPokemon()
{
	_pokemon.push_back(PM_CHARIZARD);
	_pokemon.push_back(PM_IVYSAUR);





}

void oLabMap::potalLoad()
{
	{
		potalInfo info;
		//오박사의 포탈 좌표
		info.x = 16;					// 마을로 이동할 포탈 좌표
		info.y = 21;					// 마을로 이동할 포탈 좌표
		info.nextX = 36;				// 마을로 씬이 전환되면 플레이어가 위치할 좌표
		info.nextY = 17;				// 마을로 씬이 전환되면 플레이어가 위치할 좌표
		info.nextScene = "townScene";	// 마을 씬으로 전환
		info.nextDirection = 3;			// 마을로 나가면 플레이어가 바라보고 있는 방향
		_potal.push_back(info);
	}
}
