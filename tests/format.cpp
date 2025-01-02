#include <format.h>
#include <date.h>
#include <vector>

struct not_formattable
{
};


TEST(cpp_rutils, format_chrono)
{
  auto s = std__format("{}", std__chrono::December);
  s      = std__format("{}", std::chrono::seconds(1));
  static_assert(formattable<int>);
  static_assert(!formattable<not_formattable>);
  }

TEST(cpp_rutils, format_vector)
  {
   std::vector<int> v = {1, 2, 3};
   auto r = format_join("{:02}", v, ",");
   EXPECT_TRUE(r == "01,02,03");
   auto s = std__format("{}", v);
  }

TEST(cpp_rutils, format_tuple)
  {
    std::tuple v = {1, 2., 3};
    auto             r = format_join("{:02}", v, ",");
    EXPECT_TRUE(r == "[01,02,03]");
    
  }

TEST(cpp_rutils, format_optional)
  {
    std::optional<int> v = 1;
    auto               r = std__format("{}", v);
    EXPECT_TRUE(r == "1");
    std::optional<int> v2;
    auto               r2 = std__format("{}", v2);
    EXPECT_TRUE(r2 == "{nullptr}");
  }