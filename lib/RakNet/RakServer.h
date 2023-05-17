/*
 * SA-MP Plugin RakNet interface by LouzinDeev
 * Big Thanks to Brunoo16 for the Packet List ( https://github.com/Brunoo16/samp-packet-list ).
 */
#ifndef _RAKSERVER_H_
#define _RAKSERVER_H_
#include "Packet.h"
#include "RPC.h"
#include "BitStream.h"
#include "../types.h"
#include "../subhook/subhook.h"

namespace RakNet
{
	#ifdef _WIN32
	class RakServer
	{
	public:
		~RakServer();
		virtual void _0();
		virtual bool Start(unsigned short AllowedPlayers, unsigned int depreciated, int threadSleepTimer, unsigned short port, const char* forceHostAddress = 0) = 0; // 4
		virtual void DisableSecurity(void); // 8
		virtual void SetPassword(const char* _password);	// 12
		virtual bool HasPassword(void);	// 16
		virtual void Disconnect(unsigned int blockDuration, unsigned char orderingChannel = 0);	// 20
		virtual bool Send_ASD(const char* data, const int length, int priority, int reliability, char orderingChannel, PlayerID playerId, bool broadcast); // 24
		virtual bool Send(BitStream* parameters, int priority, int reliability, unsigned orderingChannel, PlayerID playerId, bool broadcast);	// 28
		virtual void _20(); // 
		virtual void _24();
		virtual Packet* Receive(void);
		virtual void Kick(const PlayerID playerId); // 0x2C
		virtual void DeallocatePacket(Packet* asd);
		virtual void SetAllowedPlayers(unsigned short numberAllowed); // 0x34
		virtual unsigned short GetAllowedPlayers(void) const;
		virtual unsigned short GetConnectedPlayers(void);
		virtual void GetPlayerIPFromID(const PlayerID playerId, char returnValue[22], unsigned short* port);
		virtual void PingPlayer(const PlayerID playerId);
		virtual int GetAveragePing(const PlayerID playerId);
		virtual int GetLastPing(const PlayerID playerId); // 4C
		virtual int GetLowestPing(const PlayerID playerId);
		virtual void _54();
		virtual void _58();
		virtual void _5C();
		virtual void _60();
		virtual void _64();
		virtual void _68();
		virtual void _6C();
		virtual void _70();
		virtual void RegisterAsRemoteProcedureCall(int* uniqueID, void (*functionPointer) (RPCParameters* rpcParms));	// 74
		virtual void RegisterClassMemberRPC(int* uniqueID, void* functionPointer);	// 78
		virtual void UnregisterAsRemoteProcedureCall(int* uniqueID);	// 7C
		virtual bool RPC(int* uniqueID, RakNet::BitStream* parameters, PacketPriority priority, PacketReliability reliability, unsigned orderingChannel, PlayerID playerId, bool broadcast, bool shiftTimestamp); // 80
		virtual void _84();
		virtual void _88();
		virtual void _8C();
		virtual void _90();
		virtual void _94();
		virtual void _98();
		virtual void _9C();
		virtual void _A0();
		virtual void _A4();
		virtual void _A8();
		virtual void _AC();
		virtual void _B0();
		virtual void _B4();
		virtual void _B8();
		virtual void _BC();
		virtual void _C0();
		virtual void _C4();
		virtual void _C8();
		virtual void _CC();
		virtual const char* GetLocalIP(unsigned int index);
		virtual PlayerID GetInternalID(void) const;
		virtual void PushBackPacket(Packet* packet, bool pushAtHead);
		virtual void SetRouterInterface(void* routerInterface);
		virtual void RemoveRouterInterface(void* routerInterface);
		virtual int GetIndexFromPlayerID(PlayerID playerId); // E4
		virtual PlayerID GetPlayerIDFromIndex(int index); // E8 - 232 - 236
		virtual void UNKNOWN(void); // 236 - 240
		virtual void AddToBanList(const char* IP, unsigned int milliseconds = 0); // 240 - 244
		virtual void RemoveFromBanList(const char* IP);
		virtual void ClearBanList(void);
		virtual bool IsBanned(const char* IP);
		virtual bool IsActivePlayerID(const PlayerID playerId);
		virtual void SetTimeoutTime(RakNetTime timeMS, const PlayerID target);
		virtual bool SetMTUSize(int size);
		virtual int GetMTUSize(void) const;
		virtual void AdvertiseSystem(const char* host, unsigned short remotePort, const char* data, int dataLength);
		virtual RakNetStatisticsStruct* const GetStatistics(const PlayerID playerId);
		virtual void ApplyNetworkSimulator(double maxSendBPS, unsigned short minExtraPing, unsigned short extraPingVariance);
	};

#else

	class RakServer
	{
	public:
		~RakServer();
		virtual bool _0();
		virtual void _4();
		virtual bool Start(unsigned short AllowedPlayers, unsigned int depreciated, int threadSleepTimer, unsigned short port, const char* forceHostAddress = 0) = 0;
		virtual void _C();
		virtual void _10();
		virtual void _14();
		virtual void _18();
		virtual void _1C();
		virtual void _20();
		virtual bool Send(RakNet::BitStream* parameters, int priority, int reliability, unsigned orderingChannel, PlayerID playerId, bool broadcast);
		virtual void _28();
		virtual void _2C();
		virtual void _30();
		virtual void _34();
		virtual void SetAllowedPlayers(unsigned short numberAllowed);
		virtual void _3C();
		virtual void _40();
		virtual void _44();
		virtual void _48();
		virtual void _4C();
		virtual int GetLastPing(const PlayerID playerId); // 0x50
		virtual void _54();
		virtual void _58();
		virtual void _5C();
		virtual const char* GetLocalIP(unsigned int index);
		virtual PlayerID GetInternalID(void) const;
		virtual void PushBackPacket(Packet* packet, bool pushAtHead);
		virtual void SetRouterInterface(void* routerInterface);
		virtual void RemoveRouterInterface(void* routerInterface);
		virtual void UnregisterAsRemoteProcedureCall_BAD(int* uniqueID);
		virtual void RegisterAsRemoteProcedureCall(int* uniqueID, void (*functionPointer) (RPCParameters* rpcParms)); // 120
		virtual void RegisterClassMemberRPC(int* uniqueID, void* functionPointer); // 124
		virtual void UnregisterAsRemoteProcedureCall(int* uniqueID); // 128
		virtual void UnregisterAsRemoteProcedureCall_4(int* uniqueID);
		virtual void UnregisterAsRemoteProcedureCall_5(int* uniqueID);
		virtual bool RPC(int* uniqueID, RakNet::BitStream* parameters, int priority, int reliability, unsigned orderingChannel, PlayerID playerId, bool broadcast, bool shiftTimestamp);
		virtual void _90();
		virtual void _94();
		virtual void _98();
		virtual void _9C();
		virtual void _A0();
		virtual void _A4();
		virtual void _A8();
		virtual void _AC();
		virtual void _B0();
		virtual void _B4();
		virtual void _B8();
		virtual void _BC();
		virtual void _C0();
		virtual void _C4();
		virtual void _C8();
		virtual void _CC();
		virtual void _D0();
		virtual void _D4();
		virtual void _D8();
		virtual void _DC();
		virtual void _E0();
		virtual void _E8();
		virtual int GetIndexFromPlayerID(PlayerID playerId); // EC
		virtual PlayerID GetPlayerIDFromIndex(int index); // F0
		virtual void AddToBanList(const char* IP, unsigned int milliseconds = 0);
		virtual void RemoveFromBanList(const char* IP);
		virtual void ClearBanList(void);
		virtual bool IsBanned(const char* IP);
		virtual bool IsActivePlayerID(const PlayerID playerId);
		virtual void SetTimeoutTime(RakNetTime timeMS, const PlayerID target);
		virtual bool SetMTUSize(int size);
		virtual int GetMTUSize(void) const;
		virtual void AdvertiseSystem(const char* host, unsigned short remotePort, const char* data, int dataLength);
		virtual RakNetStatisticsStruct* const GetStatistics(const PlayerID playerId);
		virtual void ApplyNetworkSimulator(double maxSendBPS, unsigned short minExtraPing, unsigned short extraPingVariance);
	};
#endif
	
}

#endif