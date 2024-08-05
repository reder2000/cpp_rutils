#include <vector_range.h>


TEST(cpp_rutils,vector_range)
{
    auto v1 = vector_range(12);
    EXPECT_TRUE(v1[1] == 1);
    auto v2 = vector_range<size_t>(12);
    EXPECT_TRUE(v2[1] == 1);
    auto v3 = vector_range<size_t>(12,16);
    EXPECT_TRUE(v3[1] == 13);
    auto v4 = vector_range<size_t>(42, 16, -3);
    EXPECT_TRUE(v4[1] == 39);
    auto v5= []() { vector_range<size_t>(42, 16, 3); };
    EXPECT_ANY_THROW(v5());
    auto v6 = vector_range<size_t>(16, 42, 3);
    EXPECT_TRUE(v6[1] == 19);
    auto v7 = []() { vector_range<size_t>(16, 42, -3); };
    EXPECT_ANY_THROW(v7());
}
