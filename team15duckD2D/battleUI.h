#pragma once
#include <queue>

class battleUI
{
private:

	queue<wstring>		_script;						//스크립트를 저장하는 큐! 여기에 정보가 들어있으면 다른녀석은 아무것도 할수가없지 
	UINT				_scriptLength;					//현재 재생중인 스크립트의 길이 글자를 순서대로 보여주기 위함
	wstring				_viewScript;					//보여줄 스크립트만큼 여기 복사해와서 적을거다
	float				_scriptCount;					//스크립트 재생속도를 체크
	float				_scriptDelay;					//스크립트 재생속도를 결정
	bool				_isSkip;						//이스크립트 스킵가능해?
	wstring				_pokemonName;					//내포켓몬의 이름
	wstring				_enemyName;						//적포켓몬의 이름
	UINT				_currentSelectMenu;				//현재 선택한 메뉴의 숫자는?



public:
	battleUI();
	~battleUI();

	HRESULT init();
	void release();
	void update();
	void render();

	void pushScript(wstring script);

	bool battleSceneUpdate();			//대사 출력될때는 업데이트안되게 불값드릴거임


	void setScriptSkip(bool skip) { _isSkip = skip; }

	void setPokemonName(wstring name) { _pokemonName = name; }
	void setEnemyName(wstring name) { _enemyName = name; }


	UINT getCurrentSelectMenuNum() { return _currentSelectMenu; }
	void setCurrentSelctMenuNum(UINT num) { _currentSelectMenu = num; }



};

