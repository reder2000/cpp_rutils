#include "memory_size.h"

#define CATCH_CONFIG_ALL_PARTS
#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <cpp_rutils/name.h>
#include <map>


struct A
{
    std::vector<int> value;
};
struct B
{
    std::vector<int> value;
    size_t size_impl(memory::record& mc) const { return memory_sizes(mc,value);  }
};
struct C
{
    std::vector<int> value;
};

//template <>
size_t size_impl(const C& c,  memory::record& mc) { return memory_sizes(mc, c.value); }


struct D
{
    std::shared_ptr<std::string> value1,value2;
};

//template <>
size_t size_impl(const D& d, memory::record& mc) { return memory_sizes(mc, d.value1, d.value2); }

TEST_CASE("mem_size", "[mem][hide]") {
    auto pr = [](auto&& a) {
        using T = typename std::decay_t<decltype(a)>;
        auto sz = memory_size(a);
        std::cout << type_name<T>() << " : " << sz << std::endl;
    };
    pr((int)1);
    pr(nullptr_t{});
    std::vector<int> v;
    pr(v);
    v.resize(10);
    pr(v);
    std::string s;
    pr(s);
    s = "hello";
    pr(s);
    s.reserve(100);
    pr(s);
    auto hs = std::shared_ptr<std::string>{};
    pr(hs);
    hs.reset(new std::string("toto"));
    pr(hs);
    std::map<std::string, std::vector<int>> mm{};
    pr(mm);
    mm[s] = v;
    pr(mm);
    A a{};
    pr(a);
    a.value = v;
    pr(a);
    B  b{};
    pr(b);
    b.value = v;
    pr(b);
    static_assert(memory::has_external_impl<C>);
    C  c{};
    pr(c);
    c.value = v;
    pr(c);
    D d{};
    pr(d);
    d.value1 = hs;
    pr(d);
    d.value2 = hs;
    pr(d);
			
}