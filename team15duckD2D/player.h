#pragma once
class player
{
private:
	string _name;			//�̸�
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
};

