#pragma once

#include <vector>
#include "require.h"

// vector result as ranges

template <class I>
std::vector<I> vector_range(I stop);

template <class I>
std::vector<I> vector_range(I start, I stop);

template <class I, class J>
std::vector<I> vector_range(I start, I stop, J step);

template <class I>
std::vector<I> reversed_vector_range(I start, I stop);

// ---------------------------

template <class I>
std::vector<I> vector_range(I stop)
{
  std::vector<I> res(stop);
  for (I i = 0; i < stop; ++i)
    res[i] = i;
  return res;
}

template <class I>
std::vector<I> vector_range(I start, I stop)
{
  std::vector<I> res(stop - start);
  size_t         j = 0;
  for (I i = start; i < stop; ++i, ++j)
    res[j] = i;
  return res;
}

template <class I, class J>
std::vector<I> vector_range(I start, I stop, J step)
{
  std::vector<I> res;
  if (start > stop)
  {
    MREQUIRE(step < 0);
    res.reserve((start - stop) / (-step));
    for (I i = start; i > stop; i += step)
      res.push_back(i);
  }
  else
  {
    MREQUIRE(step > 0);
    res.reserve((stop - start) / (step));
    for (I i = start; i < stop; i += step)
      res.push_back(i);
  }
  return res;
}

template <class I>
std::vector<I> reversed_vector_range(I start, I stop)
{
  std::vector<I> res = vector_range(start, stop);
  const size_t   N   = res.size();
  const size_t   N2  = N / 2;
  for (size_t i = 0; i < N2; i++)
    std::swap(res[i], res[N - i - 1]);
  return res;
}
