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
		//������ ��Ż ��ǥ
		info.x = 14;					// ������ �̵��� ��Ż ��ǥ
		info.y = 14;					// ������ �̵��� ��Ż ��ǥ
		info.nextX = 38;				// ������ ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info.nextY = 27;				// ������ ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info.nextScene = "townScene";	// ���� ������ ��ȯ
		info.nextDirection = 3;			// ������ ������ �÷��̾ �ٶ󺸰� �ִ� ����
		_potal.push_back(info);
	}
}
