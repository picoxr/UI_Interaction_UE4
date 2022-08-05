#pragma once
#include <string>

namespace pxr
{
    typedef char			   p_int8;
    typedef short              p_int16;
    typedef int                p_int32;
    typedef long long          p_int64;
    typedef unsigned char      p_uint8;
    typedef unsigned short     p_uint16;
    typedef unsigned int       p_uint32;
    typedef unsigned long long p_uint64;
    typedef float              p_float;
    typedef double             p_double;


#ifndef p_nullptr
#define p_nullptr nullptr
#endif

#ifndef p_bool
#define p_bool bool
#endif

    typedef size_t				p_size;
    typedef std::string			p_string;

    typedef p_uint64 p_resource_handle;

#ifndef p_resource_null
#define p_resource_null (p_resource_handle)0
#endif

    typedef union
    {
        p_uint32 ui;
        p_uint8 uc[4];
    } p_uint32_union;

    template<typename T> struct p_vector2
    {
        T x, y;

        template <class Archive>
        void serialize(Archive& ar)
        {
            ar(x);
            ar(y);
        }
    };

    template<typename T> struct p_vector3
    {
        T x, y, z;

        template <class Archive>
        void serialize(Archive& ar)
        {
            ar(x);
            ar(y);
            ar(z);
        }
    };
    
    template<typename T> struct p_vector4
    {
        T x, y, z, w;

        template <class Archive>
        void serialize(Archive& ar)
        {
            ar(x);
            ar(y);
            ar(z);
            ar(w);
        }
    };

    typedef p_vector2<p_float> p_vector2_f;
    typedef p_vector3<p_float> p_vector3_f;
    typedef p_vector4<p_float> p_vector4_f;

#ifndef PXR_INTERGER_FLOOR
    /**
     * Provide a macro to get the upper int divisor of two integers
     */
#define PXR_INTEGER_FLOOR(a, b) p_uint32(((a) + (b)-1) / (b))
#endif

#ifndef PXR_SAFE_DELETE
#define PXR_SAFE_DELETE(p)       { if(p) { delete (p);     (p)=nullptr; } }
#endif    

#ifndef PXR_SAFE_DELETE_ARRAY
#define PXR_SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=nullptr; } }
#endif

#ifndef PXR_UNUSED
     /**
      * Provide a macro to use for marking method parameters as unused.
      */
#define PXR_UNUSED(x) (void)(x)
#endif

#ifndef PXR_FRIEND_DECLARATION
      /**
       * Provide a macro to use for marking method parameters as unused.
       */
#define PXR_FRIEND_DECLARATION(x) friend class x
#endif

#ifndef PXR_NO_COPY
      /**
       * Provide a macro to use for make class disable copy constructor
       */
#define PXR_NO_COPY(ClassName) \
	public: \
		ClassName(const ClassName &) = delete; \
		ClassName &operator=(const ClassName &) = delete;
#endif

#ifndef PXR_NULLABLE
       /**
        * Provide a macro to indicate field is nullable
        */
#define PXR_NULLABLE
#endif

#ifndef PXR_OUT_VALUE
        /**
         * Provide a macro to indicate parameter is used for get value from function
         */
#define PXR_OUT_VALUE
#endif


#if  defined(_WINDOWS) || defined(_WINDLL)
#ifndef PXR_PLATFORM_WINDOWS
#define PXR_PLATFORM_WINDOWS
#endif


    template <class T> void pxr_com_interface_safe_release(T** ppT)
    {
        if (*ppT)
        {
            (*ppT)->Release();
            *ppT = NULL;
        }
    }

#ifndef PXR_COM_INTERFACE_SAFE_RELEASE
#define PXR_COM_INTERFACE_SAFE_RELEASE pxr_com_interface_safe_release
#endif

#endif


#ifdef _MSC_VER
//#define _WIN32_WINNT 0x0A00 //Windows10
#endif

}
