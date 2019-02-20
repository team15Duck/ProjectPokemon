#pragma once
#include "baseUI.h"

enum REPORT_STATE
{
	RS_CURRENT_INFO,	//현재 정보 출력창 
	RS_REPORT_SELECT,	//리포트선택창
};
enum REPORT_SELECT
{
	YES,
	NO
};
enum REPORT_SAVE_POSITION	//저장위치 
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

	REPORT_STATE			_rState;		//리포트 상태
	REPORT_SELECT			_rSelect;		//예/아니오선택
	REPORT_SAVE_POSITION	_rsPosition;	//리포트 저장 포지션 
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

