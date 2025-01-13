#include "stdafx.h"
#include <wstring.h>

TEST(cpp_rutils,wstring)
{
	std::wstring wfoo(L"foo");
	std::string foo("foo");
	EXPECT_TRUE( foo == to_strings(wfoo));
	EXPECT_TRUE( foo == to_strings(foo));
	EXPECT_TRUE(to_wstrings(foo) == wfoo);
	EXPECT_TRUE(to_wstrings(wfoo) == wfoo);
}