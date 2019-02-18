#include "stdafx.h"
#include "centerMap.h"


centerMap::centerMap()
{
}


centerMap::~centerMap()
{
}

void centerMap::setPokemon()
{
	_pokemon.push_back(PM_CHARIZARD);
	_pokemon.push_back(PM_IVYSAUR);

}

void centerMap::potalLoad()
{
	{
		potalInfo info;
		//센터의 포탈
		info.x = 17;					//센터의 포탈좌표
		info.y = 15;					//센터의 포탈좌표
		info.nextX = 33;				//센터에서 나오면 마을의 센터앞으로 이동합니다
		info.nextY = 27;				//센터에서 나오면 마을의 센터앞으로 이동합니다
		info.nextScene = "townScene";	//센터에서 나오면 마을이죱
		info.nextDirection = 3;			//센터에서 나오고 나면 아래방향을 보고있을 거에여
		_potal.push_back(info);
	}



}
