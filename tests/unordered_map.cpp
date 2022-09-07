#include <catch2/catch_test_macros.hpp>
#include <unordered_map.h>


TEST_CASE("unordered_map", "[enum][hide]")
{
	um<int, double> map;
	map[1] = 2.;
}


TEST_CASE("unordered_map_callback", "[enum][hide]")
{
	um_cp<int, double> map;
	map[1] = 2.;
	CHECK(map.at(1) == 2);
	auto fns = [](double d) {return d * d; };
	CHECK(map.find_or_add(1, fns, 2) == 2.);
	CHECK(map.find_or_add(2, fns, 2) == 4.);
	auto fnc = []() {return 3.; };
	CHECK(map.find_or_add(-3, fnc) == 3.);
	auto& v = map[10];
}

TEST_CASE("default_dict", "[enum][hide]")
{
	// auto dd = make_default_dict<std::string, size_t>::make([](auto&& self) {return self.size(); });
	default_dict<std::string, size_t> dd([](auto&& self) {return self.size(); });
	dd["1"];
	dd["2"];
	bool res  = dd["2"] == 1;
}