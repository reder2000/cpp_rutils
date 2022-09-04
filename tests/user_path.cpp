#include "user_path.h"

#include <catch2/catch_test_macros.hpp>
#include <fmt/std.h>

TEST_CASE("user_path", "[mem][hide]") {
		auto foo = get_home_path();
	fmt::print("{}", foo);
}