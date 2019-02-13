#pragma once
#include <locale>
#include <codecvt>
#include <string>

typedef struct tagPokemonBookInfo
{
	wstring number; //��ȣ
	wstring name;	//�̸�
	wstring attr;	//�Ӽ�
	wstring weight;	//����
	wstring height;	//Ű

	int attrframeX;
	int attrframeY;


	bool isCatch;	//�������ϸ��̴�?
	bool isDataSet;	//�����ͼ����ߴ�?

}POKEMONBOOK;


class IllustratedBook
{
private:

	POKEMONBOOK _book[151];

	UINT _currentSelectNum;		//���� ������ ��ȣ

	float _selectNumMoveCount;
	float _selectNumMoveDelay;

	bool _isdataexist;			//�������ִ�?
	bool _isdetaileinfo;		//���ϸ� ������â�̴�?

public:
	IllustratedBook();
	~IllustratedBook();

	HRESULT init();
	void release();
	void update();
	void render();

	POKEMONBOOK* getBook() { return _book; }

	void pokemonDataSet();

};

