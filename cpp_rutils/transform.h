#pragma once 

#include <vector>
#include "vector_concept.h"

// return a new, transformed vector

template <VectorConcept In, class Tr>
auto transform_vc(const In& in, Tr tr) {
	using result_type = typename std::invoke_result_t<Tr, typename In::value_type>;
	std::vector<result_type> res;
	res.reserve(in.size());
	for (auto i : in)
		res.emplace_back(tr(i));
	return res;
}


template <class Fun, class Vec>
std::vector<std::invoke_result_t<Fun, typename Vec::value_type>> List(Fun fun, const Vec& vec)
{
	return transform_vc(vec, fun);
}