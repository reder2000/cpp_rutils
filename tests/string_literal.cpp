#include <catch2/catch_test_macros.hpp>
#include <string_literal.h>
#include <optional>
#include <array>
#include <name_short.h>

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
concept is_good_string = tuple_sl_contains < U, tuple_sl<"toto", "tata">>   ;


template <StringLiteral U> requires is_good_string<U>
void fun() {}



TEST_CASE("string literal", "[enum][hide]")
{
	using tu = tuple_sl<"toto", "tata">;
	static_assert (tuple_sl_index<"tata", tu> == 1);
	// this would fail
	// size_t s = tuple_sl_index<"titi", tu>;
	fun<"toto">();
	// this would fail  fun<"titi">();
	//std::array < const char*, 2> t{ "toto","tata" };
	//auto t = detail::get_tuple_sl_array(tu{});
	auto t = tuple_sl_array<tu>;
	auto tt = type_name_short<decltype(t)>();
	std::cout << "XXXXXXXXXXXXXX " << tt << "\n";
	CHECK(tuple_sl_get_i<tu>(1) == "tata");
	CHECK(tuple_sl_index_s<tu>("tata") == 1);
}
