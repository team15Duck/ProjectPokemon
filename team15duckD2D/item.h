#pragma once
#include "gameNode.h"

enum ITEM_TYPE
{
	//���ϸ��� ���� ü���� 30�� �̸��̸� ������ ������
	//�� �̻��̸� ���ϸ��� ��ȹ���� ���� ������.
	MONSTER_BALL,			//���ͺ�
	SUPER_BALL,				//���ۺ�
	HYPER_BALL,				//�����ۺ�
	MASTER_BALL,			//�����ͺ�
						   
	NORMAL_POTION,			//��ó��(20ȸ��)
	SUPER_POTION,			//������ó��(60ȸ��)
	HYPER_POTION,			//��޻�ó��(120ȸ��)
	MAX_POTION,				//Ǯȸ����(��üȸ��)
	FULL_RESTORE,			//ȸ����(��üȸ��+�����̻�)

	NORMAL_ETHER,			//PPȸ��(�ѱ�� 10ȸ��)
	MAX_ETHER,				//ppȸ��(�ѱ�� ��üȸ��)
	NORMAL_ELIXIR,			//ppȸ��(����� 10ȸ��)
	MAX_ELIXIR,				//ppȸ��(����� ��üȸ��)

	ANTIDOTE,				//�ص���
	PARLYZE_HEAL,			//�����ص���
	BURN_HEAL,				//ȭ��ġ����
	ICE_HEAL,				//����ġ����
	AWAKENING,				//����¾�
	FULL_HEAL,				//��ü�����̻�				

	
	RARE_CANDY,				//�̻���ĵ��
	BICYCLE,				//������
	FISHING_ROD,			//���ô�
	TOWN_MAP,				//Ÿ���
	TM_CASE					//����ӽ����̽�


};


class item : public gameNode
{
private:
	
	image*		_img;			//�̹���
	RECT		_rc;			//��Ʈ
	string		_itemName;		//�������̸�
	ITEM_TYPE	_itemType;		//����
	int			_itemValue;		//���������밪(ȸ����, ppȸ����, ��ȹ�� ��)
	int			_itemNum;		//����
	int			_frameNum;		//�����ӹ�ȣ


public:
	item();
	~item();

	HRESULT init();
	HRESULT init(int value, ITEM_TYPE type);
	void release();
	void update();
	void render();
	
	void initImg();



	// ========== GET & SET ==========
	string getItemName() { return _itemName; }
	void setItemName(string name) { _itemName = name; }

	ITEM_TYPE getItemType() { return _itemType; }
	void setItemType(ITEM_TYPE type) { _itemType = type; }

	int getItemValue() { return _itemValue; }
	void setItemValue(int value) { _itemValue = value; }

	int getItemNum() { return _itemNum; }
	void setItemNum(int num) { _itemNum = num; }
};

