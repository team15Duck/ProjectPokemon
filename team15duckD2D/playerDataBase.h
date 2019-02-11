#pragma once
#include "singletonBase.h"
#include "player.h"

class playerDataBase : public singletonBase<playerDataBase>
{
private:

public:
	playerDataBase();
	~playerDataBase();

	HRESULT init();
	void release();
	void update();
	void render();

	void dataLoad(UINT dataNum);						//저장된 데이터를 불러오기 위한 함수
	void dataSet(player* p);							//플레이어에게 현재 데이터를 세팅 해주기 위한 함수  -- 씬마다 플레이어가 새로 생성될 것이기 때문에 플레이어의 주소값을 받아온다
	void dataSave(int num);								//몇번 데이터에 저장할거니



};

