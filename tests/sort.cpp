#include <sort.h>

#include <vector>

TEST(cpp_rutils,sort)
{
    std::vector<double> v{ 1.,2.,3.,4. };
    std::vector<double> w{ 4.,2.,1.,3. };

    EXPECT_TRUE(sort(std::move(w)) == v);
}

TEST(cpp_rutils,sort2)
{
    std::vector<double> v{ 4.,3.,2.,1. };
    std::vector<double> w{ 4.,2.,1.,3. };

    EXPECT_TRUE(sort(std::move(w),std::greater<>()) == v);
}

