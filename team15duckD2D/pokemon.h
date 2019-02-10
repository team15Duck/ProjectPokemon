#pragma once
#include "pokemonInfo.h"
#include "pokemonSkill.h"
#include "item.h"
#include <functional>


#define POKEMON_SKILL_MAX_COUNT 4			// 최대 보유할 수 있는 스킬의 수
#define PROGRESSING_TERM 0.1

// 세이브용 데이터
typedef struct tagPokemonPackage
{
	unsigned int idNo;				// 고유 번호
	unsigned int index;				// 도감 번호

	string nickName;				// 이름
	string trainerNote;				// 트레이너 노트

	unsigned int itemIdx;			// 소지하고 있는 아이템의 번호

	unsigned int level;				// 레벨
	unsigned int currentExp;		// 현재 경험치

	unsigned int upsetConditionType;	// 상태이상
	unsigned int upsetConditionValue;	// 상태이상
	unsigned int upsetConditionCount;	// 상태이상
	
	// 현재 상태값들
	unsigned int hp;		// 체력
	unsigned int attk;		// 공격력
	unsigned int dex;		// 방어력
	unsigned int spAttk;	// 특수 공격력
	unsigned int spDex;		// 특수 방어력

	unsigned int speed;		// 속도
	
	int skillIds[POKEMON_SKILL_MAX_COUNT];		// 스킬 번호
	int currentPPs[POKEMON_SKILL_MAX_COUNT];	// 현재 남은 스킬의 수
	int maxPPs[POKEMON_SKILL_MAX_COUNT];		// 최대 스킬의 수

}pmPack;

// 포켓몬
class pokemon
{
private:
	//typedef function<void(void)> CALLBACK_FUNCTION;

private:

	unsigned int _idNo;							// 고유 번호
	POKEMON _index;								// 도감 번호

	string _nickName;							// 닉네임
	string _trainerNote;						// 트레이너 노트

	item* _item;								// 소지하고 있는 아이템

	unsigned int _level;						// 레벨
	unsigned int _currentExp;					// 현재 경험치
	unsigned int _nextExp;						// 다음 레벨까지 필요한 경험치

	bool _isAwake;								// 깨어 있는가, 기절하지 않았는가
	bool _isMyPokemon;							// 플레이어의 포켓몬인가

	pokemonStatus _defaultStatus;				// 원래 status
	pokemonStatus _currentStatus;				// 현재 status

	int _displayHp;								// 연출용 hp
	int _displayExp;							// 연출용 경험치

	float _displayTime;							// 연출 용 시간

	pokemonUC	  _upsetCondition;				// 상태 이상

	pmSkill _skills[POKEMON_SKILL_MAX_COUNT];	// 스킬

	image*		_img;	// 이미지

	function<void(void)> _function;				// 연출용 함수

public:
	pokemon();
	~pokemon();

	HRESULT init(int idNo, pokemonInfo* info, int level, int nextExp, bool isMyPokemon, pokemonStatus* status, pokemonSkill* skills);
	void release();
	void update();
	void render();

	// 저장용 데이터 생성
	pmPack* makeSavePack();
	// 로드된 데이터 적용
	void loadSavePack(pmPack* pack);
	
	// 레벨 업 : 경험치 레벨업 외에 강제 레벨업 하는 경우 사용 ex. 이상한 사탕 사용
	void levelUpForce();
	// 몇 번째(idx) 스킬 사용
	void useSkill(int idx);

	// 데미지 입음
	void takeDamage(int value);
	// hp full 회복
	void fillHp();
	// hp 회복
	void hillHp(int value);
	// 경험치 획득
	void gainExp(int exp);
	// 소지 아이템 해제
	item* withdrawItem();
	// 상태이상 해제
	void clearUpsetCondtion();
	// 스킬 교체
	void changeSkill(int idx, pmSkill* skill);

	
	//============================================== set
	
	// 상태이상 세팅
	void setUpsetCondition(pokemonUC upsetCondition){ _upsetCondition = upsetCondition; }
	// 소지 아이템 세팅
	void setOwnerItem(item* ownerItem)		{ _item = ownerItem; }
	// 닉네임
	void setNicName(string nickName)		{ _nickName = nickName; }
	// 트레이너 노트
	void setTrainerNote(string trainerNote) { _trainerNote = trainerNote; }

	//============================================== get
	
	// 깨어있는가
	bool isAwake()		{ return _isAwake;}
	// 플레이어 포켓몬인가
	bool isMyPokemon()	{ return _isMyPokemon;}

	// 고유번호
	unsigned int getIdNo()		{ return _idNo; }
	// 포켓몬 번호
	POKEMON getPokeminIndex()	{ return _index; }
	// 트레이너 노트
	string getTrainerNote()		{ return _trainerNote; }
	// 소지하고 있는 아이템
	const item* getOwnerItem()	{ return _item;}

	// 레벨
	unsigned int getLevel()		{ return _level;}
	// 현재 경험치
	unsigned int getCurrentExp(){ return _currentExp; }
	// 레벨업에 필요한 총 경험치
	unsigned int getNextExp()	{ return _nextExp; }
	// 레벨업에 필요한 남은 경험치
	unsigned int getRemainExp()	{ return _nextExp - _currentExp; }
	// 현재 체력
	int getHp()			{ return _currentStatus.hp; }
	// 풀 체력
	int getMaxHp()		{ return _defaultStatus.hp;}
	// 현재 공격력
	int getAttk()		{ return _currentStatus.attk;}
	// 현재 방어력
	int getDex()		{ return _currentStatus.dex; }
	// 현재 특수 공격력
	int getSpAttk()		{ return _currentStatus.spAttk; }
	// 현재 특수 방어력
	int getSpDex()		{ return _currentStatus.spDex; }
	// 현재 속도
	int getspeed()		{ return _currentStatus.speed;}
	// 상태이상 
	POKEMON_UPSET_CONDITION getUpsetCondition() { return _upsetCondition.type; }
	// 스킬
	const pmSkill* getPokemonSkills() { return _skills; }

	// 연출용 hp
	int getDisplayHp()	{ return _displayHp; }
	//  연출용 exp
	int getDisplayExp() { return _displayExp; }



private:
	// 경험치로 인한 레벨업
	void levelUp();
	// 능령치 세팅
	void settingStatus();
	// 진화
	void evolution();
	// 레벨업에 따른 스킬 획득
	void gainSkill();

	// 연출 시작
	void startProgessingValue(function<void(void)> func);
	// hp 변화
	void progressingIncreaseHp();
	void progressingDecreaseHp();
	// exp 변화
	void progressingIncreseExp(void);

};

