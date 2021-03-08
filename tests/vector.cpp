#include <catch.hpp>
#include <vector.h>


TEST_CASE("sp_vector", "[enum][hide]")
{
    auto ev = new_sp_vc<double>();
    auto evl = new_sp_vc<double>({ 1.,2.,3. });
    REQUIRE((*evl)[1] == 2);
    auto ev1 = sp_vc<double>(new vc<double>({ 1.,2.,3. }));
    REQUIRE((*ev1)[1] == 2);
}

#include <iostream>

TEST_CASE("vector_sp", "[enum][hide]")
{
    vc_sp<double> v;
    auto v1 = new_vc_sp(1.);
    REQUIRE(*(v1[0]) == 1.);
    auto v2 = new_vc_sp({ 1.,2.,3. });
    REQUIRE(*(v2)[1] == 2);
    //auto ev = new_sp_vc<double>();
    //auto evl = new_sp_vc<double>({ 1.,2.,3. });
    //auto ev1 = sp_vc<double>(new vc<double>({ 1.,2.,3. }));
}


#include <iostream>
#include <utility>
#include <tuple>

//template<class T>
//void test(T&& t)
//{
//    int a[std::tuple_size<T>::value]; // can be used at compile time
//    std::cout << std::tuple_size<T>::value << '\n'; // or at run time
//}
//
//int maine()
//{
//    test(std::make_tuple(1, 2, 3.14));
//    test(std::make_pair(1, 3.14));
//}


struct A {
    A(double d) : _d(d) {}
    double _d;
};

struct B : public A {
    B(double d, double e) : A(d), _e(e) {}
    double _e;
};

TEST_CASE("apply", "[enum][hide]")
{

    auto f = std::make_tuple(1., 2., 3.);

    //auto v = std::apply([](auto ...x) {vc<double> res;
    //((res.push_back(x)), ...); return res; }, f);
    auto v = vc_from_tuple<double>(f);
    auto vs = vc_sp_from_tuple<double>(f);

   REQUIRE(v[1] == 2.);
   REQUIRE(*(vs[1]) == 2.);

   auto f2 = std::make_tuple(A(1.), B(2., 3.));

   auto v2 = vc_from_tuple<A>(f2);
   REQUIRE(v2[0]._d == 1.);

   auto vs2 = vc_sp_from_tuple<A>(f2);
   REQUIRE(vs2[0]->_d == 1.);

   using vd = vc<double>;
   auto f3 = std::make_tuple(vd{ 1. }, vd{ 2., 3. });

   auto v3 = vc_from_tuple<vd>(f3);
   REQUIRE(v3[0][0] == 1.);

   auto vs3 = vc_sp_from_tuple<vd>(f3);
   REQUIRE((*(vs3[0]))[0] == 1.);

   auto vsm3 = vc_sp_move_tuple<vd>(f3);
   REQUIRE((*(vsm3[0]))[0] == 1.);
   REQUIRE(std::get<0>(f3).size() == 0);

}