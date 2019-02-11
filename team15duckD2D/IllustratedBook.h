#pragma once


typedef struct tagPokemonBookInfo
{
	string name;	//�̸�
	string attr;	//�Ӽ�
	string weight;	//����
	string height;	//Ű
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

