#include <catch2/catch_test_macros.hpp>
#include <set.h>

TEST_CASE("set", "[set][hide]")
{

	std::vector<int> v1{ 0,1,2,3 };
	auto s1 = Set(v1);
	std::vector<int> v2{ 0,1,2,0 };
	CHECK_THROWS(SetUnique(v2));
}