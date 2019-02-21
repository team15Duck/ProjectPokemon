#pragma once
#include <queue>
#include <vector>
#include "possessionPokemon.h"

typedef struct tagPokemonSkillUIInfo
{
	wstring skillName;
	UINT currentPP;
	UINT maxPP;
	wstring type;
}SKILLUI;

enum BATTLE_UI
{
	BATTLE_UI_SKILL,
	BATTLE_UI_BAG,
	BATTLE_UI_POKEMON,
	BATTLE_UI_RUN,
	BATTLE_UI_NONE
};

class pokemon;
class battleUI
{
private:


	//////////////////////////////////////////////////스크립트///////////////////////////////////////////////////////////////
	queue<wstring>		_script;						//스크립트를 저장하는 큐! 여기에 정보가 들어있으면 다른업데이트막음
	UINT				_scriptLength;					//현재 재생중인 스크립트의 길이 글자를 순서대로 보여주기 위함
	wstring				_viewScript;					//보여줄 스크립트만큼 여기 복사해와서 적을거다
	float				_scriptCount;					//스크립트 재생속도를 체크
	float				_scriptDelay;					//스크립트 재생속도를 결정
	bool				_isSkip;						//이스크립트 스킵가능해?
	wstring				_pokemonName;					//내포켓몬의 이름
	wstring				_enemyName;						//적포켓몬의 이름
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




	UINT				_currentSelectMenu;				//현재 선택한 메뉴의 숫자는?
	bool				_isEscape;						//도망?
	bool				_isPlayerTurn;					//플레이어 행동 턴?




	///////////////////////////////////////////////////////스킬///////////////////////////////////////////////////////////////
	vector<SKILLUI>		_skillUI;						//스킬의정보를담고있는 구조체의 벡터  최대사이즈는 4로 제한한다
	UINT				_currentSelectSkill;			//현재 어떤스킬을 선택하고 있니?
	bool				_isBattle;						//배틀중인가
	bool				_isKeyDownZ;					//Z키가 눌렸는가
	BATTLE_UI			_currentMenu;					//현재 메뉴 상태
	pokemon*			_myPokemon;						//정보를 출력하기 위함
	pokemon*			_enemyPokemon;					//정보를 출력하기 위함
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////포켓몬/////////////////////////////////////////////////
	UINT				_pokemonSelectNum;				//내가 고른 숫자
	P_POKEMON_STATE		_ppState;						//어떤 메뉴	보여주니
	P_POKEMON_SELECT	_ppselect;						//어떤놈골랏니
	P_SUB_MENU_SELECT	_psmselect;						//서브메뉴목록
	P_LOOK_POKEMON		_plpokemon;						//인포목록
	bool				_isSubMenu;						//서브메뉴 켰어?
	UINT				_currentPokemonNum;				//현재 밖에있는 포켓몬 숫자
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////가방//////////////////////////////////////////////////

	UINT				_bagSelectNum;					//가방 몇번째꺼 선택함?
	item*				_item[39];
	bool				_itemSubMenuOn;	

	UINT				_subMenuSelectNum;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







public:
	battleUI();
	~battleUI();

	HRESULT init();
	void release();
	void update();
	void render();

	item* getItemArray(ITEM_TYPE type) { return _item[type]; }

	UINT getBagSelectNum() { return _bagSelectNum; }
	void setBagSelectNum(int num) { _bagSelectNum = num; }
	
	bool getItemSubMenuOn() { return _itemSubMenuOn; }
	void setItemSubMenuOn(bool on) { _itemSubMenuOn = on; }

	UINT getSubMenuSelectNum() { return _subMenuSelectNum; }
	void setSubMenuSelectNum(int num) { _subMenuSelectNum = num; }




	P_POKEMON_STATE		getPPState() { return _ppState; }
	void				setPPState(P_POKEMON_STATE state) { _ppState = state; }

	P_POKEMON_SELECT	getPPSelect() { return _ppselect; }
	void				setPPSelect(P_POKEMON_SELECT select) { _ppselect = select; }

	P_SUB_MENU_SELECT	getSubMenu() { return _psmselect; }
	void				setSubMenu(P_SUB_MENU_SELECT sub) { _psmselect = sub; }

	P_LOOK_POKEMON		getLookPokemon() { return _plpokemon; }
	void				setLookPokemon(P_LOOK_POKEMON lp) { _plpokemon = lp; }

	bool				getIsSubMenu() { return _isSubMenu; }
	void				setIsSubMenu(bool isSub) { _isSubMenu = isSub; }


	UINT				getCurrentPokemonNum() { return _currentPokemonNum; }
	void				setCurrentPokemonNum(UINT num) { _currentPokemonNum = num; }

	void skillUIClear() { _skillUI.clear(); }
	void addSkill(wstring skillName, UINT cPP, UINT mPP, wstring type)
	{
		SKILLUI skill;
		skill.skillName = skillName;
		skill.currentPP = cPP;
		skill.maxPP = mPP;
		skill.type = type;
		_skillUI.push_back(skill);
	}
	UINT getCurrentPP(UINT skillNum)
	{
		if (skillNum < 0 || skillNum >= _skillUI.size()) return 0;

		_skillUI[skillNum].currentPP;
	}
	void setCurrentPP(UINT skillNum)
	{
		if (skillNum < 0 || skillNum >= _skillUI.size()) return;

		_skillUI[skillNum].currentPP--;
		if (_skillUI[skillNum].currentPP < 0) _skillUI[skillNum].currentPP = 0;
	}
	UINT getSkillSize() { return _skillUI.size(); }


	BATTLE_UI getCurrentMenu() { return _currentMenu; }
	void setCurrentMenu(BATTLE_UI cMenu) { _currentMenu = cMenu; }


	void pushScript(wstring script);

	bool battleSceneUpdate();			//대사 출력될때는 업데이트안되게 불값드릴거임


	void setScriptSkip(bool skip) { _isSkip = skip; }

	void setPokemonName(wstring name) { _pokemonName = name; }
	void setEnemyName(wstring name) { _enemyName = name; }


	UINT getCurrentSelectMenuNum() { return _currentSelectMenu; }
	void setCurrentSelctMenuNum(UINT num) { _currentSelectMenu = num; }

	UINT getCurrentSelectSkill() { return _currentSelectSkill; }
	void setCurrentSelectSkill(UINT num) { _currentSelectSkill = num; }


	void setMyPokemonMemoryAdressLink(pokemon* m) { _myPokemon = m; }
	void setEnemyPokemonMemoryAdressLink(pokemon* e) { _enemyPokemon = e; }

	void setIsPlayerTurn(bool isPlayerTurn) { _isPlayerTurn = isPlayerTurn;	}
	void setIsBattle(bool isBattle)			{ _isBattle = isBattle;			}

	bool isKeyDownKeyZ() { return _isKeyDownZ; }
};

