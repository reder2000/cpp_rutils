#pragma once 

#include <vector>

template <class In, class Tr>
auto transform_vc(const In& in, Tr tr) {
	using result_type = typename std::invoke_result<Tr, typename In::value_type>::type;
	std::vector<result_type> res;
	for (auto i : in)
		res.push_back(tr(i));
	return res;
}

