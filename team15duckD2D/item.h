#pragma once

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
	FULL_HEAL,				//������ġ��				

	RARE_CANDY,				//�̻��ѻ���
	ESCAPE_ROPE,			//����Ż�����
	REVIVE,					//����� ����
	BICYCLE,				//������
	FISHING_ROD,			//���ô�
	TOWN_MAP,				//Ÿ���
	TM_CASE,				//����ӽ����̽�

	ITEM_TYPE_NONE,

	ITEM_TYPE_COUNT = ITEM_TYPE_NONE

};


class item
{
private:
	
	image*					_img;			//�̹���
	RECT					_rc;			//��Ʈ
	string					_itemName;		//�������̸�
	ITEM_TYPE				_itemType;		//����
	unsigned int			_itemValue;		//���������밪(ȸ����, ppȸ����, ��ȹ�� ��)
	unsigned int			_itemNum;		//����
	unsigned int			_buyPrice;		//���԰���
	unsigned int			_sellPrice;		//�ǸŰ���
	POINTF					_rcPos;			//��ġ
	POINTF					_imgPos;		//�̹�����ġ
	POINT					_imgSize;		//�̹���ũ��



public:
	item();
	~item();

	HRESULT init();
	//�̴ϴϴϴ�(    ���� , ���밪, ���԰���, �ǸŰ���, ����)
	HRESULT init(string name, ITEM_TYPE type, int value, int buyPrice, int sellPrice, int num);
	void release();
	void update();
	void render();



	// ========== GET & SET ==========
	string getItemName() { return _itemName; }
	ITEM_TYPE getItemType() { return _itemType; }
	int getItemValue() { return _itemValue; }
	int getItemNum() { return _itemNum; }
	int getBuyPrice() { return _buyPrice; }
	int getSellPrice() { return _sellPrice; }
};

