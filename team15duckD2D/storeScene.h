#pragma once
#include "storeMap.h"
#include "gameNode.h"
#include "npc.h"
#include "shop.h"

enum SHOP_TALK
{
	//�λ�
	SHOP_TALK_HELLO,
	SHOP_TALK_BUY_UI,
	//1. �緯�Դ�
	SHOP_TALK_BUY_CHOICE,						//�������� ����������
	SHOP_TALK_BUY,								//�������� ��������
	SHOP_TALK_BUY_SURE,							//������
	
	//2. �ȷ��Դ�
	SHOP_TALK_SELL_CHOICE,						//�������� ����������
	SHOP_TALK_SELL,								//�������� ��������
	SHOP_TALK_SELL_SURE,						//�Ǹ���
	
	//3. �ƴմϴ�
	SHOP_TALK_NOPE_OR_BYE,						//������

	//4. ������ư
	SHOP_TALK_CANCEL,							//1. �緯�Դ� / 2. �ȷ��Դٿ���
												//������ư ��������
	SHOP_TALK_NONE,
	SHOP_TALK_COUNT = SHOP_TALK_NONE
};


class storeScene : public gameNode
{
private:
	mapData*	_storeMap;						//������
	npc*		_npc;							//NPC
	shop*		_shop;

	float		_curPointY;						//����â������ ȭ��ǥ Y��ġ
	
	bool		_isTalk;						//NPC�� ����ϴ�
	bool		_isChoice;						//�緯�Դ� �ȷ��Դ� ���Ϸ��Դ�
	bool		_isBuy;							//�緯�Դ�?(������UI)
	bool		_isSure;						//�����?
	
	SHOP_TALK	_shopTalk;						//����

public:
	storeScene();
	~storeScene();

	HRESULT init();
	void release();
	void update();
	void render();

	//�������� ��ȭ ������
	void activeShopOwner();


	//1. �緯�Դ�
	void buyItemChoice();						//������ �������� �����ϰ� ���� �����
	void buyItem();								//��� ������, �� �� �� ���̸� �� ���̴�.
	void buyItemSure();							//������ Ȯ���Ǿ�����


	//2. �ȷ��Դ�.
	void sellItemChoice();						//�Ǹ��� �������� �����ϰ� ���� �����
	void sellItem();							//�Ĵ� ������, �� �� �� ���̸� �� ���̴�.
	void sellItemSure();						//�ǸŰ� Ȯ���Ǿ�����

	
	//3. ������ư (X��ư ��������)
	void menuBack();
	
	//4. �ƴմϴ�
	void nopeTalk();

};

