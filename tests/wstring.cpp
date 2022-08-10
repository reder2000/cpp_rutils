#include <catch2/catch_test_macros.hpp>
#include <wstring.h>

TEST_CASE("wstring", "[is_strictly_sorted][hide]")
{
	std::wstring wfoo(L"foo");
	std::string foo("foo");
	CHECK( foo == to_strings(wfoo));
	CHECK( foo == to_strings(foo));
	CHECK(to_wstrings(foo) == wfoo);
	CHECK(to_wstrings(wfoo) == wfoo);
}