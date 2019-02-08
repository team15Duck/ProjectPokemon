#pragma once

enum PLAYER_STATE
{
	PS_IDLE_LEFT,		PS_IDLE_UP,			PS_IDLE_RIGHT,			PS_IDLE_DOWN,			//������				
	PS_MOVE_LEFT,		PS_MOVE_UP,			PS_MOVE_RIGHT,			PS_MOVE_DOWN,			//�̵�
	PS_FASTMOVE_LEFT,	PS_FASTMOVE_UP,		PS_FASTMOVE_RIGHT,		PS_FASTMOVE_DOWN,		//�����̵�
	PS_BICYCLE_LEFT,	PS_BICYCLE_UP,		PS_BICYCLE_RIGHT,		PS_BICYCLE_DOWN,		//������
};

class player
{
private:
	string _name;			//�̸�
	bool _isMan;			//���ڴ�?
	int _playTime;			//�÷���Ÿ��
	float _posX;			//��ǥ
	float _posY;			//��ǥ
	int _tileX;				//���� ��ġ�ϰ� �ִ� Ÿ�� ��ȣ
	int _tileY;				//���� ��ġ�ϰ� �ִ� Ÿ�� ��ȣ



public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	void render();

	void aniSetUp();
	void dataLoad();
};

