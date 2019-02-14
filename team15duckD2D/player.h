#pragma once
#include <unordered_map>
#include "item.h"
#include "pokemon.h"
#include <list>

#define PLAYER_SPEED 150.0f

class mapData;
class player
{
public:
	enum PLAYER_STATE
	{
		PS_IDLE_LEFT,			PS_IDLE_UP,				PS_IDLE_RIGHT,				PS_IDLE_DOWN,			//서있음				
		PS_MOVE_LEFT,			PS_MOVE_UP,				PS_MOVE_RIGHT,				PS_MOVE_DOWN,			//이동
		PS_FASTMOVE_LEFT,		PS_FASTMOVE_UP,			PS_FASTMOVE_RIGHT,			PS_FASTMOVE_DOWN,		//빨리이동
		PS_BICYCLE_IDLE_LEFT,	PS_BICYCLE_IDLE_UP,		PS_BICYCLE_IDLE_RIGHT,		PS_BICYCLE_IDLE_DOWN,	//자전거가만히
		PS_BICYCLE_LEFT,		PS_BICYCLE_UP,			PS_BICYCLE_RIGHT,			PS_BICYCLE_DOWN,		//자전거
		PS_JUMP_LEFT,			PS_JUMP_RIGHT,			PS_JUMP_DOWN										//점프
	};

	typedef unordered_map<ITEM_TYPE,UINT>				mapItemList;
	typedef unordered_map<ITEM_TYPE,UINT>::iterator		mapItemIter;

private:
	string				_name;									//이름
	bool				_isMan;									//남자니?
	float				_playTime;								//플레이타임
	float				_posX;									//좌표
	float				_posY;									//좌표
	float				_posZ;									//Z축 ============= 점프하기위함
	UINT				_tileX;									//현재 위치하고 있는 타일 번호
	UINT				_tileY;									//현재 위치하고 있는 타일 번호
	PLAYER_STATE		_state;									//스테이트
	mapItemList			_mItemList;								//아이템을 담고 있는 셋
	pokemon*			_pokemon[6];							//포켓몬ㅋ
	UINT				_currentPokemon;						//현재 소지하고 있는 마릿수

	list<pokemon*>		_bankPokemonList;						//이자식도 저장해야됨 ㅂㄷㅂㄷ
	


	animation*			_playerAni;								//플레이어 애니
	string				_key;									//키값
	float				_moveDistance;							//이동할거리 ㅎㅎ
	bool				_isRight;								//오른쪽보니?
	bool				_isBicycle;								//자전거탈거?
	bool				_isFaseMove;							//빨리갈거?



	mapData*			_map;									//이거슨 맵데이터?!
public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	//얘는 맵에 끼워넣어서 그려야함
	void render();	

	void dataLoad();
private:
	//내부함수
	void aniSetUp();
	

	void keyUpdate();
	void stateUpdate();





	void aniSetStart(string aniKeyName);


public:
	//겟셋

	float getPosX() { return _posX; }
	float getPosY() { return _posY; }

	UINT getTileX() { return _tileX; }
	UINT getTileY() { return _tileY; }
	
	string getName() { return _name; }
	bool getIsMan() { return _isMan; }

	mapItemList getItem() { return _mItemList; }
	pokemon** getPokemon() { return _pokemon; }

	void setMapDataMemoryAdressLink(mapData* map) { _map = map; }
};

