#include <catch.hpp>
#include <require.h>
#include <vector>
#include <iostream>


TEST_CASE("require", "[require][hide]")
{
    auto f = []() { MREQUIRE(true); };
    CHECK_NOTHROW(f());
    auto g = []() { MREQUIRE(false); };
    CHECK_THROWS(g());
    auto h = []() { MREQUIRE_EQUAL(1,2); };
    CHECK_THROWS(h());
    auto i = []() { MREQUIRE_EQUAL(1, 1); };
    CHECK_NOTHROW(i());
    auto j = []() { MREQUIRE_EQUAL(1, 2, "some {}" , "comment"); };
    CHECK_THROWS(j());


}

template <class T>
T Copy(const T& t) {
    T res(t);
    return res;
}

struct mover {
    mover(std::vector<double>&& v) : _v(v) {}
    std::vector<double> _v;
};

TEST_CASE("move", "[require][hide]")
{
    using VD = std::vector<double>;
    using VV = std::vector<VD>;

    VD vd0{ 1.,2. };
    const double* where = std::addressof(vd0[0]);
    VD vd1(std::move(vd0));

    REQUIRE(vd0.size() == 0);

    VV vv;
    vv.push_back(std::move(vd1));
    REQUIRE(vd1.size() == 0);

    REQUIRE(std::addressof(vv[0][0]) == where);

    mover _v(Copy(vv[0]));

    mover mv2((VD(vv[0])));

    REQUIRE(vv[0].size());

    std::set<double> s{ 1.,2. };
    VD vs(s.begin(), s.end());
    std::sort(vs.begin(), vs.end());
    REQUIRE(vs[0] < vs[1]);
}