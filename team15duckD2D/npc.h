#pragma once

enum NPC_TYPE
{
	NPC_TYPE_OAK,										  //���ڻ�
	NPC_TYPE_SHOPOWNER,									  //��������
	NPC_TYPE_NURSE,										  //��ȣ��
		
	NPC_TYPE_NONE,
	NPC_TYPE_COUNT = NPC_TYPE_NONE
};

enum NPC_ACTIVE
{
	NPC_ACTIVE_OAK_LEFT,									//���ڻ�(����)
	NPC_ACTIVE_OAK_RIGHT,									//���ڻ�(������)
	NPC_ACTIVE_OAK_UP,										//���ڻ�(����)
	NPC_ACTIVE_OAK_DOWN,									//���ڻ�(�Ʒ���)
															
	NPC_ACTIVE_SHOPOWNER_RIGHT,								//��������(������)
	NPC_ACTIVE_SHOPOWNER_DOWN,								//��������(�Ʒ���)
															
	NPC_ACTIVE_NURSE_LEFT,									//��ȣ��(����)
	NPC_ACTIVE_NURSE_DOWN,									//��ȣ��(�Ʒ���)
	
	NPC_ACTIVE_NONE,
	NPC_ACTIVE_COUNT = NPC_ACTIVE_NONE
};


class npc
{
private:

	//���� �켱 ���ͷ� �־��.


	string		_sceneName;						//������ ���̸�
	string		_npcName;						//npc�̸�(Ű����)
	NPC_TYPE	_npcType;						//npc����
	NPC_ACTIVE	_npcActive;						//�÷��̾ npc���� ���ɾ����� ����



	UINT		_tileX;							//��ġ
	UINT		_tileY;							//��ġ



public:
	npc();
	~npc();

	HRESULT init(string sceneName);
	void release();
	void update();
	void render();

	void settingNPC();
};

