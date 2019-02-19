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
		//���� ��Ż
		info.x = 31;
		info.y = 40;
		info.nextScene = "fieldScene";		//��Ż�� Ÿ�� �ʵ��� ���� �Ա��� �����.
		info.nextX = 52;					//�ʵ��� ���� �Ա� ��ǥ X
		info.nextY = 15;					//�ʵ��� ���� �Ա� ��ǥ Y
		info.nextDirection = 3;				//�������� �Ʒ������� ����
		_potal.push_back(info);
	}


}
