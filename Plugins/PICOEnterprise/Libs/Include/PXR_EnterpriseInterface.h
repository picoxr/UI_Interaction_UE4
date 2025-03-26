// Copyright® 2015-2023 PICO Technology Co., Ltd. All rights reserved.
// This plugin incorporates portions of the Unreal® Engine. Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere.
// Unreal® Engine, Copyright 1998 – 2023, Epic Games, Inc. All rights reserved. 

#include <stdint.h>
#include "PXR_EnterpriseTypes.h"

#ifndef QUEUETEST_CLIENT_INTERFACES_H
#define QUEUETEST_CLIENT_INTERFACES_H
#if defined(__cplusplus)
extern "C" {
#endif
    /**
     * get current head tracking confidence
     * @return 0---bad 1---good
     */
    PVRP_EXPORT int getHeadTrackingConfidence();
    /**
     * Open RGB camera
     * @return 0---success other---failed
     */
    PVRP_EXPORT int openVSTCamera();
    /**
     * Close RGB camera
     * @return 0---success other---failed
     */
    PVRP_EXPORT int closeVSTCamera();
    /**
     * Acquire RGB camera frame,distorted
     * @param [out]out_frame frame info
     * @return 0---success other---failed
     */
    PVRP_EXPORT int acquireVSTCameraFrame(frame_item_ext_t &out_frame);
    /**
     * Acquire RGB camera frame,anti-distortion
     * @param [in]token token to get authentication from seethrough service
     * @param [in]width desired frame width,should be less equal than 2328
     * @param [in]height desired frame height, should be less equal than 1748
     * @param [out]frame frame info
     * @return 0---success other---failed
     */
    PVRP_EXPORT int acquireVSTCameraFrameAntiDistortion(const char* token, int32_t width, int32_t height, frame_item_ext_t &frame);
    /**
     * get camera parameters(including Intrinsics & Extrinsics)
     * @param [in]token token to get authentication from seethrough service
     * @param [out]ctx parameters including intrinsics and extrinsics
     * @return
     */
    PVRP_EXPORT int getCameraParameters(const char* token, rgb_camera_params &params);
#if defined(__cplusplus)
}; // extern "C"
#endif

#endif //QUEUETEST_CLIENT_INTERFACES_H
