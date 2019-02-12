#pragma once


typedef struct tagPokemonBookInfo
{
	wstring name;	//이름
	wstring attr;	//속성
	wstring weight;	//무게
	wstring height;	//키

}POKEMONBOOK;


class IllustratedBook
{
private:

	POKEMONBOOK _book[151];

	UINT _currentSelectNum;		//현재 선택한 번호
	float _selectNumMoveCount;
	float _selectNumMoveDelay;

public:
	IllustratedBook();
	~IllustratedBook();

	HRESULT init();
	void release();
	void update();
	void render();

	POKEMONBOOK* getBook() { return _book; }


};

