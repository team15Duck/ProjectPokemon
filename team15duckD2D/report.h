#pragma once
#include "baseUI.h"

typedef struct tagReport
{
	wstring currentity;
	wstring name;
	wstring IllustratedBook;
	wstring playTime;
}REPORT;
class report : public baseUI
{
private:

	REPORT _report;

public:
	report();
	~report();

	HRESULT init();
	void release();
	void update();
	void render();


};

