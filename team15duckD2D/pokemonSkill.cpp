#include "stdafx.h"
#include "pokemonSkill.h"

pokemonSkillInfo::pokemonSkillInfo()
: _skillId(SKILL_INDEX_NONE)
, _type(PM_TYPE_NONE)
, _category(PMSC_NONE)
, _upsetConditionType(PMUC_NONE)
, _buffType(PMB_NONE)
, _power(0)
, _accuracyRate(0)
, _defaultPP(0)
{
	_description.clear();
	_name.clear();
}

pokemonSkillInfo::~pokemonSkillInfo()
{
}

HRESULT pokemonSkillInfo::init(	 SKILL_INDEX id
							   , POKEMON_TYPE type
							   , POKEMON_SKILL_CATEGORY category
							   , string text
							   , string name
							   , POKEMON_UPSET_CONDITION conditionType
							   , POKEMON_BUFF buff
							   , int power
							   , int rate
							   , int maXpp)
{
	_skillId = id;
	_type = type;
	_category = category;
	_description = text;
	_name = name;
	_upsetConditionType = conditionType;
	_buffType = buff;
	_power = power;
	_accuracyRate = rate;
	_defaultPP = maXpp;

	return S_OK;
}

void pokemonSkillInfo::release()
{
}

wstring pokemonSkillInfo::getSkillTypestring()
{
	switch (_skillId)
	{
	case TACLE:
		return L"몸통박치기";
	case LEECH_SEEd:
		return L"씨뿌리기";
	case VINE_WHIP:
		return L"덩쿨채찍";
	case POISON_POWDER:
		return L"독가루";
	case SLEEP_POWDER:
		return L"수면가루";
	case RAZOR_LEAF:
		return L"잎날 가르기";
	case SCRATCH:
		return L"할퀴기";
	case EMBER:
		return L"불꽃세례";
	case FLAMETHROWER:
		return L"화염방사";
	case DRAGON_RAGE:
		return L"용의 분노";
	case BUBBLE:
		return L"거품";
	case WATER_GUN:
		return L"물대포";
	case HYDRO_PUMP:
		return L"하이드로 펌프";
	case QUICK_ATTACK:
		return L"전광석화";
	case THUNDERSHOCK:
		return L"전기쇼크";
	case THUNDERBOLT:
		return L"10만볼트";
	case THUNDER:
		return L"번개";
	case THNDER_WAVE:
		return L"전기자석파";
	case SPLASH:
		return L"튀어오르기";
	case SKILL_INDEX_NONE:
		return L"-";
	}
	return L" ";
}

wstring pokemonSkillInfo::getSkillTypeName()
{
	switch (_type)
	{
		case PM_TYPE_NORMAL:
			return L"노말";
		case PM_TYPE_FIRE:
			return L"불";
		case PM_TYPE_WATER:
			return L"물";
		case PM_TYPE_ELECTRONIC:
			return L"전기";
		case PM_TYPE_GRASS:
			return L"풀";
		case PB_TYPE_POISION:
			return L"독";
		case PB_TYPE_DRAGON:
			return L"드래곤";
	}


	return L"";
}


pokemonSkill::pokemonSkill()
: _skillId(0)
, _currentPP(0)
, _isPlayingEffect(false)
{
}


pokemonSkill::~pokemonSkill()
{
}

HRESULT pokemonSkill::init(int skillid)
{
	_skillId = skillid;
	_info = *SKILLDATA->getPokemonSkillinfo(skillid);
	if(_info.getSkillID() != SKILL_INDEX_NONE)
		_currentPP = _info.getDefaultPP();

	return S_OK;
}

void pokemonSkill::release()
{
}

void pokemonSkill::update()
{
	if (_isPlayingEffect)
	{
		// todo effect update
	}

}

void pokemonSkill::render()
{
	if (_isPlayingEffect)
	{
		// todo effect render
	}
}

void pokemonSkill::clear()
{
	_skillId = SKILL_INDEX_NONE;
	_currentPP = 0;
	_isPlayingEffect = false;
}

void pokemonSkill::increaseCurrentPP(int value)
{
	_currentPP += value;
	if(_info.getDefaultPP() < _currentPP)
		_currentPP = _info.getDefaultPP();
}

void pokemonSkill::setCurrentPP(int value)
{
	if(value < 0)
		return;
	
	_currentPP = value;
	if (_info.getDefaultPP() < _currentPP)
		_currentPP = _info.getDefaultPP();
}

bool pokemonSkill::isUsableSkill()
{
	if(0 < _currentPP)
		return true;
	else
		return false;
}

void pokemonSkill::useSkill()
{
	if (isUsableSkill())
	{
		--_currentPP;
		_isPlayingEffect = true;
		playEffect();
	}
}

pokemonUC* pokemonSkill::getUpsetCondition()
{
	pokemonUC* uc = new pokemonUC;
	uc->clear();

	POKEMON_UPSET_CONDITION type = _info.getUpsetConditionType();
	
	switch (uc->type)
	{
		case PMUC_POISON:
		{
			uc->type = type;
			uc->releseType = PMURC_CURE;
			uc->applyValue = 8;				// hp의 1/8 감소
			uc->name = L"독";
			break;
		}
		case PMUC_FROZEN:
		{
			// 10퍼센트 확률로 걸린다
			int value = RND->getFromIntTo(1, 10);
			if (value <= 10)
			{
				uc->releseType = PMURC_PERCENT;
				uc->releaseValue = 5;			// 1/5 확률로 상태 해제
				uc->type = type;
				uc->name = L"얼음";
			}

			break;
		}
		case PMUC_PALALYSIS:
		{
			// 10퍼센트 확률로 걸린다
			int value = RND->getFromIntTo(1, 10);
			if (value <= 10)
			{
				uc->type = type;
				uc->releseType = PMURC_TURN;
				uc->releaseValue = RND->getFromIntTo(1, 3);	// 1 ~ 3 턴후에 해제
				uc->name = L"마비";
			}
			break;
		}
		case PMUC_SLEEP:
		{
			uc->type = type;
			uc->releseType = PMURC_TURN;
			uc->releaseValue = RND->getFromIntTo(1, 2); // 1 ~ 2 턴후에 해제
			uc->name = L"잠듦";
			break;
		}

		case PMUC_BURN:
		{
			// 10퍼센트 확률로 걸린다
			int value = RND->getFromIntTo(1, 10);
			if (value <= 10)
			{
				uc->type = type;
				uc->releseType = PMURC_CURE;
				uc->applyValue = 16;				// hp의 1/16 감소
				uc->name = L"화상";
			}

			break;
		}

		default:
			break;
	}

	return uc;
}

void pokemonSkill::playEffect()
{

	// todo effect end check
	//if()
	{
		_isPlayingEffect = false;
	}
}

