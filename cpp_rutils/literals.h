#pragma once 

#include <cstddef>

// size_t literal 
inline
constexpr size_t operator "" _uz(unsigned long long n)
{
    return n;
}


inline constexpr unsigned char operator "" _uchar(char arg) noexcept
{
    return static_cast<unsigned char>(arg);
}