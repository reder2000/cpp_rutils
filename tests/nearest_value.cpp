#include "nearest_value.h"



TEST(cpp_rutils,nearest_value)
{
  auto   v = vector_range(0., 10., 0.5);
  size_t i = find_nearest_value(0.5, v);
  EXPECT_TRUE(v[i] == 0.5);
  i = find_nearest_value(0.49, v);
  EXPECT_TRUE(v[i] == 0.5);
  i = find_nearest_value(0.51, v);
  EXPECT_TRUE(v[i] == 0.5);
  i = find_nearest_value(0.01, v);
  EXPECT_TRUE(v[i] == 0.);
  i = find_nearest_value(-0.51, v);
  EXPECT_TRUE(v[i] == 0.);
  i = find_nearest_value(9.49, v);
  EXPECT_TRUE(v[i] == 9.5);
  i = find_nearest_value(100, v);
  EXPECT_TRUE(v[i] == 9.5);
  i = find_nearest_value(5.0, v);
  EXPECT_TRUE(i == 10);
}

TEST(cpp_rutils,nearest_value2)
{
  auto                v = vector_range(0., 10., 0.5);
  auto                w = find_nearest_values(3, 5.0, v);
  std::vector<size_t> w2{10, 9, 11};
  EXPECT_TRUE(w == w2);
  w = find_nearest_values(3, 5.01, v);
  std::vector<size_t> w3{10, 11, 9};
  EXPECT_TRUE(w == w3);
  w = find_nearest_values(3, 1.01, v);
  std::vector<size_t> w4{2, 3, 1};
  EXPECT_TRUE(w == w4);
  w = find_nearest_values(3, -1.01, v);
  std::vector<size_t> w5{0, 1, 2};
  EXPECT_TRUE(w == w5);
  w = find_nearest_values(3, 9.4, v);
  std::vector<size_t> w6{19, 18, 17};
  EXPECT_TRUE(w == w6);
  w = find_nearest_values(3, 9.1, v);
  std::vector<size_t> w7{18, 19, 17};
  EXPECT_TRUE(w == w7);
}


TEST(cpp_rutils,nearest_value3)
{
  std::vector<std::string> v{"a", "b", "c", "d", "e", "f"};
  auto i = find_nearest_value(100.1, v, [](const std::string &s) { return static_cast<double>(s[0]); });
  EXPECT_TRUE(v[i] == "d");
  auto w = find_nearest_values(3, 100.1, v, [](const std::string &s) { return static_cast<double>(s[0]); });
  EXPECT_TRUE((w == std::vector<size_t>{3, 4, 2}));
}