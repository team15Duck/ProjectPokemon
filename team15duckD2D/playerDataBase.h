#pragma once
#include "singletonBase.h"
#include "player.h"

class playerDataBase : public singletonBase<playerDataBase>
{
public:
	enum DATA
	{
		DATA_DEFAULT,
		DATA_1,
		DATA_2,
		DATA_3,
		DATA_4,
		DATA_5,
		DATA_6
	};


private:

	player* _currentPlayer;								//�갡 Ȱ���Ұ���

public:
	playerDataBase();
	~playerDataBase();

	HRESULT init();
	void release();
	void update();
	void render();

	void dataLoad(DATA data);							//����� �����͸� �ҷ����� ���� �Լ�
	void dataSave(DATA data);								//��� �����Ϳ� �����ҰŴ�

	void bankPokemonLoad(DATA data);
	void currentPokemonLoad(DATA data);
	void fieldItemDataLoad(DATA data);
	void npcDataLoad(DATA data);
	void objectDataLoad(DATA data);
	void playerDataLoad(DATA data);


	void bankPokemonSave(DATA data);
	void currentPokemonSave(DATA data);
	void fieldItemDataSave(DATA data);
	void npcDataSave(DATA data);
	void objectDataSave(DATA data);
	void playerDataSave(DATA data);

};

