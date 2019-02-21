#include "stdafx.h"
#include "pokemon.h"


pokemon::pokemon()
: _idNo(0)
, _index(POKEMON_NONE)
, _evolutionIndex(POKEMON_NONE)
, _ownerItemType(ITEM_TYPE_NONE)
, _level(0)
, _currentLvExp(0)
, _currentExp(0)
, _nextLvExp(0)
, _isAwake(false)
, _isMyPokemon(false)
, _displayHp(0)
, _displayExp(0)
, _displayTime(0.f)
, _displayTimeCnt(0.f)
, _isIdle(true)
, _isPossibleEvolution(false)
, _isLevelUp(false)
, _buff(PMB_NONE)
, _img(nullptr)
, _target(nullptr)
, _destX(0.f), _destY(0.f)
, _frameX(0), _frameY(0)
{
	_beforeLvStatus.clear();
	_currentLvStatus.clear();
	_nowStatus.clear();
	_displayDamageText.clear();
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
	assert(nullptr != info);

	_idNo = idNo;
	_index = index;
	_evolutionIndex = info->getEvolutionIndex();
	_type = info->getPokemonType();
	_nickName = *info->getPokemonName();
	_level = level;
	_isMyPokemon = isMyPokemon;

	_isAwake = true;

	settingStatus();
	_currentExp = _currentLvExp;
	_displayExp = _currentExp;

	// ���� ��ų ����
	map<int, vector<int>> skillMap = *info->getSkillMap();
	vector<int> skills = skillMap[1];
	for (int ii = 0; ii < skills.size() && ii < POKEMON_SKILL_MAX_COUNT; ++ii)
	{
		_skills[ii].init(skills[ii]);
	}

	_img = IMAGEMANAGER->findImage("pokemon_ingame");

	// todo ȭ�� �����ġ
	int idx = _index * 2;
	if (_isMyPokemon)
	{
		idx += 1;
		_destX = 160.f;
		_destY = 210.f;
	}
	else
	{
		_destX = 576.f;
		_destY = 42.f;
	}
	
	_frameX = idx % _img->GetMaxFrameX();
	_frameY = idx / _img->GetMaxFrameX();


	// �׽�Ʈ
	_damage = 0;
	
	return S_OK;
}

void pokemon::release()
{
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
				_displayTimeCnt -= TIMEMANAGER->getElapsedTime();
				if (_displayTimeCnt < 0)
				{
					_function();
					_displayTimeCnt = _displayTime;
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
	_img->frameRender(CAMERA->getPosX() + _destX, CAMERA->getPosY() + _destY, _frameX, _frameY);

	WCHAR str[256];
	swprintf_s(str, L"Hp : %d / %d", getDisplayHp(), getMaxHp());
	D2DMANAGER->drawText(str, CAMERA->getPosX() + _destX - 150, CAMERA->getPosY() + _destY + 100);
	swprintf_s(str, L"Get Damage : %d", _damage);
	D2DMANAGER->drawText(str, CAMERA->getPosX() + _destX - 150, CAMERA->getPosY() + _destY + 120);
	
	if (_isIdle)
	{
		swprintf_s(str, L" IDLE ");
		D2DMANAGER->drawText(str, CAMERA->getPosX() + _destX - 150, CAMERA->getPosY() + _destY + 140);
	}

	D2DMANAGER->drawText(_state.c_str(), CAMERA->getPosX() + _destX - 150, CAMERA->getPosY() + _destY + 160);


	for (int ii = 0; ii < POKEMON_SKILL_MAX_COUNT; ++ii)
	{
		pokemonSkillInfo info = *_skills[ii].getSkillInfomation();
		wstring s;
		s = string2wstring(info.getSkillName());
		s.append(to_wstring(_skills[ii].getCurrentPP()));
		s.append(L" / ");
		s.append(to_wstring(_skills[ii].getMaxPP()));
		D2DMANAGER->drawText(s.c_str(), CAMERA->getPosX() + _destX - 150, CAMERA->getPosY() + _destY + 200 + ii * 20);
	}

}

pmPack* pokemon::makeSavePack()
{
	pmPack* pack = new pmPack;

	pack->idNo = _idNo;
	pack->index = _index;

	pack->nickName = _nickName.c_str();
	pack->trainerNote = _trainerNote.c_str();

	pack->itemType = _ownerItemType;

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

	_ownerItemType = static_cast<ITEM_TYPE>(pack->itemType);

	_level = pack->level;
	settingStatus();
	_currentExp = pack->currentExp;
	_displayExp = _currentExp;

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

void pokemon::battelStart()
{
	_buff = PMB_NONE;
}

void pokemon::battleEnd()
{
	_battleUI = nullptr;
	_target = nullptr;
	_buff = PMB_NONE;
}

bool pokemon::applyBuff()
{
	bool isApply = false;
	wstring script = L"";

	if (!_isMyPokemon)
		script = L"���� ";
	script.append(string2wstring(_nickName));
	script.append(L"��");
	
	_state = L"���� ����";
	switch (_buff)
	{
		case PMB_ABSORB_HP:
		{
			hillHp(10);
			_target->takeDamage(10);
			_target->startTakeDamageDisplay();

			_state = L"�� ����";
			script = L" hp�� ����ߴ�.!";

			isApply = true;
			break;
		}
		default:
		{
			isApply = false;
			_state = L"���� �� ���� ����";
		}
			break;
	}

	if(isApply)
		sendScriptToUI(script);

	_isIdle = !isApply;

	return isApply;
}

bool pokemon::useOwnerItem()
{
	bool isUseOwnerItem = false;
	wstring script;
	_isIdle = false;

	_state = L"���� ������ ���";
	// todo ������ Ÿ�Ժ��� ���� üũ �� ������ ����ϱ�
	switch (_ownerItemType)
	{
		default:
			_state = L"���� ������ ����";
			break;
	}

	// ���� �������� ������� �ʾҴٸ� �ൿ ���� ��ȯ
	if (isUseOwnerItem)
		sendScriptToUI(script);
	else
		_isIdle = true;


	return isUseOwnerItem;
}

bool pokemon::applyUpsetCondition()
{
	bool isApplyUpsetCondition = false;
	wstring script = L"";
	
	_isIdle = false;

	if (!_isMyPokemon)
		script = L"���� ";
	script.append(string2wstring(_nickName));
	script.append(L"��(��)");

	_state = L"���� �̻� ����";

	bool releaseCheck = false;
	switch (_upsetCondition.type)
	{
		case PMUC_POISON:
		{
			script = L"";
			_state = L"PMUC_POISON";
			int damage = static_cast<int>(_currentLvStatus.hp / (float)_upsetCondition.applyValue);
			if( 10 < damage )
				damage = 10;
			takeDamage(damage);

			isApplyUpsetCondition = true;
			break;
		}
		case PMUC_FROZEN:
		{
			_state = L"PMUC_POISON";
			int percent = RND->getInt(100);
			if (percent < 20) // 1/5 Ȯ���� ���� ����
			{
				clearUpsetCondtion();
				releaseCheck = true;
			}
			break;
		}
		case PMUC_PALALYSIS:
		case PMUC_SLEEP:
		{
			_state = L"PMUC_PALALYSIS | PMUC_SLEEP";
			if (_upsetCondition.releaseValue <= 0)
			{
				clearUpsetCondtion();
				releaseCheck = true;
			}
			else
				--_upsetCondition.releaseValue;

			break;
		}

		case PMUC_BURN:
		{
			_state = L"PMUC_BURN";
			int damage = static_cast<int>(_currentLvStatus.hp / (float)_upsetCondition.applyValue);
			takeDamage(damage);
			break;
		}

		default:
			_state = L"���� �̻� ����";
			break;
	}

	if (PMUC_NONE != _upsetCondition.type) // ���� �̻�ȿ���� ������ �ȵǾ��ٸ� 
	{
		_state = L"���� �̻� ȿ�� ����";
		script = _upsetCondition.name;
		script.append(L"�� �ɷȴ�.");
		sendScriptToUI(script);

		startProgessing(bind(&pokemon::progressingApplyUpsetCondition, this), PROGRESSING_SKILL);
	}
	else
	{
		if (releaseCheck)
		{
			_state = L"�����̻� ����";
			script = _upsetCondition.name;
			script.append(L"��(��) Ǯ�ȴ�.");

			sendScriptToUI(script);
		}
		// ���� �ൿ ���
		_isIdle = true;
	}

	return isApplyUpsetCondition;
}

bool pokemon::useSkill(int idx)
{
	wstring script = L"";
	bool isUseSkill = false;
	if(!_isMyPokemon)
		script = L"���� ";

	script.append(string2wstring(_nickName));

	_state = L"��ų ���";
	_isIdle = true;
	if (idx < 0 || POKEMON_SKILL_MAX_COUNT < idx)
	{
		_state = L"���� ��ų";
		script = L"ERROR : ���� ��ų";
	}
	else if (!_skills[idx].isUsableSkill())
	{
		_state = L"PP ����";
		script = L"PP �� �����մϴ�.";
	}
	else
	{
		pokemonSkill* skill = &_skills[idx];
		pokemonSkillInfo skillInfo = *skill->getSkillInfomation();

		// pp �Ҹ�
		int pp = skill->getCurrentPP();
		skill->setCurrentPP(pp - 1);

		// �����ߴ���
		int rate = skillInfo.getAccuracyRate();
		int value = RND->getFromIntTo(1, 100);

		// ������
		if (rate < value)
		{
			_state = L"���� ����";
			script.append(L"��\n\n");
			script.append(string2wstring(skillInfo.getSkillName()));
			script = L"��(��) ���¾Ҵ�.";
		}
		else
		{
			_isIdle = false;
			_state = L" ���� ���� ��ų id : " + string2wstring(skillInfo.getSkillName());

			// �����, ���� 
			pokemonUC* upsetCondition = skill->getUpsetCondition();
			POKEMON_BUFF buff = skillInfo.getBuffType();
			if (PMB_NONE != buff)
				_buff = buff;

			int damage = calculateAttkValue(idx);
			attack(damage, upsetCondition);
			
			startProgessing(bind(&pokemon::progressintSkillEffect, this, idx), PROGRESSING_SKILL);

			script.append(L"��\n\n");
			script.append(string2wstring(skillInfo.getSkillName()));
			script.append(L"!");

			isUseSkill = true;
		}
	}

	sendScriptToUI(script);

	return isUseSkill;
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

void pokemon::takeDamage(int value, SKILL_INFLUENCE influence)
{
	_state = L"������ ����";
	_damage = value;
	_displayHp = _nowStatus.hp;
	
	if (_nowStatus.hp <= value )
	{
		_nowStatus.hp = 0;
		_isAwake = false;
	}
	else
		_nowStatus.hp -= value;
	
	_displayValue = _displayHp - _nowStatus.hp;
}

bool pokemon::evolution()
{
	pokemonInfo* info = POKEMONDATA->getPokemonInfomation(_index);
	int evolutionLv = info->getEvolutionLevel();
	if (0 != evolutionLv && evolutionLv <= _level)
	{
		//���ϸ� ��ȭ�ƾƤ���
		POKEMON evolutionIndex = info->getEvolutionIndex();
		if (POKEMON_NONE != evolutionIndex)
		{
			_index = evolutionIndex;
			settingStatus();

			int idx = _index * 2;
			if (_isMyPokemon)
				idx += 1;

			_frameX = idx % _img->GetMaxFrameX();
			_frameY = idx / _img->GetMaxFrameX();

			pokemonInfo* evolutionInfo = POKEMONDATA->getPokemonInfomation(evolutionIndex);
			if (evolutionInfo)
			{
				_type = info->getPokemonType();
				_nickName = *evolutionInfo->getPokemonName();
				_evolutionIndex = info->getEvolutionIndex();
			}
			
			_isPossibleEvolution = false;

			return true;
		}
	}

	return false;
}

bool pokemon::checkPossibleEvolution()
{
	pokemonInfo* info = POKEMONDATA->getPokemonInfomation(_index);
	int evolutionLv = info->getEvolutionLevel();
	if (0 != evolutionLv && evolutionLv <= _level)
	{
		//���ϸ� ��ȭ�ƾƤ��� ����?
		POKEMON evolutionIndex = info->getEvolutionIndex();
		if (POKEMON_NONE != evolutionIndex)
		{
			return true;
		}
	}

	return false;
}

bool pokemon::evolutionForce()
{
	pokemonInfo* info = POKEMONDATA->getPokemonInfomation(_index);
	int evolutionLv = info->getEvolutionLevel();
	if (0 != evolutionLv)
	{
		//���ϸ� ��ȭ�ƾƤ���
		POKEMON evolutionIndex = info->getEvolutionIndex();
		if (POKEMON_NONE != evolutionIndex)
		{
			_index = evolutionIndex;
			settingStatus();
			return true;
		}
	}

	return false;
}

bool pokemon::displayEvolution()
{
	if(!_isPossibleEvolution)
		return false;

	evolution();
	return true;
}


void pokemon::fillHp()
{
	_displayValue = _currentLvStatus.hp - _nowStatus.hp;
	
	_displayHp = _nowStatus.hp;
	_nowStatus.hp = _currentLvStatus.hp;
	startProgessing(bind(&pokemon::progressingIncreaseHp, this), PROGRESSING_VALUE);
}

void pokemon::hillHp(int value)
{
	if (_currentLvStatus.hp < _nowStatus.hp + value )
	{
		fillHp();
	}
	else
	{
		_displayValue = value;
		_displayHp = _nowStatus.hp;
		_nowStatus.hp += value;

		startProgessing(bind(&pokemon::progressingIncreaseHp, this), PROGRESSING_VALUE);
	}
}

void pokemon::gainExp(int exp)
{
	_isLevelUp = false;
	_displayValue = exp;
	_displayExp = _currentExp;
	_currentExp += exp;
	
	// �ʿ� ����ġ ä������ ������
	//if (_nextLvExp < _currentExp )
	//{
	//	levelUp();
	//	_isPossibleEvolution = checkPossibleEvolution();
	//}

	startProgessing(bind(&pokemon::progressingIncreseExp, this), PROGRESSING_VALUE);
}

void pokemon::gainExpEnterBattle(int exp)
{
	_isLevelUp = false;
	_displayValue = exp;
	_displayExp = _currentExp;
	_currentExp += exp;

	// �ʿ� ����ġ ä������ ������
	while (_currentExp < _nextLvExp || POKEMON_MAX_LEVEL != _level)
	{
		levelUp();
		if(!_isPossibleEvolution)
			_isPossibleEvolution = checkPossibleEvolution();
	}
}

ITEM_TYPE pokemon::withdrawItem()
{
	ITEM_TYPE type = _ownerItemType;
	_ownerItemType = ITEM_TYPE_NONE;

	return type;
}

void pokemon::clearUpsetCondtion()
{
	_upsetCondition.clear();
}

void pokemon::clearBuff()
{
	_buff = PMB_NONE;
}

void pokemon::changeSkill(int idx, int skillId)
{
	if(idx < 0 || POKEMON_SKILL_MAX_COUNT <= idx)
		return;

	if(SKILL_INDEX_NONE == skillId)
		return;

	_skills[idx].init(skillId);
}

void pokemon::startTakeDamageDisplay()
{
	startProgessing(bind(&pokemon::progressingDecreaseHp, this), PROGRESSING_VALUE);
}

void pokemon::setUpsetCondition(pokemonUC upsetCondition)
{
	wstring script = L"";

	if (!_isMyPokemon)
		script = L"���� ";
	script.append(string2wstring(_nickName));
	script.append(L"��(��)");

	if (upsetCondition.type != _upsetCondition.type)
	{
		_upsetCondition = upsetCondition;
		script.append(_upsetCondition.name);
		script.append(L"�� �ɷȴ�.");
		
		_state = L"���� �̻� ȿ�� ����";
	}
	else
	{
		script = L"�ҿ��� ������.";
		_state = L"������ ���� �̻� ȿ��";
	}
}

wstring pokemon::getPokemonTypeString()
{
	switch (_type)
	{
	case PM_TYPE_NORMAL:
		return L"�븻";
	case PM_TYPE_FIRE:
		return L"��";
	case PM_TYPE_WATER:
		return L"��";
	case PM_TYPE_ELECTRONIC:
		return L"����";
	case PM_TYPE_GRASS:
		return L"Ǯ";
	case PB_TYPE_POISION:
		return L"��";
	case PB_TYPE_DRAGON:
		return L"�巡��";
	}

	return L"";
}

void pokemon::levelUp()
{
	if(POKEMON_MAX_LEVEL == _level)
		return;

	_beforeLvStatus = _currentLvStatus;
	++_level;
	_isLevelUp = true;
	
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
}



void pokemon::gainSkill()
{
	if(!_isMyPokemon)
		return;

	pokemonInfo* info = POKEMONDATA->getPokemonInfomation(_index);
	if(!info)
		return;

	map<int, vector<int>> skillMap = *info->getSkillMap();

	// �������� ���� ��ų ȹ��
	if (skillMap.find(_level) != skillMap.end())
	{
		vector<int> newSkills = skillMap[_level];
		int skillCnt = 0;
		for (; skillCnt < POKEMON_SKILL_MAX_COUNT; ++skillCnt)
		{
			if(_skills[skillCnt].getSkillID() == SKILL_INDEX_NONE)
				break;
		}

		int size = newSkills.size();
		for (int ii = 0; ii < size; ++ii)
		{
			if (skillCnt < POKEMON_SKILL_MAX_COUNT - 1) // ��ų�� �ƽø��� �ƴϸ� �׳� ȹ��
			{
				_skills[skillCnt].init(newSkills[ii]);
				skillCnt += 1;
			}
			else // ��ų�� �ƽø��̶�� ó�� ��ų�� �� ��ų�� ��ü // todo ���� ��ü �� �� �ֵ��� �ٲ����
			{
				_skills[0].init(newSkills[ii]);
			}
		}
	}
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
	if (PROGRESSING_VALUE == type)
	{
		if (0 == _displayValue)
		{
			endProgressing();
			return;
		}

		_displayTime = static_cast<float>(PROGRESSING_TERM) / _displayValue;
		_displayTimeCnt = _displayTime;
	}

	_isIdle = false;
	_progressingType = type;
	_function = std::move(func);
}

void pokemon::endProgressing()
{
	_isIdle = true;
	_progressingType = PROGRESSING_NONE;
	_function = NULL;

	if (_isLevelUp)
	{
		_isPossibleEvolution = checkPossibleEvolution();

		wstring script = L"�������� �Ͽ���!";
		sendScriptToUI(script);

		_isLevelUp = false;
	}
}

void pokemon::progressingIncreaseHp()
{
	// �� ä������ �ݹ��Լ� ����
	if (_displayHp == _nowStatus.hp)
		endProgressing();
	else
		++_displayHp;
}

void pokemon::progressingDecreaseHp()
{
	// �Ǹ� �Q���� �ݹ��Լ� ����
	if ( _displayHp == _nowStatus.hp )
	{
		if ( _displayDamageText.size() != 0 )
		{
			sendScriptToUI(_displayDamageText);
			_displayDamageText.clear();
		}
		endProgressing();
	}
	else
		--_displayHp;
}

void pokemon::progressingIncreseExp(void)
{
	// ����ġ �� �÷����� �ݹ��Լ� ����
	if (_displayExp == _currentExp)
		endProgressing();
	else
	{
		if (_nextLvExp <= _displayExp)
		{
			levelUp();
			if (POKEMON_MAX_LEVEL == _level)
				endProgressing();
		}

		++_displayExp;
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

			// �Ǹ� ������ �ݹ��Լ� ����
			if (_displayHp == _nowStatus.hp)
				endProgressing();
			else
				--_displayHp;

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
				_isIdle = true;
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
				_isIdle = true;
			}
			endProgressing();
			break;
		}

		case PMUC_BURN:
		{

			// �Ǹ� �Q���� �ݹ��Լ� ����
			if (_displayHp == _nowStatus.hp)
				endProgressing();
			else
				--_displayHp;

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
	pokemonSkill skill = _skills[skillIdx];
	pokemonSkillInfo info = *skill.getSkillInfomation();

	int value = 0;
	float power = (1.f * info.getPower());		// ����
	float attk = 1.f;							// ����
	float dex = 1.f;							// ���
	float vitalPoint = 1.f;						// �޼�
	float randValue = 1.f;						// ������
	float conflictValue = 1.f;					// Ÿ�� ��
	
	// ������ 0�� ��ų�� ������ ����
	if (info.getPower() == 0)
	{
		return 0;
	}

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



	// ������
	value = RND->getFromIntTo(217, 255);
	randValue = floorf(value * 100.f / 255.f);
	
	// Ÿ�Ի�
	SKILL_INFLUENCE influence = POKEMONDATA->checkConflict(info.getSkillType(), _target->getPokeminIndex());
	wstring script;
	switch ( influence )
	{
		case SI_NORMAL:
		{
			conflictValue = 1.f;
			break;
		}
		case SI_SLIGHT:
		{
			script = L"ȿ���� �����ΰ� ����.";
			conflictValue = 0.5f;
			break;
		}
		case SI_EXCELLENT:
		{
			script = L"ȿ���� �����ߴ�.";
			conflictValue = 2.f;
			break;
		}
	}

	// �޼�
	value = RND->getFromIntTo(1, 100);
	if (value < 6) // �޼Ҹ��� Ȯ���� 6% : ��� 6.25%�ε� �Ҽ����� ��������
	{
		vitalPoint = 2.f;
		script = L"�޼ҿ� �¾Ҵ�!";
	}
	_target->setDisplayDamageText(script);
	
	float damage = 0.f;
	damage = ((((float)_level * 2.f / 5.f) + 2.f) * power * attk / 50.f / dex + 2.f) * (vitalPoint * 1.f) * conflictValue * randValue / 100.f;

	return static_cast<int>(damage);
}

void pokemon::faint()
{
	battleEnd();
	_upsetCondition.clear();
}

void pokemon::sendScriptToUI(wstring script)
{
	if(_battleUI)
		_battleUI->pushScript(script);
}

