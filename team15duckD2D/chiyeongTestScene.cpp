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
	}

	if (_start && _count < 500)
	{
		_count++;
	}
}

void chiyeongTestScene::render()
{
	for (int i = 0; i < 9; i++)
	{
		if (_count > i * 30 + 10)
		{
			D2DMANAGER->_renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(_angle[i], Point2F(400, 300)));
			D2DMANAGER->fillRectangle(RGB(0, 0, 0), _rc[i]);
			D2DMANAGER->_renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
		}
	}
	//if (_count > 10)
	//{
	//	D2DMANAGER->_renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(_angle[0], Point2F(0, 300)));
	//	D2DMANAGER->fillRectangle(RGB(0, 0, 0), _rc[0]);
	//	D2DMANAGER->_renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	//}
	//if (_count > 20)
	//{
	//	D2DMANAGER->_renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(-_angle[1], Point2F(0, 300)));
	//	D2DMANAGER->fillRectangle(RGB(0, 0, 0), _rc[1]);
	//	D2DMANAGER->_renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	//}
	//if (_count > 30)
	//{
	//	D2DMANAGER->_renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(-_angle[2], Point2F(0, 300)));
	//	D2DMANAGER->fillRectangle(RGB(0, 0, 0), _rc[2]);
	//	D2DMANAGER->_renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	//}
	//if (_count > 40)
	//{
	//	D2DMANAGER->_renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(_angle[3], Point2F(0, 300)));
	//	D2DMANAGER->fillRectangle(RGB(0, 0, 0), _rc[3]);
	//	D2DMANAGER->_renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	//}
	//if (_count > 50)
	//{
	//	D2DMANAGER->_renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(_angle[4], Point2F(0, 300)));
	//	D2DMANAGER->fillRectangle(RGB(0, 0, 0), _rc[4]);
	//	D2DMANAGER->_renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	//}
	//if (_count > 60)
	//{
	//	D2DMANAGER->_renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(_angle[5], Point2F(0, 300)));
	//	D2DMANAGER->fillRectangle(RGB(0, 0, 0), _rc[5]);
	//	D2DMANAGER->_renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	//}
	//if (_count > 70)
	//{
	//	D2DMANAGER->_renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(_angle[6], Point2F(0, 300)));
	//	D2DMANAGER->fillRectangle(RGB(0, 0, 0), _rc[6]);
	//	D2DMANAGER->_renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	//}
	//if (_count > 80)
	//{
	//	D2DMANAGER->_renderTarget->SetTransform(D2D1::Matrix3x2F::Rotation(_angle[7], Point2F(0, 300)));
	//	D2DMANAGER->fillRectangle(RGB(0, 0, 0), _rc[7]);
	//	D2DMANAGER->_renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	//}
	//if (_count > 90)
	//{
	//	D2DMANAGER->fillRectangle(RGB(0, 0, 0), _rc[8]);
	//}
}
