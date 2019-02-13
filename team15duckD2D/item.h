#pragma once
#include "pokemonInfo.h"

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

	//�߿��� ����
	BICYCLE,				//������
	FISHING_ROD,			//���ô�
	TOWN_MAP,				//Ÿ���
	TM_CASE,				//����ӽ����̽�

	//�����ӽ�(������ ��밡��)
	HM_CUT,					//Ǯ����
	HM_FLASH,				//�÷���

	//����ӽ�(�ѹ��� ��밡��)
	TM_THUNDERBOLT,			//10����Ʈ
	TM_THUNDER,				//����
	TM_FLAMETHROWER,		//ȭ�����

	ITEM_TYPE_NONE,

	ITEM_TYPE_COUNT = ITEM_TYPE_NONE

};

enum ITEM_VALUE
{
	//�ִ�����ġ�� 999, �߿��ѹ��ǿ����� �� ������ ���� 255
	MONSTER_BALL_VALUE = 3,											//���ͺ�
	SUPER_BALL_VALUE = 4,											//���ۺ�
	HYPER_BALL_VALUE = 5,											//�����ۺ�
	MASTER_BALL_VALUE = 10,											//�����ͺ�

	NORMAL_POTION_VALUE = 20,										//��ó��(20ȸ��)
	SUPER_POTION_VALUE = 50,										//������ó��(60ȸ��)
	HYPER_POTION_VALUE = 120,										//��޻�ó��(120ȸ��)
	MAX_POTION_VALUE = 999,											//Ǯȸ����(��üȸ��)
	FULL_RESTORE_VALUE = 999,										//ȸ����(��üȸ��+�����̻�)

	NORMAL_ETHER_VALUE = 10,										//PPȸ��(�ѱ�� 10ȸ��)
	MAX_ETHER_VALUE = 999,											//ppȸ��(�ѱ�� ��üȸ��)
	NORMAL_ELIXIR_VALUE = 10,										//ppȸ��(����� 10ȸ��)
	MAX_ELIXIR_VALUE = 999,											//ppȸ��(����� ��üȸ��)

	ANTIDOTE_VALUE = POKEMON_UPSET_CONDITION::PMUC_POISON,			//�ص���
	PARLYZE_HEAL_VALUE = POKEMON_UPSET_CONDITION::PMUC_PALALYSIS,	//�����ص���
	BURN_HEAL_VALUE = POKEMON_UPSET_CONDITION::PMUC_BURN,			//ȭ��ġ����
	ICE_HEAL_VALUE = 999,											//����ġ����
	AWAKENING_VALUE = POKEMON_UPSET_CONDITION::PMUC_SLEEP,			//����¾�
	FULL_HEAL_VALUE = 999,											//������ġ��				

	RARE_CANDY_VALUE = 1,											//�̻��ѻ���
	ESCAPE_ROPE_VALUE = 1,											//����Ż�����
	REVIVE_VALUE = 255,												//����� ����
	
	//�߿��� ����
	BICYCLE_VALUE = 2,												//������
	FISHING_ROD_VALUE = 255,										//���ô�
	TOWN_MAP_VALUE = 255,											//Ÿ���
	TM_CASE_VALUE = 255,
	

	HM_CUT_VALUE = 255,					
	HM_FLASH_VALUE = 255,				

	TM_THUNDERBOLT_VALUE = 255,			
	TM_THUNDER_VALUE = 255,				
	TM_FLAMETHROWER_VALUE = 255,		

	ITEM_VALUE_NONE,

	ITEM_VALUE_COUNT = ITEM_VALUE_NONE
};

enum ITEM_BUY_PRICE
{
	MONSTER_BALL_BUY_PRICE = 200,
	SUPER_BALL_BUY_PRICE = 600,
	HYPER_BALL_BUY_PRICE = 1200,
	MASTER_BALL_BUY_PRICE = 50000,

	NORMAL_POTION_BUY_PRICE = 300,
	SUPER_POTION_BUY_PRICE = 700,
	HYPER_POTION_BUY_PRICE = 1200,
	MAX_POTION_BUY_PRICE = 2500,
	FULL_RESTORE_BUY_PRICE = 3000,

	NORMAL_ETHER_BUY_PRICE = 0,
	MAX_ETHER_BUY_PRICE = 0,
	NORMAL_ELIXIR_BUY_PRICE = 0,
	MAX_ELIXIR_BUY_PRICE = 0,

	ANTIDOTE_BUY_PRICE = 100,
	PARLYZE_HEAL_BUY_PRICE = 200,
	BURN_HEAL_BUY_PRICE = 250,
	ICE_HEAL_BUY_PRICE = 250,
	AWAKENING_BUY_PRICE = 250,
	FULL_HEAL_BUY_PRICE = 600,

	RARE_CANDY_BUY_PRICE = 0,
	ESCAPE_ROPE_BUY_PRICE = 0,
	REVIVE_BUY_PRICE = 1500,
	BICYCLE_BUY_PRICE = 0,
	FISHING_ROD_BUY_PRICE = 0,
	TOWN_MAP_BUY_PRICE = 0,
	TM_CASE_BUY_PRICE = 0,

	HM_CUT_BUY_PRICE = 0,				
	HM_FLASH_BUY_PRICE = 0,

	TM_THUNDERBOLT_BUY_PRICE = 0,
	TM_THUNDER_BUY_PRICE = 0,
	TM_FLAMETHROWER_BUY_PRICE = 0,

	ITEM_BUY_PRICE_NONE,

	ITEM_BUY_PRICE_COUNT = ITEM_BUY_PRICE_NONE
};

enum ITEM_SELL_PRICE
{
	MONSTER_BALL_SELL_PRICE = 100,
	SUPER_BALL_SELL_PRICE = 300,
	HYPER_BALL_SELL_PRICE = 600,
	MASTER_BALL_SELL_PRICE = 25000,

	NORMAL_POTION_SELL_PRICE = 150,
	SUPER_POTION_SELL_PRICE = 350,
	HYPER_POTION_SELL_PRICE = 600,
	MAX_POTION_SELL_PRICE = 600,
	FULL_RESTORE_SELL_PRICE = 1500,

	NORMAL_ETHER_SELL_PRICE = 600,
	MAX_ETHER_SELL_PRICE = 1000,
	NORMAL_ELIXIR_SELL_PRICE = 1500,
	MAX_ELIXIR_SELL_PRICE = 2250,

	ANTIDOTE_SELL_PRICE = 50,
	PARLYZE_HEAL_SELL_PRICE = 100, 
	BURN_HEAL_SELL_PRICE = 125,
	ICE_HEAL_SELL_PRICE = 125,
	AWAKENING_SELL_PRICE = 125,
	FULL_HEAL_SELL_PRICE = 300,

	RARE_CANDY_SELL_PRICE = 2400,
	ESCAPE_ROPE_SELL_PRICE = 2400,
	REVIVE_SELL_PRICE = 750,
	BICYCLE_SELL_PRICE = 0,
	FISHING_ROD_SELL_PRICE = 0,
	TOWN_MAP_SELL_PRICE = 0,
	TM_CASE_SELL_PRICE = 0,

	HM_CUT_SELL_PRICE = 0,
	HM_FLASH_SELL_PRICE = 0,

	TM_THUNDERBOLT_SELL_PRICE = 0,
	TM_THUNDER_SELL_PRICE = 0,
	TM_FLAMETHROWER_SELL_PRICE = 0,

	ITEM_SELL_PRICE_NONE,

	ITEM_SELL_PRICE_COUNT = ITEM_SELL_PRICE_NONE
};

class item
{
private:
	
	image*					_img;			//�̹���
	RECT					_rc;			//��Ʈ
	string					_itemName;		//�������̸�
	string					_sceneName;		//�ʳ��� ��ġ�Ǿ��ִٸ� �������?
	UINT					_tileX;			//�ִٸ� ��� Ÿ�Ͽ�?
	UINT					_tileY;			//�ִٸ� ��� Ÿ�Ͽ�?

	ITEM_TYPE				_itemType;		//����
	ITEM_VALUE				_itemValue;		//���������밪(ȸ����, ppȸ����, ��ȹ�� ��)
	unsigned int			_itemNum;		//����
	ITEM_BUY_PRICE			_buyPrice;		//���԰���
	ITEM_SELL_PRICE			_sellPrice;		//�ǸŰ���
	POINTF					_rcPos;			//��ġ
	POINTF					_imgPos;		//�̹�����ġ
	POINT					_imgSize;		//�̹���ũ��


public:
	item();
	~item();

	HRESULT init();
	//�̴ϴϴϴ�(    ���� , ���밪, ���԰���, �ǸŰ���, ����)
	HRESULT init(string name, ITEM_TYPE type, ITEM_VALUE value, ITEM_BUY_PRICE buyPrice, ITEM_SELL_PRICE sellPrice, int num);
	void release();
	void update();
	void render();



	// ========== GET & SET ==========
	//�̸�
	string getItemName() { return _itemName; }

	//����
	ITEM_TYPE getItemType() { return _itemType; }

	//���밪
	ITEM_VALUE getItemValue() { return _itemValue; }

	//����
	int getItemNum() { return _itemNum; }

	//���԰���
	ITEM_BUY_PRICE getBuyPrice() { return _buyPrice; }
	
	//�ǸŰ���
	ITEM_SELL_PRICE getSellPrice() { return _sellPrice; }


	ITEM_VALUE makeItemValue(ITEM_TYPE type);
	ITEM_BUY_PRICE makeItemBuyPrice(ITEM_TYPE type);
	ITEM_SELL_PRICE makeItemSellPrice(ITEM_TYPE type);

	item* settionItemInfo(ITEM_TYPE type);
};

