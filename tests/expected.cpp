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
}
