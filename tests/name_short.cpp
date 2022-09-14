#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_test_macros.hpp>
#include <name_short.h>

#include <unordered_map>


TEST_CASE("short_name_vector", "[name][hide]")
{

	std::vector<int> toto;
	std::cout << type_name_short<decltype(toto)>() << std::endl;
	std::vector<std::vector<int>> tototo;
	std::cout << type_name_short<decltype(tototo)>() << std::endl;
	std::unordered_map<int, decltype(tototo)> tata;
	std::cout << type_name_short<decltype(tata)>() << std::endl;
}
