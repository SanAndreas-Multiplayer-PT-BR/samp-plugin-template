/*
 * SA-MP NetGame Pool by LouzinDeev.
 * Big thanks to kurta999 for structs.h
 */
#ifndef _NETGAME_GANGZONE_H_
#define _NETGAME_GANGZONE_H_
#include "defines.h"
#include "../SDK/plugin.h"
#include "../types.h"
#include "../CVector.h"
#include <map>

namespace NetGame
{
#pragma pack(push, 1)
	class CSAMPGangZonePool
	{
	public:
		float			fGangZone[MAX_GANG_ZONES][4];
		BOOL			bSlotState[MAX_GANG_ZONES];
	};
#pragma pack(pop)
}
#endif