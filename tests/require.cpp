#include <catch.hpp>
#include <require.h>
#include <vector>

TEST_CASE("require", "[require][hide]")
{
    auto f = []() { MREQUIRE(true); };
    CHECK_NOTHROW(f());
    auto g = []() { MREQUIRE(false); };
    CHECK_THROWS(g());
}