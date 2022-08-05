#pragma once

#include <filesystem>
#include <fmt/format.h>
#include "secure_deprecate.h"

inline
std::filesystem::path get_home_path() {
#if defined(_WIN32)
	return std::filesystem::path(getenv("USERPROFILE"));
#else
    return std::filesystem::path(m_getenv_s("HOME"));
#endif
}


template <>
struct fmt::formatter<std::filesystem::path> : formatter<std::string>
{
    // parse is inherited from formatter<string_view>.
    template <typename FormatContext>
    auto format(std::filesystem::path c, FormatContext& ctx)
    {
        std::stringstream ss;
        ss << c;
        return formatter<std::string>::format(ss.str(), ctx);
    }
};
