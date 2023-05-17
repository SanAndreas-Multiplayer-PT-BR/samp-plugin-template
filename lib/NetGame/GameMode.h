/*
 * SA-MP NetGame Pool by LouzinDeev.
 * Big thanks to kurta999 for structs.h
 */
#ifndef _NETGAME_GAMEMODE_H_
#define _NETGAME_GAMEMODE_H_
#include "defines.h"
#include "../SDK/plugin.h"
#include "../types.h"
#include "../CVector.h"
#include <map>

namespace NetGame
{
#pragma pack(push, 1)
	class CGameMode
	{
	public:
		AMX m_amx;
		bool m_bInitialised;
		bool m_bSleeping;
		float m_fSleepTime;
	};
#pragma pack(pop)
#pragma pack(push, 1)
	class CFilterScripts
	{
	public:
		void* m_pFilterScripts[MAX_FILTER_SCRIPTS];
		char m_szFilterScriptName[MAX_FILTER_SCRIPTS][255];
		int m_iFilterScriptCount;
	};
#pragma pack(pop)
}

#endif