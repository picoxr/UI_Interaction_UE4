//  Copyright © 2015-2022 Pico Technology Co., Ltd. All Rights Reserved.

/** \file pxr_audio_spatializer_types.h
 * This header contains data structure definition inorder to use Pico Spatial Audio Renderer.
 */

#ifndef PXR_AUDIO_SPATIALIZER_TYPES_H
#define PXR_AUDIO_SPATIALIZER_TYPES_H

#include <stdbool.h>
#include <stdint.h>

#ifndef PXR_AUDIO_SPATIALIZER_EXPORT
#if defined(_MSC_VER)
#define PXR_AUDIO_SPATIALIZER_EXPORT __declspec(dllexport)
#elif defined(__clang__) || defined(__GNUC__)
#define PXR_AUDIO_SPATIALIZER_EXPORT __attribute__((visibility("default")))
#else
#define PXR_AUDIO_SPATIALIZER_EXPORT
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

struct PxrAudioSpatializer_Context;

/** The struct of a spatial audio rendering context, which holds all data for our renderer to run. */
typedef struct PxrAudioSpatializer_Context PxrAudioSpatializer_Context;

/** The callback function definition for external source distance attenuation methods.
 * @param Parameter 1: Source-listener distance
 * @param Parameter 2: Min attenuation distance
 * @param Parameter 3: Max attenuation distance
 * @return Attenuation gain
 * */
typedef float (*DistanceAttenuationCallback)(float, float, float);

/*! \enum PxrAudioSpatializer_Result
 *   Runtime result of API calls.
 */
typedef enum {
    PASP_ERROR = -1,
    PASP_SUCCESS = 0,
    PASP_SOURCE_NOT_FOUND = -1001,
    PASP_SOURCE_DATA_NOT_FOUND = -1002,
    PASP_SCENE_NOT_FOUND = -1003,
    PASP_SCENE_MESH_NOT_FOUND = -1004,
    PASP_ILLEGAL_VALUE = -1005,
    PASP_CONTEXT_NOT_CREATED = -1006,
    PASP_CONTEXT_NOT_READY = -1007,
    PASP_CONTEXT_REPEATED_INITIALIZATION = -1008,
    PASP_ENVIRONMENTAL_ACOUSTICS_DISABLED = -1009,  ///< API is disabled in current build
                                                    ///< because environmental acoustics is disabled.
    PASP_API_DISABLED = -1010,                      ///< API is disabled in current build
    PASP_SOURCE_INUSE = -1011,
} PxrAudioSpatializer_Result;

/*! \enum PxrAudioSpatializer_PlaybackMode
 *   Global playback mode. You can choose from binaural or loudspeaker array output.
 */
typedef enum {
    PASP_BINAURAL_OUT,
    PASP_LOUDSPEAKERS_OUT,
} PxrAudioSpatializer_PlaybackMode;

/*! \enum PxrAudioSpatializer_RenderingMode
 *   Global rendering quality setting.
 */
typedef enum {
    PASP_LOW_QUALITY = 0,     ///< 1st order ambisonic
    PASP_MEDIUM_QUALITY = 1,  ///< 3rd order ambisonics
    PASP_HIGH_QUALITY = 2,    ///< 5th order ambisonics
    PASP_AMBISONIC_FIRST_ORDER,
    PASP_AMBISONIC_SECOND_ORDER,
    PASP_AMBISONIC_THIRD_ORDER,
    PASP_AMBISONIC_FOURTH_ORDER,
    PASP_AMBISONIC_FIFTH_ORDER,
    PASP_AMBISONIC_SIXTH_ORDER,
    PASP_AMBISONIC_SEVENTH_ORDER,
} PxrAudioSpatializer_RenderingMode;

/*! \enum PxrAudioSpatializer_SourceMode
 *   Source-wise rendering mode. Currently, we only support SPATIALIZE and BYPASS.
 */
typedef enum {
    PASP_SOURCE_SPATIALIZE = 0,
    PASP_SOURCE_BYPASS = 1,
} PxrAudioSpatializer_SourceMode;

/*! \enum PxrAudioSpatializer_SourceAttenuationMode
 *   Source attenuation mode indicates how source volume is changed based on source-listener distance.
 */
typedef enum {
    PASP_SOURCE_ATTENUATION_MODE_NONE =
        0,  ///< Renderer doesn't attenuate source volume based on source-listener distance
    PASP_SOURCE_ATTENUATION_MODE_FIXED = 1,           ///< Same as PASP_SOURCE_ATTENUATION_MODE_NONE
    PASP_SOURCE_ATTENUATION_MODE_INVERSE_SQUARE = 2,  ///< Calculate source attenuation according to Inverse-Square Law
    PASP_SOURCE_ATTENUATION_MODE_CUSTOMIZED = 3,      ///< Calculate source attenuation using external callback function
} PxrAudioSpatializer_SourceAttenuationMode;

/*! \enum PxrAudioSpatializer_AcousticsMaterial
 *   Presets of different acoustic material, which are indicated by their names.
 */
typedef enum {
    PASP_MATERIAL_AcousticTile,
    PASP_MATERIAL_Brick,
    PASP_MATERIAL_BrickPainted,
    PASP_MATERIAL_Carpet,
    PASP_MATERIAL_CarpetHeavy,
    PASP_MATERIAL_CarpetHeavyPadded,
    PASP_MATERIAL_CeramicTile,
    PASP_MATERIAL_Concrete,
    PASP_MATERIAL_ConcreteRough,
    PASP_MATERIAL_ConcreteBlock,
    PASP_MATERIAL_ConcreteBlockPainted,
    PASP_MATERIAL_Curtain,
    PASP_MATERIAL_Foliage,
    PASP_MATERIAL_Glass,
    PASP_MATERIAL_GlassHeavy,
    PASP_MATERIAL_Grass,
    PASP_MATERIAL_Gravel,
    PASP_MATERIAL_GypsumBoard,
    PASP_MATERIAL_PlasterOnBrick,
    PASP_MATERIAL_PlasterOnConcreteBlock,
    PASP_MATERIAL_Soil,
    PASP_MATERIAL_SoundProof,
    PASP_MATERIAL_Snow,
    PASP_MATERIAL_Steel,
    PASP_MATERIAL_Water,
    PASP_MATERIAL_WoodThin,
    PASP_MATERIAL_WoodThick,
    PASP_MATERIAL_WoodFloor,
    PASP_MATERIAL_WoodOnConcrete,
    PASP_MATERIAL_Custom,
} PxrAudioSpatializer_AcousticsMaterial;

/*! \enum PxrAudioSpatializer_AmbisonicNormalizationType
 *   Ambisonic normalization method. Currently, we only support SN3D and N3D, which is indicated by enum names.
 */
typedef enum { PASP_SN3D, PASP_N3D } PxrAudioSpatializer_AmbisonicNormalizationType;

/**
 * 声源配置数据包
 *
 * 该数据类型记录了用以初始化声源所需的输入参数，并对部分参数定义了默认值。
 *
 * 其中：
 * 声源的朝向对创建非全向声源会很有帮助（但非全向声源的支持还在开发中，所以即便我们手动设置了声源朝向，目前效果不会有任何区别）
 * 声源检测球的大小会影响到环境仿真的结果。
 * 打开多普勒效应可以得到真实的声音传播延迟以及多普勒效应，但是计算速度较慢；关闭多普勒效应可以极大的提升计算速度，但是声音传播延迟会不那么真实。
 * 另外，在初始化阶段就关闭多普勒效应的声源，PxrAudioSpatializer_SetDopplerEffect API 并不会生效
 *
 * @param mode 选择创建声源的模式，目前支持 PASP_SOURCE_SPATIALIZE 和 PASP_SOURCE_BYPASS。默认为
 * PASP_SOURCE_SPATIALIZE，该声源会正常加入空间化的渲染，如果选择 bypass 模式，声源会被直接 bypass 到各声道输出。
 * @param position 指向待创建声源的位置的指针，position
 * 中应有3个浮点数，对应世界坐标系定义中XYZ。单位：米。默认位置为坐标轴原点，即 (0, 0, 0)
 * @param front 指向声源正面的方向向量的指针。默认 front 指向 Z 轴正向，即 (0, 0, 1)
 * @param up 指向声源正上方的方向向量的指针。默认 up 指向 Y 轴正向，即 (0, 1, 0)
 * @param radius 声源检测球的半径，单位：米。默认半径为 0.1 米
 * @param enable_doppler 是否打开多普勒效应模拟。默认为 false
 *
 * Source config parameter bundle
 * This data structure stores useful parameters for source initialization; some parameters are given with default value
 *
 * Please beware that:
 * The pose of Sourceis useful for simulating non-omnidirectional sources (but non-omnidirectional source simulation is
 * still under development).
 * Ray tracing detection radius affects echo density and authenticity of simulation early reflections and late reverb
 * Turning on doppler effect would give you realistic sound path delay and doppler effect, but will make source audio
 * processing slower; Turning off doppler effect would give you faster signal processing, but sound path delay wouldn't
 * sound as realistic. What's more, sources that had turned doppler off during initialization using this API would not
 * be affected by PxrAudioSpatializer_SetDopplerEffect API call.
 *
 * @param mode The spatialization mode used for source initialization, only PASP_SOURCE_SPATIALIZE and
 * PASP_SOURCE_BYPASS is supported here。Mode is defaulted to PASP_SOURCE_SPATIALIZE, which will make the source
 * spatialized; If PASP_SOURCE_BYPASS is chosen, the sound source will be bypassed to output channels
 * @param position A float[3] indicating source position, which corresponds to {X, Y, Z} (meters). Default to {0, 0, 0}
 * @param front A float[3] indicating source front direction, which defaults to Z axis positive direction, {0, 0, 1}
 * @param up  A float[3] indicating source up direction, which defaults to Y axis positive direction, {0, 1, 0}
 * @param radius Radius of ray tracing detection sphere (meter), which defaults to 0.1 meter
 * @param enable_doppler Turn on/off doppler effect for this source, which defaults to false
 *
 */
typedef struct PxrAudioSpatializer_SourceConfig {
    /// Source mode
    PxrAudioSpatializer_SourceMode mode = PASP_SOURCE_SPATIALIZE;

    /// Source pose
    float position[3] = {0.f, 0.f, 0.f};
    float front[3] = {0.f, 0.f, 1.f};
    float up[3] = {0.f, 1.f, 0.f};

    /// Directivity pattern
    float directivity_alpha = 0.0f;  ///< Weighting balance between figure of eight pattern and circular pattern for
                                     ///< source emission in range [0, 1].
                                     ///< A value of 0 results in a circular pattern.
                                     ///< A value of 0.5 results in a cardioid pattern.
                                     ///< A value of 1 results in a figure of eight pattern.
    float directivity_order = 1.0f;  ///< Order applied to computed directivity. Higher values will result in narrower
                                     ///< and sharper directivity patterns. Range [1, inf).

    /// Volumetric Source
    float radius = 0.1f;
    bool use_direct_path_spread = false;
    float direct_path_spread = 0.0f;  ///< Alternatively, we could use spread param directly.
                                      ///< This is useful when audio middleware specifies spread value by itself.

    /// Mix control
    float source_gain = 1.0f;      ///< Master gain of sound source.
    float reflection_gain = 1.0f;  ///< Reflection gain relative to default (master gain).

    /// Doppler effect
    bool enable_doppler = false;

    /// Attenuation Function
    PxrAudioSpatializer_SourceAttenuationMode attenuation_mode = PASP_SOURCE_ATTENUATION_MODE_INVERSE_SQUARE;
    DistanceAttenuationCallback direct_distance_attenuation_callback = nullptr;
    DistanceAttenuationCallback indirect_distance_attenuation_callback = nullptr;

    /// Attenuation range
    float range_min = 0.25;  ///< When distance < range_min, no attenuation.
    float range_max = 250;   ///< When distance > range_max, attenuation = AttenuationFunc(range_max).
} PxrAudioSpatializer_SourceConfig;

enum PxrAudioSpatializer_SourceProperty {
    PASP_SourceProperty_Mode = 1u,
    PASP_SourceProperty_Position = (1u << 1),     ///< float[3]
    PASP_SourceProperty_Orientation = (1u << 2),  ///< float[6]
    PASP_SourceProperty_Directivity = (1u << 3),  ///< float[2], directivity alpha and directivity order
    PASP_SourceProperty_VolumetricRadius = (1u << 4),
    PASP_SourceProperty_VolumetricSpread = (1u << 5),
    PASP_SourceProperty_SourceGain = (1u << 6),
    PASP_SourceProperty_ReflectionGain = (1u << 7),
    PASP_SourceProperty_DopplerOnOff = (1u << 8),
    PASP_SourceProperty_AttenuationMode =
        (1u << 9),  ///< Only after setting AttenuationMode will AttenuationCallback be applied
    PASP_SourceProperty_DirectAttenuationCallback = (1u << 10),
    PASP_SourceProperty_IndirectAttenuationCallback = (1u << 11),
    PASP_SourceProperty_RangeMin = (1u << 12),
    PASP_SourceProperty_RangeMax = (1u << 13),
    PASP_SourceProperty_All = ~0u,
    PASP_SourceProperty_None = 0u,
};

typedef struct PxrAudioSpatializer_AcousticMeshConfig {
    bool enabled = true;
    PxrAudioSpatializer_AcousticsMaterial material_type =
        PASP_MATERIAL_AcousticTile;  ///< Material preset; If this equal to YGG_MATERIAL_Custom, the absorption,
                                     ///< scattering, and transmission coefficients below will be used
    float absorption[4] = {1.0f, 1.0f, 1.0f, 1.0f};  ///< Absorption of 4 bands
    float scattering = 0.f;                          ///< Wide-band scattering
    float transmission = 0.f;                        ///< Wide-band transmission
    float to_world_transform[16] = {
        1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};  ///< Column-major 4x4 to-world transform matrix of this mesh, which
                                                    ///< describes the position, rotation, and scale of it's default to
                                                    ///< identity matrix, which represents a scene mesh positioned at
                                                    ///< world origin, with no rotation and no scaling what's so ever
} PxrAudioSpatializer_AcousticMeshConfig;

enum PxrAudioSpatializer_AcousticMeshProperty {
    PASP_MeshProperty_Enabled = 1u,
    PASP_MeshProperty_Material = (1u << 1),
    PASP_MeshProperty_Absorption = (1u << 2),
    PASP_MeshProperty_Scattering = (1u << 3),
    PASP_MeshProperty_Transmission = (1u << 4),
    PASP_MeshProperty_ToWorldTransform = (1u << 5),
    PASP_MeshProperty_All = ~0u,
    PASP_MeshProperty_None = 0u,
};

#ifdef __cplusplus
}
#endif

#endif  // PXR_AUDIO_SPATIALIZER_TYPES_H
