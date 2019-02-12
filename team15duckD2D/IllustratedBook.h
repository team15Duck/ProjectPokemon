#pragma once


typedef struct tagPokemonBookInfo
{
	wstring name;	//�̸�
	wstring attr;	//�Ӽ�
	wstring weight;	//����
	wstring height;	//Ű

}POKEMONBOOK;


class IllustratedBook
{
private:

	POKEMONBOOK _book[151];

	UINT _currentSelectNum;		//���� ������ ��ȣ
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

