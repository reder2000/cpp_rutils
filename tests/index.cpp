#include <index.h>
#include <array>


TEST(cpp_rutils,index)
{
	std::array<const char*, 2> a = { "toto","tata" };
	EXPECT_TRUE(index_of(a, std::string_view("tata")) == 1);
	EXPECT_TRUE(index_of(a, std::string_view("tutu")) == std::string::npos);
}
