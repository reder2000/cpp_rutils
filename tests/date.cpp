#include <catch2/catch_test_macros.hpp>

#include <date.h>

#include <iostream>

#pragma warning(1: 4996)

TEST_CASE("date", "[require][hide]")
{
	using duration [[maybe_unused]] = std__chrono::utc_clock::duration;
	fmt::print("a date {}", make_date(2022, 2, 2));
}

