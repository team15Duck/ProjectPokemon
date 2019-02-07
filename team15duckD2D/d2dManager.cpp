#include "stdafx.h"
#include "d2dManager.h"


d2dManager::d2dManager()
{
}


d2dManager::~d2dManager()
{
}

HRESULT d2dManager::init()
{
	_d2dFactory = nullptr;
	_renderTarget = nullptr;

	HRESULT hr = E_FAIL;

	//---------------------------------------------------------------------------
	//	D2D Factory ����
	//---------------------------------------------------------------------------
	hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &_d2dFactory);
	assert(hr == S_OK);

	//---------------------------------------------------------------------------
	//	Hwnd Render Target ����
	//---------------------------------------------------------------------------
	hr = _d2dFactory->CreateHwndRenderTarget(RenderTargetProperties(),
		HwndRenderTargetProperties(_hWnd, SizeU(WINSIZEX, WINSIZEY)),
		&_renderTarget);
	assert(hr == S_OK);

	//---------------------------------------------------------------------------
	//	IDWriteFactory ����
	//---------------------------------------------------------------------------
	hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(_writeFactory),
		reinterpret_cast<IUnknown **>(&_writeFactory));
	assert(hr == S_OK);
	
	// �귯�� ����
	_defaultBrush = createBrush(RGB(0, 0, 0));

	//	�⺻ �ؽ�Ʈ ���� ����
	_writeFactory->CreateTextFormat(L"�������", NULL, DWRITE_FONT_WEIGHT_REGULAR,
		DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 17.0f, L"", &_defaultTextFormat);

	// COM ���̺귯�� �ʱ�ȭ -> ȣ������ ������ CoCreateInstance�� ����� ������� ����
	CoInitialize(NULL);


	return S_OK;
}

void d2dManager::release()
{
	SAFE_RELEASE2(_defaultBrush);
	SAFE_RELEASE2(_defaultTextFormat);
	SAFE_RELEASE2(_writeFactory);
	SAFE_RELEASE2(_renderTarget);
	SAFE_RELEASE2(_d2dFactory);
}

void d2dManager::update()
{
}

void d2dManager::render()
{

}

void d2dManager::beginDraw()
{
	_renderTarget->BeginDraw();
	_renderTarget->Clear(ColorF(ColorF::White));
}

void d2dManager::endDraw()
{
	_renderTarget->EndDraw();
}

ID2D1SolidColorBrush * d2dManager::createBrush(COLORREF rgb, float opacity)
{
	HRESULT hr;
	ID2D1SolidColorBrush* brush;
	brush = nullptr;

	hr = _renderTarget->CreateSolidColorBrush(ColorF(rgb, opacity), &brush);

	return brush;
	
}



//===================================================================
//			Draw, Fill Method (Line, Rectangle, Ellipse)
//- ī�޶� �̵� ���� & ������ ���� ���븸 ����
//===================================================================

void d2dManager::drawLine(ID2D1SolidColorBrush * brush, float startX, float startY, float endX, float endY, float strokeWidth)
{
	D2D1_RECT_F rcf = getDrawRectfArea(startX, startY, endX, endY);

	if ( !isRectFInRangeWindow(rcf) )
		return;

	_renderTarget->DrawLine(Point2F(rcf.left, rcf.top), Point2F(rcf.right, rcf.bottom), brush, strokeWidth);
}

void d2dManager::drawRectangle(ID2D1SolidColorBrush * brush, float startX, float startY, float endX, float endY, float strokeWidth)
{
	D2D1_RECT_F rcf = getDrawRectfArea(startX, startY, endX, endY);

	if ( !isRectFInRangeWindow(rcf) )
		return;

	_renderTarget->DrawRectangle(rcf, brush, strokeWidth);
}

void d2dManager::drawEllipse(ID2D1SolidColorBrush * brush, float startX, float startY, float endX, float endY, float strokeWidth)
{
	D2D1_RECT_F rcf = getDrawRectfArea(startX, startY, endX, endY);

	if ( !isRectFInRangeWindow(rcf) )
		return;

	float width = endX - startX;
	float height = endY - startY;

	D2D1_ELLIPSE ellipse;
	ellipse.point.x = rcf.left + width * 0.5;
	ellipse.point.y = rcf.top + height * 0.5;
	ellipse.radiusX = width * 0.5;
	ellipse.radiusY = height * 0.5;

	_renderTarget->DrawEllipse(&ellipse, brush, strokeWidth);
}

void d2dManager::fillRectangle(ID2D1SolidColorBrush * brush, float startX, float startY, float endX, float endY)
{
	D2D1_RECT_F rcf = getDrawRectfArea(startX, startY, endX, endY);

	if (!isRectFInRangeWindow(rcf))
		return;

	_renderTarget->FillRectangle( rcf, brush);
}

void d2dManager::fillEllipse(ID2D1SolidColorBrush * brush, float startX, float startY, float endX, float endY)
{
	D2D1_RECT_F rcf = getDrawRectfArea(startX, startY, endX, endY);

	if (!isRectFInRangeWindow(rcf))
		return;

	float width = endX - startX;
	float height = endY - startY;

	D2D1_ELLIPSE ellipse;
	ellipse.point.x = rcf.left + width * 0.5;
	ellipse.point.y = rcf.top + height * 0.5;
	ellipse.radiusX = width * 0.5;
	ellipse.radiusY = height * 0.5;

	_renderTarget->FillEllipse(&ellipse, brush);
}

void d2dManager::drawText(LPCWSTR string, float x, float y)
{
	D2D1_RECT_F rcf = getDrawRectfArea(x, y, x + lstrlenW(string) * 15, y + 20);

	if (!isRectFInRangeWindow(rcf))
		return;

	//	TextFormat ����
	_writeFactory->CreateTextFormat(L"�������", NULL, DWRITE_FONT_WEIGHT_REGULAR,
		DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 15, L"", &_customTextFormat);

	_renderTarget->DrawTextA(string, lstrlenW(string), _customTextFormat, rcf, _defaultBrush);

	SAFE_RELEASE2(_customTextFormat);
}


void d2dManager::drawTextD2D(ID2D1SolidColorBrush * brush, LPCWSTR string, float startX, float startY, float endX, float endY)
{
	D2D1_RECT_F rcf = getDrawRectfArea(startX, startY, endX, endY);

	if (!isRectFInRangeWindow(rcf))
		return;

	_renderTarget->DrawTextA(string, lstrlenW(string), _defaultTextFormat, rcf, brush);
}

void d2dManager::drawTextD2D(ID2D1SolidColorBrush * brush, LPCWSTR fontName, float fontSize, LPCWSTR string, float startX, float startY, float endX, float endY)
{
	D2D1_RECT_F rcf = getDrawRectfArea(startX, startY, endX, endY);
	
	if( !isRectFInRangeWindow(rcf) )
		return;
	
	//	TextFormat ����
	_writeFactory->CreateTextFormat(fontName, NULL, DWRITE_FONT_WEIGHT_REGULAR,
		DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, fontSize, L"", &_customTextFormat);


	_renderTarget->DrawTextA(string, lstrlenW(string), _customTextFormat, rcf, brush);

	SAFE_RELEASE2(_customTextFormat);
}

D2D1_RECT_F d2dManager::getDrawRectfArea( float startX, float startY, float endX, float endY)
{
	D2D1_RECT_F rc;
	rc = {	  startX - CAMERA->getPosX()
			, startY - CAMERA->getPosY()
			, endX	 - CAMERA->getPosX()
			, endY	 - CAMERA->getPosY()
		};

	return rc;
}

bool d2dManager::isRectFInRangeWindow(const D2D1_RECT_F& rcf)
{
	if ( rcf.left < 0 && rcf.right < 0 ) return false;
	if ( rcf.top < 0 && rcf.bottom < 0 ) return false;
	if ( WINSIZEX < rcf.left && WINSIZEX < rcf.right ) return false;
	if ( WINSIZEY < rcf.top &&  WINSIZEY < rcf.bottom) return false;

	return true;
}
