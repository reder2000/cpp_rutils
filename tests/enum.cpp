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



TEST(cpp_rutils,enum_string)
{
	const DataType toto(DataType::high);
	EXPECT_TRUE(enum_to_string(toto) == std::string("high"));
	EXPECT_TRUE(to_string(toto) == "high");
	EXPECT_TRUE(string_to_enum< DataType>("low") == DataType::low);
	// test std__format
	EXPECT_TRUE(std__format("{}", toto) == "high");
	//EXPECT_TRUE(enum_to_cstring<DataType::low>()==std::string("low"));
	//auto t = enum_to_cstring<DataType::high>();
	//auto d = cstring_to_enum< DataType, "high">;
	//EXPECT_TRUE(d == DataType::high);
	//d = dstring_to_enum<DataType>("vwap");
	//EXPECT_TRUE(d == DataType::vwap);
	//EXPECT_ANY_THROW(dstring_to_enum<DataType>("High"));
	
}
