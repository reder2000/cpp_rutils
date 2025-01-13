#include "stdafx.h"
#include <partitioner.h>
#include <transform.h>

bool operator == (const Partitioner::chunk_type& a, const Partitioner::chunk_type& b)
{
	return a._start == b._start && a._end == b._end;
}


TEST(cpp_rutils,partitioner)
{
	Partitioner p(101, 15, 7);
	auto sizes = List([](const Partitioner::chunk_type& c) {return  c._end - c._start; }, p._chunks);
	Partitioner p2(sizes);
	EXPECT_TRUE(p._chunks == p2._chunks);
}


