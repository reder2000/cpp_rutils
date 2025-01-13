#include "stdafx.h"
#include <to_.h>

struct To {
	int a;
};

struct From {
	int a;
	operator To() const { return To{ a }; }
};

TEST(cpp_rutils,to)
{
	const From from{ 1 };
	const To to = to_<To>::_(from);
	EXPECT_TRUE(to.a == 1);
	//	 to_<From>::_(to);
}