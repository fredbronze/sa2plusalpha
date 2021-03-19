#include "SA2ModLoader.h"
#include "utils.h"

namespace CityEscapeMusic
{
	const char* c_escap1_sd_adx = "c_escap1_sd.adx";
	const char* c_escap3_sd_adx = "c_escap3_sd.adx";

	constexpr int Start_CallSite = 0x5DD119;
	constexpr int Restart_CallSite = 0x5E2DEA;
	void Start_Detour()
	{
		PlayMusic(c_escap1_sd_adx);
	}

	void Start_Check_Detour()
	{
		if (MainCharObj2[0]->CharID2 != Characters_Sonic)
			PlayMusic(c_escap1_sd_adx);
		else
			PlayMusic(c_escap1_adx);
	}

	constexpr int Resume_CallSite = 0x5E2EC6;
	void Resume_Detour()
	{
		PlayMusic(c_escap3_sd_adx);
	}

	void Resume_Check_Detour()
	{
		if (MainCharObj2[0]->CharID2 != Characters_Sonic)
			PlayMusic(c_escap3_sd_adx);
		else
			PlayMusic(c_escap3_adx);
	}

	constexpr int Respawn_CallSite = 0x5E2E1E;
	void Respawn_Detour()
	{
		if (CheckpointFlag != 0)
			PlayMusic(c_escap1_sd_adx);
		else
			PlayMusic(c_escap3_sd_adx);
	}

	void Respawn_Check_Detour()
	{
		if (MainCharObj2[0]->CharID2 != Characters_Sonic)
			Respawn_Detour();
		else if (CheckpointFlag != 0)
			PlayMusic(c_escap1_adx);
		else
			PlayMusic(c_escap3_adx);
	}

	void Start2P_Detour()
	{
		PlaySong_Queue(c_escap1_sd_adx);
	}

	void Init1PMode()
	{
		WriteCall((void*)Start_CallSite, Start_Check_Detour);
		WriteCall((void*)Restart_CallSite, Start_Check_Detour);
		WriteCall((void*)Resume_CallSite, Resume_Check_Detour);
		WriteCall((void*)Respawn_CallSite, Respawn_Check_Detour);
	}

	void Init2PMode()
	{
		WriteCall((void*)0x5DD4D2, Start2P_Detour);
	}

	void InitAlways()
	{
		WriteCall((void*)Start_CallSite, Start_Detour);
		WriteCall((void*)Restart_CallSite, Start_Detour);
		WriteCall((void*)Resume_CallSite, Resume_Detour);
		WriteCall((void*)Respawn_CallSite, Respawn_Detour);
		Init2PMode();
		MusicList[80] = (char*)c_escap1_sd_adx;
		MusicList[82] = (char*)c_escap3_sd_adx;
	}

	void Init(int setting)
	{
		switch (setting)
		{
			case 0: return Init1PMode(); // On
			case 1:        Init1PMode(); // Also in 2P mode
			case 2: return Init2PMode(); // Only in 2P mode
			case 3: return InitAlways(); // Always
		}
	}

}
