/*
 * SA-MP NetGame Pool by LouzinDeev.
 * Big thanks to kurta999 for structs.h
 */
#ifndef _NETGAME_VEHICLE_H_
#define _NETGAME_VEHICLE_H_
#include "defines.h"
#include "../SDK/plugin.h"
#include "../types.h"
#include "../CVector.h"
#include <map>

namespace NetGame
{
#pragma pack(push, 1)
	class CVehicleSpawn // size 36
	{
	public:
		int			iModelID;
		CVector		vecPos;
		float		fRot;
		int			iColor1;
		int			iColor2;
		int			iRespawnTime;
		int			iInterior;
	};
#pragma pack(pop)
#pragma pack(push, 1)
	class CVehicleModInfo // sizeof = 26
	{
	public:
		BYTE byteModSlots[14];                // + 0x0000
		BYTE bytePaintJob;                    // + 0x000E
		int iColor1;                             // + 0x000F
		int iColor2;                             // + 0x0010
	};
#pragma pack(pop)
#pragma pack(push, 1)
	class CVehicleParams // sizeof = 16
	{
	public:
		BYTE engine;
		BYTE lights;
		BYTE alarm;
		BYTE doors;
		BYTE bonnet;
		BYTE boot;
		BYTE objective; // 6

		BYTE siren; // 7

		BYTE door_driver; // 8
		BYTE door_passenger;
		BYTE door_backleft;
		BYTE door_backright; // 11

		BYTE windows_driver; // 12
		BYTE windows_passenger;
		BYTE windows_backleft;
		BYTE windows_backright; // 15 - 16
	};
#pragma pack(pop)
#pragma pack(push, 1)
	class CVehicle
	{
	public:
		CVector			vecPosition;		// 0 - 12
		MATRIX4X4		vehMatrix;			// 12 - 76
		CVector			vecVelocity;		// 76 - 88
		CVector			vecTurnSpeed;		// 88 - 100
		WORD			wVehicleID;			// 100 - 102
		WORD			wTrailerID;			// 102 - 104
		WORD			wCabID;				// 104 - 106
		WORD			wLastDriverID;		// 106 - 108
		WORD			vehPassengers[7];	// 108 - 122
		DWORD			vehActive;			// 122 - 126
		DWORD			vehWasted;			// 126 - 130	
		CVehicleSpawn	customSpawn;		// 130 - 166
		float			fHealth;			// 166 - 170
		DWORD			vehDoorStatus;		// 170 - 174
		DWORD			vehPanelStatus;		// 174 - 178
		BYTE			vehLightStatus;		// 178 - 179
		BYTE			vehTireStatus;		// 179 - 180
		bool			bDead;				// 180 - 181
		WORD			wKillerID;			// 181 - 183
		CVehicleModInfo vehModInfo;			// 183 - 206
		char			szNumberplate[32 + 1]; // 206 - 239
		CVehicleParams	vehParamEx;			// 239 - 255
		BYTE			bDeathNotification; // 255 - 256
		BYTE			bOccupied;			// 256 - 257
		DWORD			vehOccupiedTick;	// 257 - 261
		DWORD			vehRespawnTick;		// 261 -265
	};
#pragma pack(pop)
#pragma pack(push, 1)
	class CVehiclePool
	{
	public:
		BYTE				byteVehicleModelsUsed[212];			// 0 - 212
		int					iVirtualWorld[MAX_VEHICLES];		// 212 - 8212
		BOOL				bVehicleSlotState[MAX_VEHICLES];	// 8212 - 16212
		CVehicle* pVehicle[MAX_VEHICLES];			// 16212 - 24212
		DWORD				dwVehiclePoolSize;					// 24212
	};
#pragma pack(pop)
}
#endif