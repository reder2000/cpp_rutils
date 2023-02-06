#include <catch2/catch_test_macros.hpp>
#include <ssize_t.h>


TEST_CASE("ssize_t", "[enum][hide]")
{
	ssize_t test = -1;
	CHECK(test == -1);
}

