#include <catch.hpp>
#include <is_strictly_sorted.h>
#include <vector>

TEST_CASE("is strictly sorted", "[is_strictly_sorted][hide]")
{
    std::vector<double> v{ 1.,2.,3.,4. };
    std::vector<double> w{ 1.,2.,2.,4. };

    CHECK(is_strictly_sorted(v.begin(), v.end()));
    CHECK(!is_strictly_sorted(w.begin(), w.end()));
    CHECK(is_strictly_sorted_until(v.begin(), v.end()) == v.end());
    CHECK(is_strictly_sorted_until(w.begin(), w.end()) == w.begin()+1);
}