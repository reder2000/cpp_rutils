#include "stdafx.h"
#include <set.h>

TEST(cpp_rutils,set)
{

	std::vector<int> v1{ 0,1,2,3 };
	auto s1 = Set(v1);
	std::vector<int> v2{ 0,1,2,0 };
        EXPECT_ANY_THROW(SetUnique(v2));
}

TEST(cpp_rutils,map)
{

	std::vector<int> v1{ 0,1,2,4 };
	auto s1 = Dict(v1,[](int i){return i*i;});
	EXPECT_TRUE(s1[4]==16);
	auto s2 = DictSelf<int>(v1,[](auto &&a,int){return a.size();});
	EXPECT_TRUE(s2[4]==3);
}
