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
enum P_LOOK_POKEMON
{
	LP_INFO,
	LP_ABILITY,
	LP_ATTK_SKILL
};
typedef struct tagPpokemonInfo
{
	wstring iD_number;
	wstring name;
	wstring level;
	wstring type;
	wstring item;

	wstring currentHp;
	wstring maxHp;

	wstring attk;
	wstring s_attk;
	wstring def;
	wstring s_def;
	wstring currentExp;

	bool isDataSet;

}PPOKEMON;
class possessionPokemon : public baseUI
{
private : 
	P_POKEMON_STATE		_ppstate;
	P_POKEMON_SELECT	_ppselect;
	P_SUB_MENU_SELECT	_psmselect;
	P_LOOK_POKEMON		_plpokemon;
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


	void uiInfoSet();
	void pPokemonDataSet();

	void uiOpen();
	void uiClose();

	P_POKEMON_STATE getstate() { return _ppstate; }
};

