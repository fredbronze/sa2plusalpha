#include "SA2ModLoader.h"
#include "utils.h"

namespace InGameDialogue
{
	constexpr int SecurityHall_Start = 0x634C8E;
	constexpr int SecurityHall_End = 0x634D55;
	int SecurityHall;
	void SecurityHall_Detour()
	{
		if (CurrentStory == 2)
			JumpTo(SecurityHall);
		else
			JumpTo(SecurityHall_End);
	}

	constexpr int KartRacing_Intro_Start = 0x61AD45;
	constexpr int KartRacing_Intro_End = 0x61AD7C;
	int KartRacing_Intro;
	void KartRacing_Intro_Detour()
	{
		if (CurrentStory != 0)
			JumpTo(KartRacing_Intro);
		else
			JumpTo(KartRacing_Intro_End);
	}

	constexpr int CannonsCore1_Range_Start = 0x63A604;
	constexpr int CannonsCore1_Range_End = 0x63A75A;
	int CannonsCore1_Range;
	void CannonsCore1_Range_Detour()
	{
		if (CurrentStory == 3)
			JumpTo(CannonsCore1_Range);
		else
			JumpTo(CannonsCore1_Range_End);
	}

	constexpr int CannonsCore2_Intro_Start = 0x5147C9;
	constexpr int CannonsCore2_Intro_End = 0x51486C;
	int CannonsCore2_Intro;
	void CannonsCore2_Intro_Detour()
	{
		if (CurrentStory == 3)
			JumpTo(CannonsCore2_Intro);
		else
			JumpTo(CannonsCore2_Intro_End);
	}

	constexpr int CannonsCore2_Range_Start = 0x515196;
	constexpr int CannonsCore2_Range_End = 0x51524D;
	int CannonsCore2_Range;
	void CannonsCore2_Range_Detour()
	{
		if (CurrentStory == 3)
			JumpTo(CannonsCore2_Range);
		else
			JumpTo(CannonsCore2_Range_End);
	}

	constexpr int CannonsCore3_Intro_Start = 0x4DB5E8;
	constexpr int CannonsCore3_Intro_End = 0x4DB67E;
	int CannonsCore3_Intro;
	void CannonsCore3_Intro_Detour()
	{
		if (CurrentStory == 3)
			JumpTo(CannonsCore3_Intro);
		else
			JumpTo(CannonsCore3_Intro_End);
	}

	constexpr int CannonsCore3_Switch_Start = 0x4DD678;
	constexpr int CannonsCore3_Switch_End = 0x4DD6DE;
	int CannonsCore3_Switch;
	void CannonsCore3_Switch_Detour()
	{
		if (CurrentStory == 3)
			JumpTo(CannonsCore3_Switch);
		else
		{
			PopBytes(4);
			JumpTo(CannonsCore3_Switch_End);
		}
	}

	constexpr int CannonsCore4_Intro_Start = 0x65EC18;
	constexpr int CannonsCore4_Intro_End = 0x65ECB8;
	int CannonsCore4_Intro;
	void CannonsCore4_Intro_Detour()
	{
		if (CurrentStory == 3)
			JumpTo(CannonsCore4_Intro);
		else
			JumpTo(CannonsCore4_Intro_End);
	}

	constexpr int CannonsCore4_Range_Start = 0x65ED8A;
	constexpr int CannonsCore4_Range_End = 0x65EE3E;
	int CannonsCore4_Range;
	void CannonsCore4_Range_Detour()
	{
		if (CurrentStory == 3)
			JumpTo(CannonsCore4_Range);
		else
			JumpTo(CannonsCore4_Range_End);
	}

	constexpr int CannonsCore5_Intro_Start = 0x4CA486;
	constexpr int CannonsCore5_Intro_End = 0x4CA526;
	int CannonsCore5_Intro;
	void CannonsCore5_Intro_Detour()
	{
		if (CurrentStory == 3)
			JumpTo(CannonsCore5_Intro);
		else
			JumpTo(CannonsCore5_Intro_End);
	}

	constexpr int CannonsCore5_Range_Start = 0x4CA73A;
	constexpr int CannonsCore5_Range_End = 0x4CA7EE;
	int CannonsCore5_Range;
	void CannonsCore5_Range_Detour()
	{
		if (CurrentStory == 3)
			JumpTo(CannonsCore5_Range);
		else
			JumpTo(CannonsCore5_Range_End);
	}

	void KartRacing_Check_Detour()
	{
		if (CurrentStory != 0)
			JumpTo((int)PlayVoicePtr);
	}

	void Finalhazard_Detour()
	{
		if (CurrentStory == 3)
			JumpTo(0x6C0A90);
	}


	void Init(int setting)
	{
		if (setting != 0) return;

#ifdef FIXUPS
		SecurityHall = Repair(new Trampoline(SecurityHall_Start, SecurityHall_End, SecurityHall_Detour));
		KartRacing_Intro = Repair(new Trampoline(KartRacing_Intro_Start, KartRacing_Intro_End, KartRacing_Intro_Detour));
		CannonsCore1_Range = Repair(new Trampoline(CannonsCore1_Range_Start, CannonsCore1_Range_End, CannonsCore1_Range_Detour));
		CannonsCore2_Intro = Repair(new Trampoline(CannonsCore2_Intro_Start, CannonsCore2_Intro_End, CannonsCore2_Intro_Detour));
		CannonsCore2_Range = Repair(new Trampoline(CannonsCore2_Range_Start, CannonsCore2_Range_End, CannonsCore2_Range_Detour));
		CannonsCore3_Intro = Repair(new Trampoline(CannonsCore3_Intro_Start, CannonsCore3_Intro_End, CannonsCore3_Intro_Detour));
		CannonsCore3_Switch = Repair(new Trampoline(CannonsCore3_Switch_Start, CannonsCore3_Switch_End, CannonsCore3_Switch_Detour));
		CannonsCore4_Intro = Repair(new Trampoline(CannonsCore4_Intro_Start, CannonsCore4_Intro_End, CannonsCore4_Intro_Detour));
		CannonsCore4_Range = Repair(new Trampoline(CannonsCore4_Range_Start, CannonsCore4_Range_End, CannonsCore4_Range_Detour));
		CannonsCore5_Intro = Repair(new Trampoline(CannonsCore5_Intro_Start, CannonsCore5_Intro_End, CannonsCore5_Intro_Detour));
		CannonsCore5_Range = Repair(new Trampoline(CannonsCore5_Range_Start, CannonsCore5_Range_End, CannonsCore5_Range_Detour));
#else
		SecurityHall = addr(new Trampoline(SecurityHall_Start, SecurityHall_Start + 7, SecurityHall_Detour));
		KartRacing_Intro = addr(new Trampoline(KartRacing_Intro_Start, KartRacing_Intro_Start + 5, KartRacing_Intro_Detour));
		CannonsCore1_Range = addr(new Trampoline(CannonsCore1_Range_Start, CannonsCore1_Range_Start + 7, CannonsCore1_Range_Detour));
		CannonsCore2_Intro = addr(new Trampoline(CannonsCore2_Intro_Start, CannonsCore2_Intro_Start + 5, CannonsCore2_Intro_Detour));
		CannonsCore2_Range = addr(new Trampoline(CannonsCore2_Range_Start, CannonsCore2_Range_Start + 7, CannonsCore2_Range_Detour));
		CannonsCore3_Intro = addr(new Trampoline(CannonsCore3_Intro_Start, CannonsCore3_Intro_Start + 5, CannonsCore3_Intro_Detour));
		CannonsCore3_Switch = addr(new Trampoline(CannonsCore3_Switch_Start, CannonsCore3_Switch_Start + 5, CannonsCore3_Switch_Detour));
		CannonsCore4_Intro = addr(new Trampoline(CannonsCore4_Intro_Start, CannonsCore4_Intro_Start + 5, CannonsCore4_Intro_Detour));
		CannonsCore4_Range = addr(new Trampoline(CannonsCore4_Range_Start, CannonsCore4_Range_Start + 7, CannonsCore4_Range_Detour));
		CannonsCore5_Intro = addr(new Trampoline(CannonsCore5_Intro_Start, CannonsCore5_Intro_Start + 5, CannonsCore5_Intro_Detour));
		CannonsCore5_Range = addr(new Trampoline(CannonsCore5_Range_Start, CannonsCore5_Range_Start + 7, CannonsCore5_Range_Detour));
#endif

		WriteCall((void*)0x621B98, KartRacing_Check_Detour);
		WriteCall((void*)0x621C7C, KartRacing_Check_Detour);
		WriteCall((void*)0x499B54, Finalhazard_Detour);
		WriteCall((void*)0x49E4C9, Finalhazard_Detour);
	}

}
