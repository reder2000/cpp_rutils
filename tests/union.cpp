#include <union.h>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("union", "[union][hide]")
{
	std::vector<int> v1 = { 1,2,3 };
	std::vector<int> v2 = { 2,3,4 };
	std::vector<int> v3 = { 1,3,4 };
	auto res = union_vc(v1, v2);
	CHECK(res == std::vector<int>{ 1, 2, 3, 4 });
	auto res2 = union_vc(v1, v2, std::less<>());
	CHECK(res2 == std::vector<int>{ 1, 2, 3, 4});
	auto fun = [](int i) {return i * i; };
	auto res3 = union_vc_fun(v1, v2, fun);
	CHECK(res3 == std::vector<int>{ 1, 4, 9, 16 });
	auto res4 = union_vcs(v1, v2, v3);
	CHECK(res4 == std::vector<int>{ 1, 2, 3, 4 });
	std::vector < std::reference_wrapper<const std::vector<int>>> vr({ v1,v2,v3 });
	auto res5 = set_union(vr);
	CHECK(res5 == std::vector<int>{1, 2, 3, 4 });
	std::vector < std::vector<int>> vv({ v1,v2,v3 });
	auto res7 = set_union(vv);
	CHECK(res7 == std::vector<int>{1, 2, 3, 4});

}
