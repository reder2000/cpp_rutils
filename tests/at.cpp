#include <catch2/catch_test_macros.hpp>
#include <throwing/at.h>
#include <map>

TEST_CASE("throwing at", "[enum][hide]")
{
	std::map<int, double> m;
	m[1] = 1.;
		at(m, 1);
		try {
			at(m, 2);
		}
	catch(const std::exception &e)
	{
		fmt::print("exception {}\n", e.what());
	}

}
