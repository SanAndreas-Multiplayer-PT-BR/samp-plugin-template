/*
 * SA-MP NetGame Pool by LouzinDeev.
 * Big thanks to kurta999 for structs.h
 */
#ifndef _NETGAME_OBJECT_H_
#define _NETGAME_OBJECT_H_
#include "defines.h"
#include "../SDK/plugin.h"
#include "../types.h"
#include "../CVector.h"
#include <map>

namespace NetGame
{
#pragma pack(push, 1)
	class CAttachedObject // sizeof = 52 - 0x34
	{
	public:
		int				iModelID;
		int				iBoneiD;
		CVector         vecPos;
		CVector         vecRot;
		CVector         vecScale;
		DWORD			dwMaterialColor1;
		DWORD			dwMaterialColor2;
	};
#pragma pack(pop)
#pragma pack(push, 1)
	class CObjectMaterial // sizeof = 212
	{
	public:
		BYTE			byteUsed;				// 197 - 198
		BYTE			byteSlot;				// 198 - 199
		WORD			wModelID;				// 199 - 201
		DWORD			dwMaterialColor;		// 201 - 205
		char			szMaterialTXD[64 + 1];	// 205 - 270
		char			szMaterialTexture[64 + 1]; // 270 - 335
		BYTE			byteMaterialSize;		// 335 - 336
		char			szFont[64 + 1];			// 336 - 401
		BYTE			byteFontSize;			// 401 - 402
		BYTE			byteBold;				// 402 - 403
		DWORD			dwFontColor;			// 403 - 407
		DWORD			dwBackgroundColor;		// 407 - 411
		BYTE			byteAlignment;			// 411 - 412
	};
#pragma pack(pop)
#pragma pack(push, 1)
	class CObject // sizeof = 3700
	{
	public:
		WORD				wObjectID;			// 0 - 2
		int					iModel;				// 2 - 6
		BOOL				bActive;			// 6 - 10
		MATRIX4X4			matWorld;			// 10 - 74 - pos - Object position
		CVector				vecRot; 			// 74 - 86 - Object rotation
		MATRIX4X4			matTarget;			// 86 - 150	- 
		BYTE				bIsMoving;			// 150 - 151
		BYTE				bNoCameraCol;		// 151 - 152
		float				fMoveSpeed;			// 152 - 156
		DWORD				unk_4;				// 156 -160
		float				fDrawDistance;		// 160 - 164
		WORD				wAttachedVehicleID;	// 164 - 166
		WORD				wAttachedObjectID;	// 166 - 168
		CVector				vecAttachedOffset;	// 168 - 180
		CVector				vecAttachedRotation;// 180 - 192
		BYTE				byteSyncRot;		// 192 - 193
		DWORD				dwMaterialCount;	// 193 - 197
		CObjectMaterial		Material[16];		// 197 - 3637
		char* szMaterialText[16];// 3637 - 3653
	};
#pragma pack(pop)
#pragma pack(push, 1)
	class CObjectPool
	{
	public:
		BOOL m_bPlayerObjectSlotState[MAX_PLAYERS][MAX_OBJECTS];	// 0 
		BOOL m_bPlayersObject[MAX_OBJECTS];							// 4.000.000
		CObject* m_pPlayerObjects[MAX_PLAYERS][MAX_OBJECTS];		// 4.004.000
		BOOL m_bObjectSlotState[MAX_OBJECTS];						// 8.004.000
		CObject* m_pObjects[MAX_OBJECTS];							// 8.008.000
	};
#pragma pack(pop)
}
#endif 