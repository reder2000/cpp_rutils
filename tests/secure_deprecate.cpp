#include <catch2/catch_test_macros.hpp>

#pragma warning(1: 4996)

#include <secure_deprecate.h>

#include <iostream>

#pragma warning(1: 4996)

TEST_CASE("secure_deprecate_strerror", "[require][hide]")
{
	std::cout << m_strerror_s(0) << std::endl;
	
}

TEST_CASE("secure_deprecate_localtime", "[require][hide]")
{
	time_t tt;
	time(&tt);
	m_localtime_s(tt);
}