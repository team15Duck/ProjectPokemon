#pragma once
#include "baseUI.h"
#include "playerDataBase.h"

enum BAG_STATE
{
	ITEM_LIST,
	ITEM_USE_SELECT,
	ITEM_PASS_SELECT,
};
enum ITEM_USE_STATE
{
	ITEM_USE,
	ITEM_PASS,
	ITEM_THROW_AWAY,
	ITEM_STATE_NONE
};
enum ITEM_USE_POKEMON
{
	USE_MAIN_POKEMON,
	USE_SUB_POKEMON1,
	USE_SUB_POKEMON2,
	USE_SUB_POKEMON3,
	USE_SUB_POKEMON4,
	USE_SUB_POKEMON5,
	USE_CANCEL
};
typedef struct tagBagInfo
{
	wstring name;		//������ ��
	wstring amount;		//������ ����
	wstring info;		//������ ����
	int type;

	bool _isDataset;
}BAG;

typedef struct tagItemUsePokemon
{
	wstring iD_number;
	wstring name;
	wstring level;
	wstring type;
	wstring item;

	wstring currentHp;
	wstring maxHp;

	bool isDataSet;
}IUPOKEMON;

class bag : public baseUI
{
private:
	
	BAG_STATE _bag_state;
	ITEM_USE_STATE _item_use;

	ITEM_USE_POKEMON _ie_Pokemon; //�������� �����۾���?
	
	BAG _bag[39];
	IUPOKEMON _iuPokemon[6];
	playerDataBase* _playeritem;

	UINT _currentSelectNum;
	
	UINT _currentitemamount;
	UINT _maxitemamount;

	float _selectNumMoveCount;
	float _selectNumMoveDelay;

	bool _isitemUse;			//������ ����Ҳ���?

	//====================������ ���� ������

	int _pokemonCnt; // �����ϰ� �ִ� ���ϸ��� ��

	// �ִϸ��̼�
	animation* _pkAni[6];

public:
	bag();
	~bag();

	HRESULT init();
	void release();
	void update();
	void render();

	void uiOpen();
	void uiClose();

	void uiInfoSet();
	void itemDataSet();

	void keyAni();
	//=====�����ۻ���� ���� ȭ��
	void itemUseScreen();

};

