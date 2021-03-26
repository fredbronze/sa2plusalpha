#include "SA2ModLoader.h"
#include "utils.h"

namespace ManualDig
{
	constexpr int Dig_Start = 0x733938;
	constexpr int Dig_End = 0x733954;
	int Dig;
	void Dig_Detour()
	{
		if (Action_Held[0])
			JumpTo(Dig);
		else
			JumpTo(0x73392C);
	}

	void Init(int setting)
	{
		if (setting != 0) return;

#ifdef FIXUPS
		Dig = Repair(new Trampoline(Dig_Start, Dig_End, Dig_Detour));
#else
		Dig = addr(new Trampoline(Dig_Start, Dig_Start + 5, Dig_Detour));
#endif
	}

}
