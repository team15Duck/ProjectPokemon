#pragma once
#include "singletonBase.h"


class camera;
class d2dManager : public singletonBase<d2dManager>
{
public:
	ID2D1Factory*				_d2dFactory;
	ID2D1HwndRenderTarget*		_renderTarget;
	IDWriteFactory*				_writeFactory;
	IDWriteTextFormat*			_defaultTextFormat;		//�⺻ �ؽ�Ʈ ����
	IDWriteTextFormat*			_customTextFormat;		//Ŀ���� �ؽ�Ʈ ����
	ID2D1SolidColorBrush*		_defaultBrush;			//�⺻ ������ �귯��

	
	

public:
	d2dManager();
	~d2dManager();

	HRESULT init();
	void release();
	void update();
	void render();
	void beginDraw();
	void endDraw();
	ID2D1SolidColorBrush* createBrush(COLORREF rgb, float opacity = 1.0f);



	
	//===================================================================
	//			Draw, Fill Method (Line, Rectangle, Ellipse)
	//- ī�޶� �̵� ���� & ������ ���� ���븸 ����
	//===================================================================
	

	void drawLine(ID2D1SolidColorBrush* brush, float startX, float startY, float endX, float endY, float strokeWidth = 1.0f);
	void drawRectangle(ID2D1SolidColorBrush* brush, float startX, float startY, float endX, float endY, float strokeWidth = 1.0f);
	void drawEllipse(ID2D1SolidColorBrush* brush, float startX, float startY, float endX, float endY, float strokeWidth = 1.0f);
	void fillRectangle(ID2D1SolidColorBrush* brush, float startX, float startY, float endX, float endY);
	void fillEllipse(ID2D1SolidColorBrush* brush, float startX, float startY, float endX, float endY);

	
	void drawText(LPCWSTR string, float x, float y);

	//����� ���ڿ�, ���ڿ��� �׸� Rect�� Left, Top, Right, Bottom, �׸� �귯��
	void drawTextD2D(ID2D1SolidColorBrush* brush, LPCWSTR string, float startX, float startY, float endX, float endY);

	//����� ���ڿ�, ���ڿ��� �׸� Rect�� Left, Top, Right, Bottom, �׸� �귯��, ��Ʈ��, ��Ʈ ũ��
	void drawTextD2D(ID2D1SolidColorBrush* brush, LPCWSTR fontName, float fontSize, LPCWSTR string, float startX, float startY, float endX, float endY);



	//===================================================================
	//			���� �Լ�
	//===================================================================

private:
	D2D1_RECT_F getDrawRectfArea( float startX, float startY, float endX, float endY);
	bool		isRectFInRangeWindow(const D2D1_RECT_F& rcf );
};

