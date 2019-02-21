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
	float				_battleStartTime;	//배틀씬 시작할때 시간
	float				_curTime;			//현재시간 
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

	//팬텀 vs 니드런
	int					_frameX;			//현재 재생될 프레임X 의 번호
	int					_grassFrameX;		//풀의 프레임
	int					_frameCount;		//프레임이 바뀔 간격을 지정하기 위한 변수
	float				_moveUp;			//팬텀 위로 올라올때 움직일 속도
	float				_moveDown;			//니드런 아래로 내려갈때 움직일 속도
		//루프돌때 필요한 변수들
	D2D1_RECT_F			_loopRange;			//루프돌 범위 rect
	int					_loopX;				//루프 속도
		//두마리 대전 직전 등장에 필요한 변수
	float				_moveWidth;			//팬텀과 니드런이 대결 직전에 자리에 위치하기 위한 속도 변수
	float				_phantomPosX;		//팬텀의 left 좌표
	float				_phantomPosY;		//팬텀의 top 좌표
	float				_nidrunPosX;		//니드런의 left 좌표
	float				_nidrunPosY;		//니드런의 top 좌표
	float				_zoomIn;			//줌인 할 때 쓸 변수인데...아직 사용 X.

	float				_gravity;			//니드런이 점프했을 때 중력값
	float				_jumpPower;			//니드런의 점프력
	int					_nidrunFrame;		//니드런 frame번호
	
	float				_tempRectSpeed;
	D2D1_RECT_F			_orangeRect;		//루프돌 범위 rect
	D2D1_RECT_F			_redRect;	//루프돌 범위 rect
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

