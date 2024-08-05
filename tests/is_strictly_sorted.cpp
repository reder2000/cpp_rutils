#include <is_strictly_sorted.h>
#include <throwing/is_strictly_sorted.h>
#include <vector>

TEST(cpp_rutils,is_strictly_sorted)
{
    std::vector<double> v{ 1.,2.,3.,4. };
    std::vector<double> w{ 1.,2.,2.,4. };

    EXPECT_TRUE(is_strictly_sorted(v.begin(), v.end()));
    EXPECT_TRUE(!is_strictly_sorted(w.begin(), w.end()));
    EXPECT_TRUE(is_strictly_sorted_until(v.begin(), v.end()) == v.end());
    EXPECT_TRUE(is_strictly_sorted_until(w.begin(), w.end()) == w.begin()+1);
}

struct stupid {
    stupid() = default;
	stupid(int i) : _i(i) {}
	bool operator<(stupid const& other) const { return _i < other._i; }
	int _i;
};


TEST(cpp_rutils,throwing_is_strictly_sorted)
{
    std::vector<double> v{ 1.,2.,3.,4. };
    std::vector<double> w{ 1.,2.,2.,3. };
    EXPECT_TRUE(throwing::is_strictly_sorted(v.begin(), v.end()));
    EXPECT_ANY_THROW(throwing::is_strictly_sorted(w.begin(), w.end()));
    std::vector<stupid> z{ 1,2,2,3 };
    EXPECT_ANY_THROW(throwing::is_strictly_sorted(z.begin(), z.end()));
}