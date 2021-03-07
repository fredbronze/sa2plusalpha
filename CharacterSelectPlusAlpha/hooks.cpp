#include "pch.h"
#include "SA2ModLoader.h"
#include "TikalRadar.h"
#include "IniFile.hpp"
using std::string;

extern "C"
{
	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };

	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		const IniFile* settings = new IniFile(std::string(path) + "\\config.ini");

		if (settings->getBool("Gameplay", "TikalRadar", true)) InitTikalRadar();

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
