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
		//���ڻ��� ��Ż ��ǥ
		info.x = 16;					// ������ �̵��� ��Ż ��ǥ
		info.y = 21;					// ������ �̵��� ��Ż ��ǥ
		info.nextX = 36;				// ������ ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info.nextY = 17;				// ������ ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info.nextScene = "townScene";	// ���� ������ ��ȯ
		info.nextDirection = 3;			// ������ ������ �÷��̾ �ٶ󺸰� �ִ� ����
		_potal.push_back(info);
	}
}
