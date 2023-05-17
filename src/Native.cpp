#include "Native.h"

namespace Native
{
	// native PrintPlayerH(const playerid);
	cell PrintPlayerH(AMX* amx, cell* params)
	{
		const int playerid = static_cast<int>(params[1]);
		float health = NetGame::Hooks::pNetGame->pPlayerPool->pPlayer[playerid]->fHealth;
		logprintf("Player id: %d has %f health\n", playerid, health);
		return 1;
	}

	const AMX_NATIVE_INFO native_list[] = {
		{ "PrintPlayerH", PrintPlayerH }
	};
}
