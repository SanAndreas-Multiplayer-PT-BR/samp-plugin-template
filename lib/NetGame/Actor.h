/*
 * SA-MP NetGame Pool by LouzinDeev.
 * Big thanks to kurta999 for structs.h
 */
#ifndef _NETGAME_ACTOR_H_
#define _NETGAME_ACTOR_H_
#include "defines.h"
#include "../SDK/plugin.h"
#include "../types.h"
#include "../CVector.h"
#include <map>

namespace NetGame
{
#pragma pack(push, 1)
	class CActor
	{
	public:
		BYTE pad0;				// 0
		int iSkinID;			// 1 - 5
		CVector vecSpawnPos;	// 5 - 17
		float fSpawnAngle;		// 17 - 21
		DWORD pad4;				// 21 - 25
		DWORD pad5;				// 25 - 29
		BYTE pad6;				// 29 - 30
		char animation[140];	// 30 - 170
		WORD pad7;				// 170 - 171
		float fHealth;			// 172 - 176
		DWORD pad;				// 176 - 180
		float fAngle;			// 180 - 184
		CVector vecPos;			// 184 - 196
		DWORD pad8[3];			// 196 - 208
		BYTE byteInvulnerable;	// 208 - 209
		WORD wActorID;			// 209 - 211
	};
#pragma pack(pop)
#pragma pack(push, 1)
	class CActorPool
	{
	public:
		int iActorVirtualWorld[1000];
		BOOL bValidActor[1000];
		CActor* pActor[1000];
		DWORD dwActorPoolSize;
	};
#pragma pack(pop)
}
#endif