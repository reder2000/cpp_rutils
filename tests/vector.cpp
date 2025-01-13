#include "stdafx.h"
#include <vector.h>


TEST(cpp_rutils,sp_vector)
{
    auto ev = new_sp_vc<double>();
    auto evl = new_sp_vc<double>({ 1.,2.,3. });
    EXPECT_TRUE((*evl)[1] == 2);
    auto ev1 = sp_vc<double>(new vc<double>({ 1.,2.,3. }));
    EXPECT_TRUE((*ev1)[1] == 2);
}


TEST(cpp_rutils,vector_sp)
{
    vc_sp<double> v;
    auto v1 = new_vc_sp(1.);
    EXPECT_TRUE(*(v1[0]) == 1.);
    auto v2 = new_vc_sp({ 1.,2.,3. });
    EXPECT_TRUE(*(v2)[1] == 2);
    //auto ev = new_sp_vc<double>();
    //auto evl = new_sp_vc<double>({ 1.,2.,3. });
    //auto ev1 = sp_vc<double>(new vc<double>({ 1.,2.,3. }));
}


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

TEST(cpp_rutils,apply)
{

    auto f = std::make_tuple(1., 2., 3.);

    //auto v = std::apply([](auto ...x) {vc<double> res;
    //((res.push_back(x)), ...); return res; }, f);
    auto v = vc_from_tuple<double>(f);
    auto vs = vc_sp_from_tuple<double>(f);

   EXPECT_TRUE(v[1] == 2.);
   EXPECT_TRUE(*(vs[1]) == 2.);

   auto f2 = std::make_tuple(A(1.), B(2., 3.));

   auto v2 = vc_from_tuple<A>(f2);
   EXPECT_TRUE(v2[0]._d == 1.);

   auto vs2 = vc_sp_from_tuple<A>(f2);
   EXPECT_TRUE(vs2[0]->_d == 1.);

   using vd = vc<double>;
   auto f3 = std::make_tuple(vd{ 1. }, vd{ 2., 3. });

   auto v3 = vc_from_tuple<vd>(f3);
   EXPECT_TRUE(v3[0][0] == 1.);

   auto vs3 = vc_sp_from_tuple<vd>(f3);
   EXPECT_TRUE((*(vs3[0]))[0] == 1.);

   auto vsm3 = vc_sp_move_tuple<vd>(f3);
   EXPECT_TRUE((*(vsm3[0]))[0] == 1.);
   EXPECT_TRUE(std::get<0>(f3).empty());

   sp_vc<double> shared_ptr_vector_double(new std::vector{ 1.,2.,3. });
   (*shared_ptr_vector_double)[1] = 4;
   spc_vc<double> shared_ptr_const_vector_double(new std::vector{ 1.,2.,3. });
   EXPECT_TRUE((*shared_ptr_const_vector_double)[1] == 2.);

}