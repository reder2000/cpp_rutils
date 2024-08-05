#include "always_false.h"


struct never_false {};

template <>
struct always_false< never_false>
{
	static constexpr bool value = true;
};


TEST(cpp_rutils,always_false) {
static_assert(!always_false<int>::value);
static_assert(always_false<never_false>::value);
static_assert(!always_false_v<int>);
static_assert(always_false_v<never_false>);
}