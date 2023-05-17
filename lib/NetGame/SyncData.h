/*
 * SA-MP NetGame Pool by LouzinDeev.
 * Big thanks to kurta999 for structs.h
 */
#ifndef _NETGAME_SYNCDATA_H_
#define _NETGAME_SYNCDATA_H_
#include "defines.h"
#include "../SDK/plugin.h"
#include "../types.h"
#include "../CVector.h"
#include <map>

namespace NetGame
{
	// Big thanks to OrMisicL
#pragma pack(push, 1)
	class CAimSyncData
	{
	public:
		BYTE			byteCameraMode;			// 0
		CVector			vecFront;				// 1 - 13
		CVector			vecPosition;			// 13 - 25
		float			fZAim;					// 25 - 29
		BYTE			byteWeaponState : 6;	// 29
		BYTE			byteCameraZoom : 2;		// 29
		BYTE			unk;					// 30 - 31
		WORD			wCameraObject;			// 31 - 33
		WORD			wCameraVehicle;			// 33 - 35
		WORD			wCameraPlayer;			// 35 - 37
		WORD			wCameraActor;			// 37 - 39
		// Size = 39
	};
#pragma pack(pop)
#pragma pack(push, 1)
	class CVehicleSyncData
	{
	public:
		WORD			wVehicleId;				// 0x001F - 0x0021
		WORD			wUDAnalog;				// 0x0021 - 0x0023
		WORD			wLRAnalog;				// 0x0023 - 0x0025
		WORD			wKeys;					// 0x0025 - 0x0027
		float			fQuaternionAngle;		// 0x0027 - 0x002B
		CVector			vecQuaternion;			// 0x002B - 0x0037
		CVector			vecPosition;			// 0x0037 - 0x0043
		CVector			vecVelocity;			// 0x0043 - 0x004F
		float			fHealth;				// 0x004F - 0x0053
		BYTE			bytePlayerHealth;		// 0x0053 - 0x0054
		BYTE			bytePlayerArmour;		// 0x0054 - 0x0055
		BYTE			bytePlayerWeapon;		// 0x0055 - 0x0056
		BYTE			byteSirenState;			// 0x0056 - 0x0057
		BYTE			byteGearState;			// 0x0057 -	0x0058
		WORD			wTrailerID;				// 0x0058 - 0x005A
		union									// 
		{
			WORD			wHydraReactorAngle[2];
			float           fTrainSpeed;
		};
		// Size = 63
	};
#pragma pack(pop)
#pragma pack(push, 1)
	class CPassengerSyncData
	{
	public:
		WORD			wVehicleId;				// 0x005E - 0x0060
		BYTE			byteSeatFlags : 7;
		BYTE			byteDriveBy : 1;
		BYTE			bytePlayerWeapon;		// 0x0061 - 0x0062
		BYTE			bytePlayerHealth;		// 0x0062 - 0x0063
		BYTE			bytePlayerArmour;		// 0x0063 - 0x0064
		WORD			wUDAnalog;				// 0x0064 - 0x0066
		WORD			wLRAnalog;				// 0x0066 - 0x0068
		WORD			wKeys;					// 0x0068 - 0x006A
		CVector			vecPosition;			// 0x006A - 0x0076
		// Size = 24
	};
#pragma pack(pop)
#pragma pack(push, 1)
	class CSyncData
	{
	public:
		WORD			wUDAnalog;				// 0x0076 - 0x0078
		WORD			wLRAnalog;				// 0x0078 - 0x007A
		WORD			wKeys;					// 0x007A - 0x007C
		CVector			vecPosition;			// 0x007C - 0x0088
		float		fQuaternionAngle;
		CVector	    vecQuaternion;
		BYTE			byteHealth;				// 0x0098 - 0x0099
		BYTE			byteArmour;				// 0x0099 - 0x009A
		BYTE			byteWeapon;				// 0x009A - 0x009B
		BYTE			byteSpecialAction;		// 0x009B - 0x009C
		CVector			vecVelocity;			// 0x009C - 0x00A8
		CVector			vecSurfing;				// 0x00A8 - 0x00B4
		WORD			wSurfingInfo;			// 0x00B4 - 0x00B6
		union
		{
			DWORD		dwAnimationData;		// 0x00B6 - 0x00BA
			struct
			{
				WORD	wAnimIndex;
				WORD	wAnimFlags;
			};
		};
		// Size = 68
	};
#pragma pack(pop)
#pragma pack(push, 1)
	class CUnoccupiedSyncData // size 0x43
	{
	public:
		WORD wVehicleID;				// + 0x0000
		BYTE bytePassengerSlot;			// + 0x0002
		CVector vecRool;				// + 0x0003
		CVector vecDirection;			// + 0x000F
		CVector vecPosition;			// + 0x001B
		CVector vecVelocity;			// + 0x0027
		CVector vecTurnVelocity;		// + 0x0033
		float fHealth;					// + 0x003F
	};
#pragma pack(pop)
#pragma pack(push, 1)
	class CSpectatingSyncData		// size 0x12
	{
	public:
		WORD		wLeftRightKeysOnSpectating;				// + 0x0000
		WORD		wUpDownKeysOnSpectating;				// + 0x0002
		WORD		wKeysOnSpectating;						// + 0x0004
		CVector		vecPosition;							// + 0x0006
	};
#pragma pack(pop)
#pragma pack(push, 1)
	class CTrailerSyncData // size 0x36 = 54
	{
	public:
		WORD wTrailerID;				// + 0x0000
		CVector	vecRoll;				// + 0x0002
		CVector vecDirection;			// + 0x000E
		CVector vecPosition;			// + 0x001A
		CVector vecVelocity;			// + 0x0026
		DWORD pad;
	};
#pragma pack(pop)
#pragma pack(push, 1)
	class CBulletSyncData // sizeof = 40
	{
	public:
		BYTE			byteHitType;
		WORD			wHitID;
		CVector			vecHitOrigin;
		CVector			vecHitTarget;
		CVector			vecCenterOfHit;
		BYTE			byteWeaponID;
	};
#pragma pack(pop)
}
#endif