#include <catch2/catch_test_macros.hpp>
#include <data_frame.h>

TEST_CASE("dataframe", "[name][hide]")
{
  LightMatrix<double>      data(3, 2);
  std::vector<int>         index(3);
  std::vector<std::string> columns(2);

  auto             lm = make_LightDataFrame(data, index, columns);
  std::vector<int> bad_index(2);
  CHECK_THROWS([&]() { auto blm = make_LightDataFrame(data, bad_index, columns); }());
  std::vector<std::string> bad_columns(3);
  CHECK_THROWS([&]() { auto blm = make_LightDataFrame(data, index, bad_columns); }());
}


TEST_CASE("dataframe_dropna", "[name][hide]")
{
  std::vector v{std::vector{1., 2., 3.}, std::vector{11., 12., 13.}, std::vector{21., 22., 23.},
                std::vector{31., 32., 33.}};
  LightMatrix<double>      data(v);
  std::vector<int>         index{1, 2, 3, 4};
  std::vector<std::string> columns{"A", "B", "C"};
  auto                     ldf = make_LightDataFrame(data, index, columns);

  std::vector<double>       empty_row_v(3, std::numeric_limits<double>::quiet_NaN());
  std::span<const double>   empty_row{empty_row_v.data(), 3};
  std::vector<double>       empty_col_v(4 * 3, std::numeric_limits<double>::quiet_NaN());
  SliceVector<const double> empty_col(std::addressof(empty_col_v[0]), 4, 3);

  auto data2 = data;
  data2.assign_row(2, empty_row);
  auto ldf2 = make_LightDataFrame(data2, index, columns).dropna(Axis::index);
  CHECK(ldf2._index == std::vector<int>{1, 2, 4});

  auto data3 = data;
  data3.assign_col(2, empty_col);
  auto ldf3 = make_LightDataFrame(data3, index, columns).dropna(Axis::column);
  CHECK(ldf3._columns == std::vector<std::string>{"A", "B"});
}
