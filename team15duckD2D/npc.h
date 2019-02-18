#pragma once
#include "player.h"

enum NPC_TYPE
{
	NPC_TYPE_OAK,										  //���ڻ�
	NPC_TYPE_SHOPOWNER,									  //��������
	NPC_TYPE_NURSE,										  //��ȣ��
		
	NPC_TYPE_NONE,
	NPC_TYPE_COUNT = NPC_TYPE_NONE
};

enum NPC_ACTIVE_WAY
{
	NPC_ACTIVE_WAY_OAK_DOWN,								//���ڻ�(�Ʒ���)
	NPC_ACTIVE_WAY_OAK_RIGHT,								//���ڻ�(������)
	NPC_ACTIVE_WAY_OAK_LEFT,								//���ڻ�(����)	
	NPC_ACTIVE_WAY_OAK_UP,									//���ڻ�(����)
										
	NPC_ACTIVE_WAY_SHOPOWNER_DOWN,							//��������(�Ʒ���)
	NPC_ACTIVE_WAY_SHOPOWNER_RIGHT,							//��������(������)
										
	NPC_ACTIVE_WAY_NURSE_DOWN,								//��ȣ��(�Ʒ���)
	NPC_ACTIVE_WAY_NURSE_LEFT,								//��ȣ��(����)

	NPC_ACTIVE_WAY_NONE,
	NPC_ACTIVE_WAY_COUNT = NPC_ACTIVE_WAY_NONE
};


class npc
{
private:

	//���� �켱 ���ͷ� �־��.


	string			_sceneName;						//������ ���̸�
	string			_npcName;						//npc�̸�(Ű����)
	NPC_TYPE		_npcType;						//npc����
	NPC_ACTIVE_WAY	_npcActive;						//�÷��̾ npc���� ���ɾ����� ����

	UINT			_tileX;							//��ġ
	UINT			_tileY;							//��ġ

	bool			_isTalk;						//���ɾ�����?
	bool			_isPrologue;					//���ڻ�� ù �����̴�?
	bool			_isReverse;						//�������ο� �¿�����ߴ�?

	animation*		_motion;						//�������� �ִϸ��̼�
	int				_test;

	player::PLAYER_STATE	_state;
	player*					_player;

public:
	npc();
	~npc();

	HRESULT init(NPC_TYPE type);
	void release();
	void update();
	void render();

	void activeDialog();							//NPC��缳��
	void activeWay();								//NPC���⼳��
	
	void setPlayerState(player::PLAYER_STATE state) { _state = state; }

	UINT getTileX() { return _tileX; }
	UINT getTileY() { return _tileY; }
};

