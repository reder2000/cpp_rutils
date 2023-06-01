#pragma once

#include <vector>
#include "vector_concept.h"
#include <algorithm>

// Do(lambda).ForEach(container)
// Do(lambda).For(value)
// Do(lambda).ForEach(container).And().For(value).
// Do(lambda_1).ForEach(container).And(lambda_2).For(value).
// Do(lambda,params).ForEach(container) => for (c : container) lamba(c,params)
template <class F>
struct Do
{
  Do(F f) : _f(f) {}
  template <class C>
  Do& ForEach(C&& c)
  {
    for (auto&& a : c)
      _f(a);
    return *this;
  }
  template <class C, class... Args>
  Do& ForEach(C&& c, Args&&... args)
  {
    for (auto&& a : c)
      _f(a, args...);
    return *this;
  }
  template <class C>
  Do& For(C&& c)
  {
    _f(c);
    return *this;
  }
  template <class C, class... Args>
  Do& For(C&& c, Args&&... args)
  {
    _f(c, args...);
    return *this;
  }
  Do& And() { return *this; }
  template <class G>
  Do<G> And(G g)
  {
    return Do<G>(g);
  }
  F _f;
};



// return a new, transformed vector
template <VectorConcept In, class Tr>
auto transform_vc(const In& in, Tr tr)
{
  using result_type = typename std::invoke_result_t<Tr, typename In::value_type>;
  std::vector<result_type> res;
  res.reserve(in.size());
  for (auto i : in)
    res.emplace_back(tr(i));
  return res;
}


template <class Fun, class Iterable>
auto List(Fun fun, const Iterable& iter)
{
  //using result_type = typename std::invoke_result_t<Tr, typename In::value_type>;
  //using iterator_type = std::invoke_result_t<decltype(&Iterable::begin)>;
  using iterator_type = decltype(*std::declval<Iterable>().begin());
  using result_type   = std::invoke_result_t<Fun, iterator_type>;
  std::vector<result_type> res;
  for (auto i : iter)
    res.push_back(fun(i));
  return res;
}

template <class Fun, VectorConcept Vec>
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
  std::vector<T> res{dst};
  res.insert(res.end(), src.begin(), src.end());
  return res;
}

// concat with move
template <class T>
std::vector<T>& concat(std::vector<T>& dst, std::vector<T>&& src)
{
  dst.insert(dst.end(), std::make_move_iterator(src.begin()), std::make_move_iterator(src.end()));
  return dst;
}
