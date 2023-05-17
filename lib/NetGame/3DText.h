/*
 * SA-MP NetGame Pool by LouzinDeev.
 * Big thanks to kurta999 for structs.h
 */
#ifndef _NETGAME_3DTEXT_H_
#define _NETGAME_3DTEXT_H_
#include "defines.h"
#include "../SDK/plugin.h"
#include "../types.h"
#include "../CVector.h"
#include <map>

namespace NetGame
{
#pragma pack(push, 1)
	class C3DText  // size 0x21
	{
	public:
		char* text;                                     // + 0x00
		unsigned int color;                         // + 0x04
		float posX;                                     // + 0x08
		float posY;                                     // + 0x0C
		float posZ;                                     // + 0x10
		float drawDistance;                     // + 0x14
		bool useLineOfSight;            // + 0x18
		int virtualWorld;                  // + 0x19
		WORD attachedToPlayerID;    // + 0x1D
		WORD attachedToVehicleID;   // + 0x1F
	};
#pragma pack(pop)
#pragma pack(push, 1)
	class C3DTextPool
	{
	public:
		BOOL                    m_bIsCreated[MAX_3DTEXT_GLOBAL];
		C3DText					m_TextLabels[MAX_3DTEXT_GLOBAL];
	};
#pragma pack(pop)
#pragma pack(push, 1)
	class CPlayerText3DLabels // size 0x9802
	{
	public:
		C3DText				TextLabels[MAX_3DTEXT_PLAYER];	// + 0x0000
		BOOL				isCreated[MAX_3DTEXT_PLAYER];	// + 0x8400
		BYTE				unknown9800[MAX_3DTEXT_PLAYER];				// + 0x9400
		WORD				ownerID;
	};
#pragma pack(pop)
}
#endif