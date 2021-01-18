#include <catch.hpp>
#include <require.h>
#include <vector>

TEST_CASE("require", "[require][hide]")
{
    auto f = []() { MREQUIRE(true); };
    CHECK_NOTHROW(f());
    auto g = []() { MREQUIRE(false); };
    CHECK_THROWS(g());
    auto h = []() { MREQUIRE_EQUAL(1,2); };
    CHECK_THROWS(h());
    auto i = []() { MREQUIRE_EQUAL(1, 1); };
    CHECK_NOTHROW(i());
}