#include <catch.hpp>
#include <visit.h>
#include <variant>

TEST_CASE("visit", "[is_strictly_sorted][hide]")
{
	using vt = std::variant<int, double>;

	auto get_type= overloaded{
		[](int ) {return "int"; }
		,[](double ){return "double"; } };
	
	vt v = 1;
	CHECK(std::string ("int") == std::visit(get_type, v) );
	v = 2.;
	CHECK(std::string("double") == std::visit(get_type, v) );
}