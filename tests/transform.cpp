#include <catch.hpp>
#include <transform.h>
#include <cstdlib>

TEST_CASE("transform", "[transform][hide]")
{

	std::vector<int> v{ 0,1,2,3 };

	char buffer[256];
	auto to_string = [&](int i)->std::string { return std::to_string(i);  };
	
	auto w = transform_vc(v, to_string);

	CHECK(std::string("2") == w[2] );
}