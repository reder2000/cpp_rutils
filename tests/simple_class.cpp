#include <catch2/catch_test_macros.hpp>
#include <simple_class.h>
#include <string_literal.h>
#include <always_false.h>
#include <require.h>
#include <optional>

#define SimpleClass_tuple ((int,i,0),(double,d,2.))

struct SimpleClass
{
	EMIT_SIMPLE_CLASS_DECLARE_ALL(SimpleClass)
};


TEST_CASE("SimpleClass", "[enum][hide]")
{
	SimpleClass sc;
	CHECK(sc._d == 2.);
	sc._i = 12;
	sc._d = 3.14;
}
