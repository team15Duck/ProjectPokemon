#include "stdafx.h"
#include "pokemonSkill.h"

pokemonSkillInfo::pokemonSkillInfo()
{
}

pokemonSkillInfo::~pokemonSkillInfo()
{
}

HRESULT pokemonSkillInfo::init(	 int id
							   , POKEMON_TYPE type
							   , POKEMON_SKILL_CATEGORY category
							   , string text
							   , string name
							   , POKEMON_UPSET_CONDITION conditionType
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
	_power = power;
	_accuracyRate = rate;
	_defaultPP = maXpp;

	return S_OK;
}

void pokemonSkillInfo::release()
{
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
	_skillId = -1;
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

	uc->type = _info.getUpsetConditionType();
	
	switch (uc->type)
	{
		case PMUC_POISON:
		{
			uc->releseType = PMURC_CURE;
			uc->applyValue = 8;				// hp의 1/8 감소
			break;
		}
		case PMUC_FROZEN:
		{
			uc->releseType = PMURC_PERCENT;
			uc->releaseValue = 5;			// 1/5 확률로 상태 해제
			break;
		}
		case PMUC_PALALYSIS:
		{
			uc->releseType = PMURC_TURN;
			uc->releaseValue = RND->getFromIntTo(1, 3);	// 1 ~ 3 턴후에 해제
			break;
		}
		case PMUC_SLEEP:
		{
			uc->releseType = PMURC_TURN;
			uc->releaseValue = RND->getFromIntTo(1, 2); // 1 ~ 2 턴후에 해제
			break;
		}

		case PMUC_BURN:
		{
			uc->releseType = PMURC_CURE;
			uc->applyValue = 16;				// hp의 1/16 감소
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

