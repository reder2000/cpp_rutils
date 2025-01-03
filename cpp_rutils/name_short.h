#pragma once

// compile time type name
#include "cpp_rutils/config.h"
#include "name.h"
#include <string>
#include <memory>

#if !defined(HAVE_CXX20_STD_FORMAT)
#include <fmt/format.h>
#endif


// forward declare std stuff
namespace std
{
  template <class _Kty, class _Ty, class _Hasher, class _Keyeq, class _Alloc>
  class unordered_map;

  template <class _Kty, class _Ty, class Pr, class _Alloc>
  class map;

  template <class _Ty, class _Alloc>
  class vector;

}  // namespace std

namespace detail
{
  // we cannot return a char array from a function, therefore we need a wrapper
  template <size_t N>
  struct String
  {
    char c[N];
  };

  template <size_t... Len>
  constexpr auto cat(const char (&... strings)[Len])
  {
    constexpr size_t N      = (... + Len) - sizeof...(Len);
    String<N + 1>    result = {};
    result.c[N]             = '\0';

    char* dst = result.c;
    for (const char* src : {strings...})
    {
      for (; *src != '\0'; src++, dst++)
      {
        *dst = *src;
      }
    }
    return result;
  }

  template <typename T>
  struct type_namer
  {
    constexpr static auto get()
    {
      constexpr auto   sv     = ::type_name<T>();
      constexpr size_t N      = sv.length();
      String<N + 1>    result = {};
      result.c[N]             = '\0';

      char* dst = result.c;
      for (auto src : sv)
      {
        *dst++ = src;
      }
      return result;
    }
  };

  template <class _Ty, class _Alloc>
  struct type_namer<std::vector<_Ty, _Alloc>>
  {
    constexpr static auto get()
    {
      return cat("vector<", type_namer<std::decay_t<_Ty>>().get().c, ">");
    }
  };

  template <class _Kty, class _Ty, class _Hasher, class _Keyeq, class _Alloc>
  struct type_namer<std::unordered_map<_Kty, _Ty, _Hasher, _Keyeq, _Alloc>>
  {
    constexpr static auto get()
    {
      return cat("unordered_map<", type_namer<std::decay_t<_Kty>>().get().c, ",",
                 type_namer<std::decay_t<_Ty>>().get().c, ">");
    }
  };

  template <class _Elem, class _Traits, class _Alloc>
  struct type_namer<std::basic_string<_Elem, _Traits, _Alloc>>
  {
    constexpr static auto get() { return cat("string"); }
  };

  template <class _Ty>
  struct type_namer<std::shared_ptr<_Ty>>
  {
    constexpr static auto get()
    {
      return cat("shared_ptr<", type_namer<std::decay_t<_Ty>>().get().c, ">");
    }
  };

  template <class _Kty, class _Ty, class Pr, class _Alloc>
  struct type_namer<std::map<_Kty, _Ty, Pr, _Alloc>>
  {
    constexpr static auto get()
    {
      return cat("map<", type_namer<std::decay_t<_Kty>>().get().c, ",",
                 type_namer<std::decay_t<_Ty>>().get().c, ">");
    }
  };

}  // namespace detail


template <typename T>
constexpr auto type_name_short() noexcept
{
  {
    return detail::type_namer<std::decay_t<T>>::get();
  }
}

template <size_t N>
std::ostream& operator<<(std::ostream& os, const detail::String<N> s)
{
  os << s.c;
  return os;
}

#if defined(HAVE_CXX20_STD_FORMAT)
namespace std
{
  template <size_t N>
  struct formatter<::detail::String<N>> : formatter<std::string>
  // template < class CharT> struct formatter < Point, CharT>
  {
    //template <typename FormatParseContext>
    //auto parse(FormatParseContext& pc)
    //{
    //  // parse formatter args like padding, precision if you support it
    //  return pc
    //      .end();  // returns the iterator to the last parsed character in the format string, in this case we just swallow everything
    //}

    template <typename FormatContext>
    auto format(::detail::String<N> c, FormatContext& ctx) const
    {
      //return std::format_to(fc.out(), "[{}, {}]", p.x, p.y);
      return formatter<std::string>::format(c.c, ctx);
    }
  };
}  // namespace std
#else
template < size_t N>
struct std__formatter<::detail::String<N>> : formatter<std::string>
{
  // parse is inherited from formatter<string_view>.
  template <typename FormatContext>
  auto format(::detail::String<N> c, FormatContext& ctx) const
  {
    static std::string formatString("%Y-%m-%dT%T%Z");
    return formatter<std::string>::format(c.c, ctx);
  }
};
#endif

