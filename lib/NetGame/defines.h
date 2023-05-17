/*
 * SA-MP NetGame Pool by LouzinDeev.
 * Big thanks to kurta999 for structs.h
 */
#ifndef _NETGAME_DEFINES_H_
#define _NETGAME_DEFINES_H_
#include "../types.h"
#include "../CVector.h"

#define PAD(a, b) char a[b]

#define PLAYER_STATE_NONE			(0)
#define PLAYER_STATE_ONFOOT			(1)
#define PLAYER_STATE_DRIVER			(2)
#define PLAYER_STATE_PASSENGER			(3)
#define PLAYER_STATE_EXIT_VEHICLE		(4) // (used internally)
#define PLAYER_STATE_ENTER_VEHICLE_DRIVER	(5) // (used internally)
#define PLAYER_STATE_ENTER_VEHICLE_PASSENGER	(6) // (used internally)
#define PLAYER_STATE_WASTED			(7)
#define PLAYER_STATE_SPAWNED			(8)
#define PLAYER_STATE_SPECTATING			(9)

#define WEAPON_BRASSKNUCKLE		1
#define WEAPON_GOLFCLUB			2
#define WEAPON_NITESTICK		3
#define WEAPON_KNIFE			4
#define WEAPON_BAT			5
#define WEAPON_SHOVEL			6
#define WEAPON_POOLSTICK		7
#define WEAPON_KATANA			8
#define WEAPON_CHAINSAW			9
#define WEAPON_DILDO			10
#define WEAPON_DILDO2			11
#define WEAPON_VIBRATOR			12
#define WEAPON_VIBRATOR2		13
#define WEAPON_FLOWER			14
#define WEAPON_CANE			15
#define WEAPON_GRENADE			16
#define WEAPON_TEARGAS			17
#define WEAPON_MOLTOV			18
#define WEAPON_COLT45			22
#define WEAPON_SILENCED			23
#define WEAPON_DEAGLE			24
#define WEAPON_SHOTGUN			25
#define WEAPON_SAWEDOFF			26
#define WEAPON_SHOTGSPA			27
#define WEAPON_UZI			28
#define WEAPON_MP5			29
#define WEAPON_AK47			30
#define WEAPON_M4			31
#define WEAPON_TEC9			32
#define WEAPON_RIFLE			33
#define WEAPON_SNIPER			34
#define WEAPON_ROCKETLAUNCHER		35
#define WEAPON_HEATSEEKER		36
#define WEAPON_FLAMETHROWER		37
#define WEAPON_MINIGUN			38
#define WEAPON_SATCHEL			39
#define WEAPON_BOMB			40
#define WEAPON_SPRAYCAN			41
#define WEAPON_FIREEXTINGUISHER		42
#define WEAPON_CAMERA			43
#define WEAPON_NIGHTVISION              44
#define WEAPON_INFRARED			45
#define WEAPON_PARACHUTE		46
#define WEAPON_VEHICLE			49
#define WEAPON_DROWN			53
#define WEAPON_COLLISION		54

#define	MAX_ATTACHED_OBJECTS		10
#define	MAX_FILTER_SCRIPTS			16
#define AFK_ACCURACY					1500

#define CON_VARFLAG_DEBUG		1
#define CON_VARFLAG_READONLY	2
#define CON_VARFLAG_RULE		4	// Gets sent with a RULES query responce

#define MAX_PVARS               800
#define MAX_PVAR_NAME			40

#define MAX_MENU_TEXT_SIZE	32
#define MAX_ITEMS			12
#define MAX_COLUMNS			2

#define GAMESTATE_STOPPED	 0
#define GAMESTATE_RUNNING	 1
#define GAMESTATE_RESTARTING 2

namespace NetGame
{
	const int MAX_PLAYER_NAME = 24;
	const int MAX_CLIENT_MESSAGE = 144;
	const int MAX_PLAYERS = 1000;
	const int MAX_VEHICLES = 2000;
	const int MAX_ACTORS = 1000;
	const int INVALID_PLAYER_ID = 0xFFFF;
	const int INVALID_VEHICLE_ID = 0xFFFF;
	const int INVALID_ACTOR_ID = 0xFFFF;
	const int NO_TEAM = 255;
	const int MAX_OBJECTS = 1000;
	const int INVALID_OBJECT_ID = 0xFFFF;
	const int MAX_GANG_ZONES = 1024;
	const int MAX_TEXT_DRAWS = 2048;
	const int MAX_PLAYER_TEXT_DRAWS = 256;
	const int MAX_MENUS = 128;
	const int MAX_3DTEXT_GLOBAL = 1024;
	const int MAX_3DTEXT_PLAYER = 1024;
	const int MAX_PICKUPS = 4096;
	const int INVALID_MENU = 0xFF;
	const int INVALID_TEXT_DRAW = 0xFFFF;
	const int INVALID_GANG_ZONE = -1;
	const int INVALID_3DTEXT_ID = 0xFFFF;

	typedef int                 INT;
	typedef unsigned int        UINT;

	enum CON_VARTYPE { CON_VARTYPE_FLOAT, CON_VARTYPE_INT, CON_VARTYPE_BOOL, CON_VARTYPE_STRING };

	typedef void(*VARCHANGEFUNC)();

#pragma pack(push, 1)
	struct ConsoleVariable_s
	{
		CON_VARTYPE VarType;
		DWORD VarFlags;
		void* VarPtr;
		VARCHANGEFUNC VarChangeFunc;
	};
#pragma pack(pop)
#pragma pack(push, 1)
	typedef struct _MATRIX4X4
	{
		CVector right;
		DWORD  flags;
		CVector up;
		float  pad_u;
		CVector at;
		float  pad_a;
		CVector pos;
		float  pad_p;
	} MATRIX4X4, * PMATRIX4X4;
#pragma pack(pop)

	/*class CGangZonePool;

	class C3DText;
	class C3DTextPool;
	class CPlayerText3DLabels;

	class CActor;
	class CActorPool;

	class CGameMode;
	class CFilterScripts;

	class CSAMPGangZonePool;

	class CMenu;
	class CMenuPool;

	class CAttachedObject;
	class CObjectMaterial;
	class CObject;
	class CObjectPool;

	class CPickupPool_;

	class CPlayerSpawnInfo;
	class CPlayer;
	class CPlayerPool;

	class CPlayerVar;

	class CScriptTimers;

	class CAimSyncData;
	class CVehicleSyncData;
	class CPassengerSyncData;
	class CSyncData;
	class CUnoccupiedSyncData;
	class CSpectatingSyncData;
	class CTrailerSyncData;
	class CBulletSyncData;

	class CPlayerTextDraw;
	class CTextDrawPool;

	class CVehicleSpawn;
	class CVehicleModInfo;
	class CVehicleParams;
	class CVehicle;
	class CVehiclePool;*/

}

#endif