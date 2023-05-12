#include <catch2/catch_test_macros.hpp>
#include <data_frame.h>

TEST_CASE("dataframe", "[name][hide]")
{
  LightMatrix<double>      data(3, 2);
  std::vector<int>         index(3);
  std::vector<std::string> columns(2);

  auto             lm = make_LighDataFrame(data, index, columns);
  std::vector<int> bad_index(2);
  CHECK_THROWS([&]() { auto blm = make_LighDataFrame(data, bad_index, columns); }());
  std::vector<std::string> bad_columns(3);
  CHECK_THROWS([&]() { auto blm = make_LighDataFrame(data, index, bad_columns); }());
}
