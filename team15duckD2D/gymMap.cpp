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
		//ü������ ��Ż ��ǥ
		potalInfo info;
		info.x = 16;					// ü������ �ִ� ��Ż ��ǥ
		info.y = 20;					// ü������ �ִ� ��Ż ��ǥ
		info.nextX = 26;				// ������ ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info.nextY = 27;				// ������ ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info.nextScene = "townScene";	// ���������� ��ȯ
		info.nextDirection = 3;			// ������ ������ �÷��̾ �ٶ󺸰� �ִ� ����
		_potal.push_back(info);
	}


}
