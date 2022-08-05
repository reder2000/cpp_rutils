#include "user_path.h"

#include <catch2/catch_test_macros.hpp>

#include <filesystem>

#include <iostream>

std::filesystem::path get_home_path() {
#if defined(_WIN32)
	return std::filesystem::path(std::getenv("USERPROFILE"));
#else // Linux
	return std::filesystem::path(std::getenv("HOME"));
#endif
}



TEST_CASE("user_path", "[mem][hide]") {
	auto foo = get_home_path();
	std::cout << foo << std::endl;
}