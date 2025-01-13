#include "stdafx.h"
#include <pair.h>

TEST(cpp_rutils,hash_a_pair)
{
    const std::pair<int, double> toto;
    hash_pair()(toto);
}