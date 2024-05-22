#include <catch2/catch_test_macros.hpp>
#include <struct_transpose.h>
#include <boost/utility/identity_type.hpp>

//template <class T>
//T merge(const std::vector<T>&)
//{
//	static_assert(always_false_v<T>);
//}



TEST_CASE("struct_transpose", "[transform][hide]")
{
	std::vector<std::vector<int>> vs{ {1},{2,3} };
	CHECK(merge(vs) == std::vector<int>{1, 2, 3});
	std::vector<std::unordered_set<int>> vus{ {1,2},{2,3} };
	CHECK(merge(vus) == std::unordered_set<int>{1, 2, 3});
	std::vector<std::unordered_map<int, double>> vum{ {{1,1.},{2,2.}},{{2,2.},{3,3.}} };
	CHECK(merge(vum) == std::unordered_map<int, double>{ {1, 1.}, { 2,2. }, { 3,3. } });
}

//#define mystruct_tuple ((BOOST_IDENTITY_TYPE((std::vector<int>)),i),(BOOST_IDENTITY_TYPE((std::unordered_set<double>)),d))
#define mystruct_tuple ((std::vector<int>,i),(BOOST_IDENTITY_TYPE((std::unordered_map<double,int>)),d))
//#define mystruct_tuple 	((int,i),(double,d))
//name_tuple_struct_declare(mystruct);
//name_tuple_struct_vector_declare(mystruct);
//name_tuple_struct_vector_merge_declare(mystruct);
name_tuple_struct_vector_merge_declare_all(mystruct);

TEST_CASE("struct_transpose_cplx", "[transform][hide]")
{
	mystruct_vector toto(2);
	toto._i[0] = { 1 };
	toto._i[1] = { 2,3 };
	toto._d[0] = std::unordered_map<double, int>{ {1.,1} };
	toto._d[1] = std::unordered_map<double, int>{ {2.,2},{3.,3} };
	auto to = merge_struct(toto);
	CHECK(to._i == std::vector<int>{1, 2, 3});
	CHECK(to._d == std::unordered_map<double, int>{ {1., 1}, { 2.,2 }, { 3.,3 } });
}