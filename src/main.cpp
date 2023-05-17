#include "main.h"

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() {
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES | SUPPORTS_PROCESS_TICK;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData) {
	PluginLoad(ppData);
	if(!RakNet::Hooks::Load())
	{
		logprintf("Error: SA-MP version not supported.");
	}
	logprintf("* Plugin loaded");
	return true;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx) {
	NetGame::Hooks::AmxLoad();
	RakNet::Hooks::AmxLoad();
	return amx_Register(amx, Native::native_list, -1);
}

PLUGIN_EXPORT void PLUGIN_CALL Unload() {
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX* amx) {
	return 1;
}

RakNet::Packet* __thiscall RakNet::Hooks::HookReceive(void* ppRakServer)
{
	RakNet::Packet* packet = RakNet::Hooks::Receive((void*)RakNet::Hooks::pRakServer);
	BYTE packetID = RakNet::Hooks::GetPacketID(packet);
	if (packetID == (int)RakNet::incoming_packets::ID_ONFOOT_SYNC)
	{
		if (packet->data && packet->length >= sizeof(NetGame::CSyncData) + 1)
		{
			logprintf("Incomming!!!!");
			NetGame::CSyncData* pSyncData = reinterpret_cast<NetGame::CSyncData*>(&packet->data[1]);
			logprintf("Incomming packet ID_ONFOOT_SYNC playerid = %d, BYTE weaponid = %d, health = %d, armour = %d", packet->playerIndex, pSyncData->byteWeapon, pSyncData->byteHealth, pSyncData->byteArmour);
		}
	}
	return packet;
}

PLUGIN_EXPORT void PLUGIN_CALL ProcessTick() {
	
}