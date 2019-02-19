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
		//�ʵ��� ��Ż ��ǥ1 ( ������ ���� ��Ż�� ������ 4���� )
		potalInfo info1;
		//4�� �� ù��° ��Ż
		info1.x = 47;
		info1.y = 42;
		info1.nextX = 7;					//���������� ��ȯ �ǰ� ���� "����->�ʵ�" ��Ż��ǥ �� ��� ��ǥ�� �̵���
		info1.nextY = 9;					//���������� ��ȯ �ǰ� ���� "����->�ʵ�" ��Ż��ǥ �� ��� ��ǥ�� �̵���
		info1.nextScene = "townScene";		//���������� ��ȯ
		info1.nextDirection = 2;			//������ �������� �����־
		_potal.push_back(info1);			

		//4�� �� �ι�° ��Ż
		info1.x = 48;
		info1.y = 42;
		info1.nextX = 7;
		info1.nextY = 9;
		info1.nextScene = "townScene";
		info1.nextDirection = 2;
		_potal.push_back(info1);

		//4�� �� ����° ��Ż
		info1.x = 49;
		info1.y = 42;
		info1.nextX = 7;
		info1.nextY = 9;
		info1.nextScene = "townScene";
		info1.nextDirection = 2;
		_potal.push_back(info1);

		//4�� �� �׹�° ��Ż
		info1.x = 50;
		info1.y = 42;
		info1.nextX = 7;
		info1.nextY = 9;
		info1.nextScene = "townScene";
		info1.nextDirection = 2;
		_potal.push_back(info1);
	}

	{
		//�ʵ��� ��Ż ��ǥ2 ( ������ ���� ��Ż )
		potalInfo info2;
		info2.x = 52;					//������ �̵��ϴ� ��Ż
		info2.y = 15;					//������ �̵��ϴ� ��Ż
		info2.nextX = 31;				//�������� �����ϴ� ��ǥ
		info2.nextY = 40;				//�������� �����ϴ� ��ǥ
		info2.nextScene = "caveScene";	//������
		info2.nextDirection = 1;		//�÷��̾�� ���� �ٶ󺸰��֡�
		_potal.push_back(info2);		
	}
}

void fieldMap::fieldItemLoad()
{
	tagFieldItem field;
	field.x = 13;						 //ù��° ������ ��ġ
	field.y = 7;						 //ù��° ������ ��ġ
	field.itemType = SUPER_POTION;		 //���ȸ����
	_fieldItems.push_back(field);		 

	field.x = 22;						 //�ι�° ������ ��ġ
	field.y = 11;						 //�ι�° ������ ��ġ
	field.itemType = SUPER_BALL;		 //���ۺ�
	_fieldItems.push_back(field);

	field.x = 58;						 //����° ������ ��ġ
	field.y = 38;						 //����° ������ ��ġ
	field.itemType = ANTIDOTE;			 //�ص���
	_fieldItems.push_back(field);

	field.x = 57;						 //�׹�° ������ ��ġ
	field.y = 25;						 //�׹�° ������ ��ġ
	field.itemType = NORMAL_ETHER;		 //PP���̵�
	_fieldItems.push_back(field);
}
