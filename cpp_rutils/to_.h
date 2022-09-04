#pragma once

#include <concepts>
#include "always_false.h"

// conversion prototype
// to<TargetType>::_(SrcTypeVar)

// convert _From to _To
// example : double i = to_<double>::_(1) ; 
template <typename _To>
struct to_
{
  template <typename _From>
  static _To _(_From const &);
  template <typename _From, typename... _MoreArgs>
  static _To _(_From const &, _MoreArgs  ...)
  {
    static_assert(always_false_v<_From, _MoreArgs...>);
  }
};

// default implementation
template <typename _To>
template <typename _From>
_To to_<_To>::_(_From const &from)
{
  static_assert(std::convertible_to<_From, _To>);
  return static_cast<_To>(from);
}
