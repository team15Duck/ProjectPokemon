#include "stdafx.h"
#include "chiyeongTestScene.h"


chiyeongTestScene::chiyeongTestScene()
{
}


chiyeongTestScene::~chiyeongTestScene()
{
}

HRESULT chiyeongTestScene::init()
{

	_rc[0] = { -500, -WINSIZEY, 200, WINSIZEY * 2};
	_rc[1] = { -500, -WINSIZEY, 200, WINSIZEY * 2};
	_rc[2] = { 600, -WINSIZEY, 1200, WINSIZEY * 2};
	_rc[3] = {  600, -WINSIZEY, 1200, WINSIZEY * 2};

	_rc[4] = { -200, -300, WINSIZEX + 200, 200 };
	_rc[5] = { -300, -WINSIZEY, 300, WINSIZEY * 2};
	_rc[6] = { -200, 400, WINSIZEX + 200, 900 };
	_rc[7] = { 500, -WINSIZEY, 1200, WINSIZEY * 2};

	_rc[8] = { 0, 0, WINSIZEX, WINSIZEY };
	_count = 0;
	_start = 0;

	_rc2 = { 0, 0, WINSIZEX, WINSIZEY };


	return S_OK;
}

void chiyeongTestScene::release()
{
}

void chiyeongTestScene::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		_start = true;
		_count = 0;
		_angle[0] = RND->getFromIntTo(30, 60);
		_angle[1] = -RND->getFromIntTo(30, 60);
		_angle[2] = -RND->getFromIntTo(30, 60);
		_angle[3] = RND->getFromIntTo(30, 60);
		_angle[4] = RND->getFromIntTo(-15, 15);
		_angle[5] = RND->getFromIntTo(-15, 15);
		_angle[6] = RND->getFromIntTo(-15, 15);
		_angle[7] = RND->getFromIntTo(-15, 15);
		_angle[8] = 0;
		_scale = 1;
	}

	if (_start && _count < 500)
	{
		_count++;
		if (_scale > 0)
		{
			_scale -= 0.005f;
		}
	}
}

void chiyeongTestScene::render()
{
	for (int i = 0; i < 9; i++)
	{
		if (_count > i * 10 + 10)
		{
			D2DMANAGER->_renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(_angle[i], Point2F(400, 300)));
			D2DMANAGER->fillRectangle(RGB(0, 0, 0), _rc[i]);
			D2DMANAGER->_renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
		}
	}
	
	//if (_start)
	//{
	//	D2D1_SIZE_F size;
	//	size.width = _scale;
	//	size.height = _scale;
	//	Matrix3x2F mat = D2D1::Matrix3x2F::Rotation(_count, Point2F(400, 300));
	//	mat.SetProduct(mat, D2D1::Matrix3x2F::Scale(size, Point2F(400, 300)));
	//	D2D1::Matrix3x2F::Scale(size, Point2F(400, 300));
	//	D2DMANAGER->_renderTarget->SetTransform(mat);
	//}
	//D2DMANAGER->fillRectangle(RGB(0, 0, 0), _rc2);
}
