#pragma once

// sorted vector seek

#include <vector>
#include <algorithm>

#include "require.h"


// find the PREVIOUS index value if no exact match.
template <class T>
size_t get_index_ffill(const std::vector<T>& v, const T& value);

// find the NEXT index value if no exact match.
template <class T>
size_t get_index_bfill(const std::vector<T>& v, const T& value);

// -------------------------------------------------------------------------
template <class T>
size_t get_index_bfill(const std::vector<T>& v, const T& value)
{
	MREQUIRE_GREATER(v.size(), 0);
	MREQUIRE_LESS_EQUAL(value, v.back());
	auto it = std::lower_bound(v.cbegin(), v.cend(), value);
	size_t res = std::distance(v.cbegin(), it);
	return res;
}

template <class T>
size_t get_index_ffill(const std::vector<T>& v, const T& value)
{
	MREQUIRE_GREATER(v.size(), 0);
	MREQUIRE_GREATER_EQUAL(value, v.front());
	auto it = std::lower_bound(v.crbegin(), v.crend(), value, std::greater<>{});
	size_t res = std::distance(it, v.crend()) - 1;
	return res;
}
