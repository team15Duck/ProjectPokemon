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
		//������ ��Ż
		info.x = 17;					//������ ��Ż��ǥ
		info.y = 15;					//������ ��Ż��ǥ
		info.nextX = 33;				//���Ϳ��� ������ ������ ���;����� �̵��մϴ�
		info.nextY = 27;				//���Ϳ��� ������ ������ ���;����� �̵��մϴ�
		info.nextScene = "townScene";	//���Ϳ��� ������ �����̡�
		info.nextDirection = 3;			//���Ϳ��� ������ ���� �Ʒ������� �������� �ſ���
		_potal.push_back(info);
	}



}
