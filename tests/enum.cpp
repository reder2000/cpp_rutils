#include <catch.hpp>
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
    DataType toto(DataType::high);
    CHECK(enum_to_string(toto) == std::string("high"));
    CHECK(string_to_enum< DataType>("low") == DataType::low);
}
