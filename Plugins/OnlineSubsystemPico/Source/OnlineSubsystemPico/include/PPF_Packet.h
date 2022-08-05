#ifndef PPF_PACKET_H
#define PPF_PACKET_H

#include "PPF_Platform_Defs.h"
#include "PPF_Types.h"
#include <stddef.h>

/// @file PPF_Packet.h
/// @ingroup Game

typedef struct ppfPacket *ppfPacketHandle;

PPF_PUBLIC_FUNCTION(void)          ppf_Packet_Free(const ppfPacketHandle obj);
PPF_PUBLIC_FUNCTION(const void *)  ppf_Packet_GetBytes(const ppfPacketHandle obj);
PPF_PUBLIC_FUNCTION(const char *)  ppf_Packet_GetSenderID(const ppfPacketHandle obj);
PPF_PUBLIC_FUNCTION(size_t)        ppf_Packet_GetSize(const ppfPacketHandle obj);

#endif
