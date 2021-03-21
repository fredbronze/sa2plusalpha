#include "SA2ModLoader.h"
#include "utils.h"

namespace AltFixes
{
	constexpr int ChaosZero_Punch_Start = 0x7295A7;
	constexpr int ChaosZero_Punch_End = 0x7295BE;
	int ChaosZero_Punch;
	void ChaosZero_Punch_Detour()
	{
		__asm push  eax
		if (MainCharObj2[0]->CharID2 != Characters_Chaos) __asm
		{
			pop     eax
			push    ChaosZero_Punch
		}
		else __asm
		{
			pop      eax
			push     0x72954B
		}
	}
	
	constexpr int ChaosZero_Uppercut_Start = 0x729702;
	constexpr int ChaosZero_Uppercut_End = 0x729720;
	int ChaosZero_Uppercut;
	void ChaosZero_Uppercut_Detour()
	{
		if (MainCharObj2[0]->CharID2 != Characters_Chaos)
			JumpTo(ChaosZero_Uppercut);
		else
			JumpTo(0x7296E4);
	}

	void Init(int setting)
	{
		if (setting != 0) return;

#ifdef FIXUPS
		ChaosZero_Punch = Repair(new Trampoline(ChaosZero_Punch_Start, ChaosZero_Punch_End, ChaosZero_Punch_Detour));
		ChaosZero_Uppercut = Repair(new Trampoline(ChaosZero_Uppercut_Start, ChaosZero_Uppercut_End, ChaosZero_Uppercut_Detour));
#else
		ChaosZero_Punch = addr(new Trampoline(ChaosZero_Punch_Start, ChaosZero_Punch_Start + 7, ChaosZero_Punch_Detour));
		ChaosZero_Uppercut = addr(new Trampoline(ChaosZero_Uppercut_Start, ChaosZero_Uppercut_Start + 7, ChaosZero_Uppercut_Detour));
#endif
	}

}
