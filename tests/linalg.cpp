#include "stdafx.h"
#include <linalg.h>

TEST(cpp_rutils,linalg)
{
  std::vector<double> a{1., 2, 3.}, b{3., 2., 1.};
  EXPECT_TRUE((add(a, b) == std::vector<double>{4., 4., 4.}));
  EXPECT_TRUE((minus(a, b) == std::vector<double>{-2., 0., 2.}));
  EXPECT_TRUE(sumproduct(a, b) == 10.);
  EXPECT_TRUE(mean(a) == 2.);
  EXPECT_TRUE(sum(a) == 6.);
  EXPECT_TRUE(variance(a, 0) == (2. / 3.));
  EXPECT_TRUE(variance(a, 1) == 1.);
  EXPECT_TRUE(covariance(a, b, 0) == (-2. / 3.));
  EXPECT_TRUE(covariance(a, b, 1) == -1.);
  std::vector<double> c{1, 2, 3, 4}, d{2, 2, 5, 4};
  auto                v = log_variance(c, 0);
  EXPECT_TRUE(fabs(v - 0.029003975) < 1e-7);
  v = log_variance(c, 1);
  EXPECT_TRUE(fabs(v - 0.043505962) < 1e-7);
  double cv = log_covariance(c, d, 0);
  EXPECT_TRUE(fabs(cv - -0.004324163) < 1e-7);
  cv = log_covariance(c, d, 1);
  EXPECT_TRUE(fabs(cv - -0.006486244) < 1e-7);
  [[maybe_unused]] auto cv2 = return_covariance(c, d, 1);
}
