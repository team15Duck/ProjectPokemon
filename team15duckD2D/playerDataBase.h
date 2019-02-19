#pragma once
#include "singletonBase.h"
#include "player.h"
#include "pokemon.h"
//#include 엔피씨

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

	player* _currentPlayer;								//얘가 활동할거임

	
	//배틀씬에서 얘 통해서 정보 받아오기
	pokemon* _pokemon;									//다음상대 : default = nullptr;
	//enemyNpc* _npc;									//얘도 nullptr





public:
	playerDataBase();
	~playerDataBase();

	HRESULT init();
	void release();
	void update();
	void render();

	void dataLoad(DATA data);								//저장된 데이터를 불러오기 위한 함수
	void dataSave(DATA data);								//몇번 데이터에 저장할거니

	void bankPokemonLoad(DATA data);
	void currentPokemonLoad(DATA data);
	void fieldItemDataLoad(DATA data);
	void npcDataLoad(DATA data);
	void itemDataLoad(DATA data);
	void objectDataLoad(DATA data);
	void playerDataLoad(DATA data);


	void bankPokemonSave(DATA data);
	void currentPokemonSave(DATA data);
	void fieldItemDataSave(DATA data);
	void npcDataSave(DATA data);
	void itemDataSave(DATA data);
	void objectDataSave(DATA data);
	void playerDataSave(DATA data);





public:
	pokemon* getPokemon() { return _pokemon; }
	void setPokemon(pokemon* pokemon) { _pokemon = pokemon; }
	player* getPlayer() { return _currentPlayer; }
};

