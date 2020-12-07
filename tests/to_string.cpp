#include <catch.hpp>
#include <to_string.h>

#include <catch.hpp>
#include <iostream>
#include <name.h>

enum class toto {
    red = 0
}; 

std::ostream& operator<<(std::ostream& os, toto v) {
    os << "red";
    return os;
}

struct A {};

// fixme 
template <> struct fmt::formatter<A> : formatter<std::string> {
    // parse is inherited from formatter<string_view>.
    template <typename FormatContext>
    auto format(A , FormatContext& ctx) {
        return formatter<std::string>::format("A", ctx);
    }
};


TEST_CASE("to_string", "[to_string][hide]")
{
    int i = 10;
    CHECK(to_string(i) == "10");
    void* v = (void*)0xF010;
    CHECK(to_string(v) == "0xf010");
    std::variant<int, const char*> vic = 12;
    CHECK(to_string(vic) == "12");
    vic = "abcd";
    CHECK(to_string(vic) == "abcd");
    CHECK(to_string(toto::red) == "red");
    CHECK(to_string(A()) == "A");
}

