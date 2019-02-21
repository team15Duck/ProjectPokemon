#pragma once
#include "gameNode.h"
#include "soundFile.h"
#include <commdlg.h>


#define MOVE_WIDTH_SPEED		800.f
#define MOVE_HEIGHT_SPEED		10.f

#define OPEN_SPEED				400.f
#define POKEMON_NUM				30

#define NIDRUN_MOVE_SPEED		30.f
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
	float				_battleStartTime;	//��Ʋ�� �����Ҷ� �ð�
	float				_curTime;			//����ð� 
	bool				_isStart;

	float				_starMoveWidthSpeed;
	float				_starMoveHeightSpeed;

	float				_pokemonMoveWidthSpeed;
	float				_pokemonMoveHeightSpeed;
	float				_openSpeed;
	float				_alpha, _alpha1, _alpha2, _alpha3, _alpha4;

	bool				_isStop;
	bool				_isPresent;
	//string _imgKeys[3];

	D2D1_RECT_F			_topRect;
	D2D1_RECT_F			_bottomRect;
	D2D1_RECT_F			_ground;

	tagTempPokemon		_pokemon[POKEMON_NUM];
	float				_distance;

	//���� vs �ϵ己
	int					_frameX;			//���� ����� ������X �� ��ȣ
	int					_grassFrameX;		//Ǯ�� ������
	int					_frameCount;		//�������� �ٲ� ������ �����ϱ� ���� ����
	float				_moveUp;			//���� ���� �ö�ö� ������ �ӵ�
	float				_moveDown;			//�ϵ己 �Ʒ��� �������� ������ �ӵ�
		//�������� �ʿ��� ������
	D2D1_RECT_F			_loopRange;			//������ ���� rect
	int					_loopX;				//���� �ӵ�
		//�θ��� ���� ���� ���忡 �ʿ��� ����
	float				_moveWidth;			//���Ұ� �ϵ己�� ��� ������ �ڸ��� ��ġ�ϱ� ���� �ӵ� ����
	float				_phantomPosX;		//������ left ��ǥ
	float				_phantomPosY;		//������ top ��ǥ
	float				_nidrunPosX;		//�ϵ己�� left ��ǥ
	float				_nidrunPosY;		//�ϵ己�� top ��ǥ
	float				_zoomIn;			//���� �� �� �� �����ε�...���� ��� X.

	float				_gravity;			//�ϵ己�� �������� �� �߷°�
	float				_jumpPower;			//�ϵ己�� ������
	int					_nidrunFrame;		//�ϵ己 frame��ȣ
	
	float				_tempRectSpeed;
	D2D1_RECT_F			_orangeRect;		//������ ���� rect
	D2D1_RECT_F			_redRect;	//������ ���� rect
	float				_textMove;
	float				_textPosX;
public:
	startScene();
	~startScene();

	HRESULT init();
	void release();
	void update();
	void render();

};

