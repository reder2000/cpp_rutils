#include <catch.hpp>
#include <name.h>

TEST_CASE("name", "[name][hide]")
{
    CHECK(type_name<double>() == "double");
}