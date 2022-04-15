#include <catch.hpp>
#include <shared_ptr.h>


TEST_CASE("shared_ptr", "[enum][hide]")
{
    std::shared_ptr<int> sp1(new int{ 2 });
    auto sp2 = sp<int>(new int{ 2 });
    CHECK(*sp1 == *sp2);
    auto sp3 = make_sp_copy<int>(2.);
    CHECK(*sp1 == *sp3);
}

TEST_CASE("shared_ptr_v", "[enum][hide]")
{
    using V = std::vector<int>;
    V v1{ 1,2 };
    std::shared_ptr<V> sp1(new V{ 1,2 });
    auto sp2 = sp<V>(new V{ 1,2 });
    CHECK(*sp1 == *sp2);
    auto sp3 = make_sp_move<V>(v1);
    CHECK(*sp1 == *sp3);
    CHECK(v1.size() == 0);
}