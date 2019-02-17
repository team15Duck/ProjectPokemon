#pragma once

enum P_POKEMON_STATE
{
	P_POKEMON_LIST,
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
class possessionPokemon
{
private : 
	P_POKEMON_STATE		_ppstate;
	P_POKEMON_SELECT	_ppselect;
	PPOKEMON			_pPokemon[6];

	int _pokemonCnt; // 보유하고 있는 포켓몬의 수

	UINT _currentSelecPok;

	bool _isMainpokemon;	//메인포켓몬이냐?

	bool _isSubpokemon;		//서브 포켓몬이 있냐?

	bool _issubpkm1exist;	//서브포켓몬 확인용 불값
	bool _issubpkm2exist;	//서브포켓몬 확인용 불값
	bool _issubpkm3exist;	//서브포켓몬 확인용 불값
	bool _issubpkm4exist;	//서브포켓몬 확인용 불값
	bool _issubpkm5exist;	//서브포켓몬 확인용 불값
	
public:
	possessionPokemon();
	~possessionPokemon();

	HRESULT init();
	void release();
	void update();
	void render();

	void pPokemonDataSet();
};

