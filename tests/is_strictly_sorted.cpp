#include <catch2/catch_test_macros.hpp>
#include <is_strictly_sorted.h>
#include <throwing/is_strictly_sorted.h>
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

struct stupid {
    stupid() = default;
	stupid(int i) : _i(i) {}
	bool operator<(stupid const& other) const { return _i < other._i; }
	int _i;
};


TEST_CASE("throwing is strictly sorted", "[throwing_is_strictly_sorted][hide]")
{
    std::vector<double> v{ 1.,2.,3.,4. };
    std::vector<double> w{ 1.,2.,2.,3. };
    CHECK(throwing::is_strictly_sorted(v.begin(), v.end()));
    CHECK_THROWS(throwing::is_strictly_sorted(w.begin(), w.end()));
    std::vector<stupid> z{ 1,2,2,3 };
    CHECK_THROWS(throwing::is_strictly_sorted(z.begin(), z.end()));
}