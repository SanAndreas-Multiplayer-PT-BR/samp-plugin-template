/*
 * SA-MP NetGame Pool by LouzinDeev.
 * Big thanks to kurta999 for structs.h
 */
#ifndef _NETGAME_SCRIPTTIMER_H_
#define _NETGAME_SCRIPTTIMER_H_
#include "defines.h"
#include "../SDK/plugin.h"
#include "../types.h"
#include "../CVector.h"
#include <map>

namespace NetGame
{
#pragma pack(push, 1)
	struct ScriptTimer_s // sizeof = 0x11B (283)
	{
		char szScriptFunc[255];
		int iTotalTime;
		int iRemainingTime;
		BOOL bRepeating;
		BOOL bKilled;
		AMX* pAMX;
		int iParamCount;
		void* cellParams;
	};
#pragma pack(pop)
#pragma pack(push, 1)
	typedef std::map<DWORD, ScriptTimer_s*> DwordTimerMap;

	class CScriptTimers
	{
	public:
		DwordTimerMap m_Timers;
		DWORD m_dwTimerCount;
	};
#pragma pack(pop)
}
#endif