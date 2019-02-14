#pragma once

typedef struct tagBagInfo
{
	wstring name;		//아이템 명
	wstring amount;		//아이템 수량
}BAG;

class bag
{
private:
	BAG _bag[39];

	UINT _currentSelectNum;
public:
	bag();
	~bag();

	HRESULT init();
	void release();
	void update();
	void render();

	void itemDataSet();

};

