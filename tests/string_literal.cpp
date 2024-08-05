#include <string_literal.h>
#include <optional>
#include <array>
#include <name_short.h>
#include <always_false.h>
#include <iostream>

//#define DataType_tuple (close,\
//open,\
//high,\
//low,\
//mid,\
//vwap\
//)
//
//EMIT_ENUM_CLASS(DataType);



template <StringLiteral U>
concept is_good_string = tuple_sl_contains<U, tuple_sl<"toto", "tata">>;


template <StringLiteral U>
  requires is_good_string<U>
void fun()
{
}

template <StringLiteral T>
struct always_false_sl
{
  static constexpr bool value = false;
};


struct toto
{
  template <StringLiteral S>
  static void create()
  {
    static_assert(always_false_sl<S>::value);
  }
};

template <>
void toto::create<"tutu">()
{
}


TEST(cpp_rutils,string_literal)
{
  using tu = tuple_sl<"toto", "tata">;
  static_assert(tuple_sl_index<"tata", tu> == 1);
  // this would fail
  // size_t s = tuple_sl_index<"titi", tu>;
  fun<"toto">();
  // this would fail  fun<"titi">();
  //std::array < const char*, 2> t{ "toto","tata" };
  //auto t = detail::get_tuple_sl_array(tu{});
  [[maybe_unused]] auto t  = tuple_sl_array<tu>;
  auto                  tt = type_name_short<decltype(t)>();
  std::cout << "XXXXXXXXXXXXXX " << tt << "\n";
  EXPECT_TRUE(tuple_sl_get_i<tu>(1) == "tata");
  EXPECT_TRUE(tuple_sl_index_s<tu>("tata") == 1);
}

TEST(cpp_rutils,string_literal_ctor)
{
  // fails
  //auto t = toto::create<"titi">();
  toto::create<"tutu">();
}
