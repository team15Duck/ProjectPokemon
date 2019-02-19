#include "stdafx.h"
#include "fieldMap.h"


fieldMap::fieldMap()
{
}


fieldMap::~fieldMap()
{
}

void fieldMap::setPokemon()
{
	_minLevel = 3;
	_maxLevel = 5;

	_pokemon.push_back(PM_CHARIZARD);
	_pokemon.push_back(PM_IVYSAUR);





}

void fieldMap::potalLoad()
{
	{
		//필드의 포탈 좌표1 ( 마을로 가는 포탈은 나란히 4개임 )
		potalInfo info1;
		//4개 중 첫번째 포탈
		info1.x = 47;
		info1.y = 42;
		info1.nextX = 7;					//마을씬으로 전환 되고 나면 "마을->필드" 포탈좌표 중 가운데 좌표로 이동함
		info1.nextY = 9;					//마을씬으로 전환 되고 나면 "마을->필드" 포탈좌표 중 가운데 좌표로 이동함
		info1.nextScene = "townScene";		//마을씬으로 전환
		info1.nextDirection = 2;			//방향은 오른쪽을 보고있어여
		_potal.push_back(info1);			

		//4개 중 두번째 포탈
		info1.x = 48;
		info1.y = 42;
		info1.nextX = 7;
		info1.nextY = 9;
		info1.nextScene = "townScene";
		info1.nextDirection = 2;
		_potal.push_back(info1);

		//4개 중 세번째 포탈
		info1.x = 49;
		info1.y = 42;
		info1.nextX = 7;
		info1.nextY = 9;
		info1.nextScene = "townScene";
		info1.nextDirection = 2;
		_potal.push_back(info1);

		//4개 중 네번째 포탈
		info1.x = 50;
		info1.y = 42;
		info1.nextX = 7;
		info1.nextY = 9;
		info1.nextScene = "townScene";
		info1.nextDirection = 2;
		_potal.push_back(info1);
	}

	{
		//필드의 포탈 좌표2 ( 동굴로 가는 포탈 )
		potalInfo info2;
		info2.x = 52;					//동굴로 이동하는 포탈
		info2.y = 15;					//동굴로 이동하는 포탈
		info2.nextX = 31;				//동굴에서 시작하는 좌표
		info2.nextY = 40;				//동굴에서 시작하는 좌표
		info2.nextScene = "caveScene";	//동굴씬
		info2.nextDirection = 1;		//플레이어는 위를 바라보고있죱
		_potal.push_back(info2);		
	}
}

void fieldMap::fieldItemLoad()
{
	tagFieldItem field;
	field.x = 13;						 //첫번째 아이템 위치
	field.y = 7;						 //첫번째 아이템 위치
	field.itemType = SUPER_POTION;		 //고급회복약
	_fieldItems.push_back(field);		 

	field.x = 22;						 //두번째 아이템 위치
	field.y = 11;						 //두번째 아이템 위치
	field.itemType = SUPER_BALL;		 //슈퍼볼
	_fieldItems.push_back(field);

	field.x = 58;						 //세번째 아이템 위치
	field.y = 38;						 //세번째 아이템 위치
	field.itemType = ANTIDOTE;			 //해독제
	_fieldItems.push_back(field);

	field.x = 57;						 //네번째 아이템 위치
	field.y = 25;						 //네번째 아이템 위치
	field.itemType = NORMAL_ETHER;		 //PP에이드
	_fieldItems.push_back(field);
}
