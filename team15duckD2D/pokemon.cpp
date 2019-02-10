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
, _img(nullptr)
{
	_defaultStatus.clear();
	_currentStatus.clear();
	for (int ii = 0; ii < POKEMON_SKILL_MAX_COUNT; ++ii)
	{
		_skills[ii].clear();
	}
}


pokemon::~pokemon()
{
}

HRESULT pokemon::init( int idNo
					  ,pokemonInfo* info
					  ,int level
					  ,int nextExp
					  ,bool isMyPokemon
					  ,pokemonStatus* status
					  ,pokemonSkill* skills)
{
	return S_OK;
}

void pokemon::release()
{
	_item = nullptr;
	_img = nullptr;
}

void pokemon::update()
{
	if ( _function != NULL )
	{
		_displayTime -= TIMEMANAGER->getElapsedTime();
		if ( _displayTime < 0 )
		{
			_function();
			_displayTime = PROGRESSING_TERM;
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
	_currentExp = pack->currentExp;
	settingStatus();

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
	startProgessingValue(bind(&pokemon::progressingDecreaseHp, this));
}

void pokemon::fillHp()
{
	_displayHp = _currentStatus.hp;
	_currentStatus.hp = _defaultStatus.hp;
	startProgessingValue(bind(&pokemon::progressingIncreaseHp, this));
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
		startProgessingValue(bind(&pokemon::progressingIncreaseHp, this));
	}
}

void pokemon::gainExp(int exp)
{
	_displayExp = _currentExp;
	_currentExp += exp;
	startProgessingValue(bind(&pokemon::progressingIncreseExp, this));
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
	++_level;
	settingStatus();
	
	evolution();
	gainSkill();
}

void pokemon::settingStatus()
{
	// todo 그 다음 레벨까지 필요한 누적 경험치 갱신
	// _currentLvExp = _nextLvExp; 
	//_nextLvExp =  
}

void pokemon::evolution()
{
}

void pokemon::gainSkill()
{
}

void pokemon::startProgessingValue(function<void(void)> func)
{
	_displayTime = PROGRESSING_TERM;
	_function = std::move(func);
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
		_function = NULL;
	}
}

void pokemon::progressingDecreaseHp()
{
	--_displayHp;

	// 피를 뻈으면 콜백함수 해제
	if ( _displayHp == _currentStatus.hp )
	{
		_function = NULL;
	}
}

void pokemon::progressingIncreseExp(void)
{
	++_displayHp;

	// 피 채웠으면 콜백함수 해제
	if ( _displayHp == _currentStatus.hp )
	{
		_function = NULL;
	}
}
