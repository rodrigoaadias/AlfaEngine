#define ASSERTIONS_ENABLED 1
#include <cassert>

#if ASSERTIONS_ENABLED

// check the expression and fail if it is false
#define ASSERT(expr) \
    if (expr) { } \
    else \
    { \
        assert(#expr, __FILE__, __LINE__); \
        __debugbreak(); \
    }
#else
#define ASSERT(expr) // evaluates to nothing
#endif

#ifndef _MSVC_LANG
#define _MSVC_LANG __cplusplus
#endif

#ifdef _MSVC_LANG
    #if _MSVC_LANG >= 201103L
        #define STATIC_ASSERT(expr) \
        static_assert(expr, \
        "static assert failed:" \
        #expr)
    #else
        // declare a template but only define the
        // true case (via specialization)
        template<bool> class TStaticAssert;
        template<> class TStaticAssert<true> {};
        #define STATIC_ASSERT(expr) \
        enum \
        { \
            ASSERT_GLUE(g_assert_fail_, __LINE__) = sizeof(TStaticAssert<!!(expr)>) \
        }
    #endif
#endif