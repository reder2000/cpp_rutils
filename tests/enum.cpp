#include <catch2/catch_test_macros.hpp>
#include <enum.h>

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
}
