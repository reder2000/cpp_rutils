#include "always_false.h"

#include <catch2/catch_test_macros.hpp>

struct never_false {};

template <>
struct always_false< never_false>
{
	static constexpr bool value = true;
};


TEST_CASE("always_false", "[mem][hide]") {
static_assert(!always_false<int>::value);
static_assert(always_false<never_false>::value);
static_assert(!always_false_v<int>);
static_assert(always_false_v<never_false>);
}