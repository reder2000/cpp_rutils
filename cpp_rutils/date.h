#pragma once

// header for portable c++20 calendar 
#include "config.h"

#include <chrono>

#if defined(HAVE_CXX20_CHRONO)
#define std__chrono std::chrono
#else
#include <date/date.h>
#include <date/tz.h>
#define std__chrono date
#endif

#include "secure_deprecate.h"
#include "to_.h"


using Date = std__chrono::year_month_day;

inline constexpr Date make_date(int _year, int _month, int _day)
{
  using namespace std__chrono;
  return Date(year(_year), month(_month), day(_day));
}

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

namespace std
{

  template <>
  struct hash<Date>
  {
    std::size_t operator()(const Date& k) const
    {
      using std::hash;
      using std::size_t;
      using std::string;

      // Compute individual hash values for first,
      // second and third and combine them using XOR
      // and bit shifting:

      //return ((hash<string>()(k.first) ^ (hash<string>()(k.second) << 1)) >> 1) ^ (hash<int>()(k.third) << 1);
      //return hash<size_t>()(k.time_since_epoch().count());
      return hash<size_t>()(k.operator std__chrono::sys_days().time_since_epoch().count());
    }
  };

}

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
  //struct tm ttm = to_<struct tm>::_(d);
  struct tm ttm = d;
  res           = mktime(&ttm);
  return res;
}

template <>
template <>
inline struct_tm to_<struct_tm>::_(const time_t& d)
{
  return m_localtime_s(d);
  //struct tm res;
  //localtime_s(&res,&d);
  //return res;
}

template <>
template <>
inline time_t to_<time_t>::_(const Date& d)
{
  time_t res;
  //  auto dr = d.operator std::chrono::sys_days().time_since_epoch();
  struct tm ttm = to_<struct tm>::_(d);
  res           = mktime(&ttm);
  // res = std__chrono::system_clock::to_time_t(d.time_since_epoch());
  //auto ds = std__chrono::duration_cast<std__chrono::seconds>(d.time_since_epoch());
  //auto ds = std__chrono::duration_cast<std__chrono::seconds>(dr);
  //res     = ds.count();
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
