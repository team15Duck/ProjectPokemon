#pragma once
#include "gameNode.h"

#define LOADINGMAX 236

//��絥���� �ε��ϰ� ��ŸƮ������ �Ѿ
class loadingScene : public gameNode
{
private:
	image* _backGround;
	animation* _ani;

	float _loadingBar;


public:
	loadingScene();
	~loadingScene();

	int _currentCount;	//�ܺο��� �����Ҽ��ְ� �صд�

	HRESULT init();
	void release();
	void update();
	void render();
};

static DWORD CALLBACK ThreadFunction(LPVOID lpParameter);

