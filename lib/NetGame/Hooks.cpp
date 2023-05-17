#include "Hooks.h"

namespace NetGame
{
	CNetGame* Hooks::pNetGame = NULL;
	void Hooks::Load()
	{
	}
	void Hooks::AmxLoad()
	{
		static bool loaded = false;
		if (!loaded) {
			loaded = true;

			auto(*pfn_GetNetGame)(void) = (int(*)(void))ppPluginData[PLUGIN_DATA_NETGAME];
			pNetGame = reinterpret_cast<CNetGame*>(pfn_GetNetGame());
		}
	}
}