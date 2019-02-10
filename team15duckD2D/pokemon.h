#pragma once
#include "pokemonInfo.h"
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

	string nickName;				// �̸�
	string trainerNote;				// Ʈ���̳� ��Ʈ

	unsigned int itemIdx;			// �����ϰ� �ִ� �������� ��ȣ

	unsigned int level;				// ����
	unsigned int currentExp;		// ���� ����ġ

	unsigned int upsetConditionType;	// �����̻�
	unsigned int upsetConditionValue;	// �����̻�
	unsigned int upsetConditionCount;	// �����̻�
	
	// ���� ���°���
	unsigned int hp;		// ü��
	unsigned int attk;		// ���ݷ�
	unsigned int dex;		// ����
	unsigned int spAttk;	// Ư�� ���ݷ�
	unsigned int spDex;		// Ư�� ����

	unsigned int speed;		// �ӵ�
	
	int skillIds[POKEMON_SKILL_MAX_COUNT];		// ��ų ��ȣ
	int currentPPs[POKEMON_SKILL_MAX_COUNT];	// ���� ���� ��ų�� ��
	int maxPPs[POKEMON_SKILL_MAX_COUNT];		// �ִ� ��ų�� ��

}pmPack;

// ���ϸ�
class pokemon
{
private:
	//typedef function<void(void)> CALLBACK_FUNCTION;

private:

	unsigned int _idNo;							// ���� ��ȣ
	POKEMON _index;								// ���� ��ȣ

	string _nickName;							// �г���
	string _trainerNote;						// Ʈ���̳� ��Ʈ

	item* _item;								// �����ϰ� �ִ� ������

	unsigned int _level;						// ����
	unsigned int _currentExp;					// ���� ����ġ
	unsigned int _nextExp;						// ���� �������� �ʿ��� ����ġ

	bool _isAwake;								// ���� �ִ°�, �������� �ʾҴ°�
	bool _isMyPokemon;							// �÷��̾��� ���ϸ��ΰ�

	pokemonStatus _defaultStatus;				// ���� status
	pokemonStatus _currentStatus;				// ���� status

	int _displayHp;								// ����� hp
	int _displayExp;							// ����� ����ġ

	float _displayTime;							// ���� �� �ð�

	pokemonUC	  _upsetCondition;				// ���� �̻�

	pmSkill _skills[POKEMON_SKILL_MAX_COUNT];	// ��ų

	image*		_img;	// �̹���

	function<void(void)> _function;				// ����� �Լ�

public:
	pokemon();
	~pokemon();

	HRESULT init(int idNo, pokemonInfo* info, int level, int nextExp, bool isMyPokemon, pokemonStatus* status, pokemonSkill* skills);
	void release();
	void update();
	void render();

	// ����� ������ ����
	pmPack* makeSavePack();
	// �ε�� ������ ����
	void loadSavePack(pmPack* pack);
	
	// ���� �� : ����ġ ������ �ܿ� ���� ������ �ϴ� ��� ��� ex. �̻��� ���� ���
	void levelUpForce();
	// �� ��°(idx) ��ų ���
	void useSkill(int idx);

	// ������ ����
	void takeDamage(int value);
	// hp full ȸ��
	void fillHp();
	// hp ȸ��
	void hillHp(int value);
	// ����ġ ȹ��
	void gainExp(int exp);
	// ���� ������ ����
	item* withdrawItem();
	// �����̻� ����
	void clearUpsetCondtion();
	// ��ų ��ü
	void changeSkill(int idx, pmSkill* skill);

	
	//============================================== set
	
	// �����̻� ����
	void setUpsetCondition(pokemonUC upsetCondition){ _upsetCondition = upsetCondition; }
	// ���� ������ ����
	void setOwnerItem(item* ownerItem)		{ _item = ownerItem; }
	// �г���
	void setNicName(string nickName)		{ _nickName = nickName; }
	// Ʈ���̳� ��Ʈ
	void setTrainerNote(string trainerNote) { _trainerNote = trainerNote; }

	//============================================== get
	
	// �����ִ°�
	bool isAwake()		{ return _isAwake;}
	// �÷��̾� ���ϸ��ΰ�
	bool isMyPokemon()	{ return _isMyPokemon;}

	// ������ȣ
	unsigned int getIdNo()		{ return _idNo; }
	// ���ϸ� ��ȣ
	POKEMON getPokeminIndex()	{ return _index; }
	// Ʈ���̳� ��Ʈ
	string getTrainerNote()		{ return _trainerNote; }
	// �����ϰ� �ִ� ������
	const item* getOwnerItem()	{ return _item;}

	// ����
	unsigned int getLevel()		{ return _level;}
	// ���� ����ġ
	unsigned int getCurrentExp(){ return _currentExp; }
	// �������� �ʿ��� �� ����ġ
	unsigned int getNextExp()	{ return _nextExp; }
	// �������� �ʿ��� ���� ����ġ
	unsigned int getRemainExp()	{ return _nextExp - _currentExp; }
	// ���� ü��
	int getHp()			{ return _currentStatus.hp; }
	// Ǯ ü��
	int getMaxHp()		{ return _defaultStatus.hp;}
	// ���� ���ݷ�
	int getAttk()		{ return _currentStatus.attk;}
	// ���� ����
	int getDex()		{ return _currentStatus.dex; }
	// ���� Ư�� ���ݷ�
	int getSpAttk()		{ return _currentStatus.spAttk; }
	// ���� Ư�� ����
	int getSpDex()		{ return _currentStatus.spDex; }
	// ���� �ӵ�
	int getspeed()		{ return _currentStatus.speed;}
	// �����̻� 
	POKEMON_UPSET_CONDITION getUpsetCondition() { return _upsetCondition.type; }
	// ��ų
	const pmSkill* getPokemonSkills() { return _skills; }

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

	// ���� ����
	void startProgessingValue(function<void(void)> func);
	// hp ��ȭ
	void progressingIncreaseHp();
	void progressingDecreaseHp();
	// exp ��ȭ
	void progressingIncreseExp(void);

};

