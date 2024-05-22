#pragma once

// portable way to get home path

#include <filesystem>
#include "secure_deprecate.h"

inline std::filesystem::path get_home_path()
{
#if defined(_WIN32)
  return std::filesystem::path{m_getenv_s("USERPROFILE")};
#else
  return std::filesystem::path{m_getenv_s("HOME")};
#endif
}

inline std::filesystem::path get_data_path()
{
  return get_home_path() / "tmp" / "data";
}
// fmt interface to path
// should be in fmt/std

#if ! defined(HAVE_CXX26_STD_FORMAT_PATH)
template <>
struct std__formatter<std::filesystem::path> : formatter<std::string>
{
    // parse is inherited from formatter<string_view>.
    template <typename FormatContext>
    auto format(std::filesystem::path c, FormatContext& ctx) const
    {
        std::stringstream ss;
        ss << c;
        return formatter<std::string>::format(ss.str(), ctx);
    }
};
#endif