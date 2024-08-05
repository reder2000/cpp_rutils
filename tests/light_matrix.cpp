#include <light_matrix.h>


template <class T>
bool is_equal(std::span<const T> s, const std::vector<T>& v)
{
  std::vector<T> sv(v.begin(), v.end());
  return sv == v;
}


TEST(cpp_rutils,light_matrix)
{
  std::vector<int> e{1, 2, 3, 4, 5, 6};
  LightMatrix<int> m(std::move(e), size_t(2), size_t(3));
  EXPECT_TRUE(m(1, 2) == 6);
  EXPECT_ANY_THROW(m.at(2, 3));
  std::vector<int> e2{1, 2, 3, 4, 5, 6};
  LightMatrix<int> m2(std::move(e2), size_t(2), size_t(3));
  EXPECT_TRUE(m == m2);
  std::vector<int> e3{1, 2, 3, 4, 5, 6};
  LightMatrix<int> m3(std::move(e3), size_t(3), size_t(2));
  EXPECT_TRUE(m3(2, 1) == 6);
  EXPECT_TRUE(m != m3);
  std::vector<int> aa{1, 2, 3};
  std::vector<int> r{14, 32};
  EXPECT_TRUE(m * aa == r);
  std::vector<int> aa2{2, 4, 6};
  EXPECT_TRUE(mult(aa, 2) == aa2);
  EXPECT_TRUE(is_equal(m3.get_row_view(1), std::vector<int>{3, 4}));
  m3.assign_col(1, std::vector<int>{7, 8, 9});
  EXPECT_TRUE(is_equal(m3.get_row_view(1), std::vector<int>{3, 8}));
  mult_self(aa, aa2);
  EXPECT_TRUE((aa == std::vector<int>{2, 8, 18}));
}
