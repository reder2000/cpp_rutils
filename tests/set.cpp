#include <catch2/catch_test_macros.hpp>
#include <set.h>

TEST_CASE("set", "[set][hide]")
{

	std::vector<int> v1{ 0,1,2,3 };
	auto s1 = Set(v1);
	std::vector<int> v2{ 0,1,2,0 };
	CHECK_THROWS(SetUnique(v2));
}

TEST_CASE("map", "[map][hide]")
{

	std::vector<int> v1{ 0,1,2,4 };
	auto s1 = Dict(v1,[](int i){return i*i;});
	CHECK(s1[3]==16);
	auto s2 = DictSelf<int>(v1,[](auto &&a,int){return a.size();});
	CHECK(s2[3]==3);
}
