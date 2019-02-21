#pragma once
#include "pokemonInfo.h"

enum ITEM_TYPE
{
	//���ϸ��� ���� ü���� 30�� �̸��̸� ������ ������
	//�� �̻��̸� ���ϸ��� ��ȹ���� ���� ������.
	MONSTER_BALL,				//���ͺ�
	SUPER_BALL,					//���ۺ�
	HYPER_BALL,					//�����ۺ�
	MASTER_BALL,				//�����ͺ�

	NORMAL_POTION,				//��ó��(20ȸ��)
	SUPER_POTION,				//������ó��(60ȸ��)
	HYPER_POTION,				//��޻�ó��(120ȸ��)
	MAX_POTION,					//Ǯȸ����(��üȸ��)
	FULL_RESTORE,				//ȸ����(��üȸ��+�����̻�)

	NORMAL_ETHER,				//PP���̵�(�ѱ�� 10ȸ��)
	MAX_ETHER,					//ppȸ��(�ѱ�� ��üȸ��)
	NORMAL_ELIXIR,				//pp���̴�(����� 10ȸ��)
	MAX_ELIXIR,					//pp�ƽ�(����� ��üȸ��)

	ANTIDOTE,					//�ص���
	PARLYZE_HEAL,				//�����ص���
	BURN_HEAL,					//ȭ��ġ����
	ICE_HEAL,					//��������ġ����
	AWAKENING,					//����¾�
	FULL_HEAL,					//������ġ��				

	RARE_CANDY,					//�̻��ѻ���
	ESCAPE_ROPE,				//����Ż�����
	REVIVE,						//����� ����

	//�߿��� ����
	BICYCLE,					//������
	FISHING_ROD,				//���ô�
	TOWN_MAP,					//Ÿ���

	//�����ӽ�(������ ��밡��)
	HM_CUT,						//Ǯ����
	HM_FLASH,					//�÷���

	//����ӽ�(�ѹ��� ��밡��)
	TM_THUNDERBOLT,				//10����Ʈ
	TM_THUNDER,					//����
	TM_FLAMETHROWER,			//ȭ�����

	//��������
	CHERI_BERRY,				//��ġ����(����ȸ��)
	CHESTO_BERRY,				//���翭��(���ȸ��)
	PECHA_BERRY,				//��������(��ȸ��)
	RAWST_BERRY,				//���п���(ȭ��ȸ��)
	ASPEAR_BERRY,				//�踮����(����ȸ��)
	LEPPA_BERRY,				//���翭��(PP10ȸ��)
	ORAN_BERRY,					//��������(ü��10ȸ��)
	LUM_BERRY,					//��������(�������̻�ȸ��)
	SITRUS_BERRY,				//�ڹ�����(ü��30ȸ��)


	ITEM_TYPE_NONE,

	ITEM_TYPE_COUNT = ITEM_TYPE_NONE

};

enum ITEM_VALUE
{
	//�ִ�����ġ�� 999, �߿��ѹ��ǿ����� �� ������ ���� 255
	MONSTER_BALL_VALUE = 3,											   //���ͺ�
	SUPER_BALL_VALUE = 4,											   //���ۺ�
	HYPER_BALL_VALUE = 5,											   //�����ۺ�
	MASTER_BALL_VALUE = 10,											   //�����ͺ�

	NORMAL_POTION_VALUE = 20,										   //��ó��(20ȸ��)
	SUPER_POTION_VALUE = 50,										   //������ó��(60ȸ��)
	HYPER_POTION_VALUE = 120,										   //��޻�ó��(120ȸ��)
	MAX_POTION_VALUE = 999,											   //Ǯȸ����(��üȸ��)
	FULL_RESTORE_VALUE = 999,										   //ȸ����(��üȸ��+�����̻�)

	NORMAL_ETHER_VALUE = 10,										   //PP���̵�(�ѱ�� 10ȸ��)
	MAX_ETHER_VALUE = 999,											   //ppȸ��(�ѱ�� ��üȸ��)
	NORMAL_ELIXIR_VALUE = 10,										   //pp���̴�(����� 10ȸ��)
	MAX_ELIXIR_VALUE = 999,											   //pp�ƽ�(����� ��üȸ��)

	ANTIDOTE_VALUE = POKEMON_UPSET_CONDITION::PMUC_POISON,			   //�ص���
	PARLYZE_HEAL_VALUE = POKEMON_UPSET_CONDITION::PMUC_PALALYSIS,	   //�����ص���
	BURN_HEAL_VALUE = POKEMON_UPSET_CONDITION::PMUC_BURN,			   //ȭ��ġ����
	ICE_HEAL_VALUE = POKEMON_UPSET_CONDITION::PMUC_FROZEN,			   //��������ġ����
	AWAKENING_VALUE = POKEMON_UPSET_CONDITION::PMUC_SLEEP,			   //����¾�
	FULL_HEAL_VALUE = 999,											   //������ġ��				

	RARE_CANDY_VALUE = 1,											   //�̻��ѻ���
	ESCAPE_ROPE_VALUE = 1,											   //����Ż�����
	REVIVE_VALUE = 255,												   //����� ����
	
	//�߿��� ����
	BICYCLE_VALUE = 2,												   //������
	FISHING_ROD_VALUE = 255,										   //���ô�
	TOWN_MAP_VALUE = 255,											   //Ÿ���

	HM_CUT_VALUE = 255,												   //Ǯ����
	HM_FLASH_VALUE = 255,											   //�÷���
																	   
	TM_THUNDERBOLT_VALUE = 255,										   //10����Ʈ
	TM_THUNDER_VALUE = 255,											   //����
	TM_FLAMETHROWER_VALUE = 255,									   //ȭ�����
																	   
	CHERI_BERRY_VALUE = POKEMON_UPSET_CONDITION::PMUC_PALALYSIS,	   //��ġ����(����ȸ��)
	CHESTO_BERRY_VALUE = POKEMON_UPSET_CONDITION::PMUC_SLEEP,		   //���翭��(���ȸ��)
	PECHA_BERRY_VALUE = POKEMON_UPSET_CONDITION::PMUC_POISON,		   //��������(��ȸ��)
	RAWST_BERRY_VALUE = POKEMON_UPSET_CONDITION::PMUC_BURN,			   //���п���(ȭ��ȸ��)
	ASPEAR_BERRY_VALUE = POKEMON_UPSET_CONDITION::PMUC_FROZEN,		   //�踮����(����ȸ��)
	LEPPA_BERRY_VALUE = 10,											   //���翭��(PP10ȸ��)
	ORAN_BERRY_VALUE = 10,											   //��������(ü��10ȸ��)
	LUM_BERRY_VALUE = 999,											   //��������(�������̻�ȸ��)
	SITRUS_BERRY_VALUE = 30,										   //�ڹ�����(ü��30ȸ��)
																	   
	ITEM_VALUE_NONE,												   
																	   
	ITEM_VALUE_COUNT = ITEM_VALUE_NONE
};

enum ITEM_BUY_PRICE
{
	MONSTER_BALL_BUY_PRICE = 200,									   //���ͺ�
	SUPER_BALL_BUY_PRICE = 600,										   //���ۺ�
	HYPER_BALL_BUY_PRICE = 1200,									   //�����ۺ�
	MASTER_BALL_BUY_PRICE = 50000,									   //�����ͺ�

	NORMAL_POTION_BUY_PRICE = 300,									   //��ó��(20ȸ��)
	SUPER_POTION_BUY_PRICE = 700,									   //������ó��(60ȸ��)
	HYPER_POTION_BUY_PRICE = 1200,									   //��޻�ó��(120ȸ��)
	MAX_POTION_BUY_PRICE = 2500,									   //Ǯȸ����(��üȸ��)
	FULL_RESTORE_BUY_PRICE = 3000,									   //ȸ����(��üȸ��+�����̻�)

	NORMAL_ETHER_BUY_PRICE = 0,										   //PP���̵�(�ѱ�� 10ȸ��)
	MAX_ETHER_BUY_PRICE = 0,										   //ppȸ��(�ѱ�� ��üȸ��)
	NORMAL_ELIXIR_BUY_PRICE = 0,									   //pp���̴�(����� 10ȸ��)
	MAX_ELIXIR_BUY_PRICE = 0,										   //pp�ƽ�(����� ��üȸ��)

	ANTIDOTE_BUY_PRICE = 100,										   //�ص���
	PARLYZE_HEAL_BUY_PRICE = 200,									   //�����ص���
	BURN_HEAL_BUY_PRICE = 250,										   //ȭ��ġ����
	ICE_HEAL_BUY_PRICE = 250,										   //��������ġ����
	AWAKENING_BUY_PRICE = 250,										   //����¾�
	FULL_HEAL_BUY_PRICE = 600,										   //������ġ��				

	RARE_CANDY_BUY_PRICE = 0,										   //�̻��ѻ���
	ESCAPE_ROPE_BUY_PRICE = 0,										   //����Ż�����
	REVIVE_BUY_PRICE = 1500,										   //����� ����
	BICYCLE_BUY_PRICE = 0,											   //������
	FISHING_ROD_BUY_PRICE = 0,										   //���ô�
	TOWN_MAP_BUY_PRICE = 0,											   //Ÿ���
																	   
	HM_CUT_BUY_PRICE = 0,											   //Ǯ����
	HM_FLASH_BUY_PRICE = 0,											   //�÷���
																	   
	TM_THUNDERBOLT_BUY_PRICE = 3000,								   //10����Ʈ
	TM_THUNDER_BUY_PRICE = 3000,									   //����
	TM_FLAMETHROWER_BUY_PRICE = 3000,								   //ȭ�����
																	   
	CHERI_BERRY_BUY_PRICE = 20,										   //��ġ����(����ȸ��)
	CHESTO_BERRY_BUY_PRICE = 20,									   //���翭��(���ȸ��)
	PECHA_BERRY_BUY_PRICE = 20,										   //��������(��ȸ��)
	RAWST_BERRY_BUY_PRICE = 20,										   //���п���(ȭ��ȸ��)
	ASPEAR_BERRY_BUY_PRICE = 20,									   //�踮����(����ȸ��)
	LEPPA_BERRY_BUY_PRICE = 20,										   //���翭��(PP10ȸ��)
	ORAN_BERRY_BUY_PRICE = 20,										   //��������(ü��10ȸ��)
	LUM_BERRY_BUY_PRICE = 20,										   //��������(�������̻�ȸ��)
	SITRUS_BERRY_BUY_PRICE = 20,									   //�ڹ�����(ü��30ȸ��)
																	   
	ITEM_BUY_PRICE_NONE,											   

	ITEM_BUY_PRICE_COUNT = ITEM_BUY_PRICE_NONE
};

enum ITEM_SELL_PRICE
{
	MONSTER_BALL_SELL_PRICE = 100,									   //���ͺ�
	SUPER_BALL_SELL_PRICE = 300,									   //���ۺ�
	HYPER_BALL_SELL_PRICE = 600,									   //�����ۺ�
	MASTER_BALL_SELL_PRICE = 25000,									   //�����ͺ�

	NORMAL_POTION_SELL_PRICE = 150,									   //��ó��(20ȸ��)
	SUPER_POTION_SELL_PRICE = 350,									   //������ó��(60ȸ��)
	HYPER_POTION_SELL_PRICE = 600,									   //��޻�ó��(120ȸ��)
	MAX_POTION_SELL_PRICE = 600,									   //Ǯȸ����(��üȸ��)
	FULL_RESTORE_SELL_PRICE = 1500,									   //ȸ����(��üȸ��+�����̻�)

	NORMAL_ETHER_SELL_PRICE = 600,									   //PP���̵�(�ѱ�� 10ȸ��)
	MAX_ETHER_SELL_PRICE = 1000,									   //ppȸ��(�ѱ�� ��üȸ��)
	NORMAL_ELIXIR_SELL_PRICE = 1500,								   //pp���̴�(����� 10ȸ��)
	MAX_ELIXIR_SELL_PRICE = 2250,									   //pp�ƽ�(����� ��üȸ��)

	ANTIDOTE_SELL_PRICE = 50,										   //�ص���
	PARLYZE_HEAL_SELL_PRICE = 100, 									   //�����ص���
	BURN_HEAL_SELL_PRICE = 125,										   //ȭ��ġ����
	ICE_HEAL_SELL_PRICE = 125,										   //��������ġ����
	AWAKENING_SELL_PRICE = 125,										   //����¾�
	FULL_HEAL_SELL_PRICE = 300,										   //������ġ��				

	RARE_CANDY_SELL_PRICE = 2400,									   //�̻��ѻ���
	ESCAPE_ROPE_SELL_PRICE = 2400,									   //����Ż�����
	REVIVE_SELL_PRICE = 750,										   //����� ����
	BICYCLE_SELL_PRICE = 0,											   //������
	FISHING_ROD_SELL_PRICE = 0,										   //���ô�
	TOWN_MAP_SELL_PRICE = 0,										   //Ÿ���

	HM_CUT_SELL_PRICE = 0,											   //Ǯ����
	HM_FLASH_SELL_PRICE = 0,										   //�÷���

	TM_THUNDERBOLT_SELL_PRICE = 1500,								   //10����Ʈ
	TM_THUNDER_SELL_PRICE = 1500,									   //����
	TM_FLAMETHROWER_SELL_PRICE = 1500,								   //ȭ�����

	CHERI_BERRY_SELL_PRICE = 10,									   //��ġ����(����ȸ��)
	CHESTO_BERRY_SELL_PRICE = 10,									   //���翭��(���ȸ��)
	PECHA_BERRY_SELL_PRICE = 10,									   //��������(��ȸ��)
	RAWST_BERRY_SELL_PRICE = 10,									   //���п���(ȭ��ȸ��)
	ASPEAR_BERRY_SELL_PRICE = 10,									   //�踮����(����ȸ��)
	LEPPA_BERRY_SELL_PRICE = 10,									   //���翭��(PP10ȸ��)
	ORAN_BERRY_SELL_PRICE = 10,										   //��������(ü��10ȸ��)
	LUM_BERRY_SELL_PRICE = 10,										   //��������(�������̻�ȸ��)
	SITRUS_BERRY_SELL_PRICE = 10,									   //�ڹ�����(ü��30ȸ��)

	ITEM_SELL_PRICE_NONE,

	ITEM_SELL_PRICE_COUNT = ITEM_SELL_PRICE_NONE
};

class item : public singletonBase<item>
{
private:
	
	image*					_img;			//�̹���
	RECT					_rc;			//��Ʈ
	
	string					_sceneName;		//�ʳ��� ��ġ�Ǿ��ִٸ� �������?
	UINT					_tileX;			//�ִٸ� ��� Ÿ�Ͽ�?
	UINT					_tileY;			//�ִٸ� ��� Ÿ�Ͽ�?

	string					_itemName;		//�������̸�
	string					_itemInfo;		//�����ۼ���
	ITEM_TYPE				_itemType;		//����
	ITEM_VALUE				_itemValue;		//���������밪(ȸ����, ppȸ����, ��ȹ�� ��)
	UINT					_itemNum;		//����
	ITEM_BUY_PRICE			_buyPrice;		//���԰���
	ITEM_SELL_PRICE			_sellPrice;		//�ǸŰ���

	POINTF					_rcPos;			//��ġ
	POINTF					_imgPos;		//�̹�����ġ
	POINT					_imgSize;		//�̹���ũ��

	vector<item*>			_fieldItem;


public:
	item();
	~item();

	HRESULT init();
	//�̴ϴϴϴ�(����)
	HRESULT init(ITEM_TYPE type);
	void release();
	void update();
	void render();

	string makeName(ITEM_TYPE type);

	// ========== GET & SET ==========
	//�̸�
	string getItemName() { return _itemName; }

	//����
	ITEM_TYPE getItemType() { return _itemType; }

	//���밪
	ITEM_VALUE getItemValue() { return _itemValue; }

	//����
	UINT getItemNum() { return _itemNum; }

	//���԰���
	ITEM_BUY_PRICE getBuyPrice() { return _buyPrice; }
	
	//�ǸŰ���
	ITEM_SELL_PRICE getSellPrice() { return _sellPrice; }

	//����������
	string getItemInfo() { return _itemInfo; }


	//������ ��ġ
	UINT getTileX() { return _tileX; }
	UINT getTileY() { return _tileY; }
	void setTileX(UINT tileX) { _tileX = tileX; }
	void setTileY(UINT tileY) { _tileY = tileY; }

	//������޾ƿ���
	void setCurrentScene(string scene) { _sceneName = scene; }




	//ITEM_VALUE makeItemValue(ITEM_TYPE type);
	//ITEM_BUY_PRICE makeItemBuyPrice(ITEM_TYPE type);
	//ITEM_SELL_PRICE makeItemSellPrice(ITEM_TYPE type);
	//string makeItemName(ITEM_TYPE type);
	//string makeItemInfo(ITEM_TYPE type);
	
	//������������ ���� ������Ÿ�� �־��ֽ��
	item* settingItemInfo(ITEM_TYPE type);

};

