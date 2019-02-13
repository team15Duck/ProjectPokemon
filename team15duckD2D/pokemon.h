#pragma once
#include "pokemonSkill.h"
#include "item.h"
#include <functional>


#define POKEMON_SKILL_MAX_COUNT 4			// �ִ� ������ �� �ִ� ��ų�� ��
#define PROGRESSING_TERM 0.1

// ���̺�� ������
typedef struct tagPokemonPackage
{
	unsigned int idNo;				// ���� ��ȣ
	unsigned int index;				// ���� ��ȣ

	const char* nickName;			// �̸�
	const char* trainerNote;		// Ʈ���̳� ��Ʈ

	unsigned int itemType;			// �����ϰ� �ִ� �������� ��ȣ(Ÿ��)

	unsigned int level;				// ����
	unsigned int currentExp;		// ���� ����ġ

	unsigned int upsetConditionType;	// �����̻�
	unsigned int upsetConditionApplyValue;	// �����̻�
	unsigned int upsetConditionReleseValue;	// �����̻�
	
	// ���� ���°���
	unsigned int hp;		// ü��
	unsigned int attk;		// ���ݷ�
	unsigned int dex;		// ����
	unsigned int spAttk;	// Ư�� ���ݷ�
	unsigned int spDex;		// Ư�� ����

	unsigned int speed;		// �ӵ�
	
	int skillIds[POKEMON_SKILL_MAX_COUNT];		// ��ų ��ȣ
	int currentPPs[POKEMON_SKILL_MAX_COUNT];	// ���� ���� ��ų�� ��

}pmPack;

class pokemonInfo;

// ���ϸ�
class pokemon
{
private:
	//typedef function<void(void)> CALLBACK_FUNCTION;
	enum PROGRESSING_TYPE
	{
		PROGRESSING_VALUE,
		PROGRESSING_SKILL,

		PROGRESSING_NONE,
		PROGRESSING_COUNT = PROGRESSING_NONE,
	};

private:

	unsigned int _idNo;							// ���� ��ȣ
	POKEMON _index;								// ���� ��ȣ

	string _nickName;							// �г���
	string _trainerNote;						// Ʈ���̳� ��Ʈ

	ITEM_TYPE _ownerItemType;					// �����ϰ� �ִ� ������

	unsigned int _level;						// ����
	unsigned int _currentLvExp;					// ���� ���������� ���� ����ġ
	unsigned int _currentExp;					// ���� ���� ����ġ
	unsigned int _nextLvExp;					// ���� �������� ���� ����ġ

	bool _isAwake;								// ���� �ִ°�, �������� �ʾҴ°�
	bool _isMyPokemon;							// �÷��̾��� ���ϸ��ΰ�

	pokemonStatus _beforeLvStatus;				// ���� lv�� status
	pokemonStatus _currentLvStatus;				// ���� lv�� status
	pokemonStatus _nowStatus;					// ���� status

	int _displayHp;								// ����� hp
	int _displayExp;							// ����� ����ġ

	float _displayTime;							// ���� �� �ð�
	bool _isIdle;								// �ൿ ������ΰ�
	PROGRESSING_TYPE	_progressingType;

	pokemonUC	  _upsetCondition;				// ���� �̻�
	pokemonSkill _skills[POKEMON_SKILL_MAX_COUNT]; // ��ų
	
	image*		_img;	// �̹���
	pokemon* _target;	// ���̴�
	function<void(void)> _function;				// ����� �Լ�

	float _destX, _destY;						// ���� ��ġ
	int _frameX, _frameY;						// ���� ������ ��ǥ

public:
	pokemon();
	~pokemon();

	// ������ȣ, ���ϸ� ��ȣ, ����, �÷��̾� ���ϸ�?, ���� letf, ���� top
	HRESULT init(int idNo, POKEMON index, int level, bool isMyPokemon);
	void release();
	void update();
	void render();

	// ����� ������ ����
	pmPack* makeSavePack();
	// �ε�� ������ ����
	void loadSavePack(pmPack* pack);
	

	// 1. �����ϰ� �ִ� ������ ��� : ��������� return true
	bool useOwnerItem();
	// 2. ���� �̻� ����
	void applyUpsetCondition();
	// 3. ������ ���
	// 3. �� ��°(idx) ��ų ���
	void useSkill(int idx);

	
	// ���� �� : ����ġ ������ �ܿ� ���� ������ �ϴ� ��� ��� ex. �̻��� ���� ���
	// ���� ���� ������ return true, �׷��� �ʴٸ� return false
	bool levelUpForce();
	
	// ������ ����
	void takeDamage(int value);
	// hp full ȸ��
	void fillHp();
	// hp ȸ��
	void hillHp(int value);
	// ����ġ ȹ��
	void gainExp(int exp);
	// ���� ������ ����
	ITEM_TYPE withdrawItem();
	// �����̻� ����
	void clearUpsetCondtion();
	// ��ų ��ü
	void changeSkill(int idx, int skillId);
	// ü�°��� ���� ���� : ������ ��ų ������ �������� �������� �Դ� �� ó�� ���̵���.
	void startTakeDamageDisplay();
	
	//============================================== set
	
	// �� ���ϸ� ����
	void setTargetPokemon(pokemon* pm) { _target = pm; }

	// �����̻� ����
	void setUpsetCondition(pokemonUC upsetCondition){ _upsetCondition = upsetCondition; }
	// ���� ������ ����
	void setOwnerItem(ITEM_TYPE itemType)	{ _ownerItemType = itemType; }
	// �г���
	void setNicName(string nickName)		{ _nickName = nickName; }
	// Ʈ���̳� ��Ʈ
	void setTrainerNote(string trainerNote) { _trainerNote = trainerNote; }

	//============================================== get
	
	// �ൿ ������ΰ� : �ൿ ��� ���϶��� ���� �ൿ�� �� �� �ִ�.
	bool isIdle()				{ return _isIdle;}

	// �����ִ°�
	bool isAwake()				{ return _isAwake;}
	// �÷��̾� ���ϸ��ΰ�		
	bool isMyPokemon()			{ return _isMyPokemon;}

	// ������ȣ
	unsigned int getIdNo()		{ return _idNo; }
	// ���ϸ� ��ȣ
	POKEMON getPokeminIndex()	{ return _index; }
	// Ʈ���̳� ��Ʈ
	string getTrainerNote()		{ return _trainerNote; }
	// �����ϰ� �ִ� ������ Ÿ��
	ITEM_TYPE getOwnerItemType(){ return _ownerItemType;}

	// ����
	unsigned int getLevel()		{ return _level;}
	
	// ���� ����ġ
	unsigned int getCurrentExp()		{ return _currentExp - _currentLvExp; }
	// ���� �������� ����ġ
	unsigned int getNextExp()			{ return _nextLvExp - _currentLvExp; }
	// �������� �ʿ��� ���� ����ġ
	unsigned int getRemainExp()			{ return _nextLvExp - _currentExp; }
	
	// ���� ������ ����ġ
	unsigned int getCurrentTotalExp()	{ return _currentExp; }
	// ���� ���� ���� ����ġ
	unsigned int getNextTotalExp()		{ return _nextLvExp; }
	
	// ���� ü��
	int getHp()			{ return _nowStatus.hp; }
	// Ǯ ü��
	int getMaxHp()		{ return _nowStatus.hp;}
	// ���� ���ݷ�
	int getAttk()		{ return _nowStatus.attk;}
	// ���� ����
	int getDex()		{ return _nowStatus.dex; }
	// ���� Ư�� ���ݷ�
	int getSpAttk()		{ return _nowStatus.spAttk; }
	// ���� Ư�� ����
	int getSpDex()		{ return _nowStatus.spDex; }
	// ���� �ӵ�
	int getspeed()		{ return _nowStatus.speed;}
	// �����̻� 
	POKEMON_UPSET_CONDITION getUpsetCondition() { return _upsetCondition.type; }
	// ��ų
	const pokemonSkill* getPokemonSkills() { return _skills; }

	// ����� hp
	int getDisplayHp()	{ return _displayHp; }
	//  ����� exp
	int getDisplayExp() { return _displayExp; }

private:
	// ����ġ�� ���� ������
	void levelUp();
	// �ɷ�ġ ����
	void settingStatus();
	// ��ȭ
	void evolution();
	// �������� ���� ��ų ȹ��
	void gainSkill();
	// ����
	void attack(int value, pokemonUC* upsetCondition);

	
	
	// ���� ����
	void startProgessing(function<void(void)> func, PROGRESSING_TYPE type);
	// ���� ��
	void endProgressing();

	// hp ��ȭ
	void progressingIncreaseHp();
	void progressingDecreaseHp();
	// exp ��ȭ
	void progressingIncreseExp(void);
	// ��ų ����Ʈ
	void progressintSkillEffect(int idx);
	// �����̻� ȿ�� ����
	void progressingApplyUpsetCondition();
	
	// ������ ���
	int calculateAttkValue(int skillIdx);

};

