#include "stdafx.h"
#include <visit.h>
#include <variant>

TEST(cpp_rutils,visit)
{
	using vt = std::variant<int, double>;

	auto get_type= overloaded{
		[](int ) {return "int"; }
		,[](double ){return "double"; } };
	
	vt v = 1;
	EXPECT_TRUE(std::string ("int") == std::visit(get_type, v) );
	v = 2.;
	EXPECT_TRUE(std::string("double") == std::visit(get_type, v) );
}