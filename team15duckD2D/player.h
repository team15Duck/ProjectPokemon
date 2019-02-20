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
		PS_IDLE_LEFT,			PS_IDLE_UP,				PS_IDLE_RIGHT,				PS_IDLE_DOWN,			//������				
		PS_MOVE_LEFT,			PS_MOVE_UP,				PS_MOVE_RIGHT,				PS_MOVE_DOWN,			//�̵�
		PS_FASTMOVE_LEFT,		PS_FASTMOVE_UP,			PS_FASTMOVE_RIGHT,			PS_FASTMOVE_DOWN,		//�����̵�
		PS_BICYCLE_IDLE_LEFT,	PS_BICYCLE_IDLE_UP,		PS_BICYCLE_IDLE_RIGHT,		PS_BICYCLE_IDLE_DOWN,	//�����Ű�����
		PS_BICYCLE_LEFT,		PS_BICYCLE_UP,			PS_BICYCLE_RIGHT,			PS_BICYCLE_DOWN,		//������
		PS_JUMP_LEFT,			PS_JUMP_RIGHT,			PS_JUMP_DOWN,										//����
		PS_FISHING_LEFT,		PS_FISHING_UP,			PS_FISHING_RIGHT,			PS_FISHING_DOWN			//����
	};

	typedef unordered_map<ITEM_TYPE,UINT>				mapItemList;
	typedef unordered_map<ITEM_TYPE,UINT>::iterator		mapItemIter;

private:
	string				_name;									//�̸�
	bool				_isMan;									//���ڴ�?
	float				_playTime;								//�÷���Ÿ��
	float				_posX;									//��ǥ
	float				_posY;									//��ǥ
	float				_posZ;									//Z�� ============= �����ϱ�����
	UINT				_tileX;									//���� ��ġ�ϰ� �ִ� Ÿ�� ��ȣ
	UINT				_tileY;									//���� ��ġ�ϰ� �ִ� Ÿ�� ��ȣ
	PLAYER_STATE		_state;									//������Ʈ
	mapItemList			_mItemList;								//�������� ��� �ִ� ��
	pokemon*			_pokemon[6];							//���ϸ�
	UINT				_currentPokemon;						//���� �����ϰ� �ִ� ������

	list<pokemon*>		_bankPokemonList;						//���ڽĵ� �����ؾߵ� ��������
	


	animation*			_playerAni;								//�÷��̾� �ִ�
	string				_key;									//Ű��
	float				_moveDistance;							//�̵��ҰŸ� ����
	bool				_isRight;								//�����ʺ���?
	bool				_isBicycle;								//������Ż��?
	bool				_isFaseMove;							//��������?

	float				_jumpPower;								//�����Ŀ�
	float				_gravity;								//�׷���Ƽ

	mapData*			_map;									//�̰Ž� �ʵ�����?!

	string				_currentSceneName;						//���� ��ġ�� ���� �̸�


	float				_currentFishingTime;					//�����ѽð�
	float				_maxFishingTime;						//�����ҽð�

	UINT				_money;


public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	//��� �ʿ� �����־ �׷�����
	void render();	
	void shadowRender();

	void dataLoad();
private:
	//�����Լ�
	void aniSetUp();
	

	void keyUpdate();
	void stateUpdate();




	void horizonSet();
	void verticalSet();
	void aniSetStart(string aniKeyName);
	void appearTileCheck();
	void potalCheck();

public:
	//�ټ�

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
	void setIsMan(bool isMan) { _isMan = isMan; }

	mapItemList getItem() { return _mItemList; }
	//mapItemList getItemAmount() { return _mItemList.size; }
	pokemon** getPokemon() { return _pokemon; }
	pokemon* getPokemonArray(int num) { return _pokemon[num]; }
	void setPokemonArray(int num, pokemon* pokemon) { _pokemon[num] = pokemon; }


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




};

