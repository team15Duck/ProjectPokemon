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

	int _pokemonCnt; // �����ϰ� �ִ� ���ϸ��� ��

	UINT _currentSelecPok;

	bool _isMainpokemon;	//�������ϸ��̳�?

	bool _isSubpokemon;		//���� ���ϸ��� �ֳ�?

	bool _issubpkm1exist;	//�������ϸ� Ȯ�ο� �Ұ�
	bool _issubpkm2exist;	//�������ϸ� Ȯ�ο� �Ұ�
	bool _issubpkm3exist;	//�������ϸ� Ȯ�ο� �Ұ�
	bool _issubpkm4exist;	//�������ϸ� Ȯ�ο� �Ұ�
	bool _issubpkm5exist;	//�������ϸ� Ȯ�ο� �Ұ�
	
public:
	possessionPokemon();
	~possessionPokemon();

	HRESULT init();
	void release();
	void update();
	void render();

	void pPokemonDataSet();
};

