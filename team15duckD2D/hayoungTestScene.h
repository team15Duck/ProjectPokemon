#pragma once
#include "gameNode.h"

enum MENU_DIRECTION
{
	MD_LT, MD_RT, MD_LB, MD_RB, MD_L, MD_R, MD_T, MD_B, MD_NONE
};
enum CUSSOR_STATE
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

enum MENU_SELECT
{
	YES = 1,
	NO,
};

struct tagCommonMenu
{
	D2D1_RECT_F _bottom;
	D2D1_RECT_F _menu[7];
	D2D1_RECT_F _cursor[7];
	CUSSOR_STATE _cstate;
	MENU_SELECT _ms;
};
struct tagCMPokemonBook
{

};
struct tagCMPokemon
{

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
	D2D1_RECT_F _rc;

	tagCommonMenu		_cm;		//�⺻�޴�
	tagCMPokemonBook	_cmpb;		//�⺻�޴� - ����
	tagCMPokemon		_cmpm;		//�⺻�޴� - ���ϸ�
	tagCMBag			_cmb;		//�⺻�޴� - ����
	tagCMPlayer			_cmp;		//�⺻�޴� - �÷��̾�
	tagCMReport			_cmr;		//�⺻�޴� - ����
	tagCMSetting		_cms;		//�⺻�޴� - ����
	tagCMClose			_cmc;		//�⺻�޴� - �ݱ�



	bool _isCommonMenu;		//�⺻�޴�

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
	void commonMenuinit();				//�⺻�޴�
	void commonMenurender();			//�⺻�޴�

	//================================ GET && SET ===================================//

	   
};

