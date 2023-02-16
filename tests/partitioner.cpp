#include <always_false.h>
#include <catch2/catch_test_macros.hpp>
#include <partitioner.h>
#include <transform.h>

bool operator == (const Partitioner::chunk_type& a, const Partitioner::chunk_type& b)
{
	return a._start == b._start && a._end == b._end;
}


TEST_CASE("partitioner", "[transform][hide]")
{
	Partitioner p(101, 15, 7);
	auto sizes = List([](const Partitioner::chunk_type& c) {return  c._end - c._start; }, p._chunks);
	Partitioner p2(sizes);
	CHECK(p._chunks == p2._chunks);
}


