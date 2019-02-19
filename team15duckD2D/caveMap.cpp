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

void caveMap::fieldItemLoad()
{
	{
		tagFieldItem field;
		field.x = 19;						 //ù��° ������ ��ġ
		field.y = 22;						 //ù��° ������ ��ġ
		field.itemType = REVIVE;		 //���ȸ����
		_fieldItems.push_back(field);

		field.x = 35;						 //�ι�° ������ ��ġ
		field.y = 25;						 //�ι�° ������ ��ġ
		field.itemType = NORMAL_ETHER;		 //���ۺ�
		_fieldItems.push_back(field);

		field.x = 42;						 //����° ������ ��ġ
		field.y = 25;						 //����° ������ ��ġ
		field.itemType = HYPER_BALL;			 //�ص���
		_fieldItems.push_back(field);

		field.x = 45;						 //�׹�° ������ ��ġ
		field.y = 9;						 //�׹�° ������ ��ġ
		field.itemType = NORMAL_POTION;		 //PP���̵�
		_fieldItems.push_back(field);
	}
}
