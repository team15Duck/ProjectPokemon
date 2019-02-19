#include "stdafx.h"
#include "townMap.h"


townMap::townMap()
{
}


townMap::~townMap()
{
}

void townMap::setPokemon()
{
	_pokemon.push_back(PM_CHARIZARD);
	_pokemon.push_back(PM_IVYSAUR);





}

void townMap::potalLoad()
{
	{
		potalInfo info;
		//마을의 포탈 좌표 1 ( 집 )
		info.x = 23;					// 집으로 이동할 포탈 좌표
		info.y = 15;					// 집으로 이동할 포탈 좌표
		info.nextX = 15;				// 집으로 씬이 전환되면 플레이어가 위치할 좌표
		info.nextY = 15;				// 집으로 씬이 전환되면 플레이어가 위치할 좌표
		info.nextScene = "homeScene";	// 집 씬으로 전환
		info.nextDirection = 1;			// 집에 들어가면 플레이어가 바라보고 있는 방향
		_potal.push_back(info);

		//마을의 포탈 좌표 2 ( 오박사 연구실 )
		info.x = 36;					// 연구실로 이동할 포탈 좌표
		info.y = 16;					// 연구실로 이동할 포탈 좌표
		info.nextX = 16;				// 연구실로 씬이 전환되면 플레이어가 위치할 좌표
		info.nextY = 21;				// 연구실로 씬이 전환되면 플레이어가 위치할 좌표
		info.nextScene = "oLabScene";	// 연구실 씬으로 전환
		info.nextDirection = 1;			// 연구실에 들어가면 플레이어가 바라보고 있는 방향
		_potal.push_back(info);

		//마을의 포탈 좌표 3 ( 상점 )
		info.x = 38;					// 상점으로 이동할 포탈 좌표
		info.y = 26;					// 상점으로 이동할 포탈 좌표
		info.nextX = 14;				// 상점으로 씬이 전환되면 플레이어가 위치할 좌표
		info.nextY = 14;				// 상점으로 씬이 전환되면 플레이어가 위치할 좌표
		info.nextScene = "storeScene";	// 상점 씬으로 전환
		info.nextDirection = 1;			// 상점에 들어가면 플레이어가 바라보고 있는 방향
		_potal.push_back(info);

		//마을의 포탈 좌표 4 ( 포켓몬센터 )
		info.x = 33;					// 센터로 이동할 포탈 좌표
		info.y = 26;					// 센터로 이동할 포탈 좌표
		info.nextX = 17;				// 센터로 씬이 전환되면 플레이어가 위치할 좌표
		info.nextY = 15;				// 센터로 씬이 전환되면 플레이어가 위치할 좌표
		info.nextScene = "centerScene";	// 센터 씬으로 전환
		info.nextDirection = 1;			// 센터에 들어가면 플레이어가 바라보고 있는 방향
		_potal.push_back(info);

		//마을의 포탈 좌표 5 ( 체육관 )
		info.x = 26;					// 체육관으로 이동할 포탈 좌표
		info.y = 26;					// 체육관으로 이동할 포탈 좌표
		info.nextX = 16;				// 체육관으로 씬이 전환되면 플레이어가 위치할 좌표
		info.nextY = 20;				// 체육관으로 씬이 전환되면 플레이어가 위치할 좌표
		info.nextScene = "gymScene";	// 체육관 씬으로 전환
		info.nextDirection = 1;			// 체육관에 들어가면 플레이어가 바라보고 있는 방향
		_potal.push_back(info);



	}

	{
		//필드로 이동할 포탈 좌표 ( 총 3 개)
		potalInfo info2;
		//3개 중 첫 번째
		info2.x = 7;					// 필드로 이동할 포탈 좌표 1
		info2.y = 8;					// 필드로 이동할 포탈 좌표 1
		info2.nextX = 48;				// 필드로 씬이 전환되면 플레이어가 위치할 좌표
		info2.nextY = 42;				// 필드로 씬이 전환되면 플레이어가 위치할 좌표
		info2.nextScene = "fieldScene";	// 필드 씬으로 전환
		info2.nextDirection = 1;		// 필드에 들어가면 플레이어가 바라보고 있는 방향
		_potal.push_back(info2);

		//3개 중 두 번째
		info2.x = 7;					// 필드로 이동할 포탈 좌표 2
		info2.y = 9;					// 필드로 이동할 포탈 좌표 2
		info2.nextX = 48;				// 필드로 씬이 전환되면 플레이어가 위치할 좌표
		info2.nextY = 42;				// 필드로 씬이 전환되면 플레이어가 위치할 좌표
		info2.nextScene = "fieldScene";	// 필드 씬으로 전환
		info2.nextDirection = 1;		// 필드에 들어가면 플레이어가 바라보고 있는 방향
		_potal.push_back(info2);

		//3개 중 세 번째
		info2.x = 7;					// 필드로 이동할 포탈 좌표 1
		info2.y = 10;					// 필드로 이동할 포탈 좌표 1
		info2.nextX = 48;				// 필드로 씬이 전환되면 플레이어가 위치할 좌표
		info2.nextY = 42;				// 필드로 씬이 전환되면 플레이어가 위치할 좌표
		info2.nextScene = "fieldScene";	// 필드 씬으로 전환
		info2.nextDirection = 1;		// 필드에 들어가면 플레이어가 바라보고 있는 방향
		_potal.push_back(info2);
	}



}
