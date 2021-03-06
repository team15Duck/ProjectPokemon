#pragma once
#include <unordered_map>
#include "item.h"
#include "pokemon.h"
#include <list>

#define PLAYER_SPEED 250.0f
#define JUMP_POWER 350.0f
#define GRAVITY 1450.0f


#define ANI_SPEED 14


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
		PS_JUMP_LEFT,			PS_JUMP_RIGHT,			PS_JUMP_DOWN,										//점프
		PS_FISHING_LEFT,		PS_FISHING_UP,			PS_FISHING_RIGHT,			PS_FISHING_DOWN			//낚씨
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

	float				_jumpPower;								//점프파워
	float				_gravity;								//그래비티

	mapData*			_map;									//이거슨 맵데이터?!

	string				_currentSceneName;						//현재 위치한 씬의 이름


	float				_currentFishingTime;					//낚시한시간
	float				_maxFishingTime;						//낚시할시간

	UINT				_money;

	bool				_isShopOn;

	D2D1_RECT_F _rc[9];
	int _count;
	bool _start;
	float _angle[9];
	float _scale;
	D2D1_RECT_F _rc2;
	bool _boss;

public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	//얘는 맵에 끼워넣어서 그려야함
	void render();	
	void shadowRender();
	void rectSet();
	void dataLoad();
	void rectRender();
	void aniSetUp();
private:
	//내부함수
	

	void keyUpdate();
	void stateUpdate();




	void horizonSet();
	void verticalSet();
	void aniSetStart(string aniKeyName);
	void appearTileCheck();
	void potalCheck();

public:
	//겟셋
	void setKey();

	float getPosX() { return _posX; }
	float getPosY() { return _posY; }

	void setPos();

	UINT getTileX() { return _tileX; }
	void setTileX(int x) { _tileX = x; }
	UINT getTileY() { return _tileY; }
	void setTileY(int y) { _tileY = y; }
	
	string getName() { return _name; }
	void setName(string name) { _name = name; }
	bool getIsMan() { return _isMan; }
	void setIsMan(bool isMan)
	{ 
		_isMan = isMan; 
		if (isMan)
			_key = "playerM";
		else
			_key = "playerF";
	}

	mapItemList getItem() { return _mItemList; }
	//mapItemList getItemAmount() { return _mItemList.size; }
	pokemon** getPokemon() { return _pokemon; }
	pokemon* getPokemonArray(int num) { return _pokemon[num]; }
	void setPokemonArray(int num, pokemon* pokemon) { _pokemon[num] = pokemon; }
	void pushItem(ITEM_TYPE type, int num)
	{

		_mItemList.insert(make_pair(type, num));
	}

	UINT	getCurrentPokemonCnt() { return _currentPokemon; }
	void	setCurrentPokemonCnt(int num) { _currentPokemon = num; }


	void setMapDataMemoryAdressLink(mapData* map) { _map = map; }


	void fishingStart();

	string getSceneName() { return _currentSceneName; }
	void setSceneName(string name) { _currentSceneName = name; }

	float getPlayTime() { return _playTime; }
	void setPlayTime(float time) { _playTime = time; }
	UINT getMoney() { return _money; }
	void setMoney(int money) { _money = money; }

	PLAYER_STATE getState() { return _state; }


	bool getShopOn() { return _isShopOn; }
	void setShopOn(bool shopOn) { _isShopOn = shopOn; }
};

