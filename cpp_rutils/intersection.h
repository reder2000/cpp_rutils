#pragma once

// vector intersection of two vector


#include <utility>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

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

template <class V, class Op>
std::vector<
	std::reference_wrapper<const std::decay_t<std::invoke_result_t<Op, typename V::value_type>>>>
	make_vector_reference(const V& vs, Op op)
{
	using T = std::invoke_result_t<Op, typename V::value_type>;
	static_assert(std::is_reference_v<T>);
	//static_assert(std::is_same_v<T, std::vector<TZDate>>);
	std::vector < std::reference_wrapper<const std::decay_t<T>>> res;
	res.reserve(vs.size());
	for (auto const& v : vs)
		res.emplace_back(op(v));
	return res;
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
std::vector<T> set_intersection(const std::vector<std::reference_wrapper<const std::vector<T>>>& vs)
{
	//const size_t M = std::accumulate(vs.begin(), vs.end(), std::numeric_limits<size_t>::max(), [](size_t a, const std::reference_wrapper<const std::vector<T>>& b)
	//	{return std::min(a, b.get().size()); });
	const size_t M = std::accumulate(vs.begin(), vs.end(), size_t(0), [](size_t a, const std::reference_wrapper<const std::vector<T>>& b)
		{return std::max(a, b.get().size()); });	std::unordered_map<T, size_t> inter;
	inter.reserve(M);
	for (auto const& v : vs)
		for (auto const& t : v.get())
		{
			auto u = inter.try_emplace(t, size_t(0));
			u.first->second++;
		}
	//inter[t] += 1;
	const size_t N = vs.size();
	std::vector<T> res;
	for (auto const i : inter)
		if (i.second == N)
			res.push_back(i.first);
	std::sort(res.begin(), res.end());
	return res;
}


template <class T>
std::vector<T> set_intersection(const std::vector<std::vector<T>>& vs)
{
	std::vector<std::reference_wrapper<const std::vector<T>>> re_vs;
	for (auto const& v : vs)
		re_vs.push_back(v);
	return set_intersection(re_vs);
}