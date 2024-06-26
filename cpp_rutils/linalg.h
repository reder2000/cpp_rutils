#pragma once

// very minimal linear algorithms

#include <numeric>
#include <vector>
#include <algorithm>
#include <span>

#include "require.h"
#include "slice_vector.h"
#include <cmath>

// 1-d

template <class InIt, class BinOp, class T, class Fn>
T accumulate_adjacent(InIt const& first, InIt const& last, BinOp op, T val, Fn fn);

//  sum mean variance
template <typename T>
T sum(const std::vector<T>& v);
template <typename T>
T mean(const std::vector<T>& v);
template <typename T>
std::vector<T>& mult_self(std::vector<T>& v, const T& val);
template <typename T>
std::vector<T>& div_self(std::vector<T>& v, const std::vector<T>& other_v);
template <typename T>
std::vector<T> mult(const std::vector<T>& v, const T& val);
template <typename T>
T variance(const std::vector<T>& v, unsigned short ddof);
template <class T>
T log_variance(const std::vector<T>& v, unsigned short ddof);

// 2-d

template <class InIt1, class InIt2, class T, class Fn>
T accumulate2d(InIt1 first1, InIt1 last1, InIt2 first2, T val, Fn fn);

template <class InIt, class BinOp, class T, class Fn>
T accumulate2d_adjacent(const InIt& first1,
                        const InIt& last1,
                        const InIt& first2,
                        BinOp       op,
                        T           val,
                        Fn          fn);

// - + var cov

template <class T>
std::vector<T> add(const std::vector<T>& a, std::vector<T>& b);
template <class T>
std::vector<T> minus(const std::vector<T>& a, std::vector<T>& b);
template <class V, class W>
auto sumproduct(const V& a, const W& b)
    -> decltype(typename V::value_type(0) * typename W::value_type(0));
template <class T>
T covariance(const std::vector<T>& a, const std::vector<T>& b, unsigned short ddof);
template <class T>
std::array<std::array<T, 2>, 2> cov(const std::vector<T>& a,
                                    const std::vector<T>& b,
                                    unsigned short        ddof);
template <class T>
T log_covariance(const std::vector<T>& v1, const std::vector<T>& v2, unsigned short ddof);
template <class T>
T return_covariance(const std::vector<T>& v1, const std::vector<T>& v2, unsigned short ddof);


// ----------------------------------------
// implementation
// ----------------------------------------


template <class T>
std::vector<T> add(const std::vector<T>& a, std::vector<T>& b)
{
  std::vector<T> res;
  MREQUIRE_EQUAL(a.size(), b.size());
  res.reserve(a.size());
  std::transform(a.begin(), a.end(), b.begin(), std::back_inserter(res), std::plus<T>());
  return res;
}

template <class T>
std::vector<T> minus(const std::vector<T>& a, std::vector<T>& b)
{
  std::vector<T> res;
  MREQUIRE_EQUAL(a.size(), b.size());
  res.reserve(a.size());
  std::transform(a.begin(), a.end(), b.begin(), std::back_inserter(res), std::minus<T>());
  return res;
}

template <typename T>
T sum(const std::vector<T>& v)
{
  MREQUIRE(! v.empty());
  return std::accumulate(v.begin(), v.end(), 0.0);
}

template <typename T>
T mean(const std::vector<T>& v)
{
  MREQUIRE(! v.empty());
  const size_t sz = v.size();
  return std::accumulate(v.begin(), v.end(), 0.0) / sz;
}

template <typename T>
std::vector<T>& mult_self(std::vector<T>& v, const T& val)
{
  for (auto& x : v)
    x *= val;
  return v;
}

template <typename T>
std::vector<T>& div_self(std::vector<T>& v, const T& val)
{
  for (auto& x : v)
    x /= val;
  return v;
}

template <typename T>
std::vector<T>& mult_self(std::vector<T>& v, const std::vector<T>& other_v)
{
  MREQUIRE_EQUAL(v.size(), other_v.size());
  auto j = other_v.begin();
  for (auto& x : v)
  {
    x *= *j;
    ++j;
  }
  return v;
}

template <typename T>
std::vector<T> mult(std::vector<T>& v, const T& val)
{
  std::vector<T> res = v;
  mult_self(res, val);
  return res;
}
template <typename T>
T variance(const std::vector<T>& v, unsigned short ddof)
{
  T res = 0.;
  MREQUIRE(! v.empty());
  const size_t sz = v.size();
  if (sz == 1)
  {
    return res;
  }

  const T mean = std::accumulate(v.begin(), v.end(), 0.0) / sz;

  auto variance_func = [mean](T accumulator, T val)
  { return accumulator + (val - mean) * (val - mean); };

  res = std::accumulate(v.begin(), v.end(), 0.0, variance_func);
  res /= (sz - ddof);
  return res;
}

template <class T>
T covariance(const std::vector<T>& a, const std::vector<T>& b, unsigned short ddof)
{
  T            res = 0.0;
  const size_t sz  = a.size();
  MREQUIRE_EQUAL(sz, b.size());
  if (sz == 1)
  {
    return res;
  }
  T    ma = mean(a), mb = mean(b);
  auto ia = a.begin();
  auto ib = b.begin();
  for (size_t i = 0; i < sz; i++)
  {
    res += (*ia++ - ma) * (*ib++ - mb);
  }
  res /= (sz - ddof);
  return res;
}

template <class T>
std::array<std::array<T, 2>, 2> cov(const std::vector<T>& a,
                                    const std::vector<T>& b,
                                    unsigned short        ddof)
{
  std::array<std::array<T, 2>, 2> res;
  res[0][0] = variance(a, ddof);
  res[1][1] = variance(b, ddof);
  res[0][1] = covariance(a, b, ddof);
  res[1][0] = res[0][1];
  return res;
}

template <class InIt, class BinOp, class T, class Fn>
T accumulate_adjacent(InIt const& first, InIt const& last, BinOp op, T val, Fn fn)
{
  T    res    = val;
  auto mfirst = first;
  auto mlast  = last;
  auto ival   = *mfirst;
  while (++mfirst != mlast)
  {
    auto tmp = *mfirst;
    res      = fn(res, op(ival, tmp));
    ival     = std::move(tmp);
  }
  return res;
}

template <class InIt>
typename InIt::value_type log_variance(const InIt first, const InIt last, unsigned short ddof)
{
  using T        = typename InIt::value_type;
  const size_t N = std::distance(first, last) - 1;
  MREQUIRE_GREATER(N - ddof, 0, "vector must have at least {} elements", 2 + ddof);
  T second_order = accumulate_adjacent(
                       first, last, [](T a, T b) { return log(b / a); }, 0.,
                       [](T val, T x) { return val + x * x; }) /
                   N;
  T mean = log(*(last - 1) / *first) / N;
  T res  = N * (second_order - mean * mean) / (N - ddof);
  return res;
}

template <class T>
T log_variance(const std::vector<T>& v, unsigned short ddof)
{
  return log_variance(v.begin(), v.end(), ddof);
}

template <class InIt1, class InIt2, class T, class Fn>
T accumulate2d(InIt1 first1, InIt1 last1, InIt2 first2, T val, Fn fn)
{
  T    res     = val;
  auto mlast1  = last1;
  auto mfirst2 = first2;
  for (auto mfirst1 = first1; mfirst1 != mlast1; ++mfirst2, ++mfirst1)
  {
    res = fn(res, *mfirst1, *mfirst2);
  }
  return res;
}

template <class InIt, class BinOp, class T, class Fn>
T accumulate2d_adjacent(const InIt& first1,
                        const InIt& last1,
                        const InIt& first2,
                        BinOp       op,
                        T           val,
                        Fn          fn)
{
  T    res     = val;
  auto mfirst1 = first1;
  auto mlast1  = last1;
  auto mfirst2 = first2;
  auto ival1   = *mfirst1;
  auto ival2   = *mfirst2;
  while (++mfirst1 != mlast1)
  {
    ++mfirst2;
    auto tmp1 = *mfirst1;
    auto tmp2 = *mfirst2;
    res       = fn(res, op(ival1, tmp1), op(ival2, tmp2));
    ival1     = std::move(tmp1);
    ival2     = std::move(tmp2);
  }
  return res;
}

template <class V, class W>
auto sumproduct(const V& a, const W& b)
    -> decltype(typename V::value_type(0) * typename W::value_type(0))
{
  using T = decltype(typename V::value_type(0) * typename W::value_type(0));
  MREQUIRE_EQUAL(a.size(), b.size());
  return accumulate2d(a.begin(), a.end(), b.begin(), 0.,
                      [](T val, const typename V::value_type& x, const typename W::value_type& y)
                      { return val + x * y; });
}


template <class InIt>
typename InIt::value_type log_covariance(const InIt     first1,
                                         const InIt     last1,
                                         const InIt     first2,
                                         unsigned short ddof)
{
  using T        = typename InIt::value_type;
  const size_t N = std::distance(first1, last1) - 1;
  MREQUIRE_GREATER(N - ddof, 0, "vector must have at least {} elements", 2 + ddof);
  T second_order = accumulate2d_adjacent(
                       first1, last1, first2, [](T a, T b) { return log(b / a); }, 0.,
                       [](T val, T x, T y) { return val + x * y; }) /
                   N;
  T mean1 = log(*(last1 - 1) / *first1) / N;
  T mean2 = log(*(first2 + N) / *first2) / N;
  T res   = N * (second_order - mean1 * mean2) / (N - ddof);
  return res;
}


template <class InIt>
typename InIt::value_type return_covariance(const InIt     first1,
                                            const InIt     last1,
                                            const InIt     first2,
                                            unsigned short ddof)
{
  using T        = typename InIt::value_type;
  using tuple_t  = std::tuple<T, T, T>;
  const size_t N = std::distance(first1, last1) - 1;
  MREQUIRE_GREATER(N - ddof, 0, "vector must have at least {} elements", 2 + ddof);
  auto values = accumulate2d_adjacent(
      first1, last1, first2, [](T a, T b) { return b / a - 1; }, tuple_t{0., 0., 0.},
      [](tuple_t val, T x, T y)
      {
        std::get<0>(val) += x * y;
        std::get<1>(val) += x;
        std::get<2>(val) += y;
        return val;
      });
  T second_order = std::get<0>(values) / N;
  T mean1        = std::get<1>(values) / N;
  T mean2        = std::get<2>(values) / N;
  T res          = N * (second_order - mean1 * mean2) / (N - ddof);
  return res;
}

template <class T>
T log_covariance(const std::vector<T>& v1, const std::vector<T>& v2, unsigned short ddof)
{
  return log_covariance(v1.begin(), v1.end(), v2.begin(), ddof);
}

template <class T>
T return_covariance(const std::vector<T>& v1, const std::vector<T>& v2, unsigned short ddof)
{
  return return_covariance(v1.begin(), v1.end(), v2.begin(), ddof);
}
