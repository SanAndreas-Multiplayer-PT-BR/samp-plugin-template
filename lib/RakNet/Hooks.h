/*
 * SA-MP Plugin RakNet interface by LouzinDeev
 * Big Thanks to Brunoo16 for the Packet List ( https://github.com/Brunoo16/samp-packet-list ).
 */
#ifndef _RAK_HOOKS_H_
#define _RAK_HOOKS_H_
#include "../SDK/plugin.h"
#include "../types.h"
#include "../subhook/subhook.h"

#include "Addresses.h"
#include "Packet.h"
#include "RakServer.h"
#include "RPC.h"
#include "BitStream.h"
#include "../utils.h"

namespace RakNet
{
	typedef Packet* (__thiscall* RakNet_Receive_t)(void* ppRakServer);
	typedef BYTE(*getPacketId)(Packet* p);

	extern DWORD FUNC_GetPacketID;
	extern subhook::Hook GetPacketID_hook;

	class Hooks
	{
	public:
		static RakServer* pRakServer;
		static RakNet_Receive_t Receive;
		static BYTE GetPacketID(Packet* p);
		static bool Load();
		static void AmxLoad();
	};
}


#endif