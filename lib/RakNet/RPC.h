/*
 * SA-MP Plugin RakNet interface by LouzinDeev
 * Big Thanks to Brunoo16 for the Packet List ( https://github.com/Brunoo16/samp-packet-list ).
 */
#ifndef _RAKRPC_H_
#define _RAKRPC_H_
#include "BitStream.h"
#include "Packet.h"

namespace RakNet
{
	struct RPCParameters
	{
		/// The data from the remote system
		unsigned char* input;

		/// How many bits long \a input is
		unsigned int numberOfBitsOfData;

		/// Which system called this RPC
		PlayerID sender;

		/// Which instance of RakPeer (or a derived RakServer or RakClient) got this call
		void* recipient;

		/// You can return values from RPC calls by writing them to this BitStream.
		/// This is only sent back if the RPC call originally passed a BitStream to receive the reply.
		/// If you do so and your send is reliable, it will block until you get a reply or you get disconnected from the system you are sending to, whichever is first.
		/// If your send is not reliable, it will block for triple the ping time, or until you are disconnected, or you get a reply, whichever is first.
		BitStream* replyToSender;
	};

	enum incoming_RPC
	{
		EnterVehicle = 26,
		ExitVehicle = 154,
		VehicleDamaged = 106,
		ScmEvent = 96,
		VehicleDestroyed = 136,
		SendSpawn = 52,
		ChatMessage = 101,
		InteriorChangeNotification = 118,
		DeathNotification = 53,
		SendCommand = 50,
		ClickPlayer = 23,
		DialogResponse = 62,
		ClientCheckResponse = 103,
		GiveTakeDamage = 115,
		GiveActorDamage = 177,
		MapMarker = 119,
		IRequestClass = 128,
		IRequestSpawn = 129,
		MenuSelect = 132,
		MenuQuit = 140,
		SelectTextDraw = 83,
		PickedUpPickup = 131,
		SelectObject = 27,
		ClientJoin = 25,
		NPCJoin = 54,
		CameraTarget = 168
	};

	enum outgoing_RPC
	{
		ShowActor = 171,
		HideActor = 172,
		ApplyActorAnimation = 173,
		ClearActorAnimation = 174,
		SetActorFacingAngle = 175,
		SetActorPos = 176,
		SetActorHealth = 178,
		SetPlayerAttachedObject = 113,
		ChatBubble = 59,
		DisableCheckpoint = 37,
		SetRaceCheckpoint = 38,
		DisableRaceCheckpoint = 39,
		SetCheckpoint = 107,
		ShowDialog = 61,
		AddGangZone = 108,
		GangZoneDestroy = 120,
		GangZoneFlash = 121,
		GangZoneStopFlash = 85,
		ShowGameText = 73,
		SetGravity = 146,
		SetMapIcon = 56,
		RemoveMapIcon = 144,
		ShowMenu = 77,
		HideMenu = 78,
		ShowPlayerNameTag = 80,
		CreateObject = 44,
		SetPlayerObjectMaterial = 84,
		AttachObjectToPlayer = 75,
		AttachCameraToObject = 81,
		EditAttachedObject = 116,
		EditObject = 117,
		EnterEditObject = 27,
		CancelEdit = 28,
		SetObjectPos = 45,
		SetObjectRotation = 46,
		DestroyObject = 47,
		MoveObject = 99,
		StopObject = 122,
		CreatePickup = 95,
		DestroyPickup = 63,
		SetPlayerFacingAngle = 19,
		ServerJoin = 137,
		ServerQuit = 138,
		InitGame = 139,
		UpdateScoresAndPings = 155,
		ClientCheck = 103,
		GameModeRestart = 40,
		ApplyPlayerAnimation = 86,
		ClearPlayerAnimation = 87,
		DeathBroadcast = 166,
		SetPlayerName = 11,
		SetPlayerPos = 12,
		SetPlayerPosFindZ = 13,
		SetPlayerSkillLevel = 34,
		SetPlayerSkin = 153,
		SetPlayerTime = 29,
		SetPlayerSpecialAction = 88,
		SetWeather = 152,
		SetWorldBounds = 17,
		SetPlayerVelocity = 90,
		TogglePlayerControllable = 15,
		TogglePlayerSpectating = 124,
		ToggleClock = 30,
		SetPlayerTeam = 69,
		PlaySound = 16,
		GivePlayerMoney = 18,
		ResetPlayerMoney = 20,
		ResetPlayerWeapons = 21,
		GivePlayerWeapon = 22,
		PlayAudioStream = 41,
		PlayCrimeReport = 112,
		StopAudioStream = 42,
		RemoveBuilding = 43,
		SetPlayerHealth = 14,
		SetPlayerArmour = 66,
		SetWeaponAmmo = 145,
		SetCameraBehind = 162,
		SetArmedWeapon = 67,
		WorldPlayerAdd = 32,
		WorldPlayerRemove = 163,
		InterpolateCamera = 82,
		CreateExplosion = 79,
		SendDeathMessage = 55,
		SendGameTimeUpdate = 60,
		SendClientMessage = 93,
		SetShopName = 33,
		SetPlayerDrunkLevel = 35,
		SetPlayerFightingStyle = 89,
		SetInterior = 156,
		SetPlayerColor = 72,
		ForceClassSelection = 74,
		ToggleWidescreen = 111,
		SetPlayerWantedLevel = 133,
		SetCameraPos = 157,
		SetCameraLookAt = 158,
		SetSpawnInfo = 68,
		ORequestClass = 128,
		ORequestSpawn = 129,
		SpectatePlayer = 126,
		SpectateVehicle = 127,
		EnableStuntBonus = 104,
		ToggleSelectTextDraw = 83,
		TextDrawSetString = 105,
		ShowTextDraw = 134,
		HideTextDraw = 135,
		PlayerEnterVehicle = 26,
		PlayerExitVehicle = 154,
		RemoveVehicleComponent = 57,
		AttachTrailerToVehicle = 148,
		DetachTrailerFromVehicle = 149,
		LinkVehicleToInterior = 65,
		PutPlayerInVehicle = 70,
		RemovePlayerFromVehicle = 71,
		UpdateVehicleDamageStatus = 106,
		IScmEvent = 96,
		SetVehicleNumberPlate = 123,
		DisableVehicleCollisions = 167,
		SetVehicleHealth = 147,
		SetVehicleVelocity = 91,
		SetVehiclePos = 159,
		SetVehicleZAngle = 160,
		SetVehicleParams = 161,
		SetVehicleParamsEx = 24,
		WorldVehicleAdd = 164,
		WorldVehicleRemove = 165,
		Create3DTextLabel = 36,
		Update3DTextLabel = 58,
		SetWorldTime = 94,
		ToggleCameraTarget = 170
	};
}

#endif