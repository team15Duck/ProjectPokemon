#pragma once

typedef struct tagBagInfo
{
	wstring name;		//������ ��
	wstring amount;		//������ ����
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

