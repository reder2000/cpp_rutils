#pragma once

#include "intersection.h"

template <class In, class Compare >
std::vector<typename In::value_type> union_vc(const In& v1, const In& v2, Compare comp) {
	using result_type = typename In::value_type;
	std::vector<result_type> res;
	res.reserve(std::max(v1.size(), v2.size()));
	std::set_union(v1.begin(), v1.end(),
		v2.begin(), v2.end(),
		std::back_inserter(res), comp);
	return res;
}

template <class In>
std::vector<typename In::value_type>  union_vc(const In& v1, const In& v2) {
	return union_vc(v1, v2, std::less<>{});
}


template <class In, class Fun, class Compare>
std::vector<typename std::invoke_result_t<Fun, typename In::value_type>> union_vc_fun(const In& v1, const In& v2, Fun fun, Compare comp) {
	// fixme : uses intermediate storage
	auto inter = union_vc(v1, v2, comp);
	auto res = transform_vc(inter, fun);
	return res;
}

template <class In, class Fun>
std::vector<typename std::invoke_result_t<Fun, typename In::value_type>> union_vc_fun(const In& v1, const In& v2, Fun fun) {
	return union_vc_fun(v1, v2, fun, std::less<>{});
}

// many unions (not completely efficient, though)

template <class In, class ...Args>
std::vector<typename In::value_type>  union_vcs(const In& v1, const In& v2) {
	return union_vc(v1, v2);
}

template <class In, class ...Args>
std::vector<typename In::value_type>  union_vcs(const In& v1, const In& v2, const Args... args) {
	return union_vc(v1, union_vcs(v2, args...));
}

template <class T>
std::vector<T> set_union(const std::vector<std::reference_wrapper<const std::vector<T>>>& vs)
{
	const size_t M = std::accumulate(vs.begin(), vs.end(), size_t(0), [](size_t a, const std::reference_wrapper<const std::vector<T>>& b)
		{return std::max(a, b.get().size()); });
	std::unordered_set<T> inter;
	inter.reserve(M);
	for (auto const& v : vs)
		for (auto const& t : v.get())
			inter.insert(t);
	std::vector<T> res(inter.begin(), inter.end());
	std::sort(res.begin(), res.end());
	return res;
}

template <class T>
std::vector<T> set_union(const std::vector<std::vector<T>>& vs)
{
	std::vector<std::reference_wrapper<const std::vector<T>>> re_vs;
	for (auto const& v : vs)
		re_vs.push_back(v);
	return set_union(re_vs);
}