#include "stdafx.h"
#include "report.h"


report::report()
{
}


report::~report()
{
}

HRESULT report::init()
{
	MENUMANAGER->addFrame("현재정보", 0, 0, 14, 6);
	MENUMANAGER->addFrame("저장메뉴", 0, 190, 12, 14);
	MENUMANAGER->addFrame("체크박스", 750, 280, 6, 5);
	MENUMANAGER->addFrame("확인창", 200, 200, 6, 5);

	_rState = RS_CURRENT_INFO;
	_rSelect = YES;
	_rsPosition = RS_1_POSITION;

	return S_OK;
}

void report::release()
{
}

void report::update()
{
	if (_rState == RS_CURRENT_INFO)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			switch (_rSelect)
			{
			case YES:
				_rSelect = NO;
			break;
			case NO:
				_rSelect = YES;
			break;
			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			switch (_rSelect)
			{
			case YES:
				_rSelect = NO;
			break;
			case NO:
				_rSelect = YES;
			break;
			}
		}
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			switch (_rSelect)
			{
			case YES:
				_rState = RS_REPORT_SELECT;
				break;
			case NO:
				UIMANAGER->moveBeforeUI();
				break;
			}
		}
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			UIMANAGER->moveBeforeUI();
		}
	}
	if (_rState == RS_REPORT_SELECT)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			switch (_rsPosition)
			{
			case RS_1_POSITION:
				_rsPosition = RS_2_POSITION;
				break;
			case RS_2_POSITION:
				_rsPosition = RS_3_POSITION;
				break;
			case RS_3_POSITION:
				_rsPosition = RS_4_POSITION;
				break;
			case RS_4_POSITION:
				_rsPosition = RS_5_POSITION;
				break;
			case RS_5_POSITION:
				_rsPosition = RS_6_POSITION;
				break;
			case RS_6_POSITION:
				_rsPosition = RS_1_POSITION;
				break;
			}
		}
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			switch (_rsPosition)
			{
			case RS_1_POSITION:
				
				break;
			case RS_2_POSITION:
				
				break;
			case RS_3_POSITION:
				
				break;
			case RS_4_POSITION:
				
				break;
			case RS_5_POSITION:
				
				break;
			case RS_6_POSITION:
				
				break;
			}
		}

		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			_rState = RS_CURRENT_INFO;
		}
	}
}

void report::render()
{
	WCHAR report[128];

	MENUMANAGER->findMenuFrame("현재정보")->render();
	swprintf_s(report, L"%d", _report.currencity);
	D2DMANAGER->drawText(report, 32 + CAMERA->getPosX(), 32 + CAMERA->getPosY(), 34);
	swprintf_s(report, L"이름 : %d", _report.name);
	D2DMANAGER->drawText(report, 32 + CAMERA->getPosX(), 66 + CAMERA->getPosY(), 34);
	swprintf_s(report, L"포켓몬도감 : %d", _report.IllustratedBook);
	D2DMANAGER->drawText(report, 32 + CAMERA->getPosX(), 100 + CAMERA->getPosY(), 34);
	swprintf_s(report, L"플레이시간 : %d", _report.playTime);
	D2DMANAGER->drawText(report, 32 + CAMERA->getPosX(), 134 + CAMERA->getPosY(), 34);


	if (_rState == RS_CURRENT_INFO)
	{
		IMAGEMANAGER->findImage("기본하단")->render(0, 480);
		swprintf_s(report, L"지금까지의 활약을 리포트에 저장하시겠습니까?");
		D2DMANAGER->drawText(report, 50 + CAMERA->getPosX(), 500 + CAMERA->getPosY(), 40, RGB(255,255,255));
		

		MENUMANAGER->findMenuFrame("체크박스")->render();
		switch (_rSelect)
		{
		case YES:
			IMAGEMANAGER->findImage("화살표")->render(774 + CAMERA->getPosX(), 310 + CAMERA->getPosY());
			break;
		case NO:
			IMAGEMANAGER->findImage("화살표")->render(774 + CAMERA->getPosX(), 370 + CAMERA->getPosY());
			break;
		}

		swprintf_s(report, L"예");
		D2DMANAGER->drawText(report, 798 + CAMERA->getPosX(), 310 + CAMERA->getPosY(), 40);
		swprintf_s(report, L"아니오");
		D2DMANAGER->drawText(report, 798 + CAMERA->getPosX(), 370 + CAMERA->getPosY(), 40);
	}

	if (_rState == RS_REPORT_SELECT)
	{
		MENUMANAGER->findMenuFrame("저장메뉴")->render();
		switch (_rsPosition)
		{
		case RS_1_POSITION:
			IMAGEMANAGER->findImage("화살표")->render(30 + CAMERA->getPosX(), 230 + CAMERA->getPosY());
			break;
		case RS_2_POSITION:
			IMAGEMANAGER->findImage("화살표")->render(30 + CAMERA->getPosX(), 290 + CAMERA->getPosY());
			break;
		case RS_3_POSITION:
			IMAGEMANAGER->findImage("화살표")->render(30 + CAMERA->getPosX(), 350 + CAMERA->getPosY());
			break;
		case RS_4_POSITION:
			IMAGEMANAGER->findImage("화살표")->render(30 + CAMERA->getPosX(), 410 + CAMERA->getPosY());
			break;
		case RS_5_POSITION:
			IMAGEMANAGER->findImage("화살표")->render(30 + CAMERA->getPosX(), 470 + CAMERA->getPosY());
			break;
		case RS_6_POSITION:
			IMAGEMANAGER->findImage("화살표")->render(30 + CAMERA->getPosX(), 530 + CAMERA->getPosY());
			break;
		}


		swprintf_s(report, L"1.");
		D2DMANAGER->drawText(report, 55 + CAMERA->getPosX(), 230 + CAMERA->getPosY(), 40);
		swprintf_s(report, L"2.");
		D2DMANAGER->drawText(report, 55 + CAMERA->getPosX(), 290 + CAMERA->getPosY(), 40);
		swprintf_s(report, L"3.");
		D2DMANAGER->drawText(report, 55 + CAMERA->getPosX(), 350 + CAMERA->getPosY(), 40);
		swprintf_s(report, L"4.");
		D2DMANAGER->drawText(report, 55 + CAMERA->getPosX(), 410 + CAMERA->getPosY(), 40);
		swprintf_s(report, L"5.");
		D2DMANAGER->drawText(report, 55 + CAMERA->getPosX(), 470 + CAMERA->getPosY(), 40);
		swprintf_s(report, L"6.");
		D2DMANAGER->drawText(report, 55 + CAMERA->getPosX(), 530 + CAMERA->getPosY(), 40);

		MENUMANAGER->findMenuFrame("확인창")->render();

	}
}

void report::uiDataSetting()
{
	setReportData();
}

void report::setReportData()
{
	_report.currencity = string2wstring(PLAYERDATA->getPlayer()->getSceneName());
	_report.name = string2wstring(PLAYERDATA->getPlayer()->getName());
	_report.IllustratedBook = to_wstring(PLAYERDATA->getPlayer()->getCurrentPokemonCnt());
	_report.playTime = to_wstring(PLAYERDATA->getPlayer()->getPlayTime());
}
