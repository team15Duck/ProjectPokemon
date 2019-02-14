#pragma once
#include <vector>
#include "tileNode.h"
#include "pokemon.h"





//�ʵ��� �̰� ��ӹ޾Ƽ� �����.
class mapData
{
protected:
	UINT						TILEX;							//Ÿ�ϰ��ΰ���
	UINT						TILEY;							//Ÿ�ϼ��ΰ���
	vector<vector<tagTile*>>	_vvTile;						//Ÿ���� ��� �ִ� ����
	player*						_player;						//�÷��̾ ����Ű�� �ִ� �����ͺ���

	vector<POKEMON>				_pokemon;						//�����ϴ� ���ϸ��� ����
	UINT						_maxLevel;						//�����ϴ� ���ϸ��� ���� ����
	UINT						_minLevel;						//�����ϴ� ���ϸ��� ���� ����



	UINT						ii;								//������ for���� �� ���� ���� �̳༮���� ������ �ش�.
	UINT						iiMax;							//������ for���� �� ���� ���� �̳༮���� ������ �ش�.
	UINT						jj;								//������ for���� �� ���� ���� �̳༮���� ������ �ش�.
	UINT						jjMax;							//������ for���� �� ���� ���� �̳༮���� ������ �ش�.
public:
	mapData();
	~mapData();
	
	virtual HRESULT init(const char* mapSizeFileName, const char* mapFileName);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void load(const char* mapSizeFileName, const char* mapFileName);

	virtual void setPlayerMemoryAdressLink(player* p) { _player = p; }

	virtual void setPokemon() = 0;



public:
	//�ټ�
	tagTile* getTile(UINT x, UINT y) { return _vvTile[y][x]; }

	inline POKEMON getPokemon()
	{
		return _pokemon[RND->getInt(_pokemon.size())];
	}
	inline UINT getLevel()
	{
		return (UINT)RND->getFromIntTo(_minLevel, _maxLevel + 1);
	}
};

