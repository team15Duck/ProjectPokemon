#pragma once
#include "gameNode.h"
#include "soundFile.h"
#include <commdlg.h>

#define MOVE_WIDTH_SPEED		700.f
#define MOVE_HEIGHT_SPEED		20.f

#define OPEN_SPEED				400.f
#define POKEMON_NUM				30

#define NIDRUN_MOVE_SPEED		8.f
#define POKEMON_MATCH_SPEED		400.f

#define ZOOM_IN					400.f

struct tagTempPokemon
{
	float				pokemonAngle;
	int					pokemon;
	float				pokemonPosY;
	float				pokemonPosX;
};
class startScene : public gameNode
{
private:
	string				_bgmKey;
	string				_effectKey;
	string				_soundKeys[3];
	int					_idx;

	float				_gameTime;
	bool				_isStart;

	float				_starMoveWidthSpeed;
	float				_starMoveHeightSpeed;

	float				_pokemonMoveWidthSpeed;
	float				_pokemonMoveHeightSpeed;
	float				_openSpeed;
	float				_alpha, _alpha1, _alpha2;

	bool				_isStop;
	bool				_isPresent;
	//string _imgKeys[3];

	D2D1_RECT_F			_topRect;
	D2D1_RECT_F			_bottomRect;
	D2D1_RECT_F			_ground;

	tagTempPokemon		_pokemon[POKEMON_NUM];
	float				_distance;

	//���� vs �ϵ己
	int					_frameX;
	int					_frameCount;
	float				_moveUp;
	float				_moveDown;
		//�������� �ʿ��� ������
	D2D1_RECT_F			_loopRange;
	int					_loopX;
	int					_loopY;
		//�θ��� ���� ���� ���忡 �ʿ��� ����
	float				_moveWidth;
	float				_phantomPosX;
	float				_phantomPosY;
	float				_nidrunPosX;
	float				_nidrunPosY;		//�ϵ己�� ���������� Y�� �־����.
	float				_zoomIn;
	float				_zoomImgWidthSize;
	float				_zoomImgHeightSize;
	float				_zoomImgLeft;
	float				_zoomImgTop;
	int					_frameInd;
	int					_nidrunFrame;
	


	bool				_isPhantomAtk;
	bool				_isNidrunAtk;

public:
	startScene();
	~startScene();

	HRESULT init();
	void release();
	void update();
	void render();

};

