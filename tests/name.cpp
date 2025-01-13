#include "stdafx.h"
#include <name.h>


TEST(cpp_rutils,name)
{
    EXPECT_TRUE(type_name<double>() == "double");
}

