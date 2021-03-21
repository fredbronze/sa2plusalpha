#include "SA2ModLoader.h"
#include "utils.h"

namespace AltUpgrades
{
	void TikalDrown_Detour()
	{
		if (MainCharObj2[0]->CharID2 != Characters_Tikal && MainCharObj2[0]->Upgrades & Upgrades_KnucklesAirNecklace)
			JumpTo(0x45A081);
		else
			JumpTo(0x459FB4);
	}

	void Init(int setting)
	{
		if (setting != 0) return;

		WriteJump((void*)0x459FA7, TikalDrown_Detour);
	}

}
