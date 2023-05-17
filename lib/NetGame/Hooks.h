/*
 * SA-MP NetGame Pool by LouzinDeev.
 * Big thanks to kurta999 for structs.h
 */
#ifndef _NETGAME_HOOKS_H_
#define _NETGAME_HOOKS_H_
#include "defines.h"
#include "../SDK/plugin.h"
#include "../types.h"
#include "../CVector.h"
#include <map>

#include "CNetGame.h"

namespace NetGame
{
	class Hooks
	{
	public:
		static CNetGame* pNetGame;
		static void Load();
		static void AmxLoad();
	};
}

#endif