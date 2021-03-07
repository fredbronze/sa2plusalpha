#include "SA2ModLoader.h"

void TikalRadarDisplay()
{
	if (MainCharObj2[0]->CharID2 != Characters_Tikal) __asm
	{
		fstp    st
		lea	    ecx, [esi + 10h]
	}
	else __asm
	{
		fstp    st
		lea	    ecx, [esi + 4]
	}
}

void TikalRadarSound()
{
	if ((FrameCountIngame & 0x3F) == 0 && MainCharObj2[0]->CharID2 != Characters_Tikal) __asm
	{
		fstp    st
		push    0x739DEA
		ret
	}
	else __asm
	{
		push    0x739E58
		ret
	}
}

void InitTikalRadar()
{
	WriteJump((void*)0x739DC9, TikalRadarSound);
	WriteCall((void*)0x73A7F5, TikalRadarDisplay);
}
