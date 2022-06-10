#include <catch2/catch_test_macros.hpp>
#include <is_one_of.h>

TEST_CASE("is one of", "[is_one_off][hide]")
{
    static_assert(is_one_of(0, 1, 2, 0, 4));
    static_assert(!is_one_of(3, 1, 2, 0, 4));
}