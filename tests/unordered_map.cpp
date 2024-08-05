#include <unordered_map.h>


TEST(cpp_rutils,unordered_map)
{
	um<int, double> map;
	map[1] = 2.;
}


TEST(cpp_rutils,unordered_map_callback)
{
	um_cp<int, double> map;
	map[1] = 2.;
	EXPECT_TRUE(map.at(1) == 2);
	auto fns = [](double d) {return d * d; };
	EXPECT_TRUE(map.find_or_add(1, fns, 2) == 2.);
	EXPECT_TRUE(map.find_or_add(2, fns, 2) == 4.);
	auto fnc = []() {return 3.; };
	EXPECT_TRUE(map.find_or_add(-3, fnc) == 3.);
    [[maybe_unused]] auto& v = map[10];
}

TEST(cpp_rutils,default_dict)
{
	// auto dd = make_default_dict<std::string, size_t>::make([](auto&& self) {return self.size(); });
	default_dict<std::string, size_t> dd([](auto&& self) {return self.size(); });
	dd["1"];
	dd["2"];
    [[maybe_unused]] bool res  = dd["2"] == 1;
}

TEST(cpp_rutils,ump)
{
	um_p<int, int> m;
	m[1] = 1;
	m[2] = 2;
        EXPECT_THROW(m.at(3), std::out_of_range);
	try {
		m.at(3);
	}
	catch (const std::exception& e)
	{
		std__print("exception {}\n", e.what());
	}
}