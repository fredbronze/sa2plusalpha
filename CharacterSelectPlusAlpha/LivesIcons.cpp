#include "SA2ModLoader.h"
#include "utils.h"

namespace LivesIcons
{
	const char* objtex_common_2p = "objtex_common_2p";
	constexpr int num_zanki = 8;

	signed int __fastcall LoadTextureList_Detour(char* filename, NJS_TEXLIST* texlist)
	{
		if (AltCharacter[0] && filename == objtex_common)
			filename = (char*)objtex_common_2p;

		return LoadTextureList(filename, texlist);
	}

	void Init(int setting, const HelperFunctions& helperFunctions)
	{
		if (setting != 0) return;

		const std::string zanki[num_zanki] =
		{
			std::string(zanki_amy),
			std::string(zanki_metal),
			std::string(zanki_chao),
			std::string(zanki_dchao),
			std::string(zanki_tical),
			std::string(zanki_chaos0),
			std::string(zanki_big0),
			std::string(zanki_big1)
		};

		for (int i = 0; i < num_zanki; i++)
		{
			auto src  = "resource\\gd_PC\\PRS\\" + zanki[i] + ".pak";
			auto dest = "resource\\gd_PC\\PRS\\" + zanki[i] + "_3x.pak";
			helperFunctions.ReplaceFile(src.c_str(), dest.c_str());
		}

		WriteCall((void*)0x44C7C9, LoadTextureList_Detour);
	}
}
