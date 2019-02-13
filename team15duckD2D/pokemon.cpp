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
, _target(nullptr)
, _img(nullptr)
, _destX(0.f), _destY(0.f)
, _frameX(0), _frameY(0)
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
					  ,bool isMyPokemon
					  )
{
	pokemonInfo* info = POKEMONDATA->getPokemonInfomation(index);

	_idNo = idNo;
	_index = info->getPokemonIndex();
	_nickName = *info->getPokemonName();
	_level = level;
	_isMyPokemon = isMyPokemon;

	_isAwake = true;

	settingStatus();
	_currentExp = _currentLvExp;

	// todo : �ε������� �̵�
	IMAGEMANAGER->addFrameImage("pokemon_ingame", L"image/pokemon.png", 5120, 4696, 20, 16);
	
	_img = IMAGEMANAGER->findImage("pokemon_ingame");

	//_destX = destX;
	//_destY = destY;

	int idx = _index * 2;
	if (_isMyPokemon)
	{
		idx += 1;
	}
	else
	{

	}
	
	_frameX = idx % _img->GetMaxFrameX();
	_frameY = idx / _img->GetMaxFrameX();


	_skills[0].init(33);

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
					_displayTime = static_cast<float>(PROGRESSING_TERM);
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

	pack->nickName = _nickName.c_str();
	pack->trainerNote = _trainerNote.c_str();

	//pack->itemIdx = _item->getItemID(); // ������ ���̵�

	pack->level = _level;
	pack->currentExp = _currentExp;

	pack->upsetConditionType = _upsetCondition.type;
	pack->upsetConditionApplyValue = _upsetCondition.applyValue;
	pack->upsetConditionReleseValue = _upsetCondition.releaseValue;

	// ���� ���°���
	pack->hp = _nowStatus.hp;
	pack->attk = _nowStatus.attk;
	pack->dex = _nowStatus.dex;
	pack->spAttk = _nowStatus.spAttk;
	pack->spDex = _nowStatus.spDex;
	pack->speed = _nowStatus.speed;

	for (int ii = 0; ii < POKEMON_SKILL_MAX_COUNT; ++ii)
	{
		pack->skillIds[ii] = _skills[ii].getSkillID();
		pack->currentPPs[ii] = _skills[ii].getCurrentPP();
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
		// todo ������ ���̵�
		// pack->itemIdx = _item->getItemID(); 
	}

	_level = pack->level;
	settingStatus();
	_currentExp = pack->currentExp;

	_upsetCondition.type = (POKEMON_UPSET_CONDITION)pack->upsetConditionType;
	_upsetCondition.applyValue = pack->upsetConditionApplyValue;
	_upsetCondition.releaseValue = _upsetCondition.type; pack->upsetConditionReleseValue;

	// ���� ���°���
	_nowStatus.hp		= pack->hp;
	_nowStatus.attk		= pack->attk;
	_nowStatus.dex		= pack->dex;
	_nowStatus.spAttk	= pack->spAttk;
	_nowStatus.spDex	= pack->spDex;
	_nowStatus.speed	= pack->speed;

	for (int ii = 0; ii < POKEMON_SKILL_MAX_COUNT; ++ii)
	{
		_skills[ii].init(pack->skillIds[ii]);
		_skills[ii].setCurrentPP(pack->currentPPs[ii]);
	}
}


void pokemon::ready()
{
	_state = ACTIVE_WAIT_APPLY_CONDITION;
}

void pokemon::applyUpsetCondition()
{
	_state = ACTIVE_APPLY_CONDITON;
	switch (_upsetCondition.type)
	{
		case PMUC_POISON:
		{
			int damage = static_cast<int>(_currentLvStatus.hp / (float)_upsetCondition.applyValue);
			takeDamage(damage);
			break;
		}
		case PMUC_FROZEN:
		{
			int percent = RND->getInt(100);
			if (percent < 20) // 1/5 Ȯ���� ���� ����
			{
				clearUpsetCondtion();
			}
			break;
		}
		case PMUC_PALALYSIS:
		case PMUC_SLEEP:
		{
			if (_upsetCondition.releaseValue <= 0)
			{
				clearUpsetCondtion();
			}
			else
				--_upsetCondition.releaseValue;

			break;
		}

		case PMUC_BURN:
		{
			int damage = static_cast<int>(_currentLvStatus.hp / (float)_upsetCondition.applyValue);
			takeDamage(damage);
			break;
		}

		default:
			break;
	}

	if (PMUC_NONE != _upsetCondition.type) // ���� �̻�ȿ���� ������ �ȵǾ��ٸ� 
	{
		startProgessing(bind(&pokemon::progressingApplyUpsetCondition, this), PROGRESSING_SKILL);
	}
	else
	{
		// ���� �ൿ ���
		_state = ACTIVE_WAIT_ACTIVE;
	}
}

void pokemon::applyItem(item* item)
{
	_state = ACTIVE_ACTIVE;

	// todo ������ ���

}

void pokemon::useSkill(int idx)
{
	_state = ACTIVE_ACTIVE;
	int skillId = _skills[idx].getSkillID();

	// todo
	pokemonSkill skill;
	pokemonUC* upsetCondition = skill.getUpsetCondition();

	int damage = calculateAttkValue(idx);
	attack(damage, upsetCondition);
	startProgessing(bind(&pokemon::progressintSkillEffect, this, idx), PROGRESSING_SKILL);
}

void pokemon::useSkill()
{
	_state = ACTIVE_ACTIVE;
	int ii = 0;
	for (; ii < POKEMON_SKILL_MAX_COUNT; ++ii)
	{
		if (-1 == _skills[ii].getSkillID())
			break;
	}

	int index = 0;
	if (0 != ii)
		RND->getInt(ii);

	useSkill(index);
}

bool pokemon::levelUpForce()
{
	if (POKEMON_MAX_LEVEL == _level)
		return false;

	_beforeLvStatus = _currentLvStatus;

	++_level;
	settingStatus();
	_currentExp += (_nextLvExp - _currentLvExp);
	// ���� ������ ����ġ ������ ȿ�� ����

	return true;
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
	
	// �ʿ� ����ġ ä������ ������
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

void pokemon::changeSkill(int idx, int skillId)
{
	if(idx < 0 || POKEMON_SKILL_MAX_COUNT <= idx)
		return;

	if(-1 == skillId)
		return;

	_skills[idx].init(skillId);
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
	// �ɷ�ġ
	_currentLvStatus = POKEMONDATA->calculateStatus(_level, _index);
	_nowStatus = _currentLvStatus;
	
	// �� ���� �������� �ʿ��� ���� ����ġ ����
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
	pokemonInfo* info = POKEMONDATA->getPokemonInfomation(_index);
	int evolutionLv = info->getEvolutionLevel();
	if( 0 != evolutionLv && evolutionLv == _level )
	{
		int evolutionIndex = info->getEvolutionIndex();
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
	_isIdle = false;
	_progressingType = type;
	_displayTime = static_cast<float>(PROGRESSING_TERM);
	_function = std::move(func);
}

void pokemon::endProgressing()
{
	_isIdle = true;
	_progressingType = PROGRESSING_NONE;
	_function = NULL;

	switch (_state)
	{
		case pokemon::ACTIVE_APPLY_CONDITON:
		{
			_state = ACTIVE_WAIT_ACTIVE;
			break;
		}
		case pokemon::ACTIVE_ACTIVE:
		{
			_state = ACTIVE_END;
			break;
		}
	}
}

void pokemon::progressingIncreaseHp()
{
	++_displayHp;

	// �� ä������ �ݹ��Լ� ����
	if (_displayHp == _nowStatus.hp)
	{
		endProgressing();
	}
}

void pokemon::progressingDecreaseHp()
{
	--_displayHp;

	// �Ǹ� �Q���� �ݹ��Լ� ����
	if ( _displayHp == _nowStatus.hp )
	{
		endProgressing();
	}
}

void pokemon::progressingIncreseExp(void)
{
	++_displayExp;

	// ����ġ �� �÷����� �ݹ��Լ� ����
	if (_displayExp == _currentExp)
	{
		endProgressing();
	}
}

void pokemon::progressintSkillEffect(int idx)
{
	//_skills[idx]->update();
	// todo ��ų ����Ʈ �����ٸ�
	//if ()
	{
		endProgressing();

		if(_target)
			_target->startTakeDamageDisplay();
	}
}

void pokemon::progressingApplyUpsetCondition()
{
	switch (_upsetCondition.type)
	{
		case PMUC_POISON:
		{
			--_displayHp;

			// �Ǹ� �Q���� �ݹ��Լ� ����
			if (_displayHp == _nowStatus.hp)
			{
				endProgressing();
			}
			break;
		}
		case PMUC_FROZEN:
		{
			int percent = RND->getInt(100);
			if (percent < 20) // 1/5 Ȯ���� ���� ����
			{
				clearUpsetCondtion();
			}
			else
			{
				// �ൿ �Ұ�
				_state = ACTIVE_END;
			}
			endProgressing();

			break;
		}
		case PMUC_PALALYSIS:
		case PMUC_SLEEP:
		{
			if (_upsetCondition.releaseValue <= 0)
			{
				clearUpsetCondtion();
			}
			else
			{
				// �ൿ �Ұ�
				_state = ACTIVE_END;
			}
			endProgressing();
			break;
		}

		case PMUC_BURN:
		{
			--_displayHp;

			// �Ǹ� �Q���� �ݹ��Լ� ����
			if (_displayHp == _nowStatus.hp)
			{
				endProgressing();
			}

			break;
		}

		default:
		{
			endProgressing();
		}
		break;
	}
}

int pokemon::calculateAttkValue(int skillIdx)
{
	// Ÿ���� ���ٸ� 
	if(!_target)
		return 0;

	//_skills[idx]._skillId
	pokemonSkill skill;
	pokemonSkillInfo info = *skill.getSkillInfomation();

	int value = 0;
	float power = (1.f * info.getPower());		// ����
	float attk = 1.f;							// ����
	float dex = 1.f;							// ���
	float vitalPoint = 1.f;						// �޼�
	float randValue = 1.f;						// ������
	float conflictValue = 1.f;					// Ÿ�� ��
	
	// ���ݷ�, ����
	switch (info.getSkillCategory())
	{
		case PMSC_ATTACK:
		{
			attk = static_cast<float>(_nowStatus.attk);
			dex = static_cast<float>(_target->getDex());

			break;
		}

		case PMSC_SPECAIL:
		{
			attk = static_cast<float>(_nowStatus.spAttk);
			dex = static_cast<float>(_target->getSpDex());
			break;
		}
	}

	// �޼�
	value = RND->getFromIntTo(1, 100);
	if (value < 6) // �޼Ҹ��� Ȯ���� 6% : ��� 6.25%�ε� �Ҽ����� ��������
	{
		vitalPoint = 2.f;
	}

	// ������
	value = RND->getFromIntTo(217, 255);
	randValue = floorf(value * 100.f / 255.f);
	
	// Ÿ�Ի�
	conflictValue = POKEMONDATA->calculateConflictValue(_index, _target->getPokeminIndex());

	float damage = 0.f;
	damage = ((((float)_level * 2.f / 5.f) + 2.f) * power * attk / 50.f / dex + 2) * (vitalPoint * 2) * conflictValue * randValue / 100.f;

	return static_cast<int>(damage);
}

