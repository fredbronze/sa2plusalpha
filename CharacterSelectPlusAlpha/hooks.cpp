#include "SA2ModLoader.h"
#include "IniFile.hpp"
#include "AltFixes.h"
#include "AltUpgrades.h"
#include "ChaoMusic.h"
#include "CityEscapeMusic.h"
#include "InGameDialogue.h"
#include "ManualDig.h"
#include "TikalRadar.h"

extern "C"
{
	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };

	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		const IniFile* settings = new IniFile(std::string(path) + "\\config.ini");

		AltUpgrades::Init(settings->getInt("Gameplay", "AltUpgrades"));
		AltFixes::Init(settings->getInt("Presentation", "AltFixes"));
		ChaoMusic::Init(settings->getInt("Presentation", "ChaoMusic"));
		CityEscapeMusic::Init(settings->getInt("Presentation", "CityEscapeMusic"));
		InGameDialogue::Init(settings->getInt("Presentation", "InGameDialogue"));
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
