#pragma once

#define POKEMON_MAX_LEVEL 100

// 포켓몬 번호
enum POKEMON
{
	PM_BULBASAUR,	PM_IVYSAUR,		PM_VENUSAUR,
	PM_CHARMANDER,	PM_CHARMELEON,	PM_CHARIZARD,
	PM_SQUIRTLE,	PM_WARTORTLE,	PM_BLASTOISE,
	POKEMON10,
	POKEMON11,  POKEMON12,  POKEMON13,  POKEMON14,	POKEMON15,
	POKEMON16,  POKEMON17,  POKEMON18,  POKEMON19,	POKEMON20,
	POKEMON21,  POKEMON22,  POKEMON23,  POKEMON24,	
	PM_PIKACHU,	PM_RAICHU,  
	POKEMON27,  POKEMON28,  POKEMON29,	POKEMON30,
	POKEMON31,  POKEMON32,  POKEMON33,  POKEMON34,	POKEMON35,
	POKEMON36,  POKEMON37,  POKEMON38,  POKEMON39,	POKEMON40,
	POKEMON41,  POKEMON42,  POKEMON43,  POKEMON44,	POKEMON45,
	POKEMON46,  POKEMON47,  POKEMON48,  POKEMON49,	POKEMON50,
	POKEMON51,  POKEMON52,  POKEMON53,  POKEMON54,	POKEMON55,
	POKEMON56,  POKEMON57,  POKEMON58,  POKEMON59,	POKEMON60,
	POKEMON61,  POKEMON62,  POKEMON63,  POKEMON64,	POKEMON65,
	POKEMON66,  POKEMON67,  POKEMON68,  POKEMON69,	POKEMON70,
	POKEMON71,  POKEMON72,  POKEMON73,  POKEMON74,	POKEMON75,
	POKEMON76,  POKEMON77,  POKEMON78,  POKEMON79,	POKEMON80,
	POKEMON81,  POKEMON82,  POKEMON83,  POKEMON84,	POKEMON85,
	POKEMON86,  POKEMON87,  POKEMON88,  POKEMON89,	POKEMON90,
	POKEMON91,  POKEMON92,  POKEMON93,  POKEMON94,	POKEMON95,
	POKEMON96,  POKEMON97,  POKEMON98,  POKEMON99,	POKEMON100,
	POKEMON101, POKEMON102,	POKEMON103,	POKEMON104, POKEMON105,
	POKEMON106, POKEMON107,	POKEMON108,	POKEMON109, POKEMON110,
	POKEMON111, POKEMON112, POKEMON113, POKEMON114, POKEMON115,
	POKEMON116, POKEMON117, POKEMON118, POKEMON119, POKEMON120,
	POKEMON121, POKEMON122, POKEMON123, POKEMON124, POKEMON125,
	POKEMON126, POKEMON127, POKEMON128,
	PM_MAGIKARP, POKEMON130,
	POKEMON131, POKEMON132, POKEMON133, POKEMON134, POKEMON135,
	POKEMON136, POKEMON137, POKEMON138, POKEMON139, POKEMON140,
	POKEMON141, POKEMON142, POKEMON143, POKEMON144, POKEMON145,
	POKEMON146, POKEMON147, POKEMON148, POKEMON149, POKEMON150,
	POKEMON151,

	POKEMON_NONE,
	POKEMON_COUNT = POKEMON_NONE,
};

// 타입, 속성
enum POKEMON_TYPE
{
	PM_TYPE_NORMAL,		// 노말
	PM_TYPE_FIRE,		// 불
	PM_TYPE_WATER,		// 물
	PM_TYPE_ELECTRONIC,	// 전기
	PM_TYPE_GRASS,		// 풀
	PB_TYPE_POISION,	// 독
	PB_TYPE_DRAGON,		// 드래곤

	PM_TYPE_NONE,
	PM_TYPE_COUNT = PM_TYPE_NONE,
};

// 상태이상
enum POKEMON_UPSET_CONDITION
{
	PMUC_POISON,		// 독
	PMUC_FROZEN,		// 얼음
	PMUC_PALALYSIS,		// 마비
	PMUC_SLEEP,			// 잠듦
	PMUC_BURN,			// 화상

	  
	PMUC_NONE,
	PMUC_COUNT = PMUC_NONE,
};

// 버프
enum POKEMON_BUFF
{
	PMB_ABSORB_HP,	// 체력 흡수

	PMB_NONE,
	PMB_COUNT = PMB_NONE,
};

enum POKEMON_UPSET_RELEASE_CONDITION
{
	PMURC_TURN,			// 턴 수로 회복
	PMURC_PERCENT,		// 확률로 회복
	PMURC_CURE,			// 치유(포션, 포켓몬센터)로 회복

	PMURC_NONE,
	PMURC_COUNT = PMUC_NONE,
};

// 능력치
typedef struct tagPokemonStatus
{
	unsigned int hp;		// 체력
	unsigned int attk;		// 공격력
	unsigned int dex;		// 방어력
	unsigned int spAttk;	// 특수 공격력
	unsigned int spDex;		// 특수 방어력
	
	unsigned int speed;		// 속도

	// 값 복사
	void operator=(tagPokemonStatus status)
	{
		hp		= status.hp;
		attk	= status.attk;
		dex		= status.dex;
		spAttk	= status.spAttk;
		spDex	= status.spDex;
		speed	= status.speed;
	}

	// 초기화
	void clear()
	{
		hp		= 0;
		attk	= 0;
		dex		= 0;
		spAttk	= 0;
		spDex	= 0;
		speed	= 0;
	}
}pokemonStatus;


typedef struct tagPokemonUpsetCondition
{
	POKEMON_UPSET_CONDITION type;				// 상태이상
	POKEMON_UPSET_RELEASE_CONDITION releseType;	// 상태이상 해제 조건
	int applyValue;								// 상태 적용 시 사용 ex) 확률 등
	int releaseValue;							// 상태 해제 조건 ex) 턴 수, 확률 등
	wstring name;

	// 값 복사
	void operator= (tagPokemonUpsetCondition condition)
	{
		type  = condition.type;
		releseType = condition.releseType;
		applyValue = condition.applyValue;
		releaseValue = condition.releaseValue;
		name = condition.name;
	}

	// 초기화
	void clear()
	{
		type = PMUC_NONE;
		releseType = PMURC_NONE;
		applyValue = 0;
		releaseValue = 0;
		name.clear();
	}

}pokemonUC;



// 포켓몬 기본 정보
// 데이터에서 정보를 받아온 뒤 수정되지 않을 정보들
class pokemonInfo
{
private:

	POKEMON			_index;				// 포켓몬 넘버
	POKEMON_TYPE	_type;				// 포켓몬 타입
	pokemonStatus	_kindStatus;		// 포켓몬 종족값

	string			_name;				// 포켓몬 이름
	string			_description;		// 설명

	float			_weight;			// 무게
	float			_height;			// 키

	int				_captureRate;		// 표획률

	int				_evolutionLv;		// 진화를 위한 레벨
	POKEMON			_evolutionIndex;	// 진화 넘버

	map<int, vector<int>>  _skillMap;	// 레벨 별 얻는 스킬 : 레벨, 스킬id vector map
	
public:
	pokemonInfo();
	~pokemonInfo();

	// 초기화 : 진화 없음
	HRESULT init(	POKEMON index, POKEMON_TYPE type, string name, pokemonStatus* status
				 ,	string text, float weight, float height, int captureRate, map<int, vector<int>> skillMap);
	// 초기화 : 진화 있음
	HRESULT init(POKEMON index, POKEMON_TYPE type, string name, pokemonStatus* status
				 , string text, float weight, float height, int captureRate, map<int, vector<int>> skillMap
				 , int evolutionLv, POKEMON evolutionIndex);
	void clear();
	

	POKEMON getPokemonIndex()					{ return _index;			}
	POKEMON_TYPE getPokemonType()				{ return _type;				}
	const pokemonStatus* getPokemonKindStatus()	{ return &_kindStatus;		}
	const string* getPokemonName()				{ return &_name;			}
	const string* getPokemonDescription()		{ return &_description;		}
	float getWeight()							{ return _weight;			}
	float getHeight()							{ return _height;			}
	int getCaptureRate()						{ return _captureRate;		}
	int getEvolutionLevel()						{ return _evolutionLv;		}
	POKEMON getEvolutionIndex()					{ return _evolutionIndex;	}	
	map<int, vector<int>>* getSkillMap()		{ return &_skillMap;		}

};

