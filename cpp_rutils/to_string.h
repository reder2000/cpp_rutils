#pragma once

// try to convert anything to string
// needs a rework

#include <sstream>
#include <string>
#include "format.h"
#include <variant>
#include <string_view>

#include "to_string.h"

//#if ! defined(HAVE_CXX20_STD_FORMAT)
//  #if FMT_VERSION >= 100000
//    #define FMT_VXX fmt::v10
//  #elif FMT_VERSION >= 90000
//    #define FMT_VXX fmt::v9
//  #else
//    #error "FMT VERSION TOO OLD"
//  #endif
//#endif


template <typename T>
inline constexpr bool is_stdstring_convertible = std::is_convertible_v<T, std::string>;

template <class T>
concept is_fmt_formattable_c = requires(T a) { std__formatter<T>{}; };

template <class T>
constexpr bool is_fmt_formattable = is_fmt_formattable_c<T>;

namespace
{
  namespace detaille
  {
    struct toto
    {
      int a, b;
    };

    static_assert(is_fmt_formattable_c<std::string>);
    static_assert(! is_fmt_formattable_c<toto>);

    static_assert(is_fmt_formattable<std::string>);
    static_assert(! is_fmt_formattable<toto>);

  }  // namespace
}  // namespace

//template <typename T>
//constexpr bool is_fmt_formattable_t()
//{
//  using Context = FMT_VXX::basic_format_context<FMT_VXX::detail::buffer_appender<char>, char>;
//  return fmt::has_formatter<T, Context>::value;
//}
//
//template <typename T>
//inline constexpr bool is_fmt_formattable = is_fmt_formattable_t<T>();

// See http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4502.pdf.
template <typename...>
using void_t = void;

// Primary template handles all types not supporting the operation.
template <typename, template <typename> class, typename = void_t<>>
struct detect : std::false_type
{
};

// Specialization recognizes/validates only types supporting the archetype.
template <typename T, template <typename> class Op>
struct detect<T, Op, void_t<Op<T>>> : std::true_type
{
};

//// Archetypal expression for assignment operation.
template <typename T>
using is_streamable_t = decltype(std::declval<std::ostream &>() << std::declval<T>());

// Trait corresponding to that archetype.
template <typename T>
inline constexpr bool is_streamable = detect<T, is_streamable_t>::value;

// Traits if type may be printed by one of the methods
template <typename T>
inline constexpr bool is_printable = is_fmt_formattable<T>;  // is_streamable<T>; // ||

template <typename T>
std::string to_string(const T &v)
{
  bool constexpr is_pointer_to_non_void =
      std::is_pointer_v<T> && ! std::is_void_v<std::decay_t<std::remove_pointer_t<T>>>;

  static_assert((! is_pointer_to_non_void) || is_stdstring_convertible<T>, "must be implemented");

  bool constexpr has_to_string = is_stdstring_convertible<T> || is_fmt_formattable<T> || is_streamable<T>;

  static_assert(has_to_string, "must be implemented");

  if constexpr (is_stdstring_convertible<T>)
  {
    return std::string(v);
  }
  else if constexpr (is_fmt_formattable<T>)
  {
    static_assert(is_fmt_formattable_c<T>);
    return std__format("{}", v);
  }
  else if constexpr (is_streamable<T>)
  {
    std::ostringstream ss;
    ss << v;
    return ss.str();
  }
  else
  {
    throw std::runtime_error("I should not have been here");
  }
}

template <class... T>
std::string to_string(const std::variant<T...> &v)
{
  return std::visit([](auto &&a) { return to_string(a); }, v);
}

std::string_view at_most_n_lines(std::string_view sv, size_t n);
