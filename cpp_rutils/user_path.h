#pragma once

#include <filesystem>

inline
std::filesystem::path get_home_path() {
#if defined(_WIN32)
	return std::filesystem::path(std::getenv("USERPROFILE"));
#else // Linux
	return std::filesystem::path(std::getenv("HOME"));
#endif
}


