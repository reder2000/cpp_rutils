#include <get_loc.h>
#include <vector_range.h>


TEST(cpp_rutils,get_loc_bfill)
{
	auto v = vector_range<double>(11);
	EXPECT_TRUE(get_index_bfill(v, -1.) == 0);
	EXPECT_TRUE(get_index_bfill(v, 0.) == 0);
	EXPECT_TRUE(get_index_bfill(v, 4.) == 4);
	EXPECT_TRUE(get_index_bfill(v, 10.) == 10);
	EXPECT_TRUE(get_index_bfill(v, 4.1) == 5);
        EXPECT_ANY_THROW(get_index_bfill(v, 10.1));
}

TEST(cpp_rutils,get_loc_ffill)
{
	auto v = vector_range<double>(11);
  EXPECT_ANY_THROW(get_index_ffill(v, -1.));
	EXPECT_TRUE(get_index_ffill(v, 0.) == 0);
	EXPECT_TRUE(get_index_ffill(v, 0.1) == 0);
	EXPECT_TRUE(get_index_ffill(v, 2.9) == 2);
	EXPECT_TRUE(get_index_ffill(v, 4.) == 4);
	EXPECT_TRUE(get_index_ffill(v, 4.1) == 4);
	EXPECT_TRUE(get_index_ffill(v, 10.) == 10);
	EXPECT_TRUE(get_index_ffill(v, 11.) == 10);
}
