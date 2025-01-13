#include "stdafx.h"
#include <expected.h>



TEST(cpp_rutils,expected)
{
  auto f = []() { MEXPECTED(false); };
  std__print("unexpected : {}\n", f());
  auto g = []() { MEXPECTED(false, "bad value {}", false); };
  std__print("unexpected : {}\n", g());
  auto h = []() -> expected_s<bool>
  {
    expected_s<bool> e;
    e = unexpected_s("missed");
    CHECK_EXPECTED(e);
    return e;
  };
  std__print("unexpected : {}\n", h());
  auto success          = []() -> expected_s<bool> { return expected_s<bool>(true); };
  auto failure          = []() -> expected_s<bool> { return unexpected_s("failure"); };
  auto require_expected = [](expected_s<bool> e) { REQUIRE_EXPECTED(e); };
  EXPECT_NO_THROW(require_expected(success()));
  EXPECT_ANY_THROW(require_expected(failure()));
  auto expected_or_fail_failure = [&]()
  {
    EXPECTED_OR_FAIL(var, failure());
    return var;
  };
  EXPECT_ANY_THROW(expected_or_fail_failure());
  auto expected_or_fail_success = [&]()
  {
    EXPECTED_OR_FAIL(var, success());
    return var;
  };
  EXPECT_TRUE(expected_or_fail_success() == true);
}
