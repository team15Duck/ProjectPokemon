#pragma once
#include "baseUI.h"

enum P_POKEMON_STATE
{
	P_POKEMON_LIST,
	P_POKEMON_SUB_MENU,
	P_POKEMON_INFO,
};
enum P_POKEMON_SELECT
{
	SELECT_MAIN_POKEMON,
	SELECT_SUB_POKEMON1,
	SELECT_SUB_POKEMON2,
	SELECT_SUB_POKEMON3,
	SELECT_SUB_POKEMON4,
	SELECT_SUB_POKEMON5,
	SELECT_CANCEL
};
typedef struct tagPpokemonInfo
{
	wstring name;
	wstring level;
	wstring hp;

	bool isDataSet;

}PPOKEMON;
class possessionPokemon : public baseUI
{
private : 
	P_POKEMON_STATE		_ppstate;
	P_POKEMON_SELECT	_ppselect;
	PPOKEMON			_pPokemon[6];

	int _pokemonCnt; // �����ϰ� �ִ� ���ϸ��� ��

	UINT _currentSelecPok;

	bool _isMainpokemon;	//�������ϸ��̳�?

	bool _isSubpokemon;		//���� ���ϸ��� �ֳ�?

public:
	possessionPokemon();
	~possessionPokemon();

	HRESULT init();
	void release();
	void update();
	void render();

	void pPokemonDataSet();

	void uiOpen();
	void uiClose();

	P_POKEMON_STATE getstate() { return _ppstate; }
};

