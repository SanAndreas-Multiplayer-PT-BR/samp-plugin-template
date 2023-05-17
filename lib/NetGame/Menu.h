/*
 * SA-MP NetGame Pool by LouzinDeev.
 * Big thanks to kurta999 for structs.h
 */
#ifndef _NETGAME_MENU_H_
#define _NETGAME_MENU_H_
#include "defines.h"
#include "../SDK/plugin.h"
#include "../types.h"
#include "../CVector.h"
#include <map>

namespace NetGame
{
#pragma pack(push, 1)
	struct t_MenuInteraction
	{
		BOOL	Menu;
		BOOL	Row[MAX_ITEMS];
	};
#pragma pack(pop)
#pragma pack(push, 1)
	class CMenu	// size 0xB84
	{
	public:

		BYTE	menuID;														// + 0x0000
		char	title[MAX_MENU_TEXT_SIZE];								// + 0x0001
		char	items[MAX_ITEMS][MAX_COLUMNS][MAX_MENU_TEXT_SIZE];	// + 0x0021
		char	headers[MAX_COLUMNS][MAX_MENU_TEXT_SIZE];					// + 0x0321
		BOOL	isInitiedForPlayer[MAX_PLAYERS];							// + 0x0361
		t_MenuInteraction interaction;										// + 0x0B31
		float	posX;														// + 0x0B71
		float	posY;														// + 0x0B75
		float	column1Width;												// + 0x0B79
		float	column2Width;												// + 0x0B7D
		BYTE	columnsNumber;												// + 0x0B81
		BYTE	itemsCount[MAX_COLUMNS];									// + 0x0B82

	};
#pragma pack(pop)
#pragma pack(push, 1)
	class CMenuPool
	{
	public:
		CMenu* menu[MAX_MENUS];			//	+ 0x0000
		BOOL		isCreated[MAX_MENUS];		//	+ 0x0200
		BOOL		playerMenu[MAX_PLAYERS];	//	+ 0x0400
	};
#pragma pack(pop)
}
#endif