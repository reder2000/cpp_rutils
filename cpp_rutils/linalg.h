#pragma once

// very minimal linear algorithms

#include <numeric>
#include <vector>
#include <algorithm>
#include "require.h"

template <class _Ty>
std::vector<_Ty> add(const std::vector<_Ty>& a, std::vector<_Ty>& b)
{
	std::vector<_Ty> res;
	MREQUIRE_EQUAL(a.size(), b.size());
	res.reserve(a.size());
	std::transform(a.begin(), a.end(), b.begin(), std::back_inserter(res), std::plus<_Ty>());
	return res;
}

template <class _Ty>
std::vector<_Ty> minus(const std::vector<_Ty>& a, std::vector<_Ty>& b)
{
	std::vector<_Ty> res;
	MREQUIRE_EQUAL(a.size(), b.size());
	res.reserve(a.size());
	std::transform(a.begin(), a.end(), b.begin(), std::back_inserter(res), std::minus<_Ty>());
	return res;
}

template<typename _Ty>
_Ty sum(const std::vector<_Ty> &v) {
    MREQUIRE(!v.empty());
    return std::accumulate(v.begin(), v.end(), 0.0) ;
}

template<typename _Ty>
_Ty mean(const std::vector<_Ty> &v) {
    MREQUIRE(!v.empty());
    const size_t sz = v.size();
    return std::accumulate(v.begin(), v.end(), 0.0) / sz;
}

template<typename _Ty>
_Ty variance(const std::vector<_Ty> &v, size_t ddof) {
    _Ty  res = 0.;
    MREQUIRE(!v.empty());
    const size_t sz = v.size();
    if (sz == 1) {
        return res;
    }

    const _Ty mean = std::accumulate(v.begin(), v.end(), 0.0) / sz;

    auto variance_func = [mean](_Ty accumulator, _Ty val) {
        return accumulator + (val - mean)*(val - mean) ;
    };

    res = std::accumulate(v.begin(), v.end(), 0.0, variance_func);
    res /= (sz-ddof);
    return res;
}

template <class _Ty>
_Ty covariance(const std::vector<_Ty>& a, std::vector<_Ty>& b, size_t ddof)
{
    _Ty res = 0.0;
    const size_t sz = a.size();
	MREQUIRE_EQUAL(sz,b.size());
    if (sz == 1) {
        return res;
    }
    _Ty ma = mean(a) , mb = mean(b);
    auto ia = a.begin() ;
	auto ib = b.begin();
    for (size_t i=0; i<sz; i++)
    {
	    res += (*ia++ - ma) * (*ib++ -mb);
    }
    res /= (sz-ddof);
    return res;
}



template <class _Ty>
std::array<std::array<_Ty,2>,2> cov(const std::vector<_Ty>& a, std::vector<_Ty>& b,size_t ddof)
{
std::array<std::array<_Ty,2>,2> res;
	res[0][0] = variance(a,ddof);
    res[1][1] = variance(b,ddof);
    res[0][1] = covariance(a,b,ddof);
    res[1][0] = res[0][1];
	return res;
}