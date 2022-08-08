#pragma once

#include <type_traits>
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
  static _To _(const _From&);
};

// default implementation
template <typename _To>
template <typename _From>
inline _To to_<_To>::_(const _From &from)
{
  static_assert(std::convertible_to<_From, _To>);
  return static_cast<_To>(from);
}
