#ifndef MATRIX_PPF_APPLICATIONBYMESSAGEOPTIONS_H
#define MATRIX_PPF_APPLICATIONBYMESSAGEOPTIONS_H

/// @file PPF_ApplicationByMessageOptions.h
/// @ingroup Social

typedef struct ppfApplicationByMessageOptions* ppfApplicationByMessageOptionsHandle;

PPF_PUBLIC_FUNCTION(ppfApplicationByMessageOptionsHandle) ppf_ApplicationByMessageOptions_Create();
PPF_PUBLIC_FUNCTION(void) ppf_ApplicationByMessageOptions_Destroy(ppfApplicationByMessageOptionsHandle handle);

PPF_PUBLIC_FUNCTION(void) ppf_ApplicationByMessageOptions_SetMessageData(ppfApplicationByMessageOptionsHandle handle, const char * value);


#endif //MATRIX_PPF_APPLICATIONBYMESSAGEOPTIONS_H
