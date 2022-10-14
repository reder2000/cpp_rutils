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

template <class InIt, class BinOp, class T, class Fn>
T accumulate_adjacent(const InIt first, const InIt last, BinOp op , T val, Fn fn )
{
    T res = val;
    auto mfirst = first;
    auto mlast = last;
    auto ival = *mfirst;
    while (++mfirst != mlast)
    {
        auto tmp = *mfirst;
        res = fn(res, op(ival, tmp));
        ival = std::move(tmp);
    };
    return res;
}

template <class InIt>
typename InIt::value_type log_variance(const InIt first, const InIt last, size_t ddof)
{
    using T = typename InIt::value_type;
    const size_t N = std::distance(first,last) - 1;
    MREQUIRE_GREATER(N - ddof, 0, "vector must have at least {} elements",2+ddof);
    T second_order = accumulate_adjacent(first, last, [](T a, T b) {return log(b / a); }, 0., [](T val, T x) {return val + x * x; }) / N;
    T mean = log(*(last-1)/ *first) / N;
    T res = N * (second_order - mean * mean) / (N - ddof);
    return res;
}

template <class T>
double log_variance(const std::vector<T>& v, size_t ddof)
{
    return log_variance(v.begin(), v.end(), ddof);
}

template <class InIt, class BinOp, class T, class Fn>
T accumulate_biadjacent(const InIt first1, const InIt last1, const InIt first2, BinOp op, T val, Fn fn)
{
    T res = val;
    auto mfirst1 = first1;
    auto mlast1 = last1;
    auto mfirst2 = first2;
    auto ival1 = *mfirst1;
    auto ival2 = *mfirst2;
    while (++mfirst1 != mlast1)
    {
        ++mfirst2;
        auto tmp1 = *mfirst1;
        auto tmp2 = *mfirst2;
        res = fn(res, op(ival1, tmp1), op(ival2, tmp2));
        ival1 = std::move(tmp1);
        ival2 = std::move(tmp2);
    };
    return res;
}

template <class InIt>
typename InIt::value_type log_covariance(const InIt first1, const InIt last1, const InIt first2, size_t ddof)
{
    using T = typename InIt::value_type;
    const size_t N = std::distance(first1, last1) - 1;
    MREQUIRE_GREATER(N - ddof, 0, "vector must have at least {} elements", 2 + ddof);
    T second_order = accumulate_biadjacent(first1, last1, first2,  [](T a, T b) {return log(b / a); }, 0., [](T val, T x, T y) {return val + x * y; }) / N;
    T mean1 = log(*(last1 - 1) / *first1 ) / N;
    T mean2 = log(*(first2+N) / *first2 ) / N;
    T res = N * (second_order - mean1 * mean2) / (N - ddof);
    return res;
}

template <class T>
double log_covariance(const std::vector<T>& v1, const std::vector<T>& v2, size_t ddof)
{
    return log_covariance(v1.begin(), v1.end(), v2.begin(),  ddof);
}