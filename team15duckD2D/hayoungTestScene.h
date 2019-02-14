#pragma once
#include "gameNode.h"
#include "IllustratedBook.h"

enum MAIN_MENU_SELECT
{
	MMS_YES = 1,
	MMS_NO
};
enum SUB_MENU_SELECT
{
	SMS_YES = 1,
	SMS_NO,
};
enum CUSSOR_SELECT
{
	POKEMON_BOOK = 1,
	POKEMON,
	BAG,
	PLAYER,
	SAVE_REPORT,
	SETTING,
	CLOSE,
	NONE
};
enum POKEMON_CURRENT_SELECT
{
	MAIN_POKEMON = 1,
	SUB_POKEMON1,
	SUB_POKEMON2,
	SUB_POKEMON3,
	SUB_POKEMON4,
	SUB_POKEMON5,
	CANCEL,
};


struct tagCMPokemonBook
{

};
struct tagCMPokemon
{
	D2D1_RECT_F _subPokemon[5];
	POKEMON_CURRENT_SELECT _pcs;

};
struct tagCMBag
{

};
struct tagCMPlayer
{

};
struct tagCMReport
{

};
struct tagCMSetting
{

};
struct tagCMClose
{

};
class hayoungTestScene : public gameNode
{
private:

	tagCMPokemonBook	_cmpb;		//�⺻�޴� - ����
	tagCMPokemon		_cmpm;		//�⺻�޴� - ���ϸ�
	tagCMBag			_cmb;		//�⺻�޴� - ����
	tagCMPlayer			_cmp;		//�⺻�޴� - �÷��̾�
	tagCMReport			_cmr;		//�⺻�޴� - ����
	tagCMSetting		_cms;		//�⺻�޴� - ����
	tagCMClose			_cmc;		//�⺻�޴� - �ݱ�

	IllustratedBook* _book;

	MAIN_MENU_SELECT	_mmselect;	//���θ޴� ����
	SUB_MENU_SELECT		_smselect;	//����޴� ����
	CUSSOR_SELECT		_cselect;	//Ŀ�� ����

	bool _isCommonMenu;		//�⺻�޴�

	bool _issubpkm1exist;	//�������ϸ� Ȯ�ο� �Ұ�
	bool _issubpkm2exist;	//�������ϸ� Ȯ�ο� �Ұ�
	bool _issubpkm3exist;	//�������ϸ� Ȯ�ο� �Ұ�
	bool _issubpkm4exist;	//�������ϸ� Ȯ�ο� �Ұ�
	bool _issubpkm5exist;	//�������ϸ� Ȯ�ο� �Ұ�

	bool _isFemale;		//���ڳ�
	bool _isMale;		//���ڳ�

public:
	hayoungTestScene();
	~hayoungTestScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void frameImageinit();
	void commonMenurender();			//�⺻�޴�

	//================================ GET && SET ===================================//


};

