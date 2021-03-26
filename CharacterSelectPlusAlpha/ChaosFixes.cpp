#include "SA2ModLoader.h"
#include "utils.h"

namespace ChaosFixes
{
	constexpr int Effects_Punch_Start = 0x7295A7;
	constexpr int Effects_Punch_End = 0x7295BE;
	int Effects_Punch;
	void Effects_Punch_Detour()
	{
		__asm push  eax
		if (MainCharObj2[0]->CharID2 != Characters_Chaos) __asm
		{
			pop     eax
			push    Effects_Punch
		}
		else __asm
		{
			pop      eax
			push     0x72954B
		}
	}
	
	constexpr int Effects_Uppercut_Start = 0x729702;
	constexpr int Effects_Uppercut_End = 0x729720;
	int Effects_Uppercut;
	void Effects_Uppercut_Detour()
	{
		if (MainCharObj2[0]->CharID2 != Characters_Chaos)
			JumpTo(Effects_Uppercut);
		else
			JumpTo(0x7296E4);
	}

	constexpr int DisplayCallback_ArmL_Start = 0x7316C6;
	constexpr int DisplayCallback_ArmL_End = 0x7316CE;
	int DisplayCallback_ArmL;
	void DisplayCallback_ArmL_Detour(int dummy, NJS_OBJECT* obj)
	{
		if (obj == CharacterModels[520].Model ||
			obj == CharacterModels[525].Model->child->child->child->sibling->child->child->child->child->child) __asm
		{
			mov     eax, [obj]
			pop     ebp
			push    DisplayCallback_ArmL_End
			ret
		}
		else __asm
		{
			mov     eax, [obj]
			pop     ebp
			push    0x731718
			ret
		}
	}

	constexpr int DisplayCallback_ArmR_Start = 0x73168E;
	constexpr int DisplayCallback_ArmR_End = 0x731696;
	int DisplayCallback_ArmR;
	void DisplayCallback_ArmR_Detour(int dummy, NJS_OBJECT* obj)
	{
		if (obj == CharacterModels[519].Model ||
			obj == CharacterModels[525].Model->child->child->child->sibling->child->child->child->child->sibling->sibling->child) __asm
		{
			mov     eax, [obj]
			pop     ebp
			push    DisplayCallback_ArmR_End
			ret
		}
		else __asm
		{
			mov     eax, [obj]
			pop     ebp
			push    DisplayCallback_ArmL_Start
			ret
		}
	}

	constexpr int DisplayCallback_Root3_Start = 0x731665;
	constexpr int DisplayCallback_Root3_End = 0x73166D;
	int DisplayCallback_Root3;
	void DisplayCallback_Root3_Detour(int dummy, NJS_OBJECT* obj)
	{
		if (obj == CharacterModels[509].Model ||
			obj == CharacterModels[525].Model->child->child->child->sibling) __asm
		{
			mov     eax, [obj]
			pop     ebp
			push    DisplayCallback_Root3_End
			ret
		}
		else __asm
		{
			mov     eax, [obj]
			pop     ebp
			push    DisplayCallback_ArmR_Start
			ret
		}
	}

	constexpr int ShellDisplay_Prologue_Start = 0x732213;
	constexpr int ShellDisplay_Prologue_End = 0x73221A;
	int ShellDisplay_Prologue;
	void ShellDisplay_Prologue_Detour()
	{
		*(int*)0x1A55834 = 0x7315E0;
		JumpTo(ShellDisplay_Prologue);
	}

	constexpr int ShellDisplay_Epilogue_Start = 0x732743;
	constexpr int ShellDisplay_Epilogue_End = 0x732749;
	int ShellDisplay_Epilogue;
	void ShellDisplay_Epilogue_Detour()
	{
		*(int*)0x1A55834 = 0;
		JumpTo(ShellDisplay_Epilogue);
	}

	void InitEffects()
	{
#ifdef FIXUPS
		Effects_Punch = Repair(new Trampoline(Effects_Punch_Start, Effects_Punch_End, Effects_Punch_Detour));
		Effects_Uppercut = Repair(new Trampoline(Effects_Uppercut_Start, Effects_Uppercut_End, Effects_Uppercut_Detour));
#else
		Effects_Punch = addr(new Trampoline(Effects_Punch_Start, Effects_Punch_Start + 7, Effects_Punch_Detour));
		Effects_Uppercut = addr(new Trampoline(Effects_Uppercut_Start, Effects_Uppercut_Start + 7, Effects_Uppercut_Detour));
#endif
	}

	void InitShell()
	{
#ifdef FIXUPS
		ShellDisplay_Prologue = Repair(new Trampoline(ShellDisplay_Prologue_Start, ShellDisplay_Prologue_End, ShellDisplay_Prologue_Detour));
		ShellDisplay_Epilogue = Repair(new Trampoline(ShellDisplay_Epilogue_Start, ShellDisplay_Epilogue_End, ShellDisplay_Epilogue_Detour));
		DisplayCallback_Root3 = Repair(new Trampoline(DisplayCallback_Root3_Start, DisplayCallback_Root3_End, DisplayCallback_Root3_Detour));
		DisplayCallback_ArmR = Repair(new Trampoline(DisplayCallback_ArmR_Start, DisplayCallback_ArmR_End, DisplayCallback_ArmR_Detour));
		DisplayCallback_ArmL = Repair(new Trampoline(DisplayCallback_ArmL_Start, DisplayCallback_ArmL_End, DisplayCallback_ArmL_Detour));
#else
		ShellDisplay_Prologue = addr(new Trampoline(ShellDisplay_Prologue_Start, ShellDisplay_Prologue_Start + 7, ShellDisplay_Prologue_Detour));
		ShellDisplay_Epilogue = addr(new Trampoline(ShellDisplay_Epilogue_Start, ShellDisplay_Epilogue_Start + 6, ShellDisplay_Epilogue_Detour));
		DisplayCallback_Root3 = addr(new Trampoline(DisplayCallback_Root3_Start, DisplayCallback_Root3_Start + 7, DisplayCallback_Root3_Detour));
		DisplayCallback_ArmR = addr(new Trampoline(DisplayCallback_ArmR_Start, DisplayCallback_ArmR_Start + 7, DisplayCallback_ArmR_Detour));
		DisplayCallback_ArmL = addr(new Trampoline(DisplayCallback_ArmL_Start, DisplayCallback_ArmL_Start + 7, DisplayCallback_ArmL_Detour));
#endif
	}

	void Init(int setting)
	{
		switch (setting)
		{
			case 0:        InitEffects(); // On
			case 1: return InitShell();   // Only the shell
			case 2: return InitEffects(); // Only the effects
		}
	}

}
