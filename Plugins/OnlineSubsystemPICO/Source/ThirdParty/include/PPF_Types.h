// Copyright © 2022-2025 Pico Technology Co., Ltd. All Rights Reserved.

#ifndef PPF_TYPES_H
#define PPF_TYPES_H

#include "PPF_Platform_Defs.h"
#include "PPF_KeyValuePairType.h"
#include "PPF_MatchmakingCriterionImportance.h"
#include <stdint.h>
/// @file PPF_Types.h
/// @ingroup Global

#ifdef __cplusplus
extern "C" {
#endif

typedef uint64_t ppfID;
typedef uint64_t ppfRequest;
typedef uint8_t* UInt8Array;
/// @brief Represents an RequestID that can used as a default.
/// We guarantee that no valid Request ID will equal invalidRequestID
const uint64_t invalidRequestID = 0;

/// @brief Represents an invalid MessageID that can used as a default.
/// We guarantee that no valid Message ID will equal invalidMessageID
const uint64_t invalidMessageID = 0;

typedef void (*LogFunctionPtr)(const char*, const char*);
extern LogFunctionPtr DoLogging;


#ifdef __cplusplus
}
#endif

#endif //PPF_TYPES_H
