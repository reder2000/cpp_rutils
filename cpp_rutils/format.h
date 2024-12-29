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
  #include <fmt/ranges.h>
  #define std__formatter fmt::formatter
  #define std__format fmt::format
  #define std__print fmt::print
#endif

template <class V, class S>
auto format_join(V v, S sep)
{
#if defined(HAVE_CXX20_STD_FORMAT) 
    auto b = v.begin();
    auto e = v.end();
    if (b == e) return std::string{};
    std::string res = *b;
    b++;
    for (; b != e; ++b)
    {
      res += sep;
      res += *b;
    }
    return res;
#else
  return fmt::format("{}", fmt::join(v, sep));
#endif
}
