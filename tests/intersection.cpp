#include <intersection.h>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("intersection", "[intersection][hide]")
{
	std::vector<int> v1 = { 1,2,3 };
	std::vector<int> v2 = { 2,3,4 };
	auto res = intersection_vc(v1, v2);
	CHECK(res == std::vector<int>{ 2, 3 });
	auto res2= intersection_vc(v1, v2, std::less<int>());
	CHECK(res2 == std::vector<int>{ 2, 3 });
	auto fun = [](int i) {return i*i;};
	auto res3 = intersection_vc_fun(v1,v2,fun);
	CHECK(res3 == std::vector<int>{ 4, 9 });

}
 