#pragma once 

#include <vector>
#include "vector_concept.h"
#include <algorithm>

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

template <class UnaryPredicate, class Vec>
Vec List_if(const Vec& vec, UnaryPredicate pred)
{
	Vec res;
	std::copy_if(vec.begin(), vec.end(), std::back_inserter(res), pred);
	return res;
}

template <VectorConcept In, class Pred>
bool contains_if(const In& in, Pred pred)
{
	return std::find_if(in.begin(), in.end(), pred) != in.end();
}

template <VectorConcept In>
bool contains(const In& in, typename In::value_type val)
{
	return std::find(in.begin(), in.end(), val) != in.end();
}


template <class T>
[[nodiscard]] std::vector<T> concat(const std::vector<T>& dst, const std::vector<T>& src)
{
	std::vector<T>	res{ dst };
	res.insert(
		res.end(),
		src.begin(),
		src.end()
	);
	return res;
}

// concat with move
template <class T>
std::vector<T> &concat(std::vector<T> & dst, std::vector<T> && src)
{
	dst.insert(
		dst.end(),
		std::make_move_iterator(src.begin()),
		std::make_move_iterator(src.end())
	);
	return dst;
}