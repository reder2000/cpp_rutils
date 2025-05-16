#pragma once

#include <cstddef>
#include <cstdint>

// size_t literal
constexpr size_t operator""_uz(unsigned long long n)
{
  return n;
}


constexpr unsigned char operator""_uchar(char arg) noexcept
{
  return static_cast<unsigned char>(arg);
}

// byte/megabyte/.... literals

// g++ not happy with uint64_t
#if defined(__GNUC__)
using my_uint64_t = unsigned long long;
#else
using my_uint64_t = uint64_t;
#endif

constexpr my_uint64_t operator""_B(my_uint64_t bytes)
{
  return bytes;
}
constexpr my_uint64_t operator""_kB(my_uint64_t kilo_bytes)
{
  return 1024 * kilo_bytes;
}
constexpr my_uint64_t operator""_MB(my_uint64_t mega_bytes)
{
  return 1024_kB * mega_bytes;
}
constexpr my_uint64_t operator""_GB(my_uint64_t giga_bytes)
{
  return 1024_MB * giga_bytes;
}
constexpr double operator""_pct(long double d)
{
  return 0.01 * static_cast<double>(d);
}
constexpr double operator""_bps(long double d)
{
  return 0.0001 * static_cast<double>(d);
}