#pragma once

#include <vector>
#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/tuple/to_seq.hpp>
#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/comma_if.hpp>
#include <unordered_map>
#include <unordered_set>

/*
 building struct of vectors

 suppose we have

 struct A {
	some_struct _a;
	other_struct _b;
	};

	we want to have

	struct vA {
	vA (size_t n);
	std::vector<some_struct> _a;
	std::vector<other_struct> _b;
	};

 */

//#define mystruct_tuple \
 //	((int,i),(double,d))

#define name_tuple(name) BOOST_PP_CAT(name, _tuple)

#define name_tuple_sequence(name) BOOST_PP_TUPLE_TO_SEQ(name_tuple(name))

#define struct_declare_elem(r, data, elem) \
  BOOST_PP_TUPLE_ELEM(0, elem) BOOST_PP_CAT(_, BOOST_PP_TUPLE_ELEM(1, elem));

#define name_tuple_struct_declare(name)                                      \
  struct name                                                                \
  {                                                                          \
    BOOST_PP_SEQ_FOR_EACH(struct_declare_elem, _, name_tuple_sequence(name)) \
  }

// name_tuple_struct_declare(mystruct);  -> struct mystruct { int _i ; double _d ; } ;

#define struct_declare_vector_elem(r, data, elem) \
  std::vector<BOOST_PP_TUPLE_ELEM(0, elem)> BOOST_PP_CAT(_, BOOST_PP_TUPLE_ELEM(1, elem));

#define struct_declare_vector_init_elem(r, data, i, elem) \
  BOOST_PP_COMMA_IF(i) BOOST_PP_CAT(_, BOOST_PP_TUPLE_ELEM(1, elem))(n)

#define name_tuple_struct_vector_declare(name)                                                     \
  struct BOOST_PP_CAT(name, _vector)                                                               \
  {                                                                                                \
    BOOST_PP_SEQ_FOR_EACH(struct_declare_vector_elem, _, name_tuple_sequence(name))                \
    BOOST_PP_CAT(name, _vector)() = default;                                                       \
    BOOST_PP_CAT(name, _vector)                                                                    \
    (size_t n)                                                                                     \
        : BOOST_PP_SEQ_FOR_EACH_I(struct_declare_vector_init_elem, _, name_tuple_sequence(name))   \
    {                                                                                              \
    }                                                                                              \
    size_t size() const                                                                            \
    {                                                                                              \
      return BOOST_PP_CAT(_,                                                                       \
                          BOOST_PP_TUPLE_ELEM(1, BOOST_PP_SEQ_ELEM(0, name_tuple_sequence(name)))) \
          .size();                                                                                 \
    }                                                                                              \
  }

// name_tuple_struct_vector_declare(mystruct); -> struct mystruct { std::vector<int> _i ; std::vector<double> _d ; } ;

#define name_tuple_struct_vector_merge_elem(r, data, elem) \
  res.BOOST_PP_CAT(_, BOOST_PP_TUPLE_ELEM(1, elem)) =      \
      merge(v.BOOST_PP_CAT(_, BOOST_PP_TUPLE_ELEM(1, elem)));

#define name_tuple_struct_vector_merge_declare(name)                                         \
  name merge_struct(const BOOST_PP_CAT(name, _vector) & v)                                   \
  {                                                                                          \
    name res;                                                                                \
    BOOST_PP_SEQ_FOR_EACH(name_tuple_struct_vector_merge_elem, X, name_tuple_sequence(name)) \
    return res;                                                                              \
  }


//name_tuple_struct_declare(mystruct);
//name_tuple_struct_vector_declare(mystruct);

#define name_tuple_struct_vector_merge_declare_all(name) \
  name_tuple_struct_declare(name);                       \
  name_tuple_struct_vector_declare(name);                \
  name_tuple_struct_vector_merge_declare(name)

template <class T>
T merge2(const T& first, const T& second)
{
  static_assert(always_false_v<T>);
}

template <class T>
std::vector<T> merge2(const std::vector<T>& first, const std::vector<T>& second)
{
  std::vector<T> res = first;
  res.insert(res.end(), second.begin(), second.end());
  return res;
}

template <class T>
std::unordered_set<T> merge2(const std::unordered_set<T>& first,
                             const std::unordered_set<T>& second)
{
  std::unordered_set<T> res = first;
  for (auto const& s : second)
    res.insert(s);
  return res;
}

template <class T>
std::vector<T> merge(const std::vector<std::vector<T>>& vs)
{
  size_t         total_size = std::accumulate(vs.begin(), vs.end(), (size_t)0,
                                              [](size_t i, auto const& t) { return i + t.size(); });
  std::vector<T> res;
  res.reserve(total_size);
  for (auto const& s : vs)
    for (auto const& v : s)
      res.push_back(v);
  return res;
}

template <class T>
std::unordered_set<T> merge(const std::vector<std::unordered_set<T>>& vs)
{
  std::unordered_set<T> res;
  for (auto const& s : vs)
    for (auto const& v : s)
      res.insert(v);
  return res;
}

template <class T, class U>
std::unordered_map<T, U> merge(const std::vector<std::unordered_map<T, U>>& vs)
{
  std::unordered_map<T, U> res;
  for (auto const& s : vs)
    for (auto const& v : s)
    {
      auto p = res.find(v.first);
      if (p == res.end())
        res[v.first] = v.second;
      else
      {
        res[v.first] = merge2(p->second, v.second);
      }
    }
  return res;
}
