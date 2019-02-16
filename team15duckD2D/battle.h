#pragma once
 
//�� ----------- 1���� ���簪�� ���ָ� ����
enum BattleTurn
{
	TURN_PLAYER,
	TURN_ENEMY,
	TURN_MAX = TURN_ENEMY
};

//������ �̳����� ������ ����
enum BattlePhase
{
	PHASE_START,
	PHASE_BATTLE,
	PHASE_END,
	PHASE_CHANGE,
	PHASE_EVOLUTION
};

//��Ʋ �ܰ�
enum BattleStep
{
	STEP_APPLY_BUFF,			// ���� ����
	STEP_USE_OWNER_ITEM,		// �����ϰ� �ִ� ������ ���
	STEP_APPLY_UPSETCONDITON,	// ���� �̻� ����
	STEP_ACTIVE,				// �ൿ : ������ ���, ��ų ���, ����, ���ϸ� ��ü ��
	STEP_END,					// ��Ʋ ���� : ����ġ ȹ��

	STEP_NONE,
	STEP_COUNT = STEP_NONE,
};

enum PlayerActive
{
	PA_USE_SKILL,				// ��ų ���
	PA_USE_ITEM,				// ������ ���
	PA_CHANGE_POKEMON,			// ���ϸ� ��ü
	PA_RUNAWAY,					// ����
	PA_ACTIVE_END,				// �ൿ ����

	PA_NONE,
	PA_COUNT = PA_NONE,
};
