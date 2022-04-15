#include <catch.hpp>
#include <hashes.h>

TEST_CASE("hash a pair", "[hashes][hide]")
{
    std::pair<int, double> toto;
    hash_pair()(toto);
}