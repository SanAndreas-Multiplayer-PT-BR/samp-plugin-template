/*
 * SA-MP NetGame Pool by LouzinDeev.
 * Big thanks to kurta999 for structs.h
 */
#ifndef _NETGAME_PLAYER_H_
#define _NETGAME_PLAYER_H_
#include "defines.h"
#include "../SDK/plugin.h"
#include "../types.h"
#include "../CVector.h"
#include <map>

#include "SyncData.h"
#include "TextDraw.h"
#include "PlayerVar.h"

namespace NetGame
{
#pragma pack(push, 1)
	class CPlayerSpawnInfo // size  46
	{
	public:
		BYTE byteTeam;				// 0 - 1
		int iSkin;					// 1 - 5
		BYTE unk;					// 5 - 6
		CVector vecPos;				// 6 - 18
		float fRotation;			// 18 - 22
		int iSpawnWeapons[3];		// 22 - 34
		int iSpawnWeaponsAmmo[3];	// 34 - 46
	};
#pragma pack(pop)
	// 10505 - camera target
#pragma pack(push, 1)
	class CPlayer
	{
	public:
		CAimSyncData			aimSyncData;			// 0 - 39
		CVehicleSyncData		vehicleSyncData;		// 39 -
		CPassengerSyncData		passengerSyncData;		//
		CSyncData				syncData;				// 126 - 194
		CUnoccupiedSyncData		unoccupiedSyncData;		// 194 - 261
		CSpectatingSyncData		spectatingSyncData;		// 261 - 279
		CTrailerSyncData		trailerSyncData;		// 279 - 333
		DWORD					dwPlayerSyncUnused;		// 333 - 337
		DWORD					dwVehicleSyncUnused;	// 337 - 341
		BYTE					byteStreamedIn[MAX_PLAYERS];				// 341 - 1341
		BYTE					byteVehicleStreamedIn[MAX_VEHICLES];		// 1341 - 3341
		BYTE					byteSomethingUnused[1000];					// 3341 - 4341
		BYTE					byte3DTextLabelStreamedIn[1024];			// 4341  - 5365
		BYTE					bPickupStreamedIn[MAX_PICKUPS];				// 5365 - 9461
		BYTE					byteActorStreamedIn[MAX_PLAYERS];			// 9461 - 10461
		DWORD					dwStreamedInPlayers;						// 10461 - 10465
		DWORD					dwStreamedInVehicles;						// 10465 - 10469
		DWORD					dwStreamedInSomethingUnused;				// 10469 - 10473
		DWORD					dwStreamedIn3DTextLabels;					// 10479 - 10477
		DWORD					dwStreamedInPickups;						// 10477 - 10481
		DWORD					dwStreamedInActors;							// 10481 - 10485
		DWORD					bHasSetVehiclePos;	// 10485 - 10489
		DWORD					dwSetVehiclePosTick;// 10489 - 10493
		CVector					vecVehicleNewPos;	// 10493 - 10505
		BOOL					bCameraTarget;		// 10505
		DWORD					bHasSpawnInfo;		// 10509
		BOOL					bUpdateKeys;		// 50513
		CVector					vecPosition;		// 10517
		float					fHealth;			// 10529 - 10533
		float					fArmour;			// 10533 - 10537
		float					fQuaternion[4];		// 10537 - 10553
		float					fAngle;				// 10553 - 10557
		CVector					vecVelocity;		// 10557 - 10569
		WORD					wUDAnalog;			// 10569
		WORD					wLRAnalog;			// 10571
		DWORD					dwKeys;				// 10573 - 10577
		DWORD					dwOldKeys;			// 10577 - 10581
		BOOL					bEditObject;		// 10581 - 10585
		BOOL					bEditAttachedObject;// 10585 - 10589
		WORD					wDialogID;			// 10589 - 10591
		CPlayerTextDraw* pTextdraw;			// 10591 - 10595
		CPlayerText3DLabels* p3DText;			// 10595 - 10599
		WORD					wPlayerId;			// 10599 - 10601
		int						iUpdateState;		// 10601 - 10605
		//DWORD					dwLastSyncTick;		// 10605 - 10609
		CAttachedObject			attachedObject[MAX_ATTACHED_OBJECTS]; // 10605 - 11125
		BOOL					attachedObjectSlot[MAX_ATTACHED_OBJECTS]; // 11125 - 11165
		BOOL					bHasAimSync;		// 11165 - 11169
		BOOL					bHasTrailerSync;	// 11169 - 11173
		BOOL					bHasUnoccupiedSync;	// 11173 - 11177
		BYTE					byteState;			// 11177 - 11178
		CVector					vecCPPos;			// 11178 - 11190
		float					fCPSize;			// 11190 - 11194
		BOOL					bIsInCP;			// 11194 - 11198
		CVector					vecRaceCPPos;		// 11198 - 11210
		CVector					vecRaceCPNextPos;	// 11210 - 11222 
		BYTE					byteRaceCPType;		// 11222 - 11223 // TODO -> replace
		float					fRaceCPSize;		// 11223 - 11227
		BOOL					bIsInRaceCP;		// 11227 - 11231
		BOOL					bIsInModShop;		// 11231 - 11235
		WORD					wSkillLevel[11];	// 11235 - 11257
		int						iLastMarkerUpdate;	// 11257 - 11261
		CPlayerSpawnInfo		spawn;				// 11261 - 11307
		BOOL					bReadyToSpawn;		// 11307 - 11311
		BYTE					byteWantedLevel;	// 11311 - 11312
		BYTE					byteFightingStyle;  // 11312 - 11313
		BYTE					byteSeatId;			// 11313 - 11314
		WORD					wVehicleId;			// 11314 - 11316
		DWORD					iNickNameColor;		// 11316 - 11320
		BOOL					bShowCheckpoint;	// 11320 - 11324
		BOOL					bShowRaceCheckpoint;// 11324 - 11328
		int						iInteriorId;		// 11328 - 11332
		WORD					wWeaponAmmo[12];	// 11332 - 11356
		PAD(pad10, 28);								// 11356 - 11384
		BYTE					byteWeaponId[12];	// 11384 - 11396
		BYTE					byteWeaponID_unknown;// 11396 - 11397
		BYTE					byteCurrentWeapon;	// 11397 - 11398
		WORD					wTargetId;			// 11398 - 11400
		WORD					wTargetActorId;		// 11400 - 11402
		DWORD					dwLastShotTick;		// 11402 - 11406
		BYTE					dwLastShotWeapon;	// 11406 - 11407
		CBulletSyncData			bulletSyncData;		// 11407 - 11447	
		BYTE					m_byteTime;			// 11447 - 11448
		float					m_fGameTime;		// 11448 - 11452
		BYTE					byteSpectateType;	// 11452 - 11453
		DWORD					wSpectateID;		// 11453 - 11457
		DWORD					dwLastStreaming;	// 11457 - 11461
		DWORD					dwNPCRecordingType;	// 11461 - 11465
		void* pRecordingFile;	// 11465 - 11469
		DWORD					dwFirstNPCWritingTime; // 11469 - 11473 
		PAD(unused, 9);								// 11473 - 11482
		CPlayerVar* pPlayerVars;		// 11482 - 11486
		// Size = 9963
	};
#pragma pack(pop)
#pragma pack(push, 1)
	class CPlayerPool // sizeof = 99520
	{
	public:
		DWORD				dwVirtualWorld[MAX_PLAYERS];			// 0 - 4000
		DWORD				dwPlayersCount;							// 4000 - 4004
		DWORD				dwlastMarkerUpdate;						// 4004 - 4008
		float				fUpdatePlayerGameTimers;				// 4008 - 4012
		DWORD				dwScore[MAX_PLAYERS];					// 4012 - 8012
		DWORD				dwMoney[MAX_PLAYERS];					// 8012 - 12012
		DWORD				dwDrunkLevel[MAX_PLAYERS];				// 12012 - 16012
		DWORD				dwLastScoreUpdate[MAX_PLAYERS];			// 16012 - 20012
		char				szSerial[MAX_PLAYERS][101];				// 20012 - 121012				
		char				szVersion[MAX_PLAYERS][29];				// 121012 - 150012
		BOOL				bIsPlayerConnectedEx[MAX_PLAYERS];		// 150012 - 154012
		CPlayer* pPlayer[MAX_PLAYERS];					// 154012 - 158012
		char				szName[MAX_PLAYERS][25];				// 158012 - 183012
		BOOL				bIsAnAdmin[MAX_PLAYERS];				// 183012 - 187012
		BOOL				bIsNPC[MAX_PLAYERS];					// 187012 - 191012
		PAD(pad0, 8004);											// 191012 - 199016
		DWORD				dwPlayerPoolSize;						// 199016 - 199020
	};
#pragma pack(pop)
}

#endif