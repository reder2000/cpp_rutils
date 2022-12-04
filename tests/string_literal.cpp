#include <catch2/catch_test_macros.hpp>
#include <string_literal.h>

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
concept is_good_string = is_tuple_sl_element < U, tuple_sl<"toto", "tata">>   ;


template <StringLiteral U> requires is_good_string<U>
void fun() {}

TEST_CASE("string literal", "[enum][hide]")
{
	using tu = tuple_sl<"toto", "tata">;
	static_assert (tuple_sl_element<"tata", tu> == 1);
	// this would fail size_t s = tuple_sl_element<"titi", tu>;
	fun<"toto">();
	// this would fail  fun<"titi">();
}
