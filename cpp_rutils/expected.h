#pragma once

#include "cpp_rutils_config.h"

#if defined(HAVE_CXX23_EXPECTED)
#include <expected>
template <class T>
using expected_s   = std::expected<T, std::string>;
using unexpected_s = std::unexpected<std::string>;
#else
#include <tl/expected.hpp>
template <class T>
using expected_s   = tl::expected<T, std::string>;
using unexpected_s = tl::unexpected<std::string>;
#endif

#include <boost/preprocessor/if.hpp>
#include <boost/preprocessor/dec.hpp>
#include <boost/preprocessor/variadic/size.hpp>
#include <fmt/format.h>


#define MEXPECTED1(success, ...) \
  if (! (success))               \
  return unexpected_s(           \
      fmt::format("{} , {} , {} , {} ", __func__, __FILE__, __LINE__, fmt::format(__VA_ARGS__)))

#define MEXPECTED0(...) MEXPECTED1(__VA_ARGS__, #__VA_ARGS__)

#define MEXPECTED(...)                                                                    \
  BOOST_PP_IF(BOOST_PP_DEC(BOOST_PP_VARIADIC_SIZE(__VA_ARGS__)), MEXPECTED1(__VA_ARGS__), \
              MEXPECTED0(__VA_ARGS__))

#define CHECK_EXPECTED(e) \
  if (! e) return unexpected_s(e.error());

#define REQUIRE_EXPECTED(e) \
  if (! e) MFAIL("{}", e.error())


#define EXPECTED_OR_RETURN(var, walue) \
  auto var##temp = walue;              \
  CHECK_EXPECTED((var##temp));         \
  auto var = std::move(var##temp.value());

#define EXPECTED_OR_FAIL(var, walue) \
  auto var##temp = walue;            \
  REQUIRE_EXPECTED((var##temp));     \
  auto var = std::move(var##temp.value());

template <>
struct fmt::formatter<unexpected_s> : formatter<std::string>
{
  auto format(unexpected_s const& c, format_context& ctx) const
  {
    const std::string& v =
#if defined(HAVE_CXX23_EXPECTED)
        c.error();
#else
        c.value();
#endif
    return formatter<std::string>::format(v, ctx);
  }
};

template <class T>
struct fmt::formatter<expected_s<T>> : formatter<std::string>
{
  auto format(expected_s<T> const& c, format_context& ctx) const
  {
    if (c) return formatter<std::string>::format(fmt::format("{}", *c), ctx);
    return formatter<std::string>::format(fmt::format("{}", c.error()), ctx);
  }
};
