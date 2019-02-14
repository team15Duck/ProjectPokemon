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
		PS_IDLE_LEFT,			PS_IDLE_UP,				PS_IDLE_RIGHT,				PS_IDLE_DOWN,			//������				
		PS_MOVE_LEFT,			PS_MOVE_UP,				PS_MOVE_RIGHT,				PS_MOVE_DOWN,			//�̵�
		PS_FASTMOVE_LEFT,		PS_FASTMOVE_UP,			PS_FASTMOVE_RIGHT,			PS_FASTMOVE_DOWN,		//�����̵�
		PS_BICYCLE_IDLE_LEFT,	PS_BICYCLE_IDLE_UP,		PS_BICYCLE_IDLE_RIGHT,		PS_BICYCLE_IDLE_DOWN,	//�����Ű�����
		PS_BICYCLE_LEFT,		PS_BICYCLE_UP,			PS_BICYCLE_RIGHT,			PS_BICYCLE_DOWN,		//������
		PS_JUMP_LEFT,			PS_JUMP_RIGHT,			PS_JUMP_DOWN										//����
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



	mapData*			_map;									//�̰Ž� �ʵ�����?!
public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	//��� �ʿ� �����־ �׷�����
	void render();	

	void dataLoad();
private:
	//�����Լ�
	void aniSetUp();
	

	void keyUpdate();
	void stateUpdate();





	void aniSetStart(string aniKeyName);


public:
	//�ټ�

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

