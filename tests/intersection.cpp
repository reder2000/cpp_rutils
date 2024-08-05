#include <intersection.h>
#include <gtest/gtest-matchers.h>

TEST(cpp_rutils,intersection)
{
	std::vector<int> v1 = { 1,2,3 };
	std::vector<int> v2 = { 2,3,4 };
	std::vector<int> v3 = { 1,3,4 };
	auto res = intersection_vc(v1, v2);
        EXPECT_EQ(res, (std::vector<int>{2, 3}));
	auto res2 = intersection_vc(v1, v2, std::less<>());
	EXPECT_TRUE((res2 == std::vector<int>{ 2, 3 }));
	auto fun = [](int i) {return i * i; };
	auto res3 = intersection_vc_fun(v1, v2, fun);
	EXPECT_TRUE((res3 == std::vector<int>{ 4, 9 }));
	auto res4 = intersection_vcs(v1, v2, v3);
	EXPECT_TRUE(res4 == std::vector<int>{ 3 });
	std::vector < std::reference_wrapper<const std::vector<int>>> vr({ v1,v2,v3 });
	auto res6 = set_intersection(vr);
	EXPECT_TRUE(res6 == std::vector<int>{3});
	std::vector < std::vector<int>> vv({ v1,v2,v3 });
	auto res7 = set_intersection(vv);
	EXPECT_TRUE(res7 == std::vector<int>{3});

}
