#ifndef MATRIX_PPF_APPLICATIONOPTIONS_H
#define MATRIX_PPF_APPLICATIONOPTIONS_H

/// @file PPF_ApplicationOptions.h
/// @ingroup Social

typedef struct ppfApplicationOptions* ppfApplicationOptionsHandle;

PPF_PUBLIC_FUNCTION(ppfApplicationOptionsHandle) ppf_ApplicationOptions_Create();
PPF_PUBLIC_FUNCTION(void) ppf_ApplicationOptions_Destroy(ppfApplicationOptionsHandle handle);
/// A message to be passed to a launched app, which can be retrieved with
/// ppf_LaunchDetails_GetDeeplinkMessage()
PPF_PUBLIC_FUNCTION(void) ppf_ApplicationOptions_SetDeeplinkMessage(ppfApplicationOptionsHandle handle, const char * value);


#endif //MATRIX_PPF_APPLICATIONOPTIONS_H
