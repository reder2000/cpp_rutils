#include <catch2/catch_test_macros.hpp>
#include <transform.h>

TEST_CASE("transform", "[transform][hide]")
{

	std::vector<int> v{ 0,1,2,3 };

	auto to_string = [&](int i)->std::string { return std::to_string(i);  };
	
	auto w = transform_vc(v, to_string);

	CHECK(std::string("2") == w[2] );

	auto ww = List(to_string, v);

	CHECK(std::string("3") == ww[3]);

	CHECK(List_if(v, [](int i) {return i % 2 == 1; }) == std::vector<int>{1, 3});

	CHECK(contains(v, 2));
	CHECK(!contains(v, 10));
	CHECK(contains_if(v, [](auto&& x) {return x == 2; }));
	CHECK(!contains_if(v, [](auto&& x) {return x == 10; }));

	std::vector<int> cc{ 4,5,6 };
	concat(v, std::move(cc));
	CHECK(v.at(6) == 6);
	std::vector<int> dd{ 7,8 };
	auto vv = concat(v, dd);
	CHECK(vv.at(8) == 8);
	CHECK(v.size() == 7);
}