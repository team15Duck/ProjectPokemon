#pragma once
#include <vector>
#include "tileNode.h"
#include "pokemon.h"
#include "npc.h"

#define POTAL_NUM 6





//맵들은 이거 상속받아서 사용함.
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
	struct tagFieldItem
	{
		UINT x;												//필드아이템 위치
		UINT y;												//필드아이템 위치
		ITEM_TYPE itemType;									//아이템타입
		bool isEat;											//먹었는지?
	};
	struct tagStartingMon
	{
		UINT x;												//위치
		UINT y;												//위치
		POKEMON pokemon;									//포켓몬종류
	};


protected:
	UINT						TILEX;							//타일가로갯수
	UINT						TILEY;							//타일세로갯수
	vector<vector<tagTile*>>	_vvTile;						//타일을 담고 있는 벡터
	player*						_player;						//플레이어를 가르키고 있는 포인터변수

	vector<POKEMON>				_pokemon;						//출현하는 포켓몬의 종류
	UINT						_maxLevel;						//출현하는 포켓몬의 레벨 범위
	UINT						_minLevel;						//출현하는 포켓몬의 레벨 범위

	vector<potalInfo>			_potal;
	vector<tagFieldItem>		_fieldItems;					//필드아이템
	vector<tagStartingMon>		_startingMonster;				//스타팅몬스터

	UINT						ii;								//렌더시 for문을 덜 돌기 위해 이녀석들을 세팅해 준다.
	UINT						iiMax;							//렌더시 for문을 덜 돌기 위해 이녀석들을 세팅해 준다.
	UINT						jj;								//렌더시 for문을 덜 돌기 위해 이녀석들을 세팅해 준다.
	UINT						jjMax;							//렌더시 for문을 덜 돌기 위해 이녀석들을 세팅해 준다.

	int							_count;							//프레임용
	vector<npc*>				_npc;		
public:
	mapData();
	~mapData();
	
	virtual HRESULT init(const char* mapSizeFileName, const char* mapFileName);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void load(const char* mapSizeFileName, const char* mapFileName);

	virtual void potalLoad();

	virtual void fieldItemLoad();
	virtual void monsterLoad();

	
	//오브젝트 렌더용 함수
	virtual void drawObject();

	virtual void setPlayerMemoryAdressLink(player* p) { _player = p; }

	virtual void setPokemon();

	//=======================
	
	void imgObject() 
	{ 
		IMAGEMANAGER->findImage(OBJECT_NAME[_vvTile[ii][jj]->objectImageIndex])->frameRender(jj*TILE_SIZE, ii*TILE_SIZE, 0, 0, 64, 64, _vvTile[ii][jj]->objectFrameX, _vvTile[ii][jj]->objectFrameY, 1); 
	}


public:
	//겟셋
	tagTile* getTile(UINT x, UINT y) { return _vvTile[y][x]; }

	inline POKEMON getPokemon()
	{
		return _pokemon[RND->getInt((int)_pokemon.size())];
	}
	inline UINT getLevel()
	{
		return (UINT)RND->getFromIntTo(_minLevel, _maxLevel + 1);
	}

	void pushNpc(npc* npc) { _npc.push_back(npc); }
	

	vector<potalInfo> getPotal() { return _potal; }
	vector<tagFieldItem> getFieldItems() { return _fieldItems; }
	void erase(int num) { _fieldItems.erase(_fieldItems.begin() + num); }
	
};

