#include "stdafx.h"

#include <date.h>

#include <iostream>

#pragma warning(1: 4996)

TEST(cpp_rutils,date)
{
	using duration [[maybe_unused]] = std__chrono::utc_clock::duration;
	auto date = make_date(2022, 2, 2);
	auto sdate = std__format("{}", date);
	auto date2 = parse_date(sdate);
	EXPECT_TRUE(date == date2);
	auto missed = try_parse_date("totalbs");
	EXPECT_TRUE(!missed.has_value());
	[[maybe_unused]] auto tz = std__chrono::locate_zone("Zulu");
        [[maybe_unused]] auto y2012 = 2012_y;
        [[maybe_unused]] auto d10 = 10_d;
}

