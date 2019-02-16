#pragma once
 
//턴 ----------- 1에서 현재값을 빼주며 변경
enum BattleTurn
{
	TURN_PLAYER,
	TURN_ENEMY,
	TURN_MAX = TURN_ENEMY
};

//페이즈 이넘으로 나눠서 ㄱㄱ
enum BattlePhase
{
	PHASE_START,
	PHASE_BATTLE,
	PHASE_END,
	PHASE_CHANGE,
	PHASE_EVOLUTION
};

//배틀 단계
enum BattleStep
{
	STEP_APPLY_BUFF,			// 버프 적용
	STEP_USE_OWNER_ITEM,		// 소지하고 있는 아이템 사용
	STEP_APPLY_UPSETCONDITON,	// 상태 이상 적용
	STEP_ACTIVE,				// 행동 : 아이템 사용, 스킬 사용, 도망, 포켓몬 교체 등
	STEP_END,					// 배틀 종료 : 경험치 획득

	STEP_NONE,
	STEP_COUNT = STEP_NONE,
};

enum PlayerActive
{
	PA_USE_SKILL,				// 스킬 사용
	PA_USE_ITEM,				// 아이템 사용
	PA_CHANGE_POKEMON,			// 포켓몬 교체
	PA_RUNAWAY,					// 도망
	PA_ACTIVE_END,				// 행동 종료

	PA_NONE,
	PA_COUNT = PA_NONE,
};
