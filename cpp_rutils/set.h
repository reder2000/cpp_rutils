#pragma once 

#include <unordered_set>
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