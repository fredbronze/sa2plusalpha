#include "pch.h"
#include "SA2ModLoader.h"

extern "C"
{
	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };

	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		// Executed at startup, contains helperFunctions and the path to your mod (useful for getting the config file.)
		// This is where we override functions, replace static data, etc.
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
