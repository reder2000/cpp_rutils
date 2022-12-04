#include <catch2/catch_test_macros.hpp>
#include <enum.h>
#include <string_literal.h>
#include <always_false.h>

#define DataType_tuple (close,\
open,\
high,\
low,\
mid,\
vwap\
)

EMIT_ENUM_CLASS(DataType);

using DataType_tuple_sl = tuple_sl<"close", "open", "high", "low", "mid", "vwap">;

template <DataType d>
constexpr const char* enum_to_cstring() {
	return tuple_sl_element_t<static_cast<size_t>(d), DataType_tuple_sl>.value;
}

template <typename T, StringLiteral S>
struct cstring_to_enum_s {
 static_assert(	always_false_v<T> );
};

template <StringLiteral S>
struct cstring_to_enum_s<DataType,S> {
	static constexpr DataType value = static_cast<DataType>(tuple_sl_element<S, DataType_tuple_sl>);
};

template <typename T, StringLiteral S>
constexpr T cstring_to_enum = cstring_to_enum_s<T,S>::value;



TEST_CASE("enum string", "[enum][hide]")
{
	const DataType toto(DataType::high);
	CHECK(enum_to_string(toto) == std::string("high"));
	CHECK(to_string(toto) == "high");
	CHECK(string_to_enum< DataType>("low") == DataType::low);
	// test fmt::format
	CHECK(fmt::format("{}", toto) == "high");
	CHECK(enum_to_cstring<DataType::low>()==std::string("low"));
	auto t = enum_to_cstring<DataType::high>();
	auto d = cstring_to_enum< DataType, "high">;
	CHECK(d == DataType::high);
}
