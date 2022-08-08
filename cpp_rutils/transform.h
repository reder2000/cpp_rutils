#pragma once 

#include <vector>
#include "vector_concept.h"

// return a new, transformed vector

template <VectorConcept In, class Tr>
auto transform_vc(const In& in, Tr tr) {
	using result_type = typename std::invoke_result<Tr, typename In::value_type>::type;
	std::vector<result_type> res;
	for (auto i : in)
		res.push_back(tr(i));
	return res;
}

