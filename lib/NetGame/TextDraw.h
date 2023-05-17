/*
 * SA-MP NetGame Pool by LouzinDeev.
 * Big thanks to kurta999 for structs.h
 */
#ifndef _NETGAME_TEXTDRAW_H_
#define _NETGAME_TEXTDRAW_H_
#include "defines.h"
#include "../SDK/plugin.h"
#include "../types.h"
#include "../CVector.h"
#include <map>

namespace NetGame
{
#pragma pack(push, 1)
	typedef struct CTextdraw
	{
		union
		{
			BYTE byteFlags;			// 25
			struct
			{
				BYTE byteBox : 1;
				BYTE byteLeft : 1;
				BYTE byteRight : 1;
				BYTE byteCenter : 1;
				BYTE byteProportional : 1;
				BYTE bytePadding : 3;
			};
		};
		float fLetterWidth;			// 1
		float fLetterHeight;		// 5
		DWORD dwLetterColor;		// 9
		float fLineWidth;			// 13
		float fLineHeight;			// 17
		DWORD dwBoxColor;			// 21
		BYTE byteShadow; // 26
		BYTE byteOutline; // 27
		DWORD dwBackgroundColor; // 31
		BYTE byteStyle; // 32
		BYTE byteSelectable; // 32
		float fX; // 33
		float fY; // 37
		WORD dwModelIndex; // 41
		CVector vecRot;
		float fZoom;
		WORD color1;
		WORD color2;
	} _CTextdraw;
#pragma pack(pop)
#pragma pack(push, 1)
	class CPlayerTextDraw
	{
	public:
		BOOL				bSlotState[MAX_PLAYER_TEXT_DRAWS];
		CTextdraw* TextDraw[MAX_PLAYER_TEXT_DRAWS];
		char* szFontText[MAX_PLAYER_TEXT_DRAWS];
		bool				bHasText[MAX_PLAYER_TEXT_DRAWS];
	};
#pragma pack(pop)
#pragma pack(push, 1)
	class CTextDrawPool
	{
	public:
		BOOL				bSlotState[MAX_TEXT_DRAWS];
		CTextdraw* TextDraw[MAX_TEXT_DRAWS];
		char* szFontText[MAX_TEXT_DRAWS];
		bool				bHasText[MAX_TEXT_DRAWS][MAX_PLAYERS];
	};
#pragma pack(pop)
}

#endif