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


	//////////////////////////////////////////////////��ũ��Ʈ///////////////////////////////////////////////////////////////
	queue<wstring>		_script;						//��ũ��Ʈ�� �����ϴ� ť! ���⿡ ������ ��������� �ٸ�������Ʈ����
	UINT				_scriptLength;					//���� ������� ��ũ��Ʈ�� ���� ���ڸ� ������� �����ֱ� ����
	wstring				_viewScript;					//������ ��ũ��Ʈ��ŭ ���� �����ؿͼ� �����Ŵ�
	float				_scriptCount;					//��ũ��Ʈ ����ӵ��� üũ
	float				_scriptDelay;					//��ũ��Ʈ ����ӵ��� ����
	bool				_isSkip;						//�̽�ũ��Ʈ ��ŵ������?
	wstring				_pokemonName;					//�����ϸ��� �̸�
	wstring				_enemyName;						//�����ϸ��� �̸�
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




	UINT				_currentSelectMenu;				//���� ������ �޴��� ���ڴ�?
	bool				_isEscape;						//����?
	bool				_isPlayerTurn;					//�÷��̾� �ൿ ��?




	///////////////////////////////////////////////////////��ų///////////////////////////////////////////////////////////////
	vector<SKILLUI>		_skillUI;						//��ų������������ִ� ����ü�� ����  �ִ������� 4�� �����Ѵ�
	UINT				_currentSelectSkill;			//���� ���ų�� �����ϰ� �ִ�?
	bool				_isBattle;						//��Ʋ���ΰ�
	bool				_isKeyDownZ;					//ZŰ�� ���ȴ°�
	BATTLE_UI			_currentMenu;					//���� �޴� ����
	pokemon*			_myPokemon;						//������ ����ϱ� ����
	pokemon*			_enemyPokemon;					//������ ����ϱ� ����
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////���ϸ�/////////////////////////////////////////////////
	UINT				_pokemonSelectNum;				//���� �� ����
	P_POKEMON_STATE		_ppState;						//� �޴�	�����ִ�
	P_POKEMON_SELECT	_ppselect;						//�������
	P_SUB_MENU_SELECT	_psmselect;						//����޴����
	P_LOOK_POKEMON		_plpokemon;						//�������
	bool				_isSubMenu;						//����޴� �׾�?
	UINT				_currentPokemonNum;				//���� �ۿ��ִ� ���ϸ� ����
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////����//////////////////////////////////////////////////

	UINT				_bagSelectNum;					//���� ���°�� ������?
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

	bool battleSceneUpdate();			//��� ��µɶ��� ������Ʈ�ȵǰ� �Ұ��帱����


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

