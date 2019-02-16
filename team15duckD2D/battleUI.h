#pragma once
#include <queue>

class battleUI
{
private:
	queue<wstring> _script;
	UINT _scriptLength;
	wstring _viewScript;
	float _scriptCount;
	float _scriptDelay;

	bool _isSkip;

	wstring _pokemonName;
	wstring _enemyName;


	UINT _currentSelectMenu;



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

