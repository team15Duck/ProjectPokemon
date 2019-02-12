#include "stdafx.h"
#include "pokemon.h"


pokemon::pokemon()
: _idNo(0)
, _index(POKEMON_NONE)
, _item(nullptr)
, _level(0)
, _currentLvExp(0)
, _currentExp(0)
, _nextLvExp(0)
, _isAwake(false)
, _isMyPokemon(false)
, _displayHp(0)
, _displayExp(0)
, _displayTime(0.f)
, _isProgressing(false)
, _target(nullptr)
, _img(nullptr)
, _hitDamage(0)
{
	_defaultStatus.clear();
	_currentStatus.clear();
	for (int ii = 0; ii < POKEMON_SKILL_MAX_COUNT; ++ii)
	{
		_skills[ii].clear();
	}
	_upsetCondition.clear();
	_function = NULL;
	_hitUpsetCondition.clear();
}


pokemon::~pokemon()
{
}

HRESULT pokemon::init( int idNo
					  ,POKEMON index
					  ,int level
					  ,bool isMyPokemon)
{
	pokemonInfo info = *POKEMONDATA->getPokemonInfomation(index);

	_idNo = idNo;
	_index = info.getPokemonIndex();
	_nickName = *info.getPokemonName();
	_level = level;
	_isMyPokemon = isMyPokemon;

	_isAwake = true;

	settingStatus();

	// todo : 로딩씬으로 이동
	IMAGEMANAGER->addFrameImage("pokemon_ingame", L"image/pokemon.png", 5120, 4696, 20, 16);
	
	_img = IMAGEMANAGER->findImage("pokemon_ingame");

	return S_OK;
}

void pokemon::release()
{
	_item = nullptr;
	_img = nullptr;
}

void pokemon::update()
{
	if (_function != NULL )
	{
		switch (_progressingType)
		{
			case PROGRESSING_VALUE:
			{
				_displayTime -= TIMEMANAGER->getElapsedTime();
				if (_displayTime < 0)
				{
					_function();
					_displayTime = PROGRESSING_TERM;
				}
				break;
			}

			case PROGRESSING_SKILL:
			{
				_function();
				break;
			}

			default:
			{
				endProgressing();
				break;
			}
		}
	}
}

void pokemon::render()
{

}

pmPack* pokemon::makeSavePack()
{
	pmPack* pack = new pmPack;

	pack->idNo = _idNo;
	pack->index = _index;

	pack->nickName.clear();
	pack->nickName.append(_nickName);
	
	pack->trainerNote.clear();
	pack->trainerNote.append(_trainerNote);

	//pack->itemIdx = _item->getItemID(); // 아이템 아이디

	pack->level = _level;
	pack->currentExp = _currentExp;

	pack->upsetConditionType = _upsetCondition.type;
	pack->upsetConditionValue = _upsetCondition.value;
	pack->upsetConditionCount = _upsetCondition.count;

	// 현재 상태값들
	pack->hp = _currentStatus.hp;
	pack->attk = _currentStatus.attk;
	pack->dex = _currentStatus.dex;
	pack->spAttk = _currentStatus.spAttk;
	pack->spDex = _currentStatus.spDex;
	pack->speed = _currentStatus.speed;

	for (int ii = 0; ii < POKEMON_SKILL_MAX_COUNT; ++ii)
	{
		pack->skillIds[ii] = _skills[ii]._skillId;
		pack->currentPPs[ii] = _skills[ii]._currentPP;
		pack->maxPPs[ii] = _skills[ii]._maxPP;
	}

	return pack;
}

void pokemon::loadSavePack(pmPack* pack)
{
	_idNo = pack->idNo;
	_index = (POKEMON)pack->index;

	_nickName.clear();
	_nickName.append(pack->nickName);

	_trainerNote.clear();
	_trainerNote.append(pack->trainerNote);

	if (pack->itemIdx != -1)
	{
		item* ownerItem = new item;
		ownerItem->init();

		_item = ownerItem;
		// todo 아이템 아이디
		// pack->itemIdx = _item->getItemID(); 
	}

	_level = pack->level;
	settingStatus();
	_currentExp = pack->currentExp;

	_upsetCondition.type = (POKEMON_UPSET_CONDITION)pack->upsetConditionType;
	_upsetCondition.value = pack->upsetConditionValue;
	_upsetCondition.count = _upsetCondition.type; pack->upsetConditionCount;

	// 현재 상태값들
	_currentStatus.hp		= pack->hp;
	_currentStatus.attk		= pack->attk;	
	_currentStatus.dex		= pack->dex;
	_currentStatus.spAttk	= pack->spAttk;
	_currentStatus.spDex	= pack->spDex;
	_currentStatus.speed	= pack->speed;

	for (int ii = 0; ii < POKEMON_SKILL_MAX_COUNT; ++ii)
	{
		_skills[ii]._skillId	= pack->skillIds[ii];
		_skills[ii]._currentPP	= pack->currentPPs[ii];
		_skills[ii]._maxPP		= pack->maxPPs[ii];
	}
}

void pokemon::levelUpForce()
{
	++_level;
	settingStatus();
	// 강제 렙업은 경험치 오르는 효과 없음
}

void pokemon::useSkill(int idx)
{
	// todo 스킬별로 데미지 계산 및 적용
	_hitDamage = _currentStatus.attk;
	//_hitUpsetCondition.type = 

	startProgessing(bind(&pokemon::progressintSkillEffect, this, idx), PROGRESSING_SKILL);
}



void pokemon::takeDamage(int value)
{
	_displayHp = _currentStatus.hp;
	_currentStatus.hp -= value;
	if ( _currentStatus.hp < 0 )
	{
		_currentStatus.hp = 0;
	}

	_displayTime = PROGRESSING_TERM;
	startProgessing(bind(&pokemon::progressingDecreaseHp, this), PROGRESSING_VALUE);
}

void pokemon::fillHp()
{
	_displayHp = _currentStatus.hp;
	_currentStatus.hp = _defaultStatus.hp;
	startProgessing(bind(&pokemon::progressingIncreaseHp, this), PROGRESSING_VALUE);
}

void pokemon::hillHp(int value)
{
	_displayHp = _currentStatus.hp;
	_currentStatus.hp += value;
	if ( _defaultStatus.hp < _currentStatus.hp )
	{
		fillHp();
	}
	else
	{
		startProgessing(bind(&pokemon::progressingIncreaseHp, this), PROGRESSING_VALUE);
	}
}

void pokemon::gainExp(int exp)
{
	_displayExp = _currentExp;
	_currentExp += exp;
	startProgessing(bind(&pokemon::progressingIncreseExp, this), PROGRESSING_VALUE);
}

item* pokemon::withdrawItem()
{
	item* ownerItem = _item;
	_item = nullptr;

	return ownerItem;
}

void pokemon::clearUpsetCondtion()
{
	_upsetCondition.clear();
}

void pokemon::changeSkill(int idx, pmSkill* skill)
{
	if(idx < 0 || POKEMON_SKILL_MAX_COUNT <= idx)
		return;

	_skills[idx] = *skill;
}

void pokemon::levelUp()
{
	if(POKEMON_MAX_LEVEL == _level)
		return;

	++_level;
	
	evolution();
	settingStatus();
	gainSkill();
}

void pokemon::settingStatus()
{
	// 능력치
	_defaultStatus = POKEMONDATA->calculateStatus(_level, _index);
	_currentStatus = _defaultStatus;
	
	// 그 다음 레벨까지 필요한 누적 경험치 갱신
	_currentLvExp = POKEMONDATA->calcuateExp(_level, _index);
	_currentExp = _currentLvExp;
	if (_level < POKEMON_MAX_LEVEL)
	{
		_nextLvExp = POKEMONDATA->calcuateExp(_level + 1, _index);
	}
	else
	{
		_nextLvExp = _currentLvExp;
	}

	_displayHp = _currentStatus.hp;
	_displayExp = _currentExp;
}

void pokemon::evolution()
{
	pokemonInfo info = *POKEMONDATA->getPokemonInfomation(_index);
	int evolutionLv = info.getEvolutionLevel();
	if( 0 != evolutionLv && evolutionLv == _level )
	{
		int evolutionIndex = info.getEvolutionIndex();
		if (POKEMON_NONE != evolutionIndex)
		{
			_level = evolutionIndex;
		}
	}
}

void pokemon::gainSkill()
{
}

void pokemon::attack()
{
	if(!_target)
		return;

	if (0 != _hitDamage)
		_target->takeDamage(_hitDamage);
	if( PMUC_NONE != _hitUpsetCondition.type)
		_target->setUpsetCondition(_hitUpsetCondition);
}

void pokemon::startProgessing(function<void(void)> func, PROGRESSING_TYPE type)
{
	_progressingType = type;
	_displayTime = PROGRESSING_TERM;
	_function = std::move(func);
}

void pokemon::endProgressing()
{
	_progressingType = PROGRESSING_NONE;
	_function = NULL;
}

void pokemon::progressingIncreaseHp()
{
	++_displayExp;
	
	// 필요 경험치 채웠으면 레벨업
	if ( _displayExp == _nextLvExp )
	{
		levelUp();
	}
	// 경험치 다 올렸으면 콜백함수 해제
	else if ( _displayExp == _currentExp )
	{
		endProgressing();
	}
}

void pokemon::progressingDecreaseHp()
{
	--_displayHp;

	// 피를 뻈으면 콜백함수 해제
	if ( _displayHp == _currentStatus.hp )
	{
		endProgressing();
	}
}

void pokemon::progressingIncreseExp(void)
{
	++_displayHp;

	// 피 채웠으면 콜백함수 해제
	if ( _displayHp == _currentStatus.hp )
	{
		endProgressing();
	}
}

void pokemon::progressintSkillEffect(int idx)
{
	//_skills[idx]->update();

	// todo 스킬 이펙트 끝났다면
	//if ()
	{
		attack();
		_hitDamage = 0;
		_hitUpsetCondition.clear();
		endProgressing();
	}
}
