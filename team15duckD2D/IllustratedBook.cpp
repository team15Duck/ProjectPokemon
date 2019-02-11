#include "stdafx.h"
#include "IllustratedBook.h"


IllustratedBook::IllustratedBook()
{
}


IllustratedBook::~IllustratedBook()
{
}

HRESULT IllustratedBook::init()
{
	for (int i = 0; i < 151; i++)
	{
		_book[i].name = "???";
		_book[i].attr = "???";
		_book[i].weight = "???";
		_book[i].height = "???";
	}


	return S_OK;
}

void IllustratedBook::release()
{
}

void IllustratedBook::update()
{
}

void IllustratedBook::render()
{
}
