#pragma once
#include "singletonBase.h"
#include "player.h"

class playerDataBase : public singletonBase<playerDataBase>
{
private:

public:
	playerDataBase();
	~playerDataBase();

	HRESULT init();
	void release();
	void update();
	void render();

	void dataLoad(UINT dataNum);						//����� �����͸� �ҷ����� ���� �Լ�
	void dataSet(player* p);							//�÷��̾�� ���� �����͸� ���� ���ֱ� ���� �Լ�  -- ������ �÷��̾ ���� ������ ���̱� ������ �÷��̾��� �ּҰ��� �޾ƿ´�
	void dataSave(int num);								//��� �����Ϳ� �����ҰŴ�



};

