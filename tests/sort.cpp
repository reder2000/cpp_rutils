#include <catch2/catch_test_macros.hpp>
#include <sort.h>

#include <vector>

TEST_CASE("sort", "[sort][hide]")
{
    std::vector<double> v{ 1.,2.,3.,4. };
    std::vector<double> w{ 4.,2.,1.,3. };

    CHECK(sort(w) == v);
}

TEST_CASE("sort2", "[sort][hide]")
{
    std::vector<double> v{ 4.,3.,2.,1. };
    std::vector<double> w{ 4.,2.,1.,3. };

    CHECK(sort(w,std::greater<double>()) == v);
}

