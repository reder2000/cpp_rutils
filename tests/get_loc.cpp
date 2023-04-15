#include <catch2/catch_test_macros.hpp>
#include <get_loc.h>
#include <vector_range.h>


TEST_CASE("get_loc_bfill", "[enum][hide]")
{
	auto v = vector_range<double>(11);
	CHECK(get_index_bfill(v, -1.) == 0);
	CHECK(get_index_bfill(v, 0.) == 0);
	CHECK(get_index_bfill(v, 4.) == 4);
	CHECK(get_index_bfill(v, 10.) == 10);
	CHECK(get_index_bfill(v, 4.1) == 5);
	CHECK_THROWS(get_index_bfill(v, 10.1));
}

TEST_CASE("get_loc_ffill", "[enum][hide]")
{
	auto v = vector_range<double>(11);
	CHECK_THROWS(get_index_ffill(v, -1.));
	CHECK(get_index_ffill(v, 0.) == 0);
	CHECK(get_index_ffill(v, 0.1) == 0);
	CHECK(get_index_ffill(v, 2.9) == 2);
	CHECK(get_index_ffill(v, 4.) == 4);
	CHECK(get_index_ffill(v, 4.1) == 4);
	CHECK(get_index_ffill(v, 10.) == 10);
	CHECK(get_index_ffill(v, 11.) == 10);
}
