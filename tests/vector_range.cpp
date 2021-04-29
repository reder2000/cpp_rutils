#include <catch.hpp>
#include <vector_range.h>


TEST_CASE("vector_range", "[enum][hide]")
{
    auto v1 = vector_range(12);
    CHECK(v1[1] == 1);
    auto v2 = vector_range<size_t>(12);
    CHECK(v2[1] == 1);
    auto v3 = vector_range<size_t>(12,16);
    CHECK(v3[1] == 13);
    auto v4 = vector_range<size_t>(42, 16, -3);
    CHECK(v4[1] == 39);
    auto v5= []() { vector_range<size_t>(42, 16, 3); };
    CHECK_THROWS(v5());
    auto v6 = vector_range<size_t>(16, 42, 3);
    CHECK(v6[1] == 19);
    auto v7 = []() { vector_range<size_t>(16, 42, -3); };
    CHECK_THROWS(v7());
}
