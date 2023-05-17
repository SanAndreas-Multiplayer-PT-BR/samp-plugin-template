/*
 * SA-MP Plugin RakNet interface by LouzinDeev
 * Big Thanks to Brunoo16 for the Packet List ( https://github.com/Brunoo16/samp-packet-list ).
 */

#ifndef _RAKPACKET_H_
#define _RAKPACKET_H_
#include "../types.h"

namespace RakNet
{

	enum class incoming_packets
	{
		ID_DRIVER_SYNC = 200,
		ID_RCON_COMMAND = 201,
		ID_AIM_SYNC = 203,
		ID_WEAPONS_UPDATE = 204,
		ID_STATS_UPDATE = 205,
		ID_BULLET_SYNC = 206,
		ID_ONFOOT_SYNC = 207,
		ID_UNOCCUPIED_SYNC = 209,
		ID_TRAILER_SYNC = 210,
		ID_PASSENGER_SYNC = 211
	};

	enum class outgoing_packets
	{
		ID_MARKERS_SYNC = 208
	};

	
	enum PacketPriority
	{
		SYSTEM_PRIORITY,   /// \internal Used by RakNet to send above-high priority messages.
		HIGH_PRIORITY,   /// High priority messages are send before medium priority messages.
		MEDIUM_PRIORITY,   /// Medium priority messages are send before low priority messages.
		LOW_PRIORITY,   /// Low priority messages are only sent when no other messages are waiting.
		NUMBER_OF_PRIORITIES
	};

	/// These enumerations are used to describe how packets are delivered.
	/// \note  Note to self: I write this with 3 bits in the stream.  If I add more remember to change that
	enum PacketReliability
	{
		UNRELIABLE = 6,   /// Same as regular UDP, except that it will also discard duplicate datagrams.  RakNet adds (6 to 17) + 21 bits of overhead, 16 of which is used to detect duplicate packets and 6 to 17 of which is used for message length.
		UNRELIABLE_SEQUENCED,  /// Regular UDP with a sequence counter.  Out of order messages will be discarded.  This adds an additional 13 bits on top what is used for UNRELIABLE.
		RELIABLE,   /// The message is sent reliably, but not necessarily in any order.  Same overhead as UNRELIABLE.
		RELIABLE_ORDERED,   /// This message is reliable and will arrive in the order you sent it.  Messages will be delayed while waiting for out of order messages.  Same overhead as UNRELIABLE_SEQUENCED.
		RELIABLE_SEQUENCED /// This message is reliable and will arrive in the sequence you sent it.  Out or order messages will be dropped.  Same overhead as UNRELIABLE_SEQUENCED.
	};

	/// \sa NetworkIDGenerator.h
	typedef unsigned char UniqueIDType;
	typedef unsigned short PlayerIndex;
	typedef unsigned char RPCIndex;
	const int MAX_RPC_MAP_SIZE = ((RPCIndex)-1) - 1;
	const int UNDEFINED_RPC_INDEX = ((RPCIndex)-1);

	/// First byte of a network message
	typedef unsigned char MessageID;

	typedef unsigned int RakNetTime;
	typedef long long RakNetTimeNS;

	struct PlayerID
	{
		unsigned int binaryAddress;
		unsigned short port;
	};

	const PlayerID UNASSIGNED_PLAYER_ID =
	{
		0xFFFFFFFF, 0xFFFF
	};

	struct Packet
	{
		/// Server only - this is the index into the player array that this playerId maps to
		PlayerIndex playerIndex;

		/// The system that send this packet.
		PlayerID playerId;

		/// The length of the data in bytes
		/// \deprecated You should use bitSize.
		unsigned int length;

		/// The length of the data in bits
		unsigned int bitSize;

		/// The data from the sender
		unsigned char* data;

		/// @internal
		/// Indicates whether to delete the data, or to simply delete the packet.
		bool deleteData;
	};

	struct RakNetStatisticsStruct
	{
		//		Number of Messages in the send Buffer (high, medium, low priority)unsigned messageSendBuffer[NUMBER_OF_PRIORITIES];
	//		Number of messages sent (high, medium, low priority)
		unsigned messagesSent[NUMBER_OF_PRIORITIES];
		//		Number of data bits used for user messages
		unsigned messageDataBitsSent[NUMBER_OF_PRIORITIES];
		//		Number of total bits used for user messages, including headers
		unsigned messageTotalBitsSent[NUMBER_OF_PRIORITIES];
		//		Number of packets sent containing only acknowledgements
		unsigned packetsContainingOnlyAcknowlegements;
		//		Number of acknowledgements sent
		unsigned acknowlegementsSent;
		//		Number of acknowledgements waiting to be sent
		unsigned acknowlegementsPending;
		//		Number of acknowledgements bits sent
		unsigned acknowlegementBitsSent;
		//		Number of packets containing only acknowledgements and resends
		unsigned packetsContainingOnlyAcknowlegementsAndResends;
		//		Number of messages resent
		unsigned messageResends;
		//		Number of bits resent of actual data
		unsigned messageDataBitsResent;
		//		Total number of bits resent, including headers
		unsigned messagesTotalBitsResent;
		//		Number of messages waiting for ack
		unsigned messagesOnResendQueue;
		//		Number of messages not split for sending
		unsigned numberOfUnsplitMessages;
		//		Number of messages split for sending
		unsigned numberOfSplitMessages;
		//		Total number of splits done for sending
		unsigned totalSplits;
		//		Total packets sent
		unsigned packetsSent;
		//		Number of bits added by encryption
		unsigned encryptionBitsSent;
		//		total bits sent
		unsigned totalBitsSent;
		//		Number of sequenced messages arrived out of order
		unsigned sequencedMessagesOutOfOrder;
		//		Number of sequenced messages arrived in order
		unsigned sequencedMessagesInOrder;
		//		Number of ordered messages arrived out of order
		unsigned orderedMessagesOutOfOrder;
		//		Number of ordered messages arrived in order
		unsigned orderedMessagesInOrder;
		//		Packets with a good CRC received
		unsigned packetsReceived;
		//		Packets with a bad CRC received
		unsigned packetsWithBadCRCRecieved;
		//		Bits with a good CRC received
		unsigned bitsReceived;
		//		Bits with a bad CRC received
		unsigned bitsWithBadCRCReceived;
		//		Number of acknowledgement messages received for packets we are resending
		unsigned acknowlegementsReceived;
		//		Number of acknowledgement messages received for packets we are not resending
		unsigned duplicateAcknowlegementsReceived;
		//		Number of data messages (anything other than an ack) received that are valid and not duplicate
		unsigned messagesReceived;
		//		Number of data messages (anything other than an ack) received that are invalid
		unsigned invalidMessagesReceived;
		//		Number of data messages (anything other than an ack) received that are duplicate
		unsigned duplicateMessagesReceived;
		//		Number of messages waiting for reassembly
		unsigned messagesWaitingForReassembly;
		//		Number of messages in reliability output queue
		unsigned internalOutputQueueSize;
		//		Current window size
		unsigned windowSize;
		//		lossy window size
		unsigned lossySize;
		//		connection start time
		unsigned long connectionStartTime;
	};

}


#endif