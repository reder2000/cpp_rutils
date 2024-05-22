#include <catch2/catch_test_macros.hpp>
#include <enum.h>
#include <string_literal.h>
#include <require.h>
#include <optional>

#define DataType_tuple (close,\
open,\
high,\
low,\
mid,\
vwap\
)



EMIT_ENUM_CLASS(DataType);



TEST_CASE("enum string", "[enum][hide]")
{
	const DataType toto(DataType::high);
	CHECK(enum_to_string(toto) == std::string("high"));
	CHECK(to_string(toto) == "high");
	CHECK(string_to_enum< DataType>("low") == DataType::low);
	// test std__format
	CHECK(std__format("{}", toto) == "high");
	//CHECK(enum_to_cstring<DataType::low>()==std::string("low"));
	//auto t = enum_to_cstring<DataType::high>();
	//auto d = cstring_to_enum< DataType, "high">;
	//CHECK(d == DataType::high);
	//d = dstring_to_enum<DataType>("vwap");
	//CHECK(d == DataType::vwap);
	//CHECK_THROWS(dstring_to_enum<DataType>("High"));
	
}
