// This file is generated automatically. Please don't edit it.


#ifndef PPF_SESSIONMEDIA_H
#define PPF_SESSIONMEDIA_H

#include "PPF_Types.h"
#include "PPF_Platform_Defs.h"

#include "PPF_CaptureInfo.h"
#include "PPF_RecordInfo.h"


typedef struct ppfSessionMedia *ppfSessionMediaHandle;


PPF_PUBLIC_FUNCTION(ppfCaptureInfoHandle) ppf_SessionMedia_GetImages(const ppfSessionMediaHandle obj,size_t index);


PPF_PUBLIC_FUNCTION(size_t) ppf_SessionMedia_GetImagesSize(const ppfSessionMediaHandle obj);


PPF_PUBLIC_FUNCTION(ppfRecordInfoHandle) ppf_SessionMedia_GetVideos(const ppfSessionMediaHandle obj,size_t index);


PPF_PUBLIC_FUNCTION(size_t) ppf_SessionMedia_GetVideosSize(const ppfSessionMediaHandle obj);



#endif

