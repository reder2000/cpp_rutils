#include <catch2/catch_test_macros.hpp>
#include <linalg.h>

TEST_CASE("linalg", "[name][hide]")
{
  std::vector<double> a{1., 2, 3.}, b{3., 2., 1.};
  CHECK(add(a, b) == std::vector<double>{4., 4., 4.});
  CHECK(minus(a, b) == std::vector<double>{-2., 0., 2.});
  CHECK(sumproduct(a, b) == 10.);
  CHECK(mean(a) == 2.);
  CHECK(sum(a) == 6.);
  CHECK(variance(a, 0) == (2. / 3.));
  CHECK(variance(a, 1) == 1.);
  CHECK(covariance(a, b, 0) == (-2. / 3.));
  CHECK(covariance(a, b, 1) == -1.);
  std::vector<double> c{1, 2, 3, 4}, d{2, 2, 5, 4};
  auto                v = log_variance(c, 0);
  CHECK(fabs(v - 0.029003975) < 1e-7);
  v = log_variance(c, 1);
  CHECK(fabs(v - 0.043505962) < 1e-7);
  double cv = log_covariance(c, d, 0);
  CHECK(fabs(cv - -0.004324163) < 1e-7);
  cv = log_covariance(c, d, 1);
  CHECK(fabs(cv - -0.006486244) < 1e-7);
  [[maybe_unused]] auto cv2 = return_covariance(c, d, 1);
}
