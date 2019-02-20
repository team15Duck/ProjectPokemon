#pragma once
#include "baseUI.h"

enum REPORT_STATE
{
	RS_CURRENT_INFO,	//���� ���� ���â 
	RS_REPORT_SELECT,	//����Ʈ����â
};
enum REPORT_SELECT
{
	YES,
	NO
};
enum REPORT_SAVE_POSITION	//������ġ 
{
	RS_1_POSITION,
	RS_2_POSITION,
	RS_3_POSITION,
	RS_4_POSITION,
	RS_5_POSITION,
	RS_6_POSITION
};
typedef struct tagReport
{
	wstring currencity;
	wstring name;
	wstring IllustratedBook;
	wstring playTime;
}REPORT;


class report : public baseUI
{
private:

	REPORT_STATE			_rState;		//����Ʈ ����
	REPORT_SELECT			_rSelect;		//��/�ƴϿ�����
	REPORT_SAVE_POSITION	_rsPosition;	//����Ʈ ���� ������ 
	REPORT _report;

public:
	report();
	~report();

	HRESULT init();
	void release();
	void update();
	void render();

	void uiDataSetting();
	void setReportData();
};

