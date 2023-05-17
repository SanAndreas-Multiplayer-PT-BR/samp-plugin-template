/*
 * SA-MP NetGame Pool by LouzinDeev.
 * Big thanks to kurta999 for structs.h
 */
#ifndef _NETGAME_CNETGAME_H_
#define _NETGAME_CNETGAME_H_
#include "defines.h"
#include "../SDK/plugin.h"
#include "../types.h"
#include "../CVector.h"
#include <map>

#include "3DText.h"
#include "Actor.h"
#include "GameMode.h"
#include "GangZone.h"
#include "Menu.h"
#include "Object.h"
#include "PickUp.h"
#include "Player.h"
#include "PlayerVar.h"
#include "ScriptTimer.h"
#include "SyncData.h"
#include "TextDraw.h"
#include "Vehicle.h"

namespace NetGame
{
	class CGangZonePool;
#pragma pack(push, 1)
	class CNetGame
	{
	public:
		CGameMode* pGameModePool;			// 0
		CFilterScripts* pFilterScriptPool;		// 4
		CPlayerPool* pPlayerPool;			// 8
		CVehiclePool* pVehiclePool;			// 12
#ifndef NEW_PICKUP_SYSTEM
		CPickupPool_* pPickupPool;			// 16
#else
		CPickupPool* pPickupPool;			// 16
#endif
		CObjectPool* pObjectPool;			// 20
		CMenuPool* pMenuPool;				// 24
		CTextDrawPool* pTextDrawPool;			// 28
		C3DTextPool* p3DTextPool;			// 32
		CGangZonePool* pGangZonePool;			// 36 
		CActorPool* pActorPool;			// 40 
		int						iCurrentGameModeIndex;	// 44
		int						iCurrentGameModeRepeat;	// 48
		BOOL					bFirstGameModeLoaded;	// 52
		BOOL					unkasdasd;				// 56
		CScriptTimers* pScriptTimers;			// 60
		void* pRak;					// 64
		DWORD					dwSomethingTick;
		DWORD					dwUnk;
		DWORD					dwUnk1;
		BOOL					bLanMode;				// 
		BOOL					bShowPlayerMarkers;		// 84
		BYTE					byteShowNameTags;		// 
		BYTE					bTirePopping;			// 
		BYTE					byteAllowWeapons;		// 
		BYTE					byteStuntBonus;			// 91 - 92
		BYTE					byteDefaultCameraCollision; // 92 - 93
		BYTE					byteWeather;			// 93 - 94
		int						iGameState;				// 94 - 98
		float					fGravity;				// 98 - 102
		int						iDeathDropMoney;		// 102 - 106
		BYTE					unklofasz;				// 106 - 107
		BYTE					byteMode;				// 107 - 108
		BYTE					bLimitGlobalChatRadius;	// 108 - 109
		BYTE					bUseCJWalk;				// 109 - 110
		float					fGlobalChatRadius;		// 110 - 114
		float					fNameTagDrawDistance;	// 114 - 118
		BYTE					byteDisableEnterExits;	// 118 - 119
		BYTE					byteNameTagLOS;			// 119 - 120
		BYTE					bManulVehicleEngineAndLights; // 120 - 121
		BYTE					bLimitPlayerMarkers;	// 121 - 122
		float					fPlayerMarkesLimit;		// 122 - 126 
		BOOL					bVehicleFriendlyFire;	// 126 - 130
#ifndef _WIN32
		double					dElapsedTime;			// size = 8
#endif
		int						iSpawnsAvailable;		// 130 - 134
		CPlayerSpawnInfo		AvailableSpawns[300];	// 129 - 13929
	};
#pragma pack(pop)
}

#endif