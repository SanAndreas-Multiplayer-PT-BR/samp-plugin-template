/*
 * SA-MP NetGame Pool by LouzinDeev.
 * Big thanks to kurta999 for structs.h
 */
#ifndef _NETGAME_PICKUP_H_
#define _NETGAME_PICKUP_H_
#include "defines.h"
#include "../SDK/plugin.h"
#include "../types.h"
#include "../CVector.h"
#include <map>

namespace NetGame
{
#pragma pack(push, 1)
	typedef struct Pickup_t // size 0x14
	{
		int	iModel;
		int	iType;
		CVector		vecPos;
	} tPickup;
#pragma pack(pop)
#pragma pack(push, 1)
	class CPickupPool_
	{
	public:
		tPickup	m_Pickup[MAX_PICKUPS];			// + 0x0000
		BOOL	m_bActive[MAX_PICKUPS];			// + 0xA000
		int		m_iWorld[MAX_PICKUPS];		// + 0xC000
		int		m_iPickupCount;
	};
#pragma pack(pop)
}
#endif