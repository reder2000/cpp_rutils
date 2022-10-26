#pragma once 

#include <unordered_set>
#include <unordered_map>
#include "vector_concept.h"
#include "require.h"

template <VectorConcept In>
std::unordered_set<typename In::value_type> Set(const In& v)
{
	std::unordered_set<typename In::value_type> res{v.begin(), v.end()};
	return res;
}

template <VectorConcept In>
std::unordered_set<typename In::value_type> SetUnique(const In& v)
{
std::unordered_set<typename In::value_type> res;
	for (auto const & val : v)
	{
		MREQUIRE(!res.contains(val),"{} duplicated",val);
		res.insert(val);
	}
	return res;
}

template <VectorConcept In, typename Fun >
std::unordered_map<typename In::value_type,typename std::invoke_result_t<Fun,typename In::value_type>> Dict(In vec, Fun fun)
{
	using result_type = std::invoke_result_t<Fun,typename In::value_type>;
	std::unordered_map<typename In::value_type,result_type> res;
	for (auto v:vec)
		res[v] = fun(v);
	return res;
}

template <typename Out, VectorConcept In, typename Fun >
std::unordered_map<typename In::value_type,Out>  DictSelf(In vec, Fun fun)
{
	std::unordered_map<typename In::value_type,Out> res;
	for (auto v:vec)
		res[v] = fun(res,v);
	return res;
}
