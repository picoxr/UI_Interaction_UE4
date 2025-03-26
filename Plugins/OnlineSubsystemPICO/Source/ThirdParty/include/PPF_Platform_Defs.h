// Copyright © 2022-2025 Pico Technology Co., Ltd. All Rights Reserved.

#ifndef PPF_PLATFORM_DEFS_H
#define PPF_PLATFORM_DEFS_H

#include <stdint.h>
#include <stddef.h>
/// @file PPF_Platform_Defs.h
/// @ingroup Global

//-----------------------------------------------------------------------------------
// ***** PPF_CDECL
//
//
#if !defined(PPF_CDECL)
#if defined(_WIN32)
#define PPF_CDECL __cdecl
#else
#define PPF_CDECL
#endif
#endif
//-----------------------------------------------------------------------------------
// ***** PPF_EXTERN_C
//
/// Defined as extern "C" when built from C++ code.
//
#if !defined(PPF_EXTERN_C)
#ifdef __cplusplus
#define PPF_EXTERN_C extern "C"
#else
#define PPF_EXTERN_C
#endif
#endif

#if !defined(PPF_PUBLIC_FUNCTION)
#if defined(_WIN32)
#if defined(PPF_DLL_BUILD)
#define PPF_PUBLIC_FUNCTION(r_val) PPF_EXTERN_C __declspec(dllexport) r_val PPF_CDECL
#elif defined(PPF_STATIC_BUILD)
#define PPF_PUBLIC_FUNCTION(r_val) PPF_EXTERN_C r_val PPF_CDECL
#else
#define PPF_PUBLIC_FUNCTION(r_val) PPF_EXTERN_C __declspec(dllimport) r_val PPF_CDECL
#endif
#else // defined(_WIN32)
#define PPF_PUBLIC_FUNCTION(r_val) PPF_EXTERN_C __attribute__((visibility("default"))) r_val PPF_CDECL
//#define PPF_PUBLIC_FUNCTION(r_val) PPF_EXTERN_C r_val PPF_CDECL
#endif // defined(_WIN32)
#endif //! defined(PPF_PUBLIC_FUNCTION)

#if !defined(PPF_PRIVATE_FUNCTION)
#if defined(_WIN32)
#define PPF_PRIVATE_FUNCTION(r_val) PPF_EXTERN_C r_val PPF_CDECL
#else // defined(_WIN32)
#define PPF_PRIVATE_FUNCTION(r_val) PPF_EXTERN_C __attribute__((visibility("hidden"))) r_val PPF_CDECL
#endif // defined(_WIN32)
#endif //! defined(PPF_PRIVATE_FUNCTION)


#ifdef __GNUC__
#define attribute_deprecated __attribute__((deprecated))
#elif defined(_MSC_VER)
#define attribute_deprecated __declspec(deprecated)
#else
#define attribute_deprecated
#endif

#endif //PPF_PLATFORM_DEFS_H
