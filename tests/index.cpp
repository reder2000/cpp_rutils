#include <catch2/catch_test_macros.hpp>
#include <index.h>
#include <array>


TEST_CASE("index", "[enum][hide]")
{
	std::array<const char*,2> a = { "toto","tata" };
	CHECK(index(a,std::string_view("tata")) == 1);
	CHECK(index(a, std::string_view("tutu")) == std::string::npos);
}
