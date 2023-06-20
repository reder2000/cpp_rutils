#include "nearest_value.h"

#include <catch2/catch_test_macros.hpp>


TEST_CASE("nearest_value", "[mem][hide]")
{
  auto   v = vector_range(0., 10., 0.5);
  size_t i = find_nearest_value(0.5, v);
  CHECK(v[i] == 0.5);
  i = find_nearest_value(0.49, v);
  CHECK(v[i] == 0.5);
  i = find_nearest_value(0.51, v);
  CHECK(v[i] == 0.5);
  i = find_nearest_value(0.01, v);
  CHECK(v[i] == 0.);
  i = find_nearest_value(-0.51, v);
  CHECK(v[i] == 0.);
  i = find_nearest_value(9.49, v);
  CHECK(v[i] == 9.5);
  i = find_nearest_value(100, v);
  CHECK(v[i] == 9.5);
  i = find_nearest_value(5.0, v);
  CHECK(i == 10);
}

TEST_CASE("nearest_value2", "[mem][hide]")
{
  auto                v = vector_range(0., 10., 0.5);
  auto                w = find_nearest_values(3, 5.0, v);
  std::vector<size_t> w2{10, 9, 11};
  CHECK(w == w2);
  w = find_nearest_values(3, 5.01, v);
  std::vector<size_t> w3{10, 11, 9};
  CHECK(w == w3);
  w = find_nearest_values(3, 1.01, v);
  std::vector<size_t> w4{2, 3, 1};
  CHECK(w == w4);
  w = find_nearest_values(3, -1.01, v);
  std::vector<size_t> w5{0, 1, 2};
  CHECK(w == w5);
  w = find_nearest_values(3, 9.4, v);
  std::vector<size_t> w6{19, 18, 17};
  CHECK(w == w6);
  w = find_nearest_values(3, 9.1, v);
  std::vector<size_t> w7{18, 19, 17};
  CHECK(w == w7);
}


TEST_CASE("nearest_value3", "[mem][hide]")
{
  std::vector<std::string> v{"a", "b", "c", "d", "e", "f"};
  auto i = find_nearest_value(100.1, v, [](const std::string &s) { return static_cast<double>(s[0]); });
  CHECK(v[i] == "d");
  auto w = find_nearest_values(3, 100.1, v, [](const std::string &s) { return static_cast<double>(s[0]); });
  CHECK(w == std::vector<size_t>{3, 4, 2});
}