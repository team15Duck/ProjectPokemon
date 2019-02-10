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

	tagCommonMenu		_cm;		//기본메뉴
	tagCMPokemonBook	_cmpb;		//기본메뉴 - 도감
	tagCMPokemon		_cmpm;		//기본메뉴 - 포켓몬
	tagCMBag			_cmb;		//기본메뉴 - 가방
	tagCMPlayer			_cmp;		//기본메뉴 - 플레이어
	tagCMReport			_cmr;		//기본메뉴 - 저장
	tagCMSetting		_cms;		//기본메뉴 - 세팅
	tagCMClose			_cmc;		//기본메뉴 - 닫기



	bool _isCommonMenu;		//기본메뉴

	bool _isFemale;		//여자냐
	bool _isMale;		//남자냐

public:
	hayoungTestScene();
	~hayoungTestScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void frameImageinit();
	void commonMenuinit();				//기본메뉴
	void commonMenurender();			//기본메뉴

	//================================ GET && SET ===================================//

	   
};

