#pragma once

#include "cpp_rutils/config.h"

#if defined(HAVE_CXX20_STD_FORMAT)
  #include <format>

  #define std__format std::format
  #define std__formatter std::formatter
  #if defined(HAVE_CXX23_STD_PRINT)
  #define std__print std::print
#else
  #include <cstdio>
    #define std__print(...) printf("%s",std__format(__VA_ARGS__).c_str())
  #endif

#else
  #include <fmt/format.h>
  #define std__formatter fmt::formatter
  #define std__format fmt::format
  #define std__print fmt::print
#endif
