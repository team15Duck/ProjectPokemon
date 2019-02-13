#pragma once
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

	const char* nickName;			// 이름
	const char* trainerNote;		// 트레이너 노트

	unsigned int itemType;			// 소지하고 있는 아이템의 번호(타입)

	unsigned int level;				// 레벨
	unsigned int currentExp;		// 현재 경험치

	unsigned int upsetConditionType;	// 상태이상
	unsigned int upsetConditionApplyValue;	// 상태이상
	unsigned int upsetConditionReleseValue;	// 상태이상
	
	// 현재 상태값들
	unsigned int hp;		// 체력
	unsigned int attk;		// 공격력
	unsigned int dex;		// 방어력
	unsigned int spAttk;	// 특수 공격력
	unsigned int spDex;		// 특수 방어력

	unsigned int speed;		// 속도
	
	int skillIds[POKEMON_SKILL_MAX_COUNT];		// 스킬 번호
	int currentPPs[POKEMON_SKILL_MAX_COUNT];	// 현재 남은 스킬의 수

}pmPack;

class pokemonInfo;

// 포켓몬
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

	unsigned int _idNo;							// 고유 번호
	POKEMON _index;								// 도감 번호

	string _nickName;							// 닉네임
	string _trainerNote;						// 트레이너 노트

	ITEM_TYPE _ownerItemType;					// 소지하고 있는 아이템

	unsigned int _level;						// 레벨
	unsigned int _currentLvExp;					// 현재 레벨까지의 누적 경험치
	unsigned int _currentExp;					// 현재 누적 경험치
	unsigned int _nextLvExp;					// 다음 레벨까지 누적 경험치

	bool _isAwake;								// 깨어 있는가, 기절하지 않았는가
	bool _isMyPokemon;							// 플레이어의 포켓몬인가

	pokemonStatus _beforeLvStatus;				// 이전 lv의 status
	pokemonStatus _currentLvStatus;				// 현재 lv의 status
	pokemonStatus _nowStatus;					// 현재 status

	int _displayHp;								// 연출용 hp
	int _displayExp;							// 연출용 경험치

	float _displayTime;							// 연출 용 시간
	bool _isIdle;								// 행동 대기중인가
	PROGRESSING_TYPE	_progressingType;

	pokemonUC	  _upsetCondition;				// 상태 이상
	pokemonSkill _skills[POKEMON_SKILL_MAX_COUNT]; // 스킬
	
	image*		_img;	// 이미지
	pokemon* _target;	// 적이당
	function<void(void)> _function;				// 연출용 함수

	float _destX, _destY;						// 렌더 위치
	int _frameX, _frameY;						// 렌더 프레임 좌표

public:
	pokemon();
	~pokemon();

	// 고유번호, 포켓몬 번호, 레벨, 플레이어 포켓몬?, 렌더 letf, 렌더 top
	HRESULT init(int idNo, POKEMON index, int level, bool isMyPokemon);
	void release();
	void update();
	void render();

	// 저장용 데이터 생성
	pmPack* makeSavePack();
	// 로드된 데이터 적용
	void loadSavePack(pmPack* pack);
	

	// 1. 소지하고 있는 아이템 사용 : 사용했으면 return true
	bool useOwnerItem();
	// 2. 상태 이상 적용
	void applyUpsetCondition();
	// 3. 아이템 사용
	// 3. 몇 번째(idx) 스킬 사용
	void useSkill(int idx);

	
	// 레벨 업 : 경험치 레벨업 외에 강제 레벨업 하는 경우 사용 ex. 이상한 사탕 사용
	// 레벨 업을 했으면 return true, 그렇지 않다면 return false
	bool levelUpForce();
	
	// 데미지 입음
	void takeDamage(int value);
	// hp full 회복
	void fillHp();
	// hp 회복
	void hillHp(int value);
	// 경험치 획득
	void gainExp(int exp);
	// 소지 아이템 해제
	ITEM_TYPE withdrawItem();
	// 상태이상 해제
	void clearUpsetCondtion();
	// 스킬 교체
	void changeSkill(int idx, int skillId);
	// 체력감소 연출 시작 : 상대방의 스킬 연출이 끝나고나면 데미지를 입는 것 처럼 보이도록.
	void startTakeDamageDisplay();
	
	//============================================== set
	
	// 적 포켓몬 세팅
	void setTargetPokemon(pokemon* pm) { _target = pm; }

	// 상태이상 세팅
	void setUpsetCondition(pokemonUC upsetCondition){ _upsetCondition = upsetCondition; }
	// 소지 아이템 세팅
	void setOwnerItem(ITEM_TYPE itemType)	{ _ownerItemType = itemType; }
	// 닉네임
	void setNicName(string nickName)		{ _nickName = nickName; }
	// 트레이너 노트
	void setTrainerNote(string trainerNote) { _trainerNote = trainerNote; }

	//============================================== get
	
	// 행동 대기중인가 : 행동 대기 중일때만 다음 행동을 할 수 있다.
	bool isIdle()				{ return _isIdle;}

	// 깨어있는가
	bool isAwake()				{ return _isAwake;}
	// 플레이어 포켓몬인가		
	bool isMyPokemon()			{ return _isMyPokemon;}

	// 고유번호
	unsigned int getIdNo()		{ return _idNo; }
	// 포켓몬 번호
	POKEMON getPokeminIndex()	{ return _index; }
	// 트레이너 노트
	string getTrainerNote()		{ return _trainerNote; }
	// 소지하고 있는 아이템 타입
	ITEM_TYPE getOwnerItemType(){ return _ownerItemType;}

	// 레벨
	unsigned int getLevel()		{ return _level;}
	
	// 현재 경험치
	unsigned int getCurrentExp()		{ return _currentExp - _currentLvExp; }
	// 다음 레벨까지 경험치
	unsigned int getNextExp()			{ return _nextLvExp - _currentLvExp; }
	// 레벨업에 필요한 남은 경험치
	unsigned int getRemainExp()			{ return _nextLvExp - _currentExp; }
	
	// 현재 누적된 경험치
	unsigned int getCurrentTotalExp()	{ return _currentExp; }
	// 다음 레벨 누적 경험치
	unsigned int getNextTotalExp()		{ return _nextLvExp; }
	
	// 현재 체력
	int getHp()			{ return _nowStatus.hp; }
	// 풀 체력
	int getMaxHp()		{ return _nowStatus.hp;}
	// 현재 공격력
	int getAttk()		{ return _nowStatus.attk;}
	// 현재 방어력
	int getDex()		{ return _nowStatus.dex; }
	// 현재 특수 공격력
	int getSpAttk()		{ return _nowStatus.spAttk; }
	// 현재 특수 방어력
	int getSpDex()		{ return _nowStatus.spDex; }
	// 현재 속도
	int getspeed()		{ return _nowStatus.speed;}
	// 상태이상 
	POKEMON_UPSET_CONDITION getUpsetCondition() { return _upsetCondition.type; }
	// 스킬
	const pokemonSkill* getPokemonSkills() { return _skills; }

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
	// 공격
	void attack(int value, pokemonUC* upsetCondition);

	
	
	// 연출 시작
	void startProgessing(function<void(void)> func, PROGRESSING_TYPE type);
	// 연출 끝
	void endProgressing();

	// hp 변화
	void progressingIncreaseHp();
	void progressingDecreaseHp();
	// exp 변화
	void progressingIncreseExp(void);
	// 스킬 이펙트
	void progressintSkillEffect(int idx);
	// 상태이상 효과 적용
	void progressingApplyUpsetCondition();
	
	// 데미지 계산
	int calculateAttkValue(int skillIdx);

};

