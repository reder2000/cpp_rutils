#include <catch2/catch_test_macros.hpp>

#include <date.h>

#include <iostream>

#pragma warning(1: 4996)

TEST_CASE("date", "[require][hide]")
{
	using duration [[maybe_unused]] = std__chrono::utc_clock::duration;
	auto date = make_date(2022, 2, 2);
	auto sdate = fmt::format("{}", date);
	auto date2 = parse_date(sdate);
	CHECK(date == date2);
	auto missed = try_parse_date("totalbs");
	CHECK(!missed.has_value());
	[[maybe_unused]] auto tz = std__chrono::locate_zone("Zulu");
}

