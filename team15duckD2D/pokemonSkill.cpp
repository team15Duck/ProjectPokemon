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
			uc->applyValue = 8;				// hp�� 1/8 ����
			break;
		}
		case PMUC_FROZEN:
		{
			// 10�ۼ�Ʈ Ȯ���� �ɸ���
			int value = RND->getFromIntTo(1, 10);
			if (value <= 10)
			{
				uc->releseType = PMURC_PERCENT;
				uc->releaseValue = 5;			// 1/5 Ȯ���� ���� ����
				uc->type = type;
			}

			break;
		}
		case PMUC_PALALYSIS:
		{
			// 10�ۼ�Ʈ Ȯ���� �ɸ���
			int value = RND->getFromIntTo(1, 10);
			if (value <= 10)
			{
				uc->type = type;
				uc->releseType = PMURC_TURN;
				uc->releaseValue = RND->getFromIntTo(1, 3);	// 1 ~ 3 ���Ŀ� ����
			}
			break;
		}
		case PMUC_SLEEP:
		{
			uc->type = type;
			uc->releseType = PMURC_TURN;
			uc->releaseValue = RND->getFromIntTo(1, 2); // 1 ~ 2 ���Ŀ� ����
			break;
		}

		case PMUC_BURN:
		{
			// 10�ۼ�Ʈ Ȯ���� �ɸ���
			int value = RND->getFromIntTo(1, 10);
			if (value <= 10)
			{
				uc->type = type;
				uc->releseType = PMURC_CURE;
				uc->applyValue = 16;				// hp�� 1/16 ����
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

