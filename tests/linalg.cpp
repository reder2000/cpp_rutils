#include <catch2/catch_test_macros.hpp>
#include <linalg.h>

TEST_CASE("linalg", "[name][hide]")
{
    std::vector<double> a{1.,2,3.}, b{3.,2.,1.};
    CHECK(add(a,b)==std::vector<double>{4.,4.,4.});
    CHECK(minus(a,b)==std::vector<double>{-2.,0.,2.});
    CHECK(mean(a)==2.);
    CHECK(sum(a)==6.);
    CHECK(variance(a,0)==(2./3.));
    CHECK(variance(a,1)==1.);
    CHECK(covariance(a,b,0)==(-2./3.));
    CHECK(covariance(a,b,1)==-1.);
}
