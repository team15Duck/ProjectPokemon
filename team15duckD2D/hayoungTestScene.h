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

struct tagCommonMenu
{
	D2D1_RECT_F _bottom;
	D2D1_RECT_F _menu[7];
	D2D1_RECT_F _cursor[7];
	CUSSOR_STATE _cstate;
};
class hayoungTestScene : public gameNode
{
private:
	D2D1_RECT_F _rc;

	tagCommonMenu _cm;

	bool _isCommonMenu;	//�⺻�޴�
	bool _isCussorDown; //Ŀ��������
	bool _isCussorUp;	//Ŀ��������

public:
	hayoungTestScene();
	~hayoungTestScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void frameImageinit();

	//================================ GET && SET ===================================//


};

