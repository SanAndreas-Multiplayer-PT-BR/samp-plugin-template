#include "Hooks.h"

namespace RakNet
{
	DWORD FUNC_GetPacketID = NULL;
	subhook::Hook GetPacketID_hook;

	RakNet_Receive_t Hooks::Receive = NULL;
	RakServer* Hooks::pRakServer = NULL;

	bool Hooks::Load()
	{
#ifdef _WIN32
		FUNC_GetPacketID = FindPattern("\x8B\x44\x24\x04\x85\xC0\x75\x03\x0C\xFF\xC3", "xxxxxxx???x");
#else
		Hooks::FUNC_GetPacketID = FindPattern("\x55\xB8\x00\x00\x00\x00\x89\xE5\x8B\x55\x00\x85\xD2", "xx????xxxx?xx");
#endif

		if (FUNC_GetPacketID != NULL)
		{
			GetPacketID_hook.Install(reinterpret_cast<void*>(FUNC_GetPacketID), reinterpret_cast<void*>(GetPacketID));
			return true;
		}
		else
		{
			return false;
		}
	}

	void Hooks::AmxLoad()
	{
		static bool loaded = false;
		if(!loaded)
		{
			loaded = true;
			int(*pfn_GetRakServer)(void) = (int(*)(void))ppPluginData[PLUGIN_DATA_RAKSERVER];
			pRakServer = reinterpret_cast<RakServer*>(pfn_GetRakServer());

			int* pRakServer_VTBL = ((int*)(*(void**)pRakServer));
			Receive = reinterpret_cast<RakNet_Receive_t>(pRakServer_VTBL[RAKNET_RECEIVE_OFFSET]);

			Unlock((void*)&pRakServer_VTBL[RAKNET_RECEIVE_OFFSET], 4);
			pRakServer_VTBL[RAKNET_RECEIVE_OFFSET] = reinterpret_cast<int>(HookReceive);

		}
	}

	BYTE Hooks::GetPacketID(Packet* p)
	{
		subhook::ScopedHookRemove remove(&GetPacketID_hook);

		const BYTE packetId = (reinterpret_cast<getPacketId>(FUNC_GetPacketID))(p);

		if (packetId == 0xFF)
		{
			return 0xFF;
		}

		if (!GetPacketID_hook.GetTrampoline())
		{
			return packetId;
		}
		else
		{
			return (reinterpret_cast<getPacketId>(GetPacketID_hook.GetTrampoline()))(p);
		}
	}

}