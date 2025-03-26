//  Copyright © 2015-2022 Pico Technology Co., Ltd. All Rights Reserved.

/** \file pxr_audio_spatializer.h
 * Pico Spatial Audio Renderer is a realtime audio spatialization and virtual acoustics simulation engine.
 * This is the api header of the renderer.
 */

#ifndef PXR_AUDIO_SPATIALIZER_H
#define PXR_AUDIO_SPATIALIZER_H

#include <stdint.h>
#include <stdlib.h>
#include "pxr_audio_spatializer_types.h"
#include "pxr_audio_spatializer_channel_config.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 返回 Pico 空间音频渲染器 版本号
 * Returns version of Pico Spatial Audio Renderer
 *
 * @param[out] major 主版本号
 * @param[out] minor 小版本号
 * @param[out] patch 补丁号
 * @return
 */
PXR_AUDIO_SPATIALIZER_EXPORT const char* PxrAudioSpatializer_GetVersion(int* major, int* minor, int* patch);

/**
 * 创建 Pico 空间音频渲染器 context
 *
 * Pico 空间音频渲染器 所有 API 的调用都基于 context，在使用 Pico 空间音频渲染器 之初，需要调用这个函数创建 context
 * 以供调用其他 API 使用.
 *
 * @param[out] ctx 用于保存context的指针地址
 * @param mode 用于创建 context 的模式，可选
 * PASP_LOW_QUALITY，PASP_MEDIUM_QUALITY，PASP_HIGH_QUALITY。在基础模式下对应不同ambisonic阶数，在环境声学开启的模式下还会改变，射线数量，路径深度等其他参数
 * @param frames_per_buffer 每次输入到引擎的单通道的 buffer 长度，关于 frame 的定义可以参考
 * https://developer.mozilla.org/en-US/docs/Web/API/Web_Audio_API/Basic_concepts_behind_Web_Audio_API#audio_buffers_frames_samples_and_channels
 * @param sample_rate 输入到引擎音频的采样率
 * @return 返回执行结果
 *
 * * Create Pico Spatial Audio Renderer context
 *
 * All API calls of Pico Spatial Audio Renderer needs to be provided with a context，therefore you should create a
 * context BEFORE you make any API calls
 *
 * @param[out] ctx A pointer of context pointer. The created context address will be written to the context pointer
 * @param mode The rendering tier for your specific need, you can choose from one of the following
 * tiers:
 *       PASP_LOW_QUALITY,
 *       PASP_MEDIUM_QUALITY,
 *       PASP_HIGH_QUALITY.
 * If you build / run in free field mode, this rendering tier only affects the ambisonic order;
 * however, if you included environmental acoustics simulation, this rendering tier also changes number of rays,
 * maximum path depth, and etc.
 * @param frames_per_buffer which defines the size of each mono input buffer. More details about the concept of "audio
 * frame" can be found here:
 * https://developer.mozilla.org/en-US/docs/Web/API/Web_Audio_API/Basic_concepts_behind_Web_Audio_API#audio_buffers_frames_samples_and_channels
 * @param sample_rate The sampling rate of I/O signal to/from the engine.
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_CreateContext(PxrAudioSpatializer_Context** ctx,
                                  PxrAudioSpatializer_RenderingMode mode,
                                  size_t frames_per_buffer,
                                  size_t sample_rate);

/**
 * 初始化 Pico 空间音频渲染器 context
 *
 * 在使用 PxrAudioSpatializer_CreateContext 创建 context 后，可以进一步修改 context
 * 相关的配置参数，在调成参数完毕后，需要调用这个函数来对 context 进行初始化。
 *
 * @param ctx 要使用的 context
 * @return 返回执行结果
 *
 * Initialize Pico Spatial Audio Renderer context
 *
 * Must be called
 * 1. After creating a context using PxrAudioSpatializer_CreateContext
 * 2. Before make other calls
 * Before calling this API, you can further modify configs of the context manually after it's created;
 *
 * @param ctx context to be initialized.
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_InitializeContext(PxrAudioSpatializer_Context* ctx);

/**
 * 提交mesh到场景中
 *
 * 当使用环境声学模式时，需要向引擎提交环境信息，包括环境的 mesh 与 材质。目前仅支持三角形 mesh。
 * 如果运行基础模式（非环境声学仿真关闭），则不需要使用这个 API，（如果用了也没有效果）
 *
 * @param ctx 要使用的的 context
 * @param vertices 场景的顶点数组，以[x0 y0 z0 x1 y1 z1 ...]的形式排列
 * @param vertices_count 场景中顶点的个数
 * @param indices 场景中三角形的顶点索引数组，三个顶点下标一组，表示场景中的一个三角形
 * @param indices_count 顶点索引数组（三角形）的个数
 * @param material 指定 mesh 的材质
 * @param[out] geometry_id 返回提交的 Mesh 的 geometry_id，每个 Mesh 在场景中会有唯一对应的 geometry_id
 * @return 返回执行结果
 *
 * Submits acoustic mesh to the scene
 *
 * When using the Pico Spatial Audio Renderer with environmental acoustics simulation, you need to provide the engine
 * with scene mesh and material information. If you are using free field mode (without environmental acoustics
 * simulation), you don't need to call this API; It won't do anything.
 *
 * @param ctx Pico Spatial Audio Renderer context
 * @param vertices Vertices array of the scene, in the layout of [x0 y0 z0 x1 y1 z1 ...]
 * @param vertices_count Number of vertices in the vertices array
 * @param indices Indices array of the scene, which contains groups of 3 vertex indices that forms a triangle
 * @param indices_count Number of triangles represented by the indices array
 * @param material The acoustic material enum of this scene mesh. See definition of
 * PxrAudioSpatializer_AcousticsMaterial for all categories
 * @param[out] geometry_id Returns the geometry id of the submitted scene mesh, this is unique in current current
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_SubmitMesh(PxrAudioSpatializer_Context* ctx,
                               const float* vertices,
                               int vertices_count,
                               const int* indices,
                               int indices_count,
                               PxrAudioSpatializer_AcousticsMaterial material,
                               int* geometry_id);

/**
 * 提交mesh到场景中。与 PxrAudioSpatializer_SubmitMesh 功能相同，不过这个API可以直接输入mesh材质的吸收和散射系数
 * @param ctx 要使用的的 context
 * @param vertices 场景的顶点数组
 * @param vertices_count 场景中顶点的个数
 * @param indices 场景中三角形的顶点索引数组
 * @param indices_count 顶点索引数组（三角形）的个数
 * @param absorption_factor 材质的吸收系数
 * @param scattering_factor 材质的散射系数
 * @param geometry_id 返回提交的 Mesh 的 geometry_id，每个 Mesh 在场景中会有唯一对应的 geometry_id
 * @return 返回执行结果
 *
 * Submits acoustic mesh to the scene. This API has the same functionality as PxrAudioSpatializer_SubmitMesh, but can
 * directly input absorption and scattering factor of material
 * @param ctx Context pointer
 * @param vertices Vertices array of the scene
 * @param vertices_count Number of vertices in the vertices array
 * @param indices Indices array of the scene
 * @param indices_count Number of triangles represented by the indices array
 * @param absorption_factor Absorption factor of the material in all frequency bands
 * @param scattering_factor Scattering factor of the material
 * @param transmission_factor Transmission factor of the material
 * @param[out] geometry_id Returns the geometry id of the submitted scene mesh, this is unique in current current
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_SubmitMeshAndMaterialFactor(PxrAudioSpatializer_Context* ctx,
                                                const float* vertices,
                                                int vertices_count,
                                                const int* indices,
                                                int indices_count,
                                                const float* absorption_factor,
                                                float scattering_factor,
                                                float transmission_factor,
                                                int* geometry_id);

/**
 * 提交mesh到场景中。与 PxrAudioSpatializer_SubmitMesh 功能相同，不过这个API可以直接输入mesh的配置属性数据结构
 *
 * @param ctx 要使用的的 context
 * @param vertices 场景的顶点数组
 * @param vertices_count 场景中顶点的个数
 * @param indices 场景中三角形的顶点索引数组
 * @param indices_count 顶点索引数组（三角形）的个数
 * @param config Mesh 的属性
 * @param geometry_id 返回提交的 Mesh 的 geometry_id，每个 Mesh 在场景中会有唯一对应的 geometry_id
 * @return 返回执行结果
 *
 * Submits acoustic mesh to the scene. This API has the same functionality as PxrAudioSpatializer_SubmitMesh, but can
 * directly input property of mesh.
 *
 * @param ctx context
 * @param vertices Vertices array of the scene
 * @param vertices_count Number of vertices in the vertices array
 * @param indices Indices array of the scene
 * @param indices_count Number of triangles represented by the indices array
 * @param config Config of the mesh
 * @param[out] geometry_id Returns the geometry id of the submitted scene mesh, this is unique in current current
 * @return Error code of this API call. Returns YGG_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_SubmitMeshWithConfig(PxrAudioSpatializer_Context* ctx,
                                         const float* vertices,
                                         int vertices_count,
                                         const int* indices,
                                         int indices_count,
                                         const PxrAudioSpatializer_AcousticMeshConfig* config,
                                         int* geometry_id);

/**
 * 从场景中删除指定的场景mesh
 * @param ctx 要使用的的 context
 * @param geometry_id 要删除的 Mesh 的 geometry_id，每个 Mesh 在场景中会有唯一对应的 geometry_id
 * @return 返回执行结果
 *
 * Remove specified scene mesh from scene
 * @param ctx context
 * @param geometry_id ID of the mesh you want to remove from scene
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result PxrAudioSpatializer_RemoveMesh(PxrAudioSpatializer_Context* ctx,
                                                                                       int geometry_id);

/**
 * 从场景中 enable / disable 指定的场景mesh
 * @param ctx 要使用的的 context
 * @param geometry_id 要删除的 Mesh 的 geometry_id，每个 Mesh 在场景中会有唯一对应的 geometry_id
 * @param enable enable / disable 指定的场景mesh
 * @return 返回执行结果
 *
 * Enable / disable specified scene mesh from scene
 * @param ctx context
 * @param geometry_id ID of the mesh you want to remove from scene
 * @param enable enable / disable specified scene mesh
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_SetMeshEnable(PxrAudioSpatializer_Context* ctx, int geometry_id, bool enable);

/**
 * 设定指定场景mesh的位置、朝向，和缩放。如果想让被提交的mesh有初始的位置、朝向，以及缩放的话，请务必在提交mesh后立刻调用这个接口。
 * @param ctx 要使用的的 context
 * @param geometry_id 要修改的 Mesh 的 geometry_id，每个 Mesh 在场景中会有唯一对应的 geometry_id
 * @param config Mesh 的配置属性
 * @param property_mask 一个表示什么Mesh属性需要被修改的bit mask。只有和property_mask 按位与之后不为0的
 * PxrAudioSpatializer_AcousticMeshConfig 才会被修改
 * @return 返回执行结果
 *
 * Setup the position, rotation, and scaling of the specified mesh via a 4x4 transform matrix. If you want to
 * specify the initial transform of a submitted mesh, please call this API as soon as you finished your mesh submission
 * call.
 * @param ctx context
 * @param geometry_id ID of the mesh you want to config
 * @param config Config of the mesh
 * @param property_mask A bit mask that specify which properties of the mesh need to be changed. Only the
 * PxrAudioSpatializer_AcousticMeshConfig that yield non-zero value by bit-wise and operation with property_mask will be
 * changed.
 * @return Error code of this API call. Returns YGG_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_SetMeshConfig(PxrAudioSpatializer_Context* ctx,
                                  int geometry_id,
                                  const PxrAudioSpatializer_AcousticMeshConfig* config,
                                  unsigned int property_mask = PASP_MeshProperty_All);

/**
 * 根据输入的材质预设，输出材质的吸收参数
 * @param material 输入的材质类型
 * @param[out] absorption_factor 输出多频段吸收参数
 * @return 返回执行结果
 *
 * Get absorption coefficients of given material type
 * @param material material type name
 * @param absorption_factor float array of absorption factors of all bands.
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_GetAbsorptionFactor(PxrAudioSpatializer_AcousticsMaterial material, float* absorption_factor);

/**
 * 根据输入的材质预设，输出材质的散射率
 * @param material 输入的材质类型
 * @param[out] scattering_factor 输出散射率
 * @return 返回执行结果
 *
 * Get scattering factor of given material type
 * @param material material type name
 * @param scattering_factor scattering factor.
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_GetScatteringFactor(PxrAudioSpatializer_AcousticsMaterial material, float* scattering_factor);

/**
 * 根据输入的材质预设，输出材质的透射率
 * @param material 输入的材质类型
 * @param[out] scattering_factor 输出散射率
 * @return 返回执行结果
 *
 * Get scattering factor of given material type
 * @param material material type name
 * @param scattering_factor scattering factor.
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_GetTransmissionFactor(PxrAudioSpatializer_AcousticsMaterial material, float* transmission_factor);

/**
 * 向渲染器提交当前的场景
 *
 * 在使用 PxrAudioSpatializer_SubmitMesh 创建 Mesh 后,
 * 或者调用过PxrAudioSpatializer_InitializeContext之后，你需要使用这个方法将创建的 mesh 提交到引擎中参与计算。
 * 值得注意的是，哪怕使用基础模式，或者场景中没有 Mesh，也需要调用一下这个方法。
 *
 * @param ctx 要使用的的 context
 * @return 返回执行结果
 *
 * Commit current scene to Pico Spatial Audio Renderer engine
 *
 * After calling PxrAudioSpatializer_SubmitMesh or PxrAudioSpatializer_InitializeContext, you need to call this API to
 * include the scene into computation.
 * You should ALSO call this method even there's no acoustic mesh in the scene。
 *
 * @param ctx Context pointer
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_CommitScene(PxrAudioSpatializer_Context* ctx);

/**
 * 创建声源
 *
 * 根据声源的位置信息与行为模式创建声源，并返回 source_id
 *
 * @param ctx 要使用的的 context
 * @param source_mode 选择创建声源的模式，目前支持 PASP_SOURCE_SPATIALIZE 和 PASP_SOURCE_BYPASS。默认为
 * PASP_SOURCE_SPATIALIZE，该声源会正常加入空间化的渲染，如果选择 bypass 模式，声源会被直接 mix 到各声道输出。
 * @param position 指向待创建声源的初始位置的指针，position
 * 中应有3个浮点数，对应世界坐标系定义中XYZ（世界坐标系的定义参考 README.md）。单位：米。
 * @param[out] source_id 返回创建成功的声源的 source_id。每个声源都会对应全局唯一的 source_id。
 * @param is_async (默认值为false) 是否以非同步的方法添加声源，这个选项实质上是一个trade-off：\n
 * 1.
 * 非同步添加声源：不会阻塞调用这个函数的线程，但是在你使用这个source前，你需要去主动询问声源是否被创建完成了。一个例外是
 * PxrAudioSpatializer_SubmitSourceBuffer函数，你可以在任何时候调用它。 \n
 * 2.
 * 同步添加声源（默认）：确保了在这个函数被调用之后，source一定已经初始化完成了；但是函数耗时会更多。在大量声源被一起添加进场景时，可能会短暂阻塞
 * 你的调用线程，造成卡顿。
 * @return 返回执行结果
 *
 * Create sound source
 *
 * Create a virtual sound source, and set it up with specified source mode and position in scene. Returns source id.
 *
 * @param ctx Context pointer
 * @param source_mode Source rendering mode, which currently includes PASP_SOURCE_SPATIALIZE(default) and
 * PASP_SOURCE_BYPASS. PASP_SOURCE_SPATIALIZE will let this sound source be spatialized, while PASP_SOURCE_BYPASS will
 * directly mix input signal to output channels
 * @param position Source world position, which is a 3-element float array [x, y, z] follows the convention defined in
 * README.md. Unit is meter
 * @param[out] source_id Returns unique source id.
 * @param is_async (Default to be false) Determine if source is added asynchronously into the scene. This choice is
 * essentially a trade-off:
 * 1. Async source addition won't block the thread that's calling it, but you would need to manually check if source
 * initialization is finished before using this source. The exception of this is PxrAudioSpatializer_SubmitSourceBuffer,
 * which can be called anytime; \n
 * 2. Synchronous source addition (Default) ensures that source is definitely initialized right after the source
 * addition call, but it would take longer to finish, and when lot's of sources was added at the same time, it might
 * block your calling thread for too long.
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_AddSource(PxrAudioSpatializer_Context* ctx,
                              PxrAudioSpatializer_SourceMode source_mode,
                              const float* position,
                              int* source_id,
                              bool is_async = false);

/**
 * 创建声源
 *
 * 根据声源的位置信息与行为模式创建声源，并返回 source_id。
 * 这个方法与 PxrAudioSpatializer_AddSource
 * 的区别是，这个方法可以指定声源的朝向与声源检测球的大小。
 * 声源的朝向对创建非全向声源会很有帮助（但非全向声源的支持还在开发中，所以即便我们手动设置了声源朝向，目前效果不会有任何区别）
 * 声源检测球的大小会影响到环境仿真的结果。
 *
 * @param ctx 要使用的的 context
 * @param mode 选择创建声源的模式，目前支持 PASP_SOURCE_SPATIALIZE 和 PASP_SOURCE_BYPASS。默认为
 * PASP_SOURCE_SPATIALIZE，该声源会正常加入空间化的渲染，如果选择 bypass 模式，声源会被直接 bypass 到各声道输出。
 * @param position 指向待创建声源的位置的指针，position
 * 中应有3个浮点数，对应世界坐标系定义中XYZ。单位：米。默认位置为坐标轴原点，即 (0, 0, 0)
 * @param front 指向声源正面的方向向量的指针。默认 front 指向 Z 轴正向，即 (0, 0, 1)
 * @param up 指向声源正上方的方向向量的指针。默认 up 指向 Y 轴正向，即 (0, 1, 0)
 * @param radius 声源检测球的半径，单位：米。默认半径为 0.1 米
 * @param[out] source_id 返回创建成功的声源的 source_id。每个声源都会对应全局唯一的 source_id。
 * @param is_async (默认值为false) 是否以非同步的方法添加声源，这个选项实质上是一个trade-off：\n
 * 1.
 * 非同步添加声源：不会阻塞调用这个函数的线程，但是在你使用这个source前，你需要去主动询问声源是否被创建完成了。一个例外是
 * PxrAudioSpatializer_SubmitSourceBuffer函数，你可以在任何时候调用它。 \n
 * 2.
 * 同步添加声源（默认）：确保了在这个函数被调用之后，source一定已经初始化完成了；但是函数耗时会更多。在大量声源被一起添加进场景时，可能会短暂阻塞
 * 你的调用线程，造成卡顿。
 * @return 返回执行结果
 *
 * Same as PxrAudioSpatializer_AddSource, except this API can setup source orientation and ray tracing detection radius.
 * Source orientation is useful when creating non-omnidirectional sources (non-omnidirectional source simulation is
 * still under development).
 * Ray tracing detection radius affects echo density and authenticity of simulation early reflections and late reverb
 *
 * @param ctx Context pointer
 * @param source_mode Source rendering mode, which currently includes PASP_SOURCE_SPATIALIZE(default) and
 * PASP_SOURCE_BYPASS. PASP_SOURCE_SPATIALIZE will let this sound source be spatialized, while PASP_SOURCE_BYPASS will
 * directly mix input signal to output channels
 * @param position Source world position, which is a 3-element float array [x, y, z] follows the convention defined in
 * README.md. Unit is meter
 * @param front Facing direction of the source, which defaults to positive direction of Z axis, [0, 0, 1]
 * @param up Direction vector that defines where the top of the source is facing at. it defaults to positive direction
 * of Y axis, [0, 1, 0]
 * @param radius Ray tracing detection radius (unit: meter), which defaults to 0.1
 * @param[out] source_id Returns unique source id.
 * @param is_async (Default to be false) Determine if source is added asynchronously into the scene. This choice is
 * essentially a trade-off:
 * 1. Async source addition won't block the thread that's calling it, but you would need to manually check if source
 * initialization is finished before using this source. The exception of this is PxrAudioSpatializer_SubmitSourceBuffer,
 * which can be called anytime; \n
 * 2. Synchronous source addition (Default) ensures that source is definitely initialized right after the source
 * addition call, but it would take longer to finish, and when lot's of sources was added at the same time, it might
 * block your calling thread for too long.
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_AddSourceWithOrientation(PxrAudioSpatializer_Context* ctx,
                                             PxrAudioSpatializer_SourceMode mode,
                                             const float* position,
                                             const float* front,
                                             const float* up,
                                             float radius,
                                             int* source_id,
                                             bool is_async = false);

/**
 * 根据输入的声源配置创建声源，并返回 source_id。
 *
 * @param ctx 要使用的的 context
 * @param source_config 要使用的声源 config
 * @param[out] source_id 返回创建成功的声源的 source_id。每个声源都会对应全局唯一的 source_id。
 * @param is_async (默认值为false) 是否以非同步的方法添加声源，这个选项实质上是一个trade-off：\n
 * 1.
 * 非同步添加声源：不会阻塞调用这个函数的线程，但是在你使用这个source前，你需要去主动询问声源是否被创建完成了。一个例外是
 * PxrAudioSpatializer_SubmitSourceBuffer 函数，你可以在任何时候调用它。 \n
 * 2.
 * 同步添加声源（默认）：确保了在这个函数被调用之后，source一定已经初始化完成了；但是函数耗时会更多。在大量声源被一起添加进场景时，可能会短暂阻塞
 * 你的调用线程，造成卡顿。
 * @return 返回执行结果
 *
 * Initialize a sound source using specified config
 *
 * @param ctx Context pointer
 * @param source_config Source initialization config to use
 * @param[out] source_id Returns unique source id.
 * @param is_async (Default to be false) Determine if source is added asynchronously into the scene. This choice is
 * essentially a trade-off:
 * 1. Async source addition won't block the thread that's calling it, but you would need to manually check if source
 * initialization is finished before using this source. The exception of this is PxrAudioSpatializer_SubmitSourceBuffer,
 * which can be called anytime; \n
 * 2. Synchronous source addition (Default) ensures that source is definitely initialized right after the source
 * addition call, but it would take longer to finish, and when lot's of sources was added at the same time, it might
 * block your calling thread for too long.
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_AddSourceWithConfig(PxrAudioSpatializer_Context* ctx,
                                        const PxrAudioSpatializer_SourceConfig* source_config,
                                        int* source_id,
                                        bool is_async = false);

/**
 * 通过 PxrAudioSpatializer_SetSourceConfig 设置声源属性。
 *
 * @param ctx 要使用的的 context
 * @param source_id 需要配置 config 的 source id
 * @param source_config 要使用的声源 config
 * @return 返回执行结果
 *
 * Set sound source config by PxrAudioSpatializer_SetSourceConfig
 *
 * @param ctx Context pointer
 * @param source_id ID of sound source
 * @param source_config config of sound source
 * @return Error code of API call
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_SetSourceConfig(PxrAudioSpatializer_Context* ctx,
                                    const int source_id,
                                    const PxrAudioSpatializer_SourceConfig* source_config,
                                    unsigned int property_mask = PASP_SourceProperty_All);
/**
 * 获得声源的 source config 配置
 *
 * @param ctx 要使用的的 context
 * @param source_id 需要获取 config 的source id
 * @param source_config 写入 config 的地址
 * @return 返回执行结果
 *
 * Get sound source config
 *
 * @param ctx Context pointer
 * @param source_id ID of sound source
 * @param source_config address to write source config
 * @return Error code of API call
 *
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_GetSourceConfig(PxrAudioSpatializer_Context* ctx,
                                    const int source_id,
                                    PxrAudioSpatializer_SourceConfig* source_config);

/**
 * 设置声源的距离衰减模型，默认为 InverseSquare，即按照物理计算距离带来的音量衰减。
 * 如果希望外界（游戏引擎、中间件）控制距离衰减，则可讲衰减模型设置为 None 或者 Fixed（在目前的实现中这两者完全相同）。
 *
 * 当衰减模型为 Customized 时，需要用户传入计算距离衰减的回调函数。
 * 回调函数入参为 distance，range_min，range_max，返回距离衰减的gain。
 * 在开启声学仿真模式时，可以分别设置直达声与非直达声的 callback。
 * 如果｜indirect_distance_attenuation_callback｜为 nullptr，则会共用直达声的 callback。
 *
 * @param ctx 要使用的的 context
 * @param source_id 需要调整衰减距离的声源的 ID
 * @param mode 要使用的距离衰减模型
 * @param direct_distance_attenuation_callback 用于直达声的距离衰减回调函数
 * @param indirect_distance_attenuation_callback 用于非直达声的距离衰减回调函数
 * @return 错误码
 *
 * Set distance attenuation mode of the sound source (InverseSquare by default, which calculates attenuation follow
 * Inverse Square Law).
 * Sound is not attenuated when setting attenuation mode to None or Fixed.
 * Customized mode allows user to pass distance attenuation callback.
 * The signature of callback function is float (float distance, float range_min, float range max).
 * Engine allows to apply different callback to direct sound and indirect sound.
 * when |indirect_distance_attenuation_callback| is nullptr, direct and indirect sound will share the callback.
 *
 * @param ctx Context pointer
 * @param source_id ID of sound source
 * @param mode attenuation mode to use
 * @param direct_distance_attenuation_callback callback that applied to direct sound
 * @param indirect_distance_attenuation_callback callback that applied to indirect sound
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result PxrAudioSpatializer_SetSourceAttenuationMode(
    PxrAudioSpatializer_Context* ctx,
    int source_id,
    PxrAudioSpatializer_SourceAttenuationMode mode,
    DistanceAttenuationCallback direct_distance_attenuation_callback = nullptr,
    DistanceAttenuationCallback indirect_distance_attenuation_callback = nullptr);

/**
 * 设置声源的最大与最小衰减距离。
 * 当声源与听音者距离小于 ｜range_min｜ 时，声源音量会到达最大值。
 * 当声源与听音者距离大于 ｜range_max｜ 时，声源音量将会维持 |range_max| 时大小。
 *
 * @param ctx 要使用的的 context
 * @param source_id 需要调整衰减距离的声源的 ID
 * @param range_min 声源音量开始衰减最小的距离（单位：米）
 * @param range_max 声源可听的最大距离（单位：米）
 * @return 错误码
 *
 * Sets min and max range of the sound source.
 * Distance Attenuation becomes 1 when distance from source to listener is shorter than |range_min|.
 * Distance Attenuation stops attenuating when distance from source to listener is longer than |range_max|.
 *
 * @param ctx Context pointer
 * @param source_id ID of sound source
 * @param range_min min range in meters.
 * @param range_max max range in meters.
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_SetSourceRange(PxrAudioSpatializer_Context* ctx, int source_id, float range_min, float range_max);

/**
 * 从场景中删除指定的声源。
 *
 * @param ctx 要使用的的 context
 * @param source_id 需要删除的的声源的 source_id。
 * @return 返回执行结果
 *
 * Remove a sound source from scene
 *
 * @param ctx Context pointer
 * @param source_id ID of the sound source you want to remove
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_RemoveSource(PxrAudioSpatializer_Context* ctx, int source_id);

/**
 * 提交 ID 为 source_id 声源的待处理的单声道音频 buffer
 *
 * 这个方法是音频渲染的核心函数之一。在实时的处理循环中，我们需要将场景中存在的所有的声源的当前待播放的音频数据都提交到引擎中以供统一处理。
 * 这个函数并非立即返回结果，而需要一定的计算时间，当然计算时间会远小于实时音频处理的 deadline。
 *
 * @param ctx 要使用的的 context
 * @param source_id Id of sound source
 * @param input_buffer_ptr Pointer to mono audio buffer
 * @param num_frames Number of frames in audio buffer，通常这个参数的值应当与创建 context 时的 frames_per_buffer 一致。
 * @return 返回执行结果
 *
 * submit input audio for source with specified source ID
 *
 * This API is one of the core API calls of Pico Spatial Audio Renderer.
 * In realtime audio loops, we need to submit source signals of ALL sound sources in the scene for the engine to
 * compute. Mind that this API do take some time to process, but it will meet the realtime deadline with ample head room
 * in time.
 *
 * @param ctx Context pointer
 * @param source_id Id of sound source
 * @param input_buffer_ptr Pointer to mono audio buffer
 * @param num_frames Number of frames in audio buffer, usually the same value as the frames_per_buffer used when
 * creating context.
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_SubmitSourceBuffer(PxrAudioSpatializer_Context* ctx,
                                       int source_id,
                                       const float* input_buffer_ptr,
                                       size_t num_frames);
/**
 * 提交当前的 HOA 音频 PCM buffer。每次调用可以以声道为单位提交 HOA 中指定 order 与 degree 声道的 buffer。这里的 HOA
 * 内容会与 object 的音频内容进行混音。
 *
 * @param ctx 要使用的的 context
 * @param ambisonic_channel_buffer 一个 HOA 声道的 buffer
 * @param order 该声道对应的 HOA 的 order
 * @param degree 该声道对应的 HOA 的 degree
 * @param norm_type 该声道使用的正规化方法，一般有 SN3D 与 N3D 两种
 * @param gain 该声道加入混音的 gain。一般来说为了保证 HOA 渲染结果的准确性，HOA 的所有声道的 gain 应该相同
 * @param (可选) parent_ambisonic_order 该声道所隶属于的Ambisonics信号的阶数
 * @return 返回执行结果
 *
 * Submit a channel of HOA input signal, with input order and degree indices to specify ambisonic channel. The HOA input
 * here will be mixed with object-based audio output
 *
 * @param ctx Context pointer
 * @param ambisonic_channel_buffer The buffer of one HOA channel
 * @param order The order index of this HOA channel
 * @param degree The degree index of this HOA channel
 * @param norm_type The normalization method used for this HOA channel, for example SN3D or N3D
 * @param gain The gain/attenuation added to this HOA channel. Normally all channels of an HOA should have the same
 * gain.*
 * @param (optional) parent_ambisonic_order The ambisonic order of the ambisonic data that owns the submitted channel
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_SubmitAmbisonicChannelBuffer(PxrAudioSpatializer_Context* ctx,
                                                 const float* ambisonic_channel_buffer,
                                                 int order,
                                                 int degree,
                                                 PxrAudioSpatializer_AmbisonicNormalizationType norm_type,
                                                 float gain,
                                                 int parent_ambisonic_order = -1);

/**
 * 提交当前的 HOA 音频 PCM buffer。每次调用将当前处理 block 的 HOA 的所有声道一起提交。这里的 HOA 内容会与 object
 * 的音频内容进行混音。
 *
 * @param ctx 要使用的的 context
 * @param ambisonic_buffer HOA 的 block buffer，以 interleaved 方式排列
 * @param ambisonic_order HOA buffer 的阶数，它应该与 HOA 的声道数相对应
 * @param norm_type HOA 使用的正规化方法，一般有 SN3D 与 N3D 两种
 * @param gain HOA 信号进行混音的 gain
 * @return 返回执行结果
 *
 *
 * Submit a interleaved buffer of HOA input signal. The HOA input here will be mixed with object-based audio output
 *
 * @param ctx Context pointer
 * @param ambisonic_buffer Interleaved HOA input buffer
 * @param ambisonic_order Order of the input HOA signal
 * @param norm_type The normalization method used for this HOA channel, for example SN3D or N3D
 * @param gain The gain/attenuation added to this HOA channel. Normally all channels of an HOA should have the same
 * gain.
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_SubmitInterleavedAmbisonicBuffer(PxrAudioSpatializer_Context* ctx,
                                                     const float* ambisonic_buffer,
                                                     int ambisonic_order,
                                                     PxrAudioSpatializer_AmbisonicNormalizationType norm_type,
                                                     float gain);
/**
 * 提交 matrix 类型输入的音频 buffer。每次调用会提交一个通道。
 *
 * @param ctx 要使用的的 context
 * @param input_buffer 当前输入 block buffer
 * @param input_channel_index 输入 buffer 对应的 matrix mapping index
 * @return 返回执行结果
 *
 * Submit a matrix type input audio channel.
 *
 * @param ctx Context pointer
 * @param input_buffer Input audio channel
 * @param input_channel_index The matrix mapping index of the input buffer
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_SubmitMatrixInputBuffer(PxrAudioSpatializer_Context* ctx,
                                            const float* input_buffer,
                                            int input_channel_index);

/**
 * 提交 自定义类型的输入音频 planner buffer。
 *
 * @param ctx 要使用的的 context
 * @param input_buffer 当前输入 planner buffer
 * @param num_frames 当前输入buffer 的帧长
 * @param channel_config 输入 buffer 对应的通道大类，有若干 Ambisonic 以及传统多通道类型可供选择
 * @param channel_mask 输入 buffer 对应的通道掩码，只有掩码中的非零位对应的通道会被提交到引擎
 * @param discard_lfe 在提交传统多通道 buffer 时，是否丢弃 lfe 通道的信号，默认为
 * true。当你的输出是双耳音频时，建议选择true
 * @return 返回执行结果
 *
 * Submit a matrix type input audio channel.
 *
 * @param ctx Context pointer
 * @param input_buffer Input audio channel
 * @param num_frames Number of frames to be submitted
 * @param channel_config The channel config type of input buffer. You can choose from several Ambisonic and
 * multi-channel configurations
 * @param channel_mask The channel enabling mask of input buffer. Only the input channels that have a non-zero mask bit
 * would be submitted to our engine
 * @param discard_lfe Determine if we would discard lfe channel signal when inputting multi-channel buffer (default to
 * true). When outputting to binaural, we highly recommend that you set it to true.
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_SubmitPlanarPresetInputBuffer(PxrAudioSpatializer_Context* ctx,
                                                  const float* const* input_buffer,
                                                  size_t num_frames,
                                                  PxrAudioSpatializer_ChannelConfig channel_config,
                                                  PxrAudioSpatializer_ChannelMask channel_mask,
                                                  bool discard_lfe = true);

/**
 * 获取空间化处理后的音频数据到交织格式排列的输出。
 *
 * 这个方法是 Pico 空间音频渲染器进行音频渲染的核心函数之一。在实时的处理循环中，当我们使用
 * PxrAudioSpatializer_SubmitSourceBuffer
 * 将所有的声源的音频数据都提交到引擎后，使用这一方法从引擎获取计算好的双声道空间音频输出数据。
 * 通过这个方法获取的数据为双耳数据，即使用耳机进行播放的双声道音频数据。输出音频的格式为交织的，即 LRLRLR。
 *
 * @param ctx 要使用的的 context
 * @param output_buffer_ptr Pointer to output audio buffer。写入渲染后的空间音频结果的指针，这个地址需要留有
 * 2*frames_per_buffer 的空间。
 * @param num_frames 返回输出音频数据的长度。
 * @param is_accumulative 是否将输出双耳信号叠加到 output_buffer_ptr 中的已有信号上
 * @return 返回执行结果
 *
 * Get the interleaved output of the spatialized binaural output
 *
 * This is one of the core API call of Pico Spatial Audio Renderer. After we submitted all source input using
 * PxrAudioSpatializer_SubmitSourceBuffer, use this API to get the interleaved binaural output signal.
 * FYI: use headphone to play back binaural signal.
 *
 * @param ctx Context pointer
 * @param output_buffer_ptr Pointer to output audio buffer, which is a interleaved stereo buffer with
 * 2 * frames_per_buffer of element.
 * @param num_frames Frame count of the output signal。
 * @param is_accumulative Set to true if we want to accumulate current output binaural signal to the existing signal
 * stored in output_buffer_ptr.
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_GetInterleavedBinauralBuffer(PxrAudioSpatializer_Context* ctx,
                                                 float* output_buffer_ptr,
                                                 size_t num_frames,
                                                 bool is_accumulative = false);

/**
 * 获取空间化处理后的音频数据到 Planar 格式排列的输出。
 *
 * 这个方法是 Pico 空间音频渲染器进行音频渲染的核心函数之一。在实时的处理循环中，当我们使用
 * PxrAudioSpatializer_SubmitSourceBuffer
 * 将所有的声源的音频数据都提交到引擎后，使用这一方法从引擎获取计算好的双声道空间音频输出数据。
 * 通过这个方法获取的数据为双耳数据，即使用耳机进行播放的双声道音频数据。
 *
 * @param ctx 要使用的的 context
 * @param output_buffer_ptr Pointer to output audio
 * buffer。写入渲染后的空间音频结果的指针，这个地址需要留有2个声道。且每个声道有 frames_per_buffer 的空间。
 * @param num_frames 返回输出音频数据的长度。
 * @param is_accumulative 是否将输出双耳信号叠加到 output_buffer_ptr 中的已有信号上
 * @return 返回执行结果
 *
 * Same as PxrAudioSpatializer_GetInterleavedBinauralBuffer, but the output layout is planer stereo.
 *
 * This is one of the core API call of Pico Spatial Audio Renderer. After we submitted all source input using
 * PxrAudioSpatializer_SubmitSourceBuffer, use this API to get the planer binaural output signal.
 * FYI: use headphone to play back binaural signal.
 *
 * @param ctx Context pointer
 * @param output_buffer_ptr Pointer to output audio buffer, which is a planer stereo buffer with
 * 2 * frames_per_buffer of element.
 * @param num_frames Frame count of the output signal
 * @param is_accumulative Set to true if we want to accumulate current output binaural signal to the existing signal
 * stored in output_buffer_ptr.
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_GetPlanarBinauralBuffer(PxrAudioSpatializer_Context* ctx,
                                            float* const* output_buffer_ptr,
                                            size_t num_frames,
                                            bool is_accumulative = false);

/**
 * 获取空间化处理后的音频数据
 *
 * 这个方法是 Pico 空间音频渲染器进行音频渲染的核心函数之一。在实时的处理循环中，当我们使用
 * PxrAudioSpatializer_SubmitSourceBuffer
 * 将所有的声源的音频数据都提交到引擎后，使用这一方法从引擎获取计算好的多声道空间音频输出数据。
 * 通过这个方法获取的数据为供扬声器阵列播放的数据，输出音频的格式为交织的，各扬声器的音频数据排列顺序与初始化时扬声器的顺序一致。
 *
 * @param ctx 要使用的的 context
 * @param output_buffer_ptr Pointer to output audio buffer。写入渲染后的空间音频结果的指针，这个地址需要留有
 * num_loudspeakers*frames_per_buffer 的空间。
 * @param num_frames 返回输出音频数据的长度。
 * @return 返回执行结果
 *
 * Get spatialized audio output
 *
 * This is one of the core API call of Pico Spatial Audio Renderer. After we submitted all source input using
 * PxrAudioSpatializer_SubmitSourceBuffer，we call this API to get spatialized audio in multichannel format, aimed for
 * playback on loudspeaker array. Output is interleaved
 *
 * @param ctx Context pointer
 * @param[out] output_buffer_ptr Pointer to output audio buffer。Output buffer pointer, which has
 * num_loudspeakers * frames_per_buffer element。
 * @param num_frames Frame count of the output signal
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_GetInterleavedLoudspeakersBuffer(PxrAudioSpatializer_Context* ctx,
                                                     float* output_buffer_ptr,
                                                     size_t num_frames);

/**
 * 获取空间化处理后的音频数据到 Planar 格式排列的输出。
 *
 * 这个方法是 Pico 空间音频渲染器进行音频渲染的核心函数之一。在实时的处理循环中，当我们使用
 * PxrAudioSpatializer_SubmitSourceBuffer
 * 将所有的声源的音频数据都提交到引擎后，使用这一方法从引擎获取计算好的双声道空间音频输出数据。
 * 通过这个方法获取的数据为供扬声器阵列播放的数据。
 *
 * @param ctx 要使用的的 context
 * @param[out] output_buffer_ptr Pointer to output audio buffer。写入渲染后的空间音频结果的指针，这个地址需要留有
 * num_loudspeakers 个声道，且每个声道 frames_per_buffer 的空间。
 * @param num_frames 返回输出音频数据的长度。
 * @return 返回执行结果
 *
 * Get spatialized audio output, same as PxrAudioSpatializer_GetInterleavedLoudspeakersBuffer, but the output layout is
 * planer.
 *
 * This is one of the core API call of Pico Spatial Audio Renderer. After we submitted all source input using
 * PxrAudioSpatializer_SubmitSourceBuffer，we call this API to get spatialized audio in multichannel format, aimed for
 * playback on loudspeaker array. Output layout is planer.
 *
 * @param ctx Context pointer
 * @param[out] output_buffer_ptr Pointer to output audio buffer。Output buffer pointer, which has
 * num_loudspeakers * frames_per_buffer element。
 * @param num_frames Frame count of the output signal
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_GetPlanarLoudspeakersBuffer(PxrAudioSpatializer_Context* ctx,
                                                float* const* output_buffer_ptr,
                                                size_t num_frames);

/**
 * 更新音频场景变化
 *
 * 这个方法是 Pico 空间音频渲染器
 * 进行音频渲染的核心函数之一。在实时的处理循环中，每个循环都要调用一次这个函数，用于更新场景的数据。
 * 在基础模式中，这个方法会在引擎内部中更新被设置的新的 listener 与 sources 的状态。
 * 在环境声学仿真的模式下，还会根据场景更新场景对听到声音的影响。
 * 另外，在 Free-Field 模式中，这个API可以在音频实时线程中直接使用，但在环境声学模式下，不要在实时线程中使用。
 * @param ctx 要使用的的 context
 * @return 返回执行结果
 *
 * Update acoustic scene status
 *
 * One of the core API call of Pico Spatial Audio Renderer. It has to be called frequently in order to refresh audio
 * rendering parameters inside engine. In free field mode, calling this API would update source and listener status.
 * When environmental acoustics is enabled, this API would also update the influence of scene on early reflection
 * and late reverb.
 * Also, in free field mode, this API can be called in audio thread; However, when environmental acoustics is enabled,
 * you should never call it in audio thread, or any other thread with hard deadline.
 *
 * @param ctx Context pointer
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_UpdateScene(PxrAudioSpatializer_Context* ctx);

/**
 * Switch Doppler effect. Only affect in free field Build.
 * This method will allocate memory, don't call it during playing.
 *
 * @param ctx Context pointer
 * @param on 1 or 0. 1=turn on Doppler effect, 0=turn off Doppler effect
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_SetDopplerEffect(PxrAudioSpatializer_Context* ctx, int source_id, int on);

/**
 * 设置双耳回放或扬声器回放，默认为双耳回放，这个方法应在 context 创建后，初始化前调用。
 * 目前，如果是双耳回放，则使用 PxrAudioSpatializer_GetInterleavedBinauralBuffer
 * 获取渲染后音频数据，如果是扬声器阵列回放，则使用 PxrAudioSpatializer_GetInterleavedLoudspeakersBuffer
 * 来获取渲染后音频数据。
 *
 * @param ctx 要使用的的 context
 * @param playback_mode 回放方式，PASP_BINAURAL_OUT 或者 PASP_LOUDSPEAKERS_OUT。
 * @return 返回执行结果
 *
 * Setup whether we use binaural (default) or loudspeaker output scheme. Call it after creating the context, but before
 * initializing it.
 * If we use binaural output mode, then use PxrAudioSpatializer_GetInterleavedBinauralBuffer to get output signal;
 * Instead, if we use loudspeaker output, then use PxrAudioSpatializer_GetInterleavedLoudspeakersBuffer to get output
 * signal
 *
 * @param ctx Context pointer
 * @param playback_mode Choose PASP_BINAURAL_OUT or PASP_LOUDSPEAKERS_OUT。
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_SetPlaybackMode(PxrAudioSpatializer_Context* ctx, PxrAudioSpatializer_PlaybackMode playback_mode);

/**
 * 设置用于回放的扬声器阵列位置，这个API较为耗时，因此应在实时处理开始前调用。
 *
 * @param ctx 要使用的的 context
 * @param positions 扬声器阵列在世界坐标系下的位置，格式为 xyzxyzxyz，
 * @param num_loudspeakers 扬声器阵列中扬声器的数量
 * @return 返回执行结果
 *
 * Setup loudspeaker positions in the loudspeaker array. This API is time-consuming, please call it before realtime
 * processing is started
 *
 * @param ctx Context pointer
 * @param positions World positions of loudspeakers, in the format of xyzxyzxyz，
 * @param num_loudspeakers Num of loudspeakers in the playback array
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_SetLoudspeakerArray(PxrAudioSpatializer_Context* ctx, const float* positions, int num_loudspeakers);

/**
 * 设置 Matrix 类型输入的映射矩阵。
 *
 * @param ctx 要使用的的 context
 * @param matrix 矩阵数据，Column major。
 * @param num_input_channels 输入channel总数
 * @param num_output_channels 输出channel 总数，应当与扬声器的数量相同。
 * @return 返回执行结果
 *
 * Setup mapping matrix for matrix type input signal
 *
 * @param ctx Context pointer
 * @param Column major mapping matrix
 * @param num_input_channels Num of input channels
 * @param num_output_channels Num of input channels, should agree with the number of loudspeakers
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_SetMappingMatrix(PxrAudioSpatializer_Context* ctx,
                                     const float* matrix,
                                     int num_input_channels,
                                     int num_output_channels);

/**
 * 设置 Ambisonic 输入的默认朝向。有时我们会希望在渲染声源的同时加入 Ambisonic 格式的输入。在实际应用中，Ambisonic
 * 的方向是与场景保持锁定，不随 Listener 转向而变化，这个方法用于设置Ambisonic默认的朝向。
 *
 * @param ctx 要使用的的 context
 * @param front Ambisonic 朝向的前方的向量
 * @param up Ambisonic 朝向的上方的向量
 * @return
 *
 * Setup default orientation of Ambisonic input
 *
 * @param ctx Context pointer
 * @param front Facing direction of Ambisonic input
 * @param up Up direction of Ambisonic input
 * @return
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_SetAmbisonicOrientation(PxrAudioSpatializer_Context* ctx, const float* front, const float* up);

/**
 * 设置 listener 在世界坐标系中的位置。这个方法不会改变 listener 的朝向。
 *
 * @param ctx 要使用的的 context
 * @param position 指向 listener 的位置的指针，position 中应有3个浮点数，对应世界坐标系定义中XYZ。单位：米。
 * @return 返回执行结果
 *
 * Setup world position of listener. This API call wouldn't change the orientation of the listener
 *
 * @param ctx Context pointer
 * @param position Pointer to a 3-float array containing the world position of listener in XYZ order (unit: meter).
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_SetListenerPosition(PxrAudioSpatializer_Context* ctx, const float* position);

/**
 * 设置 listener 在世界坐标系中的朝向信息，这个方法不会改变 listener 的位置
 *
 * @param ctx 要使用的的 context
 * @param front 指向 listener 正面的方向向量的指针
 * @param up 指向 listener 正上方的方向向量的指针
 * @return 返回执行结果
 *
 * Setup world orientation of the listener. This API call wouldn't change the position of the listener
 *
 * @param ctx Context pointer
 * @param front Facing direction of the source.
 * @param up Direction vector that defines where the top of the source is facing at.
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_SetListenerOrientation(PxrAudioSpatializer_Context* ctx, const float* front, const float* up);

/**
 * 设置 listener 在世界坐标系中的姿态信息，包含了位置与朝向
 *
 * @param ctx 要使用的的 context
 * @param position 指向 listener 的位置的指针，position 中应有3个浮点数，对应世界坐标系定义中XYZ。单位：米。
 * @param front 指向 listener 正面的方向向量的指针
 * @param up 指向 listener 正上方的方向向量的指针
 * @return 返回执行结果
 *
 * Setup both world position and orientation of the listener
 *
 * @param ctx Context pointer
 * @param position Pointer to a 3-float array containing the world position of listener in XYZ order (unit: meter).
 * @param front Facing direction of the source.
 * @param up Direction vector that defines where the top of the source is facing at.
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_SetListenerPose(PxrAudioSpatializer_Context* ctx,
                                    const float* position,
                                    const float* front,
                                    const float* up);

/**
 * 设置 ID 为 source_id 的声源的位置
 *
 * @param ctx 要使用的的 context
 * @param source_id 想要改变位置的声源的 source_id
 * @param position 指向要改变到的位置的指针，position 中应有3个浮点数，对应世界坐标系定义中XYZ。单位：米。
 * @return 返回执行结果
 *
 * Setup the world position of the specified source
 *
 * @param ctx Context pointer
 * @param source_id The ID of the source to modify
 * @param position Pointer to a 3-float array containing the world position of listener in XYZ order (unit: meter).
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_SetSourcePosition(PxrAudioSpatializer_Context* ctx, int source_id, const float* position);

/**
 * 改变 ID 为 source_id 的声源的音量
 *
 * @param ctx 要使用的的 context
 * @param source_id 想要改变位置的声源的 source_id
 * @param gain 想要设置的声源的音量
 * @return 返回执行结果
 *
 * Setup gain applied to the specified source
 *
 * @param ctx Context pointer
 * @param source_id The ID of the source to modify
 * @param gain Source signal gain/attenuation
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_SetSourceGain(PxrAudioSpatializer_Context* ctx, int source_id, float gain);

/**
 * 改变 ID 为 source_id 的声源的大小
 *
 * @param ctx 要使用的的 context
 * @param source_id 想要改变位置的声源的 source_id
 * @param volumetric_size 想要设置的声源的半径，单位是米
 * @return 返回执行结果
 *
 * Setup gain applied to the specified source
 *
 * @param ctx Context pointer
 * @param source_id The ID of the source to modify
 * @param volumetric_size Source volumetric radius in meters
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_SetSourceSize(PxrAudioSpatializer_Context* ctx, int source_id, float volumetric_size);

/**
 * 更新source的mode:PASP_SOURCE_SPATIALIZE 或 PASP_SOURCE_BYPASS
 * @param ctx 要使用的的 context
 * @param source_id 想要更新的声源的 source_id
 * @param mode 处理方式
 * @return 返回执行结果
 *
 * Update source mode: between PASP_SOURCE_SPATIALIZE or PASP_SOURCE_BYPASS
 * @param ctx Context pointer
 * @param source_id The ID of the source to modify
 * @param mode Source playback mode
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result
PxrAudioSpatializer_UpdateSourceMode(PxrAudioSpatializer_Context* ctx,
                                     int source_id,
                                     PxrAudioSpatializer_SourceMode mode);

/**
 * 销毁 context
 *
 * 在 Pico 空间音频渲染器运行结束后，调用这个方法销毁 context
 *
 * @param ctx 要使用的的 context
 * @return 返回执行结果
 *
 * Destroy context
 *
 * After done running the Pico Spatial Audio Renderer, call this method to deconstruct context
 *
 * @param ctx Context pointer
 * @return Error code of this API call. Returns PASP_SUCCESS if nothing was wrong.
 */
PXR_AUDIO_SPATIALIZER_EXPORT PxrAudioSpatializer_Result PxrAudioSpatializer_Destroy(PxrAudioSpatializer_Context* ctx);

/**
 * 申请内存地址对齐的指针数据(float)
 * @param 数据的长度
 * @return 返回指向该内存的首地址指针
 *
 * Get the address aligned memory block
 * @param Length size of memory block
 * @return Pointer of memory address
 */
PXR_AUDIO_SPATIALIZER_EXPORT float* PxrAudioSpatializer_AlignedMalloc(size_t length);

/**
 * 释放分配的浮点型内存地址
 * @param malloced_ptr  地址指针
 *
 * Free the malloced memory address block
 * @param malloced_ptr
 */
PXR_AUDIO_SPATIALIZER_EXPORT void PxrAudioSpatializer_AlignedFree(float* malloced_ptr);

#ifdef __cplusplus
}
#endif

#endif  // PXR_AUDIO_SPATIALIZER_H
