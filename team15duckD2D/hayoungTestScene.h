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

	tagCMPokemonBook	_cmpb;		//기본메뉴 - 도감
	tagCMPokemon		_cmpm;		//기본메뉴 - 포켓몬
	tagCMBag			_cmb;		//기본메뉴 - 가방
	tagCMPlayer			_cmp;		//기본메뉴 - 플레이어
	tagCMReport			_cmr;		//기본메뉴 - 저장
	tagCMSetting		_cms;		//기본메뉴 - 세팅
	tagCMClose			_cmc;		//기본메뉴 - 닫기

	IllustratedBook* _book;

	MAIN_MENU_SELECT	_mmselect;	//메인메뉴 선택
	SUB_MENU_SELECT		_smselect;	//서브메뉴 선택
	CUSSOR_SELECT		_cselect;	//커서 선택

	bool _isCommonMenu;		//기본메뉴

	bool _issubpkm1exist;	//서브포켓몬 확인용 불값
	bool _issubpkm2exist;	//서브포켓몬 확인용 불값
	bool _issubpkm3exist;	//서브포켓몬 확인용 불값
	bool _issubpkm4exist;	//서브포켓몬 확인용 불값
	bool _issubpkm5exist;	//서브포켓몬 확인용 불값

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
	void commonMenurender();			//기본메뉴

	//================================ GET && SET ===================================//


};

