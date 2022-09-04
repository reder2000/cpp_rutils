#include <catch2/catch_test_macros.hpp>
#include <pair.h>

TEST_CASE("hash a pair", "[hashes][hide]")
{
    const std::pair<int, double> toto;
    hash_pair()(toto);
}