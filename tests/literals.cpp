#include <catch2/catch_test_macros.hpp>
#include <literals.h>

TEST_CASE("literals", "[name][hide]")
{
    CHECK(1_MB == 1024 * 1024);
}