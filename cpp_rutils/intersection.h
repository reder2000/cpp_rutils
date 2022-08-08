#pragma once

// vector intersection of two vector


#include <utility>
#include <algorithm>

template <class In, class Compare > inline
auto intersection_vc(const In& v1, const In& v2, Compare comp) {
	using result_type = typename In::value_type;
	std::vector<result_type> res;
	res.reserve(std::max(v1.size(), v2.size()));
	std::set_intersection(v1.begin(), v1.end(),
		v2.begin(), v2.end(),
		std::back_inserter(res), comp);
	return res;
}

template <class In> inline
auto intersection_vc(const In& v1, const In& v2) {
	return intersection_vc(v1, v2, std::less<>{});
}
