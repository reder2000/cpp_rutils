#pragma once

// vector intersection of two vector


#include <utility>
#include <algorithm>
#include <iterator>

#include "transform.h"

template <class In, class Compare >
std::vector<typename In::value_type> intersection_vc(const In& v1, const In& v2, Compare comp) {
	using result_type = typename In::value_type;
	std::vector<result_type> res;
	res.reserve(std::max(v1.size(), v2.size()));
	std::set_intersection(v1.begin(), v1.end(),
		v2.begin(), v2.end(),
		std::back_inserter(res), comp);
	return res;
}

template <class In>
std::vector<typename In::value_type>  intersection_vc(const In& v1, const In& v2) {
	return intersection_vc(v1, v2, std::less<>{});
}


template <class In, class Fun , class Compare>
std::vector<typename std::invoke_result_t<Fun, typename In::value_type>> intersection_vc_fun(const In& v1, const In& v2, Fun fun, Compare comp) {
	// fixme : uses intermediate storage
	auto inter = intersection_vc(v1, v2, comp);
	auto res = transform_vc(inter, fun);
	return res;
}

template <class In, class Fun>
std::vector<typename std::invoke_result_t<Fun, typename In::value_type>> intersection_vc_fun(const In& v1, const In& v2, Fun fun) {
	return intersection_vc_fun(v1, v2, fun, std::less<>{});
}

// many intersections (not completely efficient, though)

template <class In, class ...Args>
std::vector<typename In::value_type>  intersection_vcs(const In& v1, const In& v2) {
	return intersection_vc(v1, v2);
}

template <class In, class ...Args>
std::vector<typename In::value_type>  intersection_vcs(const In& v1, const In& v2, const Args... args) {
	return intersection_vc(v1, intersection_vcs(v2,args...));
}


