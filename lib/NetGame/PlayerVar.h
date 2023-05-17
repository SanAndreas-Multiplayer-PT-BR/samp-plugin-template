/*
 * SA-MP NetGame Pool by LouzinDeev.
 * Big thanks to kurta999 for structs.h
 */
#ifndef _NETGAME_PLAYERVAR_H_
#define _NETGAME_PLAYERVAR_H_
#include "defines.h"
#include "../SDK/plugin.h"
#include "../types.h"
#include "../CVector.h"
#include <map>

namespace NetGame
{
#pragma pack(push, 1)
	typedef struct PVAR_DATA_t
	{
		char			pVarName[MAX_PVAR_NAME + 1];
		BOOL			isReadOnly;
		int				pVarType;
		int				intValue;
		float			floatValue;
		char* stringValue;
	} PVAR_DATA;
#pragma pack(pop)
#pragma pack(push, 1)
	class CPlayerVar
	{
	public:
		PVAR_DATA       pVars[MAX_PVARS];
		BOOL			isPVarActive[MAX_PVARS];
		int				upperIndex;
	};
#pragma pack(pop)
}
#endif