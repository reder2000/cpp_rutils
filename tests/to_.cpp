#include <to_.h>
#include <catch2/catch_test_macros.hpp>
#include <concepts>

struct To {
	int a;
};

struct From {
	int a;
	operator To() const { return To{ a }; }
};

TEST_CASE("to_", "[require][hide]")
{
 From from{ 1 };
	To to = to_<To>::_(from);
	REQUIRE(to.a == 1);
	//	 to_<From>::_(to);
}