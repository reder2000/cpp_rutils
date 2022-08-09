#pragma once
// tentative portable date 
// will use either chrono or date

#include "cpp_rutils_config.h"

#include <chrono>

#if defined(HAVE_CXX20_CHRONO_DURATION)
#define std__chrono std::chrono
#else
#include <date/date.h>
#include <date/tz.h>
#define std__chrono date
#endif

#include "secure_deprecate.h"
#include "to_.h"
#include <fmt/chrono.h>

// date type
using Date = std__chrono::year_month_day;

// date constructor without boilerplate conversions
inline constexpr Date make_date(int _year, int _month, int _day)
{
  using namespace std__chrono;
  return Date(year(_year), month(_month), day(_day));
}

// date limits
namespace std
{
  template <>
  class numeric_limits<Date>
  {
public:
    static constexpr Date max() noexcept
    {
      return make_date(2199, 12, 31);
      ;
    }
    static constexpr Date min() noexcept
    {
      return make_date(1970, 1, 11);
      ;
    }
  };
}

// until P2592R1 is resolved
namespace std
{

  template <>
  struct hash<Date>
  {
    size_t operator()(const Date& k) const
    {
      return hash<size_t>()(k.operator std__chrono::sys_days().time_since_epoch().count());
    }
  };

}

// date conversions
using struct_tm = struct tm;

template <>
template <>
inline struct_tm to_<struct_tm>::_(const Date& d)
{
  struct tm res
  {
    0, 0, 0, (int)d.day().operator unsigned int(), (int)d.month().operator unsigned int() - 1, (int)d.year() - 1900, 0, 0, 1
#if defined(__GNUC__) && defined(__USE_MISC)
        ,
        0, nullptr
#endif
  };
  return res;
}

template <>
template <>
inline time_t to_<time_t>::_(const struct tm& d)
{
  time_t res;
  struct tm ttm = d;
  res           = mktime(&ttm);
  return res;
}

template <>
template <>
inline struct_tm to_<struct_tm>::_(const time_t& d)
{
  return m_localtime_s(d);
}

template <>
template <>
inline time_t to_<time_t>::_(const Date& d)
{
  time_t res;
  struct tm ttm = to_<struct tm>::_(d);
  res           = mktime(&ttm);
  return res;
}

template <>
template <>
inline Date to_<Date>::_(const time_t& d)
{
  struct tm ttm = to_<struct tm>::_(d);
  Date      res = Date(std__chrono::year(ttm.tm_year + 1900), std__chrono::month(ttm.tm_mon + 1), std__chrono::day(ttm.tm_mday));
  return res;
}

// formatter
template <>
struct fmt::formatter<Date> : formatter<std::string>
{
  // parse is inherited from formatter<string_view>.
  template <typename FormatContext>
  auto format(Date c, FormatContext& ctx)
  {
    auto res = fmt::format("{:04}-{:02}-{:02}", (int)c.year() , (unsigned int)(c.month()) , (unsigned int)c.day() );
    return formatter<std::string>::format(res, ctx);
  }
};

// parser
Date parse_date(std::string_view sv);


inline
Date parse_date(std::string_view sv)
{
    int  year, month, day;
    auto s = sv.data();
    auto f = [&s](int& res, int l, int sk)
    {
        std::from_chars(s, s + l, res);
        s += (l + sk);
    };
    f(year, 4, 1);
    f(month, 2, 1);
    f(day, 2, 1);
    auto ld = Date{ std__chrono::year(year) / std__chrono::month(month) / std__chrono::day(day) };
    return ld;
}

