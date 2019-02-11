#pragma once


typedef struct tagPokemonBookInfo
{
	string name;	//이름
	string attr;	//속성
	string weight;	//무게
	string height;	//키
}POKEMONBOOK;


class IllustratedBook
{
private:

	POKEMONBOOK _book[151];



public:
	IllustratedBook();
	~IllustratedBook();

	HRESULT init();
	void release();
	void update();
	void render();

	POKEMONBOOK* getBook() { return _book; }


};

