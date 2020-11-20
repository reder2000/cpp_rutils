#include <catch.hpp>
#include <hashes.h>

TEST_CASE("hash a pair", "[hashes][hide]")
{
    std::pair<int, double> toto;
    auto res = hash_pair()(toto);
}