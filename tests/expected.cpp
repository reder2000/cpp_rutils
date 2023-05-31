#include <catch2/catch_test_macros.hpp>

#include <expected.h>



TEST_CASE("expected", "[enum][hide]")
{
  auto f = []() { MEXPECTED(false); };
  fmt::print("unexpected : {}\n", f());
  auto g = []() { MEXPECTED(false, "bad value {}", false); };
  fmt::print("unexpected : {}\n", g());
  auto h = []() -> expected_s<bool>
  {
    expected_s<bool> e;
    e = unexpected_s("missed");
    CHECK_EXPECTED(e);
    return e;
  };
  fmt::print("unexpected : {}\n", h());
  auto success          = []() -> expected_s<bool> { return expected_s<bool>(true); };
  auto failure          = []() -> expected_s<bool> { return unexpected_s("failure"); };
  auto require_expected = [](expected_s<bool> e) { REQUIRE_EXPECTED(e); };
  CHECK_NOTHROW(require_expected(success()));
  CHECK_THROWS(require_expected(failure()));
  auto expected_or_fail_failure = [&]()
  {
    EXPECTED_OR_FAIL(var, failure());
    return var;
  };
  CHECK_THROWS(expected_or_fail_failure());
  auto expected_or_fail_success = [&]()
  {
    EXPECTED_OR_FAIL(var, success());
    return var;
  };
  CHECK(expected_or_fail_success() == true);
}
