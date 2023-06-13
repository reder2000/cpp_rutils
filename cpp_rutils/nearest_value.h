#pragma once
#include "vector_range.h"

// find the nearest value in an increasing sequence
// return index
template <VectorConcept Container, class Transform>
size_t find_nearest_value_old(
    double           target_value,
    Container const &v,
    Transform        f = [](const typename Container::value_type &value) -> std::decay_t<typename Container::value_type>
    { return value; })
{
  MREQUIRE(! v.empty());
  if (v.size() == 1) return 0;
  size_t i = 0, j = v.size() - 1;
  double dj = f(v[j]) - target_value;
  if (dj <= 0)  // target is above max value
    return j;
  double di = f(v[0]) - target_value;
  if (di >= 0)  // target is below min value
    return 0;
  while ((j - i) > 1)
  {
    size_t k = ((i + j) / 2);
    double d = f(v[k]) - target_value;
    if (d > 0)
    {
      j  = k;
      dj = d;
    }
    else
    {
      i  = k;
      di = d;
    }
  }
  MREQUIRE(i != j);
  MREQUIRE(di * dj <= 0);
  if (fabs(di) < fabs(dj))
    return i;
  else
    return j;
}

template <VectorConcept Container, class Transform>
struct VectorCache
{
  using value_type = std::decay_t<std::invoke_result_t<Transform, const typename Container::value_type &>>;

  VectorCache(const Container &container, Transform transform);
  //VectorCache(const VectorCache &vc);
  //VectorCache(VectorCache &&vc);

  const value_type &operator[](size_t i);

  const Container &_container;
  Transform        _transform;

  std::vector<bool>       _is_init;
  std::vector<value_type> _cache;
};

template <VectorConcept Container, class Transform>
VectorCache<Container, Transform>::VectorCache(const Container &container, Transform transform)
    : _container(container), _transform(transform), _is_init(_container.size(), false), _cache(_container.size())
{
}

//template <VectorConcept Container, class Transform>
//VectorCache<Container, Transform>::VectorCache(const VectorCache &vc) : VectorCache(vc._container, vc._transform)
//{
//}
//
//template <VectorConcept Container, class Transform>
//VectorCache<Container, Transform>::VectorCache(VectorCache &&vc) : VectorCache(vc._container, std::move(vc._transform))
//{
//}

template <VectorConcept Container, class Transform>
const typename VectorCache<Container, Transform>::value_type &VectorCache<Container, Transform>::operator[](size_t i)
{
  if (! _is_init[i])
  {
    _cache[i]   = _transform(_container[i]);
    _is_init[i] = true;
  }
  return _cache[i];
}

template <VectorConcept Container, class Transform>
VectorCache<Container, Transform> make_VectorCache(const Container &container, Transform transform)
{
  return VectorCache<Container, Transform>(container, transform);
}

// find the nearest value in an increasing sequence
// return index
// f may be an expensive function
template <VectorConcept Container, class Transform>
auto _find_nearest_value(double target_value, Container const &v, Transform f)
{
  size_t res;
  auto   vector_cache = make_VectorCache(v, f);
  if (v.empty())
  {
    res = std::string::npos;
  }
  else
  {
    auto g     = [&vector_cache](size_t i) { return vector_cache[i]; };
    auto range = vector_range(v.size());
    auto lb    = std::upper_bound(range.begin(), range.end(), target_value,
                                  [&g](const double &d, size_t j) { return d < g(j); });
    if (lb == range.end())
    {
      res = v.size() - 1;
    }
    else
    {
      size_t i = std::distance(range.begin(), lb);
      res      = i;
      if (i > 0 && (g(i) - target_value > target_value - g(i - 1))) --res;
    }
  }
  return std::pair{res, vector_cache};
}

template <VectorConcept Container,
          class Transform = std::function<typename Container::value_type(const typename Container::value_type &value)>>
size_t find_nearest_value(
    double           target_value,
    Container const &v,
    Transform        f = [](const typename Container::value_type &value) { return value; })
{
  return std::get<0>(_find_nearest_value(target_value, v, f));
}

template <VectorConcept Container,
          class Transform = std::function<typename Container::value_type(const typename Container::value_type &value)>>
std::vector<size_t> find_nearest_values(
    size_t           nb_values,
    double           target_value,
    Container const &v,
    Transform        f = [](const typename Container::value_type &value) -> std::decay_t<typename Container::value_type>
    { return value; })
{
  if (nb_values > v.size()) return find_nearest_values(v.size(), target_value, v, f);
  if (nb_values == 0) return std::vector<size_t>{};
  auto tmp =
      //std::forward<std::pair<size_t, VectorCache<Container, Transform>>>(_find_nearest_value(target_value, v, f));
      _find_nearest_value(target_value, v, f);
  auto  ni           = tmp.first;
  auto &vector_cache = tmp.second;
  auto  g            = [&vector_cache](size_t i) { return vector_cache[i]; };
  if (ni == 0) return vector_range(nb_values);
  if (ni == v.size() - 1) return reversed_vector_range(v.size() - nb_values, v.size());
  std::vector<size_t> res;
  res.push_back(ni);
  size_t li = ni - 1, ui = ni + 1;
  while (res.size() < nb_values)
  {
    if (target_value - g(li) <= g(ui) - target_value)
    {
      res.push_back(li);
      if (li == 0)
      {
        while (res.size() < nb_values)
          res.push_back(ui++);
      }
      else
        --li;
    }
    else
    {
      {
        res.push_back(ui);
        if (++ui == v.size())
          while (res.size() < nb_values)
            res.push_back(li--);
      }
    }
  }
  return res;
}
