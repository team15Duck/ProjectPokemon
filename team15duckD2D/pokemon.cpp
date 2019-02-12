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
{
	_beforeLvStatus.clear();
	_currentLvStatus.clear();
	_nowStatus.clear();
	for (int ii = 0; ii < POKEMON_SKILL_MAX_COUNT; ++ii)
	{
		_skills[ii].clear();
	}
	_upsetCondition.clear();
	_function = NULL;
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
	_currentExp = _currentLvExp;

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
	pack->upsetConditionApplyValue = _upsetCondition.applyValue;
	pack->upsetConditionReleseValue = _upsetCondition.releaseValue;

	// 현재 상태값들
	pack->hp = _nowStatus.hp;
	pack->attk = _nowStatus.attk;
	pack->dex = _nowStatus.dex;
	pack->spAttk = _nowStatus.spAttk;
	pack->spDex = _nowStatus.spDex;
	pack->speed = _nowStatus.speed;

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
	_upsetCondition.applyValue = pack->upsetConditionApplyValue;
	_upsetCondition.releaseValue = _upsetCondition.type; pack->upsetConditionReleseValue;

	// 현재 상태값들
	_nowStatus.hp		= pack->hp;
	_nowStatus.attk		= pack->attk;
	_nowStatus.dex		= pack->dex;
	_nowStatus.spAttk	= pack->spAttk;
	_nowStatus.spDex	= pack->spDex;
	_nowStatus.speed	= pack->speed;

	for (int ii = 0; ii < POKEMON_SKILL_MAX_COUNT; ++ii)
	{
		_skills[ii]._skillId	= pack->skillIds[ii];
		_skills[ii]._currentPP	= pack->currentPPs[ii];
		_skills[ii]._maxPP		= pack->maxPPs[ii];
	}
}

void pokemon::active()
{
	//if(_ == _upsetCondition.type)
}

bool pokemon::levelUpForce()
{
	if(POKEMON_MAX_LEVEL == _level)
		return false;

	_beforeLvStatus = _currentLvStatus;
	
	++_level;
	settingStatus();
	_currentExp += (_nextLvExp - _currentLvExp);
	// 강제 렙업은 경험치 오르는 효과 없음

	return true;
}

void pokemon::useSkill(int idx)
{
	int skillId = _skills[idx]._skillId;

	// todo
	pokemonSkill skill;
	pokemonUC* upsetCondition = skill.getUpsetCondition();

	int damage = calculateAttkValue(idx);
	attack(damage, upsetCondition);
	startProgessing(bind(&pokemon::progressintSkillEffect, this, idx), PROGRESSING_SKILL);
}



void pokemon::takeDamage(int value)
{
	_displayHp = _nowStatus.hp;
	_nowStatus.hp -= value;
	if (_nowStatus.hp < 0 )
	{
		_nowStatus.hp = 0;
	}
}

void pokemon::fillHp()
{
	_displayHp = _nowStatus.hp;
	_nowStatus.hp = _currentLvStatus.hp;
	startProgessing(bind(&pokemon::progressingIncreaseHp, this), PROGRESSING_VALUE);
}

void pokemon::hillHp(int value)
{
	_displayHp = _nowStatus.hp;
	_nowStatus.hp += value;
	if (_currentLvStatus.hp < _nowStatus.hp )
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
	
	// 필요 경험치 채웠으면 레벨업
	if (_nextLvExp < _currentExp )
	{
		levelUp();
	}

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

void pokemon::startTakeDamageDisplay()
{
	startProgessing(bind(&pokemon::progressingDecreaseHp, this), PROGRESSING_VALUE);
}

void pokemon::levelUp()
{
	if(POKEMON_MAX_LEVEL == _level)
		return;

	_beforeLvStatus = _currentLvStatus;
	++_level;
	
	evolution();
	settingStatus();
	gainSkill();
}

void pokemon::settingStatus()
{
	// 능력치
	_currentLvStatus = POKEMONDATA->calculateStatus(_level, _index);
	_nowStatus = _currentLvStatus;
	
	// 그 다음 레벨까지 필요한 누적 경험치 갱신
	_currentLvExp = POKEMONDATA->calcuateExp(_level, _index);
	if (_level < POKEMON_MAX_LEVEL)
	{
		_nextLvExp = POKEMONDATA->calcuateExp(_level + 1, _index);
	}
	else
	{
		_nextLvExp = _currentLvExp;
		_currentExp = _currentLvExp;
	}

	_displayHp = _nowStatus.hp;
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

void pokemon::attack(int value, pokemonUC* upsetCondition)
{
	if(!_target)
		return;

	_target->takeDamage(value);
	if( PMUC_NONE != upsetCondition->type)
		_target->setUpsetCondition(*upsetCondition);
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
	++_displayHp;

	// 피 채웠으면 콜백함수 해제
	if (_displayHp == _nowStatus.hp)
	{
		endProgressing();
	}
}

void pokemon::progressingDecreaseHp()
{
	--_displayHp;

	// 피를 뻈으면 콜백함수 해제
	if ( _displayHp == _nowStatus.hp )
	{
		endProgressing();
	}
}

void pokemon::progressingIncreseExp(void)
{
	++_displayExp;

	// 경험치 다 올렸으면 콜백함수 해제
	if (_displayExp == _currentExp)
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
		endProgressing();

		if(_target)
			_target->startTakeDamageDisplay();
	}
}

int pokemon::calculateAttkValue(int skillIdx)
{
	// 타겟이 없다면 
	if(!_target)
		return 0;

	//_skills[idx]._skillId
	pokemonSkill skill;
	pokemonSkillInfo info = *skill.getSkillInfomation();

	int value = 0;
	float power = (1.f * info.getPower());		// 위력
	float attk = 1.f;							// 공격
	float dex = 1.f;							// 방어
	float vitalPoint = 1.f;						// 급소
	float randValue = 1.f;						// 랜덤값
	float conflictValue = 1.f;					// 타입 상성
	
	// 공격력, 방어력
	switch (info.getSkillCategory())
	{
		case PMSC_ATTACK:
		{
			attk = _nowStatus.attk;
			dex = _target->getDex();

			break;
		}

		case PMSC_SPECAIL:
		{
			attk = _nowStatus.spAttk;
			dex = _target->getSpDex();
			break;
		}
	}

	// 급소
	value = RND->getFromIntTo(1, 100);
	if (value < 6) // 급소맞을 확률은 6% : 사실 6.25%인데 소수점은 버려버림
	{
		vitalPoint = 2.f;
	}

	// 랜덤값
	value = RND->getFromIntTo(217, 255);
	randValue = floorf(value * 100.f / 255.f);
	
	// 타입상성
	conflictValue = POKEMONDATA->calculateConflictValue(_index, _target->getPokeminIndex());

	float damage = 0.f;
	damage = ((((float)_level * 2.f / 5.f) + 2.f) * power * attk / 50.f / dex + 2) * (vitalPoint * 2) * conflictValue * randValue / 100.f;

	return static_cast<int>(damage);
}

void pokemon::applyUpsetCondition()
{
}
