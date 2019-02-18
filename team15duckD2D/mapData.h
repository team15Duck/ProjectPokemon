#pragma once
#include <vector>
#include "tileNode.h"
#include "pokemon.h"
#include "npc.h"

#define POTAL_NUM 6





//�ʵ��� �̰� ��ӹ޾Ƽ� �����.
class mapData
{
public:
	struct potalInfo
	{
		UINT x;
		UINT y;
		string nextScene;
		UINT nextX;
		UINT nextY;
		int nextDirection;
		// left = 0; top = 1; right = 2; down = 3;
	};
	struct savedPotalPos
	{
		string x;
		string y;
	};


protected:
	UINT						TILEX;							//Ÿ�ϰ��ΰ���
	UINT						TILEY;							//Ÿ�ϼ��ΰ���
	vector<vector<tagTile*>>	_vvTile;						//Ÿ���� ��� �ִ� ����
	player*						_player;						//�÷��̾ ����Ű�� �ִ� �����ͺ���

	vector<POKEMON>				_pokemon;						//�����ϴ� ���ϸ��� ����
	UINT						_maxLevel;						//�����ϴ� ���ϸ��� ���� ����
	UINT						_minLevel;						//�����ϴ� ���ϸ��� ���� ����

	vector<potalInfo>			_potal;

	UINT						ii;								//������ for���� �� ���� ���� �̳༮���� ������ �ش�.
	UINT						iiMax;							//������ for���� �� ���� ���� �̳༮���� ������ �ش�.
	UINT						jj;								//������ for���� �� ���� ���� �̳༮���� ������ �ش�.
	UINT						jjMax;							//������ for���� �� ���� ���� �̳༮���� ������ �ش�.

	npc*						_npc;
	int							_count;							//�����ӿ�

public:
	mapData();
	~mapData();
	
	virtual HRESULT init(const char* mapSizeFileName, const char* mapFileName, const char* mapPotalName);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void load(const char* mapSizeFileName, const char* mapFileName, const char* mapPotalName);

	virtual void potalLoad(const char* mapPotalName);

	
	//������Ʈ ������ �Լ�
	virtual void drawObject();

	virtual void setPlayerMemoryAdressLink(player* p) { _player = p; }

	virtual void setPokemon();

	//=======================
	
	void imgObject() 
	{ 
		IMAGEMANAGER->findImage(OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex])->frameRender(jj*TILE_SIZE, ii*TILE_SIZE, 0, 0, 64, 64, _vvTile[ii][jj]->objectFrameX, _vvTile[ii][jj]->objectFrameY, 1); 
	}


public:
	//�ټ�
	tagTile* getTile(UINT x, UINT y) { return _vvTile[y][x]; }

	inline POKEMON getPokemon()
	{
		return _pokemon[RND->getInt((int)_pokemon.size())];
	}
	inline UINT getLevel()
	{
		return (UINT)RND->getFromIntTo(_minLevel, _maxLevel + 1);
	}
	
};

