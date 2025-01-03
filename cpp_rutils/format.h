#pragma once

#include "cpp_rutils/config.h"
#include <vector>

#if defined(HAVE_CXX20_STD_FORMAT)
  #include <format>
  #include <optional>
  #include <sstream>
  #include <tuple>

  #define std__format std::format
  #define std__vformat std::vformat
  #define std__formatter std::formatter
  #define std__format_context std::format_context
  #if defined(HAVE_CXX23_STD_PRINT)
    #define std__print std::print
  #else
    #include <cstdio>
    #define std__print(...) printf("%s", std__format(__VA_ARGS__).c_str())
  #endif

#else
  #include <fmt/format.h>
  #include <fmt/ranges.h>
  #include <fmt/chrono.h>
  #include <fmt/std.h>
  #define std__formatter fmt::formatter
  #define std__format fmt::format
  #define std__vformat fmt::vformat
  #define std__print fmt::print
  #define std__format_context fmt::format_context
  #define std__streamed fmt::streamed
#endif

template <class R, class V, class S>
auto format_join(R r, std::vector<V> v, S sep)
{
#if defined(HAVE_CXX20_STD_FORMAT)
  auto b = v.begin();
  auto e = v.end();
  if (b == e) return std::string{};
  std::string res = std__vformat(r, std::make_format_args(*b));
  b++;
  for (; b != e; ++b)
  {
    res += sep;
    res += std__vformat(r, std::make_format_args(*b));
  }
  return res;
#else
  return fmt::format(r, fmt::join(v, sep));
#endif
}

template <class R, class... Args, class S>
auto format_join(R r, std::tuple<Args...> const& t, S sep)
{
#if defined(HAVE_CXX20_STD_FORMAT)
  std::stringstream ss;
  ss << "[";
  std::apply([&](auto&&... args) { ((ss << std__vformat(r, std::make_format_args(args)) << sep), ...); }, t);
  ss.seekp(- static_cast<int>(std::size(std::string(sep))), ss.cur);
  ss << "]";
  return ss.str();
#else
  return fmt::format(r, fmt::join(v, sep));
#endif
}



#if defined(HAVE_CXX20_STD_FORMAT)
template <class V>
struct std::formatter<std::vector<V>> : formatter<std::string>
{
  template <typename FormatContext>
  auto format(const std::vector<V>& v, FormatContext& ctx) const
  {
    auto res = format_join("{}", v, ",");
    return formatter<std::string>::format(res, ctx);
  }
};

template <class T>
std::string std__streamed(T v)
{
  std::stringstream ss;
  ss << v;
  return ss.str();
}


template <class V>
struct std::formatter<std::optional<V>> : formatter<std::string>
{
  template <typename FormatContext>
  auto format(const std::optional<V>& v, FormatContext& ctx) const
  {
    if (v.has_value())
    {
      auto res = std__format("{}", v.value());
      return formatter<std::string>::format(res, ctx);
    }
    else
    {
      return formatter<std::string>::format("{nullptr}", ctx);
    }
  }
};

#endif


template <typename T>
concept formattable =
    requires(T& v, std__format_context ctx) { std__formatter<std::remove_cvref_t<T>>().format(v, ctx); };
