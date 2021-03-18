#include "SA2ModLoader.h"
#include "utils.h"

namespace DreamcastMusic
{
	void Init(int setting)
	{
		if (setting != 0) return;

		WriteString(0x1314018, MusicList[57]); // chao_hall.adx -> chao_l_m.adx
		WriteString(0x1313798, MusicList[70]); // chao_l_m.adx  -> c_btl_cv.adx
		WriteString(0x1313908, MusicList[63]); // c_btl_cv.adx  -> CHAO_R_E.ADX
		WriteString(0x1314168, MusicList[47]); // chao_r_e.ADX  -> chao_k_m2.adx
		WriteString(0x11BF624, MusicList[47]); // chao_r_e.ADX  -> chao_k_m2.adx
		WriteString(0x11BF634, MusicList[47]); // chao_r_e.ADX  -> chao_k_m2.adx

		char* sa1_chao_hall = MusicList[45];
		MusicList[45] = MusicList[57];         // chao_hall.adx -> chao_l_m.adx
		MusicList[57] = MusicList[70];         // chao_l_m.adx  -> c_btl_cv.adx
		MusicList[70] = MusicList[63];         // c_btl_cv.adx  -> CHAO_R_E.ADX
		MusicList[63] = MusicList[47];         // CHAO_R_E.ADX  -> chao_k_m2.adx
		MusicList[47] = sa1_chao_hall;         // chao_k_m2.adx -> chao_hall.adx
	}

}
