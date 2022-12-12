#ifndef PPF_NETWORKING_H
#define PPF_NETWORKING_H

#include "PPF_Packet.h"
#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/// @file PPF_Functions_Networking.h
/// @ingroup Game

/// @brief Read packet from current room.
/// @return Handle to the recved packet, null if no new packet. 
/// 
/// Read the next incoming packet. Returns null when no more packets are
/// available. Returned handle points to an object representing data read from
/// the network. 
/// use helper functions from the 'PPF_Packet.h" to extract packet info.
/// Ownership of that object is transferred to the application, 
/// use ppf_Packet_Free() to release memory.
///
/// For example:
///
///   ppfPacketHandle packet;
///   while (packet = ppf_Net_ReadPacket()) {
///     ppfID sender = ppf_Packet_GetSender(packet);
///     // dispatch packet
///     ppf_Packet_Free(packet);
///   }
///
PPF_PUBLIC_FUNCTION(ppfPacketHandle) ppf_Net_ReadPacket();

/// @brief Send packet to another user in the same room
/// @param userID Target user id
/// @param length Packet length
/// @param bytes Pointer to the packet
/// @return True if the packet has been sent to the server
/// 
/// Send a sequence of bytes to another user in the same room. The length must be less than or
/// equal to the allocated length of bytes.
/// This function may returns false, if target userID is not in the room, or connection to server is lost.
PPF_PUBLIC_FUNCTION(bool) ppf_Net_SendPacket(const char* userID, size_t length, const void *bytes);

/// @brief Send packet to another user in the same room
/// @param userID Target user id
/// @param length Packet length
/// @param bytes Pointer to the packet
/// @return True if the packet has been sent to the server
/// 
/// Send a sequence of bytes to another user in the same room. The length must be less than or
/// equal to the allocated length of bytes.
/// This function may returns false, if target userID is not in the room, or connection to server is lost.
PPF_PUBLIC_FUNCTION(bool) ppf_Net_SendPacket2(const char* userID, size_t length, const void* bytes, bool reliable);

/// @brief Send packet to all users in the same room
/// @param length Packet length
/// @param bytes Pointer to the packet
/// @return True if the packet has been sent to the server
///
/// Sends a packet to all users in the same room, including self.
/// This function may returns false, if the user currently isn't in a room, or connection to server is lost.
PPF_PUBLIC_FUNCTION(bool) ppf_Net_SendPacketToCurrentRoom(size_t length, const void *bytes);

/// @brief Send packet to all users in the same room
/// @param length Packet length
/// @param bytes Pointer to the packet
/// @return True if the packet has been sent to the server 
///
/// Sends a packet to all users in the same room, including self. 
/// This function may returns false, if the user currently isn't in a room, or connection to server is lost.
PPF_PUBLIC_FUNCTION(bool) ppf_Net_SendPacketToCurrentRoom2(size_t length, const void *bytes, bool reliable);
#endif
