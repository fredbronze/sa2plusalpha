#include "SA2ModLoader.h"
#include "IniFile.hpp"
#include "AltUpgrades.h"
#include "ChaoMusic.h"
#include "ChaosFixes.h"
#include "CityEscapeMusic.h"
#include "InGameDialogue.h"
#include "LivesIcons.h"
#include "ManualDig.h"
#include "TikalRadar.h"

extern "C"
{
	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };

	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		const IniFile* settings = new IniFile(std::string(path) + "\\config.ini");

		AltUpgrades::Init(settings->getInt("Gameplay", "AltUpgrades"));
		ChaoMusic::Init(settings->getInt("Presentation", "ChaoMusic"));
		ChaosFixes::Init(settings->getInt("Presentation", "ChaosFixes"));
		CityEscapeMusic::Init(settings->getInt("Presentation", "CityEscapeMusic"));
		InGameDialogue::Init(settings->getInt("Presentation", "InGameDialogue"));
		LivesIcons::Init(settings->getInt("Presentation", "LivesIcons"), helperFunctions);
		ManualDig::Init(settings->getInt("Gameplay", "ManualDig"));
		TikalRadar::Init(settings->getInt("Gameplay", "TikalRadar"));

		delete settings;
	}

	__declspec(dllexport) void __cdecl OnFrame()
	{
		// Executed every running frame of SA2
	}

	__declspec(dllexport) void __cdecl OnInput()
	{
		// Executed before the game processes input
	}

	__declspec(dllexport) void __cdecl OnControl()
	{
		// Executed when the game processes input
	}
}
