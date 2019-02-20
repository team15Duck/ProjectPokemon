#pragma once
class trainerNPC
{
private:

	image* _img;

	string _name;

	pokemon _pokemons[6];
	bool	_isBeat;			// �÷��̾ ��Ʋ���� �̰���°�
	int		_prizeGold;			// �÷��̾ ��Ʋ���� �̰��� �� ���� �� �ִ� ���

	int		_pokemonCnt;		// �����ϰ��ִ� ���ϸ��� ��

	int		_enterPokemon;		// �������� ���ϸ� ���� ��ȣ

public:
	trainerNPC();
	~trainerNPC();

	// �̹��� �̸�, npc �̸�, ���
	HRESULT init(string imgName, string name, int prizeGold);
	void release();
	void render();
	void update();

	// npc ���� ���ϸ�
	void pushbackPokemon(pokemon pm);

	// �÷��̾�� ��⿡�� ��
	void loseBattle();
	// �÷��̾�� ��⿡�� �̱�
	void winBattle();

	// ���ϸ��� �ٲܰ��ΰ�
	bool isChangePokemon();
	// ���ϸ� ��ü
	void changePokemon();
	// ���ϸ� ��ü �����Ѱ�
	bool isPossibleChangePokemon();

	// �÷��̾�� �̰���� ������ ����
	void setBeat(bool isBeat) { _isBeat = isBeat; }
	// �÷��̾ �� npc�� �������� �̰���°�
	bool isBeat() { return _isBeat; }

	// npc �̸�
	string getName() { return _name; }
	// npc���� ����ִ� ���ϸ�
	pokemon* getPokemons() { return _pokemons; }
	// ���
	int getPrizeGold() { return _prizeGold; }
	// �����ϰ� �ִ� ���ϸ� ��
	int getPokemonCount() { return _pokemonCnt; }
	// ������ ������ ���ϸ� ���� ��ȣ
	int getEnterPokemonSlotIndex() { return _enterPokemon; }
};