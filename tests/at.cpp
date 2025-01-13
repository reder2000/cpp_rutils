#include "stdafx.h"
#include <throwing/at.h>
#include <map>
#include <unordered_map>
#include <to_string.h>

TEST(cpp_rutils,throwing_at)
{
	std::map<int, double> m;
	m[1] = 1.;

	EXPECT_TRUE( ( AT(m, 1) ) == 1. );
	std::unordered_map<int, double> um;
	um[1] = 1.;
	// EXPECT_TRUE(at(um, 1) == 1);
	try {
			AT(m, 2);
		}
	catch(const std::exception &e)
	{
		std__print("exception {}\n", at_most_n_lines(e.what(),15));
	}
	try {
		AT(um, 2);
	}
	catch (const std::exception& e)
	{
		std__print("exception {}\n", at_most_n_lines(e.what(),15));
	}

}
