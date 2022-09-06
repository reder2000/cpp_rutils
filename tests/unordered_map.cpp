#include <catch2/catch_test_macros.hpp>
#include <unordered_map.h>


TEST_CASE("unordered_map", "[enum][hide]")
{
	um<int, double> map;
	map[1] = 2.;
}

