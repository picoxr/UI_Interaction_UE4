#pragma once

#include "../types.h"
#include "../iinterface.h"

namespace pxr
{
    namespace renderer
    {
        class RendererInterface
            :public IDPInterface
        {
        public:
            virtual IResult Startup(IRenderType type) = 0;

            virtual IResult Shutdown() = 0;

            virtual IRenderType GetType() = 0;

            /**
             * \brief Get the renderer context after Initialize(...) success.
             * \return The context of Direct3D or OpenGL. For D3D, it's a pointer of ID3D11Device, for OpenGL, it's a EGLContext
             */
            virtual p_resource_handle GetNativeRendererContext() = 0;

            /**
             * \brief Set the input texture as a render input.
             * \param in_texture Must be able to use as a shader resource which created by the context from GetNativeRendererContext().
             * \return
             */
            virtual IResult SetSourceTexture(p_resource_handle in_texture) = 0;

            /**
             * \brief Set the input texture as a render input.
             * \param in_texture Must be able to use as a shader resource which created by the context from GetNativeRendererContext().
             * \return
             */
            virtual IResult SetSourceDDSTexture(std::wstring& dds_path) = 0;


            virtual bool IsCurrentSourceTextureValid() = 0;

            /**
             * \brief Set the output texture as a render output.
             * \param out_texture Must be able to use as a render target which created by the context from GetNativeRendererContext().
             * \return
             */
            virtual IResult SetTargetTexture(p_resource_handle out_texture) = 0;

            virtual bool IsCurrentTargetTextureValid() = 0;

            virtual IResult PreRender() = 0;

            virtual IResult Render(IRenderProc proc) = 0;

            virtual IResult PostRender() = 0;


        };
    }
}
