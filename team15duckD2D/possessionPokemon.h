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
enum P_SUB_MENU_SELECT
{
	SELECT_LOOK_POKEMON,
	SELECT_CHANGE_ORDER,
	SELECT_KEEP_ITEM,
	SELECT_NONE,
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
	P_SUB_MENU_SELECT	_psmselect;
	PPOKEMON			_pPokemon[6];

	int _pokemonCnt; // 보유하고 있는 포켓몬의 수

	UINT _currentSelecPok;

	bool _isMainpokemon;	//메인포켓몬이냐?
	bool _isSubpokemon;		//서브 포켓몬이 있냐?
	bool _isSubMenu;

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

