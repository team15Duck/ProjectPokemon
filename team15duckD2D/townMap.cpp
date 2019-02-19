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
		//������ ��Ż ��ǥ 1 ( �� )
		info.x = 23;					// ������ �̵��� ��Ż ��ǥ
		info.y = 15;					// ������ �̵��� ��Ż ��ǥ
		info.nextX = 15;				// ������ ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info.nextY = 15;				// ������ ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info.nextScene = "homeScene";	// �� ������ ��ȯ
		info.nextDirection = 1;			// ���� ���� �÷��̾ �ٶ󺸰� �ִ� ����
		_potal.push_back(info);

		//������ ��Ż ��ǥ 2 ( ���ڻ� ������ )
		info.x = 36;					// �����Ƿ� �̵��� ��Ż ��ǥ
		info.y = 16;					// �����Ƿ� �̵��� ��Ż ��ǥ
		info.nextX = 16;				// �����Ƿ� ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info.nextY = 21;				// �����Ƿ� ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info.nextScene = "oLabScene";	// ������ ������ ��ȯ
		info.nextDirection = 1;			// �����ǿ� ���� �÷��̾ �ٶ󺸰� �ִ� ����
		_potal.push_back(info);

		//������ ��Ż ��ǥ 3 ( ���� )
		info.x = 38;					// �������� �̵��� ��Ż ��ǥ
		info.y = 26;					// �������� �̵��� ��Ż ��ǥ
		info.nextX = 14;				// �������� ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info.nextY = 14;				// �������� ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info.nextScene = "storeScene";	// ���� ������ ��ȯ
		info.nextDirection = 1;			// ������ ���� �÷��̾ �ٶ󺸰� �ִ� ����
		_potal.push_back(info);

		//������ ��Ż ��ǥ 4 ( ���ϸ��� )
		info.x = 33;					// ���ͷ� �̵��� ��Ż ��ǥ
		info.y = 26;					// ���ͷ� �̵��� ��Ż ��ǥ
		info.nextX = 17;				// ���ͷ� ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info.nextY = 15;				// ���ͷ� ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info.nextScene = "centerScene";	// ���� ������ ��ȯ
		info.nextDirection = 1;			// ���Ϳ� ���� �÷��̾ �ٶ󺸰� �ִ� ����
		_potal.push_back(info);

		//������ ��Ż ��ǥ 5 ( ü���� )
		info.x = 26;					// ü�������� �̵��� ��Ż ��ǥ
		info.y = 26;					// ü�������� �̵��� ��Ż ��ǥ
		info.nextX = 16;				// ü�������� ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info.nextY = 20;				// ü�������� ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info.nextScene = "gymScene";	// ü���� ������ ��ȯ
		info.nextDirection = 1;			// ü������ ���� �÷��̾ �ٶ󺸰� �ִ� ����
		_potal.push_back(info);



	}

	{
		//�ʵ�� �̵��� ��Ż ��ǥ ( �� 3 ��)
		potalInfo info2;
		//3�� �� ù ��°
		info2.x = 7;					// �ʵ�� �̵��� ��Ż ��ǥ 1
		info2.y = 8;					// �ʵ�� �̵��� ��Ż ��ǥ 1
		info2.nextX = 48;				// �ʵ�� ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info2.nextY = 42;				// �ʵ�� ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info2.nextScene = "fieldScene";	// �ʵ� ������ ��ȯ
		info2.nextDirection = 1;		// �ʵ忡 ���� �÷��̾ �ٶ󺸰� �ִ� ����
		_potal.push_back(info2);

		//3�� �� �� ��°
		info2.x = 7;					// �ʵ�� �̵��� ��Ż ��ǥ 2
		info2.y = 9;					// �ʵ�� �̵��� ��Ż ��ǥ 2
		info2.nextX = 48;				// �ʵ�� ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info2.nextY = 42;				// �ʵ�� ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info2.nextScene = "fieldScene";	// �ʵ� ������ ��ȯ
		info2.nextDirection = 1;		// �ʵ忡 ���� �÷��̾ �ٶ󺸰� �ִ� ����
		_potal.push_back(info2);

		//3�� �� �� ��°
		info2.x = 7;					// �ʵ�� �̵��� ��Ż ��ǥ 1
		info2.y = 10;					// �ʵ�� �̵��� ��Ż ��ǥ 1
		info2.nextX = 48;				// �ʵ�� ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info2.nextY = 42;				// �ʵ�� ���� ��ȯ�Ǹ� �÷��̾ ��ġ�� ��ǥ
		info2.nextScene = "fieldScene";	// �ʵ� ������ ��ȯ
		info2.nextDirection = 1;		// �ʵ忡 ���� �÷��̾ �ٶ󺸰� �ִ� ����
		_potal.push_back(info2);
	}



}
