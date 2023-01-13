#pragma once
#include <iostream>
#define UNUSED [[maybe_unused]]
#define LOG(x) std::cout << x << '\n'
#define ASSERT(x, log) if (!(x)) { LOG(log << "\n[Exiting due to assert failed]"); exit(-1); }

// Flag helper macros
#define BIT(x) (1 << (x))

template<typename Enum, typename std::enable_if_t<std::is_enum_v<Enum>, bool> = true>
using EnumType = std::underlying_type_t<Enum>;

// Based on https://stackoverflow.com/questions/1448396/how-to-use-enums-as-flags-in-c
// (Answer https://stackoverflow.com/a/23152590): Licensed under CC BY-SA 3.0
#define DEFINE_ENUM_FLAGS(T)                            \
    inline T operator~(T a)                             \
    {                                                   \
        return (T) ~(EnumType<T>)a;                     \
    }                                                   \
    inline T operator|(T a, T b)                        \
    {                                                   \
        return (T)((EnumType<T>)a | (EnumType<T>)b);    \
    }                                                   \
    inline T operator&(T a, T b)                        \
    {                                                   \
        return (T)((EnumType<T>)a & (EnumType<T>)b);    \
    }                                                   \
    inline T operator^(T a, T b)                        \
    {                                                   \
        return (T)((EnumType<T>)a ^ (EnumType<T>)b);    \
    }                                                   \
    inline T& operator|=(T& a, T b)                     \
    {                                                   \
        return (T&)((EnumType<T>&)a |= (EnumType<T>)b); \
    }                                                   \
    inline T& operator&=(T& a, T b)                     \
    {                                                   \
        return (T&)((EnumType<T>&)a &= (EnumType<T>)b); \
    }                                                   \
    inline T& operator^=(T& a, T b)                     \
    {                                                   \
        return (T&)((EnumType<T>&)a ^= (EnumType<T>)b); \
    }

#define FLAG_CHECK(val, check) ((int)(val & (check)) == (int)check)

namespace Utils
{
    inline std::string ToStringPrecision(double x, const char* fmt)
    {
        char buf[128];
        snprintf(buf, sizeof(buf), fmt, x);
        return buf;
    }
}
