#include <catch2/catch_test_macros.hpp>
#include <name.h>

TEST_CASE("name", "[name][hide]")
{
    CHECK(type_name<double>() == "double");
}