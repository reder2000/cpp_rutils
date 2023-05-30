#pragma once

#include <tl/expected.hpp>
#include <boost/preprocessor/if.hpp>
#include <boost/preprocessor/dec.hpp>
#include <boost/preprocessor/variadic/size.hpp>


template <class T>
using expected_s   = tl::expected<T, std::string>;
using unexpected_s = tl::unexpected<std::string>;

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

#define EXPECTED_OR_RETURN(var, walue) \
  auto var##temp = walue;              \
  CHECK_EXPECTED((var##temp));         \
  auto var = std::move(var##temp.value());
