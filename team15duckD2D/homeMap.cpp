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
		//���� ��Ż ��ǥ
		potalInfo info;
		info.x = 15;					// ���� �ִ� ��Ż ��ǥ
		info.y = 15;					// ���� �ִ� ��Ż ��ǥ
		info.nextX = 23;				// ������ ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info.nextY = 15;				// ������ ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info.nextScene = "townScene";	// ���������� ��ȯ
		info.nextDirection = 3;			// ������ ������ �÷��̾ �ٶ󺸰� �ִ� ����
		_potal.push_back(info);


	}

}


