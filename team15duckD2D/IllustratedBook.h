#pragma once
#include <locale>
#include <codecvt>
#include <string>
#include "baseUI.h"

enum POKEMON_BOOK_STATE
{
	BOOK_LIST,
	BOOK_INFO,
};
typedef struct tagPokemonBookInfo
{
	wstring number; //번호
	wstring name;	//이름
	wstring attr;	//속성
	wstring weight;	//무게
	wstring height;	//키
	wstring info;	//설명


	wstring tagweight;	//무게 명칭
	wstring tagheight;	//키 명칭
	wstring tagcm;
	wstring tagkg;

	int attrframeX;
	int attrframeY;


	bool isCatch;	//잡은포켓몬이니?
	bool isDataSet;	//데이터세팅했니?

}POKEMONBOOK;


class IllustratedBook : public baseUI
{
private:

	POKEMON_BOOK_STATE _pbstate;

	POKEMONBOOK _book[151];

	UINT _currentSelectNum;		//현재 선택한 번호

	float _selectNumMoveCount;
	float _selectNumMoveDelay;

	bool _isdataexist;			//데이터있니?
	bool _isdetaileinfo;		//포켓몬 상세정보창이니?

public:
	IllustratedBook();
	~IllustratedBook();

	HRESULT init();
	void release();
	void update();
	void render();

	POKEMONBOOK* getBook() { return _book; }

	void pokemonDataSet();
	void uiInfoSet();

	POKEMON_BOOK_STATE getState() { return _pbstate; }
};

