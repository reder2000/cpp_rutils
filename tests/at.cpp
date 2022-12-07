#include <catch2/catch_test_macros.hpp>
#include <throwing/at.h>
#include <map>
#include <unordered_map>
#include <to_string.h>

TEST_CASE("throwing at", "[enum][hide]")
{
	std::map<int, double> m;
	m[1] = 1.;

	CHECK( ( AT(m, 1) ) == 1. );
	std::unordered_map<int, double> um;
	um[1] = 1.;
	// CHECK(at(um, 1) == 1);
	try {
			AT(m, 2);
		}
	catch(const std::exception &e)
	{
		fmt::print("exception {}\n", at_most_n_lines(e.what(),15));
	}
	try {
		AT(um, 2);
	}
	catch (const std::exception& e)
	{
		fmt::print("exception {}\n", at_most_n_lines(e.what(),15));
	}

}
