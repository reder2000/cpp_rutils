#include <catch2/catch_test_macros.hpp>
#include <require.h>
#include <vector>
#include <iostream>
#include <enum.h>
#include <set>
#include <algorithm>

#define EnumFail_tuple (good,bad)
EMIT_ENUM_CLASS(EnumFail);

TEST_CASE("require", "[require][hide]")
{
	//try { MFAIL("reason why"); }	catch (const std::exception& e) { fmt::print("failed since: {}", e.what()); }
	auto f = []() { MREQUIRE(true); };
	CHECK_NOTHROW(f());
	auto g = []() { MREQUIRE(false); };
	CHECK_THROWS(g());
	auto h = []() { MREQUIRE_EQUAL(1, 2); };
	CHECK_THROWS(h());
	auto i = []() { MREQUIRE_EQUAL(1, 1); };
	CHECK_NOTHROW(i());
	auto j = []() { MREQUIRE_EQUAL(1, 2, "some {}", "comment"); };
	CHECK_THROWS(j());
	auto k = [](EnumFail ef) {
		switch (ef) {
		case EnumFail::good:
			break;
			default_fail_enum_string(ef);
		} };
	CHECK_NOTHROW(k(EnumFail::good));
	CHECK_THROWS(k(EnumFail::bad));
	auto failure = []() -> bool {throw std::runtime_error("expected to fail"); };
	try { MREQUIRE_TRY(failure()) }
	catch (std::exception& e) { std::cout << at_most_n_lines( e.what() ,5) <<  std::endl; }
	try { MREQUIRE_TRY(failure() , "{}" , "failure") }
	catch (std::exception& e) { std::cout << at_most_n_lines( e.what() ,5) << std::endl; }

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

	REQUIRE(vd0.empty());

	VV vv;
	vv.push_back(std::move(vd1));
	REQUIRE(vd1.empty());

	REQUIRE(std::addressof(vv[0][0]) == where);

	mover _v(Copy(vv[0]));

	mover mv2((VD(vv[0])));

	REQUIRE(!vv[0].empty());

	std::set<double> s{ 1.,2. };
	VD vs(s.begin(), s.end());
	std::sort(vs.begin(), vs.end());
	REQUIRE(vs[0] < vs[1]);
}

int test_MREQUIRE_RET(bool must_throw, bool success) {
	int res = 1;
	MREQUIRE_RET(must_throw, res, success);
	return 2;
}

TEST_CASE("MREQUIRE_RET", "[require][hide]")
{
	CHECK(test_MREQUIRE_RET(true, true) == 2);
	CHECK(test_MREQUIRE_RET(false, false) == 1);
	CHECK_THROWS(test_MREQUIRE_RET(true, false));
}


TEST_CASE("MREQUIRE_INIT", "[require][hide]")
{
	auto good_fun = []() {return std::string("OK"); };
	auto bad_fun = []() -> std::string {throw std::runtime_error("ouch");  };

    [[maybe_unused]] auto a = TRY_INIT(good_fun(), "ok");
    [[maybe_unused]] auto b = TRY_INIT(good_fun());

	CHECK_THROWS( TRY_INIT(bad_fun(), "this is {}", "bad"));
	CHECK_THROWS(TRY_INIT(bad_fun() ));

}
