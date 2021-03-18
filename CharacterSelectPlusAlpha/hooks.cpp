#include "SA2ModLoader.h"
#include "IniFile.hpp"
#include "DreamcastMusic.h"
#include "InGameDialogue.h"
#include "TikalRadar.h"

extern "C"
{
	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };

	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		const IniFile* settings = new IniFile(std::string(path) + "\\config.ini");

		DreamcastMusic::Init(settings->getInt("Presentation", "DreamcastMusic"));
		InGameDialogue::Init(settings->getInt("Presentation", "InGameDialogue"));
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
