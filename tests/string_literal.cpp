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


TEST_CASE("string literal", "[enum][hide]")
{
	using tu = tuple_sl<"toto", "tata">;
	static_assert (tuple_sl_element<"tata", tu> == 1);
	// this would fail size_t s = tuple_sl_element<"titi", tu>;
}
