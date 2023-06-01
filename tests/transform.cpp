#include <catch2/catch_test_macros.hpp>
#include <transform.h>

TEST_CASE("transform", "[transform][hide]")
{
  std::vector<int> v{0, 1, 2, 3};

  auto to_string = [&](int i) -> std::string { return std::to_string(i); };

  auto w = transform_vc(v, to_string);

  CHECK(std::string("2") == w[2]);

  auto ww = List(to_string, v);

  CHECK(std::string("3") == ww[3]);

  CHECK(List_if(v, [](int i) { return i % 2 == 1; }) == std::vector<int>{1, 3});

  CHECK(contains(v, 2));
  CHECK(! contains(v, 10));
  CHECK(contains_if(v, [](auto&& x) { return x == 2; }));
  CHECK(! contains_if(v, [](auto&& x) { return x == 10; }));

  std::vector<int> cc{4, 5, 6};
  concat(v, std::move(cc));
  CHECK(v.at(6) == 6);
  std::vector<int> dd{7, 8};
  auto             vv = concat(v, dd);
  CHECK(vv.at(8) == 8);
  CHECK(v.size() == 7);

  std::vector<int> v1{0, 1, 2, 3};
  std::vector<int> v2;
  Do([&v2](int i) { v2.push_back(i); }).ForEach(v1).And().For(4);
  CHECK(v2 == std::vector<int>{0, 1, 2, 3, 4});
  Do([](int& i) { i *= i; }).ForEach(v2);
  CHECK(v2 == std::vector<int>{0, 1, 4, 9, 16});
  std::vector<int> v3;
  Do([&v3](int i) { v3.push_back(i); }).ForEach(v1).And([](int& i) { i *= i; }).ForEach(v3);
  CHECK(v3 == std::vector<int>{0, 1, 4, 9});
  std::vector<int> v4;
  Do([&v4](int i, int n) { v4.push_back(pow(i, n)); }).ForEach(v1, 3).And().For(4, 2);
  CHECK(v4 == std::vector<int>{0, 1, 8, 27, 16});
}