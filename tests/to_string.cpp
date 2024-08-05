#include <to_string.h>

#include <iostream>

enum class toto {
    red = 0
}; 

std::ostream& operator<<(std::ostream& os, toto /*v*/) {
    os << "red";
    return os;
}

struct A {};

// fixme 
template <> struct std__formatter<A> : formatter<std::string> {
    // parse is inherited from formatter<string_view>.
    template <typename FormatContext>
    auto format(A , FormatContext& ctx) const {
        return formatter<std::string>::format("A", ctx);
    }
};


std::string_view at_most_n_lines(std::string_view sv, size_t n)
{
    auto i = sv.begin();
    for (; n > 0; --n)
    {
        i = std::find(i, sv.end(), '\n');
        if (i == sv.end()) break;
        ++i;
    }
    return std::string_view{sv.begin(), i};
}


TEST(cpp_rutils,to_string)
{
    int i = 10;
    EXPECT_TRUE(to_string(i) == "10");
    void* v = (void*)0xF010;
    EXPECT_TRUE(to_string(v) == "0xf010");
    std::variant<int, const char*> vic = 12;
    EXPECT_TRUE(to_string(vic) == "12");
    vic = "abcd";
    EXPECT_TRUE(to_string(vic) == "abcd");
    EXPECT_TRUE(to_string(toto::red) == "red");
    EXPECT_TRUE(to_string(A()) == "A");
}
