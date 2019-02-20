#pragma once
class trainerNPC
{
private:

	image* _img;

	string _name;

	pokemon _pokemons[6];
	bool	_isBeat;			// 플레이어가 배틀에서 이겼었는가
	int		_prizeGold;			// 플레이어가 배틀에서 이겼을 때 얻을 수 있는 상금

	int		_pokemonCnt;		// 소유하고있는 포켓몬의 수

	int		_enterPokemon;		// 출전중인 포켓몬 슬롯 번호

public:
	trainerNPC();
	~trainerNPC();

	// 이미지 이름, npc 이름, 상금
	HRESULT init(string imgName, string name, int prizeGold);
	void release();
	void render();
	void update();

	// npc 소유 포켓몬
	void pushbackPokemon(pokemon pm);

	// 플레이어와 경기에서 짐
	void loseBattle();
	// 플레이어와 경기에서 이김
	void winBattle();

	// 포켓몬을 바꿀것인가
	bool isChangePokemon();
	// 포켓몬 교체
	void changePokemon();
	// 포켓몬 교체 가능한가
	bool isPossibleChangePokemon();

	// 플레이어에게 이겼는지 젔는지 세팅
	void setBeat(bool isBeat) { _isBeat = isBeat; }
	// 플레이어가 이 npc와 전투에서 이겼었는가
	bool isBeat() { return _isBeat; }

	// npc 이름
	string getName() { return _name; }
	// npc들이 들고있는 포켓몬
	pokemon* getPokemons() { return _pokemons; }
	// 상금
	int getPrizeGold() { return _prizeGold; }
	// 소유하고 있는 포켓몬 수
	int getPokemonCount() { return _pokemonCnt; }
	// 전투에 참여할 포켓몬 슬롯 번호
	int getEnterPokemonSlotIndex() { return _enterPokemon; }
};