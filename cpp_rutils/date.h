#pragma once

// header for portable c++20 calendar 

#if defined(__GNUC__)
#include <date/date.h>
#include <date/tz.h>
#define std__chrono date
#else
#define std__chrono std::chrono
#endif