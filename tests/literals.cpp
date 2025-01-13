#include "stdafx.h"
#include <literals.h>

TEST(cpp_rutils,literals)
{
    EXPECT_TRUE(1_MB == 1024 * 1024);
}