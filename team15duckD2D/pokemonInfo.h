#pragma once

#define POKEMON_MAX_LEVEL 100

// ���ϸ� ��ȣ
enum POKEMON
{
	PM_BULBASAUR,	PM_IVYSAUR,		PM_VENUSAUR,
	PM_CHARMANDER,	PM_CHARMELEON,	PM_CHARIZARD,
	PM_SQUIRTLE,	PM_WARTORTLE,	PM_BLASTOISE,
	POKEMON10,
	POKEMON11,  POKEMON12,  POKEMON13,  POKEMON14,	POKEMON15,
	POKEMON16,  POKEMON17,  POKEMON18,  POKEMON19,	POKEMON20,
	POKEMON21,  POKEMON22,  POKEMON23,  POKEMON24,	POKEMON25,
	POKEMON26,  POKEMON27,  POKEMON28,  POKEMON29,	POKEMON30,
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
	POKEMON126, POKEMON127, POKEMON128, POKEMON129, POKEMON130,
	POKEMON131, POKEMON132, POKEMON133, POKEMON134, POKEMON135,
	POKEMON136, POKEMON137, POKEMON138, POKEMON139, POKEMON140,
	POKEMON141, POKEMON142, POKEMON143, POKEMON144, POKEMON145,
	POKEMON146, POKEMON147, POKEMON148, POKEMON149, POKEMON150,
	POKEMON151,

	POKEMON_NONE,
	POKEMON_COUNT = POKEMON_NONE,
};

// Ÿ��, �Ӽ�
enum POKEMON_TYPE
{
	PM_TYPE_NORMAL,
	PM_TYPE_FIRE,
	PM_TYPE_WATER,
	PM_TYPE_ELECTRONIC,
	PM_TYPE_GRASS,

	PM_TYPE_NONE,
	PM_TYPE_COUNT = PM_TYPE_NONE,
};

// �����̻�
enum POKEMON_UPSET_CONDITION
{
	PMUC_POISON,		// ��
	PMUC_PALALYSIS,		// ����
	PMUC_CONFUSE,		// ȥ��
	PMUC_SLEEP,			// ���
	  
	PMUC_NONE,
	PMUC_COUNT = PMUC_NONE,
};

// �ɷ�ġ
typedef struct tagPokemonStatus
{
	unsigned int hp;		// ü��
	unsigned int attk;		// ���ݷ�
	unsigned int dex;		// ����
	unsigned int spAttk;	// Ư�� ���ݷ�
	unsigned int spDex;		// Ư�� ����
	
	unsigned int speed;		// �ӵ�

	// �� ����
	void operator=(tagPokemonStatus status)
	{
		hp		= status.hp;
		attk	= status.attk;
		dex		= status.dex;
		spAttk	= status.spAttk;
		spDex	= status.spDex;
		speed	= status.speed;
	}

	// �ʱ�ȭ
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
	POKEMON_UPSET_CONDITION type;	// �����̻�
	int value;						// ���� �̻� �� ���� �� ��(ex. �� ������, ���� Ȯ�� ��)
	int count;						// �����̻� ���� ��

	// �� ����
	void operator= (tagPokemonUpsetCondition condition)
	{
		type  = condition.type;
		value = condition.value;
		count = condition.count;
	}

	// �ʱ�ȭ
	void clear()
	{
		type = PMUC_NONE;
		value = 0;
		count = 0;
	}

}pokemonUC;



// ���ϸ� �⺻ ����
// �����Ϳ��� ������ �޾ƿ� �� �������� ���� ������
class pokemonInfo
{
private:

	POKEMON			_index;				// ���ϸ� �ѹ�
	POKEMON_TYPE	_type;				// ���ϸ� Ÿ��
	pokemonStatus	_kindStatus;		// ���ϸ� ������

	string			_name;				// ���ϸ� �̸�
	string			_description;		// ����

	float			_weight;			// ����
	float			_height;			// Ű

	int				_captureRate;		// ǥȹ��

	int				_evolutionLv;		// ��ȭ�� ���� ����
	POKEMON			_evolutionIndex;	// ��ȭ �ѹ�
	
public:
	pokemonInfo();
	~pokemonInfo();

	// �ʱ�ȭ : ��ȭ ����
	HRESULT init(	POKEMON index, POKEMON_TYPE type, string name, pokemonStatus* status
				 ,	string text, float weight, float height, int captureRate);
	// �ʱ�ȭ : ��ȭ ����
	HRESULT init(POKEMON index, POKEMON_TYPE type, string name, pokemonStatus* status
				 , string text, float weight, float height, int captureRate
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

};

