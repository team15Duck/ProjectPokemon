#include "stdafx.h"
#include "startScene.h"


startScene::startScene()
{
}


startScene::~startScene()
{
}

HRESULT startScene::init()
{
	_bgmKey.clear();
	_effectKey.clear();

	_bgmKey = "startSceneBgm";
	SOUNDMANAGER->addSound(_bgmKey, _vBgmString[1], true, false);
	SOUNDMANAGER->addSound("startBattleBgm", _vBgmString[2], true, false);
	SOUNDMANAGER->addSound("titleBgm", _vBgmString[3], true, false);

	_soundKeys[0] = "startSceneBgm";
	_soundKeys[1] = "startBattleBgm";
	_soundKeys[2] = "titleBgm";

	_idx = 0;
	_gameTime = 0.f;

	_starMoveWidthSpeed = 0.f;
	_starMoveHeightSpeed = 0.f;

	_pokemonMoveWidthSpeed = 0.f;
	_pokemonMoveHeightSpeed = 0.f;
	_openSpeed = 0.f;
	_distance = 0.f;

	_alpha = 1.f;
	_alpha1 = 0.f;
	_alpha2 = 0.f;

	//���ϸ� ���� ��� �̹���
	IMAGEMANAGER->addImage("pokemonInfoImg", L"image/startSceneImg/startImage01.png", 960, 640);

	//�Ϸη� �̹���
	IMAGEMANAGER->addImage("starBackground", L"image/startSceneImg/startImage02.png", 960, 640);
	IMAGEMANAGER->addFrameImage("star", L"image/startSceneImg/Star.png", 608, 76, 8, 1);
	IMAGEMANAGER->addImage("gameFreak", L"image/startSceneImg/gameFreak.png", 576, 76);
	IMAGEMANAGER->addImage("gameFreakLogo", L"image/startSceneImg/gameFreakLogo.png", 96, 224);
	IMAGEMANAGER->addImage("presents", L"image/startSceneImg/presents.png", 266, 32);
	IMAGEMANAGER->addFrameImage("pokemon", L"image/pokemon/pokemon_mini_start.png", 1152, 1088, 18, 17);
	IMAGEMANAGER->addImage("gameFreak", L"image/pokemon/gameFreak.png", 576, 76);
	IMAGEMANAGER->addImage("gameFreakLogo", L"image/pokemon/gameFreakLogo.png", 96, 224);
	IMAGEMANAGER->addImage("presents", L"image/pokemon/presents.png", 266, 32);

	//ȭ�� ��, �Ʒ� � rect
	_topRect = { 0, 0, WINSIZEX, WINSIZEY / 2 };
	_bottomRect = { 0, WINSIZEY / 2, WINSIZEX, WINSIZEY };

	_isStart = false;
	_isStop = false;
	_isPresent = false;

	//�Ϸηտ��� �ѷ��� ���� ���ϸ�� init
	for (int i = 0; i < POKEMON_NUM; ++i)
	{
		_pokemon[i].pokemonAngle = 0;
		_pokemon[i].pokemon = RND->getInt(302);
		_pokemon[i].pokemonPosY = (WINSIZEY / 2 + 50) - RND->getFromIntTo(10, 250);
		_pokemon[i].pokemonPosX = WINSIZEX + (i * 50);
	}

	//���� vs �ϵ己
	IMAGEMANAGER->addImage("background", L"image/startSceneImg/startImage03.png", 960, 640);
	IMAGEMANAGER->addFrameImage("introForest", L"image/startSceneImg/grassFrame.png", 2880, 640, 3, 1);
	IMAGEMANAGER->addImage("meeting", L"image/startSceneImg/startImage04.png", 960, 640); //->�����ؾ��ϴ� �̹���
	IMAGEMANAGER->addImage("battleBackground2nd", L"image/startSceneImg/startImage05.png", 960, 640);
	IMAGEMANAGER->addImage("startBattleGrass", L"image/startSceneImg/startBattleGrass.png", 960, 640);
	IMAGEMANAGER->addImage("phantom1", L"image/startSceneImg/Phantom1.png", 380, 380);
	IMAGEMANAGER->addImage("nidrun1", L"image/startSceneImg/nidrun1.png", 380, 380);
	IMAGEMANAGER->addImage("phantom2", L"image/startSceneImg/Phantom2.png", 380, 380);
	IMAGEMANAGER->addImage("nidrun2", L"image/startSceneImg/nidrun2.png", 440, 404);
	IMAGEMANAGER->addFrameImage("phantomIdle", L"image/startSceneImg/PhantomFrame.png", 1520, 380, 4, 1);
	//IMAGEMANAGER->addFrameImage("phantomIdle", L"image/startSceneImg/PhantomIdle.png", 760, 380, 2, 1);
	//IMAGEMANAGER->addFrameImage("phantomAtk", L"image/startSceneImg/phantomAtk.png", 760, 380, 2, 1);
	IMAGEMANAGER->addFrameImage("nidrunFrame", L"image/startSceneImg/nidrunFrame.png", 1350, 270, 5, 1);
	IMAGEMANAGER->addImage("attack", L"image/startSceneImg/attackEffect.png", 88, 304);
	IMAGEMANAGER->addImage("grass", L"image/startSceneImg/zOderGrass.png", 240, 104);
	
	//�ð��� ��� �׳� ��ũ�������� ��ü��
	IMAGEMANAGER->addImage("tempStartImg3", L"image/tempStartImg3.png", 960, 640);


	_frameX = 0;
	_nidrunFrame = 0;
	_frameCount = 0;

	_moveUp = 225.f;
	_moveDown = 95.f;

	_loopRange = { 0, 0, 960, 640 };
	_loopX = 0;
	_loopY = 0;
	
	_moveWidth = 0.f;
	_phantomPosX = WINSIZEX - 400;
	_phantomPosY = 130;
	_nidrunPosX = 50;
	_nidrunPosY = 240;

	_zoomImgLeft = 0.f;
	_zoomImgTop = 0.f;

	_zoomImgWidthSize = 0.f;
	_zoomImgHeightSize = 0.f;

	_isPhantomAtk = false;
	_isNidrunAtk = false;
	_frameInd = 0;



	return S_OK;
}

void startScene::release()
{
}

void startScene::update()
{
	_gameTime += TIMEMANAGER->getElapsedTime();
	if (_gameTime < 2.f)
		return;

	if (3 <= _idx)
		return;

	if (!_isStart)
	{
		SOUNDMANAGER->play(_soundKeys[0]);
		_isStart = true;
	}
	//�Ϸη� �κ�
	if (_idx == 0)
	{
		_openSpeed += TIMEMANAGER->getElapsedTime() * OPEN_SPEED;

		_starMoveWidthSpeed += TIMEMANAGER->getElapsedTime() * MOVE_WIDTH_SPEED;
		_starMoveHeightSpeed += TIMEMANAGER->getElapsedTime() * MOVE_HEIGHT_SPEED;

		_pokemonMoveWidthSpeed = TIMEMANAGER->getElapsedTime() * MOVE_WIDTH_SPEED;
		_pokemonMoveHeightSpeed = TIMEMANAGER->getElapsedTime() * MOVE_HEIGHT_SPEED;
		//������� ���������� ���ϸ� ������ ���ؼ� ������ � ��Ʈ�� ������
		if (_topRect.bottom <= 120)
			_openSpeed = 0;
		if (_bottomRect.top >= WINSIZEY - 120)
			_openSpeed = 0;

		_topRect.bottom -= _openSpeed;
		_bottomRect.top += _openSpeed;
		for (int i = 0; i < POKEMON_NUM; ++i)
		{
			_pokemon[i].pokemonAngle += RND->getFromIntTo(2, 4);
			_pokemon[i].pokemonPosX -= _pokemonMoveWidthSpeed;
			_pokemon[i].pokemonPosY += _pokemonMoveHeightSpeed;
			if (WINSIZEX - _pokemon[i].pokemonPosX > WINSIZEX)
			{
				//���ϸ��� ���� �Ÿ��� �̵��ϰ� ���� ���̻� �������� ����
				_pokemonMoveWidthSpeed = 0;
				_pokemonMoveHeightSpeed = 0;
				_isStop = true;
			}
		}
		//���ϸ��� ���̻� �ȿ����϶�
		if (_isStop)
		{
			//���ϸ��� ���� �����
			_alpha -= 0.005f;
			//gameFreak �ܾ�� ������
			_alpha1 += 0.005f;
			//�ܾ ��������
			if (_alpha1 >= 0.8f)
			{
				//present ��� �ܾ �������� ������
				_isPresent = true;
				_alpha2 += 0.003f;
			}
		}
	}
	//���� vs �ϵ己
	if (_idx == 1)
	{
		//������� ���������� ���ϸ� ������ ���ؼ� � ��Ʈ �����
		_topRect.bottom = 130;
		_bottomRect.top = WINSIZEY - 130;
	
		//��Ȳ�� ���
		_moveUp -=  TIMEMANAGER->getElapsedTime() * NIDRUN_MOVE_SPEED;
		_moveDown += TIMEMANAGER->getElapsedTime() * NIDRUN_MOVE_SPEED;
		
		_ground = { 0, 0, 960, 640 };
		_loopX += 3;
		//++_loopY;
		++_frameCount;
		//���� ���̵� ������
		if ( _frameCount % 5== 0)
		{
			_frameX++;
			if (_frameX >= 2)
			{
				_frameX = 0;
			}
		}
		//���� �ϴ� �κ�
		_zoomImgWidthSize = IMAGEMANAGER->findImage("background")->GetWidth();
		_zoomImgHeightSize = IMAGEMANAGER->findImage("background")->GetHeight();
		//�����ϰ�ʹٰ������....//todo
		if (_frameCount > 80 && _frameCount < 90)
		{
			_zoomIn = TIMEMANAGER->getElapsedTime() * ZOOM_IN;
			_zoomImgLeft -= _zoomIn;
			_zoomImgTop -= _zoomIn;
			//todo
			_zoomImgWidthSize += _zoomIn;
			_zoomImgHeightSize += _zoomIn;
		}
		//�θ��� ������ ���۵Ǵ� �ð� : _frameCount = 200
		else if (_frameCount >= 200 && _frameCount < 280)
		{
			//�� ���ϸ��� �糡���� �ڱ���ġ�� �̵���
			_moveWidth = TIMEMANAGER->getElapsedTime() * POKEMON_MATCH_SPEED;
			if (_phantomPosX <= 40)
			{
				//��ġ�� ���� ��ž!
				_moveWidth = 0;
			}
			//��ġ�� �̵�
			_phantomPosX -= _moveWidth;
			_nidrunPosX += _moveWidth;
			//���� ����ϴٰ� ������ ���� ����
			if (_frameCount >= 260)
			{
				_phantomPosX += 5;
				if (_phantomPosX <= 150)
				{
					_phantomPosX -= 5;
				}
				//�̶� �ȵ��!
				if(_frameCount >= 261  && _frameCount < 270)
				{	
					_frameX = 2;
					_isPhantomAtk = true;
				}
				//�� ������!!
				else if (_frameCount >= 270)
				{
					_frameX = 3;
					//�̶� �ϵ己�� ���ؿ�
					_nidrunFrame = 1;
				}
				//���� ������ ���̵�� �ǵ�����!
				if (_frameX == 3)
				{
					_frameX = 0;
				}
				
			}
		}
		else if (_frameCount >= 280)
		{
			_isPhantomAtk = false;
			int jumpRange = 20;

			_nidrunPosY -= 5;
			_nidrunPosX += 5; 
			jumpRange -= 5;
			if (_nidrunPosY <= 150)
			{
				//_nidrunPosY += 5;
				if (_nidrunPosY >= 240)
				{
					_nidrunPosY = 240;
					
				}
			}
			
			_nidrunFrame = 3;
		}
	}

	if (KEYMANAGER->isOnceKeyDown('Z') || !SOUNDMANAGER->isPlaySound(_soundKeys[_idx]))
	{
		SOUNDMANAGER->stop(_soundKeys[_idx]);
		++_idx;
		if (3 <= _idx)
		{
			SCENEMANAGER->changeScene("mapTestScene");
			return;
		}
		SOUNDMANAGER->play(_soundKeys[_idx]);
	}
}

void startScene::render()
{
	if (_gameTime < 2.f)
		IMAGEMANAGER->render("pokemonInfoImg");
	else
	{
		//�Ϸη� �κ�
		if (_idx == 0)
		{
			IMAGEMANAGER->findImage("starBackground")->render(1.0f);
			//ū��
			IMAGEMANAGER->frameRender("star", (WINSIZEX - 50) - _starMoveWidthSpeed, (WINSIZEY / 2) + _starMoveHeightSpeed, 0, 0);
			for (int i = 0; i < POKEMON_NUM; ++i)
			{

				if (_isStop)
				{
					IMAGEMANAGER->findImage("pokemon")->frameRenderAngle(_pokemon[i].pokemonPosX
																		 , _pokemon[i].pokemonPosY
																		 , _pokemon[i].pokemon % 18
																		 , _pokemon[i].pokemon / 18
																		 , _pokemon[i].pokemonAngle, _alpha);
					if (_isPresent)
					{
						IMAGEMANAGER->findImage("presents")->render(WINSIZEX / 2 - (IMAGEMANAGER->findImage("presents")->GetWidth() / 2)
																	, (WINSIZEY / 2 + 100) - (IMAGEMANAGER->findImage("presents")->GetHeight() / 2)
																	, _alpha2);
						IMAGEMANAGER->findImage("gameFreakLogo")->render(WINSIZEX / 2 - (IMAGEMANAGER->findImage("gameFreakLogo")->GetWidth() / 2)
																		 , (WINSIZEY / 2 - 50) - (IMAGEMANAGER->findImage("gameFreakLogo")->GetHeight() / 2)
																		 , _alpha2);
					}

					IMAGEMANAGER->findImage("gameFreak")->render(WINSIZEX / 2 - (IMAGEMANAGER->findImage("gameFreak")->GetWidth() / 2)
																 , (WINSIZEY / 2) - (IMAGEMANAGER->findImage("gameFreak")->GetHeight() / 2)
																 , _alpha1);
				}
				else
				{
					//����� �ѷ��� ���ϸ� �̹��� ���
					IMAGEMANAGER->findImage("pokemon")->frameRenderAngle(_pokemon[i].pokemonPosX
																		 , _pokemon[i].pokemonPosY, _pokemon[i].pokemon % 18
																		 , _pokemon[i].pokemon / 18
																		 , _pokemon[i].pokemonAngle);

				}
				D2DMANAGER->fillRectangle(RGB(0, 0, 0), _topRect);
				D2DMANAGER->fillRectangle(RGB(0, 0, 0), _bottomRect);
			}
		}
		//���� vs �ϵ巳
		else if (_idx == 1)
		{
			if (_frameCount <= 80)
			{
				//�����̴� Ǯ
				IMAGEMANAGER->findImage("background")->render(1);
				IMAGEMANAGER->findImage("introForest")->frameRender(0, 0, _frameX, 0);
			}
			else if (_frameCount > 80 && _frameCount < 90)
			{
				//�� ����� �κ�
				//todo
				//���� ũ�� ��� - �׷��� x��ǥ, y��ǥ, ����� �ʺ�, ����� ����, ����
				//void render(float destX, float destY, int showWidth, int showHeight, float alpha = 1.0f);
				//IMAGEMANAGER->findImage("background")->render(_zoomImgLeft, _zoomImgTop,
				//											  _zoomImgWidthSize, _zoomImgHeightSize);
				IMAGEMANAGER->findImage("background")->render(0, 0,
															  WINSIZEX, WINSIZEY);
				IMAGEMANAGER->findImage("introForest")->frameRender(0, 0, _frameX, 0);
			}
			//���Ұ� �ϵ己�� ������ ���
			else if (_frameCount >= 90 && _frameCount < 135)
			{
				//IMAGEMANAGER->findImage("meeting")->render(1);
				IMAGEMANAGER->findImage("meeting")->loopRender(_loopRange, _loopX, _loopY);

				
				IMAGEMANAGER->findImage("phantom1")->render(130, 130);
				IMAGEMANAGER->findImage("nidrun1")->render(500, 200);
				
				IMAGEMANAGER->findImage("startBattleGrass")->loopRender(_loopRange, _loopX, 0);
					//if(IMAGEMANAGER->findImage("startBattleGrass"))
				
			}
			//��Ȳ����濡�� ���� °������
			else if (_frameCount >= 135 && _frameCount <200)
			{
				D2DMANAGER->fillRectangle(RGB(0, 144, 248), _ground);
				IMAGEMANAGER->findImage("nidrun2")->render(WINSIZEX - 440, _moveDown );
				IMAGEMANAGER->findImage("phantom2")->render(20, _moveUp);
			}
			//���� ���ֺ��� ���� ���� ��ٸ�
			else if(_frameCount >= 200 < _frameCount < 400)
			{
				IMAGEMANAGER->findImage("battleBackground2nd")->loopRender(_loopRange, _loopX, _loopY);
				IMAGEMANAGER->findImage("nidrunFrame")->frameRender(_nidrunPosX, _nidrunPosY, _nidrunFrame, 0);
				IMAGEMANAGER->findImage("phantomIdle")->frameRender(_phantomPosX, _phantomPosY, _frameX, 0);
				IMAGEMANAGER->findImage("grass")->render(WINSIZEX - _loopX, 410);
				if (_isPhantomAtk && _frameCount >= 270)
				{
					IMAGEMANAGER->findImage("attack")->render(400, 190);

				}

			}
			//else if (_frameCount >= 400)
			//{
			//	
			//}

			//ȭ�� ��, �Ʒ� � ��Ʈ
			D2DMANAGER->fillRectangle(RGB(0, 0, 0), _topRect);
			D2DMANAGER->fillRectangle(RGB(0, 0, 0), _bottomRect);
		}
		else if (_idx == 2)
		{
			IMAGEMANAGER->findImage("tempStartImg3")->render(1);
		}
	}
}
