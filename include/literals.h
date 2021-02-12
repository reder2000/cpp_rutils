#pragma once 

#include <cstddef>

// size_t literal 
constexpr size_t operator "" _uz(unsigned long long n)
{
    return n;
}

